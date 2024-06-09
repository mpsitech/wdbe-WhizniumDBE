<template>
	<v-container v-if="initdone">
		<PnlWdbeUsrList
			v-on:request="handleRequest"
			ref="PnlWdbeUsrList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeUsrRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeUsrRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeUsrList from './PnlWdbeUsrList';
	import PnlWdbeUsrRec from './PnlWdbeUsrRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeUsr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeUsrList,
			PnlWdbeUsrRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeUsr.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWdbeUsr) this.continf = dpcheng.ContInfWdbeUsr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeUsr) this.statapp = dpcheng.StatAppWdbeUsr;
				if (dpcheng.StatShrWdbeUsr) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrWdbeUsr.scrJrefDlgmngkeypair != "");
						dlgclose = (this.statshr.scrJrefDlgmngkeypair != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWdbeUsr.scrJrefDlgmngkeypair != "") {
								srefDlg = "DlgWdbeUsrMngkeypair";
								scrJrefDlg = dpcheng.StatShrWdbeUsr.scrJrefDlgmngkeypair;
							}
						}
					}
					this.statshr = dpcheng.StatShrWdbeUsr;
				}
				if (dpcheng.TagWdbeUsr) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeUsr);
					this.tag = dpcheng.TagWdbeUsr;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeUsrList.handleReply(obj);
					else this.$refs.PnlWdbeUsrRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeUsrData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeUsrList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeUsrRec.handleUpdate(obj);
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
