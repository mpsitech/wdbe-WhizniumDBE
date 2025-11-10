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
					<PnlWdbeUntDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUntDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeUnt1NBank
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUnt1NBank"
						:scrJref=statshr.scrJref1NBank
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeUntSil1NUnit
						v-on:request="handleRequest"
						ref="PnlWdbeUntSil1NUnit"
						:scrJref=statshr.scrJrefSil1NUnit
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeUnt1NPeripheral
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUnt1NPeripheral"
						:scrJref=statshr.scrJref1NPeripheral
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeUnt1NInterrupt
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUnt1NInterrupt"
						:scrJref=statshr.scrJref1NInterrupt
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeUntRef1NCommand
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUntRef1NCommand"
						:scrJref=statshr.scrJrefRef1NCommand
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeUntHk1NModule
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUntHk1NModule"
						:scrJref=statshr.scrJrefHk1NModule
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeUntHk1NVector
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUntHk1NVector"
						:scrJref=statshr.scrJrefHk1NVector
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeUntRef1NError
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUntRef1NError"
						:scrJref=statshr.scrJrefRef1NError
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeUntRef1NSignal
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUntRef1NSignal"
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
	import PnlWdbeUntDetail from './PnlWdbeUntDetail';
	import PnlWdbeUnt1NBank from './PnlWdbeUnt1NBank';
	import PnlWdbeUntSil1NUnit from './PnlWdbeUntSil1NUnit';
	import PnlWdbeUnt1NPeripheral from './PnlWdbeUnt1NPeripheral';
	import PnlWdbeUnt1NInterrupt from './PnlWdbeUnt1NInterrupt';
	import PnlWdbeUntRef1NCommand from './PnlWdbeUntRef1NCommand';
	import PnlWdbeUntHk1NModule from './PnlWdbeUntHk1NModule';
	import PnlWdbeUntHk1NVector from './PnlWdbeUntHk1NVector';
	import PnlWdbeUntRef1NError from './PnlWdbeUntRef1NError';
	import PnlWdbeUntRef1NSignal from './PnlWdbeUntRef1NSignal';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeUntRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeUntDetail,
			PnlWdbeUnt1NBank,
			PnlWdbeUntSil1NUnit,
			PnlWdbeUnt1NPeripheral,
			PnlWdbeUnt1NInterrupt,
			PnlWdbeUntRef1NCommand,
			PnlWdbeUntHk1NModule,
			PnlWdbeUntHk1NVector,
			PnlWdbeUntRef1NError,
			PnlWdbeUntRef1NSignal
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeUntRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeUntRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeUntRec) this.continf = dpcheng.ContInfWdbeUntRec;
				if (dpcheng.StatAppWdbeUntRec) this.statapp = dpcheng.StatAppWdbeUntRec;
				if (dpcheng.StatShrWdbeUntRec) this.statshr = dpcheng.StatShrWdbeUntRec;
				if (dpcheng.TagWdbeUntRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeUntRec);
					this.tag = dpcheng.TagWdbeUntRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeUntDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NBank) this.$refs.PnlWdbeUnt1NBank.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSil1NUnit) this.$refs.PnlWdbeUntSil1NUnit.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NPeripheral) this.$refs.PnlWdbeUnt1NPeripheral.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NInterrupt) this.$refs.PnlWdbeUnt1NInterrupt.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NCommand) this.$refs.PnlWdbeUntRef1NCommand.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NModule) this.$refs.PnlWdbeUntHk1NModule.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWdbeUntHk1NVector.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NError) this.$refs.PnlWdbeUntRef1NError.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NSignal) this.$refs.PnlWdbeUntRef1NSignal.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeUntRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeUntRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeUntDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NBank) this.$refs.PnlWdbeUnt1NBank.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSil1NUnit) this.$refs.PnlWdbeUntSil1NUnit.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NPeripheral) this.$refs.PnlWdbeUnt1NPeripheral.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NInterrupt) this.$refs.PnlWdbeUnt1NInterrupt.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NCommand) this.$refs.PnlWdbeUntRef1NCommand.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NModule) this.$refs.PnlWdbeUntHk1NModule.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWdbeUntHk1NVector.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NError) this.$refs.PnlWdbeUntRef1NError.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NSignal) this.$refs.PnlWdbeUntRef1NSignal.handleUpdate(obj);
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
