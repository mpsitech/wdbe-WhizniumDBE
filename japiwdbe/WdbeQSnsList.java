/**
	* \file WdbeQSnsList.h
	* Java API code for record of table TblWdbeQSnsList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQSnsList {
	
	public WdbeQSnsList(
				int jnum
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
				, String srefSrcIxVTbl
				, String titSrcIxVTbl
				, String stubSrcUref
			) {
		this.jnum = jnum;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
		this.srefSrcIxVTbl = srefSrcIxVTbl;
		this.titSrcIxVTbl = titSrcIxVTbl;
		this.stubSrcUref = stubSrcUref;
	};

	public int jnum;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	public String srefSrcIxVTbl;
	public String titSrcIxVTbl;
	public String stubSrcUref;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQSnsList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			srefSrcIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefSrcIxVTbl", "srt", null, 0);
			titSrcIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titSrcIxVTbl", "srt2", null, 0);
			stubSrcUref = Xmlio.extractStringUclc(doc, basexpath, "stubSrcUref", "sru", null, 0);
			
			return true;
		};

		return false;
	};
};
