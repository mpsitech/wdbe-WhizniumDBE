<template>
	<v-app>
		<v-main>
			<!-- srefIxVSge prop for CrdWdbeStart, others for SessWdbe -->
			<component
				v-bind:is="content"
				v-on:login="handleLogin"
				v-on:logout="handleLogout"
				ref="content"
				:srefIxVSge_initial=srefIxVSge
				:scrJrefSess=scrJrefSess
				:scrJrefCrdnav=scrJrefCrdnav
				:srefCrd_initial=srefCrd
				:scrJrefCrd_initial=scrJrefCrd
			/>
		</v-main>
	</v-app>
</template>

<script>
	import Wdbe from './scripts/Wdbe';

	import CrdWdbeStart from './components/CrdWdbeStart/CrdWdbeStart';
	import SessWdbe from './components/SessWdbe';

	export default {
		name: 'AppWdbe',

		components: {
			CrdWdbeStart,
			SessWdbe
		},

		beforeMount() {
			document.title = Wdbe.title + " v" + Wdbe.version;

			// possible keys: scrJrefSess, scrJrefCrdnav, srefCrd, scrJrefCrd
			const params = new URLSearchParams(window.location.search);
			//params.forEach(function(value, key) {console.log(key + ": " + value)});

			this.childNotParent = params.has("scrJrefSess");

			if (!this.childNotParent) this.content = "CrdWdbeStart";
			else {
				this.scrJrefSess = params.get("scrJrefSess");
				this.scrJrefCrdnav = params.get("scrJrefCrdnav");

				this.srefCrd = params.get("srefCrd");
				this.scrJrefCrd = params.get("scrJrefCrd");

				this.content = "SessWdbe";
			}
		},

		methods: {
			handleLogin(obj) {
				//console.log("AppWdbe.handleLogin() received login event with scrJrefSess = " + scrJrefSess);

				this.scrJrefSess = obj.scrJrefSess;
				this.scrJrefCrdnav = obj.scrJrefCrdnav;

				this.srefCrd = "";
				this.scrJrefCrd = "";

				this.content = "SessWdbe"
			},

			handleLogout() {
				if (!this.childNotParent) {
					this.srefIxVSge = "term";

					this.scrJrefSess = "";
					this.scrJrefCrdnav = "";

					this.srefCrd = "";
					this.scrJrefCrd = "";

					this.content = "CrdWdbeStart"

				} else window.open("about:blank", "_self");
			}
		},

		data: () => ({
			childNotParent: false,	

			content: "",

			srefIxVSge: "idle",

			scrJrefSess: "",
			scrJrefCrdnav: "",

			srefCrd: "",
			scrJrefCrd: ""
		})
	};
</script>
