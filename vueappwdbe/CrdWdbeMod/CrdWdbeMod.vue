<template>
	<v-container v-if="initdone">
		<PnlWdbeModList
			v-on:request="handleRequest"
			ref="PnlWdbeModList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeModRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeModRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeModList from './PnlWdbeModList';
	import PnlWdbeModRec from './PnlWdbeModRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeMod',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeModList,
			PnlWdbeModRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeMod.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeMod) this.continf = dpcheng.ContInfWdbeMod;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeMod) this.statapp = dpcheng.StatAppWdbeMod;
				if (dpcheng.StatShrWdbeMod) this.statshr = dpcheng.StatShrWdbeMod;
				if (dpcheng.TagWdbeMod) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeMod);
					this.tag = dpcheng.TagWdbeMod;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeModList.handleReply(obj);
					else this.$refs.PnlWdbeModRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeModData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeModList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeModRec.handleUpdate(obj);
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
