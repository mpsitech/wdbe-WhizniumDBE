// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeNavDevdev", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Devdev", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Devdev_side").setAttribute("height", "30");
	doc.getElementById("Devdev_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Devdev_side").src = "./PnlWdbeNavDevdev_aside.html";
	doc.getElementById("Devdev_cont").src = "./PnlWdbeNavDevdev_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeNavDevdev", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Devdev_side").src = "./PnlWdbeNavDevdev_bside.html";
	doc.getElementById("Devdev_cont").src = "./PnlWdbeNavDevdev_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Devdev_side").contentDocument;
	contdoc = doc.getElementById("Devdev_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavDevdev", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Devdev_side").contentDocument;
	contdoc = doc.getElementById("Devdev_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Devdev_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Devdev_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavDevdev", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "srefIxWdbeVExpstate");

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

	var height = 298; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstPrjAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "LstPrjAlt") == "true");
	var LstPrjAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDevdev", "LstPrjAvail") == "true");
	var ButPrjViewAvail = !LstPrjAlt;
	var ButPrjViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDevdev", "ButPrjViewActive") == "true");

	var LstVerAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "LstVerAlt") == "true");
	var LstVerAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDevdev", "LstVerAvail") == "true");
	var ButVerViewAvail = !LstVerAlt;
	var ButVerViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDevdev", "ButVerViewActive") == "true");

	var LstUntAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "LstUntAlt") == "true");
	var LstUntAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDevdev", "LstUntAvail") == "true");
	var ButUntViewAvail = !LstUntAlt;
	var ButUntViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDevdev", "ButUntViewActive") == "true");
	var ButUntNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavDevdev", "ButUntNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Prj", LstPrjAvail, 96);
	height -= setCtlAvail(contcontdoc, "Prj2", LstPrjAvail && !LstPrjAlt, (LstPrjAvail) ? 71 : 0);
	if (LstPrjAvail) {
		if ( (LstPrjAlt == !contcontdoc.getElementById("ButPrjExpand")) || (!LstPrjAlt == !contcontdoc.getElementById("ButPrjCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynPrj");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptPrj", retrieveTi(srcdoc, "TagWdbeNavDevdev", "CptPrj")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstPrjAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButPrjExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButPrjCollapse", "icon/collapse"));
		};

		if (!LstPrjAlt == !contcontdoc.getElementById("LstPrj")) {
			mytd = contcontdoc.getElementById("rdynPrj");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynPrj");
			clearElem(mytd);

			if (LstPrjAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstPrj", "./PnlWdbeNavDevdev_LstPrj.xml", true));
			};

		} else {
			if (!LstPrjAlt) refreshLst(contcontdoc.getElementById("LstPrj").contentWindow.document, srcdoc, 1, true, false, "FeedFLstPrj",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "LstPrjNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDevdev", "numFLstPrj"))]);
		};

		if ((ButPrjViewAvail == !contcontdoc.getElementById("ButPrjView")) || !contcontdoc.getElementById("ButPrjNewcrd")) {
			if (LstPrjAlt) mytd = contcontdoc.getElementById("dynPrj");
			else mytd = contcontdoc.getElementById("rdynPrj");
			clearElem(mytd);

			first = true;

			if (ButPrjViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButPrjView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButPrjNewcrd", "icon/newcrd"));
		};

		if (ButPrjViewAvail) refreshButicon(contcontdoc, "ButPrjView", "icon/view", ButPrjViewActive, false);

	} else setCtlAvail(contcontdoc, "Prj2", false, 0);

	height -= setCtlAvail(contcontdoc, "Ver", LstVerAvail, 96);
	height -= setCtlAvail(contcontdoc, "Ver2", LstVerAvail && !LstVerAlt, (LstVerAvail) ? 71 : 0);
	if (LstVerAvail) {
		if ( (LstVerAlt == !contcontdoc.getElementById("ButVerExpand")) || (!LstVerAlt == !contcontdoc.getElementById("ButVerCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynVer");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptVer", retrieveTi(srcdoc, "TagWdbeNavDevdev", "CptVer")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstVerAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButVerExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButVerCollapse", "icon/collapse"));
		};

		if (!LstVerAlt == !contcontdoc.getElementById("LstVer")) {
			mytd = contcontdoc.getElementById("rdynVer");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynVer");
			clearElem(mytd);

			if (LstVerAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstVer", "./PnlWdbeNavDevdev_LstVer.xml", true));
			};

		} else {
			if (!LstVerAlt) refreshLst(contcontdoc.getElementById("LstVer").contentWindow.document, srcdoc, 1, true, false, "FeedFLstVer",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "LstVerNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDevdev", "numFLstVer"))]);
		};

		if ((ButVerViewAvail == !contcontdoc.getElementById("ButVerView")) || !contcontdoc.getElementById("ButVerNewcrd")) {
			if (LstVerAlt) mytd = contcontdoc.getElementById("dynVer");
			else mytd = contcontdoc.getElementById("rdynVer");
			clearElem(mytd);

			first = true;

			if (ButVerViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButVerView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButVerNewcrd", "icon/newcrd"));
		};

		if (ButVerViewAvail) refreshButicon(contcontdoc, "ButVerView", "icon/view", ButVerViewActive, false);

	} else setCtlAvail(contcontdoc, "Ver2", false, 0);

	height -= setCtlAvail(contcontdoc, "Unt", LstUntAvail, 96);
	height -= setCtlAvail(contcontdoc, "Unt2", LstUntAvail && !LstUntAlt, (LstUntAvail) ? 71 : 0);
	if (LstUntAvail) {
		if ( (LstUntAlt == !contcontdoc.getElementById("ButUntExpand")) || (!LstUntAlt == !contcontdoc.getElementById("ButUntCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynUnt");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptUnt", retrieveTi(srcdoc, "TagWdbeNavDevdev", "CptUnt")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstUntAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButUntExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButUntCollapse", "icon/collapse"));
		};

		if (!LstUntAlt == !contcontdoc.getElementById("LstUnt")) {
			mytd = contcontdoc.getElementById("rdynUnt");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynUnt");
			clearElem(mytd);

			if (LstUntAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstUnt", "./PnlWdbeNavDevdev_LstUnt.xml", true));
			};

		} else {
			if (!LstUntAlt) refreshLst(contcontdoc.getElementById("LstUnt").contentWindow.document, srcdoc, 1, true, false, "FeedFLstUnt",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "LstUntNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDevdev", "numFLstUnt"))]);
		};

		if ((ButUntViewAvail == !contcontdoc.getElementById("ButUntView")) || !contcontdoc.getElementById("ButUntNewcrd")) {
			if (LstUntAlt) mytd = contcontdoc.getElementById("dynUnt");
			else mytd = contcontdoc.getElementById("rdynUnt");
			clearElem(mytd);

			first = true;

			if (ButUntViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButUntView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButUntNewcrd", "icon/newcrd"));
		};

		if (ButUntViewAvail) refreshButicon(contcontdoc, "ButUntView", "icon/view", ButUntViewActive, false);
		refreshButicon(contcontdoc, "ButUntNewcrd", "icon/newcrd", ButUntNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Unt2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Devdev", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Devdev_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Devdev_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Devdev_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavDevdev", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("Devdev_src").contentDocument;

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
	setSi(srcdoc, "StatAppWdbeNavDevdev", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeNavDevdev", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavDevdevDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavDevdevDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDevdev", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavDevdev", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDevdev", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDevdev", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavDevdev", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbeNavDevdev", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDevdev", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeNavDevdev", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeNavDevdevData", scrJref, "ContIacWdbeNavDevdev");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDevdev", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeNavDevdev", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavDevdev", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDevdev", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWdbeNavDevdevData", "ContIacWdbeNavDevdev", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeNavDevdevData", "FeedFLstPrj", srcdoc)) mask.push("feedFLstPrj");
	if (updateSrcblock(dom, "DpchEngWdbeNavDevdevData", "FeedFLstUnt", srcdoc)) mask.push("feedFLstUnt");
	if (updateSrcblock(dom, "DpchEngWdbeNavDevdevData", "FeedFLstVer", srcdoc)) mask.push("feedFLstVer");
	if (updateSrcblock(dom, "DpchEngWdbeNavDevdevData", "StatAppWdbeNavDevdev", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeNavDevdevData", "StatShrWdbeNavDevdev", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeNavDevdevData", "TagWdbeNavDevdev", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeNavDevdevData") {
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
			if (blk.nodeName == "DpchEngWdbeNavDevdevData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Devdev");
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

			} else if (blk.nodeName == "DpchEngWdbeNavDevdevData") {
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
