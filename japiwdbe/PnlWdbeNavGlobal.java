/**
  * \file PnlWdbeNavGlobal.java
  * Java API code for job PnlWdbeNavGlobal
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeNavGlobal {
	/**
		* VecVDo (full: VecVWdbeNavGlobalDo)
		*/
	public static class VecVDo {

		public static final int BUTMCHVIEWCLICK = 1;
		public static final int BUTMCHNEWCRDCLICK = 2;
		public static final int BUTLIBVIEWCLICK = 3;
		public static final int BUTLIBNEWCRDCLICK = 4;
		public static final int BUTFAMVIEWCLICK = 5;
		public static final int BUTFAMNEWCRDCLICK = 6;
		public static final int BUTSILVIEWCLICK = 7;
		public static final int BUTSILNEWCRDCLICK = 8;
		public static final int BUTMTPVIEWCLICK = 9;
		public static final int BUTMTPNEWCRDCLICK = 10;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butmchviewclick")) return BUTMCHVIEWCLICK;
			if (s.equals("butmchnewcrdclick")) return BUTMCHNEWCRDCLICK;
			if (s.equals("butlibviewclick")) return BUTLIBVIEWCLICK;
			if (s.equals("butlibnewcrdclick")) return BUTLIBNEWCRDCLICK;
			if (s.equals("butfamviewclick")) return BUTFAMVIEWCLICK;
			if (s.equals("butfamnewcrdclick")) return BUTFAMNEWCRDCLICK;
			if (s.equals("butsilviewclick")) return BUTSILVIEWCLICK;
			if (s.equals("butsilnewcrdclick")) return BUTSILNEWCRDCLICK;
			if (s.equals("butmtpviewclick")) return BUTMTPVIEWCLICK;
			if (s.equals("butmtpnewcrdclick")) return BUTMTPNEWCRDCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTMCHVIEWCLICK) return("ButMchViewClick");
			if (ix == BUTMCHNEWCRDCLICK) return("ButMchNewcrdClick");
			if (ix == BUTLIBVIEWCLICK) return("ButLibViewClick");
			if (ix == BUTLIBNEWCRDCLICK) return("ButLibNewcrdClick");
			if (ix == BUTFAMVIEWCLICK) return("ButFamViewClick");
			if (ix == BUTFAMNEWCRDCLICK) return("ButFamNewcrdClick");
			if (ix == BUTSILVIEWCLICK) return("ButSilViewClick");
			if (ix == BUTSILNEWCRDCLICK) return("ButSilNewcrdClick");
			if (ix == BUTMTPVIEWCLICK) return("ButMtpViewClick");
			if (ix == BUTMTPNEWCRDCLICK) return("ButMtpNewcrdClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeNavGlobal)
	  */
	public class ContIac extends Block {

		public static final int NUMFLSTMCH = 1;
		public static final int NUMFLSTLIB = 2;
		public static final int NUMFLSTFAM = 3;
		public static final int NUMFLSTSIL = 4;
		public static final int NUMFLSTMTP = 5;

		public ContIac(
					int numFLstMch
					, int numFLstLib
					, int numFLstFam
					, int numFLstSil
					, int numFLstMtp
				) {
			this.numFLstMch = numFLstMch;
			this.numFLstLib = numFLstLib;
			this.numFLstFam = numFLstFam;
			this.numFLstSil = numFLstSil;
			this.numFLstMtp = numFLstMtp;

			mask = new HashSet<Integer>(Arrays.asList(NUMFLSTMCH, NUMFLSTLIB, NUMFLSTFAM, NUMFLSTSIL, NUMFLSTMTP));
		};

		public int numFLstMch;
		public int numFLstLib;
		public int numFLstFam;
		public int numFLstSil;
		public int numFLstMtp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeNavGlobal");

			String itemtag = "ContitemIacWdbeNavGlobal";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFLstMch = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstMch", mask, NUMFLSTMCH);
				numFLstLib = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstLib", mask, NUMFLSTLIB);
				numFLstFam = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstFam", mask, NUMFLSTFAM);
				numFLstSil = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstSil", mask, NUMFLSTSIL);
				numFLstMtp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFLstMtp", mask, NUMFLSTMTP);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeNavGlobal";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeNavGlobal";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstMch", numFLstMch);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstLib", numFLstLib);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstFam", numFLstFam);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstSil", numFLstSil);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFLstMtp", numFLstMtp);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFLstMch == comp.numFLstMch) items.add(NUMFLSTMCH);
			if (numFLstLib == comp.numFLstLib) items.add(NUMFLSTLIB);
			if (numFLstFam == comp.numFLstFam) items.add(NUMFLSTFAM);
			if (numFLstSil == comp.numFLstSil) items.add(NUMFLSTSIL);
			if (numFLstMtp == comp.numFLstMtp) items.add(NUMFLSTMTP);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFLSTMCH, NUMFLSTLIB, NUMFLSTFAM, NUMFLSTSIL, NUMFLSTMTP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeNavGlobal)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int LSTMCHALT = 2;
		public static final int LSTLIBALT = 3;
		public static final int LSTFAMALT = 4;
		public static final int LSTSILALT = 5;
		public static final int LSTMTPALT = 6;
		public static final int LSTMCHNUMFIRSTDISP = 7;
		public static final int LSTLIBNUMFIRSTDISP = 8;
		public static final int LSTFAMNUMFIRSTDISP = 9;
		public static final int LSTSILNUMFIRSTDISP = 10;
		public static final int LSTMTPNUMFIRSTDISP = 11;

		public StatApp(
					int ixWdbeVExpstate
					, boolean LstMchAlt
					, boolean LstLibAlt
					, boolean LstFamAlt
					, boolean LstSilAlt
					, boolean LstMtpAlt
					, int LstMchNumFirstdisp
					, int LstLibNumFirstdisp
					, int LstFamNumFirstdisp
					, int LstSilNumFirstdisp
					, int LstMtpNumFirstdisp
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.LstMchAlt = LstMchAlt;
			this.LstLibAlt = LstLibAlt;
			this.LstFamAlt = LstFamAlt;
			this.LstSilAlt = LstSilAlt;
			this.LstMtpAlt = LstMtpAlt;
			this.LstMchNumFirstdisp = LstMchNumFirstdisp;
			this.LstLibNumFirstdisp = LstLibNumFirstdisp;
			this.LstFamNumFirstdisp = LstFamNumFirstdisp;
			this.LstSilNumFirstdisp = LstSilNumFirstdisp;
			this.LstMtpNumFirstdisp = LstMtpNumFirstdisp;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTMCHALT, LSTLIBALT, LSTFAMALT, LSTSILALT, LSTMTPALT, LSTMCHNUMFIRSTDISP, LSTLIBNUMFIRSTDISP, LSTFAMNUMFIRSTDISP, LSTSILNUMFIRSTDISP, LSTMTPNUMFIRSTDISP));
		};

		public int ixWdbeVExpstate;
		public boolean LstMchAlt;
		public boolean LstLibAlt;
		public boolean LstFamAlt;
		public boolean LstSilAlt;
		public boolean LstMtpAlt;
		public int LstMchNumFirstdisp;
		public int LstLibNumFirstdisp;
		public int LstFamNumFirstdisp;
		public int LstSilNumFirstdisp;
		public int LstMtpNumFirstdisp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeNavGlobal");

			String itemtag = "StatitemAppWdbeNavGlobal";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				LstMchAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMchAlt", mask, LSTMCHALT);
				LstLibAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstLibAlt", mask, LSTLIBALT);
				LstFamAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFamAlt", mask, LSTFAMALT);
				LstSilAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSilAlt", mask, LSTSILALT);
				LstMtpAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMtpAlt", mask, LSTMTPALT);
				LstMchNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMchNumFirstdisp", mask, LSTMCHNUMFIRSTDISP);
				LstLibNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstLibNumFirstdisp", mask, LSTLIBNUMFIRSTDISP);
				LstFamNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFamNumFirstdisp", mask, LSTFAMNUMFIRSTDISP);
				LstSilNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSilNumFirstdisp", mask, LSTSILNUMFIRSTDISP);
				LstMtpNumFirstdisp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMtpNumFirstdisp", mask, LSTMTPNUMFIRSTDISP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (LstMchAlt == comp.LstMchAlt) items.add(LSTMCHALT);
			if (LstLibAlt == comp.LstLibAlt) items.add(LSTLIBALT);
			if (LstFamAlt == comp.LstFamAlt) items.add(LSTFAMALT);
			if (LstSilAlt == comp.LstSilAlt) items.add(LSTSILALT);
			if (LstMtpAlt == comp.LstMtpAlt) items.add(LSTMTPALT);
			if (LstMchNumFirstdisp == comp.LstMchNumFirstdisp) items.add(LSTMCHNUMFIRSTDISP);
			if (LstLibNumFirstdisp == comp.LstLibNumFirstdisp) items.add(LSTLIBNUMFIRSTDISP);
			if (LstFamNumFirstdisp == comp.LstFamNumFirstdisp) items.add(LSTFAMNUMFIRSTDISP);
			if (LstSilNumFirstdisp == comp.LstSilNumFirstdisp) items.add(LSTSILNUMFIRSTDISP);
			if (LstMtpNumFirstdisp == comp.LstMtpNumFirstdisp) items.add(LSTMTPNUMFIRSTDISP);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, LSTMCHALT, LSTLIBALT, LSTFAMALT, LSTSILALT, LSTMTPALT, LSTMCHNUMFIRSTDISP, LSTLIBNUMFIRSTDISP, LSTFAMNUMFIRSTDISP, LSTSILNUMFIRSTDISP, LSTMTPNUMFIRSTDISP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeNavGlobal)
	  */
	public class StatShr extends Block {

		public static final int LSTMCHAVAIL = 1;
		public static final int BUTMCHVIEWACTIVE = 2;
		public static final int LSTLIBAVAIL = 3;
		public static final int BUTLIBVIEWACTIVE = 4;
		public static final int LSTFAMAVAIL = 5;
		public static final int BUTFAMVIEWACTIVE = 6;
		public static final int LSTSILAVAIL = 7;
		public static final int BUTSILVIEWACTIVE = 8;
		public static final int LSTMTPAVAIL = 9;
		public static final int BUTMTPVIEWACTIVE = 10;

		public StatShr(
					boolean LstMchAvail
					, boolean ButMchViewActive
					, boolean LstLibAvail
					, boolean ButLibViewActive
					, boolean LstFamAvail
					, boolean ButFamViewActive
					, boolean LstSilAvail
					, boolean ButSilViewActive
					, boolean LstMtpAvail
					, boolean ButMtpViewActive
				) {
			this.LstMchAvail = LstMchAvail;
			this.ButMchViewActive = ButMchViewActive;
			this.LstLibAvail = LstLibAvail;
			this.ButLibViewActive = ButLibViewActive;
			this.LstFamAvail = LstFamAvail;
			this.ButFamViewActive = ButFamViewActive;
			this.LstSilAvail = LstSilAvail;
			this.ButSilViewActive = ButSilViewActive;
			this.LstMtpAvail = LstMtpAvail;
			this.ButMtpViewActive = ButMtpViewActive;

			mask = new HashSet<Integer>(Arrays.asList(LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE, LSTFAMAVAIL, BUTFAMVIEWACTIVE, LSTSILAVAIL, BUTSILVIEWACTIVE, LSTMTPAVAIL, BUTMTPVIEWACTIVE));
		};

		public boolean LstMchAvail;
		public boolean ButMchViewActive;
		public boolean LstLibAvail;
		public boolean ButLibViewActive;
		public boolean LstFamAvail;
		public boolean ButFamViewActive;
		public boolean LstSilAvail;
		public boolean ButSilViewActive;
		public boolean LstMtpAvail;
		public boolean ButMtpViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeNavGlobal");

			String itemtag = "StatitemShrWdbeNavGlobal";

			if (Xmlio.checkXPath(doc, basexpath)) {
				LstMchAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMchAvail", mask, LSTMCHAVAIL);
				ButMchViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMchViewActive", mask, BUTMCHVIEWACTIVE);
				LstLibAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstLibAvail", mask, LSTLIBAVAIL);
				ButLibViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButLibViewActive", mask, BUTLIBVIEWACTIVE);
				LstFamAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstFamAvail", mask, LSTFAMAVAIL);
				ButFamViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButFamViewActive", mask, BUTFAMVIEWACTIVE);
				LstSilAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstSilAvail", mask, LSTSILAVAIL);
				ButSilViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSilViewActive", mask, BUTSILVIEWACTIVE);
				LstMtpAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "LstMtpAvail", mask, LSTMTPAVAIL);
				ButMtpViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMtpViewActive", mask, BUTMTPVIEWACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (LstMchAvail == comp.LstMchAvail) items.add(LSTMCHAVAIL);
			if (ButMchViewActive == comp.ButMchViewActive) items.add(BUTMCHVIEWACTIVE);
			if (LstLibAvail == comp.LstLibAvail) items.add(LSTLIBAVAIL);
			if (ButLibViewActive == comp.ButLibViewActive) items.add(BUTLIBVIEWACTIVE);
			if (LstFamAvail == comp.LstFamAvail) items.add(LSTFAMAVAIL);
			if (ButFamViewActive == comp.ButFamViewActive) items.add(BUTFAMVIEWACTIVE);
			if (LstSilAvail == comp.LstSilAvail) items.add(LSTSILAVAIL);
			if (ButSilViewActive == comp.ButSilViewActive) items.add(BUTSILVIEWACTIVE);
			if (LstMtpAvail == comp.LstMtpAvail) items.add(LSTMTPAVAIL);
			if (ButMtpViewActive == comp.ButMtpViewActive) items.add(BUTMTPVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(LSTMCHAVAIL, BUTMCHVIEWACTIVE, LSTLIBAVAIL, BUTLIBVIEWACTIVE, LSTFAMAVAIL, BUTFAMVIEWACTIVE, LSTSILAVAIL, BUTSILVIEWACTIVE, LSTMTPAVAIL, BUTMTPVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeNavGlobal)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTMCH = 2;
		public static final int CPTLIB = 3;
		public static final int CPTFAM = 4;
		public static final int CPTSIL = 5;
		public static final int CPTMTP = 6;

		public Tag(
					String Cpt
					, String CptMch
					, String CptLib
					, String CptFam
					, String CptSil
					, String CptMtp
				) {
			this.Cpt = Cpt;
			this.CptMch = CptMch;
			this.CptLib = CptLib;
			this.CptFam = CptFam;
			this.CptSil = CptSil;
			this.CptMtp = CptMtp;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTMCH, CPTLIB, CPTFAM, CPTSIL, CPTMTP));
		};

		public String Cpt;
		public String CptMch;
		public String CptLib;
		public String CptFam;
		public String CptSil;
		public String CptMtp;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeNavGlobal");

			String itemtag = "TagitemWdbeNavGlobal";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptMch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMch", mask, CPTMCH);
				CptLib = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptLib", mask, CPTLIB);
				CptFam = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFam", mask, CPTFAM);
				CptSil = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSil", mask, CPTSIL);
				CptMtp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMtp", mask, CPTMTP);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptMch.equals(comp.CptMch)) items.add(CPTMCH);
			if (CptLib.equals(comp.CptLib)) items.add(CPTLIB);
			if (CptFam.equals(comp.CptFam)) items.add(CPTFAM);
			if (CptSil.equals(comp.CptSil)) items.add(CPTSIL);
			if (CptMtp.equals(comp.CptMtp)) items.add(CPTMTP);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTMCH, CPTLIB, CPTFAM, CPTSIL, CPTMTP));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeNavGlobalData)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVGLOBALDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavGlobalData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeNavGlobalDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBENAVGLOBALDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeNavGlobalDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeNavGlobalData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int FEEDFLSTFAM = 3;
		public static final int FEEDFLSTLIB = 4;
		public static final int FEEDFLSTMCH = 5;
		public static final int FEEDFLSTMTP = 6;
		public static final int FEEDFLSTSIL = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBENAVGLOBALDATA);

			contiac = new ContIac(0, 0, 0, 0, 0);
			feedFLstFam = new Feed("FeedFLstFam");
			feedFLstLib = new Feed("FeedFLstLib");
			feedFLstMch = new Feed("FeedFLstMch");
			feedFLstMtp = new Feed("FeedFLstMtp");
			feedFLstSil = new Feed("FeedFLstSil");
			statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "");
		};

		public ContIac contiac;
		public Feed feedFLstFam;
		public Feed feedFLstLib;
		public Feed feedFLstMch;
		public Feed feedFLstMtp;
		public Feed feedFLstSil;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(FEEDFLSTFAM)) ss.add("feedFLstFam");
			if (has(FEEDFLSTLIB)) ss.add("feedFLstLib");
			if (has(FEEDFLSTMCH)) ss.add("feedFLstMch");
			if (has(FEEDFLSTMTP)) ss.add("feedFLstMtp");
			if (has(FEEDFLSTSIL)) ss.add("feedFLstSil");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeNavGlobalData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (feedFLstFam.readXML(doc, basexpath, true)) add(FEEDFLSTFAM);
				if (feedFLstLib.readXML(doc, basexpath, true)) add(FEEDFLSTLIB);
				if (feedFLstMch.readXML(doc, basexpath, true)) add(FEEDFLSTMCH);
				if (feedFLstMtp.readXML(doc, basexpath, true)) add(FEEDFLSTMTP);
				if (feedFLstSil.readXML(doc, basexpath, true)) add(FEEDFLSTSIL);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, 0, 0, 0);
				feedFLstFam = new Feed("FeedFLstFam");
				feedFLstLib = new Feed("FeedFLstLib");
				feedFLstMch = new Feed("FeedFLstMch");
				feedFLstMtp = new Feed("FeedFLstMtp");
				feedFLstSil = new Feed("FeedFLstSil");
				statapp = new StatApp(0, false, false, false, false, false, 0, 0, 0, 0, 0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "");
			};
		};

	};

};

