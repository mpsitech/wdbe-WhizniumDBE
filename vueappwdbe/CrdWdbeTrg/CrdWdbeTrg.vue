<template>
	<v-container v-if="initdone">
		<PnlWdbeTrgList
			v-on:request="handleRequest"
			ref="PnlWdbeTrgList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeTrgRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeTrgRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeTrgList from './PnlWdbeTrgList';
	import PnlWdbeTrgRec from './PnlWdbeTrgRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeTrg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeTrgList,
			PnlWdbeTrgRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeTrg.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeTrg) this.continf = dpcheng.ContInfWdbeTrg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeTrg) this.statapp = dpcheng.StatAppWdbeTrg;
				if (dpcheng.StatShrWdbeTrg) this.statshr = dpcheng.StatShrWdbeTrg;
				if (dpcheng.TagWdbeTrg) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeTrg);
					this.tag = dpcheng.TagWdbeTrg;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeTrgList.handleReply(obj);
					else this.$refs.PnlWdbeTrgRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeTrgData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeTrgList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeTrgRec.handleUpdate(obj);
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
