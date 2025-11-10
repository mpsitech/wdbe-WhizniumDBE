<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSrf"
				:label="tag.CptSrf"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFLstClu"
				return-object
				:items="feedFLstClu"
				item-value="num"
				item-text="tit1"
				:label="tag.CptClu"
				v-on:change="handleFiChange('numFLstClu', contapp.fiFLstClu)"
				:disabled="!statshr.LstCluActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtReu"
				:label="tag.CptReu"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkCon"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptCon"
				:disabled="!statshr.ChkConActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkFal"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptFal"
				:disabled="!statshr.ChkFalActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupHty"
				return-object
				:items="feedFPupHty"
				item-value="num"
				item-text="tit1"
				:label="tag.CptHty"
				v-on:change="handleFiChange('numFPupHty', contapp.fiFPupHty)"
				:disabled="!statshr.PupHtyActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfWid"
				:label="tag.CptWid"
				:disabled="!statshr.TxfWidActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfMmx"
				:label="tag.CptMmx"
				:disabled="!statshr.TxfMmxActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfOnv"
				:label="tag.CptOnv"
				:disabled="!statshr.TxfOnvActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfOfv"
				:label="tag.CptOfv"
				:disabled="!statshr.TxfOfvActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmt"
				:label="tag.CptCmt"
				:disabled="!statshr.TxfCmtActive"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeVarDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeVarDetail.mounted() with scrJref = " + this.scrJref);

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

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWdbeVarDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleFiChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeVarDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeVarDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeVarDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeVarDetail) this.contiac = dpcheng.ContIacWdbeVarDetail;
				if (dpcheng.ContInfWdbeVarDetail) this.continf = dpcheng.ContInfWdbeVarDetail;
				if (dpcheng.FeedFLstClu) this.feedFLstClu = dpcheng.FeedFLstClu;
				if (dpcheng.FeedFPupHty) this.feedFPupHty = dpcheng.FeedFPupHty;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.StatAppWdbeVarDetail) this.statapp = dpcheng.StatAppWdbeVarDetail;
				if (dpcheng.StatShrWdbeVarDetail) this.statshr = dpcheng.StatShrWdbeVarDetail;
				if (dpcheng.TagWdbeVarDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeVarDetail);
					this.tag = dpcheng.TagWdbeVarDetail;
				}
				if (dpcheng.ContIacWdbeVarDetail) {
					for (let i = 0; i < this.feedFLstClu.length; i++)
						if (this.feedFLstClu[i].num == this.contiac.numFLstClu) {
							this.contapp.fiFLstClu = this.feedFLstClu[i];
							break;
						}
					for (let i = 0; i < this.feedFPupRet.length; i++)
						if (this.feedFPupRet[i].num == this.contiac.numFPupRet) {
							this.contapp.fiFPupRet = this.feedFPupRet[i];
							break;
						}
					for (let i = 0; i < this.feedFPupHty.length; i++)
						if (this.feedFPupHty[i].num == this.contiac.numFPupHty) {
							this.contapp.fiFPupHty = this.feedFPupHty[i];
							break;
						}
				}
				/*
				<!-- IP mergeDpchEngData - END -->
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
				if (srefIxWdbeVDpch == "DpchEngWdbeVarDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeVarDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstClu: null,

			feedFPupHty: null,

			feedFPupRet: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFLstClu: null,

				fiFPupRet: null,

				fiFPupHty: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
