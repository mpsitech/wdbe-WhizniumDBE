/**
  * \file WdbeQCmdMNController.h
  * Java API code for record of table TblWdbeQCmdMNController
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQCmdMNController {
	
	public WdbeQCmdMNController(
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
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQCmdMNController");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubMref = Xmlio.extractStringUclc(doc, basexpath, "stubMref", "mref", null, 0);
			stubIvrRefWdbeMSignal = Xmlio.extractStringUclc(doc, basexpath, "stubIvrRefWdbeMSignal", "ivr", null, 0);
			stubRvrRefWdbeMSignal = Xmlio.extractStringUclc(doc, basexpath, "stubRvrRefWdbeMSignal", "rvr", null, 0);
			
			return true;
		};

		return false;
	};
};

