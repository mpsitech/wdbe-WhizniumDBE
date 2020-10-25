/**
  * \file PnlWdbeNavCoredev.java
  * Java API code for job PnlWdbeNavCoredev
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavCoredev {
	/**
		* VecVDo (full: VecVWdbeNavCoredevDo)
		*/
	public static class VecVDo {

		public static final int BUTCPRVIEWCLICK = 1;
		public static final int BUTCPRNEWCRDCLICK = 2;
		public static final int BUTCVRVIEWCLICK = 3;
		public static final int BUTCVRNEWCRDCLICK = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butcprviewclick")) return BUTCPRVIEWCLICK;
			if (s.equals("butcprnewcrdclick")) return BUTCPRNEWCRDCLICK;
			if (s.equals("butcvrviewclick")) return BUTCVRVIEWCLICK;
			if (s.equals("butcvrnewcrdclick")) return BUTCVRNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTCPRVIEWCLICK) return("ButCprViewClick");
			if (ix == BUTCPRNEWCRDCLICK) return("ButCprNewcrdClick");
			if (ix == BUTCVRVIEWCLICK) return("ButCvrViewClick");
			if (ix == BUTCVRNEWCRDCLICK) return("ButCvrNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeNavCoredev)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTCPR = 1;
		public static final int NUMFLSTCVR = 2;

		public ContIac(
					int numFLstCpr
					, int numFLstCvr
				) {
			this.numFLstCpr = numFLstCpr;
			this.numFLstCvr = numFLstCvr;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTCPR, NUMFLSTCVR));
		};

		public int numFLstCpr;
		public int numFLstCvr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeNavCoredev");

			String itemtag = "ContitemIacWdbeNavCoredev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstCpr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCpr", mask, NUMFLSTCPR);
				numFLstCvr = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstCvr", mask, NUMFLSTCVR);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeNavCoredev";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeNavCoredev";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCpr", numFLstCpr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstCvr", numFLstCvr);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstCpr == comp.numFLstCpr) items.add(NUMFLSTCPR);
			if (numFLstCvr == comp.numFLstCvr) items.add(NUMFLSTCVR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTCPR, NUMFLSTCVR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNavCoredev)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTCPRALT = 2;
		public static final int LSTCVRALT = 3;
		public static final int LSTCPRNUMFIRSTDISP = 4;
		public static final int LSTCVRNUMFIRSTDISP = 5;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstCprAlt
					, boolean LstCvrAlt
					, int LstCprNumFirstdisp
					, int LstCvrNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstCprAlt = LstCprAlt;
			this.LstCvrAlt = LstCvrAlt;
			this.LstCprNumFirstdisp = LstCprNumFirstdisp;
			this.LstCvrNumFirstdisp = LstCvrNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCPRALT, LSTCVRALT, LSTCPRNUMFIRSTDISP, LSTCVRNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstCprAlt;
		public boolean LstCvrAlt;
		public int LstCprNumFirstdisp;
		public int LstCvrNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNavCoredev");

			String itemtag = "StatitemAppWdbeNavCoredev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstCprAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCprAlt", mask, LSTCPRALT);
				LstCvrAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCvrAlt", mask, LSTCVRALT);
				LstCprNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCprNumFirstdisp", mask, LSTCPRNUMFIRSTDISP);
				LstCvrNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCvrNumFirstdisp", mask, LSTCVRNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstCprAlt == comp.LstCprAlt) items.add(LSTCPRALT);
			if (LstCvrAlt == comp.LstCvrAlt) items.add(LSTCVRALT);
			if (LstCprNumFirstdisp == comp.LstCprNumFirstdisp) items.add(LSTCPRNUMFIRSTDISP);
			if (LstCvrNumFirstdisp == comp.LstCvrNumFirstdisp) items.add(LSTCVRNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTCPRALT, LSTCVRALT, LSTCPRNUMFIRSTDISP, LSTCVRNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNavCoredev)
	  */
	public class StatShr extends Block {

		public static final int LSTCPRAVAIL = 1;
		public static final int BUTCPRVIEWACTIVE = 2;
		public static final int LSTCVRAVAIL = 3;
		public static final int BUTCVRVIEWACTIVE = 4;

		public StatShr(
					boolean LstCprAvail
					, boolean ButCprViewActive
					, boolean LstCvrAvail
					, boolean ButCvrViewActive
				) {
			this.LstCprAvail = LstCprAvail;
			this.ButCprViewActive = ButCprViewActive;
			this.LstCvrAvail = LstCvrAvail;
			this.ButCvrViewActive = ButCvrViewActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTCPRAVAIL, BUTCPRVIEWACTIVE, LSTCVRAVAIL, BUTCVRVIEWACTIVE));
		};

		public boolean LstCprAvail;
		public boolean ButCprViewActive;
		public boolean LstCvrAvail;
		public boolean ButCvrViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavCoredev");

			String itemtag = "StatitemShrWdbeNavCoredev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstCprAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCprAvail", mask, LSTCPRAVAIL);
				ButCprViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCprViewActive", mask, BUTCPRVIEWACTIVE);
				LstCvrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstCvrAvail", mask, LSTCVRAVAIL);
				ButCvrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCvrViewActive", mask, BUTCVRVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstCprAvail == comp.LstCprAvail) items.add(LSTCPRAVAIL);
			if (ButCprViewActive == comp.ButCprViewActive) items.add(BUTCPRVIEWACTIVE);
			if (LstCvrAvail == comp.LstCvrAvail) items.add(LSTCVRAVAIL);
			if (ButCvrViewActive == comp.ButCvrViewActive) items.add(BUTCVRVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTCPRAVAIL, BUTCPRVIEWACTIVE, LSTCVRAVAIL, BUTCVRVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavCoredev)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTCPR = 2;
		public static final int CPTCVR = 3;

		public Tag(
					String Cpt
					, String CptCpr
					, String CptCvr
				) {
			this.Cpt = Cpt;
			this.CptCpr = CptCpr;
			this.CptCvr = CptCvr;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTCPR, CPTCVR));
		};

		public String Cpt;
		public String CptCpr;
		public String CptCvr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavCoredev");

			String itemtag = "TagitemWdbeNavCoredev";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptCpr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCpr", mask, CPTCPR);
				CptCvr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCvr", mask, CPTCVR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptCpr.equals(comp.CptCpr)) items.add(CPTCPR);
			if (CptCvr.equals(comp.CptCvr)) items.add(CPTCVR);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTCPR, CPTCVR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeNavCoredevData)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVCOREDEVDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavCoredevData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavCoredevDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVCOREDEVDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavCoredevDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavCoredevData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTCPR = 3;
		public static final int FEEDFLSTCVR = 4;
		public static final int STATAPP = 5;
		public static final int STATSHR = 6;
		public static final int TAG = 7;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVCOREDEVDATA);

			contiac = new ContIac(0, 0);
			feedFLstCpr = new Feed("FeedFLstCpr");
			feedFLstCvr = new Feed("FeedFLstCvr");
			statapp = new StatApp(0, false, false, 0, 0);
			statshr = new StatShr(false, false, false, false);
			tag = new Tag("", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstCpr;
		public Feed feedFLstCvr;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTCPR)) ss.add("feedFLstCpr");
			if (has(FEEDFLSTCVR)) ss.add("feedFLstCvr");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavCoredevData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstCpr.readXML(doc, basexpath, true)) add(FEEDFLSTCPR);
				if (feedFLstCvr.readXML(doc, basexpath, true)) add(FEEDFLSTCVR);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0);
				feedFLstCpr = new Feed("FeedFLstCpr");
				feedFLstCvr = new Feed("FeedFLstCvr");
				statapp = new StatApp(0, false, false, 0, 0);
				statshr = new StatShr(false, false, false, false);
				tag = new Tag("", "", "");
			};
		};

	};

};

