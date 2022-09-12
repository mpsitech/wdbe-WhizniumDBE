<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtCpr"
				:label="tag.CptCpr"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfMaj"
				:label="tag.CptMaj"
				:disabled="!statshr.TxfMajActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfMin"
				:label="tag.CptMin"
				:disabled="!statshr.TxfMinActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSub"
				:label="tag.CptSub"
				:disabled="!statshr.TxfSubActive"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtBcv"
				:label="tag.CptBcv"
			/>

			<div
				class="my-1"
			>
				<!-- IP divJst - INSERT -->
			</div>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSte"
				:items="feedFPupSte"
				:label='tag.CptSte'
				v-on:change="handlePupChange('numFPupSte', contapp.fiFPupSte)"
				:disabled="!statshr.PupSteActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<div
				class="my-1"
			>
				<!-- IP divSty - INSERT -->
			</div>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeCvrDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeCvrDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeCvrDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeCvrDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeCvrDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeCvrDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeCvrDetail) this.contiac = dpcheng.ContIacWdbeCvrDetail;
				if (dpcheng.ContInfWdbeCvrDetail) this.continf = dpcheng.ContInfWdbeCvrDetail;
				if (dpcheng.FeedFLstSty) this.feedFLstSty = dpcheng.FeedFLstSty;
				if (dpcheng.FeedFPupJst) this.feedFPupJst = dpcheng.FeedFPupJst;
				if (dpcheng.FeedFPupSte) this.feedFPupSte = dpcheng.FeedFPupSte;
				if (dpcheng.StatAppWdbeCvrDetail) this.statapp = dpcheng.StatAppWdbeCvrDetail;
				if (dpcheng.StatShrWdbeCvrDetail) this.statshr = dpcheng.StatShrWdbeCvrDetail;
				if (dpcheng.TagWdbeCvrDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCvrDetail);
					this.tag = dpcheng.TagWdbeCvrDetail;
				}
				if (dpcheng.ContIacWdbeCvrDetail) {
					for (let i = 0; i < this.feedFPupJst.length; i++)
						if (this.feedFPupJst[i].num == this.contiac.numFPupJst) {
							this.contapp.fiFPupJst = this.feedFPupJst[i];
							break;
						}
					for (let i = 0; i < this.feedFPupSte.length; i++)
						if (this.feedFPupSte[i].num == this.contiac.numFPupSte) {
							this.contapp.fiFPupSte = this.feedFPupSte[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeCvrDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeCvrDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstSty: null,

			feedFPupJst: null,

			feedFPupSte: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJst: null,

				fiFPupSte: null,

				fisFLstSty: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
