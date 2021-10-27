/**
	* \file ListWdbeQMtpHsm1NPipeline.java
	* Java API code for record set of table TblWdbeQMtpHsm1NPipeline
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ListWdbeQMtpHsm1NPipeline {

	public ListWdbeQMtpHsm1NPipeline() {
		nodes = new ArrayList<WdbeQMtpHsm1NPipeline>();
	};
	
	public void clear() {
		nodes.clear();
	};

	public ArrayList<WdbeQMtpHsm1NPipeline> nodes;

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		Vector<Integer> ics = new Vector<Integer>();
		Vector<Boolean> shorttags = new Vector<Boolean>();

		WdbeQMtpHsm1NPipeline rec;

		String s;

		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ListWdbeQMtpHsm1NPipeline");

		if (Xmlio.checkXPath(doc, basexpath)) {
			Xmlio.extractList(doc, basexpath, "WdbeQMtpHsm1NPipeline", "row", "jnum", ics, shorttags);

			clear();
			
			for (int i = 0; i < ics.size(); i++) {
				rec = new WdbeQMtpHsm1NPipeline(i+1, "");

				if (shorttags.get(i)) s = basexpath + "/row[@jnum='" + ics.get(i).toString() + "']";
				else s = basexpath + "/WdbeQMtpHsm1NPipeline[@jnum='" + ics.get(i).toString() + "']";
				
				if (rec.readXML(doc, s, false)) nodes.add(rec);
			};
			
			return true;
		};

		return false;
	};
};
