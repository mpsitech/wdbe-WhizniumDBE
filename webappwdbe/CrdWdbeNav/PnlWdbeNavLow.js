// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavLow", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeNavLow", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Low", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Low_side").setAttribute("height", "30");
	doc.getElementById("Low_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Low_side").src = "./PnlWdbeNavLow_aside.html";
	doc.getElementById("Low_cont").src = "./PnlWdbeNavLow_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavLow", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeNavLow", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Low_side").src = "./PnlWdbeNavLow_bside.html";
	doc.getElementById("Low_cont").src = "./PnlWdbeNavLow_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Low_side").contentDocument;
	contdoc = doc.getElementById("Low_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavLow", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Low_side").contentDocument;
	contdoc = doc.getElementById("Low_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Low_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Low_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavLow", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavLow", "srefIxWdbeVExpstate");

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

	var height = 1066; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstBnkAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstBnkAlt") == "true");
	var LstBnkAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstBnkAvail") == "true");
	var ButBnkViewAvail = !LstBnkAlt;
	var ButBnkViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButBnkViewActive") == "true");
	var ButBnkNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButBnkNewcrdActive") == "true");

	var LstPinAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstPinAlt") == "true");
	var LstPinAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstPinAvail") == "true");
	var ButPinViewAvail = !LstPinAlt;
	var ButPinViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButPinViewActive") == "true");
	var ButPinNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButPinNewcrdActive") == "true");

	var LstIntAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstIntAlt") == "true");
	var LstIntAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstIntAvail") == "true");
	var ButIntViewAvail = !LstIntAlt;
	var ButIntViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButIntViewActive") == "true");
	var ButIntNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButIntNewcrdActive") == "true");

	var LstSnsAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstSnsAlt") == "true");
	var LstSnsAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstSnsAvail") == "true");
	var ButSnsViewAvail = !LstSnsAlt;
	var ButSnsViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButSnsViewActive") == "true");

	var LstVarAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstVarAlt") == "true");
	var LstVarAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstVarAvail") == "true");
	var ButVarViewAvail = !LstVarAlt;
	var ButVarViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButVarViewActive") == "true");

	var LstGenAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstGenAlt") == "true");
	var LstGenAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstGenAvail") == "true");
	var ButGenViewAvail = !LstGenAlt;
	var ButGenViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButGenViewActive") == "true");

	var LstPrtAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstPrtAlt") == "true");
	var LstPrtAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstPrtAvail") == "true");
	var ButPrtViewAvail = !LstPrtAlt;
	var ButPrtViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButPrtViewActive") == "true");

	var LstSigAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstSigAlt") == "true");
	var LstSigAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstSigAvail") == "true");
	var ButSigViewAvail = !LstSigAlt;
	var ButSigViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButSigViewActive") == "true");
	var ButSigNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButSigNewcrdActive") == "true");

	var LstCdcAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstCdcAlt") == "true");
	var LstCdcAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstCdcAvail") == "true");
	var ButCdcViewAvail = !LstCdcAlt;
	var ButCdcViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButCdcViewActive") == "true");

	var LstPrcAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstPrcAlt") == "true");
	var LstPrcAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstPrcAvail") == "true");
	var ButPrcViewAvail = !LstPrcAlt;
	var ButPrcViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButPrcViewActive") == "true");

	var LstFstAlt = (retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstFstAlt") == "true");
	var LstFstAvail = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "LstFstAvail") == "true");
	var ButFstViewAvail = !LstFstAlt;
	var ButFstViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavLow", "ButFstViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Bnk", LstBnkAvail, 96);
	height -= setCtlAvail(contcontdoc, "Bnk2", LstBnkAvail && !LstBnkAlt, (LstBnkAvail) ? 71 : 0);
	if (LstBnkAvail) {
		if ( (LstBnkAlt == !contcontdoc.getElementById("ButBnkExpand")) || (!LstBnkAlt == !contcontdoc.getElementById("ButBnkCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynBnk");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptBnk", retrieveTi(srcdoc, "TagWdbeNavLow", "CptBnk")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstBnk", "./PnlWdbeNavLow_LstBnk.xml", true));
			};

		} else {
			if (!LstBnkAlt) refreshLst(contcontdoc.getElementById("LstBnk").contentWindow.document, srcdoc, 1, true, false, "FeedFLstBnk",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstBnkNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstBnk"))]);
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

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPin", retrieveTi(srcdoc, "TagWdbeNavLow", "CptPin")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPin", "./PnlWdbeNavLow_LstPin.xml", true));
			};

		} else {
			if (!LstPinAlt) refreshLst(contcontdoc.getElementById("LstPin").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPin",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstPinNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstPin"))]);
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

	height -= setCtlAvail(contcontdoc, "Int", LstIntAvail, 96);
	height -= setCtlAvail(contcontdoc, "Int2", LstIntAvail && !LstIntAlt, (LstIntAvail) ? 71 : 0);
	if (LstIntAvail) {
		if ( (LstIntAlt == !contcontdoc.getElementById("ButIntExpand")) || (!LstIntAlt == !contcontdoc.getElementById("ButIntCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynInt");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptInt", retrieveTi(srcdoc, "TagWdbeNavLow", "CptInt")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstIntAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButIntExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButIntCollapse", "icon/collapse"));
		};

		if (!LstIntAlt == !contcontdoc.getElementById("LstInt")) {
			mytd = contcontdoc.getElementById("rdynInt");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynInt");
			clearElem(mytd);

			if (LstIntAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstInt", "./PnlWdbeNavLow_LstInt.xml", true));
			};

		} else {
			if (!LstIntAlt) refreshLst(contcontdoc.getElementById("LstInt").contentWindow.document, srcdoc, 1, true, false, "FeedFLstInt",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstIntNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstInt"))]);
		};

		if ((ButIntViewAvail == !contcontdoc.getElementById("ButIntView")) || !contcontdoc.getElementById("ButIntNewcrd")) {
			if (LstIntAlt) mytd = contcontdoc.getElementById("dynInt");
			else mytd = contcontdoc.getElementById("rdynInt");
			clearElem(mytd);

			first = true;

			if (ButIntViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButIntView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButIntNewcrd", "icon/newcrd"));
		};

		if (ButIntViewAvail) refreshButicon(contcontdoc, "ButIntView", "icon/view", ButIntViewActive, false);
		refreshButicon(contcontdoc, "ButIntNewcrd", "icon/newcrd", ButIntNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Int2", false, 0);

	height -= setCtlAvail(contcontdoc, "Sns", LstSnsAvail, 96);
	height -= setCtlAvail(contcontdoc, "Sns2", LstSnsAvail && !LstSnsAlt, (LstSnsAvail) ? 71 : 0);
	if (LstSnsAvail) {
		if ( (LstSnsAlt == !contcontdoc.getElementById("ButSnsExpand")) || (!LstSnsAlt == !contcontdoc.getElementById("ButSnsCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSns");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSns", retrieveTi(srcdoc, "TagWdbeNavLow", "CptSns")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSnsAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSnsExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSnsCollapse", "icon/collapse"));
		};

		if (!LstSnsAlt == !contcontdoc.getElementById("LstSns")) {
			mytd = contcontdoc.getElementById("rdynSns");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSns");
			clearElem(mytd);

			if (LstSnsAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSns", "./PnlWdbeNavLow_LstSns.xml", true));
			};

		} else {
			if (!LstSnsAlt) refreshLst(contcontdoc.getElementById("LstSns").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSns",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstSnsNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstSns"))]);
		};

		if ((ButSnsViewAvail == !contcontdoc.getElementById("ButSnsView"))) {
			if (LstSnsAlt) mytd = contcontdoc.getElementById("dynSns");
			else mytd = contcontdoc.getElementById("rdynSns");
			clearElem(mytd);

			first = true;

			if (ButSnsViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSnsView", "icon/view"));
			};
		};

		if (ButSnsViewAvail) refreshButicon(contcontdoc, "ButSnsView", "icon/view", ButSnsViewActive, false);

	} else setCtlAvail(contcontdoc, "Sns2", false, 0);

	height -= setCtlAvail(contcontdoc, "Var", LstVarAvail, 96);
	height -= setCtlAvail(contcontdoc, "Var2", LstVarAvail && !LstVarAlt, (LstVarAvail) ? 71 : 0);
	if (LstVarAvail) {
		if ( (LstVarAlt == !contcontdoc.getElementById("ButVarExpand")) || (!LstVarAlt == !contcontdoc.getElementById("ButVarCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynVar");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVar", retrieveTi(srcdoc, "TagWdbeNavLow", "CptVar")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVar", "./PnlWdbeNavLow_LstVar.xml", true));
			};

		} else {
			if (!LstVarAlt) refreshLst(contcontdoc.getElementById("LstVar").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVar",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstVarNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstVar"))]);
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

	height -= setCtlAvail(contcontdoc, "Gen", LstGenAvail, 96);
	height -= setCtlAvail(contcontdoc, "Gen2", LstGenAvail && !LstGenAlt, (LstGenAvail) ? 71 : 0);
	if (LstGenAvail) {
		if ( (LstGenAlt == !contcontdoc.getElementById("ButGenExpand")) || (!LstGenAlt == !contcontdoc.getElementById("ButGenCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynGen");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptGen", retrieveTi(srcdoc, "TagWdbeNavLow", "CptGen")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstGen", "./PnlWdbeNavLow_LstGen.xml", true));
			};

		} else {
			if (!LstGenAlt) refreshLst(contcontdoc.getElementById("LstGen").contentWindow.document, srcdoc, 1, true, false, "FeedFLstGen",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstGenNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstGen"))]);
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

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrt", retrieveTi(srcdoc, "TagWdbeNavLow", "CptPrt")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrt", "./PnlWdbeNavLow_LstPrt.xml", true));
			};

		} else {
			if (!LstPrtAlt) refreshLst(contcontdoc.getElementById("LstPrt").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPrt",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstPrtNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstPrt"))]);
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

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSig", retrieveTi(srcdoc, "TagWdbeNavLow", "CptSig")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSig", "./PnlWdbeNavLow_LstSig.xml", true));
			};

		} else {
			if (!LstSigAlt) refreshLst(contcontdoc.getElementById("LstSig").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSig",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstSigNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstSig"))]);
		};

		if ((ButSigViewAvail == !contcontdoc.getElementById("ButSigView")) || !contcontdoc.getElementById("ButSigNewcrd")) {
			if (LstSigAlt) mytd = contcontdoc.getElementById("dynSig");
			else mytd = contcontdoc.getElementById("rdynSig");
			clearElem(mytd);

			first = true;

			if (ButSigViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSigView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSigNewcrd", "icon/newcrd"));
		};

		if (ButSigViewAvail) refreshButicon(contcontdoc, "ButSigView", "icon/view", ButSigViewActive, false);
		refreshButicon(contcontdoc, "ButSigNewcrd", "icon/newcrd", ButSigNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Sig2", false, 0);

	height -= setCtlAvail(contcontdoc, "Cdc", LstCdcAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cdc2", LstCdcAvail && !LstCdcAlt, (LstCdcAvail) ? 71 : 0);
	if (LstCdcAvail) {
		if ( (LstCdcAlt == !contcontdoc.getElementById("ButCdcExpand")) || (!LstCdcAlt == !contcontdoc.getElementById("ButCdcCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCdc");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCdc", retrieveTi(srcdoc, "TagWdbeNavLow", "CptCdc")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCdcAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCdcExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCdcCollapse", "icon/collapse"));
		};

		if (!LstCdcAlt == !contcontdoc.getElementById("LstCdc")) {
			mytd = contcontdoc.getElementById("rdynCdc");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCdc");
			clearElem(mytd);

			if (LstCdcAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCdc", "./PnlWdbeNavLow_LstCdc.xml", true));
			};

		} else {
			if (!LstCdcAlt) refreshLst(contcontdoc.getElementById("LstCdc").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCdc",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstCdcNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstCdc"))]);
		};

		if ((ButCdcViewAvail == !contcontdoc.getElementById("ButCdcView"))) {
			if (LstCdcAlt) mytd = contcontdoc.getElementById("dynCdc");
			else mytd = contcontdoc.getElementById("rdynCdc");
			clearElem(mytd);

			first = true;

			if (ButCdcViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCdcView", "icon/view"));
			};
		};

		if (ButCdcViewAvail) refreshButicon(contcontdoc, "ButCdcView", "icon/view", ButCdcViewActive, false);

	} else setCtlAvail(contcontdoc, "Cdc2", false, 0);

	height -= setCtlAvail(contcontdoc, "Prc", LstPrcAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prc2", LstPrcAvail && !LstPrcAlt, (LstPrcAvail) ? 71 : 0);
	if (LstPrcAvail) {
		if ( (LstPrcAlt == !contcontdoc.getElementById("ButPrcExpand")) || (!LstPrcAlt == !contcontdoc.getElementById("ButPrcCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrc");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrc", retrieveTi(srcdoc, "TagWdbeNavLow", "CptPrc")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrc", "./PnlWdbeNavLow_LstPrc.xml", true));
			};

		} else {
			if (!LstPrcAlt) refreshLst(contcontdoc.getElementById("LstPrc").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPrc",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstPrcNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstPrc"))]);
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

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFst", retrieveTi(srcdoc, "TagWdbeNavLow", "CptFst")));

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
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFst", "./PnlWdbeNavLow_LstFst.xml", true));
			};

		} else {
			if (!LstFstAlt) refreshLst(contcontdoc.getElementById("LstFst").contentWindow.document, srcdoc, 1, true, false, "FeedFLstFst",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", "LstFstNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numFLstFst"))]);
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

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Low", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Low_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Low_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Low_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavLow", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("Low_src").contentDocument;

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
	setSi(srcdoc, "StatAppWdbeNavLow", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeNavLow", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavLowDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavLowDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbeNavLow", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeNavLow", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeNavLowData", scrJref, "ContIacWdbeNavLow");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeNavLow", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeNavLow", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavLow", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "ContIacWdbeNavLow", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstBnk", srcdoc)) mask.push("feedFLstBnk");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstCdc", srcdoc)) mask.push("feedFLstCdc");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstFst", srcdoc)) mask.push("feedFLstFst");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstGen", srcdoc)) mask.push("feedFLstGen");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstInt", srcdoc)) mask.push("feedFLstInt");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstPin", srcdoc)) mask.push("feedFLstPin");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstPrc", srcdoc)) mask.push("feedFLstPrc");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstPrt", srcdoc)) mask.push("feedFLstPrt");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstSig", srcdoc)) mask.push("feedFLstSig");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstSns", srcdoc)) mask.push("feedFLstSns");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "FeedFLstVar", srcdoc)) mask.push("feedFLstVar");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "StatAppWdbeNavLow", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "StatShrWdbeNavLow", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeNavLowData", "TagWdbeNavLow", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeNavLowData") {
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
			if (blk.nodeName == "DpchEngWdbeNavLowData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Low");
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

			} else if (blk.nodeName == "DpchEngWdbeNavLowData") {
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
