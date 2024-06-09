<template>
	<v-card v-if="initdone" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{tag.Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end"/>
			</v-row>
		</v-card-title>
		<v-card-text>
			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupCpr"
				return-object
				:items="feedFDetPupCpr"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetCpr"
				v-on:change="handleFiChange('', 'numFDetPupCpr', contapp.fiFDetPupCpr)"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupBcv"
				return-object
				:items="feedFDetPupBcv"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetBcv"
				v-on:change="handleFiChange('', 'numFDetPupBcv', contapp.fiFDetPupBcv)"
			/>

		</v-card-text>
		<v-divider/>
		<v-card-actions>
			<v-spacer/>
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButCncClick')"
			>
				{{tag.ButCnc}}
			</v-btn>
			&#160;
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButCreClick')"
			>
				{{tag.ButCre}}
			</v-btn>
		</v-card-actions>
	</v-card>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'DlgWdbeCvrNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeCvrNew.mounted() with scrJref = " + this.scrJref);

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

			handleButClick: function(ditshort, ctlsref) {
				var srefIxVDo = "srefIxVDo";
				if (ditshort != "") srefIxVDo += ditshort.charAt(0).toUpperCase() + ditshort.slice(1);

				const dpchapp = {
					"DpchAppDlgWdbeCvrNewDo": {
						"scrJref": this.scrJref,
						[srefIxVDo]: ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleFiChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeCvrNew"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeCvrNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeCvrNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeCvrNew) this.contiac = dpcheng.ContIacDlgWdbeCvrNew;
				if (dpcheng.ContInfDlgWdbeCvrNew) this.continf = dpcheng.ContInfDlgWdbeCvrNew;
				if (dpcheng.FeedFDetPupBcv) this.feedFDetPupBcv = dpcheng.FeedFDetPupBcv;
				if (dpcheng.FeedFDetPupCpr) this.feedFDetPupCpr = dpcheng.FeedFDetPupCpr;
				if (dpcheng.FeedFDetRbuVni) this.feedFDetRbuVni = dpcheng.FeedFDetRbuVni;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeCvrNew) this.statapp = dpcheng.StatAppDlgWdbeCvrNew;
				if (dpcheng.StatShrDlgWdbeCvrNew) this.statshr = dpcheng.StatShrDlgWdbeCvrNew;
				if (dpcheng.TagDlgWdbeCvrNew) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeCvrNew);
					this.tag = dpcheng.TagDlgWdbeCvrNew;
				}
				if (dpcheng.ContIacDlgWdbeCvrNew) {
					for (let i = 0; i < this.feedFDetPupCpr.length; i++)
						if (this.feedFDetPupCpr[i].num == this.contiac.numFDetPupCpr) {
							this.contapp.fiFDetPupCpr = this.feedFDetPupCpr[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupBcv.length; i++)
						if (this.feedFDetPupBcv[i].num == this.contiac.numFDetPupBcv) {
							this.contapp.fiFDetPupBcv = this.feedFDetPupBcv[i];
							break;
						}
				}
				/*
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeCvrNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeCvrNewData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFDetPupBcv: null,

			feedFDetPupCpr: null,

			feedFDetRbuVni: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFDetPupCpr: null,

				fiFDetPupBcv: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
