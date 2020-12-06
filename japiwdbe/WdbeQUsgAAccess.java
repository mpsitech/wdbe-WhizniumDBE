/**
	* \file WdbeQUsgAAccess.h
	* Java API code for record of table TblWdbeQUsgAAccess
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQUsgAAccess {
	
	public WdbeQUsgAAccess(
				int jnum
				, String srefX1IxWdbeVFeatgroup
				, String titX1IxWdbeVFeatgroup
				, String x2FeaSrefUix
				, String srefsIxWdbeWAccess
				, String titsIxWdbeWAccess
			) {
		this.jnum = jnum;
		this.srefX1IxWdbeVFeatgroup = srefX1IxWdbeVFeatgroup;
		this.titX1IxWdbeVFeatgroup = titX1IxWdbeVFeatgroup;
		this.x2FeaSrefUix = x2FeaSrefUix;
		this.srefsIxWdbeWAccess = srefsIxWdbeWAccess;
		this.titsIxWdbeWAccess = titsIxWdbeWAccess;
	};

	public int jnum;
	public String srefX1IxWdbeVFeatgroup;
	public String titX1IxWdbeVFeatgroup;
	public String x2FeaSrefUix;
	public String srefsIxWdbeWAccess;
	public String titsIxWdbeWAccess;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQUsgAAccess");

		if (Xmlio.checkXPath(doc, basexpath)) {
			srefX1IxWdbeVFeatgroup = Xmlio.extractStringUclc(doc, basexpath, "srefX1IxWdbeVFeatgroup", "feg", null, 0);
			titX1IxWdbeVFeatgroup = Xmlio.extractStringUclc(doc, basexpath, "titX1IxWdbeVFeatgroup", "feg2", null, 0);
			x2FeaSrefUix = Xmlio.extractStringUclc(doc, basexpath, "x2FeaSrefUix", "fea", null, 0);
			srefsIxWdbeWAccess = Xmlio.extractStringUclc(doc, basexpath, "srefsIxWdbeWAccess", "acc", null, 0);
			titsIxWdbeWAccess = Xmlio.extractStringUclc(doc, basexpath, "titsIxWdbeWAccess", "acc2", null, 0);
			
			return true;
		};

		return false;
	};
};
