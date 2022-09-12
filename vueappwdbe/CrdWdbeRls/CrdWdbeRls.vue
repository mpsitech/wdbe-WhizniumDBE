<template>
	<v-container v-if="initdone">
		<PnlWdbeRlsList
			v-on:request="handleRequest"
			ref="PnlWdbeRlsList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeRlsRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeRlsRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeRlsList from './PnlWdbeRlsList';
	import PnlWdbeRlsRec from './PnlWdbeRlsRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeRls',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeRlsList,
			PnlWdbeRlsRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeRls.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWdbeRls) this.continf = dpcheng.ContInfWdbeRls;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeRls) this.statapp = dpcheng.StatAppWdbeRls;
				if (dpcheng.StatShrWdbeRls) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWdbeRls.scrJrefDlgfinreptr != "") || (dpcheng.StatShrWdbeRls.scrJrefDlgnew != "") || (dpcheng.StatShrWdbeRls.scrJrefDlgstareptr != "") || (dpcheng.StatShrWdbeRls.scrJrefDlgwrite != ""));
						dlgclose = ((this.statshr.scrJrefDlgfinreptr != "") || (this.statshr.scrJrefDlgnew != "") || (this.statshr.scrJrefDlgstareptr != "") || (this.statshr.scrJrefDlgwrite != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWdbeRls.scrJrefDlgfinreptr != "") {
								srefDlg = "DlgWdbeRlsFinreptr";
								scrJrefDlg = dpcheng.StatShrWdbeRls.scrJrefDlgfinreptr;
							} else if (dpcheng.StatShrWdbeRls.scrJrefDlgnew != "") {
								srefDlg = "DlgWdbeRlsNew";
								scrJrefDlg = dpcheng.StatShrWdbeRls.scrJrefDlgnew;
							} else if (dpcheng.StatShrWdbeRls.scrJrefDlgstareptr != "") {
								srefDlg = "DlgWdbeRlsStareptr";
								scrJrefDlg = dpcheng.StatShrWdbeRls.scrJrefDlgstareptr;
							} else if (dpcheng.StatShrWdbeRls.scrJrefDlgwrite != "") {
								srefDlg = "DlgWdbeRlsWrite";
								scrJrefDlg = dpcheng.StatShrWdbeRls.scrJrefDlgwrite;
							}
						}
					}
					this.statshr = dpcheng.StatShrWdbeRls;
				}
				if (dpcheng.TagWdbeRls) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeRls);
					this.tag = dpcheng.TagWdbeRls;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeRlsList.handleReply(obj);
					else this.$refs.PnlWdbeRlsRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeRlsData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeRlsList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeRlsRec.handleUpdate(obj);
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
