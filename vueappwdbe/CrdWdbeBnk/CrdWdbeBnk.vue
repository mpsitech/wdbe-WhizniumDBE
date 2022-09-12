<template>
	<v-container v-if="initdone">
		<PnlWdbeBnkList
			v-on:request="handleRequest"
			ref="PnlWdbeBnkList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeBnkRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeBnkRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeBnkList from './PnlWdbeBnkList';
	import PnlWdbeBnkRec from './PnlWdbeBnkRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeBnk',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeBnkList,
			PnlWdbeBnkRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeBnk.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeBnk) this.continf = dpcheng.ContInfWdbeBnk;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeBnk) this.statapp = dpcheng.StatAppWdbeBnk;
				if (dpcheng.StatShrWdbeBnk) this.statshr = dpcheng.StatShrWdbeBnk;
				if (dpcheng.TagWdbeBnk) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeBnk);
					this.tag = dpcheng.TagWdbeBnk;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeBnkList.handleReply(obj);
					else this.$refs.PnlWdbeBnkRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeBnkData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeBnkList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeBnkRec.handleUpdate(obj);
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
