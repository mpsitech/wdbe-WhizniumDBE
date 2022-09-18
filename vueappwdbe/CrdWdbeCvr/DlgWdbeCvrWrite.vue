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
								:label="tagcuc.Cpt"
								v-model="contappcuc.file"
							>
							</v-file-input>
							<v-btn
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
		name: 'DlgWdbeCvrWrite',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeCvrWrite.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWdbeCvrWriteDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeCvrWrite"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiaccuc") != -1) dpchapp["ContIacDlgWdbeCvrWriteCuc"] = this.contiaccuc;
				if (mask.indexOf("contiacwrc") != -1) dpchapp["ContIacDlgWdbeCvrWriteWrc"] = this.contiacwrc;
				if (mask.indexOf("contiacfia") != -1) dpchapp["ContIacDlgWdbeCvrWriteFia"] = this.contiacfia;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeCvrWriteData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeCvrWriteData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeCvrWrite) this.contiac = dpcheng.ContIacDlgWdbeCvrWrite;
				if (dpcheng.ContInfDlgWdbeCvrWrite) this.continf = dpcheng.ContInfDlgWdbeCvrWrite;
				if (dpcheng.ContInfDlgWdbeCvrWriteFia) this.continffia = dpcheng.ContInfDlgWdbeCvrWriteFia;
				if (dpcheng.ContInfDlgWdbeCvrWriteWrc) this.continfwrc = dpcheng.ContInfDlgWdbeCvrWriteWrc;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeCvrWrite) this.statapp = dpcheng.StatAppDlgWdbeCvrWrite;
				if (dpcheng.StatShrDlgWdbeCvrWrite) this.statshr = dpcheng.StatShrDlgWdbeCvrWrite;
				if (dpcheng.StatShrDlgWdbeCvrWriteCuc) this.statshrcuc = dpcheng.StatShrDlgWdbeCvrWriteCuc;
				if (dpcheng.StatShrDlgWdbeCvrWriteFia) this.statshrfia = dpcheng.StatShrDlgWdbeCvrWriteFia;
				if (dpcheng.StatShrDlgWdbeCvrWriteWrc) this.statshrwrc = dpcheng.StatShrDlgWdbeCvrWriteWrc;
				if (dpcheng.TagDlgWdbeCvrWrite) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeCvrWrite);
					this.tag = dpcheng.TagDlgWdbeCvrWrite;
				}
				if (dpcheng.TagDlgWdbeCvrWriteCuc) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeCvrWriteCuc);
					this.tagcuc = dpcheng.TagDlgWdbeCvrWriteCuc;
				}
				if (dpcheng.TagDlgWdbeCvrWriteFia) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeCvrWriteFia);
					this.tagfia = dpcheng.TagDlgWdbeCvrWriteFia;
				}
				if (dpcheng.TagDlgWdbeCvrWriteWrc) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeCvrWriteWrc);
					this.tagwrc = dpcheng.TagDlgWdbeCvrWriteWrc;
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeCvrWriteData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeCvrWriteData") this.mergeDpchEngData(obj.dpcheng);
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

			continffia: null,

			continfwrc: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrcuc: null,

			statshrfia: null,

			statshrwrc: null,

			tag: null,

			tagcuc: null,

			tagfia: null,

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
