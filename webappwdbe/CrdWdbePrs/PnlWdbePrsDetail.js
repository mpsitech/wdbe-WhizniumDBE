// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbePrsDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbePrsDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbePrsDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbePrsDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbePrsDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbePrsDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbePrsDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbePrsDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbePrsDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptTit", retrieveTi(srcdoc, "TagWdbePrsDetail", "CptTit"));
	initCpt(contcontdoc, "CptFnm", retrieveTi(srcdoc, "TagWdbePrsDetail", "CptFnm"));
	initCpt(contcontdoc, "CptLnm", retrieveTi(srcdoc, "TagWdbePrsDetail", "CptLnm"));
	initCpt(contcontdoc, "CptSex", retrieveTi(srcdoc, "TagWdbePrsDetail", "CptSex"));
	refreshPup(contcontdoc, srcdoc, "PupSex", "", "FeedFPupSex", retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numFPupSex"), retrieveSi(srcdoc, "StatShrWdbePrsDetail", "PupSexActive"), false);
	initCpt(contcontdoc, "CptTel", retrieveTi(srcdoc, "TagWdbePrsDetail", "CptTel"));
	initCpt(contcontdoc, "CptEml", retrieveTi(srcdoc, "TagWdbePrsDetail", "CptEml"));
	initCpt(contcontdoc, "CptSal", retrieveTi(srcdoc, "TagWdbePrsDetail", "CptSal"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbePrsDetail", "srefIxWdbeVExpstate");

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

	var height = 313; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxfTitActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "TxfTitActive") == "true");

	var TxfFnmActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "TxfFnmActive") == "true");

	var PupJActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "PupJActive") == "true");
	var ButJEditAvail = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "ButJEditAvail") == "true");

	var TxtLnmActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "TxtLnmActive") == "true");

	var LstDrvAlt = (retrieveSi(srcdoc, "StatAppWdbePrsDetail", "LstDrvAlt") == "true");
	var LstDrvActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "LstDrvActive") == "true");

	var PupSexActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "PupSexActive") == "true");

	var TxfTelActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "TxfTelActive") == "true");

	var TxfEmlActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "TxfEmlActive") == "true");

	var TxfSalActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "TxfSalActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbePrsDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxf(contcontdoc, "TxfTit", "s", retrieveCi(srcdoc, "ContIacWdbePrsDetail", "TxfTit"), TxfTitActive, false, true);

	refreshTxf(contcontdoc, "TxfFnm", "s", retrieveCi(srcdoc, "ContIacWdbePrsDetail", "TxfFnm"), TxfFnmActive, false, true);

	if ((ButJEditAvail == !contcontdoc.getElementById("ButJEdit"))) {
		mytd = contcontdoc.getElementById("rdynJ");
		clearElem(mytd);

		first = true;

		if (ButJEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJ", "s", "FeedFPupJ", retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numFPupJ"), PupJActive, false);

	refreshTxt(contcontdoc, "TxtLnm", retrieveCi(srcdoc, "ContInfWdbePrsDetail", "TxtLnm"));

	height -= setCtlAvail(contcontdoc, "Drv2", !LstDrvAlt, 71);
	if ( (LstDrvAlt == !contcontdoc.getElementById("ButDrvExpand")) || (!LstDrvAlt == !contcontdoc.getElementById("ButDrvCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynDrv");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptDrv", retrieveTi(srcdoc, "TagWdbePrsDetail", "CptDrv")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstDrvAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButDrvExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButDrvCollapse", "icon/collapse"));
	};

	if ( (LstDrvAlt == !contcontdoc.getElementById("TxtDrv")) || (!LstDrvAlt == !contcontdoc.getElementById("LstDrv")) ) {
		mytd = contcontdoc.getElementById("dynDrv");
		clearElem(mytd);

		if (LstDrvAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtDrv", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstDrv", "./PnlWdbePrsDetail_LstDrv.xml", false));
		};

	} else {
		if (!LstDrvAlt) refreshLst(contcontdoc.getElementById("LstDrv").contentWindow.document, srcdoc, 1, false, true, "FeedFLstDrv",
					parseInt(retrieveSi(srcdoc, "StatAppWdbePrsDetail", "LstDrvNumFirstdisp")), parseUintvec(retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numsFLstDrv")));
	};

	if (LstDrvAlt) refreshTxt(contcontdoc, "TxtDrv", retrieveCi(srcdoc, "ContInfWdbePrsDetail", "TxtDrv"));

	contcontdoc.getElementById("PupSex").value = retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numFPupSex");

	refreshTxf(contcontdoc, "TxfTel", "", retrieveCi(srcdoc, "ContIacWdbePrsDetail", "TxfTel"), TxfTelActive, false, true);

	refreshTxf(contcontdoc, "TxfEml", "", retrieveCi(srcdoc, "ContIacWdbePrsDetail", "TxfEml"), TxfEmlActive, false, true);

	refreshTxf(contcontdoc, "TxfSal", "", retrieveCi(srcdoc, "ContIacWdbePrsDetail", "TxfSal"), TxfSalActive, false, true);

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbePrsDetail", "srefIxWdbeVExpstate");

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
	setSi(srcdoc, "StatAppWdbePrsDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbePrsDetail", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrsDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbePrsDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbePrsDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbePrsDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbePrsDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrsDetailData", scrJref, "ContIacWdbePrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbePrsDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbePrsDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbePrsDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbePrsDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrsDetailData", scrJref, "ContIacWdbePrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbePrsDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrsDetailData", scrJref, "ContIacWdbePrsDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbePrsDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrsDetailData", scrJref, "ContIacWdbePrsDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbePrsDetailData", "ContIacWdbePrsDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbePrsDetailData", "ContInfWdbePrsDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbePrsDetailData", "FeedFLstDrv", srcdoc)) mask.push("feedFLstDrv");
	if (updateSrcblock(dom, "DpchEngWdbePrsDetailData", "FeedFPupJ", srcdoc)) mask.push("feedFPupJ");
	if (updateSrcblock(dom, "DpchEngWdbePrsDetailData", "FeedFPupSex", srcdoc)) mask.push("feedFPupSex");
	if (updateSrcblock(dom, "DpchEngWdbePrsDetailData", "StatAppWdbePrsDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbePrsDetailData", "StatShrWdbePrsDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbePrsDetailData", "TagWdbePrsDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbePrsDetailData") {
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
			if (blk.nodeName == "DpchEngWdbePrsDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbePrsDetailData") {
				mergeDpchEngData(dom);
				refresh();
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

