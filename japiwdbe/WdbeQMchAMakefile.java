/**
	* \file WdbeQMchAMakefile.h
	* Java API code for record of table TblWdbeQMchAMakefile
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQMchAMakefile {
	
	public WdbeQMchAMakefile(
				int jnum
				, String x1SrefKTag
				, String titX1SrefKTag
				, String Val
			) {
		this.jnum = jnum;
		this.x1SrefKTag = x1SrefKTag;
		this.titX1SrefKTag = titX1SrefKTag;
		this.Val = Val;
	};

	public int jnum;
	public String x1SrefKTag;
	public String titX1SrefKTag;
	public String Val;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQMchAMakefile");

		if (Xmlio.checkXPath(doc, basexpath)) {
			x1SrefKTag = Xmlio.extractStringUclc(doc, basexpath, "x1SrefKTag", "tag", null, 0);
			titX1SrefKTag = Xmlio.extractStringUclc(doc, basexpath, "titX1SrefKTag", "tag2", null, 0);
			Val = Xmlio.extractStringUclc(doc, basexpath, "Val", "val", null, 0);
			
			return true;
		};

		return false;
	};
};
