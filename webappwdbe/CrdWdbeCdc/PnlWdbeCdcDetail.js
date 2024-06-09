// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeCdcDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeCdcDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeCdcDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeCdcDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeCdcDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeCdcDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeCdcDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeCdcDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeCdcDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptFck", retrieveTi(srcdoc, "TagWdbeCdcDetail", "CptFck"));
	initCpt(contcontdoc, "CptSck", retrieveTi(srcdoc, "TagWdbeCdcDetail", "CptSck"));
	initCpt(contcontdoc, "CptMdl", retrieveTi(srcdoc, "TagWdbeCdcDetail", "CptMdl"));
	initCpt(contcontdoc, "CptFar", retrieveTi(srcdoc, "TagWdbeCdcDetail", "CptFar"));
	initCpt(contcontdoc, "CptSar", retrieveTi(srcdoc, "TagWdbeCdcDetail", "CptSar"));
	initCpt(contcontdoc, "CptRat", retrieveTi(srcdoc, "TagWdbeCdcDetail", "CptRat"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeCdcDetail", "srefIxWdbeVExpstate");

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

	var height = 167; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtFckAlt = (retrieveSi(srcdoc, "StatAppWdbeCdcDetail", "TxtFckAlt") == "true");
	var TxfFckValid = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxfFckValid") == "true");
	var TxtFckActive = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxtFckActive") == "true");
	var ButFckViewAvail = !TxtFckAlt && (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "ButFckViewAvail") == "true");;

	var TxtSckAlt = (retrieveSi(srcdoc, "StatAppWdbeCdcDetail", "TxtSckAlt") == "true");
	var TxfSckValid = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxfSckValid") == "true");
	var TxtSckActive = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxtSckActive") == "true");
	var ButSckViewAvail = !TxtSckAlt && (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "ButSckViewAvail") == "true");;

	var TxtMdlActive = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxtMdlActive") == "true");
	var ButMdlViewAvail = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "ButMdlViewAvail") == "true");
	var ButMdlViewActive = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "ButMdlViewActive") == "true");

	var TxtFarAlt = (retrieveSi(srcdoc, "StatAppWdbeCdcDetail", "TxtFarAlt") == "true");
	var TxfFarValid = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxfFarValid") == "true");
	var TxtFarActive = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxtFarActive") == "true");
	var ButFarViewAvail = !TxtFarAlt && (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "ButFarViewAvail") == "true");;

	var TxtSarAlt = (retrieveSi(srcdoc, "StatAppWdbeCdcDetail", "TxtSarAlt") == "true");
	var TxfSarValid = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxfSarValid") == "true");
	var TxtSarActive = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxtSarActive") == "true");
	var ButSarViewAvail = !TxtSarAlt && (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "ButSarViewAvail") == "true");;

	var TxfRatActive = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "TxfRatActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeCdcDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	if ( (TxtFckAlt == !contcontdoc.getElementById("TxfFck")) || (!TxtFckAlt == !contcontdoc.getElementById("TxtFck")) ) {
		mytd = contcontdoc.getElementById("dynFck");
		clearElem(mytd);

		if (TxtFckAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfFck", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtFck", ""));
	};

	if (TxtFckAlt) refreshTxf(contcontdoc, "TxfFck", "", retrieveCi(srcdoc, "ContIacWdbeCdcDetail", "TxfFck"), TxtFckActive, false, TxfFckValid);
	else refreshTxt(contcontdoc, "TxtFck", retrieveCi(srcdoc, "ContInfWdbeCdcDetail", "TxtFck"));

	if ((ButFckViewAvail == !contcontdoc.getElementById("ButFckView"))) {
		mytd = contcontdoc.getElementById("rdynFck");
		clearElem(mytd);

		first = true;

		if (ButFckViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFckView", "icon/view"));
		};
	};

	if ( (TxtSckAlt == !contcontdoc.getElementById("TxfSck")) || (!TxtSckAlt == !contcontdoc.getElementById("TxtSck")) ) {
		mytd = contcontdoc.getElementById("dynSck");
		clearElem(mytd);

		if (TxtSckAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfSck", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtSck", ""));
	};

	if (TxtSckAlt) refreshTxf(contcontdoc, "TxfSck", "", retrieveCi(srcdoc, "ContIacWdbeCdcDetail", "TxfSck"), TxtSckActive, false, TxfSckValid);
	else refreshTxt(contcontdoc, "TxtSck", retrieveCi(srcdoc, "ContInfWdbeCdcDetail", "TxtSck"));

	if ((ButSckViewAvail == !contcontdoc.getElementById("ButSckView"))) {
		mytd = contcontdoc.getElementById("rdynSck");
		clearElem(mytd);

		first = true;

		if (ButSckViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSckView", "icon/view"));
		};
	};

	if ((ButMdlViewAvail == !contcontdoc.getElementById("ButMdlView"))) {
		mytd = contcontdoc.getElementById("rdynMdl");
		clearElem(mytd);

		first = true;

		if (ButMdlViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMdlView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtMdl", retrieveCi(srcdoc, "ContInfWdbeCdcDetail", "TxtMdl"));

	if (ButMdlViewAvail) refreshButicon(contcontdoc, "ButMdlView", "icon/view", ButMdlViewActive, false);

	if ( (TxtFarAlt == !contcontdoc.getElementById("TxfFar")) || (!TxtFarAlt == !contcontdoc.getElementById("TxtFar")) ) {
		mytd = contcontdoc.getElementById("dynFar");
		clearElem(mytd);

		if (TxtFarAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfFar", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtFar", ""));
	};

	if (TxtFarAlt) refreshTxf(contcontdoc, "TxfFar", "", retrieveCi(srcdoc, "ContIacWdbeCdcDetail", "TxfFar"), TxtFarActive, false, TxfFarValid);
	else refreshTxt(contcontdoc, "TxtFar", retrieveCi(srcdoc, "ContInfWdbeCdcDetail", "TxtFar"));

	if ((ButFarViewAvail == !contcontdoc.getElementById("ButFarView"))) {
		mytd = contcontdoc.getElementById("rdynFar");
		clearElem(mytd);

		first = true;

		if (ButFarViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFarView", "icon/view"));
		};
	};

	if ( (TxtSarAlt == !contcontdoc.getElementById("TxfSar")) || (!TxtSarAlt == !contcontdoc.getElementById("TxtSar")) ) {
		mytd = contcontdoc.getElementById("dynSar");
		clearElem(mytd);

		if (TxtSarAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfSar", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtSar", ""));
	};

	if (TxtSarAlt) refreshTxf(contcontdoc, "TxfSar", "", retrieveCi(srcdoc, "ContIacWdbeCdcDetail", "TxfSar"), TxtSarActive, false, TxfSarValid);
	else refreshTxt(contcontdoc, "TxtSar", retrieveCi(srcdoc, "ContInfWdbeCdcDetail", "TxtSar"));

	if ((ButSarViewAvail == !contcontdoc.getElementById("ButSarView"))) {
		mytd = contcontdoc.getElementById("rdynSar");
		clearElem(mytd);

		first = true;

		if (ButSarViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSarView", "icon/view"));
		};
	};

	refreshTxf(contcontdoc, "TxfRat", "s", retrieveCi(srcdoc, "ContIacWdbeCdcDetail", "TxfRat"), TxfRatActive, false, true);

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeCdcDetail", "srefIxWdbeVExpstate");

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

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppWdbeCdcDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWdbeCdcDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeCdcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeCdcDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeCdcDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCdcDetailData", scrJref, "ContIacWdbeCdcDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeCdcDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeCdcDetailData", scrJref, "ContIacWdbeCdcDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeCdcDetailData", "ContIacWdbeCdcDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeCdcDetailData", "ContInfWdbeCdcDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeCdcDetailData", "StatAppWdbeCdcDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeCdcDetailData", "StatShrWdbeCdcDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeCdcDetailData", "TagWdbeCdcDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeCdcDetailData") {
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
			if (blk.nodeName == "DpchEngWdbeCdcDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbeCdcDetailData") {
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
