<template>
	<v-container v-if="initdone">
		<PnlWdbeUntList
			v-on:request="handleRequest"
			ref="PnlWdbeUntList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeUntRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeUntRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeUntList from './PnlWdbeUntList';
	import PnlWdbeUntRec from './PnlWdbeUntRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeUnt',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeUntList,
			PnlWdbeUntRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeUnt.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeUnt) this.continf = dpcheng.ContInfWdbeUnt;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeUnt) this.statapp = dpcheng.StatAppWdbeUnt;
				if (dpcheng.StatShrWdbeUnt) this.statshr = dpcheng.StatShrWdbeUnt;
				if (dpcheng.TagWdbeUnt) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeUnt);
					this.tag = dpcheng.TagWdbeUnt;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeUntList.handleReply(obj);
					else this.$refs.PnlWdbeUntRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeUntData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeUntList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeUntRec.handleUpdate(obj);
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
