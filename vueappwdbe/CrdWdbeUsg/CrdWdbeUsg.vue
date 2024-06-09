<template>
	<v-container v-if="initdone">
		<PnlWdbeUsgList
			v-on:request="handleRequest"
			ref="PnlWdbeUsgList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeUsgRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeUsgRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeUsgList from './PnlWdbeUsgList';
	import PnlWdbeUsgRec from './PnlWdbeUsgRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeUsg',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeUsgList,
			PnlWdbeUsgRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeUsg.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeUsg) this.continf = dpcheng.ContInfWdbeUsg;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeUsg) this.statapp = dpcheng.StatAppWdbeUsg;
				if (dpcheng.StatShrWdbeUsg) this.statshr = dpcheng.StatShrWdbeUsg;
				if (dpcheng.TagWdbeUsg) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeUsg);
					this.tag = dpcheng.TagWdbeUsg;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeUsgList.handleReply(obj);
					else this.$refs.PnlWdbeUsgRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeUsgData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeUsgList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeUsgRec.handleUpdate(obj);
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
