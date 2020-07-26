/**
  * \file WdbeQVitList.h
  * Java API code for record of table TblWdbeQVitList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQVitList {
	
	public WdbeQVitList(
				int jnum
				, String sref
				, String Title
				, String stubVecRefWdbeMVector
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.stubVecRefWdbeMVector = stubVecRefWdbeMVector;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String stubVecRefWdbeMVector;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQVitList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubVecRefWdbeMVector = Xmlio.extractStringUclc(doc, basexpath, "stubVecRefWdbeMVector", "vec", null, 0);
			
			return true;
		};

		return false;
	};
};

