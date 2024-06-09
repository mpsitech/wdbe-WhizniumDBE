<template>
	<v-container v-if="initdone">
		<PnlWdbeCmpList
			v-on:request="handleRequest"
			ref="PnlWdbeCmpList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeCmpRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeCmpRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeCmpList from './PnlWdbeCmpList';
	import PnlWdbeCmpRec from './PnlWdbeCmpRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeCmp',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeCmpList,
			PnlWdbeCmpRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeCmp.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeCmp) this.continf = dpcheng.ContInfWdbeCmp;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeCmp) this.statapp = dpcheng.StatAppWdbeCmp;
				if (dpcheng.StatShrWdbeCmp) this.statshr = dpcheng.StatShrWdbeCmp;
				if (dpcheng.TagWdbeCmp) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCmp);
					this.tag = dpcheng.TagWdbeCmp;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeCmpList.handleReply(obj);
					else this.$refs.PnlWdbeCmpRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeCmpData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeCmpList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeCmpRec.handleUpdate(obj);
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
