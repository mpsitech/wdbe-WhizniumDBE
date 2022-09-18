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

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtUnt"
				:label="tag.CptUnt"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupVst"
				return-object
				:items="feedFPupVst"
				item-value="num"
				item-text="tit1"
				:label="tag.CptVst"
				v-on:change="handleFiChange('numFPupVst', contapp.fiFPupVst)"
				:disabled="!statshr.PupVstActive"
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
		name: 'PnlWdbeBnkDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeBnkDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeBnkDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeBnkDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeBnkDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeBnkDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeBnkDetail) this.contiac = dpcheng.ContIacWdbeBnkDetail;
				if (dpcheng.ContInfWdbeBnkDetail) this.continf = dpcheng.ContInfWdbeBnkDetail;
				if (dpcheng.FeedFPupVst) this.feedFPupVst = dpcheng.FeedFPupVst;
				if (dpcheng.StatAppWdbeBnkDetail) this.statapp = dpcheng.StatAppWdbeBnkDetail;
				if (dpcheng.StatShrWdbeBnkDetail) this.statshr = dpcheng.StatShrWdbeBnkDetail;
				if (dpcheng.TagWdbeBnkDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeBnkDetail);
					this.tag = dpcheng.TagWdbeBnkDetail;
				}
				if (dpcheng.ContIacWdbeBnkDetail) {
					for (let i = 0; i < this.feedFPupVst.length; i++)
						if (this.feedFPupVst[i].num == this.contiac.numFPupVst) {
							this.contapp.fiFPupVst = this.feedFPupVst[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeBnkDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeBnkDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupVst: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupVst: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
