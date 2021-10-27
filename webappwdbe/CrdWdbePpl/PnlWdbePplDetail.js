// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbePplDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbePplDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbePplDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbePplDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbePplDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbePplDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbePplDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbePplDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbePplDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbePplDetail", "CptSrf"));
	initCpt(contcontdoc, "CptHsm", retrieveTi(srcdoc, "TagWdbePplDetail", "CptHsm"));
	initCpt(contcontdoc, "CptClk", retrieveTi(srcdoc, "TagWdbePplDetail", "CptClk"));
	initCpt(contcontdoc, "CptClg", retrieveTi(srcdoc, "TagWdbePplDetail", "CptClg"));
	initCpt(contcontdoc, "CptAsr", retrieveTi(srcdoc, "TagWdbePplDetail", "CptAsr"));
	initCpt(contcontdoc, "CptDpt", retrieveTi(srcdoc, "TagWdbePplDetail", "CptDpt"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbePplDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbePplDetail", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		initA();
	} else if (srefIxWdbeVExpstate == "regd") {
		initBD(true);
	} else if (srefIxWdbeVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	if (!contcontdoc) return;

	var height = 242; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxtSrfActive") == "true");

	var TxtHsmActive = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxtHsmActive") == "true");
	var ButHsmViewAvail = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "ButHsmViewAvail") == "true");
	var ButHsmViewActive = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "ButHsmViewActive") == "true");

	var TxtClkAlt = (retrieveSi(srcdoc, "StatAppWdbePplDetail", "TxtClkAlt") == "true");
	var TxfClkValid = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxfClkValid") == "true");
	var TxtClkActive = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxtClkActive") == "true");
	var ButClkViewAvail = !TxtClkAlt && (retrieveSi(srcdoc, "StatShrWdbePplDetail", "ButClkViewAvail") == "true");;

	var TxtClgAlt = (retrieveSi(srcdoc, "StatAppWdbePplDetail", "TxtClgAlt") == "true");
	var TxfClgValid = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxfClgValid") == "true");
	var TxtClgActive = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxtClgActive") == "true");
	var ButClgViewAvail = !TxtClgAlt && (retrieveSi(srcdoc, "StatShrWdbePplDetail", "ButClgViewAvail") == "true");;

	var TxtAsrAlt = (retrieveSi(srcdoc, "StatAppWdbePplDetail", "TxtAsrAlt") == "true");
	var TxfAsrValid = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxfAsrValid") == "true");
	var TxtAsrActive = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxtAsrActive") == "true");
	var ButAsrViewAvail = !TxtAsrAlt && (retrieveSi(srcdoc, "StatShrWdbePplDetail", "ButAsrViewAvail") == "true");;

	var TxfDptActive = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxfDptActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbePplDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbePplDetail", "TxtSrf"));

	if ((ButHsmViewAvail == !contcontdoc.getElementById("ButHsmView"))) {
		mytd = contcontdoc.getElementById("rdynHsm");
		clearElem(mytd);

		first = true;

		if (ButHsmViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButHsmView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtHsm", retrieveCi(srcdoc, "ContInfWdbePplDetail", "TxtHsm"));

	if (ButHsmViewAvail) refreshButicon(contcontdoc, "ButHsmView", "icon/view", ButHsmViewActive, false);

	if ( (TxtClkAlt == !contcontdoc.getElementById("TxfClk")) || (!TxtClkAlt == !contcontdoc.getElementById("TxtClk")) ) {
		mytd = contcontdoc.getElementById("dynClk");
		clearElem(mytd);

		if (TxtClkAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfClk", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtClk", ""));
	};

	if (TxtClkAlt) refreshTxf(contcontdoc, "TxfClk", "", retrieveCi(srcdoc, "ContIacWdbePplDetail", "TxfClk"), TxtClkActive, false, TxfClkValid);
	else refreshTxt(contcontdoc, "TxtClk", retrieveCi(srcdoc, "ContInfWdbePplDetail", "TxtClk"));

	if ((ButClkViewAvail == !contcontdoc.getElementById("ButClkView"))) {
		mytd = contcontdoc.getElementById("rdynClk");
		clearElem(mytd);

		first = true;

		if (ButClkViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButClkView", "icon/view"));
		};
	};

	if ( (TxtClgAlt == !contcontdoc.getElementById("TxfClg")) || (!TxtClgAlt == !contcontdoc.getElementById("TxtClg")) ) {
		mytd = contcontdoc.getElementById("dynClg");
		clearElem(mytd);

		if (TxtClgAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfClg", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtClg", ""));
	};

	if (TxtClgAlt) refreshTxf(contcontdoc, "TxfClg", "", retrieveCi(srcdoc, "ContIacWdbePplDetail", "TxfClg"), TxtClgActive, false, TxfClgValid);
	else refreshTxt(contcontdoc, "TxtClg", retrieveCi(srcdoc, "ContInfWdbePplDetail", "TxtClg"));

	if ((ButClgViewAvail == !contcontdoc.getElementById("ButClgView"))) {
		mytd = contcontdoc.getElementById("rdynClg");
		clearElem(mytd);

		first = true;

		if (ButClgViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButClgView", "icon/view"));
		};
	};

	if ( (TxtAsrAlt == !contcontdoc.getElementById("TxfAsr")) || (!TxtAsrAlt == !contcontdoc.getElementById("TxtAsr")) ) {
		mytd = contcontdoc.getElementById("dynAsr");
		clearElem(mytd);

		if (TxtAsrAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAsr", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAsr", ""));
	};

	if (TxtAsrAlt) refreshTxf(contcontdoc, "TxfAsr", "", retrieveCi(srcdoc, "ContIacWdbePplDetail", "TxfAsr"), TxtAsrActive, false, TxfAsrValid);
	else refreshTxt(contcontdoc, "TxtAsr", retrieveCi(srcdoc, "ContInfWdbePplDetail", "TxtAsr"));

	if ((ButAsrViewAvail == !contcontdoc.getElementById("ButAsrView"))) {
		mytd = contcontdoc.getElementById("rdynAsr");
		clearElem(mytd);

		first = true;

		if (ButAsrViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButAsrView", "icon/view"));
		};
	};

	refreshTxf(contcontdoc, "TxfDpt", "s", retrieveCi(srcdoc, "ContIacWdbePplDetail", "TxfDpt"), TxfDptActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbePplDetail", "TxfCmt"), TxfCmtActive, false, true);

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbePplDetail", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		refreshA();
	} else if (srefIxWdbeVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxWdbeVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Detail_src").contentDocument;

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

// --- generalized event handlers for app controls

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppWdbePplDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWdbePplDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePplDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePplDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbePplDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbePplDetailData", scrJref, "ContIacWdbePplDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbePplDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePplDetailData", scrJref, "ContIacWdbePplDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacWdbePplDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePplDetailData", scrJref, "ContIacWdbePplDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbePplDetailData", "ContIacWdbePplDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbePplDetailData", "ContInfWdbePplDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbePplDetailData", "StatAppWdbePplDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbePplDetailData", "StatShrWdbePplDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbePplDetailData", "TagWdbePplDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbePplDetailData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWdbePplDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
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

			} else if (blk.nodeName == "DpchEngWdbePplDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWdbeConfirm") {
				accepted = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:accepted");
				_scrJref = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:scrJref");
				sref = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngWdbeAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wdbe:DpchEngWdbeAlert/wdbe:scrJref"),
						retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:ContInfWdbeAlert"),
						retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:FeedFMcbAlert"));
			};
		};
	};
};
