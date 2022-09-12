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
					<PnlWdbeCmdDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCmdDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeCmdAInvpar
						v-on:request="handleRequest"
						ref="PnlWdbeCmdAInvpar"
						:scrJref=statshr.scrJrefAInvpar
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeCmdARetpar
						v-on:request="handleRequest"
						ref="PnlWdbeCmdARetpar"
						:scrJref=statshr.scrJrefARetpar
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeCmdMNController
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCmdMNController"
						:scrJref=statshr.scrJrefMNController
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
	import PnlWdbeCmdDetail from './PnlWdbeCmdDetail';
	import PnlWdbeCmdAInvpar from './PnlWdbeCmdAInvpar';
	import PnlWdbeCmdARetpar from './PnlWdbeCmdARetpar';
	import PnlWdbeCmdMNController from './PnlWdbeCmdMNController';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeCmdRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeCmdDetail,
			PnlWdbeCmdAInvpar,
			PnlWdbeCmdARetpar,
			PnlWdbeCmdMNController
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeCmdRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeCmdRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeCmdRec) this.continf = dpcheng.ContInfWdbeCmdRec;
				if (dpcheng.StatAppWdbeCmdRec) this.statapp = dpcheng.StatAppWdbeCmdRec;
				if (dpcheng.StatShrWdbeCmdRec) this.statshr = dpcheng.StatShrWdbeCmdRec;
				if (dpcheng.TagWdbeCmdRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCmdRec);
					this.tag = dpcheng.TagWdbeCmdRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeCmdDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAInvpar) this.$refs.PnlWdbeCmdAInvpar.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefARetpar) this.$refs.PnlWdbeCmdARetpar.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNController) this.$refs.PnlWdbeCmdMNController.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeCmdRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeCmdRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeCmdDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAInvpar) this.$refs.PnlWdbeCmdAInvpar.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefARetpar) this.$refs.PnlWdbeCmdARetpar.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNController) this.$refs.PnlWdbeCmdMNController.handleUpdate(obj);
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
