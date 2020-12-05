function setCtlAvail(contdoc, short, avail, dh) {
	var oldAvail = (contdoc.getElementById("tr" + short).getAttribute("class") == "show");

	if (avail != oldAvail) {
		if (avail) contdoc.getElementById("tr" + short).setAttribute("class", "show");
		else contdoc.getElementById("tr" + short).setAttribute("class", "hide");
	};

	if (avail) return 0;
	else return dh;
};

function makeSpanCpt(contdoc, id, tit) {
	var myspan;

	myspan = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:span");
	myspan.setAttribute("class", "cpt");
	myspan.setAttribute("id", id);
	setTextContent(contdoc, myspan, tit);

	return myspan;
};

function makeSpanBut(contdoc, id, tit) {
	var myspan;

	myspan = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:span");
	myspan.setAttribute("id", id);
	myspan.setAttribute("class", "but");
	myspan.setAttribute("onclick", "handle" + id + "Click()");
	setTextContent(contdoc, myspan, tit);

	return myspan;
};

function makeImgBut(contdoc, id, icon) {
	var myimg;

	myimg = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:img");
	myimg.setAttribute("id", id);
	myimg.setAttribute("class", "but");
	myimg.setAttribute("width", "16");
	myimg.setAttribute("height", "16");
	myimg.setAttribute("valign", "bottom");
	myimg.setAttribute("alt", id);
	myimg.setAttribute("src", "../" + icon + ".png");
	myimg.setAttribute("onmouseover", "src='../" + icon + "_hlt.png'");
	myimg.setAttribute("onmouseout", "src='../" + icon + ".png'");
	myimg.setAttribute("onclick", "handle" + id + "Click()")

	return myimg;
};

function makeInputTxf(contdoc, id, size) {
	var myinput;

	myinput = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:input");
	myinput.setAttribute("class", "txf" + size);
	myinput.setAttribute("id", id);
	myinput.setAttribute("type", "text");
	myinput.setAttribute("value", id);
	myinput.setAttribute("onchange", "handle" + id + "Change()");
	myinput.setAttribute("onkeypress", "return handle" + id + "Key(event)");

	return myinput;
};

function makeInputTxt(contdoc, id, size) {
	var myinput;

	myinput = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:input");
	myinput.setAttribute("class", "txf" + size + "noed");
	myinput.setAttribute("id", id);
	myinput.setAttribute("type", "text");
	myinput.setAttribute("value", id);
	myinput.setAttribute("readonly", "readonly");

	return myinput;
};

function initBut(contdoc, id, tit) {
	var myspan;

	myspan = contdoc.getElementById(id);
	setTextContent(contdoc, myspan, tit);
};

function initCpt(contdoc, id, tit) {
	var myspan;

	myspan = contdoc.getElementById(id);
	setTextContent(contdoc, myspan, tit);
};

function refreshBut(contdoc, id, act, on) {
	var myspan;

	myspan = contdoc.getElementById(id);

	if (on) myspan.setAttribute("class", "buthlt");
	else if (act) myspan.setAttribute("class", "but");
	else myspan.setAttribute("class", "butinact");

	if (act) myspan.setAttribute("onclick", "handle" + id + "Click()");
	else myspan.onclick = null;
};

function refreshButicon(contdoc, id, icon, act, on) {
	var myimg;

	myimg = contdoc.getElementById(id);

	if (on) myimg.setAttribute("src", "../" + icon + "_hlt.png");
	else if (act) myimg.setAttribute("src", "../" + icon + ".png");
	else myimg.setAttribute("src", "../" + icon + "_inact.png");

	if (act && !on) {
		myimg.setAttribute("onmouseover", "src='../" + icon + "_hlt.png'");
		myimg.setAttribute("onmouseout", "src='../" + icon + ".png'");
	} else {
		myimg.onmouseover = null;
		myimg.onmouseout = null;
	};

	if (act) {
		myimg.setAttribute("class", "but");
		myimg.setAttribute("onclick", "handle" + id + "Click()")
	} else {
		myimg.setAttribute("class", "butinact");
		myimg.onclick = null;
	};
};

