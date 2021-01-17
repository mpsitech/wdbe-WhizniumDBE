function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "scrJrefDetail");
	scrJrefAInvpar = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "scrJrefAInvpar");
	scrJrefARetpar = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "scrJrefARetpar");
	scrJrefMNController = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "scrJrefMNController");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWdbeCmdRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWdbeCmdRec", "initdoneAInvpar", "false");
	setSi(srcdoc, "StatAppWdbeCmdRec", "initdoneARetpar", "false");
	setSi(srcdoc, "StatAppWdbeCmdRec", "initdoneMNController", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightAInvpar = 30;
	heightARetpar = 30;
	heightMNController = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWdbeCmdRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWdbeCmdRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeCmdRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWdbeCmdRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWdbeCmdRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeCmdRec", "initdoneDetail") == "true");
	var initdoneAInvpar = (retrieveSi(srcdoc, "StatAppWdbeCmdRec", "initdoneAInvpar") == "true");
	var initdoneARetpar = (retrieveSi(srcdoc, "StatAppWdbeCmdRec", "initdoneARetpar") == "true");
	var initdoneMNController = (retrieveSi(srcdoc, "StatAppWdbeCmdRec", "initdoneMNController") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWdbeCmdDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneAInvpar) {
		lhsdoc.getElementById("AInvpar").src = "./PnlWdbeCmdAInvpar.html?scrJref=" + scrJrefAInvpar;
	} else if (!initdoneARetpar) {
		lhsdoc.getElementById("ARetpar").src = "./PnlWdbeCmdARetpar.html?scrJref=" + scrJrefARetpar;
	} else if (!initdoneMNController) {
		rhsdoc.getElementById("MNController").src = "./PnlWdbeCmdMNController.html?scrJref=" + scrJrefMNController;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "AInvpar") || (short == "ARetpar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	var oldAvail = (lhsrhsdoc.getElementById("tr" + short).getAttribute("class") == "show");

	var height;

	if (avail != oldAvail) {
		if (avail) {
			height = 30;

			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "show");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "show");

		} else {
			height = -13;

			lhsrhsdoc.getElementById(short).contentWindow.minimize(false);
			
			lhsrhsdoc.getElementById("spc" + short).setAttribute("class", "hide");
			lhsrhsdoc.getElementById("tr" + short).setAttribute("class", "hide");
		};

		if (short == "Headbar") heightHeadbar = height;
		else if (short == "List") heightList = height;
		else if (short == "Rec") heightRec = height;
		else if (short == "Detail") heightDetail = height;
		else if (short == "AInvpar") heightAInvpar = height;
		else if (short == "ARetpar") heightARetpar = height;
		else if (short == "MNController") heightMNController = height;
	};

	return(avail != oldAvail);
};

// --- expand state management
function minimize() {
	resetInitdones();

	getCrdwnd().changeHeight("Rec", 45);
	doc.getElementById("tdSide").setAttribute("height", "45");
	doc.getElementById("Rec_side").setAttribute("height", "45");
	doc.getElementById("Rec_cont").setAttribute("height", "45");

	doc.getElementById("Rec_side").src = "./PnlWdbeCmdRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeCmdRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 180);
	doc.getElementById("tdSide").setAttribute("height", "180");
	doc.getElementById("Rec_side").setAttribute("height", "180");
	doc.getElementById("Rec_cont").setAttribute("height", "180");

	doc.getElementById("Rec_side").src = "./PnlWdbeCmdRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeCmdRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "AInvpar") || (pnlshort == "ARetpar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "AInvpar") heightAInvpar = height;
	else if (pnlshort == "ARetpar") heightARetpar = height;
	else if (pnlshort == "MNController") heightMNController = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightAInvpar+13 + heightARetpar+13 + 5;
	heightRhs = heightMNController+13 + 5;

	if (heightLhs > heightRhs) {
		lhsdoc.getElementById("tdFill").setAttribute("height", "5");
		rhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightLhs-heightRhs+5));

		heightGt = heightLhs;

	} else {
		lhsdoc.getElementById("tdFill").setAttribute("height", "" + (heightRhs-heightLhs+5));
		rhsdoc.getElementById("tdFill").setAttribute("height", "5");

		heightGt = heightRhs;
	};

	getCrdwnd().changeHeight("Rec", 45+heightGt+1);

	doc.getElementById("tdSide").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_side").setAttribute("height", "" + (45+heightGt+1));
	doc.getElementById("Rec_cont").setAttribute("height", "" + (45+heightGt+1));

	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (heightGt+1));

	contdoc.getElementById("tdLhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_lhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("tdRhs").setAttribute("height", "" + heightGt);
	contdoc.getElementById("Rec_rhs").setAttribute("height", "" + heightGt);
};

