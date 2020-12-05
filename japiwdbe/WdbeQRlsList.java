/**
	* \file WdbeQRlsList.h
	* Java API code for record of table TblWdbeQRlsList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQRlsList {
	
	public WdbeQRlsList(
				int jnum
				, String sref
				, String srefIxVBasetype
				, String titIxVBasetype
				, String stubRefWdbeMVersion
				, String stubRefWdbeMMachine
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.srefIxVBasetype = srefIxVBasetype;
		this.titIxVBasetype = titIxVBasetype;
		this.stubRefWdbeMVersion = stubRefWdbeMVersion;
		this.stubRefWdbeMMachine = stubRefWdbeMMachine;
	};

	public int jnum;
	public String sref;
	public String srefIxVBasetype;
	public String titIxVBasetype;
	public String stubRefWdbeMVersion;
	public String stubRefWdbeMMachine;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQRlsList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			srefIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "srefIxVBasetype", "typ", null, 0);
			titIxVBasetype = Xmlio.extractStringUclc(doc, basexpath, "titIxVBasetype", "typ2", null, 0);
			stubRefWdbeMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMVersion", "ver", null, 0);
			stubRefWdbeMMachine = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMMachine", "mch", null, 0);
			
			return true;
		};

		return false;
	};
};

