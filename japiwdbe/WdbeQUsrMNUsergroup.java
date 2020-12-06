/**
	* \file WdbeQUsrMNUsergroup.h
	* Java API code for record of table TblWdbeQUsrMNUsergroup
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQUsrMNUsergroup {
	
	public WdbeQUsrMNUsergroup(
				int jnum
				, String stubMref
				, String srefIxWdbeVUserlevel
				, String titIxWdbeVUserlevel
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.srefIxWdbeVUserlevel = srefIxWdbeVUserlevel;
		this.titIxWdbeVUserlevel = titIxWdbeVUserlevel;
	};

	public int jnum;
	public String stubMref;
	public String srefIxWdbeVUserlevel;
	public String titIxWdbeVUserlevel;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQUsrMNUsergroup");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			srefIxWdbeVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "srefIxWdbeVUserlevel", "ulv", null, 0);
			titIxWdbeVUserlevel = Xmlio.extractStringUclc(doc, basexpath, "titIxWdbeVUserlevel", "ulv2", null, 0);
			
			return true;
		};

		return false;
	};
};
