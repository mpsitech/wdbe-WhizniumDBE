/**
  * \file PnlWdbeNavAdmin.java
  * Java API code for job PnlWdbeNavAdmin
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavAdmin {
	/**
		* VecVDo (full: VecVWdbeNavAdminDo)
		*/
	public static class VecVDo {

		public static final int BUTUSGVIEWCLICK = 1;
		public static final int BUTUSGNEWCRDCLICK = 2;
		public static final int BUTUSRVIEWCLICK = 3;
		public static final int BUTUSRNEWCRDCLICK = 4;
		public static final int BUTPRSVIEWCLICK = 5;
		public static final int BUTPRSNEWCRDCLICK = 6;
		public static final int BUTFILVIEWCLICK = 7;
		public static final int BUTFILNEWCRDCLICK = 8;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butusgviewclick")) return BUTUSGVIEWCLICK;
			if (s.equals("butusgnewcrdclick")) return BUTUSGNEWCRDCLICK;
			if (s.equals("butusrviewclick")) return BUTUSRVIEWCLICK;
			if (s.equals("butusrnewcrdclick")) return BUTUSRNEWCRDCLICK;
			if (s.equals("butprsviewclick")) return BUTPRSVIEWCLICK;
			if (s.equals("butprsnewcrdclick")) return BUTPRSNEWCRDCLICK;
			if (s.equals("butfilviewclick")) return BUTFILVIEWCLICK;
			if (s.equals("butfilnewcrdclick")) return BUTFILNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTUSGVIEWCLICK) return("ButUsgViewClick");
			if (ix == BUTUSGNEWCRDCLICK) return("ButUsgNewcrdClick");
			if (ix == BUTUSRVIEWCLICK) return("ButUsrViewClick");
			if (ix == BUTUSRNEWCRDCLICK) return("ButUsrNewcrdClick");
			if (ix == BUTPRSVIEWCLICK) return("ButPrsViewClick");
			if (ix == BUTPRSNEWCRDCLICK) return("ButPrsNewcrdClick");
			if (ix == BUTFILVIEWCLICK) return("ButFilViewClick");
			if (ix == BUTFILNEWCRDCLICK) return("ButFilNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeNavAdmin)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTUSG = 1;
		public static final int NUMFLSTUSR = 2;
		public static final int NUMFLSTPRS = 3;
		public static final int NUMFLSTFIL = 4;

		public ContIac(
					int numFLstUsg
					, int numFLstUsr
					, int numFLstPrs
					, int numFLstFil
				) {
			this.numFLstUsg = numFLstUsg;
			this.numFLstUsr = numFLstUsr;
			this.numFLstPrs = numFLstPrs;
			this.numFLstFil = numFLstFil;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS, NUMFLSTFIL));
		};

		public int numFLstUsg;
		public int numFLstUsr;
		public int numFLstPrs;
		public int numFLstFil;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeNavAdmin");

			String itemtag = "ContitemIacWdbeNavAdmin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstUsg = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstUsg", mask, NUMFLSTUSG);
				numFLstUsr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstUsr", mask, NUMFLSTUSR);
				numFLstPrs = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrs", mask, NUMFLSTPRS);
				numFLstFil = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstFil", mask, NUMFLSTFIL);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeNavAdmin";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeNavAdmin";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstUsg", numFLstUsg);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstUsr", numFLstUsr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrs", numFLstPrs);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstFil", numFLstFil);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstUsg == comp.numFLstUsg) items.add(NUMFLSTUSG);
			if (numFLstUsr == comp.numFLstUsr) items.add(NUMFLSTUSR);
			if (numFLstPrs == comp.numFLstPrs) items.add(NUMFLSTPRS);
			if (numFLstFil == comp.numFLstFil) items.add(NUMFLSTFIL);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTUSG, NUMFLSTUSR, NUMFLSTPRS, NUMFLSTFIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNavAdmin)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTUSGALT = 2;
		public static final int LSTUSRALT = 3;
		public static final int LSTPRSALT = 4;
		public static final int LSTFILALT = 5;
		public static final int LSTUSGNUMFIRSTDISP = 6;
		public static final int LSTUSRNUMFIRSTDISP = 7;
		public static final int LSTPRSNUMFIRSTDISP = 8;
		public static final int LSTFILNUMFIRSTDISP = 9;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstUsgAlt
					, boolean LstUsrAlt
					, boolean LstPrsAlt
					, boolean LstFilAlt
					, int LstUsgNumFirstdisp
					, int LstUsrNumFirstdisp
					, int LstPrsNumFirstdisp
					, int LstFilNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstUsgAlt = LstUsgAlt;
			this.LstUsrAlt = LstUsrAlt;
			this.LstPrsAlt = LstPrsAlt;
			this.LstFilAlt = LstFilAlt;
			this.LstUsgNumFirstdisp = LstUsgNumFirstdisp;
			this.LstUsrNumFirstdisp = LstUsrNumFirstdisp;
			this.LstPrsNumFirstdisp = LstPrsNumFirstdisp;
			this.LstFilNumFirstdisp = LstFilNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTFILALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP, LSTFILNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstUsgAlt;
		public boolean LstUsrAlt;
		public boolean LstPrsAlt;
		public boolean LstFilAlt;
		public int LstUsgNumFirstdisp;
		public int LstUsrNumFirstdisp;
		public int LstPrsNumFirstdisp;
		public int LstFilNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNavAdmin");

			String itemtag = "StatitemAppWdbeNavAdmin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstUsgAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsgAlt", mask, LSTUSGALT);
				LstUsrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsrAlt", mask, LSTUSRALT);
				LstPrsAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrsAlt", mask, LSTPRSALT);
				LstFilAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFilAlt", mask, LSTFILALT);
				LstUsgNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsgNumFirstdisp", mask, LSTUSGNUMFIRSTDISP);
				LstUsrNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsrNumFirstdisp", mask, LSTUSRNUMFIRSTDISP);
				LstPrsNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrsNumFirstdisp", mask, LSTPRSNUMFIRSTDISP);
				LstFilNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFilNumFirstdisp", mask, LSTFILNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstUsgAlt == comp.LstUsgAlt) items.add(LSTUSGALT);
			if (LstUsrAlt == comp.LstUsrAlt) items.add(LSTUSRALT);
			if (LstPrsAlt == comp.LstPrsAlt) items.add(LSTPRSALT);
			if (LstFilAlt == comp.LstFilAlt) items.add(LSTFILALT);
			if (LstUsgNumFirstdisp == comp.LstUsgNumFirstdisp) items.add(LSTUSGNUMFIRSTDISP);
			if (LstUsrNumFirstdisp == comp.LstUsrNumFirstdisp) items.add(LSTUSRNUMFIRSTDISP);
			if (LstPrsNumFirstdisp == comp.LstPrsNumFirstdisp) items.add(LSTPRSNUMFIRSTDISP);
			if (LstFilNumFirstdisp == comp.LstFilNumFirstdisp) items.add(LSTFILNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTUSGALT, LSTUSRALT, LSTPRSALT, LSTFILALT, LSTUSGNUMFIRSTDISP, LSTUSRNUMFIRSTDISP, LSTPRSNUMFIRSTDISP, LSTFILNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNavAdmin)
	  */
	public class StatShr extends Block {

		public static final int LSTUSGAVAIL = 1;
		public static final int BUTUSGVIEWACTIVE = 2;
		public static final int LSTUSRAVAIL = 3;
		public static final int BUTUSRVIEWACTIVE = 4;
		public static final int LSTPRSAVAIL = 5;
		public static final int BUTPRSVIEWACTIVE = 6;
		public static final int LSTFILAVAIL = 7;
		public static final int BUTFILVIEWACTIVE = 8;

		public StatShr(
					boolean LstUsgAvail
					, boolean ButUsgViewActive
					, boolean LstUsrAvail
					, boolean ButUsrViewActive
					, boolean LstPrsAvail
					, boolean ButPrsViewActive
					, boolean LstFilAvail
					, boolean ButFilViewActive
				) {
			this.LstUsgAvail = LstUsgAvail;
			this.ButUsgViewActive = ButUsgViewActive;
			this.LstUsrAvail = LstUsrAvail;
			this.ButUsrViewActive = ButUsrViewActive;
			this.LstPrsAvail = LstPrsAvail;
			this.ButPrsViewActive = ButPrsViewActive;
			this.LstFilAvail = LstFilAvail;
			this.ButFilViewActive = ButFilViewActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE));
		};

		public boolean LstUsgAvail;
		public boolean ButUsgViewActive;
		public boolean LstUsrAvail;
		public boolean ButUsrViewActive;
		public boolean LstPrsAvail;
		public boolean ButPrsViewActive;
		public boolean LstFilAvail;
		public boolean ButFilViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavAdmin");

			String itemtag = "StatitemShrWdbeNavAdmin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstUsgAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsgAvail", mask, LSTUSGAVAIL);
				ButUsgViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUsgViewActive", mask, BUTUSGVIEWACTIVE);
				LstUsrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUsrAvail", mask, LSTUSRAVAIL);
				ButUsrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUsrViewActive", mask, BUTUSRVIEWACTIVE);
				LstPrsAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrsAvail", mask, LSTPRSAVAIL);
				ButPrsViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrsViewActive", mask, BUTPRSVIEWACTIVE);
				LstFilAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFilAvail", mask, LSTFILAVAIL);
				ButFilViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFilViewActive", mask, BUTFILVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstUsgAvail == comp.LstUsgAvail) items.add(LSTUSGAVAIL);
			if (ButUsgViewActive == comp.ButUsgViewActive) items.add(BUTUSGVIEWACTIVE);
			if (LstUsrAvail == comp.LstUsrAvail) items.add(LSTUSRAVAIL);
			if (ButUsrViewActive == comp.ButUsrViewActive) items.add(BUTUSRVIEWACTIVE);
			if (LstPrsAvail == comp.LstPrsAvail) items.add(LSTPRSAVAIL);
			if (ButPrsViewActive == comp.ButPrsViewActive) items.add(BUTPRSVIEWACTIVE);
			if (LstFilAvail == comp.LstFilAvail) items.add(LSTFILAVAIL);
			if (ButFilViewActive == comp.ButFilViewActive) items.add(BUTFILVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTUSGAVAIL, BUTUSGVIEWACTIVE, LSTUSRAVAIL, BUTUSRVIEWACTIVE, LSTPRSAVAIL, BUTPRSVIEWACTIVE, LSTFILAVAIL, BUTFILVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavAdmin)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTUSG = 2;
		public static final int CPTUSR = 3;
		public static final int CPTPRS = 4;
		public static final int CPTFIL = 5;

		public Tag(
					String Cpt
					, String CptUsg
					, String CptUsr
					, String CptPrs
					, String CptFil
				) {
			this.Cpt = Cpt;
			this.CptUsg = CptUsg;
			this.CptUsr = CptUsr;
			this.CptPrs = CptPrs;
			this.CptFil = CptFil;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTUSG, CPTUSR, CPTPRS, CPTFIL));
		};

		public String Cpt;
		public String CptUsg;
		public String CptUsr;
		public String CptPrs;
		public String CptFil;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavAdmin");

			String itemtag = "TagitemWdbeNavAdmin";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptUsg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUsg", mask, CPTUSG);
				CptUsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUsr", mask, CPTUSR);
				CptPrs = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrs", mask, CPTPRS);
				CptFil = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFil", mask, CPTFIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptUsg.equals(comp.CptUsg)) items.add(CPTUSG);
			if (CptUsr.equals(comp.CptUsr)) items.add(CPTUSR);
			if (CptPrs.equals(comp.CptPrs)) items.add(CPTPRS);
			if (CptFil.equals(comp.CptFil)) items.add(CPTFIL);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTUSG, CPTUSR, CPTPRS, CPTFIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeNavAdminData)
		*/
	public class DpchAppData extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int ALL = 3;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPWDBENAVADMINDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
		};

		public ContIac contiac;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppWdbeNavAdminData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavAdminDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVADMINDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavAdminDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavAdminData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTFIL = 3;
		public static final int FEEDFLSTPRS = 4;
		public static final int FEEDFLSTUSG = 5;
		public static final int FEEDFLSTUSR = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVADMINDATA);

			contiac = new ContIac(0, 0, 0, 0);
			feedFLstFil = new Feed("FeedFLstFil");
			feedFLstPrs = new Feed("FeedFLstPrs");
			feedFLstUsg = new Feed("FeedFLstUsg");
			feedFLstUsr = new Feed("FeedFLstUsr");
			statapp = new StatApp(0, false, false, false, false, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstFil;
		public Feed feedFLstPrs;
		public Feed feedFLstUsg;
		public Feed feedFLstUsr;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTFIL)) ss.add("feedFLstFil");
			if (has(FEEDFLSTPRS)) ss.add("feedFLstPrs");
			if (has(FEEDFLSTUSG)) ss.add("feedFLstUsg");
			if (has(FEEDFLSTUSR)) ss.add("feedFLstUsr");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(TAG)) ss.add("tag");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavAdminData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstFil.readXML(doc, basexpath, true)) add(FEEDFLSTFIL);
				if (feedFLstPrs.readXML(doc, basexpath, true)) add(FEEDFLSTPRS);
				if (feedFLstUsg.readXML(doc, basexpath, true)) add(FEEDFLSTUSG);
				if (feedFLstUsr.readXML(doc, basexpath, true)) add(FEEDFLSTUSR);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0);
				feedFLstFil = new Feed("FeedFLstFil");
				feedFLstPrs = new Feed("FeedFLstPrs");
				feedFLstUsg = new Feed("FeedFLstUsg");
				feedFLstUsr = new Feed("FeedFLstUsr");
				statapp = new StatApp(0, false, false, false, false, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "");
			};
		};

	};

};
