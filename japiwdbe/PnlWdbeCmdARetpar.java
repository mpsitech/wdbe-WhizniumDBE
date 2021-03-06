/**
  * \file PnlWdbeCmdARetpar.java
  * Java API code for job PnlWdbeCmdARetpar
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeCmdARetpar {
	/**
		* VecVDo (full: VecVWdbeCmdARetparDo)
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
	  * ContInf (full: ContInfWdbeCmdARetpar)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeCmdARetpar");

			String itemtag = "ContitemInfWdbeCmdARetpar";

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
	  * StatApp (full: StatAppWdbeCmdARetpar)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeCmdARetpar");

			String itemtag = "StatitemAppWdbeCmdARetpar";

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
	  * StatShr (full: StatShrWdbeCmdARetpar)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeCmdARetpar");

			String itemtag = "StatitemShrWdbeCmdARetpar";

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
	  * StgIac (full: StgIacWdbeCmdARetpar)
	  */
	public class StgIac extends Block {

		public static final int TCOSRFWIDTH = 1;
		public static final int TCOPTYWIDTH = 2;
		public static final int TCOVECWIDTH = 3;
		public static final int TCOLENWIDTH = 4;
		public static final int TCOCMTWIDTH = 5;

		public StgIac(
					int TcoSrfWidth
					, int TcoPtyWidth
					, int TcoVecWidth
					, int TcoLenWidth
					, int TcoCmtWidth
				) {
			this.TcoSrfWidth = TcoSrfWidth;
			this.TcoPtyWidth = TcoPtyWidth;
			this.TcoVecWidth = TcoVecWidth;
			this.TcoLenWidth = TcoLenWidth;
			this.TcoCmtWidth = TcoCmtWidth;

			mask = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOPTYWIDTH, TCOVECWIDTH, TCOLENWIDTH, TCOCMTWIDTH));
		};

		public int TcoSrfWidth;
		public int TcoPtyWidth;
		public int TcoVecWidth;
		public int TcoLenWidth;
		public int TcoCmtWidth;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StgIacWdbeCmdARetpar");

			String itemtag = "StgitemIacWdbeCmdARetpar";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TcoSrfWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoSrfWidth", mask, TCOSRFWIDTH);
				TcoPtyWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoPtyWidth", mask, TCOPTYWIDTH);
				TcoVecWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoVecWidth", mask, TCOVECWIDTH);
				TcoLenWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoLenWidth", mask, TCOLENWIDTH);
				TcoCmtWidth = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TcoCmtWidth", mask, TCOCMTWIDTH);

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
			if (difftag.isEmpty()) difftag = "StgIacWdbeCmdARetpar";

			String itemtag;

			if (shorttags) itemtag = "Si";
			else itemtag = "StgitemIacWdbeCmdARetpar";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoSrfWidth", TcoSrfWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoPtyWidth", TcoPtyWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoVecWidth", TcoVecWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoLenWidth", TcoLenWidth);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "TcoCmtWidth", TcoCmtWidth);
		};

		public HashSet<Integer> comm(
					StgIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TcoSrfWidth == comp.TcoSrfWidth) items.add(TCOSRFWIDTH);
			if (TcoPtyWidth == comp.TcoPtyWidth) items.add(TCOPTYWIDTH);
			if (TcoVecWidth == comp.TcoVecWidth) items.add(TCOVECWIDTH);
			if (TcoLenWidth == comp.TcoLenWidth) items.add(TCOLENWIDTH);
			if (TcoCmtWidth == comp.TcoCmtWidth) items.add(TCOCMTWIDTH);

			return(items);
		};

		public HashSet<Integer> diff(
					StgIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TCOSRFWIDTH, TCOPTYWIDTH, TCOVECWIDTH, TCOLENWIDTH, TCOCMTWIDTH));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeCmdARetpar)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int TXTRECORD1 = 2;
		public static final int TXTRECORD2 = 3;
		public static final int TRS = 4;
		public static final int TXTSHOWING1 = 5;
		public static final int TXTSHOWING2 = 6;
		public static final int TCOSRF = 7;
		public static final int TCOPTY = 8;
		public static final int TCOVEC = 9;
		public static final int TCOLEN = 10;
		public static final int TCOCMT = 11;

		public Tag(
					String Cpt
					, String TxtRecord1
					, String TxtRecord2
					, String Trs
					, String TxtShowing1
					, String TxtShowing2
					, String TcoSrf
					, String TcoPty
					, String TcoVec
					, String TcoLen
					, String TcoCmt
				) {
			this.Cpt = Cpt;
			this.TxtRecord1 = TxtRecord1;
			this.TxtRecord2 = TxtRecord2;
			this.Trs = Trs;
			this.TxtShowing1 = TxtShowing1;
			this.TxtShowing2 = TxtShowing2;
			this.TcoSrf = TcoSrf;
			this.TcoPty = TcoPty;
			this.TcoVec = TcoVec;
			this.TcoLen = TcoLen;
			this.TcoCmt = TcoCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOPTY, TCOVEC, TCOLEN, TCOCMT));
		};

		public String Cpt;
		public String TxtRecord1;
		public String TxtRecord2;
		public String Trs;
		public String TxtShowing1;
		public String TxtShowing2;
		public String TcoSrf;
		public String TcoPty;
		public String TcoVec;
		public String TcoLen;
		public String TcoCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeCmdARetpar");

			String itemtag = "TagitemWdbeCmdARetpar";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				TxtRecord1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord1", mask, TXTRECORD1);
				TxtRecord2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtRecord2", mask, TXTRECORD2);
				Trs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Trs", mask, TRS);
				TxtShowing1 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing1", mask, TXTSHOWING1);
				TxtShowing2 = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TxtShowing2", mask, TXTSHOWING2);
				TcoSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoSrf", mask, TCOSRF);
				TcoPty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoPty", mask, TCOPTY);
				TcoVec = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoVec", mask, TCOVEC);
				TcoLen = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoLen", mask, TCOLEN);
				TcoCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "TcoCmt", mask, TCOCMT);

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
			if (TcoSrf.equals(comp.TcoSrf)) items.add(TCOSRF);
			if (TcoPty.equals(comp.TcoPty)) items.add(TCOPTY);
			if (TcoVec.equals(comp.TcoVec)) items.add(TCOVEC);
			if (TcoLen.equals(comp.TcoLen)) items.add(TCOLEN);
			if (TcoCmt.equals(comp.TcoCmt)) items.add(TCOCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, TXTRECORD1, TXTRECORD2, TRS, TXTSHOWING1, TXTSHOWING2, TCOSRF, TCOPTY, TCOVEC, TCOLEN, TCOCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeCmdARetparData)
		*/
	public class DpchAppData extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int STGIAC = 2;
		public static final int STGIACQRY = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, StgIac stgiac
					, QryWdbeCmdARetpar.StgIac stgiacqry
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPWDBECMDARETPARDATA, scrJref);

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
		public QryWdbeCmdARetpar.StgIac stgiacqry;

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
			Element el = doc.createElement("DpchAppWdbeCmdARetparData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(STGIAC)) stgiac.writeXML(doc, el, "", true);
			if (has(STGIACQRY)) stgiacqry.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeCmdARetparDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBECMDARETPARDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeCmdARetparDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeCmdARetparData)
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
			super(VecWdbeVDpch.DPCHENGWDBECMDARETPARDATA);

			continf = new ContInf(0);
			feedFCsiQst = new Feed("FeedFCsiQst");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false);
			stgiac = new StgIac(0, 0, 0, 0, 0);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
			rst = new ListWdbeQCmdARetpar();
			statappqry = (new QryWdbeCmdARetpar()).new StatApp(0, 0, 0, 0);
			statshrqry = (new QryWdbeCmdARetpar()).new StatShr(0, 0, 0);
			stgiacqry = (new QryWdbeCmdARetpar()).new StgIac(0, 0, 0);
		};

		public ContInf continf;
		public Feed feedFCsiQst;
		public StatApp statapp;
		public StatShr statshr;
		public StgIac stgiac;
		public Tag tag;
		public ListWdbeQCmdARetpar rst;
		public QryWdbeCmdARetpar.StatApp statappqry;
		public QryWdbeCmdARetpar.StatShr statshrqry;
		public QryWdbeCmdARetpar.StgIac stgiacqry;

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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeCmdARetparData");

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
				stgiac = new StgIac(0, 0, 0, 0, 0);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
				statappqry = (new QryWdbeCmdARetpar()).new StatApp(0, 0, 0, 0);
				statshrqry = (new QryWdbeCmdARetpar()).new StatShr(0, 0, 0);
				stgiacqry = (new QryWdbeCmdARetpar()).new StgIac(0, 0, 0);
			};
		};

	};

};
