<template>
	<v-container v-if="initdone">
		<PnlWdbeLibList
			v-on:request="handleRequest"
			ref="PnlWdbeLibList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeLibRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeLibRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeLibList from './PnlWdbeLibList';
	import PnlWdbeLibRec from './PnlWdbeLibRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeLib',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeLibList,
			PnlWdbeLibRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeLib.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeLib) this.continf = dpcheng.ContInfWdbeLib;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeLib) this.statapp = dpcheng.StatAppWdbeLib;
				if (dpcheng.StatShrWdbeLib) this.statshr = dpcheng.StatShrWdbeLib;
				if (dpcheng.TagWdbeLib) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeLib);
					this.tag = dpcheng.TagWdbeLib;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeLibList.handleReply(obj);
					else this.$refs.PnlWdbeLibRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeLibData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeLibList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeLibRec.handleUpdate(obj);
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
