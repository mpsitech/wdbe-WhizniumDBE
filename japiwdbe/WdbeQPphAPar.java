/**
	* \file WdbeQPphAPar.h
	* Java API code for record of table TblWdbeQPphAPar
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPphAPar {
	
	public WdbeQPphAPar(
				int jnum
				, String x1SrefKKey
				, String titX1SrefKKey
				, String Val
			) {
		this.jnum = jnum;
		this.x1SrefKKey = x1SrefKKey;
		this.titX1SrefKKey = titX1SrefKKey;
		this.Val = Val;
	};

	public int jnum;
	public String x1SrefKKey;
	public String titX1SrefKKey;
	public String Val;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPphAPar");

		if (Xmlio.checkXPath(doc, basexpath)) {
			x1SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "x1SrefKKey", "key", null, 0);
			titX1SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "titX1SrefKKey", "key2", null, 0);
			Val = Xmlio.extractStringUclc(doc, basexpath, "Val", "val", null, 0);
			
			return true;
		};

		return false;
	};
};
