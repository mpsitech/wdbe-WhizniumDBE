<template>
	<v-container v-if="initdone">
		<PnlWdbeVerList
			v-on:request="handleRequest"
			ref="PnlWdbeVerList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeVerRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeVerRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeVerList from './PnlWdbeVerList';
	import PnlWdbeVerRec from './PnlWdbeVerRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeVer',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeVerList,
			PnlWdbeVerRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeVer.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWdbeVer) this.continf = dpcheng.ContInfWdbeVer;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeVer) this.statapp = dpcheng.StatAppWdbeVer;
				if (dpcheng.StatShrWdbeVer) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWdbeVer.scrJrefDlgcmdset != "") || (dpcheng.StatShrWdbeVer.scrJrefDlgcustfst != "") || (dpcheng.StatShrWdbeVer.scrJrefDlgdeploy != "") || (dpcheng.StatShrWdbeVer.scrJrefDlgdflalg != "") || (dpcheng.StatShrWdbeVer.scrJrefDlgfinmod != "") || (dpcheng.StatShrWdbeVer.scrJrefDlggenfst != "") || (dpcheng.StatShrWdbeVer.scrJrefDlgmdlstr != "") || (dpcheng.StatShrWdbeVer.scrJrefDlgnew != ""));
						dlgclose = ((this.statshr.scrJrefDlgcmdset != "") || (this.statshr.scrJrefDlgcustfst != "") || (this.statshr.scrJrefDlgdeploy != "") || (this.statshr.scrJrefDlgdflalg != "") || (this.statshr.scrJrefDlgfinmod != "") || (this.statshr.scrJrefDlggenfst != "") || (this.statshr.scrJrefDlgmdlstr != "") || (this.statshr.scrJrefDlgnew != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWdbeVer.scrJrefDlgcmdset != "") {
								srefDlg = "DlgWdbeVerCmdset";
								scrJrefDlg = dpcheng.StatShrWdbeVer.scrJrefDlgcmdset;
							} else if (dpcheng.StatShrWdbeVer.scrJrefDlgcustfst != "") {
								srefDlg = "DlgWdbeVerCustfst";
								scrJrefDlg = dpcheng.StatShrWdbeVer.scrJrefDlgcustfst;
							} else if (dpcheng.StatShrWdbeVer.scrJrefDlgdeploy != "") {
								srefDlg = "DlgWdbeVerDeploy";
								scrJrefDlg = dpcheng.StatShrWdbeVer.scrJrefDlgdeploy;
							} else if (dpcheng.StatShrWdbeVer.scrJrefDlgdflalg != "") {
								srefDlg = "DlgWdbeVerDflalg";
								scrJrefDlg = dpcheng.StatShrWdbeVer.scrJrefDlgdflalg;
							} else if (dpcheng.StatShrWdbeVer.scrJrefDlgfinmod != "") {
								srefDlg = "DlgWdbeVerFinmod";
								scrJrefDlg = dpcheng.StatShrWdbeVer.scrJrefDlgfinmod;
							} else if (dpcheng.StatShrWdbeVer.scrJrefDlggenfst != "") {
								srefDlg = "DlgWdbeVerGenfst";
								scrJrefDlg = dpcheng.StatShrWdbeVer.scrJrefDlggenfst;
							} else if (dpcheng.StatShrWdbeVer.scrJrefDlgmdlstr != "") {
								srefDlg = "DlgWdbeVerMdlstr";
								scrJrefDlg = dpcheng.StatShrWdbeVer.scrJrefDlgmdlstr;
							} else if (dpcheng.StatShrWdbeVer.scrJrefDlgnew != "") {
								srefDlg = "DlgWdbeVerNew";
								scrJrefDlg = dpcheng.StatShrWdbeVer.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrWdbeVer;
				}
				if (dpcheng.TagWdbeVer) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeVer);
					this.tag = dpcheng.TagWdbeVer;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeVerList.handleReply(obj);
					else this.$refs.PnlWdbeVerRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeVerData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeVerList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeVerRec.handleUpdate(obj);
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
