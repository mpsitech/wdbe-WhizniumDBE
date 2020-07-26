/**
  * \file WdbeQCvrList.h
  * Java API code for record of table TblWdbeQCvrList
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQCvrList {
	
	public WdbeQCvrList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String stubRefWdbeMCoreproject
				, int Major
				, int Minor
				, int Sub
				, String stubBcvRefWdbeMCoreversion
				, String srefIxVState
				, String titIxVState
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.stubRefWdbeMCoreproject = stubRefWdbeMCoreproject;
		this.Major = Major;
		this.Minor = Minor;
		this.Sub = Sub;
		this.stubBcvRefWdbeMCoreversion = stubBcvRefWdbeMCoreversion;
		this.srefIxVState = srefIxVState;
		this.titIxVState = titIxVState;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String stubRefWdbeMCoreproject;
	public int Major;
	public int Minor;
	public int Sub;
	public String stubBcvRefWdbeMCoreversion;
	public String srefIxVState;
	public String titIxVState;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQCvrList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			stubRefWdbeMCoreproject = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMCoreproject", "cpr", null, 0);
			Major = Xmlio.extractIntegerUclc(doc, basexpath, "Major", "maj", null, 0);
			Minor = Xmlio.extractIntegerUclc(doc, basexpath, "Minor", "min", null, 0);
			Sub = Xmlio.extractIntegerUclc(doc, basexpath, "Sub", "sub", null, 0);
			stubBcvRefWdbeMCoreversion = Xmlio.extractStringUclc(doc, basexpath, "stubBcvRefWdbeMCoreversion", "bcv", null, 0);
			srefIxVState = Xmlio.extractStringUclc(doc, basexpath, "srefIxVState", "ste", null, 0);
			titIxVState = Xmlio.extractStringUclc(doc, basexpath, "titIxVState", "ste2", null, 0);
			
			return true;
		};

		return false;
	};
};

