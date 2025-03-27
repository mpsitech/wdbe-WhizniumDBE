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
			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg1}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf2"
				:label="tag.Cpt2"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.Chk3"
				v-on:change='updateEng(["contiac"])'
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

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg101}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf102"
				:label="tag.Cpt102"
			/>

			<v-checkbox
				class="my-1"
				v-model="contiac.Chk103"
				v-on:change='updateEng(["contiac"])'
				:label="tag.Cpt103"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf104"
				:label="tag.Cpt104"
			/>

			<v-divider v-if="statshr.Sep2Avail"/>

			<h3
				v-if="statshr.Hdg201Avail"
				class="text-5 my-1"
			>
				{{tag.Hdg201}}
			</h3>

			<v-text-field
				v-if="statshr.Txf202Avail"
				class="my-1"
				v-model="contiac.Txf202"
				:label="tag.Cpt202"
			/>

			<v-text-field
				v-if="statshr.Txf203Avail"
				class="my-1"
				v-model="contiac.Txf203"
				:label="tag.Cpt203"
			/>

			<v-checkbox
				v-if="statshr.Chk204Avail"
				class="my-1"
				v-model="contiac.Chk204"
				v-on:change='updateEng(["contiac"])'
				:label="tag.Cpt204"
			/>

			<v-divider v-if="statshr.Sep3Avail"/>

			<h3
				v-if="statshr.Hdg301Avail"
				class="text-5 my-1"
			>
				{{tag.Hdg301}}
			</h3>

			<v-text-field
				v-if="statshr.Txf302Avail"
				class="my-1"
				v-model="contiac.Txf302"
				:label="tag.Cpt302"
			/>

			<v-text-field
				v-if="statshr.Txf303Avail"
				class="my-1"
				v-model="contiac.Txf303"
				:label="tag.Cpt303"
			/>

			<v-checkbox
				v-if="statshr.Chk304Avail"
				class="my-1"
				v-model="contiac.Chk304"
				v-on:change='updateEng(["contiac"])'
				:label="tag.Cpt304"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg401}}
			</h3>

			<v-select
				class="my-1"
				v-model="contapp.fiFPup402"
				return-object
				:items="feedFPup402"
				item-value="num"
				item-text="tit1"
				:label="tag.Cpt402"
				v-on:change="handleFiChange('numFPup402', contapp.fiFPup402)"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf403"
				:label="tag.Cpt403"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf404"
				:label="tag.Cpt404"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf405"
				:label="tag.Cpt405"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf406"
				:label="tag.Cpt406"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf407"
				:label="tag.Cpt407"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf408"
				:label="tag.Cpt408"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg501}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf502"
				:label="tag.Cpt502"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf503"
				:label="tag.Cpt503"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf504"
				:label="tag.Cpt504"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf505"
				:label="tag.Cpt505"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf506"
				:label="tag.Cpt506"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf507"
				:label="tag.Cpt507"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg601}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf602"
				:label="tag.Cpt602"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf603"
				:label="tag.Cpt603"
			/>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.Hdg701}}
			</h3>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf702"
				:label="tag.Cpt702"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf703"
				:label="tag.Cpt703"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf704"
				:label="tag.Cpt704"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf705"
				:label="tag.Cpt705"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFPup706"
				return-object
				:items="feedFPup706"
				item-value="num"
				item-text="tit1"
				:label="tag.Cpt706"
				v-on:change="handleFiChange('numFPup706', contapp.fiFPup706)"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf707"
				:label="tag.Cpt707"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf708"
				:label="tag.Cpt708"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf709"
				:label="tag.Cpt709"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.Txf710"
				:label="tag.Cpt710"
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
		name: 'PnlWdbePrfDaemon',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbePrfDaemon.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbePrfDaemonDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbePrfDaemon"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbePrfDaemonData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbePrfDaemonData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWdbePrfDaemon) this.contiac = dpcheng.ContIacWdbePrfDaemon;
				if (dpcheng.FeedFPup402) this.feedFPup402 = dpcheng.FeedFPup402;
				if (dpcheng.FeedFPup706) this.feedFPup706 = dpcheng.FeedFPup706;
				if (dpcheng.StatShrWdbePrfDaemon) this.statshr = dpcheng.StatShrWdbePrfDaemon;
				if (dpcheng.TagWdbePrfDaemon) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrfDaemon);
					this.tag = dpcheng.TagWdbePrfDaemon;
				}
				if (dpcheng.ContIacWdbePrfDaemon) {
					for (let i = 0; i < this.feedFPup402.length; i++)
						if (this.feedFPup402[i].num == this.contiac.numFPup402) {
							this.contapp.fiFPup402 = this.feedFPup402[i];
							break;
						}
					for (let i = 0; i < this.feedFPup706.length; i++)
						if (this.feedFPup706[i].num == this.contiac.numFPup706) {
							this.contapp.fiFPup706 = this.feedFPup706[i];
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
				if (srefIxWdbeVDpch == "DpchEngWdbePrfDaemonData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbePrfDaemonData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFPup402: null,

			feedFPup706: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPup402: null,

				fiFPup706: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
