<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="3">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWdbeVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWdbeVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWdbeVExpstate=='regd'"
		>
			<v-text-field
				class="my-1"
				v-model="contiac.Txf1"
				:label="tag.Cpt1"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf2"
				:label="tag.Cpt2"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf3"
				:label="tag.Cpt3"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf4"
				:label="tag.Cpt4"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf5"
				:label="tag.Cpt5"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf6"
				:label="tag.Cpt6"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf7"
				:label="tag.Cpt7"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf8"
				:label="tag.Cpt8"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf9"
				:label="tag.Cpt9"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf10"
				:label="tag.Cpt10"
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
		name: 'PnlWdbePrfLicense',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbePrfLicense.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbePrfLicenseDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbePrfLicense"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbePrfLicenseData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbePrfLicenseData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbePrfLicense) this.contiac = dpcheng.ContIacWdbePrfLicense;
				if (dpcheng.StatShrWdbePrfLicense) this.statshr = dpcheng.StatShrWdbePrfLicense;
				if (dpcheng.TagWdbePrfLicense) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrfLicense);
					this.tag = dpcheng.TagWdbePrfLicense;
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
				if (srefIxWdbeVDpch == "DpchEngWdbePrfLicenseData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbePrfLicenseData") this.mergeDpchEngData(obj.dpcheng);
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
