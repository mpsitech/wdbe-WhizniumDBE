/**
  * \file DlgWdbeNavMnglic.js
  * web client functionality for dialog DlgWdbeNavMnglic
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "Cpt"));

	initCpt(contdoc, "DetHdgSrv", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetHdgSrv"));
	initCpt(contdoc, "DetCptSip", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetCptSip"));
	initCpt(contdoc, "DetCptScp", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetCptScp"));
	initBut(contdoc, "DetButScn", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetButScn"));
	initBut(contdoc, "DetButSdc", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetButSdc"));
	initCpt(contdoc, "DetCptFis", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetCptFis"));
	refreshPup(contdoc, srcdoc, "DetPupFis", "", "FeedFDetPupFis", retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numFDetPupFis"), true, false);
	initCpt(contdoc, "DetCptLcs", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetCptLcs"));
	initBut(contdoc, "DetButAct", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetButAct"));
	initCpt(contdoc, "DetHdgLic", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetHdgLic"));
	initCpt(contdoc, "DetCptLsr", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetCptLsr"));
	initCpt(contdoc, "DetCptLar", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetCptLar"));
	initCpt(contdoc, "DetCptLst", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetCptLst"));
	initCpt(contdoc, "DetCptLex", retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "DetCptLex"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeNavMnglic", "ButDne"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var DetButActActive = (retrieveSi(srcdoc, "StatShrDlgWdbeNavMnglic", "DetButActActive") == "true");

	// IP refresh.vars --- END

	// IP refresh --- BEGIN

	refreshTxt(contdoc, "DetTxtSip", retrieveCi(srcdoc, "ContInfDlgWdbeNavMnglic", "DetTxtSip"));

	refreshTxt(contdoc, "DetTxtScp", retrieveCi(srcdoc, "ContInfDlgWdbeNavMnglic", "DetTxtScp"));

	contdoc.getElementById("DetPupFis").value = retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numFDetPupFis");
	refreshChk(contdoc, "DetChkFis", (retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "DetChkFis") == "true"), true);

	refreshLst(contdoc.getElementById("DetLstLcs").contentWindow.document, srcdoc, 2, true, false, "FeedFDetLstLcs",
				parseInt(retrieveSi(srcdoc, "StatAppDlgWdbeNavMnglic", "DetLstLcsNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numFDetLstLcs"))]);

	refreshBut(contdoc, "DetButAct", DetButActActive, false);

	refreshTxt(contdoc, "DetTxtLsr", retrieveCi(srcdoc, "ContInfDlgWdbeNavMnglic", "DetTxtLsr"));

	refreshTxt(contdoc, "DetTxtLar", retrieveCi(srcdoc, "ContInfDlgWdbeNavMnglic", "DetTxtLar"));

	refreshTxt(contdoc, "DetTxtLst", retrieveCi(srcdoc, "ContInfDlgWdbeNavMnglic", "DetTxtLst"));

	refreshTxt(contdoc, "DetTxtLex", retrieveCi(srcdoc, "ContInfDlgWdbeNavMnglic", "DetTxtLex"));

	// IP refresh --- END
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

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
	lstdoc.getElementById("tdLsb").onmousemove = contdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWdbeNavMnglicDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacDlgWdbeNavMnglic", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeNavMnglicData", scrJref, "ContIacDlgWdbeNavMnglic");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgWdbeNavMnglic", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppDlgWdbeNavMnglic", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeNavMnglicData", scrJref, "ContIacDlgWdbeNavMnglic");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppDlgWdbeNavMnglic", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppDlgWdbeNavMnglic", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWdbeNavMnglic", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeNavMnglicData", scrJref, "ContIacDlgWdbeNavMnglic");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeNavMnglicData", "ContIacDlgWdbeNavMnglic", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeNavMnglicData", "ContInfDlgWdbeNavMnglic", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeNavMnglicData", "FeedFDetLstLcs", srcdoc)) mask.push("feedFDetLstLcs");
	if (updateSrcblock(dom, "DpchEngDlgWdbeNavMnglicData", "FeedFDetPupFis", srcdoc)) mask.push("feedFDetPupFis");
	if (updateSrcblock(dom, "DpchEngDlgWdbeNavMnglicData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeNavMnglicData", "StatAppDlgWdbeNavMnglic", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeNavMnglicData", "StatShrDlgWdbeNavMnglic", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeNavMnglicData", "TagDlgWdbeNavMnglic", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWdbeNavMnglicData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWdbeNavMnglicData") {
		handleDpchEngDlgWdbeNavMnglicData(dom);
	};
};

function handleDpchEngDlgWdbeNavMnglicData(dom) {
	// IP handleDpchEngDlgWdbeNavMnglicData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeNavMnglicData") {
				mergeDpchEngData(dom);
				init();
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

			} else if (blk.nodeName == "DpchEngWdbeAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wdbe:DpchEngWdbeAlert/wdbe:scrJref"),
							retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:ContInfWdbeAlert"),
							retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:FeedFMcbAlert"));;

			} else if (blk.nodeName == "DpchEngDlgWdbeNavMnglicData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

