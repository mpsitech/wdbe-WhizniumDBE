/**
	* \file WdbeQSegList.h
	* Java API code for record of table TblWdbeQSegList
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQSegList {
	
	public WdbeQSegList(
				int jnum
				, String sref
				, String stubPplRefWdbeMPipeline
				, String stubSupRefWdbeMSegment
				, String Infmt
				, String Outfmt
				, int Latency
			) {
		this.jnum = jnum;
		this.sref = sref;
		this.stubPplRefWdbeMPipeline = stubPplRefWdbeMPipeline;
		this.stubSupRefWdbeMSegment = stubSupRefWdbeMSegment;
		this.Infmt = Infmt;
		this.Outfmt = Outfmt;
		this.Latency = Latency;
	};

	public int jnum;
	public String sref;
	public String stubPplRefWdbeMPipeline;
	public String stubSupRefWdbeMSegment;
	public String Infmt;
	public String Outfmt;
	public int Latency;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQSegList");

		if (Xmlio.checkXPath(doc, basexpath)) {
			sref = Xmlio.extractStringUclc(doc, basexpath, "sref", "srf", null, 0);
			stubPplRefWdbeMPipeline = Xmlio.extractStringUclc(doc, basexpath, "stubPplRefWdbeMPipeline", "ppl", null, 0);
			stubSupRefWdbeMSegment = Xmlio.extractStringUclc(doc, basexpath, "stubSupRefWdbeMSegment", "sup", null, 0);
			Infmt = Xmlio.extractStringUclc(doc, basexpath, "Infmt", "ifm", null, 0);
			Outfmt = Xmlio.extractStringUclc(doc, basexpath, "Outfmt", "ofm", null, 0);
			Latency = Xmlio.extractIntegerUclc(doc, basexpath, "Latency", "lcy", null, 0);
			
			return true;
		};

		return false;
	};
};
