// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeFstAStep", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeFstAStep", "srefIxWdbeVExpstate", "mind");

	getRecwnd().changeHeight("AStep", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("AStep_side").setAttribute("height", "30");
	doc.getElementById("AStep_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("AStep_side").src = "./PnlWdbeFstAStep_aside.html";
	doc.getElementById("AStep_cont").src = "./PnlWdbeFstAStep_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeFstAStep", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeFstAStep", "srefIxWdbeVExpstate", "regd");

	getRecwnd().changeHeight("AStep", 255, true);
	doc.getElementById("tdSide").setAttribute("height", "255");
	doc.getElementById("AStep_side").setAttribute("height", "255");
	doc.getElementById("AStep_cont").setAttribute("height", "255");

	// change content
	doc.getElementById("AStep_side").src = "./PnlWdbeFstAStep_bside.html";
	doc.getElementById("AStep_cont").src = "./PnlWdbeFstAStep_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("AStep_side").contentDocument;
	contdoc = doc.getElementById("AStep_cont").contentDocument;
	hdrdoc = null;
	tbldoc = null;
	ftrdoc = null;

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("AStep_side").contentDocument;
	contdoc = doc.getElementById("AStep_cont").contentDocument;
	hdrdoc = contdoc.getElementById("AStep_hdr").contentDocument;
	tbldoc = contdoc.getElementById("AStep_tbl").contentDocument;
	ftrdoc = contdoc.getElementById("AStep_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeFstAStep", "Cpt"));

	// column headers in refreshBD() only

	setTextContent(ftrdoc, ftrdoc.getElementById("TrsGoto"), retrieveTi(srcdoc, "TagWdbeFstAStep", "Trs"));

	refreshBD(bNotD, true);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeFstAStep", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") initA();
	else if (srefIxWdbeVExpstate == "regd") initBD(true);
	else if (srefIxWdbeVExpstate == "detd") initBD(false);
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeFstAStep", "Cpt") + " (" + retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "ntot") + ")");
};

