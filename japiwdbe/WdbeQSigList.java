/**
	* \file WdbeQSigList.h
	* Java API code for record of table TblWdbeQSigList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQSigList {
	
	public WdbeQSigList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
				, String srefMgeIxVTbl
				, String titMgeIxVTbl
				, String stubMgeUref
				, String stubRefWdbeMVector
				, String yesnoConst
				, String srefWdbeKHdltype
				, String titSrefWdbeKHdltype
				, int Width
				, String Minmax
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
		this.srefMgeIxVTbl = srefMgeIxVTbl;
		this.titMgeIxVTbl = titMgeIxVTbl;
		this.stubMgeUref = stubMgeUref;
		this.stubRefWdbeMVector = stubRefWdbeMVector;
		this.yesnoConst = yesnoConst;
		this.srefWdbeKHdltype = srefWdbeKHdltype;
		this.titSrefWdbeKHdltype = titSrefWdbeKHdltype;
		this.Width = Width;
		this.Minmax = Minmax;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	public String srefMgeIxVTbl;
	public String titMgeIxVTbl;
	public String stubMgeUref;
	public String stubRefWdbeMVector;
	public String yesnoConst;
	public String srefWdbeKHdltype;
	public String titSrefWdbeKHdltype;
	public int Width;
	public String Minmax;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQSigList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			srefMgeIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefMgeIxVTbl", "mgt", null, 0);
			titMgeIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titMgeIxVTbl", "mgt2", null, 0);
			stubMgeUref = Xmlio.extractStringUclc(doc, basexpath, "stubMgeUref", "mgu", null, 0);
			stubRefWdbeMVector = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMVector", "vec", null, 0);
			yesnoConst = Xmlio.extractStringUclc(doc, basexpath, "yesnoConst", "con", null, 0);
			srefWdbeKHdltype = Xmlio.extractStringUclc(doc, basexpath, "srefWdbeKHdltype", "hty", null, 0);
			titSrefWdbeKHdltype = Xmlio.extractStringUclc(doc, basexpath, "titSrefWdbeKHdltype", "hty2", null, 0);
			Width = Xmlio.extractIntegerUclc(doc, basexpath, "Width", "wid", null, 0);
			Minmax = Xmlio.extractStringUclc(doc, basexpath, "Minmax", "mmx", null, 0);
			
			return true;
		};

		return false;
	};
};
