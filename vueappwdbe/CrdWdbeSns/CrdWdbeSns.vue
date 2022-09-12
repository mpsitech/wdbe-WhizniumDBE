<template>
	<v-container v-if="initdone">
		<PnlWdbeSnsList
			v-on:request="handleRequest"
			ref="PnlWdbeSnsList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeSnsRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeSnsRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeSnsList from './PnlWdbeSnsList';
	import PnlWdbeSnsRec from './PnlWdbeSnsRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeSns',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeSnsList,
			PnlWdbeSnsRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeSns.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeSns) this.continf = dpcheng.ContInfWdbeSns;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeSns) this.statapp = dpcheng.StatAppWdbeSns;
				if (dpcheng.StatShrWdbeSns) this.statshr = dpcheng.StatShrWdbeSns;
				if (dpcheng.TagWdbeSns) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeSns);
					this.tag = dpcheng.TagWdbeSns;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeSnsList.handleReply(obj);
					else this.$refs.PnlWdbeSnsRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeSnsData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeSnsList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeSnsRec.handleUpdate(obj);
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
