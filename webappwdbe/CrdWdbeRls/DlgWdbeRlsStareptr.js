// IP cust --- INSERT

// --- view initialization and refresh
function initDet() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initDet --- BEGIN
	initCpt(contdoc, "CptBrt", retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrDet", "CptBrt"));
	refreshRbu(contdoc, srcdoc, "RbuBrt", "FeedFDetRbuBrt", retrieveCi(srcdoc, "ContIacDlgWdbeRlsStareptrDet", "numFRbuBrt"), true);
	initCpt(contdoc, "CptGrl", retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrDet", "CptGrl"));
	initBut(contdoc, "ButSta", retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrDet", "ButSta"));
	// IP initDet --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsStareptr", "initdone", "true");

	refreshDet();
};

function initIni() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initIni --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrIni", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrIni", "Uld");
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrIni", "CptPrg"));
	// IP initIni --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsStareptr", "initdone", "true");

	refreshIni();
};

function initExt() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initExt --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrExt", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrExt", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrExt", "ButSto"));
	// IP initExt --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsStareptr", "initdone", "true");

	refreshExt();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsStareptr", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeRlsStareptr", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeRlsStareptr", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeRlsStareptr", "numFDse"));

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

function refreshDet() {
	// IP refreshDet.vars --- BEGIN

	var TxfGrlAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrDet", "TxfGrlAvail") == "true");

	var ButStaActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrDet", "ButStaActive") == "true");

	// IP refreshDet.vars --- END

	// IP refreshDet --- BEGIN
	setRbuValue(contdoc, "RbuBrt", retrieveCi(srcdoc, "ContIacDlgWdbeRlsStareptrDet", "numFRbuBrt"), true);

	setCtlAvail(contdoc, "Grl", TxfGrlAvail, 25);
	if (TxfGrlAvail) {
		refreshTxf(contdoc, "TxfGrl", "", retrieveCi(srcdoc, "ContIacDlgWdbeRlsStareptrDet", "TxfGrl"), true, false, true);

	};

	refreshBut(contdoc, "ButSta", ButStaActive, false);

	// IP refreshDet --- END
};

function refreshIni() {
	// IP refreshIni.vars --- BEGIN
	var UldAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrIni", "UldAvail") == "true");
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrIni", "UldActive") == "true");

	var TxtPrgAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrIni", "TxtPrgAvail") == "true");

	var Sep1Avail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrIni", "Sep1Avail") == "true");

	var ButClgAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrIni", "ButClgAvail") == "true");
	var ButClgActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrIni", "ButClgActive") == "true");

	var mytd, first;
	// IP refreshIni.vars --- END

	// IP refreshIni --- BEGIN
	setCtlAvail(contdoc, "", UldAvail, 25);
	if (UldAvail) {

		if (UldActive) {
			contdoc.getElementById("But").setAttribute("class", "but");
			contdoc.getElementById("But").setAttribute("type", "submit");
		} else {
			contdoc.getElementById("But").setAttribute("class", "butinact");
			contdoc.getElementById("But").setAttribute("type", "reset");
		};

	};

	setCtlAvail(contdoc, "Prg", TxtPrgAvail, 75);
	if (TxtPrgAvail) {
		refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeRlsStareptrIni", "TxtPrg"));

	};

	setCtlAvail(contdoc, "11", Sep1Avail, 0);
	setCtlAvail(contdoc, "12", Sep1Avail, 7);
	setCtlAvail(contdoc, "13", Sep1Avail, 0);
	if (Sep1Avail) {

	};

	setCtlAvail(contdoc, "Clg", ButClgAvail, 25);
	if (ButClgAvail) {
		if ((ButClgAvail == !contdoc.getElementById("ButClg"))) {
			mytd = contdoc.getElementById("dynClg");
			clearElem(mytd);

			first = true;

			if (ButClgAvail) {
				if (first) first = false;
				else mytd.appendChild(contdoc.createTextNode("\u00a0\u00a0"));
				mytd.appendChild(makeSpanBut(contdoc, "ButClg", retrieveTi(srcdoc, "TagDlgWdbeRlsStareptrIni", "ButClg")));
			};
		};

		if (ButClgAvail) refreshBut(contdoc, "ButClg", ButClgActive, false);

	};

	// IP refreshIni --- END
};

function refreshExt() {
	// IP refreshExt.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrExt", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrExt", "ButStoActive") == "true");

	// IP refreshExt.vars --- END

	// IP refreshExt --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeRlsStareptrExt", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshExt --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptrLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeRlsStareptrLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeRlsStareptr", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeRlsStareptr", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsStareptr", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeRlsStareptr" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Det") {
			refreshDet();
		} else if (shortDit == "Ini") {
			refreshIni();
		} else if (shortDit == "Ext") {
			refreshExt();
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

// --- specific event handlers for app controls of dialog item Det

// --- specific event handlers for app controls of dialog item Ini

// --- specific event handlers for app controls of dialog item Ext

// --- specific event handlers for app controls of dialog item Lfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeRlsStareptrDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeRlsStareptr", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeRlsStareptr", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeRlsStareptr", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsStareptrData", scrJref, "ContIacDlgWdbeRlsStareptr");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleRbuSelect(_doc, ditshort, ctlsref, num) {
	setCi(srcdoc, "ContIacDlgWdbeRlsStareptr" + ditshort, "numF" + ctlsref, "" + num);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsStareptrData", scrJref, "ContIacDlgWdbeRlsStareptr" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ditshort, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacDlgWdbeRlsStareptr" + ditshort, ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsStareptrData", scrJref, "ContIacDlgWdbeRlsStareptr" + ditshort);
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ditshort, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacDlgWdbeRlsStareptr" + ditshort, ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsStareptrData", scrJref, "ContIacDlgWdbeRlsStareptr" + ditshort);
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "ContIacDlgWdbeRlsStareptr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "ContIacDlgWdbeRlsStareptrDet", srcdoc)) mask.push("contiacdet");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "ContInfDlgWdbeRlsStareptr", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "ContInfDlgWdbeRlsStareptrExt", srcdoc)) mask.push("continfext");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "ContInfDlgWdbeRlsStareptrIni", srcdoc)) mask.push("continfini");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "ContInfDlgWdbeRlsStareptrLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "FeedFDetRbuBrt", srcdoc)) mask.push("feedFDetRbuBrt");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "StatAppDlgWdbeRlsStareptr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "StatShrDlgWdbeRlsStareptr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "StatShrDlgWdbeRlsStareptrDet", srcdoc)) mask.push("statshrdet");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "StatShrDlgWdbeRlsStareptrExt", srcdoc)) mask.push("statshrext");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "StatShrDlgWdbeRlsStareptrIni", srcdoc)) mask.push("statshrini");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "StatShrDlgWdbeRlsStareptrLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "TagDlgWdbeRlsStareptr", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "TagDlgWdbeRlsStareptrDet", srcdoc)) mask.push("tagdet");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "TagDlgWdbeRlsStareptrExt", srcdoc)) mask.push("tagext");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "TagDlgWdbeRlsStareptrIni", srcdoc)) mask.push("tagini");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsStareptrData", "TagDlgWdbeRlsStareptrLfi", srcdoc)) mask.push("taglfi");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeRlsStareptrData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeRlsStareptrData") {
		handleDpchEngDlgWdbeRlsStareptrData(dom);
	};
};

function handleDpchEngDlgWdbeRlsStareptrData(dom) {
	// IP handleDpchEngDlgWdbeRlsStareptrData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeRlsStareptrData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeRlsStareptrData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
