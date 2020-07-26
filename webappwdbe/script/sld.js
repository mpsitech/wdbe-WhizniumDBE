function alignSldVal(min, max, rast, val) {
	if ((rast != 0.0) && (rast < (max-min))) val = min + rast * Math.round((val-min) / rast);

	if (val < min) val = min;
	if (val > max) val = max;

	return val;
};

function alignSldLogval(min, max, rast, logval) {
	if ((rast != 0.0) && (rast < (max/min))) logval = min * Math.pow(rast, Math.round(Math.log(logval/min) / Math.log(rast)));

	if (logval < min) logval = min;
	if (logval > max) logval = max;

	return logval;
};

function getSldPosFromEvtx(large, evtx) {
	var pos;

	if (large) pos = (evtx-225.0-5.0)/(340.0-10.0);
	else pos = (evtx-165.0-5.0)/(190.0-10.0);

	if (pos < 0.0) pos = 0.0;
	if (pos > 1.0) pos = 1.0;

	return pos;
};

function getSldValFromPos(min, max, rast, pos) {
	// linear mapping pos = [0;1] -> [min:rast:max] = val
	var posrast, val;

	if ((rast != 0.0) && (rast < (max-min))) {
		posrast = rast / (max-min);
		pos = posrast * Math.round(pos/posrast);
	};

	if (pos < 0.0) pos = 0.0;
	if (pos > 1.0) pos = 1.0;

	val = min + pos * (max-min);

	return val;
};

function getSldLogvalFromPos(min, max, rast, pos) {
	// logarithmic mapping pos = [0;1] -> [min:rast:max] = val
	var posrast, logval;

	if ((rast != 0.0) && (rast < (max/min))) {
		posrast = Math.log(rast) / Math.log(max/min);
		pos = posrast * Math.round(pos/posrast);
	};

	if (pos < 0.0) pos = 0.0;
	if (pos > 1.0) pos = 1.0;

	logval = min * Math.pow(max/min, pos);

	return logval;
};

function getSldPosFromVal(min, max, val) {
	return((val-min) / (max-min));
};

function getSldPosFromLogval(min, max, logval) {
	return(Math.log(logval/min) / Math.log(max/min));
};

function setSldPos(contdoc, id, large, pos) {
	// pos = [0;1]
	var w = (large ? 330.0 : 180.0);

	contdoc.getElementById(id + "Jpleftr").setAttribute("width", "" + (pos*w));
	contdoc.getElementById(id + "Jpleftl").setAttribute("x2", "" + (pos*w+2.5));

	contdoc.getElementById(id + "Jprightr").setAttribute("x", "" + (pos*w+5.0));
	contdoc.getElementById(id + "Jprightr").setAttribute("width", "" + ((1.0-pos)*w));
	contdoc.getElementById(id + "Jprightl").setAttribute("x1", "" + (pos*w+7.5));

	contdoc.getElementById(id).setAttribute("transform", "translate(" + (pos*w+5.0) + " 0)");
};

function setSldVal(contdoc, id, val, act, chg) {
	var myinput;

	var cl;

	cl = "txfxs";
	if (act) {
		if (chg) cl = cl + "mod";
	} else cl = cl + "noed";

	myinput = contdoc.getElementById(id + "Val");
	myinput.value = "" + val;
	myinput.setAttribute("class", cl);
};

function refreshSld(contdoc, id, large, log, min, max, val, act, chg) {
	if (val < min) val = min;
	if (val > max) val = max;

	if (log) setSldPos(contdoc, id, large, getSldPosFromLogval(min, max, val));
	else setSldPos(contdoc, id, large, getSldPosFromVal(min, max, val));

	setSldVal(contdoc, id, val, act, chg);

	if (act) {
		contdoc.getElementById(id + "Jpleft").setAttribute("class", "sld");
		contdoc.getElementById(id + "Jpleft").setAttribute("onmouseover", "handle" + id + "JpleftMov()");
		contdoc.getElementById(id + "Jpleft").setAttribute("onmouseout", "handle" + id + "JpleftMou()");
		contdoc.getElementById(id + "Jpleft").setAttribute("onclick", "handle" + id + "JpleftClick(event)");
		contdoc.getElementById(id + "Jpleftr").setAttribute("class", "sldr");
		contdoc.getElementById(id + "Jpleftl").setAttribute("class", "sldl");
		contdoc.getElementById(id + "Jpright").setAttribute("class", "sld");
		contdoc.getElementById(id + "Jpright").setAttribute("onmouseover", "handle" + id + "JprightMov()");
		contdoc.getElementById(id + "Jpright").setAttribute("onmouseout", "handle" + id + "JprightMou()");
		contdoc.getElementById(id + "Jpright").setAttribute("onclick", "handle" + id + "JprightClick(event)");
		contdoc.getElementById(id + "Jprightr").setAttribute("class", "sldr");
		contdoc.getElementById(id + "Jprightl").setAttribute("class", "sldl");
		contdoc.getElementById(id).setAttribute("class", "sld");
		contdoc.getElementById(id).setAttribute("onmouseover", "handle" + id + "Mov()");
		contdoc.getElementById(id).setAttribute("onmouseout", "handle" + id + "Mou()");
		contdoc.getElementById(id).setAttribute("onmousedown", "handle" + id + "Mdn()");
		contdoc.getElementById(id + "R").setAttribute("class", "sldr");
		contdoc.getElementById(id + "Bar").setAttribute("class", "sldl");
		contdoc.getElementById(id + "Val").removeAttribute("readonly");
		contdoc.getElementById(id + "Val").setAttribute("onchange", "handle" + id + "ValChange()");
		contdoc.getElementById(id + "Val").setAttribute("onkeypress", "return handle" + id + "ValKey(event)");
	} else {
		contdoc.getElementById(id + "Jpleft").setAttribute("class", "sldinact");
		contdoc.getElementById(id + "Jpleft").removeAttribute("onmouseover");
		contdoc.getElementById(id + "Jpleft").removeAttribute("onmouseout");
		contdoc.getElementById(id + "Jpleft").removeAttribute("onclick");
		contdoc.getElementById(id + "Jpleftr").setAttribute("class", "sldrinact");
		contdoc.getElementById(id + "Jpleftl").setAttribute("class", "sldlinact");
		contdoc.getElementById(id + "Jpright").setAttribute("class", "sldinact");
		contdoc.getElementById(id + "Jpright").removeAttribute("onmouseover");
		contdoc.getElementById(id + "Jpright").removeAttribute("onmouseout");
		contdoc.getElementById(id + "Jpright").removeAttribute("onclick");
		contdoc.getElementById(id + "Jprightr").setAttribute("class", "sldrinact");
		contdoc.getElementById(id + "Jprightl").setAttribute("class", "sldlinact");
		contdoc.getElementById(id).setAttribute("class", "sldinact");
		contdoc.getElementById(id).removeAttribute("onmouseover");
		contdoc.getElementById(id).removeAttribute("onmouseout");
		contdoc.getElementById(id).removeAttribute("onmousedown");
		contdoc.getElementById(id + "R").setAttribute("class", "sldrinact");
		contdoc.getElementById(id + "Bar").setAttribute("class", "sldlinact");
		contdoc.getElementById(id + "Val").setAttribute("readonly", "readonly");
		contdoc.getElementById(id + "Val").removeAttribute("onchange");
		contdoc.getElementById(id + "Val").removeAttribute("onkeypress");
	};
};

