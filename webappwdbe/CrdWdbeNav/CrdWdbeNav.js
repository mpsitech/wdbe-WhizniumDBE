/**
  * \file CrdWdbeNav.js
  * web client functionality for card CrdWdbeNav
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

function getInitdone(pnlshort) {
	return(retrieveSi(srcdoc, "StatAppWdbeNav", "initdone" + pnlshort) == "true");
};

function setInitdone(pnlshort) {
	setSi(srcdoc, "StatAppWdbeNav", "initdone" + pnlshort, "true");

	checkInitdone();
};

function checkInitdone() {
	var initdoneHeadbar = (retrieveSi(srcdoc, "StatAppWdbeNav", "initdoneHeadbar") == "true");
	var initdonePre = (retrieveSi(srcdoc, "StatAppWdbeNav", "initdonePre") == "true");
	var initdoneAdmin = (retrieveSi(srcdoc, "StatAppWdbeNav", "initdoneAdmin") == "true");
	var initdoneGlobal = (retrieveSi(srcdoc, "StatAppWdbeNav", "initdoneGlobal") == "true");
	var initdoneDevdev = (retrieveSi(srcdoc, "StatAppWdbeNav", "initdoneDevdev") == "true");
	var initdoneCoredev = (retrieveSi(srcdoc, "StatAppWdbeNav", "initdoneCoredev") == "true");
	var initdoneDescr = (retrieveSi(srcdoc, "StatAppWdbeNav", "initdoneDescr") == "true");
	var initdoneAuxfct = (retrieveSi(srcdoc, "StatAppWdbeNav", "initdoneAuxfct") == "true");

	if (!initdoneHeadbar) {
		doc.getElementById("Headbar").src = "./PnlWdbeNavHeadbar.html?scrJref=" + scrJrefHeadbar;
	} else if (!initdonePre) {
		doc.getElementById("Pre").src = "./PnlWdbeNavPre.html?scrJref=" + scrJrefPre;
	} else if (!initdoneAdmin) {
		doc.getElementById("Admin").src = "./PnlWdbeNavAdmin.html?scrJref=" + scrJrefAdmin;
	} else if (!initdoneGlobal) {
		doc.getElementById("Global").src = "./PnlWdbeNavGlobal.html?scrJref=" + scrJrefGlobal;
	} else if (!initdoneDevdev) {
		doc.getElementById("Devdev").src = "./PnlWdbeNavDevdev.html?scrJref=" + scrJrefDevdev;
	} else if (!initdoneCoredev) {
		doc.getElementById("Coredev").src = "./PnlWdbeNavCoredev.html?scrJref=" + scrJrefCoredev;
	} else if (!initdoneDescr) {
		doc.getElementById("Descr").src = "./PnlWdbeNavDescr.html?scrJref=" + scrJrefDescr;
	} else if (!initdoneAuxfct) {
		doc.getElementById("Auxfct").src = "./PnlWdbeNavAuxfct.html?scrJref=" + scrJrefAuxfct;
	} else {
		doc.initdone = true;
		window.onfocus = resumeNotify;

		refresh();

		restartNotify();
	};
};

function setPnlAvail(short, avail) {
	var oldAvail = (doc.getElementById("tr" + short).getAttribute("class") == "show");

	if (avail != oldAvail) {
		if (avail) {
			doc.getElementById("spc" + short).setAttribute("class", "show");
			doc.getElementById("tr" + short).setAttribute("class", "show");
		} else {
			doc.getElementById(short).contentWindow.minimize();
			doc.getElementById("spc" + short).setAttribute("class", "hide");
			doc.getElementById("tr" + short).setAttribute("class", "hide");
		};
	};
};

function getHeight() {
	var height = 25;

	if (doc.getElementById("trPre").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdPre").getAttribute("height"));
	if (doc.getElementById("trAdmin").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAdmin").getAttribute("height")) + 8;
	if (doc.getElementById("trGlobal").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdGlobal").getAttribute("height")) + 8;
	if (doc.getElementById("trDevdev").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdDevdev").getAttribute("height")) + 8;
	if (doc.getElementById("trCoredev").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdCoredev").getAttribute("height")) + 8;
	if (doc.getElementById("trDescr").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdDescr").getAttribute("height")) + 8;
	if (doc.getElementById("trAuxfct").getAttribute("class") == "show") height += 10 + parseInt(doc.getElementById("tdAuxfct").getAttribute("height")) + 8;

	height += 5;

	return height;
};

// --- menu functionality
function toggleMenu(short, left, width, height) {
	var shortMenu = retrieveSi(srcdoc, "StatAppWdbeNav", "shortMenu");

	if (doc.getElementById("divMenu")) {
		if (shortMenu == short)
			hideMenu(shortMenu);
		else {
			hideMenu(shortMenu);
			showMenu(short, left, width, height);
		};

	} else {
		showMenu(short, left, width, height);
	};
};

function showMenu(short, left, width, height) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppWdbeNav", "shortMenu", short);
	setSi(srcdoc, "StatAppWdbeNav", "widthMenu", "" + (width-3));

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuappact");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menuact");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menulineact");

	var body = doc.getElementById("body");
	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "menu");
	mydiv.setAttribute("id", "divMenu");
	mydiv.setAttribute("style", "left:" + left + "px;");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Menu");
	myif.setAttribute("src", "./Men" + short + ".html");
	myif.setAttribute("width", "" + width);
	myif.setAttribute("height", "" + height);
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideMenu(short) {
	var headbarcontdoc = doc.getElementById("Headbar").contentWindow.document.getElementById("Headbar_cont").contentWindow.document;

	setSi(srcdoc, "StatAppWdbeNav", "shortMenu", "");

	if (short == "App") headbarcontdoc.getElementById("MenApp").setAttribute("class", "menuapp");
	else headbarcontdoc.getElementById("Men" + short).setAttribute("class", "menu");
	headbarcontdoc.getElementById("lineMen" + short).setAttribute("class", "menuline");

	var body = doc.getElementById("body");

	body.removeChild(doc.getElementById("divMenu"));
};

function initMenApp() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspApp2Avail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MspApp2Avail") == "true");
	MitAppMlcAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitAppMlcAvail") == "true");
	MitAppLoiAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitAppLoiAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWdbeNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitAppAbt"), retrieveTi(srcdoc, "TagWdbeNav", "MitAppAbt"));
	setTextContent(mendoc, mendoc.getElementById("MrlAppHlp"), retrieveTi(srcdoc, "TagWdbeNav", "MrlAppHlp"));
	setTextContent(mendoc, mendoc.getElementById("MitAppMlc"), retrieveTi(srcdoc, "TagWdbeNav", "MitAppMlc"));
	setTextContent(mendoc, mendoc.getElementById("MitAppLoi"), retrieveTi(srcdoc, "TagWdbeNav", "MitAppLoi"));

	height -= setMitMspAvail("MspApp2", MspApp2Avail, 1);
	height -= setMitMspAvail("MitAppMlc", MitAppMlcAvail, 20);
	height -= setMitMspAvail("MitAppLoi", MitAppLoiAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function initMenSes() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MitSesSpsAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitSesSpsAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWdbeNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MtxSesSes1"), retrieveCi(srcdoc, "ContInfWdbeNav", "MtxSesSes1"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes2"), retrieveCi(srcdoc, "ContInfWdbeNav", "MtxSesSes2"));
	setTextContent(mendoc, mendoc.getElementById("MtxSesSes3"), retrieveCi(srcdoc, "ContInfWdbeNav", "MtxSesSes3"));
	setTextContent(mendoc, mendoc.getElementById("MitSesSps"), retrieveTi(srcdoc, "TagWdbeNav", "MitSesSps"));
	setTextContent(mendoc, mendoc.getElementById("MitSesTrm"), retrieveTi(srcdoc, "TagWdbeNav", "MitSesTrm"));

	height -= setMitMspAvail("MitSesSps", MitSesSpsAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function initMenCrd() {
	var mendoc = doc.getElementById("Menu").contentDocument;

	var height = parseInt(doc.getElementById("Menu").getAttribute("height"));

	MspCrd1Avail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MspCrd1Avail") == "true");
	MitCrdUsgAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdUsgAvail") == "true");
	MitCrdUsrAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdUsrAvail") == "true");
	MitCrdPrsAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdPrsAvail") == "true");
	MitCrdFilAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdFilAvail") == "true");
	MspCrd2Avail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MspCrd2Avail") == "true");
	MitCrdMchAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdMchAvail") == "true");
	MitCrdLibAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdLibAvail") == "true");
	MitCrdFamAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdFamAvail") == "true");
	MitCrdSilAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdSilAvail") == "true");
	MitCrdMtpAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdMtpAvail") == "true");
	MspCrd3Avail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MspCrd3Avail") == "true");
	MitCrdPrjAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdPrjAvail") == "true");
	MitCrdVerAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdVerAvail") == "true");
	MitCrdSysAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdSysAvail") == "true");
	MitCrdSysActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdSysActive") == "true");
	MitCrdTrgAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdTrgAvail") == "true");
	MitCrdTrgActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdTrgActive") == "true");
	MitCrdUntAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdUntAvail") == "true");
	MitCrdUntActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdUntActive") == "true");
	MitCrdRlsAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdRlsAvail") == "true");
	MitCrdRlsActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdRlsActive") == "true");
	MspCrd4Avail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MspCrd4Avail") == "true");
	MitCrdCprAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdCprAvail") == "true");
	MitCrdCvrAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdCvrAvail") == "true");
	MspCrd5Avail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MspCrd5Avail") == "true");
	MitCrdModAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdModAvail") == "true");
	MitCrdModActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdModActive") == "true");
	MitCrdVecAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdVecAvail") == "true");
	MitCrdVecActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdVecActive") == "true");
	MitCrdCmdAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdCmdAvail") == "true");
	MitCrdCmdActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdCmdActive") == "true");
	MitCrdErrAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdErrAvail") == "true");
	MitCrdErrActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdErrActive") == "true");
	MitCrdPphAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdPphAvail") == "true");
	MitCrdPphActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdPphActive") == "true");
	MitCrdBnkAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdBnkAvail") == "true");
	MitCrdBnkActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdBnkActive") == "true");
	MitCrdPinAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdPinAvail") == "true");
	MitCrdPinActive = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdPinActive") == "true");
	MspCrd6Avail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MspCrd6Avail") == "true");
	MitCrdUtlAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "MitCrdUtlAvail") == "true");

	mendoc.getElementById("colCont").setAttribute("width", retrieveSi(srcdoc, "StatAppWdbeNav", "widthMenu"));

	setTextContent(mendoc, mendoc.getElementById("MitCrdUsg"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdUsg"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdUsr"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdUsr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrs"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdPrs"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFil"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdFil"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdMch"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdMch"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdLib"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdLib"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdFam"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdFam"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdSil"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdSil"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdMtp"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdMtp"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdPrj"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdPrj"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdVer"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdVer"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdSys"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdSys"));
	setMitActive("MitCrdSys", MitCrdSysActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdTrg"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdTrg"));
	setMitActive("MitCrdTrg", MitCrdTrgActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdUnt"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdUnt"));
	setMitActive("MitCrdUnt", MitCrdUntActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdRls"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdRls"));
	setMitActive("MitCrdRls", MitCrdRlsActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdCpr"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdCpr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdCvr"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdCvr"));
	setTextContent(mendoc, mendoc.getElementById("MitCrdMod"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdMod"));
	setMitActive("MitCrdMod", MitCrdModActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdVec"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdVec"));
	setMitActive("MitCrdVec", MitCrdVecActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdCmd"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdCmd"));
	setMitActive("MitCrdCmd", MitCrdCmdActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdErr"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdErr"));
	setMitActive("MitCrdErr", MitCrdErrActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdPph"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdPph"));
	setMitActive("MitCrdPph", MitCrdPphActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdBnk"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdBnk"));
	setMitActive("MitCrdBnk", MitCrdBnkActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdPin"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdPin"));
	setMitActive("MitCrdPin", MitCrdPinActive);
	setTextContent(mendoc, mendoc.getElementById("MitCrdUtl"), retrieveTi(srcdoc, "TagWdbeNav", "MitCrdUtl"));

	height -= setMitMspAvail("MspCrd1", MspCrd1Avail, 1);
	height -= setMitMspAvail("MitCrdUsg", MitCrdUsgAvail, 20);
	height -= setMitMspAvail("MitCrdUsr", MitCrdUsrAvail, 20);
	height -= setMitMspAvail("MitCrdPrs", MitCrdPrsAvail, 20);
	height -= setMitMspAvail("MitCrdFil", MitCrdFilAvail, 20);
	height -= setMitMspAvail("MspCrd2", MspCrd2Avail, 1);
	height -= setMitMspAvail("MitCrdMch", MitCrdMchAvail, 20);
	height -= setMitMspAvail("MitCrdLib", MitCrdLibAvail, 20);
	height -= setMitMspAvail("MitCrdFam", MitCrdFamAvail, 20);
	height -= setMitMspAvail("MitCrdSil", MitCrdSilAvail, 20);
	height -= setMitMspAvail("MitCrdMtp", MitCrdMtpAvail, 20);
	height -= setMitMspAvail("MspCrd3", MspCrd3Avail, 1);
	height -= setMitMspAvail("MitCrdPrj", MitCrdPrjAvail, 20);
	height -= setMitMspAvail("MitCrdVer", MitCrdVerAvail, 20);
	height -= setMitMspAvail("MitCrdSys", MitCrdSysAvail, 20);
	height -= setMitMspAvail("MitCrdTrg", MitCrdTrgAvail, 20);
	height -= setMitMspAvail("MitCrdUnt", MitCrdUntAvail, 20);
	height -= setMitMspAvail("MitCrdRls", MitCrdRlsAvail, 20);
	height -= setMitMspAvail("MspCrd4", MspCrd4Avail, 1);
	height -= setMitMspAvail("MitCrdCpr", MitCrdCprAvail, 20);
	height -= setMitMspAvail("MitCrdCvr", MitCrdCvrAvail, 20);
	height -= setMitMspAvail("MspCrd5", MspCrd5Avail, 1);
	height -= setMitMspAvail("MitCrdMod", MitCrdModAvail, 20);
	height -= setMitMspAvail("MitCrdVec", MitCrdVecAvail, 20);
	height -= setMitMspAvail("MitCrdCmd", MitCrdCmdAvail, 20);
	height -= setMitMspAvail("MitCrdErr", MitCrdErrAvail, 20);
	height -= setMitMspAvail("MitCrdPph", MitCrdPphAvail, 20);
	height -= setMitMspAvail("MitCrdBnk", MitCrdBnkAvail, 20);
	height -= setMitMspAvail("MitCrdPin", MitCrdPinAvail, 20);
	height -= setMitMspAvail("MspCrd6", MspCrd6Avail, 1);
	height -= setMitMspAvail("MitCrdUtl", MitCrdUtlAvail, 20);

	doc.getElementById("Menu").setAttribute("height", "" + height);
};

function setMitMspAvail(short, avail, dh) {
	var mendoc = doc.getElementById("Menu").contentDocument;

	if (!avail) mendoc.getElementById("tr" + short).setAttribute("class", "hide");

	if (avail) return 0;
	else return dh;
};

function setMitActive(short, active) {
	var mendoc = doc.getElementById("Menu").contentDocument;
	var mit = mendoc.getElementById(short);

	if (active) {
		mit.setAttribute("class", "item");
		mit.setAttribute("onclick", "handle" + short + "Click()");
	} else {
		mit.setAttribute("class", "itemdis");
		mit.setAttribute("onclick", "");
	};
};

// --- detached panel functionality
function detachPnl(sref, _scrJref) {
	if ((scrJrefPnld != "") && (scrJrefPnld != _scrJref)) attachPnl();

	scrJrefPnld = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divPnldshld");
	mydiv.setAttribute("class", "pnldshld");
	mydiv.setAttribute("style", "height:" + (getHeight()-35) + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "pnld");
	mydiv.setAttribute("id", "divPnld");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Pnld");
	myif.setAttribute("src", "./" + sref + "_d.html?scrJref=" + _scrJref);
	myif.setAttribute("width", "891"); /// PRELIMINARY
	myif.setAttribute("height", "586");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function maximizePnl() {
	/// TBD
};

function attachPnl() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divPnldshld"));
	body.removeChild(doc.getElementById("divPnld"));

	scrJrefPnld = "";
};

// --- dialog functionality
function showDlg(sref, _scrJref)  {
	if ((scrJrefDlg != "") && (scrJrefDlg != _scrJref)) hideDlg();

	scrJrefDlg = _scrJref;

	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divDlgshld");
	mydiv.setAttribute("class", "dlgshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "dlg");
	mydiv.setAttribute("id", "divDlg");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Dlg");
	myif.setAttribute("src", "./" + sref + ".html?scrJref=" + _scrJref);
	myif.setAttribute("width", "691");
	if ((sref == "DlgWdbeNavLoaini")) myif.setAttribute("height", "585");
	else myif.setAttribute("height", "555");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideDlg() {
	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divDlgshld"));
	body.removeChild(doc.getElementById("divDlg"));

	scrJrefDlg = "";
};

// --- alert functionality
function showAlr(_scrJref, blkcontinf, blkfeedfmcb)  {
	// update information
	scrJrefAlr = _scrJref;

	replaceSrcblock(blkcontinf, "ContInfWdbeAlert", srcdoc);
	replaceSrcblock(blkfeedfmcb, "FeedFMcbAlert", srcdoc);

	// show alert
	var body = doc.getElementById("body");

	var mydiv, myif;

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("id", "divAlrshld");
	mydiv.setAttribute("class", "alrshld");
	mydiv.setAttribute("style", "height:" + getHeight() + "px;");
	body.appendChild(mydiv);

	mydiv = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:div");
	mydiv.setAttribute("class", "alr");
	mydiv.setAttribute("id", "divAlr");

	myif = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myif.setAttribute("id", "Alr");
	myif.setAttribute("src", "../iframe/alr.xml");
	myif.setAttribute("width", "501");
	myif.setAttribute("height", "60");
	myif.setAttribute("frameborder", "0");
	myif.setAttribute("scrolling", "no");

	mydiv.appendChild(myif);
	body.appendChild(mydiv);
};

function hideAlr(numFMcb) {
	var str = serializeDpchAppAlert(scrJrefAlr, numFMcb);
	sendReq(str, doc, handleDpchAppDoReply);

	var body = doc.getElementById("body");
	body.removeChild(doc.getElementById("divAlrshld"));
	body.removeChild(doc.getElementById("divAlr"));

	scrJrefAlr = "";
};

function initAlr() {
	var alrdoc = doc.getElementById("Alr").contentDocument;

	var height = 30+2+3+25;

	setTextContent(alrdoc, alrdoc.getElementById("TxtCpt"), retrieveCi(srcdoc, "ContInfWdbeAlert", "TxtCpt"));

	height += fillAlrTxtMsgFromCont(alrdoc, srcdoc, "ContInfWdbeAlert");

	doc.getElementById("Alr").setAttribute("height", "" + height);

	fillAlrMcbFromFeed(alrdoc, srcdoc, "FeedFMcbAlert");
};

// --- expand state management
function changeHeight(pnlshort, height) {
	var divPnldshld = doc.getElementById("divPnldshld");
	var divDlgshld = doc.getElementById("divDlgshld");
	var divAlrshld = doc.getElementById("divAlrshld");

	if (pnlshort == "Admin") {
		doc.getElementById("tdAdmin").setAttribute("height", "" + height);
		doc.getElementById("Admin").setAttribute("height", "" + height);
	} else if (pnlshort == "Global") {
		doc.getElementById("tdGlobal").setAttribute("height", "" + height);
		doc.getElementById("Global").setAttribute("height", "" + height);
	} else if (pnlshort == "Devdev") {
		doc.getElementById("tdDevdev").setAttribute("height", "" + height);
		doc.getElementById("Devdev").setAttribute("height", "" + height);
	} else if (pnlshort == "Coredev") {
		doc.getElementById("tdCoredev").setAttribute("height", "" + height);
		doc.getElementById("Coredev").setAttribute("height", "" + height);
	} else if (pnlshort == "Descr") {
		doc.getElementById("tdDescr").setAttribute("height", "" + height);
		doc.getElementById("Descr").setAttribute("height", "" + height);
	} else if (pnlshort == "Auxfct") {
		doc.getElementById("tdAuxfct").setAttribute("height", "" + height);
		doc.getElementById("Auxfct").setAttribute("height", "" + height);
	};

	if (divPnldshld) divPnldshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divDlgshld) divDlgshld.setAttribute("style", "height:" + getHeight() + "px;");
	if (divAlrshld) divAlrshld.setAttribute("style", "height:" + getHeight() + "px;");
};

// --- view initialization and refresh
function refresh() {
	var scrJrefDlgloaini = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefDlgloaini");
	var scrJrefDlgmnglic = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefDlgmnglic");
	var pnlpreAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "pnlpreAvail") == "true");
	var pnladminAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "pnladminAvail") == "true");
	var pnlglobalAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "pnlglobalAvail") == "true");
	var pnldevdevAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "pnldevdevAvail") == "true");
	var pnlcoredevAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "pnlcoredevAvail") == "true");
	var pnldescrAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "pnldescrAvail") == "true");
	var pnlauxfctAvail = (retrieveSi(srcdoc, "StatShrWdbeNav", "pnlauxfctAvail") == "true");

	if (scrJrefDlgloaini != "") {
		if (scrJrefDlg != scrJrefDlgloaini) showDlg("DlgWdbeNavLoaini", scrJrefDlgloaini);
	} else if (scrJrefDlgmnglic != "") {
		if (scrJrefDlg != scrJrefDlgmnglic) showDlg("DlgWdbeNavMnglic", scrJrefDlgmnglic);
	} else if (scrJrefDlg != "") hideDlg();

	setPnlAvail("Pre", pnlpreAvail);
	setPnlAvail("Admin", pnladminAvail);
	setPnlAvail("Global", pnlglobalAvail);
	setPnlAvail("Devdev", pnldevdevAvail);
	setPnlAvail("Coredev", pnlcoredevAvail);
	setPnlAvail("Descr", pnldescrAvail);
	setPnlAvail("Auxfct", pnlauxfctAvail);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("_src").contentDocument;

	var str = serializeDpchApp("DpchAppWdbeInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleUnload() {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavDo", scrJref, "close");
	sendReq(str, doc, null, true);
};

function handleMitClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoReply);

	hideMenu(menshort);
};

function handleMitCrdopenClick(menshort, consref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWdbeNavDo", scrJref, consref + "Click");
	sendReq(str, doc, handleDpchAppDoCrdopenReply);

	hideMenu(menshort);
};

function handleMrlClick(menshort, consref) {
	window.open(retrieveCi(srcdoc, "ContInfWdbeNav", consref), "_blank");

	hideMenu(menshort);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWdbeNavData", "ContInfWdbeNav", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWdbeNavData", "FeedFSge", srcdoc)) mask.push("feedFSge");
	if (updateSrcblock(dom, "DpchEngWdbeNavData", "StatAppWdbeNav", srcdoc)) mask.push("statapp");
	if (updateSrcblock(dom, "DpchEngWdbeNavData", "StatShrWdbeNav", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWdbeNavData", "TagWdbeNav", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEngSub(_scrJref, dom, dpch) {
	if (_scrJref == scrJrefPnld) {
		doc.getElementById("Pnld").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefDlg) {
		doc.getElementById("Dlg").contentWindow.handleDpchEng(dom, dpch);

	} else if (_scrJref == scrJrefPre) {
		doc.getElementById("Pre").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefAdmin) {
		doc.getElementById("Admin").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefGlobal) {
		doc.getElementById("Global").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefDevdev) {
		doc.getElementById("Devdev").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefCoredev) {
		doc.getElementById("Coredev").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefDescr) {
		doc.getElementById("Descr").contentWindow.handleDpchEng(dom, dpch);
	} else if (_scrJref == scrJrefAuxfct) {
		doc.getElementById("Auxfct").contentWindow.handleDpchEng(dom, dpch);

	} else {
		// alert("got a '" + dpch + "' from job with scrJref " + _scrJref);
	};
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWdbeNavData") {
				mergeDpchEngData(dom);

				// establish sub-panel scrJref's as global variables, and start sub-panel load sequence
				scrJrefHeadbar = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefHeadbar");
				scrJrefPre = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefPre");
				scrJrefAdmin = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefAdmin");
				scrJrefGlobal = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefGlobal");
				scrJrefDevdev = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefDevdev");
				scrJrefCoredev = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefCoredev");
				scrJrefDescr = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefDescr");
				scrJrefAuxfct = retrieveSi(srcdoc, "StatShrWdbeNav", "scrJrefAuxfct");

				scrJrefPnld = "";

				scrJrefDlg = "";

				scrJrefAlr = "";

				// load sub-panels one by one
				checkInitdone();
			};
		};
	};
};

function handleDpchAppDoReply() {
	var _scrJref;

	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) {
			_scrJref = retrieveValue(dom, "//wdbe:*/wdbe:scrJref");

			if (_scrJref != "") {
				if (_scrJref == scrJref) {
					if (blk.nodeName == "DpchEngWdbeConfirm") {
						// do nothing

					} else if (blk.nodeName == "DpchEngWdbeAlert") {
						// show alert with new content
						showAlr(retrieveValue(dom, "//wdbe:DpchEngWdbeAlert/wdbe:scrJref"),
								retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:ContInfWdbeAlert"),
								retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:FeedFMcbAlert"));

					} else if (blk.nodeName == "DpchEngWdbeNavData") {
						mergeDpchEngData(dom);
						refresh();
					};

				} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
			};

			restartNotify();
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
				showAlr(retrieveValue(dom, "//wdbe:DpchEngWdbeAlert/wdbe:scrJref"),
						retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:ContInfWdbeAlert"),
						retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:FeedFMcbAlert"));
			};

			restartNotify();
		};
	};
};

