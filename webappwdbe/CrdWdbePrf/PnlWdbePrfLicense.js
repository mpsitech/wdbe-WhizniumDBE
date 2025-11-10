// IP cust --- INSERT

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("License", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("License_side").setAttribute("height", "30");
	doc.getElementById("License_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("License_side").src = "./PnlWdbePrfLicense_aside.html";
	doc.getElementById("License_cont").src = "./PnlWdbePrfLicense_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("License_side").src = "./PnlWdbePrfLicense_bside.html";
	doc.getElementById("License_cont").src = "./PnlWdbePrfLicense_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("License_side").contentDocument;
	contdoc = doc.getElementById("License_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("License_side").contentDocument;
	contdoc = doc.getElementById("License_cont").contentDocument;
	hdrdoc = contdoc.getElementById("License_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("License_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt"));
	initCpt(contcontdoc, "Cpt1", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt1"));
	initCpt(contcontdoc, "Cpt2", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt2"));
	initCpt(contcontdoc, "Cpt3", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt3"));
	initCpt(contcontdoc, "Cpt4", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt4"));
	initCpt(contcontdoc, "Cpt5", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt5"));
	initCpt(contcontdoc, "Cpt6", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt6"));
	initCpt(contcontdoc, "Cpt7", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt7"));
	initCpt(contcontdoc, "Cpt8", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt8"));
	initCpt(contcontdoc, "Cpt9", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt9"));
	initCpt(contcontdoc, "Cpt10", retrieveTi(srcdoc, "TagWdbePrfLicense", "Cpt10"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfLicense", "srefIxWdbeVExpstate");

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

	var height = 260; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxf(contcontdoc, "Txf1", "", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf1"), true, false, true);

	refreshTxf(contcontdoc, "Txf2", "s", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf2"), true, false, true);

	refreshTxf(contcontdoc, "Txf3", "", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf3"), true, false, true);

	refreshTxf(contcontdoc, "Txf4", "", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf4"), true, false, true);

	refreshTxf(contcontdoc, "Txf5", "", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf5"), true, false, true);

	refreshTxf(contcontdoc, "Txf6", "", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf6"), true, false, true);

	refreshTxf(contcontdoc, "Txf7", "", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf7"), true, false, true);

	refreshTxf(contcontdoc, "Txf8", "", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf8"), true, false, true);

	refreshTxf(contcontdoc, "Txf9", "", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf9"), true, false, true);

	refreshTxf(contcontdoc, "Txf10", "", retrieveCi(srcdoc, "ContIacWdbePrfLicense", "Txf10"), true, false, true);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("License", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("License_side").setAttribute("height", "" + (height+31));
	doc.getElementById("License_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("License_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfLicense", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("License_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrfLicenseDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbePrfLicense", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrfLicenseData", scrJref, "ContIacWdbePrfLicense");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbePrfLicense", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrfLicenseData", scrJref, "ContIacWdbePrfLicense");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWdbePrfLicenseData", "ContIacWdbePrfLicense", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbePrfLicenseData", "StatShrWdbePrfLicense", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbePrfLicenseData", "TagWdbePrfLicense", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbePrfLicenseData") {
		var oldSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfLicense", "srefIxWdbeVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfLicense", "srefIxWdbeVExpstate");

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
			if (blk.nodeName == "DpchEngWdbePrfLicenseData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("License");
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

			} else if (blk.nodeName == "DpchEngWdbePrfLicenseData") {
				var oldSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfLicense", "srefIxWdbeVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrfLicense", "srefIxWdbeVExpstate");

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
