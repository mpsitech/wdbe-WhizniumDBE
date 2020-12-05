/**
	* \file WdbeQPrcList.h
	* Java API code for record of table TblWdbeQPrcList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQPrcList {
	
	public WdbeQPrcList(
				int jnum
				, String sref
				, String stubRefWdbeMModule
				, String yesnoFalling
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubRefWdbeMModule = stubRefWdbeMModule;
		this.yesnoFalling = yesnoFalling;
	};

	public int jnum;
	public String sref;
	public String stubRefWdbeMModule;
	public String yesnoFalling;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQPrcList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubRefWdbeMModule = Xmlio.extractStringUclc(doc, basexpath, "stubRefWdbeMModule", "mdl", null, 0);
			yesnoFalling = Xmlio.extractStringUclc(doc, basexpath, "yesnoFalling", "fal", null, 0);
			
			return true;
		};

		return false;
	};
};

