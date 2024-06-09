/**
	* \file WdbeQCdcList.java
	* Java API code for record of table TblWdbeQCdcList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQCdcList {
	
	public WdbeQCdcList(
				int jnum
				, String stubRefWdbeMModule
			) {
		this.jnum = jnum;
		this.stubRefWdbeMModule = stubRefWdbeMModule;
	};

	public int jnum;
	public String stubRefWdbeMModule;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQCdcList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubRefWdbeMModule = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMModule", "mdl", null, 0);
			
			return true;
		};

		return false;
	};
};
