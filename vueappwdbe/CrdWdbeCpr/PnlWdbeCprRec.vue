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
					<PnlWdbeCprDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCprDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeCpr1NCoreversion
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCpr1NCoreversion"
						:scrJref=statshr.scrJref1NCoreversion
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeCprMNPerson
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCprMNPerson"
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
	import PnlWdbeCprDetail from './PnlWdbeCprDetail';
	import PnlWdbeCpr1NCoreversion from './PnlWdbeCpr1NCoreversion';
	import PnlWdbeCprMNPerson from './PnlWdbeCprMNPerson';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeCprRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeCprDetail,
			PnlWdbeCpr1NCoreversion,
			PnlWdbeCprMNPerson
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeCprRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeCprRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeCprRec) this.continf = dpcheng.ContInfWdbeCprRec;
				if (dpcheng.StatAppWdbeCprRec) this.statapp = dpcheng.StatAppWdbeCprRec;
				if (dpcheng.StatShrWdbeCprRec) this.statshr = dpcheng.StatShrWdbeCprRec;
				if (dpcheng.TagWdbeCprRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCprRec);
					this.tag = dpcheng.TagWdbeCprRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeCprDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NCoreversion) this.$refs.PnlWdbeCpr1NCoreversion.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNPerson) this.$refs.PnlWdbeCprMNPerson.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeCprRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeCprRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeCprDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NCoreversion) this.$refs.PnlWdbeCpr1NCoreversion.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNPerson) this.$refs.PnlWdbeCprMNPerson.handleUpdate(obj);
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
