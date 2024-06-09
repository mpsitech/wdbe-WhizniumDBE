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
					<PnlWdbePrsDetail
						v-on:request="handleRequest"
						ref="PnlWdbePrsDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbePrsADetail
						v-on:request="handleRequest"
						ref="PnlWdbePrsADetail"
						:scrJref=statshr.scrJrefADetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbePrsMNProject
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrsMNProject"
						:scrJref=statshr.scrJrefMNProject
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbePrsMNCoreproject
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrsMNCoreproject"
						:scrJref=statshr.scrJrefMNCoreproject
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
	import PnlWdbePrsDetail from './PnlWdbePrsDetail';
	import PnlWdbePrsADetail from './PnlWdbePrsADetail';
	import PnlWdbePrsMNProject from './PnlWdbePrsMNProject';
	import PnlWdbePrsMNCoreproject from './PnlWdbePrsMNCoreproject';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbePrsRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbePrsDetail,
			PnlWdbePrsADetail,
			PnlWdbePrsMNProject,
			PnlWdbePrsMNCoreproject
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbePrsRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbePrsRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbePrsRec) this.continf = dpcheng.ContInfWdbePrsRec;
				if (dpcheng.StatAppWdbePrsRec) this.statapp = dpcheng.StatAppWdbePrsRec;
				if (dpcheng.StatShrWdbePrsRec) this.statshr = dpcheng.StatShrWdbePrsRec;
				if (dpcheng.TagWdbePrsRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrsRec);
					this.tag = dpcheng.TagWdbePrsRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbePrsDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefADetail) this.$refs.PnlWdbePrsADetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNProject) this.$refs.PnlWdbePrsMNProject.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNCoreproject) this.$refs.PnlWdbePrsMNCoreproject.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbePrsRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbePrsRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbePrsDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefADetail) this.$refs.PnlWdbePrsADetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNProject) this.$refs.PnlWdbePrsMNProject.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNCoreproject) this.$refs.PnlWdbePrsMNCoreproject.handleUpdate(obj);
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
