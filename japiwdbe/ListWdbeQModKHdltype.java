/**
  * \file ListWdbeQModKHdltype.java
  * Java API code for record set of table TblWdbeQModKHdltype
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQModKHdltype {

	public ListWdbeQModKHdltype() {
		nodes = new ArrayList<WdbeQModKHdltype>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQModKHdltype> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQModKHdltype rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQModKHdltype");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQModKHdltype", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQModKHdltype(i+1, "", "", "", "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQModKHdltype[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

