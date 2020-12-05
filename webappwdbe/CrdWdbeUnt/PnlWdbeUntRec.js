function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJrefDetail");
	scrJref1NBank = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJref1NBank");
	scrJrefFwd1NController = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJrefFwd1NController");
	scrJref1NTarget = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJref1NTarget");
	scrJref1NPeripheral = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJref1NPeripheral");
	scrJrefSil1NUnit = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJrefSil1NUnit");
	scrJrefRef1NCommand = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJrefRef1NCommand");
	scrJrefHk1NModule = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJrefHk1NModule");
	scrJrefHk1NVector = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJrefHk1NVector");
	scrJrefRef1NError = retrieveSi(srcdoc, "StatShrWdbeUntRec", "scrJrefRef1NError");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWdbeUntRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWdbeUntRec", "initdone1NBank", "false");
	setSi(srcdoc, "StatAppWdbeUntRec", "initdoneFwd1NController", "false");
	setSi(srcdoc, "StatAppWdbeUntRec", "initdone1NTarget", "false");
	setSi(srcdoc, "StatAppWdbeUntRec", "initdone1NPeripheral", "false");
	setSi(srcdoc, "StatAppWdbeUntRec", "initdoneSil1NUnit", "false");
	setSi(srcdoc, "StatAppWdbeUntRec", "initdoneRef1NCommand", "false");
	setSi(srcdoc, "StatAppWdbeUntRec", "initdoneHk1NModule", "false");
	setSi(srcdoc, "StatAppWdbeUntRec", "initdoneHk1NVector", "false");
	setSi(srcdoc, "StatAppWdbeUntRec", "initdoneRef1NError", "false");
};

