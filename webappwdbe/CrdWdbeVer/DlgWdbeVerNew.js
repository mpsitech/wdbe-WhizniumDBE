// IP cust --- INSERT

// --- view initialization and refresh
function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	contdoc = doc.getElementById("_cont").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeVerNew", "Cpt"));

	initCpt(contdoc, "DetCptPrj", retrieveTi(srcdoc, "TagDlgWdbeVerNew", "DetCptPrj"));
	initCpt(contdoc, "DetCptBvr", retrieveTi(srcdoc, "TagDlgWdbeVerNew", "DetCptBvr"));
	initCpt(contdoc, "DetCptVni", retrieveTi(srcdoc, "TagDlgWdbeVerNew", "DetCptVni"));
	refreshRbu(contdoc, srcdoc, "DetRbuVni", "FeedFDetRbuVni", retrieveCi(srcdoc, "ContIacDlgWdbeVerNew", "numFDetRbuVni"), true);
	initCpt(contdoc, "DetCptCmt", retrieveTi(srcdoc, "TagDlgWdbeVerNew", "DetCptCmt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButCnc"), retrieveTi(srcdoc, "TagDlgWdbeVerNew", "ButCnc"));
	setTextContent(ftrdoc, ftrdoc.getElementById("ButCre"), "\u00a0\u00a0" + retrieveTi(srcdoc, "TagDlgWdbeVerNew", "ButCre"));

	refresh();
};

function refresh() {
	// IP refresh.vars --- BEGIN

	var ButCreActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerNew", "ButCreActive") == "true");
	// IP refresh.vars --- END

	// IP refresh --- BEGIN
	refreshPup(contdoc, srcdoc, "DetPupPrj", "", "FeedFDetPupPrj", retrieveCi(srcdoc, "ContIacDlgWdbeVerNew", "numFDetPupPrj"), true, false);

	refreshPup(contdoc, srcdoc, "DetPupBvr", "", "FeedFDetPupBvr", retrieveCi(srcdoc, "ContIacDlgWdbeVerNew", "numFDetPupBvr"), true, false);

	setRbuValue(contdoc, "DetRbuVni", retrieveCi(srcdoc, "ContIacDlgWdbeVerNew", "numFDetRbuVni"), true);

	refreshTxft(contdoc, "DetTxfCmt", retrieveCi(srcdoc, "ContIacDlgWdbeVerNew", "DetTxfCmt"), true, false, true);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppDlgWdbeVerNewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacDlgWdbeVerNew", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeVerNewData", scrJref, "ContIacDlgWdbeVerNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleRbuSelect(_doc, ctlsref, num) {
	setCi(srcdoc, "ContIacDlgWdbeVerNew", "numF" + ctlsref, "" + num);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeVerNewData", scrJref, "ContIacDlgWdbeVerNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacDlgWdbeVerNew", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeVerNewData", scrJref, "ContIacDlgWdbeVerNew");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeVerNewData", "ContIacDlgWdbeVerNew", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerNewData", "ContInfDlgWdbeVerNew", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerNewData", "FeedFDetPupBvr", srcdoc)) mask.push("feedFDetPupBvr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerNewData", "FeedFDetPupPrj", srcdoc)) mask.push("feedFDetPupPrj");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerNewData", "FeedFDetRbuVni", srcdoc)) mask.push("feedFDetRbuVni");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerNewData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerNewData", "StatAppDlgWdbeVerNew", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerNewData", "StatShrDlgWdbeVerNew", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerNewData", "TagDlgWdbeVerNew", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngDlgWdbeVerNewData") {
		mergeDpchEngData(dom);
		refresh();
	} else if (dpch == "DpchEngDlgWdbeVerNewData") {
		handleDpchEngDlgWdbeVerNewData(dom);
	};
};

function handleDpchEngDlgWdbeVerNewData(dom) {
	// IP handleDpchEngDlgWdbeVerNewData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeVerNewData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeVerNewData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

