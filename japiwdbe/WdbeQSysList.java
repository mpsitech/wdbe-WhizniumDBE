/**
	* \file WdbeQSysList.h
	* Java API code for record of table TblWdbeQSysList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQSysList {
	
	public WdbeQSysList(
				int jnum
				, String sref
				, String stubRefWdbeMVersion
				, String stubRefWdbeMUnit
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWdbeMVersion = stubRefWdbeMVersion;
		this.stubRefWdbeMUnit = stubRefWdbeMUnit;
	};

	public int jnum;
	public String sref;
	public String stubRefWdbeMVersion;
	public String stubRefWdbeMUnit;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQSysList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWdbeMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMVersion", "ver", null, 0);
			stubRefWdbeMUnit = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMUnit", "unt", null, 0);
			
			return true;
		};

		return false;
	};
};
