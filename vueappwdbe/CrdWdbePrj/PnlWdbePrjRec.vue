<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="9">
					<div class="caption text-decoration-underline">{{tag.Cpt}}</div>
					<div>{{continf.TxtRef}}</div>
				</v-col>
				<v-col cols="3" align="end">
					<v-btn
						v-if="statshr.srefIxWdbeVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeCLick')"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					<v-btn
						v-if="statshr.srefIxWdbeVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						:disabled="!statshr.ButRegularizeActive"
						v-on:click="handleButClick('ButRegularizeClick')"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWdbeVExpstate=='regd'"
		>
			<v-row>
				<v-col cols="12" md="12">
					<PnlWdbePrjDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrjDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbePrjPrj1NVersion
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrjPrj1NVersion"
						:scrJref=statshr.scrJrefPrj1NVersion
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbePrjMNPerson
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrjMNPerson"
						:scrJref=statshr.scrJrefMNPerson
					/>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbePrjDetail from './PnlWdbePrjDetail';
	import PnlWdbePrjPrj1NVersion from './PnlWdbePrjPrj1NVersion';
	import PnlWdbePrjMNPerson from './PnlWdbePrjMNPerson';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbePrjRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbePrjDetail,
			PnlWdbePrjPrj1NVersion,
			PnlWdbePrjMNPerson
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbePrjRec.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWdbeInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWdbePrjRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbePrjRec) this.continf = dpcheng.ContInfWdbePrjRec;
				if (dpcheng.StatAppWdbePrjRec) this.statapp = dpcheng.StatAppWdbePrjRec;
				if (dpcheng.StatShrWdbePrjRec) this.statshr = dpcheng.StatShrWdbePrjRec;
				if (dpcheng.TagWdbePrjRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrjRec);
					this.tag = dpcheng.TagWdbePrjRec;
				}
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				//console.log(obj);
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
					else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWdbeVDpch, obj.dpcheng);

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						/*
						*/
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbePrjDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefPrj1NVersion) this.$refs.PnlWdbePrjPrj1NVersion.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNPerson) this.$refs.PnlWdbePrjMNPerson.handleReply(obj);
						/*
						*/
					}
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWdbeVDpch, dpcheng) {
				if (srefIxWdbeVDpch == "DpchEngWdbePrjRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbePrjRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbePrjDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefPrj1NVersion) this.$refs.PnlWdbePrjPrj1NVersion.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNPerson) this.$refs.PnlWdbePrjMNPerson.handleUpdate(obj);
						/*
						*/
						else processed = false;
					}
				}

				return processed
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
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
