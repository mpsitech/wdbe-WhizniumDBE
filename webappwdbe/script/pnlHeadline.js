function makeSpanCpt(tit) {
	var myspan;

	myspan = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:span");
	myspan.setAttribute("class", "cpt");
	setTextContent(contdoc, myspan, tit);

	return myspan;
};

function makeImgBut(id, icon) {
	var myimg;

	myimg = contdoc.createElementNS("http://www.w3.org/1999/xhtml", "html:img");
	myimg.setAttribute("class", "but");
	myimg.setAttribute("width", "10");
	myimg.setAttribute("height", "10");
	myimg.setAttribute("alt", id);
	myimg.setAttribute("src", "../" + icon + ".png");
	myimg.setAttribute("onmouseover", "src='../" + icon + "_hlt.png'");
	myimg.setAttribute("onmouseout", "src='../" + icon + ".png'");
	myimg.setAttribute("onclick", "handle" + id + "Click()")

	return myimg;
};
