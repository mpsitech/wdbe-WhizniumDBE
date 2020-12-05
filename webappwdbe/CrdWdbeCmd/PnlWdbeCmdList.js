// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("List", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("List_side").setAttribute("height", "30");
	doc.getElementById("List_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("List_side").src = "./PnlWdbeCmdList_aside.html";
	doc.getElementById("List_cont").src = "./PnlWdbeCmdList_a.html";
};

function regularize() {
	// change content (container heights in refreshB)
	doc.getElementById("List_side").src = "./PnlWdbeCmdList_bside.html";
	doc.getElementById("List_cont").src = "./PnlWdbeCmdList_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("List_side").contentDocument;
	contdoc = doc.getElementById("List_cont").contentDocument;
	hdrdoc = null;
	tbldoc = null;
	ftrdoc = null;

	refreshA();

	getCrdwnd().setInitdone("List");
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("List_side").contentDocument;
	contdoc = doc.getElementById("List_cont").contentDocument;
	hdrdoc = contdoc.getElementById("List_hdr").contentDocument;
	tbldoc = contdoc.getElementById("List_tbl").contentDocument;
	ftrdoc = contdoc.getElementById("List_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeCmdList", "Cpt"));

	// column headers in refreshB() only

	setTextContent(ftrdoc, ftrdoc.getElementById("TrsGoto"), retrieveTi(srcdoc, "TagWdbeCmdList", "Trs"));

	refreshB(true);

	getCrdwnd().setInitdone("List");
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdList", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") minimize();
	else if (srefIxWdbeVExpstate == "regd") regularize();
};

function refreshA() {
	var TxtFor = retrieveCi(srcdoc, "ContInfWdbeCmdList", "TxtFor");

	setTextContent(contdoc, contdoc.getElementById("TxtFor"), strFor(retrieveTi(srcdoc, "TagWdbeCmdList", "TxtFor"), TxtFor));

	if (TxtFor == "") {
		setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeCmdList", "Cpt") + " (" + retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "ntot") + ")");
		clearElem(contdoc.getElementById("TxtPre"));
	} else {
		setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeCmdList", "Cpt"));
		setTextContent(contdoc, contdoc.getElementById("TxtPre"), retrieveCi(srcdoc, "ContInfWdbeCmdList", "TxtPre") + " (" + retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "ntot") + ")");
	};
};

