function updateScrJrefs() {
	scrJrefDetail = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefDetail");
	scrJrefKHdltype = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefKHdltype");
	scrJrefAPar = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefAPar");
	scrJref1NPeripheral = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJref1NPeripheral");
	scrJrefMdl1NSignal = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefMdl1NSignal");
	scrJref1NProcess = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJref1NProcess");
	scrJrefMdl1NPort = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefMdl1NPort");
	scrJrefCor1NImbuf = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefCor1NImbuf");
	scrJrefMdl1NGeneric = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefMdl1NGeneric");
	scrJrefSup1NModule = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefSup1NModule");
	scrJrefMge1NSignal = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefMge1NSignal");
	scrJrefCtrRef1NCommand = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefCtrRef1NCommand");
	scrJrefCtrRef1NError = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefCtrRef1NError");
	scrJrefCtrHk1NVector = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefCtrHk1NVector");
	scrJrefCtrMNCommand = retrieveSi(srcdoc, "StatShrWdbeModRec", "scrJrefCtrMNCommand");
};

function resetInitdones() {
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneDetail", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneKHdltype", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneAPar", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdone1NPeripheral", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneMdl1NSignal", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdone1NProcess", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneMdl1NPort", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneCor1NImbuf", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneMdl1NGeneric", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneSup1NModule", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneMge1NSignal", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneCtrRef1NCommand", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneCtrRef1NError", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneCtrHk1NVector", "false");
	setSi(srcdoc, "StatAppWdbeModRec", "initdoneCtrMNCommand", "false");
};

function resetHeights() {
	heightDetail = 30;
	heightKHdltype = 30;
	heightAPar = 30;
	height1NPeripheral = 30;
	heightMdl1NSignal = 30;
	height1NProcess = 30;
	heightMdl1NPort = 30;
	heightCor1NImbuf = 30;
	heightMdl1NGeneric = 30;
	heightSup1NModule = 30;
	heightMge1NSignal = 30;
	heightCtrRef1NCommand = 30;
	heightCtrRef1NError = 30;
	heightCtrHk1NVector = 30;
	heightCtrMNCommand = 30;
};

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWdbeModRec", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWdbeModRec", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneDetail") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneAPar") == "true");
	var initdone1NRelease = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdone1NRelease") == "true");

	var initdoneDetail = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneDetail") == "true");
	var initdoneKHdltype = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneKHdltype") == "true");
	var initdoneAPar = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneAPar") == "true");
	var initdone1NPeripheral = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdone1NPeripheral") == "true");
	var initdoneMdl1NSignal = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneMdl1NSignal") == "true");
	var initdone1NProcess = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdone1NProcess") == "true");
	var initdoneMdl1NPort = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneMdl1NPort") == "true");
	var initdoneCor1NImbuf = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneCor1NImbuf") == "true");
	var initdoneMdl1NGeneric = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneMdl1NGeneric") == "true");
	var initdoneSup1NModule = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneSup1NModule") == "true");
	var initdoneMge1NSignal = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneMge1NSignal") == "true");
	var initdoneCtrRef1NCommand = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneCtrRef1NCommand") == "true");
	var initdoneCtrRef1NError = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneCtrRef1NError") == "true");
	var initdoneCtrHk1NVector = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneCtrHk1NVector") == "true");
	var initdoneCtrMNCommand = (retrieveSi(srcdoc, "StatAppWdbeModRec", "initdoneCtrMNCommand") == "true");

	if (!initdoneDetail) {
		lhsdoc.getElementById("Detail").src = "./PnlWdbeModDetail.html?scrJref=" + scrJrefDetail;
	} else if (!initdoneKHdltype) {
		lhsdoc.getElementById("KHdltype").src = "./PnlWdbeModKHdltype.html?scrJref=" + scrJrefKHdltype;
	} else if (!initdoneAPar) {
		lhsdoc.getElementById("APar").src = "./PnlWdbeModAPar.html?scrJref=" + scrJrefAPar;
	} else if (!initdone1NPeripheral) {
		rhsdoc.getElementById("1NPeripheral").src = "./PnlWdbeMod1NPeripheral.html?scrJref=" + scrJref1NPeripheral;
	} else if (!initdoneMdl1NSignal) {
		rhsdoc.getElementById("Mdl1NSignal").src = "./PnlWdbeModMdl1NSignal.html?scrJref=" + scrJrefMdl1NSignal;
	} else if (!initdone1NProcess) {
		rhsdoc.getElementById("1NProcess").src = "./PnlWdbeMod1NProcess.html?scrJref=" + scrJref1NProcess;
	} else if (!initdoneMdl1NPort) {
		rhsdoc.getElementById("Mdl1NPort").src = "./PnlWdbeModMdl1NPort.html?scrJref=" + scrJrefMdl1NPort;
	} else if (!initdoneCor1NImbuf) {
		rhsdoc.getElementById("Cor1NImbuf").src = "./PnlWdbeModCor1NImbuf.html?scrJref=" + scrJrefCor1NImbuf;
	} else if (!initdoneMdl1NGeneric) {
		rhsdoc.getElementById("Mdl1NGeneric").src = "./PnlWdbeModMdl1NGeneric.html?scrJref=" + scrJrefMdl1NGeneric;
	} else if (!initdoneSup1NModule) {
		rhsdoc.getElementById("Sup1NModule").src = "./PnlWdbeModSup1NModule.html?scrJref=" + scrJrefSup1NModule;
	} else if (!initdoneMge1NSignal) {
		rhsdoc.getElementById("Mge1NSignal").src = "./PnlWdbeModMge1NSignal.html?scrJref=" + scrJrefMge1NSignal;
	} else if (!initdoneCtrRef1NCommand) {
		rhsdoc.getElementById("CtrRef1NCommand").src = "./PnlWdbeModCtrRef1NCommand.html?scrJref=" + scrJrefCtrRef1NCommand;
	} else if (!initdoneCtrRef1NError) {
		rhsdoc.getElementById("CtrRef1NError").src = "./PnlWdbeModCtrRef1NError.html?scrJref=" + scrJrefCtrRef1NError;
	} else if (!initdoneCtrHk1NVector) {
		rhsdoc.getElementById("CtrHk1NVector").src = "./PnlWdbeModCtrHk1NVector.html?scrJref=" + scrJrefCtrHk1NVector;
	} else if (!initdoneCtrMNCommand) {
		rhsdoc.getElementById("CtrMNCommand").src = "./PnlWdbeModCtrMNCommand.html?scrJref=" + scrJrefCtrMNCommand;

	} else {
		refreshB();
	};
};

