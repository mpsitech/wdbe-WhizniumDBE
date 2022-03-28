function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefDetail");
	scrJrefKParKey = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefKParKey");
	scrJrefKHdltype = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefKHdltype");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefAPar");
	scrJrefMdl1NGeneric = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefMdl1NGeneric");
	scrJrefTpl1NModule = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefTpl1NModule");
	scrJrefHsm1NPipeline = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefHsm1NPipeline");
	scrJrefMdl1NPort = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefMdl1NPort");
	scrJrefSup1NModule = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefSup1NModule");
	scrJrefRef1NSensitivity = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefRef1NSensitivity");
	scrJrefRef1NVariable = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefRef1NVariable");
	scrJrefMge1NSignal = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefMge1NSignal");
	scrJrefRef1NFile = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "scrJrefRef1NFile");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneKParKey", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneKHdltype", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneMdl1NGeneric", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneTpl1NModule", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneHsm1NPipeline", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneMdl1NPort", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneSup1NModule", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneRef1NSensitivity", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneRef1NVariable", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneMge1NSignal", "false");
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdoneRef1NFile", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightKParKey = 30;
	heightKHdltype = 30;
	heightAPar = 30;
	heightMdl1NGeneric = 30;
	heightTpl1NModule = 30;
	heightHsm1NPipeline = 30;
	heightMdl1NPort = 30;
	heightSup1NModule = 30;
	heightRef1NSensitivity = 30;
	heightRef1NVariable = 30;
	heightMge1NSignal = 30;
	heightRef1NFile = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWdbeMtpRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneDetail") == "true");
	var initdoneKParKey = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneKParKey") == "true");
	var initdoneKHdltype = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneKHdltype") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneAPar") == "true");
	var initdoneMdl1NGeneric = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneMdl1NGeneric") == "true");
	var initdoneTpl1NModule = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneTpl1NModule") == "true");
	var initdoneHsm1NPipeline = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneHsm1NPipeline") == "true");
	var initdoneMdl1NPort = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneMdl1NPort") == "true");
	var initdoneSup1NModule = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneSup1NModule") == "true");
	var initdoneRef1NSensitivity = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneRef1NSensitivity") == "true");
	var initdoneRef1NVariable = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneRef1NVariable") == "true");
	var initdoneMge1NSignal = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneMge1NSignal") == "true");
	var initdoneRef1NFile = (retrieveSi(srcdoc, "StatAppWdbeMtpRec", "initdoneRef1NFile") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWdbeMtpDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneKParKey) {
		lhsdoc.getElementById("KParKey").src = "./PnlWdbeMtpKParKey.html?scrJref=" + scrJrefKParKey;
	} else if (!initdoneKHdltype) {
		lhsdoc.getElementById("KHdltype").src = "./PnlWdbeMtpKHdltype.html?scrJref=" + scrJrefKHdltype;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlWdbeMtpAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdoneMdl1NGeneric) {
		rhsdoc.getElementById("Mdl1NGeneric").src = "./PnlWdbeMtpMdl1NGeneric.html?scrJref=" + scrJrefMdl1NGeneric;
	} else if (!initdoneTpl1NModule) {
		rhsdoc.getElementById("Tpl1NModule").src = "./PnlWdbeMtpTpl1NModule.html?scrJref=" + scrJrefTpl1NModule;
	} else if (!initdoneHsm1NPipeline) {
		rhsdoc.getElementById("Hsm1NPipeline").src = "./PnlWdbeMtpHsm1NPipeline.html?scrJref=" + scrJrefHsm1NPipeline;
	} else if (!initdoneMdl1NPort) {
		rhsdoc.getElementById("Mdl1NPort").src = "./PnlWdbeMtpMdl1NPort.html?scrJref=" + scrJrefMdl1NPort;
	} else if (!initdoneSup1NModule) {
		rhsdoc.getElementById("Sup1NModule").src = "./PnlWdbeMtpSup1NModule.html?scrJref=" + scrJrefSup1NModule;
	} else if (!initdoneRef1NSensitivity) {
		rhsdoc.getElementById("Ref1NSensitivity").src = "./PnlWdbeMtpRef1NSensitivity.html?scrJref=" + scrJrefRef1NSensitivity;
	} else if (!initdoneRef1NVariable) {
		rhsdoc.getElementById("Ref1NVariable").src = "./PnlWdbeMtpRef1NVariable.html?scrJref=" + scrJrefRef1NVariable;
	} else if (!initdoneMge1NSignal) {
		rhsdoc.getElementById("Mge1NSignal").src = "./PnlWdbeMtpMge1NSignal.html?scrJref=" + scrJrefMge1NSignal;
	} else if (!initdoneRef1NFile) {
		rhsdoc.getElementById("Ref1NFile").src = "./PnlWdbeMtpRef1NFile.html?scrJref=" + scrJrefRef1NFile;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "KParKey") || (short == "KHdltype") || (short == "APar")) lhsrhsdoc = lhsdoc;
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
		else if (short == "KParKey") heightKParKey = height;
		else if (short == "KHdltype") heightKHdltype = height;
		else if (short == "APar") heightAPar = height;
		else if (short == "Mdl1NGeneric") heightMdl1NGeneric = height;
		else if (short == "Tpl1NModule") heightTpl1NModule = height;
		else if (short == "Hsm1NPipeline") heightHsm1NPipeline = height;
		else if (short == "Mdl1NPort") heightMdl1NPort = height;
		else if (short == "Sup1NModule") heightSup1NModule = height;
		else if (short == "Ref1NSensitivity") heightRef1NSensitivity = height;
		else if (short == "Ref1NVariable") heightRef1NVariable = height;
		else if (short == "Mge1NSignal") heightMge1NSignal = height;
		else if (short == "Ref1NFile") heightRef1NFile = height;
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

	doc.getElementById("Rec_side").src = "./PnlWdbeMtpRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeMtpRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 438);
	doc.getElementById("tdSide").setAttribute("height", "438");
	doc.getElementById("Rec_side").setAttribute("height", "438");
	doc.getElementById("Rec_cont").setAttribute("height", "438");

	doc.getElementById("Rec_side").src = "./PnlWdbeMtpRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeMtpRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "KParKey") || (pnlshort == "KHdltype") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "KParKey") heightKParKey = height;
	else if (pnlshort == "KHdltype") heightKHdltype = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "Mdl1NGeneric") heightMdl1NGeneric = height;
	else if (pnlshort == "Tpl1NModule") heightTpl1NModule = height;
	else if (pnlshort == "Hsm1NPipeline") heightHsm1NPipeline = height;
	else if (pnlshort == "Mdl1NPort") heightMdl1NPort = height;
	else if (pnlshort == "Sup1NModule") heightSup1NModule = height;
	else if (pnlshort == "Ref1NSensitivity") heightRef1NSensitivity = height;
	else if (pnlshort == "Ref1NVariable") heightRef1NVariable = height;
	else if (pnlshort == "Mge1NSignal") heightMge1NSignal = height;
	else if (pnlshort == "Ref1NFile") heightRef1NFile = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightKParKey+13 + heightKHdltype+13 + heightAPar+13 + 5;
	heightRhs = heightMdl1NGeneric+13 + heightTpl1NModule+13 + heightHsm1NPipeline+13 + heightMdl1NPort+13 + heightSup1NModule+13 + heightRef1NSensitivity+13 + heightRef1NVariable+13 + heightMge1NSignal+13 + heightRef1NFile+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeMtpRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeMtpRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		minimize();
	} else if (srefIxWdbeVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWdbeMtpRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeMtpRec", "TxtRef"));
};

