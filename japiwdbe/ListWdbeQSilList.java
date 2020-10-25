/**
  * \file ListWdbeQSilList.java
  * Java API code for record set of table TblWdbeQSilList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQSilList {

	public ListWdbeQSilList() {
		nodes = new ArrayList<WdbeQSilList>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQSilList> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQSilList rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQSilList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQSilList", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQSilList(i+1, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQSilList[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

