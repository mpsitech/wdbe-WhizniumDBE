/**
  * \file WdbeQModAPar.h
  * Java API code for record of table TblWdbeQModAPar
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQModAPar {
	
	public WdbeQModAPar(
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
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQModAPar");

		if (Xmlio.checkXPath(doc, basexpath)) {
			x1SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "x1SrefKKey", "key", null, 0);
			titX1SrefKKey = Xmlio.extractStringUclc(doc, basexpath, "titX1SrefKKey", "key2", null, 0);
			Val = Xmlio.extractStringUclc(doc, basexpath, "Val", "val", null, 0);
			
			return true;
		};

		return false;
	};
};

