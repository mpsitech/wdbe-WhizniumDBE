/**
  * \file WdbeQCprList.h
  * Java API code for record of table TblWdbeQCprList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQCprList {
	
	public WdbeQCprList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String sref
				, String Title
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWdbeMCoreversion
				, String Giturl
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.sref = sref;
		this.Title = Title;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWdbeMCoreversion = stubRefWdbeMCoreversion;
		this.Giturl = Giturl;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String sref;
	public String Title;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWdbeMCoreversion;
	public String Giturl;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQCprList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWdbeMCoreversion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMCoreversion", "cvr", null, 0);
			Giturl = Xmlio.extractStringUclc(doc, basexpath, "Giturl", "grl", null, 0);
			
			return true;
		};

		return false;
	};
};

