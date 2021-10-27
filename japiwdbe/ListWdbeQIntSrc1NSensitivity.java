/**
	* \file ListWdbeQIntSrc1NSensitivity.java
	* Java API code for record set of table TblWdbeQIntSrc1NSensitivity
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQIntSrc1NSensitivity {

	public ListWdbeQIntSrc1NSensitivity() {
		nodes = new ArrayList<WdbeQIntSrc1NSensitivity>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQIntSrc1NSensitivity> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQIntSrc1NSensitivity rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQIntSrc1NSensitivity");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQIntSrc1NSensitivity", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQIntSrc1NSensitivity(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQIntSrc1NSensitivity[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
