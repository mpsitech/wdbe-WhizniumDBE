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

			<v-text-field
				class="my-1"
				v-model="contiac.TxfFsr"
				:label="tag.CptFsr"
				:disabled="!statshr.TxfFsrActive"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupTyp"
				return-object
				:items="feedFPupTyp"
				item-value="num"
				item-text="tit1"
				:label="tag.CptTyp"
				v-on:change="handleFiChange('numFPupTyp', contapp.fiFPupTyp)"
				:disabled="!statshr.PupTypActive"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtReu"
				:label="tag.CptReu"
			/>

			<v-text-field
				v-if="statshr.TxtSilAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSil"
				:label="tag.CptSil"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSys"
				:label="tag.CptSys"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtMdl"
				:label="tag.CptMdl"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupPkg"
				return-object
				:items="feedFPupPkg"
				item-value="num"
				item-text="tit1"
				:label="tag.CptPkg"
				v-on:change="handleFiChange('numFPupPkg', contapp.fiFPupPkg)"
				:disabled="!statshr.PupPkgActive"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkEsy"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptEsy"
				:disabled="!statshr.ChkEsyActive"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupTch"
				return-object
				:items="feedFPupTch"
				item-value="num"
				item-text="tit1"
				:label="tag.CptTch"
				v-on:change="handleFiChange('numFPupTch', contapp.fiFPupTch)"
				:disabled="!statshr.PupTchActive"
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
		name: 'PnlWdbeUntDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeUntDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeUntDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeUntDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeUntDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeUntDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeUntDetail) this.contiac = dpcheng.ContIacWdbeUntDetail;
				if (dpcheng.ContInfWdbeUntDetail) this.continf = dpcheng.ContInfWdbeUntDetail;
				if (dpcheng.FeedFPupPkg) this.feedFPupPkg = dpcheng.FeedFPupPkg;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.FeedFPupTch) this.feedFPupTch = dpcheng.FeedFPupTch;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWdbeUntDetail) this.statapp = dpcheng.StatAppWdbeUntDetail;
				if (dpcheng.StatShrWdbeUntDetail) this.statshr = dpcheng.StatShrWdbeUntDetail;
				if (dpcheng.TagWdbeUntDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeUntDetail);
					this.tag = dpcheng.TagWdbeUntDetail;
				}
				if (dpcheng.ContIacWdbeUntDetail) {
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFPupRet.length; i++)
						if (this.feedFPupRet[i].num == this.contiac.numFPupRet) {
							this.contapp.fiFPupRet = this.feedFPupRet[i];
							break;
						}
					for (let i = 0; i < this.feedFPupPkg.length; i++)
						if (this.feedFPupPkg[i].num == this.contiac.numFPupPkg) {
							this.contapp.fiFPupPkg = this.feedFPupPkg[i];
							break;
						}
					for (let i = 0; i < this.feedFPupTch.length; i++)
						if (this.feedFPupTch[i].num == this.contiac.numFPupTch) {
							this.contapp.fiFPupTch = this.feedFPupTch[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeUntDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeUntDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupPkg: null,

			feedFPupRet: null,

			feedFPupTch: null,

			feedFPupTyp: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupTyp: null,

				fiFPupRet: null,

				fiFPupPkg: null,

				fiFPupTch: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
