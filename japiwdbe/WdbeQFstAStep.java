/**
	* \file WdbeQFstAStep.h
	* Java API code for record of table TblWdbeQFstAStep
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

package apiwdbe;

import org.w3c.dom.*;
import sbecore.*;

public class WdbeQFstAStep {
	
	public WdbeQFstAStep(
				int jnum
				, String stubFnxRefWdbeMFsmstate
				, String Cond1
				, String Ip1
				, String Cond2
				, String Ip2
				, String Cond3
				, String Ip3
				, String Cond4
				, String Ip4
				, String Cond5
				, String Ip5
				, String Cond6
				, String Ip6
			) {
		this.jnum = jnum;
		this.stubFnxRefWdbeMFsmstate = stubFnxRefWdbeMFsmstate;
		this.Cond1 = Cond1;
		this.Ip1 = Ip1;
		this.Cond2 = Cond2;
		this.Ip2 = Ip2;
		this.Cond3 = Cond3;
		this.Ip3 = Ip3;
		this.Cond4 = Cond4;
		this.Ip4 = Ip4;
		this.Cond5 = Cond5;
		this.Ip5 = Ip5;
		this.Cond6 = Cond6;
		this.Ip6 = Ip6;
	};

	public int jnum;
	public String stubFnxRefWdbeMFsmstate;
	public String Cond1;
	public String Ip1;
	public String Cond2;
	public String Ip2;
	public String Cond3;
	public String Ip3;
	public String Cond4;
	public String Ip4;
	public String Cond5;
	public String Ip5;
	public String Cond6;
	public String Ip6;
	
	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "WdbeQFstAStep");

		if (Xmlio.checkXPath(doc, basexpath)) {
			stubFnxRefWdbeMFsmstate = Xmlio.extractStringUclc(doc, basexpath, "stubFnxRefWdbeMFsmstate", "fnx", null, 0);
			Cond1 = Xmlio.extractStringUclc(doc, basexpath, "Cond1", "cn1", null, 0);
			Ip1 = Xmlio.extractStringUclc(doc, basexpath, "Ip1", "ip1", null, 0);
			Cond2 = Xmlio.extractStringUclc(doc, basexpath, "Cond2", "cn2", null, 0);
			Ip2 = Xmlio.extractStringUclc(doc, basexpath, "Ip2", "ip2", null, 0);
			Cond3 = Xmlio.extractStringUclc(doc, basexpath, "Cond3", "cn3", null, 0);
			Ip3 = Xmlio.extractStringUclc(doc, basexpath, "Ip3", "ip3", null, 0);
			Cond4 = Xmlio.extractStringUclc(doc, basexpath, "Cond4", "cn4", null, 0);
			Ip4 = Xmlio.extractStringUclc(doc, basexpath, "Ip4", "ip4", null, 0);
			Cond5 = Xmlio.extractStringUclc(doc, basexpath, "Cond5", "cn5", null, 0);
			Ip5 = Xmlio.extractStringUclc(doc, basexpath, "Ip5", "ip5", null, 0);
			Cond6 = Xmlio.extractStringUclc(doc, basexpath, "Cond6", "cn6", null, 0);
			Ip6 = Xmlio.extractStringUclc(doc, basexpath, "Ip6", "ip6", null, 0);
			
			return true;
		};

		return false;
	};
};
