<template>
	<v-card v-if="initdone" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{tag.Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end"/>
			</v-row>
			<v-tabs
				v-model="numFDse"
				align-with-title
			>
				<v-tabs-slider></v-tabs-slider>
				<v-tab v-for="{num, tit1} in feedFDse" :key="num">{{tit1}}</v-tab>
			</v-tabs>
		</v-card-title>
		<v-card-text>
			<v-tabs-items v-model="numFDse">
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-text-field
								class="my-1"
								readonly
								outlined
								v-model="continffnm.TxtPrg"
								:label="tagfnm.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('fnm', 'ButRunClick')"
										:disabled="!statshrfnm.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagfnm.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('fnm', 'ButStoClick')"
										:disabled="!statshrfnm.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagfnm.ButSto}}
									</v-btn>
								</v-col>
							</v-row>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-btn
								download
								:href="hrefDld"
								:disabled="!statshrlfi.DldActive"
								class="my-1"
								color="primary"
							>
								{{taglfi.Dld}}
							</v-btn>
						</v-card-text>
					</v-card>
				</v-tab-item>
			</v-tabs-items>
		</v-card-text>
		<v-divider/>
		<v-card-actions>
			<v-spacer/>
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButDneClick')"
			>
				{{tag.ButDne}}
			</v-btn>
		</v-card-actions>
	</v-card>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'DlgWdbeVerFinmod',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeVerFinmod.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWdbeInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ditshort, ctlsref) {
				var dpchapp = {
					"DpchAppDlgWdbeVerFinmodDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWdbeVerFinmodDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeVerFinmod"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacfnm") != -1) dpchapp["ContIacDlgWdbeVerFinmodFnm"] = this.contiacfnm;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWdbeVerFinmodLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeVerFinmodData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeVerFinmodData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeVerFinmod) this.contiac = dpcheng.ContIacDlgWdbeVerFinmod;
				if (dpcheng.ContInfDlgWdbeVerFinmod) this.continf = dpcheng.ContInfDlgWdbeVerFinmod;
				if (dpcheng.ContInfDlgWdbeVerFinmodFnm) this.continffnm = dpcheng.ContInfDlgWdbeVerFinmodFnm;
				if (dpcheng.ContInfDlgWdbeVerFinmodLfi) this.continflfi = dpcheng.ContInfDlgWdbeVerFinmodLfi;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeVerFinmod) this.statapp = dpcheng.StatAppDlgWdbeVerFinmod;
				if (dpcheng.StatShrDlgWdbeVerFinmod) this.statshr = dpcheng.StatShrDlgWdbeVerFinmod;
				if (dpcheng.StatShrDlgWdbeVerFinmodFnm) this.statshrfnm = dpcheng.StatShrDlgWdbeVerFinmodFnm;
				if (dpcheng.StatShrDlgWdbeVerFinmodLfi) this.statshrlfi = dpcheng.StatShrDlgWdbeVerFinmodLfi;
				if (dpcheng.TagDlgWdbeVerFinmod) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeVerFinmod);
					this.tag = dpcheng.TagDlgWdbeVerFinmod;
				}
				if (dpcheng.TagDlgWdbeVerFinmodFnm) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeVerFinmodFnm);
					this.tagfnm = dpcheng.TagDlgWdbeVerFinmodFnm;
				}
				if (dpcheng.TagDlgWdbeVerFinmodLfi) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeVerFinmodLfi);
					this.taglfi = dpcheng.TagDlgWdbeVerFinmodLfi;
				}
				/*
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWdbeVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWdbeVDpch, dpcheng) {
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeVerFinmodData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeVerFinmodData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			hrefDld: function() {
				return window.location.protocol + '//' + Wdbe.hostname() + ':' + Wdbe.appsrvport() + '/download/' + this.scrJref;
			},

			numFDse: {
				get() {
					return this.contiac.numFDse - 1;
				},
				set(sel) {
					if (sel == null) this.contiac.numFDse = 1;
					else this.contiac.numFDse = sel + 1;

					return sel;
				}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			continffnm: null,

			continflfi: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrfnm: null,

			statshrlfi: null,

			tag: null,

			tagfnm: null,

			taglfi: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
