/**
  * \file DlgWdbeFilNew.java
  * Java API code for job DlgWdbeFilNew
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeFilNew {
	/**
		* VecVDit (full: VecVDlgWdbeFilNewDit)
		*/
	public static class VecVDit {

		public static final int DET = 1;
		public static final int FIL = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("det")) return DET;
			if (s.equals("fil")) return FIL;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == DET) return("Det");
			if (ix == FIL) return("Fil");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWdbeFilNewDo)
		*/
	public static class VecVDo {

		public static final int BUTDNECLICK = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butdneclick")) return BUTDNECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTDNECLICK) return("ButDneClick");

			return "";
		};

	};

	/**
		* VecVDoDet (full: VecVDlgWdbeFilNewDoDet)
		*/
	public static class VecVDoDet {

		public static final int BUTCRECLICK = 1;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butcreclick")) return BUTCRECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTCRECLICK) return("ButCreClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWdbeFilNewSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int CREATE = 2;
		public static final int CREDONE = 3;
		public static final int DONE = 4;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("create")) return CREATE;
			if (s.equals("credone")) return CREDONE;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == CREATE) return("create");
			if (ix == CREDONE) return("credone");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWdbeFilNew)
	  */
	public class ContIac extends Block {

		public static final int NUMFDSE = 1;

		public ContIac(
					int numFDse
				) {
			this.numFDse = numFDse;

			mask = new HashSet<Integer>(Arrays.asList(NUMFDSE));
		};

		public int numFDse;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeFilNew");

			String itemtag = "ContitemIacDlgWdbeFilNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFDse = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFDse", mask, NUMFDSE);

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeFilNew";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeFilNew";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFDse", numFDse);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFDse == comp.numFDse) items.add(NUMFDSE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFDSE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContIacDet (full: ContIacDlgWdbeFilNewDet)
	  */
	public class ContIacDet extends Block {

		public static final int TXFFNM = 1;
		public static final int NUMFPUPRET = 2;
		public static final int TXFREU = 3;
		public static final int NUMFPUPCNT = 4;
		public static final int NUMFPUPMIM = 5;
		public static final int TXFCMT = 6;

		public ContIacDet(
					String TxfFnm
					, int numFPupRet
					, String TxfReu
					, int numFPupCnt
					, int numFPupMim
					, String TxfCmt
				) {
			this.TxfFnm = TxfFnm;
			this.numFPupRet = numFPupRet;
			this.TxfReu = TxfReu;
			this.numFPupCnt = numFPupCnt;
			this.numFPupMim = numFPupMim;
			this.TxfCmt = TxfCmt;

			mask = new HashSet<Integer>(Arrays.asList(TXFFNM, NUMFPUPRET, TXFREU, NUMFPUPCNT, NUMFPUPMIM, TXFCMT));
		};

		public String TxfFnm;
		public int numFPupRet;
		public String TxfReu;
		public int numFPupCnt;
		public int numFPupMim;
		public String TxfCmt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeFilNewDet");

			String itemtag = "ContitemIacDlgWdbeFilNewDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxfFnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfFnm", mask, TXFFNM);
				numFPupRet = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupRet", mask, NUMFPUPRET);
				TxfReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfReu", mask, TXFREU);
				numFPupCnt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupCnt", mask, NUMFPUPCNT);
				numFPupMim = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupMim", mask, NUMFPUPMIM);
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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeFilNewDet";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeFilNewDet";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfFnm", TxfFnm);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupRet", numFPupRet);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfReu", TxfReu);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupCnt", numFPupCnt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupMim", numFPupMim);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
		};

		public HashSet<Integer> comm(
					ContIacDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxfFnm.equals(comp.TxfFnm)) items.add(TXFFNM);
			if (numFPupRet == comp.numFPupRet) items.add(NUMFPUPRET);
			if (TxfReu.equals(comp.TxfReu)) items.add(TXFREU);
			if (numFPupCnt == comp.numFPupCnt) items.add(NUMFPUPCNT);
			if (numFPupMim == comp.numFPupMim) items.add(NUMFPUPMIM);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIacDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXFFNM, NUMFPUPRET, TXFREU, NUMFPUPCNT, NUMFPUPMIM, TXFCMT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfDlgWdbeFilNew)
	  */
	public class ContInf extends Block {

		public static final int NUMFSGE = 1;

		public ContInf(
					int numFSge
				) {
			this.numFSge = numFSge;

			mask = new HashSet<Integer>(Arrays.asList(NUMFSGE));
		};

		public int numFSge;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeFilNew");

			String itemtag = "ContitemInfDlgWdbeFilNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFSge = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFSge", mask, NUMFSGE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFSge == comp.numFSge) items.add(NUMFSGE);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFSGE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWdbeFilNew)
	  */
	public class StatApp extends Block {

		public static final int INITDONE = 1;
		public static final int SHORTMENU = 2;

		public StatApp(
					boolean initdone
					, String shortMenu
				) {
			this.initdone = initdone;
			this.shortMenu = shortMenu;

			mask = new HashSet<Integer>(Arrays.asList(INITDONE, SHORTMENU));
		};

		public boolean initdone;
		public String shortMenu;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeFilNew");

			String itemtag = "StatitemAppDlgWdbeFilNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				initdone = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "initdone", mask, INITDONE);
				shortMenu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "shortMenu", mask, SHORTMENU);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (initdone == comp.initdone) items.add(INITDONE);
			if (shortMenu.equals(comp.shortMenu)) items.add(SHORTMENU);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(INITDONE, SHORTMENU));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrDlgWdbeFilNew)
	  */
	public class StatShr extends Block {

		public static final int BUTDNEACTIVE = 1;

		public StatShr(
					boolean ButDneActive
				) {
			this.ButDneActive = ButDneActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTDNEACTIVE));
		};

		public boolean ButDneActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeFilNew");

			String itemtag = "StatitemShrDlgWdbeFilNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButDneActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButDneActive", mask, BUTDNEACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShr comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButDneActive == comp.ButDneActive) items.add(BUTDNEACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTDNEACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrDet (full: StatShrDlgWdbeFilNewDet)
	  */
	public class StatShrDet extends Block {

		public static final int BUTCREACTIVE = 1;

		public StatShrDet(
					boolean ButCreActive
				) {
			this.ButCreActive = ButCreActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTCREACTIVE));
		};

		public boolean ButCreActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeFilNewDet");

			String itemtag = "StatitemShrDlgWdbeFilNewDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButCreActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCreActive", mask, BUTCREACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButCreActive == comp.ButCreActive) items.add(BUTCREACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTCREACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrFil (full: StatShrDlgWdbeFilNewFil)
	  */
	public class StatShrFil extends Block {

		public static final int ULDACTIVE = 1;

		public StatShrFil(
					boolean UldActive
				) {
			this.UldActive = UldActive;

			mask = new HashSet<Integer>(Arrays.asList(ULDACTIVE));
		};

		public boolean UldActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeFilNewFil");

			String itemtag = "StatitemShrDlgWdbeFilNewFil";

			if (Xmlio.checkXPath(doc, basexpath)) {
				UldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UldActive", mask, ULDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrFil comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (UldActive == comp.UldActive) items.add(ULDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrFil comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(ULDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagDlgWdbeFilNew)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int BUTDNE = 2;

		public Tag(
					String Cpt
					, String ButDne
				) {
			this.Cpt = Cpt;
			this.ButDne = ButDne;

			mask = new HashSet<Integer>(Arrays.asList(CPT, BUTDNE));
		};

		public String Cpt;
		public String ButDne;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeFilNew");

			String itemtag = "TagitemDlgWdbeFilNew";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				ButDne = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButDne", mask, BUTDNE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					Tag comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Cpt.equals(comp.Cpt)) items.add(CPT);
			if (ButDne.equals(comp.ButDne)) items.add(BUTDNE);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, BUTDNE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagDet (full: TagDlgWdbeFilNewDet)
	  */
	public class TagDet extends Block {

		public static final int CPTFNM = 1;
		public static final int CPTRET = 2;
		public static final int CPTREU = 3;
		public static final int CPTCNT = 4;
		public static final int CPTMIM = 5;
		public static final int CPTCMT = 6;
		public static final int BUTCRE = 7;

		public TagDet(
					String CptFnm
					, String CptRet
					, String CptReu
					, String CptCnt
					, String CptMim
					, String CptCmt
					, String ButCre
				) {
			this.CptFnm = CptFnm;
			this.CptRet = CptRet;
			this.CptReu = CptReu;
			this.CptCnt = CptCnt;
			this.CptMim = CptMim;
			this.CptCmt = CptCmt;
			this.ButCre = ButCre;

			mask = new HashSet<Integer>(Arrays.asList(CPTFNM, CPTRET, CPTREU, CPTCNT, CPTMIM, CPTCMT, BUTCRE));
		};

		public String CptFnm;
		public String CptRet;
		public String CptReu;
		public String CptCnt;
		public String CptMim;
		public String CptCmt;
		public String ButCre;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeFilNewDet");

			String itemtag = "TagitemDlgWdbeFilNewDet";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptFnm = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptFnm", mask, CPTFNM);
				CptRet = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptRet", mask, CPTRET);
				CptReu = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptReu", mask, CPTREU);
				CptCnt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCnt", mask, CPTCNT);
				CptMim = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptMim", mask, CPTMIM);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);
				ButCre = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButCre", mask, BUTCRE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagDet comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptFnm.equals(comp.CptFnm)) items.add(CPTFNM);
			if (CptRet.equals(comp.CptRet)) items.add(CPTRET);
			if (CptReu.equals(comp.CptReu)) items.add(CPTREU);
			if (CptCnt.equals(comp.CptCnt)) items.add(CPTCNT);
			if (CptMim.equals(comp.CptMim)) items.add(CPTMIM);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);
			if (ButCre.equals(comp.ButCre)) items.add(BUTCRE);

			return(items);
		};

		public HashSet<Integer> diff(
					TagDet comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTFNM, CPTRET, CPTREU, CPTCNT, CPTMIM, CPTCMT, BUTCRE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagFil (full: TagDlgWdbeFilNewFil)
	  */
	public class TagFil extends Block {

		public static final int ULD = 1;
		public static final int CPT = 2;

		public TagFil(
					String Uld
					, String Cpt
				) {
			this.Uld = Uld;
			this.Cpt = Cpt;

			mask = new HashSet<Integer>(Arrays.asList(ULD, CPT));
		};

		public String Uld;
		public String Cpt;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeFilNewFil");

			String itemtag = "TagitemDlgWdbeFilNewFil";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Uld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Uld", mask, ULD);
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagFil comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Uld.equals(comp.Uld)) items.add(ULD);
			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					TagFil comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(ULD, CPT));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppDlgWdbeFilNewData)
		*/
	public class DpchAppData extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTIACDET = 3;
		public static final int ALL = 4;

		public DpchAppData(
					String scrJref
					, ContIac contiac
					, ContIacDet contiacdet
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPDLGWDBEFILNEWDATA, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, CONTIAC, CONTIACDET));
					break;
				};

			if (has(CONTIAC)) this.contiac = contiac;
			if (has(CONTIACDET)) this.contiacdet = contiacdet;
		};

		public ContIac contiac;
		public ContIacDet contiacdet;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTIACDET)) ss.add("contiacdet");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWdbeFilNewData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
			if (has(CONTIACDET)) contiacdet.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeFilNewDo)
		*/
	public class DpchAppDo extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int IXVDODET = 3;
		public static final int ALL = 4;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, int ixVDoDet
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPDLGWDBEFILNEWDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO, IXVDODET));
					break;
				};

			this.ixVDo = ixVDo;
			this.ixVDoDet = ixVDoDet;
		};

		public int ixVDo;
		public int ixVDoDet;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");
			if (has(IXVDODET)) ss.add("ixVDoDet");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWdbeFilNewDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
			if (has(IXVDODET)) Xmlio.writeString(doc, el, "srefIxVDoDet", VecVDoDet.getSref(ixVDoDet));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeFilNewData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTIACDET = 3;
		public static final int CONTINF = 4;
		public static final int FEEDFDETPUPCNT = 5;
		public static final int FEEDFDETPUPMIM = 6;
		public static final int FEEDFDETPUPRET = 7;
		public static final int FEEDFDSE = 8;
		public static final int FEEDFSGE = 9;
		public static final int STATAPP = 10;
		public static final int STATSHR = 11;
		public static final int STATSHRDET = 12;
		public static final int STATSHRFIL = 13;
		public static final int TAG = 14;
		public static final int TAGDET = 15;
		public static final int TAGFIL = 16;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBEFILNEWDATA);

			contiac = new ContIac(0);
			contiacdet = new ContIacDet("", 0, "", 0, 0, "");
			continf = new ContInf(0);
			feedFDetPupCnt = new Feed("FeedFDetPupCnt");
			feedFDetPupMim = new Feed("FeedFDetPupMim");
			feedFDetPupRet = new Feed("FeedFDetPupRet");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false);
			statshrdet = new StatShrDet(false);
			statshrfil = new StatShrFil(false);
			tag = new Tag("", "");
			tagdet = new TagDet("", "", "", "", "", "", "");
			tagfil = new TagFil("", "");
		};

		public ContIac contiac;
		public ContIacDet contiacdet;
		public ContInf continf;
		public Feed feedFDetPupCnt;
		public Feed feedFDetPupMim;
		public Feed feedFDetPupRet;
		public Feed feedFDse;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public StatShrDet statshrdet;
		public StatShrFil statshrfil;
		public Tag tag;
		public TagDet tagdet;
		public TagFil tagfil;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTIACDET)) ss.add("contiacdet");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFDETPUPCNT)) ss.add("feedFDetPupCnt");
			if (has(FEEDFDETPUPMIM)) ss.add("feedFDetPupMim");
			if (has(FEEDFDETPUPRET)) ss.add("feedFDetPupRet");
			if (has(FEEDFDSE)) ss.add("feedFDse");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STATSHRDET)) ss.add("statshrdet");
			if (has(STATSHRFIL)) ss.add("statshrfil");
			if (has(TAG)) ss.add("tag");
			if (has(TAGDET)) ss.add("tagdet");
			if (has(TAGFIL)) ss.add("tagfil");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeFilNewData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (contiacdet.readXML(doc, basexpath, true)) add(CONTIACDET);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFDetPupCnt.readXML(doc, basexpath, true)) add(FEEDFDETPUPCNT);
				if (feedFDetPupMim.readXML(doc, basexpath, true)) add(FEEDFDETPUPMIM);
				if (feedFDetPupRet.readXML(doc, basexpath, true)) add(FEEDFDETPUPRET);
				if (feedFDse.readXML(doc, basexpath, true)) add(FEEDFDSE);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (statshrdet.readXML(doc, basexpath, true)) add(STATSHRDET);
				if (statshrfil.readXML(doc, basexpath, true)) add(STATSHRFIL);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (tagdet.readXML(doc, basexpath, true)) add(TAGDET);
				if (tagfil.readXML(doc, basexpath, true)) add(TAGFIL);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				contiacdet = new ContIacDet("", 0, "", 0, 0, "");
				continf = new ContInf(0);
				feedFDetPupCnt = new Feed("FeedFDetPupCnt");
				feedFDetPupMim = new Feed("FeedFDetPupMim");
				feedFDetPupRet = new Feed("FeedFDetPupRet");
				feedFDse = new Feed("FeedFDse");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(false, "");
				statshr = new StatShr(false);
				statshrdet = new StatShrDet(false);
				statshrfil = new StatShrFil(false);
				tag = new Tag("", "");
				tagdet = new TagDet("", "", "", "", "", "", "");
				tagfil = new TagFil("", "");
			};
		};

	};

};

