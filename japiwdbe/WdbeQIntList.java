/**
	* \file WdbeQIntList.h
	* Java API code for record of table TblWdbeQIntList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQIntList {
	
	public WdbeQIntList(
				int jnum
				, String sref
				, String stubRefWdbeMUnit
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWdbeMUnit = stubRefWdbeMUnit;
	};

	public int jnum;
	public String sref;
	public String stubRefWdbeMUnit;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQIntList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWdbeMUnit = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMUnit", "unt", null, 0);
			
			return true;
		};

		return false;
	};
};
