/**
	* \file WdbeQFstList.h
	* Java API code for record of table TblWdbeQFstList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQFstList {
	
	public WdbeQFstList(
				int jnum
				, String sref
				, String stubFsmRefWdbeMFsm
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubFsmRefWdbeMFsm = stubFsmRefWdbeMFsm;
	};

	public int jnum;
	public String sref;
	public String stubFsmRefWdbeMFsm;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQFstList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubFsmRefWdbeMFsm = Xmlio.extractStringUclc(doc, basexpath, "stubFsmRefWdbeMFsm", "fsm", null, 0);
			
			return true;
		};

		return false;
	};
};