function refreshB(chgcol) {
	// obtain record set characteristics
	var jnumSel = parseInt(retrieveSi(srcdoc, "StgIacQryWdbeCmdList", "jnum"));
	var jnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "jnumFirstdisp"));
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "ndisp"));
	var jnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "jnumFirstload"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "ntot"));

	var mytbl, mytr, mytd, myspan, myimg, mycg, mycol;

	var txt;
	var jnum, selclass;

	var rownode;

	var height;

	var TxtFor = retrieveCi(srcdoc, "ContInfWdbeCmdList", "TxtFor");

	// header row
	setTextContent(hdrdoc, hdrdoc.getElementById("TxtFor"), strFor(retrieveTi(srcdoc, "TagWdbeCmdList", "TxtFor"), TxtFor));

	if (TxtFor == "") clearElem(hdrdoc.getElementById("TxtPre"));
	else setTextContent(hdrdoc, hdrdoc.getElementById("TxtPre"), retrieveCi(srcdoc, "ContInfWdbeCmdList", "TxtPre"));

	// update column characteristics
	if (chgcol) {
		// obtain column (header) characteristics
		var firstcol = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "firstcol"));
		var ncol = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "ncol"));

		var TcoSrfWidth = parseInt(retrieveSi(srcdoc, "StgIacWdbeCmdList", "TcoSrfWidth"));
		var TcoFsrWidth = parseInt(retrieveSi(srcdoc, "StgIacWdbeCmdList", "TcoFsrWidth"));
		var TcoRetWidth = parseInt(retrieveSi(srcdoc, "StgIacWdbeCmdList", "TcoRetWidth"));
		var TcoReuWidth = parseInt(retrieveSi(srcdoc, "StgIacWdbeCmdList", "TcoReuWidth"));
		var TcoRtyWidth = parseInt(retrieveSi(srcdoc, "StgIacWdbeCmdList", "TcoRtyWidth"));

		var numFTos = parseInt(retrieveCi(srcdoc, "ContIacWdbeCmdList", "numFTos"));

		// col data is stored in document variables
		doc.cols = new Array();
		doc.widths = new Array();
		doc.fs = new Array();
		doc.tos = new Array();

		var i, ix;
		var wtot = 0;
		var wmax = 901;

		for (i = firstcol, ix = 0; i <= ncol; i++) {
			ix++;

			if (i == 1) {
				doc.cols.push("TcoSrf"); doc.widths.push(TcoSrfWidth); doc.fs.push("srf"); doc.tos.push(2); wtot += TcoSrfWidth;
			} else if (i == 2) {
				doc.cols.push("TcoFsr"); doc.widths.push(TcoFsrWidth); doc.fs.push("fsr"); doc.tos.push(0); wtot += TcoFsrWidth;
			} else if (i == 3) {
				doc.cols.push("TcoRet"); doc.widths.push(TcoRetWidth); doc.fs.push("ret2"); doc.tos.push(0); wtot += TcoRetWidth;
			} else if (i == 4) {
				doc.cols.push("TcoReu"); doc.widths.push(TcoReuWidth); doc.fs.push("reu"); doc.tos.push(1); wtot += TcoReuWidth;
			} else if (i == 5) {
				doc.cols.push("TcoRty"); doc.widths.push(TcoRtyWidth); doc.fs.push("rty2"); doc.tos.push(0); wtot += TcoRtyWidth;
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
		mycol.setAttribute("width", "25");
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
			mytd.setAttribute("style", "background-color:#000000;");

			myspan = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:span");
			myspan.setAttribute("class", "col");
			setTextContent(tbldoc, myspan, retrieveTi(srcdoc, "TagWdbeCmdList", doc.cols[j]));
			mytd.appendChild(myspan);

			if (doc.tos[j] != 0) {
				mytd.appendChild(tbldoc.createTextNode("\u00a0"));

				myimg = tbldoc.createElementNS("http://www.w3.org/1999/xhtml", "html:img");
				myimg.setAttribute("width", "6");
				myimg.setAttribute("height", "12");
				myimg.setAttribute("alt", "sortdown");
				if (doc.tos[j] == numFTos) {
					myimg.setAttribute("class", "butdis");
					myimg.setAttribute("src", "../icon/sortdown_hlt.png");
				} else {
					myimg.setAttribute("class", "but");
					myimg.setAttribute("src", "../icon/sortdown.png");
					myimg.setAttribute("onmouseover", "src='../icon/sortdown_hlt.png'");
					myimg.setAttribute("onmouseout", "src='../icon/sortdown.png'");
					myimg.setAttribute("onclick", "handleTosSelect(" + doc.tos[j] + ")");
				};

				mytd.appendChild(myimg);
			};

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
		setSi(srcdoc, "StatAppQryWdbeCmdList", "jnumFirstdisp", jnumFirstdisp);
	};

	// scroll bar
	mytr.removeChild(tbldoc.getElementById("tdTsb"));
	mytr.appendChild(makeTdTsb(tbldoc, (ntot > ndisp), doc.cr, ndisp, (jnumFirstdisp - 1) / (ntot - ndisp), false));

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

		// find element in ListWdbeQCmdList
		rownode = getRownode(srcdoc, "ListWdbeQCmdList", jnum);

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

	setTextContent(ftrdoc, ftrdoc.getElementById("TxtShowing"), strShowing(retrieveTi(srcdoc, "TagWdbeCmdList", "TxtShowing1"), jnumFirstdisp, jnumLastdisp, ntot, retrieveTi(srcdoc, "TagWdbeCmdList", "TxtShowing2")));

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

	refreshCsi(ftrdoc, "CsiQst", srcdoc, "FeedFCsiQst", retrieveCi(srcdoc, "ContInfWdbeCmdList", "numFCsiQst"));

	height = 20 + 18*ndisp;

	getCrdwnd().changeHeight("List", height+55);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+55));
	doc.getElementById("List_side").setAttribute("height", "" + (height+55));
	doc.getElementById("List_cont").setAttribute("height", "" + (height+55));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+55-30));
	contdoc.getElementById("tdTbl").setAttribute("height", "" + height);
	contdoc.getElementById("List_tbl").setAttribute("height", "" + height);
};

