// IP cust --- INSERT

// --- view initialization and refresh
function initIfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initIfi --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeVerMdlstrIfi", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeVerMdlstrIfi", "Uld");
	// IP initIfi --- END

	setSi(srcdoc, "StatAppDlgWdbeVerMdlstr", "initdone", "true");

	refreshIfi();
};

function initImp() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initImp --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeVerMdlstrImp", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeVerMdlstrImp", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeVerMdlstrImp", "ButSto"));
	// IP initImp --- END

	setSi(srcdoc, "StatAppDlgWdbeVerMdlstr", "initdone", "true");

	refreshImp();
};

function initPpr() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initPpr --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeVerMdlstrPpr", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeVerMdlstrPpr", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeVerMdlstrPpr", "ButSto"));
	// IP initPpr --- END

	setSi(srcdoc, "StatAppDlgWdbeVerMdlstr", "initdone", "true");

	refreshPpr();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeVerMdlstrLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWdbeVerMdlstr", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeVerMdlstr", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeVerMdlstr", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeVerMdlstr", "numFDse"));

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

function refreshIfi() {
	// IP refreshIfi.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerMdlstrIfi", "UldActive") == "true");

	// IP refreshIfi.vars --- END

	// IP refreshIfi --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshIfi --- END
};

function refreshImp() {
	// IP refreshImp.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerMdlstrImp", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerMdlstrImp", "ButStoActive") == "true");

	// IP refreshImp.vars --- END

	// IP refreshImp --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeVerMdlstrImp", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshImp --- END
};

function refreshPpr() {
	// IP refreshPpr.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerMdlstrPpr", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerMdlstrPpr", "ButStoActive") == "true");

	// IP refreshPpr.vars --- END

	// IP refreshPpr --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeVerMdlstrPpr", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshPpr --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerMdlstrLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeVerMdlstrLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeVerMdlstr", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeVerMdlstr", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerMdlstr", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeVerMdlstr" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Ifi") {
			refreshIfi();
		} else if (shortDit == "Imp") {
			refreshImp();
		} else if (shortDit == "Ppr") {
			refreshPpr();
		} else if (shortDit == "Lfi") {
			refreshLfi();
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

// --- specific event handlers for app controls of dialog item Ifi

// --- specific event handlers for app controls of dialog item Imp

// --- specific event handlers for app controls of dialog item Ppr

// --- specific event handlers for app controls of dialog item Lfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeVerMdlstrDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeVerMdlstr", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeVerMdlstr", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeVerMdlstr", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeVerMdlstrData", scrJref, "ContIacDlgWdbeVerMdlstr");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "ContIacDlgWdbeVerMdlstr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "ContInfDlgWdbeVerMdlstr", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "ContInfDlgWdbeVerMdlstrImp", srcdoc)) mask.push("continfimp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "ContInfDlgWdbeVerMdlstrLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "ContInfDlgWdbeVerMdlstrPpr", srcdoc)) mask.push("continfppr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "StatAppDlgWdbeVerMdlstr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "StatShrDlgWdbeVerMdlstr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "StatShrDlgWdbeVerMdlstrIfi", srcdoc)) mask.push("statshrifi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "StatShrDlgWdbeVerMdlstrImp", srcdoc)) mask.push("statshrimp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "StatShrDlgWdbeVerMdlstrLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "StatShrDlgWdbeVerMdlstrPpr", srcdoc)) mask.push("statshrppr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "TagDlgWdbeVerMdlstr", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "TagDlgWdbeVerMdlstrIfi", srcdoc)) mask.push("tagifi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "TagDlgWdbeVerMdlstrImp", srcdoc)) mask.push("tagimp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "TagDlgWdbeVerMdlstrLfi", srcdoc)) mask.push("taglfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerMdlstrData", "TagDlgWdbeVerMdlstrPpr", srcdoc)) mask.push("tagppr");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeVerMdlstrData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeVerMdlstrData") {
		handleDpchEngDlgWdbeVerMdlstrData(dom);
	};
};

function handleDpchEngDlgWdbeVerMdlstrData(dom) {
	// IP handleDpchEngDlgWdbeVerMdlstrData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeVerMdlstrData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeVerMdlstrData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
