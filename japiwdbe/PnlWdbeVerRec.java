/**
  * \file PnlWdbeVerRec.java
  * Java API code for job PnlWdbeVerRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeVerRec {
	/**
		* VecVDo (full: VecVWdbeVerRecDo)
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
	  * ContInf (full: ContInfWdbeVerRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeVerRec");

			String itemtag = "ContitemInfWdbeVerRec";

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
	  * StatApp (full: StatAppWdbeVerRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONE1NRELEASE = 2;
		public static final int INITDONE1NSYSTEM = 3;
		public static final int INITDONEBVR1NVERSION = 4;
		public static final int INITDONE1NUNIT = 5;
		public static final int INITDONEREF1NFILE = 6;
		public static final int INITDONEMNLIBRARY = 7;

		public StatApp(
					boolean initdoneDetail
					, boolean initdone1NRelease
					, boolean initdone1NSystem
					, boolean initdoneBvr1NVersion
					, boolean initdone1NUnit
					, boolean initdoneRef1NFile
					, boolean initdoneMNLibrary
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdone1NRelease = initdone1NRelease;
			this.initdone1NSystem = initdone1NSystem;
			this.initdoneBvr1NVersion = initdoneBvr1NVersion;
			this.initdone1NUnit = initdone1NUnit;
			this.initdoneRef1NFile = initdoneRef1NFile;
			this.initdoneMNLibrary = initdoneMNLibrary;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONE1NRELEASE, INITDONE1NSYSTEM, INITDONEBVR1NVERSION, INITDONE1NUNIT, INITDONEREF1NFILE, INITDONEMNLIBRARY));
		};

		public boolean initdoneDetail;
		public boolean initdone1NRelease;
		public boolean initdone1NSystem;
		public boolean initdoneBvr1NVersion;
		public boolean initdone1NUnit;
		public boolean initdoneRef1NFile;
		public boolean initdoneMNLibrary;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeVerRec");

			String itemtag = "StatitemAppWdbeVerRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdone1NRelease = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NRelease", mask, INITDONE1NRELEASE);
				initdone1NSystem = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NSystem", mask, INITDONE1NSYSTEM);
				initdoneBvr1NVersion = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneBvr1NVersion", mask, INITDONEBVR1NVERSION);
				initdone1NUnit = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NUnit", mask, INITDONE1NUNIT);
				initdoneRef1NFile = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", mask, INITDONEREF1NFILE);
				initdoneMNLibrary = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNLibrary", mask, INITDONEMNLIBRARY);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdone1NRelease == comp.initdone1NRelease) items.add(INITDONE1NRELEASE);
			if (initdone1NSystem == comp.initdone1NSystem) items.add(INITDONE1NSYSTEM);
			if (initdoneBvr1NVersion == comp.initdoneBvr1NVersion) items.add(INITDONEBVR1NVERSION);
			if (initdone1NUnit == comp.initdone1NUnit) items.add(INITDONE1NUNIT);
			if (initdoneRef1NFile == comp.initdoneRef1NFile) items.add(INITDONEREF1NFILE);
			if (initdoneMNLibrary == comp.initdoneMNLibrary) items.add(INITDONEMNLIBRARY);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONE1NRELEASE, INITDONE1NSYSTEM, INITDONEBVR1NVERSION, INITDONE1NUNIT, INITDONEREF1NFILE, INITDONEMNLIBRARY));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeVerRec)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREF1NRELEASE = 3;
		public static final int SCRJREF1NSYSTEM = 4;
		public static final int SCRJREFBVR1NVERSION = 5;
		public static final int SCRJREF1NUNIT = 6;
		public static final int SCRJREFREF1NFILE = 7;
		public static final int SCRJREFMNLIBRARY = 8;
		public static final int BUTREGULARIZEACTIVE = 9;

		public StatShr(
					int ixWdbeVExpstate
					, String scrJrefDetail
					, String scrJref1NRelease
					, String scrJref1NSystem
					, String scrJrefBvr1NVersion
					, String scrJref1NUnit
					, String scrJrefRef1NFile
					, String scrJrefMNLibrary
					, boolean ButRegularizeActive
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJref1NRelease = scrJref1NRelease;
			this.scrJref1NSystem = scrJref1NSystem;
			this.scrJrefBvr1NVersion = scrJrefBvr1NVersion;
			this.scrJref1NUnit = scrJref1NUnit;
			this.scrJrefRef1NFile = scrJrefRef1NFile;
			this.scrJrefMNLibrary = scrJrefMNLibrary;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NRELEASE, SCRJREF1NSYSTEM, SCRJREFBVR1NVERSION, SCRJREF1NUNIT, SCRJREFREF1NFILE, SCRJREFMNLIBRARY, BUTREGULARIZEACTIVE));
		};

		public int ixWdbeVExpstate;
		public String scrJrefDetail;
		public String scrJref1NRelease;
		public String scrJref1NSystem;
		public String scrJrefBvr1NVersion;
		public String scrJref1NUnit;
		public String scrJrefRef1NFile;
		public String scrJrefMNLibrary;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeVerRec");

			String itemtag = "StatitemShrWdbeVerRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJref1NRelease = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NRelease", mask, SCRJREF1NRELEASE);
				scrJref1NSystem = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NSystem", mask, SCRJREF1NSYSTEM);
				scrJrefBvr1NVersion = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefBvr1NVersion", mask, SCRJREFBVR1NVERSION);
				scrJref1NUnit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NUnit", mask, SCRJREF1NUNIT);
				scrJrefRef1NFile = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", mask, SCRJREFREF1NFILE);
				scrJrefMNLibrary = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNLibrary", mask, SCRJREFMNLIBRARY);
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
			if (scrJref1NRelease.equals(comp.scrJref1NRelease)) items.add(SCRJREF1NRELEASE);
			if (scrJref1NSystem.equals(comp.scrJref1NSystem)) items.add(SCRJREF1NSYSTEM);
			if (scrJrefBvr1NVersion.equals(comp.scrJrefBvr1NVersion)) items.add(SCRJREFBVR1NVERSION);
			if (scrJref1NUnit.equals(comp.scrJref1NUnit)) items.add(SCRJREF1NUNIT);
			if (scrJrefRef1NFile.equals(comp.scrJrefRef1NFile)) items.add(SCRJREFREF1NFILE);
			if (scrJrefMNLibrary.equals(comp.scrJrefMNLibrary)) items.add(SCRJREFMNLIBRARY);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NRELEASE, SCRJREF1NSYSTEM, SCRJREFBVR1NVERSION, SCRJREF1NUNIT, SCRJREFREF1NFILE, SCRJREFMNLIBRARY, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeVerRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeVerRec");

			String itemtag = "TagitemWdbeVerRec";

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
		* DpchAppDo (full: DpchAppWdbeVerRecDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEVERRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeVerRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeVerRecData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEVERRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeVerRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
