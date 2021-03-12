function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWdbeVerRec", "scrJrefDetail");
	scrJrefBvr1NVersion = retrieveSi(srcdoc, "StatShrWdbeVerRec", "scrJrefBvr1NVersion");
	scrJref1NSystem = retrieveSi(srcdoc, "StatShrWdbeVerRec", "scrJref1NSystem");
	scrJref1NRelease = retrieveSi(srcdoc, "StatShrWdbeVerRec", "scrJref1NRelease");
	scrJref1NUnit = retrieveSi(srcdoc, "StatShrWdbeVerRec", "scrJref1NUnit");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrWdbeVerRec", "scrJrefRef1NFile");
	scrJrefMNLibrary = retrieveSi(srcdoc, "StatShrWdbeVerRec", "scrJrefMNLibrary");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWdbeVerRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWdbeVerRec", "initdoneBvr1NVersion", "false");
	setSi(srcdoc, "StatAppWdbeVerRec", "initdone1NSystem", "false");
	setSi(srcdoc, "StatAppWdbeVerRec", "initdone1NRelease", "false");
	setSi(srcdoc, "StatAppWdbeVerRec", "initdone1NUnit", "false");
	setSi(srcdoc, "StatAppWdbeVerRec", "initdoneRef1NFile", "false");
	setSi(srcdoc, "StatAppWdbeVerRec", "initdoneMNLibrary", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightBvr1NVersion = 30;
	height1NSystem = 30;
	height1NRelease = 30;
	height1NUnit = 30;
	heightRef1NFile = 30;
	heightMNLibrary = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWdbeVerRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdoneDetail") == "true");
	var initdoneBvr1NVersion = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdoneBvr1NVersion") == "true");
	var initdone1NSystem = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdone1NSystem") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdone1NRelease") == "true");
	var initdone1NUnit = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdone1NUnit") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdoneRef1NFile") == "true");
	var initdoneMNLibrary = (retrieveSi(srcdoc, "StatAppWdbeVerRec", "initdoneMNLibrary") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWdbeVerDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneBvr1NVersion) {
		rhsdoc.getElementById("Bvr1NVersion").src = "./PnlWdbeVerBvr1NVersion.html?scrJref=" + scrJrefBvr1NVersion;
	} else if (!initdone1NSystem) {
		rhsdoc.getElementById("1NSystem").src = "./PnlWdbeVer1NSystem.html?scrJref=" + scrJref1NSystem;
	} else if (!initdone1NRelease) {
		rhsdoc.getElementById("1NRelease").src = "./PnlWdbeVer1NRelease.html?scrJref=" + scrJref1NRelease;
	} else if (!initdone1NUnit) {
		rhsdoc.getElementById("1NUnit").src = "./PnlWdbeVer1NUnit.html?scrJref=" + scrJref1NUnit;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlWdbeVerRef1NFile.html?scrJref=" + scrJrefRef1NFile;
	} else if (!initdoneMNLibrary) {
		rhsdoc.getElementById("MNLibrary").src = "./PnlWdbeVerMNLibrary.html?scrJref=" + scrJrefMNLibrary;

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
		else if (short == "Bvr1NVersion") heightBvr1NVersion = height;
		else if (short == "1NSystem") height1NSystem = height;
		else if (short == "1NRelease") height1NRelease = height;
		else if (short == "1NUnit") height1NUnit = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
		else if (short == "MNLibrary") heightMNLibrary = height;
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

	doc.getElementById("Rec_side").src = "./PnlWdbeVerRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeVerRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 309);
	doc.getElementById("tdSide").setAttribute("height", "309");
	doc.getElementById("Rec_side").setAttribute("height", "309");
	doc.getElementById("Rec_cont").setAttribute("height", "309");

	doc.getElementById("Rec_side").src = "./PnlWdbeVerRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeVerRec_b.html";
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
	else if (pnlshort == "Bvr1NVersion") heightBvr1NVersion = height;
	else if (pnlshort == "1NSystem") height1NSystem = height;
	else if (pnlshort == "1NRelease") height1NRelease = height;
	else if (pnlshort == "1NUnit") height1NUnit = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;
	else if (pnlshort == "MNLibrary") heightMNLibrary = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = heightBvr1NVersion+13 + height1NSystem+13 + height1NRelease+13 + height1NUnit+13 + heightRef1NFile+13 + heightMNLibrary+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeVerRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeVerRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeVerRec", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		minimize();
	} else if (srefIxWdbeVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWdbeVerRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeVerRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeVerRec", "TxtRef"));

};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeVerRec", "srefIxWdbeVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeVerRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeVerRecData", "ContInfWdbeVerRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeVerRecData", "StatAppWdbeVerRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeVerRecData", "StatShrWdbeVerRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeVerRecData", "TagWdbeVerRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWdbeVExpstate, newSrefIxWdbeVExpstate;

	_scrJref = retrieveValue(dom, "//wdbe:*/wdbe:scrJref");
	srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeVerRec", "srefIxWdbeVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWdbeVerRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeVerRec", "srefIxWdbeVExpstate");

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
			} else if (_scrJref == scrJrefBvr1NVersion) {
				if (getInitdone("Bvr1NVersion")) rhsdoc.getElementById("Bvr1NVersion").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NSystem) {
				if (getInitdone("1NSystem")) rhsdoc.getElementById("1NSystem").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NRelease) {
				if (getInitdone("1NRelease")) rhsdoc.getElementById("1NRelease").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NUnit) {
				if (getInitdone("1NUnit")) rhsdoc.getElementById("1NUnit").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				if (getInitdone("Ref1NFile")) rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMNLibrary) {
				if (getInitdone("MNLibrary")) rhsdoc.getElementById("MNLibrary").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWdbeVerRecData") {
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

			} else if (blk.nodeName == "DpchEngWdbeVerRecData") {
				srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeVerRec", "srefIxWdbeVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeVerRec", "srefIxWdbeVExpstate");

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
