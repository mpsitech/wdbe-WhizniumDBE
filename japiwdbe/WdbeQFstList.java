/**
  * \file WdbeQFstList.h
  * Java API code for record of table TblWdbeQFstList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

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

