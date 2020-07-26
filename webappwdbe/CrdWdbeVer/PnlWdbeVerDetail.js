/**
  * \file PnlWdbeVerDetail.js
  * web client functionality for panel PnlWdbeVerDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeVerDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeVerDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeVerDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeVerDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeVerDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeVerDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeVerDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeVerDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeVerDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptPrj", retrieveTi(srcdoc, "TagWdbeVerDetail", "CptPrj"));
	initCpt(contcontdoc, "CptMaj", retrieveTi(srcdoc, "TagWdbeVerDetail", "CptMaj"));
	initCpt(contcontdoc, "CptMin", retrieveTi(srcdoc, "TagWdbeVerDetail", "CptMin"));
	initCpt(contcontdoc, "CptSub", retrieveTi(srcdoc, "TagWdbeVerDetail", "CptSub"));
	initCpt(contcontdoc, "CptBvr", retrieveTi(srcdoc, "TagWdbeVerDetail", "CptBvr"));
	initCpt(contcontdoc, "CptSte", retrieveTi(srcdoc, "TagWdbeVerDetail", "CptSte"));
	refreshPup(contcontdoc, srcdoc, "PupSte", "", "FeedFPupSte", retrieveCi(srcdoc, "ContIacWdbeVerDetail", "numFPupSte"), retrieveSi(srcdoc, "StatShrWdbeVerDetail", "PupSteActive"), false);
	initCpt(contcontdoc, "CptAbt", retrieveTi(srcdoc, "TagWdbeVerDetail", "CptAbt"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbeVerDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeVerDetail", "srefIxWdbeVExpstate");

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

	var height = 342; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtPrjActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "TxtPrjActive") == "true");
	var ButPrjViewAvail = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "ButPrjViewAvail") == "true");
	var ButPrjViewActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "ButPrjViewActive") == "true");

	var TxfMajActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "TxfMajActive") == "true");

	var TxfMinActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "TxfMinActive") == "true");

	var TxfSubActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "TxfSubActive") == "true");

	var TxtBvrActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "TxtBvrActive") == "true");
	var ButBvrViewAvail = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "ButBvrViewAvail") == "true");
	var ButBvrViewActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "ButBvrViewActive") == "true");

	var PupJstActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "PupJstActive") == "true");
	var ButJstEditAvail = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "ButJstEditAvail") == "true");

	var PupSteActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "PupSteActive") == "true");

	var TxfAbtActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "TxfAbtActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeVerDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ((ButPrjViewAvail == !contcontdoc.getElementById("ButPrjView"))) {
		mytd = contcontdoc.getElementById("rdynPrj");
		clearElem(mytd);

		first = true;

		if (ButPrjViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrjView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtPrj", retrieveCi(srcdoc, "ContInfWdbeVerDetail", "TxtPrj"));

	if (ButPrjViewAvail) refreshButicon(contcontdoc, "ButPrjView", "icon/view", ButPrjViewActive, false);

	refreshTxf(contcontdoc, "TxfMaj", "s", retrieveCi(srcdoc, "ContIacWdbeVerDetail", "TxfMaj"), TxfMajActive, false, true);

	refreshTxf(contcontdoc, "TxfMin", "s", retrieveCi(srcdoc, "ContIacWdbeVerDetail", "TxfMin"), TxfMinActive, false, true);

	refreshTxf(contcontdoc, "TxfSub", "s", retrieveCi(srcdoc, "ContIacWdbeVerDetail", "TxfSub"), TxfSubActive, false, true);

	if ((ButBvrViewAvail == !contcontdoc.getElementById("ButBvrView"))) {
		mytd = contcontdoc.getElementById("rdynBvr");
		clearElem(mytd);

		first = true;

		if (ButBvrViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButBvrView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtBvr", retrieveCi(srcdoc, "ContInfWdbeVerDetail", "TxtBvr"));

	if (ButBvrViewAvail) refreshButicon(contcontdoc, "ButBvrView", "icon/view", ButBvrViewActive, false);

	if ((ButJstEditAvail == !contcontdoc.getElementById("ButJstEdit"))) {
		mytd = contcontdoc.getElementById("rdynJst");
		clearElem(mytd);

		first = true;

		if (ButJstEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButJstEdit", "icon/edit"));
		};
	};

	refreshPup(contcontdoc, srcdoc, "PupJst", "s", "FeedFPupJst", retrieveCi(srcdoc, "ContIacWdbeVerDetail", "numFPupJst"), PupJstActive, false);

	contcontdoc.getElementById("PupSte").value = retrieveCi(srcdoc, "ContIacWdbeVerDetail", "numFPupSte");

	refreshTxft(contcontdoc, "TxfAbt", retrieveCi(srcdoc, "ContIacWdbeVerDetail", "TxfAbt"), TxfAbtActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbeVerDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeVerDetail", "srefIxWdbeVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeVerDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeVerDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeVerDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbeVerDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeVerDetailData", scrJref, "ContIacWdbeVerDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeVerDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeVerDetailData", scrJref, "ContIacWdbeVerDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeVerDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeVerDetailData", scrJref, "ContIacWdbeVerDetail");
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

	setCi(srcdoc, "ContIacWdbeVerDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeVerDetailData", scrJref, "ContIacWdbeVerDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeVerDetailData", "ContIacWdbeVerDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeVerDetailData", "ContInfWdbeVerDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeVerDetailData", "FeedFPupJst", srcdoc)) mask.push("feedFPupJst");
	if (updateSrcblock(dom, "DpchEngWdbeVerDetailData", "FeedFPupSte", srcdoc)) mask.push("feedFPupSte");
	if (updateSrcblock(dom, "DpchEngWdbeVerDetailData", "StatAppWdbeVerDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeVerDetailData", "StatShrWdbeVerDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeVerDetailData", "TagWdbeVerDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeVerDetailData") {
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
			if (blk.nodeName == "DpchEngWdbeVerDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbeVerDetailData") {
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

function handleDpchAppDoDlgopenReply() {
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

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};

