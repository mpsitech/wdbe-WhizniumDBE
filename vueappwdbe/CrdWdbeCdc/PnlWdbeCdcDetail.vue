<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFck"
				:label="tag.CptFck"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSck"
				:label="tag.CptSck"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtMdl"
				:label="tag.CptMdl"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtFar"
				:label="tag.CptFar"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSar"
				:label="tag.CptSar"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfRat"
				:label="tag.CptRat"
				:disabled="!statshr.TxfRatActive"
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
		name: 'PnlWdbeCdcDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeCdcDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeCdcDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeCdcDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeCdcDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeCdcDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeCdcDetail) this.contiac = dpcheng.ContIacWdbeCdcDetail;
				if (dpcheng.ContInfWdbeCdcDetail) this.continf = dpcheng.ContInfWdbeCdcDetail;
				if (dpcheng.StatAppWdbeCdcDetail) this.statapp = dpcheng.StatAppWdbeCdcDetail;
				if (dpcheng.StatShrWdbeCdcDetail) this.statshr = dpcheng.StatShrWdbeCdcDetail;
				if (dpcheng.TagWdbeCdcDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCdcDetail);
					this.tag = dpcheng.TagWdbeCdcDetail;
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
				if (srefIxWdbeVDpch == "DpchEngWdbeCdcDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeCdcDetailData") this.mergeDpchEngData(obj.dpcheng);
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