function resetHeights() {
	heightDetail = 30;
	height1NBank = 30;
	heightFwd1NController = 30;
	height1NTarget = 30;
	height1NPeripheral = 30;
	heightSil1NUnit = 30;
	heightRef1NCommand = 30;
	heightHk1NModule = 30;
	heightHk1NVector = 30;
	heightRef1NError = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWdbeUntRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdoneDetail") == "true");
	var initdone1NBank = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdone1NBank") == "true");
	var initdoneFwd1NController = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdoneFwd1NController") == "true");
	var initdone1NTarget = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdone1NTarget") == "true");
	var initdone1NPeripheral = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdone1NPeripheral") == "true");
	var initdoneSil1NUnit = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdoneSil1NUnit") == "true");
	var initdoneRef1NCommand = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdoneRef1NCommand") == "true");
	var initdoneHk1NModule = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdoneHk1NModule") == "true");
	var initdoneHk1NVector = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdoneHk1NVector") == "true");
	var initdoneRef1NError = (retrieveSi(srcdoc, "StatAppWdbeUntRec", "initdoneRef1NError") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWdbeUntDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdone1NBank) {
		rhsdoc.getElementById("1NBank").src = "./PnlWdbeUnt1NBank.html?scrJref=" + scrJref1NBank;
	} else if (!initdoneFwd1NController) {
		rhsdoc.getElementById("Fwd1NController").src = "./PnlWdbeUntFwd1NController.html?scrJref=" + scrJrefFwd1NController;
	} else if (!initdone1NTarget) {
		rhsdoc.getElementById("1NTarget").src = "./PnlWdbeUnt1NTarget.html?scrJref=" + scrJref1NTarget;
	} else if (!initdone1NPeripheral) {
		rhsdoc.getElementById("1NPeripheral").src = "./PnlWdbeUnt1NPeripheral.html?scrJref=" + scrJref1NPeripheral;
	} else if (!initdoneSil1NUnit) {
		rhsdoc.getElementById("Sil1NUnit").src = "./PnlWdbeUntSil1NUnit.html?scrJref=" + scrJrefSil1NUnit;
	} else if (!initdoneRef1NCommand) {
		rhsdoc.getElementById("Ref1NCommand").src = "./PnlWdbeUntRef1NCommand.html?scrJref=" + scrJrefRef1NCommand;
	} else if (!initdoneHk1NModule) {
		rhsdoc.getElementById("Hk1NModule").src = "./PnlWdbeUntHk1NModule.html?scrJref=" + scrJrefHk1NModule;
	} else if (!initdoneHk1NVector) {
		rhsdoc.getElementById("Hk1NVector").src = "./PnlWdbeUntHk1NVector.html?scrJref=" + scrJrefHk1NVector;
	} else if (!initdoneRef1NError) {
		rhsdoc.getElementById("Ref1NError").src = "./PnlWdbeUntRef1NError.html?scrJref=" + scrJrefRef1NError;

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
		else if (short == "1NBank") height1NBank = height;
		else if (short == "Fwd1NController") heightFwd1NController = height;
		else if (short == "1NTarget") height1NTarget = height;
		else if (short == "1NPeripheral") height1NPeripheral = height;
		else if (short == "Sil1NUnit") heightSil1NUnit = height;
		else if (short == "Ref1NCommand") heightRef1NCommand = height;
		else if (short == "Hk1NModule") heightHk1NModule = height;
		else if (short == "Hk1NVector") heightHk1NVector = height;
		else if (short == "Ref1NError") heightRef1NError = height;
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

	doc.getElementById("Rec_side").src = "./PnlWdbeUntRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeUntRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 438);
	doc.getElementById("tdSide").setAttribute("height", "438");
	doc.getElementById("Rec_side").setAttribute("height", "438");
	doc.getElementById("Rec_cont").setAttribute("height", "438");

	doc.getElementById("Rec_side").src = "./PnlWdbeUntRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeUntRec_b.html";
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
	else if (pnlshort == "1NBank") height1NBank = height;
	else if (pnlshort == "Fwd1NController") heightFwd1NController = height;
	else if (pnlshort == "1NTarget") height1NTarget = height;
	else if (pnlshort == "1NPeripheral") height1NPeripheral = height;
	else if (pnlshort == "Sil1NUnit") heightSil1NUnit = height;
	else if (pnlshort == "Ref1NCommand") heightRef1NCommand = height;
	else if (pnlshort == "Hk1NModule") heightHk1NModule = height;
	else if (pnlshort == "Hk1NVector") heightHk1NVector = height;
	else if (pnlshort == "Ref1NError") heightRef1NError = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + 5;
	heightRhs = height1NBank+13 + heightFwd1NController+13 + height1NTarget+13 + height1NPeripheral+13 + heightSil1NUnit+13 + heightRef1NCommand+13 + heightHk1NModule+13 + heightHk1NVector+13 + heightRef1NError+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeUntRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeUntRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeUntRec", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		minimize();
	} else if (srefIxWdbeVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWdbeUntRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeUntRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlsil1nunitAvail = (retrieveSi(srcdoc, "StatShrWdbeUntRec", "pnlsil1nunitAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeUntRec", "TxtRef"));

	if (setPnlAvail("Sil1NUnit", pnlsil1nunitAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeUntRec", "srefIxWdbeVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeUntRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeUntRecData", "ContInfWdbeUntRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeUntRecData", "StatAppWdbeUntRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeUntRecData", "StatShrWdbeUntRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeUntRecData", "TagWdbeUntRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWdbeVExpstate, newSrefIxWdbeVExpstate;

	_scrJref = retrieveValue(dom, "//wdbe:*/wdbe:scrJref");
	srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeUntRec", "srefIxWdbeVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWdbeUntRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeUntRec", "srefIxWdbeVExpstate");

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
			} else if (_scrJref == scrJref1NBank) {
				if (getInitdone("1NBank")) rhsdoc.getElementById("1NBank").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefFwd1NController) {
				if (getInitdone("Fwd1NController")) rhsdoc.getElementById("Fwd1NController").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NTarget) {
				if (getInitdone("1NTarget")) rhsdoc.getElementById("1NTarget").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NPeripheral) {
				if (getInitdone("1NPeripheral")) rhsdoc.getElementById("1NPeripheral").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSil1NUnit) {
				if (getInitdone("Sil1NUnit")) rhsdoc.getElementById("Sil1NUnit").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NCommand) {
				if (getInitdone("Ref1NCommand")) rhsdoc.getElementById("Ref1NCommand").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NModule) {
				if (getInitdone("Hk1NModule")) rhsdoc.getElementById("Hk1NModule").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHk1NVector) {
				if (getInitdone("Hk1NVector")) rhsdoc.getElementById("Hk1NVector").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NError) {
				if (getInitdone("Ref1NError")) rhsdoc.getElementById("Ref1NError").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWdbeUntRecData") {
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

			} else if (blk.nodeName == "DpchEngWdbeUntRecData") {
				srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeUntRec", "srefIxWdbeVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeUntRec", "srefIxWdbeVExpstate");

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

