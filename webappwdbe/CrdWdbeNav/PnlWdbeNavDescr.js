/**
  * \file PnlWdbeNavDescr.js
  * web client functionality for panel PnlWdbeNavDescr
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeNavDescr", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Descr", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Descr_side").setAttribute("height", "30");
	doc.getElementById("Descr_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Descr_side").src = "./PnlWdbeNavDescr_aside.html";
	doc.getElementById("Descr_cont").src = "./PnlWdbeNavDescr_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeNavDescr", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Descr_side").src = "./PnlWdbeNavDescr_bside.html";
	doc.getElementById("Descr_cont").src = "./PnlWdbeNavDescr_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Descr_side").contentDocument;
	contdoc = doc.getElementById("Descr_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavDescr", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Descr_side").contentDocument;
	contdoc = doc.getElementById("Descr_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Descr_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Descr_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavDescr", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavDescr", "srefIxWdbeVExpstate");

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

	var height = 1354; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstModAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstModAlt") == "true");
	var LstModAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstModAvail") == "true");
	var ButModViewAvail = !LstModAlt;
	var ButModViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButModViewActive") == "true");
	var ButModNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButModNewcrdActive") == "true");

	var LstVecAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstVecAlt") == "true");
	var LstVecAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstVecAvail") == "true");
	var ButVecViewAvail = !LstVecAlt;
	var ButVecViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButVecViewActive") == "true");
	var ButVecNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButVecNewcrdActive") == "true");

	var LstVitAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstVitAlt") == "true");
	var LstVitAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstVitAvail") == "true");
	var ButVitViewAvail = !LstVitAlt;
	var ButVitViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButVitViewActive") == "true");

	var LstCmdAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstCmdAlt") == "true");
	var LstCmdAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstCmdAvail") == "true");
	var ButCmdViewAvail = !LstCmdAlt;
	var ButCmdViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButCmdViewActive") == "true");
	var ButCmdNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButCmdNewcrdActive") == "true");

	var LstErrAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstErrAlt") == "true");
	var LstErrAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstErrAvail") == "true");
	var ButErrViewAvail = !LstErrAlt;
	var ButErrViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButErrViewActive") == "true");
	var ButErrNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButErrNewcrdActive") == "true");

	var LstPphAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstPphAlt") == "true");
	var LstPphAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstPphAvail") == "true");
	var ButPphViewAvail = !LstPphAlt;
	var ButPphViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButPphViewActive") == "true");
	var ButPphNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButPphNewcrdActive") == "true");

	var LstBnkAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstBnkAlt") == "true");
	var LstBnkAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstBnkAvail") == "true");
	var ButBnkViewAvail = !LstBnkAlt;
	var ButBnkViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButBnkViewActive") == "true");
	var ButBnkNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButBnkNewcrdActive") == "true");

	var LstPinAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstPinAlt") == "true");
	var LstPinAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstPinAvail") == "true");
	var ButPinViewAvail = !LstPinAlt;
	var ButPinViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButPinViewActive") == "true");
	var ButPinNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButPinNewcrdActive") == "true");

	var LstGenAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstGenAlt") == "true");
	var LstGenAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstGenAvail") == "true");
	var ButGenViewAvail = !LstGenAlt;
	var ButGenViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButGenViewActive") == "true");

	var LstPrtAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstPrtAlt") == "true");
	var LstPrtAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstPrtAvail") == "true");
	var ButPrtViewAvail = !LstPrtAlt;
	var ButPrtViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButPrtViewActive") == "true");

	var LstSigAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstSigAlt") == "true");
	var LstSigAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstSigAvail") == "true");
	var ButSigViewAvail = !LstSigAlt;
	var ButSigViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButSigViewActive") == "true");

	var LstPrcAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstPrcAlt") == "true");
	var LstPrcAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstPrcAvail") == "true");
	var ButPrcViewAvail = !LstPrcAlt;
	var ButPrcViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButPrcViewActive") == "true");

	var LstFstAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstFstAlt") == "true");
	var LstFstAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstFstAvail") == "true");
	var ButFstViewAvail = !LstFstAlt;
	var ButFstViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButFstViewActive") == "true");

	var LstVarAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstVarAlt") == "true");
	var LstVarAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "LstVarAvail") == "true");
	var ButVarViewAvail = !LstVarAlt;
	var ButVarViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDescr", "ButVarViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Mod", LstModAvail, 96);
	height -= setCtlAvail(contcontdoc, "Mod2", LstModAvail && !LstModAlt, (LstModAvail) ? 71 : 0);
	if (LstModAvail) {
		if ( (LstModAlt == !contcontdoc.getElementById("ButModExpand")) || (!LstModAlt == !contcontdoc.getElementById("ButModCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynMod");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptMod", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptMod")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstModAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButModExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButModCollapse", "icon/collapse"));
		};

		if (!LstModAlt == !contcontdoc.getElementById("LstMod")) {
			mytd = contcontdoc.getElementById("rdynMod");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynMod");
			clearElem(mytd);

			if (LstModAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstMod", "./PnlWdbeNavDescr_LstMod.xml", true));
			};

		} else {
			if (!LstModAlt) refreshLst(contcontdoc.getElementById("LstMod").contentWindow.document, srcdoc, 1, true, false, "FeedFLstMod",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstModNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstMod"))]);
		};

		if ((ButModViewAvail == !contcontdoc.getElementById("ButModView")) || !contcontdoc.getElementById("ButModNewcrd")) {
			if (LstModAlt) mytd = contcontdoc.getElementById("dynMod");
			else mytd = contcontdoc.getElementById("rdynMod");
			clearElem(mytd);

			first = true;

			if (ButModViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButModView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButModNewcrd", "icon/newcrd"));
		};

		if (ButModViewAvail) refreshButicon(contcontdoc, "ButModView", "icon/view", ButModViewActive, false);
		refreshButicon(contcontdoc, "ButModNewcrd", "icon/newcrd", ButModNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Mod2", false, 0);

	height -= setCtlAvail(contcontdoc, "Vec", LstVecAvail, 96);
	height -= setCtlAvail(contcontdoc, "Vec2", LstVecAvail && !LstVecAlt, (LstVecAvail) ? 71 : 0);
	if (LstVecAvail) {
		if ( (LstVecAlt == !contcontdoc.getElementById("ButVecExpand")) || (!LstVecAlt == !contcontdoc.getElementById("ButVecCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynVec");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVec", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptVec")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstVecAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButVecExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButVecCollapse", "icon/collapse"));
		};

		if (!LstVecAlt == !contcontdoc.getElementById("LstVec")) {
			mytd = contcontdoc.getElementById("rdynVec");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynVec");
			clearElem(mytd);

			if (LstVecAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVec", "./PnlWdbeNavDescr_LstVec.xml", true));
			};

		} else {
			if (!LstVecAlt) refreshLst(contcontdoc.getElementById("LstVec").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVec",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstVecNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstVec"))]);
		};

		if ((ButVecViewAvail == !contcontdoc.getElementById("ButVecView")) || !contcontdoc.getElementById("ButVecNewcrd")) {
			if (LstVecAlt) mytd = contcontdoc.getElementById("dynVec");
			else mytd = contcontdoc.getElementById("rdynVec");
			clearElem(mytd);

			first = true;

			if (ButVecViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButVecView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVecNewcrd", "icon/newcrd"));
		};

		if (ButVecViewAvail) refreshButicon(contcontdoc, "ButVecView", "icon/view", ButVecViewActive, false);
		refreshButicon(contcontdoc, "ButVecNewcrd", "icon/newcrd", ButVecNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Vec2", false, 0);

	height -= setCtlAvail(contcontdoc, "Vit", LstVitAvail, 96);
	height -= setCtlAvail(contcontdoc, "Vit2", LstVitAvail && !LstVitAlt, (LstVitAvail) ? 71 : 0);
	if (LstVitAvail) {
		if ( (LstVitAlt == !contcontdoc.getElementById("ButVitExpand")) || (!LstVitAlt == !contcontdoc.getElementById("ButVitCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynVit");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVit", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptVit")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstVitAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButVitExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButVitCollapse", "icon/collapse"));
		};

		if (!LstVitAlt == !contcontdoc.getElementById("LstVit")) {
			mytd = contcontdoc.getElementById("rdynVit");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynVit");
			clearElem(mytd);

			if (LstVitAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVit", "./PnlWdbeNavDescr_LstVit.xml", true));
			};

		} else {
			if (!LstVitAlt) refreshLst(contcontdoc.getElementById("LstVit").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVit",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstVitNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstVit"))]);
		};

		if ((ButVitViewAvail == !contcontdoc.getElementById("ButVitView"))) {
			if (LstVitAlt) mytd = contcontdoc.getElementById("dynVit");
			else mytd = contcontdoc.getElementById("rdynVit");
			clearElem(mytd);

			first = true;

			if (ButVitViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButVitView", "icon/view"));
			};
		};

		if (ButVitViewAvail) refreshButicon(contcontdoc, "ButVitView", "icon/view", ButVitViewActive, false);

	} else setCtlAvail(contcontdoc, "Vit2", false, 0);

	height -= setCtlAvail(contcontdoc, "Cmd", LstCmdAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cmd2", LstCmdAvail && !LstCmdAlt, (LstCmdAvail) ? 71 : 0);
	if (LstCmdAvail) {
		if ( (LstCmdAlt == !contcontdoc.getElementById("ButCmdExpand")) || (!LstCmdAlt == !contcontdoc.getElementById("ButCmdCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCmd");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCmd", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptCmd")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCmdAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCmdExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCmdCollapse", "icon/collapse"));
		};

		if (!LstCmdAlt == !contcontdoc.getElementById("LstCmd")) {
			mytd = contcontdoc.getElementById("rdynCmd");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCmd");
			clearElem(mytd);

			if (LstCmdAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCmd", "./PnlWdbeNavDescr_LstCmd.xml", true));
			};

		} else {
			if (!LstCmdAlt) refreshLst(contcontdoc.getElementById("LstCmd").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCmd",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstCmdNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstCmd"))]);
		};

		if ((ButCmdViewAvail == !contcontdoc.getElementById("ButCmdView")) || !contcontdoc.getElementById("ButCmdNewcrd")) {
			if (LstCmdAlt) mytd = contcontdoc.getElementById("dynCmd");
			else mytd = contcontdoc.getElementById("rdynCmd");
			clearElem(mytd);

			first = true;

			if (ButCmdViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCmdView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCmdNewcrd", "icon/newcrd"));
		};

		if (ButCmdViewAvail) refreshButicon(contcontdoc, "ButCmdView", "icon/view", ButCmdViewActive, false);
		refreshButicon(contcontdoc, "ButCmdNewcrd", "icon/newcrd", ButCmdNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Cmd2", false, 0);

	height -= setCtlAvail(contcontdoc, "Err", LstErrAvail, 96);
	height -= setCtlAvail(contcontdoc, "Err2", LstErrAvail && !LstErrAlt, (LstErrAvail) ? 71 : 0);
	if (LstErrAvail) {
		if ( (LstErrAlt == !contcontdoc.getElementById("ButErrExpand")) || (!LstErrAlt == !contcontdoc.getElementById("ButErrCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynErr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptErr", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptErr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstErrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButErrExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButErrCollapse", "icon/collapse"));
		};

		if (!LstErrAlt == !contcontdoc.getElementById("LstErr")) {
			mytd = contcontdoc.getElementById("rdynErr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynErr");
			clearElem(mytd);

			if (LstErrAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstErr", "./PnlWdbeNavDescr_LstErr.xml", true));
			};

		} else {
			if (!LstErrAlt) refreshLst(contcontdoc.getElementById("LstErr").contentWindow.document, srcdoc, 1, true, false, "FeedFLstErr",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstErrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstErr"))]);
		};

		if ((ButErrViewAvail == !contcontdoc.getElementById("ButErrView")) || !contcontdoc.getElementById("ButErrNewcrd")) {
			if (LstErrAlt) mytd = contcontdoc.getElementById("dynErr");
			else mytd = contcontdoc.getElementById("rdynErr");
			clearElem(mytd);

			first = true;

			if (ButErrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButErrView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButErrNewcrd", "icon/newcrd"));
		};

		if (ButErrViewAvail) refreshButicon(contcontdoc, "ButErrView", "icon/view", ButErrViewActive, false);
		refreshButicon(contcontdoc, "ButErrNewcrd", "icon/newcrd", ButErrNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Err2", false, 0);

	height -= setCtlAvail(contcontdoc, "Pph", LstPphAvail, 96);
	height -= setCtlAvail(contcontdoc, "Pph2", LstPphAvail && !LstPphAlt, (LstPphAvail) ? 71 : 0);
	if (LstPphAvail) {
		if ( (LstPphAlt == !contcontdoc.getElementById("ButPphExpand")) || (!LstPphAlt == !contcontdoc.getElementById("ButPphCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPph");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPph", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptPph")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPphAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPphExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPphCollapse", "icon/collapse"));
		};

		if (!LstPphAlt == !contcontdoc.getElementById("LstPph")) {
			mytd = contcontdoc.getElementById("rdynPph");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPph");
			clearElem(mytd);

			if (LstPphAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPph", "./PnlWdbeNavDescr_LstPph.xml", true));
			};

		} else {
			if (!LstPphAlt) refreshLst(contcontdoc.getElementById("LstPph").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPph",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstPphNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstPph"))]);
		};

		if ((ButPphViewAvail == !contcontdoc.getElementById("ButPphView")) || !contcontdoc.getElementById("ButPphNewcrd")) {
			if (LstPphAlt) mytd = contcontdoc.getElementById("dynPph");
			else mytd = contcontdoc.getElementById("rdynPph");
			clearElem(mytd);

			first = true;

			if (ButPphViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPphView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPphNewcrd", "icon/newcrd"));
		};

		if (ButPphViewAvail) refreshButicon(contcontdoc, "ButPphView", "icon/view", ButPphViewActive, false);
		refreshButicon(contcontdoc, "ButPphNewcrd", "icon/newcrd", ButPphNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Pph2", false, 0);

	height -= setCtlAvail(contcontdoc, "Bnk", LstBnkAvail, 96);
	height -= setCtlAvail(contcontdoc, "Bnk2", LstBnkAvail && !LstBnkAlt, (LstBnkAvail) ? 71 : 0);
	if (LstBnkAvail) {
		if ( (LstBnkAlt == !contcontdoc.getElementById("ButBnkExpand")) || (!LstBnkAlt == !contcontdoc.getElementById("ButBnkCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynBnk");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptBnk", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptBnk")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstBnkAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButBnkExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButBnkCollapse", "icon/collapse"));
		};

		if (!LstBnkAlt == !contcontdoc.getElementById("LstBnk")) {
			mytd = contcontdoc.getElementById("rdynBnk");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynBnk");
			clearElem(mytd);

			if (LstBnkAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstBnk", "./PnlWdbeNavDescr_LstBnk.xml", true));
			};

		} else {
			if (!LstBnkAlt) refreshLst(contcontdoc.getElementById("LstBnk").contentWindow.document, srcdoc, 1, true, false, "FeedFLstBnk",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstBnkNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstBnk"))]);
		};

		if ((ButBnkViewAvail == !contcontdoc.getElementById("ButBnkView")) || !contcontdoc.getElementById("ButBnkNewcrd")) {
			if (LstBnkAlt) mytd = contcontdoc.getElementById("dynBnk");
			else mytd = contcontdoc.getElementById("rdynBnk");
			clearElem(mytd);

			first = true;

			if (ButBnkViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButBnkView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButBnkNewcrd", "icon/newcrd"));
		};

		if (ButBnkViewAvail) refreshButicon(contcontdoc, "ButBnkView", "icon/view", ButBnkViewActive, false);
		refreshButicon(contcontdoc, "ButBnkNewcrd", "icon/newcrd", ButBnkNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Bnk2", false, 0);

	height -= setCtlAvail(contcontdoc, "Pin", LstPinAvail, 96);
	height -= setCtlAvail(contcontdoc, "Pin2", LstPinAvail && !LstPinAlt, (LstPinAvail) ? 71 : 0);
	if (LstPinAvail) {
		if ( (LstPinAlt == !contcontdoc.getElementById("ButPinExpand")) || (!LstPinAlt == !contcontdoc.getElementById("ButPinCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPin");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPin", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptPin")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPinAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPinExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPinCollapse", "icon/collapse"));
		};

		if (!LstPinAlt == !contcontdoc.getElementById("LstPin")) {
			mytd = contcontdoc.getElementById("rdynPin");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPin");
			clearElem(mytd);

			if (LstPinAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPin", "./PnlWdbeNavDescr_LstPin.xml", true));
			};

		} else {
			if (!LstPinAlt) refreshLst(contcontdoc.getElementById("LstPin").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPin",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstPinNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstPin"))]);
		};

		if ((ButPinViewAvail == !contcontdoc.getElementById("ButPinView")) || !contcontdoc.getElementById("ButPinNewcrd")) {
			if (LstPinAlt) mytd = contcontdoc.getElementById("dynPin");
			else mytd = contcontdoc.getElementById("rdynPin");
			clearElem(mytd);

			first = true;

			if (ButPinViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPinView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPinNewcrd", "icon/newcrd"));
		};

		if (ButPinViewAvail) refreshButicon(contcontdoc, "ButPinView", "icon/view", ButPinViewActive, false);
		refreshButicon(contcontdoc, "ButPinNewcrd", "icon/newcrd", ButPinNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Pin2", false, 0);

	height -= setCtlAvail(contcontdoc, "Gen", LstGenAvail, 96);
	height -= setCtlAvail(contcontdoc, "Gen2", LstGenAvail && !LstGenAlt, (LstGenAvail) ? 71 : 0);
	if (LstGenAvail) {
		if ( (LstGenAlt == !contcontdoc.getElementById("ButGenExpand")) || (!LstGenAlt == !contcontdoc.getElementById("ButGenCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynGen");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptGen", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptGen")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstGenAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButGenExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButGenCollapse", "icon/collapse"));
		};

		if (!LstGenAlt == !contcontdoc.getElementById("LstGen")) {
			mytd = contcontdoc.getElementById("rdynGen");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynGen");
			clearElem(mytd);

			if (LstGenAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstGen", "./PnlWdbeNavDescr_LstGen.xml", true));
			};

		} else {
			if (!LstGenAlt) refreshLst(contcontdoc.getElementById("LstGen").contentWindow.document, srcdoc, 1, true, false, "FeedFLstGen",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstGenNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstGen"))]);
		};

		if ((ButGenViewAvail == !contcontdoc.getElementById("ButGenView"))) {
			if (LstGenAlt) mytd = contcontdoc.getElementById("dynGen");
			else mytd = contcontdoc.getElementById("rdynGen");
			clearElem(mytd);

			first = true;

			if (ButGenViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButGenView", "icon/view"));
			};
		};

		if (ButGenViewAvail) refreshButicon(contcontdoc, "ButGenView", "icon/view", ButGenViewActive, false);

	} else setCtlAvail(contcontdoc, "Gen2", false, 0);

	height -= setCtlAvail(contcontdoc, "Prt", LstPrtAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prt2", LstPrtAvail && !LstPrtAlt, (LstPrtAvail) ? 71 : 0);
	if (LstPrtAvail) {
		if ( (LstPrtAlt == !contcontdoc.getElementById("ButPrtExpand")) || (!LstPrtAlt == !contcontdoc.getElementById("ButPrtCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrt");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrt", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptPrt")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrtAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrtExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrtCollapse", "icon/collapse"));
		};

		if (!LstPrtAlt == !contcontdoc.getElementById("LstPrt")) {
			mytd = contcontdoc.getElementById("rdynPrt");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrt");
			clearElem(mytd);

			if (LstPrtAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrt", "./PnlWdbeNavDescr_LstPrt.xml", true));
			};

		} else {
			if (!LstPrtAlt) refreshLst(contcontdoc.getElementById("LstPrt").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPrt",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstPrtNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstPrt"))]);
		};

		if ((ButPrtViewAvail == !contcontdoc.getElementById("ButPrtView"))) {
			if (LstPrtAlt) mytd = contcontdoc.getElementById("dynPrt");
			else mytd = contcontdoc.getElementById("rdynPrt");
			clearElem(mytd);

			first = true;

			if (ButPrtViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrtView", "icon/view"));
			};
		};

		if (ButPrtViewAvail) refreshButicon(contcontdoc, "ButPrtView", "icon/view", ButPrtViewActive, false);

	} else setCtlAvail(contcontdoc, "Prt2", false, 0);

	height -= setCtlAvail(contcontdoc, "Sig", LstSigAvail, 96);
	height -= setCtlAvail(contcontdoc, "Sig2", LstSigAvail && !LstSigAlt, (LstSigAvail) ? 71 : 0);
	if (LstSigAvail) {
		if ( (LstSigAlt == !contcontdoc.getElementById("ButSigExpand")) || (!LstSigAlt == !contcontdoc.getElementById("ButSigCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSig");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSig", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptSig")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSigAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSigExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSigCollapse", "icon/collapse"));
		};

		if (!LstSigAlt == !contcontdoc.getElementById("LstSig")) {
			mytd = contcontdoc.getElementById("rdynSig");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSig");
			clearElem(mytd);

			if (LstSigAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSig", "./PnlWdbeNavDescr_LstSig.xml", true));
			};

		} else {
			if (!LstSigAlt) refreshLst(contcontdoc.getElementById("LstSig").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSig",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstSigNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstSig"))]);
		};

		if ((ButSigViewAvail == !contcontdoc.getElementById("ButSigView"))) {
			if (LstSigAlt) mytd = contcontdoc.getElementById("dynSig");
			else mytd = contcontdoc.getElementById("rdynSig");
			clearElem(mytd);

			first = true;

			if (ButSigViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSigView", "icon/view"));
			};
		};

		if (ButSigViewAvail) refreshButicon(contcontdoc, "ButSigView", "icon/view", ButSigViewActive, false);

	} else setCtlAvail(contcontdoc, "Sig2", false, 0);

	height -= setCtlAvail(contcontdoc, "Prc", LstPrcAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prc2", LstPrcAvail && !LstPrcAlt, (LstPrcAvail) ? 71 : 0);
	if (LstPrcAvail) {
		if ( (LstPrcAlt == !contcontdoc.getElementById("ButPrcExpand")) || (!LstPrcAlt == !contcontdoc.getElementById("ButPrcCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrc");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrc", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptPrc")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrcAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrcExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrcCollapse", "icon/collapse"));
		};

		if (!LstPrcAlt == !contcontdoc.getElementById("LstPrc")) {
			mytd = contcontdoc.getElementById("rdynPrc");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrc");
			clearElem(mytd);

			if (LstPrcAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrc", "./PnlWdbeNavDescr_LstPrc.xml", true));
			};

		} else {
			if (!LstPrcAlt) refreshLst(contcontdoc.getElementById("LstPrc").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPrc",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstPrcNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstPrc"))]);
		};

		if ((ButPrcViewAvail == !contcontdoc.getElementById("ButPrcView"))) {
			if (LstPrcAlt) mytd = contcontdoc.getElementById("dynPrc");
			else mytd = contcontdoc.getElementById("rdynPrc");
			clearElem(mytd);

			first = true;

			if (ButPrcViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrcView", "icon/view"));
			};
		};

		if (ButPrcViewAvail) refreshButicon(contcontdoc, "ButPrcView", "icon/view", ButPrcViewActive, false);

	} else setCtlAvail(contcontdoc, "Prc2", false, 0);

	height -= setCtlAvail(contcontdoc, "Fst", LstFstAvail, 96);
	height -= setCtlAvail(contcontdoc, "Fst2", LstFstAvail && !LstFstAlt, (LstFstAvail) ? 71 : 0);
	if (LstFstAvail) {
		if ( (LstFstAlt == !contcontdoc.getElementById("ButFstExpand")) || (!LstFstAlt == !contcontdoc.getElementById("ButFstCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFst");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFst", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptFst")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFstAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFstExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFstCollapse", "icon/collapse"));
		};

		if (!LstFstAlt == !contcontdoc.getElementById("LstFst")) {
			mytd = contcontdoc.getElementById("rdynFst");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynFst");
			clearElem(mytd);

			if (LstFstAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFst", "./PnlWdbeNavDescr_LstFst.xml", true));
			};

		} else {
			if (!LstFstAlt) refreshLst(contcontdoc.getElementById("LstFst").contentWindow.document, srcdoc, 1, true, false, "FeedFLstFst",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstFstNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstFst"))]);
		};

		if ((ButFstViewAvail == !contcontdoc.getElementById("ButFstView"))) {
			if (LstFstAlt) mytd = contcontdoc.getElementById("dynFst");
			else mytd = contcontdoc.getElementById("rdynFst");
			clearElem(mytd);

			first = true;

			if (ButFstViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFstView", "icon/view"));
			};
		};

		if (ButFstViewAvail) refreshButicon(contcontdoc, "ButFstView", "icon/view", ButFstViewActive, false);

	} else setCtlAvail(contcontdoc, "Fst2", false, 0);

	height -= setCtlAvail(contcontdoc, "Var", LstVarAvail, 96);
	height -= setCtlAvail(contcontdoc, "Var2", LstVarAvail && !LstVarAlt, (LstVarAvail) ? 71 : 0);
	if (LstVarAvail) {
		if ( (LstVarAlt == !contcontdoc.getElementById("ButVarExpand")) || (!LstVarAlt == !contcontdoc.getElementById("ButVarCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynVar");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVar", retrieveTi(srcdoc, "TagWdbeNavDescr", "CptVar")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstVarAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButVarExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButVarCollapse", "icon/collapse"));
		};

		if (!LstVarAlt == !contcontdoc.getElementById("LstVar")) {
			mytd = contcontdoc.getElementById("rdynVar");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynVar");
			clearElem(mytd);

			if (LstVarAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVar", "./PnlWdbeNavDescr_LstVar.xml", true));
			};

		} else {
			if (!LstVarAlt) refreshLst(contcontdoc.getElementById("LstVar").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVar",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", "LstVarNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numFLstVar"))]);
		};

		if ((ButVarViewAvail == !contcontdoc.getElementById("ButVarView"))) {
			if (LstVarAlt) mytd = contcontdoc.getElementById("dynVar");
			else mytd = contcontdoc.getElementById("rdynVar");
			clearElem(mytd);

			first = true;

			if (ButVarViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButVarView", "icon/view"));
			};
		};

		if (ButVarViewAvail) refreshButicon(contcontdoc, "ButVarView", "icon/view", ButVarViewActive, false);

	} else setCtlAvail(contcontdoc, "Var2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Descr", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Descr_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Descr_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Descr_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavDescr", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("Descr_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleButRegularizeClick() {
	regularize(true);
};

function handleButMinimizeClick() {
	minimize(true);
};

// --- generalized event handlers for app controls

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeNavDescr", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeNavDescr", basectlsref + "Alt", "false");
	refresh();
};

function setLsbPos(lstdoc, pos) {
	var vpos = (16 + Math.round(pos * (90-2*16)));

	lstdoc.getElementById("LsbJpupr").setAttribute("height", "" + (vpos-10));
	lstdoc.getElementById("LsbJpupl").setAttribute("y2", "" + vpos);

	lstdoc.getElementById("LsbJpdownr").setAttribute("y", "" + vpos);
	lstdoc.getElementById("LsbJpdownr").setAttribute("height", "" + (90-vpos-10));
	lstdoc.getElementById("LsbJpdownl").setAttribute("y1", "" + vpos);

	lstdoc.getElementById("Lsb").setAttribute("transform", "translate(0 " + vpos + ")");
};

function handleLsbUpClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, multsel, ncol, 0, -1);
};

function handleLsbJpupClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, -4);
};

function handleLsbJpdownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 4);
};

function handleLsbDownClick(lstdoc, basectlsref, ncol, multsel) {
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, 0, 1);
};

function handleLsbMdn(lstdoc, basectlsref) {
	lstdoc.getElementById("tdLsb").onmousemove = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMove;
	lstdoc.getElementById("tdLsb").onmouseup = contcontdoc.getElementById(basectlsref).contentWindow.handleLsbMup;
};

function handleLsbMove(lstdoc, evt) {
	if ((evt.clientY >= 16) && (evt.clientY <= (90-16))) {
		var pos = (evt.clientY-16)/(90-2*16);
		setLsbPos(lstdoc, pos);
	};
};

function handleLsbMup(lstdoc, basectlsref, ncol, multsel, evt) {
	lstdoc.getElementById("tdLsb").removeAttribute("onmousemove");
	lstdoc.getElementById("tdLsb").removeAttribute("onmouseup");

	var cnt = getFeedSize(srcdoc, "FeedF" + basectlsref);

	var pos = (evt.clientY-16)/(90-2*16);
	changeLstNumFirstdisp(lstdoc, basectlsref, ncol, multsel, Math.round(pos*(cnt-5))+1, 0);
};

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavDescrDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavDescrDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numsF" + ctlsref));

		found = false;

		for (var i = 0; i < oldNumsFLst.length; i++) {
			if (oldNumsFLst[i] == num) {
				numsFLst = new Uint32Array(oldNumsFLst.length-1);

				for (var j = 0; j < oldNumsFLst.length; j++)
					if (j < i) numsFLst[j] = oldNumsFLst[j];
					else if (j > i) numsFLst[j-1] = oldNumsFLst[j];

				found = true;
				break;
			};
		};

		if (!found) {
			numsFLst = new Uint32Array(oldNumsFLst.length+1);

			for (var i = 0; i < oldNumsFLst.length; i++) numsFLst[i] = oldNumsFLst[i];
			numsFLst[oldNumsFLst.length] = num;
		};

		setCi(srcdoc, "ContIacWdbeNavDescr", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeNavDescr", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeNavDescrData", scrJref, "ContIacWdbeNavDescr");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDescr", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeNavDescr", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDescr", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "ContIacWdbeNavDescr", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstBnk", srcdoc)) mask.push("feedFLstBnk");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstCmd", srcdoc)) mask.push("feedFLstCmd");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstErr", srcdoc)) mask.push("feedFLstErr");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstFst", srcdoc)) mask.push("feedFLstFst");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstGen", srcdoc)) mask.push("feedFLstGen");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstMod", srcdoc)) mask.push("feedFLstMod");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstPin", srcdoc)) mask.push("feedFLstPin");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstPph", srcdoc)) mask.push("feedFLstPph");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstPrc", srcdoc)) mask.push("feedFLstPrc");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstPrt", srcdoc)) mask.push("feedFLstPrt");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstSig", srcdoc)) mask.push("feedFLstSig");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstVar", srcdoc)) mask.push("feedFLstVar");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstVec", srcdoc)) mask.push("feedFLstVec");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "FeedFLstVit", srcdoc)) mask.push("feedFLstVit");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "StatAppWdbeNavDescr", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "StatShrWdbeNavDescr", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeNavDescrData", "TagWdbeNavDescr", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeNavDescrData") {
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
			if (blk.nodeName == "DpchEngWdbeNavDescrData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Descr");
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

			} else if (blk.nodeName == "DpchEngWdbeNavDescrData") {
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

