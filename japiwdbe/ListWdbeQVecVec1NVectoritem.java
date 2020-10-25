/**
  * \file ListWdbeQVecVec1NVectoritem.java
  * Java API code for record set of table TblWdbeQVecVec1NVectoritem
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQVecVec1NVectoritem {

	public ListWdbeQVecVec1NVectoritem() {
		nodes = new ArrayList<WdbeQVecVec1NVectoritem>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQVecVec1NVectoritem> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQVecVec1NVectoritem rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQVecVec1NVectoritem");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQVecVec1NVectoritem", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQVecVec1NVectoritem(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQVecVec1NVectoritem[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