function reinitPnl(scrJrefPnl) {
};

function setPnlAvail(short, avail) {
	var lhsrhsdoc;

	if ((short == "Detail") || (short == "KHdltype") || (short == "APar")) lhsrhsdoc = lhsdoc;
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
		else if (short == "APar") heightAPar = height;
		else if (short == "1NPeripheral") height1NPeripheral = height;
		else if (short == "Mdl1NSignal") heightMdl1NSignal = height;
		else if (short == "1NProcess") height1NProcess = height;
		else if (short == "Mdl1NPort") heightMdl1NPort = height;
		else if (short == "Cor1NImbuf") heightCor1NImbuf = height;
		else if (short == "Mdl1NGeneric") heightMdl1NGeneric = height;
		else if (short == "Sup1NModule") heightSup1NModule = height;
		else if (short == "Mge1NSignal") heightMge1NSignal = height;
		else if (short == "CtrRef1NCommand") heightCtrRef1NCommand = height;
		else if (short == "CtrRef1NError") heightCtrRef1NError = height;
		else if (short == "CtrHk1NVector") heightCtrHk1NVector = height;
		else if (short == "CtrMNCommand") heightCtrMNCommand = height;
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

	doc.getElementById("Rec_side").src = "./PnlWdbeModRec_aside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeModRec_a.html";
};

function regularize() {
	resetHeights();

	getCrdwnd().changeHeight("Rec", 567);
	doc.getElementById("tdSide").setAttribute("height", "567");
	doc.getElementById("Rec_side").setAttribute("height", "567");
	doc.getElementById("Rec_cont").setAttribute("height", "567");

	doc.getElementById("Rec_side").src = "./PnlWdbeModRec_bside.html";
	doc.getElementById("Rec_cont").src = "./PnlWdbeModRec_b.html";
};

