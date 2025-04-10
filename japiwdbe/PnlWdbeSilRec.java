/**
  * \file PnlWdbeSilRec.java
  * Java API code for job PnlWdbeSilRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeSilRec {
	/**
		* VecVDo (full: VecVWdbeSilRecDo)
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
	  * ContInf (full: ContInfWdbeSilRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeSilRec");

			String itemtag = "ContitemInfWdbeSilRec";

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
	  * StatApp (full: StatAppWdbeSilRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONE1NINTERRUPT = 2;
		public static final int INITDONE1NPERIPHERAL = 3;
		public static final int INITDONESIL1NUNIT = 4;
		public static final int INITDONE1NBANK = 5;
		public static final int INITDONEHK1NMODULE = 6;
		public static final int INITDONEREF1NERROR = 7;
		public static final int INITDONEREF1NSIGNAL = 8;
		public static final int INITDONEHK1NVECTOR = 9;
		public static final int INITDONEREF1NCOMMAND = 10;

		public StatApp(
					boolean initdoneDetail
					, boolean initdone1NInterrupt
					, boolean initdone1NPeripheral
					, boolean initdoneSil1NUnit
					, boolean initdone1NBank
					, boolean initdoneHk1NModule
					, boolean initdoneRef1NError
					, boolean initdoneRef1NSignal
					, boolean initdoneHk1NVector
					, boolean initdoneRef1NCommand
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdone1NInterrupt = initdone1NInterrupt;
			this.initdone1NPeripheral = initdone1NPeripheral;
			this.initdoneSil1NUnit = initdoneSil1NUnit;
			this.initdone1NBank = initdone1NBank;
			this.initdoneHk1NModule = initdoneHk1NModule;
			this.initdoneRef1NError = initdoneRef1NError;
			this.initdoneRef1NSignal = initdoneRef1NSignal;
			this.initdoneHk1NVector = initdoneHk1NVector;
			this.initdoneRef1NCommand = initdoneRef1NCommand;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONE1NINTERRUPT, INITDONE1NPERIPHERAL, INITDONESIL1NUNIT, INITDONE1NBANK, INITDONEHK1NMODULE, INITDONEREF1NERROR, INITDONEREF1NSIGNAL, INITDONEHK1NVECTOR, INITDONEREF1NCOMMAND));
		};

		public boolean initdoneDetail;
		public boolean initdone1NInterrupt;
		public boolean initdone1NPeripheral;
		public boolean initdoneSil1NUnit;
		public boolean initdone1NBank;
		public boolean initdoneHk1NModule;
		public boolean initdoneRef1NError;
		public boolean initdoneRef1NSignal;
		public boolean initdoneHk1NVector;
		public boolean initdoneRef1NCommand;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeSilRec");

			String itemtag = "StatitemAppWdbeSilRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdone1NInterrupt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NInterrupt", mask, INITDONE1NINTERRUPT);
				initdone1NPeripheral = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NPeripheral", mask, INITDONE1NPERIPHERAL);
				initdoneSil1NUnit = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSil1NUnit", mask, INITDONESIL1NUNIT);
				initdone1NBank = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NBank", mask, INITDONE1NBANK);
				initdoneHk1NModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHk1NModule", mask, INITDONEHK1NMODULE);
				initdoneRef1NError = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NError", mask, INITDONEREF1NERROR);
				initdoneRef1NSignal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NSignal", mask, INITDONEREF1NSIGNAL);
				initdoneHk1NVector = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHk1NVector", mask, INITDONEHK1NVECTOR);
				initdoneRef1NCommand = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NCommand", mask, INITDONEREF1NCOMMAND);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdone1NInterrupt == comp.initdone1NInterrupt) items.add(INITDONE1NINTERRUPT);
			if (initdone1NPeripheral == comp.initdone1NPeripheral) items.add(INITDONE1NPERIPHERAL);
			if (initdoneSil1NUnit == comp.initdoneSil1NUnit) items.add(INITDONESIL1NUNIT);
			if (initdone1NBank == comp.initdone1NBank) items.add(INITDONE1NBANK);
			if (initdoneHk1NModule == comp.initdoneHk1NModule) items.add(INITDONEHK1NMODULE);
			if (initdoneRef1NError == comp.initdoneRef1NError) items.add(INITDONEREF1NERROR);
			if (initdoneRef1NSignal == comp.initdoneRef1NSignal) items.add(INITDONEREF1NSIGNAL);
			if (initdoneHk1NVector == comp.initdoneHk1NVector) items.add(INITDONEHK1NVECTOR);
			if (initdoneRef1NCommand == comp.initdoneRef1NCommand) items.add(INITDONEREF1NCOMMAND);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONE1NINTERRUPT, INITDONE1NPERIPHERAL, INITDONESIL1NUNIT, INITDONE1NBANK, INITDONEHK1NMODULE, INITDONEREF1NERROR, INITDONEREF1NSIGNAL, INITDONEHK1NVECTOR, INITDONEREF1NCOMMAND));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeSilRec)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREF1NINTERRUPT = 3;
		public static final int SCRJREF1NPERIPHERAL = 4;
		public static final int SCRJREFSIL1NUNIT = 5;
		public static final int SCRJREF1NBANK = 6;
		public static final int SCRJREFHK1NMODULE = 7;
		public static final int SCRJREFREF1NERROR = 8;
		public static final int SCRJREFREF1NSIGNAL = 9;
		public static final int SCRJREFHK1NVECTOR = 10;
		public static final int SCRJREFREF1NCOMMAND = 11;
		public static final int BUTREGULARIZEACTIVE = 12;

		public StatShr(
					int ixWdbeVExpstate
					, String scrJrefDetail
					, String scrJref1NInterrupt
					, String scrJref1NPeripheral
					, String scrJrefSil1NUnit
					, String scrJref1NBank
					, String scrJrefHk1NModule
					, String scrJrefRef1NError
					, String scrJrefRef1NSignal
					, String scrJrefHk1NVector
					, String scrJrefRef1NCommand
					, boolean ButRegularizeActive
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJref1NInterrupt = scrJref1NInterrupt;
			this.scrJref1NPeripheral = scrJref1NPeripheral;
			this.scrJrefSil1NUnit = scrJrefSil1NUnit;
			this.scrJref1NBank = scrJref1NBank;
			this.scrJrefHk1NModule = scrJrefHk1NModule;
			this.scrJrefRef1NError = scrJrefRef1NError;
			this.scrJrefRef1NSignal = scrJrefRef1NSignal;
			this.scrJrefHk1NVector = scrJrefHk1NVector;
			this.scrJrefRef1NCommand = scrJrefRef1NCommand;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NINTERRUPT, SCRJREF1NPERIPHERAL, SCRJREFSIL1NUNIT, SCRJREF1NBANK, SCRJREFHK1NMODULE, SCRJREFREF1NERROR, SCRJREFREF1NSIGNAL, SCRJREFHK1NVECTOR, SCRJREFREF1NCOMMAND, BUTREGULARIZEACTIVE));
		};

		public int ixWdbeVExpstate;
		public String scrJrefDetail;
		public String scrJref1NInterrupt;
		public String scrJref1NPeripheral;
		public String scrJrefSil1NUnit;
		public String scrJref1NBank;
		public String scrJrefHk1NModule;
		public String scrJrefRef1NError;
		public String scrJrefRef1NSignal;
		public String scrJrefHk1NVector;
		public String scrJrefRef1NCommand;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeSilRec");

			String itemtag = "StatitemShrWdbeSilRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJref1NInterrupt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NInterrupt", mask, SCRJREF1NINTERRUPT);
				scrJref1NPeripheral = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NPeripheral", mask, SCRJREF1NPERIPHERAL);
				scrJrefSil1NUnit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSil1NUnit", mask, SCRJREFSIL1NUNIT);
				scrJref1NBank = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NBank", mask, SCRJREF1NBANK);
				scrJrefHk1NModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHk1NModule", mask, SCRJREFHK1NMODULE);
				scrJrefRef1NError = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NError", mask, SCRJREFREF1NERROR);
				scrJrefRef1NSignal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NSignal", mask, SCRJREFREF1NSIGNAL);
				scrJrefHk1NVector = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHk1NVector", mask, SCRJREFHK1NVECTOR);
				scrJrefRef1NCommand = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NCommand", mask, SCRJREFREF1NCOMMAND);
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
			if (scrJref1NInterrupt.equals(comp.scrJref1NInterrupt)) items.add(SCRJREF1NINTERRUPT);
			if (scrJref1NPeripheral.equals(comp.scrJref1NPeripheral)) items.add(SCRJREF1NPERIPHERAL);
			if (scrJrefSil1NUnit.equals(comp.scrJrefSil1NUnit)) items.add(SCRJREFSIL1NUNIT);
			if (scrJref1NBank.equals(comp.scrJref1NBank)) items.add(SCRJREF1NBANK);
			if (scrJrefHk1NModule.equals(comp.scrJrefHk1NModule)) items.add(SCRJREFHK1NMODULE);
			if (scrJrefRef1NError.equals(comp.scrJrefRef1NError)) items.add(SCRJREFREF1NERROR);
			if (scrJrefRef1NSignal.equals(comp.scrJrefRef1NSignal)) items.add(SCRJREFREF1NSIGNAL);
			if (scrJrefHk1NVector.equals(comp.scrJrefHk1NVector)) items.add(SCRJREFHK1NVECTOR);
			if (scrJrefRef1NCommand.equals(comp.scrJrefRef1NCommand)) items.add(SCRJREFREF1NCOMMAND);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREF1NINTERRUPT, SCRJREF1NPERIPHERAL, SCRJREFSIL1NUNIT, SCRJREF1NBANK, SCRJREFHK1NMODULE, SCRJREFREF1NERROR, SCRJREFREF1NSIGNAL, SCRJREFHK1NVECTOR, SCRJREFREF1NCOMMAND, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeSilRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeSilRec");

			String itemtag = "TagitemWdbeSilRec";

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
		* DpchAppDo (full: DpchAppWdbeSilRecDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBESILRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSilRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeSilRecData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBESILRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeSilRecData");

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
				statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
