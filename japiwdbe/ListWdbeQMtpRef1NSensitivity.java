/**
	* \file ListWdbeQMtpRef1NSensitivity.java
	* Java API code for record set of table TblWdbeQMtpRef1NSensitivity
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQMtpRef1NSensitivity {

	public ListWdbeQMtpRef1NSensitivity() {
		nodes = new ArrayList<WdbeQMtpRef1NSensitivity>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQMtpRef1NSensitivity> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQMtpRef1NSensitivity rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQMtpRef1NSensitivity");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQMtpRef1NSensitivity", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQMtpRef1NSensitivity(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQMtpRef1NSensitivity[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