function changeHeight(pnlshort, height, update) {
	var lhsrhsdoc;

	if ((pnlshort == "Detail") || (pnlshort == "KHdltype") || (pnlshort == "APar")) lhsrhsdoc = lhsdoc;
	else lhsrhsdoc = rhsdoc;

	lhsrhsdoc.getElementById("td" + pnlshort).setAttribute("height", "" + height);
	lhsrhsdoc.getElementById(pnlshort).setAttribute("height", "" + height);

	if (pnlshort == "Headbar") heightHeadbar = height;
	else if (pnlshort == "List") heightList = height;
	else if (pnlshort == "Rec") heightRec = height;
	else if (pnlshort == "Detail") heightDetail = height;
	else if (pnlshort == "KHdltype") heightKHdltype = height;
	else if (pnlshort == "APar") heightAPar = height;
	else if (pnlshort == "1NPeripheral") height1NPeripheral = height;
	else if (pnlshort == "Mdl1NSignal") heightMdl1NSignal = height;
	else if (pnlshort == "1NProcess") height1NProcess = height;
	else if (pnlshort == "Mdl1NPort") heightMdl1NPort = height;
	else if (pnlshort == "Cor1NImbuf") heightCor1NImbuf = height;
	else if (pnlshort == "Mdl1NGeneric") heightMdl1NGeneric = height;
	else if (pnlshort == "Sup1NModule") heightSup1NModule = height;
	else if (pnlshort == "Mge1NSignal") heightMge1NSignal = height;
	else if (pnlshort == "CtrRef1NCommand") heightCtrRef1NCommand = height;
	else if (pnlshort == "CtrRef1NError") heightCtrRef1NError = height;
	else if (pnlshort == "CtrHk1NVector") heightCtrHk1NVector = height;
	else if (pnlshort == "CtrMNCommand") heightCtrMNCommand = height;

	if (update) updateHeight();
};

