<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end">
					&#160;
					<v-btn
						v-if="statapp.srefIxWdbeVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClipboardClick()"
						:value="1"
					>
						<v-icon color="white">mdi-clipboard</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statapp.srefIxWdbeVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButUpClick')"
						:value="1"
						:disabled="!statshr.ButUpActive"
					>
						<v-icon color="white">mdi-chevron-up-box</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWdbeVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDownClick')"
						:value="1"
						:disabled="!statshr.ButDownActive"
					>
						<v-icon color="white">mdi-chevron-down-box</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statapp.srefIxWdbeVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButNewClick')"
						:value="1"
					>
						<v-icon color="white">mdi-file-plus</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWdbeVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDuplicateClick')"
						:value="1"
						:disabled="!statshr.ButDuplicateActive"
					>
						<v-icon color="white">mdi-file-multiple</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWdbeVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDeleteClick')"
						:value="1"
						:disabled="!statshr.ButDeleteActive"
					>
						<v-icon color="white">mdi-file-remove</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statapp.srefIxWdbeVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxWdbeVExpstate='mind'"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statapp.srefIxWdbeVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="statapp.srefIxWdbeVExpstate='regd'"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statapp.srefIxWdbeVExpstate=='regd'"
		>
			<v-data-table
				:headers="headers"
				:items="contapp.rows"
				:items-per-page="10"
				item-key="jnum"
				single-select
				show-select
				class="elevation-1 my-3"
				v-on:item-selected="handleSelect"
			/>

			<v-row>
				<v-col align="end">
					<v-tooltip left>
						<template v-slot:activator="{on,attrs}">
							<v-btn
								fab
								small
								light
								v-bind="attrs"
								v-on="on"
								:color="fiFCsiQst.sref == 'ong' ? 'orange' : fiFCsiQst.sref == 'red' ? 'red' : fiFCsiQst.sref == 'yel' ? 'yellow' : fiFCsiQst.sref == 'grn' ? 'green' : 'primary'"
								v-on:click="handleButClick('ButRefreshClick')"
							>
								<v-icon color="white">mdi-refresh</v-icon>
							</v-btn>
						</template>
						{{fiFCsiQst.tit1}}
					</v-tooltip>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wdbe from '../../scripts/Wdbe';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWdbeFstAStep',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeFstAStep.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWdbeInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWdbeFstAStepDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButClipboardClick: function() {
				/*
				*/
				Wdbe.copyToClipboard(document, this.continf, this.rst, this.statshrqry, this.tag,
							["Fnx","Cn1","Ip1","Cn2","Ip2","Cn3","Ip3","Cn4","Ip4","Cn5","Ip5","Cn6","Ip6"],
							["fnx","cn1","ip1","cn2","ip2","cn3","ip3","cn4","ip4","cn5","ip5","cn6","ip6"]);
				/*
				*/
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppWdbeFstAStepData": {
						"scrJref": this.scrJref,
						"StgIacQryWdbeFstAStep": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeFstAStep"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeFstAStepData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeFstAStepData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContInfWdbeFstAStep) this.continf = dpcheng.ContInfWdbeFstAStep;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.StatAppWdbeFstAStep) this.statapp = dpcheng.StatAppWdbeFstAStep;
				if (dpcheng.StatShrWdbeFstAStep) this.statshr = dpcheng.StatShrWdbeFstAStep;
				if (dpcheng.StgIacWdbeFstAStep) this.stgiac = dpcheng.StgIacWdbeFstAStep;
				if (dpcheng.TagWdbeFstAStep) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeFstAStep);
					this.tag = dpcheng.TagWdbeFstAStep;
				}
				if (dpcheng.ListWdbeQFstAStep) this.rst = dpcheng.ListWdbeQFstAStep;
				if (dpcheng.StatAppQryWdbeFstAStep) this.statappqry = dpcheng.StatAppQryWdbeFstAStep;
				if (dpcheng.StatShrQryWdbeFstAStep) this.statshrqry = dpcheng.StatShrQryWdbeFstAStep;
				if (dpcheng.StgIacQryWdbeFstAStep) this.stgiacqry = dpcheng.StgIacQryWdbeFstAStep;
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagWdbeFstAStep) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoFnx", text: this.tag.TcoFnx}, {value: "TcoCn1", text: this.tag.TcoCn1}, {value: "TcoIp1", text: this.tag.TcoIp1}, {value: "TcoCn2", text: this.tag.TcoCn2}, {value: "TcoIp2", text: this.tag.TcoIp2}, {value: "TcoCn3", text: this.tag.TcoCn3}, {value: "TcoIp3", text: this.tag.TcoIp3}, {value: "TcoCn4", text: this.tag.TcoCn4}, {value: "TcoIp4", text: this.tag.TcoIp4}, {value: "TcoCn5", text: this.tag.TcoCn5}, {value: "TcoIp5", text: this.tag.TcoIp5}, {value: "TcoCn6", text: this.tag.TcoCn6}, {value: "TcoIp6", text: this.tag.TcoIp6});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWdbeQFstAStep) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoFnx: rec["fnx"], TcoCn1: rec["cn1"], TcoIp1: rec["ip1"], TcoCn2: rec["cn2"], TcoIp2: rec["ip2"], TcoCn3: rec["cn3"], TcoIp3: rec["ip3"], TcoCn4: rec["cn4"], TcoIp4: rec["ip4"], TcoCn5: rec["cn5"], TcoIp5: rec["ip5"], TcoCn6: rec["cn6"], TcoIp6: rec["ip6"]})
						/*
						*/

					}

					this.contapp.rows = rows;
				}
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWdbeVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWdbeVDpch, dpcheng) {
				if (srefIxWdbeVDpch == "DpchEngWdbeFstAStepData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeFstAStepData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			/*
			*/
			/*
			*/
			Cpt: function() {
				if (this.statapp.srefIxWdbeVExpstate == "mind") return(this.tag.Cpt + " (" + this.statshrqry.ntot + ")");
				return this.tag.Cpt;
			},
			/*
			*/

			headers: function() {
				return this.contapp.tcos.filter(x => x.value != "jnum")
			},

			fiFCsiQst: function() {
				if (this.feedFCsiQst && this.continf)
					for (var i = 0; i < this.feedFCsiQst.length; i++)
						if (this.feedFCsiQst[i].num == this.continf.numFCsiQst) return this.feedFCsiQst[i];

				return {sref: "gry", tit1: "invalid"}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFCsiQst: null,

			statapp: null,

			statshr: null,

			stgiac: null,

			tag: null,

			rst: null,

			statappqry: null,

			statshrqry: null,

			stgiacqry: null,

			contapp: {
				tcos: [],
				rows: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
