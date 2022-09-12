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
				v-model="contapp.fiFDetPupTyp"
				:items="feedFDetPupTyp"
				:label='tag.CptDetTyp'
				v-on:change="handlePupChange('numFDetPupTyp', contapp.fiFDetPupTyp)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupMch"
				:items="feedFDetPupMch"
				:label='tag.CptDetMch'
				v-on:change="handlePupChange('numFDetPupMch', contapp.fiFDetPupMch)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfSrf"
				:label="tag.CptDetSrf"
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
		name: 'DlgWdbeRlsNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWdbeRlsNew.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWdbeRlsNewDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWdbeRlsNewDo"]["srefIxVDo" + ditshort] = ctlsref;

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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWdbeRlsNew"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWdbeRlsNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWdbeRlsNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWdbeRlsNew) this.contiac = dpcheng.ContIacDlgWdbeRlsNew;
				if (dpcheng.ContInfDlgWdbeRlsNew) this.continf = dpcheng.ContInfDlgWdbeRlsNew;
				if (dpcheng.FeedFDetPupMch) this.feedFDetPupMch = dpcheng.FeedFDetPupMch;
				if (dpcheng.FeedFDetPupTyp) this.feedFDetPupTyp = dpcheng.FeedFDetPupTyp;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWdbeRlsNew) this.statapp = dpcheng.StatAppDlgWdbeRlsNew;
				if (dpcheng.StatShrDlgWdbeRlsNew) this.statshr = dpcheng.StatShrDlgWdbeRlsNew;
				if (dpcheng.TagDlgWdbeRlsNew) {
					Wdbe.unescapeBlock(dpcheng.TagDlgWdbeRlsNew);
					this.tag = dpcheng.TagDlgWdbeRlsNew;
				}
				if (dpcheng.ContIacDlgWdbeRlsNew) {
					for (let i = 0; i < this.feedFDetPupTyp.length; i++)
						if (this.feedFDetPupTyp[i].num == this.contiac.numFDetPupTyp) {
							this.contapp.fiFDetPupTyp = this.feedFDetPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupMch.length; i++)
						if (this.feedFDetPupMch[i].num == this.contiac.numFDetPupMch) {
							this.contapp.fiFDetPupMch = this.feedFDetPupMch[i];
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
				if (srefIxWdbeVDpch == "DpchEngDlgWdbeRlsNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngDlgWdbeRlsNewData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFDetPupMch: null,

			feedFDetPupTyp: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFDetPupTyp: null,

				fiFDetPupMch: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
