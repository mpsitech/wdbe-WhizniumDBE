/**
  * \file PnlWdbeUntRec.java
  * Java API code for job PnlWdbeUntRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeUntRec {
	/**
		* VecVDo (full: VecVWdbeUntRecDo)
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
	  * ContInf (full: ContInfWdbeUntRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeUntRec");

			String itemtag = "ContitemInfWdbeUntRec";

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
	  * StatApp (full: StatAppWdbeUntRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONESIL1NUNIT = 2;
		public static final int INITDONE1NPERIPHERAL = 3;
		public static final int INITDONE1NBANK = 4;
		public static final int INITDONEFWD1NCONTROLLER = 5;
		public static final int INITDONE1NTARGET = 6;
		public static final int INITDONEHK1NVECTOR = 7;
		public static final int INITDONEHK1NMODULE = 8;
		public static final int INITDONEREF1NCOMMAND = 9;
		public static final int INITDONEREF1NERROR = 10;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneSil1NUnit
					, boolean initdone1NPeripheral
					, boolean initdone1NBank
					, boolean initdoneFwd1NController
					, boolean initdone1NTarget
					, boolean initdoneHk1NVector
					, boolean initdoneHk1NModule
					, boolean initdoneRef1NCommand
					, boolean initdoneRef1NError
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneSil1NUnit = initdoneSil1NUnit;
			this.initdone1NPeripheral = initdone1NPeripheral;
			this.initdone1NBank = initdone1NBank;
			this.initdoneFwd1NController = initdoneFwd1NController;
			this.initdone1NTarget = initdone1NTarget;
			this.initdoneHk1NVector = initdoneHk1NVector;
			this.initdoneHk1NModule = initdoneHk1NModule;
			this.initdoneRef1NCommand = initdoneRef1NCommand;
			this.initdoneRef1NError = initdoneRef1NError;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONESIL1NUNIT, INITDONE1NPERIPHERAL, INITDONE1NBANK, INITDONEFWD1NCONTROLLER, INITDONE1NTARGET, INITDONEHK1NVECTOR, INITDONEHK1NMODULE, INITDONEREF1NCOMMAND, INITDONEREF1NERROR));
		};

		public boolean initdoneDetail;
		public boolean initdoneSil1NUnit;
		public boolean initdone1NPeripheral;
		public boolean initdone1NBank;
		public boolean initdoneFwd1NController;
		public boolean initdone1NTarget;
		public boolean initdoneHk1NVector;
		public boolean initdoneHk1NModule;
		public boolean initdoneRef1NCommand;
		public boolean initdoneRef1NError;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeUntRec");

			String itemtag = "StatitemAppWdbeUntRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneSil1NUnit = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSil1NUnit", mask, INITDONESIL1NUNIT);
				initdone1NPeripheral = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NPeripheral", mask, INITDONE1NPERIPHERAL);
				initdone1NBank = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NBank", mask, INITDONE1NBANK);
				initdoneFwd1NController = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneFwd1NController", mask, INITDONEFWD1NCONTROLLER);
				initdone1NTarget = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NTarget", mask, INITDONE1NTARGET);
				initdoneHk1NVector = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHk1NVector", mask, INITDONEHK1NVECTOR);
				initdoneHk1NModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHk1NModule", mask, INITDONEHK1NMODULE);
				initdoneRef1NCommand = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NCommand", mask, INITDONEREF1NCOMMAND);
				initdoneRef1NError = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NError", mask, INITDONEREF1NERROR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneSil1NUnit == comp.initdoneSil1NUnit) items.add(INITDONESIL1NUNIT);
			if (initdone1NPeripheral == comp.initdone1NPeripheral) items.add(INITDONE1NPERIPHERAL);
			if (initdone1NBank == comp.initdone1NBank) items.add(INITDONE1NBANK);
			if (initdoneFwd1NController == comp.initdoneFwd1NController) items.add(INITDONEFWD1NCONTROLLER);
			if (initdone1NTarget == comp.initdone1NTarget) items.add(INITDONE1NTARGET);
			if (initdoneHk1NVector == comp.initdoneHk1NVector) items.add(INITDONEHK1NVECTOR);
			if (initdoneHk1NModule == comp.initdoneHk1NModule) items.add(INITDONEHK1NMODULE);
			if (initdoneRef1NCommand == comp.initdoneRef1NCommand) items.add(INITDONEREF1NCOMMAND);
			if (initdoneRef1NError == comp.initdoneRef1NError) items.add(INITDONEREF1NERROR);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONESIL1NUNIT, INITDONE1NPERIPHERAL, INITDONE1NBANK, INITDONEFWD1NCONTROLLER, INITDONE1NTARGET, INITDONEHK1NVECTOR, INITDONEHK1NMODULE, INITDONEREF1NCOMMAND, INITDONEREF1NERROR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeUntRec)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFSIL1NUNIT = 3;
		public static final int PNLSIL1NUNITAVAIL = 4;
		public static final int SCRJREF1NPERIPHERAL = 5;
		public static final int SCRJREF1NBANK = 6;
		public static final int SCRJREFFWD1NCONTROLLER = 7;
		public static final int SCRJREF1NTARGET = 8;
		public static final int SCRJREFHK1NVECTOR = 9;
		public static final int SCRJREFHK1NMODULE = 10;
		public static final int SCRJREFREF1NCOMMAND = 11;
		public static final int SCRJREFREF1NERROR = 12;
		public static final int BUTREGULARIZEACTIVE = 13;

		public StatShr(
					int ixWdbeVExpstate
					, String scrJrefDetail
					, String scrJrefSil1NUnit
					, boolean pnlsil1nunitAvail
					, String scrJref1NPeripheral
					, String scrJref1NBank
					, String scrJrefFwd1NController
					, String scrJref1NTarget
					, String scrJrefHk1NVector
					, String scrJrefHk1NModule
					, String scrJrefRef1NCommand
					, String scrJrefRef1NError
					, boolean ButRegularizeActive
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefSil1NUnit = scrJrefSil1NUnit;
			this.pnlsil1nunitAvail = pnlsil1nunitAvail;
			this.scrJref1NPeripheral = scrJref1NPeripheral;
			this.scrJref1NBank = scrJref1NBank;
			this.scrJrefFwd1NController = scrJrefFwd1NController;
			this.scrJref1NTarget = scrJref1NTarget;
			this.scrJrefHk1NVector = scrJrefHk1NVector;
			this.scrJrefHk1NModule = scrJrefHk1NModule;
			this.scrJrefRef1NCommand = scrJrefRef1NCommand;
			this.scrJrefRef1NError = scrJrefRef1NError;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFSIL1NUNIT, PNLSIL1NUNITAVAIL, SCRJREF1NPERIPHERAL, SCRJREF1NBANK, SCRJREFFWD1NCONTROLLER, SCRJREF1NTARGET, SCRJREFHK1NVECTOR, SCRJREFHK1NMODULE, SCRJREFREF1NCOMMAND, SCRJREFREF1NERROR, BUTREGULARIZEACTIVE));
		};

		public int ixWdbeVExpstate;
		public String scrJrefDetail;
		public String scrJrefSil1NUnit;
		public boolean pnlsil1nunitAvail;
		public String scrJref1NPeripheral;
		public String scrJref1NBank;
		public String scrJrefFwd1NController;
		public String scrJref1NTarget;
		public String scrJrefHk1NVector;
		public String scrJrefHk1NModule;
		public String scrJrefRef1NCommand;
		public String scrJrefRef1NError;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeUntRec");

			String itemtag = "StatitemShrWdbeUntRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefSil1NUnit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSil1NUnit", mask, SCRJREFSIL1NUNIT);
				pnlsil1nunitAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlsil1nunitAvail", mask, PNLSIL1NUNITAVAIL);
				scrJref1NPeripheral = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NPeripheral", mask, SCRJREF1NPERIPHERAL);
				scrJref1NBank = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NBank", mask, SCRJREF1NBANK);
				scrJrefFwd1NController = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefFwd1NController", mask, SCRJREFFWD1NCONTROLLER);
				scrJref1NTarget = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NTarget", mask, SCRJREF1NTARGET);
				scrJrefHk1NVector = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVector", mask, SCRJREFHK1NVECTOR);
				scrJrefHk1NModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHk1NModule", mask, SCRJREFHK1NMODULE);
				scrJrefRef1NCommand = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NCommand", mask, SCRJREFREF1NCOMMAND);
				scrJrefRef1NError = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NError", mask, SCRJREFREF1NERROR);
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
			if (scrJrefSil1NUnit.equals(comp.scrJrefSil1NUnit)) items.add(SCRJREFSIL1NUNIT);
			if (pnlsil1nunitAvail == comp.pnlsil1nunitAvail) items.add(PNLSIL1NUNITAVAIL);
			if (scrJref1NPeripheral.equals(comp.scrJref1NPeripheral)) items.add(SCRJREF1NPERIPHERAL);
			if (scrJref1NBank.equals(comp.scrJref1NBank)) items.add(SCRJREF1NBANK);
			if (scrJrefFwd1NController.equals(comp.scrJrefFwd1NController)) items.add(SCRJREFFWD1NCONTROLLER);
			if (scrJref1NTarget.equals(comp.scrJref1NTarget)) items.add(SCRJREF1NTARGET);
			if (scrJrefHk1NVector.equals(comp.scrJrefHk1NVector)) items.add(SCRJREFHK1NVECTOR);
			if (scrJrefHk1NModule.equals(comp.scrJrefHk1NModule)) items.add(SCRJREFHK1NMODULE);
			if (scrJrefRef1NCommand.equals(comp.scrJrefRef1NCommand)) items.add(SCRJREFREF1NCOMMAND);
			if (scrJrefRef1NError.equals(comp.scrJrefRef1NError)) items.add(SCRJREFREF1NERROR);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFSIL1NUNIT, PNLSIL1NUNITAVAIL, SCRJREF1NPERIPHERAL, SCRJREF1NBANK, SCRJREFFWD1NCONTROLLER, SCRJREF1NTARGET, SCRJREFHK1NVECTOR, SCRJREFHK1NMODULE, SCRJREFREF1NCOMMAND, SCRJREFREF1NERROR, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeUntRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeUntRec");

			String itemtag = "TagitemWdbeUntRec";

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
		* DpchAppDo (full: DpchAppWdbeUntRecDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEUNTRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeUntRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeUntRecData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEUNTRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", false, "", "", "", "", "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeUntRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", false, "", "", "", "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
