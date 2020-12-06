/**
	* \file WdbeQCmdList.h
	* Java API code for record of table TblWdbeQCmdList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQCmdList {
	
	public WdbeQCmdList(
				int jnum
				, String sref
				, String Fullsref
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
				, String srefIxVRettype
				, String titIxVRettype
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Fullsref = Fullsref;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
		this.srefIxVRettype = srefIxVRettype;
		this.titIxVRettype = titIxVRettype;
	};

	public int jnum;
	public String sref;
	public String Fullsref;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	public String srefIxVRettype;
	public String titIxVRettype;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQCmdList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Fullsref = Xmlio.extractStringUclc(doc, basexpath, "Fullsref", "fsr", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			srefIxVRettype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVRettype", "rty", null, 0);
			titIxVRettype = Xmlio.extractStringUclc(doc, basexpath, "titIxVRettype", "rty2", null, 0);
			
			return true;
		};

		return false;
	};
};
