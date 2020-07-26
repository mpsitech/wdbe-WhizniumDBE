/**
  * \file DlgWdbeUtlMrgip.js
  * web client functionality for dialog DlgWdbeUtlMrgip
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- view initialization and refresh
function initSrc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initSrc --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeUtlMrgipSrc", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeUtlMrgipSrc", "Uld");
	// IP initSrc --- END

	setSi(srcdoc, "StatAppDlgWdbeUtlMrgip", "initdone", "true");

	refreshSrc();
};

function initTrg() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initTrg --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeUtlMrgipTrg", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeUtlMrgipTrg", "Uld");
	// IP initTrg --- END

	setSi(srcdoc, "StatAppDlgWdbeUtlMrgip", "initdone", "true");

	refreshTrg();
};

function initMrg() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initMrg --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeUtlMrgipMrg", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeUtlMrgipMrg", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeUtlMrgipMrg", "ButSto"));
	// IP initMrg --- END

	setSi(srcdoc, "StatAppDlgWdbeUtlMrgip", "initdone", "true");

	refreshMrg();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeUtlMrgipLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWdbeUtlMrgip", "initdone", "true");

	refreshLfi();
};

function initRes() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initRes --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeUtlMrgipRes", "Dld"));
	// IP initRes --- END

	setSi(srcdoc, "StatAppDlgWdbeUtlMrgip", "initdone", "true");

	refreshRes();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeUtlMrgip", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeUtlMrgip", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeUtlMrgip", "numFDse"));

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

function refreshSrc() {
	// IP refreshSrc.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlMrgipSrc", "UldActive") == "true");

	// IP refreshSrc.vars --- END

	// IP refreshSrc --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshSrc --- END
};

function refreshTrg() {
	// IP refreshTrg.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlMrgipTrg", "UldActive") == "true");

	// IP refreshTrg.vars --- END

	// IP refreshTrg --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshTrg --- END
};

function refreshMrg() {
	// IP refreshMrg.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlMrgipMrg", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlMrgipMrg", "ButStoActive") == "true");

	// IP refreshMrg.vars --- END

	// IP refreshMrg --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeUtlMrgipMrg", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshMrg --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlMrgipLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeUtlMrgipLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refreshRes() {
	// IP refreshRes.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlMrgipRes", "DldActive") == "true");

	// IP refreshRes.vars --- END

	// IP refreshRes --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeUtlMrgipRes", "Dld"), DldActive);

	// IP refreshRes --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeUtlMrgip", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeUtlMrgip", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlMrgip", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeUtlMrgip" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Src") {
			refreshSrc();
		} else if (shortDit == "Trg") {
			refreshTrg();
		} else if (shortDit == "Mrg") {
			refreshMrg();
		} else if (shortDit == "Lfi") {
			refreshLfi();
		} else if (shortDit == "Res") {
			refreshRes();
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

// --- specific event handlers for app controls of dialog item Src

// --- specific event handlers for app controls of dialog item Trg

// --- specific event handlers for app controls of dialog item Mrg

// --- specific event handlers for app controls of dialog item Lfi

// --- specific event handlers for app controls of dialog item Res

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeUtlMrgipDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeUtlMrgip", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeUtlMrgip", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeUtlMrgip", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeUtlMrgipData", scrJref, "ContIacDlgWdbeUtlMrgip");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "ContIacDlgWdbeUtlMrgip", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "ContInfDlgWdbeUtlMrgip", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "ContInfDlgWdbeUtlMrgipLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "ContInfDlgWdbeUtlMrgipMrg", srcdoc)) mask.push("continfmrg");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "ContInfDlgWdbeUtlMrgipRes", srcdoc)) mask.push("continfres");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "StatAppDlgWdbeUtlMrgip", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "StatShrDlgWdbeUtlMrgip", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "StatShrDlgWdbeUtlMrgipLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "StatShrDlgWdbeUtlMrgipMrg", srcdoc)) mask.push("statshrmrg");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "StatShrDlgWdbeUtlMrgipRes", srcdoc)) mask.push("statshrres");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "StatShrDlgWdbeUtlMrgipSrc", srcdoc)) mask.push("statshrsrc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "StatShrDlgWdbeUtlMrgipTrg", srcdoc)) mask.push("statshrtrg");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "TagDlgWdbeUtlMrgip", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "TagDlgWdbeUtlMrgipLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "TagDlgWdbeUtlMrgipMrg", srcdoc)) mask.push("tagmrg");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "TagDlgWdbeUtlMrgipRes", srcdoc)) mask.push("tagres");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "TagDlgWdbeUtlMrgipSrc", srcdoc)) mask.push("tagsrc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlMrgipData", "TagDlgWdbeUtlMrgipTrg", srcdoc)) mask.push("tagtrg");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeUtlMrgipData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeUtlMrgipData") {
		handleDpchEngDlgWdbeUtlMrgipData(dom);
	};
};

function handleDpchEngDlgWdbeUtlMrgipData(dom) {
	// IP handleDpchEngDlgWdbeUtlMrgipData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeUtlMrgipData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeUtlMrgipData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

