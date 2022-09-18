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

			<v-text-field
				class="my-1"
				v-model="contiac.TxfTit"
				:label="tag.CptTit"
				:disabled="!statshr.TxfTitActive"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfVer"
				:label="tag.CptVer"
				:disabled="!statshr.TxfVerActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFLstDep"
				return-object
				:items="feedFLstDep"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDep"
				v-on:change="handleFiChange('numFLstDep', contapp.fiFLstDep)"
				:disabled="!statshr.LstDepActive"
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
		name: 'PnlWdbeLibDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeLibDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeLibDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeLibDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeLibDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeLibDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeLibDetail) this.contiac = dpcheng.ContIacWdbeLibDetail;
				if (dpcheng.ContInfWdbeLibDetail) this.continf = dpcheng.ContInfWdbeLibDetail;
				if (dpcheng.FeedFLstDep) this.feedFLstDep = dpcheng.FeedFLstDep;
				if (dpcheng.StatAppWdbeLibDetail) this.statapp = dpcheng.StatAppWdbeLibDetail;
				if (dpcheng.StatShrWdbeLibDetail) this.statshr = dpcheng.StatShrWdbeLibDetail;
				if (dpcheng.TagWdbeLibDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeLibDetail);
					this.tag = dpcheng.TagWdbeLibDetail;
				}
				if (dpcheng.ContIacWdbeLibDetail) {
					for (let i = 0; i < this.feedFLstDep.length; i++)
						if (this.feedFLstDep[i].num == this.contiac.numFLstDep) {
							this.contapp.fiFLstDep = this.feedFLstDep[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeLibDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeLibDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstDep: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFLstDep: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
