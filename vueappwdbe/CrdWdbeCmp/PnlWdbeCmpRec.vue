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
					<PnlWdbeCmpDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCmpDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeCmp1NRelease
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCmp1NRelease"
						:scrJref=statshr.scrJref1NRelease
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeCmpMNLibrary
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeCmpMNLibrary"
						:scrJref=statshr.scrJrefMNLibrary
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
	import PnlWdbeCmpDetail from './PnlWdbeCmpDetail';
	import PnlWdbeCmp1NRelease from './PnlWdbeCmp1NRelease';
	import PnlWdbeCmpMNLibrary from './PnlWdbeCmpMNLibrary';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeCmpRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeCmpDetail,
			PnlWdbeCmp1NRelease,
			PnlWdbeCmpMNLibrary
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeCmpRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeCmpRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeCmpRec) this.continf = dpcheng.ContInfWdbeCmpRec;
				if (dpcheng.StatAppWdbeCmpRec) this.statapp = dpcheng.StatAppWdbeCmpRec;
				if (dpcheng.StatShrWdbeCmpRec) this.statshr = dpcheng.StatShrWdbeCmpRec;
				if (dpcheng.TagWdbeCmpRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCmpRec);
					this.tag = dpcheng.TagWdbeCmpRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeCmpDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRelease) this.$refs.PnlWdbeCmp1NRelease.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNLibrary) this.$refs.PnlWdbeCmpMNLibrary.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeCmpRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeCmpRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeCmpDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRelease) this.$refs.PnlWdbeCmp1NRelease.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNLibrary) this.$refs.PnlWdbeCmpMNLibrary.handleUpdate(obj);
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
