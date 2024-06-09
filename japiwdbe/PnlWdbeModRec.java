/**
  * \file PnlWdbeModRec.java
  * Java API code for job PnlWdbeModRec
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeModRec {
	/**
		* VecVDo (full: VecVWdbeModRecDo)
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
	  * ContInf (full: ContInfWdbeModRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeModRec");

			String itemtag = "ContitemInfWdbeModRec";

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
	  * StatApp (full: StatAppWdbeModRec)
	  */
	public class StatApp extends Block {

		public static final int INITDONEDETAIL = 1;
		public static final int INITDONEKHDLTYPE = 2;
		public static final int INITDONEAPAR = 3;
		public static final int INITDONEMDL1NGENERIC = 4;
		public static final int INITDONE1NCDC = 5;
		public static final int INITDONEHSM1NPIPELINE = 6;
		public static final int INITDONE1NPROCESS = 7;
		public static final int INITDONEMDL1NPORT = 8;
		public static final int INITDONESUP1NMODULE = 9;
		public static final int INITDONEREF1NSIGNAL = 10;
		public static final int INITDONEREF1NSENSITIVITY = 11;
		public static final int INITDONEREF1NVARIABLE = 12;
		public static final int INITDONEMGE1NSIGNAL = 13;
		public static final int INITDONECTRHK1NVECTOR = 14;
		public static final int INITDONECTRREF1NERROR = 15;
		public static final int INITDONECTRREF1NCOMMAND = 16;
		public static final int INITDONEMNPERIPHERAL = 17;
		public static final int INITDONECTDMNMODULE = 18;
		public static final int INITDONECORMNMODULE = 19;
		public static final int INITDONECTRMNCOMMAND = 20;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneKHdltype
					, boolean initdoneAPar
					, boolean initdoneMdl1NGeneric
					, boolean initdone1NCdc
					, boolean initdoneHsm1NPipeline
					, boolean initdone1NProcess
					, boolean initdoneMdl1NPort
					, boolean initdoneSup1NModule
					, boolean initdoneRef1NSignal
					, boolean initdoneRef1NSensitivity
					, boolean initdoneRef1NVariable
					, boolean initdoneMge1NSignal
					, boolean initdoneCtrHk1NVector
					, boolean initdoneCtrRef1NError
					, boolean initdoneCtrRef1NCommand
					, boolean initdoneMNPeripheral
					, boolean initdoneCtdMNModule
					, boolean initdoneCorMNModule
					, boolean initdoneCtrMNCommand
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneKHdltype = initdoneKHdltype;
			this.initdoneAPar = initdoneAPar;
			this.initdoneMdl1NGeneric = initdoneMdl1NGeneric;
			this.initdone1NCdc = initdone1NCdc;
			this.initdoneHsm1NPipeline = initdoneHsm1NPipeline;
			this.initdone1NProcess = initdone1NProcess;
			this.initdoneMdl1NPort = initdoneMdl1NPort;
			this.initdoneSup1NModule = initdoneSup1NModule;
			this.initdoneRef1NSignal = initdoneRef1NSignal;
			this.initdoneRef1NSensitivity = initdoneRef1NSensitivity;
			this.initdoneRef1NVariable = initdoneRef1NVariable;
			this.initdoneMge1NSignal = initdoneMge1NSignal;
			this.initdoneCtrHk1NVector = initdoneCtrHk1NVector;
			this.initdoneCtrRef1NError = initdoneCtrRef1NError;
			this.initdoneCtrRef1NCommand = initdoneCtrRef1NCommand;
			this.initdoneMNPeripheral = initdoneMNPeripheral;
			this.initdoneCtdMNModule = initdoneCtdMNModule;
			this.initdoneCorMNModule = initdoneCorMNModule;
			this.initdoneCtrMNCommand = initdoneCtrMNCommand;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEAPAR, INITDONEMDL1NGENERIC, INITDONE1NCDC, INITDONEHSM1NPIPELINE, INITDONE1NPROCESS, INITDONEMDL1NPORT, INITDONESUP1NMODULE, INITDONEREF1NSIGNAL, INITDONEREF1NSENSITIVITY, INITDONEREF1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONECTRHK1NVECTOR, INITDONECTRREF1NERROR, INITDONECTRREF1NCOMMAND, INITDONEMNPERIPHERAL, INITDONECTDMNMODULE, INITDONECORMNMODULE, INITDONECTRMNCOMMAND));
		};

		public boolean initdoneDetail;
		public boolean initdoneKHdltype;
		public boolean initdoneAPar;
		public boolean initdoneMdl1NGeneric;
		public boolean initdone1NCdc;
		public boolean initdoneHsm1NPipeline;
		public boolean initdone1NProcess;
		public boolean initdoneMdl1NPort;
		public boolean initdoneSup1NModule;
		public boolean initdoneRef1NSignal;
		public boolean initdoneRef1NSensitivity;
		public boolean initdoneRef1NVariable;
		public boolean initdoneMge1NSignal;
		public boolean initdoneCtrHk1NVector;
		public boolean initdoneCtrRef1NError;
		public boolean initdoneCtrRef1NCommand;
		public boolean initdoneMNPeripheral;
		public boolean initdoneCtdMNModule;
		public boolean initdoneCorMNModule;
		public boolean initdoneCtrMNCommand;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeModRec");

			String itemtag = "StatitemAppWdbeModRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdoneDetail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneDetail", mask, INITDONEDETAIL);
				initdoneKHdltype = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneKHdltype", mask, INITDONEKHDLTYPE);
				initdoneAPar = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneAPar", mask, INITDONEAPAR);
				initdoneMdl1NGeneric = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMdl1NGeneric", mask, INITDONEMDL1NGENERIC);
				initdone1NCdc = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NCdc", mask, INITDONE1NCDC);
				initdoneHsm1NPipeline = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneHsm1NPipeline", mask, INITDONEHSM1NPIPELINE);
				initdone1NProcess = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NProcess", mask, INITDONE1NPROCESS);
				initdoneMdl1NPort = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMdl1NPort", mask, INITDONEMDL1NPORT);
				initdoneSup1NModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSup1NModule", mask, INITDONESUP1NMODULE);
				initdoneRef1NSignal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NSignal", mask, INITDONEREF1NSIGNAL);
				initdoneRef1NSensitivity = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NSensitivity", mask, INITDONEREF1NSENSITIVITY);
				initdoneRef1NVariable = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneRef1NVariable", mask, INITDONEREF1NVARIABLE);
				initdoneMge1NSignal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMge1NSignal", mask, INITDONEMGE1NSIGNAL);
				initdoneCtrHk1NVector = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCtrHk1NVector", mask, INITDONECTRHK1NVECTOR);
				initdoneCtrRef1NError = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCtrRef1NError", mask, INITDONECTRREF1NERROR);
				initdoneCtrRef1NCommand = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCtrRef1NCommand", mask, INITDONECTRREF1NCOMMAND);
				initdoneMNPeripheral = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMNPeripheral", mask, INITDONEMNPERIPHERAL);
				initdoneCtdMNModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCtdMNModule", mask, INITDONECTDMNMODULE);
				initdoneCorMNModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCorMNModule", mask, INITDONECORMNMODULE);
				initdoneCtrMNCommand = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCtrMNCommand", mask, INITDONECTRMNCOMMAND);

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
			if (initdoneAPar == comp.initdoneAPar) items.add(INITDONEAPAR);
			if (initdoneMdl1NGeneric == comp.initdoneMdl1NGeneric) items.add(INITDONEMDL1NGENERIC);
			if (initdone1NCdc == comp.initdone1NCdc) items.add(INITDONE1NCDC);
			if (initdoneHsm1NPipeline == comp.initdoneHsm1NPipeline) items.add(INITDONEHSM1NPIPELINE);
			if (initdone1NProcess == comp.initdone1NProcess) items.add(INITDONE1NPROCESS);
			if (initdoneMdl1NPort == comp.initdoneMdl1NPort) items.add(INITDONEMDL1NPORT);
			if (initdoneSup1NModule == comp.initdoneSup1NModule) items.add(INITDONESUP1NMODULE);
			if (initdoneRef1NSignal == comp.initdoneRef1NSignal) items.add(INITDONEREF1NSIGNAL);
			if (initdoneRef1NSensitivity == comp.initdoneRef1NSensitivity) items.add(INITDONEREF1NSENSITIVITY);
			if (initdoneRef1NVariable == comp.initdoneRef1NVariable) items.add(INITDONEREF1NVARIABLE);
			if (initdoneMge1NSignal == comp.initdoneMge1NSignal) items.add(INITDONEMGE1NSIGNAL);
			if (initdoneCtrHk1NVector == comp.initdoneCtrHk1NVector) items.add(INITDONECTRHK1NVECTOR);
			if (initdoneCtrRef1NError == comp.initdoneCtrRef1NError) items.add(INITDONECTRREF1NERROR);
			if (initdoneCtrRef1NCommand == comp.initdoneCtrRef1NCommand) items.add(INITDONECTRREF1NCOMMAND);
			if (initdoneMNPeripheral == comp.initdoneMNPeripheral) items.add(INITDONEMNPERIPHERAL);
			if (initdoneCtdMNModule == comp.initdoneCtdMNModule) items.add(INITDONECTDMNMODULE);
			if (initdoneCorMNModule == comp.initdoneCorMNModule) items.add(INITDONECORMNMODULE);
			if (initdoneCtrMNCommand == comp.initdoneCtrMNCommand) items.add(INITDONECTRMNCOMMAND);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEAPAR, INITDONEMDL1NGENERIC, INITDONE1NCDC, INITDONEHSM1NPIPELINE, INITDONE1NPROCESS, INITDONEMDL1NPORT, INITDONESUP1NMODULE, INITDONEREF1NSIGNAL, INITDONEREF1NSENSITIVITY, INITDONEREF1NVARIABLE, INITDONEMGE1NSIGNAL, INITDONECTRHK1NVECTOR, INITDONECTRREF1NERROR, INITDONECTRREF1NCOMMAND, INITDONEMNPERIPHERAL, INITDONECTDMNMODULE, INITDONECORMNMODULE, INITDONECTRMNCOMMAND));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeModRec)
	  */
	public class StatShr extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int SCRJREFDETAIL = 2;
		public static final int SCRJREFKHDLTYPE = 3;
		public static final int SCRJREFAPAR = 4;
		public static final int SCRJREFMDL1NGENERIC = 5;
		public static final int SCRJREF1NCDC = 6;
		public static final int SCRJREFHSM1NPIPELINE = 7;
		public static final int SCRJREF1NPROCESS = 8;
		public static final int SCRJREFMDL1NPORT = 9;
		public static final int SCRJREFSUP1NMODULE = 10;
		public static final int SCRJREFREF1NSIGNAL = 11;
		public static final int SCRJREFREF1NSENSITIVITY = 12;
		public static final int SCRJREFREF1NVARIABLE = 13;
		public static final int SCRJREFMGE1NSIGNAL = 14;
		public static final int SCRJREFCTRHK1NVECTOR = 15;
		public static final int PNLCTRHK1NVECTORAVAIL = 16;
		public static final int SCRJREFCTRREF1NERROR = 17;
		public static final int PNLCTRREF1NERRORAVAIL = 18;
		public static final int SCRJREFCTRREF1NCOMMAND = 19;
		public static final int PNLCTRREF1NCOMMANDAVAIL = 20;
		public static final int SCRJREFMNPERIPHERAL = 21;
		public static final int SCRJREFCTDMNMODULE = 22;
		public static final int SCRJREFCORMNMODULE = 23;
		public static final int SCRJREFCTRMNCOMMAND = 24;
		public static final int PNLCTRMNCOMMANDAVAIL = 25;
		public static final int BUTREGULARIZEACTIVE = 26;

		public StatShr(
					int ixWdbeVExpstate
					, String scrJrefDetail
					, String scrJrefKHdltype
					, String scrJrefAPar
					, String scrJrefMdl1NGeneric
					, String scrJref1NCdc
					, String scrJrefHsm1NPipeline
					, String scrJref1NProcess
					, String scrJrefMdl1NPort
					, String scrJrefSup1NModule
					, String scrJrefRef1NSignal
					, String scrJrefRef1NSensitivity
					, String scrJrefRef1NVariable
					, String scrJrefMge1NSignal
					, String scrJrefCtrHk1NVector
					, boolean pnlctrhk1nvectorAvail
					, String scrJrefCtrRef1NError
					, boolean pnlctrref1nerrorAvail
					, String scrJrefCtrRef1NCommand
					, boolean pnlctrref1ncommandAvail
					, String scrJrefMNPeripheral
					, String scrJrefCtdMNModule
					, String scrJrefCorMNModule
					, String scrJrefCtrMNCommand
					, boolean pnlctrmncommandAvail
					, boolean ButRegularizeActive
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefKHdltype = scrJrefKHdltype;
			this.scrJrefAPar = scrJrefAPar;
			this.scrJrefMdl1NGeneric = scrJrefMdl1NGeneric;
			this.scrJref1NCdc = scrJref1NCdc;
			this.scrJrefHsm1NPipeline = scrJrefHsm1NPipeline;
			this.scrJref1NProcess = scrJref1NProcess;
			this.scrJrefMdl1NPort = scrJrefMdl1NPort;
			this.scrJrefSup1NModule = scrJrefSup1NModule;
			this.scrJrefRef1NSignal = scrJrefRef1NSignal;
			this.scrJrefRef1NSensitivity = scrJrefRef1NSensitivity;
			this.scrJrefRef1NVariable = scrJrefRef1NVariable;
			this.scrJrefMge1NSignal = scrJrefMge1NSignal;
			this.scrJrefCtrHk1NVector = scrJrefCtrHk1NVector;
			this.pnlctrhk1nvectorAvail = pnlctrhk1nvectorAvail;
			this.scrJrefCtrRef1NError = scrJrefCtrRef1NError;
			this.pnlctrref1nerrorAvail = pnlctrref1nerrorAvail;
			this.scrJrefCtrRef1NCommand = scrJrefCtrRef1NCommand;
			this.pnlctrref1ncommandAvail = pnlctrref1ncommandAvail;
			this.scrJrefMNPeripheral = scrJrefMNPeripheral;
			this.scrJrefCtdMNModule = scrJrefCtdMNModule;
			this.scrJrefCorMNModule = scrJrefCorMNModule;
			this.scrJrefCtrMNCommand = scrJrefCtrMNCommand;
			this.pnlctrmncommandAvail = pnlctrmncommandAvail;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREFMDL1NGENERIC, SCRJREF1NCDC, SCRJREFHSM1NPIPELINE, SCRJREF1NPROCESS, SCRJREFMDL1NPORT, SCRJREFSUP1NMODULE, SCRJREFREF1NSIGNAL, SCRJREFREF1NSENSITIVITY, SCRJREFREF1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, SCRJREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, SCRJREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, SCRJREFMNPERIPHERAL, SCRJREFCTDMNMODULE, SCRJREFCORMNMODULE, SCRJREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE));
		};

		public int ixWdbeVExpstate;
		public String scrJrefDetail;
		public String scrJrefKHdltype;
		public String scrJrefAPar;
		public String scrJrefMdl1NGeneric;
		public String scrJref1NCdc;
		public String scrJrefHsm1NPipeline;
		public String scrJref1NProcess;
		public String scrJrefMdl1NPort;
		public String scrJrefSup1NModule;
		public String scrJrefRef1NSignal;
		public String scrJrefRef1NSensitivity;
		public String scrJrefRef1NVariable;
		public String scrJrefMge1NSignal;
		public String scrJrefCtrHk1NVector;
		public boolean pnlctrhk1nvectorAvail;
		public String scrJrefCtrRef1NError;
		public boolean pnlctrref1nerrorAvail;
		public String scrJrefCtrRef1NCommand;
		public boolean pnlctrref1ncommandAvail;
		public String scrJrefMNPeripheral;
		public String scrJrefCtdMNModule;
		public String scrJrefCorMNModule;
		public String scrJrefCtrMNCommand;
		public boolean pnlctrmncommandAvail;
		public boolean ButRegularizeActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeModRec");

			String itemtag = "StatitemShrWdbeModRec";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				scrJrefDetail = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefDetail", mask, SCRJREFDETAIL);
				scrJrefKHdltype = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefKHdltype", mask, SCRJREFKHDLTYPE);
				scrJrefAPar = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefAPar", mask, SCRJREFAPAR);
				scrJrefMdl1NGeneric = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NGeneric", mask, SCRJREFMDL1NGENERIC);
				scrJref1NCdc = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NCdc", mask, SCRJREF1NCDC);
				scrJrefHsm1NPipeline = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefHsm1NPipeline", mask, SCRJREFHSM1NPIPELINE);
				scrJref1NProcess = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NProcess", mask, SCRJREF1NPROCESS);
				scrJrefMdl1NPort = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NPort", mask, SCRJREFMDL1NPORT);
				scrJrefSup1NModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSup1NModule", mask, SCRJREFSUP1NMODULE);
				scrJrefRef1NSignal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NSignal", mask, SCRJREFREF1NSIGNAL);
				scrJrefRef1NSensitivity = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NSensitivity", mask, SCRJREFREF1NSENSITIVITY);
				scrJrefRef1NVariable = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefRef1NVariable", mask, SCRJREFREF1NVARIABLE);
				scrJrefMge1NSignal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMge1NSignal", mask, SCRJREFMGE1NSIGNAL);
				scrJrefCtrHk1NVector = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCtrHk1NVector", mask, SCRJREFCTRHK1NVECTOR);
				pnlctrhk1nvectorAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlctrhk1nvectorAvail", mask, PNLCTRHK1NVECTORAVAIL);
				scrJrefCtrRef1NError = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCtrRef1NError", mask, SCRJREFCTRREF1NERROR);
				pnlctrref1nerrorAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlctrref1nerrorAvail", mask, PNLCTRREF1NERRORAVAIL);
				scrJrefCtrRef1NCommand = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCtrRef1NCommand", mask, SCRJREFCTRREF1NCOMMAND);
				pnlctrref1ncommandAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlctrref1ncommandAvail", mask, PNLCTRREF1NCOMMANDAVAIL);
				scrJrefMNPeripheral = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMNPeripheral", mask, SCRJREFMNPERIPHERAL);
				scrJrefCtdMNModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCtdMNModule", mask, SCRJREFCTDMNMODULE);
				scrJrefCorMNModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCorMNModule", mask, SCRJREFCORMNMODULE);
				scrJrefCtrMNCommand = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCtrMNCommand", mask, SCRJREFCTRMNCOMMAND);
				pnlctrmncommandAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlctrmncommandAvail", mask, PNLCTRMNCOMMANDAVAIL);
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
			if (scrJrefAPar.equals(comp.scrJrefAPar)) items.add(SCRJREFAPAR);
			if (scrJrefMdl1NGeneric.equals(comp.scrJrefMdl1NGeneric)) items.add(SCRJREFMDL1NGENERIC);
			if (scrJref1NCdc.equals(comp.scrJref1NCdc)) items.add(SCRJREF1NCDC);
			if (scrJrefHsm1NPipeline.equals(comp.scrJrefHsm1NPipeline)) items.add(SCRJREFHSM1NPIPELINE);
			if (scrJref1NProcess.equals(comp.scrJref1NProcess)) items.add(SCRJREF1NPROCESS);
			if (scrJrefMdl1NPort.equals(comp.scrJrefMdl1NPort)) items.add(SCRJREFMDL1NPORT);
			if (scrJrefSup1NModule.equals(comp.scrJrefSup1NModule)) items.add(SCRJREFSUP1NMODULE);
			if (scrJrefRef1NSignal.equals(comp.scrJrefRef1NSignal)) items.add(SCRJREFREF1NSIGNAL);
			if (scrJrefRef1NSensitivity.equals(comp.scrJrefRef1NSensitivity)) items.add(SCRJREFREF1NSENSITIVITY);
			if (scrJrefRef1NVariable.equals(comp.scrJrefRef1NVariable)) items.add(SCRJREFREF1NVARIABLE);
			if (scrJrefMge1NSignal.equals(comp.scrJrefMge1NSignal)) items.add(SCRJREFMGE1NSIGNAL);
			if (scrJrefCtrHk1NVector.equals(comp.scrJrefCtrHk1NVector)) items.add(SCRJREFCTRHK1NVECTOR);
			if (pnlctrhk1nvectorAvail == comp.pnlctrhk1nvectorAvail) items.add(PNLCTRHK1NVECTORAVAIL);
			if (scrJrefCtrRef1NError.equals(comp.scrJrefCtrRef1NError)) items.add(SCRJREFCTRREF1NERROR);
			if (pnlctrref1nerrorAvail == comp.pnlctrref1nerrorAvail) items.add(PNLCTRREF1NERRORAVAIL);
			if (scrJrefCtrRef1NCommand.equals(comp.scrJrefCtrRef1NCommand)) items.add(SCRJREFCTRREF1NCOMMAND);
			if (pnlctrref1ncommandAvail == comp.pnlctrref1ncommandAvail) items.add(PNLCTRREF1NCOMMANDAVAIL);
			if (scrJrefMNPeripheral.equals(comp.scrJrefMNPeripheral)) items.add(SCRJREFMNPERIPHERAL);
			if (scrJrefCtdMNModule.equals(comp.scrJrefCtdMNModule)) items.add(SCRJREFCTDMNMODULE);
			if (scrJrefCorMNModule.equals(comp.scrJrefCorMNModule)) items.add(SCRJREFCORMNMODULE);
			if (scrJrefCtrMNCommand.equals(comp.scrJrefCtrMNCommand)) items.add(SCRJREFCTRMNCOMMAND);
			if (pnlctrmncommandAvail == comp.pnlctrmncommandAvail) items.add(PNLCTRMNCOMMANDAVAIL);
			if (ButRegularizeActive == comp.ButRegularizeActive) items.add(BUTREGULARIZEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREFMDL1NGENERIC, SCRJREF1NCDC, SCRJREFHSM1NPIPELINE, SCRJREF1NPROCESS, SCRJREFMDL1NPORT, SCRJREFSUP1NMODULE, SCRJREFREF1NSIGNAL, SCRJREFREF1NSENSITIVITY, SCRJREFREF1NVARIABLE, SCRJREFMGE1NSIGNAL, SCRJREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, SCRJREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, SCRJREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, SCRJREFMNPERIPHERAL, SCRJREFCTDMNMODULE, SCRJREFCORMNMODULE, SCRJREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeModRec)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeModRec");

			String itemtag = "TagitemWdbeModRec";

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
		* DpchAppDo (full: DpchAppWdbeModRecDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEMODRECDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeModRecDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeModRecData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTINF = 2;
		public static final int STATAPP = 3;
		public static final int STATSHR = 4;
		public static final int TAG = 5;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEMODRECDATA);

			continf = new ContInf("");
			statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", "", "", false, "", false, "", false, "", "", "", "", false, false);
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeModRecData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				continf = new ContInf("");
				statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", "", "", false, "", false, "", false, "", "", "", "", false, false);
				tag = new Tag("");
			};
		};

	};

};
