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
					<PnlWdbePrcDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrcDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbePrcKHdltype
						v-on:request="handleRequest"
						ref="PnlWdbePrcKHdltype"
						:scrJref=statshr.scrJrefKHdltype
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbePrcRef1NSensitivity
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrcRef1NSensitivity"
						:scrJref=statshr.scrJrefRef1NSensitivity
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbePrcRef1NVariable
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrcRef1NVariable"
						:scrJref=statshr.scrJrefRef1NVariable
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbePrcMge1NSignal
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrcMge1NSignal"
						:scrJref=statshr.scrJrefMge1NSignal
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbePrcFsmFsm1NFsmstate
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbePrcFsmFsm1NFsmstate"
						:scrJref=statshr.scrJrefFsmFsm1NFsmstate
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
	import PnlWdbePrcDetail from './PnlWdbePrcDetail';
	import PnlWdbePrcKHdltype from './PnlWdbePrcKHdltype';
	import PnlWdbePrcRef1NSensitivity from './PnlWdbePrcRef1NSensitivity';
	import PnlWdbePrcRef1NVariable from './PnlWdbePrcRef1NVariable';
	import PnlWdbePrcMge1NSignal from './PnlWdbePrcMge1NSignal';
	import PnlWdbePrcFsmFsm1NFsmstate from './PnlWdbePrcFsmFsm1NFsmstate';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbePrcRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbePrcDetail,
			PnlWdbePrcKHdltype,
			PnlWdbePrcRef1NSensitivity,
			PnlWdbePrcRef1NVariable,
			PnlWdbePrcMge1NSignal,
			PnlWdbePrcFsmFsm1NFsmstate
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbePrcRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbePrcRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbePrcRec) this.continf = dpcheng.ContInfWdbePrcRec;
				if (dpcheng.StatAppWdbePrcRec) this.statapp = dpcheng.StatAppWdbePrcRec;
				if (dpcheng.StatShrWdbePrcRec) this.statshr = dpcheng.StatShrWdbePrcRec;
				if (dpcheng.TagWdbePrcRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrcRec);
					this.tag = dpcheng.TagWdbePrcRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbePrcDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefKHdltype) this.$refs.PnlWdbePrcKHdltype.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NSensitivity) this.$refs.PnlWdbePrcRef1NSensitivity.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NVariable) this.$refs.PnlWdbePrcRef1NVariable.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMge1NSignal) this.$refs.PnlWdbePrcMge1NSignal.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefFsmFsm1NFsmstate) this.$refs.PnlWdbePrcFsmFsm1NFsmstate.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbePrcRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbePrcRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbePrcDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefKHdltype) this.$refs.PnlWdbePrcKHdltype.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NSensitivity) this.$refs.PnlWdbePrcRef1NSensitivity.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NVariable) this.$refs.PnlWdbePrcRef1NVariable.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMge1NSignal) this.$refs.PnlWdbePrcMge1NSignal.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefFsmFsm1NFsmstate) this.$refs.PnlWdbePrcFsmFsm1NFsmstate.handleUpdate(obj);
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
