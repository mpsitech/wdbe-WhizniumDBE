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
								v-model="contiacdet.TxfFnm"
								:label="tagdet.CptFnm"
							/>

							<v-select
								class="my-1"
								v-model="contappdet.fiFPupRet"
								return-object
								:items="feedFDetPupRet"
								item-value="num"
								item-text="tit1"
								:label="tagdet.CptRet"
								v-on:change="handleFiChange('det', 'numFPupRet', contappdet.fiFPupRet)"
							/>

							<v-text-field
								class="my-1"
								v-model="contiacdet.TxfReu"
								:label="tagdet.CptReu"
							/>

							<v-select
								class="my-1"
								v-model="contappdet.fiFPupCnt"
								return-object
								:items="feedFDetPupCnt"
								item-value="num"
								item-text="tit1"
								:label="tagdet.CptCnt"
								v-on:change="handleFiChange('det', 'numFPupCnt', contappdet.fiFPupCnt)"
							/>

							<v-select
								class="my-1"
								v-model="contappdet.fiFPupMim"
								return-object
								:items="feedFDetPupMim"
								item-value="num"
								item-text="tit1"
								:label="tagdet.CptMim"
								v-on:change="handleFiChange('det', 'numFPupMim', contappdet.fiFPupMim)"
							/>

							<v-text-field
								class="my-1"
								v-model="contiacdet.TxfCmt"
								:label="tagdet.CptCmt"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('det', 'ButCreClick')"
										:disabled="!statshrdet.ButCreActive"
										class="my-1"
										color="primary"
									>
										{{tagdet.ButCre}}
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
								outlined
								show-size
								:label="tagfil.Cpt"
								v-model="contappfil.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('fil')"
								:disabled="contappfil.file == null"
								color="primary"
							>
								{{tagfil.Uld}}
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
		name: 'DlgWdbeFilNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeFilNew.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWdbeFilNewDo": {
						"scrJref": this.scrJref,
						[srefIxVDo]: ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			handleFiChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeFilNew"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgWdbeFilNewDet"] = this.contiacdet;
				if (mask.indexOf("contiacfil") != -1) dpchapp["ContIacDlgWdbeFilNewFil"] = this.contiacfil;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeFilNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeFilNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeFilNew) this.contiac = dpcheng.ContIacDlgWdbeFilNew;
				if (dpcheng.ContIacDlgWdbeFilNewDet) this.contiacdet = dpcheng.ContIacDlgWdbeFilNewDet;
				if (dpcheng.ContInfDlgWdbeFilNew) this.continf = dpcheng.ContInfDlgWdbeFilNew;
				if (dpcheng.FeedFDetPupCnt) this.feedFDetPupCnt = dpcheng.FeedFDetPupCnt;
				if (dpcheng.FeedFDetPupMim) this.feedFDetPupMim = dpcheng.FeedFDetPupMim;
				if (dpcheng.FeedFDetPupRet) this.feedFDetPupRet = dpcheng.FeedFDetPupRet;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeFilNew) this.statapp = dpcheng.StatAppDlgWdbeFilNew;
				if (dpcheng.StatShrDlgWdbeFilNew) this.statshr = dpcheng.StatShrDlgWdbeFilNew;
				if (dpcheng.StatShrDlgWdbeFilNewDet) this.statshrdet = dpcheng.StatShrDlgWdbeFilNewDet;
				if (dpcheng.StatShrDlgWdbeFilNewFil) this.statshrfil = dpcheng.StatShrDlgWdbeFilNewFil;
				if (dpcheng.TagDlgWdbeFilNew) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeFilNew);
					this.tag = dpcheng.TagDlgWdbeFilNew;
				}
				if (dpcheng.TagDlgWdbeFilNewDet) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeFilNewDet);
					this.tagdet = dpcheng.TagDlgWdbeFilNewDet;
				}
				if (dpcheng.TagDlgWdbeFilNewFil) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeFilNewFil);
					this.tagfil = dpcheng.TagDlgWdbeFilNewFil;
				}
				if (dpcheng.ContIacDlgWdbeFilNewDet) {
					for (let i = 0; i < this.feedFDetPupRet.length; i++)
						if (this.feedFDetPupRet[i].num == this.contiacdet.numFPupRet) {
							this.contappdet.fiFPupRet = this.feedFDetPupRet[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupCnt.length; i++)
						if (this.feedFDetPupCnt[i].num == this.contiacdet.numFPupCnt) {
							this.contappdet.fiFPupCnt = this.feedFDetPupCnt[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupMim.length; i++)
						if (this.feedFDetPupMim[i].num == this.contiacdet.numFPupMim) {
							this.contappdet.fiFPupMim = this.feedFDetPupMim[i];
							break;
						}
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeFilNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeFilNewData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {

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

			feedFDetPupCnt: null,

			feedFDetPupMim: null,

			feedFDetPupRet: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrdet: null,

			statshrfil: null,

			tag: null,

			tagdet: null,

			tagfil: null,

			contappdet: {
				fiFPupRet: null,

				fiFPupCnt: null,

				fiFPupMim: null,

			},

			contappfil: {
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
