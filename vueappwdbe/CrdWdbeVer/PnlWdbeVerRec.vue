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
					<PnlWdbeVerDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeVerDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeVerBvr1NVersion
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeVerBvr1NVersion"
						:scrJref=statshr.scrJrefBvr1NVersion
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeVer1NComponent
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeVer1NComponent"
						:scrJref=statshr.scrJref1NComponent
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeVer1NUnit
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeVer1NUnit"
						:scrJref=statshr.scrJref1NUnit
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeVerRef1NFile
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeVerRef1NFile"
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
	import PnlWdbeVerDetail from './PnlWdbeVerDetail';
	import PnlWdbeVerBvr1NVersion from './PnlWdbeVerBvr1NVersion';
	import PnlWdbeVer1NComponent from './PnlWdbeVer1NComponent';
	import PnlWdbeVer1NUnit from './PnlWdbeVer1NUnit';
	import PnlWdbeVerRef1NFile from './PnlWdbeVerRef1NFile';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeVerRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeVerDetail,
			PnlWdbeVerBvr1NVersion,
			PnlWdbeVer1NComponent,
			PnlWdbeVer1NUnit,
			PnlWdbeVerRef1NFile
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeVerRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeVerRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeVerRec) this.continf = dpcheng.ContInfWdbeVerRec;
				if (dpcheng.StatAppWdbeVerRec) this.statapp = dpcheng.StatAppWdbeVerRec;
				if (dpcheng.StatShrWdbeVerRec) this.statshr = dpcheng.StatShrWdbeVerRec;
				if (dpcheng.TagWdbeVerRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeVerRec);
					this.tag = dpcheng.TagWdbeVerRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeVerDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefBvr1NVersion) this.$refs.PnlWdbeVerBvr1NVersion.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NComponent) this.$refs.PnlWdbeVer1NComponent.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NUnit) this.$refs.PnlWdbeVer1NUnit.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWdbeVerRef1NFile.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeVerRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeVerRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeVerDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefBvr1NVersion) this.$refs.PnlWdbeVerBvr1NVersion.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NComponent) this.$refs.PnlWdbeVer1NComponent.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NUnit) this.$refs.PnlWdbeVer1NUnit.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWdbeVerRef1NFile.handleUpdate(obj);
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
