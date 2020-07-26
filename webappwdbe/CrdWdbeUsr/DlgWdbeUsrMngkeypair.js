/**
  * \file DlgWdbeUsrMngkeypair.js
  * web client functionality for dialog DlgWdbeUsrMngkeypair
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

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeUsrMngkeypair", "Cpt"));

	initCpt(contdoc, "DetCptSte", retrieveTi(srcdoc, "TagDlgWdbeUsrMngkeypair", "DetCptSte"));
	setTextContent(contdoc, contdoc.getElementById("DetDld"), retrieveTi(srcdoc, "TagDlgWdbeUsrMngkeypair", "DetDld"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeUsrMngkeypair", "ButDne"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var DetButDelAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeUsrMngkeypair", "DetButDelAvail") == "true");
	var DetButGenAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeUsrMngkeypair", "DetButGenAvail") == "true");
	var ButdelbutgenAvail = (DetButDelAvail || DetButGenAvail);

	var DetDldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUsrMngkeypair", "DetDldActive") == "true");

	var mytd, first;

	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshTxt(contdoc, "DetTxtSte", retrieveCi(srcdoc, "ContInfDlgWdbeUsrMngkeypair", "DetTxtSte"));

	setCtlAvail(contdoc, "Butdelbutgen", ButdelbutgenAvail, 25);
	if (ButdelbutgenAvail) {
		if ((DetButDelAvail == !contdoc.getElementById("DetButDel")) || (DetButGenAvail == !contdoc.getElementById("DetButGen"))) {
			mytd = contdoc.getElementById("dynButdelbutgen");
			clearElem(mytd);

			first = true;

			if (DetButDelAvail) {
				if (first) first = false;
				else mytd.appendChild(contdoc.createTextNode("\u00a0\u00a0"));
				mytd.appendChild(makeSpanBut(contdoc, "DetButDel", retrieveTi(srcdoc, "TagDlgWdbeUsrMngkeypair", "DetButDel")));
			};

			if (DetButGenAvail) {
				if (first) first = false;
				else mytd.appendChild(contdoc.createTextNode("\u00a0\u00a0"));
				mytd.appendChild(makeSpanBut(contdoc, "DetButGen", retrieveTi(srcdoc, "TagDlgWdbeUsrMngkeypair", "DetButGen")));
			};
		};

	};

	refreshDld(contdoc, "DetDld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeUsrMngkeypair", "DetDld"), DetDldActive);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWdbeUsrMngkeypairDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeUsrMngkeypairData", "ContInfDlgWdbeUsrMngkeypair", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUsrMngkeypairData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUsrMngkeypairData", "StatAppDlgWdbeUsrMngkeypair", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUsrMngkeypairData", "StatShrDlgWdbeUsrMngkeypair", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUsrMngkeypairData", "TagDlgWdbeUsrMngkeypair", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWdbeUsrMngkeypairData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWdbeUsrMngkeypairData") {
		handleDpchEngDlgWdbeUsrMngkeypairData(dom);
	};
};

function handleDpchEngDlgWdbeUsrMngkeypairData(dom) {
	// IP handleDpchEngDlgWdbeUsrMngkeypairData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeUsrMngkeypairData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeUsrMngkeypairData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

