// IP cust --- INSERT

// --- expand state management
function minimize(updh) {
	if (retrieveSi(srcdoc, "StatAppWdbePrtDetail", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbePrtDetail", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getRecwnd().changeHeight("Detail", 30, updh);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Detail_side").setAttribute("height", "30");
	doc.getElementById("Detail_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Detail_side").src = "./PnlWdbePrtDetail_aside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbePrtDetail_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbePrtDetail", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbePrtDetail", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Detail_side").src = "./PnlWdbePrtDetail_bside.html";
	doc.getElementById("Detail_cont").src = "./PnlWdbePrtDetail_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbePrtDetail", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Detail_side").contentDocument;
	contdoc = doc.getElementById("Detail_cont").contentDocument;
	contcontdoc = contdoc.getElementById("Detail_cont").contentDocument;
	ftrdoc = contdoc.getElementById("Detail_ftr").contentDocument;

	// IP initBD --- BEGIN
	initCpt(contcontdoc, "CptSrf", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptSrf"));
	initCpt(contcontdoc, "CptMdl", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptMdl"));
	initCpt(contcontdoc, "CptDir", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptDir"));
	refreshPup(contcontdoc, srcdoc, "PupDir", "", "FeedFPupDir", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numFPupDir"), retrieveSi(srcdoc, "StatShrWdbePrtDetail", "PupDirActive"), false);
	initCpt(contcontdoc, "CptHty", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptHty"));
	initCpt(contcontdoc, "CptWid", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptWid"));
	initCpt(contcontdoc, "CptMmx", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptMmx"));
	initCpt(contcontdoc, "CptDfv", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptDfv"));
	initCpt(contcontdoc, "CptCpi", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptCpi"));
	initCpt(contcontdoc, "CptCpr", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptCpr"));
	initCpt(contcontdoc, "CptCsi", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptCsi"));
	initCpt(contcontdoc, "CptCmt", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptCmt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbePrtDetail", "srefIxWdbeVExpstate");

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

	var height = 488; // full cont height

	// IP refreshBD.vars --- BEGIN
	var TxtSrfActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxtSrfActive") == "true");

	var LstCluAlt = (retrieveSi(srcdoc, "StatAppWdbePrtDetail", "LstCluAlt") == "true");
	var LstCluActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "LstCluActive") == "true");
	var ButCluViewAvail = !LstCluAlt;
	var ButCluViewActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButCluViewActive") == "true");
	var ButCluClusterAvail = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButCluClusterAvail") == "true");
	var ButCluUnclusterAvail = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButCluUnclusterAvail") == "true");

	var TxtMdlActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxtMdlActive") == "true");
	var ButMdlViewAvail = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButMdlViewAvail") == "true");
	var ButMdlViewActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButMdlViewActive") == "true");

	var PupDirActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "PupDirActive") == "true");

	var PupHtyAlt = (retrieveSi(srcdoc, "StatAppWdbePrtDetail", "PupHtyAlt") == "true");
	var TxfHtyValid = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxfHtyValid") == "true");
	var PupHtyActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "PupHtyActive") == "true");
	var ButHtyEditAvail = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButHtyEditAvail") == "true");

	var TxfWidActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxfWidActive") == "true");

	var TxfMmxActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxfMmxActive") == "true");

	var TxfDfvActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxfDfvActive") == "true");

	var TxtCpiAlt = (retrieveSi(srcdoc, "StatAppWdbePrtDetail", "TxtCpiAlt") == "true");
	var TxfCpiValid = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxfCpiValid") == "true");
	var TxtCpiActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxtCpiActive") == "true");
	var ButCpiViewAvail = !TxtCpiAlt && (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButCpiViewAvail") == "true");;

	var TxtCprAlt = (retrieveSi(srcdoc, "StatAppWdbePrtDetail", "TxtCprAlt") == "true");
	var TxfCprValid = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxfCprValid") == "true");
	var TxtCprActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxtCprActive") == "true");
	var ButCprViewAvail = !TxtCprAlt && (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButCprViewAvail") == "true");;

	var TxtCsiAlt = (retrieveSi(srcdoc, "StatAppWdbePrtDetail", "TxtCsiAlt") == "true");
	var TxfCsiValid = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxfCsiValid") == "true");
	var TxtCsiActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxtCsiActive") == "true");
	var ButCsiViewAvail = !TxtCsiAlt && (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButCsiViewAvail") == "true");;

	var TxfCmtActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "TxfCmtActive") == "true");

	var ButSaveActive = (retrieveSi(srcdoc, "StatShrWdbePrtDetail", "ButSaveActive") == "true");
	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtSrf", retrieveCi(srcdoc, "ContInfWdbePrtDetail", "TxtSrf"));

	height -= setCtlAvail(contcontdoc, "Clu2", !LstCluAlt, 71);
	if ( (LstCluAlt == !contcontdoc.getElementById("ButCluExpand")) || (!LstCluAlt == !contcontdoc.getElementById("ButCluCollapse")) ) {
		mytd = contcontdoc.getElementById("ldynClu");
		clearElem(mytd);

		mytd.appendChild(makeSpanCpt(contcontdoc, "CptClu", retrieveTi(srcdoc, "TagWdbePrtDetail", "CptClu")));

		mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
		if (LstCluAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCluExpand", "icon/expand"));
		else mytd.appendChild(makeImgBut(contcontdoc, "ButCluCollapse", "icon/collapse"));
	};

	if ( (LstCluAlt == !contcontdoc.getElementById("TxtClu")) || (!LstCluAlt == !contcontdoc.getElementById("LstClu")) ) {
		mytd = contcontdoc.getElementById("dynClu");
		clearElem(mytd);

		if (LstCluAlt) {
			mytd.setAttribute("rowspan", "1");
			mytd.appendChild(makeInputTxt(contcontdoc, "TxtClu", ""));
		} else {
			mytd.setAttribute("rowspan", "2");
			mytd.appendChild(makeIframeLst(contcontdoc, "LstClu", "./PnlWdbePrtDetail_LstClu.xml", false));
		};

	} else {
		if (!LstCluAlt) refreshLst(contcontdoc.getElementById("LstClu").contentWindow.document, srcdoc, 1, false, false, "FeedFLstClu",
					parseInt(retrieveSi(srcdoc, "StatAppWdbePrtDetail", "LstCluNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numFLstClu"))]);
	};

	if (LstCluAlt) refreshTxt(contcontdoc, "TxtClu", retrieveCi(srcdoc, "ContInfWdbePrtDetail", "TxtClu"));

	if ((ButCluViewAvail == !contcontdoc.getElementById("ButCluView")) || (ButCluClusterAvail == !contcontdoc.getElementById("ButCluCluster")) || (ButCluUnclusterAvail == !contcontdoc.getElementById("ButCluUncluster"))) {
		mytd = contcontdoc.getElementById("rdynClu");
		clearElem(mytd);

		first = true;

		if (ButCluViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluView", "icon/view"));
		};

		if (ButCluClusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluCluster", "icon/cluster"));
		};

		if (ButCluUnclusterAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCluUncluster", "icon/uncluster"));
		};
	};

	if (ButCluViewAvail) refreshButicon(contcontdoc, "ButCluView", "icon/view", ButCluViewActive, false);

	if ((ButMdlViewAvail == !contcontdoc.getElementById("ButMdlView"))) {
		mytd = contcontdoc.getElementById("rdynMdl");
		clearElem(mytd);

		first = true;

		if (ButMdlViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButMdlView", "icon/view"));
		};
	};

	refreshTxt(contcontdoc, "TxtMdl", retrieveCi(srcdoc, "ContInfWdbePrtDetail", "TxtMdl"));

	if (ButMdlViewAvail) refreshButicon(contcontdoc, "ButMdlView", "icon/view", ButMdlViewActive, false);

	contcontdoc.getElementById("PupDir").value = retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numFPupDir");

	if ( (PupHtyAlt == !contcontdoc.getElementById("TxfHty")) || (!PupHtyAlt == !contcontdoc.getElementById("PupHty")) ) {
		mytd = contcontdoc.getElementById("dynHty");
		clearElem(mytd);

		if (PupHtyAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfHty", ""));
		else mytd.appendChild(makeSelectPup(contcontdoc, "PupHty", ""));
	};

	if (PupHtyAlt) refreshTxf(contcontdoc, "TxfHty", "", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "TxfHty"), PupHtyActive, false, TxfHtyValid);
	else refreshPup(contcontdoc, srcdoc, "PupHty", "", "FeedFPupHty", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numFPupHty"), true, false);

	if ((ButHtyEditAvail == !contcontdoc.getElementById("ButHtyEdit"))) {
		mytd = contcontdoc.getElementById("rdynHty");
		clearElem(mytd);

		first = true;

		if (ButHtyEditAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButHtyEdit", "icon/edit"));
		};
	};

	refreshTxf(contcontdoc, "TxfWid", "s", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "TxfWid"), TxfWidActive, false, true);

	refreshTxf(contcontdoc, "TxfMmx", "s", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "TxfMmx"), TxfMmxActive, false, true);

	refreshTxft(contcontdoc, "TxfDfv", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "TxfDfv"), TxfDfvActive, false, true);

	if ( (TxtCpiAlt == !contcontdoc.getElementById("TxfCpi")) || (!TxtCpiAlt == !contcontdoc.getElementById("TxtCpi")) ) {
		mytd = contcontdoc.getElementById("dynCpi");
		clearElem(mytd);

		if (TxtCpiAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfCpi", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtCpi", ""));
	};

	if (TxtCpiAlt) refreshTxf(contcontdoc, "TxfCpi", "", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "TxfCpi"), TxtCpiActive, false, TxfCpiValid);
	else refreshTxt(contcontdoc, "TxtCpi", retrieveCi(srcdoc, "ContInfWdbePrtDetail", "TxtCpi"));

	if ((ButCpiViewAvail == !contcontdoc.getElementById("ButCpiView"))) {
		mytd = contcontdoc.getElementById("rdynCpi");
		clearElem(mytd);

		first = true;

		if (ButCpiViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCpiView", "icon/view"));
		};
	};

	if ( (TxtCprAlt == !contcontdoc.getElementById("TxfCpr")) || (!TxtCprAlt == !contcontdoc.getElementById("TxtCpr")) ) {
		mytd = contcontdoc.getElementById("dynCpr");
		clearElem(mytd);

		if (TxtCprAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfCpr", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtCpr", ""));
	};

	if (TxtCprAlt) refreshTxf(contcontdoc, "TxfCpr", "", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "TxfCpr"), TxtCprActive, false, TxfCprValid);
	else refreshTxt(contcontdoc, "TxtCpr", retrieveCi(srcdoc, "ContInfWdbePrtDetail", "TxtCpr"));

	if ((ButCprViewAvail == !contcontdoc.getElementById("ButCprView"))) {
		mytd = contcontdoc.getElementById("rdynCpr");
		clearElem(mytd);

		first = true;

		if (ButCprViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCprView", "icon/view"));
		};
	};

	if ( (TxtCsiAlt == !contcontdoc.getElementById("TxfCsi")) || (!TxtCsiAlt == !contcontdoc.getElementById("TxtCsi")) ) {
		mytd = contcontdoc.getElementById("dynCsi");
		clearElem(mytd);

		if (TxtCsiAlt) mytd.appendChild(makeInputTxf(contcontdoc, "TxfCsi", ""));
		else mytd.appendChild(makeInputTxt(contcontdoc, "TxtCsi", ""));
	};

	if (TxtCsiAlt) refreshTxf(contcontdoc, "TxfCsi", "", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "TxfCsi"), TxtCsiActive, false, TxfCsiValid);
	else refreshTxt(contcontdoc, "TxtCsi", retrieveCi(srcdoc, "ContInfWdbePrtDetail", "TxtCsi"));

	if ((ButCsiViewAvail == !contcontdoc.getElementById("ButCsiView"))) {
		mytd = contcontdoc.getElementById("rdynCsi");
		clearElem(mytd);

		first = true;

		if (ButCsiViewAvail) {
			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCsiView", "icon/view"));
		};
	};

	refreshTxft(contcontdoc, "TxfCmt", retrieveCi(srcdoc, "ContIacWdbePrtDetail", "TxfCmt"), TxfCmtActive, false, true);

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
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbePrtDetail", "srefIxWdbeVExpstate");

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

function handleButCollapseClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbePrtDetail", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbePrtDetail", basectlsref + "Alt", "false");
	refresh();
};

