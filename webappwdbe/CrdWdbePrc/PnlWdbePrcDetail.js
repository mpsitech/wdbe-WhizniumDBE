// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbePrcDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbePrcDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbePrcDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbePrcDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbePrcDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbePrcDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbePrcDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbePrcDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbePrcDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbePrcDetail", "CptSrf"));
	initCpt(contcontdoc, "CptMdl", retrieveTi(srcdoc, "TagWdbePrcDetail", "CptMdl"));
	initCpt(contcontdoc, "CptClk", retrieveTi(srcdoc, "TagWdbePrcDetail", "CptClk"));
	initCpt(contcontdoc, "CptAsr", retrieveTi(srcdoc, "TagWdbePrcDetail", "CptAsr"));
	initCpt(contcontdoc, "CptFal", retrieveTi(srcdoc, "TagWdbePrcDetail", "CptFal"));
	initCpt(contcontdoc, "CptSnr", retrieveTi(srcdoc, "TagWdbePrcDetail", "CptSnr"));
	initCpt(contcontdoc, "CptEip", retrieveTi(srcdoc, "TagWdbePrcDetail", "CptEip"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbePrcDetail", "CptCmt"));
	initCpt(contcontdoc, "CptFsmDtt", retrieveTi(srcdoc, "TagWdbePrcDetail", "CptFsmDtt"));
	refreshPup(contcontdoc, srcdoc, "PupFsmDtt", "", "FeedFPupFsmDtt", retrieveCi(srcdoc, "ContIacWdbePrcDetail", "numFPupFsmDtt"), retrieveSi(srcdoc, "StatShrWdbePrcDetail", "PupFsmDttActive"), false);
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbePrcDetail", "srefIxWdbeVExpstate");

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

	var height = 324; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "TxtSrfActive") == "true");

	var TxtMdlActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "TxtMdlActive") == "true");
	var ButMdlViewAvail = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "ButMdlViewAvail") == "true");
	var ButMdlViewActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "ButMdlViewActive") == "true");

	var TxtClkAlt = (retrieveSi(srcdoc, "StatAppWdbePrcDetail", "TxtClkAlt") == "true");
	var TxfClkValid = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "TxfClkValid") == "true");
	var TxtClkActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "TxtClkActive") == "true");
	var ButClkViewAvail = !TxtClkAlt && (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "ButClkViewAvail") == "true");;

	var TxtAsrAlt = (retrieveSi(srcdoc, "StatAppWdbePrcDetail", "TxtAsrAlt") == "true");
	var TxfAsrValid = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "TxfAsrValid") == "true");
	var TxtAsrActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "TxtAsrActive") == "true");
	var ButAsrViewAvail = !TxtAsrAlt && (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "ButAsrViewAvail") == "true");;

	var ChkFalActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "ChkFalActive") == "true");

	var TxfSnrActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "TxfSnrActive") == "true");

	var ChkEipActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "ChkEipActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "TxfCmtActive") == "true");

	var ButFsmNewAvail = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "ButFsmNewAvail") == "true");
	var ButFsmDeleteAvail = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "ButFsmDeleteAvail") == "true");

	var PupFsmDttAvail = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "PupFsmDttAvail") == "true");
	var PupFsmDttActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "PupFsmDttActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbePrcDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbePrcDetail", "TxtSrf"));

	if ((ButMdlViewAvail == !contcontdoc.getElementById("ButMdlView"))) {
		mytd = contcontdoc.getElementById("rdynMdl");
		clearElem(mytd);

		first = true;

		if (ButMdlViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMdlView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtMdl", retrieveCi(srcdoc, "ContInfWdbePrcDetail", "TxtMdl"));

	if (ButMdlViewAvail) refreshButicon(contcontdoc, "ButMdlView", "icon/view", ButMdlViewActive, false);

	if ( (TxtClkAlt == !contcontdoc.getElementById("TxfClk")) || (!TxtClkAlt == !contcontdoc.getElementById("TxtClk")) ) {
		mytd = contcontdoc.getElementById("dynClk");
		clearElem(mytd);

		if (TxtClkAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfClk", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtClk", ""));
	};

	if (TxtClkAlt) refreshTxf(contcontdoc, "TxfClk", "", retrieveCi(srcdoc, "ContIacWdbePrcDetail", "TxfClk"), TxtClkActive, false, TxfClkValid);
	else refreshTxt(contcontdoc, "TxtClk", retrieveCi(srcdoc, "ContInfWdbePrcDetail", "TxtClk"));

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

	if ( (TxtAsrAlt == !contcontdoc.getElementById("TxfAsr")) || (!TxtAsrAlt == !contcontdoc.getElementById("TxtAsr")) ) {
		mytd = contcontdoc.getElementById("dynAsr");
		clearElem(mytd);

		if (TxtAsrAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfAsr", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtAsr", ""));
	};

	if (TxtAsrAlt) refreshTxf(contcontdoc, "TxfAsr", "", retrieveCi(srcdoc, "ContIacWdbePrcDetail", "TxfAsr"), TxtAsrActive, false, TxfAsrValid);
	else refreshTxt(contcontdoc, "TxtAsr", retrieveCi(srcdoc, "ContInfWdbePrcDetail", "TxtAsr"));

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

	refreshChk(contcontdoc, "ChkFal", (retrieveCi(srcdoc, "ContIacWdbePrcDetail", "ChkFal") == "true"), ChkFalActive);

	refreshTxf(contcontdoc, "TxfSnr", "", retrieveCi(srcdoc, "ContIacWdbePrcDetail", "TxfSnr"), TxfSnrActive, false, true);

	refreshChk(contcontdoc, "ChkEip", (retrieveCi(srcdoc, "ContIacWdbePrcDetail", "ChkEip") == "true"), ChkEipActive);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbePrcDetail", "TxfCmt"), TxfCmtActive, false, true);

	if ((ButFsmNewAvail == !contcontdoc.getElementById("ButFsmNew")) || (ButFsmDeleteAvail == !contcontdoc.getElementById("ButFsmDelete"))) {
		mytd = contcontdoc.getElementById("dynFsm");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "HdgFsm", retrieveTi(srcdoc, "TagWdbePrcDetail", "HdgFsm")));
		mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

		first = true;

		if (ButFsmNewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFsmNew", "icon/new"));
		};

		if (ButFsmDeleteAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFsmDelete", "icon/delete"));
		};
	};

	height -= setCtlAvail(contcontdoc, "FsmDtt", PupFsmDttAvail, 25);
	if (PupFsmDttAvail) {
		contcontdoc.getElementById("PupFsmDtt").value = retrieveCi(srcdoc, "ContIacWdbePrcDetail", "numFPupFsmDtt");

	};

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbePrcDetail", "srefIxWdbeVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppWdbePrcDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWdbePrcDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWdbePrcDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrcDetailData", scrJref, "ContIacWdbePrcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbePrcDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrcDetailData", scrJref, "ContIacWdbePrcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbePrcDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrcDetailData", scrJref, "ContIacWdbePrcDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbePrcDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrcDetailData", scrJref, "ContIacWdbePrcDetail");
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

	setCi(srcdoc, "ContIacWdbePrcDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrcDetailData", scrJref, "ContIacWdbePrcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWdbePrcDetailData", "ContIacWdbePrcDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbePrcDetailData", "ContInfWdbePrcDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbePrcDetailData", "FeedFPupFsmDtt", srcdoc)) mask.push("feedFPupFsmDtt");
	if (updateSrcblock(dom, "DpchEngWdbePrcDetailData", "StatAppWdbePrcDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbePrcDetailData", "StatShrWdbePrcDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbePrcDetailData", "TagWdbePrcDetail", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbePrcDetailData") {
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
			if (blk.nodeName == "DpchEngWdbePrcDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbePrcDetailData") {
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
