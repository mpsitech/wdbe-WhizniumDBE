<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<div
				class="my-1"
			>
				<!-- IP divReu - INSERT -->
			</div>

			<div
				class="my-1"
			>
				<!-- IP divSru - INSERT -->
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
		name: 'PnlWdbeSnsDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeSnsDetail.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeSnsDetailDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeSnsDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeSnsDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeSnsDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbeSnsDetail) this.contiac = dpcheng.ContIacWdbeSnsDetail;
				if (dpcheng.ContInfWdbeSnsDetail) this.continf = dpcheng.ContInfWdbeSnsDetail;
				if (dpcheng.FeedFPupRet) this.feedFPupRet = dpcheng.FeedFPupRet;
				if (dpcheng.FeedFPupSrt) this.feedFPupSrt = dpcheng.FeedFPupSrt;
				if (dpcheng.StatAppWdbeSnsDetail) this.statapp = dpcheng.StatAppWdbeSnsDetail;
				if (dpcheng.StatShrWdbeSnsDetail) this.statshr = dpcheng.StatShrWdbeSnsDetail;
				if (dpcheng.TagWdbeSnsDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeSnsDetail);
					this.tag = dpcheng.TagWdbeSnsDetail;
				}
				if (dpcheng.ContIacWdbeSnsDetail) {
					for (let i = 0; i < this.feedFPupRet.length; i++)
						if (this.feedFPupRet[i].num == this.contiac.numFPupRet) {
							this.contapp.fiFPupRet = this.feedFPupRet[i];
							break;
						}
					for (let i = 0; i < this.feedFPupSrt.length; i++)
						if (this.feedFPupSrt[i].num == this.contiac.numFPupSrt) {
							this.contapp.fiFPupSrt = this.feedFPupSrt[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbeSnsDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeSnsDetailData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPupSrt: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupRet: null,

				fiFPupSrt: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
