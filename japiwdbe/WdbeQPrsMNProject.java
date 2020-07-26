/**
  * \file WdbeQPrsMNProject.h
  * Java API code for record of table TblWdbeQPrsMNProject
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPrsMNProject {
	
	public WdbeQPrsMNProject(
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
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPrsMNProject");

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

