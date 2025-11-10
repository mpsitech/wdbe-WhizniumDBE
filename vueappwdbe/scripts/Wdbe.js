export default {
	title: "WhizniumDBE",

	version: "1.1.49",

	hostname: function() {
		if (process.env.NODE_ENV === "development") return "127.0.0.1"; // IP hostname --- LINE
		else return window.location.hostname
	},

	appsrvport: function() {
		if (process.env.NODE_ENV === "development") return "13100"; // IP appsrvport --- LINE
		else return window.location.port
	},

	unescapeString: function(str) {
		var str2 = str;
		var ss = str.split("\\u");

		if (ss.length > 0) {
			str2 = ss[0];

			for (var i = 1; i < ss.length; i++)
				if (ss[i].length >= 4)
					str2 = str2 + String.fromCharCode(256*parseInt(ss[i].substr(0,2), 16) + parseInt(ss[i].substr(2,2), 16)) + ss[i].substr(4);
		}

		return str2;
	},

	unescapeBlock: function(blk) {
		for (let bit in blk)
			if (typeof(blk[bit]) == "string")
				blk[bit] = this.unescapeString(blk[bit]);
	},

	strRecord: function(tpl, firstload, lastload, ntot, empty) {
		var retval;
	
		if (ntot == 0) {
			retval = empty;
		} else {
			retval = tpl;
			retval = retval.replace(/&firstload;/g, firstload);
			retval = retval.replace(/&lastload;/g, lastload);
			retval = retval.replace(/&ntot;/g, ntot);
		}
	
		return retval;
	},

	strShowing: function(tpl, firstdisp, lastdisp, ntot, empty) {
		var retval;
	
		if (ntot == 0) {
			retval = empty;
		} else {
			retval = tpl;
			retval = retval.replace(/&firstdisp;/g, firstdisp);
			retval = retval.replace(/&lastdisp;/g, lastdisp);
			retval = retval.replace(/&ntot;/g, ntot);
		}
	
		return retval;
	},
	
	strFor: function(tpl, pretit) {
		var retval;
	
		if (pretit == "") {
			retval = "";
		} else {
			retval = tpl;
			retval = retval.replace(/&pretit;/g, pretit);
		}
	
		return retval;
	},

	replaceUesc: function(str) {
		if (typeof(str) != "string") return str.toString();

		var str2 = str;
		var ss = str.split("\\u");
	
		if (ss.length > 0) {
			str2 = ss[0];
	
			for (var i = 1; i < ss.length; i++)
				if (ss[i].length >= 4)
					str2 = str2 + String.fromCharCode(256*parseInt(ss[i].substr(0,2), 16) + parseInt(ss[i].substr(2,2), 16)) + ss[i].substr(4);
		}
	
		return str2;
	},	

	copyToClipboard: function(doc, continf, rst, statshrqry, tag, tags, tcos) {
		// obtain record set characteristics
		var jnumFirstload = statshrqry.jnumFirstload;
		var nload = statshrqry.nload;
		var ntot = statshrqry.ntot;
	
		var mytxa;
	
		mytxa = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:textarea");
	
		// header
		mytxa.value = tag.Cpt;
		var TxtFor = continf.TxtFor;
		if (TxtFor ==! "") mytxa.value += " " + this.strFor(tag.TxtFor, TxtFor) + " " + continf.TxtPre;
		mytxa.value += "\n";
	
		mytxa.value += this.strRecord(tag.TxtRecord1, jnumFirstload, jnumFirstload + nload - 1, ntot, tag.TxtRecord2);
		
		if (ntot > 0) {
			mytxa.value += "\n\n";
	
			for (var i = 0; i < tags.length; i++) {
				if (tags[i] != "") mytxa.value += tag["Tco" + tags[i]];
				mytxa.value += "\t";
			}
			mytxa.value += "\n";
	
			// content
			for (i = 0; i < rst.length; i++) {
				var rec = rst[i];

				if ((rec["jnum"] >= jnumFirstload) && (rec["jnum"] < (jnumFirstload + nload))) {
					for (var j = 0; j < tcos.length; j++) mytxa.value += this.replaceUesc(rec[tcos[j]]) + "\t";
					mytxa.value += "\n";
				}
			}
		}
	
		doc.body.appendChild(mytxa);
		mytxa.select();
		doc.execCommand("copy");
		doc.body.removeChild(mytxa);
	}
}
