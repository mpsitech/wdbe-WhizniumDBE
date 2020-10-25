/**
  * \file WdbeQUsrMNUsergroup.h
  * Java API code for record of table TblWdbeQUsrMNUsergroup
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

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

