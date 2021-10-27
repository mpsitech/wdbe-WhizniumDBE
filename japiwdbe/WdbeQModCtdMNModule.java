/**
	* \file WdbeQModCtdMNModule.h
	* Java API code for record of table TblWdbeQModCtdMNModule
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 Oct 2021
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQModCtdMNModule {
	
	public WdbeQModCtdMNModule(
				int jnum
				, String stubMref
				, String srefKFunction
				, String titSrefKFunction
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.srefKFunction = srefKFunction;
		this.titSrefKFunction = titSrefKFunction;
	};

	public int jnum;
	public String stubMref;
	public String srefKFunction;
	public String titSrefKFunction;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQModCtdMNModule");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			srefKFunction = Xmlio.extractStringUclc(doc, basexpath, "srefKFunction", "fct", null, 0);
			titSrefKFunction = Xmlio.extractStringUclc(doc, basexpath, "titSrefKFunction", "fct2", null, 0);
			
			return true;
		};

		return false;
	};
};
