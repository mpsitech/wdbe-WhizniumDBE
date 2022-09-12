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
							<v-file-input
								outlined
								show-size
								:label="tagsrc.Cpt"
								v-model="contappsrc.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('src')"
								:disabled="contappsrc.file == null"
								color="primary"
							>
								{{tagsrc.Uld}}
							</v-btn>
						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-file-input
								outlined
								show-size
								:label="tagtrg.Cpt"
								v-model="contapptrg.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('trg')"
								:disabled="contapptrg.file == null"
								color="primary"
							>
								{{tagtrg.Uld}}
							</v-btn>
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
								v-model="continfmrg.TxtPrg"
								:label="tagmrg.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('mrg', 'ButRunClick')"
										:disabled="!statshrmrg.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagmrg.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('mrg', 'ButStoClick')"
										:disabled="!statshrmrg.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagmrg.ButSto}}
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
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-btn
								download
								:href="hrefDld"
								:disabled="!statshrres.DldActive"
								class="my-1"
								color="primary"
							>
								{{tagres.Dld}}
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
		name: 'DlgWdbeUtlMrgip',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeUtlMrgip.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWdbeUtlMrgipDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWdbeUtlMrgipDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeUtlMrgip"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacsrc") != -1) dpchapp["ContIacDlgWdbeUtlMrgipSrc"] = this.contiacsrc;
				if (mask.indexOf("contiactrg") != -1) dpchapp["ContIacDlgWdbeUtlMrgipTrg"] = this.contiactrg;
				if (mask.indexOf("contiacmrg") != -1) dpchapp["ContIacDlgWdbeUtlMrgipMrg"] = this.contiacmrg;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWdbeUtlMrgipLfi"] = this.contiaclfi;
				if (mask.indexOf("contiacres") != -1) dpchapp["ContIacDlgWdbeUtlMrgipRes"] = this.contiacres;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeUtlMrgipData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeUtlMrgipData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeUtlMrgip) this.contiac = dpcheng.ContIacDlgWdbeUtlMrgip;
				if (dpcheng.ContInfDlgWdbeUtlMrgip) this.continf = dpcheng.ContInfDlgWdbeUtlMrgip;
				if (dpcheng.ContInfDlgWdbeUtlMrgipLfi) this.continflfi = dpcheng.ContInfDlgWdbeUtlMrgipLfi;
				if (dpcheng.ContInfDlgWdbeUtlMrgipMrg) this.continfmrg = dpcheng.ContInfDlgWdbeUtlMrgipMrg;
				if (dpcheng.ContInfDlgWdbeUtlMrgipRes) this.continfres = dpcheng.ContInfDlgWdbeUtlMrgipRes;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeUtlMrgip) this.statapp = dpcheng.StatAppDlgWdbeUtlMrgip;
				if (dpcheng.StatShrDlgWdbeUtlMrgip) this.statshr = dpcheng.StatShrDlgWdbeUtlMrgip;
				if (dpcheng.StatShrDlgWdbeUtlMrgipLfi) this.statshrlfi = dpcheng.StatShrDlgWdbeUtlMrgipLfi;
				if (dpcheng.StatShrDlgWdbeUtlMrgipMrg) this.statshrmrg = dpcheng.StatShrDlgWdbeUtlMrgipMrg;
				if (dpcheng.StatShrDlgWdbeUtlMrgipRes) this.statshrres = dpcheng.StatShrDlgWdbeUtlMrgipRes;
				if (dpcheng.StatShrDlgWdbeUtlMrgipSrc) this.statshrsrc = dpcheng.StatShrDlgWdbeUtlMrgipSrc;
				if (dpcheng.StatShrDlgWdbeUtlMrgipTrg) this.statshrtrg = dpcheng.StatShrDlgWdbeUtlMrgipTrg;
				if (dpcheng.TagDlgWdbeUtlMrgip) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlMrgip);
					this.tag = dpcheng.TagDlgWdbeUtlMrgip;
				}
				if (dpcheng.TagDlgWdbeUtlMrgipLfi) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlMrgipLfi);
					this.taglfi = dpcheng.TagDlgWdbeUtlMrgipLfi;
				}
				if (dpcheng.TagDlgWdbeUtlMrgipMrg) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlMrgipMrg);
					this.tagmrg = dpcheng.TagDlgWdbeUtlMrgipMrg;
				}
				if (dpcheng.TagDlgWdbeUtlMrgipRes) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlMrgipRes);
					this.tagres = dpcheng.TagDlgWdbeUtlMrgipRes;
				}
				if (dpcheng.TagDlgWdbeUtlMrgipSrc) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlMrgipSrc);
					this.tagsrc = dpcheng.TagDlgWdbeUtlMrgipSrc;
				}
				if (dpcheng.TagDlgWdbeUtlMrgipTrg) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlMrgipTrg);
					this.tagtrg = dpcheng.TagDlgWdbeUtlMrgipTrg;
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeUtlMrgipData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeUtlMrgipData") this.mergeDpchEngData(obj.dpcheng);
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

			continflfi: null,

			continfmrg: null,

			continfres: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrlfi: null,

			statshrmrg: null,

			statshrres: null,

			statshrsrc: null,

			statshrtrg: null,

			tag: null,

			taglfi: null,

			tagmrg: null,

			tagres: null,

			tagsrc: null,

			tagtrg: null,

			contappsrc: {
				file: null,

			},

			contapptrg: {
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
