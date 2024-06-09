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
								target="_blank"
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
								target="_blank"
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
		name: 'DlgWdbeUtlExtrip',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeUtlExtrip.mounted() with scrJref = " + this.scrJref);

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
				var srefIxVDo = "srefIxVDo";
				if (ditshort != "") srefIxVDo += ditshort.charAt(0).toUpperCase() + ditshort.slice(1);

				const dpchapp = {
					"DpchAppDlgWdbeUtlExtripDo": {
						"scrJref": this.scrJref,
						[srefIxVDo]: ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeUtlExtrip"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacsrc") != -1) dpchapp["ContIacDlgWdbeUtlExtripSrc"] = this.contiacsrc;
				if (mask.indexOf("contiacext") != -1) dpchapp["ContIacDlgWdbeUtlExtripExt"] = this.contiacext;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWdbeUtlExtripLfi"] = this.contiaclfi;
				if (mask.indexOf("contiacres") != -1) dpchapp["ContIacDlgWdbeUtlExtripRes"] = this.contiacres;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeUtlExtripData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeUtlExtripData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeUtlExtrip) this.contiac = dpcheng.ContIacDlgWdbeUtlExtrip;
				if (dpcheng.ContInfDlgWdbeUtlExtrip) this.continf = dpcheng.ContInfDlgWdbeUtlExtrip;
				if (dpcheng.ContInfDlgWdbeUtlExtripExt) this.continfext = dpcheng.ContInfDlgWdbeUtlExtripExt;
				if (dpcheng.ContInfDlgWdbeUtlExtripLfi) this.continflfi = dpcheng.ContInfDlgWdbeUtlExtripLfi;
				if (dpcheng.ContInfDlgWdbeUtlExtripRes) this.continfres = dpcheng.ContInfDlgWdbeUtlExtripRes;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeUtlExtrip) this.statapp = dpcheng.StatAppDlgWdbeUtlExtrip;
				if (dpcheng.StatShrDlgWdbeUtlExtrip) this.statshr = dpcheng.StatShrDlgWdbeUtlExtrip;
				if (dpcheng.StatShrDlgWdbeUtlExtripExt) this.statshrext = dpcheng.StatShrDlgWdbeUtlExtripExt;
				if (dpcheng.StatShrDlgWdbeUtlExtripLfi) this.statshrlfi = dpcheng.StatShrDlgWdbeUtlExtripLfi;
				if (dpcheng.StatShrDlgWdbeUtlExtripRes) this.statshrres = dpcheng.StatShrDlgWdbeUtlExtripRes;
				if (dpcheng.StatShrDlgWdbeUtlExtripSrc) this.statshrsrc = dpcheng.StatShrDlgWdbeUtlExtripSrc;
				if (dpcheng.TagDlgWdbeUtlExtrip) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlExtrip);
					this.tag = dpcheng.TagDlgWdbeUtlExtrip;
				}
				if (dpcheng.TagDlgWdbeUtlExtripExt) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlExtripExt);
					this.tagext = dpcheng.TagDlgWdbeUtlExtripExt;
				}
				if (dpcheng.TagDlgWdbeUtlExtripLfi) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlExtripLfi);
					this.taglfi = dpcheng.TagDlgWdbeUtlExtripLfi;
				}
				if (dpcheng.TagDlgWdbeUtlExtripRes) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlExtripRes);
					this.tagres = dpcheng.TagDlgWdbeUtlExtripRes;
				}
				if (dpcheng.TagDlgWdbeUtlExtripSrc) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeUtlExtripSrc);
					this.tagsrc = dpcheng.TagDlgWdbeUtlExtripSrc;
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeUtlExtripData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeUtlExtripData") this.mergeDpchEngData(obj.dpcheng);
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

			continfext: null,

			continflfi: null,

			continfres: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrext: null,

			statshrlfi: null,

			statshrres: null,

			statshrsrc: null,

			tag: null,

			tagext: null,

			taglfi: null,

			tagres: null,

			tagsrc: null,

			contappsrc: {
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
