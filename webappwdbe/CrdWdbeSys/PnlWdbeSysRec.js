/**
  * \file PnlWdbeSysRec.js
  * web client functionality for panel PnlWdbeSysRec
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWdbeSysRec", "scrJrefDetail");
	scrJrefSys1NTarget = retrieveSi(srcdoc, "StatShrWdbeSysRec", "scrJrefSys1NTarget");
	scrJrefHk1NVector = retrieveSi(srcdoc, "StatShrWdbeSysRec", "scrJrefHk1NVector");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWdbeSysRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWdbeSysRec", "initdoneSys1NTarget", "false");
	setSi(srcdoc, "StatAppWdbeSysRec", "initdoneHk1NVector", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightSys1NTarget = 30;
	heightHk1NVector = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWdbeSysRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWdbeSysRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeSysRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWdbeSysRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWdbeSysRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeSysRec", "initdoneDetail") == "true");
	var initdoneSys1NTarget = (retrieveSi(srcdoc, "StatAppWdbeSysRec", "initdoneSys1NTarget") == "true");
	var initdoneHk1NVector = (retrieveSi(srcdoc, "StatAppWdbeSysRec", "initdoneHk1NVector") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWdbeSysDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneSys1NTarget) {
		rhsdoc.getElementById("Sys1NTarget").src = "./PnlWdbeSysSys1NTarget.html?scrJref=" + scrJrefSys1NTarget;
	} else if (!initdoneHk1NVector) {
		rhsdoc.getElementById("Hk1NVector").src = "./PnlWdbeSysHk1NVector.html?scrJref=" + scrJrefHk1NVector;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail")) lhsrhsdoc = lhsdoc;
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
		else if (short == "Sys1NTarget") heightSys1NTarget = height;
		else if (short == "Hk1NVector") heightHk1NVector = height;
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

	doc.getElementById("Rec_side").src = "./PnlWdbeSysRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeSysRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 137);
	doc.getElementById("tdSide").setAttribute("height", "137");
	doc.getElementById("Rec_side").setAttribute("height", "137");
	doc.getElementById("Rec_cont").setAttribute("height", "137");

	doc.getElementById("Rec_side").src = "./PnlWdbeSysRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeSysRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "Sys1NTarget") heightSys1NTarget = height;
	else if (pnlshort == "Hk1NVector") heightHk1NVector = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = heightSys1NTarget+13 + heightHk1NVector+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeSysRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeSysRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeSysRec", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		minimize();
	} else if (srefIxWdbeVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWdbeSysRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeSysRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeSysRec", "TxtRef"));

};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeSysRec", "srefIxWdbeVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeSysRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeSysRecData", "ContInfWdbeSysRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeSysRecData", "StatAppWdbeSysRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeSysRecData", "StatShrWdbeSysRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeSysRecData", "TagWdbeSysRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWdbeVExpstate, newSrefIxWdbeVExpstate;

	_scrJref = retrieveValue(dom, "//wdbe:*/wdbe:scrJref");
	srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeSysRec", "srefIxWdbeVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWdbeSysRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeSysRec", "srefIxWdbeVExpstate");

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
			} else if (_scrJref == scrJrefSys1NTarget) {
				if (getInitdone("Sys1NTarget")) rhsdoc.getElementById("Sys1NTarget").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NVector) {
				if (getInitdone("Hk1NVector")) rhsdoc.getElementById("Hk1NVector").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWdbeSysRecData") {
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

			} else if (blk.nodeName == "DpchEngWdbeSysRecData") {
				srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeSysRec", "srefIxWdbeVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeSysRec", "srefIxWdbeVExpstate");

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

