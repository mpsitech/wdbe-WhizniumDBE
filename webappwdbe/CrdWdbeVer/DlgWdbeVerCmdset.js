// IP cust --- INSERT

// --- view initialization and refresh
function initIfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initIfi --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeVerCmdsetIfi", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeVerCmdsetIfi", "Uld");
	// IP initIfi --- END

	setSi(srcdoc, "StatAppDlgWdbeVerCmdset", "initdone", "true");

	refreshIfi();
};

function initImp() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initImp --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeVerCmdsetImp", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeVerCmdsetImp", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeVerCmdsetImp", "ButSto"));
	// IP initImp --- END

	setSi(srcdoc, "StatAppDlgWdbeVerCmdset", "initdone", "true");

	refreshImp();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeVerCmdsetLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWdbeVerCmdset", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeVerCmdset", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeVerCmdset", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeVerCmdset", "numFDse"));

	var active, sref, Title;

	var myspan, myrect;

	for (var num = 1; num <= 3; num++) {
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

function refreshIfi() {
	// IP refreshIfi.vars --- BEGIN
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCmdsetIfi", "UldActive") == "true");

	// IP refreshIfi.vars --- END

	// IP refreshIfi --- BEGIN

	if (UldActive) {
		contdoc.getElementById("But").setAttribute("class", "but");
		contdoc.getElementById("But").setAttribute("type", "submit");
	} else {
		contdoc.getElementById("But").setAttribute("class", "butinact");
		contdoc.getElementById("But").setAttribute("type", "reset");
	};

	// IP refreshIfi --- END
};

function refreshImp() {
	// IP refreshImp.vars --- BEGIN

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCmdsetImp", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCmdsetImp", "ButStoActive") == "true");

	// IP refreshImp.vars --- END

	// IP refreshImp --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeVerCmdsetImp", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshImp --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCmdsetLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeVerCmdsetLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeVerCmdset", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeVerCmdset", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCmdset", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeVerCmdset" + shortDit + ".xml" 

	} else if (initdone) {
		// update current dialog item
		if (shortDit == "Ifi") {
			refreshIfi();
		} else if (shortDit == "Imp") {
			refreshImp();
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

// --- specific event handlers for app controls of dialog item Ifi

// --- specific event handlers for app controls of dialog item Imp

// --- specific event handlers for app controls of dialog item Lfi

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ditshort, ctlsref) {
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeVerCmdsetDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeVerCmdset", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeVerCmdset", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeVerCmdset", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeVerCmdsetData", scrJref, "ContIacDlgWdbeVerCmdset");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "ContIacDlgWdbeVerCmdset", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "ContInfDlgWdbeVerCmdset", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "ContInfDlgWdbeVerCmdsetImp", srcdoc)) mask.push("continfimp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "ContInfDlgWdbeVerCmdsetLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "StatAppDlgWdbeVerCmdset", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "StatShrDlgWdbeVerCmdset", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "StatShrDlgWdbeVerCmdsetIfi", srcdoc)) mask.push("statshrifi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "StatShrDlgWdbeVerCmdsetImp", srcdoc)) mask.push("statshrimp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "StatShrDlgWdbeVerCmdsetLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "TagDlgWdbeVerCmdset", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "TagDlgWdbeVerCmdsetIfi", srcdoc)) mask.push("tagifi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "TagDlgWdbeVerCmdsetImp", srcdoc)) mask.push("tagimp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCmdsetData", "TagDlgWdbeVerCmdsetLfi", srcdoc)) mask.push("taglfi");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeVerCmdsetData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeVerCmdsetData") {
		handleDpchEngDlgWdbeVerCmdsetData(dom);
	};
};

function handleDpchEngDlgWdbeVerCmdsetData(dom) {
	// IP handleDpchEngDlgWdbeVerCmdsetData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeVerCmdsetData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeVerCmdsetData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
