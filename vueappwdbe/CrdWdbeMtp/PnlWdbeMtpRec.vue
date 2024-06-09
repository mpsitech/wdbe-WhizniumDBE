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
					<PnlWdbeMtpDetail
						v-on:request="handleRequest"
						ref="PnlWdbeMtpDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeMtpKParKey
						v-on:request="handleRequest"
						ref="PnlWdbeMtpKParKey"
						:scrJref=statshr.scrJrefKParKey
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpKHdltype
						v-on:request="handleRequest"
						ref="PnlWdbeMtpKHdltype"
						:scrJref=statshr.scrJrefKHdltype
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpAPar
						v-on:request="handleRequest"
						ref="PnlWdbeMtpAPar"
						:scrJref=statshr.scrJrefAPar
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeMtpMdl1NGeneric
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMtpMdl1NGeneric"
						:scrJref=statshr.scrJrefMdl1NGeneric
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpHsm1NPipeline
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMtpHsm1NPipeline"
						:scrJref=statshr.scrJrefHsm1NPipeline
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpMdl1NPort
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMtpMdl1NPort"
						:scrJref=statshr.scrJrefMdl1NPort
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpTpl1NModule
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMtpTpl1NModule"
						:scrJref=statshr.scrJrefTpl1NModule
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpSup1NModule
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMtpSup1NModule"
						:scrJref=statshr.scrJrefSup1NModule
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpRef1NSensitivity
						v-on:request="handleRequest"
						ref="PnlWdbeMtpRef1NSensitivity"
						:scrJref=statshr.scrJrefRef1NSensitivity
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpRef1NVariable
						v-on:request="handleRequest"
						ref="PnlWdbeMtpRef1NVariable"
						:scrJref=statshr.scrJrefRef1NVariable
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpMge1NSignal
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMtpMge1NSignal"
						:scrJref=statshr.scrJrefMge1NSignal
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMtpRef1NFile
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMtpRef1NFile"
						:scrJref=statshr.scrJrefRef1NFile
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
	import PnlWdbeMtpDetail from './PnlWdbeMtpDetail';
	import PnlWdbeMtpKParKey from './PnlWdbeMtpKParKey';
	import PnlWdbeMtpKHdltype from './PnlWdbeMtpKHdltype';
	import PnlWdbeMtpAPar from './PnlWdbeMtpAPar';
	import PnlWdbeMtpMdl1NGeneric from './PnlWdbeMtpMdl1NGeneric';
	import PnlWdbeMtpHsm1NPipeline from './PnlWdbeMtpHsm1NPipeline';
	import PnlWdbeMtpMdl1NPort from './PnlWdbeMtpMdl1NPort';
	import PnlWdbeMtpTpl1NModule from './PnlWdbeMtpTpl1NModule';
	import PnlWdbeMtpSup1NModule from './PnlWdbeMtpSup1NModule';
	import PnlWdbeMtpRef1NSensitivity from './PnlWdbeMtpRef1NSensitivity';
	import PnlWdbeMtpRef1NVariable from './PnlWdbeMtpRef1NVariable';
	import PnlWdbeMtpMge1NSignal from './PnlWdbeMtpMge1NSignal';
	import PnlWdbeMtpRef1NFile from './PnlWdbeMtpRef1NFile';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeMtpRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeMtpDetail,
			PnlWdbeMtpKParKey,
			PnlWdbeMtpKHdltype,
			PnlWdbeMtpAPar,
			PnlWdbeMtpMdl1NGeneric,
			PnlWdbeMtpHsm1NPipeline,
			PnlWdbeMtpMdl1NPort,
			PnlWdbeMtpTpl1NModule,
			PnlWdbeMtpSup1NModule,
			PnlWdbeMtpRef1NSensitivity,
			PnlWdbeMtpRef1NVariable,
			PnlWdbeMtpMge1NSignal,
			PnlWdbeMtpRef1NFile
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeMtpRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeMtpRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeMtpRec) this.continf = dpcheng.ContInfWdbeMtpRec;
				if (dpcheng.StatAppWdbeMtpRec) this.statapp = dpcheng.StatAppWdbeMtpRec;
				if (dpcheng.StatShrWdbeMtpRec) this.statshr = dpcheng.StatShrWdbeMtpRec;
				if (dpcheng.TagWdbeMtpRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeMtpRec);
					this.tag = dpcheng.TagWdbeMtpRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeMtpDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefKParKey) this.$refs.PnlWdbeMtpKParKey.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefKHdltype) this.$refs.PnlWdbeMtpKHdltype.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWdbeMtpAPar.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMdl1NGeneric) this.$refs.PnlWdbeMtpMdl1NGeneric.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHsm1NPipeline) this.$refs.PnlWdbeMtpHsm1NPipeline.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMdl1NPort) this.$refs.PnlWdbeMtpMdl1NPort.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefTpl1NModule) this.$refs.PnlWdbeMtpTpl1NModule.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NModule) this.$refs.PnlWdbeMtpSup1NModule.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NSensitivity) this.$refs.PnlWdbeMtpRef1NSensitivity.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NVariable) this.$refs.PnlWdbeMtpRef1NVariable.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMge1NSignal) this.$refs.PnlWdbeMtpMge1NSignal.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWdbeMtpRef1NFile.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeMtpRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeMtpRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeMtpDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefKParKey) this.$refs.PnlWdbeMtpKParKey.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefKHdltype) this.$refs.PnlWdbeMtpKHdltype.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWdbeMtpAPar.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMdl1NGeneric) this.$refs.PnlWdbeMtpMdl1NGeneric.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHsm1NPipeline) this.$refs.PnlWdbeMtpHsm1NPipeline.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMdl1NPort) this.$refs.PnlWdbeMtpMdl1NPort.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefTpl1NModule) this.$refs.PnlWdbeMtpTpl1NModule.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NModule) this.$refs.PnlWdbeMtpSup1NModule.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NSensitivity) this.$refs.PnlWdbeMtpRef1NSensitivity.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NVariable) this.$refs.PnlWdbeMtpRef1NVariable.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMge1NSignal) this.$refs.PnlWdbeMtpMge1NSignal.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWdbeMtpRef1NFile.handleUpdate(obj);
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
