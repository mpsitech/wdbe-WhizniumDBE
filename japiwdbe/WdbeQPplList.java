/**
	* \file WdbeQPplList.h
	* Java API code for record of table TblWdbeQPplList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPplList {
	
	public WdbeQPplList(
				int jnum
				, String sref
				, String stubHsmRefWdbeMModule
				, int Depth
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubHsmRefWdbeMModule = stubHsmRefWdbeMModule;
		this.Depth = Depth;
	};

	public int jnum;
	public String sref;
	public String stubHsmRefWdbeMModule;
	public int Depth;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPplList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubHsmRefWdbeMModule = Xmlio.extractStringUclc(doc, basexpath, "stubHsmRefWdbeMModule", "hsm", null, 0);
			Depth = Xmlio.extractIntegerUclc(doc, basexpath, "Depth", "dpt", null, 0);
			
			return true;
		};

		return false;
	};
};
