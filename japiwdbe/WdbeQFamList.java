/**
	* \file WdbeQFamList.h
	* Java API code for record of table TblWdbeQFamList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQFamList {
	
	public WdbeQFamList(
				int jnum
				, String srefWdbeKVendor
				, String titSrefWdbeKVendor
				, String Title
			) {
		this.jnum = jnum;
		this.srefWdbeKVendor = srefWdbeKVendor;
		this.titSrefWdbeKVendor = titSrefWdbeKVendor;
		this.Title = Title;
	};

	public int jnum;
	public String srefWdbeKVendor;
	public String titSrefWdbeKVendor;
	public String Title;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQFamList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefWdbeKVendor = Xmlio.extractStringUclc(doc, basexpath, "srefWdbeKVendor", "vnd", null, 0);
			titSrefWdbeKVendor = Xmlio.extractStringUclc(doc, basexpath, "titSrefWdbeKVendor", "vnd2", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			
			return true;
		};

		return false;
	};
};
