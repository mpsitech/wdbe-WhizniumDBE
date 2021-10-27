/**
	* \file WdbeQMtpList.h
	* Java API code for record of table TblWdbeQMtpList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQMtpList {
	
	public WdbeQMtpList(
				int jnum
				, String sref
				, String srefWdbeKVendor
				, String titSrefWdbeKVendor
				, String srefIxVBasetype
				, String titIxVBasetype
				, String srefHkIxVTbl
				, String titHkIxVTbl
				, String stubHkUref
				, String Srefrule
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefWdbeKVendor = srefWdbeKVendor;
		this.titSrefWdbeKVendor = titSrefWdbeKVendor;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.srefHkIxVTbl = srefHkIxVTbl;
		this.titHkIxVTbl = titHkIxVTbl;
		this.stubHkUref = stubHkUref;
		this.Srefrule = Srefrule;
	};

	public int jnum;
	public String sref;
	public String srefWdbeKVendor;
	public String titSrefWdbeKVendor;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String srefHkIxVTbl;
	public String titHkIxVTbl;
	public String stubHkUref;
	public String Srefrule;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQMtpList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefWdbeKVendor = Xmlio.extractStringUclc(doc, basexpath, "srefWdbeKVendor", "vnd", null, 0);
			titSrefWdbeKVendor = Xmlio.extractStringUclc(doc, basexpath, "titSrefWdbeKVendor", "vnd2", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			srefHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefHkIxVTbl", "hkt", null, 0);
			titHkIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titHkIxVTbl", "hkt2", null, 0);
			stubHkUref = Xmlio.extractStringUclc(doc, basexpath, "stubHkUref", "hku", null, 0);
			Srefrule = Xmlio.extractStringUclc(doc, basexpath, "Srefrule", "srr", null, 0);
			
			return true;
		};

		return false;
	};
};
