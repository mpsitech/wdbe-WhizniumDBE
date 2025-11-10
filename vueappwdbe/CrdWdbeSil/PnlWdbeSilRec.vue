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
					<PnlWdbeSilDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSilDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeSil1NBank
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSil1NBank"
						:scrJref=statshr.scrJref1NBank
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeSilSil1NUnit
						v-on:request="handleRequest"
						ref="PnlWdbeSilSil1NUnit"
						:scrJref=statshr.scrJrefSil1NUnit
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeSil1NPeripheral
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSil1NPeripheral"
						:scrJref=statshr.scrJref1NPeripheral
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeSil1NInterrupt
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSil1NInterrupt"
						:scrJref=statshr.scrJref1NInterrupt
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeSilRef1NCommand
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSilRef1NCommand"
						:scrJref=statshr.scrJrefRef1NCommand
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeSilHk1NModule
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSilHk1NModule"
						:scrJref=statshr.scrJrefHk1NModule
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeSilHk1NVector
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSilHk1NVector"
						:scrJref=statshr.scrJrefHk1NVector
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeSilRef1NError
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSilRef1NError"
						:scrJref=statshr.scrJrefRef1NError
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeSilRef1NSignal
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSilRef1NSignal"
						:scrJref=statshr.scrJrefRef1NSignal
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
	import PnlWdbeSilDetail from './PnlWdbeSilDetail';
	import PnlWdbeSil1NBank from './PnlWdbeSil1NBank';
	import PnlWdbeSilSil1NUnit from './PnlWdbeSilSil1NUnit';
	import PnlWdbeSil1NPeripheral from './PnlWdbeSil1NPeripheral';
	import PnlWdbeSil1NInterrupt from './PnlWdbeSil1NInterrupt';
	import PnlWdbeSilRef1NCommand from './PnlWdbeSilRef1NCommand';
	import PnlWdbeSilHk1NModule from './PnlWdbeSilHk1NModule';
	import PnlWdbeSilHk1NVector from './PnlWdbeSilHk1NVector';
	import PnlWdbeSilRef1NError from './PnlWdbeSilRef1NError';
	import PnlWdbeSilRef1NSignal from './PnlWdbeSilRef1NSignal';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeSilRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeSilDetail,
			PnlWdbeSil1NBank,
			PnlWdbeSilSil1NUnit,
			PnlWdbeSil1NPeripheral,
			PnlWdbeSil1NInterrupt,
			PnlWdbeSilRef1NCommand,
			PnlWdbeSilHk1NModule,
			PnlWdbeSilHk1NVector,
			PnlWdbeSilRef1NError,
			PnlWdbeSilRef1NSignal
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeSilRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeSilRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeSilRec) this.continf = dpcheng.ContInfWdbeSilRec;
				if (dpcheng.StatAppWdbeSilRec) this.statapp = dpcheng.StatAppWdbeSilRec;
				if (dpcheng.StatShrWdbeSilRec) this.statshr = dpcheng.StatShrWdbeSilRec;
				if (dpcheng.TagWdbeSilRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeSilRec);
					this.tag = dpcheng.TagWdbeSilRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeSilDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NBank) this.$refs.PnlWdbeSil1NBank.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSil1NUnit) this.$refs.PnlWdbeSilSil1NUnit.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NPeripheral) this.$refs.PnlWdbeSil1NPeripheral.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NInterrupt) this.$refs.PnlWdbeSil1NInterrupt.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NCommand) this.$refs.PnlWdbeSilRef1NCommand.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NModule) this.$refs.PnlWdbeSilHk1NModule.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWdbeSilHk1NVector.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NError) this.$refs.PnlWdbeSilRef1NError.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NSignal) this.$refs.PnlWdbeSilRef1NSignal.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeSilRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeSilRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeSilDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NBank) this.$refs.PnlWdbeSil1NBank.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSil1NUnit) this.$refs.PnlWdbeSilSil1NUnit.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NPeripheral) this.$refs.PnlWdbeSil1NPeripheral.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NInterrupt) this.$refs.PnlWdbeSil1NInterrupt.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NCommand) this.$refs.PnlWdbeSilRef1NCommand.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NModule) this.$refs.PnlWdbeSilHk1NModule.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWdbeSilHk1NVector.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NError) this.$refs.PnlWdbeSilRef1NError.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NSignal) this.$refs.PnlWdbeSilRef1NSignal.handleUpdate(obj);
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
