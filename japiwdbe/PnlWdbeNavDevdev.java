/**
  * \file PnlWdbeNavDevdev.java
  * Java API code for job PnlWdbeNavDevdev
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavDevdev {
	/**
		* VecVDo (full: VecVWdbeNavDevdevDo)
		*/
	public static class VecVDo {

		public static final int BUTPRJVIEWCLICK = 1;
		public static final int BUTPRJNEWCRDCLICK = 2;
		public static final int BUTVERVIEWCLICK = 3;
		public static final int BUTVERNEWCRDCLICK = 4;
		public static final int BUTUNTVIEWCLICK = 5;
		public static final int BUTUNTNEWCRDCLICK = 6;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butprjviewclick")) return BUTPRJVIEWCLICK;
			if (s.equals("butprjnewcrdclick")) return BUTPRJNEWCRDCLICK;
			if (s.equals("butverviewclick")) return BUTVERVIEWCLICK;
			if (s.equals("butvernewcrdclick")) return BUTVERNEWCRDCLICK;
			if (s.equals("butuntviewclick")) return BUTUNTVIEWCLICK;
			if (s.equals("butuntnewcrdclick")) return BUTUNTNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTPRJVIEWCLICK) return("ButPrjViewClick");
			if (ix == BUTPRJNEWCRDCLICK) return("ButPrjNewcrdClick");
			if (ix == BUTVERVIEWCLICK) return("ButVerViewClick");
			if (ix == BUTVERNEWCRDCLICK) return("ButVerNewcrdClick");
			if (ix == BUTUNTVIEWCLICK) return("ButUntViewClick");
			if (ix == BUTUNTNEWCRDCLICK) return("ButUntNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeNavDevdev)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTPRJ = 1;
		public static final int NUMFLSTVER = 2;
		public static final int NUMFLSTUNT = 3;

		public ContIac(
					int numFLstPrj
					, int numFLstVer
					, int numFLstUnt
				) {
			this.numFLstPrj = numFLstPrj;
			this.numFLstVer = numFLstVer;
			this.numFLstUnt = numFLstUnt;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTPRJ, NUMFLSTVER, NUMFLSTUNT));
		};

		public int numFLstPrj;
		public int numFLstVer;
		public int numFLstUnt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeNavDevdev");

			String itemtag = "ContitemIacWdbeNavDevdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstPrj = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstPrj", mask, NUMFLSTPRJ);
				numFLstVer = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstVer", mask, NUMFLSTVER);
				numFLstUnt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstUnt", mask, NUMFLSTUNT);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeNavDevdev";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeNavDevdev";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstPrj", numFLstPrj);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstVer", numFLstVer);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstUnt", numFLstUnt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstPrj == comp.numFLstPrj) items.add(NUMFLSTPRJ);
			if (numFLstVer == comp.numFLstVer) items.add(NUMFLSTVER);
			if (numFLstUnt == comp.numFLstUnt) items.add(NUMFLSTUNT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTPRJ, NUMFLSTVER, NUMFLSTUNT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNavDevdev)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTPRJALT = 2;
		public static final int LSTVERALT = 3;
		public static final int LSTUNTALT = 4;
		public static final int LSTPRJNUMFIRSTDISP = 5;
		public static final int LSTVERNUMFIRSTDISP = 6;
		public static final int LSTUNTNUMFIRSTDISP = 7;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstPrjAlt
					, boolean LstVerAlt
					, boolean LstUntAlt
					, int LstPrjNumFirstdisp
					, int LstVerNumFirstdisp
					, int LstUntNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstPrjAlt = LstPrjAlt;
			this.LstVerAlt = LstVerAlt;
			this.LstUntAlt = LstUntAlt;
			this.LstPrjNumFirstdisp = LstPrjNumFirstdisp;
			this.LstVerNumFirstdisp = LstVerNumFirstdisp;
			this.LstUntNumFirstdisp = LstUntNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTPRJALT, LSTVERALT, LSTUNTALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTUNTNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstPrjAlt;
		public boolean LstVerAlt;
		public boolean LstUntAlt;
		public int LstPrjNumFirstdisp;
		public int LstVerNumFirstdisp;
		public int LstUntNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNavDevdev");

			String itemtag = "StatitemAppWdbeNavDevdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstPrjAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrjAlt", mask, LSTPRJALT);
				LstVerAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVerAlt", mask, LSTVERALT);
				LstUntAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUntAlt", mask, LSTUNTALT);
				LstPrjNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrjNumFirstdisp", mask, LSTPRJNUMFIRSTDISP);
				LstVerNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVerNumFirstdisp", mask, LSTVERNUMFIRSTDISP);
				LstUntNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUntNumFirstdisp", mask, LSTUNTNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstPrjAlt == comp.LstPrjAlt) items.add(LSTPRJALT);
			if (LstVerAlt == comp.LstVerAlt) items.add(LSTVERALT);
			if (LstUntAlt == comp.LstUntAlt) items.add(LSTUNTALT);
			if (LstPrjNumFirstdisp == comp.LstPrjNumFirstdisp) items.add(LSTPRJNUMFIRSTDISP);
			if (LstVerNumFirstdisp == comp.LstVerNumFirstdisp) items.add(LSTVERNUMFIRSTDISP);
			if (LstUntNumFirstdisp == comp.LstUntNumFirstdisp) items.add(LSTUNTNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTPRJALT, LSTVERALT, LSTUNTALT, LSTPRJNUMFIRSTDISP, LSTVERNUMFIRSTDISP, LSTUNTNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNavDevdev)
	  */
	public class StatShr extends Block {

		public static final int LSTPRJAVAIL = 1;
		public static final int BUTPRJVIEWACTIVE = 2;
		public static final int LSTVERAVAIL = 3;
		public static final int BUTVERVIEWACTIVE = 4;
		public static final int LSTUNTAVAIL = 5;
		public static final int BUTUNTVIEWACTIVE = 6;
		public static final int BUTUNTNEWCRDACTIVE = 7;

		public StatShr(
					boolean LstPrjAvail
					, boolean ButPrjViewActive
					, boolean LstVerAvail
					, boolean ButVerViewActive
					, boolean LstUntAvail
					, boolean ButUntViewActive
					, boolean ButUntNewcrdActive
				) {
			this.LstPrjAvail = LstPrjAvail;
			this.ButPrjViewActive = ButPrjViewActive;
			this.LstVerAvail = LstVerAvail;
			this.ButVerViewActive = ButVerViewActive;
			this.LstUntAvail = LstUntAvail;
			this.ButUntViewActive = ButUntViewActive;
			this.ButUntNewcrdActive = ButUntNewcrdActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE));
		};

		public boolean LstPrjAvail;
		public boolean ButPrjViewActive;
		public boolean LstVerAvail;
		public boolean ButVerViewActive;
		public boolean LstUntAvail;
		public boolean ButUntViewActive;
		public boolean ButUntNewcrdActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavDevdev");

			String itemtag = "StatitemShrWdbeNavDevdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstPrjAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstPrjAvail", mask, LSTPRJAVAIL);
				ButPrjViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPrjViewActive", mask, BUTPRJVIEWACTIVE);
				LstVerAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstVerAvail", mask, LSTVERAVAIL);
				ButVerViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVerViewActive", mask, BUTVERVIEWACTIVE);
				LstUntAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstUntAvail", mask, LSTUNTAVAIL);
				ButUntViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUntViewActive", mask, BUTUNTVIEWACTIVE);
				ButUntNewcrdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUntNewcrdActive", mask, BUTUNTNEWCRDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstPrjAvail == comp.LstPrjAvail) items.add(LSTPRJAVAIL);
			if (ButPrjViewActive == comp.ButPrjViewActive) items.add(BUTPRJVIEWACTIVE);
			if (LstVerAvail == comp.LstVerAvail) items.add(LSTVERAVAIL);
			if (ButVerViewActive == comp.ButVerViewActive) items.add(BUTVERVIEWACTIVE);
			if (LstUntAvail == comp.LstUntAvail) items.add(LSTUNTAVAIL);
			if (ButUntViewActive == comp.ButUntViewActive) items.add(BUTUNTVIEWACTIVE);
			if (ButUntNewcrdActive == comp.ButUntNewcrdActive) items.add(BUTUNTNEWCRDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTPRJAVAIL, BUTPRJVIEWACTIVE, LSTVERAVAIL, BUTVERVIEWACTIVE, LSTUNTAVAIL, BUTUNTVIEWACTIVE, BUTUNTNEWCRDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavDevdev)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTPRJ = 2;
		public static final int CPTVER = 3;
		public static final int CPTUNT = 4;

		public Tag(
					String Cpt
					, String CptPrj
					, String CptVer
					, String CptUnt
				) {
			this.Cpt = Cpt;
			this.CptPrj = CptPrj;
			this.CptVer = CptVer;
			this.CptUnt = CptUnt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTVER, CPTUNT));
		};

		public String Cpt;
		public String CptPrj;
		public String CptVer;
		public String CptUnt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavDevdev");

			String itemtag = "TagitemWdbeNavDevdev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptPrj = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrj", mask, CPTPRJ);
				CptVer = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVer", mask, CPTVER);
				CptUnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUnt", mask, CPTUNT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptPrj.equals(comp.CptPrj)) items.add(CPTPRJ);
			if (CptVer.equals(comp.CptVer)) items.add(CPTVER);
			if (CptUnt.equals(comp.CptUnt)) items.add(CPTUNT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTPRJ, CPTVER, CPTUNT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeNavDevdevData)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVDEVDEVDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavDevdevData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavDevdevDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVDEVDEVDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavDevdevDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavDevdevData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTPRJ = 3;
		public static final int FEEDFLSTUNT = 4;
		public static final int FEEDFLSTVER = 5;
		public static final int STATAPP = 6;
		public static final int STATSHR = 7;
		public static final int TAG = 8;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVDEVDEVDATA);

			contiac = new ContIac(0, 0, 0);
			feedFLstPrj = new Feed("FeedFLstPrj");
			feedFLstUnt = new Feed("FeedFLstUnt");
			feedFLstVer = new Feed("FeedFLstVer");
			statapp = new StatApp(0, false, false, false, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstPrj;
		public Feed feedFLstUnt;
		public Feed feedFLstVer;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTPRJ)) ss.add("feedFLstPrj");
			if (has(FEEDFLSTUNT)) ss.add("feedFLstUnt");
			if (has(FEEDFLSTVER)) ss.add("feedFLstVer");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavDevdevData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstPrj.readXML(doc, basexpath, true)) add(FEEDFLSTPRJ);
				if (feedFLstUnt.readXML(doc, basexpath, true)) add(FEEDFLSTUNT);
				if (feedFLstVer.readXML(doc, basexpath, true)) add(FEEDFLSTVER);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0);
				feedFLstPrj = new Feed("FeedFLstPrj");
				feedFLstUnt = new Feed("FeedFLstUnt");
				feedFLstVer = new Feed("FeedFLstVer");
				statapp = new StatApp(0, false, false, false, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "");
			};
		};

	};

};
