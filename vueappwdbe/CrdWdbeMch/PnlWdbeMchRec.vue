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
					<PnlWdbeMchDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMchDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeMchAPar
						v-on:request="handleRequest"
						ref="PnlWdbeMchAPar"
						:scrJref=statshr.scrJrefAPar
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMchAMakefile
						v-on:request="handleRequest"
						ref="PnlWdbeMchAMakefile"
						:scrJref=statshr.scrJrefAMakefile
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeMch1NRelease
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMch1NRelease"
						:scrJref=statshr.scrJref1NRelease
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeMchSup1NMachine
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeMchSup1NMachine"
						:scrJref=statshr.scrJrefSup1NMachine
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
	import PnlWdbeMchDetail from './PnlWdbeMchDetail';
	import PnlWdbeMchAPar from './PnlWdbeMchAPar';
	import PnlWdbeMchAMakefile from './PnlWdbeMchAMakefile';
	import PnlWdbeMch1NRelease from './PnlWdbeMch1NRelease';
	import PnlWdbeMchSup1NMachine from './PnlWdbeMchSup1NMachine';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeMchRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeMchDetail,
			PnlWdbeMchAPar,
			PnlWdbeMchAMakefile,
			PnlWdbeMch1NRelease,
			PnlWdbeMchSup1NMachine
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeMchRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeMchRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeMchRec) this.continf = dpcheng.ContInfWdbeMchRec;
				if (dpcheng.StatAppWdbeMchRec) this.statapp = dpcheng.StatAppWdbeMchRec;
				if (dpcheng.StatShrWdbeMchRec) this.statshr = dpcheng.StatShrWdbeMchRec;
				if (dpcheng.TagWdbeMchRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeMchRec);
					this.tag = dpcheng.TagWdbeMchRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeMchDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWdbeMchAPar.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAMakefile) this.$refs.PnlWdbeMchAMakefile.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRelease) this.$refs.PnlWdbeMch1NRelease.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NMachine) this.$refs.PnlWdbeMchSup1NMachine.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeMchRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeMchRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeMchDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWdbeMchAPar.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAMakefile) this.$refs.PnlWdbeMchAMakefile.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRelease) this.$refs.PnlWdbeMch1NRelease.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NMachine) this.$refs.PnlWdbeMchSup1NMachine.handleUpdate(obj);
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
