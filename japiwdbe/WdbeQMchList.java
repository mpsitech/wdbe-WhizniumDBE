/**
  * \file WdbeQMchList.h
  * Java API code for record of table TblWdbeQMchList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQMchList {
	
	public WdbeQMchList(
				int jnum
				, String sref
				, String srefKPlatform
				, String titSrefKPlatform
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefKPlatform = srefKPlatform;
		this.titSrefKPlatform = titSrefKPlatform;
	};

	public int jnum;
	public String sref;
	public String srefKPlatform;
	public String titSrefKPlatform;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQMchList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefKPlatform = Xmlio.extractStringUclc(doc, basexpath, "srefKPlatform", "pla", null, 0);
			titSrefKPlatform = Xmlio.extractStringUclc(doc, basexpath, "titSrefKPlatform", "pla2", null, 0);
			
			return true;
		};

		return false;
	};
};

