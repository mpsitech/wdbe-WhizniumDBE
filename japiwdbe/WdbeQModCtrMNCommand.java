/**
	* \file WdbeQModCtrMNCommand.h
	* Java API code for record of table TblWdbeQModCtrMNCommand
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQModCtrMNCommand {
	
	public WdbeQModCtrMNCommand(
				int jnum
				, String stubMref
				, String stubIvrRefWdbeMSignal
				, String stubRvrRefWdbeMSignal
			) {
		this.jnum = jnum;
		this.stubMref = stubMref;
		this.stubIvrRefWdbeMSignal = stubIvrRefWdbeMSignal;
		this.stubRvrRefWdbeMSignal = stubRvrRefWdbeMSignal;
	};

	public int jnum;
	public String stubMref;
	public String stubIvrRefWdbeMSignal;
	public String stubRvrRefWdbeMSignal;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQModCtrMNCommand");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			stubIvrRefWdbeMSignal = Xmlio.extractStringUclc(doc, basexpath, "stubIvrRefWdbeMSignal", "ivr", null, 0);
			stubRvrRefWdbeMSignal = Xmlio.extractStringUclc(doc, basexpath, "stubRvrRefWdbeMSignal", "rvr", null, 0);
			
			return true;
		};

		return false;
	};
};
