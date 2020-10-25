/**
  * \file WdbeQPinList.h
  * Java API code for record of table TblWdbeQPinList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPinList {
	
	public WdbeQPinList(
				int jnum
				, String sref
				, String stubRefWdbeMBank
				, String Location
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWdbeMBank = stubRefWdbeMBank;
		this.Location = Location;
	};

	public int jnum;
	public String sref;
	public String stubRefWdbeMBank;
	public String Location;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPinList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWdbeMBank = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMBank", "bnk", null, 0);
			Location = Xmlio.extractStringUclc(doc, basexpath, "Location", "loc", null, 0);
			
			return true;
		};

		return false;
	};
};

