/**
  * \file PnlWdbeUntDetail.js
  * web client functionality for panel PnlWdbeUntDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeUntDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeUntDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeUntDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeUntDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeUntDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeUntDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeUntDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeUntDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeUntDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptTit"));
	initCpt(contcontdoc, "CptFsr", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptFsr"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWdbeUntDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWdbeUntDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWdbeUntDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptSil", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptSil"));
	initCpt(contcontdoc, "CptSys", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptSys"));
	initCpt(contcontdoc, "CptMdl", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptMdl"));
	initCpt(contcontdoc, "CptPkg", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptPkg"));
	initCpt(contcontdoc, "CptEsy", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptEsy"));
	initCpt(contcontdoc, "CptTch", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptTch"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbeUntDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeUntDetail", "srefIxWdbeVExpstate");

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

	var height = 367; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxtSrfActive") == "true");

	var TxfTitActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxfTitActive") == "true");

	var TxfFsrActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxfFsrActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "PupTypActive") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButReuViewActive") == "true");

	var TxtSilAvail = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxtSilAvail") == "true");
	var TxtSilActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxtSilActive") == "true");
	var ButSilViewAvail = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButSilViewAvail") == "true");
	var ButSilViewActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButSilViewActive") == "true");

	var TxtSysActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxtSysActive") == "true");
	var ButSysViewAvail = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButSysViewAvail") == "true");
	var ButSysViewActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButSysViewActive") == "true");

	var TxtMdlActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxtMdlActive") == "true");
	var ButMdlViewAvail = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButMdlViewAvail") == "true");
	var ButMdlViewActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButMdlViewActive") == "true");

	var PupPkgAlt = (retrieveSi(srcdoc, "StatAppWdbeUntDetail", "PupPkgAlt") == "true");
	var TxfPkgValid = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxfPkgValid") == "true");
	var PupPkgActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "PupPkgActive") == "true");
	var ButPkgEditAvail = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButPkgEditAvail") == "true");

	var ChkEsyActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ChkEsyActive") == "true");

	var PupTchAlt = (retrieveSi(srcdoc, "StatAppWdbeUntDetail", "PupTchAlt") == "true");
	var TxfTchValid = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxfTchValid") == "true");
	var PupTchActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "PupTchActive") == "true");
	var ButTchEditAvail = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButTchEditAvail") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeUntDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbeUntDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfTit", "", retrieveCi(srcdoc, "ContIacWdbeUntDetail", "TxfTit"), TxfTitActive, false, true);

	refreshTxf(contcontdoc, "TxfFsr", "", retrieveCi(srcdoc, "ContIacWdbeUntDetail", "TxfFsr"), TxfFsrActive, false, true);

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWdbeUntDetail", "numFPupTyp");

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

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWdbeUntDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWdbeUntDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

	height -= setCtlAvail(contcontdoc, "Sil", TxtSilAvail, 25);
	if (TxtSilAvail) {
		if ((ButSilViewAvail == !contcontdoc.getElementById("ButSilView"))) {
			mytd = contcontdoc.getElementById("rdynSil");
			clearElem(mytd);

			first = true;

			if (ButSilViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSilView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtSil", retrieveCi(srcdoc, "ContInfWdbeUntDetail", "TxtSil"));

		if (ButSilViewAvail) refreshButicon(contcontdoc, "ButSilView", "icon/view", ButSilViewActive, false);

	};

	if ((ButSysViewAvail == !contcontdoc.getElementById("ButSysView"))) {
		mytd = contcontdoc.getElementById("rdynSys");
		clearElem(mytd);

		first = true;

		if (ButSysViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSysView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSys", retrieveCi(srcdoc, "ContInfWdbeUntDetail", "TxtSys"));

	if (ButSysViewAvail) refreshButicon(contcontdoc, "ButSysView", "icon/view", ButSysViewActive, false);

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

	refreshTxt(contcontdoc, "TxtMdl", retrieveCi(srcdoc, "ContInfWdbeUntDetail", "TxtMdl"));

	if (ButMdlViewAvail) refreshButicon(contcontdoc, "ButMdlView", "icon/view", ButMdlViewActive, false);

	if ( (PupPkgAlt == !contcontdoc.getElementById("TxfPkg")) || (!PupPkgAlt == !contcontdoc.getElementById("PupPkg")) ) {
		mytd = contcontdoc.getElementById("dynPkg");
		clearElem(mytd);

		if (PupPkgAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfPkg", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupPkg", ""));
	};

	if (PupPkgAlt) refreshTxf(contcontdoc, "TxfPkg", "", retrieveCi(srcdoc, "ContIacWdbeUntDetail", "TxfPkg"), PupPkgActive, false, TxfPkgValid);
	else refreshPup(contcontdoc, srcdoc, "PupPkg", "", "FeedFPupPkg", retrieveCi(srcdoc, "ContIacWdbeUntDetail", "numFPupPkg"), true, false);

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

	refreshChk(contcontdoc, "ChkEsy", (retrieveCi(srcdoc, "ContIacWdbeUntDetail", "ChkEsy") == "true"), ChkEsyActive);

	if ( (PupTchAlt == !contcontdoc.getElementById("TxfTch")) || (!PupTchAlt == !contcontdoc.getElementById("PupTch")) ) {
		mytd = contcontdoc.getElementById("dynTch");
		clearElem(mytd);

		if (PupTchAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfTch", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupTch", ""));
	};

	if (PupTchAlt) refreshTxf(contcontdoc, "TxfTch", "", retrieveCi(srcdoc, "ContIacWdbeUntDetail", "TxfTch"), PupTchActive, false, TxfTchValid);
	else refreshPup(contcontdoc, srcdoc, "PupTch", "", "FeedFPupTch", retrieveCi(srcdoc, "ContIacWdbeUntDetail", "numFPupTch"), true, false);

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

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbeUntDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeUntDetail", "srefIxWdbeVExpstate");

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

	if (retrieveSi(srcdoc, "StatAppWdbeUntDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWdbeUntDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeUntDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeUntDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeUntDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWdbeUntDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeUntDetailData", scrJref, "ContIacWdbeUntDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbeUntDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeUntDetailData", scrJref, "ContIacWdbeUntDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeUntDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeUntDetailData", scrJref, "ContIacWdbeUntDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeUntDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeUntDetailData", scrJref, "ContIacWdbeUntDetail");
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

	setCi(srcdoc, "ContIacWdbeUntDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeUntDetailData", scrJref, "ContIacWdbeUntDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeUntDetailData", "ContIacWdbeUntDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeUntDetailData", "ContInfWdbeUntDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeUntDetailData", "FeedFPupPkg", srcdoc)) mask.push("feedFPupPkg");
	if (updateSrcblock(dom, "DpchEngWdbeUntDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWdbeUntDetailData", "FeedFPupTch", srcdoc)) mask.push("feedFPupTch");
	if (updateSrcblock(dom, "DpchEngWdbeUntDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWdbeUntDetailData", "StatAppWdbeUntDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeUntDetailData", "StatShrWdbeUntDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeUntDetailData", "TagWdbeUntDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeUntDetailData") {
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
			if (blk.nodeName == "DpchEngWdbeUntDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbeUntDetailData") {
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