function refreshBD(bNotD, chgcol) {
	// obtain record set characteristics
	var jnumSel = parseInt(retrieveSi(srcdoc, "StgIacQryWdbeFstAStep", "jnum"));
	var jnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "jnumFirstdisp"));
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "ndisp"));
	var jnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "jnumFirstload"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "ntot"));

	var mytbl, mytr, mytd, myimg, mycg, mycol;

	var txt;
	var jnum, selclass;

	var rownode;

	var height;

	// update column characteristics
	if (chgcol) {
		// obtain column (header) characteristics
		var firstcol = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "firstcol"));
		var ncol = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "ncol"));

		var TcoFnxWidth = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoFnxWidth"));
		var TcoCn1Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoCn1Width"));
		var TcoIp1Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoIp1Width"));
		var TcoCn2Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoCn2Width"));
		var TcoIp2Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoIp2Width"));
		var TcoCn3Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoCn3Width"));
		var TcoIp3Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoIp3Width"));
		var TcoCn4Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoCn4Width"));
		var TcoIp4Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoIp4Width"));
		var TcoCn5Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoCn5Width"));
		var TcoIp5Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoIp5Width"));
		var TcoCn6Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoCn6Width"));
		var TcoIp6Width = parseInt(retrieveSi(srcdoc, "StgIacWdbeFstAStep", "TcoIp6Width"));

		// col data is stored in document variables
		doc.cols = new Array();
		doc.widths = new Array();
		doc.fs = new Array();

		var i, ix;
		var wtot = 0;
		var wmax = 425;

		for (i = firstcol, ix = 0; i <= ncol; i++) {
			ix++;

			if (i == 1) {
				doc.cols.push("TcoFnx"); doc.widths.push(TcoFnxWidth); doc.fs.push("fnx"); wtot += TcoFnxWidth;
			} else if (i == 2) {
				doc.cols.push("TcoCn1"); doc.widths.push(TcoCn1Width); doc.fs.push("cn1"); wtot += TcoCn1Width;
			} else if (i == 3) {
				doc.cols.push("TcoIp1"); doc.widths.push(TcoIp1Width); doc.fs.push("ip1"); wtot += TcoIp1Width;
			} else if (i == 4) {
				doc.cols.push("TcoCn2"); doc.widths.push(TcoCn2Width); doc.fs.push("cn2"); wtot += TcoCn2Width;
			} else if (i == 5) {
				doc.cols.push("TcoIp2"); doc.widths.push(TcoIp2Width); doc.fs.push("ip2"); wtot += TcoIp2Width;
			} else if (i == 6) {
				doc.cols.push("TcoCn3"); doc.widths.push(TcoCn3Width); doc.fs.push("cn3"); wtot += TcoCn3Width;
			} else if (i == 7) {
				doc.cols.push("TcoIp3"); doc.widths.push(TcoIp3Width); doc.fs.push("ip3"); wtot += TcoIp3Width;
			} else if (i == 8) {
				doc.cols.push("TcoCn4"); doc.widths.push(TcoCn4Width); doc.fs.push("cn4"); wtot += TcoCn4Width;
			} else if (i == 9) {
				doc.cols.push("TcoIp4"); doc.widths.push(TcoIp4Width); doc.fs.push("ip4"); wtot += TcoIp4Width;
			} else if (i == 10) {
				doc.cols.push("TcoCn5"); doc.widths.push(TcoCn5Width); doc.fs.push("cn5"); wtot += TcoCn5Width;
			} else if (i == 11) {
				doc.cols.push("TcoIp5"); doc.widths.push(TcoIp5Width); doc.fs.push("ip5"); wtot += TcoIp5Width;
			} else if (i == 12) {
				doc.cols.push("TcoCn6"); doc.widths.push(TcoCn6Width); doc.fs.push("cn6"); wtot += TcoCn6Width;
			} else if (i == 13) {
				doc.cols.push("TcoIp6"); doc.widths.push(TcoIp6Width); doc.fs.push("ip6"); wtot += TcoIp6Width;
			} else {
				ix--;
			};

			if (wtot > wmax) break;
		};

		if (wtot > wmax) {
			wtot -= doc.widths[ix-1];
			doc.cols.pop(); doc.widths.pop(); doc.fs.pop();
			i--; ix--;
		};

		doc.widths[ix-1] = doc.widths[ix-1] + (wmax-wtot);

		// column left and right button availability
		doc.cl = false;
		doc.cr = false;

		doc.cl = (firstcol > 1);
		doc.cr = (ncol > i);

		// update colgroup
		mycg = tbldoc.getElementById("cols");
		var del = mycg.childNodes[1];
		while (del) {
			mycg.removeChild(del);
			del = mycg.childNodes[1];
		};

		mycol = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:col");
		mycol.setAttribute("width", "20");
		mycg.appendChild(mycol);

		for (var j = 0; j < doc.widths.length; j++) {
			mycol = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:col");
			mycol.setAttribute("width", "" + doc.widths[j]);
			mycg.appendChild(mycol);
		};

		mycol = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:col");
		mycol.setAttribute("width", "15");
		mycg.appendChild(mycol);

		// update header row
		mytr = tbldoc.getElementById("hdr");
		clearElem(mytr);

		mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
		mytd.setAttribute("id", "rhcl");
		mytd.setAttribute("height", "20");
		mytd.setAttribute("class", "col");
		mytd.setAttribute("style", "vertical-align:bottom");

		if (doc.cl) {
			myimg = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:img");
			myimg.setAttribute("id", "TblCprevious");
			myimg.setAttribute("class", "but");
			myimg.setAttribute("width", "12");
			myimg.setAttribute("height", "12");
			myimg.setAttribute("alt", "cprevious");
			myimg.setAttribute("src", "../icon/cprevious.png");
			myimg.setAttribute("onmouseover", "src='../icon/cprevious_hlt.png'");
			myimg.setAttribute("onmouseout", "src='../icon/cprevious.png'");
			myimg.setAttribute("onclick", "handleTblCpreviousClick()")
			mytd.appendChild(myimg);
		};

		mytr.appendChild(mytd);

		for (var j = 0; j < doc.cols.length; j++) {
			mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytd.setAttribute("id", doc.cols[j]);
			mytd.setAttribute("class", "col");
			setTextContent(tbldoc, mytd, retrieveTi(srcdoc, "TagWdbeFstAStep", doc.cols[j]));

			mytr.appendChild(mytd);
		};

		mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
		mytd.setAttribute("id", "tdTsb");
		mytr.appendChild(mytd);
	};

	mytr = tbldoc.getElementById("hdr");

	// reset jnumFirstdisp if required
	if ((jnumFirstdisp < jnumFirstload) || (jnumFirstdisp > (jnumFirstload+nload-1))) {
		jnumFirstdisp = jnumFirstload;
		setSi(srcdoc, "StatAppQryWdbeFstAStep", "jnumFirstdisp", jnumFirstdisp);
	};

	// scroll bar
	mytr.removeChild(tbldoc.getElementById("tdTsb"));
	mytr.appendChild(makeTdTsb(tbldoc, (ntot > ndisp), doc.cr, ndisp, (jnumFirstdisp - 1) / (ntot - ndisp), true));

	// clear data rows
	mytbl = tbldoc.getElementById("tbl");
	
	for (var i = 1; true; i++) {
		mytr = tbldoc.getElementById("r" + i);

		if (mytr) {
			mytbl.removeChild(mytr);
		} else {
			break;
		};
	};

	// fill data rows
	for (var i = 1; i <= ndisp; i++) {
		mytr = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:tr");
		mytr.setAttribute("id", "r" + i);

		jnum = jnumFirstdisp+i-1;

		// find element in ListWdbeQFstAStep
		rownode = getRownode(srcdoc, "ListWdbeQFstAStep", jnum);

		if (rownode) {
			// regular data row
			if (jnum == jnumSel) {
				selclass = "sel";
			} else {
				if ((jnum%2) == 0) selclass = "nonsel";
				else selclass = "nonselalt";
			};

			if (jnum == jnumSel) mytr.setAttribute("onclick", "handleTblSelect(0)");
			else mytr.setAttribute("onclick", "handleTblSelect(" + jnum + ")");

			// selector
			mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytd.setAttribute("id", "r" + i + "cs");
			mytd.setAttribute("height", "18");
			mytd.setAttribute("class", selclass);

			myimg = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:img");
			myimg.setAttribute("id", "r" + i + "s");
			myimg.setAttribute("width", "10");
			myimg.setAttribute("height", "10");
			myimg.setAttribute("alt", "sel");
			if (jnum == jnumSel) {
				myimg.setAttribute("src", "../icon/sel_hlt.png");
			} else {
				myimg.setAttribute("src", "../icon/sel.png");
				myimg.setAttribute("onmouseover", "src='../icon/sel_hlt.png'");
				myimg.setAttribute("onmouseout", "src='../icon/sel.png'");
			};

			mytd.appendChild(myimg);
			mytr.appendChild(mytd);

			// data cells
			for (var j = 0; j < doc.fs.length; j++) {
				mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
				mytd.setAttribute("id", "r" + i + "c" + (j+1));
				mytd.setAttribute("class", selclass);

				txt = replaceUesc(retrieveRowField(srcdoc, rownode, doc.fs[j]));

				if ((jnum == jnumSel) && (txt.length > Math.ceil(doc.widths[j]*0.125))) {
					txt = txt.substring(0, Math.ceil(doc.widths[j]*0.125) -3) + "...";
				} else if ((jnum != jnumSel) && (txt.length > Math.ceil(doc.widths[j]*0.15))) {
					txt = txt.substring(0, Math.ceil(doc.widths[j]*0.15) -3) + "...";
				};

				mytd.appendChild(tbldoc.createTextNode(txt));
				mytr.appendChild(mytd);
			};

		} else {
			// empty row
			mytd = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytd.setAttribute("id", "r" + i + "cs");
			mytd.setAttribute("height", "18");
			mytd.setAttribute("colspan", "" + (doc.widths.length + 2));
			mytr.appendChild(mytd);
		};

		mytbl.appendChild(mytr);
	};

	// footer row
	var jnumLastdisp = jnumFirstdisp + ndisp - 1;
	if (jnumLastdisp > ntot) jnumLastdisp = ntot;

	setTextContent(ftrdoc, ftrdoc.getElementById("TxtShowing"), strShowing(retrieveTi(srcdoc, "TagWdbeFstAStep", "TxtShowing1"), jnumFirstdisp, jnumLastdisp, ntot, retrieveTi(srcdoc, "TagWdbeFstAStep", "TxtShowing2")));

	if (ntot == 0) {
		ftrdoc.getElementById("TrsGoto").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsGoto").setAttribute("onclick", "");
	} else {
		ftrdoc.getElementById("TrsGoto").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsGoto").setAttribute("onclick", "handleTrsGotoClick()");
	};

	if ((ntot <= 1) || (jnumSel == 1)) {
		ftrdoc.getElementById("TrsFirst").src = "../icon/first_inact.png";
		ftrdoc.getElementById("TrsFirst").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseover", "");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseout", "");
		ftrdoc.getElementById("TrsFirst").setAttribute("onclick", "");

		ftrdoc.getElementById("TrsPrevious").src = "../icon/previous_inact.png";
		ftrdoc.getElementById("TrsPrevious").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseover", "");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseout", "");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onclick", "");
	} else {
		ftrdoc.getElementById("TrsFirst").src = "../icon/first.png";
		ftrdoc.getElementById("TrsFirst").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseover", "src='../icon/first_hlt.png'");
		ftrdoc.getElementById("TrsFirst").setAttribute("onmouseout", "src='../icon/first.png'");
		ftrdoc.getElementById("TrsFirst").setAttribute("onclick", "handleTrsFirstClick()");

		ftrdoc.getElementById("TrsPrevious").src = "../icon/previous.png";
		ftrdoc.getElementById("TrsPrevious").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseover", "src='../icon/previous_hlt.png'");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onmouseout", "src='../icon/previous.png'");
		ftrdoc.getElementById("TrsPrevious").setAttribute("onclick", "handleTrsPreviousClick()");
	};

	if ((ntot <= 1) || (jnumSel == ntot)) {
		ftrdoc.getElementById("TrsNext").src = "../icon/next_inact.png";
		ftrdoc.getElementById("TrsNext").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsNext").onmouseover = null;
		ftrdoc.getElementById("TrsNext").onmouseout = null;
		ftrdoc.getElementById("TrsNext").onclick = null;

		ftrdoc.getElementById("TrsLast").src = "../icon/last_inact.png";
		ftrdoc.getElementById("TrsLast").setAttribute("class", "ftr_butdis");
		ftrdoc.getElementById("TrsLast").onmouseover = null;
		ftrdoc.getElementById("TrsLast").onmouseout = null;
		ftrdoc.getElementById("TrsLast").onclick = null;
	} else {
		ftrdoc.getElementById("TrsNext").src = "../icon/next.png";
		ftrdoc.getElementById("TrsNext").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsNext").setAttribute("onmouseover", "src='../icon/next_hlt.png'");
		ftrdoc.getElementById("TrsNext").setAttribute("onmouseout", "src='../icon/next.png'");
		ftrdoc.getElementById("TrsNext").setAttribute("onclick", "handleTrsNextClick()");

		ftrdoc.getElementById("TrsLast").src = "../icon/last.png";
		ftrdoc.getElementById("TrsLast").setAttribute("class", "ftr_but");
		ftrdoc.getElementById("TrsLast").setAttribute("onmouseover", "src='../icon/last_hlt.png'");
		ftrdoc.getElementById("TrsLast").setAttribute("onmouseout", "src='../icon/last.png'");
		ftrdoc.getElementById("TrsLast").setAttribute("onclick", "handleTrsLastClick()");
	};

	refreshCsi(ftrdoc, "CsiQst", srcdoc, "FeedFCsiQst", retrieveCi(srcdoc, "ContInfWdbeFstAStep", "numFCsiQst"));

	height = 20 + 18*ndisp;

	getRecwnd().changeHeight("AStep", height+55, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+55));
	doc.getElementById("AStep_side").setAttribute("height", "" + (height+55));
	doc.getElementById("AStep_cont").setAttribute("height", "" + (height+55));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+55-30));
	contdoc.getElementById("tdTbl").setAttribute("height", "" + height);
	contdoc.getElementById("AStep_tbl").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeFstAStep", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") refreshA();
	else if (srefIxWdbeVExpstate == "regd") refreshBD(true, false);
	else if (srefIxWdbeVExpstate == "detd") refreshBD(false, false);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("AStep_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

function handleButClipboardClick() {
	copyToClipboard(document, srcdoc, "WdbeFstAStep", "ListWdbeQFstAStep", retrieveTi(srcdoc, "TagWdbeFstAStep", "TxtRecord1"), retrieveTi(srcdoc, "TagWdbeFstAStep", "TxtRecord2"),
				["Fnx","Cn1","Ip1","Cn2","Ip2","Cn3","Ip3","Cn4","Ip4","Cn5","Ip5","Cn6","Ip6"],
				["fnx","cn1","ip1","cn2","ip2","cn3","ip3","cn4","ip4","cn5","ip5","cn6","ip6"]);
};

// --- generalized event handlers for app controls

function handleTblSelect(jnum) {
	var jnumFirstdisp, jnumLastdisp, jnumFirstload;

	var oldJnum = parseInt(retrieveSi(srcdoc, "StgIacQryWdbeFstAStep", "jnum"));
	var oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "jnumFirstdisp"));
	var oldJnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "jnumFirstload"));

	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "ndisp"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "ntot"));

	if (ntot == 0) return;

	if (jnum < 0) jnum = 0;
	if (jnum > ntot) jnum = ntot;

	if (oldJnum != jnum) {
		setSi(srcdoc, "StgIacQryWdbeFstAStep", "jnum", jnum);

		if (jnum != 0) {
			if (!((jnum >= oldJnumFirstdisp) && (jnum <= (oldJnumFirstdisp+ndisp-1)))) {
				jnumFirstdisp = jnum - Math.ceil(0.5*ndisp) + 1;
				if ((jnumFirstdisp+ndisp-1) > ntot) jnumFirstdisp = ntot-ndisp+1;
				if (jnumFirstdisp < 1) jnumFirstdisp = 1;

				setSi(srcdoc, "StatAppQryWdbeFstAStep", "jnumFirstdisp", jnumFirstdisp);

				jnumLastdisp = jnumFirstdisp + ndisp - 1;
				if (jnumLastdisp > ntot) jnumLastdisp = ntot;

				if (!((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1)))) {
					jnumFirstload = jnum - Math.ceil(0.5*nload) + 1;
					if (jnumFirstload < 1) jnumFirstload = 1;

					setSi(srcdoc, "StgIacQryWdbeFstAStep", "jnumFirstload", jnumFirstload);
				};
			};
		};

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeFstAStepData", scrJref, "StgIacQryWdbeFstAStep");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function changeTblJnumFirstdisp(jnumFirstdisp, dJnumFirstdisp, dpgJnumFirstdisp) {
	var jnumLastdisp, jnumFirstload;

	var oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "jnumFirstdisp"));
	var oldJnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "jnumFirstload"));

	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "ndisp"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "ntot"));

	if (ntot == 0) return;

	if (dpgJnumFirstdisp < 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp + 1;
	else if (dpgJnumFirstdisp > 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp - 1;
	else if (dJnumFirstdisp != 0) jnumFirstdisp = oldJnumFirstdisp + dJnumFirstdisp;

	if (jnumFirstdisp > (ntot-ndisp+1)) jnumFirstdisp = ntot-ndisp+1;
	if (jnumFirstdisp < 1) jnumFirstdisp = 1;

	if (oldJnumFirstdisp != jnumFirstdisp) {
		setSi(srcdoc, "StatAppQryWdbeFstAStep", "jnumFirstdisp", jnumFirstdisp);

		jnumLastdisp = jnumFirstdisp + ndisp - 1;
		if (jnumLastdisp > ntot) jnumLastdisp = ntot;

		if ((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1))) {
			refreshBD((retrieveSi(srcdoc, "StatAppWdbeFstAStep", "srefIxWdbeVExpstate") == "regd"), false);

		} else {
			jnumFirstload = jnumFirstdisp - Math.ceil(0.5*(nload-ndisp));
			if (jnumFirstload < 1) jnumFirstload = 1;

			setSi(srcdoc, "StgIacQryWdbeFstAStep", "jnumFirstload", jnumFirstload);

			var str = serializeDpchAppData(srcdoc, "DpchAppWdbeFstAStepData", scrJref, "StgIacQryWdbeFstAStep");
			sendReq(str, doc, handleDpchAppDataDoReply);
		};
	};
};

