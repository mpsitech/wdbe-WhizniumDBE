<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				v-model="contiac.TxfFnm"
				:label="tag.CptFnm"
				:disabled="!statshr.TxfFnmActive"
			/>

			<v-divider/>

			<div
				class="my-1"
			>
				<!-- IP divClu - INSERT -->
			</div>

			<div
				class="my-1"
			>
				<!-- IP divReu - INSERT -->
			</div>

			<div
				class="my-1"
			>
				<!-- IP divCnt - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAcv"
				:label="tag.CptAcv"
				:disabled="!statshr.TxfAcvActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAnm"
				:label="tag.CptAnm"
				:disabled="!statshr.TxfAnmActive"
			/>

			<div
				class="my-1"
			>
				<!-- IP divMim - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSiz"
				:label="tag.CptSiz"
				:disabled="!statshr.TxfSizActive"
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
		name: 'PnlWdbeFilDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeFilDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeFilDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeFilDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeFilDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeFilDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeFilDetail) this.contiac = dpcheng.ContIacWdbeFilDetail;
				if (dpcheng.ContInfWdbeFilDetail) this.continf = dpcheng.ContInfWdbeFilDetail;
				if (dpcheng.FeedFLstClu) this.feedFLstClu = dpcheng.FeedFLstClu;
				if (dpcheng.FeedFPupCnt) this.feedFPupCnt = dpcheng.FeedFPupCnt;
				if (dpcheng.FeedFPupMim) this.feedFPupMim = dpcheng.FeedFPupMim;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.StatAppWdbeFilDetail) this.statapp = dpcheng.StatAppWdbeFilDetail;
				if (dpcheng.StatShrWdbeFilDetail) this.statshr = dpcheng.StatShrWdbeFilDetail;
				if (dpcheng.TagWdbeFilDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeFilDetail);
					this.tag = dpcheng.TagWdbeFilDetail;
				}
				if (dpcheng.ContIacWdbeFilDetail) {
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
					for (let i = 0; i < this.feedFPupCnt.length; i++)
						if (this.feedFPupCnt[i].num == this.contiac.numFPupCnt) {
							this.contapp.fiFPupCnt = this.feedFPupCnt[i];
							break;
						}
					for (let i = 0; i < this.feedFPupMim.length; i++)
						if (this.feedFPupMim[i].num == this.contiac.numFPupMim) {
							this.contapp.fiFPupMim = this.feedFPupMim[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeFilDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeFilDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupCnt: null,

			feedFPupMim: null,

			feedFPupRet: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFLstClu: null,

				fiFPupRet: null,

				fiFPupCnt: null,

				fiFPupMim: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
