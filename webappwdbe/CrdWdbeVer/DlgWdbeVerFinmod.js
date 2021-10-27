// IP cust --- INSERT

// --- view initialization and refresh
function initFnm() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFnm --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeVerFinmodFnm", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeVerFinmodFnm", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeVerFinmodFnm", "ButSto"));
	// IP initFnm --- END

	setSi(srcdoc, "StatAppDlgWdbeVerFinmod", "initdone", "true");

	refreshFnm();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeVerFinmodLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWdbeVerFinmod", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeVerFinmod", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeVerFinmod", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeVerFinmod", "numFDse"));

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

function refreshFnm() {
	// IP refreshFnm.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerFinmodFnm", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerFinmodFnm", "ButStoActive") == "true");

	// IP refreshFnm.vars --- END

	// IP refreshFnm --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeVerFinmodFnm", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshFnm --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerFinmodLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeVerFinmodLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeVerFinmod", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeVerFinmod", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerFinmod", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeVerFinmod" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Fnm") {
			refreshFnm();
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

// --- specific event handlers for app controls of dialog item Fnm

// --- specific event handlers for app controls of dialog item Lfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeVerFinmodDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeVerFinmod", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeVerFinmod", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeVerFinmod", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeVerFinmodData", scrJref, "ContIacDlgWdbeVerFinmod");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "ContIacDlgWdbeVerFinmod", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "ContInfDlgWdbeVerFinmod", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "ContInfDlgWdbeVerFinmodFnm", srcdoc)) mask.push("continffnm");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "ContInfDlgWdbeVerFinmodLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "StatAppDlgWdbeVerFinmod", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "StatShrDlgWdbeVerFinmod", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "StatShrDlgWdbeVerFinmodFnm", srcdoc)) mask.push("statshrfnm");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "StatShrDlgWdbeVerFinmodLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "TagDlgWdbeVerFinmod", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "TagDlgWdbeVerFinmodFnm", srcdoc)) mask.push("tagfnm");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerFinmodData", "TagDlgWdbeVerFinmodLfi", srcdoc)) mask.push("taglfi");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeVerFinmodData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeVerFinmodData") {
		handleDpchEngDlgWdbeVerFinmodData(dom);
	};
};

function handleDpchEngDlgWdbeVerFinmodData(dom) {
	// IP handleDpchEngDlgWdbeVerFinmodData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeVerFinmodData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeVerFinmodData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
