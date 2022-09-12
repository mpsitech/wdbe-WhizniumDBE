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
				:items="feedFPupTyp"
				:label='tag.CptTyp'
				v-on:change="handlePupChange('numFPupTyp', contapp.fiFPupTyp)"
				:disabled="!statshr.PupTypActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-1"
			>
				<!-- IP divReu - INSERT -->
			</div>

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

			<div
				class="my-1"
			>
				<!-- IP divPkg - INSERT -->
			</div>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkEsy"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptEsy"
				:disabled="!statshr.ChkEsyActive"
			/>

			<div
				class="my-1"
			>
				<!-- IP divTch - INSERT -->
			</div>

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
		name: 'PnlWdbeSilDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeSilDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeSilDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeSilDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeSilDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeSilDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeSilDetail) this.contiac = dpcheng.ContIacWdbeSilDetail;
				if (dpcheng.ContInfWdbeSilDetail) this.continf = dpcheng.ContInfWdbeSilDetail;
				if (dpcheng.FeedFPupPkg) this.feedFPupPkg = dpcheng.FeedFPupPkg;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.FeedFPupTch) this.feedFPupTch = dpcheng.FeedFPupTch;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.StatAppWdbeSilDetail) this.statapp = dpcheng.StatAppWdbeSilDetail;
				if (dpcheng.StatShrWdbeSilDetail) this.statshr = dpcheng.StatShrWdbeSilDetail;
				if (dpcheng.TagWdbeSilDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeSilDetail);
					this.tag = dpcheng.TagWdbeSilDetail;
				}
				if (dpcheng.ContIacWdbeSilDetail) {
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
				if (srefIxWdbeVDpch == "DpchEngWdbeSilDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeSilDetailData") this.mergeDpchEngData(obj.dpcheng);
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
