/**
	* \file WdbeQVarList.h
	* Java API code for record of table TblWdbeQVarList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQVarList {
	
	public WdbeQVarList(
				int jnum
				, String sref
				, String stubPrcRefWdbeMProcess
				, String yesnoConst
				, String yesnoFalling
				, String srefWdbeKHdltype
				, String titSrefWdbeKHdltype
				, int Width
				, String Minmax
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubPrcRefWdbeMProcess = stubPrcRefWdbeMProcess;
		this.yesnoConst = yesnoConst;
		this.yesnoFalling = yesnoFalling;
		this.srefWdbeKHdltype = srefWdbeKHdltype;
		this.titSrefWdbeKHdltype = titSrefWdbeKHdltype;
		this.Width = Width;
		this.Minmax = Minmax;
	};

	public int jnum;
	public String sref;
	public String stubPrcRefWdbeMProcess;
	public String yesnoConst;
	public String yesnoFalling;
	public String srefWdbeKHdltype;
	public String titSrefWdbeKHdltype;
	public int Width;
	public String Minmax;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQVarList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubPrcRefWdbeMProcess = Xmlio.extractStringUclc(doc, basexpath, "stubPrcRefWdbeMProcess", "prc", null, 0);
			yesnoConst = Xmlio.extractStringUclc(doc, basexpath, "yesnoConst", "con", null, 0);
			yesnoFalling = Xmlio.extractStringUclc(doc, basexpath, "yesnoFalling", "fal", null, 0);
			srefWdbeKHdltype = Xmlio.extractStringUclc(doc, basexpath, "srefWdbeKHdltype", "hty", null, 0);
			titSrefWdbeKHdltype = Xmlio.extractStringUclc(doc, basexpath, "titSrefWdbeKHdltype", "hty2", null, 0);
			Width = Xmlio.extractIntegerUclc(doc, basexpath, "Width", "wid", null, 0);
			Minmax = Xmlio.extractStringUclc(doc, basexpath, "Minmax", "mmx", null, 0);
			
			return true;
		};

		return false;
	};
};
