/**
  * \file WdbeQFamList.h
  * Java API code for record of table TblWdbeQFamList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQFamList {
	
	public WdbeQFamList(
				int jnum
				, String srefKVendor
				, String titSrefKVendor
				, String Title
			) {
		this.jnum = jnum;
		this.srefKVendor = srefKVendor;
		this.titSrefKVendor = titSrefKVendor;
		this.Title = Title;
	};

	public int jnum;
	public String srefKVendor;
	public String titSrefKVendor;
	public String Title;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQFamList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefKVendor = Xmlio.extractStringUclc(doc, basexpath, "srefKVendor", "vnd", null, 0);
			titSrefKVendor = Xmlio.extractStringUclc(doc, basexpath, "titSrefKVendor", "vnd2", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			
			return true;
		};

		return false;
	};
};

