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
				v-model="continf.TxtSys"
				:label="tag.CptSys"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtUnt"
				:label="tag.CptUnt"
			/>

			<div
				class="my-1"
			>
				<!-- IP divRte - INSERT -->
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
		name: 'PnlWdbeTrgDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeTrgDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeTrgDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeTrgDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeTrgDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeTrgDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeTrgDetail) this.contiac = dpcheng.ContIacWdbeTrgDetail;
				if (dpcheng.ContInfWdbeTrgDetail) this.continf = dpcheng.ContInfWdbeTrgDetail;
				if (dpcheng.FeedFLstRte) this.feedFLstRte = dpcheng.FeedFLstRte;
				if (dpcheng.StatAppWdbeTrgDetail) this.statapp = dpcheng.StatAppWdbeTrgDetail;
				if (dpcheng.StatShrWdbeTrgDetail) this.statshr = dpcheng.StatShrWdbeTrgDetail;
				if (dpcheng.TagWdbeTrgDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeTrgDetail);
					this.tag = dpcheng.TagWdbeTrgDetail;
				}
				if (dpcheng.ContIacWdbeTrgDetail) {
					for (let i = 0; i < this.feedFLstRte.length; i++)
						if (this.feedFLstRte[i].num == this.contiac.numFLstRte) {
							this.contapp.fiFLstRte = this.feedFLstRte[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeTrgDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeTrgDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFLstRte: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFLstRte: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
