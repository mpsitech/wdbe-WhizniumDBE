/**
	* \file WdbeQMchList.h
	* Java API code for record of table TblWdbeQMchList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQMchList {
	
	public WdbeQMchList(
				int jnum
				, String sref
				, String stubSupRefWdbeMMachine
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubSupRefWdbeMMachine = stubSupRefWdbeMMachine;
	};

	public int jnum;
	public String sref;
	public String stubSupRefWdbeMMachine;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQMchList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubSupRefWdbeMMachine = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWdbeMMachine", "sup", null, 0);
			
			return true;
		};

		return false;
	};
};
