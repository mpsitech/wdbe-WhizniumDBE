<template>
	<v-container v-if="initdone">
		<PnlWdbeMtpList
			v-on:request="handleRequest"
			ref="PnlWdbeMtpList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWdbeMtpRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWdbeMtpRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	*/
	import PnlWdbeMtpList from './PnlWdbeMtpList';
	import PnlWdbeMtpRec from './PnlWdbeMtpRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWdbeMtp',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWdbeMtpList,
			PnlWdbeMtpRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWdbeMtp.mounted() with scrJref = " + this.scrJref);

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
				if (dpcheng.ContInfWdbeMtp) this.continf = dpcheng.ContInfWdbeMtp;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWdbeMtp) this.statapp = dpcheng.StatAppWdbeMtp;
				if (dpcheng.StatShrWdbeMtp) this.statshr = dpcheng.StatShrWdbeMtp;
				if (dpcheng.TagWdbeMtp) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeMtp);
					this.tag = dpcheng.TagWdbeMtp;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWdbeMtpList.handleReply(obj);
					else this.$refs.PnlWdbeMtpRec.handleReply(obj);
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
					if (obj.srefIxWdbeVDpch == "DpchEngWdbeMtpData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWdbeMtpList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWdbeMtpRec.handleUpdate(obj);
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
