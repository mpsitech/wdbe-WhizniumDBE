function makeTdVsb(contdoc, h, pos, narrow) {
	var w, vpos, svgns, mysbg, mytd, mysvg, myg, myrect, myline, mypath, myg2;

	// pos: 0.0 .. 1.0, w: 25 regular, 15 narrow

	if (narrow == true) {
		w = 15;
	} else {
		w = 25;
	};

	vpos = (16 + Math.round(pos * (h-2*16)));

	svgns = "http://www.w3.org/2000/svg";

	// table cell
	/*
	<td id="tdVsb">
	*/
	mytd = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:td");

	mytd.setAttribute("id", "tdVsb");

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
	<g id="VsbUp" class="vsb" onmouseover="if(document.getElementById('tdVsb').onmousemove==null)document.getElementById('VsbUpl').setAttribute('stroke','#ff7f00')" onmouseout="document.getElementById('VsbUpl').setAttribute('stroke','black')" onclick="handleVsbUpClick()">
		<rect x="0" y="0" width="25" height="10" fill="white" stroke="none"/>
		<path id="VsbUpl" d="M0 10 L12.5 3.75 L25 10" fill="none" stroke-width="1" stroke="black"/>
	</g>
	*/

	// up
	myg = contdoc.createElementNS(svgns, "g");

	myg.setAttribute("id", "VsbUp");
	myg.setAttribute("class", "vsb");
	myg.setAttribute("onmouseover", "if(document.getElementById('tdVsb').onmousemove==null)document.getElementById('VsbUpl').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "document.getElementById('VsbUpl').setAttribute('stroke','black')");
	myg.setAttribute("onclick", "handleVsbUpClick()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("x", "0");
	myrect.setAttribute("y", "0");
	myrect.setAttribute("width", "" + w);
	myrect.setAttribute("height", "10");
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	mypath = contdoc.createElementNS(svgns, "path");

	mypath.setAttribute("id", "VsbUpl");
	mypath.setAttribute("d", "M0 10 L" + (w/2) + " 3.75 L" + w + " 10");
	mypath.setAttribute("fill", "none");
	mypath.setAttribute("stroke-width", "1");
	mypath.setAttribute("stroke", "black");

	myg.appendChild(mypath);

	mysbg.appendChild(myg);

	// down
	myg = contdoc.createElementNS(svgns, "g");

	myg.setAttribute("id", "VsbDown");
	myg.setAttribute("class", "vsb");
	myg.setAttribute("transform", "translate(0 " + (h-7) + ")");
	myg.setAttribute("onmouseover", "if(document.getElementById('tdVsb').onmousemove==null)document.getElementById('VsbDownl').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "document.getElementById('VsbDownl').setAttribute('stroke','black')");
	myg.setAttribute("onclick", "handleVsbDownClick()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("x", "0");
	myrect.setAttribute("y", "0");
	myrect.setAttribute("width", "" + w);
	myrect.setAttribute("height", "10");
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	mypath = contdoc.createElementNS(svgns, "path");

	mypath.setAttribute("id", "VsbDownl");
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
	myline.setAttribute("y1", "" + (h-7));
	myline.setAttribute("x2", "5");
	myline.setAttribute("y2", "" + h);

	mysbg.appendChild(myline);

	// active vertical bars
	/*
	<g class="vsb" onmouseover="if(document.getElementById('tdVsb').onmousemove==null)document.getElementById('VsbJpupl').setAttribute('stroke','#ff7f00')" onmouseout="document.getElementById('VsbJpupl').setAttribute('stroke','black')" onclick="handleVsbJpupClick()">
		<rect id="VsbJpupr" x="0" y="10" width="25" height="8" fill="white" stroke="none"/>
		<line id="VsbJpupl" x1="5" y1="10" x2="5" y2="18" stroke-width="1" stroke="black"/>
	</g>
	*/

	// jpup
	myg = contdoc.createElementNS(svgns, "g");

	myg.setAttribute("class", "vsb");
	myg.setAttribute("onmouseover", "if(document.getElementById('tdVsb').onmousemove==null)document.getElementById('VsbJpupl').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "document.getElementById('VsbJpupl').setAttribute('stroke','black')");
	myg.setAttribute("onclick", "handleVsbJpupClick()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("id", "VsbJpupr");
	myrect.setAttribute("x", "0");
	myrect.setAttribute("y", "10");
	myrect.setAttribute("width", "" + w);
	myrect.setAttribute("height", "" + (vpos-10));
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	myline = contdoc.createElementNS(svgns, "line");

	myline.setAttribute("id", "VsbJpupl");
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

	myg.setAttribute("class", "vsb");
	myg.setAttribute("onmouseover", "if(document.getElementById('tdVsb').onmousemove==null)document.getElementById('VsbJpdownl').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "document.getElementById('VsbJpdownl').setAttribute('stroke','black')");
	myg.setAttribute("onclick", "handleVsbJpdownClick()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("id", "VsbJpdownr");
	myrect.setAttribute("x", "0");
	myrect.setAttribute("y", "" + vpos);
	myrect.setAttribute("width", "" + w);
	myrect.setAttribute("height", "" + (h-vpos-7));
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	myline = contdoc.createElementNS(svgns, "line");

	myline.setAttribute("id", "VsbJpdownl");
	myline.setAttribute("x1", "5");
	myline.setAttribute("y1", "" + vpos);
	myline.setAttribute("x2", "5");
	myline.setAttribute("y2", "" + (h-7));
	myline.setAttribute("stroke-width", "1");
	myline.setAttribute("stroke", "black");

	myg.appendChild(myline);

	mysbg.appendChild(myg);

	// slider
	/*
	<g id="Vsb" class="vsb" transform="translate(0 225)" onmouseover="document.getElementById('VsbBar').setAttribute('stroke','#ff7f00')" onmouseout="if(document.getElementById('tdVsb').onmousemove==null)document.getElementById('VsbBar').setAttribute('stroke','black')" onmousedown="handleVsbMdn()">
		<rect x="0" y="-3" width="25" height="6" fill="white" stroke="none"/>
		<g id="VsbBar" stroke-width="1" stroke="black">
			<line x1="0" y1="-2" x2="25" y2="-2"/>
			<line x1="0" y1="2" x2="25" y2="2"/>
		</g>
	</g>
	*/
	myg = contdoc.createElementNS(svgns, "g");

	myg.setAttribute("id", "Vsb");
	myg.setAttribute("class", "vsb");
	myg.setAttribute("transform", "translate(0 " + vpos + ")");
	myg.setAttribute("onmouseover", "document.getElementById('VsbBar').setAttribute('stroke','#ff7f00')");
	myg.setAttribute("onmouseout", "if(document.getElementById('tdVsb').onmousemove==null)document.getElementById('VsbBar').setAttribute('stroke','black')");
	myg.setAttribute("onmousedown", "handleVsbMdn()");

	myrect = contdoc.createElementNS(svgns, "rect");

	myrect.setAttribute("x", "0");
	myrect.setAttribute("y", "-3");
	myrect.setAttribute("width", "" + w);
	myrect.setAttribute("height", "6");
	myrect.setAttribute("fill", "white");
	myrect.setAttribute("stroke", "none");

	myg.appendChild(myrect);

	myg2 = contdoc.createElementNS(svgns, "g");

	myg2.setAttribute("id", "VsbBar");
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

	mytd.appendChild(mysvg);

	// add event handlers
	mytd.onmousemove = null;
	mytd.onmouseup = null;

	return mytd;
};
