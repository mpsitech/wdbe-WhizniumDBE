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
					<PnlWdbeCvrDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCvrDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeCvrAIp
						v-on:request="handleRequest"
						ref="PnlWdbeCvrAIp"
						:scrJref=statshr.scrJrefAIp
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeCvrAPlh
						v-on:request="handleRequest"
						ref="PnlWdbeCvrAPlh"
						:scrJref=statshr.scrJrefAPlh
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeCvrBcv1NCoreversion
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCvrBcv1NCoreversion"
						:scrJref=statshr.scrJrefBcv1NCoreversion
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeCvrHk1NModule
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCvrHk1NModule"
						:scrJref=statshr.scrJrefHk1NModule
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
	import PnlWdbeCvrDetail from './PnlWdbeCvrDetail';
	import PnlWdbeCvrAIp from './PnlWdbeCvrAIp';
	import PnlWdbeCvrAPlh from './PnlWdbeCvrAPlh';
	import PnlWdbeCvrBcv1NCoreversion from './PnlWdbeCvrBcv1NCoreversion';
	import PnlWdbeCvrHk1NModule from './PnlWdbeCvrHk1NModule';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeCvrRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeCvrDetail,
			PnlWdbeCvrAIp,
			PnlWdbeCvrAPlh,
			PnlWdbeCvrBcv1NCoreversion,
			PnlWdbeCvrHk1NModule
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeCvrRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeCvrRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeCvrRec) this.continf = dpcheng.ContInfWdbeCvrRec;
				if (dpcheng.StatAppWdbeCvrRec) this.statapp = dpcheng.StatAppWdbeCvrRec;
				if (dpcheng.StatShrWdbeCvrRec) this.statshr = dpcheng.StatShrWdbeCvrRec;
				if (dpcheng.TagWdbeCvrRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCvrRec);
					this.tag = dpcheng.TagWdbeCvrRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeCvrDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAIp) this.$refs.PnlWdbeCvrAIp.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAPlh) this.$refs.PnlWdbeCvrAPlh.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefBcv1NCoreversion) this.$refs.PnlWdbeCvrBcv1NCoreversion.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NModule) this.$refs.PnlWdbeCvrHk1NModule.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeCvrRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeCvrRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeCvrDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAIp) this.$refs.PnlWdbeCvrAIp.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAPlh) this.$refs.PnlWdbeCvrAPlh.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefBcv1NCoreversion) this.$refs.PnlWdbeCvrBcv1NCoreversion.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NModule) this.$refs.PnlWdbeCvrHk1NModule.handleUpdate(obj);
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
