/**
  * \file PnlWdbeCvrRec.java
  * Java API code for job PnlWdbeCvrRec
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeCvrRec {
	/**
		* VecVDo (full: VecVWdbeCvrRecDo)
		*/
	public static class VecVDo {

		public static final int BUTMINIMIZECLICK = 1;
		public static final int BUTREGULARIZECLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butminimizeclick")) return BUTMINIMIZECLICK;
			if (s.equals("butregularizeclick")) return BUTREGULARIZECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
			if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

			return "";
		};

	};

	/**
	  * ContInf (full: ContInfWdbeCvrRec)
	  */
	public class ContInf extends Block {

		public static final int TXTREF = 1;

		public ContInf(
					String TxtRef
				) {
			this.TxtRef = TxtRef;

			mask = new HashSet<Integer>(Arrays.asList(TXTREF));
		};

		public String TxtRef;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeCvrRec");

			String itemtag = "ContitemInfWdbeCvrRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtRef = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtRef", mask, TXTREF);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtRef.equals(comp.TxtRef)) items.add(TXTREF);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTREF));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeCvrRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEAIP = 2;
		public static final int INITDONEAPLH = 3;
		public static final int INITDONEBCV1NCOREVERSION = 4;
		public static final int INITDONEHK1NMODULE = 5;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneAIp
					, boolean initdoneAPlh
					, boolean initdoneBcv1NCoreversion
					, boolean initdoneHk1NModule
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneAIp = initdoneAIp;
			this.initdoneAPlh = initdoneAPlh;
			this.initdoneBcv1NCoreversion = initdoneBcv1NCoreversion;
			this.initdoneHk1NModule = initdoneHk1NModule;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAIP, INITDONEAPLH, INITDONEBCV1NCOREVERSION, INITDONEHK1NMODULE));
		};

		public boolean initdoneDetail;
		public boolean initdoneAIp;
		public boolean initdoneAPlh;
		public boolean initdoneBcv1NCoreversion;
		public boolean initdoneHk1NModule;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeCvrRec");

			String itemtag = "StatitemAppWdbeCvrRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneAIp = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAIp", mask, INITDONEAIP);
				initdoneAPlh = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAPlh", mask, INITDONEAPLH);
				initdoneBcv1NCoreversion = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneBcv1NCoreversion", mask, INITDONEBCV1NCOREVERSION);
				initdoneHk1NModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHk1NModule", mask, INITDONEHK1NMODULE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneAIp == comp.initdoneAIp) items.add(INITDONEAIP);
			if (initdoneAPlh == comp.initdoneAPlh) items.add(INITDONEAPLH);
			if (initdoneBcv1NCoreversion == comp.initdoneBcv1NCoreversion) items.add(INITDONEBCV1NCOREVERSION);
			if (initdoneHk1NModule == comp.initdoneHk1NModule) items.add(INITDONEHK1NMODULE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEAIP, INITDONEAPLH, INITDONEBCV1NCOREVERSION, INITDONEHK1NMODULE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeCvrRec)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFAIP = 3;
		public static final int SCRJREFAPLH = 4;
		public static final int SCRJREFBCV1NCOREVERSION = 5;
		public static final int SCRJREFHK1NMODULE = 6;
		public static final int BUTREGULARIZEACTIVE = 7;

		public StatShr(
					int ixWdbeVExpstate
					, String scrJrefDetail
					, String scrJrefAIp
					, String scrJrefAPlh
					, String scrJrefBcv1NCoreversion
					, String scrJrefHk1NModule
					, boolean ButRegularizeActive
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefAIp = scrJrefAIp;
			this.scrJrefAPlh = scrJrefAPlh;
			this.scrJrefBcv1NCoreversion = scrJrefBcv1NCoreversion;
			this.scrJrefHk1NModule = scrJrefHk1NModule;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFAIP, SCRJREFAPLH, SCRJREFBCV1NCOREVERSION, SCRJREFHK1NMODULE, BUTREGULARIZEACTIVE));
		};

		public int ixWdbeVExpstate;
		public String scrJrefDetail;
		public String scrJrefAIp;
		public String scrJrefAPlh;
		public String scrJrefBcv1NCoreversion;
		public String scrJrefHk1NModule;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeCvrRec");

			String itemtag = "StatitemShrWdbeCvrRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefAIp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAIp", mask, SCRJREFAIP);
				scrJrefAPlh = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAPlh", mask, SCRJREFAPLH);
				scrJrefBcv1NCoreversion = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefBcv1NCoreversion", mask, SCRJREFBCV1NCOREVERSION);
				scrJrefHk1NModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHk1NModule", mask, SCRJREFHK1NMODULE);
				ButRegularizeActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", mask, BUTREGULARIZEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (scrJrefDetail.equals(comp.scrJrefDetail)) items.add(SCRJREFDETAIL);
			if (scrJrefAIp.equals(comp.scrJrefAIp)) items.add(SCRJREFAIP);
			if (scrJrefAPlh.equals(comp.scrJrefAPlh)) items.add(SCRJREFAPLH);
			if (scrJrefBcv1NCoreversion.equals(comp.scrJrefBcv1NCoreversion)) items.add(SCRJREFBCV1NCOREVERSION);
			if (scrJrefHk1NModule.equals(comp.scrJrefHk1NModule)) items.add(SCRJREFHK1NMODULE);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFAIP, SCRJREFAPLH, SCRJREFBCV1NCOREVERSION, SCRJREFHK1NMODULE, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeCvrRec)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;

		public Tag(
					String Cpt
				) {
			this.Cpt = Cpt;

			mask = new HashSet<Integer>(Arrays.asList(CPT));
		};

		public String Cpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeCvrRec");

			String itemtag = "TagitemWdbeCvrRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeCvrRecDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBECVRRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeCvrRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeCvrRecData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBECVRRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", false);
			tag = new Tag("");
		};

		public ContInf continf;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTINF)) ss.add("continf");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeCvrRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};

