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

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtClk"
				:label="tag.CptClk"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtAsr"
				:label="tag.CptAsr"
			/>

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

			<v-select
				v-if="statshr.PupFsmDttAvail"
				class="my-1"
				v-model="contapp.fiFPupFsmDtt"
				return-object
				:items="feedFPupFsmDtt"
				item-value="num"
				item-text="tit1"
				:label="tag.CptFsmDtt"
				v-on:change="handleFiChange('numFPupFsmDtt', contapp.fiFPupFsmDtt)"
				:disabled="!statshr.PupFsmDttActive"
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

			handleFiChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
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
				if (dpcheng.FeedFPupFsmDtt) this.feedFPupFsmDtt = dpcheng.FeedFPupFsmDtt;
				if (dpcheng.StatAppWdbePrcDetail) this.statapp = dpcheng.StatAppWdbePrcDetail;
				if (dpcheng.StatShrWdbePrcDetail) this.statshr = dpcheng.StatShrWdbePrcDetail;
				if (dpcheng.TagWdbePrcDetail) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrcDetail);
					this.tag = dpcheng.TagWdbePrcDetail;
				}
				if (dpcheng.ContIacWdbePrcDetail) {
					for (let i = 0; i < this.feedFPupFsmDtt.length; i++)
						if (this.feedFPupFsmDtt[i].num == this.contiac.numFPupFsmDtt) {
							this.contapp.fiFPupFsmDtt = this.feedFPupFsmDtt[i];
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

			feedFPupFsmDtt: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupFsmDtt: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
