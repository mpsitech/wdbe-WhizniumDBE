// IP cust --- INSERT

// --- view initialization and refresh
function initIfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initIfi --- BEGIN
	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagDlgWdbeVerCustfstIfi", "Cpt"));
	contdoc.getElementById("form").setAttribute("action", "/upload/" + scrJref);
	contdoc.getElementById("But").value = retrieveTi(srcdoc, "TagDlgWdbeVerCustfstIfi", "Uld");
	// IP initIfi --- END

	setSi(srcdoc, "StatAppDlgWdbeVerCustfst", "initdone", "true");

	refreshIfi();
};

function initImp() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initImp --- BEGIN
	initCpt(contdoc, "CptPrg", retrieveTi(srcdoc, "TagDlgWdbeVerCustfstImp", "CptPrg"));
	initBut(contdoc, "ButRun", retrieveTi(srcdoc, "TagDlgWdbeVerCustfstImp", "ButRun"));
	initBut(contdoc, "ButSto", retrieveTi(srcdoc, "TagDlgWdbeVerCustfstImp", "ButSto"));
	// IP initImp --- END

	setSi(srcdoc, "StatAppDlgWdbeVerCustfst", "initdone", "true");

	refreshImp();
};

function initLfi() {
	contdoc = doc.getElementById("_cont").contentDocument;

	// IP initLfi --- BEGIN
	setTextContent(contdoc, contdoc.getElementById("Dld"), retrieveTi(srcdoc, "TagDlgWdbeVerCustfstLfi", "Dld"));
	// IP initLfi --- END

	setSi(srcdoc, "StatAppDlgWdbeVerCustfst", "initdone", "true");

	refreshLfi();
};

function init() {
	hdrdoc = doc.getElementById("_hdr").contentDocument;
	ftrdoc = doc.getElementById("_ftr").contentDocument;
	contdoc = null;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagDlgWdbeVerCustfst", "Cpt"));

	setTextContent(ftrdoc, ftrdoc.getElementById("ButDne"), retrieveTi(srcdoc, "TagDlgWdbeVerCustfst", "ButDne"));

	// includes load of initial dit
	refresh(true, true);
};

function refreshHdr() {
	var numFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeVerCustfst", "numFDse"));

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
	var UldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCustfstIfi", "UldActive") == "true");

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

	var ButRunActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCustfstImp", "ButRunActive") == "true");
	var ButStoActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCustfstImp", "ButStoActive") == "true");

	// IP refreshImp.vars --- END

	// IP refreshImp --- BEGIN
	refreshTxtt(contdoc, "TxtPrg", retrieveCi(srcdoc, "ContInfDlgWdbeVerCustfstImp", "TxtPrg"));

	refreshBut(contdoc, "ButRun", ButRunActive, false);
	refreshBut(contdoc, "ButSto", ButStoActive, false);

	// IP refreshImp --- END
};

function refreshLfi() {
	// IP refreshLfi.vars --- BEGIN
	var DldActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCustfstLfi", "DldActive") == "true");

	// IP refreshLfi.vars --- END

	// IP refreshLfi --- BEGIN
	refreshDld(contdoc, "Dld", scrJref, retrieveCi(srcdoc, "ContInfDlgWdbeVerCustfstLfi", "Dld"), DldActive);

	// IP refreshLfi --- END
};

function refresh(updDit, updHdr) {
	var numFDse = retrieveCi(srcdoc, "ContIacDlgWdbeVerCustfst", "numFDse");
	var shortDit = retrieveFeedSrefByNum(srcdoc, "FeedFDse", numFDse);
	var initdone = (retrieveSi(srcdoc, "StatAppDlgWdbeVerCustfst", "initdone") == "true");

	// IP refresh.vars --- BEGIN
	var ButDneActive = (retrieveSi(srcdoc, "StatShrDlgWdbeVerCustfst", "ButDneActive") == "true");
	// IP refresh.vars --- END

	if (updDit || updHdr) refreshHdr();

	if (updDit) {
		// load new dialog item
		doc.getElementById("_cont").src = "./DlgWdbeVerCustfst" + shortDit + ".xml" 

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
	var str = serializeDpchAppDoDlg(srcdoc, "DpchAppDlgWdbeVerCustfstDo", scrJref, ditshort, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleDseSelect(numFDse) {
	var oldNumFDse = parseInt(retrieveCi(srcdoc, "ContIacDlgWdbeVerCustfst", "numFDse"));

	if (oldNumFDse != numFDse) {
		setCi(srcdoc, "ContIacDlgWdbeVerCustfst", "numFDse", "" + numFDse);

		setSi(srcdoc, "StatAppDlgWdbeVerCustfst", "initdone", "false");

		var str = serializeDpchAppData(srcdoc, "DpchAppDlgWdbeVerCustfstData", scrJref, "ContIacDlgWdbeVerCustfst");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "ContIacDlgWdbeVerCustfst", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "ContInfDlgWdbeVerCustfst", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "ContInfDlgWdbeVerCustfstImp", srcdoc)) mask.push("continfimp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "ContInfDlgWdbeVerCustfstLfi", srcdoc)) mask.push("continflfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "FeedFDse", srcdoc)) mask.push("feedFDse");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "StatAppDlgWdbeVerCustfst", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "StatShrDlgWdbeVerCustfst", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "StatShrDlgWdbeVerCustfstIfi", srcdoc)) mask.push("statshrifi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "StatShrDlgWdbeVerCustfstImp", srcdoc)) mask.push("statshrimp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "StatShrDlgWdbeVerCustfstLfi", srcdoc)) mask.push("statshrlfi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "TagDlgWdbeVerCustfst", srcdoc)) mask.push("tag");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "TagDlgWdbeVerCustfstIfi", srcdoc)) mask.push("tagifi");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "TagDlgWdbeVerCustfstImp", srcdoc)) mask.push("tagimp");
	if (updateSrcblock(dom, "DpchEngDlgWdbeVerCustfstData", "TagDlgWdbeVerCustfstLfi", srcdoc)) mask.push("taglfi");

	return mask;
};

function handleDpchEng(dom, dpch) {
	var mask;

	if (dpch == "DpchEngDlgWdbeVerCustfstData") {
		mask = mergeDpchEngData(dom);
		refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
	} else if (dpch == "DpchEngDlgWdbeVerCustfstData") {
		handleDpchEngDlgWdbeVerCustfstData(dom);
	};
};

function handleDpchEngDlgWdbeVerCustfstData(dom) {
	// IP handleDpchEngDlgWdbeVerCustfstData --- INSERT
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngDlgWdbeVerCustfstData") {
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

			} else if (blk.nodeName == "DpchEngDlgWdbeVerCustfstData") {
				mask = mergeDpchEngData(dom);
				refresh(mask.indexOf("contiac") != -1, mask.indexOf("feedFDse") != -1);
			};
		};
	};
};
