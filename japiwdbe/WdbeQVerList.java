/**
	* \file WdbeQVerList.h
	* Java API code for record of table TblWdbeQVerList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQVerList {
	
	public WdbeQVerList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String stubRefWdbeMProject
				, int Major
				, int Minor
				, int Sub
				, String stubBvrRefWdbeMVersion
				, String srefIxVState
				, String titIxVState
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.stubRefWdbeMProject = stubRefWdbeMProject;
		this.Major = Major;
		this.Minor = Minor;
		this.Sub = Sub;
		this.stubBvrRefWdbeMVersion = stubBvrRefWdbeMVersion;
		this.srefIxVState = srefIxVState;
		this.titIxVState = titIxVState;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String stubRefWdbeMProject;
	public int Major;
	public int Minor;
	public int Sub;
	public String stubBvrRefWdbeMVersion;
	public String srefIxVState;
	public String titIxVState;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQVerList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			stubRefWdbeMProject = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMProject", "prj", null, 0);
			Major = Xmlio.extractIntegerUclc(doc, basexpath, "Major", "maj", null, 0);
			Minor = Xmlio.extractIntegerUclc(doc, basexpath, "Minor", "min", null, 0);
			Sub = Xmlio.extractIntegerUclc(doc, basexpath, "Sub", "sub", null, 0);
			stubBvrRefWdbeMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubBvrRefWdbeMVersion", "bvr", null, 0);
			srefIxVState = Xmlio.extractStringUclc(doc, basexpath, "srefIxVState", "ste", null, 0);
			titIxVState = Xmlio.extractStringUclc(doc, basexpath, "titIxVState", "ste2", null, 0);
			
			return true;
		};

		return false;
	};
};
