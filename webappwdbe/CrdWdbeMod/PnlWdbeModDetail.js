// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbeModDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeModDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbeModDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeModDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeModDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeModDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbeModDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbeModDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeModDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbeModDetail", "CptSrf"));
	initCpt(contcontdoc, "CptVnd", retrieveTi(srcdoc, "TagWdbeModDetail", "CptVnd"));
	initCpt(contcontdoc, "CptTyp", retrieveTi(srcdoc, "TagWdbeModDetail", "CptTyp"));
	refreshPup(contcontdoc, srcdoc, "PupTyp", "", "FeedFPupTyp", retrieveCi(srcdoc, "ContIacWdbeModDetail", "numFPupTyp"), retrieveSi(srcdoc, "StatShrWdbeModDetail", "PupTypActive"), false);
	initCpt(contcontdoc, "CptHku", retrieveTi(srcdoc, "TagWdbeModDetail", "CptHku"));
	refreshPup(contcontdoc, srcdoc, "PupHkt", "xs", "FeedFPupHkt", retrieveCi(srcdoc, "ContIacWdbeModDetail", "numFPupHkt"), true, false);
	initCpt(contcontdoc, "CptSup", retrieveTi(srcdoc, "TagWdbeModDetail", "CptSup"));
	initCpt(contcontdoc, "CptTpl", retrieveTi(srcdoc, "TagWdbeModDetail", "CptTpl"));
	initCpt(contcontdoc, "CptSrr", retrieveTi(srcdoc, "TagWdbeModDetail", "CptSrr"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbeModDetail", "CptCmt"));
	initCpt(contcontdoc, "CptImbFsr", retrieveTi(srcdoc, "TagWdbeModDetail", "CptImbFsr"));
	initCpt(contcontdoc, "CptImbRty", retrieveTi(srcdoc, "TagWdbeModDetail", "CptImbRty"));
	refreshPup(contcontdoc, srcdoc, "PupImbRty", "", "FeedFPupImbRty", retrieveCi(srcdoc, "ContIacWdbeModDetail", "numFPupImbRty"), retrieveSi(srcdoc, "StatShrWdbeModDetail", "PupImbRtyActive"), false);
	initCpt(contcontdoc, "CptImbWid", retrieveTi(srcdoc, "TagWdbeModDetail", "CptImbWid"));
	initCpt(contcontdoc, "CptImbMmx", retrieveTi(srcdoc, "TagWdbeModDetail", "CptImbMmx"));
	initCpt(contcontdoc, "CptImbPri", retrieveTi(srcdoc, "TagWdbeModDetail", "CptImbPri"));
	initCpt(contcontdoc, "CptCtrFsr", retrieveTi(srcdoc, "TagWdbeModDetail", "CptCtrFsr"));
	initCpt(contcontdoc, "CptCtrClr", retrieveTi(srcdoc, "TagWdbeModDetail", "CptCtrClr"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeModDetail", "srefIxWdbeVExpstate");

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

	var height = 506; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxtSrfActive") == "true");

	var PupVndAlt = (retrieveSi(srcdoc, "StatAppWdbeModDetail", "PupVndAlt") == "true");
	var TxfVndValid = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfVndValid") == "true");
	var PupVndActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "PupVndActive") == "true");
	var ButVndEditAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButVndEditAvail") == "true");

	var PupTypActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "PupTypActive") == "true");

	var TxtHkuActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxtHkuActive") == "true");
	var ButHkuViewAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButHkuViewAvail") == "true");
	var ButHkuViewActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButHkuViewActive") == "true");

	var TxtSupActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxtSupActive") == "true");
	var ButSupViewAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButSupViewAvail") == "true");
	var ButSupViewActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButSupViewActive") == "true");

	var TxtTplActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxtTplActive") == "true");
	var ButTplViewAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButTplViewAvail") == "true");
	var ButTplViewActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButTplViewActive") == "true");

	var TxfSrrActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfSrrActive") == "true");

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfCmtActive") == "true");

	var SepImbAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "SepImbAvail") == "true");

	var HdgImbAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "HdgImbAvail") == "true");
	var ButImbNewAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButImbNewAvail") == "true");
	var ButImbDeleteAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButImbDeleteAvail") == "true");

	var TxfImbFsrAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfImbFsrAvail") == "true");
	var TxfImbFsrActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfImbFsrActive") == "true");

	var PupImbRtyAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "PupImbRtyAvail") == "true");
	var PupImbRtyActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "PupImbRtyActive") == "true");

	var TxfImbWidAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfImbWidAvail") == "true");
	var TxfImbWidActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfImbWidActive") == "true");

	var TxfImbMmxAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfImbMmxAvail") == "true");
	var TxfImbMmxActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfImbMmxActive") == "true");

	var TxfImbPriAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfImbPriAvail") == "true");
	var TxfImbPriActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfImbPriActive") == "true");

	var SepCtrAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "SepCtrAvail") == "true");

	var HdgCtrAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "HdgCtrAvail") == "true");
	var ButCtrNewAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButCtrNewAvail") == "true");
	var ButCtrDeleteAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButCtrDeleteAvail") == "true");

	var TxfCtrFsrAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfCtrFsrAvail") == "true");
	var TxfCtrFsrActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxfCtrFsrActive") == "true");

	var TxtCtrClrAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxtCtrClrAvail") == "true");
	var TxtCtrClrActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "TxtCtrClrActive") == "true");
	var ButCtrClrViewAvail = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButCtrClrViewAvail") == "true");
	var ButCtrClrViewActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButCtrClrViewActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbeModDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbeModDetail", "TxtSrf"));

	if ( (PupVndAlt == !contcontdoc.getElementById("TxfVnd")) || (!PupVndAlt == !contcontdoc.getElementById("PupVnd")) ) {
		mytd = contcontdoc.getElementById("dynVnd");
		clearElem(mytd);

		if (PupVndAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfVnd", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupVnd", ""));
	};

	if (PupVndAlt) refreshTxf(contcontdoc, "TxfVnd", "", retrieveCi(srcdoc, "ContIacWdbeModDetail", "TxfVnd"), PupVndActive, false, TxfVndValid);
	else refreshPup(contcontdoc, srcdoc, "PupVnd", "", "FeedFPupVnd", retrieveCi(srcdoc, "ContIacWdbeModDetail", "numFPupVnd"), true, false);

	if ((ButVndEditAvail == !contcontdoc.getElementById("ButVndEdit"))) {
		mytd = contcontdoc.getElementById("rdynVnd");
		clearElem(mytd);

		first = true;

		if (ButVndEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVndEdit", "icon/edit"));
		};
	};

	contcontdoc.getElementById("PupTyp").value = retrieveCi(srcdoc, "ContIacWdbeModDetail", "numFPupTyp");

	if ((ButHkuViewAvail == !contcontdoc.getElementById("ButHkuView"))) {
		mytd = contcontdoc.getElementById("rdynHku");
		clearElem(mytd);

		first = true;

		if (ButHkuViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButHkuView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtHku", retrieveCi(srcdoc, "ContInfWdbeModDetail", "TxtHku"));
	contcontdoc.getElementById("PupHkt").value = retrieveCi(srcdoc, "ContIacWdbeModDetail", "numFPupHkt");

	if (ButHkuViewAvail) refreshButicon(contcontdoc, "ButHkuView", "icon/view", ButHkuViewActive, false);

	if ((ButSupViewAvail == !contcontdoc.getElementById("ButSupView"))) {
		mytd = contcontdoc.getElementById("rdynSup");
		clearElem(mytd);

		first = true;

		if (ButSupViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSupView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtSup", retrieveCi(srcdoc, "ContInfWdbeModDetail", "TxtSup"));

	if (ButSupViewAvail) refreshButicon(contcontdoc, "ButSupView", "icon/view", ButSupViewActive, false);

	if ((ButTplViewAvail == !contcontdoc.getElementById("ButTplView"))) {
		mytd = contcontdoc.getElementById("rdynTpl");
		clearElem(mytd);

		first = true;

		if (ButTplViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButTplView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtTpl", retrieveCi(srcdoc, "ContInfWdbeModDetail", "TxtTpl"));

	if (ButTplViewAvail) refreshButicon(contcontdoc, "ButTplView", "icon/view", ButTplViewActive, false);

	refreshTxf(contcontdoc, "TxfSrr", "", retrieveCi(srcdoc, "ContIacWdbeModDetail", "TxfSrr"), TxfSrrActive, false, true);

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbeModDetail", "TxfCmt"), TxfCmtActive, false, true);

	height -= setCtlAvail(contcontdoc, "Imb1", SepImbAvail, 0);
	setCtlAvail(contcontdoc, "Imb2", SepImbAvail, 7);
	setCtlAvail(contcontdoc, "Imb3", SepImbAvail, 0);
	if (SepImbAvail) {

	};

	height -= setCtlAvail(contcontdoc, "Imb", HdgImbAvail, 25);
	if (HdgImbAvail) {
		if ((ButImbNewAvail == !contcontdoc.getElementById("ButImbNew")) || (ButImbDeleteAvail == !contcontdoc.getElementById("ButImbDelete"))) {
			mytd = contcontdoc.getElementById("dynImb");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "HdgImb", retrieveTi(srcdoc, "TagWdbeModDetail", "HdgImb")));
			mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

			first = true;

			if (ButImbNewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButImbNew", "icon/new"));
			};

			if (ButImbDeleteAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButImbDelete", "icon/delete"));
			};
		};

	};

	height -= setCtlAvail(contcontdoc, "ImbFsr", TxfImbFsrAvail, 25);
	if (TxfImbFsrAvail) {
		refreshTxf(contcontdoc, "TxfImbFsr", "", retrieveCi(srcdoc, "ContIacWdbeModDetail", "TxfImbFsr"), TxfImbFsrActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "ImbRty", PupImbRtyAvail, 25);
	if (PupImbRtyAvail) {
		contcontdoc.getElementById("PupImbRty").value = retrieveCi(srcdoc, "ContIacWdbeModDetail", "numFPupImbRty");

	};

	height -= setCtlAvail(contcontdoc, "ImbWid", TxfImbWidAvail, 25);
	if (TxfImbWidAvail) {
		refreshTxf(contcontdoc, "TxfImbWid", "s", retrieveCi(srcdoc, "ContIacWdbeModDetail", "TxfImbWid"), TxfImbWidActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "ImbMmx", TxfImbMmxAvail, 25);
	if (TxfImbMmxAvail) {
		refreshTxf(contcontdoc, "TxfImbMmx", "s", retrieveCi(srcdoc, "ContIacWdbeModDetail", "TxfImbMmx"), TxfImbMmxActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "ImbPri", TxfImbPriAvail, 25);
	if (TxfImbPriAvail) {
		refreshTxf(contcontdoc, "TxfImbPri", "s", retrieveCi(srcdoc, "ContIacWdbeModDetail", "TxfImbPri"), TxfImbPriActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "Ctr1", SepCtrAvail, 0);
	setCtlAvail(contcontdoc, "Ctr2", SepCtrAvail, 7);
	setCtlAvail(contcontdoc, "Ctr3", SepCtrAvail, 0);
	if (SepCtrAvail) {

	};

	height -= setCtlAvail(contcontdoc, "Ctr", HdgCtrAvail, 25);
	if (HdgCtrAvail) {
		if ((ButCtrNewAvail == !contcontdoc.getElementById("ButCtrNew")) || (ButCtrDeleteAvail == !contcontdoc.getElementById("ButCtrDelete"))) {
			mytd = contcontdoc.getElementById("dynCtr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "HdgCtr", retrieveTi(srcdoc, "TagWdbeModDetail", "HdgCtr")));
			mytd.appendChild(contcontdoc.createTextNode("\u00a0\u00a0"));

			first = true;

			if (ButCtrNewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCtrNew", "icon/new"));
			};

			if (ButCtrDeleteAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCtrDelete", "icon/delete"));
			};
		};

	};

	height -= setCtlAvail(contcontdoc, "CtrFsr", TxfCtrFsrAvail, 25);
	if (TxfCtrFsrAvail) {
		refreshTxf(contcontdoc, "TxfCtrFsr", "", retrieveCi(srcdoc, "ContIacWdbeModDetail", "TxfCtrFsr"), TxfCtrFsrActive, false, true);

	};

	height -= setCtlAvail(contcontdoc, "CtrClr", TxtCtrClrAvail, 25);
	if (TxtCtrClrAvail) {
		if ((ButCtrClrViewAvail == !contcontdoc.getElementById("ButCtrClrView"))) {
			mytd = contcontdoc.getElementById("rdynCtrClr");
			clearElem(mytd);

			first = true;

			if (ButCtrClrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCtrClrView", "icon/view"));
			};
		};

		refreshTxt(contcontdoc, "TxtCtrClr", retrieveCi(srcdoc, "ContInfWdbeModDetail", "TxtCtrClr"));

		if (ButCtrClrViewAvail) refreshButicon(contcontdoc, "ButCtrClrView", "icon/view", ButCtrClrViewActive, false);

	};

	refreshButicon(ftrdoc, "ButSave", "icon/save", ButSaveActive, false);
	// IP refreshBD --- END

	getRecwnd().changeHeight("Detail", height+26, true);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_side").setAttribute("height", "" + (height+26));
	doc.getElementById("Detail_cont").setAttribute("height", "" + (height+26));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+26-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Detail_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeModDetail", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("Detail_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButMinimizeClick() {
	minimize(true);
};

function handleButRegularizeClick() {
	regularize(true);
};

// --- generalized event handlers for app controls

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppWdbeModDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWdbeModDetail", basectlsref + "Alt", alt);

	refresh();
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeModDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeModDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeModDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbeModDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeModDetailData", scrJref, "ContIacWdbeModDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbeModDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbeModDetailData", scrJref, "ContIacWdbeModDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbeModDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeModDetailData", scrJref, "ContIacWdbeModDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxftKey(_doc, ctlsref, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	return true;
};

function handleTxftChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txfmod");

	setCi(srcdoc, "ContIacWdbeModDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeModDetailData", scrJref, "ContIacWdbeModDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWdbeModDetailData", "ContIacWdbeModDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeModDetailData", "ContInfWdbeModDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeModDetailData", "FeedFPupHkt", srcdoc)) mask.push("feedFPupHkt");
	if (updateSrcblock(dom, "DpchEngWdbeModDetailData", "FeedFPupImbRty", srcdoc)) mask.push("feedFPupImbRty");
	if (updateSrcblock(dom, "DpchEngWdbeModDetailData", "FeedFPupTyp", srcdoc)) mask.push("feedFPupTyp");
	if (updateSrcblock(dom, "DpchEngWdbeModDetailData", "FeedFPupVnd", srcdoc)) mask.push("feedFPupVnd");
	if (updateSrcblock(dom, "DpchEngWdbeModDetailData", "StatAppWdbeModDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeModDetailData", "StatShrWdbeModDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeModDetailData", "TagWdbeModDetail", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeModDetailData") {
		mergeDpchEngData(dom);
		refresh();
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWdbeModDetailData") {
				mergeDpchEngData(dom);
				init();

				getRecwnd().setInitdone("Detail");
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

			} else if (blk.nodeName == "DpchEngWdbeModDetailData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

function handleDpchAppDoCrdopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWdbeConfirm") {
				accepted = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:accepted");
				_scrJref = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:scrJref");
				sref = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:sref");

				if (accepted == "true") window.open("/web/" + sref + "/" + sref + ".html?scrJref=" + _scrJref, "_blank");

			} else if (blk.nodeName == "DpchEngWdbeAlert") {
				getCrdwnd().showAlr(retrieveValue(dom, "//wdbe:DpchEngWdbeAlert/wdbe:scrJref"),
						retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:ContInfWdbeAlert"),
						retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:FeedFMcbAlert"));
			};
		};
	};
};

function handleDpchAppDoDlgopenReply() {
	var dom, blk;

	var accepted, _scrJref, sref;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWdbeConfirm") {
				accepted = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:accepted");
				_scrJref = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:scrJref");
				sref = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:sref");

				if ((accepted == "true") && (sref != "")) getCrdwnd().showDlg(sref, _scrJref);
			};
		};
	};
};
