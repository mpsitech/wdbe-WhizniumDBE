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
					<PnlWdbeUsgDetail
						v-on:request="handleRequest"
						ref="PnlWdbeUsgDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeUsgAAccess
						v-on:request="handleRequest"
						ref="PnlWdbeUsgAAccess"
						:scrJref=statshr.scrJrefAAccess
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeUsgMNUser
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUsgMNUser"
						:scrJref=statshr.scrJrefMNUser
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
	import PnlWdbeUsgDetail from './PnlWdbeUsgDetail';
	import PnlWdbeUsgAAccess from './PnlWdbeUsgAAccess';
	import PnlWdbeUsgMNUser from './PnlWdbeUsgMNUser';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeUsgRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeUsgDetail,
			PnlWdbeUsgAAccess,
			PnlWdbeUsgMNUser
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeUsgRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeUsgRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeUsgRec) this.continf = dpcheng.ContInfWdbeUsgRec;
				if (dpcheng.StatAppWdbeUsgRec) this.statapp = dpcheng.StatAppWdbeUsgRec;
				if (dpcheng.StatShrWdbeUsgRec) this.statshr = dpcheng.StatShrWdbeUsgRec;
				if (dpcheng.TagWdbeUsgRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeUsgRec);
					this.tag = dpcheng.TagWdbeUsgRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeUsgDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWdbeUsgAAccess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNUser) this.$refs.PnlWdbeUsgMNUser.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeUsgRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeUsgRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeUsgDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWdbeUsgAAccess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNUser) this.$refs.PnlWdbeUsgMNUser.handleUpdate(obj);
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
