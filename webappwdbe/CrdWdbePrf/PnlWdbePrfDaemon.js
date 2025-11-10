// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Daemon", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Daemon_side").setAttribute("height", "30");
	doc.getElementById("Daemon_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Daemon_side").src = "./PnlWdbePrfDaemon_aside.html";
	doc.getElementById("Daemon_cont").src = "./PnlWdbePrfDaemon_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Daemon_side").src = "./PnlWdbePrfDaemon_bside.html";
	doc.getElementById("Daemon_cont").src = "./PnlWdbePrfDaemon_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Daemon_side").contentDocument;
	contdoc = doc.getElementById("Daemon_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Daemon_side").contentDocument;
	contdoc = doc.getElementById("Daemon_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Daemon_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Daemon_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt"));
	initCpt(contcontdoc, "Hdg1", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Hdg1"));
	initCpt(contcontdoc, "Cpt2", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt2"));
	initCpt(contcontdoc, "Cpt3", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt3"));
	initCpt(contcontdoc, "Cpt4", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt4"));
	initCpt(contcontdoc, "Cpt5", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt5"));
	initCpt(contcontdoc, "Cpt6", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt6"));
	initCpt(contcontdoc, "Hdg101", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Hdg101"));
	initCpt(contcontdoc, "Cpt102", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt102"));
	initCpt(contcontdoc, "Cpt103", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt103"));
	initCpt(contcontdoc, "Cpt104", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt104"));
	initCpt(contcontdoc, "Hdg201", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Hdg201"));
	initCpt(contcontdoc, "Cpt202", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt202"));
	initCpt(contcontdoc, "Cpt203", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt203"));
	initCpt(contcontdoc, "Cpt204", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt204"));
	initCpt(contcontdoc, "Hdg301", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Hdg301"));
	initCpt(contcontdoc, "Cpt302", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt302"));
	initCpt(contcontdoc, "Cpt303", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt303"));
	initCpt(contcontdoc, "Cpt304", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt304"));
	initCpt(contcontdoc, "Hdg401", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Hdg401"));
	initCpt(contcontdoc, "Cpt402", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt402"));
	initCpt(contcontdoc, "Cpt403", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt403"));
	initCpt(contcontdoc, "Cpt404", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt404"));
	initCpt(contcontdoc, "Cpt405", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt405"));
	initCpt(contcontdoc, "Cpt406", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt406"));
	initCpt(contcontdoc, "Cpt407", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt407"));
	initCpt(contcontdoc, "Cpt408", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt408"));
	initCpt(contcontdoc, "Hdg501", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Hdg501"));
	initCpt(contcontdoc, "Cpt502", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt502"));
	initCpt(contcontdoc, "Cpt503", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt503"));
	initCpt(contcontdoc, "Cpt504", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt504"));
	initCpt(contcontdoc, "Cpt505", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt505"));
	initCpt(contcontdoc, "Cpt506", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt506"));
	initCpt(contcontdoc, "Cpt507", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt507"));
	initCpt(contcontdoc, "Hdg601", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Hdg601"));
	initCpt(contcontdoc, "Cpt602", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt602"));
	initCpt(contcontdoc, "Cpt603", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt603"));
	initCpt(contcontdoc, "Hdg701", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Hdg701"));
	initCpt(contcontdoc, "Cpt702", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt702"));
	initCpt(contcontdoc, "Cpt703", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt703"));
	initCpt(contcontdoc, "Cpt704", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt704"));
	initCpt(contcontdoc, "Cpt705", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt705"));
	initCpt(contcontdoc, "Cpt706", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt706"));
	initCpt(contcontdoc, "Cpt707", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt707"));
	initCpt(contcontdoc, "Cpt708", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt708"));
	initCpt(contcontdoc, "Cpt709", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt709"));
	initCpt(contcontdoc, "Cpt710", retrieveTi(srcdoc, "TagWdbePrfDaemon", "Cpt710"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "srefIxWdbeVExpstate");

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

	var height = 1209; // full cont height

	// IP refreshBD.vars --- BEGIN

	var Sep2Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Sep2Avail") == "true");

	var Hdg201Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Hdg201Avail") == "true");

	var Txf202Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Txf202Avail") == "true");

	var Txf203Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Txf203Avail") == "true");

	var Chk204Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Chk204Avail") == "true");

	var Sep3Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Sep3Avail") == "true");

	var Hdg301Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Hdg301Avail") == "true");

	var Txf302Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Txf302Avail") == "true");

	var Txf303Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Txf303Avail") == "true");

	var Chk304Avail = (retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "Chk304Avail") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN

	refreshTxf(contcontdoc, "Txf2", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf2"), true, false, true);

	refreshChk(contcontdoc, "Chk3", (retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Chk3") == "true"), true);

	refreshTxf(contcontdoc, "Txf4", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf4"), true, false, true);

	refreshTxf(contcontdoc, "Txf5", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf5"), true, false, true);

	refreshTxf(contcontdoc, "Txf6", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf6"), true, false, true);

	refreshTxf(contcontdoc, "Txf102", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf102"), true, false, true);

	refreshChk(contcontdoc, "Chk103", (retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Chk103") == "true"), true);

	refreshTxf(contcontdoc, "Txf104", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf104"), true, false, true);

	height -= setCtlAvail(contcontdoc, "21", Sep2Avail, 0);
	setCtlAvail(contcontdoc, "22", Sep2Avail, 7);
	setCtlAvail(contcontdoc, "23", Sep2Avail, 0);
	if (Sep2Avail) {

	};

	height -= setCtlAvail(contcontdoc, "201", Hdg201Avail, 25);
	if (Hdg201Avail) {

	};

	height -= setCtlAvail(contcontdoc, "202", Txf202Avail, 25);
	if (Txf202Avail) {
		refreshTxf(contcontdoc, "Txf202", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf202"), true, false, true);

	};

	height -= setCtlAvail(contcontdoc, "203", Txf203Avail, 25);
	if (Txf203Avail) {
		refreshTxf(contcontdoc, "Txf203", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf203"), true, false, true);

	};

	height -= setCtlAvail(contcontdoc, "204", Chk204Avail, 25);
	if (Chk204Avail) {
		refreshChk(contcontdoc, "Chk204", (retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Chk204") == "true"), true);

	};

	height -= setCtlAvail(contcontdoc, "31", Sep3Avail, 0);
	setCtlAvail(contcontdoc, "32", Sep3Avail, 7);
	setCtlAvail(contcontdoc, "33", Sep3Avail, 0);
	if (Sep3Avail) {

	};

	height -= setCtlAvail(contcontdoc, "301", Hdg301Avail, 25);
	if (Hdg301Avail) {

	};

	height -= setCtlAvail(contcontdoc, "302", Txf302Avail, 25);
	if (Txf302Avail) {
		refreshTxf(contcontdoc, "Txf302", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf302"), true, false, true);

	};

	height -= setCtlAvail(contcontdoc, "303", Txf303Avail, 25);
	if (Txf303Avail) {
		refreshTxf(contcontdoc, "Txf303", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf303"), true, false, true);

	};

	height -= setCtlAvail(contcontdoc, "304", Chk304Avail, 25);
	if (Chk304Avail) {
		refreshChk(contcontdoc, "Chk304", (retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Chk304") == "true"), true);

	};

	refreshPup(contcontdoc, srcdoc, "Pup402", "", "FeedFPup402", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "numFPup402"), true, false);

	refreshTxf(contcontdoc, "Txf403", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf403"), true, false, true);

	refreshTxf(contcontdoc, "Txf404", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf404"), true, false, true);

	refreshTxf(contcontdoc, "Txf405", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf405"), true, false, true);

	refreshTxf(contcontdoc, "Txf406", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf406"), true, false, true);

	refreshTxf(contcontdoc, "Txf407", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf407"), true, false, true);

	refreshTxf(contcontdoc, "Txf408", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf408"), true, false, true);

	refreshTxf(contcontdoc, "Txf502", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf502"), true, false, true);

	refreshTxf(contcontdoc, "Txf503", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf503"), true, false, true);

	refreshTxf(contcontdoc, "Txf504", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf504"), true, false, true);

	refreshTxf(contcontdoc, "Txf505", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf505"), true, false, true);

	refreshTxf(contcontdoc, "Txf506", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf506"), true, false, true);

	refreshTxf(contcontdoc, "Txf507", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf507"), true, false, true);

	refreshTxf(contcontdoc, "Txf602", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf602"), true, false, true);

	refreshTxf(contcontdoc, "Txf603", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf603"), true, false, true);

	refreshTxf(contcontdoc, "Txf702", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf702"), true, false, true);

	refreshTxf(contcontdoc, "Txf703", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf703"), true, false, true);

	refreshTxf(contcontdoc, "Txf704", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf704"), true, false, true);

	refreshTxf(contcontdoc, "Txf705", "s", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf705"), true, false, true);

	refreshPup(contcontdoc, srcdoc, "Pup706", "", "FeedFPup706", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "numFPup706"), true, false);

	refreshTxf(contcontdoc, "Txf707", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf707"), true, false, true);

	refreshTxf(contcontdoc, "Txf708", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf708"), true, false, true);

	refreshTxf(contcontdoc, "Txf709", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf709"), true, false, true);

	refreshTxf(contcontdoc, "Txf710", "", retrieveCi(srcdoc, "ContIacWdbePrfDaemon", "Txf710"), true, false, true);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Daemon", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Daemon_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Daemon_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Daemon_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("Daemon_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrfDaemonDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWdbePrfDaemon", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrfDaemonData", scrJref, "ContIacWdbePrfDaemon");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbePrfDaemon", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrfDaemonData", scrJref, "ContIacWdbePrfDaemon");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbePrfDaemon", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrfDaemonData", scrJref, "ContIacWdbePrfDaemon");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbePrfDaemon", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrfDaemonData", scrJref, "ContIacWdbePrfDaemon");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWdbePrfDaemonData", "ContIacWdbePrfDaemon", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbePrfDaemonData", "FeedFPup402", srcdoc)) mask.push("feedFPup402");
	if (updateSrcblock(dom, "DpchEngWdbePrfDaemonData", "FeedFPup706", srcdoc)) mask.push("feedFPup706");
	if (updateSrcblock(dom, "DpchEngWdbePrfDaemonData", "StatShrWdbePrfDaemon", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbePrfDaemonData", "TagWdbePrfDaemon", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbePrfDaemonData") {
		var oldSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "srefIxWdbeVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "srefIxWdbeVExpstate");

			if (srefIxWdbeVExpstate != oldSrefIxWdbeVExpstate) {
				if (srefIxWdbeVExpstate == "mind") minimize();
				else if (srefIxWdbeVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWdbePrfDaemonData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Daemon");
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

			} else if (blk.nodeName == "DpchEngWdbePrfDaemonData") {
				var oldSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "srefIxWdbeVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfDaemon", "srefIxWdbeVExpstate");

					if (srefIxWdbeVExpstate != oldSrefIxWdbeVExpstate) {
						if (srefIxWdbeVExpstate == "mind") minimize();
						else if (srefIxWdbeVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			};
		};
	};
};
