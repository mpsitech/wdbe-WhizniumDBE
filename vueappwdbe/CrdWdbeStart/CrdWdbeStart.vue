<template>
	<v-container class="py-6" fill-height fluid>
		<v-card class="pa-3 mx-auto" min-width="600">
			<v-card-title>
				<div class="mx-auto my-3 text-center">{{CptVersion}}</div>
			</v-card-title>

			<v-card-text>
				<v-row>
					<v-col cols="6"/>
					<v-col cols="6">
						<v-select
							v-model="fiFPupLocale"
							:items="feedFPupLocale"
							:label="tag.CptLocale"
							v-on:change="handlePupLocaleChange"
						>
							<template v-slot:selection="{item}">{{item.tit1}}</template>
							<template v-slot:item="{item}">{{item.tit1}}</template>
						</v-select>
					</v-col>
				</v-row>

				<v-text-field
					v-model="TxfUsername"
					:label="tag.CptLoginUsername"
				/>

				<v-text-field
					v-model="TxfPassword"
					:label="tag.CptLoginPassword"
					:type="TxfPasswordShow ? 'text' : 'password'"
					:append-icon="TxfPasswordShow ? 'mdi-eye' : 'mdi-eye-off'"
					v-on:keyup.enter="handleTxfPasswordEnter"
					@click:append="TxfPasswordShow = !TxfPasswordShow"
				/>

				<div v-if="CptMessageAvail" class="pa-1 my-3" :class="CptMessageClass">{{CptMessage}}</div>

				<div class="my-6">
					<v-btn
						block
						class="primary"
						v-on:click="handleLogin"
					>
						{{tag.ButLoginLogin}}
					</v-btn>
				</div>
			</v-card-text>
		</v-card>
	</v-container>
</template>

<script>
	import axios from 'axios'

	import Wdbe from '../../scripts/Wdbe';

	const dpch = axios.create({
		baseURL: window.location.protocol + "//" + Wdbe.hostname() + ":" + Wdbe.appsrvport() + "/dpch"
	})

	function getFiBySref(feed, sref) {
		for (var i = 0; i < feed.length; i++) if (feed[i].sref == sref) return feed[i];
	}

	export default {
		name: 'CrdWdbeStart',

		props: {
			srefIxVSge_initial: String
		},

		beforeMount() {
			this.fiFSge = getFiBySref(this.feedFSge, this.srefIxVSge_initial);
		},

		methods: {

			handleLogin: function() {
				const dpchapp = {
					"DpchAppRootWdbeLogin": {
						"scrJref": "",
						"username": this.TxfUsername,
						"password": this.TxfPassword,
						"m2mNotReg": false
					}
				};
				
				const data = "json=" + encodeURIComponent(JSON.stringify(dpchapp));

				var vm = this;

				dpch.post('', data).then(function (response) {
					const dpcheng = response.data.DpchEngWdbeConfirm;

					if (dpcheng.accepted) {
						//console.log("CrdWdbeStart.handleLogin() login accepted");

						vm.fiFSge = getFiBySref(vm.feedFSge, "acc");

						vm.initSess(dpcheng.scrJref);

					} else {
						//console.log("CrdWdbeStart.handleLogin() login denied");

						vm.fiFSge = getFiBySref(vm.feedFSge, "dny");
					}

				}).catch(function (error) {
					console.log("CrdWdbeStart.handleLogin() error: " + error);
				});
			},

			initSess: function(scrJrefSess) {
				const dpchapp = {
					"DpchAppWdbeInit": {
						"scrJref": scrJrefSess
					}
				}

				const data = "json=" + encodeURIComponent(JSON.stringify(dpchapp));

				var vm = this;

				dpch.post('', data).then(function (response) {
					const dpcheng = response.data.DpchEngSessWdbeData;

					vm.$emit("login", {scrJrefSess: scrJrefSess, scrJrefCrdnav: dpcheng.StatShrSessWdbe.scrJrefCrdnav});

				}).catch(function (error) {
					console.log("CrdWdbeStart.initSess() error: " + error);
				});
			},

			handlePupLocaleChange: function() {
				this.numFPupLocale = this.fiFPupLocale.num; // changes feedFPupLocale

				for (var i = 0; i < this.feedFPupLocale.length; i++)
					if (this.feedFPupLocale[i].num == this.numFPupLocale) {
						this.fiFPupLocale = this.feedFPupLocale[i];
						break;
					}

				//console.log("CrdWdbeStart.handlePupLocaleChange() new locale is " + this.fiFPupLocale.sref);
			},

			handleTxfPasswordEnter: function() {
				this.handleLogin()
			}
		},

		computed: {
			CptVersion() {
				return(Wdbe.title + " v" + Wdbe.version);
			},

			feedFPupLocale() {
				/*
				*/
				if (this.numFPupLocale == 1) return this.feedFPupLocales.enus;
				/*
				*/
				return null;
			},

			tag() {
				/*
				*/
				if (this.numFPupLocale == 1) return this.tags.enus;
				/*
				*/
				return null;
			},

			CptMessageAvail() {
				return(this.fiFSge.sref != "idle");
			},

			CptMessageClass() {
				if (this.fiFSge.sref == "acc") return "success";
				else if (this.fiFSge.sref == "dny") return "error";
				return "info";
			},

			CptMessage() {
				if (this.fiFSge.sref == "acc") return this.tag.CptSuccess;
				else if (this.fiFSge.sref == "dny") return this.tag.CptFailureMessage;
				else if (this.fiFSge.sref == "term") return this.tag.CptLogoutMessage;
				return "CptMessage";
			}

		},

		data: () => ({
			fiFSge: null,

			TxfUsername: "",

			TxfPassword: "",
			TxfPasswordShow: false,

			numFPupLocale: 1,

			/*
			*/
			fiFPupLocale: {
				num: 1,
				sref: "enus",
				tit1: "English (United States)"
			},

			feedFPupLocales: {
				enus: [
					{
						num: 1,
						sref: "enus",
						tit1: "English (United States)"
					}
				]
			},
			/*
			*/

			tags: {
				/*
				*/
				enus: {
					ButFailureBack: "Back",
					ButLoginLogin: "Log in",
					ButLoginReset: "Reset",
					ButLogoutLogin: "Login screen",
					ButSuccessBack: "Back",
					ButSuccessNewsess: "Start new session",
					ButSuccessSuspsessResume: "Resume",
					CptFailure: "Error",
					CptFailureMessage: "Login failed.",
					CptLogin: "Login",
					CptLoginPassword: "Password",
					CptLoginUsername: "User name",
					CptLogout: "Logout",
					CptLogoutMessage: "Your session has been terminated.",
					CptSuccess: "Login successful",
					CptSuccessSuspsess: "Suspended sessions"
				}
				/*
				*/
			},

			feedFSge: [
				{
					num: 1,
					sref: "idle"
				},
				{
					num: 2,
					sref: "acc"
				},
				{
					num: 3,
					sref: "dny"
				},
				{
					num: 4,
					sref: "term"
				}
			]
		})
	}
</script>