function handleTblCpreviousClick() {
	var oldFirstcol = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "firstcol"));

	setSi(srcdoc, "StatAppQryWdbeFstAStep", "firstcol", "" + (oldFirstcol-1));

	refreshBD((retrieveSi(srcdoc, "StatAppWdbeFstAStep", "srefIxWdbeVExpstate") == "regd"), true);
};

function handleTblCnextClick() {
	var oldFirstcol = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "firstcol"));

	setSi(srcdoc, "StatAppQryWdbeFstAStep", "firstcol", "" + (oldFirstcol+1));

	refreshBD((retrieveSi(srcdoc, "StatAppWdbeFstAStep", "srefIxWdbeVExpstate") == "regd"), true);
};

function handleTrsFirstClick() {
	handleTblSelect(1);
};

function handleTrsPreviousClick() {
	var jnum = parseInt(retrieveSi(srcdoc, "StgIacQryWdbeFstAStep", "jnum"));

	handleTblSelect(jnum-1);
};

function handleTrsNextClick() {
	var jnum = parseInt(retrieveSi(srcdoc, "StgIacQryWdbeFstAStep", "jnum"));

	handleTblSelect(jnum+1);
};

function handleTrsLastClick() {
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "ntot"));

	handleTblSelect(ntot);
};

function handleTrsGotoClick() {
	ftrdoc.getElementById("TrsGoto").style.display = "none";

	var elem = ftrdoc.getElementById("TrsRow");
	elem.style.display = "inline";
	elem.focus();
};

