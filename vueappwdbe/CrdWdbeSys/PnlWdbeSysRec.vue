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
					<PnlWdbeSysDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSysDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeSysSys1NTarget
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSysSys1NTarget"
						:scrJref=statshr.scrJrefSys1NTarget
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeSysHk1NVector
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeSysHk1NVector"
						:scrJref=statshr.scrJrefHk1NVector
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
	import PnlWdbeSysDetail from './PnlWdbeSysDetail';
	import PnlWdbeSysSys1NTarget from './PnlWdbeSysSys1NTarget';
	import PnlWdbeSysHk1NVector from './PnlWdbeSysHk1NVector';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeSysRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeSysDetail,
			PnlWdbeSysSys1NTarget,
			PnlWdbeSysHk1NVector
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeSysRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeSysRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeSysRec) this.continf = dpcheng.ContInfWdbeSysRec;
				if (dpcheng.StatAppWdbeSysRec) this.statapp = dpcheng.StatAppWdbeSysRec;
				if (dpcheng.StatShrWdbeSysRec) this.statshr = dpcheng.StatShrWdbeSysRec;
				if (dpcheng.TagWdbeSysRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeSysRec);
					this.tag = dpcheng.TagWdbeSysRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeSysDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSys1NTarget) this.$refs.PnlWdbeSysSys1NTarget.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWdbeSysHk1NVector.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeSysRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeSysRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeSysDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSys1NTarget) this.$refs.PnlWdbeSysSys1NTarget.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWdbeSysHk1NVector.handleUpdate(obj);
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
