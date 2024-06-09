<template>
	<v-container v-if="initdone">
		<PnlWdbeFilList
			v-on:request="handleRequest"
			ref="PnlWdbeFilList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeFilRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeFilRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeFilList from './PnlWdbeFilList';
	import PnlWdbeFilRec from './PnlWdbeFilRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeFil',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeFilList,
			PnlWdbeFilRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeFil.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWdbeFil) this.continf = dpcheng.ContInfWdbeFil;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeFil) this.statapp = dpcheng.StatAppWdbeFil;
				if (dpcheng.StatShrWdbeFil) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWdbeFil.scrJrefDlgdownload != "") || (dpcheng.StatShrWdbeFil.scrJrefDlgnew != ""));
						dlgclose = ((this.statshr.scrJrefDlgdownload != "") || (this.statshr.scrJrefDlgnew != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWdbeFil.scrJrefDlgdownload != "") {
								srefDlg = "DlgWdbeFilDownload";
								scrJrefDlg = dpcheng.StatShrWdbeFil.scrJrefDlgdownload;
							} else if (dpcheng.StatShrWdbeFil.scrJrefDlgnew != "") {
								srefDlg = "DlgWdbeFilNew";
								scrJrefDlg = dpcheng.StatShrWdbeFil.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrWdbeFil;
				}
				if (dpcheng.TagWdbeFil) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeFil);
					this.tag = dpcheng.TagWdbeFil;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeFilList.handleReply(obj);
					else this.$refs.PnlWdbeFilRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeFilData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeFilList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeFilRec.handleUpdate(obj);
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
