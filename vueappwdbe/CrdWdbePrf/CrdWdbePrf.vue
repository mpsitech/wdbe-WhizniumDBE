<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Preferences</h1>
		<PnlWdbePrfDaemon
			v-on:request="handleRequest"
			ref="PnlWdbePrfDaemon"
			:scrJref=statshr.scrJrefDaemon
		/>
		<PnlWdbePrfLicense
			v-on:request="handleRequest"
			ref="PnlWdbePrfLicense"
			:scrJref=statshr.scrJrefLicense
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbePrfDaemon from './PnlWdbePrfDaemon';
	import PnlWdbePrfLicense from './PnlWdbePrfLicense';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbePrf',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbePrfDaemon,
			PnlWdbePrfLicense
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbePrf.mounted() with scrJref = " + this.scrJref);

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

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfWdbePrf) this.continf = dpcheng.ContInfWdbePrf;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbePrf) this.statapp = dpcheng.StatAppWdbePrf;
				if (dpcheng.StatShrWdbePrf) this.statshr = dpcheng.StatShrWdbePrf;
				if (dpcheng.TagWdbePrf) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrf);
					this.tag = dpcheng.TagWdbePrf;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefDaemon) this.$refs.PnlWdbePrfDaemon.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefLicense) this.$refs.PnlWdbePrfLicense.handleReply(obj);
					else console.log("got a '" + obj.srefIxWdbeVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWdbeVDpch == "DpchEngWdbePrfData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefDaemon) {
						this.$refs.PnlWdbePrfDaemon.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefLicense) {
						this.$refs.PnlWdbePrfLicense.handleUpdate(obj);
						processed = true;
					}
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWdbeVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

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
