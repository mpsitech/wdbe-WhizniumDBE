<template>
	<div v-if="initdonePnls">
		<div class="d-flex pa-2 align-center">
			<img src="../../assets/logo.png" height="56" alt="logo" class="mr-1">
			<div>
				<div class="title font-weight-bold text-uppercase primary--text mx-2">{{CptTitle}}</div>
				<div class="caption grey--text mx-2">{{CptVersion}}</div>
			</div>
		</div>

		<v-divider/>

		<v-list>
			<v-list-item-group v-model="MenApp">
				<v-list-item
					active-class="primary--text"
					v-on:click="handleMitClick('MitAppAbtClick')"
					value="MitAppAbt"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitAppAbt}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-list-item
					v-if="statshr.MitAppLoiAvail"
					active-class="primary--text"
					v-on:click="handleMitClick('MitAppLoiClick')"
					value="MitAppLoi"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitAppLoi}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>
			</v-list-item-group>

			<v-divider/>

			<v-list-item-group>
				<v-list-item
					v-if="statshr.MitSesSpsAvail"
					active-class="primary--text"
					v-on:click="handleMitClick('MitSesSpsClick')"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitSesSps}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-list-item
					active-class="primary--text"
					v-on:click="handleMitClick('MitSesTrmClick')"
				>
					<v-list-item-content>
						<v-list-item-title>{{tag.MitSesTrm}}</v-list-item-title>
					</v-list-item-content>
					<v-tooltip right>
						<template v-slot:activator="{on,attrs}">
							<v-list-item-icon>
								<v-icon v-bind="attrs" v-on="on">mdi-information-outline</v-icon>
							</v-list-item-icon>
						</template>
						{{continf.MtxSesSes1 + " " + continf.MtxSesSes2 + " " + continf.MtxSesSes3}}
					</v-tooltip>
				</v-list-item>
			</v-list-item-group>

			<v-divider/>

			<v-list-item-group v-if="statshr.pnlpreAvail">
				<v-list-item
					v-for="(short, j) in mitsPre"
					:key="j"
					active-class="red--text"
					class="red--text"
				>
					<v-list-item-content>
						<v-list-item-subtitle class="red--text text--lighten-3 overline">{{pnlpre.tag['Cpt' + short]}}</v-list-item-subtitle>
						<v-list-item-title>{{pnlpre.continf['Txt' + short]}}</v-list-item-title>
					</v-list-item-content>
					<v-list-item-icon>
						<v-icon
							color="red"
							v-on:click="handleButClick_other('Pre', statshr.scrJrefPre, 'But' + short + 'RemoveClick')"
						>
							mdi-close-circle-outline
						</v-icon>
					</v-list-item-icon>
				</v-list-item>
			</v-list-item-group>

			<v-divider v-if="statshr.pnlpreAvail"/>

			<v-list-item-group v-for="({sref, mits}, i) in MbarContent" :key="i" v-model="MbarContent[i].mit">
				<v-list-item small disabled dense class="grey lighten-5">
					<v-list-item-content :style="{'text-align':'right'}">
						<v-list-item-title class="grey--text text--darken-4 overline">{{MenContentHdg(sref)}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-divider/>

				<v-list-item
					v-for="(sref, j) in mitsContent(mits)"
					:key="j"
					active-class="grey lighten-5"
					class="grey lighten-5"
					v-on:click="handleMitContentClick(sref + 'Click')"
					:value="sref"
					:disabled="!MitContentActive(sref)"
				>
					<v-list-item-content>
						<v-list-item-title>{{MitContent(sref)}}</v-list-item-title>
					</v-list-item-content>
				</v-list-item>

				<v-divider/>
			</v-list-item-group>

			<v-list-item small disabled dense>
				<v-list-item-content :style="{'text-align':'right'}">
					<v-list-item-title class="overline">{{pnlheadbar.tag.MenCrd}}</v-list-item-title>
				</v-list-item-content>
			</v-list-item>

			<v-divider/>

			<v-list-item-group mandatory>
				<v-list-group v-for="({pnlsref, mits}, i) in MenCrd" :key="i">
					<template v-slot:activator>
						<v-list-item-content>
							<v-list-item-title>{{MenCrdHdg(pnlsref)}}</v-list-item-title>
						</v-list-item-content>
					</template>

					<v-list-item
						v-for="(sref, j) in mitsCrd(mits)"
						:key="j"
						active-class="primary--text"
						v-on:click="handleMitCrdopenClick(sref + 'Click')"
						:value="sref"
						:disabled="!MitCrdActive(sref)"
					>
						<v-tooltip right>
							<template v-slot:activator="{on,attrs}">
								<v-list-item-content v-bind="attrs" v-on="on">
									<v-list-item-title>{{MitCrd(sref)}}</v-list-item-title>
								</v-list-item-content>
							</template><span v-html="LstHist(pnlsref, sref.substring(3 + 3))"/>
						</v-tooltip>
					</v-list-item>
				</v-list-group>

				<v-divider/>
			</v-list-item-group>
		</v-list>
	</div>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeNav',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("CrdWdbeNav.mounted() with scrJref = " + this.scrJref);

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

			handleMitClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWdbeNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"});
			},

			handleMitCrdopenClick: function(ctlsref) {
				if (this.content.sref.substring(3 + 4) == ctlsref.substring(3 + 3, 3 + 3 + 3)) return;

				const dpchapp = {
					"DpchAppWdbeNavDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppCrdopenReply"});
			},

			handleButClick_other: function(sref, scrJref, ctlsref) {
				const dpchapp = {
					["DpchAppWdbeNav" + sref + "Do"]: {
						"scrJref": scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"});
			},

			handleMitContentClick: function(ctlsref) {
				const dpchapp = {
					["DpchApp" + this.content.sref.substring(3) + "Do"]: {
						"scrJref": this.content.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.content.scrJref, dpchapp: dpchapp, then: "handleDpchAppDoReply"}); // reply ends up in content card
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfWdbeNav) this.continf = dpcheng.ContInfWdbeNav;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeNav) this.statapp = dpcheng.StatAppWdbeNav;
				if (dpcheng.StatShrWdbeNav) {
					if (this.statshr != null) {
						dlgopen = ((dpcheng.StatShrWdbeNav.scrJrefDlgloaini != "") || (dpcheng.StatShrWdbeNav.scrJrefDlgmnglic != ""));
						dlgclose = ((this.statshr.scrJrefDlgloaini != "") || (this.statshr.scrJrefDlgmnglic != ""));
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWdbeNav.scrJrefDlgloaini != "") {
								srefDlg = "DlgWdbeNavLoaini";
								scrJrefDlg = dpcheng.StatShrWdbeNav.scrJrefDlgloaini;
							} else if (dpcheng.StatShrWdbeNav.scrJrefDlgmnglic != "") {
								srefDlg = "DlgWdbeNavMnglic";
								scrJrefDlg = dpcheng.StatShrWdbeNav.scrJrefDlgmnglic;
							}
						}
					}
					this.statshr = dpcheng.StatShrWdbeNav;
				}
				if (dpcheng.TagWdbeNav) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNav);
					this.tag = dpcheng.TagWdbeNav;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
				/*
				*/
			},

			/*
			*/
			mergeDpchEngData_pnlheadbar: function(dpcheng) {
				if (dpcheng.StatShrWdbeNavHeadbar) this.pnlheadbar.statshr = dpcheng.StatShrWdbeNavHeadbar;
				if (dpcheng.StgInfWdbeNavHeadbar) this.pnlheadbar.stginf = dpcheng.StgInfWdbeNavHeadbar;
				if (dpcheng.TagWdbeNavHeadbar) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavHeadbar);
					this.pnlheadbar.tag = dpcheng.TagWdbeNavHeadbar;
				}
			},

			mergeDpchEngData_pnlpre: function(dpcheng) {
				if (dpcheng.ContInfWdbeNavPre) this.pnlpre.continf = dpcheng.ContInfWdbeNavPre;
				if (dpcheng.StatShrWdbeNavPre) this.pnlpre.statshr = dpcheng.StatShrWdbeNavPre;
				if (dpcheng.TagWdbeNavPre) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavPre);
					this.pnlpre.tag = dpcheng.TagWdbeNavPre;
				}
			},

			mergeDpchEngData_pnladmin: function(dpcheng) {
				if (dpcheng.ContIacWdbeNavAdmin) this.pnladmin.contiac = dpcheng.ContIacWdbeNavAdmin;
				if (dpcheng.FeedFLstFil) this.pnladmin.feedFLstFil = dpcheng.FeedFLstFil;
				if (dpcheng.FeedFLstPrs) this.pnladmin.feedFLstPrs = dpcheng.FeedFLstPrs;
				if (dpcheng.FeedFLstUsg) this.pnladmin.feedFLstUsg = dpcheng.FeedFLstUsg;
				if (dpcheng.FeedFLstUsr) this.pnladmin.feedFLstUsr = dpcheng.FeedFLstUsr;
				if (dpcheng.StatAppWdbeNavAdmin) this.pnladmin.statapp = dpcheng.StatAppWdbeNavAdmin;
				if (dpcheng.StatShrWdbeNavAdmin) this.pnladmin.statshr = dpcheng.StatShrWdbeNavAdmin;
				if (dpcheng.TagWdbeNavAdmin) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavAdmin);
					this.pnladmin.tag = dpcheng.TagWdbeNavAdmin;
				}
			},

			mergeDpchEngData_pnlglobal: function(dpcheng) {
				if (dpcheng.ContIacWdbeNavGlobal) this.pnlglobal.contiac = dpcheng.ContIacWdbeNavGlobal;
				if (dpcheng.FeedFLstFam) this.pnlglobal.feedFLstFam = dpcheng.FeedFLstFam;
				if (dpcheng.FeedFLstLib) this.pnlglobal.feedFLstLib = dpcheng.FeedFLstLib;
				if (dpcheng.FeedFLstMch) this.pnlglobal.feedFLstMch = dpcheng.FeedFLstMch;
				if (dpcheng.FeedFLstMtp) this.pnlglobal.feedFLstMtp = dpcheng.FeedFLstMtp;
				if (dpcheng.FeedFLstSil) this.pnlglobal.feedFLstSil = dpcheng.FeedFLstSil;
				if (dpcheng.StatAppWdbeNavGlobal) this.pnlglobal.statapp = dpcheng.StatAppWdbeNavGlobal;
				if (dpcheng.StatShrWdbeNavGlobal) this.pnlglobal.statshr = dpcheng.StatShrWdbeNavGlobal;
				if (dpcheng.TagWdbeNavGlobal) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavGlobal);
					this.pnlglobal.tag = dpcheng.TagWdbeNavGlobal;
				}
			},

			mergeDpchEngData_pnldevdev: function(dpcheng) {
				if (dpcheng.ContIacWdbeNavDevdev) this.pnldevdev.contiac = dpcheng.ContIacWdbeNavDevdev;
				if (dpcheng.FeedFLstPrj) this.pnldevdev.feedFLstPrj = dpcheng.FeedFLstPrj;
				if (dpcheng.FeedFLstUnt) this.pnldevdev.feedFLstUnt = dpcheng.FeedFLstUnt;
				if (dpcheng.FeedFLstVer) this.pnldevdev.feedFLstVer = dpcheng.FeedFLstVer;
				if (dpcheng.StatAppWdbeNavDevdev) this.pnldevdev.statapp = dpcheng.StatAppWdbeNavDevdev;
				if (dpcheng.StatShrWdbeNavDevdev) this.pnldevdev.statshr = dpcheng.StatShrWdbeNavDevdev;
				if (dpcheng.TagWdbeNavDevdev) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavDevdev);
					this.pnldevdev.tag = dpcheng.TagWdbeNavDevdev;
				}
			},

			mergeDpchEngData_pnlcoredev: function(dpcheng) {
				if (dpcheng.ContIacWdbeNavCoredev) this.pnlcoredev.contiac = dpcheng.ContIacWdbeNavCoredev;
				if (dpcheng.FeedFLstCpr) this.pnlcoredev.feedFLstCpr = dpcheng.FeedFLstCpr;
				if (dpcheng.FeedFLstCvr) this.pnlcoredev.feedFLstCvr = dpcheng.FeedFLstCvr;
				if (dpcheng.StatAppWdbeNavCoredev) this.pnlcoredev.statapp = dpcheng.StatAppWdbeNavCoredev;
				if (dpcheng.StatShrWdbeNavCoredev) this.pnlcoredev.statshr = dpcheng.StatShrWdbeNavCoredev;
				if (dpcheng.TagWdbeNavCoredev) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavCoredev);
					this.pnlcoredev.tag = dpcheng.TagWdbeNavCoredev;
				}
			},

			mergeDpchEngData_pnlhigh: function(dpcheng) {
				if (dpcheng.ContIacWdbeNavHigh) this.pnlhigh.contiac = dpcheng.ContIacWdbeNavHigh;
				if (dpcheng.FeedFLstCmd) this.pnlhigh.feedFLstCmd = dpcheng.FeedFLstCmd;
				if (dpcheng.FeedFLstErr) this.pnlhigh.feedFLstErr = dpcheng.FeedFLstErr;
				if (dpcheng.FeedFLstMod) this.pnlhigh.feedFLstMod = dpcheng.FeedFLstMod;
				if (dpcheng.FeedFLstPph) this.pnlhigh.feedFLstPph = dpcheng.FeedFLstPph;
				if (dpcheng.FeedFLstPpl) this.pnlhigh.feedFLstPpl = dpcheng.FeedFLstPpl;
				if (dpcheng.FeedFLstSeg) this.pnlhigh.feedFLstSeg = dpcheng.FeedFLstSeg;
				if (dpcheng.FeedFLstVec) this.pnlhigh.feedFLstVec = dpcheng.FeedFLstVec;
				if (dpcheng.FeedFLstVit) this.pnlhigh.feedFLstVit = dpcheng.FeedFLstVit;
				if (dpcheng.StatAppWdbeNavHigh) this.pnlhigh.statapp = dpcheng.StatAppWdbeNavHigh;
				if (dpcheng.StatShrWdbeNavHigh) this.pnlhigh.statshr = dpcheng.StatShrWdbeNavHigh;
				if (dpcheng.TagWdbeNavHigh) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavHigh);
					this.pnlhigh.tag = dpcheng.TagWdbeNavHigh;
				}
			},

			mergeDpchEngData_pnllow: function(dpcheng) {
				if (dpcheng.ContIacWdbeNavLow) this.pnllow.contiac = dpcheng.ContIacWdbeNavLow;
				if (dpcheng.FeedFLstBnk) this.pnllow.feedFLstBnk = dpcheng.FeedFLstBnk;
				if (dpcheng.FeedFLstCdc) this.pnllow.feedFLstCdc = dpcheng.FeedFLstCdc;
				if (dpcheng.FeedFLstFst) this.pnllow.feedFLstFst = dpcheng.FeedFLstFst;
				if (dpcheng.FeedFLstGen) this.pnllow.feedFLstGen = dpcheng.FeedFLstGen;
				if (dpcheng.FeedFLstInt) this.pnllow.feedFLstInt = dpcheng.FeedFLstInt;
				if (dpcheng.FeedFLstPin) this.pnllow.feedFLstPin = dpcheng.FeedFLstPin;
				if (dpcheng.FeedFLstPrc) this.pnllow.feedFLstPrc = dpcheng.FeedFLstPrc;
				if (dpcheng.FeedFLstPrt) this.pnllow.feedFLstPrt = dpcheng.FeedFLstPrt;
				if (dpcheng.FeedFLstSig) this.pnllow.feedFLstSig = dpcheng.FeedFLstSig;
				if (dpcheng.FeedFLstSns) this.pnllow.feedFLstSns = dpcheng.FeedFLstSns;
				if (dpcheng.FeedFLstVar) this.pnllow.feedFLstVar = dpcheng.FeedFLstVar;
				if (dpcheng.StatAppWdbeNavLow) this.pnllow.statapp = dpcheng.StatAppWdbeNavLow;
				if (dpcheng.StatShrWdbeNavLow) this.pnllow.statshr = dpcheng.StatShrWdbeNavLow;
				if (dpcheng.TagWdbeNavLow) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavLow);
					this.pnllow.tag = dpcheng.TagWdbeNavLow;
				}
			},

			mergeDpchEngData_pnldeploy: function(dpcheng) {
				if (dpcheng.ContIacWdbeNavDeploy) this.pnldeploy.contiac = dpcheng.ContIacWdbeNavDeploy;
				if (dpcheng.FeedFLstCmp) this.pnldeploy.feedFLstCmp = dpcheng.FeedFLstCmp;
				if (dpcheng.FeedFLstRls) this.pnldeploy.feedFLstRls = dpcheng.FeedFLstRls;
				if (dpcheng.StatAppWdbeNavDeploy) this.pnldeploy.statapp = dpcheng.StatAppWdbeNavDeploy;
				if (dpcheng.StatShrWdbeNavDeploy) this.pnldeploy.statshr = dpcheng.StatShrWdbeNavDeploy;
				if (dpcheng.TagWdbeNavDeploy) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavDeploy);
					this.pnldeploy.tag = dpcheng.TagWdbeNavDeploy;
				}
			},

			mergeDpchEngData_pnlauxfct: function(dpcheng) {
				if (dpcheng.StatAppWdbeNavAuxfct) this.pnlauxfct.statapp = dpcheng.StatAppWdbeNavAuxfct;
				if (dpcheng.StatShrWdbeNavAuxfct) this.pnlauxfct.statshr = dpcheng.StatShrWdbeNavAuxfct;
				if (dpcheng.TagWdbeNavAuxfct) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeNavAuxfct);
					this.pnlauxfct.tag = dpcheng.TagWdbeNavAuxfct;
				}
			},

			/*
			*/

			mergeDpchEngData_content: function(dpcheng) {
				if (dpcheng["StatShr" + this.content.sref.substring(3)]) this.content.statshr = dpcheng["StatShr" + this.content.sref.substring(3)];
				if (dpcheng["Tag" + this.content.sref.substring(3)]) {
					Wdbe.unescapeBlock(dpcheng["Tag" + this.content.sref.substring(3)]);
					this.content.tag = dpcheng["Tag" + this.content.sref.substring(3)];
				}

				this.$forceUpdate();
			},

			mergeDpchEngData_contentpnlheadbar: function(dpcheng) {
				if (dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"]) {
					Wdbe.unescapeBlock(dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"]);
					this.content.pnlheadbar.tag = dpcheng["Tag" + this.content.sref.substring(3) + "Headbar"];
				}

				this.MbarContent = this["Mbar" + this.content.sref.substring(3 + 4)]
			},

			handleCrdopen: function(obj) {
				//console.log(obj.srefCrd);
				this.MenNav = "MitCrd" + obj.srefCrd.substring(3 + 4);

				this.content.sref = obj.srefCrd;
				this.content.scrJref = obj.scrJrefCrd;

				this.content.statshr = {};
				this.content.tag = {};

				this.content.initdone = false;
				this.content.pnlheadbar.initdone = false;

				this.initOther(this.content.scrJref);

				// obj content {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false}
			},

			handleAlrdlgclose: function() {
				this.MenApp = 0;
				for (var men in this.MbarContent) this.MbarContent[men].mit = 0
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppCrdopenReply") this.handleDpchAppCrdopenReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDoReply") this.handleDpchAppDoReply(obj.srefIxWdbeVDpch, obj.dpcheng);
			},

			handleUpdate: function(obj) {
				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeNavData") this.mergeDpchEngData(obj.dpcheng);

				} else if (this.initdonePnls) {
					if (obj.dpcheng.scrJref == this.statshr.scrJrefAdmin) this.mergeDpchEngData_pnladmin(obj.dpcheng);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefMon) this.mergeDpchEngData_pnlmon(obj.dpcheng);
					else if (obj.dpcheng.scrJref == this.statshr.scrJrefPre) this.mergeDpchEngData_pnlpre(obj.dpcheng);

					if (this.content.initdone) if (obj.dpcheng.scrJref == this.content.scrJref) this.mergeDpchEngData_content(obj.dpcheng);
				}
			},

			initOther: function(scrJref) {
				const dpchapp = {
					"DpchAppWdbeInit": {
						"scrJref": scrJref
					}
				};

				this.$emit("request", {scrJref: scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
			},

			handleDpchAppInitReply: function(dpcheng) {
				if (dpcheng.scrJref == this.scrJref) {
					this.mergeDpchEngData(dpcheng);
					this.initdone = true;
				}

				if (this.initdone) {
					/*
					*/
					if (dpcheng.scrJref == this.statshr.scrJrefHeadbar) {
						this.mergeDpchEngData_pnlheadbar(dpcheng);
						this.statapp.initdoneHeadbar = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefPre) {
						this.mergeDpchEngData_pnlpre(dpcheng);
						this.statapp.initdonePre = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefAdmin) {
						this.mergeDpchEngData_pnladmin(dpcheng);
						this.statapp.initdoneAdmin = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefGlobal) {
						this.mergeDpchEngData_pnlglobal(dpcheng);
						this.statapp.initdoneGlobal = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefDevdev) {
						this.mergeDpchEngData_pnldevdev(dpcheng);
						this.statapp.initdoneDevdev = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefCoredev) {
						this.mergeDpchEngData_pnlcoredev(dpcheng);
						this.statapp.initdoneCoredev = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefHigh) {
						this.mergeDpchEngData_pnlhigh(dpcheng);
						this.statapp.initdoneHigh = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefLow) {
						this.mergeDpchEngData_pnllow(dpcheng);
						this.statapp.initdoneLow = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefDeploy) {
						this.mergeDpchEngData_pnldeploy(dpcheng);
						this.statapp.initdoneDeploy = true;
					} else if (dpcheng.scrJref == this.statshr.scrJrefAuxfct) {
						this.mergeDpchEngData_pnlauxfct(dpcheng);
						this.statapp.initdoneAuxfct = true;
					} else if (dpcheng.scrJref == this.content.scrJref) {
						this.mergeDpchEngData_content(dpcheng);
						this.content.initdone = true;
					}

					if (!this.statapp.initdoneHeadbar) this.initOther(this.statshr.scrJrefHeadbar);
					else if (!this.statapp.initdonePre) this.initOther(this.statshr.scrJrefPre);
					else if (!this.statapp.initdoneAdmin) this.initOther(this.statshr.scrJrefAdmin);
					else if (!this.statapp.initdoneGlobal) this.initOther(this.statshr.scrJrefGlobal);
					else if (!this.statapp.initdoneDevdev) this.initOther(this.statshr.scrJrefDevdev);
					else if (!this.statapp.initdoneCoredev) this.initOther(this.statshr.scrJrefCoredev);
					else if (!this.statapp.initdoneHigh) this.initOther(this.statshr.scrJrefHigh);
					else if (!this.statapp.initdoneLow) this.initOther(this.statshr.scrJrefLow);
					else if (!this.statapp.initdoneDeploy) this.initOther(this.statshr.scrJrefDeploy);
					else if (!this.statapp.initdoneAuxfct) this.initOther(this.statshr.scrJrefAuxfct);
					/*
					*/
					else this.initdonePnls = true;

					if (this.content.initdone) {
						if (dpcheng.scrJref == this.content.statshr.scrJrefHeadbar) {
							this.mergeDpchEngData_contentpnlheadbar(dpcheng);
							this.content.pnlheadbar.initdone = true;
						}
		
						if (!this.content.pnlheadbar.initdone) this.initOther(this.content.statshr.scrJrefHeadbar);
					}
				}
			},

			handleDpchAppDoReply: function(srefIxWdbeVDpch, dpcheng) {
				if (srefIxWdbeVDpch == "DpchEngWdbeNavData") this.mergeDpchEngData(dpcheng);
				else if (srefIxWdbeVDpch == "DpchEngWdbeNavPreData") this.mergeDpchEngData_pnlpre(dpcheng);
			},

			handleDpchAppCrdopenReply: function(dpcheng) {
				if (dpcheng.accepted) {
					//console.log("CrdWdbeNav.handleDpchAppCrdopenReply() accepted");

					this.$emit("crdopen", {srefCrd: dpcheng.sref, scrJrefCrd: dpcheng.scrJref, newtabNotInplace: false});

				} else {
					//console.log("CrdWdbeNav.handleDpchAppCrdopenReply() denied");
				}
			},

			// (static) CrdNav.MenApp: tag

			// (static) CrdNav.MenSes: tag, continf (pop-up)

			// (dynamic) CrdNav.MenCrd: pnl*.tag (module), crd.tag (mit). pnl*.continf (history)
			MenCrdHdg: function(pnlsref) {
				if (this[pnlsref] == null) return pnlsref;
				return this[pnlsref].tag.Cpt;
			},

			mitsCrd: function(mitsAll) {
				var mits = [];

				for (const ctlsref of mitsAll) {
					if (this.statshr[ctlsref + "Avail"] != null) if (this.statshr[ctlsref + "Avail"] == false) continue;
					mits.push(ctlsref);
				}
					
				return mits
			},

			MitCrd: function(ctlsref) {
				if (this.tag[ctlsref] == null) return ctlsref;
				return this.tag[ctlsref]
			},

			MitCrdActive: function(ctlsref) {
				if (this.statshr[ctlsref + "Active"] == null) return true;
				return this.statshr[ctlsref + "Active"]
			},

			// (dynamic) PnlNavPre: tag, continf

			// (dynamic) content.Mbar: pnlheadbar.tag (men), crd.tag (mit)
			MenContentHdg: function(ctlsref) {
				if (this.content.pnlheadbar.tag == null) return ctlsref;
				if (this.content.pnlheadbar.tag[ctlsref] == null) return ctlsref;
				return this.content.pnlheadbar.tag[ctlsref];
			},

			mitsContent: function(mitsAll) {
				var mits = [];

				for (const ctlsref of mitsAll) {
					if (this.content.statshr[ctlsref + "Avail"] != null) if (this.content.statshr[ctlsref + "Avail"] == false) continue;
					mits.push(ctlsref);
				}

				return mits
			},

			MitContent: function(ctlsref) {
				if (this.content.tag == null) return ctlsref;
				if (this.content.tag[ctlsref] == null) return ctlsref;
				return this.content.tag[ctlsref];
			},

			MitContentActive: function(ctlsref) {
				if (this.content.statshr == null) return true;
				if (this.content.statshr[ctlsref + "Active"] == null) return true;
				return this.content.statshr[ctlsref + "Active"]
			},

			LstHist: function(pnlsref, short) {
				var retval = "";
				const feed = this[pnlsref]["feedFLst" + short];

				if (feed != null)
					for (var i = 0; i < feed.length; i++) {
						var fi = feed[i];
						retval += "<p class='mb-0'>" + fi.tit1 + "</p>";
					}

				return retval;
			}
		},

		computed: {
			CptTitle: function() {
				return Wdbe.title;
			},

			CptVersion: function() {
				return("v" + Wdbe.version);
			},

			MenApp: {
				get() {
					return this.MenApp_last;
				},
				set(sel) {
					if (sel == null) this.MenApp_last = 0;
					else this.MenApp_last = sel;
					
					return sel;
				}
			},

			mitsPre: function() {
				var mits = [];

				for (const short of this.MenPre) if (this.pnlpre.statshr["Txt" + short + "Avail"]) mits.push(short);

				return mits
			}
		},

		data: () => ({
			initdone: false,
			initdonePnls: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/

			MenApp_last: 0,

			/*
			*/
			MenPre: ["Cvr", "Unt", "Ver"],
			/*
			*/

			/*
			*/
			MenCrd: [
				{
					pnlsref: "pnladmin",
					mits: ["MitCrdUsg", "MitCrdUsr", "MitCrdPrs", "MitCrdFil"]
				},
				{
					pnlsref: "pnlglobal",
					mits: ["MitCrdMch", "MitCrdLib", "MitCrdFam", "MitCrdSil", "MitCrdMtp"]
				},
				{
					pnlsref: "pnldevdev",
					mits: ["MitCrdPrj", "MitCrdVer", "MitCrdUnt"]
				},
				{
					pnlsref: "pnlcoredev",
					mits: ["MitCrdCpr", "MitCrdCvr"]
				},
				{
					pnlsref: "pnlhigh",
					mits: ["MitCrdPph", "MitCrdMod", "MitCrdVec", "MitCrdCmd", "MitCrdErr", "MitCrdPpl", "MitCrdSeg"]
				},
				{
					pnlsref: "pnllow",
					mits: ["MitCrdBnk", "MitCrdPin", "MitCrdInt", "MitCrdSig"]
				},
				{
					pnlsref: "pnldeploy",
					mits: ["MitCrdCmp", "MitCrdRls"]
				},
				{
					pnlsref: "pnlauxfct",
					mits: ["MitCrdUtl"]
				}
			],
			/*
			*/

			/*
			*/
			pnlheadbar: {
			},

			pnlpre: {
				statshr: null
			},

			pnladmin: {
			},

			pnlglobal: {
			},

			pnldevdev: {
			},

			pnlcoredev: {
			},

			pnlhigh: {
			},

			pnllow: {
			},

			pnldeploy: {
			},

			pnlauxfct: {
			},

			/*
			*/

			content: {
				sref: "",
				scrJref: "",

				statshr: null,

				pnlheadbar: {
					initdone: false
				},

				initdone: false
			},

			/*
			*/
			MbarUsg: [
			],

			MbarUsr: [
				{
					sref: "MenCrd",
					mits: ["MitCrdMkp"]
				}
			],

			MbarPrs: [
			],

			MbarFil: [
				{
					sref: "MenCrd",
					mits: ["MitCrdNew", "MitCrdDld"]
				}
			],

			MbarMch: [
			],

			MbarLib: [
			],

			MbarFam: [
			],

			MbarSil: [
			],

			MbarMtp: [
			],

			MbarPrj: [
				{
					sref: "MenCrd",
					mits: ["MitCrdNew", "MitCrdIpx"]
				}
			],

			MbarVer: [
				{
					sref: "MenCrd",
					mits: ["MitCrdNew", "MitCrdPcv", "MitCrdIdp", "MitCrdImd", "MitCrdIcs", "MitCrdIda", "MitCrdGfs", "MitCrdIfs", "MitCrdFnm"]
				}
			],

			MbarUnt: [
			],

			MbarCpr: [
				{
					sref: "MenCrd",
					mits: ["MitCrdNew"]
				}
			],

			MbarCvr: [
				{
					sref: "MenCrd",
					mits: ["MitCrdNew", "MitCrdIbs", "MitCrdIds", "MitCrdWco"]
				}
			],

			MbarPph: [
			],

			MbarMod: [
			],

			MbarVec: [
			],

			MbarVit: [
			],

			MbarCmd: [
			],

			MbarErr: [
			],

			MbarPpl: [
			],

			MbarSeg: [
			],

			MbarBnk: [
			],

			MbarPin: [
			],

			MbarInt: [
			],

			MbarSns: [
			],

			MbarVar: [
			],

			MbarGen: [
			],

			MbarPrt: [
			],

			MbarSig: [
			],

			MbarCdc: [
			],

			MbarPrc: [
			],

			MbarFst: [
			],

			MbarCmp: [
			],

			MbarRls: [
				{
					sref: "MenCrd",
					mits: ["MitCrdSrt", "MitCrdCrt", "MitCrdFrt", "MitCrdWco"]
				}
			],

			MbarUtl: [
				{
					sref: "MenCrd",
					mits: ["MitCrdXip", "MitCrdMip"]
				}
			],

			/*
			*/

			MbarContent: null,

			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
