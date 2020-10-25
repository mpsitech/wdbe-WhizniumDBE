/**
  * \file DlgWdbeCvrWrite.js
  * web client functionality for dialog DlgWdbeCvrWrite
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initCuc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initCuc --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeCvrWriteCuc", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeCvrWriteCuc", "Uld");
	// IP initCuc --- END

	setSi(srcdoc, "StatAppDlgWdbeCvrWrite", "initdone", "true");

	refreshCuc();
};

function initWrc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initWrc --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeCvrWriteWrc", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeCvrWriteWrc", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeCvrWriteWrc", "ButSto"));
	// IP initWrc --- END

	setSi(srcdoc, "StatAppDlgWdbeCvrWrite", "initdone", "true");

	refreshWrc();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFia --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeCvrWriteFia", "Dld"));
	// IP initFia --- END

	setSi(srcdoc, "StatAppDlgWdbeCvrWrite", "initdone", "true");

	refreshFia();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeCvrWrite", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeCvrWrite", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeCvrWrite", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 3; num++) {
		sref = retrieveValue(srcdoc, "//wdbe:FeedFDse/wdbe:Fi[@num='" + num + "']/wdbe:sref");
		Title = retrieveValue(srcdoc, "//wdbe:FeedFDse/wdbe:Fi[@num='" + num + "']/wdbe:tit1");

		myspan = hdrdoc.getElementById("Cpt" + sref);
		myrect = hdrdoc.getElementById("Dit" + sref);

		setTextContent(hdrdoc, myspan, Title);

		if (num == numFDse) {
			myspan.setAttribute("class", "hdr_ditsel");
			myrect.setAttribute("class", "hdr_ditsels");
		} else {
			myspan.setAttribute("class", "hdr_dit");
			myspan.setAttribute("onclick", "handleDseSelect(" + num + ")");
			myrect.setAttribute("class", "hdr_dits");
			myrect.setAttribute("onclick", "handleDseSelect(" + num + ")");
		};
	};
};

function refreshCuc() {
	// IP refreshCuc.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeCvrWriteCuc", "UldActive") == "true");

	// IP refreshCuc.vars --- END

	// IP refreshCuc --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshCuc --- END
};

function refreshWrc() {
	// IP refreshWrc.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeCvrWriteWrc", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeCvrWriteWrc", "ButStoActive") == "true");

	// IP refreshWrc.vars --- END

	// IP refreshWrc --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeCvrWriteWrc", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshWrc --- END
};

function refreshFia() {
	// IP refreshFia.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeCvrWriteFia", "DldActive") == "true");

	// IP refreshFia.vars --- END

	// IP refreshFia --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeCvrWriteFia", "Dld"), DldActive);

	// IP refreshFia --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeCvrWrite", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeCvrWrite", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeCvrWrite", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeCvrWrite" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Cuc") {
			refreshCuc();
		} else if (shortDit == "Wrc") {
			refreshWrc();
		} else if (shortDit == "Fia") {
			refreshFia();
		};
	};

	// IP refresh --- BEGIN
	refreshBut(ftrdoc, "ButDne", ButDneActive, false);
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

// --- specific event handlers for app controls of dialog item Cuc

// --- specific event handlers for app controls of dialog item Wrc

// --- specific event handlers for app controls of dialog item Fia

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeCvrWriteDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeCvrWrite", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeCvrWrite", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeCvrWrite", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeCvrWriteData", scrJref, "ContIacDlgWdbeCvrWrite");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "ContIacDlgWdbeCvrWrite", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "ContInfDlgWdbeCvrWrite", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "ContInfDlgWdbeCvrWriteFia", srcdoc)) mask.push("continffia");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "ContInfDlgWdbeCvrWriteWrc", srcdoc)) mask.push("continfwrc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "StatAppDlgWdbeCvrWrite", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "StatShrDlgWdbeCvrWrite", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "StatShrDlgWdbeCvrWriteCuc", srcdoc)) mask.push("statshrcuc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "StatShrDlgWdbeCvrWriteFia", srcdoc)) mask.push("statshrfia");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "StatShrDlgWdbeCvrWriteWrc", srcdoc)) mask.push("statshrwrc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "TagDlgWdbeCvrWrite", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "TagDlgWdbeCvrWriteCuc", srcdoc)) mask.push("tagcuc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "TagDlgWdbeCvrWriteFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgWdbeCvrWriteData", "TagDlgWdbeCvrWriteWrc", srcdoc)) mask.push("tagwrc");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeCvrWriteData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeCvrWriteData") {
		handleDpchEngDlgWdbeCvrWriteData(dom);
	};
};

function handleDpchEngDlgWdbeCvrWriteData(dom) {
	// IP handleDpchEngDlgWdbeCvrWriteData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeCvrWriteData") {
				mergeDpchEngData(dom);
				init();
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;

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

			} else if (blk.nodeName == "DpchEngDlgWdbeCvrWriteData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