function refreshChk(contdoc, id, chk, act) {
	var myinput;

	myinput = contdoc.getElementById(id);

	myinput.checked = chk;
	myinput.disabled = !act;

	if (act) {
		myinput.setAttribute("class", "chk");
		myinput.setAttribute("onchange", "handle" + id + "Change()");
	} else {
		myinput.setAttribute("class", "chk");
		myinput.onchange = null;
	};
};

function refreshCsi(contdoc, id, srcdoc, blk, num) {
	var color, flashing, mycircle, myanimate;

	color = retrieveFeedSrefByNum(srcdoc, blk, num);
	if (color == "") color = "gry";

	flashing = false;
	if (color.length > 3) if ((color.indexOf(".fl")+3) == color.length) {
		color = color.slice(0, -3);
		flashing = true;
	};
	
	if (color == "wte") color = "white";
	else if (color == "gry") color = "gray";
	else if (color == "blk") color = "black";
	else if (color == "red") color = "red";
	else if (color == "grn") color = "limegreen";
	else if (color == "blu") color = "blue";
	else if (color == "cyn") color = "cyan";
	else if (color == "mgt") color = "magenta";
	else if (color == "yel") color = "yellow";
	else if (color == "vlt") color = "indigo";
	else if (color == "ong") color = "orange";
	else if (color == "brn") color = "saddlebrown";

	mycircle = contdoc.getElementById(id);

	clearElem(mycircle);

	mycircle.setAttribute("style", "fill:" + color);

	if (flashing) {
		myanimate = contdoc.createElementNS("http://www.w3.org/2000/svg", "animate");
		myanimate.setAttribute("attributeType", "CSS");
		myanimate.setAttribute("attributeName", "fill");
		myanimate.setAttribute("from", color);
		myanimate.setAttribute("to", "white");
		myanimate.setAttribute("dur", "0.5s");
		myanimate.setAttribute("repeatCount", "indefinite");
		mycircle.appendChild(myanimate);
	};
};

function refreshDld(contdoc, id, scrJref, dld, act) {
	var myelem;

	myelem = contdoc.getElementById(id);
	myelem.setAttribute("download", dld);
	if (act) {
		myelem.setAttribute("class", "but");
		myelem.setAttribute("href", "/download/" + scrJref);
		myelem.setAttribute("target", "_blank");
	} else {
		myelem.setAttribute("class", "butinact");
		myelem.setAttribute("href", "#");
		myelem.setAttribute("target", "_self");
	};
};

function refreshTxf(contdoc, id, size, tit, act, chg, vld) {
	var myelem;

	var cl;

	cl = "txf" + size;
	if (act) {
		if (chg) cl = cl + "mod";
		else if (!vld) cl = cl + "err";
	} else cl = cl + "noed";

	myelem = contdoc.getElementById(id);
	myelem.value = tit;
	myelem.setAttribute("class", cl);
	if (act) {
		myelem.removeAttribute("readonly");
		myelem.setAttribute("onchange", "handle" + id + "Change()");
		myelem.setAttribute("onkeypress", "return handle" + id + "Key(event)");
	} else {
		myelem.setAttribute("readonly", "readonly");
		myelem.removeAttribute("onchange");
		myelem.removeAttribute("onkeypress");
	};
};

function refreshTxft(contdoc, id, tit, act, chg, vld) {
	var myelem;

	var cl;

	cl = "txf";
	if (act) {
		if (chg) cl = cl + "mod";
		else if (!vld) cl = cl + "err";
	} else cl = cl + "noed";

	myelem = contdoc.getElementById(id);
	myelem.value = tit.replace(/;/g, "\n");
	myelem.setAttribute("class", cl);
	if (act) {
		myelem.removeAttribute("readonly");
		myelem.setAttribute("onchange", "handle" + id + "Change()");
		myelem.setAttribute("onkeypress", "return handle" + id + "Key(event)");
	} else {
		myelem.setAttribute("readonly", "readonly");
		myelem.removeAttribute("onchange");
		myelem.removeAttribute("onkeypress");
	};
};

function refreshTxt(contdoc, id, tit) {
	var myelem;

	myelem = contdoc.getElementById(id);
	myelem.value = tit;
};

function refreshTxtt(contdoc, id, tit) {
	var myelem;

	myelem = contdoc.getElementById(id);
	myelem.value = tit.replace(/;/g, "\n");
};
