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
								v-if="statshrdet.TxfGrlAvail"
								class="my-1"
								v-model="contiacdet.TxfGrl"
								:label="tagdet.CptGrl"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('det', 'ButStaClick')"
										:disabled="!statshrdet.ButStaActive"
										class="my-1"
										color="primary"
									>
										{{tagdet.ButSta}}
									</v-btn>
								</v-col>
							</v-row>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-file-input
								v-if="statshrini.UldAvail"
								outlined
								show-size
								:label="tagini.Cpt"
								v-model="contappini.file"
							>
							</v-file-input>
							<v-btn
								v-if="statshrini.UldAvail"
								v-on:click="handleButUploadClick('ini')"
								:disabled="contappini.file == null"
								color="primary"
							>
								{{tagini.Uld}}
							</v-btn>
							<v-text-field
								v-if="statshrini.TxtPrgAvail"
								class="my-1"
								readonly
								outlined
								v-model="continfini.TxtPrg"
								:label="tagini.CptPrg"
							/>

							<v-divider v-if="statshrini.Sep1Avail"/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('ini', 'ButClgClick')"
										:disabled="!statshrini.ButClgActive"
										class="my-1"
										color="primary"
									>
										{{tagini.ButClg}}
									</v-btn>
								</v-col>
							</v-row>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-text-field
								class="my-1"
								readonly
								outlined
								v-model="continfext.TxtPrg"
								:label="tagext.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('ext', 'ButRunClick')"
										:disabled="!statshrext.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagext.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('ext', 'ButStoClick')"
										:disabled="!statshrext.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagext.ButSto}}
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
		name: 'DlgWdbeRlsStareptr',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeRlsStareptr.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWdbeRlsStareptrDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWdbeRlsStareptrDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeRlsStareptr"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgWdbeRlsStareptrDet"] = this.contiacdet;
				if (mask.indexOf("contiacini") != -1) dpchapp["ContIacDlgWdbeRlsStareptrIni"] = this.contiacini;
				if (mask.indexOf("contiacext") != -1) dpchapp["ContIacDlgWdbeRlsStareptrExt"] = this.contiacext;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWdbeRlsStareptrLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeRlsStareptrData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeRlsStareptrData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeRlsStareptr) this.contiac = dpcheng.ContIacDlgWdbeRlsStareptr;
				if (dpcheng.ContIacDlgWdbeRlsStareptrDet) this.contiacdet = dpcheng.ContIacDlgWdbeRlsStareptrDet;
				if (dpcheng.ContInfDlgWdbeRlsStareptr) this.continf = dpcheng.ContInfDlgWdbeRlsStareptr;
				if (dpcheng.ContInfDlgWdbeRlsStareptrExt) this.continfext = dpcheng.ContInfDlgWdbeRlsStareptrExt;
				if (dpcheng.ContInfDlgWdbeRlsStareptrIni) this.continfini = dpcheng.ContInfDlgWdbeRlsStareptrIni;
				if (dpcheng.ContInfDlgWdbeRlsStareptrLfi) this.continflfi = dpcheng.ContInfDlgWdbeRlsStareptrLfi;
				if (dpcheng.FeedFDetRbuBrt) this.feedFDetRbuBrt = dpcheng.FeedFDetRbuBrt;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeRlsStareptr) this.statapp = dpcheng.StatAppDlgWdbeRlsStareptr;
				if (dpcheng.StatShrDlgWdbeRlsStareptr) this.statshr = dpcheng.StatShrDlgWdbeRlsStareptr;
				if (dpcheng.StatShrDlgWdbeRlsStareptrDet) this.statshrdet = dpcheng.StatShrDlgWdbeRlsStareptrDet;
				if (dpcheng.StatShrDlgWdbeRlsStareptrExt) this.statshrext = dpcheng.StatShrDlgWdbeRlsStareptrExt;
				if (dpcheng.StatShrDlgWdbeRlsStareptrIni) this.statshrini = dpcheng.StatShrDlgWdbeRlsStareptrIni;
				if (dpcheng.StatShrDlgWdbeRlsStareptrLfi) this.statshrlfi = dpcheng.StatShrDlgWdbeRlsStareptrLfi;
				if (dpcheng.TagDlgWdbeRlsStareptr) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsStareptr);
					this.tag = dpcheng.TagDlgWdbeRlsStareptr;
				}
				if (dpcheng.TagDlgWdbeRlsStareptrDet) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsStareptrDet);
					this.tagdet = dpcheng.TagDlgWdbeRlsStareptrDet;
				}
				if (dpcheng.TagDlgWdbeRlsStareptrExt) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsStareptrExt);
					this.tagext = dpcheng.TagDlgWdbeRlsStareptrExt;
				}
				if (dpcheng.TagDlgWdbeRlsStareptrIni) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsStareptrIni);
					this.tagini = dpcheng.TagDlgWdbeRlsStareptrIni;
				}
				if (dpcheng.TagDlgWdbeRlsStareptrLfi) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsStareptrLfi);
					this.taglfi = dpcheng.TagDlgWdbeRlsStareptrLfi;
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeRlsStareptrData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeRlsStareptrData") this.mergeDpchEngData(obj.dpcheng);
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

			contiacdet: null,

			continf: null,

			continfext: null,

			continfini: null,

			continflfi: null,

			feedFDetRbuBrt: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrdet: null,

			statshrext: null,

			statshrini: null,

			statshrlfi: null,

			tag: null,

			tagdet: null,

			tagext: null,

			tagini: null,

			taglfi: null,

			contappini: {
				file: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