function refresh(chgcol) {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdList", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") refreshA();
	else if (srefIxWdbeVExpstate == "regd") refreshB(chgcol);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("List_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButClipboardClick() {
	copyToClipboard(document, srcdoc, "WdbeCmdList", "ListWdbeQCmdList", retrieveTi(srcdoc, "TagWdbeCmdList", "TxtRecord1"), retrieveTi(srcdoc, "TagWdbeCmdList", "TxtRecord2"),
				["Srf","Fsr","","Ret","Reu","","Rty"],
				["srf","fsr","ret","ret2","reu","rty","rty2"]);
};

// --- generalized event handlers for app controls

function handleTblSelect(jnum) {
	var jnumFirstdisp, jnumLastdisp, jnumFirstload;

	var oldJnum = parseInt(retrieveSi(srcdoc, "StgIacQryWdbeCmdList", "jnum"));
	var oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "jnumFirstdisp"));
	var oldJnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "jnumFirstload"));

	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "ndisp"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "ntot"));

	if (ntot == 0) return;

	if (jnum < 0) jnum = 0;
	if (jnum > ntot) jnum = ntot;

	if (oldJnum != jnum) {
		setSi(srcdoc, "StgIacQryWdbeCmdList", "jnum", jnum);

		if (jnum != 0) {
			if (!((jnum >= oldJnumFirstdisp) && (jnum <= (oldJnumFirstdisp+ndisp-1)))) {
				jnumFirstdisp = jnum - Math.ceil(0.5*ndisp) + 1;
				if ((jnumFirstdisp+ndisp-1) > ntot) jnumFirstdisp = ntot-ndisp+1;
				if (jnumFirstdisp < 1) jnumFirstdisp = 1;

				setSi(srcdoc, "StatAppQryWdbeCmdList", "jnumFirstdisp", jnumFirstdisp);

				jnumLastdisp = jnumFirstdisp + ndisp - 1;
				if (jnumLastdisp > ntot) jnumLastdisp = ntot;

				if (!((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1)))) {
					jnumFirstload = jnum - Math.ceil(0.5*nload) + 1;
					if (jnumFirstload < 1) jnumFirstload = 1;

					setSi(srcdoc, "StgIacQryWdbeCmdList", "jnumFirstload", jnumFirstload);
				};
			};
		};

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCmdListData", scrJref, "StgIacQryWdbeCmdList");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function changeTblJnumFirstdisp(jnumFirstdisp, dJnumFirstdisp, dpgJnumFirstdisp) {
	var jnumLastdisp, jnumFirstload;

	var oldJnumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "jnumFirstdisp"));
	var oldJnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "jnumFirstload"));

	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "ndisp"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "ntot"));

	if (ntot == 0) return;

	if (dpgJnumFirstdisp < 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp + 1;
	else if (dpgJnumFirstdisp > 0) jnumFirstdisp = oldJnumFirstdisp + dpgJnumFirstdisp*ndisp - 1;
	else if (dJnumFirstdisp != 0) jnumFirstdisp = oldJnumFirstdisp + dJnumFirstdisp;

	if (jnumFirstdisp > (ntot-ndisp+1)) jnumFirstdisp = ntot-ndisp+1;
	if (jnumFirstdisp < 1) jnumFirstdisp = 1;

	if (oldJnumFirstdisp != jnumFirstdisp) {
		setSi(srcdoc, "StatAppQryWdbeCmdList", "jnumFirstdisp", jnumFirstdisp);

		jnumLastdisp = jnumFirstdisp + ndisp - 1;
		if (jnumLastdisp > ntot) jnumLastdisp = ntot;

		if ((jnumFirstdisp >= oldJnumFirstload) && (jnumLastdisp <= (oldJnumFirstload+nload-1))) {
			refreshB(false);

		} else {
			jnumFirstload = jnumFirstdisp - Math.ceil(0.5*(nload-ndisp));
			if (jnumFirstload < 1) jnumFirstload = 1;

			setSi(srcdoc, "StgIacQryWdbeCmdList", "jnumFirstload", jnumFirstload);

			var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCmdListData", scrJref, "StgIacQryWdbeCmdList");
			sendReq(str, doc, handleDpchAppDataDoReply);
		};
	};
};

