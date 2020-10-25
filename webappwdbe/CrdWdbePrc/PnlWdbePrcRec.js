/**
  * \file PnlWdbePrcRec.js
  * web client functionality for panel PnlWdbePrcRec
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWdbePrcRec", "scrJrefDetail");
	scrJrefKHdltype = retrieveSi(srcdoc, "StatShrWdbePrcRec", "scrJrefKHdltype");
	scrJrefPrc1NVariable = retrieveSi(srcdoc, "StatShrWdbePrcRec", "scrJrefPrc1NVariable");
	scrJrefMge1NSignal = retrieveSi(srcdoc, "StatShrWdbePrcRec", "scrJrefMge1NSignal");
	scrJrefFsmFsm1NFsmstate = retrieveSi(srcdoc, "StatShrWdbePrcRec", "scrJrefFsmFsm1NFsmstate");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWdbePrcRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWdbePrcRec", "initdoneKHdltype", "false");
	setSi(srcdoc, "StatAppWdbePrcRec", "initdonePrc1NVariable", "false");
	setSi(srcdoc, "StatAppWdbePrcRec", "initdoneMge1NSignal", "false");
	setSi(srcdoc, "StatAppWdbePrcRec", "initdoneFsmFsm1NFsmstate", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightKHdltype = 30;
	heightPrc1NVariable = 30;
	heightMge1NSignal = 30;
	heightFsmFsm1NFsmstate = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWdbePrcRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWdbePrcRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbePrcRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWdbePrcRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWdbePrcRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbePrcRec", "initdoneDetail") == "true");
	var initdoneKHdltype = (retrieveSi(srcdoc, "StatAppWdbePrcRec", "initdoneKHdltype") == "true");
	var initdonePrc1NVariable = (retrieveSi(srcdoc, "StatAppWdbePrcRec", "initdonePrc1NVariable") == "true");
	var initdoneMge1NSignal = (retrieveSi(srcdoc, "StatAppWdbePrcRec", "initdoneMge1NSignal") == "true");
	var initdoneFsmFsm1NFsmstate = (retrieveSi(srcdoc, "StatAppWdbePrcRec", "initdoneFsmFsm1NFsmstate") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWdbePrcDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneKHdltype) {
		lhsdoc.getElementById("KHdltype").src = "./PnlWdbePrcKHdltype.html?scrJref=" + scrJrefKHdltype;
	} else if (!initdonePrc1NVariable) {
		rhsdoc.getElementById("Prc1NVariable").src = "./PnlWdbePrcPrc1NVariable.html?scrJref=" + scrJrefPrc1NVariable;
	} else if (!initdoneMge1NSignal) {
		rhsdoc.getElementById("Mge1NSignal").src = "./PnlWdbePrcMge1NSignal.html?scrJref=" + scrJrefMge1NSignal;
	} else if (!initdoneFsmFsm1NFsmstate) {
		rhsdoc.getElementById("FsmFsm1NFsmstate").src = "./PnlWdbePrcFsmFsm1NFsmstate.html?scrJref=" + scrJrefFsmFsm1NFsmstate;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "KHdltype")) lhsrhsdoc = lhsdoc;
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
		else if (short == "KHdltype") heightKHdltype = height;
		else if (short == "Prc1NVariable") heightPrc1NVariable = height;
		else if (short == "Mge1NSignal") heightMge1NSignal = height;
		else if (short == "FsmFsm1NFsmstate") heightFsmFsm1NFsmstate = height;
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

	doc.getElementById("Rec_side").src = "./PnlWdbePrcRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbePrcRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 180);
	doc.getElementById("tdSide").setAttribute("height", "180");
	doc.getElementById("Rec_side").setAttribute("height", "180");
	doc.getElementById("Rec_cont").setAttribute("height", "180");

	doc.getElementById("Rec_side").src = "./PnlWdbePrcRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbePrcRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "KHdltype")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "KHdltype") heightKHdltype = height;
	else if (pnlshort == "Prc1NVariable") heightPrc1NVariable = height;
	else if (pnlshort == "Mge1NSignal") heightMge1NSignal = height;
	else if (pnlshort == "FsmFsm1NFsmstate") heightFsmFsm1NFsmstate = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightKHdltype+13 + 5;
	heightRhs = heightPrc1NVariable+13 + heightMge1NSignal+13 + heightFsmFsm1NFsmstate+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbePrcRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbePrcRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrcRec", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		minimize();
	} else if (srefIxWdbeVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWdbePrcRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbePrcRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlfsmfsm1nfsmstateAvail = (retrieveSi(srcdoc, "StatShrWdbePrcRec", "pnlfsmfsm1nfsmstateAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbePrcRec", "TxtRef"));

	if (setPnlAvail("FsmFsm1NFsmstate", pnlfsmfsm1nfsmstateAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrcRec", "srefIxWdbeVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrcRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbePrcRecData", "ContInfWdbePrcRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbePrcRecData", "StatAppWdbePrcRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbePrcRecData", "StatShrWdbePrcRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbePrcRecData", "TagWdbePrcRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWdbeVExpstate, newSrefIxWdbeVExpstate;

	_scrJref = retrieveValue(dom, "//wdbe:*/wdbe:scrJref");
	srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrcRec", "srefIxWdbeVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWdbePrcRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrcRec", "srefIxWdbeVExpstate");

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
			} else if (_scrJref == scrJrefKHdltype) {
				if (getInitdone("KHdltype")) lhsdoc.getElementById("KHdltype").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefPrc1NVariable) {
				if (getInitdone("Prc1NVariable")) rhsdoc.getElementById("Prc1NVariable").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMge1NSignal) {
				if (getInitdone("Mge1NSignal")) rhsdoc.getElementById("Mge1NSignal").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefFsmFsm1NFsmstate) {
				if (getInitdone("FsmFsm1NFsmstate")) rhsdoc.getElementById("FsmFsm1NFsmstate").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWdbePrcRecData") {
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

			} else if (blk.nodeName == "DpchEngWdbePrcRecData") {
				srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrcRec", "srefIxWdbeVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbePrcRec", "srefIxWdbeVExpstate");

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

