/**
  * \file PnlWdbeNavPre.js
  * web client functionality for panel PnlWdbeNavPre
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

// --- expand state management
function minimize() {
};

function regularize() {
};

// --- view initialization and refresh
function init() {
	if (!doc) return;

	contdoc = doc.getElementById("Pre_cont").contentDocument;

// IP init --- INSERT

	refresh();
};

function refresh() {
	var line;

	var n = 0;

	var TxtCvrAvail = (retrieveSi(srcdoc, "StatShrWdbeNavPre", "TxtCvrAvail") == "true"); if (TxtCvrAvail) n++;
	var TxtUntAvail = (retrieveSi(srcdoc, "StatShrWdbeNavPre", "TxtUntAvail") == "true"); if (TxtUntAvail) n++;
	var TxtVerAvail = (retrieveSi(srcdoc, "StatShrWdbeNavPre", "TxtVerAvail") == "true"); if (TxtVerAvail) n++;

	line = contdoc.getElementById("line");
	while (line.firstChild) line.removeChild(line.firstChild);

	var i = 0;

	if (TxtCvrAvail) {
		i++;

		line.appendChild(makeImgBut("ButCvrRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagWdbeNavPre", "CptCvr") + ": " + retrieveCi(srcdoc, "ContInfWdbeNavPre", "TxtCvr")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagWdbeNavPre", "CptCvr") + ": " + retrieveCi(srcdoc, "ContInfWdbeNavPre", "TxtCvr") + ",\u00a0\u00a0"));
	};

	if (TxtUntAvail) {
		i++;

		line.appendChild(makeImgBut("ButUntRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagWdbeNavPre", "CptUnt") + ": " + retrieveCi(srcdoc, "ContInfWdbeNavPre", "TxtUnt")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagWdbeNavPre", "CptUnt") + ": " + retrieveCi(srcdoc, "ContInfWdbeNavPre", "TxtUnt") + ",\u00a0\u00a0"));
	};

	if (TxtVerAvail) {
		i++;

		line.appendChild(makeImgBut("ButVerRemove", "icon/close"));
		if (i == n) line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc,  "TagWdbeNavPre", "CptVer") + ": " + retrieveCi(srcdoc, "ContInfWdbeNavPre", "TxtVer")));
		else line.appendChild(makeSpanCpt("\u00a0" + retrieveTi(srcdoc, "TagWdbeNavPre", "CptVer") + ": " + retrieveCi(srcdoc, "ContInfWdbeNavPre", "TxtVer") + ",\u00a0\u00a0"));
	};

};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Pre_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavPreDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeNavPreData", "ContInfWdbeNavPre", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeNavPreData", "StatShrWdbeNavPre", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeNavPreData", "TagWdbeNavPre", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWdbeNavPreData") {
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
			if (blk.nodeName == "DpchEngWdbeNavPreData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Pre");
			};
		};
	};
};

function handleDpchAppDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWdbeConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWdbeNavPreData") {
				mergeDpchEngData(dom);
				refresh();
			};
		};
	};
};

