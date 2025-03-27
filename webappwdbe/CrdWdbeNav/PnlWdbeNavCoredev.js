// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavCoredev", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeNavCoredev", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Coredev", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Coredev_side").setAttribute("height", "30");
	doc.getElementById("Coredev_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Coredev_side").src = "./PnlWdbeNavCoredev_aside.html";
	doc.getElementById("Coredev_cont").src = "./PnlWdbeNavCoredev_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavCoredev", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeNavCoredev", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Coredev_side").src = "./PnlWdbeNavCoredev_bside.html";
	doc.getElementById("Coredev_cont").src = "./PnlWdbeNavCoredev_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Coredev_side").contentDocument;
	contdoc = doc.getElementById("Coredev_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavCoredev", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Coredev_side").contentDocument;
	contdoc = doc.getElementById("Coredev_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Coredev_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Coredev_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavCoredev", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavCoredev", "srefIxWdbeVExpstate");

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

	var height = 202; // full cont height

	// IP refreshBD.vars --- BEGIN
	var LstCprAlt = (retrieveSi(srcdoc, "StatAppWdbeNavCoredev", "LstCprAlt") == "true");
	var LstCprAvail = (retrieveSi(srcdoc, "StatShrWdbeNavCoredev", "LstCprAvail") == "true");
	var ButCprViewAvail = !LstCprAlt;
	var ButCprViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavCoredev", "ButCprViewActive") == "true");

	var LstCvrAlt = (retrieveSi(srcdoc, "StatAppWdbeNavCoredev", "LstCvrAlt") == "true");
	var LstCvrAvail = (retrieveSi(srcdoc, "StatShrWdbeNavCoredev", "LstCvrAvail") == "true");
	var ButCvrViewAvail = !LstCvrAlt;
	var ButCvrViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavCoredev", "ButCvrViewActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Cpr", LstCprAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cpr2", LstCprAvail && !LstCprAlt, (LstCprAvail) ? 71 : 0);
	if (LstCprAvail) {
		if ( (LstCprAlt == !contcontdoc.getElementById("ButCprExpand")) || (!LstCprAlt == !contcontdoc.getElementById("ButCprCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCpr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCpr", retrieveTi(srcdoc, "TagWdbeNavCoredev", "CptCpr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCprAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCprExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCprCollapse", "icon/collapse"));
		};

		if (!LstCprAlt == !contcontdoc.getElementById("LstCpr")) {
			mytd = contcontdoc.getElementById("rdynCpr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCpr");
			clearElem(mytd);

			if (LstCprAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCpr", "./PnlWdbeNavCoredev_LstCpr.xml", true));
			};

		} else {
			if (!LstCprAlt) refreshLst(contcontdoc.getElementById("LstCpr").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCpr",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavCoredev", "LstCprNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavCoredev", "numFLstCpr"))]);
		};

		if ((ButCprViewAvail == !contcontdoc.getElementById("ButCprView")) || !contcontdoc.getElementById("ButCprNewcrd")) {
			if (LstCprAlt) mytd = contcontdoc.getElementById("dynCpr");
			else mytd = contcontdoc.getElementById("rdynCpr");
			clearElem(mytd);

			first = true;

			if (ButCprViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCprView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCprNewcrd", "icon/newcrd"));
		};

		if (ButCprViewAvail) refreshButicon(contcontdoc, "ButCprView", "icon/view", ButCprViewActive, false);

	} else setCtlAvail(contcontdoc, "Cpr2", false, 0);

	height -= setCtlAvail(contcontdoc, "Cvr", LstCvrAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cvr2", LstCvrAvail && !LstCvrAlt, (LstCvrAvail) ? 71 : 0);
	if (LstCvrAvail) {
		if ( (LstCvrAlt == !contcontdoc.getElementById("ButCvrExpand")) || (!LstCvrAlt == !contcontdoc.getElementById("ButCvrCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCvr");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCvr", retrieveTi(srcdoc, "TagWdbeNavCoredev", "CptCvr")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCvrAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCvrExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCvrCollapse", "icon/collapse"));
		};

		if (!LstCvrAlt == !contcontdoc.getElementById("LstCvr")) {
			mytd = contcontdoc.getElementById("rdynCvr");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCvr");
			clearElem(mytd);

			if (LstCvrAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCvr", "./PnlWdbeNavCoredev_LstCvr.xml", true));
			};

		} else {
			if (!LstCvrAlt) refreshLst(contcontdoc.getElementById("LstCvr").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCvr",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavCoredev", "LstCvrNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavCoredev", "numFLstCvr"))]);
		};

		if ((ButCvrViewAvail == !contcontdoc.getElementById("ButCvrView")) || !contcontdoc.getElementById("ButCvrNewcrd")) {
			if (LstCvrAlt) mytd = contcontdoc.getElementById("dynCvr");
			else mytd = contcontdoc.getElementById("rdynCvr");
			clearElem(mytd);

			first = true;

			if (ButCvrViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCvrView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCvrNewcrd", "icon/newcrd"));
		};

		if (ButCvrViewAvail) refreshButicon(contcontdoc, "ButCvrView", "icon/view", ButCvrViewActive, false);

	} else setCtlAvail(contcontdoc, "Cvr2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Coredev", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Coredev_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Coredev_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Coredev_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavCoredev", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("Coredev_src").contentDocument;

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
	setSi(srcdoc, "StatAppWdbeNavCoredev", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeNavCoredev", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavCoredevDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavCoredevDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavCoredev", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavCoredev", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavCoredev", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeNavCoredev", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavCoredev", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbeNavCoredev", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeNavCoredev", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeNavCoredev", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeNavCoredevData", scrJref, "ContIacWdbeNavCoredev");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeNavCoredev", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeNavCoredev", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavCoredev", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavCoredev", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWdbeNavCoredevData", "ContIacWdbeNavCoredev", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeNavCoredevData", "FeedFLstCpr", srcdoc)) mask.push("feedFLstCpr");
	if (updateSrcblock(dom, "DpchEngWdbeNavCoredevData", "FeedFLstCvr", srcdoc)) mask.push("feedFLstCvr");
	if (updateSrcblock(dom, "DpchEngWdbeNavCoredevData", "StatAppWdbeNavCoredev", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeNavCoredevData", "StatShrWdbeNavCoredev", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeNavCoredevData", "TagWdbeNavCoredev", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeNavCoredevData") {
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
			if (blk.nodeName == "DpchEngWdbeNavCoredevData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Coredev");
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

			} else if (blk.nodeName == "DpchEngWdbeNavCoredevData") {
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
