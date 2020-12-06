function refreshUpd(contdoc, id, min, max, val, act, chg) {
	var myinput;

	var cl;

	if (val < min) val = min;
	if (val > max) val = max;

	cl = "txfs";
	if (act) {
		if (chg) cl = cl + "mod";
	} else cl = cl + "noed";

	myinput = contdoc.getElementById(id + "Val");
	myinput.value = "" + val;
	myinput.setAttribute("class", cl);
	if (act) {
		myinput.removeAttribute("readonly");
		myinput.setAttribute("onchange", "handle" + id + "ValChange()");
		myinput.setAttribute("onkeypress", "return handle" + id + "ValKey(event)");
	}	else {
		myinput.setAttribute("readonly", "readonly");
		myinput.removeAttribute("onchange");
		myinput.removeAttribute("onkeypress");
	};

	if (act && (val != min)) {
		contdoc.getElementById(id + "Down").setAttribute("class", "upd");
		contdoc.getElementById(id + "Down").setAttribute("onclick", "handle" + id + "DownClick()");
	} else {
		contdoc.getElementById(id + "Down").setAttribute("class", "updinact");
		contdoc.getElementById(id + "Down").removeAttribute("onclick");
	};

	if (act && (val != max)) {
		contdoc.getElementById(id + "Up").setAttribute("class", "upd");
		contdoc.getElementById(id + "Up").setAttribute("onclick", "handle" + id + "UpClick()");
	} else {
		contdoc.getElementById(id + "Up").setAttribute("class", "updinact");
		contdoc.getElementById(id + "Up").removeAttribute("onclick");
	};
};
