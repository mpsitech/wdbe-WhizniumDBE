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
				v-model="contiac.TxfFsr"
				:label="tag.CptFsr"
				:disabled="!statshr.TxfFsrActive"
			/>

			<v-divider/>

			<div
				class="my-1"
			>
				<!-- IP divReu - INSERT -->
			</div>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupRty"
				:items="feedFPupRty"
				:label='tag.CptRty'
				v-on:change="handlePupChange('numFPupRty', contapp.fiFPupRty)"
				:disabled="!statshr.PupRtyActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtIvr"
				:label="tag.CptIvr"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtRvr"
				:label="tag.CptRvr"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtRer"
				:label="tag.CptRer"
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
		name: 'PnlWdbeCmdDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeCmdDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeCmdDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeCmdDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeCmdDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeCmdDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeCmdDetail) this.contiac = dpcheng.ContIacWdbeCmdDetail;
				if (dpcheng.ContInfWdbeCmdDetail) this.continf = dpcheng.ContInfWdbeCmdDetail;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.FeedFPupRty) this.feedFPupRty = dpcheng.FeedFPupRty;
				if (dpcheng.StatAppWdbeCmdDetail) this.statapp = dpcheng.StatAppWdbeCmdDetail;
				if (dpcheng.StatShrWdbeCmdDetail) this.statshr = dpcheng.StatShrWdbeCmdDetail;
				if (dpcheng.TagWdbeCmdDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCmdDetail);
					this.tag = dpcheng.TagWdbeCmdDetail;
				}
				if (dpcheng.ContIacWdbeCmdDetail) {
					for (let i = 0; i < this.feedFPupRet.length; i++)
						if (this.feedFPupRet[i].num == this.contiac.numFPupRet) {
							this.contapp.fiFPupRet = this.feedFPupRet[i];
							break;
						}
					for (let i = 0; i < this.feedFPupRty.length; i++)
						if (this.feedFPupRty[i].num == this.contiac.numFPupRty) {
							this.contapp.fiFPupRty = this.feedFPupRty[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeCmdDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeCmdDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupRet: null,

			feedFPupRty: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupRet: null,

				fiFPupRty: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
