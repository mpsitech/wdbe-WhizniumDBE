<template>
	<v-layout class="fill-height">
		<v-navigation-drawer app floating width="350" class="elevation-1">
			<CrdWdbeNav
				v-on:crdopen="handleCrdopen"
				v-on:dlgopen="handleDlgopen"
				v-on:dlgclose="handleDlgclose"
				v-on:request="handleRequestFromCrdnav"
				ref="CrdWdbeNav"
				:scrJref=scrJrefCrdnav
			/>
		</v-navigation-drawer>
		<component
			:key="srefCrd"
			v-bind:is="content"
			v-on:crdopen="handleCrdopen"
			v-on:dlgopen="handleDlgopen"
			v-on:dlgclose="handleDlgclose"
			v-on:request="handleRequestFromCrd"
			v-on:upload="handleUpload"
			ref="content"
			:scrJref=scrJrefCrd
		/>
		<v-dialog
			v-model="alert"
			v-if="alert"
			persistent
			width="500"
		>
			<v-card>
				<v-card-title>
					{{alert.TxtCpt}}
				</v-card-title>
				<v-card-text>
					<div
						v-for="(TxtMsg, ix) in alert.TxtMsgs"
						:key="ix"
					>
						{{TxtMsg ? TxtMsg : '&nbsp;'}}
					</div>
				</v-card-text>
				<v-divider/>
				<v-card-actions>
					<v-spacer/>
					<v-btn
						class="primary"
						v-for="Fi in alert.FeedFMcbAlert"
						:key="Fi.num"
						v-on:click="handleAlertAction(Fi.num)"
					>
						{{Fi.tit1}}
					</v-btn>
				</v-card-actions>
			</v-card>
		</v-dialog>
		<v-dialog
			v-model="dialog"
			v-if="dialog"
			persistent
			width="1200"
		>
			<component
				:key="srefDlg"
				v-bind:is="dialog"
				v-on:upload="handleUpload"
				v-on:request="handleRequestFromDlg"
				ref="dialog"
				:scrJref=scrJrefDlg
			/>
		</v-dialog>
	</v-layout>
</template>

