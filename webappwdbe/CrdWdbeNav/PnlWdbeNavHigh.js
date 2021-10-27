// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeNavHigh", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("High", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("High_side").setAttribute("height", "30");
	doc.getElementById("High_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("High_side").src = "./PnlWdbeNavHigh_aside.html";
	doc.getElementById("High_cont").src = "./PnlWdbeNavHigh_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeNavHigh", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("High_side").src = "./PnlWdbeNavHigh_bside.html";
	doc.getElementById("High_cont").src = "./PnlWdbeNavHigh_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("High_side").contentDocument;
	contdoc = doc.getElementById("High_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavHigh", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("High_side").contentDocument;
	contdoc = doc.getElementById("High_cont").contentDocument;
	hdrdoc = contdoc.getElementById("High_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("High_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavHigh", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavHigh", "srefIxWdbeVExpstate");

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

	var height = 778; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstPphAlt = (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstPphAlt") == "true");
	var LstPphAvail = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "LstPphAvail") == "true");
	var ButPphViewAvail = !LstPphAlt;
	var ButPphViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButPphViewActive") == "true");
	var ButPphNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButPphNewcrdActive") == "true");

	var LstModAlt = (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstModAlt") == "true");
	var LstModAvail = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "LstModAvail") == "true");
	var ButModViewAvail = !LstModAlt;
	var ButModViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButModViewActive") == "true");
	var ButModNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButModNewcrdActive") == "true");

	var LstVecAlt = (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstVecAlt") == "true");
	var LstVecAvail = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "LstVecAvail") == "true");
	var ButVecViewAvail = !LstVecAlt;
	var ButVecViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButVecViewActive") == "true");
	var ButVecNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButVecNewcrdActive") == "true");

	var LstVitAlt = (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstVitAlt") == "true");
	var LstVitAvail = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "LstVitAvail") == "true");
	var ButVitViewAvail = !LstVitAlt;
	var ButVitViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButVitViewActive") == "true");

	var LstCmdAlt = (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstCmdAlt") == "true");
	var LstCmdAvail = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "LstCmdAvail") == "true");
	var ButCmdViewAvail = !LstCmdAlt;
	var ButCmdViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButCmdViewActive") == "true");
	var ButCmdNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButCmdNewcrdActive") == "true");

	var LstErrAlt = (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstErrAlt") == "true");
	var LstErrAvail = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "LstErrAvail") == "true");
	var ButErrViewAvail = !LstErrAlt;
	var ButErrViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButErrViewActive") == "true");
	var ButErrNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButErrNewcrdActive") == "true");

	var LstPplAlt = (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstPplAlt") == "true");
	var LstPplAvail = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "LstPplAvail") == "true");
	var ButPplViewAvail = !LstPplAlt;
	var ButPplViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButPplViewActive") == "true");
	var ButPplNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButPplNewcrdActive") == "true");

	var LstSegAlt = (retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstSegAlt") == "true");
	var LstSegAvail = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "LstSegAvail") == "true");
	var ButSegViewAvail = !LstSegAlt;
	var ButSegViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButSegViewActive") == "true");
	var ButSegNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavHigh", "ButSegNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Pph", LstPphAvail, 96);
	height -= setCtlAvail(contcontdoc, "Pph2", LstPphAvail && !LstPphAlt, (LstPphAvail) ? 71 : 0);
	if (LstPphAvail) {
		if ( (LstPphAlt == !contcontdoc.getElementById("ButPphExpand")) || (!LstPphAlt == !contcontdoc.getElementById("ButPphCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPph");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPph", retrieveTi(srcdoc, "TagWdbeNavHigh", "CptPph")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPph", "./PnlWdbeNavHigh_LstPph.xml", true));
			};

		} else {
			if (!LstPphAlt) refreshLst(contcontdoc.getElementById("LstPph").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPph",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstPphNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numFLstPph"))]);
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

	height -= setCtlAvail(contcontdoc, "Mod", LstModAvail, 96);
	height -= setCtlAvail(contcontdoc, "Mod2", LstModAvail && !LstModAlt, (LstModAvail) ? 71 : 0);
	if (LstModAvail) {
		if ( (LstModAlt == !contcontdoc.getElementById("ButModExpand")) || (!LstModAlt == !contcontdoc.getElementById("ButModCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynMod");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptMod", retrieveTi(srcdoc, "TagWdbeNavHigh", "CptMod")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstMod", "./PnlWdbeNavHigh_LstMod.xml", true));
			};

		} else {
			if (!LstModAlt) refreshLst(contcontdoc.getElementById("LstMod").contentWindow.document, srcdoc, 1, true, false, "FeedFLstMod",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstModNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numFLstMod"))]);
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

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVec", retrieveTi(srcdoc, "TagWdbeNavHigh", "CptVec")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVec", "./PnlWdbeNavHigh_LstVec.xml", true));
			};

		} else {
			if (!LstVecAlt) refreshLst(contcontdoc.getElementById("LstVec").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVec",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstVecNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numFLstVec"))]);
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

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVit", retrieveTi(srcdoc, "TagWdbeNavHigh", "CptVit")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVit", "./PnlWdbeNavHigh_LstVit.xml", true));
			};

		} else {
			if (!LstVitAlt) refreshLst(contcontdoc.getElementById("LstVit").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVit",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstVitNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numFLstVit"))]);
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

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCmd", retrieveTi(srcdoc, "TagWdbeNavHigh", "CptCmd")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCmd", "./PnlWdbeNavHigh_LstCmd.xml", true));
			};

		} else {
			if (!LstCmdAlt) refreshLst(contcontdoc.getElementById("LstCmd").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCmd",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstCmdNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numFLstCmd"))]);
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

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptErr", retrieveTi(srcdoc, "TagWdbeNavHigh", "CptErr")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstErr", "./PnlWdbeNavHigh_LstErr.xml", true));
			};

		} else {
			if (!LstErrAlt) refreshLst(contcontdoc.getElementById("LstErr").contentWindow.document, srcdoc, 1, true, false, "FeedFLstErr",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstErrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numFLstErr"))]);
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

	height -= setCtlAvail(contcontdoc, "Ppl", LstPplAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ppl2", LstPplAvail && !LstPplAlt, (LstPplAvail) ? 71 : 0);
	if (LstPplAvail) {
		if ( (LstPplAlt == !contcontdoc.getElementById("ButPplExpand")) || (!LstPplAlt == !contcontdoc.getElementById("ButPplCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPpl");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPpl", retrieveTi(srcdoc, "TagWdbeNavHigh", "CptPpl")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPplAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPplExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPplCollapse", "icon/collapse"));
		};

		if (!LstPplAlt == !contcontdoc.getElementById("LstPpl")) {
			mytd = contcontdoc.getElementById("rdynPpl");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPpl");
			clearElem(mytd);

			if (LstPplAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPpl", "./PnlWdbeNavHigh_LstPpl.xml", true));
			};

		} else {
			if (!LstPplAlt) refreshLst(contcontdoc.getElementById("LstPpl").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPpl",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstPplNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numFLstPpl"))]);
		};

		if ((ButPplViewAvail == !contcontdoc.getElementById("ButPplView")) || !contcontdoc.getElementById("ButPplNewcrd")) {
			if (LstPplAlt) mytd = contcontdoc.getElementById("dynPpl");
			else mytd = contcontdoc.getElementById("rdynPpl");
			clearElem(mytd);

			first = true;

			if (ButPplViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPplView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPplNewcrd", "icon/newcrd"));
		};

		if (ButPplViewAvail) refreshButicon(contcontdoc, "ButPplView", "icon/view", ButPplViewActive, false);
		refreshButicon(contcontdoc, "ButPplNewcrd", "icon/newcrd", ButPplNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Ppl2", false, 0);

	height -= setCtlAvail(contcontdoc, "Seg", LstSegAvail, 96);
	height -= setCtlAvail(contcontdoc, "Seg2", LstSegAvail && !LstSegAlt, (LstSegAvail) ? 71 : 0);
	if (LstSegAvail) {
		if ( (LstSegAlt == !contcontdoc.getElementById("ButSegExpand")) || (!LstSegAlt == !contcontdoc.getElementById("ButSegCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSeg");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSeg", retrieveTi(srcdoc, "TagWdbeNavHigh", "CptSeg")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSegAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSegExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSegCollapse", "icon/collapse"));
		};

		if (!LstSegAlt == !contcontdoc.getElementById("LstSeg")) {
			mytd = contcontdoc.getElementById("rdynSeg");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSeg");
			clearElem(mytd);

			if (LstSegAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSeg", "./PnlWdbeNavHigh_LstSeg.xml", true));
			};

		} else {
			if (!LstSegAlt) refreshLst(contcontdoc.getElementById("LstSeg").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSeg",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", "LstSegNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numFLstSeg"))]);
		};

		if ((ButSegViewAvail == !contcontdoc.getElementById("ButSegView")) || !contcontdoc.getElementById("ButSegNewcrd")) {
			if (LstSegAlt) mytd = contcontdoc.getElementById("dynSeg");
			else mytd = contcontdoc.getElementById("rdynSeg");
			clearElem(mytd);

			first = true;

			if (ButSegViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSegView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSegNewcrd", "icon/newcrd"));
		};

		if (ButSegViewAvail) refreshButicon(contcontdoc, "ButSegView", "icon/view", ButSegViewActive, false);
		refreshButicon(contcontdoc, "ButSegNewcrd", "icon/newcrd", ButSegNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Seg2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("High", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("High_side").setAttribute("height", "" + (height+31));
	doc.getElementById("High_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("High_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavHigh", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("High_src").contentDocument;

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
	setSi(srcdoc, "StatAppWdbeNavHigh", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeNavHigh", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavHighDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavHighDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbeNavHigh", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeNavHigh", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeNavHighData", scrJref, "ContIacWdbeNavHigh");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeNavHigh", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeNavHigh", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavHigh", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "ContIacWdbeNavHigh", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "FeedFLstCmd", srcdoc)) mask.push("feedFLstCmd");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "FeedFLstErr", srcdoc)) mask.push("feedFLstErr");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "FeedFLstMod", srcdoc)) mask.push("feedFLstMod");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "FeedFLstPph", srcdoc)) mask.push("feedFLstPph");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "FeedFLstPpl", srcdoc)) mask.push("feedFLstPpl");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "FeedFLstSeg", srcdoc)) mask.push("feedFLstSeg");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "FeedFLstVec", srcdoc)) mask.push("feedFLstVec");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "FeedFLstVit", srcdoc)) mask.push("feedFLstVit");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "StatAppWdbeNavHigh", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "StatShrWdbeNavHigh", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeNavHighData", "TagWdbeNavHigh", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeNavHighData") {
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
			if (blk.nodeName == "DpchEngWdbeNavHighData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("High");
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

			} else if (blk.nodeName == "DpchEngWdbeNavHighData") {
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
