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
					<PnlWdbeUsrDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUsrDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeUsrAAccess
						v-on:request="handleRequest"
						ref="PnlWdbeUsrAAccess"
						:scrJref=statshr.scrJrefAAccess
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWdbeUsr1NSession
						v-on:request="handleRequest"
						ref="PnlWdbeUsr1NSession"
						:scrJref=statshr.scrJref1NSession
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWdbeUsrMNUsergroup
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWdbeUsrMNUsergroup"
						:scrJref=statshr.scrJrefMNUsergroup
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
	import PnlWdbeUsrDetail from './PnlWdbeUsrDetail';
	import PnlWdbeUsrAAccess from './PnlWdbeUsrAAccess';
	import PnlWdbeUsr1NSession from './PnlWdbeUsr1NSession';
	import PnlWdbeUsrMNUsergroup from './PnlWdbeUsrMNUsergroup';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeUsrRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeUsrDetail,
			PnlWdbeUsrAAccess,
			PnlWdbeUsr1NSession,
			PnlWdbeUsrMNUsergroup
			/*
			*/
		},

		mounted() {
			//console.log("PnlWdbeUsrRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeUsrRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWdbeUsrRec) this.continf = dpcheng.ContInfWdbeUsrRec;
				if (dpcheng.StatAppWdbeUsrRec) this.statapp = dpcheng.StatAppWdbeUsrRec;
				if (dpcheng.StatShrWdbeUsrRec) this.statshr = dpcheng.StatShrWdbeUsrRec;
				if (dpcheng.TagWdbeUsrRec) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeUsrRec);
					this.tag = dpcheng.TagWdbeUsrRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeUsrDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWdbeUsrAAccess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlWdbeUsr1NSession.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlWdbeUsrMNUsergroup.handleReply(obj);
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
				if (srefIxWdbeVDpch == "DpchEngWdbeUsrRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeUsrRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWdbeVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWdbeUsrDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWdbeUsrAAccess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlWdbeUsr1NSession.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlWdbeUsrMNUsergroup.handleUpdate(obj);
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
