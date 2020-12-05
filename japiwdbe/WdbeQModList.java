/**
	* \file WdbeQModList.h
	* Java API code for record of table TblWdbeQModList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQModList {
	
	public WdbeQModList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String srefHkIxVTbl
				, String titHkIxVTbl
				, String stubHkUref
				, String stubSupRefWdbeMModule
				, String stubTplRefWdbeMModule
				, String Srefrule
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.srefHkIxVTbl = srefHkIxVTbl;
		this.titHkIxVTbl = titHkIxVTbl;
		this.stubHkUref = stubHkUref;
		this.stubSupRefWdbeMModule = stubSupRefWdbeMModule;
		this.stubTplRefWdbeMModule = stubTplRefWdbeMModule;
		this.Srefrule = Srefrule;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String srefHkIxVTbl;
	public String titHkIxVTbl;
	public String stubHkUref;
	public String stubSupRefWdbeMModule;
	public String stubTplRefWdbeMModule;
	public String Srefrule;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQModList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			srefHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefHkIxVTbl", "hkt", null, 0);
			titHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titHkIxVTbl", "hkt2", null, 0);
			stubHkUref = Xmlio.extractStringUclc(doc, basexpath, "stubHkUref", "hku", null, 0);
			stubSupRefWdbeMModule = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWdbeMModule", "sup", null, 0);
			stubTplRefWdbeMModule = Xmlio.extractStringUclc(doc, basexpath, "stubTplRefWdbeMModule", "tpl", null, 0);
			Srefrule = Xmlio.extractStringUclc(doc, basexpath, "Srefrule", "srr", null, 0);
			
			return true;
		};

		return false;
	};
};

