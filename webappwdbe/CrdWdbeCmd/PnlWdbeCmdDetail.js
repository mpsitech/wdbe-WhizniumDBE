// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeCmdDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeCmdDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeCmdDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeCmdDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeCmdDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeCmdDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeCmdDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeCmdDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeCmdDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbeCmdDetail", "CptSrf"));
	initCpt(contcontdoc, "CptFsr", retrieveTi(srcdoc, "TagWdbeCmdDetail", "CptFsr"));
	initCpt(contcontdoc, "CptReu", retrieveTi(srcdoc, "TagWdbeCmdDetail", "CptReu"));
	refreshPup(contcontdoc, srcdoc, "PupRet", "xs", "FeedFPupRet", retrieveCi(srcdoc, "ContIacWdbeCmdDetail", "numFPupRet"), true, false);
	initCpt(contcontdoc, "CptRty", retrieveTi(srcdoc, "TagWdbeCmdDetail", "CptRty"));
	refreshPup(contcontdoc, srcdoc, "PupRty", "", "FeedFPupRty", retrieveCi(srcdoc, "ContIacWdbeCmdDetail", "numFPupRty"), retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "PupRtyActive"), false);
	initCpt(contcontdoc, "CptIvr", retrieveTi(srcdoc, "TagWdbeCmdDetail", "CptIvr"));
	initCpt(contcontdoc, "CptRvr", retrieveTi(srcdoc, "TagWdbeCmdDetail", "CptRvr"));
	initCpt(contcontdoc, "CptRer", retrieveTi(srcdoc, "TagWdbeCmdDetail", "CptRer"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbeCmdDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeCmdDetail", "srefIxWdbeVExpstate");

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

	var height = 267; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "TxtSrfActive") == "true");

	var TxfFsrActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "TxfFsrActive") == "true");

	var TxtReuActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "TxtReuActive") == "true");
	var ButReuViewAvail = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "ButReuViewAvail") == "true");
	var ButReuViewActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "ButReuViewActive") == "true");

	var PupRtyActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "PupRtyActive") == "true");

	var TxtIvrActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "TxtIvrActive") == "true");
	var ButIvrViewAvail = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "ButIvrViewAvail") == "true");
	var ButIvrViewActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "ButIvrViewActive") == "true");

	var TxtRvrActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "TxtRvrActive") == "true");
	var ButRvrViewAvail = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "ButRvrViewAvail") == "true");
	var ButRvrViewActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "ButRvrViewActive") == "true");

	var TxtRerActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "TxtRerActive") == "true");
	var ButRerViewAvail = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "ButRerViewAvail") == "true");
	var ButRerViewActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "ButRerViewActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeCmdDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbeCmdDetail", "TxtSrf"));

	refreshTxf(contcontdoc, "TxfFsr", "", retrieveCi(srcdoc, "ContIacWdbeCmdDetail", "TxfFsr"), TxfFsrActive, false, true);

	if ((ButReuViewAvail == !contcontdoc.getElementById("ButReuView"))) {
		mytd = contcontdoc.getElementById("rdynReu");
		clearElem(mytd);

		first = true;

		if (ButReuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButReuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtReu", retrieveCi(srcdoc, "ContInfWdbeCmdDetail", "TxtReu"));
	contcontdoc.getElementById("PupRet").value = retrieveCi(srcdoc, "ContIacWdbeCmdDetail", "numFPupRet");

	if (ButReuViewAvail) refreshButicon(contcontdoc, "ButReuView", "icon/view", ButReuViewActive, false);

	contcontdoc.getElementById("PupRty").value = retrieveCi(srcdoc, "ContIacWdbeCmdDetail", "numFPupRty");

	if ((ButIvrViewAvail == !contcontdoc.getElementById("ButIvrView"))) {
		mytd = contcontdoc.getElementById("rdynIvr");
		clearElem(mytd);

		first = true;

		if (ButIvrViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButIvrView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtIvr", retrieveCi(srcdoc, "ContInfWdbeCmdDetail", "TxtIvr"));

	if (ButIvrViewAvail) refreshButicon(contcontdoc, "ButIvrView", "icon/view", ButIvrViewActive, false);

	if ((ButRvrViewAvail == !contcontdoc.getElementById("ButRvrView"))) {
		mytd = contcontdoc.getElementById("rdynRvr");
		clearElem(mytd);

		first = true;

		if (ButRvrViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButRvrView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtRvr", retrieveCi(srcdoc, "ContInfWdbeCmdDetail", "TxtRvr"));

	if (ButRvrViewAvail) refreshButicon(contcontdoc, "ButRvrView", "icon/view", ButRvrViewActive, false);

	if ((ButRerViewAvail == !contcontdoc.getElementById("ButRerView"))) {
		mytd = contcontdoc.getElementById("rdynRer");
		clearElem(mytd);

		first = true;

		if (ButRerViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButRerView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtRer", retrieveCi(srcdoc, "ContInfWdbeCmdDetail", "TxtRer"));

	if (ButRerViewAvail) refreshButicon(contcontdoc, "ButRerView", "icon/view", ButRerViewActive, false);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbeCmdDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeCmdDetail", "srefIxWdbeVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeCmdDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeCmdDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbeCmdDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCmdDetailData", scrJref, "ContIacWdbeCmdDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeCmdDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCmdDetailData", scrJref, "ContIacWdbeCmdDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeCmdDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCmdDetailData", scrJref, "ContIacWdbeCmdDetail");
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

	setCi(srcdoc, "ContIacWdbeCmdDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCmdDetailData", scrJref, "ContIacWdbeCmdDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeCmdDetailData", "ContIacWdbeCmdDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeCmdDetailData", "ContInfWdbeCmdDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeCmdDetailData", "FeedFPupRet", srcdoc)) mask.push("feedFPupRet");
	if (updateSrcblock(dom, "DpchEngWdbeCmdDetailData", "FeedFPupRty", srcdoc)) mask.push("feedFPupRty");
	if (updateSrcblock(dom, "DpchEngWdbeCmdDetailData", "StatAppWdbeCmdDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeCmdDetailData", "StatShrWdbeCmdDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeCmdDetailData", "TagWdbeCmdDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeCmdDetailData") {
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
			if (blk.nodeName == "DpchEngWdbeCmdDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbeCmdDetailData") {
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
