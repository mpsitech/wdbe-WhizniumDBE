/**
  * \file ListWdbeQPphAPar.java
  * Java API code for record set of table TblWdbeQPphAPar
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQPphAPar {

	public ListWdbeQPphAPar() {
		nodes = new ArrayList<WdbeQPphAPar>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQPphAPar> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQPphAPar rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQPphAPar");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQPphAPar", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQPphAPar(i+1, "", "", "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQPphAPar[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

