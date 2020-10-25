/**
  * \file DlgWdbeRlsWrite.js
  * web client functionality for dialog DlgWdbeRlsWrite
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptBso", retrieveTi(srcdoc, "TagDlgWdbeRlsWriteDet", "CptBso"));
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsWrite", "initdone", "true");

	refreshDet();
};

function initCuc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initCuc --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeRlsWriteCuc", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeRlsWriteCuc", "Uld");
	// IP initCuc --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsWrite", "initdone", "true");

	refreshCuc();
};

function initWrc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initWrc --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeRlsWriteWrc", "CptPrg"));
	initBut(contdoc, "ButAut", retrieveTi(srcdoc, "TagDlgWdbeRlsWriteWrc", "ButAut"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeRlsWriteWrc", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeRlsWriteWrc", "ButSto"));
	// IP initWrc --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsWrite", "initdone", "true");

	refreshWrc();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeRlsWriteLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsWrite", "initdone", "true");

	refreshLfi();
};

function initFia() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFia --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeRlsWriteFia", "Dld"));
	// IP initFia --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsWrite", "initdone", "true");

	refreshFia();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeRlsWrite", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeRlsWrite", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeRlsWrite", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 5; num++) {
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

function refreshDet() {
	// IP refreshDet.vars --- BEGIN

	// IP refreshDet.vars --- END

	// IP refreshDet --- BEGIN
	refreshChk(contdoc, "ChkBso", (retrieveCi(srcdoc, "ContIacDlgWdbeRlsWriteDet", "ChkBso") == "true"), true);

	// IP refreshDet --- END
};

function refreshCuc() {
	// IP refreshCuc.vars --- BEGIN
	var UldAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsWriteCuc", "UldAvail") == "true");
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsWriteCuc", "UldActive") == "true");

	// IP refreshCuc.vars --- END

	// IP refreshCuc --- BEGIN
	setCtlAvail(contdoc, "", UldAvail, 25);
	if (UldAvail) {

		if (UldActive) {
			contdoc.getElementById("But").setAttribute("class", "but");
			contdoc.getElementById("But").setAttribute("type", "submit");
		} else {
			contdoc.getElementById("But").setAttribute("class", "butinact");
			contdoc.getElementById("But").setAttribute("type", "reset");
		};

	};

	// IP refreshCuc --- END
};

function refreshWrc() {
	// IP refreshWrc.vars --- BEGIN

	var ButAutActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsWriteWrc", "ButAutActive") == "true");

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsWriteWrc", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsWriteWrc", "ButStoActive") == "true");

	// IP refreshWrc.vars --- END

	// IP refreshWrc --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeRlsWriteWrc", "TxtPrg"));

	refreshBut(contdoc, "ButAut", ButAutActive, false);

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshWrc --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsWriteLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeRlsWriteLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refreshFia() {
	// IP refreshFia.vars --- BEGIN
	var DldAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsWriteFia", "DldAvail") == "true");
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsWriteFia", "DldActive") == "true");

	// IP refreshFia.vars --- END

	// IP refreshFia --- BEGIN
	setCtlAvail(contdoc, "", DldAvail, 25);
	if (DldAvail) {
		refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeRlsWriteFia", "Dld"), DldActive);

	};

	// IP refreshFia --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeRlsWrite", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeRlsWrite", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsWrite", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeRlsWrite" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Det") {
			refreshDet();
		} else if (shortDit == "Cuc") {
			refreshCuc();
		} else if (shortDit == "Wrc") {
			refreshWrc();
		} else if (shortDit == "Lfi") {
			refreshLfi();
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

// --- specific event handlers for app controls of dialog item Det

// --- specific event handlers for app controls of dialog item Cuc

// --- specific event handlers for app controls of dialog item Wrc

// --- specific event handlers for app controls of dialog item Lfi

// --- specific event handlers for app controls of dialog item Fia

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeRlsWriteDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ditshort, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacDlgWdbeRlsWrite" + ditshort, ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsWriteData", scrJref, "ContIacDlgWdbeRlsWrite" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeRlsWrite", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeRlsWrite", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeRlsWrite", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsWriteData", scrJref, "ContIacDlgWdbeRlsWrite");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "ContIacDlgWdbeRlsWrite", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "ContIacDlgWdbeRlsWriteDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "ContInfDlgWdbeRlsWrite", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "ContInfDlgWdbeRlsWriteFia", srcdoc)) mask.push("continffia");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "ContInfDlgWdbeRlsWriteLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "ContInfDlgWdbeRlsWriteWrc", srcdoc)) mask.push("continfwrc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "StatAppDlgWdbeRlsWrite", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "StatShrDlgWdbeRlsWrite", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "StatShrDlgWdbeRlsWriteCuc", srcdoc)) mask.push("statshrcuc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "StatShrDlgWdbeRlsWriteFia", srcdoc)) mask.push("statshrfia");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "StatShrDlgWdbeRlsWriteLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "StatShrDlgWdbeRlsWriteWrc", srcdoc)) mask.push("statshrwrc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "TagDlgWdbeRlsWrite", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "TagDlgWdbeRlsWriteCuc", srcdoc)) mask.push("tagcuc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "TagDlgWdbeRlsWriteDet", srcdoc)) mask.push("tagdet");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "TagDlgWdbeRlsWriteFia", srcdoc)) mask.push("tagfia");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "TagDlgWdbeRlsWriteLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsWriteData", "TagDlgWdbeRlsWriteWrc", srcdoc)) mask.push("tagwrc");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeRlsWriteData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeRlsWriteData") {
		handleDpchEngDlgWdbeRlsWriteData(dom);
	};
};

function handleDpchEngDlgWdbeRlsWriteData(dom) {
	// IP handleDpchEngDlgWdbeRlsWriteData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeRlsWriteData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeRlsWriteData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