// --- view initialization and refresh
function initAside() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;

	refreshAside();
};

function initA() {
	if (!doc) return;

	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = null;
	lhsdoc = null;
	rhsdoc = null;

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeCmdRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeCmdRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		minimize();
	} else if (srefIxWdbeVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWdbeCmdRec", "ButRegularizeActive") == "true");

	if (ButRegularizeActive) {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pm");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "src='../icon/regularize_hlt.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "src='../icon/regularize.png'");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "handleButRegularizeClick()");
	} else {
		sidedoc.getElementById("ButRegularize").src = "../icon/regularize_inact.png";
		sidedoc.getElementById("ButRegularize").setAttribute("class", "side_pmdis");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseover", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onmouseout", "");
		sidedoc.getElementById("ButRegularize").setAttribute("onclick", "");
	};
};

function refreshA() {
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeCmdRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeCmdRec", "TxtRef"));

};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		refreshAside();
		refreshA();
	} else if (srefIxWdbeVExpstate == "regd") {
		refreshB();
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Rec_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeCmdRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeCmdRecData", "ContInfWdbeCmdRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeCmdRecData", "StatAppWdbeCmdRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeCmdRecData", "StatShrWdbeCmdRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeCmdRecData", "TagWdbeCmdRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWdbeVExpstate, newSrefIxWdbeVExpstate;

	_scrJref = retrieveValue(dom, "//wdbe:*/wdbe:scrJref");
	srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "srefIxWdbeVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWdbeCmdRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "srefIxWdbeVExpstate");

				if (newSrefIxWdbeVExpstate != srefIxWdbeVExpstate) {
					updateScrJrefs();
					
					if (newSrefIxWdbeVExpstate == "mind") {
						minimize();
					} else if (newSrefIxWdbeVExpstate == "regd") {
						regularize();
					};

				} else {
					refresh();
				};

			} else {
				refresh();
			};
		};

	} else {
		if (srefIxWdbeVExpstate != "mind") {
			if (!lhsdoc) return;
			if (!rhsdoc) return;

			if (_scrJref == scrJrefDetail) {
				if (getInitdone("Detail")) lhsdoc.getElementById("Detail").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAInvpar) {
				if (getInitdone("AInvpar")) lhsdoc.getElementById("AInvpar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefARetpar) {
				if (getInitdone("ARetpar")) lhsdoc.getElementById("ARetpar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNController) {
				if (getInitdone("MNController")) rhsdoc.getElementById("MNController").contentWindow.handleDpchEng(dom, dpch);
			} else {
				// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
			};

		} else {
			// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
		};
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWdbeCmdRecData") {
				mergeDpchEngData(dom);

				updateScrJrefs();
				init();

				getCrdwnd().setInitdone("Rec");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk, mask;
	var srefIxWdbeVExpstate, newSrefIxWdbeVExpstate;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWdbeConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWdbeCmdRecData") {
				srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "srefIxWdbeVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeCmdRec", "srefIxWdbeVExpstate");

					if (newSrefIxWdbeVExpstate != srefIxWdbeVExpstate) {
						updateScrJrefs();

						if (newSrefIxWdbeVExpstate == "mind") {
							minimize();
						} else if (newSrefIxWdbeVExpstate == "regd") {
							regularize();
						};
					};

				} else {
					refresh();
				};
			};
		};
	};
};
