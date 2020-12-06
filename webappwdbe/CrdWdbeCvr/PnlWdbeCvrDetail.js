// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeCvrDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeCvrDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeCvrDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeCvrDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeCvrDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeCvrDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeCvrDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeCvrDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeCvrDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptCpr", retrieveTi(srcdoc, "TagWdbeCvrDetail", "CptCpr"));
	initCpt(contcontdoc, "CptMaj", retrieveTi(srcdoc, "TagWdbeCvrDetail", "CptMaj"));
	initCpt(contcontdoc, "CptMin", retrieveTi(srcdoc, "TagWdbeCvrDetail", "CptMin"));
	initCpt(contcontdoc, "CptSub", retrieveTi(srcdoc, "TagWdbeCvrDetail", "CptSub"));
	initCpt(contcontdoc, "CptBcv", retrieveTi(srcdoc, "TagWdbeCvrDetail", "CptBcv"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagWdbeCvrDetail", "CptSte"));
	refreshPup(contcontdoc, srcdoc, "PupSte", "", "FeedFPupSte", retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numFPupSte"), retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "PupSteActive"), false);
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeCvrDetail", "srefIxWdbeVExpstate");

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

	var height = 288; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtCprActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "TxtCprActive") == "true");
	var ButCprViewAvail = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "ButCprViewAvail") == "true");
	var ButCprViewActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "ButCprViewActive") == "true");

	var TxfMajActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "TxfMajActive") == "true");

	var TxfMinActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "TxfMinActive") == "true");

	var TxfSubActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "TxfSubActive") == "true");

	var TxtBcvActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "TxtBcvActive") == "true");
	var ButBcvViewAvail = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "ButBcvViewAvail") == "true");
	var ButBcvViewActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "ButBcvViewActive") == "true");

	var PupJstActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "PupJstActive") == "true");
	var ButJstEditAvail = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "ButJstEditAvail") == "true");

	var PupSteActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "PupSteActive") == "true");

	var LstStyAlt = (retrieveSi(srcdoc, "StatAppWdbeCvrDetail", "LstStyAlt") == "true");
	var LstStyActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "LstStyActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeCvrDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButCprViewAvail == !contcontdoc.getElementById("ButCprView"))) {
		mytd = contcontdoc.getElementById("rdynCpr");
		clearElem(mytd);

		first = true;

		if (ButCprViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCprView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtCpr", retrieveCi(srcdoc, "ContInfWdbeCvrDetail", "TxtCpr"));

	if (ButCprViewAvail) refreshButicon(contcontdoc, "ButCprView", "icon/view", ButCprViewActive, false);

	refreshTxf(contcontdoc, "TxfMaj", "s", retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "TxfMaj"), TxfMajActive, false, true);

	refreshTxf(contcontdoc, "TxfMin", "s", retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "TxfMin"), TxfMinActive, false, true);

	refreshTxf(contcontdoc, "TxfSub", "s", retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "TxfSub"), TxfSubActive, false, true);

	if ((ButBcvViewAvail == !contcontdoc.getElementById("ButBcvView"))) {
		mytd = contcontdoc.getElementById("rdynBcv");
		clearElem(mytd);

		first = true;

		if (ButBcvViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButBcvView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtBcv", retrieveCi(srcdoc, "ContInfWdbeCvrDetail", "TxtBcv"));

	if (ButBcvViewAvail) refreshButicon(contcontdoc, "ButBcvView", "icon/view", ButBcvViewActive, false);

	if ((ButJstEditAvail == !contcontdoc.getElementById("ButJstEdit"))) {
		mytd = contcontdoc.getElementById("rdynJst");
		clearElem(mytd);

		first = true;

		if (ButJstEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJstEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJst", "s", "FeedFPupJst", retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numFPupJst"), PupJstActive, false);

	contcontdoc.getElementById("PupSte").value = retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numFPupSte");

	height -= setCtlAvail(contcontdoc, "Sty2", !LstStyAlt, 71);
	if ( (LstStyAlt == !contcontdoc.getElementById("ButStyExpand")) || (!LstStyAlt == !contcontdoc.getElementById("ButStyCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynSty");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptSty", retrieveTi(srcdoc, "TagWdbeCvrDetail", "CptSty")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstStyAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButStyExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButStyCollapse", "icon/collapse"));
	};

	if ( (LstStyAlt == !contcontdoc.getElementById("TxtSty")) || (!LstStyAlt == !contcontdoc.getElementById("LstSty")) ) {
		mytd = contcontdoc.getElementById("dynSty");
		clearElem(mytd);

		if (LstStyAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtSty", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstSty", "./PnlWdbeCvrDetail_LstSty.xml", false));
		};

	} else {
		if (!LstStyAlt) refreshLst(contcontdoc.getElementById("LstSty").contentWindow.document, srcdoc, 1, false, true, "FeedFLstSty",
					parseInt(retrieveSi(srcdoc, "StatAppWdbeCvrDetail", "LstStyNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numsFLstSty")));
	};

	if (LstStyAlt) refreshTxt(contcontdoc, "TxtSty", retrieveCi(srcdoc, "ContInfWdbeCvrDetail", "TxtSty"));

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeCvrDetail", "srefIxWdbeVExpstate");

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
	setSi(srcdoc, "StatAppWdbeCvrDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeCvrDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeCvrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeCvrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeCvrDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeCvrDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeCvrDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbeCvrDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeCvrDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCvrDetailData", scrJref, "ContIacWdbeCvrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeCvrDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeCvrDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeCvrDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbeCvrDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCvrDetailData", scrJref, "ContIacWdbeCvrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeCvrDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCvrDetailData", scrJref, "ContIacWdbeCvrDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeCvrDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCvrDetailData", scrJref, "ContIacWdbeCvrDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeCvrDetailData", "ContIacWdbeCvrDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeCvrDetailData", "ContInfWdbeCvrDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeCvrDetailData", "FeedFLstSty", srcdoc)) mask.push("feedFLstSty");
	if (updateSrcblock(dom, "DpchEngWdbeCvrDetailData", "FeedFPupJst", srcdoc)) mask.push("feedFPupJst");
	if (updateSrcblock(dom, "DpchEngWdbeCvrDetailData", "FeedFPupSte", srcdoc)) mask.push("feedFPupSte");
	if (updateSrcblock(dom, "DpchEngWdbeCvrDetailData", "StatAppWdbeCvrDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeCvrDetailData", "StatShrWdbeCvrDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeCvrDetailData", "TagWdbeCvrDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeCvrDetailData") {
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
			if (blk.nodeName == "DpchEngWdbeCvrDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbeCvrDetailData") {
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
