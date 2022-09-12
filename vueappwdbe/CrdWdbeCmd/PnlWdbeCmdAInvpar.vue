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
		name: 'PnlWdbeCmdAInvpar',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWdbeCmdAInvpar.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWdbeCmdAInvparDo": {
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
							["Srf","Pty","","Vec","Len","Dfv","Vit","Cmt"],
							["srf","pty","pty2","vec","len","dfv","vit","cmt"]);
				/*
				*/
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppWdbeCmdAInvparData": {
						"scrJref": this.scrJref,
						"StgIacQryWdbeCmdAInvpar": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWdbeCmdAInvpar"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWdbeCmdAInvparData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWdbeCmdAInvparData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContInfWdbeCmdAInvpar) this.continf = dpcheng.ContInfWdbeCmdAInvpar;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.StatAppWdbeCmdAInvpar) this.statapp = dpcheng.StatAppWdbeCmdAInvpar;
				if (dpcheng.StatShrWdbeCmdAInvpar) this.statshr = dpcheng.StatShrWdbeCmdAInvpar;
				if (dpcheng.StgIacWdbeCmdAInvpar) this.stgiac = dpcheng.StgIacWdbeCmdAInvpar;
				if (dpcheng.TagWdbeCmdAInvpar) {
					Wdbe.unescapeBlock(dpcheng.TagWdbeCmdAInvpar);
					this.tag = dpcheng.TagWdbeCmdAInvpar;
				}
				if (dpcheng.ListWdbeQCmdAInvpar) this.rst = dpcheng.ListWdbeQCmdAInvpar;
				if (dpcheng.StatAppQryWdbeCmdAInvpar) this.statappqry = dpcheng.StatAppQryWdbeCmdAInvpar;
				if (dpcheng.StatShrQryWdbeCmdAInvpar) this.statshrqry = dpcheng.StatShrQryWdbeCmdAInvpar;
				if (dpcheng.StgIacQryWdbeCmdAInvpar) this.stgiacqry = dpcheng.StgIacQryWdbeCmdAInvpar;
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagWdbeCmdAInvpar) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoSrf", text: this.tag.TcoSrf}, {value: "TcoPty", text: this.tag.TcoPty}, {value: "TcoVec", text: this.tag.TcoVec}, {value: "TcoLen", text: this.tag.TcoLen}, {value: "TcoDfv", text: this.tag.TcoDfv}, {value: "TcoVit", text: this.tag.TcoVit}, {value: "TcoCmt", text: this.tag.TcoCmt});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWdbeQCmdAInvpar) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoSrf: rec["srf"], TcoPty: rec["pty"], TcoVec: rec["vec"], TcoLen: rec["len"], TcoDfv: rec["dfv"], TcoVit: rec["vit"], TcoCmt: rec["cmt"]})
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
				if (srefIxWdbeVDpch == "DpchEngWdbeCmdAInvparData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWdbeVDpch == "DpchEngWdbeCmdAInvparData") this.mergeDpchEngData(obj.dpcheng);
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
