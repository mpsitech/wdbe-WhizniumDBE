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
				v-model="continf.TxtMdl"
				:label="tag.CptMdl"
			/>

			<div
				class="my-1"
			>
				<!-- IP divClk - INSERT -->
			</div>

			<div
				class="my-1"
			>
				<!-- IP divAsr - INSERT -->
			</div>

			<v-checkbox
				class="my-1"
				v-model="contiac.ChkFal"
				v-on:change='updateEng(["contiac"])'
				:label="tag.CptFal"
				:disabled="!statshr.ChkFalActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfSnr"
				:label="tag.CptSnr"
				:disabled="!statshr.TxfSnrActive"
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

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.HdgFsm}}
			</h3>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbePrcDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbePrcDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbePrcDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbePrcDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbePrcDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbePrcDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbePrcDetail) this.contiac = dpcheng.ContIacWdbePrcDetail;
				if (dpcheng.ContInfWdbePrcDetail) this.continf = dpcheng.ContInfWdbePrcDetail;
				if (dpcheng.StatAppWdbePrcDetail) this.statapp = dpcheng.StatAppWdbePrcDetail;
				if (dpcheng.StatShrWdbePrcDetail) this.statshr = dpcheng.StatShrWdbePrcDetail;
				if (dpcheng.TagWdbePrcDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrcDetail);
					this.tag = dpcheng.TagWdbePrcDetail;
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
				if (srefIxWdbeVDpch == "DpchEngWdbePrcDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbePrcDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
