/**
  * \file PnlWdbeFstAStep.java
  * Java API code for job PnlWdbeFstAStep
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeFstAStep {
	/**
		* VecVDo (full: VecVWdbeFstAStepDo)
		*/
	public static class VecVDo {

		public static final int BUTUPCLICK = 1;
		public static final int BUTDOWNCLICK = 2;
		public static final int BUTNEWCLICK = 3;
		public static final int BUTDUPLICATECLICK = 4;
		public static final int BUTDELETECLICK = 5;
		public static final int BUTREFRESHCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butupclick")) return BUTUPCLICK;
			if (s.equals("butdownclick")) return BUTDOWNCLICK;
			if (s.equals("butnewclick")) return BUTNEWCLICK;
			if (s.equals("butduplicateclick")) return BUTDUPLICATECLICK;
			if (s.equals("butdeleteclick")) return BUTDELETECLICK;
			if (s.equals("butrefreshclick")) return BUTREFRESHCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTUPCLICK) return("ButUpClick");
			if (ix == BUTDOWNCLICK) return("ButDownClick");
			if (ix == BUTNEWCLICK) return("ButNewClick");
			if (ix == BUTDUPLICATECLICK) return("ButDuplicateClick");
			if (ix == BUTDELETECLICK) return("ButDeleteClick");
			if (ix == BUTREFRESHCLICK) return("ButRefreshClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWdbeFstAStep)
	  */
	public class ContInf extends Block {

		public static final int NUMFCSIQST = 1;

		public ContInf(
					int numFCsiQst
				) {
			this.numFCsiQst = numFCsiQst;

			mask = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
		};

		public int numFCsiQst;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeFstAStep");

			String itemtag = "ContitemInfWdbeFstAStep";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFCsiQst = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFCsiQst", mask, NUMFCSIQST);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFCsiQst == comp.numFCsiQst) items.add(NUMFCSIQST);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFCSIQST));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeFstAStep)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;

		public StatApp(
					int ixWdbeVExpstate
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE));
		};

		public int ixWdbeVExpstate;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeFstAStep");

			String itemtag = "StatitemAppWdbeFstAStep";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeFstAStep)
	  */
	public class StatShr extends Block {

		public static final int BUTUPAVAIL = 1;
		public static final int BUTUPACTIVE = 2;
		public static final int BUTDOWNAVAIL = 3;
		public static final int BUTDOWNACTIVE = 4;
		public static final int BUTNEWAVAIL = 5;
		public static final int BUTDUPLICATEAVAIL = 6;
		public static final int BUTDUPLICATEACTIVE = 7;
		public static final int BUTDELETEAVAIL = 8;
		public static final int BUTDELETEACTIVE = 9;

		public StatShr(
					boolean ButUpAvail
					, boolean ButUpActive
					, boolean ButDownAvail
					, boolean ButDownActive
					, boolean ButNewAvail
					, boolean ButDuplicateAvail
					, boolean ButDuplicateActive
					, boolean ButDeleteAvail
					, boolean ButDeleteActive
				) {
			this.ButUpAvail = ButUpAvail;
			this.ButUpActive = ButUpActive;
			this.ButDownAvail = ButDownAvail;
			this.ButDownActive = ButDownActive;
			this.ButNewAvail = ButNewAvail;
			this.ButDuplicateAvail = ButDuplicateAvail;
			this.ButDuplicateActive = ButDuplicateActive;
			this.ButDeleteAvail = ButDeleteAvail;
			this.ButDeleteActive = ButDeleteActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE));
		};

		public boolean ButUpAvail;
		public boolean ButUpActive;
		public boolean ButDownAvail;
		public boolean ButDownActive;
		public boolean ButNewAvail;
		public boolean ButDuplicateAvail;
		public boolean ButDuplicateActive;
		public boolean ButDeleteAvail;
		public boolean ButDeleteActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeFstAStep");

			String itemtag = "StatitemShrWdbeFstAStep";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButUpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUpAvail", mask, BUTUPAVAIL);
				ButUpActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUpActive", mask, BUTUPACTIVE);
				ButDownAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDownAvail", mask, BUTDOWNAVAIL);
				ButDownActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDownActive", mask, BUTDOWNACTIVE);
				ButNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButNewAvail", mask, BUTNEWAVAIL);
				ButDuplicateAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDuplicateAvail", mask, BUTDUPLICATEAVAIL);
				ButDuplicateActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDuplicateActive", mask, BUTDUPLICATEACTIVE);
				ButDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteAvail", mask, BUTDELETEAVAIL);
				ButDeleteActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDeleteActive", mask, BUTDELETEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButUpAvail == comp.ButUpAvail) items.add(BUTUPAVAIL);
			if (ButUpActive == comp.ButUpActive) items.add(BUTUPACTIVE);
			if (ButDownAvail == comp.ButDownAvail) items.add(BUTDOWNAVAIL);
			if (ButDownActive == comp.ButDownActive) items.add(BUTDOWNACTIVE);
			if (ButNewAvail == comp.ButNewAvail) items.add(BUTNEWAVAIL);
			if (ButDuplicateAvail == comp.ButDuplicateAvail) items.add(BUTDUPLICATEAVAIL);
			if (ButDuplicateActive == comp.ButDuplicateActive) items.add(BUTDUPLICATEACTIVE);
			if (ButDeleteAvail == comp.ButDeleteAvail) items.add(BUTDELETEAVAIL);
			if (ButDeleteActive == comp.ButDeleteActive) items.add(BUTDELETEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTUPAVAIL, BUTUPACTIVE, BUTDOWNAVAIL, BUTDOWNACTIVE, BUTNEWAVAIL, BUTDUPLICATEAVAIL, BUTDUPLICATEACTIVE, BUTDELETEAVAIL, BUTDELETEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StgIac (full: StgIacWdbeFstAStep)
	  */
	public class StgIac extends Block {

		public static final int TCOFNXWIDTH = 1;
		public static final int TCOCN1WIDTH = 2;
		public static final int TCOIP1WIDTH = 3;
		public static final int TCOCN2WIDTH = 4;
		public static final int TCOIP2WIDTH = 5;
		public static final int TCOCN3WIDTH = 6;
		public static final int TCOIP3WIDTH = 7;
		public static final int TCOCN4WIDTH = 8;
		public static final int TCOIP4WIDTH = 9;

		public StgIac(
					int TcoFnxWidth
					, int TcoCn1Width
					, int TcoIp1Width
					, int TcoCn2Width
					, int TcoIp2Width
					, int TcoCn3Width
					, int TcoIp3Width
					, int TcoCn4Width
					, int TcoIp4Width
				) {
			this.TcoFnxWidth = TcoFnxWidth;
			this.TcoCn1Width = TcoCn1Width;
			this.TcoIp1Width = TcoIp1Width;
			this.TcoCn2Width = TcoCn2Width;
			this.TcoIp2Width = TcoIp2Width;
			this.TcoCn3Width = TcoCn3Width;
			this.TcoIp3Width = TcoIp3Width;
			this.TcoCn4Width = TcoCn4Width;
			this.TcoIp4Width = TcoIp4Width;

			mask = new HashSet<Integer>(Arrays.asList(TCOFNXWIDTH, TCOCN1WIDTH, TCOIP1WIDTH, TCOCN2WIDTH, TCOIP2WIDTH, TCOCN3WIDTH, TCOIP3WIDTH, TCOCN4WIDTH, TCOIP4WIDTH));
		};

		public int TcoFnxWidth;
		public int TcoCn1Width;
		public int TcoIp1Width;
		public int TcoCn2Width;
		public int TcoIp2Width;
		public int TcoCn3Width;
		public int TcoIp3Width;
		public int TcoCn4Width;
		public int TcoIp4Width;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWdbeFstAStep");

			String itemtag = "StgitemIacWdbeFstAStep";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoFnxWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoFnxWidth", mask, TCOFNXWIDTH);
				TcoCn1Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoCn1Width", mask, TCOCN1WIDTH);
				TcoIp1Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoIp1Width", mask, TCOIP1WIDTH);
				TcoCn2Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoCn2Width", mask, TCOCN2WIDTH);
				TcoIp2Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoIp2Width", mask, TCOIP2WIDTH);
				TcoCn3Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoCn3Width", mask, TCOCN3WIDTH);
				TcoIp3Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoIp3Width", mask, TCOIP3WIDTH);
				TcoCn4Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoCn4Width", mask, TCOCN4WIDTH);
				TcoIp4Width = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoIp4Width", mask, TCOIP4WIDTH);

				return true;
			};

			return false;
		};

		public void writeXML(
					Document doc
					, Element sup
					, String difftag
					, boolean shorttags
				) {
			if (difftag.isEmpty()) difftag = "StgIacWdbeFstAStep";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWdbeFstAStep";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoFnxWidth", TcoFnxWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoCn1Width", TcoCn1Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoIp1Width", TcoIp1Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoCn2Width", TcoCn2Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoIp2Width", TcoIp2Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoCn3Width", TcoCn3Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoIp3Width", TcoIp3Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoCn4Width", TcoCn4Width);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoIp4Width", TcoIp4Width);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoFnxWidth == comp.TcoFnxWidth) items.add(TCOFNXWIDTH);
			if (TcoCn1Width == comp.TcoCn1Width) items.add(TCOCN1WIDTH);
			if (TcoIp1Width == comp.TcoIp1Width) items.add(TCOIP1WIDTH);
			if (TcoCn2Width == comp.TcoCn2Width) items.add(TCOCN2WIDTH);
			if (TcoIp2Width == comp.TcoIp2Width) items.add(TCOIP2WIDTH);
			if (TcoCn3Width == comp.TcoCn3Width) items.add(TCOCN3WIDTH);
			if (TcoIp3Width == comp.TcoIp3Width) items.add(TCOIP3WIDTH);
			if (TcoCn4Width == comp.TcoCn4Width) items.add(TCOCN4WIDTH);
			if (TcoIp4Width == comp.TcoIp4Width) items.add(TCOIP4WIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOFNXWIDTH, TCOCN1WIDTH, TCOIP1WIDTH, TCOCN2WIDTH, TCOIP2WIDTH, TCOCN3WIDTH, TCOIP3WIDTH, TCOCN4WIDTH, TCOIP4WIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeFstAStep)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOFNX = 7;
		public static final int TCOCN1 = 8;
		public static final int TCOIP1 = 9;
		public static final int TCOCN2 = 10;
		public static final int TCOIP2 = 11;
		public static final int TCOCN3 = 12;
		public static final int TCOIP3 = 13;
		public static final int TCOCN4 = 14;
		public static final int TCOIP4 = 15;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoFnx
					, String TcoCn1
					, String TcoIp1
					, String TcoCn2
					, String TcoIp2
					, String TcoCn3
					, String TcoIp3
					, String TcoCn4
					, String TcoIp4
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoFnx = TcoFnx;
			this.TcoCn1 = TcoCn1;
			this.TcoIp1 = TcoIp1;
			this.TcoCn2 = TcoCn2;
			this.TcoIp2 = TcoIp2;
			this.TcoCn3 = TcoCn3;
			this.TcoIp3 = TcoIp3;
			this.TcoCn4 = TcoCn4;
			this.TcoIp4 = TcoIp4;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOFNX, TCOCN1, TCOIP1, TCOCN2, TCOIP2, TCOCN3, TCOIP3, TCOCN4, TCOIP4));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoFnx;
		public String TcoCn1;
		public String TcoIp1;
		public String TcoCn2;
		public String TcoIp2;
		public String TcoCn3;
		public String TcoIp3;
		public String TcoCn4;
		public String TcoIp4;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeFstAStep");

			String itemtag = "TagitemWdbeFstAStep";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoFnx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoFnx", mask, TCOFNX);
				TcoCn1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoCn1", mask, TCOCN1);
				TcoIp1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoIp1", mask, TCOIP1);
				TcoCn2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoCn2", mask, TCOCN2);
				TcoIp2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoIp2", mask, TCOIP2);
				TcoCn3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoCn3", mask, TCOCN3);
				TcoIp3 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoIp3", mask, TCOIP3);
				TcoCn4 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoCn4", mask, TCOCN4);
				TcoIp4 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoIp4", mask, TCOIP4);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (TxtRecord1.equals(comp.TxtRecord1)) items.add(TXTRECORD1);
			if (TxtRecord2.equals(comp.TxtRecord2)) items.add(TXTRECORD2);
			if (Trs.equals(comp.Trs)) items.add(TRS);
			if (TxtShowing1.equals(comp.TxtShowing1)) items.add(TXTSHOWING1);
			if (TxtShowing2.equals(comp.TxtShowing2)) items.add(TXTSHOWING2);
			if (TcoFnx.equals(comp.TcoFnx)) items.add(TCOFNX);
			if (TcoCn1.equals(comp.TcoCn1)) items.add(TCOCN1);
			if (TcoIp1.equals(comp.TcoIp1)) items.add(TCOIP1);
			if (TcoCn2.equals(comp.TcoCn2)) items.add(TCOCN2);
			if (TcoIp2.equals(comp.TcoIp2)) items.add(TCOIP2);
			if (TcoCn3.equals(comp.TcoCn3)) items.add(TCOCN3);
			if (TcoIp3.equals(comp.TcoIp3)) items.add(TCOIP3);
			if (TcoCn4.equals(comp.TcoCn4)) items.add(TCOCN4);
			if (TcoIp4.equals(comp.TcoIp4)) items.add(TCOIP4);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOFNX, TCOCN1, TCOIP1, TCOCN2, TCOIP2, TCOCN3, TCOIP3, TCOCN4, TCOIP4));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeFstAStepData)
		*/
	public class DpchAppData extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWdbeFstAStep.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPWDBEFSTASTEPDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, STGIAC, STGIACQRY));
					break;
				};

			if (has(STGIAC)) this.stgiac = stgiac;
			if (has(STGIACQRY)) this.stgiacqry = stgiacqry;
		};

		public StgIac stgiac;
		public QryWdbeFstAStep.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWdbeFstAStepData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeFstAStepDo)
		*/
	public class DpchAppDo extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int ALL = 3;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPWDBEFSTASTEPDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO));
					break;
				};

			this.ixVDo = ixVDo;
		};

		public int ixVDo;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWdbeFstAStepDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeFstAStepData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int FEEDFCSIQST = 3;
		public static final int STATAPP = 4;
		public static final int STATSHR = 5;
		public static final int STGIAC = 6;
		public static final int TAG = 7;
		public static final int RST = 8;
		public static final int STATAPPQRY = 9;
		public static final int STATSHRQRY = 10;
		public static final int STGIACQRY = 11;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEFSTASTEPDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false);
			stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWdbeQFstAStep();
			statappqry = (new QryWdbeFstAStep()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWdbeFstAStep()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWdbeFstAStep()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWdbeQFstAStep rst;
		public QryWdbeFstAStep.StatApp statappqry;
		public QryWdbeFstAStep.StatShr statshrqry;
		public QryWdbeFstAStep.StgIac stgiacqry;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFCSIQST)) ss.add("feedFCsiQst");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STGIAC)) ss.add("stgiac");
			if (has(TAG)) ss.add("tag");
			if (has(RST)) ss.add("rst");
			if (has(STATAPPQRY)) ss.add("statappqry");
			if (has(STATSHRQRY)) ss.add("statshrqry");
			if (has(STGIACQRY)) ss.add("stgiacqry");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeFstAStepData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFCsiQst.readXML(doc, basexpath, true)) add(FEEDFCSIQST);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (stgiac.readXML(doc, basexpath, true)) add(STGIAC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (rst.readXML(doc, basexpath, true)) add(RST);
				if (statappqry.readXML(doc, basexpath, true)) add(STATAPPQRY);
				if (statshrqry.readXML(doc, basexpath, true)) add(STATSHRQRY);
				if (stgiacqry.readXML(doc, basexpath, true)) add(STGIACQRY);
			} else {
				scrJref = "";
				continf = new ContInf(0);
				feedFCsiQst = new Feed("FeedFCsiQst");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false);
				stgiac = new StgIac(0, 0, 0, 0, 0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWdbeFstAStep()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWdbeFstAStep()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWdbeFstAStep()).new StgIac(0, 0, 0);
			};
		};

	};

};

