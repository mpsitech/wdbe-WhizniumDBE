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

			<div
				class="my-1"
			>
				<!-- IP divVnd - INSERT -->
			</div>

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
				<!-- IP divHku - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSup"
				:label="tag.CptSup"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtTpl"
				:label="tag.CptTpl"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSrr"
				:label="tag.CptSrr"
				:disabled="!statshr.TxfSrrActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmt"
				:label="tag.CptCmt"
				:disabled="!statshr.TxfCmtActive"
			/>

			<v-divider v-if="statshr.SepCtrAvail"/>

			<h3
				v-if="statshr.HdgCtrAvail"
				class="text-5 my-1"
			>
				{{tag.HdgCtr}}
			</h3>

			<v-text-field
				v-if="statshr.TxfCtrFsrAvail"
				class="my-1"
				v-model="contiac.TxfCtrFsr"
				:label="tag.CptCtrFsr"
				:disabled="!statshr.TxfCtrFsrActive"
			/>

			<v-text-field
				v-if="statshr.TxtCtrFwdAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtCtrFwd"
				:label="tag.CptCtrFwd"
			/>

			<v-text-field
				v-if="statshr.TxtCtrClrAvail"
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtCtrClr"
				:label="tag.CptCtrClr"
			/>

			<v-divider v-if="statshr.SepImbAvail"/>

			<h3
				v-if="statshr.HdgImbAvail"
				class="text-5 my-1"
			>
				{{tag.HdgImb}}
			</h3>

			<v-text-field
				v-if="statshr.TxfImbFsrAvail"
				class="my-1"
				v-model="contiac.TxfImbFsr"
				:label="tag.CptImbFsr"
				:disabled="!statshr.TxfImbFsrActive"
			/>

			<v-select
				v-if="statshr.PupImbRtyAvail"
				class="my-1"
				v-model="contapp.fiFPupImbRty"
				:items="feedFPupImbRty"
				:label='tag.CptImbRty'
				v-on:change="handlePupChange('numFPupImbRty', contapp.fiFPupImbRty)"
				:disabled="!statshr.PupImbRtyActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				v-if="statshr.TxfImbWidAvail"
				class="my-1"
				v-model="contiac.TxfImbWid"
				:label="tag.CptImbWid"
				:disabled="!statshr.TxfImbWidActive"
			/>

			<v-text-field
				v-if="statshr.TxfImbMmxAvail"
				class="my-1"
				v-model="contiac.TxfImbMmx"
				:label="tag.CptImbMmx"
				:disabled="!statshr.TxfImbMmxActive"
			/>

			<v-text-field
				v-if="statshr.TxfImbPriAvail"
				class="my-1"
				v-model="contiac.TxfImbPri"
				:label="tag.CptImbPri"
				:disabled="!statshr.TxfImbPriActive"
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
		name: 'PnlWdbeModDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeModDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeModDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeModDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeModDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeModDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeModDetail) this.contiac = dpcheng.ContIacWdbeModDetail;
				if (dpcheng.ContInfWdbeModDetail) this.continf = dpcheng.ContInfWdbeModDetail;
				if (dpcheng.FeedFPupHkt) this.feedFPupHkt = dpcheng.FeedFPupHkt;
				if (dpcheng.FeedFPupImbRty) this.feedFPupImbRty = dpcheng.FeedFPupImbRty;
				if (dpcheng.FeedFPupTyp) this.feedFPupTyp = dpcheng.FeedFPupTyp;
				if (dpcheng.FeedFPupVnd) this.feedFPupVnd = dpcheng.FeedFPupVnd;
				if (dpcheng.StatAppWdbeModDetail) this.statapp = dpcheng.StatAppWdbeModDetail;
				if (dpcheng.StatShrWdbeModDetail) this.statshr = dpcheng.StatShrWdbeModDetail;
				if (dpcheng.TagWdbeModDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeModDetail);
					this.tag = dpcheng.TagWdbeModDetail;
				}
				if (dpcheng.ContIacWdbeModDetail) {
					for (let i = 0; i < this.feedFPupVnd.length; i++)
						if (this.feedFPupVnd[i].num == this.contiac.numFPupVnd) {
							this.contapp.fiFPupVnd = this.feedFPupVnd[i];
							break;
						}
					for (let i = 0; i < this.feedFPupTyp.length; i++)
						if (this.feedFPupTyp[i].num == this.contiac.numFPupTyp) {
							this.contapp.fiFPupTyp = this.feedFPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFPupHkt.length; i++)
						if (this.feedFPupHkt[i].num == this.contiac.numFPupHkt) {
							this.contapp.fiFPupHkt = this.feedFPupHkt[i];
							break;
						}
					for (let i = 0; i < this.feedFPupImbRty.length; i++)
						if (this.feedFPupImbRty[i].num == this.contiac.numFPupImbRty) {
							this.contapp.fiFPupImbRty = this.feedFPupImbRty[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeModDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeModDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupHkt: null,

			feedFPupImbRty: null,

			feedFPupTyp: null,

			feedFPupVnd: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupVnd: null,

				fiFPupTyp: null,

				fiFPupHkt: null,

				fiFPupImbRty: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
