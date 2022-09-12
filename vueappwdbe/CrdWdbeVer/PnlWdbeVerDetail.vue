<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPrj"
				:label="tag.CptPrj"
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
				v-model="continf.TxtBvr"
				:label="tag.CptBvr"
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

			<v-text-field
				class="my-1"
				v-model="contiac.TxfAbt"
				:label="tag.CptAbt"
				:disabled="!statshr.TxfAbtActive"
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
		name: 'PnlWdbeVerDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeVerDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeVerDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeVerDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeVerDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeVerDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeVerDetail) this.contiac = dpcheng.ContIacWdbeVerDetail;
				if (dpcheng.ContInfWdbeVerDetail) this.continf = dpcheng.ContInfWdbeVerDetail;
				if (dpcheng.FeedFPupJst) this.feedFPupJst = dpcheng.FeedFPupJst;
				if (dpcheng.FeedFPupSte) this.feedFPupSte = dpcheng.FeedFPupSte;
				if (dpcheng.StatAppWdbeVerDetail) this.statapp = dpcheng.StatAppWdbeVerDetail;
				if (dpcheng.StatShrWdbeVerDetail) this.statshr = dpcheng.StatShrWdbeVerDetail;
				if (dpcheng.TagWdbeVerDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeVerDetail);
					this.tag = dpcheng.TagWdbeVerDetail;
				}
				if (dpcheng.ContIacWdbeVerDetail) {
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
				if (srefIxWdbeVDpch == "DpchEngWdbeVerDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeVerDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupJst: null,

			feedFPupSte: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJst: null,

				fiFPupSte: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
