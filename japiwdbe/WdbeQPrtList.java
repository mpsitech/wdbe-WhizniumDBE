/**
  * \file WdbeQPrtList.h
  * Java API code for record of table TblWdbeQPrtList
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPrtList {
	
	public WdbeQPrtList(
				int jnum
				, String sref
				, String stubMdlRefWdbeMModule
				, String srefMdlIxVCat
				, String titMdlIxVCat
				, String srefIxVDir
				, String titIxVDir
				, String srefWdbeKHdltype
				, String titSrefWdbeKHdltype
				, int Width
				, String Minmax
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubMdlRefWdbeMModule = stubMdlRefWdbeMModule;
		this.srefMdlIxVCat = srefMdlIxVCat;
		this.titMdlIxVCat = titMdlIxVCat;
		this.srefIxVDir = srefIxVDir;
		this.titIxVDir = titIxVDir;
		this.srefWdbeKHdltype = srefWdbeKHdltype;
		this.titSrefWdbeKHdltype = titSrefWdbeKHdltype;
		this.Width = Width;
		this.Minmax = Minmax;
	};

	public int jnum;
	public String sref;
	public String stubMdlRefWdbeMModule;
	public String srefMdlIxVCat;
	public String titMdlIxVCat;
	public String srefIxVDir;
	public String titIxVDir;
	public String srefWdbeKHdltype;
	public String titSrefWdbeKHdltype;
	public int Width;
	public String Minmax;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPrtList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubMdlRefWdbeMModule = Xmlio.extractStringUclc(doc, basexpath, "stubMdlRefWdbeMModule", "mdl", null, 0);
			srefMdlIxVCat = Xmlio.extractStringUclc(doc, basexpath, "srefMdlIxVCat", "mdc", null, 0);
			titMdlIxVCat = Xmlio.extractStringUclc(doc, basexpath, "titMdlIxVCat", "mdc2", null, 0);
			srefIxVDir = Xmlio.extractStringUclc(doc, basexpath, "srefIxVDir", "dir", null, 0);
			titIxVDir = Xmlio.extractStringUclc(doc, basexpath, "titIxVDir", "dir2", null, 0);
			srefWdbeKHdltype = Xmlio.extractStringUclc(doc, basexpath, "srefWdbeKHdltype", "hty", null, 0);
			titSrefWdbeKHdltype = Xmlio.extractStringUclc(doc, basexpath, "titSrefWdbeKHdltype", "hty2", null, 0);
			Width = Xmlio.extractIntegerUclc(doc, basexpath, "Width", "wid", null, 0);
			Minmax = Xmlio.extractStringUclc(doc, basexpath, "Minmax", "mmx", null, 0);
			
			return true;
		};

		return false;
	};
};

