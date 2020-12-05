// IP cust --- INSERT

// --- view initialization and refresh
function initFin() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initFin --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeRlsFinreptrFin", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeRlsFinreptrFin", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeRlsFinreptrFin", "ButSto"));
	// IP initFin --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsFinreptr", "initdone", "true");

	refreshFin();
};

function initRes() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initRes --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeRlsFinreptrRes", "Dld"));
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeRlsFinreptrRes", "CptPrg"));
	// IP initRes --- END

	setSi(srcdoc, "StatAppDlgWdbeRlsFinreptr", "initdone", "true");

	refreshRes();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeRlsFinreptr", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeRlsFinreptr", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeRlsFinreptr", "numFDse"));

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

function refreshFin() {
	// IP refreshFin.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsFinreptrFin", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsFinreptrFin", "ButStoActive") == "true");

	// IP refreshFin.vars --- END

	// IP refreshFin --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeRlsFinreptrFin", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshFin --- END
};

function refreshRes() {
	// IP refreshRes.vars --- BEGIN
	var DldAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsFinreptrRes", "DldAvail") == "true");
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsFinreptrRes", "DldActive") == "true");

	var TxtPrgAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsFinreptrRes", "TxtPrgAvail") == "true");

	var Sep1Avail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsFinreptrRes", "Sep1Avail") == "true");

	var ButPsgAvail = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsFinreptrRes", "ButPsgAvail") == "true");
	var ButPsgActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsFinreptrRes", "ButPsgActive") == "true");

	var mytd, first;
	// IP refreshRes.vars --- END

	// IP refreshRes --- BEGIN
	setCtlAvail(contdoc, "", DldAvail, 25);
	if (DldAvail) {
		refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeRlsFinreptrRes", "Dld"), DldActive);

	};

	setCtlAvail(contdoc, "Prg", TxtPrgAvail, 75);
	if (TxtPrgAvail) {
		refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeRlsFinreptrRes", "TxtPrg"));

	};

	setCtlAvail(contdoc, "11", Sep1Avail, 0);
	setCtlAvail(contdoc, "12", Sep1Avail, 7);
	setCtlAvail(contdoc, "13", Sep1Avail, 0);
	if (Sep1Avail) {

	};

	setCtlAvail(contdoc, "Psg", ButPsgAvail, 25);
	if (ButPsgAvail) {
		if ((ButPsgAvail == !contdoc.getElementById("ButPsg"))) {
			mytd = contdoc.getElementById("dynPsg");
			clearElem(mytd);

			first = true;

			if (ButPsgAvail) {
				if (first) first = false;
				else mytd.appendChild(contdoc.createTextNode("\u00a0\u00a0"));
				mytd.appendChild(makeSpanBut(contdoc, "ButPsg", retrieveTi(srcdoc, "TagDlgWdbeRlsFinreptrRes", "ButPsg")));
			};
		};

		if (ButPsgAvail) refreshBut(contdoc, "ButPsg", ButPsgActive, false);

	};

	// IP refreshRes --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeRlsFinreptr", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeRlsFinreptr", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeRlsFinreptr", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeRlsFinreptr" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Fin") {
			refreshFin();
		} else if (shortDit == "Res") {
			refreshRes();
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

// --- specific event handlers for app controls of dialog item Fin

// --- specific event handlers for app controls of dialog item Res

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeRlsFinreptrDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeRlsFinreptr", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeRlsFinreptr", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeRlsFinreptr", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeRlsFinreptrData", scrJref, "ContIacDlgWdbeRlsFinreptr");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "ContIacDlgWdbeRlsFinreptr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "ContInfDlgWdbeRlsFinreptr", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "ContInfDlgWdbeRlsFinreptrFin", srcdoc)) mask.push("continffin");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "ContInfDlgWdbeRlsFinreptrRes", srcdoc)) mask.push("continfres");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "StatAppDlgWdbeRlsFinreptr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "StatShrDlgWdbeRlsFinreptr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "StatShrDlgWdbeRlsFinreptrFin", srcdoc)) mask.push("statshrfin");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "StatShrDlgWdbeRlsFinreptrRes", srcdoc)) mask.push("statshrres");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "TagDlgWdbeRlsFinreptr", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "TagDlgWdbeRlsFinreptrFin", srcdoc)) mask.push("tagfin");
	if (updateSrcblock(dom, "DpchEngDlgWdbeRlsFinreptrData", "TagDlgWdbeRlsFinreptrRes", srcdoc)) mask.push("tagres");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeRlsFinreptrData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeRlsFinreptrData") {
		handleDpchEngDlgWdbeRlsFinreptrData(dom);
	};
};

function handleDpchEngDlgWdbeRlsFinreptrData(dom) {
	// IP handleDpchEngDlgWdbeRlsFinreptrData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeRlsFinreptrData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeRlsFinreptrData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};

