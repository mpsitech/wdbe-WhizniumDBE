// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbePrjNew", "Cpt"));

	initCpt(contdoc, "DetCptSho", retrieveTi(srcdoc, "TagDlgWdbePrjNew", "DetCptSho"));
	initCpt(contdoc, "DetCptTit", retrieveTi(srcdoc, "TagDlgWdbePrjNew", "DetCptTit"));
	initBut(contdoc, "DetButAut", retrieveTi(srcdoc, "TagDlgWdbePrjNew", "DetButAut"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWdbePrjNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWdbePrjNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var DetButAutActive = (retrieveSi(srcdoc, "StatShrDlgWdbePrjNew", "DetButAutActive") == "true");

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgWdbePrjNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWdbePrjNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshTxf(contdoc, "DetTxfSho", "s", retrieveCi(srcdoc, "ContIacDlgWdbePrjNew", "DetTxfSho"), true, false, true);

	refreshTxf(contdoc, "DetTxfTit", "", retrieveCi(srcdoc, "ContIacDlgWdbePrjNew", "DetTxfTit"), true, false, true);

	refreshBut(contdoc, "DetButAut", DetButAutActive, false);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWdbePrjNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWdbePrjNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbePrjNewData", scrJref, "ContIacDlgWdbePrjNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWdbePrjNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbePrjNewData", scrJref, "ContIacDlgWdbePrjNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbePrjNewData", "ContIacDlgWdbePrjNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbePrjNewData", "ContInfDlgWdbePrjNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbePrjNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbePrjNewData", "StatAppDlgWdbePrjNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbePrjNewData", "StatShrDlgWdbePrjNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbePrjNewData", "TagDlgWdbePrjNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWdbePrjNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWdbePrjNewData") {
		handleDpchEngDlgWdbePrjNewData(dom);
	};
};

function handleDpchEngDlgWdbePrjNewData(dom) {
	// IP handleDpchEngDlgWdbePrjNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbePrjNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbePrjNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

