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
					<PnlWdbeModDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeModKHdltype
						v-on:request="handleRequest"
						ref="PnlWdbeModKHdltype"
						:scrJref=statshr.scrJrefKHdltype
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModAPar
						v-on:request="handleRequest"
						ref="PnlWdbeModAPar"
						:scrJref=statshr.scrJrefAPar
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeModMdl1NGeneric
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModMdl1NGeneric"
						:scrJref=statshr.scrJrefMdl1NGeneric
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModMdl1NPort
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModMdl1NPort"
						:scrJref=statshr.scrJrefMdl1NPort
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMod1NProcess
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMod1NProcess"
						:scrJref=statshr.scrJref1NProcess
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModHsm1NPipeline
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModHsm1NPipeline"
						:scrJref=statshr.scrJrefHsm1NPipeline
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMod1NCdc
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMod1NCdc"
						:scrJref=statshr.scrJref1NCdc
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModSup1NModule
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModSup1NModule"
						:scrJref=statshr.scrJrefSup1NModule
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModMge1NSignal
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModMge1NSignal"
						:scrJref=statshr.scrJrefMge1NSignal
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModRef1NVariable
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModRef1NVariable"
						:scrJref=statshr.scrJrefRef1NVariable
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModRef1NSensitivity
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModRef1NSensitivity"
						:scrJref=statshr.scrJrefRef1NSensitivity
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModRef1NSignal
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModRef1NSignal"
						:scrJref=statshr.scrJrefRef1NSignal
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModCtrRef1NCommand
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModCtrRef1NCommand"
						:scrJref=statshr.scrJrefCtrRef1NCommand
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModCtrHk1NVector
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModCtrHk1NVector"
						:scrJref=statshr.scrJrefCtrHk1NVector
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModCtrRef1NError
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModCtrRef1NError"
						:scrJref=statshr.scrJrefCtrRef1NError
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModCtdMNModule
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModCtdMNModule"
						:scrJref=statshr.scrJrefCtdMNModule
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModMNPeripheral
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModMNPeripheral"
						:scrJref=statshr.scrJrefMNPeripheral
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModCorMNModule
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModCorMNModule"
						:scrJref=statshr.scrJrefCorMNModule
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeModCtrMNCommand
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeModCtrMNCommand"
						:scrJref=statshr.scrJrefCtrMNCommand
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
	import PnlWdbeModDetail from './PnlWdbeModDetail';
	import PnlWdbeModKHdltype from './PnlWdbeModKHdltype';
	import PnlWdbeModAPar from './PnlWdbeModAPar';
	import PnlWdbeModMdl1NGeneric from './PnlWdbeModMdl1NGeneric';
	import PnlWdbeModMdl1NPort from './PnlWdbeModMdl1NPort';
	import PnlWdbeMod1NProcess from './PnlWdbeMod1NProcess';
	import PnlWdbeModHsm1NPipeline from './PnlWdbeModHsm1NPipeline';
	import PnlWdbeMod1NCdc from './PnlWdbeMod1NCdc';
	import PnlWdbeModSup1NModule from './PnlWdbeModSup1NModule';
	import PnlWdbeModMge1NSignal from './PnlWdbeModMge1NSignal';
	import PnlWdbeModRef1NVariable from './PnlWdbeModRef1NVariable';
	import PnlWdbeModRef1NSensitivity from './PnlWdbeModRef1NSensitivity';
	import PnlWdbeModRef1NSignal from './PnlWdbeModRef1NSignal';
	import PnlWdbeModCtrRef1NCommand from './PnlWdbeModCtrRef1NCommand';
	import PnlWdbeModCtrHk1NVector from './PnlWdbeModCtrHk1NVector';
	import PnlWdbeModCtrRef1NError from './PnlWdbeModCtrRef1NError';
	import PnlWdbeModCtdMNModule from './PnlWdbeModCtdMNModule';
	import PnlWdbeModMNPeripheral from './PnlWdbeModMNPeripheral';
	import PnlWdbeModCorMNModule from './PnlWdbeModCorMNModule';
	import PnlWdbeModCtrMNCommand from './PnlWdbeModCtrMNCommand';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeModRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeModDetail,
			PnlWdbeModKHdltype,
			PnlWdbeModAPar,
			PnlWdbeModMdl1NGeneric,
			PnlWdbeModMdl1NPort,
			PnlWdbeMod1NProcess,
			PnlWdbeModHsm1NPipeline,
			PnlWdbeMod1NCdc,
			PnlWdbeModSup1NModule,
			PnlWdbeModMge1NSignal,
			PnlWdbeModRef1NVariable,
			PnlWdbeModRef1NSensitivity,
			PnlWdbeModRef1NSignal,
			PnlWdbeModCtrRef1NCommand,
			PnlWdbeModCtrHk1NVector,
			PnlWdbeModCtrRef1NError,
			PnlWdbeModCtdMNModule,
			PnlWdbeModMNPeripheral,
			PnlWdbeModCorMNModule,
			PnlWdbeModCtrMNCommand
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeModRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeModRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeModRec) this.continf = dpcheng.ContInfWdbeModRec;
				if (dpcheng.StatAppWdbeModRec) this.statapp = dpcheng.StatAppWdbeModRec;
				if (dpcheng.StatShrWdbeModRec) this.statshr = dpcheng.StatShrWdbeModRec;
				if (dpcheng.TagWdbeModRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeModRec);
					this.tag = dpcheng.TagWdbeModRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeModDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefKHdltype) this.$refs.PnlWdbeModKHdltype.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWdbeModAPar.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMdl1NGeneric) this.$refs.PnlWdbeModMdl1NGeneric.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMdl1NPort) this.$refs.PnlWdbeModMdl1NPort.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NProcess) this.$refs.PnlWdbeMod1NProcess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHsm1NPipeline) this.$refs.PnlWdbeModHsm1NPipeline.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NCdc) this.$refs.PnlWdbeMod1NCdc.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NModule) this.$refs.PnlWdbeModSup1NModule.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMge1NSignal) this.$refs.PnlWdbeModMge1NSignal.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NVariable) this.$refs.PnlWdbeModRef1NVariable.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NSensitivity) this.$refs.PnlWdbeModRef1NSensitivity.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NSignal) this.$refs.PnlWdbeModRef1NSignal.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefCtrRef1NCommand) this.$refs.PnlWdbeModCtrRef1NCommand.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefCtrHk1NVector) this.$refs.PnlWdbeModCtrHk1NVector.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefCtrRef1NError) this.$refs.PnlWdbeModCtrRef1NError.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefCtdMNModule) this.$refs.PnlWdbeModCtdMNModule.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNPeripheral) this.$refs.PnlWdbeModMNPeripheral.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefCorMNModule) this.$refs.PnlWdbeModCorMNModule.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefCtrMNCommand) this.$refs.PnlWdbeModCtrMNCommand.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeModRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeModRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeModDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefKHdltype) this.$refs.PnlWdbeModKHdltype.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWdbeModAPar.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMdl1NGeneric) this.$refs.PnlWdbeModMdl1NGeneric.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMdl1NPort) this.$refs.PnlWdbeModMdl1NPort.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NProcess) this.$refs.PnlWdbeMod1NProcess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHsm1NPipeline) this.$refs.PnlWdbeModHsm1NPipeline.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NCdc) this.$refs.PnlWdbeMod1NCdc.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NModule) this.$refs.PnlWdbeModSup1NModule.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMge1NSignal) this.$refs.PnlWdbeModMge1NSignal.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NVariable) this.$refs.PnlWdbeModRef1NVariable.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NSensitivity) this.$refs.PnlWdbeModRef1NSensitivity.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NSignal) this.$refs.PnlWdbeModRef1NSignal.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefCtrRef1NCommand) this.$refs.PnlWdbeModCtrRef1NCommand.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefCtrHk1NVector) this.$refs.PnlWdbeModCtrHk1NVector.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefCtrRef1NError) this.$refs.PnlWdbeModCtrRef1NError.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefCtdMNModule) this.$refs.PnlWdbeModCtdMNModule.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNPeripheral) this.$refs.PnlWdbeModMNPeripheral.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefCorMNModule) this.$refs.PnlWdbeModCorMNModule.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefCtrMNCommand) this.$refs.PnlWdbeModCtrMNCommand.handleUpdate(obj);
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
