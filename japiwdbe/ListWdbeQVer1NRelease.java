/**
	* \file ListWdbeQVer1NRelease.java
	* Java API code for record set of table TblWdbeQVer1NRelease
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQVer1NRelease {

	public ListWdbeQVer1NRelease() {
		nodes = new ArrayList<WdbeQVer1NRelease>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQVer1NRelease> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQVer1NRelease rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQVer1NRelease");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQVer1NRelease", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQVer1NRelease(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQVer1NRelease[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
