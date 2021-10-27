// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeVerGenfst", "Cpt"));

	initCpt(contdoc, "GfsCptPrg", retrieveTi(srcdoc, "TagDlgWdbeVerGenfst", "GfsCptPrg"));
	initBut(contdoc, "GfsButRun", retrieveTi(srcdoc, "TagDlgWdbeVerGenfst", "GfsButRun"));
	initBut(contdoc, "GfsButSto", retrieveTi(srcdoc, "TagDlgWdbeVerGenfst", "GfsButSto"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeVerGenfst", "ButDne"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var GfsButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerGenfst", "GfsButRunActive") == "true");
	var GfsButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerGenfst", "GfsButStoActive") == "true");

	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerGenfst", "ButDneActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshTxtt(contdoc, "GfsTxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeVerGenfst", "GfsTxtPrg"));

	refreshBut(contdoc, "GfsButRun", GfsButRunActive, false);
	refreshBut(contdoc, "GfsButSto", GfsButStoActive, false);

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

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWdbeVerGenfstDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeVerGenfstData", "ContInfDlgWdbeVerGenfst", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerGenfstData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerGenfstData", "StatAppDlgWdbeVerGenfst", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerGenfstData", "StatShrDlgWdbeVerGenfst", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerGenfstData", "TagDlgWdbeVerGenfst", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWdbeVerGenfstData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWdbeVerGenfstData") {
		handleDpchEngDlgWdbeVerGenfstData(dom);
	};
};

function handleDpchEngDlgWdbeVerGenfstData(dom) {
	// IP handleDpchEngDlgWdbeVerGenfstData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeVerGenfstData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeVerGenfstData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};
