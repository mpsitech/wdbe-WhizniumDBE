/**
  * \file ContInfWdbeAlert.java
  * Wdbe Java API package alert informative content block
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class ContInfWdbeAlert extends Block {

	public static final int TXTCPT = 1;
	public static final int TXTMSG1 = 2;
	public static final int TXTMSG2 = 3;
	public static final int TXTMSG3 = 4;
	public static final int TXTMSG4 = 5;
	public static final int TXTMSG5 = 6;
	public static final int TXTMSG6 = 7;
	public static final int TXTMSG7 = 8;
	public static final int TXTMSG8 = 9;
	public static final int TXTMSG9 = 10;
	public static final int TXTMSG10 = 11;
	public static final int TXTMSG11 = 12;
	public static final int TXTMSG12 = 13;

	public ContInfWdbeAlert(
				String TxtCpt
				, String TxtMsg1
				, String TxtMsg2
				, String TxtMsg3
				, String TxtMsg4
				, String TxtMsg5
				, String TxtMsg6
				, String TxtMsg7
				, String TxtMsg8
				, String TxtMsg9
				, String TxtMsg10
				, String TxtMsg11
				, String TxtMsg12
			) {
		this.TxtCpt = TxtCpt;
		this.TxtMsg1 = TxtMsg1;
		this.TxtMsg2 = TxtMsg2;
		this.TxtMsg3 = TxtMsg3;
		this.TxtMsg4 = TxtMsg4;
		this.TxtMsg5 = TxtMsg5;
		this.TxtMsg6 = TxtMsg6;
		this.TxtMsg7 = TxtMsg7;
		this.TxtMsg8 = TxtMsg8;
		this.TxtMsg9 = TxtMsg9;
		this.TxtMsg10 = TxtMsg10;
		this.TxtMsg11 = TxtMsg11;
		this.TxtMsg12 = TxtMsg12;
	};

	public String TxtCpt;
	public String TxtMsg1;
	public String TxtMsg2;
	public String TxtMsg3;
	public String TxtMsg4;
	public String TxtMsg5;
	public String TxtMsg6;
	public String TxtMsg7;
	public String TxtMsg8;
	public String TxtMsg9;
	public String TxtMsg10;
	public String TxtMsg11;
	public String TxtMsg12;

	public static boolean all(
				HashSet<Integer> items
			) {
		if (!items.contains(TXTCPT)) return false;
		if (!items.contains(TXTMSG1)) return false;
		if (!items.contains(TXTMSG2)) return false;
		if (!items.contains(TXTMSG3)) return false;
		if (!items.contains(TXTMSG4)) return false;
		if (!items.contains(TXTMSG5)) return false;
		if (!items.contains(TXTMSG6)) return false;
		if (!items.contains(TXTMSG7)) return false;
		if (!items.contains(TXTMSG8)) return false;
		if (!items.contains(TXTMSG9)) return false;
		if (!items.contains(TXTMSG10)) return false;
		if (!items.contains(TXTMSG11)) return false;
		if (!items.contains(TXTMSG12)) return false;

		return true;
	};

	public boolean readXML(
				Document doc
				, String basexpath
				, boolean addbasetag
			) {
		clear();
		
		if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeAlert");

		String itemtag = "ContitemInfWdbeAlert";
		
		if (Xmlio.checkXPath(doc, basexpath)) {
			TxtCpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCpt", mask, TXTCPT);
			TxtMsg1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg1", mask, TXTMSG1);
			TxtMsg2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg2", mask, TXTMSG2);
			TxtMsg3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg3", mask, TXTMSG3);
			TxtMsg4 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg4", mask, TXTMSG4);
			TxtMsg5 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg5", mask, TXTMSG5);
			TxtMsg6 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg6", mask, TXTMSG6);
			TxtMsg7 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg7", mask, TXTMSG7);
			TxtMsg8 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg8", mask, TXTMSG8);
			TxtMsg9 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg9", mask, TXTMSG9);
			TxtMsg10 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg10", mask, TXTMSG10);
			TxtMsg11 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg11", mask, TXTMSG11);
			TxtMsg12 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMsg12", mask, TXTMSG12);
			
			return true;
		};
		
		return false;
	};

	public HashSet<Integer> compare(
				ContInfWdbeAlert comp
			) {
		HashSet<Integer> items = new HashSet<Integer>();

		if (TxtCpt == comp.TxtCpt) items.add(TXTCPT);
		if (TxtMsg1 == comp.TxtMsg1) items.add(TXTMSG1);
		if (TxtMsg2 == comp.TxtMsg2) items.add(TXTMSG2);
		if (TxtMsg3 == comp.TxtMsg3) items.add(TXTMSG3);
		if (TxtMsg4 == comp.TxtMsg4) items.add(TXTMSG4);
		if (TxtMsg5 == comp.TxtMsg5) items.add(TXTMSG5);
		if (TxtMsg6 == comp.TxtMsg6) items.add(TXTMSG6);
		if (TxtMsg7 == comp.TxtMsg7) items.add(TXTMSG7);
		if (TxtMsg8 == comp.TxtMsg8) items.add(TXTMSG8);
		if (TxtMsg9 == comp.TxtMsg9) items.add(TXTMSG9);
		if (TxtMsg10 == comp.TxtMsg10) items.add(TXTMSG10);
		if (TxtMsg11 == comp.TxtMsg11) items.add(TXTMSG11);
		if (TxtMsg12 == comp.TxtMsg12) items.add(TXTMSG12);

		return items;
	};
};

