/**
  * \file PnlWdbeMtpRec.java
  * Java API code for job PnlWdbeMtpRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeMtpRec {
	/**
		* VecVDo (full: VecVWdbeMtpRecDo)
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
	  * ContInf (full: ContInfWdbeMtpRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeMtpRec");

			String itemtag = "ContitemInfWdbeMtpRec";

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
	  * StatApp (full: StatAppWdbeMtpRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEKPARKEY = 2;
		public static final int INITDONEKHDLTYPE = 3;
		public static final int INITDONEAPAR = 4;
		public static final int INITDONEHSM1NPIPELINE = 5;
		public static final int INITDONEMDL1NPORT = 6;
		public static final int INITDONETPL1NMODULE = 7;
		public static final int INITDONEMDL1NGENERIC = 8;
		public static final int INITDONESUP1NMODULE = 9;
		public static final int INITDONEREF1NSENSITIVITY = 10;
		public static final int INITDONEREF1NVARIABLE = 11;
		public static final int INITDONEMGE1NSIGNAL = 12;
		public static final int INITDONEREF1NFILE = 13;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneKParKey
					, boolean initdoneKHdltype
					, boolean initdoneAPar
					, boolean initdoneHsm1NPipeline
					, boolean initdoneMdl1NPort
					, boolean initdoneTpl1NModule
					, boolean initdoneMdl1NGeneric
					, boolean initdoneSup1NModule
					, boolean initdoneRef1NSensitivity
					, boolean initdoneRef1NVariable
					, boolean initdoneMge1NSignal
					, boolean initdoneRef1NFile
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneKParKey = initdoneKParKey;
			this.initdoneKHdltype = initdoneKHdltype;
			this.initdoneAPar = initdoneAPar;
			this.initdoneHsm1NPipeline = initdoneHsm1NPipeline;
			this.initdoneMdl1NPort = initdoneMdl1NPort;
			this.initdoneTpl1NModule = initdoneTpl1NModule;
			this.initdoneMdl1NGeneric = initdoneMdl1NGeneric;
			this.initdoneSup1NModule = initdoneSup1NModule;
			this.initdoneRef1NSensitivity = initdoneRef1NSensitivity;
			this.initdoneRef1NVariable = initdoneRef1NVariable;
			this.initdoneMge1NSignal = initdoneMge1NSignal;
			this.initdoneRef1NFile = initdoneRef1NFile;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEKPARKEY, INITDONEKHDLTYPE, INITDONEAPAR, INITDONEHSM1NPIPELINE, INITDONEMDL1NPORT, INITDONETPL1NMODULE, INITDONEMDL1NGENERIC, INITDONESUP1NMODULE, INITDONEREF1NSENSITIVITY, INITDONEREF1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONEREF1NFILE));
		};

		public boolean initdoneDetail;
		public boolean initdoneKParKey;
		public boolean initdoneKHdltype;
		public boolean initdoneAPar;
		public boolean initdoneHsm1NPipeline;
		public boolean initdoneMdl1NPort;
		public boolean initdoneTpl1NModule;
		public boolean initdoneMdl1NGeneric;
		public boolean initdoneSup1NModule;
		public boolean initdoneRef1NSensitivity;
		public boolean initdoneRef1NVariable;
		public boolean initdoneMge1NSignal;
		public boolean initdoneRef1NFile;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeMtpRec");

			String itemtag = "StatitemAppWdbeMtpRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneKParKey = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneKParKey", mask, INITDONEKPARKEY);
				initdoneKHdltype = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneKHdltype", mask, INITDONEKHDLTYPE);
				initdoneAPar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAPar", mask, INITDONEAPAR);
				initdoneHsm1NPipeline = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHsm1NPipeline", mask, INITDONEHSM1NPIPELINE);
				initdoneMdl1NPort = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMdl1NPort", mask, INITDONEMDL1NPORT);
				initdoneTpl1NModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneTpl1NModule", mask, INITDONETPL1NMODULE);
				initdoneMdl1NGeneric = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMdl1NGeneric", mask, INITDONEMDL1NGENERIC);
				initdoneSup1NModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSup1NModule", mask, INITDONESUP1NMODULE);
				initdoneRef1NSensitivity = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NSensitivity", mask, INITDONEREF1NSENSITIVITY);
				initdoneRef1NVariable = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NVariable", mask, INITDONEREF1NVARIABLE);
				initdoneMge1NSignal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMge1NSignal", mask, INITDONEMGE1NSIGNAL);
				initdoneRef1NFile = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NFile", mask, INITDONEREF1NFILE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdoneDetail == comp.initdoneDetail) items.add(INITDONEDETAIL);
			if (initdoneKParKey == comp.initdoneKParKey) items.add(INITDONEKPARKEY);
			if (initdoneKHdltype == comp.initdoneKHdltype) items.add(INITDONEKHDLTYPE);
			if (initdoneAPar == comp.initdoneAPar) items.add(INITDONEAPAR);
			if (initdoneHsm1NPipeline == comp.initdoneHsm1NPipeline) items.add(INITDONEHSM1NPIPELINE);
			if (initdoneMdl1NPort == comp.initdoneMdl1NPort) items.add(INITDONEMDL1NPORT);
			if (initdoneTpl1NModule == comp.initdoneTpl1NModule) items.add(INITDONETPL1NMODULE);
			if (initdoneMdl1NGeneric == comp.initdoneMdl1NGeneric) items.add(INITDONEMDL1NGENERIC);
			if (initdoneSup1NModule == comp.initdoneSup1NModule) items.add(INITDONESUP1NMODULE);
			if (initdoneRef1NSensitivity == comp.initdoneRef1NSensitivity) items.add(INITDONEREF1NSENSITIVITY);
			if (initdoneRef1NVariable == comp.initdoneRef1NVariable) items.add(INITDONEREF1NVARIABLE);
			if (initdoneMge1NSignal == comp.initdoneMge1NSignal) items.add(INITDONEMGE1NSIGNAL);
			if (initdoneRef1NFile == comp.initdoneRef1NFile) items.add(INITDONEREF1NFILE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEKPARKEY, INITDONEKHDLTYPE, INITDONEAPAR, INITDONEHSM1NPIPELINE, INITDONEMDL1NPORT, INITDONETPL1NMODULE, INITDONEMDL1NGENERIC, INITDONESUP1NMODULE, INITDONEREF1NSENSITIVITY, INITDONEREF1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONEREF1NFILE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeMtpRec)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFKPARKEY = 3;
		public static final int SCRJREFKHDLTYPE = 4;
		public static final int SCRJREFAPAR = 5;
		public static final int SCRJREFHSM1NPIPELINE = 6;
		public static final int SCRJREFMDL1NPORT = 7;
		public static final int SCRJREFTPL1NMODULE = 8;
		public static final int SCRJREFMDL1NGENERIC = 9;
		public static final int SCRJREFSUP1NMODULE = 10;
		public static final int SCRJREFREF1NSENSITIVITY = 11;
		public static final int SCRJREFREF1NVARIABLE = 12;
		public static final int SCRJREFMGE1NSIGNAL = 13;
		public static final int SCRJREFREF1NFILE = 14;
		public static final int BUTREGULARIZEACTIVE = 15;

		public StatShr(
					int ixWdbeVExpstate
					, String scrJrefDetail
					, String scrJrefKParKey
					, String scrJrefKHdltype
					, String scrJrefAPar
					, String scrJrefHsm1NPipeline
					, String scrJrefMdl1NPort
					, String scrJrefTpl1NModule
					, String scrJrefMdl1NGeneric
					, String scrJrefSup1NModule
					, String scrJrefRef1NSensitivity
					, String scrJrefRef1NVariable
					, String scrJrefMge1NSignal
					, String scrJrefRef1NFile
					, boolean ButRegularizeActive
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefKParKey = scrJrefKParKey;
			this.scrJrefKHdltype = scrJrefKHdltype;
			this.scrJrefAPar = scrJrefAPar;
			this.scrJrefHsm1NPipeline = scrJrefHsm1NPipeline;
			this.scrJrefMdl1NPort = scrJrefMdl1NPort;
			this.scrJrefTpl1NModule = scrJrefTpl1NModule;
			this.scrJrefMdl1NGeneric = scrJrefMdl1NGeneric;
			this.scrJrefSup1NModule = scrJrefSup1NModule;
			this.scrJrefRef1NSensitivity = scrJrefRef1NSensitivity;
			this.scrJrefRef1NVariable = scrJrefRef1NVariable;
			this.scrJrefMge1NSignal = scrJrefMge1NSignal;
			this.scrJrefRef1NFile = scrJrefRef1NFile;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKPARKEY, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREFHSM1NPIPELINE, SCRJREFMDL1NPORT, SCRJREFTPL1NMODULE, SCRJREFMDL1NGENERIC, SCRJREFSUP1NMODULE, SCRJREFREF1NSENSITIVITY, SCRJREFREF1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFREF1NFILE, BUTREGULARIZEACTIVE));
		};

		public int ixWdbeVExpstate;
		public String scrJrefDetail;
		public String scrJrefKParKey;
		public String scrJrefKHdltype;
		public String scrJrefAPar;
		public String scrJrefHsm1NPipeline;
		public String scrJrefMdl1NPort;
		public String scrJrefTpl1NModule;
		public String scrJrefMdl1NGeneric;
		public String scrJrefSup1NModule;
		public String scrJrefRef1NSensitivity;
		public String scrJrefRef1NVariable;
		public String scrJrefMge1NSignal;
		public String scrJrefRef1NFile;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeMtpRec");

			String itemtag = "StatitemShrWdbeMtpRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefKParKey = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefKParKey", mask, SCRJREFKPARKEY);
				scrJrefKHdltype = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefKHdltype", mask, SCRJREFKHDLTYPE);
				scrJrefAPar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAPar", mask, SCRJREFAPAR);
				scrJrefHsm1NPipeline = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHsm1NPipeline", mask, SCRJREFHSM1NPIPELINE);
				scrJrefMdl1NPort = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NPort", mask, SCRJREFMDL1NPORT);
				scrJrefTpl1NModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefTpl1NModule", mask, SCRJREFTPL1NMODULE);
				scrJrefMdl1NGeneric = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NGeneric", mask, SCRJREFMDL1NGENERIC);
				scrJrefSup1NModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSup1NModule", mask, SCRJREFSUP1NMODULE);
				scrJrefRef1NSensitivity = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NSensitivity", mask, SCRJREFREF1NSENSITIVITY);
				scrJrefRef1NVariable = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NVariable", mask, SCRJREFREF1NVARIABLE);
				scrJrefMge1NSignal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMge1NSignal", mask, SCRJREFMGE1NSIGNAL);
				scrJrefRef1NFile = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NFile", mask, SCRJREFREF1NFILE);
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
			if (scrJrefKParKey.equals(comp.scrJrefKParKey)) items.add(SCRJREFKPARKEY);
			if (scrJrefKHdltype.equals(comp.scrJrefKHdltype)) items.add(SCRJREFKHDLTYPE);
			if (scrJrefAPar.equals(comp.scrJrefAPar)) items.add(SCRJREFAPAR);
			if (scrJrefHsm1NPipeline.equals(comp.scrJrefHsm1NPipeline)) items.add(SCRJREFHSM1NPIPELINE);
			if (scrJrefMdl1NPort.equals(comp.scrJrefMdl1NPort)) items.add(SCRJREFMDL1NPORT);
			if (scrJrefTpl1NModule.equals(comp.scrJrefTpl1NModule)) items.add(SCRJREFTPL1NMODULE);
			if (scrJrefMdl1NGeneric.equals(comp.scrJrefMdl1NGeneric)) items.add(SCRJREFMDL1NGENERIC);
			if (scrJrefSup1NModule.equals(comp.scrJrefSup1NModule)) items.add(SCRJREFSUP1NMODULE);
			if (scrJrefRef1NSensitivity.equals(comp.scrJrefRef1NSensitivity)) items.add(SCRJREFREF1NSENSITIVITY);
			if (scrJrefRef1NVariable.equals(comp.scrJrefRef1NVariable)) items.add(SCRJREFREF1NVARIABLE);
			if (scrJrefMge1NSignal.equals(comp.scrJrefMge1NSignal)) items.add(SCRJREFMGE1NSIGNAL);
			if (scrJrefRef1NFile.equals(comp.scrJrefRef1NFile)) items.add(SCRJREFREF1NFILE);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKPARKEY, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREFHSM1NPIPELINE, SCRJREFMDL1NPORT, SCRJREFTPL1NMODULE, SCRJREFMDL1NGENERIC, SCRJREFSUP1NMODULE, SCRJREFREF1NSENSITIVITY, SCRJREFREF1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFREF1NFILE, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeMtpRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeMtpRec");

			String itemtag = "TagitemWdbeMtpRec";

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
		* DpchAppDo (full: DpchAppWdbeMtpRecDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEMTPRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeMtpRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeMtpRecData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEMTPRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", "", false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeMtpRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", "", false);
				tag = new Tag("");
			};
		};

	};

};
