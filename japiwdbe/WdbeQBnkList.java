/**
	* \file WdbeQBnkList.h
	* Java API code for record of table TblWdbeQBnkList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQBnkList {
	
	public WdbeQBnkList(
				int jnum
				, String sref
				, String stubRefWdbeMUnit
				, String srefKVoltstd
				, String titSrefKVoltstd
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWdbeMUnit = stubRefWdbeMUnit;
		this.srefKVoltstd = srefKVoltstd;
		this.titSrefKVoltstd = titSrefKVoltstd;
	};

	public int jnum;
	public String sref;
	public String stubRefWdbeMUnit;
	public String srefKVoltstd;
	public String titSrefKVoltstd;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQBnkList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWdbeMUnit = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMUnit", "unt", null, 0);
			srefKVoltstd = Xmlio.extractStringUclc(doc, basexpath, "srefKVoltstd", "vst", null, 0);
			titSrefKVoltstd = Xmlio.extractStringUclc(doc, basexpath, "titSrefKVoltstd", "vst2", null, 0);
			
			return true;
		};

		return false;
	};
};

