// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeNavGlobal", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Global", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Global_side").setAttribute("height", "30");
	doc.getElementById("Global_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Global_side").src = "./PnlWdbeNavGlobal_aside.html";
	doc.getElementById("Global_cont").src = "./PnlWdbeNavGlobal_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeNavGlobal", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Global_side").src = "./PnlWdbeNavGlobal_bside.html";
	doc.getElementById("Global_cont").src = "./PnlWdbeNavGlobal_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Global_side").contentDocument;
	contdoc = doc.getElementById("Global_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavGlobal", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Global_side").contentDocument;
	contdoc = doc.getElementById("Global_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Global_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Global_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavGlobal", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "srefIxWdbeVExpstate");

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

	var height = 490; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstMchAlt = (retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstMchAlt") == "true");
	var LstMchAvail = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "LstMchAvail") == "true");
	var ButMchViewAvail = !LstMchAlt;
	var ButMchViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "ButMchViewActive") == "true");

	var LstLibAlt = (retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstLibAlt") == "true");
	var LstLibAvail = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "LstLibAvail") == "true");
	var ButLibViewAvail = !LstLibAlt;
	var ButLibViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "ButLibViewActive") == "true");

	var LstFamAlt = (retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstFamAlt") == "true");
	var LstFamAvail = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "LstFamAvail") == "true");
	var ButFamViewAvail = !LstFamAlt;
	var ButFamViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "ButFamViewActive") == "true");

	var LstSilAlt = (retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstSilAlt") == "true");
	var LstSilAvail = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "LstSilAvail") == "true");
	var ButSilViewAvail = !LstSilAlt;
	var ButSilViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "ButSilViewActive") == "true");

	var LstMtpAlt = (retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstMtpAlt") == "true");
	var LstMtpAvail = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "LstMtpAvail") == "true");
	var ButMtpViewAvail = !LstMtpAlt;
	var ButMtpViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavGlobal", "ButMtpViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Mch", LstMchAvail, 96);
	height -= setCtlAvail(contcontdoc, "Mch2", LstMchAvail && !LstMchAlt, (LstMchAvail) ? 71 : 0);
	if (LstMchAvail) {
		if ( (LstMchAlt == !contcontdoc.getElementById("ButMchExpand")) || (!LstMchAlt == !contcontdoc.getElementById("ButMchCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynMch");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptMch", retrieveTi(srcdoc, "TagWdbeNavGlobal", "CptMch")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstMchAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButMchExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButMchCollapse", "icon/collapse"));
		};

		if (!LstMchAlt == !contcontdoc.getElementById("LstMch")) {
			mytd = contcontdoc.getElementById("rdynMch");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynMch");
			clearElem(mytd);

			if (LstMchAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstMch", "./PnlWdbeNavGlobal_LstMch.xml", true));
			};

		} else {
			if (!LstMchAlt) refreshLst(contcontdoc.getElementById("LstMch").contentWindow.document, srcdoc, 1, true, false, "FeedFLstMch",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstMchNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numFLstMch"))]);
		};

		if ((ButMchViewAvail == !contcontdoc.getElementById("ButMchView")) || !contcontdoc.getElementById("ButMchNewcrd")) {
			if (LstMchAlt) mytd = contcontdoc.getElementById("dynMch");
			else mytd = contcontdoc.getElementById("rdynMch");
			clearElem(mytd);

			first = true;

			if (ButMchViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButMchView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMchNewcrd", "icon/newcrd"));
		};

		if (ButMchViewAvail) refreshButicon(contcontdoc, "ButMchView", "icon/view", ButMchViewActive, false);

	} else setCtlAvail(contcontdoc, "Mch2", false, 0);

	height -= setCtlAvail(contcontdoc, "Lib", LstLibAvail, 96);
	height -= setCtlAvail(contcontdoc, "Lib2", LstLibAvail && !LstLibAlt, (LstLibAvail) ? 71 : 0);
	if (LstLibAvail) {
		if ( (LstLibAlt == !contcontdoc.getElementById("ButLibExpand")) || (!LstLibAlt == !contcontdoc.getElementById("ButLibCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynLib");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptLib", retrieveTi(srcdoc, "TagWdbeNavGlobal", "CptLib")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstLibAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButLibExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButLibCollapse", "icon/collapse"));
		};

		if (!LstLibAlt == !contcontdoc.getElementById("LstLib")) {
			mytd = contcontdoc.getElementById("rdynLib");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynLib");
			clearElem(mytd);

			if (LstLibAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstLib", "./PnlWdbeNavGlobal_LstLib.xml", true));
			};

		} else {
			if (!LstLibAlt) refreshLst(contcontdoc.getElementById("LstLib").contentWindow.document, srcdoc, 1, true, false, "FeedFLstLib",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstLibNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numFLstLib"))]);
		};

		if ((ButLibViewAvail == !contcontdoc.getElementById("ButLibView")) || !contcontdoc.getElementById("ButLibNewcrd")) {
			if (LstLibAlt) mytd = contcontdoc.getElementById("dynLib");
			else mytd = contcontdoc.getElementById("rdynLib");
			clearElem(mytd);

			first = true;

			if (ButLibViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButLibView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButLibNewcrd", "icon/newcrd"));
		};

		if (ButLibViewAvail) refreshButicon(contcontdoc, "ButLibView", "icon/view", ButLibViewActive, false);

	} else setCtlAvail(contcontdoc, "Lib2", false, 0);

	height -= setCtlAvail(contcontdoc, "Fam", LstFamAvail, 96);
	height -= setCtlAvail(contcontdoc, "Fam2", LstFamAvail && !LstFamAlt, (LstFamAvail) ? 71 : 0);
	if (LstFamAvail) {
		if ( (LstFamAlt == !contcontdoc.getElementById("ButFamExpand")) || (!LstFamAlt == !contcontdoc.getElementById("ButFamCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynFam");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptFam", retrieveTi(srcdoc, "TagWdbeNavGlobal", "CptFam")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstFamAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButFamExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButFamCollapse", "icon/collapse"));
		};

		if (!LstFamAlt == !contcontdoc.getElementById("LstFam")) {
			mytd = contcontdoc.getElementById("rdynFam");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynFam");
			clearElem(mytd);

			if (LstFamAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstFam", "./PnlWdbeNavGlobal_LstFam.xml", true));
			};

		} else {
			if (!LstFamAlt) refreshLst(contcontdoc.getElementById("LstFam").contentWindow.document, srcdoc, 1, true, false, "FeedFLstFam",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstFamNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numFLstFam"))]);
		};

		if ((ButFamViewAvail == !contcontdoc.getElementById("ButFamView")) || !contcontdoc.getElementById("ButFamNewcrd")) {
			if (LstFamAlt) mytd = contcontdoc.getElementById("dynFam");
			else mytd = contcontdoc.getElementById("rdynFam");
			clearElem(mytd);

			first = true;

			if (ButFamViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButFamView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButFamNewcrd", "icon/newcrd"));
		};

		if (ButFamViewAvail) refreshButicon(contcontdoc, "ButFamView", "icon/view", ButFamViewActive, false);

	} else setCtlAvail(contcontdoc, "Fam2", false, 0);

	height -= setCtlAvail(contcontdoc, "Sil", LstSilAvail, 96);
	height -= setCtlAvail(contcontdoc, "Sil2", LstSilAvail && !LstSilAlt, (LstSilAvail) ? 71 : 0);
	if (LstSilAvail) {
		if ( (LstSilAlt == !contcontdoc.getElementById("ButSilExpand")) || (!LstSilAlt == !contcontdoc.getElementById("ButSilCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynSil");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptSil", retrieveTi(srcdoc, "TagWdbeNavGlobal", "CptSil")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstSilAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButSilExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButSilCollapse", "icon/collapse"));
		};

		if (!LstSilAlt == !contcontdoc.getElementById("LstSil")) {
			mytd = contcontdoc.getElementById("rdynSil");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynSil");
			clearElem(mytd);

			if (LstSilAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstSil", "./PnlWdbeNavGlobal_LstSil.xml", true));
			};

		} else {
			if (!LstSilAlt) refreshLst(contcontdoc.getElementById("LstSil").contentWindow.document, srcdoc, 1, true, false, "FeedFLstSil",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstSilNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numFLstSil"))]);
		};

		if ((ButSilViewAvail == !contcontdoc.getElementById("ButSilView")) || !contcontdoc.getElementById("ButSilNewcrd")) {
			if (LstSilAlt) mytd = contcontdoc.getElementById("dynSil");
			else mytd = contcontdoc.getElementById("rdynSil");
			clearElem(mytd);

			first = true;

			if (ButSilViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButSilView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButSilNewcrd", "icon/newcrd"));
		};

		if (ButSilViewAvail) refreshButicon(contcontdoc, "ButSilView", "icon/view", ButSilViewActive, false);

	} else setCtlAvail(contcontdoc, "Sil2", false, 0);

	height -= setCtlAvail(contcontdoc, "Mtp", LstMtpAvail, 96);
	height -= setCtlAvail(contcontdoc, "Mtp2", LstMtpAvail && !LstMtpAlt, (LstMtpAvail) ? 71 : 0);
	if (LstMtpAvail) {
		if ( (LstMtpAlt == !contcontdoc.getElementById("ButMtpExpand")) || (!LstMtpAlt == !contcontdoc.getElementById("ButMtpCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynMtp");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptMtp", retrieveTi(srcdoc, "TagWdbeNavGlobal", "CptMtp")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstMtpAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButMtpExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButMtpCollapse", "icon/collapse"));
		};

		if (!LstMtpAlt == !contcontdoc.getElementById("LstMtp")) {
			mytd = contcontdoc.getElementById("rdynMtp");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynMtp");
			clearElem(mytd);

			if (LstMtpAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstMtp", "./PnlWdbeNavGlobal_LstMtp.xml", true));
			};

		} else {
			if (!LstMtpAlt) refreshLst(contcontdoc.getElementById("LstMtp").contentWindow.document, srcdoc, 1, true, false, "FeedFLstMtp",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "LstMtpNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numFLstMtp"))]);
		};

		if ((ButMtpViewAvail == !contcontdoc.getElementById("ButMtpView")) || !contcontdoc.getElementById("ButMtpNewcrd")) {
			if (LstMtpAlt) mytd = contcontdoc.getElementById("dynMtp");
			else mytd = contcontdoc.getElementById("rdynMtp");
			clearElem(mytd);

			first = true;

			if (ButMtpViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButMtpView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMtpNewcrd", "icon/newcrd"));
		};

		if (ButMtpViewAvail) refreshButicon(contcontdoc, "ButMtpView", "icon/view", ButMtpViewActive, false);

	} else setCtlAvail(contcontdoc, "Mtp2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Global", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Global_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Global_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Global_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavGlobal", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("Global_src").contentDocument;

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
	setSi(srcdoc, "StatAppWdbeNavGlobal", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeNavGlobal", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavGlobalDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavGlobalDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavGlobal", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavGlobal", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbeNavGlobal", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeNavGlobal", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeNavGlobalData", scrJref, "ContIacWdbeNavGlobal");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeNavGlobal", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeNavGlobal", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavGlobal", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeNavGlobalData", "ContIacWdbeNavGlobal", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeNavGlobalData", "FeedFLstFam", srcdoc)) mask.push("feedFLstFam");
	if (updateSrcblock(dom, "DpchEngWdbeNavGlobalData", "FeedFLstLib", srcdoc)) mask.push("feedFLstLib");
	if (updateSrcblock(dom, "DpchEngWdbeNavGlobalData", "FeedFLstMch", srcdoc)) mask.push("feedFLstMch");
	if (updateSrcblock(dom, "DpchEngWdbeNavGlobalData", "FeedFLstMtp", srcdoc)) mask.push("feedFLstMtp");
	if (updateSrcblock(dom, "DpchEngWdbeNavGlobalData", "FeedFLstSil", srcdoc)) mask.push("feedFLstSil");
	if (updateSrcblock(dom, "DpchEngWdbeNavGlobalData", "StatAppWdbeNavGlobal", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeNavGlobalData", "StatShrWdbeNavGlobal", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeNavGlobalData", "TagWdbeNavGlobal", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeNavGlobalData") {
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
			if (blk.nodeName == "DpchEngWdbeNavGlobalData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Global");
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

			} else if (blk.nodeName == "DpchEngWdbeNavGlobalData") {
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
