/**
  * \file PnlWdbeSigDetail.js
  * web client functionality for panel PnlWdbeSigDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeSigDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeSigDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeSigDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeSigDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeSigDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeSigDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeSigDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeSigDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeSigDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptSrf"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWdbeSigDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptMdl", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptMdl"));
	initCpt(contcontdoc, "CptMgu", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptMgu"));
	refreshPup(contcontdoc, srcdoc, "PupMgt", "xs", "FeedFPupMgt", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numFPupMgt"), true, false);
	initCpt(contcontdoc, "CptVec", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptVec"));
	initCpt(contcontdoc, "CptCon", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptCon"));
	initCpt(contcontdoc, "CptHty", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptHty"));
	initCpt(contcontdoc, "CptWid", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptWid"));
	initCpt(contcontdoc, "CptMmx", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptMmx"));
	initCpt(contcontdoc, "CptCmb", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptCmb"));
	initCpt(contcontdoc, "CptOnv", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptOnv"));
	initCpt(contcontdoc, "CptOfv", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptOfv"));
	initCpt(contcontdoc, "CptDfo", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptDfo"));
	initCpt(contcontdoc, "CptDrv", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptDrv"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeSigDetail", "srefIxWdbeVExpstate");

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

	var height = 638; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxtSrfActive") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "PupTypActive") == "true");

	var LstCluAlt = (retrieveSi(srcdoc, "StatAppWdbeSigDetail", "LstCluAlt") == "true");
	var LstCluActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "LstCluActive") == "true");
	var ButCluViewAvail = !LstCluAlt;
	var ButCluViewActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButCluViewActive") == "true");
	var ButCluClusterAvail = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButCluClusterAvail") == "true");
	var ButCluUnclusterAvail = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButCluUnclusterAvail") == "true");

	var TxtMdlActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxtMdlActive") == "true");
	var ButMdlViewAvail = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButMdlViewAvail") == "true");
	var ButMdlViewActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButMdlViewActive") == "true");

	var TxtMguActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxtMguActive") == "true");
	var ButMguViewAvail = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButMguViewAvail") == "true");
	var ButMguViewActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButMguViewActive") == "true");

	var TxtVecActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxtVecActive") == "true");
	var ButVecViewAvail = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButVecViewAvail") == "true");
	var ButVecViewActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButVecViewActive") == "true");

	var ChkConActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ChkConActive") == "true");

	var PupHtyAlt = (retrieveSi(srcdoc, "StatAppWdbeSigDetail", "PupHtyAlt") == "true");
	var TxfHtyValid = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxfHtyValid") == "true");
	var PupHtyActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "PupHtyActive") == "true");
	var ButHtyEditAvail = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButHtyEditAvail") == "true");

	var TxfWidActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxfWidActive") == "true");

	var TxfMmxActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxfMmxActive") == "true");

	var TxfCmbActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxfCmbActive") == "true");

	var TxfOnvActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxfOnvActive") == "true");

	var TxfOfvActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxfOfvActive") == "true");

	var ChkDfoActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ChkDfoActive") == "true");

	var TxtDrvActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxtDrvActive") == "true");
	var ButDrvViewAvail = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButDrvViewAvail") == "true");
	var ButDrvViewActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButDrvViewActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeSigDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbeSigDetail", "TxtSrf"));

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numFPupTyp");

	height -= setCtlAvail(contcontdoc, "Clu2", !LstCluAlt, 71);
	if ( (LstCluAlt == !contcontdoc.getElementById("ButCluExpand")) || (!LstCluAlt == !contcontdoc.getElementById("ButCluCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynClu");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptClu", retrieveTi(srcdoc, "TagWdbeSigDetail", "CptClu")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstCluAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCluExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButCluCollapse", "icon/collapse"));
	};

	if ( (LstCluAlt == !contcontdoc.getElementById("TxtClu")) || (!LstCluAlt == !contcontdoc.getElementById("LstClu")) ) {
		mytd = contcontdoc.getElementById("dynClu");
		clearElem(mytd);

		if (LstCluAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtClu", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstClu", "./PnlWdbeSigDetail_LstClu.xml", false));
		};

	} else {
		if (!LstCluAlt) refreshLst(contcontdoc.getElementById("LstClu").contentWindow.document, srcdoc, 1, false, false, "FeedFLstClu",
					parseInt(retrieveSi(srcdoc, "StatAppWdbeSigDetail", "LstCluNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numFLstClu"))]);
	};

	if (LstCluAlt) refreshTxt(contcontdoc, "TxtClu", retrieveCi(srcdoc, "ContInfWdbeSigDetail", "TxtClu"));

	if ((ButCluViewAvail == !contcontdoc.getElementById("ButCluView")) || (ButCluClusterAvail == !contcontdoc.getElementById("ButCluCluster")) || (ButCluUnclusterAvail == !contcontdoc.getElementById("ButCluUncluster"))) {
		mytd = contcontdoc.getElementById("rdynClu");
		clearElem(mytd);

		first = true;

		if (ButCluViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluView", "icon/view"));
		};

		if (ButCluClusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluCluster", "icon/cluster"));
		};

		if (ButCluUnclusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluUncluster", "icon/uncluster"));
		};
	};

	if (ButCluViewAvail) refreshButicon(contcontdoc, "ButCluView", "icon/view", ButCluViewActive, false);

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

	refreshTxt(contcontdoc, "TxtMdl", retrieveCi(srcdoc, "ContInfWdbeSigDetail", "TxtMdl"));

	if (ButMdlViewAvail) refreshButicon(contcontdoc, "ButMdlView", "icon/view", ButMdlViewActive, false);

	if ((ButMguViewAvail == !contcontdoc.getElementById("ButMguView"))) {
		mytd = contcontdoc.getElementById("rdynMgu");
		clearElem(mytd);

		first = true;

		if (ButMguViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMguView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtMgu", retrieveCi(srcdoc, "ContInfWdbeSigDetail", "TxtMgu"));
	contcontdoc.getElementById("PupMgt").value = retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numFPupMgt");

	if (ButMguViewAvail) refreshButicon(contcontdoc, "ButMguView", "icon/view", ButMguViewActive, false);

	if ((ButVecViewAvail == !contcontdoc.getElementById("ButVecView"))) {
		mytd = contcontdoc.getElementById("rdynVec");
		clearElem(mytd);

		first = true;

		if (ButVecViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVecView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtVec", retrieveCi(srcdoc, "ContInfWdbeSigDetail", "TxtVec"));

	if (ButVecViewAvail) refreshButicon(contcontdoc, "ButVecView", "icon/view", ButVecViewActive, false);

	refreshChk(contcontdoc, "ChkCon", (retrieveCi(srcdoc, "ContIacWdbeSigDetail", "ChkCon") == "true"), ChkConActive);

	if ( (PupHtyAlt == !contcontdoc.getElementById("TxfHty")) || (!PupHtyAlt == !contcontdoc.getElementById("PupHty")) ) {
		mytd = contcontdoc.getElementById("dynHty");
		clearElem(mytd);

		if (PupHtyAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfHty", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupHty", ""));
	};

	if (PupHtyAlt) refreshTxf(contcontdoc, "TxfHty", "", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "TxfHty"), PupHtyActive, false, TxfHtyValid);
	else refreshPup(contcontdoc, srcdoc, "PupHty", "", "FeedFPupHty", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numFPupHty"), true, false);

	if ((ButHtyEditAvail == !contcontdoc.getElementById("ButHtyEdit"))) {
		mytd = contcontdoc.getElementById("rdynHty");
		clearElem(mytd);

		first = true;

		if (ButHtyEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButHtyEdit", "icon/edit"));
		};
	};

	refreshTxf(contcontdoc, "TxfWid", "s", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "TxfWid"), TxfWidActive, false, true);

	refreshTxf(contcontdoc, "TxfMmx", "s", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "TxfMmx"), TxfMmxActive, false, true);

	refreshTxf(contcontdoc, "TxfCmb", "", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "TxfCmb"), TxfCmbActive, false, true);

	refreshTxft(contcontdoc, "TxfOnv", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "TxfOnv"), TxfOnvActive, false, true);

	refreshTxft(contcontdoc, "TxfOfv", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "TxfOfv"), TxfOfvActive, false, true);

	refreshChk(contcontdoc, "ChkDfo", (retrieveCi(srcdoc, "ContIacWdbeSigDetail", "ChkDfo") == "true"), ChkDfoActive);

	if ((ButDrvViewAvail == !contcontdoc.getElementById("ButDrvView"))) {
		mytd = contcontdoc.getElementById("rdynDrv");
		clearElem(mytd);

		first = true;

		if (ButDrvViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButDrvView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtDrv", retrieveCi(srcdoc, "ContInfWdbeSigDetail", "TxtDrv"));

	if (ButDrvViewAvail) refreshButicon(contcontdoc, "ButDrvView", "icon/view", ButDrvViewActive, false);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbeSigDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeSigDetail", "srefIxWdbeVExpstate");

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

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeSigDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeSigDetail", basectlsref + "Alt", "false");
	refresh();
};

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppWdbeSigDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWdbeSigDetail", basectlsref + "Alt", alt);

	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, ncol, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, ncol, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeSigDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeSigDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeSigDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWdbeSigDetail", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSigDetailData", scrJref, "ContIacWdbeSigDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeSigDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeSigDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numsF" + ctlsref));

		found = false;

		for (var i = 0; i < oldNumsFLst.length; i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j = 0; j < oldNumsFLst.length; j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i = 0; i < oldNumsFLst.length; i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacWdbeSigDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeSigDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSigDetailData", scrJref, "ContIacWdbeSigDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeSigDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeSigDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeSigDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbeSigDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSigDetailData", scrJref, "ContIacWdbeSigDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeSigDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSigDetailData", scrJref, "ContIacWdbeSigDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeSigDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSigDetailData", scrJref, "ContIacWdbeSigDetail");
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

	setCi(srcdoc, "ContIacWdbeSigDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeSigDetailData", scrJref, "ContIacWdbeSigDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeSigDetailData", "ContIacWdbeSigDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeSigDetailData", "ContInfWdbeSigDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeSigDetailData", "FeedFLstClu", srcdoc)) mask.push("feedFLstClu");
	if (updateSrcblock(dom, "DpchEngWdbeSigDetailData", "FeedFPupHty", srcdoc)) mask.push("feedFPupHty");
	if (updateSrcblock(dom, "DpchEngWdbeSigDetailData", "FeedFPupMgt", srcdoc)) mask.push("feedFPupMgt");
	if (updateSrcblock(dom, "DpchEngWdbeSigDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWdbeSigDetailData", "StatAppWdbeSigDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeSigDetailData", "StatShrWdbeSigDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeSigDetailData", "TagWdbeSigDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeSigDetailData") {
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
			if (blk.nodeName == "DpchEngWdbeSigDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbeSigDetailData") {
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