function updateHeight() {
	var heightLhs, heightRhs, heightGt;

	heightLhs = heightDetail+13 + heightKHdltype+13 + heightAPar+13 + 5;
	heightRhs = height1NPeripheral+13 + heightMdl1NSignal+13 + height1NProcess+13 + heightMdl1NPort+13 + heightCor1NImbuf+13 + heightMdl1NGeneric+13 + heightSup1NModule+13 + heightMge1NSignal+13 + heightCtrRef1NCommand+13 + heightCtrRef1NError+13 + heightCtrHk1NVector+13 + heightCtrMNCommand+13 + 5;

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

	setTextContent(contdoc, contdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeModRec", "Cpt"));

	refreshA();
};

function initB() {
	if (!doc) return;

	sidedoc = doc.getElementById("Rec_side").contentDocument;
	contdoc = doc.getElementById("Rec_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Rec_hdr").contentDocument;
	lhsdoc = contdoc.getElementById("Rec_lhs").contentDocument;
	rhsdoc = contdoc.getElementById("Rec_rhs").contentDocument;

	setTextContent(hdrdoc, hdrdoc.getElementById("Cpt"), retrieveTi(srcdoc, "TagWdbeModRec", "Cpt"));

	checkInitdone();
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeModRec", "srefIxWdbeVExpstate");

	if (srefIxWdbeVExpstate == "mind") {
		minimize();
	} else if (srefIxWdbeVExpstate == "regd") {
		regularize();
	};
};

function refreshAside() {
	var ButRegularizeActive;

	ButRegularizeActive = (retrieveSi(srcdoc, "StatShrWdbeModRec", "ButRegularizeActive") == "true");

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
	setTextContent(contdoc, contdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeModRec", "TxtRef"));
};

function refreshB() {
	var updh = false;

	var pnlctrref1ncommandAvail = (retrieveSi(srcdoc, "StatShrWdbeModRec", "pnlctrref1ncommandAvail") == "true");
	var pnlctrref1nerrorAvail = (retrieveSi(srcdoc, "StatShrWdbeModRec", "pnlctrref1nerrorAvail") == "true");
	var pnlctrhk1nvectorAvail = (retrieveSi(srcdoc, "StatShrWdbeModRec", "pnlctrhk1nvectorAvail") == "true");
	var pnlctrmncommandAvail = (retrieveSi(srcdoc, "StatShrWdbeModRec", "pnlctrmncommandAvail") == "true");

	setTextContent(hdrdoc, hdrdoc.getElementById("TxtRef"), retrieveCi(srcdoc, "ContInfWdbeModRec", "TxtRef"));

	if (setPnlAvail("CtrRef1NCommand", pnlctrref1ncommandAvail)) updh = true;
	if (setPnlAvail("CtrRef1NError", pnlctrref1nerrorAvail)) updh = true;
	if (setPnlAvail("CtrHk1NVector", pnlctrhk1nvectorAvail)) updh = true;
	if (setPnlAvail("CtrMNCommand", pnlctrmncommandAvail)) updh = true;

	if (updh) updateHeight();
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeModRec", "srefIxWdbeVExpstate");

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeModRecDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeModRecData", "ContInfWdbeModRec", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeModRecData", "StatAppWdbeModRec", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeModRecData", "StatShrWdbeModRec", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeModRecData", "TagWdbeModRec", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (!srcdoc) return;

	var _scrJref, mask;
	var srefIxWdbeVExpstate, newSrefIxWdbeVExpstate;

	_scrJref = retrieveValue(dom, "//wdbe:*/wdbe:scrJref");
	srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeModRec", "srefIxWdbeVExpstate");

	if (_scrJref == scrJref) {
		if (dpch == "DpchEngWdbeModRecData") {
			mask = mergeDpchEngData(dom);

			if (mask.indexOf("statshr") != -1) {
				newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeModRec", "srefIxWdbeVExpstate");

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
			} else if (_scrJref == scrJrefAPar) {
				if (getInitdone("APar")) lhsdoc.getElementById("APar").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NPeripheral) {
				if (getInitdone("1NPeripheral")) rhsdoc.getElementById("1NPeripheral").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMdl1NSignal) {
				if (getInitdone("Mdl1NSignal")) rhsdoc.getElementById("Mdl1NSignal").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJref1NProcess) {
				if (getInitdone("1NProcess")) rhsdoc.getElementById("1NProcess").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMdl1NPort) {
				if (getInitdone("Mdl1NPort")) rhsdoc.getElementById("Mdl1NPort").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefCor1NImbuf) {
				if (getInitdone("Cor1NImbuf")) rhsdoc.getElementById("Cor1NImbuf").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMdl1NGeneric) {
				if (getInitdone("Mdl1NGeneric")) rhsdoc.getElementById("Mdl1NGeneric").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefSup1NModule) {
				if (getInitdone("Sup1NModule")) rhsdoc.getElementById("Sup1NModule").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefMge1NSignal) {
				if (getInitdone("Mge1NSignal")) rhsdoc.getElementById("Mge1NSignal").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefCtrRef1NCommand) {
				if (getInitdone("CtrRef1NCommand")) rhsdoc.getElementById("CtrRef1NCommand").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefCtrRef1NError) {
				if (getInitdone("CtrRef1NError")) rhsdoc.getElementById("CtrRef1NError").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefCtrHk1NVector) {
				if (getInitdone("CtrHk1NVector")) rhsdoc.getElementById("CtrHk1NVector").contentWindow.handleDpchEng(dom, dpch);
			} else if (_scrJref == scrJrefCtrMNCommand) {
				if (getInitdone("CtrMNCommand")) rhsdoc.getElementById("CtrMNCommand").contentWindow.handleDpchEng(dom, dpch);
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
			if (blk.nodeName == "DpchEngWdbeModRecData") {
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

			} else if (blk.nodeName == "DpchEngWdbeModRecData") {
				srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeModRec", "srefIxWdbeVExpstate");

				mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					newSrefIxWdbeVExpstate = retrieveSi(srcdoc, "StatShrWdbeModRec", "srefIxWdbeVExpstate");

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
