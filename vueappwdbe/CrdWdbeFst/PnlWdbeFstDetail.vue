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

			<div
				class="my-1"
			>
				<!-- IP divClu - INSERT -->
			</div>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFsm"
				:label="tag.CptFsm"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkEip"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptEip"
				:disabled="!statshr.ChkEipActive"
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
		name: 'PnlWdbeFstDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeFstDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeFstDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeFstDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeFstDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeFstDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeFstDetail) this.contiac = dpcheng.ContIacWdbeFstDetail;
				if (dpcheng.ContInfWdbeFstDetail) this.continf = dpcheng.ContInfWdbeFstDetail;
				if (dpcheng.FeedFLstClu) this.feedFLstClu = dpcheng.FeedFLstClu;
				if (dpcheng.StatAppWdbeFstDetail) this.statapp = dpcheng.StatAppWdbeFstDetail;
				if (dpcheng.StatShrWdbeFstDetail) this.statshr = dpcheng.StatShrWdbeFstDetail;
				if (dpcheng.TagWdbeFstDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeFstDetail);
					this.tag = dpcheng.TagWdbeFstDetail;
				}
				if (dpcheng.ContIacWdbeFstDetail) {
					for (let i = 0; i < this.feedFLstClu.length; i++)
						if (this.feedFLstClu[i].num == this.contiac.numFLstClu) {
							this.contapp.fiFLstClu = this.feedFLstClu[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeFstDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeFstDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFLstClu: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
