/**
  * \file PnlWdbeModRec.java
  * Java API code for job PnlWdbeModRec
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

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
		public static final int INITDONECOR1NIMBUF = 5;
		public static final int INITDONEMDL1NPORT = 6;
		public static final int INITDONE1NPROCESS = 7;
		public static final int INITDONEMDL1NSIGNAL = 8;
		public static final int INITDONE1NPERIPHERAL = 9;
		public static final int INITDONESUP1NMODULE = 10;
		public static final int INITDONEMGE1NSIGNAL = 11;
		public static final int INITDONECTRREF1NCOMMAND = 12;
		public static final int INITDONECTRHK1NVECTOR = 13;
		public static final int INITDONECTRREF1NERROR = 14;
		public static final int INITDONECTRMNCOMMAND = 15;

		public StatApp(
					boolean initdoneDetail
					, boolean initdoneKHdltype
					, boolean initdoneAPar
					, boolean initdoneMdl1NGeneric
					, boolean initdoneCor1NImbuf
					, boolean initdoneMdl1NPort
					, boolean initdone1NProcess
					, boolean initdoneMdl1NSignal
					, boolean initdone1NPeripheral
					, boolean initdoneSup1NModule
					, boolean initdoneMge1NSignal
					, boolean initdoneCtrRef1NCommand
					, boolean initdoneCtrHk1NVector
					, boolean initdoneCtrRef1NError
					, boolean initdoneCtrMNCommand
				) {
			this.initdoneDetail = initdoneDetail;
			this.initdoneKHdltype = initdoneKHdltype;
			this.initdoneAPar = initdoneAPar;
			this.initdoneMdl1NGeneric = initdoneMdl1NGeneric;
			this.initdoneCor1NImbuf = initdoneCor1NImbuf;
			this.initdoneMdl1NPort = initdoneMdl1NPort;
			this.initdone1NProcess = initdone1NProcess;
			this.initdoneMdl1NSignal = initdoneMdl1NSignal;
			this.initdone1NPeripheral = initdone1NPeripheral;
			this.initdoneSup1NModule = initdoneSup1NModule;
			this.initdoneMge1NSignal = initdoneMge1NSignal;
			this.initdoneCtrRef1NCommand = initdoneCtrRef1NCommand;
			this.initdoneCtrHk1NVector = initdoneCtrHk1NVector;
			this.initdoneCtrRef1NError = initdoneCtrRef1NError;
			this.initdoneCtrMNCommand = initdoneCtrMNCommand;

			mask = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEAPAR, INITDONEMDL1NGENERIC, INITDONECOR1NIMBUF, INITDONEMDL1NPORT, INITDONE1NPROCESS, INITDONEMDL1NSIGNAL, INITDONE1NPERIPHERAL, INITDONESUP1NMODULE, INITDONEMGE1NSIGNAL, INITDONECTRREF1NCOMMAND, INITDONECTRHK1NVECTOR, INITDONECTRREF1NERROR, INITDONECTRMNCOMMAND));
		};

		public boolean initdoneDetail;
		public boolean initdoneKHdltype;
		public boolean initdoneAPar;
		public boolean initdoneMdl1NGeneric;
		public boolean initdoneCor1NImbuf;
		public boolean initdoneMdl1NPort;
		public boolean initdone1NProcess;
		public boolean initdoneMdl1NSignal;
		public boolean initdone1NPeripheral;
		public boolean initdoneSup1NModule;
		public boolean initdoneMge1NSignal;
		public boolean initdoneCtrRef1NCommand;
		public boolean initdoneCtrHk1NVector;
		public boolean initdoneCtrRef1NError;
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
				initdoneCor1NImbuf = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCor1NImbuf", mask, INITDONECOR1NIMBUF);
				initdoneMdl1NPort = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMdl1NPort", mask, INITDONEMDL1NPORT);
				initdone1NProcess = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NProcess", mask, INITDONE1NPROCESS);
				initdoneMdl1NSignal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMdl1NSignal", mask, INITDONEMDL1NSIGNAL);
				initdone1NPeripheral = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone1NPeripheral", mask, INITDONE1NPERIPHERAL);
				initdoneSup1NModule = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneSup1NModule", mask, INITDONESUP1NMODULE);
				initdoneMge1NSignal = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneMge1NSignal", mask, INITDONEMGE1NSIGNAL);
				initdoneCtrRef1NCommand = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCtrRef1NCommand", mask, INITDONECTRREF1NCOMMAND);
				initdoneCtrHk1NVector = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCtrHk1NVector", mask, INITDONECTRHK1NVECTOR);
				initdoneCtrRef1NError = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdoneCtrRef1NError", mask, INITDONECTRREF1NERROR);
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
			if (initdoneCor1NImbuf == comp.initdoneCor1NImbuf) items.add(INITDONECOR1NIMBUF);
			if (initdoneMdl1NPort == comp.initdoneMdl1NPort) items.add(INITDONEMDL1NPORT);
			if (initdone1NProcess == comp.initdone1NProcess) items.add(INITDONE1NPROCESS);
			if (initdoneMdl1NSignal == comp.initdoneMdl1NSignal) items.add(INITDONEMDL1NSIGNAL);
			if (initdone1NPeripheral == comp.initdone1NPeripheral) items.add(INITDONE1NPERIPHERAL);
			if (initdoneSup1NModule == comp.initdoneSup1NModule) items.add(INITDONESUP1NMODULE);
			if (initdoneMge1NSignal == comp.initdoneMge1NSignal) items.add(INITDONEMGE1NSIGNAL);
			if (initdoneCtrRef1NCommand == comp.initdoneCtrRef1NCommand) items.add(INITDONECTRREF1NCOMMAND);
			if (initdoneCtrHk1NVector == comp.initdoneCtrHk1NVector) items.add(INITDONECTRHK1NVECTOR);
			if (initdoneCtrRef1NError == comp.initdoneCtrRef1NError) items.add(INITDONECTRREF1NERROR);
			if (initdoneCtrMNCommand == comp.initdoneCtrMNCommand) items.add(INITDONECTRMNCOMMAND);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONEDETAIL, INITDONEKHDLTYPE, INITDONEAPAR, INITDONEMDL1NGENERIC, INITDONECOR1NIMBUF, INITDONEMDL1NPORT, INITDONE1NPROCESS, INITDONEMDL1NSIGNAL, INITDONE1NPERIPHERAL, INITDONESUP1NMODULE, INITDONEMGE1NSIGNAL, INITDONECTRREF1NCOMMAND, INITDONECTRHK1NVECTOR, INITDONECTRREF1NERROR, INITDONECTRMNCOMMAND));
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
		public static final int SCRJREFCOR1NIMBUF = 6;
		public static final int SCRJREFMDL1NPORT = 7;
		public static final int SCRJREF1NPROCESS = 8;
		public static final int SCRJREFMDL1NSIGNAL = 9;
		public static final int SCRJREF1NPERIPHERAL = 10;
		public static final int SCRJREFSUP1NMODULE = 11;
		public static final int SCRJREFMGE1NSIGNAL = 12;
		public static final int SCRJREFCTRREF1NCOMMAND = 13;
		public static final int PNLCTRREF1NCOMMANDAVAIL = 14;
		public static final int SCRJREFCTRHK1NVECTOR = 15;
		public static final int PNLCTRHK1NVECTORAVAIL = 16;
		public static final int SCRJREFCTRREF1NERROR = 17;
		public static final int PNLCTRREF1NERRORAVAIL = 18;
		public static final int SCRJREFCTRMNCOMMAND = 19;
		public static final int PNLCTRMNCOMMANDAVAIL = 20;
		public static final int BUTREGULARIZEACTIVE = 21;

		public StatShr(
					int ixWdbeVExpstate
					, String scrJrefDetail
					, String scrJrefKHdltype
					, String scrJrefAPar
					, String scrJrefMdl1NGeneric
					, String scrJrefCor1NImbuf
					, String scrJrefMdl1NPort
					, String scrJref1NProcess
					, String scrJrefMdl1NSignal
					, String scrJref1NPeripheral
					, String scrJrefSup1NModule
					, String scrJrefMge1NSignal
					, String scrJrefCtrRef1NCommand
					, boolean pnlctrref1ncommandAvail
					, String scrJrefCtrHk1NVector
					, boolean pnlctrhk1nvectorAvail
					, String scrJrefCtrRef1NError
					, boolean pnlctrref1nerrorAvail
					, String scrJrefCtrMNCommand
					, boolean pnlctrmncommandAvail
					, boolean ButRegularizeActive
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.scrJrefDetail = scrJrefDetail;
			this.scrJrefKHdltype = scrJrefKHdltype;
			this.scrJrefAPar = scrJrefAPar;
			this.scrJrefMdl1NGeneric = scrJrefMdl1NGeneric;
			this.scrJrefCor1NImbuf = scrJrefCor1NImbuf;
			this.scrJrefMdl1NPort = scrJrefMdl1NPort;
			this.scrJref1NProcess = scrJref1NProcess;
			this.scrJrefMdl1NSignal = scrJrefMdl1NSignal;
			this.scrJref1NPeripheral = scrJref1NPeripheral;
			this.scrJrefSup1NModule = scrJrefSup1NModule;
			this.scrJrefMge1NSignal = scrJrefMge1NSignal;
			this.scrJrefCtrRef1NCommand = scrJrefCtrRef1NCommand;
			this.pnlctrref1ncommandAvail = pnlctrref1ncommandAvail;
			this.scrJrefCtrHk1NVector = scrJrefCtrHk1NVector;
			this.pnlctrhk1nvectorAvail = pnlctrhk1nvectorAvail;
			this.scrJrefCtrRef1NError = scrJrefCtrRef1NError;
			this.pnlctrref1nerrorAvail = pnlctrref1nerrorAvail;
			this.scrJrefCtrMNCommand = scrJrefCtrMNCommand;
			this.pnlctrmncommandAvail = pnlctrmncommandAvail;
			this.ButRegularizeActive = ButRegularizeActive;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREFMDL1NGENERIC, SCRJREFCOR1NIMBUF, SCRJREFMDL1NPORT, SCRJREF1NPROCESS, SCRJREFMDL1NSIGNAL, SCRJREF1NPERIPHERAL, SCRJREFSUP1NMODULE, SCRJREFMGE1NSIGNAL, SCRJREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, SCRJREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, SCRJREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, SCRJREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE));
		};

		public int ixWdbeVExpstate;
		public String scrJrefDetail;
		public String scrJrefKHdltype;
		public String scrJrefAPar;
		public String scrJrefMdl1NGeneric;
		public String scrJrefCor1NImbuf;
		public String scrJrefMdl1NPort;
		public String scrJref1NProcess;
		public String scrJrefMdl1NSignal;
		public String scrJref1NPeripheral;
		public String scrJrefSup1NModule;
		public String scrJrefMge1NSignal;
		public String scrJrefCtrRef1NCommand;
		public boolean pnlctrref1ncommandAvail;
		public String scrJrefCtrHk1NVector;
		public boolean pnlctrhk1nvectorAvail;
		public String scrJrefCtrRef1NError;
		public boolean pnlctrref1nerrorAvail;
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
				scrJrefCor1NImbuf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCor1NImbuf", mask, SCRJREFCOR1NIMBUF);
				scrJrefMdl1NPort = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NPort", mask, SCRJREFMDL1NPORT);
				scrJref1NProcess = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NProcess", mask, SCRJREF1NPROCESS);
				scrJrefMdl1NSignal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMdl1NSignal", mask, SCRJREFMDL1NSIGNAL);
				scrJref1NPeripheral = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJref1NPeripheral", mask, SCRJREF1NPERIPHERAL);
				scrJrefSup1NModule = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefSup1NModule", mask, SCRJREFSUP1NMODULE);
				scrJrefMge1NSignal = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefMge1NSignal", mask, SCRJREFMGE1NSIGNAL);
				scrJrefCtrRef1NCommand = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCtrRef1NCommand", mask, SCRJREFCTRREF1NCOMMAND);
				pnlctrref1ncommandAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlctrref1ncommandAvail", mask, PNLCTRREF1NCOMMANDAVAIL);
				scrJrefCtrHk1NVector = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCtrHk1NVector", mask, SCRJREFCTRHK1NVECTOR);
				pnlctrhk1nvectorAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlctrhk1nvectorAvail", mask, PNLCTRHK1NVECTORAVAIL);
				scrJrefCtrRef1NError = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "scrJrefCtrRef1NError", mask, SCRJREFCTRREF1NERROR);
				pnlctrref1nerrorAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "pnlctrref1nerrorAvail", mask, PNLCTRREF1NERRORAVAIL);
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
			if (scrJrefCor1NImbuf.equals(comp.scrJrefCor1NImbuf)) items.add(SCRJREFCOR1NIMBUF);
			if (scrJrefMdl1NPort.equals(comp.scrJrefMdl1NPort)) items.add(SCRJREFMDL1NPORT);
			if (scrJref1NProcess.equals(comp.scrJref1NProcess)) items.add(SCRJREF1NPROCESS);
			if (scrJrefMdl1NSignal.equals(comp.scrJrefMdl1NSignal)) items.add(SCRJREFMDL1NSIGNAL);
			if (scrJref1NPeripheral.equals(comp.scrJref1NPeripheral)) items.add(SCRJREF1NPERIPHERAL);
			if (scrJrefSup1NModule.equals(comp.scrJrefSup1NModule)) items.add(SCRJREFSUP1NMODULE);
			if (scrJrefMge1NSignal.equals(comp.scrJrefMge1NSignal)) items.add(SCRJREFMGE1NSIGNAL);
			if (scrJrefCtrRef1NCommand.equals(comp.scrJrefCtrRef1NCommand)) items.add(SCRJREFCTRREF1NCOMMAND);
			if (pnlctrref1ncommandAvail == comp.pnlctrref1ncommandAvail) items.add(PNLCTRREF1NCOMMANDAVAIL);
			if (scrJrefCtrHk1NVector.equals(comp.scrJrefCtrHk1NVector)) items.add(SCRJREFCTRHK1NVECTOR);
			if (pnlctrhk1nvectorAvail == comp.pnlctrhk1nvectorAvail) items.add(PNLCTRHK1NVECTORAVAIL);
			if (scrJrefCtrRef1NError.equals(comp.scrJrefCtrRef1NError)) items.add(SCRJREFCTRREF1NERROR);
			if (pnlctrref1nerrorAvail == comp.pnlctrref1nerrorAvail) items.add(PNLCTRREF1NERRORAVAIL);
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

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, SCRJREFDETAIL, SCRJREFKHDLTYPE, SCRJREFAPAR, SCRJREFMDL1NGENERIC, SCRJREFCOR1NIMBUF, SCRJREFMDL1NPORT, SCRJREF1NPROCESS, SCRJREFMDL1NSIGNAL, SCRJREF1NPERIPHERAL, SCRJREFSUP1NMODULE, SCRJREFMGE1NSIGNAL, SCRJREFCTRREF1NCOMMAND, PNLCTRREF1NCOMMANDAVAIL, SCRJREFCTRHK1NVECTOR, PNLCTRHK1NVECTORAVAIL, SCRJREFCTRREF1NERROR, PNLCTRREF1NERRORAVAIL, SCRJREFCTRMNCOMMAND, PNLCTRMNCOMMANDAVAIL, BUTREGULARIZEACTIVE));
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
			statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", false, "", false, "", false, "", false, false);
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
				statapp = new StatApp(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				statshr = new StatShr(0, "", "", "", "", "", "", "", "", "", "", "", "", false, "", false, "", false, "", false, false);
				tag = new Tag("");
			};
		};

	};

};

