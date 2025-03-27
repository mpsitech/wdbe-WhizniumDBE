// IP cust --- INSERT

// --- expand state management
function minimize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavDeploy", "srefIxWdbeVExpstate") == "mind") return;

	setSi(srcdoc, "StatAppWdbeNavDeploy", "srefIxWdbeVExpstate", "mind");

	// change container heights
	getCrdwnd().changeHeight("Deploy", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Deploy_side").setAttribute("height", "30");
	doc.getElementById("Deploy_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Deploy_side").src = "./PnlWdbeNavDeploy_aside.html";
	doc.getElementById("Deploy_cont").src = "./PnlWdbeNavDeploy_a.html";
};

function regularize() {
	if (retrieveSi(srcdoc, "StatAppWdbeNavDeploy", "srefIxWdbeVExpstate") == "regd") return;

	setSi(srcdoc, "StatAppWdbeNavDeploy", "srefIxWdbeVExpstate", "regd");

	// change content (container heights in refreshBD)
	doc.getElementById("Deploy_side").src = "./PnlWdbeNavDeploy_bside.html";
	doc.getElementById("Deploy_cont").src = "./PnlWdbeNavDeploy_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Deploy_side").contentDocument;
	contdoc = doc.getElementById("Deploy_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavDeploy", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Deploy_side").contentDocument;
	contdoc = doc.getElementById("Deploy_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Deploy_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Deploy_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWdbeNavDeploy", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavDeploy", "srefIxWdbeVExpstate");

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
	var LstCmpAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDeploy", "LstCmpAlt") == "true");
	var LstCmpAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDeploy", "LstCmpAvail") == "true");
	var ButCmpViewAvail = !LstCmpAlt;
	var ButCmpViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDeploy", "ButCmpViewActive") == "true");

	var LstRlsAlt = (retrieveSi(srcdoc, "StatAppWdbeNavDeploy", "LstRlsAlt") == "true");
	var LstRlsAvail = (retrieveSi(srcdoc, "StatShrWdbeNavDeploy", "LstRlsAvail") == "true");
	var ButRlsViewAvail = !LstRlsAlt;
	var ButRlsViewActive = (retrieveSi(srcdoc, "StatShrWdbeNavDeploy", "ButRlsViewActive") == "true");
	var ButRlsNewcrdActive = (retrieveSi(srcdoc, "StatShrWdbeNavDeploy", "ButRlsNewcrdActive") == "true");

	var mytd, first;
	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	height -= setCtlAvail(contcontdoc, "Cmp", LstCmpAvail, 96);
	height -= setCtlAvail(contcontdoc, "Cmp2", LstCmpAvail && !LstCmpAlt, (LstCmpAvail) ? 71 : 0);
	if (LstCmpAvail) {
		if ( (LstCmpAlt == !contcontdoc.getElementById("ButCmpExpand")) || (!LstCmpAlt == !contcontdoc.getElementById("ButCmpCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynCmp");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptCmp", retrieveTi(srcdoc, "TagWdbeNavDeploy", "CptCmp")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstCmpAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButCmpExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButCmpCollapse", "icon/collapse"));
		};

		if (!LstCmpAlt == !contcontdoc.getElementById("LstCmp")) {
			mytd = contcontdoc.getElementById("rdynCmp");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynCmp");
			clearElem(mytd);

			if (LstCmpAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstCmp", "./PnlWdbeNavDeploy_LstCmp.xml", true));
			};

		} else {
			if (!LstCmpAlt) refreshLst(contcontdoc.getElementById("LstCmp").contentWindow.document, srcdoc, 1, true, false, "FeedFLstCmp",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDeploy", "LstCmpNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDeploy", "numFLstCmp"))]);
		};

		if ((ButCmpViewAvail == !contcontdoc.getElementById("ButCmpView")) || !contcontdoc.getElementById("ButCmpNewcrd")) {
			if (LstCmpAlt) mytd = contcontdoc.getElementById("dynCmp");
			else mytd = contcontdoc.getElementById("rdynCmp");
			clearElem(mytd);

			first = true;

			if (ButCmpViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButCmpView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButCmpNewcrd", "icon/newcrd"));
		};

		if (ButCmpViewAvail) refreshButicon(contcontdoc, "ButCmpView", "icon/view", ButCmpViewActive, false);

	} else setCtlAvail(contcontdoc, "Cmp2", false, 0);

	height -= setCtlAvail(contcontdoc, "Rls", LstRlsAvail, 96);
	height -= setCtlAvail(contcontdoc, "Rls2", LstRlsAvail && !LstRlsAlt, (LstRlsAvail) ? 71 : 0);
	if (LstRlsAvail) {
		if ( (LstRlsAlt == !contcontdoc.getElementById("ButRlsExpand")) || (!LstRlsAlt == !contcontdoc.getElementById("ButRlsCollapse")) ) {
			mytd = contcontdoc.getElementById("ldynRls");
			clearElem(mytd);

			mytd.appendChild(makeSpanCpt(contcontdoc, "CptRls", retrieveTi(srcdoc, "TagWdbeNavDeploy", "CptRls")));

			mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			if (LstRlsAlt) mytd.appendChild(makeImgBut(contcontdoc, "ButRlsExpand", "icon/expand"));
			else mytd.appendChild(makeImgBut(contcontdoc, "ButRlsCollapse", "icon/collapse"));
		};

		if (!LstRlsAlt == !contcontdoc.getElementById("LstRls")) {
			mytd = contcontdoc.getElementById("rdynRls");
			clearElem(mytd);
			mytd = contcontdoc.getElementById("dynRls");
			clearElem(mytd);

			if (LstRlsAlt) {
				mytd.setAttribute("rowspan", "1");
			} else {
				mytd.setAttribute("rowspan", "2");
				mytd.appendChild(makeIframeLst(contcontdoc, "LstRls", "./PnlWdbeNavDeploy_LstRls.xml", true));
			};

		} else {
			if (!LstRlsAlt) refreshLst(contcontdoc.getElementById("LstRls").contentWindow.document, srcdoc, 1, true, false, "FeedFLstRls",
						parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDeploy", "LstRlsNumFirstdisp")), [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDeploy", "numFLstRls"))]);
		};

		if ((ButRlsViewAvail == !contcontdoc.getElementById("ButRlsView")) || !contcontdoc.getElementById("ButRlsNewcrd")) {
			if (LstRlsAlt) mytd = contcontdoc.getElementById("dynRls");
			else mytd = contcontdoc.getElementById("rdynRls");
			clearElem(mytd);

			first = true;

			if (ButRlsViewAvail) {
				if (first) first = false;
				else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
				mytd.appendChild(makeImgBut(contcontdoc, "ButRlsView", "icon/view"));
			};

			if (first) first = false;
			else mytd.appendChild(contcontdoc.createTextNode("\u00a0"));
			mytd.appendChild(makeImgBut(contcontdoc, "ButRlsNewcrd", "icon/newcrd"));
		};

		if (ButRlsViewAvail) refreshButicon(contcontdoc, "ButRlsView", "icon/view", ButRlsViewActive, false);
		refreshButicon(contcontdoc, "ButRlsNewcrd", "icon/newcrd", ButRlsNewcrdActive, false);

	} else setCtlAvail(contcontdoc, "Rls2", false, 0);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Deploy", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Deploy_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Deploy_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Deploy_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWdbeVExpstate = retrieveSi(srcdoc, "StatAppWdbeNavDeploy", "srefIxWdbeVExpstate");

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
	srcdoc = doc.getElementById("Deploy_src").contentDocument;

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
	setSi(srcdoc, "StatAppWdbeNavDeploy", basectlsref + "Alt", "true");
	refresh();
};

