<template>
	<v-container v-if="initdone">
		<PnlWdbeCmdList
			v-on:request="handleRequest"
			ref="PnlWdbeCmdList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeCmdRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeCmdRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeCmdList from './PnlWdbeCmdList';
	import PnlWdbeCmdRec from './PnlWdbeCmdRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeCmd',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeCmdList,
			PnlWdbeCmdRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeCmd.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeCmd) this.continf = dpcheng.ContInfWdbeCmd;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeCmd) this.statapp = dpcheng.StatAppWdbeCmd;
				if (dpcheng.StatShrWdbeCmd) this.statshr = dpcheng.StatShrWdbeCmd;
				if (dpcheng.TagWdbeCmd) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCmd);
					this.tag = dpcheng.TagWdbeCmd;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeCmdList.handleReply(obj);
					else this.$refs.PnlWdbeCmdRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeCmdData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeCmdList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeCmdRec.handleUpdate(obj);
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
