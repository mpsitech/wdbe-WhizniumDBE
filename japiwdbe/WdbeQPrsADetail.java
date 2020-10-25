/**
  * \file WdbeQPrsADetail.h
  * Java API code for record of table TblWdbeQPrsADetail
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPrsADetail {
	
	public WdbeQPrsADetail(
				int jnum
				, String x1SrefKType
				, String titX1SrefKType
				, String Val
			) {
		this.jnum = jnum;
		this.x1SrefKType = x1SrefKType;
		this.titX1SrefKType = titX1SrefKType;
		this.Val = Val;
	};

	public int jnum;
	public String x1SrefKType;
	public String titX1SrefKType;
	public String Val;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPrsADetail");

		if (Xmlio.checkXPath(doc, basexpath)) {
			x1SrefKType = Xmlio.extractStringUclc(doc, basexpath, "x1SrefKType", "typ", null, 0);
			titX1SrefKType = Xmlio.extractStringUclc(doc, basexpath, "titX1SrefKType", "typ2", null, 0);
			Val = Xmlio.extractStringUclc(doc, basexpath, "Val", "val", null, 0);
			
			return true;
		};

		return false;
	};
};