function terminate() {
	if (doc.timeout) window.clearTimeout(doc.timeout);

	window.onfocus = null;
	window.onbeforeunload = null;

	window.open("../CrdWdbeStart/CrdWdbeStart.html?do=Logout", "_self");
};

function restartNotify() {
	var srefIxWdbeVReqitmode = retrieveSi(srcdoc, "StatAppWdbeNav", "srefIxWdbeVReqitmode");

	if (srefIxWdbeVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		srefIxWdbeVReqitmode = "notify";
		setSi(srcdoc, "StatAppWdbeNav", "srefIxWdbeVReqitmode", srefIxWdbeVReqitmode);

		iterateReqit();
	};
};

function resumeNotify() {
	var srefIxWdbeVReqitmode = retrieveSi(srcdoc, "StatAppWdbeNav", "srefIxWdbeVReqitmode");

	if (srefIxWdbeVReqitmode != "notify") {
		if (doc.timeout) window.clearTimeout(doc.timeout);

		var str = serializeDpchApp("DpchAppWdbeResume", scrJref);
		sendReq(str, doc, handleDpchAppResumeReply);
	};
};

function handleDpchAppResumeReply() {
	var dom, blk;

	if ((doc.req.readyState == 4) && (doc.req.status == 404)) {
		terminate();

	} else if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wdbe:*");

		if (blk) if (blk.nodeName == "DpchEngWdbeAck") restartNotify();
	};
};

