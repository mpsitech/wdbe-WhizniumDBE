function makeSelectPup(contdoc, id, size) {
	var myselect;

	myselect = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:select");
	myselect.setAttribute("class", "pup" + size);
	myselect.setAttribute("id", id);
	myselect.setAttribute("size", "1");
	myselect.setAttribute("onchange", "handle" + id + "Change()");

	return myselect;
};

function refreshPup(contdoc, srcdoc, id, size, blk, numSel, act, chg) {
	var myselect, res, finode, myoption;

	var cl;

	cl = "pup" + size;
	if (chg) cl = cl + "mod";

	myselect = contdoc.getElementById(id);

	if (blk) {
		clearElem(myselect);

		res = srcdoc.evaluate("//wdbe:" + blk + "/wdbe:Fi", srcdoc, nsResolver, XPathResult.ANY_TYPE, null);
		finode = res.iterateNext();

		while (finode) {
			myoption = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:option");
			myoption.setAttribute("value", retrieveFiSub(srcdoc, finode, "num"));
			setTextContent(contdoc, myoption, retrieveFiSub(srcdoc, finode, "tit1"));
			myselect.appendChild(myoption);

			finode = res.iterateNext();
		};
	};

	myselect.value = "" + numSel;
	myselect.setAttribute("class", cl);

	if (act) myselect.removeAttribute("disabled");
	else myselect.setAttribute("disabled", "disabled");
};