function handleTrsRowMou() {
	var elem = ftrdoc.getElementById("TrsRow");
	elem.value = "";
	elem.style.display = "none";

	ftrdoc.getElementById("TrsGoto").style.display = "inline";
};

function handleTrsRowKey(evt) {
	if (evt.keyCode == 13) {
		handleTblSelect(parseInt(ftrdoc.getElementById("TrsRow").value));

		handleTrsRowMou();
		return false;
	};

	return true;
};

function setTsbPos(pos) {
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "ndisp"));
	var vpos = (18 + Math.round(pos * (18*(ndisp-2))));

	tbldoc.getElementById("TsbJpupr").setAttribute("height", "" + (vpos-10));
	tbldoc.getElementById("TsbJpupl").setAttribute("y2", "" + vpos);

	tbldoc.getElementById("TsbJpdownr").setAttribute("y", "" + vpos);
	tbldoc.getElementById("TsbJpdownr").setAttribute("height", "" + (18*ndisp-vpos-11));
	tbldoc.getElementById("TsbJpdownl").setAttribute("y1", "" + vpos);

	tbldoc.getElementById("Tsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleTsbUpClick() {
	changeTblJnumFirstdisp(0, -1, 0);
};

function handleTsbJpupClick() {
	changeTblJnumFirstdisp(0, 0, -1);
};

