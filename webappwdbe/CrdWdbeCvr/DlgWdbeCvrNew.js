/**
  * \file DlgWdbeCvrNew.js
  * web client functionality for dialog DlgWdbeCvrNew
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeCvrNew", "Cpt"));

	initCpt(contdoc, "DetCptCpr", retrieveTi(srcdoc, "TagDlgWdbeCvrNew", "DetCptCpr"));
	initCpt(contdoc, "DetCptBcv", retrieveTi(srcdoc, "TagDlgWdbeCvrNew", "DetCptBcv"));
	initCpt(contdoc, "DetCptVni", retrieveTi(srcdoc, "TagDlgWdbeCvrNew", "DetCptVni"));
	refreshRbu(contdoc, srcdoc, "DetRbuVni", "FeedFDetRbuVni", retrieveCi(srcdoc, "ContIacDlgWdbeCvrNew", "numFDetRbuVni"), true);

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWdbeCvrNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWdbeCvrNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgWdbeCvrNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWdbeCvrNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshPup(contdoc, srcdoc, "DetPupCpr", "", "FeedFDetPupCpr", retrieveCi(srcdoc, "ContIacDlgWdbeCvrNew", "numFDetPupCpr"), true, false);

	refreshPup(contdoc, srcdoc, "DetPupBcv", "", "FeedFDetPupBcv", retrieveCi(srcdoc, "ContIacDlgWdbeCvrNew", "numFDetPupBcv"), true, false);

	setRbuValue(contdoc, "DetRbuVni", retrieveCi(srcdoc, "ContIacDlgWdbeCvrNew", "numFDetRbuVni"), true);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWdbeCvrNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWdbeCvrNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeCvrNewData", scrJref, "ContIacDlgWdbeCvrNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleRbuSelect(_doc, ctlsref, num) {
	setCi(srcdoc, "ContIacDlgWdbeCvrNew", "numF" + ctlsref, "" + num);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeCvrNewData", scrJref, "ContIacDlgWdbeCvrNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrNewData", "ContIacDlgWdbeCvrNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrNewData", "ContInfDlgWdbeCvrNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrNewData", "FeedFDetPupBcv", srcdoc)) mask.push("feedFDetPupBcv");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrNewData", "FeedFDetPupCpr", srcdoc)) mask.push("feedFDetPupCpr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrNewData", "FeedFDetRbuVni", srcdoc)) mask.push("feedFDetRbuVni");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrNewData", "StatAppDlgWdbeCvrNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrNewData", "StatShrDlgWdbeCvrNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrNewData", "TagDlgWdbeCvrNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWdbeCvrNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWdbeCvrNewData") {
		handleDpchEngDlgWdbeCvrNewData(dom);
	};
};

function handleDpchEngDlgWdbeCvrNewData(dom) {
	// IP handleDpchEngDlgWdbeCvrNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeCvrNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeCvrNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

