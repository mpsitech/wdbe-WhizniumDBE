<template>
	<v-container v-if="initdone">
		<PnlWdbeCdcList
			v-on:request="handleRequest"
			ref="PnlWdbeCdcList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeCdcRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeCdcRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeCdcList from './PnlWdbeCdcList';
	import PnlWdbeCdcRec from './PnlWdbeCdcRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeCdc',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeCdcList,
			PnlWdbeCdcRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeCdc.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWdbeInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfWdbeCdc) this.continf = dpcheng.ContInfWdbeCdc;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeCdc) this.statapp = dpcheng.StatAppWdbeCdc;
				if (dpcheng.StatShrWdbeCdc) this.statshr = dpcheng.StatShrWdbeCdc;
				if (dpcheng.TagWdbeCdc) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCdc);
					this.tag = dpcheng.TagWdbeCdc;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeCdcList.handleReply(obj);
					else this.$refs.PnlWdbeCdcRec.handleReply(obj);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeCdcData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeCdcList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeCdcRec.handleUpdate(obj);
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWdbeVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
