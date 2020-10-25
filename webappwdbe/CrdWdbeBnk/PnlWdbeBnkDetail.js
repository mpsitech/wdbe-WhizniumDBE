/**
  * \file PnlWdbeBnkDetail.js
  * web client functionality for panel PnlWdbeBnkDetail
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeBnkDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeBnkDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeBnkDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeBnkDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeBnkDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeBnkDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeBnkDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeBnkDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeBnkDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbeBnkDetail", "CptSrf"));
	initCpt(contcontdoc, "CptUnt", retrieveTi(srcdoc, "TagWdbeBnkDetail", "CptUnt"));
	initCpt(contcontdoc, "CptVst", retrieveTi(srcdoc, "TagWdbeBnkDetail", "CptVst"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeBnkDetail", "srefIxWdbeVExpstate");

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

	var height = 92; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbeBnkDetail", "TxtSrfActive") == "true");

	var TxtUntActive = (retrieveSi(srcdoc, "StatShrWdbeBnkDetail", "TxtUntActive") == "true");
	var ButUntViewAvail = (retrieveSi(srcdoc, "StatShrWdbeBnkDetail", "ButUntViewAvail") == "true");
	var ButUntViewActive = (retrieveSi(srcdoc, "StatShrWdbeBnkDetail", "ButUntViewActive") == "true");

	var PupVstAlt = (retrieveSi(srcdoc, "StatAppWdbeBnkDetail", "PupVstAlt") == "true");
	var TxfVstValid = (retrieveSi(srcdoc, "StatShrWdbeBnkDetail", "TxfVstValid") == "true");
	var PupVstActive = (retrieveSi(srcdoc, "StatShrWdbeBnkDetail", "PupVstActive") == "true");
	var ButVstEditAvail = (retrieveSi(srcdoc, "StatShrWdbeBnkDetail", "ButVstEditAvail") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeBnkDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbeBnkDetail", "TxtSrf"));

	if ((ButUntViewAvail == !contcontdoc.getElementById("ButUntView"))) {
		mytd = contcontdoc.getElementById("rdynUnt");
		clearElem(mytd);

		first = true;

		if (ButUntViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUntView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtUnt", retrieveCi(srcdoc, "ContInfWdbeBnkDetail", "TxtUnt"));

	if (ButUntViewAvail) refreshButicon(contcontdoc, "ButUntView", "icon/view", ButUntViewActive, false);

	if ( (PupVstAlt == !contcontdoc.getElementById("TxfVst")) || (!PupVstAlt == !contcontdoc.getElementById("PupVst")) ) {
		mytd = contcontdoc.getElementById("dynVst");
		clearElem(mytd);

		if (PupVstAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfVst", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupVst", ""));
	};

	if (PupVstAlt) refreshTxf(contcontdoc, "TxfVst", "", retrieveCi(srcdoc, "ContIacWdbeBnkDetail", "TxfVst"), PupVstActive, false, TxfVstValid);
	else refreshPup(contcontdoc, srcdoc, "PupVst", "", "FeedFPupVst", retrieveCi(srcdoc, "ContIacWdbeBnkDetail", "numFPupVst"), true, false);

	if ((ButVstEditAvail == !contcontdoc.getElementById("ButVstEdit"))) {
		mytd = contcontdoc.getElementById("rdynVst");
		clearElem(mytd);

		first = true;

		if (ButVstEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVstEdit", "icon/edit"));
		};
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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeBnkDetail", "srefIxWdbeVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppWdbeBnkDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWdbeBnkDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeBnkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeBnkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeBnkDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbeBnkDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeBnkDetailData", scrJref, "ContIacWdbeBnkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeBnkDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeBnkDetailData", scrJref, "ContIacWdbeBnkDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeBnkDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeBnkDetailData", scrJref, "ContIacWdbeBnkDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeBnkDetailData", "ContIacWdbeBnkDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeBnkDetailData", "ContInfWdbeBnkDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeBnkDetailData", "FeedFPupVst", srcdoc)) mask.push("feedFPupVst");
	if (updateSrcblock(dom, "DpchEngWdbeBnkDetailData", "StatAppWdbeBnkDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeBnkDetailData", "StatShrWdbeBnkDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeBnkDetailData", "TagWdbeBnkDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeBnkDetailData") {
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
			if (blk.nodeName == "DpchEngWdbeBnkDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbeBnkDetailData") {
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

function handleDpchAppDoDlgopenReply() {
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

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};

