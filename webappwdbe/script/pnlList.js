function strRecord(tpl, firstload, lastload, ntot, empty) {
	var retval;

	if (parseInt(ntot) == 0) {
		retval = empty;
	} else {
		retval = tpl;
		retval = retval.replace(/&firstload;/g, firstload);
		retval = retval.replace(/&lastload;/g, lastload);
		retval = retval.replace(/&ntot;/g, ntot);
	};

	return retval;
};

function strShowing(tpl, firstdisp, lastdisp, ntot, empty) {
	var retval;

	if (parseInt(ntot) == 0) {
		retval = empty;
	} else {
		retval = tpl;
		retval = retval.replace(/&firstdisp;/g, firstdisp);
		retval = retval.replace(/&lastdisp;/g, lastdisp);
		retval = retval.replace(/&ntot;/g, ntot);
	};

	return retval;
};

function strFor(tpl, pretit) {
	var retval;

	if (pretit == "") {
		retval = "";
	} else {
		retval = tpl;
		retval = retval.replace(/&pretit;/g, pretit);
	};

	return retval;
};

function copyToClipboard(doc, srcdoc, blkshort, listblk, tpl, empty, tags, tcos) {
	// obtain record set characteristics
	var jnumFirstload = parseInt(retrieveSi(srcdoc, "StatShrQry" + blkshort, "jnumFirstload"));
	var nload = parseInt(retrieveSi(srcdoc, "StatShrQry" + blkshort, "nload"));
	var ntot = parseInt(retrieveSi(srcdoc, "StatShrQry" + blkshort, "ntot"));

	var rownode;

	var mytxa;

	mytxa = doc.createElementNS("http://www.w3.org/1999/xhtml", "html:textarea");

	// header
	mytxa.value = retrieveTi(srcdoc, "Tag" + blkshort, "Cpt");
	var TxtFor = retrieveCi(srcdoc, "ContInf" + blkshort, "TxtFor");
	if (TxtFor != "") mytxa.value += " " + strFor(retrieveTi(srcdoc, "Tag" + blkshort, "TxtFor"), TxtFor) + " " + retrieveCi(srcdoc, "ContInf" + blkshort, "TxtPre");
	mytxa.value += "\n";

	mytxa.value += strRecord(tpl, jnumFirstload, jnumFirstload + nload - 1, ntot, empty);
	
	if (ntot > 0) {
		mytxa.value += "\n\n";

		for (var i = 0; i < tags.length; i++) {
			if (tags[i] != "") mytxa.value += retrieveTi(srcdoc, "Tag" + blkshort, "Tco" + tags[i]);
			mytxa.value += "\t";
		};
		mytxa.value += "\n";

		// content
		for (var i = jnumFirstload; i < (jnumFirstload + nload); i++) {
			rownode = getRownode(srcdoc, listblk, i);

			for (var j = 0; j < tcos.length; j++) mytxa.value += replaceUesc(retrieveRowField(srcdoc, rownode, tcos[j])) + "\t";
			mytxa.value += "\n";
		};
	};

	doc.body.appendChild(mytxa);
	mytxa.select();
	doc.execCommand("copy");
	doc.body.removeChild(mytxa);
};
