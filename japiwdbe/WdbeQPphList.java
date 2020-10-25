/**
  * \file WdbeQPphList.h
  * Java API code for record of table TblWdbeQPphList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPphList {
	
	public WdbeQPphList(
				int jnum
				, String sref
				, String stubRefWdbeMUnit
				, String stubRefWdbeMModule
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWdbeMUnit = stubRefWdbeMUnit;
		this.stubRefWdbeMModule = stubRefWdbeMModule;
	};

	public int jnum;
	public String sref;
	public String stubRefWdbeMUnit;
	public String stubRefWdbeMModule;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPphList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWdbeMUnit = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMUnit", "unt", null, 0);
			stubRefWdbeMModule = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMModule", "mdl", null, 0);
			
			return true;
		};

		return false;
	};
};

