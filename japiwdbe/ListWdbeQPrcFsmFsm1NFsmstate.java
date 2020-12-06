/**
	* \file ListWdbeQPrcFsmFsm1NFsmstate.java
	* Java API code for record set of table TblWdbeQPrcFsmFsm1NFsmstate
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQPrcFsmFsm1NFsmstate {

	public ListWdbeQPrcFsmFsm1NFsmstate() {
		nodes = new ArrayList<WdbeQPrcFsmFsm1NFsmstate>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQPrcFsmFsm1NFsmstate> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQPrcFsmFsm1NFsmstate rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQPrcFsmFsm1NFsmstate");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQPrcFsmFsm1NFsmstate", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQPrcFsmFsm1NFsmstate(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQPrcFsmFsm1NFsmstate[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
