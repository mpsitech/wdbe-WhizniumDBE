function fillAlrTxtMsgFromCont(alrdoc, srcdoc, blk) {
	var height = 0;

	var s, s2;
	var ptr;

	var tr, td, span;

	var tbl = alrdoc.getElementById("tbl");

	var maxrow = 0;
	for (var i = 1; i <= 10; i++) {
		s = retrieveCi(srcdoc, blk, "TxtMsg" + i);
		if (s.length != 0) maxrow = i;
	};

	for (var i = 1; i <= maxrow; i++) {
		s = retrieveCi(srcdoc, blk, "TxtMsg" + i);

		if (s.length == 0) {
			tr = alrdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:tr");

			td = alrdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			td.setAttribute("height", "8");
			td.setAttribute("class", "frame");
			tr.appendChild(td);

			td = alrdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			td.setAttribute("colspan", "2");
			tr.appendChild(td);

			tbl.appendChild(tr);

			height += 8;

		} else {
			while (s.length > 0) {
				if (s.length > 70) {
					ptr = s.lastIndexOf(' ', 70);
					if (ptr == -1) ptr = s.indexOf(' ');
				} else ptr = -1;

				if (ptr == -1) {
					s2 = s;
					s = "";

				} else {
					s2 = s.substr(0, ptr);
					s = s.substr(ptr).trim();
				};

				tr = alrdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:tr");

				td = alrdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
				td.setAttribute("height", "20");
				td.setAttribute("class", "frame");
				tr.appendChild(td);

				td = alrdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
				tr.appendChild(td);

				span = alrdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:span");
				span.setAttribute("class", "cpt");
				setTextContent(alrdoc, span, s2);

				td = alrdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
				td.appendChild(span);

				tr.appendChild(td);

				tbl.appendChild(tr);

				height += 20;
			};
		};
	};

	return height;
};

function fillAlrMcbFromFeed(alrdoc, srcdoc, blk) {
	var res, finode;

	var span;

	res = srcdoc.evaluate("//wdbe:" + blk + "/wdbe:Fi", srcdoc, nsResolver, XPathResult.ANY_TYPE, null);
	finode = res.iterateNext();

	while (finode) {
		span = alrdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:span");
		span.setAttribute("class", "ftr_but");
		span.setAttribute("id", retrieveFiSub(srcdoc, finode, "sref"));
		span.setAttribute("onclick", "hideAlr(" + retrieveFiSub(srcdoc, finode, "num") + ")");

		span.appendChild(alrdoc.createTextNode("\u00a0\u00a0" + replaceUesc(retrieveFiSub(srcdoc, finode, "tit1"))));

		alrdoc.getElementById("tdMcb").appendChild(span);

		finode = res.iterateNext();
	};
};

