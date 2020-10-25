/**
  * \file DlgWdbeCprNew.js
  * web client functionality for dialog DlgWdbeCprNew
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

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeCprNew", "Cpt"));

	initCpt(contdoc, "DetCptTyp", retrieveTi(srcdoc, "TagDlgWdbeCprNew", "DetCptTyp"));
	refreshPup(contdoc, srcdoc, "DetPupTyp", "", "FeedFDetPupTyp", retrieveCi(srcdoc, "ContIacDlgWdbeCprNew", "numFDetPupTyp"), true, false);
	initCpt(contdoc, "DetCptSrf", retrieveTi(srcdoc, "TagDlgWdbeCprNew", "DetCptSrf"));
	initCpt(contdoc, "DetCptTit", retrieveTi(srcdoc, "TagDlgWdbeCprNew", "DetCptTit"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWdbeCprNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWdbeCprNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgWdbeCprNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWdbeCprNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	contdoc.getElementById("DetPupTyp").value = retrieveCi(srcdoc, "ContIacDlgWdbeCprNew", "numFDetPupTyp");

	refreshTxf(contdoc, "DetTxfSrf", "s", retrieveCi(srcdoc, "ContIacDlgWdbeCprNew", "DetTxfSrf"), true, false, true);

	refreshTxf(contdoc, "DetTxfTit", "", retrieveCi(srcdoc, "ContIacDlgWdbeCprNew", "DetTxfTit"), true, false, true);

	refreshBut(ftrdoc, "ButCnc", ButCncActive, false);
	refreshBut(ftrdoc, "ButCre", ButCreActive, false);
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

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWdbeCprNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWdbeCprNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeCprNewData", scrJref, "ContIacDlgWdbeCprNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWdbeCprNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeCprNewData", scrJref, "ContIacDlgWdbeCprNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWdbeCprNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeCprNewData", scrJref, "ContIacDlgWdbeCprNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeCprNewData", "ContIacDlgWdbeCprNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCprNewData", "ContInfDlgWdbeCprNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCprNewData", "FeedFDetPupTyp", srcdoc)) mask.push("feedFDetPupTyp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCprNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCprNewData", "StatAppDlgWdbeCprNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCprNewData", "StatShrDlgWdbeCprNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCprNewData", "TagDlgWdbeCprNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWdbeCprNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWdbeCprNewData") {
		handleDpchEngDlgWdbeCprNewData(dom);
	};
};

function handleDpchEngDlgWdbeCprNewData(dom) {
	// IP handleDpchEngDlgWdbeCprNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeCprNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeCprNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

