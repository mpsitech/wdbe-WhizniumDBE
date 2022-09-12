<template>
	<v-container v-if="initdone">
		<PnlWdbeErrList
			v-on:request="handleRequest"
			ref="PnlWdbeErrList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeErrRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeErrRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeErrList from './PnlWdbeErrList';
	import PnlWdbeErrRec from './PnlWdbeErrRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeErr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeErrList,
			PnlWdbeErrRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeErr.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeErr) this.continf = dpcheng.ContInfWdbeErr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeErr) this.statapp = dpcheng.StatAppWdbeErr;
				if (dpcheng.StatShrWdbeErr) this.statshr = dpcheng.StatShrWdbeErr;
				if (dpcheng.TagWdbeErr) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeErr);
					this.tag = dpcheng.TagWdbeErr;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeErrList.handleReply(obj);
					else this.$refs.PnlWdbeErrRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeErrData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeErrList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeErrRec.handleUpdate(obj);
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
