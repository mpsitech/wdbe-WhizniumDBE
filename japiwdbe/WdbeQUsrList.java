/**
  * \file WdbeQUsrList.h
  * Java API code for record of table TblWdbeQUsrList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQUsrList {
	
	public WdbeQUsrList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String stubRefWdbeMPerson
				, String sref
				, String stubRefWdbeMUsergroup
				, String srefIxVState
				, String titIxVState
				, String srefIxWdbeVLocale
				, String titIxWdbeVLocale
				, String srefIxWdbeVUserlevel
				, String titIxWdbeVUserlevel
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.stubRefWdbeMPerson = stubRefWdbeMPerson;
		this.sref = sref;
		this.stubRefWdbeMUsergroup = stubRefWdbeMUsergroup;
		this.srefIxVState = srefIxVState;
		this.titIxVState = titIxVState;
		this.srefIxWdbeVLocale = srefIxWdbeVLocale;
		this.titIxWdbeVLocale = titIxWdbeVLocale;
		this.srefIxWdbeVUserlevel = srefIxWdbeVUserlevel;
		this.titIxWdbeVUserlevel = titIxWdbeVUserlevel;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String stubRefWdbeMPerson;
	public String sref;
	public String stubRefWdbeMUsergroup;
	public String srefIxVState;
	public String titIxVState;
	public String srefIxWdbeVLocale;
	public String titIxWdbeVLocale;
	public String srefIxWdbeVUserlevel;
	public String titIxWdbeVUserlevel;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQUsrList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			stubRefWdbeMPerson = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMPerson", "prs", null, 0);
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWdbeMUsergroup = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMUsergroup", "usg", null, 0);
			srefIxVState = Xmlio.extractStringUclc(doc, basexpath, "srefIxVState", "ste", null, 0);
			titIxVState = Xmlio.extractStringUclc(doc, basexpath, "titIxVState", "ste2", null, 0);
			srefIxWdbeVLocale = Xmlio.extractStringUclc(doc, basexpath, "srefIxWdbeVLocale", "lcl", null, 0);
			titIxWdbeVLocale = Xmlio.extractStringUclc(doc, basexpath, "titIxWdbeVLocale", "lcl2", null, 0);
			srefIxWdbeVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "srefIxWdbeVUserlevel", "ulv", null, 0);
			titIxWdbeVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "titIxWdbeVUserlevel", "ulv2", null, 0);
			
			return true;
		};

		return false;
	};
};

