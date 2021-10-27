/**
  * \file PnlWdbePrcRec.java
  * Java API code for job PnlWdbePrcRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbePrcRec {
	/**
		* VecVDo (full: VecVWdbePrcRecDo)
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
	  * ContInf (full: ContInfWdbePrcRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbePrcRec");

			String itemtag = "ContitemInfWdbePrcRec";

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
	  * StatApp (full: StatAppWdbePrcRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEKHDLTYPE = 2;
		public static final int INITDONEREF1NSENSITIVITY = 3;
		public static final int INITDONEREF1NVARIABLE = 4;
		public static final int INITDONEMGE1NSIGNAL = 5;
		public static final int INITDONEFSMFSM1NFSMSTATE = 6;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneKHdltype
					, boolean initdoneRef1NSensitivity
					, boolean initdoneRef1NVariable
					, boolean initdoneMge1NSignal
					, boolean initdoneFsmFsm1NFsmstate
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneKHdltype = initdoneKHdltype;
			this.initdoneRef1NSensitivity = initdoneRef1NSensitivity;
			this.initdoneRef1NVariable = initdoneRef1NVariable;
			this.initdoneMge1NSignal = initdoneMge1NSignal;
			this.initdoneFsmFsm1NFsmstate = initdoneFsmFsm1NFsmstate;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEREF1NSENSITIVITY, INITDONEREF1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONEFSMFSM1NFSMSTATE));
		};

		public boolean initdoneDetail;
		public boolean initdoneKHdltype;
		public boolean initdoneRef1NSensitivity;
		public boolean initdoneRef1NVariable;
		public boolean initdoneMge1NSignal;
		public boolean initdoneFsmFsm1NFsmstate;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbePrcRec");

			String itemtag = "StatitemAppWdbePrcRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneKHdltype = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneKHdltype", mask, INITDONEKHDLTYPE);
				initdoneRef1NSensitivity = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NSensitivity", mask, INITDONEREF1NSENSITIVITY);
				initdoneRef1NVariable = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NVariable", mask, INITDONEREF1NVARIABLE);
				initdoneMge1NSignal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMge1NSignal", mask, INITDONEMGE1NSIGNAL);
				initdoneFsmFsm1NFsmstate = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneFsmFsm1NFsmstate", mask, INITDONEFSMFSM1NFSMSTATE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneKHdltype == comp.initdoneKHdltype) items.add(INITDONEKHDLTYPE);
			if (initdoneRef1NSensitivity == comp.initdoneRef1NSensitivity) items.add(INITDONEREF1NSENSITIVITY);
			if (initdoneRef1NVariable == comp.initdoneRef1NVariable) items.add(INITDONEREF1NVARIABLE);
			if (initdoneMge1NSignal == comp.initdoneMge1NSignal) items.add(INITDONEMGE1NSIGNAL);
			if (initdoneFsmFsm1NFsmstate == comp.initdoneFsmFsm1NFsmstate) items.add(INITDONEFSMFSM1NFSMSTATE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEREF1NSENSITIVITY, INITDONEREF1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONEFSMFSM1NFSMSTATE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbePrcRec)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFKHDLTYPE = 3;
		public static final int SCRJREFREF1NSENSITIVITY = 4;
		public static final int SCRJREFREF1NVARIABLE = 5;
		public static final int SCRJREFMGE1NSIGNAL = 6;
		public static final int SCRJREFFSMFSM1NFSMSTATE = 7;
		public static final int PNLFSMFSM1NFSMSTATEAVAIL = 8;
		public static final int BUTREGULARIZEACTIVE = 9;

		public StatShr(
					int ixWdbeVExpstate
					, String scrJrefDetail
					, String scrJrefKHdltype
					, String scrJrefRef1NSensitivity
					, String scrJrefRef1NVariable
					, String scrJrefMge1NSignal
					, String scrJrefFsmFsm1NFsmstate
					, boolean pnlfsmfsm1nfsmstateAvail
					, boolean ButRegularizeActive
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefKHdltype = scrJrefKHdltype;
			this.scrJrefRef1NSensitivity = scrJrefRef1NSensitivity;
			this.scrJrefRef1NVariable = scrJrefRef1NVariable;
			this.scrJrefMge1NSignal = scrJrefMge1NSignal;
			this.scrJrefFsmFsm1NFsmstate = scrJrefFsmFsm1NFsmstate;
			this.pnlfsmfsm1nfsmstateAvail = pnlfsmfsm1nfsmstateAvail;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFREF1NSENSITIVITY, SCRJREFREF1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFFSMFSM1NFSMSTATE, PNLFSMFSM1NFSMSTATEAVAIL, BUTREGULARIZEACTIVE));
		};

		public int ixWdbeVExpstate;
		public String scrJrefDetail;
		public String scrJrefKHdltype;
		public String scrJrefRef1NSensitivity;
		public String scrJrefRef1NVariable;
		public String scrJrefMge1NSignal;
		public String scrJrefFsmFsm1NFsmstate;
		public boolean pnlfsmfsm1nfsmstateAvail;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbePrcRec");

			String itemtag = "StatitemShrWdbePrcRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefKHdltype = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefKHdltype", mask, SCRJREFKHDLTYPE);
				scrJrefRef1NSensitivity = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NSensitivity", mask, SCRJREFREF1NSENSITIVITY);
				scrJrefRef1NVariable = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NVariable", mask, SCRJREFREF1NVARIABLE);
				scrJrefMge1NSignal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMge1NSignal", mask, SCRJREFMGE1NSIGNAL);
				scrJrefFsmFsm1NFsmstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefFsmFsm1NFsmstate", mask, SCRJREFFSMFSM1NFSMSTATE);
				pnlfsmfsm1nfsmstateAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlfsmfsm1nfsmstateAvail", mask, PNLFSMFSM1NFSMSTATEAVAIL);
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
			if (scrJrefKHdltype.equals(comp.scrJrefKHdltype)) items.add(SCRJREFKHDLTYPE);
			if (scrJrefRef1NSensitivity.equals(comp.scrJrefRef1NSensitivity)) items.add(SCRJREFREF1NSENSITIVITY);
			if (scrJrefRef1NVariable.equals(comp.scrJrefRef1NVariable)) items.add(SCRJREFREF1NVARIABLE);
			if (scrJrefMge1NSignal.equals(comp.scrJrefMge1NSignal)) items.add(SCRJREFMGE1NSIGNAL);
			if (scrJrefFsmFsm1NFsmstate.equals(comp.scrJrefFsmFsm1NFsmstate)) items.add(SCRJREFFSMFSM1NFSMSTATE);
			if (pnlfsmfsm1nfsmstateAvail == comp.pnlfsmfsm1nfsmstateAvail) items.add(PNLFSMFSM1NFSMSTATEAVAIL);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFREF1NSENSITIVITY, SCRJREFREF1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFFSMFSM1NFSMSTATE, PNLFSMFSM1NFSMSTATEAVAIL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbePrcRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbePrcRec");

			String itemtag = "TagitemWdbePrcRec";

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
		* DpchAppDo (full: DpchAppWdbePrcRecDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEPRCRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbePrcRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbePrcRecData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEPRCRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", false, false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbePrcRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", false, false);
				tag = new Tag("");
			};
		};

	};

};
