/**
	* \file WdbeQPrjList.h
	* Java API code for record of table TblWdbeQPrjList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPrjList {
	
	public WdbeQPrjList(
				int jnum
				, String stubGrp
				, String stubOwn
				, String Short
				, String Title
				, String stubRefWdbeMVersion
				, String yesnoEasy
				, String Giturl
			) {
		this.jnum = jnum;
		this.stubGrp = stubGrp;
		this.stubOwn = stubOwn;
		this.Short = Short;
		this.Title = Title;
		this.stubRefWdbeMVersion = stubRefWdbeMVersion;
		this.yesnoEasy = yesnoEasy;
		this.Giturl = Giturl;
	};

	public int jnum;
	public String stubGrp;
	public String stubOwn;
	public String Short;
	public String Title;
	public String stubRefWdbeMVersion;
	public String yesnoEasy;
	public String Giturl;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPrjList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubGrp = Xmlio.extractStringUclc(doc, basexpath, "stubGrp", "grp", null, 0);
			stubOwn = Xmlio.extractStringUclc(doc, basexpath, "stubOwn", "own", null, 0);
			Short = Xmlio.extractStringUclc(doc, basexpath, "Short", "sho", null, 0);
			Title = Xmlio.extractStringUclc(doc, basexpath, "Title", "tit", null, 0);
			stubRefWdbeMVersion = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMVersion", "ver", null, 0);
			yesnoEasy = Xmlio.extractStringUclc(doc, basexpath, "yesnoEasy", "esy", null, 0);
			Giturl = Xmlio.extractStringUclc(doc, basexpath, "Giturl", "grl", null, 0);
			
			return true;
		};

		return false;
	};
};
