<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPrs"
				:label="tag.CptPrs"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSrf"
				:label="tag.CptSrf"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtUsg"
				:label="tag.CptUsg"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSte"
				return-object
				:items="feedFPupSte"
				item-value="num"
				item-text="tit1"
				:label="tag.CptSte"
				v-on:change="handleFiChange('numFPupSte', contapp.fiFPupSte)"
				:disabled="!statshr.PupSteActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupLcl"
				return-object
				:items="feedFPupLcl"
				item-value="num"
				item-text="tit1"
				:label="tag.CptLcl"
				v-on:change="handleFiChange('numFPupLcl', contapp.fiFPupLcl)"
				:disabled="!statshr.PupLclActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupUlv"
				return-object
				:items="feedFPupUlv"
				item-value="num"
				item-text="tit1"
				:label="tag.CptUlv"
				v-on:change="handleFiChange('numFPupUlv', contapp.fiFPupUlv)"
				:disabled="!statshr.PupUlvActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfPwd"
				:label="tag.CptPwd"
				:disabled="!statshr.TxfPwdActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfFky"
				:label="tag.CptFky"
				:disabled="!statshr.TxfFkyActive"
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
		name: 'PnlWdbeUsrDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeUsrDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeUsrDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeUsrDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeUsrDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeUsrDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeUsrDetail) this.contiac = dpcheng.ContIacWdbeUsrDetail;
				if (dpcheng.ContInfWdbeUsrDetail) this.continf = dpcheng.ContInfWdbeUsrDetail;
				if (dpcheng.FeedFPupLcl) this.feedFPupLcl = dpcheng.FeedFPupLcl;
				if (dpcheng.FeedFPupSte) this.feedFPupSte = dpcheng.FeedFPupSte;
				if (dpcheng.FeedFPupUlv) this.feedFPupUlv = dpcheng.FeedFPupUlv;
				if (dpcheng.StatAppWdbeUsrDetail) this.statapp = dpcheng.StatAppWdbeUsrDetail;
				if (dpcheng.StatShrWdbeUsrDetail) this.statshr = dpcheng.StatShrWdbeUsrDetail;
				if (dpcheng.TagWdbeUsrDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeUsrDetail);
					this.tag = dpcheng.TagWdbeUsrDetail;
				}
				if (dpcheng.ContIacWdbeUsrDetail) {
					for (let i = 0; i < this.feedFPupSte.length; i++)
						if (this.feedFPupSte[i].num == this.contiac.numFPupSte) {
							this.contapp.fiFPupSte = this.feedFPupSte[i];
							break;
						}
					for (let i = 0; i < this.feedFPupLcl.length; i++)
						if (this.feedFPupLcl[i].num == this.contiac.numFPupLcl) {
							this.contapp.fiFPupLcl = this.feedFPupLcl[i];
							break;
						}
					for (let i = 0; i < this.feedFPupUlv.length; i++)
						if (this.feedFPupUlv[i].num == this.contiac.numFPupUlv) {
							this.contapp.fiFPupUlv = this.feedFPupUlv[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeUsrDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeUsrDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupLcl: null,

			feedFPupSte: null,

			feedFPupUlv: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupSte: null,

				fiFPupLcl: null,

				fiFPupUlv: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
