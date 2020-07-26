function makeTdLsb(lstdoc, sb, pos) {
	var vpos, svgns, mysbg, mytd, mysvg, myg, myrect, myline, mypath, myg2;

	// pos: 0.0 .. 1.0

	vpos = (16 + Math.round(pos * (90-2*16)));

	svgns = "http://www.w3.org/2000/svg";

	// table cell
	/*
	<td id="tdLsb" rowspan="5">
	*/
	mytd = lstdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");

	mytd.setAttribute("id", "tdLsb");
	mytd.setAttribute("rowspan", "5");

	if (sb == true) {
		// SVG object
		/*
		<svg width="100%" height="90px" version="1.1" xmlns="http://www.w3.org/2000/svg">
		*/
		mysvg = lstdoc.createElementNS(svgns, "svg:svg");

		mysvg.setAttribute("width", "15px");
		mysvg.setAttribute("height", "90px");
		mysvg.setAttribute("version", "1.1");
		mysvg.setAttribute("xmlns", svgns);

		// scroll bar container
		mysbg = lstdoc.createElementNS(svgns, "g");
		mysbg.setAttribute("class", "but");

		// arrows
		/*
		<g id="LsbUp" class="lsb" onmouseover="if(document.getElementById('tdLsb').onmousemove==null)document.getElementById('LsbUpl').setAttribute('stroke','#ff7f00')" onmouseout="document.getElementById('LsbUpl').setAttribute('stroke','black')" onclick="LsbUpClick()">
			<rect x="0" y="0" width="15" height="8" fill="white" stroke="none"/>
			<path id="LsbUpl" d="M0 8 L7.5 1.75 L15 8" fill="none" stroke-width="1" stroke="black"/>
		</g>
		*/

		// up
		myg = lstdoc.createElementNS(svgns, "g");

		myg.setAttribute("id", "LsbUp");
		myg.setAttribute("class", "lsb");
		myg.setAttribute("onmouseover", "if(document.getElementById('tdLsb').onmousemove==null)document.getElementById('LsbUpl').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "document.getElementById('LsbUpl').setAttribute('stroke','black')");
		myg.setAttribute("onclick", "handleLsbUpClick()");

		myrect = lstdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "0");
		myrect.setAttribute("width", "15");
		myrect.setAttribute("height", "8");
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		mypath = lstdoc.createElementNS(svgns, "path");

		mypath.setAttribute("id", "LsbUpl");
		mypath.setAttribute("d", "M0 8 L7.5 1.75 L15 8");
		mypath.setAttribute("fill", "none");
		mypath.setAttribute("stroke-width", "1");
		mypath.setAttribute("stroke", "black");

		myg.appendChild(mypath);

		mysbg.appendChild(myg);

		// down
		myg = lstdoc.createElementNS(svgns, "g");

		myg.setAttribute("id", "LsbDown");
		myg.setAttribute("class", "lsb");
		myg.setAttribute("transform", "translate(0 81)");
		myg.setAttribute("onmouseover", "if(document.getElementById('tdLsb').onmousemove==null)document.getElementById('LsbDownl').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "document.getElementById('LsbDownl').setAttribute('stroke','black')");
		myg.setAttribute("onclick", "handleLsbDownClick()");

		myrect = lstdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "0");
		myrect.setAttribute("width", "15");
		myrect.setAttribute("height", "8");
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		mypath = lstdoc.createElementNS(svgns, "path");

		mypath.setAttribute("id", "LsbDownl");
		mypath.setAttribute("d", "M0 0 L7.5 6.25 L15 0");
		mypath.setAttribute("fill", "none");
		mypath.setAttribute("stroke-width", "1");
		mypath.setAttribute("stroke", "black");

		myg.appendChild(mypath);

		mysbg.appendChild(myg);

		// inactive vertical bars
		/*
		<line stroke-width="1" stroke="#7f7f7f" x1="5" y1="1" x2="5" y2="8"/>
		*/
		myline = lstdoc.createElementNS(svgns, "line");

		myline.setAttribute("stroke-width", "1");
		myline.setAttribute("stroke", "#7f7f7f");
		myline.setAttribute("x1", "5");
		myline.setAttribute("y1", "1");
		myline.setAttribute("x2", "5");
		myline.setAttribute("y2", "8");

		mysbg.appendChild(myline);

		myline = lstdoc.createElementNS(svgns, "line");

		myline.setAttribute("stroke-width", "1");
		myline.setAttribute("stroke", "#7f7f7f");
		myline.setAttribute("x1", "5");
		myline.setAttribute("y1", "81");
		myline.setAttribute("x2", "5");
		myline.setAttribute("y2", "88");

		mysbg.appendChild(myline);

		// active vertical bars
		/*
		<g class="lsb" onmouseover="if(document.getElementById('tdLsb').onmousemove==null)document.getElementById('LsbJpupl').setAttribute('stroke','#ff7f00')" onmouseout="document.getElementById('LsbJpupl').setAttribute('stroke','black')" onclick="handleLsbJpupClick()">
			<rect id="LsbJpupr" x="0" y="8" width="15" height="37" fill="white" stroke="none"/>
			<line id="LsbJpupl" x1="5" y1="8" x2="5" y2="45" stroke-width="1" stroke="black"/>
		</g>
		*/

		// jpup
		myg = lstdoc.createElementNS(svgns, "g");

		myg.setAttribute("class", "lsb");
		myg.setAttribute("onmouseover", "if(document.getElementById('tdLsb').onmousemove==null)document.getElementById('LsbJpupl').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "document.getElementById('LsbJpupl').setAttribute('stroke','black')");
		myg.setAttribute("onclick", "handleLsbJpupClick()");

		myrect = lstdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("id", "LsbJpupr");
		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "8");
		myrect.setAttribute("width", "15");
		myrect.setAttribute("height", "" + (vpos-10));
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		myline = lstdoc.createElementNS(svgns, "line");

		myline.setAttribute("id", "LsbJpupl");
		myline.setAttribute("x1", "5");
		myline.setAttribute("y1", "8");
		myline.setAttribute("x2", "5");
		myline.setAttribute("y2", "" + vpos);
		myline.setAttribute("stroke-width", "1");
		myline.setAttribute("stroke", "black");

		myg.appendChild(myline);

		mysbg.appendChild(myg);

		// jpdown
		myg = lstdoc.createElementNS(svgns, "g");

		myg.setAttribute("class", "lsb");
		myg.setAttribute("onmouseover", "if(document.getElementById('tdLsb').onmousemove==null)document.getElementById('LsbJpdownl').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "document.getElementById('LsbJpdownl').setAttribute('stroke','black')");
		myg.setAttribute("onclick", "handleLsbJpdownClick()");

		myrect = lstdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("id", "LsbJpdownr");
		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "" + vpos);
		myrect.setAttribute("width", "15");
		myrect.setAttribute("height", "" + (90-vpos-9));
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		myline = lstdoc.createElementNS(svgns, "line");

		myline.setAttribute("id", "LsbJpdownl");
		myline.setAttribute("x1", "5");
		myline.setAttribute("y1", "" + vpos);
		myline.setAttribute("x2", "5");
		myline.setAttribute("y2", "" + (90-9));
		myline.setAttribute("stroke-width", "1");
		myline.setAttribute("stroke", "black");

		myg.appendChild(myline);

		mysbg.appendChild(myg);

		// slider
		/*
		<g id="Lsb" class="lsb" transform="translate(0 45)" onmouseover="document.getElementById('LsbBar').setAttribute('stroke','#ff7f00')" onmouseout="if(document.getElementById('tdLsb').onmousemove==null)document.getElementById('LsbBar').setAttribute('stroke','black')" onmousedown="handleLsbMdn()">
			<rect x="0" y="-3" width="15" height="6" fill="white" stroke="none"/>
			<g id="LsbBar" stroke-width="1" stroke="black">
				<line x1="0" y1="-2" x2="15" y2="-2"/>
				<line x1="0" y1="2" x2="15" y2="2"/>
			</g>
		</g>
		*/
		myg = lstdoc.createElementNS(svgns, "g");

		myg.setAttribute("id", "Lsb");
		myg.setAttribute("class", "lsb");
		myg.setAttribute("transform", "translate(0 " + vpos + ")");
		myg.setAttribute("onmouseover", "document.getElementById('LsbBar').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "if(document.getElementById('tdLsb').onmousemove==null)document.getElementById('LsbBar').setAttribute('stroke','black')");
		myg.setAttribute("onmousedown", "handleLsbMdn()");

		myrect = lstdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "-3");
		myrect.setAttribute("width", "15");
		myrect.setAttribute("height", "6");
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		myg2 = lstdoc.createElementNS(svgns, "g");

		myg2.setAttribute("id", "LsbBar");
		myg2.setAttribute("stroke-width", "1");
		myg2.setAttribute("stroke", "black");

		myline = lstdoc.createElementNS(svgns, "line");

		myline.setAttribute("x1", "0");
		myline.setAttribute("y1", "-2");
		myline.setAttribute("x2", "15");
		myline.setAttribute("y2", "-2");

		myg2.appendChild(myline);

		myline = lstdoc.createElementNS(svgns, "line");

		myline.setAttribute("x1", "0");
		myline.setAttribute("y1", "2");
		myline.setAttribute("x2", "15");
		myline.setAttribute("y2", "2");

		myg2.appendChild(myline);

		myg.appendChild(myg2);

		mysbg.appendChild(myg);

		mysvg.appendChild(mysbg);

		mytd.appendChild(mysvg);
	};

	// add event handlers
	mytd.onmousemove = null;
	mytd.onmouseup = null;

	return mytd;
};