function iteratePoll() {
	iterateReqit();
};

function iterateReqit(ev) {
	var accepted, _scrJref, mask;

	var news = false;
	var iterate = true;

	var srefIxWdbeVReqitmode = retrieveSi(srcdoc, "StatAppWdbeNav", "srefIxWdbeVReqitmode");
	var latency = parseInt(retrieveSi(srcdoc, "StatAppWdbeNav", "latency"));

	if (doc.reqit && ev) {
		if (doc.reqit.readyState != 4) {
			iterate = false;

		} else if ((doc.reqit.readyState == 4) && (doc.reqit.status == 404)) {
			iterate = false;

			terminate();

		} else if (doc.reqit.readyState == 4) {
			dom = doc.reqit.responseXML;

			// check dispatch type
			blk = retrieveBlock(dom, "//wdbe:*");

			if (blk) {
				if (blk.nodeName == "DpchEngWdbeAck") {
					// no news
					// alert("no news");

				} else if (blk.nodeName == "DpchEngWdbeSuspend") {
					// change to "poll" mode
					news = true;

					srefIxWdbeVReqitmode = "poll";
					setSi(srcdoc, "StatAppWdbeNav", "srefIxWdbeVReqitmode", srefIxWdbeVReqitmode);

				} else {
					// request with content
					news = true;

					_scrJref = retrieveValue(dom, "//wdbe:*/wdbe:scrJref");

					if (blk.nodeName == "DpchEngWdbeAlert") {
						// card-based treatment even for scrJref corresponding to panel / dialog
						showAlr(retrieveValue(dom, "//wdbe:DpchEngWdbeAlert/wdbe:scrJref"),
								retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:ContInfWdbeAlert"),
								retrieveBlock(dom, "//wdbe:DpchEngWdbeAlert/wdbe:FeedFMcbAlert"));

					} else if (_scrJref != "") {
						if (_scrJref == scrJref) {
							if (blk.nodeName == "DpchEngWdbeConfirm") {
								accepted = retrieveValue(dom, "//wdbe:DpchEngWdbeConfirm/wdbe:accepted");

								if (accepted == "false") {
									// arrives on card close
									iterate = false;
									terminate();
								};

							} else if (blk.nodeName == "DpchEngWdbeNavData") {
								mask = mergeDpchEngData(dom);
								refresh();
							};

						} else handleDpchEngSub(_scrJref, dom, blk.nodeName);
					};
				};
			};
		};
	};

	if ((srefIxWdbeVReqitmode == "notify") && iterate) {
		// send notify request
		if (!doc.reqit) doc.reqit = new XMLHttpRequest();
		doc.reqit.onreadystatechange = iterateReqit;
		doc.reqit.open("GET", "/notify/" + scrJref, true);
		doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		doc.reqit.send("");

	} else if ((srefIxWdbeVReqitmode == "poll") && iterate) {
		if (!ev || (news && ev)) {
			// send poll request
			if (!doc.reqit) doc.reqit = new XMLHttpRequest();
			doc.reqit.onreadystatechange = iterateReqit;
			doc.reqit.open("GET", "/poll/" + scrJref, true);
			doc.reqit.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			doc.reqit.send("");

		} else {
			// wait
			doc.timeout = setTimeout(iteratePoll, latency*1000);
		};
	};
};

