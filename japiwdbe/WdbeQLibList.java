/**
	* \file WdbeQLibList.h
	* Java API code for record of table TblWdbeQLibList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQLibList {
	
	public WdbeQLibList(
				int jnum
				, String sref
				, String Title
				, String Version
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.Version = Version;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String Version;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQLibList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			Version = Xmlio.extractStringUclc(doc, basexpath, "Version", "ver", null, 0);
			
			return true;
		};

		return false;
	};
};

