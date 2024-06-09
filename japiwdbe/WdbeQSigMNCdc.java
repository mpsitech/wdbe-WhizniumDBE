/**
	* \file WdbeQSigMNCdc.java
	* Java API code for record of table TblWdbeQSigMNCdc
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 9 May 2023
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQSigMNCdc {
	
	public WdbeQSigMNCdc(
				int jnum
				, String stubMref
				, String srefIxVDir
				, String titIxVDir
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.srefIxVDir = srefIxVDir;
		this.titIxVDir = titIxVDir;
	};

	public int jnum;
	public String stubMref;
	public String srefIxVDir;
	public String titIxVDir;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQSigMNCdc");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			srefIxVDir = Xmlio.extractStringUclc(doc, basexpath, "srefIxVDir", "dir", null, 0);
			titIxVDir = Xmlio.extractStringUclc(doc, basexpath, "titIxVDir", "dir2", null, 0);
			
			return true;
		};

		return false;
	};
};
