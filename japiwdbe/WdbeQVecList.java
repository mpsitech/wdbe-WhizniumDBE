/**
  * \file WdbeQVecList.h
  * Java API code for record of table TblWdbeQVecList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQVecList {
	
	public WdbeQVecList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String srefHkIxVTbl
				, String titHkIxVTbl
				, String stubHkUref
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.srefHkIxVTbl = srefHkIxVTbl;
		this.titHkIxVTbl = titHkIxVTbl;
		this.stubHkUref = stubHkUref;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String srefHkIxVTbl;
	public String titHkIxVTbl;
	public String stubHkUref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQVecList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			srefHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefHkIxVTbl", "hkt", null, 0);
			titHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titHkIxVTbl", "hkt2", null, 0);
			stubHkUref = Xmlio.extractStringUclc(doc, basexpath, "stubHkUref", "hku", null, 0);
			
			return true;
		};

		return false;
	};
};

