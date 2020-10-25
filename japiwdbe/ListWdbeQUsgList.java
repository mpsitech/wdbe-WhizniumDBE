/**
  * \file ListWdbeQUsgList.java
  * Java API code for record set of table TblWdbeQUsgList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQUsgList {

	public ListWdbeQUsgList() {
		nodes = new ArrayList<WdbeQUsgList>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQUsgList> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQUsgList rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQUsgList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQUsgList", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQUsgList(i+1, "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQUsgList[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

