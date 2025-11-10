// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeSilDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeSilDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeSilDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeSilDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeSilDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeSilDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeSilDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeSilDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeSilDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptTit"));
	initCpt(contcontdoc, "CptFsr", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptFsr"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWdbeSilDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWdbeSilDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWdbeSilDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptMdl", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptMdl"));
	initCpt(contcontdoc, "CptPkg", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptPkg"));
	initCpt(contcontdoc, "CptEsy", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptEsy"));
	initCpt(contcontdoc, "CptTch", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptTch"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbeSilDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeSilDetail", "srefIxWdbeVExpstate");

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

	var height = 317; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "TxtSrfActive") == "true");

	var TxfTitActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "TxfTitActive") == "true");

	var TxfFsrActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "TxfFsrActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "PupTypActive") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "ButReuViewActive") == "true");

	var TxtMdlActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "TxtMdlActive") == "true");
	var ButMdlViewAvail = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "ButMdlViewAvail") == "true");
	var ButMdlViewActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "ButMdlViewActive") == "true");

	var PupPkgAlt = (retrieveSi(srcdoc, "StatAppWdbeSilDetail", "PupPkgAlt") == "true");
	var TxfPkgValid = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "TxfPkgValid") == "true");
	var PupPkgActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "PupPkgActive") == "true");
	var ButPkgEditAvail = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "ButPkgEditAvail") == "true");

	var ChkEsyActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "ChkEsyActive") == "true");

	var PupTchAlt = (retrieveSi(srcdoc, "StatAppWdbeSilDetail", "PupTchAlt") == "true");
	var TxfTchValid = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "TxfTchValid") == "true");
	var PupTchActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "PupTchActive") == "true");
	var ButTchEditAvail = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "ButTchEditAvail") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeSilDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbeSilDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacWdbeSilDetail", "TxfTit"), TxfTitActive, false, true);

	refreshTxf(contcontdoc, "TxfFsr", "", retrieveCi(srcdoc, "ContIacWdbeSilDetail", "TxfFsr"), TxfFsrActive, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWdbeSilDetail", "numFPupTyp");

	if ((ButReuViewAvail == !contcontdoc.getElementById("ButReuView"))) {
		mytd = contcontdoc.getElementById("rdynReu");
		clearElem(mytd);

		first = true;

		if (ButReuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButReuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWdbeSilDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWdbeSilDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

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

	refreshTxt(contcontdoc, "TxtMdl", retrieveCi(srcdoc, "ContInfWdbeSilDetail", "TxtMdl"));

	if (ButMdlViewAvail) refreshButicon(contcontdoc, "ButMdlView", "icon/view", ButMdlViewActive, false);

	if ( (PupPkgAlt == !contcontdoc.getElementById("TxfPkg")) || (!PupPkgAlt == !contcontdoc.getElementById("PupPkg")) ) {
		mytd = contcontdoc.getElementById("dynPkg");
		clearElem(mytd);

		if (PupPkgAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfPkg", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupPkg", ""));
	};

	if (PupPkgAlt) refreshTxf(contcontdoc, "TxfPkg", "", retrieveCi(srcdoc, "ContIacWdbeSilDetail", "TxfPkg"), PupPkgActive, false, TxfPkgValid);
	else refreshPup(contcontdoc, srcdoc, "PupPkg", "", "FeedFPupPkg", retrieveCi(srcdoc, "ContIacWdbeSilDetail", "numFPupPkg"), true, false);

	if ((ButPkgEditAvail == !contcontdoc.getElementById("ButPkgEdit"))) {
		mytd = contcontdoc.getElementById("rdynPkg");
		clearElem(mytd);

		first = true;

		if (ButPkgEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPkgEdit", "icon/edit"));
		};
	};

	refreshChk(contcontdoc, "ChkEsy", (retrieveCi(srcdoc, "ContIacWdbeSilDetail", "ChkEsy") == "true"), ChkEsyActive);

	if ( (PupTchAlt == !contcontdoc.getElementById("TxfTch")) || (!PupTchAlt == !contcontdoc.getElementById("PupTch")) ) {
		mytd = contcontdoc.getElementById("dynTch");
		clearElem(mytd);

		if (PupTchAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfTch", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupTch", ""));
	};

	if (PupTchAlt) refreshTxf(contcontdoc, "TxfTch", "", retrieveCi(srcdoc, "ContIacWdbeSilDetail", "TxfTch"), PupTchActive, false, TxfTchValid);
	else refreshPup(contcontdoc, srcdoc, "PupTch", "", "FeedFPupTch", retrieveCi(srcdoc, "ContIacWdbeSilDetail", "numFPupTch"), true, false);

	if ((ButTchEditAvail == !contcontdoc.getElementById("ButTchEdit"))) {
		mytd = contcontdoc.getElementById("rdynTch");
		clearElem(mytd);

		first = true;

		if (ButTchEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTchEdit", "icon/edit"));
		};
	};

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbeSilDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeSilDetail", "srefIxWdbeVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppWdbeSilDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWdbeSilDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeSilDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeSilDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeSilDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWdbeSilDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSilDetailData", scrJref, "ContIacWdbeSilDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbeSilDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSilDetailData", scrJref, "ContIacWdbeSilDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeSilDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSilDetailData", scrJref, "ContIacWdbeSilDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeSilDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSilDetailData", scrJref, "ContIacWdbeSilDetail");
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

	setCi(srcdoc, "ContIacWdbeSilDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSilDetailData", scrJref, "ContIacWdbeSilDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWdbeSilDetailData", "ContIacWdbeSilDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeSilDetailData", "ContInfWdbeSilDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeSilDetailData", "FeedFPupPkg", srcdoc)) mask.push("feedFPupPkg");
	if (updateSrcblock(dom, "DpchEngWdbeSilDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWdbeSilDetailData", "FeedFPupTch", srcdoc)) mask.push("feedFPupTch");
	if (updateSrcblock(dom, "DpchEngWdbeSilDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWdbeSilDetailData", "StatAppWdbeSilDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeSilDetailData", "StatShrWdbeSilDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeSilDetailData", "TagWdbeSilDetail", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeSilDetailData") {
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
			if (blk.nodeName == "DpchEngWdbeSilDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbeSilDetailData") {
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
