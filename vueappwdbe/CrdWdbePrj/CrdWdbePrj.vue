<template>
	<v-container v-if="initdone">
		<PnlWdbePrjList
			v-on:request="handleRequest"
			ref="PnlWdbePrjList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbePrjRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbePrjRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbePrjList from './PnlWdbePrjList';
	import PnlWdbePrjRec from './PnlWdbePrjRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbePrj',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbePrjList,
			PnlWdbePrjRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbePrj.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWdbePrj) this.continf = dpcheng.ContInfWdbePrj;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbePrj) this.statapp = dpcheng.StatAppWdbePrj;
				if (dpcheng.StatShrWdbePrj) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWdbePrj.scrJrefDlgimpex != "") || (dpcheng.StatShrWdbePrj.scrJrefDlgnew != ""));
						dlgclose = ((this.statshr.scrJrefDlgimpex != "") || (this.statshr.scrJrefDlgnew != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWdbePrj.scrJrefDlgimpex != "") {
								srefDlg = "DlgWdbePrjImpex";
								scrJrefDlg = dpcheng.StatShrWdbePrj.scrJrefDlgimpex;
							} else if (dpcheng.StatShrWdbePrj.scrJrefDlgnew != "") {
								srefDlg = "DlgWdbePrjNew";
								scrJrefDlg = dpcheng.StatShrWdbePrj.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrWdbePrj;
				}
				if (dpcheng.TagWdbePrj) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrj);
					this.tag = dpcheng.TagWdbePrj;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbePrjList.handleReply(obj);
					else this.$refs.PnlWdbePrjRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbePrjData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbePrjList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbePrjRec.handleUpdate(obj);
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
