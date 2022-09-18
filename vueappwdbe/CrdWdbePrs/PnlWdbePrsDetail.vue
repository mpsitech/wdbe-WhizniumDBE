<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
				:disabled="!statshr.TxfTitActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfFnm"
				:label="tag.CptFnm"
				:disabled="!statshr.TxfFnmActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupJ"
				return-object
				:items="feedFPupJ"
				item-value="num"
				item-text="tit1"
				:label="tag.CptJ"
				v-on:change="handleFiChange('numFPupJ', contapp.fiFPupJ)"
				:disabled="!statshr.PupJActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtLnm"
				:label="tag.CptLnm"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fisFLstDrv"
				multiple
				return-object
				:items="feedFLstDrv"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDrv"
				v-on:change="handleFisChange('numsFLstDrv', contapp.fisFLstDrv)"
				:disabled="!statshr.LstDrvActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSex"
				return-object
				:items="feedFPupSex"
				item-value="num"
				item-text="tit1"
				:label="tag.CptSex"
				v-on:change="handleFiChange('numFPupSex', contapp.fiFPupSex)"
				:disabled="!statshr.PupSexActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTel"
				:label="tag.CptTel"
				:disabled="!statshr.TxfTelActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfEml"
				:label="tag.CptEml"
				:disabled="!statshr.TxfEmlActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSal"
				:label="tag.CptSal"
				:disabled="!statshr.TxfSalActive"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';
	import vecio from '../../scripts/vecio';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbePrsDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbePrsDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbePrsDetailDo": {
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

			handleFisChange: function(cisref, fis) {
				var nums = new Uint32Array(fis.length);

				for (let i = 0; i < fis.length; i++) nums[i] = fis[i].num;
				this.contiac[cisref] = vecio.toBase64(nums);

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbePrsDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbePrsDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbePrsDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbePrsDetail) this.contiac = dpcheng.ContIacWdbePrsDetail;
				if (dpcheng.ContInfWdbePrsDetail) this.continf = dpcheng.ContInfWdbePrsDetail;
				if (dpcheng.FeedFLstDrv) this.feedFLstDrv = dpcheng.FeedFLstDrv;
				if (dpcheng.FeedFPupJ) this.feedFPupJ = dpcheng.FeedFPupJ;
				if (dpcheng.FeedFPupSex) this.feedFPupSex = dpcheng.FeedFPupSex;
				if (dpcheng.StatAppWdbePrsDetail) this.statapp = dpcheng.StatAppWdbePrsDetail;
				if (dpcheng.StatShrWdbePrsDetail) this.statshr = dpcheng.StatShrWdbePrsDetail;
				if (dpcheng.TagWdbePrsDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrsDetail);
					this.tag = dpcheng.TagWdbePrsDetail;
				}
				if (dpcheng.ContIacWdbePrsDetail) {
					for (let i = 0; i < this.feedFPupJ.length; i++)
						if (this.feedFPupJ[i].num == this.contiac.numFPupJ) {
							this.contapp.fiFPupJ = this.feedFPupJ[i];
							break;
						}
					var fisFLstDrv = [];
					var numsFLstDrv = vecio.parseUintvec(this.contiac.numsFLstDrv);

					for (let i = 0; i < this.feedFLstDrv.length; i++)
						if (numsFLstDrv.includes(this.feedFLstDrv[i].num))
							fisFLstDrv.push(this.feedFLstDrv[i]);

					this.contapp.fisFLstDrv = fisFLstDrv;
					for (let i = 0; i < this.feedFPupSex.length; i++)
						if (this.feedFPupSex[i].num == this.contiac.numFPupSex) {
							this.contapp.fiFPupSex = this.feedFPupSex[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbePrsDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbePrsDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstDrv: null,

			feedFPupJ: null,

			feedFPupSex: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJ: null,

				fisFLstDrv: [],

				fiFPupSex: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
