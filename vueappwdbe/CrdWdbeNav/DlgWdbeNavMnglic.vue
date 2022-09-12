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
		</v-card-title>
		<v-card-text>
			<h3
				class="text-5 my-1"
			>
				{{tag.DetHdgSrv}}
			</h3>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtSip"
				:label="tag.CptDetSip"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtScp"
				:label="tag.CptDetScp"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('DetButScnClick')"
						class="my-1"
						color="primary"
					>
						{{tag.DetButScn}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('DetButSdcClick')"
						class="my-1"
						color="primary"
					>
						{{tag.DetButSdc}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupFis"
				:items="feedFDetPupFis"
				:label='tag.CptDetFis'
				v-on:change="handlePupChange('numFDetPupFis', contapp.fiFDetPupFis)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-1"
			>
				<!-- IP divDetLcs - INSERT -->
			</div>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('DetButActClick')"
						:disabled="!statshr.DetButActActive"
						class="my-1"
						color="primary"
					>
						{{tag.DetButAct}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.DetHdgLic}}
			</h3>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtLsr"
				:label="tag.CptDetLsr"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtLar"
				:label="tag.CptDetLar"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtLst"
				:label="tag.CptDetLst"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtLex"
				:label="tag.CptDetLex"
			/>

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
		name: 'DlgWdbeNavMnglic',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeNavMnglic.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWdbeNavMnglicDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWdbeNavMnglicDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeNavMnglic"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeNavMnglicData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeNavMnglicData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeNavMnglic) this.contiac = dpcheng.ContIacDlgWdbeNavMnglic;
				if (dpcheng.ContInfDlgWdbeNavMnglic) this.continf = dpcheng.ContInfDlgWdbeNavMnglic;
				if (dpcheng.FeedFDetLstLcs) this.feedFDetLstLcs = dpcheng.FeedFDetLstLcs;
				if (dpcheng.FeedFDetPupFis) this.feedFDetPupFis = dpcheng.FeedFDetPupFis;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeNavMnglic) this.statapp = dpcheng.StatAppDlgWdbeNavMnglic;
				if (dpcheng.StatShrDlgWdbeNavMnglic) this.statshr = dpcheng.StatShrDlgWdbeNavMnglic;
				if (dpcheng.TagDlgWdbeNavMnglic) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeNavMnglic);
					this.tag = dpcheng.TagDlgWdbeNavMnglic;
				}
				if (dpcheng.ContIacDlgWdbeNavMnglic) {
					for (let i = 0; i < this.feedFDetPupFis.length; i++)
						if (this.feedFDetPupFis[i].num == this.contiac.numFDetPupFis) {
							this.contapp.fiFDetPupFis = this.feedFDetPupFis[i];
							break;
						}
					for (let i = 0; i < this.feedFDetLstLcs.length; i++)
						if (this.feedFDetLstLcs[i].num == this.contiac.numFDetLstLcs) {
							this.contapp.fiFDetLstLcs = this.feedFDetLstLcs[i];
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeNavMnglicData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeNavMnglicData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {

		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFDetLstLcs: null,

			feedFDetPupFis: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFDetPupFis: null,

				fiFDetLstLcs: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
