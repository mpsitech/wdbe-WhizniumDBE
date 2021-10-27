// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeIntDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeIntDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeIntDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeIntDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeIntDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeIntDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeIntDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeIntDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeIntDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbeIntDetail", "CptSrf"));
	initCpt(contcontdoc, "CptUnt", retrieveTi(srcdoc, "TagWdbeIntDetail", "CptUnt"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbeIntDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeIntDetail", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		initA();
	} else if (srefIxWdbeVExpstate == "regd") {
		initBD(true);
	} else if (srefIxWdbeVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	if (!contcontdoc) return;

	var height = 142; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbeIntDetail", "TxtSrfActive") == "true");

	var TxtUntActive = (retrieveSi(srcdoc, "StatShrWdbeIntDetail", "TxtUntActive") == "true");
	var ButUntViewAvail = (retrieveSi(srcdoc, "StatShrWdbeIntDetail", "ButUntViewAvail") == "true");
	var ButUntViewActive = (retrieveSi(srcdoc, "StatShrWdbeIntDetail", "ButUntViewActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbeIntDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeIntDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbeIntDetail", "TxtSrf"));

	if ((ButUntViewAvail == !contcontdoc.getElementById("ButUntView"))) {
		mytd = contcontdoc.getElementById("rdynUnt");
		clearElem(mytd);

		first = true;

		if (ButUntViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUntView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtUnt", retrieveCi(srcdoc, "ContInfWdbeIntDetail", "TxtUnt"));

	if (ButUntViewAvail) refreshButicon(contcontdoc, "ButUntView", "icon/view", ButUntViewActive, false);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbeIntDetail", "TxfCmt"), TxfCmtActive, false, true);

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeIntDetail", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		refreshA();
	} else if (srefIxWdbeVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxWdbeVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeIntDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeIntDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacWdbeIntDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeIntDetailData", scrJref, "ContIacWdbeIntDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeIntDetailData", "ContIacWdbeIntDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeIntDetailData", "ContInfWdbeIntDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeIntDetailData", "StatAppWdbeIntDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeIntDetailData", "StatShrWdbeIntDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeIntDetailData", "TagWdbeIntDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeIntDetailData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWdbeIntDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
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

			} else if (blk.nodeName == "DpchEngWdbeIntDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWdbeConfirm") {
				accepted = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:accepted");
				_scrJref = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:scrJref");
				sref = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngWdbeAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wdbe:DpchEngWdbeAlert/wdbe:scrJref"),
						retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:ContInfWdbeAlert"),
						retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:FeedFMcbAlert"));
			};
		};
	};
};
