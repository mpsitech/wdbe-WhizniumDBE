/**
	* \file DpchAppWdbe.java
	* Wdbe Java API package app dispatch block
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DpchAppWdbe extends DpchWdbe {

	public static final int SCRJREF = 1;
	
	public DpchAppWdbe(
				int ixWdbeVDpch
				, String scrJref
			) {
		super(ixWdbeVDpch);
		
		this.scrJref = scrJref;
		
		mask = new HashSet<Integer>(Arrays.asList(SCRJREF));
	};

	public String scrJref;
	
	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(SCRJREF)) return false;

		return true;
	};
	
	public String getSrefsMask() {
		if (has(SCRJREF)) return("scrJref");
		
		return "";
	};
	
	public void writeXML(
				Document doc
				, Element sup
			) {
		Element el = doc.createElement(VecWdbeVDpch.getSref(ixWdbeVDpch));

		if (sup == null) doc.appendChild(el);
		else sup.appendChild(el);

		el.setAttribute("xmlns", "http://www.mpsitech.com/wdbe");
		
		if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
	};
};

