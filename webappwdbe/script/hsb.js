function makeTdHsb(contdoc, w, pos, narrow) {
	var h, hpos, svgns, mysbg, mytd, mysvg, myg, myrect, myline, mypath, myg2;

	// pos: 0.0 .. 1.0, h: 25 regular, 15 narrow

	if (narrow == true) {
		h = 15;
	} else {
		h = 25;
	};

	hpos = (16 + Math.round(pos * (w-2*16)));

	svgns = "http://www.w3.org/2000/svg";

	// table cell
	/*
	<td id="tdHsb">
	*/
	mytd = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");

	mytd.setAttribute("id", "tdHsb");

	// SVG object
	/*
	<svg width="100%" height="100%" version="1.1" xmlns="http://www.w3.org/2000/svg">
	*/
	mysvg = contdoc.createElementNS(svgns, "svg:svg");

	mysvg.setAttribute("width", "" + w + "px");
	mysvg.setAttribute("height", "" + h + "px");
	mysvg.setAttribute("version", "1.1");
	mysvg.setAttribute("xmlns", svgns);

	// scroll bar container
	mysbg = contdoc.createElementNS(svgns, "g");
	mysbg.setAttribute("class", "but");

	// arrows
	/*
	<g id="HsbLeft" class="hsb" onmouseover="if(document.getElementById('tdHsb').onmousemove==null)document.getElementById('HsbLeftl').setAttribute('stroke','#ff7f00')" onmouseout="document.getElementById('HsbLeftl').setAttribute('stroke','black')" onclick="handleHsbLeftClick()">
		<rect x="0" y="0" width="10" height="25" fill="white" stroke="none"/>
		<path id="HsbLeftl" d="M10 0 L3.75 12.5 L10 25" fill="none" stroke-width="1" stroke="black"/>
	</g>
	*/

	// left
	myg = contdoc.createElementNS(svgns, "g");

	myg.setAttribute("id", "HsbLeft");
	myg.setAttribute("class", "hsb");
	myg.setAttribute("onmouseover", "if(document.getElementById('tdHsb').onmousemove==null)document.getElementById('HsbLeftl').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "document.getElementById('HsbLeftl').setAttribute('stroke','black')");
	myg.setAttribute("onclick", "handleHsbLeftClick()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("x", "0");
	myrect.setAttribute("y", "0");
	myrect.setAttribute("width", "10");
	myrect.setAttribute("height", "" + h);
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	mypath = contdoc.createElementNS(svgns, "path");

	mypath.setAttribute("id", "HsbLeftl");
	mypath.setAttribute("d", "M10 0 L3.75 " + (h/2) + " L10 " + h);
	mypath.setAttribute("fill", "none");
	mypath.setAttribute("stroke-width", "1");
	mypath.setAttribute("stroke", "black");

	myg.appendChild(mypath);

	mysbg.appendChild(myg);

	// right
	myg = contdoc.createElementNS(svgns, "g");

	myg.setAttribute("id", "HsbRight");
	myg.setAttribute("class", "hsb");
	myg.setAttribute("transform", "translate(" + (w-7) + " 0)");
	myg.setAttribute("onmouseover", "if(document.getElementById('tdHsb').onmousemove==null)document.getElementById('HsbRightl').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "document.getElementById('HsbRightl').setAttribute('stroke','black')");
	myg.setAttribute("onclick", "handleHsbRightClick()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("x", "0");
	myrect.setAttribute("y", "0");
	myrect.setAttribute("width", "10");
	myrect.setAttribute("height", "" + h);
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	mypath = contdoc.createElementNS(svgns, "path");

	mypath.setAttribute("id", "HsbRightl");
	mypath.setAttribute("d", "M0 0 L6.25 " + (h/2) + " L0 " + h);
	mypath.setAttribute("fill", "none");
	mypath.setAttribute("stroke-width", "1");
	mypath.setAttribute("stroke", "black");

	myg.appendChild(mypath);

	mysbg.appendChild(myg);

	// inactive vertical bars
	/*
	<line stroke-width="1" stroke="#7f7f7f" x1="3" y1="5" x2="10" y2="5"/>
	*/
	myline = contdoc.createElementNS(svgns, "line");

	myline.setAttribute("stroke-width", "1");
	myline.setAttribute("stroke", "#7f7f7f");
	myline.setAttribute("x1", "3");
	myline.setAttribute("y1", "5");
	myline.setAttribute("x2", "10");
	myline.setAttribute("y2", "5");

	mysbg.appendChild(myline);

	myline = contdoc.createElementNS(svgns, "line");

	myline.setAttribute("stroke-width", "1");
	myline.setAttribute("stroke", "#7f7f7f");
	myline.setAttribute("x1", "" + (w-7));
	myline.setAttribute("y1", "5");
	myline.setAttribute("x2", "" + w);
	myline.setAttribute("y2", "5");

	mysbg.appendChild(myline);

	// active vertical bars
	/*
	<g class="hsb" onmouseover="if(document.getElementById('tdHsb').onmousemove==null)document.getElementById('HsbJpleftl').setAttribute('stroke','#ff7f00')" onmouseout="document.getElementById('HsbJpleftl').setAttribute('stroke','black')" onclick="handleHsbJpleftClick()">
		<rect id="HsbJpleftr" x="0" y="10" width="8" height="25" fill="white" stroke="none"/>
		<line id="HsbJpleftl" x1="10" y1="5" x2="18" y2="5" stroke-width="1" stroke="black"/>
	</g>
	*/

	// jpleft
	myg = contdoc.createElementNS(svgns, "g");

	myg.setAttribute("class", "hsb");
	myg.setAttribute("onmouseover", "if(document.getElementById('tdHsb').onmousemove==null)document.getElementById('HsbJpleftl').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "document.getElementById('HsbJpleftl').setAttribute('stroke','black')");
	myg.setAttribute("onclick", "handleHsbJpleftClick()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("id", "HsbJpleftr");
	myrect.setAttribute("x", "10");
	myrect.setAttribute("y", "0");
	myrect.setAttribute("width", "" + (hpos-10));
	myrect.setAttribute("height", "" + h);
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	myline = contdoc.createElementNS(svgns, "line");

	myline.setAttribute("id", "HsbJpleftl");
	myline.setAttribute("x1", "10");
	myline.setAttribute("y1", "5");
	myline.setAttribute("x2", "" + hpos);
	myline.setAttribute("y2", "5");
	myline.setAttribute("stroke-width", "1");
	myline.setAttribute("stroke", "black");

	myg.appendChild(myline);

	mysbg.appendChild(myg);

	// jpright
	myg = contdoc.createElementNS(svgns, "g");

	myg.setAttribute("class", "hsb");
	myg.setAttribute("onmouseover", "if(document.getElementById('tdHsb').onmousemove==null)document.getElementById('HsbJprightl').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "document.getElementById('HsbJprightl').setAttribute('stroke','black')");
	myg.setAttribute("onclick", "handleHsbJprightClick()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("id", "HsbJprightr");
	myrect.setAttribute("x", "" + hpos);
	myrect.setAttribute("y", "0");
	myrect.setAttribute("width", "" + (w-hpos-7));
	myrect.setAttribute("height", "" + h);
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	myline = contdoc.createElementNS(svgns, "line");

	myline.setAttribute("id", "HsbJprightl");
	myline.setAttribute("x1", "" + hpos);
	myline.setAttribute("y1", "5");
	myline.setAttribute("x2", "" + (w-7));
	myline.setAttribute("y2", "5");
	myline.setAttribute("stroke-width", "1");
	myline.setAttribute("stroke", "black");

	myg.appendChild(myline);

	mysbg.appendChild(myg);

	// slider
	/*
	<g id="Hsb" class="hsb" transform="translate(0 225)" onmouseover="document.getElementById('HsbBar').setAttribute('stroke','#ff7f00')" onmouseout="if(document.getElementById('tdHsb').onmousemove==null)document.getElementById('HsbBar').setAttribute('stroke','black')" onmousedown="handleHsbMdn()">
		<rect x="-3" y="0" width="6" height="25" fill="white" stroke="none"/>
		<g id="HsbBar" stroke-width="1" stroke="black">
			<line x1="-2" y1="0" x2="-2" y2="25"/>
			<line x1="2" y1="0" x2="2" y2="25"/>
		</g>
	</g>
	*/
	myg = contdoc.createElementNS(svgns, "g");

	myg.setAttribute("id", "Hsb");
	myg.setAttribute("class", "hsb");
	myg.setAttribute("transform", "translate(" + hpos + " 0)");
	myg.setAttribute("onmouseover", "document.getElementById('HsbBar').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "if(document.getElementById('tdHsb').onmousemove==null)document.getElementById('HsbBar').setAttribute('stroke','black')");
	myg.setAttribute("onmousedown", "handleHsbMdn()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("x", "-3");
	myrect.setAttribute("y", "0");
	myrect.setAttribute("width", "6");
	myrect.setAttribute("height", "" + h);
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	myg2 = contdoc.createElementNS(svgns, "g");

	myg2.setAttribute("id", "HsbBar");
	myg2.setAttribute("stroke-width", "1");
	myg2.setAttribute("stroke", "black");

	myline = contdoc.createElementNS(svgns, "line");

	myline.setAttribute("x1", "-2");
	myline.setAttribute("y1", "0");
	myline.setAttribute("x2", "-2");
	myline.setAttribute("y2", "" + h);

	myg2.appendChild(myline);

	myline = contdoc.createElementNS(svgns, "line");

	myline.setAttribute("x1", "2");
	myline.setAttribute("y1", "0");
	myline.setAttribute("x2", "2");
	myline.setAttribute("y2", "" + h);

	myg2.appendChild(myline);

	myg.appendChild(myg2);

	mysbg.appendChild(myg);

	mysvg.appendChild(mysbg);

	mytd.appendChild(mysvg);

	// add event handlers
	mytd.onmousemove = null;
	mytd.onmouseup = null;

	return mytd;
};