function refreshB() {

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeMtpRec", "TxtRef"));

};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "srefIxWdbeVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeMtpRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeMtpRecData", "ContInfWdbeMtpRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeMtpRecData", "StatAppWdbeMtpRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeMtpRecData", "StatShrWdbeMtpRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeMtpRecData", "TagWdbeMtpRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWdbeVExpstate, newSrefIxWdbeVExpstate;

	_scrJref = retrieveValue(dom, "//wdbe:*/wdbe:scrJref");
	srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "srefIxWdbeVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWdbeMtpRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "srefIxWdbeVExpstate");

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
			} else if (_scrJref == scrJrefKParKey) {
				if (getInitdone("KParKey")) lhsdoc.getElementById("KParKey").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefKHdltype) {
				if (getInitdone("KHdltype")) lhsdoc.getElementById("KHdltype").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefAPar) {
				if (getInitdone("APar")) lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMdl1NGeneric) {
				if (getInitdone("Mdl1NGeneric")) rhsdoc.getElementById("Mdl1NGeneric").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefTpl1NModule) {
				if (getInitdone("Tpl1NModule")) rhsdoc.getElementById("Tpl1NModule").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefHsm1NPipeline) {
				if (getInitdone("Hsm1NPipeline")) rhsdoc.getElementById("Hsm1NPipeline").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMdl1NPort) {
				if (getInitdone("Mdl1NPort")) rhsdoc.getElementById("Mdl1NPort").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NModule) {
				if (getInitdone("Sup1NModule")) rhsdoc.getElementById("Sup1NModule").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NSensitivity) {
				if (getInitdone("Ref1NSensitivity")) rhsdoc.getElementById("Ref1NSensitivity").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NVariable) {
				if (getInitdone("Ref1NVariable")) rhsdoc.getElementById("Ref1NVariable").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMge1NSignal) {
				if (getInitdone("Mge1NSignal")) rhsdoc.getElementById("Mge1NSignal").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefRef1NFile) {
				if (getInitdone("Ref1NFile")) rhsdoc.getElementById("Ref1NFile").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWdbeMtpRecData") {
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

			} else if (blk.nodeName == "DpchEngWdbeMtpRecData") {
				srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "srefIxWdbeVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeMtpRec", "srefIxWdbeVExpstate");

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
