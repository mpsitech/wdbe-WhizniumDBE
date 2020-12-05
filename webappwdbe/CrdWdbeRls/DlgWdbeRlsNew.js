// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeRlsNew", "Cpt"));

	initCpt(contdoc, "DetCptTyp", retrieveTi(srcdoc, "TagDlgWdbeRlsNew", "DetCptTyp"));
	refreshPup(contdoc, srcdoc, "DetPupTyp", "", "FeedFDetPupTyp", retrieveCi(srcdoc, "ContIacDlgWdbeRlsNew", "numFDetPupTyp"), true, false);
	initCpt(contdoc, "DetCptMch", retrieveTi(srcdoc, "TagDlgWdbeRlsNew", "DetCptMch"));
	initCpt(contdoc, "DetCptSrf", retrieveTi(srcdoc, "TagDlgWdbeRlsNew", "DetCptSrf"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWdbeRlsNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWdbeRlsNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var ButCncActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsNew", "ButCncActive") == "true");
	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	contdoc.getElementById("DetPupTyp").value = retrieveCi(srcdoc, "ContIacDlgWdbeRlsNew", "numFDetPupTyp");

	refreshPup(contdoc, srcdoc, "DetPupMch", "", "FeedFDetPupMch", retrieveCi(srcdoc, "ContIacDlgWdbeRlsNew", "numFDetPupMch"), true, false);

	refreshTxf(contdoc, "DetTxfSrf", "s", retrieveCi(srcdoc, "ContIacDlgWdbeRlsNew", "DetTxfSrf"), true, false, true);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWdbeRlsNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWdbeRlsNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsNewData", scrJref, "ContIacDlgWdbeRlsNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWdbeRlsNew", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsNewData", scrJref, "ContIacDlgWdbeRlsNew");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWdbeRlsNew", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsNewData", scrJref, "ContIacDlgWdbeRlsNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsNewData", "ContIacDlgWdbeRlsNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsNewData", "ContInfDlgWdbeRlsNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsNewData", "FeedFDetPupMch", srcdoc)) mask.push("feedFDetPupMch");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsNewData", "FeedFDetPupTyp", srcdoc)) mask.push("feedFDetPupTyp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsNewData", "StatAppDlgWdbeRlsNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsNewData", "StatShrDlgWdbeRlsNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsNewData", "TagDlgWdbeRlsNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWdbeRlsNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWdbeRlsNewData") {
		handleDpchEngDlgWdbeRlsNewData(dom);
	};
};

function handleDpchEngDlgWdbeRlsNewData(dom) {
	// IP handleDpchEngDlgWdbeRlsNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeRlsNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeRlsNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

