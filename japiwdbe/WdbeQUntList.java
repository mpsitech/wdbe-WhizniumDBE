/**
  * \file WdbeQUntList.h
  * Java API code for record of table TblWdbeQUntList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQUntList {
	
	public WdbeQUntList(
				int jnum
				, String sref
				, String Title
				, String Fullsref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String srefRefIxVTbl
				, String titRefIxVTbl
				, String stubRefUref
				, String stubRefWdbeMSystem
				, String stubRefWdbeMModule
				, String srefKPackage
				, String titSrefKPackage
				, String yesnoEasy
				, String srefKToolch
				, String titSrefKToolch
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.Title = Title;
		this.Fullsref = Fullsref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.srefRefIxVTbl = srefRefIxVTbl;
		this.titRefIxVTbl = titRefIxVTbl;
		this.stubRefUref = stubRefUref;
		this.stubRefWdbeMSystem = stubRefWdbeMSystem;
		this.stubRefWdbeMModule = stubRefWdbeMModule;
		this.srefKPackage = srefKPackage;
		this.titSrefKPackage = titSrefKPackage;
		this.yesnoEasy = yesnoEasy;
		this.srefKToolch = srefKToolch;
		this.titSrefKToolch = titSrefKToolch;
	};

	public int jnum;
	public String sref;
	public String Title;
	public String Fullsref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String srefRefIxVTbl;
	public String titRefIxVTbl;
	public String stubRefUref;
	public String stubRefWdbeMSystem;
	public String stubRefWdbeMModule;
	public String srefKPackage;
	public String titSrefKPackage;
	public String yesnoEasy;
	public String srefKToolch;
	public String titSrefKToolch;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQUntList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			Fullsref = Xmlio.extractStringUclc(doc, basexpath, "Fullsref", "fsr", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			srefRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "srefRefIxVTbl", "ret", null, 0);
			titRefIxVTbl = Xmlio.extractStringUclc(doc, basexpath, "titRefIxVTbl", "ret2", null, 0);
			stubRefUref = Xmlio.extractStringUclc(doc, basexpath, "stubRefUref", "reu", null, 0);
			stubRefWdbeMSystem = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMSystem", "sys", null, 0);
			stubRefWdbeMModule = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMModule", "mdl", null, 0);
			srefKPackage = Xmlio.extractStringUclc(doc, basexpath, "srefKPackage", "pkg", null, 0);
			titSrefKPackage = Xmlio.extractStringUclc(doc, basexpath, "titSrefKPackage", "pkg2", null, 0);
			yesnoEasy = Xmlio.extractStringUclc(doc, basexpath, "yesnoEasy", "esy", null, 0);
			srefKToolch = Xmlio.extractStringUclc(doc, basexpath, "srefKToolch", "tch", null, 0);
			titSrefKToolch = Xmlio.extractStringUclc(doc, basexpath, "titSrefKToolch", "tch2", null, 0);
			
			return true;
		};

		return false;
	};
};