function handleButExpandClick(basectlsref) {
	setSi(srcdoc, "StatAppWdbeNavDeploy", basectlsref + "Alt", "false");
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
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavDeployDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleButCrdopenClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavDeployDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);
};

function handleLstLoad(lstdoc, ctlsref, ncol, multsel) {
	if (!srcdoc) return;

	if (multsel) {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDeploy", ctlsref + "NumFirstdisp")),
					parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavDeploy", "numsF" + ctlsref)));
	} else {
		refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDeploy", ctlsref + "NumFirstdisp")),
					[parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDeploy", "numF" + ctlsref))]);
	};
};

function handleLstSelect(ctlsref, multsel, num) {
	var found, oldNumFLst, numsFLst, oldNumsFLst;

	if (multsel) {
		oldNumsFLst = parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavDeploy", "numsF" + ctlsref));

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

		setCi(srcdoc, "ContIacWdbeNavDeploy", "numsF" + ctlsref, encodeUintvec(numsFLst));

	} else {
		oldNumFLst = parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDeploy", "numF" + ctlsref));
		if (num == oldNumFLst) num = 0;

		setCi(srcdoc, "ContIacWdbeNavDeploy", "numF" + ctlsref, num);
	};

	var str = serializeDpchAppData(srcdoc, "DpchAppWdbeNavDeployData", scrJref, "ContIacWdbeNavDeploy");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function changeLstNumFirstdisp(lstdoc, ctlsref, ncol, multsel, numFirstdisp, dNumFirstdisp) {
	var oldNumFirstdisp = parseInt(retrieveSi(srcdoc, "StatAppWdbeNavDeploy", ctlsref + "NumFirstdisp"));
	if (dNumFirstdisp != 0) numFirstdisp = oldNumFirstdisp + dNumFirstdisp;

	var cnt = getFeedSize(srcdoc, "FeedF" + ctlsref);

	if (numFirstdisp > (cnt-5+1)) numFirstdisp = cnt-5+1;
	if (numFirstdisp < 1) numFirstdisp = 1;

	if (numFirstdisp != oldNumFirstdisp) {
		setSi(srcdoc, "StatAppWdbeNavDeploy", ctlsref + "NumFirstdisp", "" + numFirstdisp);

		if (multsel) refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, parseUintvec(retrieveCi(srcdoc, "ContIacWdbeNavDeploy", "numsF" + ctlsref)));
		else refreshLst(lstdoc, srcdoc, ncol, true, multsel, "FeedF" + ctlsref, numFirstdisp, [parseInt(retrieveCi(srcdoc, "ContIacWdbeNavDeploy", "numF" + ctlsref))]);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWdbeNavDeployData", "ContIacWdbeNavDeploy", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWdbeNavDeployData", "FeedFLstCmp", srcdoc)) mask.push("feedFLstCmp");
	if (updateSrcblock(dom, "DpchEngWdbeNavDeployData", "FeedFLstRls", srcdoc)) mask.push("feedFLstRls");
	if (updateSrcblock(dom, "DpchEngWdbeNavDeployData", "StatAppWdbeNavDeploy", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeNavDeployData", "StatShrWdbeNavDeploy", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeNavDeployData", "TagWdbeNavDeploy", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeNavDeployData") {
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
			if (blk.nodeName == "DpchEngWdbeNavDeployData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Deploy");
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

			} else if (blk.nodeName == "DpchEngWdbeNavDeployData") {
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