<script>
	import axios from 'axios'

	import Wdbe from '../scripts/Wdbe';

	/*
	*/
	import CrdWdbeUsg from './CrdWdbeUsg/CrdWdbeUsg';
	import CrdWdbeUsr from './CrdWdbeUsr/CrdWdbeUsr';
	import DlgWdbeUsrMngkeypair from './CrdWdbeUsr/DlgWdbeUsrMngkeypair';
	import CrdWdbePrs from './CrdWdbePrs/CrdWdbePrs';
	import CrdWdbeFil from './CrdWdbeFil/CrdWdbeFil';
	import DlgWdbeFilDownload from './CrdWdbeFil/DlgWdbeFilDownload';
	import DlgWdbeFilNew from './CrdWdbeFil/DlgWdbeFilNew';
	import CrdWdbeNav from './CrdWdbeNav/CrdWdbeNav';
	import DlgWdbeNavLoaini from './CrdWdbeNav/DlgWdbeNavLoaini';
	import DlgWdbeNavMnglic from './CrdWdbeNav/DlgWdbeNavMnglic';
	import CrdWdbeMch from './CrdWdbeMch/CrdWdbeMch';
	import CrdWdbeLib from './CrdWdbeLib/CrdWdbeLib';
	import CrdWdbeFam from './CrdWdbeFam/CrdWdbeFam';
	import CrdWdbeSil from './CrdWdbeSil/CrdWdbeSil';
	import CrdWdbeMtp from './CrdWdbeMtp/CrdWdbeMtp';
	import CrdWdbePrj from './CrdWdbePrj/CrdWdbePrj';
	import DlgWdbePrjImpex from './CrdWdbePrj/DlgWdbePrjImpex';
	import DlgWdbePrjNew from './CrdWdbePrj/DlgWdbePrjNew';
	import CrdWdbeVer from './CrdWdbeVer/CrdWdbeVer';
	import DlgWdbeVerCmdset from './CrdWdbeVer/DlgWdbeVerCmdset';
	import DlgWdbeVerCustfst from './CrdWdbeVer/DlgWdbeVerCustfst';
	import DlgWdbeVerDflalg from './CrdWdbeVer/DlgWdbeVerDflalg';
	import DlgWdbeVerFinmod from './CrdWdbeVer/DlgWdbeVerFinmod';
	import DlgWdbeVerGenfst from './CrdWdbeVer/DlgWdbeVerGenfst';
	import DlgWdbeVerMdlstr from './CrdWdbeVer/DlgWdbeVerMdlstr';
	import DlgWdbeVerNew from './CrdWdbeVer/DlgWdbeVerNew';
	import CrdWdbeSys from './CrdWdbeSys/CrdWdbeSys';
	import CrdWdbeTrg from './CrdWdbeTrg/CrdWdbeTrg';
	import CrdWdbeUnt from './CrdWdbeUnt/CrdWdbeUnt';
	import CrdWdbeRls from './CrdWdbeRls/CrdWdbeRls';
	import DlgWdbeRlsFinreptr from './CrdWdbeRls/DlgWdbeRlsFinreptr';
	import DlgWdbeRlsNew from './CrdWdbeRls/DlgWdbeRlsNew';
	import DlgWdbeRlsStareptr from './CrdWdbeRls/DlgWdbeRlsStareptr';
	import DlgWdbeRlsWrite from './CrdWdbeRls/DlgWdbeRlsWrite';
	import CrdWdbeCpr from './CrdWdbeCpr/CrdWdbeCpr';
	import DlgWdbeCprNew from './CrdWdbeCpr/DlgWdbeCprNew';
	import CrdWdbeCvr from './CrdWdbeCvr/CrdWdbeCvr';
	import DlgWdbeCvrBsccd from './CrdWdbeCvr/DlgWdbeCvrBsccd';
	import DlgWdbeCvrDetcd from './CrdWdbeCvr/DlgWdbeCvrDetcd';
	import DlgWdbeCvrNew from './CrdWdbeCvr/DlgWdbeCvrNew';
	import DlgWdbeCvrWrite from './CrdWdbeCvr/DlgWdbeCvrWrite';
	import CrdWdbePph from './CrdWdbePph/CrdWdbePph';
	import CrdWdbeMod from './CrdWdbeMod/CrdWdbeMod';
	import CrdWdbeVec from './CrdWdbeVec/CrdWdbeVec';
	import CrdWdbeVit from './CrdWdbeVit/CrdWdbeVit';
	import CrdWdbeCmd from './CrdWdbeCmd/CrdWdbeCmd';
	import CrdWdbeErr from './CrdWdbeErr/CrdWdbeErr';
	import CrdWdbePpl from './CrdWdbePpl/CrdWdbePpl';
	import CrdWdbeSeg from './CrdWdbeSeg/CrdWdbeSeg';
	import CrdWdbeBnk from './CrdWdbeBnk/CrdWdbeBnk';
	import CrdWdbePin from './CrdWdbePin/CrdWdbePin';
	import CrdWdbeInt from './CrdWdbeInt/CrdWdbeInt';
	import CrdWdbeSns from './CrdWdbeSns/CrdWdbeSns';
	import CrdWdbeVar from './CrdWdbeVar/CrdWdbeVar';
	import CrdWdbeGen from './CrdWdbeGen/CrdWdbeGen';
	import CrdWdbePrt from './CrdWdbePrt/CrdWdbePrt';
	import CrdWdbeSig from './CrdWdbeSig/CrdWdbeSig';
	import CrdWdbePrc from './CrdWdbePrc/CrdWdbePrc';
	import CrdWdbeFst from './CrdWdbeFst/CrdWdbeFst';
	import CrdWdbeUtl from './CrdWdbeUtl/CrdWdbeUtl';
	import DlgWdbeUtlExtrip from './CrdWdbeUtl/DlgWdbeUtlExtrip';
	import DlgWdbeUtlMrgip from './CrdWdbeUtl/DlgWdbeUtlMrgip';
	/*
	*/

	const dpch = axios.create({
		baseURL: window.location.protocol + "//" + Wdbe.hostname() + ":" + Wdbe.appsrvport() + "/dpch"
	})

	const notify = axios.create({
		baseURL: window.location.protocol + "//" + Wdbe.hostname() + ":" + Wdbe.appsrvport() + "/notify/json"
	})

	export default {
		name: 'SessWdbe',

		props: {
			scrJrefSess: String,
			scrJrefCrdnav: String,

			srefCrd_initial: String,
			scrJrefCrd_initial: String
		},

		components: {
			/*
			*/
			CrdWdbeUsg,
			CrdWdbeUsr,
			DlgWdbeUsrMngkeypair,
			CrdWdbePrs,
			CrdWdbeFil,
			DlgWdbeFilDownload,
			DlgWdbeFilNew,
			CrdWdbeNav,
			DlgWdbeNavLoaini,
			DlgWdbeNavMnglic,
			CrdWdbeMch,
			CrdWdbeLib,
			CrdWdbeFam,
			CrdWdbeSil,
			CrdWdbeMtp,
			CrdWdbePrj,
			DlgWdbePrjImpex,
			DlgWdbePrjNew,
			CrdWdbeVer,
			DlgWdbeVerCmdset,
			DlgWdbeVerCustfst,
			DlgWdbeVerDflalg,
			DlgWdbeVerFinmod,
			DlgWdbeVerGenfst,
			DlgWdbeVerMdlstr,
			DlgWdbeVerNew,
			CrdWdbeSys,
			CrdWdbeTrg,
			CrdWdbeUnt,
			CrdWdbeRls,
			DlgWdbeRlsFinreptr,
			DlgWdbeRlsNew,
			DlgWdbeRlsStareptr,
			DlgWdbeRlsWrite,
			CrdWdbeCpr,
			DlgWdbeCprNew,
			CrdWdbeCvr,
			DlgWdbeCvrBsccd,
			DlgWdbeCvrDetcd,
			DlgWdbeCvrNew,
			DlgWdbeCvrWrite,
			CrdWdbePph,
			CrdWdbeMod,
			CrdWdbeVec,
			CrdWdbeVit,
			CrdWdbeCmd,
			CrdWdbeErr,
			CrdWdbePpl,
			CrdWdbeSeg,
			CrdWdbeBnk,
			CrdWdbePin,
			CrdWdbeInt,
			CrdWdbeSns,
			CrdWdbeVar,
			CrdWdbeGen,
			CrdWdbePrt,
			CrdWdbeSig,
			CrdWdbePrc,
			CrdWdbeFst,
			CrdWdbeUtl,
			DlgWdbeUtlExtrip,
			DlgWdbeUtlMrgip
			/*
			*/
		},

		beforeMount() {
			this.srefCrd = this.srefCrd_initial;
			this.scrJrefCrd = this.scrJrefCrd_initial;

			this.content = this.srefCrd_initial;

			this.iterateNotify();
		},

		methods: {
			showAlert(dpcheng) {
				let continf = dpcheng.ContInfWdbeAlert;

				Wdbe.unescapeBlock(continf);

				dpcheng.TxtCpt = continf.TxtCpt; delete continf.TxtCpt;

				var i = 12;
				if (continf.TxtMsg12 == "") {
					i--;
					if (continf.TxtMsg11 == "") {
						i--;
						if (continf.TxtMsg10 == "") {
							i--;
							if (continf.TxtMsg9 == "") {
								i--;
								if (continf.TxtMsg8 == "") {
									i--;
									if (continf.TxtMsg7 == "") {
										i--;
										if (continf.TxtMsg6 == "") {
											i--;
											if (continf.TxtMsg5 == "") {
												i--;
												if (continf.TxtMsg4 == "") {
													i--;
													if (continf.TxtMsg3 == "") {
														i--;
														if (continf.TxtMsg2 == "") {
															i--;
															if (continf.TxtMsg1 == "") i--;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}

				dpcheng.TxtMsgs = new Array();
				if (i > 0) dpcheng.TxtMsgs.push(continf.TxtMsg1);
				if (i > 1) dpcheng.TxtMsgs.push(continf.TxtMsg2);
				if (i > 2) dpcheng.TxtMsgs.push(continf.TxtMsg3);
				if (i > 3) dpcheng.TxtMsgs.push(continf.TxtMsg4);
				if (i > 4) dpcheng.TxtMsgs.push(continf.TxtMsg5);
				if (i > 5) dpcheng.TxtMsgs.push(continf.TxtMsg6);
				if (i > 6) dpcheng.TxtMsgs.push(continf.TxtMsg7);
				if (i > 7) dpcheng.TxtMsgs.push(continf.TxtMsg8);
				if (i > 8) dpcheng.TxtMsgs.push(continf.TxtMsg9);
				if (i > 9) dpcheng.TxtMsgs.push(continf.TxtMsg10);
				if (i > 10) dpcheng.TxtMsgs.push(continf.TxtMsg11);
				if (i > 11) dpcheng.TxtMsgs.push(continf.TxtMsg12);

				delete continf.TxtMsg1;
				delete continf.TxtMsg2;
				delete continf.TxtMsg3;
				delete continf.TxtMsg4;
				delete continf.TxtMsg5;
				delete continf.TxtMsg6;
				delete continf.TxtMsg7;
				delete continf.TxtMsg8;
				delete continf.TxtMsg9;
				delete continf.TxtMsg10;
				delete continf.TxtMsg11;
				delete continf.TxtMsg12;

				this.alert = dpcheng;
			},

			handleAlertAction: function(num) {
				const dpchapp = {
					"DpchAppWdbeAlert": {
						"scrJref": this.alert.scrJref,
						"numFMcb": num
					}
				};
	
				this.handleRequest({scrJref: this.alert.scrJref, dpchapp: dpchapp, then: ""}, false);

				this.alert = null;

				this.$refs.CrdWdbeNav.handleAlrdlgclose();
			},

			handleCrdopen: function(obj) {
				//console.log("SessWdbe.handleCrdopen() with " + obj.srefCrd);

				if ((obj.srefCrd != this.content) || obj.newtabNotInplace) {
					if (!obj.newtabNotInplace) {
						//console.log("SessWdbe.handleCrdopen() new card in-place");

						this.srefCrd = obj.srefCrd;
						this.scrJrefCrd = obj.scrJrefCrd;

						this.content = obj.srefCrd;

						this.$refs.CrdWdbeNav.handleCrdopen(obj)

					} else {
						//console.log("SessWdbe.handleCrdopen() new card in new tab");

						var paramBegin = window.location.href.indexOf("?");
						var url = window.location.href.substring(0, (paramBegin == -1) ? window.location.href.length : paramBegin);
						window.open(url + "?scrJrefCrdnav=" + this.scrJrefCrdnav + "&srefCrd=" + obj.srefCrd + "&scrJrefCrd=" + obj.scrJrefCrd, "_blank");
					}
				}
			},

			handleDlgopen: function(obj) {
				if (obj.srefDlg != this.dialog) {
					this.srefDlg = obj.srefDlg;
					this.scrJrefDlg = obj.scrJrefDlg;

					this.dialog = obj.srefDlg;
				}
			},

			handleDlgclose: function() {
				this.srefDlg = "";
				this.scrJrefDlg = "";

				this.dialog = null;

				this.$refs.CrdWdbeNav.handleAlrdlgclose();
			},

			handleRequestFromCrdnav: function(obj) {
				this.handleRequest(obj, false, false);
			},

			handleRequestFromCrd: function(obj) {
				this.handleRequest(obj, false, true);
			},

			handleRequestFromDlg: function(obj) {
				this.handleRequest(obj, true, false);
			},

			handleRequest: function(obj, srcDlgNotCrd, srcCrdNotCrdnav) {
				const data = "json=" + encodeURIComponent(JSON.stringify(obj.dpchapp));

				var vm = this;

				dpch.post('', data).then(function (response) {
					const scrJref = obj.dpchapp[Object.keys(obj.dpchapp)[0]].scrJref;
					const srefIxWdbeVDpch = Object.keys(response.data)[0];
					const dpcheng = response.data[srefIxWdbeVDpch];

					const target = (srcDlgNotCrd) ? vm.$refs.dialog : (srcCrdNotCrdnav) ? vm.$refs.content : vm.$refs.CrdWdbeNav;
					if (target) {
						target.handleReply({scrJref: scrJref, srefIxWdbeVDpch: srefIxWdbeVDpch, dpcheng: dpcheng, then: obj.then});
						if (dpcheng.scrJref == vm.scrJrefCrd) {
							if (target != vm.$refs.CrdWdbeNav) vm.$refs.CrdWdbeNav.handleUpdate({srefIxWdbeVDpch: srefIxWdbeVDpch, dpcheng: dpcheng});
							else if (vm.$refs.content) if (target != vm.$refs.content) vm.$refs.content.handleUpdate({srefIxWdbeVDpch: srefIxWdbeVDpch, dpcheng: dpcheng});
						}
					}

				}).catch(function (error) {
					console.log("SessWdbe.handleRequest() error: " + error);
				});
			},

			handleUpload: function(obj) {
				var formData = new FormData()

				formData.append("file", obj.file, obj.file.name);

				axios.post(window.location.protocol + "//" + Wdbe.hostname() + ":" + Wdbe.appsrvport() + "/upload/" + obj.scrJref, formData).catch(function (error) {
					console.log("SessWdbe.handleUpload() error: " + error);
				});
			},

			iterateNotify: function() {
				var vm = this;

				notify.get(this.scrJrefSess).then(function (response) {
					var iterate = true;

					const srefIxWdbeVDpch = Object.keys(response.data)[0];
					const dpcheng = response.data[srefIxWdbeVDpch];

					//console.log("SessWdbe.iterateNotify() received " + srefIxWdbeVDpch);

					if (dpcheng.scrJref == vm.scrJrefSess) {
						if (srefIxWdbeVDpch == "DpchEngWdbeConfirm")
							if (!dpcheng.accepted) {
								vm.$emit('logout');
								iterate = false;
							}

					} else if (srefIxWdbeVDpch == "DpchEngWdbeAlert") vm.showAlert(dpcheng);
					else {
						var processed = false;
						const target = (dpcheng.scrJref == vm.scrJrefDlg) ? vm.$refs.dialog : (dpcheng.scrJref != vm.scrJrefCrdnav) ? vm.$refs.content : vm.$refs.CrdWdbeNav;
						processed = target.handleUpdate({srefIxWdbeVDpch: srefIxWdbeVDpch, dpcheng: dpcheng});
						if (!processed || (dpcheng.scrJref == vm.scrJrefCrd)) vm.$refs.CrdWdbeNav.handleUpdate({srefIxWdbeVDpch: srefIxWdbeVDpch, dpcheng: dpcheng});
					}

					if (iterate) vm.iterateNotify();

				}).catch(function (error) {
					console.log("SessWdbe.iterateNotify() error: " + error);
				});
			}
		},

		data: () => ({
			content: "",

			srefCrd: "",
			scrJrefCrd: "",
			scrJrefDlg: "",

			alert: null,

			dialog: null
		})
	}
</script>
