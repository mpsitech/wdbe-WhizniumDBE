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
				v-model="contapp.fiFDetPupPrj"
				:items="feedFDetPupPrj"
				:label='tag.CptDetPrj'
				v-on:change="handlePupChange('numFDetPupPrj', contapp.fiFDetPupPrj)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupBvr"
				:items="feedFDetPupBvr"
				:label='tag.CptDetBvr'
				v-on:change="handlePupChange('numFDetPupBvr', contapp.fiFDetPupBvr)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfCmt"
				:label="tag.CptDetCmt"
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
		name: 'DlgWdbeVerNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeVerNew.mounted() with scrJref = " + this.scrJref);

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
				var dpchapp = {
					"DpchAppDlgWdbeVerNewDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWdbeVerNewDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeVerNew"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeVerNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeVerNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeVerNew) this.contiac = dpcheng.ContIacDlgWdbeVerNew;
				if (dpcheng.ContInfDlgWdbeVerNew) this.continf = dpcheng.ContInfDlgWdbeVerNew;
				if (dpcheng.FeedFDetPupBvr) this.feedFDetPupBvr = dpcheng.FeedFDetPupBvr;
				if (dpcheng.FeedFDetPupPrj) this.feedFDetPupPrj = dpcheng.FeedFDetPupPrj;
				if (dpcheng.FeedFDetRbuVni) this.feedFDetRbuVni = dpcheng.FeedFDetRbuVni;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeVerNew) this.statapp = dpcheng.StatAppDlgWdbeVerNew;
				if (dpcheng.StatShrDlgWdbeVerNew) this.statshr = dpcheng.StatShrDlgWdbeVerNew;
				if (dpcheng.TagDlgWdbeVerNew) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeVerNew);
					this.tag = dpcheng.TagDlgWdbeVerNew;
				}
				if (dpcheng.ContIacDlgWdbeVerNew) {
					for (let i = 0; i < this.feedFDetPupPrj.length; i++)
						if (this.feedFDetPupPrj[i].num == this.contiac.numFDetPupPrj) {
							this.contapp.fiFDetPupPrj = this.feedFDetPupPrj[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupBvr.length; i++)
						if (this.feedFDetPupBvr[i].num == this.contiac.numFDetPupBvr) {
							this.contapp.fiFDetPupBvr = this.feedFDetPupBvr[i];
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeVerNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeVerNewData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFDetPupBvr: null,

			feedFDetPupPrj: null,

			feedFDetRbuVni: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFDetPupPrj: null,

				fiFDetPupBvr: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