function handleButToggleClick(basectlsref) {
	var alt;

	if (retrieveSi(srcdoc, "StatAppWdbePrtDetail", basectlsref + "Alt") == "true") alt = "false"; else alt = "true";
	setSi(srcdoc, "StatAppWdbePrtDetail", basectlsref + "Alt", alt);

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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrtDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrtDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleButDlgopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbePrtDetailDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoDlgopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbePrtDetail", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbePrtDetail", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbePrtDetail", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbePrtDetail", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrtDetailData", scrJref, "ContIacWdbePrtDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbePrtDetail", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbePrtDetail", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, false, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbePrtDetail", "numF" + ctlsref))]);
	};
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWdbePrtDetail", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrtDetailData", scrJref, "ContIacWdbePrtDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleTxfKey(_doc, ctlsref, size, evt) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	if (evt.keyCode == 13) {
		setCi(srcdoc, "ContIacWdbePrtDetail", ctlsref, elem.value);

		var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrtDetailData", scrJref, "ContIacWdbePrtDetail");
		sendReq(str, doc, handleDpchAppDataDoReply);

		return false;
	};

	return true;
};

function handleTxfChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "txf" + size + "mod");

	setCi(srcdoc, "ContIacWdbePrtDetail", ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrtDetailData", scrJref, "ContIacWdbePrtDetail");
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

	setCi(srcdoc, "ContIacWdbePrtDetail", ctlsref, elem.value.replace(/\n/g, ";"));

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbePrtDetailData", scrJref, "ContIacWdbePrtDetail");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbePrtDetailData", "ContIacWdbePrtDetail", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbePrtDetailData", "ContInfWdbePrtDetail", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbePrtDetailData", "FeedFLstClu", srcdoc)) mask.push("feedFLstClu");
	if (updateSrcblock(dom, "DpchEngWdbePrtDetailData", "FeedFPupDir", srcdoc)) mask.push("feedFPupDir");
	if (updateSrcblock(dom, "DpchEngWdbePrtDetailData", "FeedFPupHty", srcdoc)) mask.push("feedFPupHty");
	if (updateSrcblock(dom, "DpchEngWdbePrtDetailData", "StatAppWdbePrtDetail", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbePrtDetailData", "StatShrWdbePrtDetail", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbePrtDetailData", "TagWdbePrtDetail", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbePrtDetailData") {
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
			if (blk.nodeName == "DpchEngWdbePrtDetailData") {
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

			} else if (blk.nodeName == "DpchEngWdbePrtDetailData") {
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

