function refreshRbu(contdoc, srcdoc, id, blk, numSel, act) {
	var mytd, res, finode, myinput, num;

	mytd = contdoc.getElementById(id);

	if (blk) {
		clearElem(mytd);

		res = srcdoc.evaluate("//wdbe:" + blk + "/wdbe:Fi", srcdoc, nsResolver, XPathResult.ANY_TYPE, null);
		finode = res.iterateNext();

		while (finode) {
			num = parseInt(retrieveFiSub(srcdoc, finode, "num"));

			myinput = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:input");
			myinput.setAttribute("type", "radio");
			myinput.setAttribute("name", id);
			myinput.setAttribute("value", "" + num);
			myinput.setAttribute("onclick", "handle" + id + "Select(" + num + ")");
			myinput.checked = (num == numSel);
			if (!act) myinput.setAttribute("disabled", "disabled");
			mytd.appendChild(myinput);

			mytd.appendChild(makeSpanCpt(contdoc, id + "Cpt" + num, retrieveFiSub(srcdoc, finode, "tit1") + "\u00a0"));

			finode = res.iterateNext();
		};
	};
};

function setRbuValue(contdoc, id, numSel, act) {
	var elems = contdoc.getElementsByName(id);

	for (var i = 0; i < elems.length; i++) {
		elems[i].checked = (elems[i].value == numSel);

		if (act) elems[i].removeAttribute("disabled");
		else elems[i].setAttribute("disabled", "disabled");
	};
};

