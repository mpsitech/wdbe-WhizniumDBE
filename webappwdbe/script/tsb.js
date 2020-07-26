function makeTdTsb(contdoc, sb, rhcr, rows, pos, narrow) {
	var h, w, yoffset, vpos, svgns, mysbg, myimg, mytd, mysvg, myg, myrect, myline, mypath, myg2;

	// pos: 0.0 .. 1.0, h: rows*18, w: 25 regular, 15 narrow

	if (narrow == true) w = 15;
	else w = 25;

	h = rows * 18;
	vpos = (18 + Math.round(pos * (h-2*18)));

	svgns = "http://www.w3.org/2000/svg";

	// table cell
	/*
	<td id="tdTsb" rowspan="10">
	*/
	mytd = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");

	mytd.setAttribute("id", "tdTsb");
	mytd.setAttribute("rowspan", "" + (rows+1));

	// SVG object
	/*
	<svg width="100%" height="100%" version="1.1" xmlns="http://www.w3.org/2000/svg">
	*/
	mysvg = contdoc.createElementNS(svgns, "svg:svg");

	mysvg.setAttribute("width", "" + w + "px");
	mysvg.setAttribute("height", "" + (h+20) + "px");
	mysvg.setAttribute("version", "1.1");
	mysvg.setAttribute("xmlns", svgns);

	// top black rect
	/*
	<rect x="0" y="0" width="25" height="20" fill="black" stroke="none"/>
	*/
	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("x", "0");
	myrect.setAttribute("y", "0");
	myrect.setAttribute("width", "" + w);
	myrect.setAttribute("height", "20");
	myrect.setAttribute("fill", "black");
	myrect.setAttribute("stroke", "none");

	mysvg.appendChild(myrect);

	if (rhcr == true) {
		// row header column right container
		myimg = contdoc.createElementNS(svgns, "image");

		myimg.setAttribute("id", "TblCnext");
		myimg.setAttribute("class", "but");
		myimg.setAttributeNS("http://www.w3.org/1999/xlink", "xlink:href", "../icon/cnext.png");
		myimg.setAttribute("x", "" + (w-12));
		myimg.setAttribute("y", "4");
		myimg.setAttribute("width", "12");
		myimg.setAttribute("height", "12");
		myimg.setAttribute("alt", "cnext");
		myimg.setAttribute("onmouseover", "setAttributeNS('http://www.w3.org/1999/xlink', 'xlink:href', '../icon/cnext_hlt.png')");
		myimg.setAttribute("onmouseout", "setAttributeNS('http://www.w3.org/1999/xlink', 'xlink:href', '../icon/cnext.png')");
		myimg.setAttribute("onclick", "handleTblCnextClick()");

		mysvg.appendChild(myimg);
	};

	if (sb == true) {
		// scroll bar container
		mysbg = contdoc.createElementNS(svgns, "g");
		mysbg.setAttribute("transform", "translate(0 20)");
		mysbg.setAttribute("class", "but");

		// arrows
		/*
		<g id="TsbUp" class="tsb" onmouseover="if(document.getElementById('tdTsb').onmousemove==null)document.getElementById('TsbUpl').setAttribute('stroke','#ff7f00')" onmouseout="document.getElementById('TsbUpl').setAttribute('stroke','black')" onclick="handleTsbUpClick()">
			<rect x="0" y="0" width="25" height="10" fill="white" stroke="none"/>
			<path id="TsbUpl" d="M0 10 L12.5 3.75 L25 10" fill="none" stroke-width="1" stroke="black"/>
		</g>
		*/

		// up
		myg = contdoc.createElementNS(svgns, "g");

		myg.setAttribute("id", "TsbUp");
		myg.setAttribute("class", "tsb");
		myg.setAttribute("onmouseover", "if(document.getElementById('tdTsb').onmousemove==null)document.getElementById('TsbUpl').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "document.getElementById('TsbUpl').setAttribute('stroke','black')");
		myg.setAttribute("onclick", "handleTsbUpClick()");

		myrect = contdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "0");
		myrect.setAttribute("width", "" + w);
		myrect.setAttribute("height", "10");
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		mypath = contdoc.createElementNS(svgns, "path");

		mypath.setAttribute("id", "TsbUpl");
		mypath.setAttribute("d", "M0 10 L" + (w/2) + " 3.75 L" + w + " 10");
		mypath.setAttribute("fill", "none");
		mypath.setAttribute("stroke-width", "1");
		mypath.setAttribute("stroke", "black");

		myg.appendChild(mypath);

		mysbg.appendChild(myg);

		// down
		myg = contdoc.createElementNS(svgns, "g");

		myg.setAttribute("id", "TsbDown");
		myg.setAttribute("class", "tsb");
		myg.setAttribute("transform", "translate(0 " + (h-11) + ")");
		myg.setAttribute("onmouseover", "if(document.getElementById('tdTsb').onmousemove==null)document.getElementById('TsbDownl').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "document.getElementById('TsbDownl').setAttribute('stroke','black')");
		myg.setAttribute("onclick", "handleTsbDownClick()");

		myrect = contdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "0");
		myrect.setAttribute("width", "" + w);
		myrect.setAttribute("height", "10");
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		mypath = contdoc.createElementNS(svgns, "path");

		mypath.setAttribute("id", "TsbDownl");
		mypath.setAttribute("d", "M0 0 L" + (w/2) + " 6.25 L" + w + " 0");
		mypath.setAttribute("fill", "none");
		mypath.setAttribute("stroke-width", "1");
		mypath.setAttribute("stroke", "black");

		myg.appendChild(mypath);

		mysbg.appendChild(myg);

		// inactive vertical bars
		/*
		<line stroke-width="1" stroke="#7f7f7f" x1="5" y1="3" x2="5" y2="10"/>
		*/
		myline = contdoc.createElementNS(svgns, "line");

		myline.setAttribute("stroke-width", "1");
		myline.setAttribute("stroke", "#7f7f7f");
		myline.setAttribute("x1", "5");
		myline.setAttribute("y1", "3");
		myline.setAttribute("x2", "5");
		myline.setAttribute("y2", "10");

		mysbg.appendChild(myline);

		myline = contdoc.createElementNS(svgns, "line");

		myline.setAttribute("stroke-width", "1");
		myline.setAttribute("stroke", "#7f7f7f");
		myline.setAttribute("x1", "5");
		myline.setAttribute("y1", "" + (h-11));
		myline.setAttribute("x2", "5");
		myline.setAttribute("y2", "" + (h-4));

		mysbg.appendChild(myline);

		// active vertical bars
		/*
		<g class="tsb" onmouseover="if(document.getElementById('tdTsb').onmousemove==null)document.getElementById('TsbJpupl').setAttribute('stroke','#ff7f00')" onmouseout="document.getElementById('TsbJpupl').setAttribute('stroke','black')" onclick="handleTsbJpupClick()">
			<rect id="TsbJpupr" x="0" y="10" width="25" height="8" fill="white" stroke="none"/>
			<line id="TsbJpupl" x1="5" y1="10" x2="5" y2="18" stroke-width="1" stroke="black"/>
		</g>
		*/

		// jpup
		myg = contdoc.createElementNS(svgns, "g");

		myg.setAttribute("class", "tsb");
		myg.setAttribute("onmouseover", "if(document.getElementById('tdTsb').onmousemove==null)document.getElementById('TsbJpupl').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "document.getElementById('TsbJpupl').setAttribute('stroke','black')");
		myg.setAttribute("onclick", "handleTsbJpupClick()");

		myrect = contdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("id", "TsbJpupr");
		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "10");
		myrect.setAttribute("width", "" + w);
		myrect.setAttribute("height", "" + (vpos-10));
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		myline = contdoc.createElementNS(svgns, "line");

		myline.setAttribute("id", "TsbJpupl");
		myline.setAttribute("x1", "5");
		myline.setAttribute("y1", "10");
		myline.setAttribute("x2", "5");
		myline.setAttribute("y2", "" + vpos);
		myline.setAttribute("stroke-width", "1");
		myline.setAttribute("stroke", "black");

		myg.appendChild(myline);

		mysbg.appendChild(myg);

		// jpdown
		myg = contdoc.createElementNS(svgns, "g");

		myg.setAttribute("class", "tsb");
		myg.setAttribute("onmouseover", "if(document.getElementById('tdTsb').onmousemove==null)document.getElementById('TsbJpdownl').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "document.getElementById('TsbJpdownl').setAttribute('stroke','black')");
		myg.setAttribute("onclick", "handleTsbJpdownClick()");

		myrect = contdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("id", "TsbJpdownr");
		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "" + vpos);
		myrect.setAttribute("width", "" + w);
		myrect.setAttribute("height", "" + (h-vpos-11));
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		myline = contdoc.createElementNS(svgns, "line");

		myline.setAttribute("id", "TsbJpdownl");
		myline.setAttribute("x1", "5");
		myline.setAttribute("y1", "" + vpos);
		myline.setAttribute("x2", "5");
		myline.setAttribute("y2", "" + (h-11));
		myline.setAttribute("stroke-width", "1");
		myline.setAttribute("stroke", "black");

		myg.appendChild(myline);

		mysbg.appendChild(myg);

		// slider
		/*
		<g id="Tsb" class="tsb" transform="translate(0 225)" onmouseover="document.getElementById('TsbBar').setAttribute('stroke','#ff7f00')" onmouseout="if(document.getElementById('tdTsb').onmousemove==null)document.getElementById('TsbBar').setAttribute('stroke','black')" onmousedown="handleTsbMdn()">
			<rect x="0" y="-3" width="25" height="6" fill="white" stroke="none"/>
			<g id="TsbBar" stroke-width="1" stroke="black">
				<line x1="0" y1="-2" x2="25" y2="-2"/>
				<line x1="0" y1="2" x2="25" y2="2"/>
			</g>
		</g>
		*/
		myg = contdoc.createElementNS(svgns, "g");

		myg.setAttribute("id", "Tsb");
		myg.setAttribute("class", "tsb");
		myg.setAttribute("transform", "translate(0 " + vpos + ")");
		myg.setAttribute("onmouseover", "document.getElementById('TsbBar').setAttribute('stroke','#ff7f00')");
		myg.setAttribute("onmouseout", "if(document.getElementById('tdTsb').onmousemove==null)document.getElementById('TsbBar').setAttribute('stroke','black')");
		myg.setAttribute("onmousedown", "handleTsbMdn()");

		myrect = contdoc.createElementNS(svgns, "rect");

		myrect.setAttribute("x", "0");
		myrect.setAttribute("y", "-3");
		myrect.setAttribute("width", "" + w);
		myrect.setAttribute("height", "6");
		myrect.setAttribute("fill", "white");
		myrect.setAttribute("stroke", "none");

		myg.appendChild(myrect);

		myg2 = contdoc.createElementNS(svgns, "g");

		myg2.setAttribute("id", "TsbBar");
		myg2.setAttribute("stroke-width", "1");
		myg2.setAttribute("stroke", "black");

		myline = contdoc.createElementNS(svgns, "line");

		myline.setAttribute("x1", "0");
		myline.setAttribute("y1", "-2");
		myline.setAttribute("x2", "" + w);
		myline.setAttribute("y2", "-2");

		myg2.appendChild(myline);

		myline = contdoc.createElementNS(svgns, "line");

		myline.setAttribute("x1", "0");
		myline.setAttribute("y1", "2");
		myline.setAttribute("x2", "" + w);
		myline.setAttribute("y2", "2");

		myg2.appendChild(myline);

		myg.appendChild(myg2);

		mysbg.appendChild(myg);

		mysvg.appendChild(mysbg);
	};

	mytd.appendChild(mysvg);

	// add event handlers
	mytd.onmousemove = null;
	mytd.onmouseup = null;

	return mytd;
};
