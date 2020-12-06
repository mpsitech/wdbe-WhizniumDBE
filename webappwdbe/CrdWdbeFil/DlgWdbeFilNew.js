// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptFnm", retrieveTi(srcdoc, "TagDlgWdbeFilNewDet", "CptFnm"));
	initCpt(contdoc, "CptRet", retrieveTi(srcdoc, "TagDlgWdbeFilNewDet", "CptRet"));
	refreshPup(contdoc, srcdoc, "PupRet", "", "FeedFDetPupRet", retrieveCi(srcdoc, "ContIacDlgWdbeFilNewDet", "numFPupRet"), true, false);
	initCpt(contdoc, "CptReu", retrieveTi(srcdoc, "TagDlgWdbeFilNewDet", "CptReu"));
	initCpt(contdoc, "CptCnt", retrieveTi(srcdoc, "TagDlgWdbeFilNewDet", "CptCnt"));
	initCpt(contdoc, "CptMim", retrieveTi(srcdoc, "TagDlgWdbeFilNewDet", "CptMim"));
	initCpt(contdoc, "CptCmt", retrieveTi(srcdoc, "TagDlgWdbeFilNewDet", "CptCmt"));
	initBut(contdoc, "ButCre", retrieveTi(srcdoc, "TagDlgWdbeFilNewDet", "ButCre"));
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgWdbeFilNew", "initdone", "true");

	refreshDet();
};

function initFil() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFil --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeFilNewFil", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeFilNewFil", "Uld");
	// IP initFil --- END

	setSi(srcdoc, "StatAppDlgWdbeFilNew", "initdone", "true");

	refreshFil();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeFilNew", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeFilNew", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeFilNew", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 2; num++) {
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

	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWdbeFilNewDet", "ButCreActive") == "true");

	// IP refreshDet.vars --- END

	// IP refreshDet --- BEGIN
	refreshTxf(contdoc, "TxfFnm", "", retrieveCi(srcdoc, "ContIacDlgWdbeFilNewDet", "TxfFnm"), true, false, true);

	contdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacDlgWdbeFilNewDet", "numFPupRet");

	refreshTxf(contdoc, "TxfReu", "", retrieveCi(srcdoc, "ContIacDlgWdbeFilNewDet", "TxfReu"), true, false, true);

	refreshPup(contdoc, srcdoc, "PupCnt", "", "FeedFDetPupCnt", retrieveCi(srcdoc, "ContIacDlgWdbeFilNewDet", "numFPupCnt"), true, false);

	refreshPup(contdoc, srcdoc, "PupMim", "", "FeedFDetPupMim", retrieveCi(srcdoc, "ContIacDlgWdbeFilNewDet", "numFPupMim"), true, false);

	refreshTxft(contdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacDlgWdbeFilNewDet", "TxfCmt"), true, false, true);

	refreshBut(contdoc, "ButCre", ButCreActive, false);

	// IP refreshDet --- END
};

function refreshFil() {
	// IP refreshFil.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeFilNewFil", "UldActive") == "true");

	// IP refreshFil.vars --- END

	// IP refreshFil --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshFil --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeFilNew", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeFilNew", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeFilNew", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeFilNew" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Det") {
			refreshDet();
		} else if (shortDit == "Fil") {
			refreshFil();
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

// --- specific event handlers for app controls of dialog item Fil

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeFilNewDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeFilNew", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeFilNew", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeFilNew", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeFilNewData", scrJref, "ContIacDlgWdbeFilNew");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handlePupChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWdbeFilNew" + ditshort, "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeFilNewData", scrJref, "ContIacDlgWdbeFilNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ditshort, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWdbeFilNew" + ditshort, ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeFilNewData", scrJref, "ContIacDlgWdbeFilNew" + ditshort);
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWdbeFilNew" + ditshort, ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeFilNewData", scrJref, "ContIacDlgWdbeFilNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ditshort, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ditshort, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacDlgWdbeFilNew" + ditshort, ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeFilNewData", scrJref, "ContIacDlgWdbeFilNew" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "ContIacDlgWdbeFilNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "ContIacDlgWdbeFilNewDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "ContInfDlgWdbeFilNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "FeedFDetPupCnt", srcdoc)) mask.push("feedFDetPupCnt");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "FeedFDetPupMim", srcdoc)) mask.push("feedFDetPupMim");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "FeedFDetPupRet", srcdoc)) mask.push("feedFDetPupRet");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "StatAppDlgWdbeFilNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "StatShrDlgWdbeFilNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "StatShrDlgWdbeFilNewDet", srcdoc)) mask.push("statshrdet");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "StatShrDlgWdbeFilNewFil", srcdoc)) mask.push("statshrfil");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "TagDlgWdbeFilNew", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "TagDlgWdbeFilNewDet", srcdoc)) mask.push("tagdet");
	if (updateSrcblock(dom, "DpchEngDlgWdbeFilNewData", "TagDlgWdbeFilNewFil", srcdoc)) mask.push("tagfil");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeFilNewData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeFilNewData") {
		handleDpchEngDlgWdbeFilNewData(dom);
	};
};

function handleDpchEngDlgWdbeFilNewData(dom) {
	// IP handleDpchEngDlgWdbeFilNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeFilNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeFilNewData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
