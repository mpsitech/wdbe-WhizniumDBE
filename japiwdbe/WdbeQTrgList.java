/**
  * \file WdbeQTrgList.h
  * Java API code for record of table TblWdbeQTrgList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQTrgList {
	
	public WdbeQTrgList(
				int jnum
				, String sref
				, String stubSysRefWdbeMSystem
				, String stubRefWdbeMUnit
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubSysRefWdbeMSystem = stubSysRefWdbeMSystem;
		this.stubRefWdbeMUnit = stubRefWdbeMUnit;
	};

	public int jnum;
	public String sref;
	public String stubSysRefWdbeMSystem;
	public String stubRefWdbeMUnit;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQTrgList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubSysRefWdbeMSystem = Xmlio.extractStringUclc(doc, basexpath, "stubSysRefWdbeMSystem", "sys", null, 0);
			stubRefWdbeMUnit = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMUnit", "unt", null, 0);
			
			return true;
		};

		return false;
	};
};

