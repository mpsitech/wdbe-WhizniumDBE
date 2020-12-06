/**
	* \file WdbeQCprMNPerson.h
	* Java API code for record of table TblWdbeQCprMNPerson
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQCprMNPerson {
	
	public WdbeQCprMNPerson(
				int jnum
				, String stubMref
				, String ftmX1Startd
				, String ftmX1Stopd
				, String srefKFunction
				, String titSrefKFunction
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.ftmX1Startd = ftmX1Startd;
		this.ftmX1Stopd = ftmX1Stopd;
		this.srefKFunction = srefKFunction;
		this.titSrefKFunction = titSrefKFunction;
	};

	public int jnum;
	public String stubMref;
	public String ftmX1Startd;
	public String ftmX1Stopd;
	public String srefKFunction;
	public String titSrefKFunction;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQCprMNPerson");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			ftmX1Startd = Xmlio.extractStringUclc(doc, basexpath, "ftmX1Startd", "sta", null, 0);
			ftmX1Stopd = Xmlio.extractStringUclc(doc, basexpath, "ftmX1Stopd", "sto", null, 0);
			srefKFunction = Xmlio.extractStringUclc(doc, basexpath, "srefKFunction", "fct", null, 0);
			titSrefKFunction = Xmlio.extractStringUclc(doc, basexpath, "titSrefKFunction", "fct2", null, 0);
			
			return true;
		};

		return false;
	};
};
