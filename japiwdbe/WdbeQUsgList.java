/**
  * \file WdbeQUsgList.h
  * Java API code for record of table TblWdbeQUsgList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQUsgList {
	
	public WdbeQUsgList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String sref
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.sref = sref;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String sref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQUsgList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			
			return true;
		};

		return false;
	};
};

