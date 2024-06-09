<template>
	<v-container v-if="initdone">
		<PnlWdbeCvrList
			v-on:request="handleRequest"
			ref="PnlWdbeCvrList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeCvrRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeCvrRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeCvrList from './PnlWdbeCvrList';
	import PnlWdbeCvrRec from './PnlWdbeCvrRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeCvr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeCvrList,
			PnlWdbeCvrRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeCvr.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWdbeCvr) this.continf = dpcheng.ContInfWdbeCvr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeCvr) this.statapp = dpcheng.StatAppWdbeCvr;
				if (dpcheng.StatShrWdbeCvr) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWdbeCvr.scrJrefDlgbsccd != "") || (dpcheng.StatShrWdbeCvr.scrJrefDlgdetcd != "") || (dpcheng.StatShrWdbeCvr.scrJrefDlgnew != "") || (dpcheng.StatShrWdbeCvr.scrJrefDlgwrite != ""));
						dlgclose = ((this.statshr.scrJrefDlgbsccd != "") || (this.statshr.scrJrefDlgdetcd != "") || (this.statshr.scrJrefDlgnew != "") || (this.statshr.scrJrefDlgwrite != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWdbeCvr.scrJrefDlgbsccd != "") {
								srefDlg = "DlgWdbeCvrBsccd";
								scrJrefDlg = dpcheng.StatShrWdbeCvr.scrJrefDlgbsccd;
							} else if (dpcheng.StatShrWdbeCvr.scrJrefDlgdetcd != "") {
								srefDlg = "DlgWdbeCvrDetcd";
								scrJrefDlg = dpcheng.StatShrWdbeCvr.scrJrefDlgdetcd;
							} else if (dpcheng.StatShrWdbeCvr.scrJrefDlgnew != "") {
								srefDlg = "DlgWdbeCvrNew";
								scrJrefDlg = dpcheng.StatShrWdbeCvr.scrJrefDlgnew;
							} else if (dpcheng.StatShrWdbeCvr.scrJrefDlgwrite != "") {
								srefDlg = "DlgWdbeCvrWrite";
								scrJrefDlg = dpcheng.StatShrWdbeCvr.scrJrefDlgwrite;
							}
						}
					}
					this.statshr = dpcheng.StatShrWdbeCvr;
				}
				if (dpcheng.TagWdbeCvr) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCvr);
					this.tag = dpcheng.TagWdbeCvr;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeCvrList.handleReply(obj);
					else this.$refs.PnlWdbeCvrRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeCvrData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeCvrList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeCvrRec.handleUpdate(obj);
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