function handleTblCpreviousClick() {
	var oldFirstcol = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "firstcol"));

	setSi(srcdoc, "StatAppQryWdbeCmdList", "firstcol", "" + (oldFirstcol-1));

	refreshB(true);
};

function handleTblCnextClick() {
	var oldFirstcol = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "firstcol"));

	setSi(srcdoc, "StatAppQryWdbeCmdList", "firstcol", "" + (oldFirstcol+1));

	refreshB(true);
};

function handleTrsFirstClick() {
	handleTblSelect(1);
};

function handleTrsPreviousClick() {
	var jnum = parseInt(retrieveSi(srcdoc, "StgIacQryWdbeCmdList", "jnum"));

	handleTblSelect(jnum-1);
};

function handleTrsNextClick() {
	var jnum = parseInt(retrieveSi(srcdoc, "StgIacQryWdbeCmdList", "jnum"));

	handleTblSelect(jnum+1);
};

function handleTrsLastClick() {
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "ntot"));

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
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "ndisp"));
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
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "ndisp"));

	if ((evt.clientY >= (18+20)) && (evt.clientY <= (18*(ndisp-1)+20))) {
		pos = ((evt.clientY-20) - 18) / (18*(ndisp-2));
		setTsbPos(pos);
	};
};

function handleTsbMup(evt) {
	tbldoc.getElementById("tdTsb").removeAttribute("onmousemove");
	tbldoc.getElementById("tdTsb").removeAttribute("onmouseup");

	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQryWdbeCmdList", "ntot"));
	var ndisp = parseInt(retrieveSi(srcdoc, "StatAppQryWdbeCmdList", "ndisp"));

	var pos = ((evt.clientY-20) - 18) / (18*(ndisp-2));

	changeTblJnumFirstdisp(Math.round(pos*(ntot-ndisp))+1, 0, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeCmdListDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTosSelect(numFTos) {
	var oldNumFTos = parseInt(retrieveCi(srcdoc, "ContIacWdbeCmdList", "numFTos"));

	if (oldNumFTos != numFTos) {
		setCi(srcdoc, "ContIacWdbeCmdList", "numFTos", "" + numFTos);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCmdListData", scrJref, "ContIacWdbeCmdList");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "ContIacWdbeCmdList", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "ContInfWdbeCmdList", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "FeedFCsiQst", srcdoc)) mask.push("feedFCsiQst");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "FeedFTos", srcdoc)) mask.push("feedFTos");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "StatShrWdbeCmdList", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "StgIacWdbeCmdList", srcdoc)) mask.push("stgiac");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "TagWdbeCmdList", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "ListWdbeQCmdList", srcdoc)) mask.push("rst");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "StatAppQryWdbeCmdList", srcdoc)) mask.push("statappqry");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "StatShrQryWdbeCmdList", srcdoc)) mask.push("statshrqry");
	if (updateSrcblock(dom, "DpchEngWdbeCmdListData", "StgIacQryWdbeCmdList", srcdoc)) mask.push("stgiacqry");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngWdbeCmdListData") {
		mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdList", "srefIxWdbeVExpstate");
			if (srefIxWdbeVExpstate == "mind") minimize();
			else if (srefIxWdbeVExpstate == "regd") regularize();
		} else {
			refresh(mask.indexOf("contiac") != -1);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWdbeCmdListData") {
				mergeDpchEngData(dom);
				init();
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWdbeConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWdbeCmdListData") {
				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdList", "srefIxWdbeVExpstate");
					if (srefIxWdbeVExpstate == "mind") minimize();
					else if (srefIxWdbeVExpstate == "regd") regularize();
				} else {
					refresh(mask.indexOf("contiac") != -1);
				};
			};

			getCrdwnd().restartNotify();
		};
	};
};

