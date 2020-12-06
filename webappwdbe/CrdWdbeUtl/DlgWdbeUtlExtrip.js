// IP cust --- INSERT

// --- view initialization and refresh
function initSrc() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initSrc --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeUtlExtripSrc", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeUtlExtripSrc", "Uld");
	// IP initSrc --- END

	setSi(srcdoc, "StatAppDlgWdbeUtlExtrip", "initdone", "true");

	refreshSrc();
};

function initExt() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initExt --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeUtlExtripExt", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeUtlExtripExt", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeUtlExtripExt", "ButSto"));
	// IP initExt --- END

	setSi(srcdoc, "StatAppDlgWdbeUtlExtrip", "initdone", "true");

	refreshExt();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeUtlExtripLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWdbeUtlExtrip", "initdone", "true");

	refreshLfi();
};

function initRes() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initRes --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeUtlExtripRes", "Dld"));
	// IP initRes --- END

	setSi(srcdoc, "StatAppDlgWdbeUtlExtrip", "initdone", "true");

	refreshRes();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeUtlExtrip", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeUtlExtrip", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeUtlExtrip", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 4; num++) {
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
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlExtripSrc", "UldActive") == "true");

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

function refreshExt() {
	// IP refreshExt.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlExtripExt", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlExtripExt", "ButStoActive") == "true");

	// IP refreshExt.vars --- END

	// IP refreshExt --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeUtlExtripExt", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshExt --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlExtripLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeUtlExtripLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refreshRes() {
	// IP refreshRes.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlExtripRes", "DldActive") == "true");

	// IP refreshRes.vars --- END

	// IP refreshRes --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeUtlExtripRes", "Dld"), DldActive);

	// IP refreshRes --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeUtlExtrip", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeUtlExtrip", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeUtlExtrip", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeUtlExtrip" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Src") {
			refreshSrc();
		} else if (shortDit == "Ext") {
			refreshExt();
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

// --- specific event handlers for app controls of dialog item Ext

// --- specific event handlers for app controls of dialog item Lfi

// --- specific event handlers for app controls of dialog item Res

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeUtlExtripDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeUtlExtrip", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeUtlExtrip", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeUtlExtrip", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeUtlExtripData", scrJref, "ContIacDlgWdbeUtlExtrip");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "ContIacDlgWdbeUtlExtrip", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "ContInfDlgWdbeUtlExtrip", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "ContInfDlgWdbeUtlExtripExt", srcdoc)) mask.push("continfext");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "ContInfDlgWdbeUtlExtripLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "ContInfDlgWdbeUtlExtripRes", srcdoc)) mask.push("continfres");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "StatAppDlgWdbeUtlExtrip", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "StatShrDlgWdbeUtlExtrip", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "StatShrDlgWdbeUtlExtripExt", srcdoc)) mask.push("statshrext");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "StatShrDlgWdbeUtlExtripLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "StatShrDlgWdbeUtlExtripRes", srcdoc)) mask.push("statshrres");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "StatShrDlgWdbeUtlExtripSrc", srcdoc)) mask.push("statshrsrc");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "TagDlgWdbeUtlExtrip", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "TagDlgWdbeUtlExtripExt", srcdoc)) mask.push("tagext");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "TagDlgWdbeUtlExtripLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "TagDlgWdbeUtlExtripRes", srcdoc)) mask.push("tagres");
	if (updateSrcblock(dom, "DpchEngDlgWdbeUtlExtripData", "TagDlgWdbeUtlExtripSrc", srcdoc)) mask.push("tagsrc");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeUtlExtripData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeUtlExtripData") {
		handleDpchEngDlgWdbeUtlExtripData(dom);
	};
};

function handleDpchEngDlgWdbeUtlExtripData(dom) {
	// IP handleDpchEngDlgWdbeUtlExtripData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeUtlExtripData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeUtlExtripData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
