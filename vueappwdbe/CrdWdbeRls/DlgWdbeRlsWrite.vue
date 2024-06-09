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
							<v-checkbox
								class="my-1"
								v-model="contiacdet.ChkBso"
								v-on:change='updateEng(["contiacdet"])'
								:label="tagdet.CptBso"
							/>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-file-input
								v-if="statshrcuc.UldAvail"
								outlined
								show-size
								:label="tagcuc.Cpt"
								v-model="contappcuc.file"
							>
							</v-file-input>
							<v-btn
								v-if="statshrcuc.UldAvail"
								v-on:click="handleButUploadClick('cuc')"
								:disabled="contappcuc.file == null"
								color="primary"
							>
								{{tagcuc.Uld}}
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
								v-model="continfwrc.TxtPrg"
								:label="tagwrc.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('wrc', 'ButAutClick')"
										:disabled="!statshrwrc.ButAutActive"
										class="my-1"
										color="primary"
									>
										{{tagwrc.ButAut}}
									</v-btn>
								</v-col>
							</v-row>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('wrc', 'ButRunClick')"
										:disabled="!statshrwrc.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagwrc.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('wrc', 'ButStoClick')"
										:disabled="!statshrwrc.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagwrc.ButSto}}
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
								v-if="statshrfia.DldAvail"
								download
								:href="hrefDld"
								target="_blank"
								:disabled="!statshrfia.DldActive"
								class="my-1"
								color="primary"
							>
								{{tagfia.Dld}}
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
		name: 'DlgWdbeRlsWrite',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeRlsWrite.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWdbeRlsWriteDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeRlsWrite"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgWdbeRlsWriteDet"] = this.contiacdet;
				if (mask.indexOf("contiaccuc") != -1) dpchapp["ContIacDlgWdbeRlsWriteCuc"] = this.contiaccuc;
				if (mask.indexOf("contiacwrc") != -1) dpchapp["ContIacDlgWdbeRlsWriteWrc"] = this.contiacwrc;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWdbeRlsWriteLfi"] = this.contiaclfi;
				if (mask.indexOf("contiacfia") != -1) dpchapp["ContIacDlgWdbeRlsWriteFia"] = this.contiacfia;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeRlsWriteData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeRlsWriteData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeRlsWrite) this.contiac = dpcheng.ContIacDlgWdbeRlsWrite;
				if (dpcheng.ContIacDlgWdbeRlsWriteDet) this.contiacdet = dpcheng.ContIacDlgWdbeRlsWriteDet;
				if (dpcheng.ContInfDlgWdbeRlsWrite) this.continf = dpcheng.ContInfDlgWdbeRlsWrite;
				if (dpcheng.ContInfDlgWdbeRlsWriteFia) this.continffia = dpcheng.ContInfDlgWdbeRlsWriteFia;
				if (dpcheng.ContInfDlgWdbeRlsWriteLfi) this.continflfi = dpcheng.ContInfDlgWdbeRlsWriteLfi;
				if (dpcheng.ContInfDlgWdbeRlsWriteWrc) this.continfwrc = dpcheng.ContInfDlgWdbeRlsWriteWrc;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeRlsWrite) this.statapp = dpcheng.StatAppDlgWdbeRlsWrite;
				if (dpcheng.StatShrDlgWdbeRlsWrite) this.statshr = dpcheng.StatShrDlgWdbeRlsWrite;
				if (dpcheng.StatShrDlgWdbeRlsWriteCuc) this.statshrcuc = dpcheng.StatShrDlgWdbeRlsWriteCuc;
				if (dpcheng.StatShrDlgWdbeRlsWriteFia) this.statshrfia = dpcheng.StatShrDlgWdbeRlsWriteFia;
				if (dpcheng.StatShrDlgWdbeRlsWriteLfi) this.statshrlfi = dpcheng.StatShrDlgWdbeRlsWriteLfi;
				if (dpcheng.StatShrDlgWdbeRlsWriteWrc) this.statshrwrc = dpcheng.StatShrDlgWdbeRlsWriteWrc;
				if (dpcheng.TagDlgWdbeRlsWrite) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsWrite);
					this.tag = dpcheng.TagDlgWdbeRlsWrite;
				}
				if (dpcheng.TagDlgWdbeRlsWriteCuc) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsWriteCuc);
					this.tagcuc = dpcheng.TagDlgWdbeRlsWriteCuc;
				}
				if (dpcheng.TagDlgWdbeRlsWriteDet) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsWriteDet);
					this.tagdet = dpcheng.TagDlgWdbeRlsWriteDet;
				}
				if (dpcheng.TagDlgWdbeRlsWriteFia) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsWriteFia);
					this.tagfia = dpcheng.TagDlgWdbeRlsWriteFia;
				}
				if (dpcheng.TagDlgWdbeRlsWriteLfi) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsWriteLfi);
					this.taglfi = dpcheng.TagDlgWdbeRlsWriteLfi;
				}
				if (dpcheng.TagDlgWdbeRlsWriteWrc) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsWriteWrc);
					this.tagwrc = dpcheng.TagDlgWdbeRlsWriteWrc;
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeRlsWriteData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeRlsWriteData") this.mergeDpchEngData(obj.dpcheng);
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

			continffia: null,

			continflfi: null,

			continfwrc: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrcuc: null,

			statshrfia: null,

			statshrlfi: null,

			statshrwrc: null,

			tag: null,

			tagcuc: null,

			tagdet: null,

			tagfia: null,

			taglfi: null,

			tagwrc: null,

			contappcuc: {
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