function handleTsbJpdownClick() {
	changeTblJnumFirstdisp(0, 0, 1);
};

function handleTsbDownClick() {
	changeTblJnumFirstdisp(0, 1, 0);
};

function handleTsbMdn() {
	tbldoc.getElementById("tdTsb").onmousemove = handleTsbMove;
	tbldoc.getElementById("tdTsb").onmouseup = handleTsbMup;
};

function handleTsbMove(evt) {
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "ndisp"));

	if ((evt.clientY >= (18+20)) && (evt.clientY <= (18*(ndisp-1)+20))) {
		pos = ((evt.clientY-20) - 18) / (18*(ndisp-2));
		setTsbPos(pos);
	};
};

function handleTsbMup(evt) {
	tbldoc.getElementById("tdTsb").removeAttribute("onmousemove");
	tbldoc.getElementById("tdTsb").removeAttribute("onmouseup");

	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeFstAStep", "ntot"));
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeFstAStep", "ndisp"));

	var pos = ((evt.clientY-20) - 18) / (18*(ndisp-2));

	changeTblJnumFirstdisp(Math.round(pos*(ntot-ndisp))+1, 0, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeFstAStepDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "ContInfWdbeFstAStep", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "FeedFCsiQst", srcdoc)) mask.push("feedFCsiQst");
	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "StatAppWdbeFstAStep", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "StatShrWdbeFstAStep", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "StgIacWdbeFstAStep", srcdoc)) mask.push("stgiac");
	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "TagWdbeFstAStep", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "ListWdbeQFstAStep", srcdoc)) mask.push("rst");
	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "StatAppQryWdbeFstAStep", srcdoc)) mask.push("statappqry");
	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "StatShrQryWdbeFstAStep", srcdoc)) mask.push("statshrqry");
	if (updateSrcblock(dom, "DpchEngWdbeFstAStepData", "StgIacQryWdbeFstAStep", srcdoc)) mask.push("stgiacqry");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeFstAStepData") {
		mergeDpchEngData(dom);
		refresh();
		// IP handleDpchEng --- INSERT
	};
};

// IP dpchhdls --- INSERT

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWdbeFstAStepData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("AStep");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWdbeConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWdbeFstAStepData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};
