<template>
	<v-container v-if="initdone">
		<PnlWdbePrtList
			v-on:request="handleRequest"
			ref="PnlWdbePrtList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbePrtRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbePrtRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbePrtList from './PnlWdbePrtList';
	import PnlWdbePrtRec from './PnlWdbePrtRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbePrt',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbePrtList,
			PnlWdbePrtRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbePrt.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbePrt) this.continf = dpcheng.ContInfWdbePrt;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbePrt) this.statapp = dpcheng.StatAppWdbePrt;
				if (dpcheng.StatShrWdbePrt) this.statshr = dpcheng.StatShrWdbePrt;
				if (dpcheng.TagWdbePrt) {
					Wdbe.unescapeBlock(dpcheng.TagWdbePrt);
					this.tag = dpcheng.TagWdbePrt;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbePrtList.handleReply(obj);
					else this.$refs.PnlWdbePrtRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbePrtData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbePrtList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbePrtRec.handleUpdate(obj);
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
