/**
  * \file PnlWdbeNavAuxfct.java
  * Java API code for job PnlWdbeNavAuxfct
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavAuxfct {
	/**
		* VecVDo (full: VecVWdbeNavAuxfctDo)
		*/
	public static class VecVDo {

		public static final int BUTIDFNEWCRDCLICK = 1;
		public static final int BUTUTLNEWCRDCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butidfnewcrdclick")) return BUTIDFNEWCRDCLICK;
			if (s.equals("bututlnewcrdclick")) return BUTUTLNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTIDFNEWCRDCLICK) return("ButIdfNewcrdClick");
			if (ix == BUTUTLNEWCRDCLICK) return("ButUtlNewcrdClick");

			return "";
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNavAuxfct)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNavAuxfct");

			String itemtag = "StatitemAppWdbeNavAuxfct";

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
	  * StatShr (full: StatShrWdbeNavAuxfct)
	  */
	public class StatShr extends Block {

		public static final int BUTIDFNEWCRDAVAIL = 1;
		public static final int BUTUTLNEWCRDAVAIL = 2;

		public StatShr(
					boolean ButIdfNewcrdAvail
					, boolean ButUtlNewcrdAvail
				) {
			this.ButIdfNewcrdAvail = ButIdfNewcrdAvail;
			this.ButUtlNewcrdAvail = ButUtlNewcrdAvail;

			mask = new HashSet<Integer>(Arrays.asList(BUTIDFNEWCRDAVAIL, BUTUTLNEWCRDAVAIL));
		};

		public boolean ButIdfNewcrdAvail;
		public boolean ButUtlNewcrdAvail;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavAuxfct");

			String itemtag = "StatitemShrWdbeNavAuxfct";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButIdfNewcrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButIdfNewcrdAvail", mask, BUTIDFNEWCRDAVAIL);
				ButUtlNewcrdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButUtlNewcrdAvail", mask, BUTUTLNEWCRDAVAIL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButIdfNewcrdAvail == comp.ButIdfNewcrdAvail) items.add(BUTIDFNEWCRDAVAIL);
			if (ButUtlNewcrdAvail == comp.ButUtlNewcrdAvail) items.add(BUTUTLNEWCRDAVAIL);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTIDFNEWCRDAVAIL, BUTUTLNEWCRDAVAIL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavAuxfct)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTIDF = 2;
		public static final int CPTUTL = 3;

		public Tag(
					String Cpt
					, String CptIdf
					, String CptUtl
				) {
			this.Cpt = Cpt;
			this.CptIdf = CptIdf;
			this.CptUtl = CptUtl;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTIDF, CPTUTL));
		};

		public String Cpt;
		public String CptIdf;
		public String CptUtl;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavAuxfct");

			String itemtag = "TagitemWdbeNavAuxfct";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptIdf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptIdf", mask, CPTIDF);
				CptUtl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptUtl", mask, CPTUTL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptIdf.equals(comp.CptIdf)) items.add(CPTIDF);
			if (CptUtl.equals(comp.CptUtl)) items.add(CPTUTL);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTIDF, CPTUTL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavAuxfctDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVAUXFCTDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavAuxfctDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavAuxfctData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int STATAPP = 2;
		public static final int STATSHR = 3;
		public static final int TAG = 4;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVAUXFCTDATA);

			statapp = new StatApp(0);
			statshr = new StatShr(false, false);
			tag = new Tag("", "", "");
		};

		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavAuxfctData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				statapp = new StatApp(0);
				statshr = new StatShr(false, false);
				tag = new Tag("", "", "");
			};
		};

	};

};
