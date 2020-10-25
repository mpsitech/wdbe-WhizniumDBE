/**
  * \file ListWdbeQCvrBcv1NCoreversion.java
  * Java API code for record set of table TblWdbeQCvrBcv1NCoreversion
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQCvrBcv1NCoreversion {

	public ListWdbeQCvrBcv1NCoreversion() {
		nodes = new ArrayList<WdbeQCvrBcv1NCoreversion>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQCvrBcv1NCoreversion> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQCvrBcv1NCoreversion rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQCvrBcv1NCoreversion");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQCvrBcv1NCoreversion", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQCvrBcv1NCoreversion(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQCvrBcv1NCoreversion[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};

