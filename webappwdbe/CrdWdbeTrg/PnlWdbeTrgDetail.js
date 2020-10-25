/**
  * \file PnlWdbeTrgDetail.js
  * web client functionality for panel PnlWdbeTrgDetail
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeTrgDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeTrgDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeTrgDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeTrgDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeTrgDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeTrgDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeTrgDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeTrgDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeTrgDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbeTrgDetail", "CptSrf"));
	initCpt(contcontdoc, "CptSys", retrieveTi(srcdoc, "TagWdbeTrgDetail", "CptSys"));
	initCpt(contcontdoc, "CptUnt", retrieveTi(srcdoc, "TagWdbeTrgDetail", "CptUnt"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbeTrgDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeTrgDetail", "srefIxWdbeVExpstate");

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

	var height = 263; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "TxtSrfActive") == "true");

	var TxtSysActive = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "TxtSysActive") == "true");
	var ButSysViewAvail = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "ButSysViewAvail") == "true");
	var ButSysViewActive = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "ButSysViewActive") == "true");

	var TxtUntActive = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "TxtUntActive") == "true");
	var ButUntViewAvail = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "ButUntViewAvail") == "true");
	var ButUntViewActive = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "ButUntViewActive") == "true");

	var LstRteAlt = (retrieveSi(srcdoc, "StatAppWdbeTrgDetail", "LstRteAlt") == "true");
	var TxfRteValid = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "TxfRteValid") == "true");
	var LstRteActive = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "LstRteActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeTrgDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbeTrgDetail", "TxtSrf"));

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

	refreshTxt(contcontdoc, "TxtSys", retrieveCi(srcdoc, "ContInfWdbeTrgDetail", "TxtSys"));

	if (ButSysViewAvail) refreshButicon(contcontdoc, "ButSysView", "icon/view", ButSysViewActive, false);

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

	refreshTxt(contcontdoc, "TxtUnt", retrieveCi(srcdoc, "ContInfWdbeTrgDetail", "TxtUnt"));

	if (ButUntViewAvail) refreshButicon(contcontdoc, "ButUntView", "icon/view", ButUntViewActive, false);

	height -= setCtlAvail(contcontdoc, "Rte2", !LstRteAlt, 71);
	if ( (LstRteAlt == !contcontdoc.getElementById("ButRteExpand")) || (!LstRteAlt == !contcontdoc.getElementById("ButRteCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynRte");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptRte", retrieveTi(srcdoc, "TagWdbeTrgDetail", "CptRte")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstRteAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButRteExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButRteCollapse", "icon/collapse"));
	};

	if ( (LstRteAlt == !contcontdoc.getElementById("TxfRte")) || (!LstRteAlt == !contcontdoc.getElementById("LstRte")) ) {
		mytd = contcontdoc.getElementById("dynRte");
		clearElem(mytd);

		if (LstRteAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxf(contcontdoc, "TxfRte", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstRte", "./PnlWdbeTrgDetail_LstRte.xml", false));
		};

	} else {
		if (!LstRteAlt) refreshLst(contcontdoc.getElementById("LstRte").contentWindow.document, srcdoc, 1, false, false, "FeedFLstRte",
					parseInt(retrieveSi(srcdoc, "StatAppWdbeTrgDetail", "LstRteNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeTrgDetail", "numFLstRte"))]);
	};

	if (LstRteAlt) refreshTxf(contcontdoc, "TxfRte", "", retrieveCi(srcdoc, "ContIacWdbeTrgDetail", "TxfRte"), LstRteActive, false, TxfRteValid);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbeTrgDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeTrgDetail", "srefIxWdbeVExpstate");

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
	setSi(srcdoc, "StatAppWdbeTrgDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeTrgDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeTrgDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeTrgDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeTrgDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeTrgDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeTrgDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeTrgDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeTrgDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbeTrgDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeTrgDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeTrgDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeTrgDetailData", scrJref, "ContIacWdbeTrgDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeTrgDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeTrgDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeTrgDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeTrgDetail", "numF" + ctlsref))]);
	};
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeTrgDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeTrgDetailData", scrJref, "ContIacWdbeTrgDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeTrgDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeTrgDetailData", scrJref, "ContIacWdbeTrgDetail");
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

	setCi(srcdoc, "ContIacWdbeTrgDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeTrgDetailData", scrJref, "ContIacWdbeTrgDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeTrgDetailData", "ContIacWdbeTrgDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeTrgDetailData", "ContInfWdbeTrgDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeTrgDetailData", "FeedFLstRte", srcdoc)) mask.push("feedFLstRte");
	if (updateSrcblock(dom, "DpchEngWdbeTrgDetailData", "StatAppWdbeTrgDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeTrgDetailData", "StatShrWdbeTrgDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeTrgDetailData", "TagWdbeTrgDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeTrgDetailData") {
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
			if (blk.nodeName == "DpchEngWdbeTrgDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbeTrgDetailData") {
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

