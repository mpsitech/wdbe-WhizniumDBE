/**
  * \file WdbeQGenList.h
  * Java API code for record of table TblWdbeQGenList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQGenList {
	
	public WdbeQGenList(
				int jnum
				, String sref
				, String stubMdlRefWdbeMModule
				, String srefWdbeKHdltype
				, String titSrefWdbeKHdltype
				, int Width
				, String Minmax
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubMdlRefWdbeMModule = stubMdlRefWdbeMModule;
		this.srefWdbeKHdltype = srefWdbeKHdltype;
		this.titSrefWdbeKHdltype = titSrefWdbeKHdltype;
		this.Width = Width;
		this.Minmax = Minmax;
	};

	public int jnum;
	public String sref;
	public String stubMdlRefWdbeMModule;
	public String srefWdbeKHdltype;
	public String titSrefWdbeKHdltype;
	public int Width;
	public String Minmax;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQGenList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubMdlRefWdbeMModule = Xmlio.extractStringUclc(doc, basexpath, "stubMdlRefWdbeMModule", "mdl", null, 0);
			srefWdbeKHdltype = Xmlio.extractStringUclc(doc, basexpath, "srefWdbeKHdltype", "hty", null, 0);
			titSrefWdbeKHdltype = Xmlio.extractStringUclc(doc, basexpath, "titSrefWdbeKHdltype", "hty2", null, 0);
			Width = Xmlio.extractIntegerUclc(doc, basexpath, "Width", "wid", null, 0);
			Minmax = Xmlio.extractStringUclc(doc, basexpath, "Minmax", "mmx", null, 0);
			
			return true;
		};

		return false;
	};
};

