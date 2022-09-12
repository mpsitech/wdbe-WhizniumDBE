<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Utilities</h1>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeUtl',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeUtl.mounted() with scrJref = " + this.scrJref);

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
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfWdbeUtl) this.continf = dpcheng.ContInfWdbeUtl;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeUtl) this.statapp = dpcheng.StatAppWdbeUtl;
				if (dpcheng.StatShrWdbeUtl) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWdbeUtl.scrJrefDlgextrip != "") || (dpcheng.StatShrWdbeUtl.scrJrefDlgmrgip != ""));
						dlgclose = ((this.statshr.scrJrefDlgextrip != "") || (this.statshr.scrJrefDlgmrgip != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWdbeUtl.scrJrefDlgextrip != "") {
								srefDlg = "DlgWdbeUtlExtrip";
								scrJrefDlg = dpcheng.StatShrWdbeUtl.scrJrefDlgextrip;
							} else if (dpcheng.StatShrWdbeUtl.scrJrefDlgmrgip != "") {
								srefDlg = "DlgWdbeUtlMrgip";
								scrJrefDlg = dpcheng.StatShrWdbeUtl.scrJrefDlgmrgip;
							}
						}
					}
					this.statshr = dpcheng.StatShrWdbeUtl;
				}
				if (dpcheng.TagWdbeUtl) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeUtl);
					this.tag = dpcheng.TagWdbeUtl;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
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
					console.log("got a '" + obj.srefIxWdbeVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeUtlData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					
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
