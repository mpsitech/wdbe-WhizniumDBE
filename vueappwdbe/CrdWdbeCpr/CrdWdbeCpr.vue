<template>
	<v-container v-if="initdone">
		<PnlWdbeCprList
			v-on:request="handleRequest"
			ref="PnlWdbeCprList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeCprRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeCprRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeCprList from './PnlWdbeCprList';
	import PnlWdbeCprRec from './PnlWdbeCprRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeCpr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeCprList,
			PnlWdbeCprRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeCpr.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWdbeCpr) this.continf = dpcheng.ContInfWdbeCpr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeCpr) this.statapp = dpcheng.StatAppWdbeCpr;
				if (dpcheng.StatShrWdbeCpr) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrWdbeCpr.scrJrefDlgnew != "");
						dlgclose = (this.statshr.scrJrefDlgnew != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWdbeCpr.scrJrefDlgnew != "") {
								srefDlg = "DlgWdbeCprNew";
								scrJrefDlg = dpcheng.StatShrWdbeCpr.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrWdbeCpr;
				}
				if (dpcheng.TagWdbeCpr) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCpr);
					this.tag = dpcheng.TagWdbeCpr;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeCprList.handleReply(obj);
					else this.$refs.PnlWdbeCprRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeCprData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeCprList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeCprRec.handleUpdate(obj);
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