function makeIframeLst(contdoc, id, src, large) {
	var myiframe;

	myiframe = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:iframe");
	myiframe.setAttribute("id", id);
	myiframe.setAttribute("src", src);
	if (large) myiframe.setAttribute("width", "340");
	else myiframe.setAttribute("width", "195");
	myiframe.setAttribute("height", "92");
	myiframe.setAttribute("frameborder", "0");
	myiframe.setAttribute("scrolling", "no");

	return myiframe;
};

function refreshLst(lstdoc, srcdoc, ncol, large, multsel, blk, numFirstdisp, numsSel) {
	var mytbl, mytr, mytd, num, res, finode, selclass;

	var cnt = getFeedSize(srcdoc, blk);

	var w;

	mytbl = lstdoc.getElementById("tbl");
	clearElem(mytbl);

	for (var i = 1; i <= 5; i++) {
		mytr = lstdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:tr");
		mytr.setAttribute("id", "r" + i);

		mytd = lstdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
		mytd.setAttribute("height", "18");
		mytd.setAttribute("class", "frame");
		mytr.appendChild(mytd);

		num = numFirstdisp+i-1;

		// find element in feed
		res = srcdoc.evaluate("//wdbe:" + blk + "/wdbe:Fi[@num='" + num + "']", srcdoc, nsResolver, XPathResult.ANY_TYPE, null);
		finode = res.iterateNext();

		if (finode) {
			// regular data row
			if ((num%2) == 0) selclass = "nonsel";
			else selclass = "nonselalt";

			for (var j = 0; j < numsSel.length; j++) {
				if (numsSel[j] == num) {
					selclass = "sel";
					break;
				};
			};

			for (var j = 1; j <= ncol; j++) {
				mytd = lstdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
				mytd.setAttribute("id", "r" + i + "c" + j);

				mytd.setAttribute("class", selclass);

				if (i == 1) mytd.setAttribute("onclick", "handleLstSelect(" + num + ")");
				else mytr.setAttribute("onclick", "handleLstSelect(" + num + ")");

				txt = retrieveFeedTitleByNumI(srcdoc, blk, num, j);

				if (ncol == 1) {
					w = ((large == true) ? 324 : 179);
				} else if (ncol == 2) {
					if (j == 1) w = ((large == true) ? 174 : 94);
					else w = ((large == true) ? 150 : 85);
				} else if (ncol == 3) {
					if (j == 1) w = ((large == true) ? 124 : 69);
					else if (j == 2) w = ((large == true) ? 100 : 55);
					else w = ((large == true) ? 100 : 55);
				};

				if ((selclass == "sel") && (txt.length > Math.ceil(w*0.125))) {
					txt = txt.substring(0, Math.ceil(w*0.125) -3) + "...";
				} else if ((selclass != "sel") && (txt.length > Math.ceil(w*0.15))) {
					txt = txt.substring(0, Math.ceil(w*0.15) -3) + "...";
				};

				setTextContent(lstdoc, mytd, txt);

				mytr.appendChild(mytd);
			};
			
		} else {
			// empty row
			mytd = lstdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");
			mytr.appendChild(mytd);
		};

		if (i == 1) {
			// scroll bar
			mytr.appendChild(makeTdLsb(lstdoc, (cnt > 5), (numFirstdisp-1) / (cnt-5)));
		};

		mytbl.appendChild(mytr);
	};
};


