/**
  * \file PnlWdbeSilDetail.java
  * Java API code for job PnlWdbeSilDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeSilDetail {
	/**
		* VecVDo (full: VecVWdbeSilDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTREUVIEWCLICK = 2;
		public static final int BUTMDLVIEWCLICK = 3;
		public static final int BUTPKGEDITCLICK = 4;
		public static final int BUTTCHEDITCLICK = 5;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butreuviewclick")) return BUTREUVIEWCLICK;
			if (s.equals("butmdlviewclick")) return BUTMDLVIEWCLICK;
			if (s.equals("butpkgeditclick")) return BUTPKGEDITCLICK;
			if (s.equals("buttcheditclick")) return BUTTCHEDITCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTREUVIEWCLICK) return("ButReuViewClick");
			if (ix == BUTMDLVIEWCLICK) return("ButMdlViewClick");
			if (ix == BUTPKGEDITCLICK) return("ButPkgEditClick");
			if (ix == BUTTCHEDITCLICK) return("ButTchEditClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeSilDetail)
	  */
	public class ContIac extends Block {

		public static final int TXFTIT = 1;
		public static final int TXFFSR = 2;
		public static final int NUMFPUPTYP = 3;
		public static final int NUMFPUPRET = 4;
		public static final int NUMFPUPPKG = 5;
		public static final int TXFPKG = 6;
		public static final int CHKESY = 7;
		public static final int NUMFPUPTCH = 8;
		public static final int TXFTCH = 9;
		public static final int TXFCMT = 10;

		public ContIac(
					String TxfTit
					, String TxfFsr
					, int numFPupTyp
					, int numFPupRet
					, int numFPupPkg
					, String TxfPkg
					, boolean ChkEsy
					, int numFPupTch
					, String TxfTch
					, String TxfCmt
				) {
			this.TxfTit = TxfTit;
			this.TxfFsr = TxfFsr;
			this.numFPupTyp = numFPupTyp;
			this.numFPupRet = numFPupRet;
			this.numFPupPkg = numFPupPkg;
			this.TxfPkg = TxfPkg;
			this.ChkEsy = ChkEsy;
			this.numFPupTch = numFPupTch;
			this.TxfTch = TxfTch;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFTIT, TXFFSR, NUMFPUPTYP, NUMFPUPRET, NUMFPUPPKG, TXFPKG, CHKESY, NUMFPUPTCH, TXFTCH, TXFCMT));
		};

		public String TxfTit;
		public String TxfFsr;
		public int numFPupTyp;
		public int numFPupRet;
		public int numFPupPkg;
		public String TxfPkg;
		public boolean ChkEsy;
		public int numFPupTch;
		public String TxfTch;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeSilDetail");

			String itemtag = "ContitemIacWdbeSilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTit", mask, TXFTIT);
				TxfFsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFsr", mask, TXFFSR);
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				numFPupPkg = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupPkg", mask, NUMFPUPPKG);
				TxfPkg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfPkg", mask, TXFPKG);
				ChkEsy = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "ChkEsy", mask, CHKESY);
				numFPupTch = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTch", mask, NUMFPUPTCH);
				TxfTch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfTch", mask, TXFTCH);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeSilDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeSilDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTit", TxfTit);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFsr", TxfFsr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupPkg", numFPupPkg);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfPkg", TxfPkg);
			Xmlio.writeBooleanAttr(doc, el, itemtag, "sref", "ChkEsy", ChkEsy);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTch", numFPupTch);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfTch", TxfTch);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfTit.equals(comp.TxfTit)) items.add(TXFTIT);
			if (TxfFsr.equals(comp.TxfFsr)) items.add(TXFFSR);
			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (numFPupPkg == comp.numFPupPkg) items.add(NUMFPUPPKG);
			if (TxfPkg.equals(comp.TxfPkg)) items.add(TXFPKG);
			if (ChkEsy == comp.ChkEsy) items.add(CHKESY);
			if (numFPupTch == comp.numFPupTch) items.add(NUMFPUPTCH);
			if (TxfTch.equals(comp.TxfTch)) items.add(TXFTCH);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFTIT, TXFFSR, NUMFPUPTYP, NUMFPUPRET, NUMFPUPPKG, TXFPKG, CHKESY, NUMFPUPTCH, TXFTCH, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeSilDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTREU = 2;
		public static final int TXTMDL = 3;

		public ContInf(
					String TxtSrf
					, String TxtReu
					, String TxtMdl
				) {
			this.TxtSrf = TxtSrf;
			this.TxtReu = TxtReu;
			this.TxtMdl = TxtMdl;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTREU, TXTMDL));
		};

		public String TxtSrf;
		public String TxtReu;
		public String TxtMdl;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeSilDetail");

			String itemtag = "ContitemInfWdbeSilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtReu", mask, TXTREU);
				TxtMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtMdl", mask, TXTMDL);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtReu.equals(comp.TxtReu)) items.add(TXTREU);
			if (TxtMdl.equals(comp.TxtMdl)) items.add(TXTMDL);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTREU, TXTMDL));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeSilDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int PUPPKGALT = 2;
		public static final int PUPTCHALT = 3;

		public StatApp(
					int ixWdbeVExpstate
					, boolean PupPkgAlt
					, boolean PupTchAlt
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.PupPkgAlt = PupPkgAlt;
			this.PupTchAlt = PupTchAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPPKGALT, PUPTCHALT));
		};

		public int ixWdbeVExpstate;
		public boolean PupPkgAlt;
		public boolean PupTchAlt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeSilDetail");

			String itemtag = "StatitemAppWdbeSilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);
				PupPkgAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPkgAlt", mask, PUPPKGALT);
				PupTchAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTchAlt", mask, PUPTCHALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (PupPkgAlt == comp.PupPkgAlt) items.add(PUPPKGALT);
			if (PupTchAlt == comp.PupTchAlt) items.add(PUPTCHALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPPKGALT, PUPTCHALT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeSilDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int TXFTITACTIVE = 4;
		public static final int TXFFSRACTIVE = 5;
		public static final int PUPTYPACTIVE = 6;
		public static final int TXTREUACTIVE = 7;
		public static final int BUTREUVIEWAVAIL = 8;
		public static final int BUTREUVIEWACTIVE = 9;
		public static final int TXTMDLACTIVE = 10;
		public static final int BUTMDLVIEWAVAIL = 11;
		public static final int BUTMDLVIEWACTIVE = 12;
		public static final int PUPPKGACTIVE = 13;
		public static final int TXFPKGVALID = 14;
		public static final int BUTPKGEDITAVAIL = 15;
		public static final int CHKESYACTIVE = 16;
		public static final int PUPTCHACTIVE = 17;
		public static final int TXFTCHVALID = 18;
		public static final int BUTTCHEDITAVAIL = 19;
		public static final int TXFCMTACTIVE = 20;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean TxfTitActive
					, boolean TxfFsrActive
					, boolean PupTypActive
					, boolean TxtReuActive
					, boolean ButReuViewAvail
					, boolean ButReuViewActive
					, boolean TxtMdlActive
					, boolean ButMdlViewAvail
					, boolean ButMdlViewActive
					, boolean PupPkgActive
					, boolean TxfPkgValid
					, boolean ButPkgEditAvail
					, boolean ChkEsyActive
					, boolean PupTchActive
					, boolean TxfTchValid
					, boolean ButTchEditAvail
					, boolean TxfCmtActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.TxfTitActive = TxfTitActive;
			this.TxfFsrActive = TxfFsrActive;
			this.PupTypActive = PupTypActive;
			this.TxtReuActive = TxtReuActive;
			this.ButReuViewAvail = ButReuViewAvail;
			this.ButReuViewActive = ButReuViewActive;
			this.TxtMdlActive = TxtMdlActive;
			this.ButMdlViewAvail = ButMdlViewAvail;
			this.ButMdlViewActive = ButMdlViewActive;
			this.PupPkgActive = PupPkgActive;
			this.TxfPkgValid = TxfPkgValid;
			this.ButPkgEditAvail = ButPkgEditAvail;
			this.ChkEsyActive = ChkEsyActive;
			this.PupTchActive = PupTchActive;
			this.TxfTchValid = TxfTchValid;
			this.ButTchEditAvail = ButTchEditAvail;
			this.TxfCmtActive = TxfCmtActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFFSRACTIVE, PUPTYPACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPPKGACTIVE, TXFPKGVALID, BUTPKGEDITAVAIL, CHKESYACTIVE, PUPTCHACTIVE, TXFTCHVALID, BUTTCHEDITAVAIL, TXFCMTACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean TxfTitActive;
		public boolean TxfFsrActive;
		public boolean PupTypActive;
		public boolean TxtReuActive;
		public boolean ButReuViewAvail;
		public boolean ButReuViewActive;
		public boolean TxtMdlActive;
		public boolean ButMdlViewAvail;
		public boolean ButMdlViewActive;
		public boolean PupPkgActive;
		public boolean TxfPkgValid;
		public boolean ButPkgEditAvail;
		public boolean ChkEsyActive;
		public boolean PupTchActive;
		public boolean TxfTchValid;
		public boolean ButTchEditAvail;
		public boolean TxfCmtActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeSilDetail");

			String itemtag = "StatitemShrWdbeSilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				TxfTitActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTitActive", mask, TXFTITACTIVE);
				TxfFsrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfFsrActive", mask, TXFFSRACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtReuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtReuActive", mask, TXTREUACTIVE);
				ButReuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewAvail", mask, BUTREUVIEWAVAIL);
				ButReuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButReuViewActive", mask, BUTREUVIEWACTIVE);
				TxtMdlActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtMdlActive", mask, TXTMDLACTIVE);
				ButMdlViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewAvail", mask, BUTMDLVIEWAVAIL);
				ButMdlViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButMdlViewActive", mask, BUTMDLVIEWACTIVE);
				PupPkgActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupPkgActive", mask, PUPPKGACTIVE);
				TxfPkgValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfPkgValid", mask, TXFPKGVALID);
				ButPkgEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButPkgEditAvail", mask, BUTPKGEDITAVAIL);
				ChkEsyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ChkEsyActive", mask, CHKESYACTIVE);
				PupTchActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTchActive", mask, PUPTCHACTIVE);
				TxfTchValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfTchValid", mask, TXFTCHVALID);
				ButTchEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTchEditAvail", mask, BUTTCHEDITAVAIL);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButSaveAvail == comp.ButSaveAvail) items.add(BUTSAVEAVAIL);
			if (ButSaveActive == comp.ButSaveActive) items.add(BUTSAVEACTIVE);
			if (TxtSrfActive == comp.TxtSrfActive) items.add(TXTSRFACTIVE);
			if (TxfTitActive == comp.TxfTitActive) items.add(TXFTITACTIVE);
			if (TxfFsrActive == comp.TxfFsrActive) items.add(TXFFSRACTIVE);
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxtReuActive == comp.TxtReuActive) items.add(TXTREUACTIVE);
			if (ButReuViewAvail == comp.ButReuViewAvail) items.add(BUTREUVIEWAVAIL);
			if (ButReuViewActive == comp.ButReuViewActive) items.add(BUTREUVIEWACTIVE);
			if (TxtMdlActive == comp.TxtMdlActive) items.add(TXTMDLACTIVE);
			if (ButMdlViewAvail == comp.ButMdlViewAvail) items.add(BUTMDLVIEWAVAIL);
			if (ButMdlViewActive == comp.ButMdlViewActive) items.add(BUTMDLVIEWACTIVE);
			if (PupPkgActive == comp.PupPkgActive) items.add(PUPPKGACTIVE);
			if (TxfPkgValid == comp.TxfPkgValid) items.add(TXFPKGVALID);
			if (ButPkgEditAvail == comp.ButPkgEditAvail) items.add(BUTPKGEDITAVAIL);
			if (ChkEsyActive == comp.ChkEsyActive) items.add(CHKESYACTIVE);
			if (PupTchActive == comp.PupTchActive) items.add(PUPTCHACTIVE);
			if (TxfTchValid == comp.TxfTchValid) items.add(TXFTCHVALID);
			if (ButTchEditAvail == comp.ButTchEditAvail) items.add(BUTTCHEDITAVAIL);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, TXFTITACTIVE, TXFFSRACTIVE, PUPTYPACTIVE, TXTREUACTIVE, BUTREUVIEWAVAIL, BUTREUVIEWACTIVE, TXTMDLACTIVE, BUTMDLVIEWAVAIL, BUTMDLVIEWACTIVE, PUPPKGACTIVE, TXFPKGVALID, BUTPKGEDITAVAIL, CHKESYACTIVE, PUPTCHACTIVE, TXFTCHVALID, BUTTCHEDITAVAIL, TXFCMTACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeSilDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTIT = 3;
		public static final int CPTFSR = 4;
		public static final int CPTTYP = 5;
		public static final int CPTREU = 6;
		public static final int CPTMDL = 7;
		public static final int CPTPKG = 8;
		public static final int CPTESY = 9;
		public static final int CPTTCH = 10;
		public static final int CPTCMT = 11;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTit
					, String CptFsr
					, String CptTyp
					, String CptReu
					, String CptMdl
					, String CptPkg
					, String CptEsy
					, String CptTch
					, String CptCmt
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTit = CptTit;
			this.CptFsr = CptFsr;
			this.CptTyp = CptTyp;
			this.CptReu = CptReu;
			this.CptMdl = CptMdl;
			this.CptPkg = CptPkg;
			this.CptEsy = CptEsy;
			this.CptTch = CptTch;
			this.CptCmt = CptCmt;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTFSR, CPTTYP, CPTREU, CPTMDL, CPTPKG, CPTESY, CPTTCH, CPTCMT));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTit;
		public String CptFsr;
		public String CptTyp;
		public String CptReu;
		public String CptMdl;
		public String CptPkg;
		public String CptEsy;
		public String CptTch;
		public String CptCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeSilDetail");

			String itemtag = "TagitemWdbeSilDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTit = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTit", mask, CPTTIT);
				CptFsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFsr", mask, CPTFSR);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptMdl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMdl", mask, CPTMDL);
				CptPkg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPkg", mask, CPTPKG);
				CptEsy = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptEsy", mask, CPTESY);
				CptTch = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTch", mask, CPTTCH);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (CptSrf.equals(comp.CptSrf)) items.add(CPTSRF);
			if (CptTit.equals(comp.CptTit)) items.add(CPTTIT);
			if (CptFsr.equals(comp.CptFsr)) items.add(CPTFSR);
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptMdl.equals(comp.CptMdl)) items.add(CPTMDL);
			if (CptPkg.equals(comp.CptPkg)) items.add(CPTPKG);
			if (CptEsy.equals(comp.CptEsy)) items.add(CPTESY);
			if (CptTch.equals(comp.CptTch)) items.add(CPTTCH);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTIT, CPTFSR, CPTTYP, CPTREU, CPTMDL, CPTPKG, CPTESY, CPTTCH, CPTCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeSilDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBESILDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSilDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeSilDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBESILDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeSilDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeSilDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPPKG = 4;
		public static final int FEEDFPUPRET = 5;
		public static final int FEEDFPUPTCH = 6;
		public static final int FEEDFPUPTYP = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBESILDETAILDATA);

			contiac = new ContIac("", "", 0, 0, 0, "", false, 0, "", "");
			continf = new ContInf("", "", "");
			feedFPupPkg = new Feed("FeedFPupPkg");
			feedFPupRet = new Feed("FeedFPupRet");
			feedFPupTch = new Feed("FeedFPupTch");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0, false, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupPkg;
		public Feed feedFPupRet;
		public Feed feedFPupTch;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPPKG)) ss.add("feedFPupPkg");
			if (has(FEEDFPUPRET)) ss.add("feedFPupRet");
			if (has(FEEDFPUPTCH)) ss.add("feedFPupTch");
			if (has(FEEDFPUPTYP)) ss.add("feedFPupTyp");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeSilDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupPkg.readXML(doc, basexpath, true)) add(FEEDFPUPPKG);
				if (feedFPupRet.readXML(doc, basexpath, true)) add(FEEDFPUPRET);
				if (feedFPupTch.readXML(doc, basexpath, true)) add(FEEDFPUPTCH);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac("", "", 0, 0, 0, "", false, 0, "", "");
				continf = new ContInf("", "", "");
				feedFPupPkg = new Feed("FeedFPupPkg");
				feedFPupRet = new Feed("FeedFPupRet");
				feedFPupTch = new Feed("FeedFPupTch");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0, false, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
