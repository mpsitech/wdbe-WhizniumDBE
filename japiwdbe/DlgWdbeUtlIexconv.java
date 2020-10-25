/**
  * \file DlgWdbeUtlIexconv.java
  * Java API code for job DlgWdbeUtlIexconv
  * \author Alexander Wirthmueller
  * \date created: 23 Aug 2020
  * \date modified: 23 Aug 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class DlgWdbeUtlIexconv {
	/**
		* VecVDit (full: VecVDlgWdbeUtlIexconvDit)
		*/
	public static class VecVDit {

		public static final int SRC = 1;
		public static final int CNV = 2;
		public static final int RES = 3;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("src")) return SRC;
			if (s.equals("cnv")) return CNV;
			if (s.equals("res")) return RES;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == SRC) return("Src");
			if (ix == CNV) return("Cnv");
			if (ix == RES) return("Res");

			return "";
		};

	};

	/**
		* VecVDo (full: VecVDlgWdbeUtlIexconvDo)
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
		* VecVDoCnv (full: VecVDlgWdbeUtlIexconvDoCnv)
		*/
	public static class VecVDoCnv {

		public static final int BUTRUNCLICK = 1;
		public static final int BUTSTOCLICK = 2;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butrunclick")) return BUTRUNCLICK;
			if (s.equals("butstoclick")) return BUTSTOCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTRUNCLICK) return("ButRunClick");
			if (ix == BUTSTOCLICK) return("ButStoClick");

			return "";
		};

	};

	/**
		* VecVSge (full: VecVDlgWdbeUtlIexconvSge)
		*/
	public static class VecVSge {

		public static final int IDLE = 1;
		public static final int UPKIDLE = 2;
		public static final int UNPACK = 3;
		public static final int UPKDONE = 4;
		public static final int ULDDONE = 5;
		public static final int CONV = 6;
		public static final int PACK = 7;
		public static final int DONE = 8;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("idle")) return IDLE;
			if (s.equals("upkidle")) return UPKIDLE;
			if (s.equals("unpack")) return UNPACK;
			if (s.equals("upkdone")) return UPKDONE;
			if (s.equals("ulddone")) return ULDDONE;
			if (s.equals("conv")) return CONV;
			if (s.equals("pack")) return PACK;
			if (s.equals("done")) return DONE;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == IDLE) return("idle");
			if (ix == UPKIDLE) return("upkidle");
			if (ix == UNPACK) return("unpack");
			if (ix == UPKDONE) return("upkdone");
			if (ix == ULDDONE) return("ulddone");
			if (ix == CONV) return("conv");
			if (ix == PACK) return("pack");
			if (ix == DONE) return("done");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacDlgWdbeUtlIexconv)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacDlgWdbeUtlIexconv");

			String itemtag = "ContitemIacDlgWdbeUtlIexconv";

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
			if (difftag.isEmpty()) difftag = "ContIacDlgWdbeUtlIexconv";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacDlgWdbeUtlIexconv";

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
	  * ContInf (full: ContInfDlgWdbeUtlIexconv)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeUtlIexconv");

			String itemtag = "ContitemInfDlgWdbeUtlIexconv";

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
	  * ContInfCnv (full: ContInfDlgWdbeUtlIexconvCnv)
	  */
	public class ContInfCnv extends Block {

		public static final int TXTPRG = 1;

		public ContInfCnv(
					String TxtPrg
				) {
			this.TxtPrg = TxtPrg;

			mask = new HashSet<Integer>(Arrays.asList(TXTPRG));
		};

		public String TxtPrg;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeUtlIexconvCnv");

			String itemtag = "ContitemInfDlgWdbeUtlIexconvCnv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtPrg", mask, TXTPRG);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfCnv comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtPrg.equals(comp.TxtPrg)) items.add(TXTPRG);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfCnv comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTPRG));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInfRes (full: ContInfDlgWdbeUtlIexconvRes)
	  */
	public class ContInfRes extends Block {

		public static final int DLD = 1;

		public ContInfRes(
					String Dld
				) {
			this.Dld = Dld;

			mask = new HashSet<Integer>(Arrays.asList(DLD));
		};

		public String Dld;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfDlgWdbeUtlIexconvRes");

			String itemtag = "ContitemInfDlgWdbeUtlIexconvRes";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInfRes comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInfRes comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppDlgWdbeUtlIexconv)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppDlgWdbeUtlIexconv");

			String itemtag = "StatitemAppDlgWdbeUtlIexconv";

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
	  * StatShr (full: StatShrDlgWdbeUtlIexconv)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeUtlIexconv");

			String itemtag = "StatitemShrDlgWdbeUtlIexconv";

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
	  * StatShrCnv (full: StatShrDlgWdbeUtlIexconvCnv)
	  */
	public class StatShrCnv extends Block {

		public static final int BUTRUNACTIVE = 1;
		public static final int BUTSTOACTIVE = 2;

		public StatShrCnv(
					boolean ButRunActive
					, boolean ButStoActive
				) {
			this.ButRunActive = ButRunActive;
			this.ButStoActive = ButStoActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTRUNACTIVE, BUTSTOACTIVE));
		};

		public boolean ButRunActive;
		public boolean ButStoActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeUtlIexconvCnv");

			String itemtag = "StatitemShrDlgWdbeUtlIexconvCnv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButRunActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButRunActive", mask, BUTRUNACTIVE);
				ButStoActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButStoActive", mask, BUTSTOACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrCnv comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ButRunActive == comp.ButRunActive) items.add(BUTRUNACTIVE);
			if (ButStoActive == comp.ButStoActive) items.add(BUTSTOACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrCnv comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTRUNACTIVE, BUTSTOACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrRes (full: StatShrDlgWdbeUtlIexconvRes)
	  */
	public class StatShrRes extends Block {

		public static final int DLDACTIVE = 1;

		public StatShrRes(
					boolean DldActive
				) {
			this.DldActive = DldActive;

			mask = new HashSet<Integer>(Arrays.asList(DLDACTIVE));
		};

		public boolean DldActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeUtlIexconvRes");

			String itemtag = "StatitemShrDlgWdbeUtlIexconvRes";

			if (Xmlio.checkXPath(doc, basexpath)) {
				DldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "DldActive", mask, DLDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrRes comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (DldActive == comp.DldActive) items.add(DLDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrRes comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLDACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShrSrc (full: StatShrDlgWdbeUtlIexconvSrc)
	  */
	public class StatShrSrc extends Block {

		public static final int ULDACTIVE = 1;

		public StatShrSrc(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrDlgWdbeUtlIexconvSrc");

			String itemtag = "StatitemShrDlgWdbeUtlIexconvSrc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				UldActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "UldActive", mask, ULDACTIVE);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatShrSrc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (UldActive == comp.UldActive) items.add(ULDACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShrSrc comp
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
	  * Tag (full: TagDlgWdbeUtlIexconv)
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeUtlIexconv");

			String itemtag = "TagitemDlgWdbeUtlIexconv";

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
	  * TagCnv (full: TagDlgWdbeUtlIexconvCnv)
	  */
	public class TagCnv extends Block {

		public static final int CPTPRG = 1;
		public static final int BUTRUN = 2;
		public static final int BUTSTO = 3;

		public TagCnv(
					String CptPrg
					, String ButRun
					, String ButSto
				) {
			this.CptPrg = CptPrg;
			this.ButRun = ButRun;
			this.ButSto = ButSto;

			mask = new HashSet<Integer>(Arrays.asList(CPTPRG, BUTRUN, BUTSTO));
		};

		public String CptPrg;
		public String ButRun;
		public String ButSto;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeUtlIexconvCnv");

			String itemtag = "TagitemDlgWdbeUtlIexconvCnv";

			if (Xmlio.checkXPath(doc, basexpath)) {
				CptPrg = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptPrg", mask, CPTPRG);
				ButRun = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButRun", mask, BUTRUN);
				ButSto = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "ButSto", mask, BUTSTO);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagCnv comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (CptPrg.equals(comp.CptPrg)) items.add(CPTPRG);
			if (ButRun.equals(comp.ButRun)) items.add(BUTRUN);
			if (ButSto.equals(comp.ButSto)) items.add(BUTSTO);

			return(items);
		};

		public HashSet<Integer> diff(
					TagCnv comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPTPRG, BUTRUN, BUTSTO));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagRes (full: TagDlgWdbeUtlIexconvRes)
	  */
	public class TagRes extends Block {

		public static final int DLD = 1;

		public TagRes(
					String Dld
				) {
			this.Dld = Dld;

			mask = new HashSet<Integer>(Arrays.asList(DLD));
		};

		public String Dld;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeUtlIexconvRes");

			String itemtag = "TagitemDlgWdbeUtlIexconvRes";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Dld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Dld", mask, DLD);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagRes comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Dld.equals(comp.Dld)) items.add(DLD);

			return(items);
		};

		public HashSet<Integer> diff(
					TagRes comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(DLD));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * TagSrc (full: TagDlgWdbeUtlIexconvSrc)
	  */
	public class TagSrc extends Block {

		public static final int ULD = 1;
		public static final int CPT = 2;

		public TagSrc(
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagDlgWdbeUtlIexconvSrc");

			String itemtag = "TagitemDlgWdbeUtlIexconvSrc";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Uld = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Uld", mask, ULD);
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					TagSrc comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (Uld.equals(comp.Uld)) items.add(ULD);
			if (Cpt.equals(comp.Cpt)) items.add(CPT);

			return(items);
		};

		public HashSet<Integer> diff(
					TagSrc comp
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
		* DpchAppData (full: DpchAppDlgWdbeUtlIexconvData)
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
			super(VecWdbeVDpch.DPCHAPPDLGWDBEUTLIEXCONVDATA, scrJref);

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
			Element el = doc.createElement("DpchAppDlgWdbeUtlIexconvData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppDlgWdbeUtlIexconvDo)
		*/
	public class DpchAppDo extends DpchAppWdbe {

		public static final int SCRJREF = 1;
		public static final int IXVDO = 2;
		public static final int IXVDOCNV = 3;
		public static final int ALL = 4;

		public DpchAppDo(
					String scrJref
					, int ixVDo
					, int ixVDoCnv
					, Integer[] mask
				) {
			super(VecWdbeVDpch.DPCHAPPDLGWDBEUTLIEXCONVDO, scrJref);

			this.mask = new HashSet<Integer>(Arrays.asList(mask));

			for (Integer i: mask)
				if (i == ALL) {
					this.mask = new HashSet<Integer>(Arrays.asList(SCRJREF, IXVDO, IXVDOCNV));
					break;
				};

			this.ixVDo = ixVDo;
			this.ixVDoCnv = ixVDoCnv;
		};

		public int ixVDo;
		public int ixVDoCnv;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(IXVDO)) ss.add("ixVDo");
			if (has(IXVDOCNV)) ss.add("ixVDoCnv");

			return StrMod.vectorToString(ss, ';');
		};

		public void writeXML(
					Document doc
					, Element sup
				) {
			Element el = doc.createElement("DpchAppDlgWdbeUtlIexconvDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
			if (has(IXVDOCNV)) Xmlio.writeString(doc, el, "srefIxVDoCnv", VecVDoCnv.getSref(ixVDoCnv));
		};

	};

	/**
		* DpchEngData (full: DpchEngDlgWdbeUtlIexconvData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int CONTINFCNV = 4;
		public static final int CONTINFRES = 5;
		public static final int FEEDFDSE = 6;
		public static final int FEEDFSGE = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int STATSHRCNV = 10;
		public static final int STATSHRRES = 11;
		public static final int STATSHRSRC = 12;
		public static final int TAG = 13;
		public static final int TAGCNV = 14;
		public static final int TAGRES = 15;
		public static final int TAGSRC = 16;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGDLGWDBEUTLIEXCONVDATA);

			contiac = new ContIac(0);
			continf = new ContInf(0);
			continfcnv = new ContInfCnv("");
			continfres = new ContInfRes("");
			feedFDse = new Feed("FeedFDse");
			feedFSge = new Feed("FeedFSge");
			statapp = new StatApp(false, "");
			statshr = new StatShr(false);
			statshrcnv = new StatShrCnv(false, false);
			statshrres = new StatShrRes(false);
			statshrsrc = new StatShrSrc(false);
			tag = new Tag("", "");
			tagcnv = new TagCnv("", "", "");
			tagres = new TagRes("");
			tagsrc = new TagSrc("", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public ContInfCnv continfcnv;
		public ContInfRes continfres;
		public Feed feedFDse;
		public Feed feedFSge;
		public StatApp statapp;
		public StatShr statshr;
		public StatShrCnv statshrcnv;
		public StatShrRes statshrres;
		public StatShrSrc statshrsrc;
		public Tag tag;
		public TagCnv tagcnv;
		public TagRes tagres;
		public TagSrc tagsrc;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(CONTINFCNV)) ss.add("continfcnv");
			if (has(CONTINFRES)) ss.add("continfres");
			if (has(FEEDFDSE)) ss.add("feedFDse");
			if (has(FEEDFSGE)) ss.add("feedFSge");
			if (has(STATAPP)) ss.add("statapp");
			if (has(STATSHR)) ss.add("statshr");
			if (has(STATSHRCNV)) ss.add("statshrcnv");
			if (has(STATSHRRES)) ss.add("statshrres");
			if (has(STATSHRSRC)) ss.add("statshrsrc");
			if (has(TAG)) ss.add("tag");
			if (has(TAGCNV)) ss.add("tagcnv");
			if (has(TAGRES)) ss.add("tagres");
			if (has(TAGSRC)) ss.add("tagsrc");

			return StrMod.vectorToString(ss, ';');
		};

		public void readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngDlgWdbeUtlIexconvData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (continfcnv.readXML(doc, basexpath, true)) add(CONTINFCNV);
				if (continfres.readXML(doc, basexpath, true)) add(CONTINFRES);
				if (feedFDse.readXML(doc, basexpath, true)) add(FEEDFDSE);
				if (feedFSge.readXML(doc, basexpath, true)) add(FEEDFSGE);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (statshrcnv.readXML(doc, basexpath, true)) add(STATSHRCNV);
				if (statshrres.readXML(doc, basexpath, true)) add(STATSHRRES);
				if (statshrsrc.readXML(doc, basexpath, true)) add(STATSHRSRC);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
				if (tagcnv.readXML(doc, basexpath, true)) add(TAGCNV);
				if (tagres.readXML(doc, basexpath, true)) add(TAGRES);
				if (tagsrc.readXML(doc, basexpath, true)) add(TAGSRC);
			} else {
				scrJref = "";
				contiac = new ContIac(0);
				continf = new ContInf(0);
				continfcnv = new ContInfCnv("");
				continfres = new ContInfRes("");
				feedFDse = new Feed("FeedFDse");
				feedFSge = new Feed("FeedFSge");
				statapp = new StatApp(false, "");
				statshr = new StatShr(false);
				statshrcnv = new StatShrCnv(false, false);
				statshrres = new StatShrRes(false);
				statshrsrc = new StatShrSrc(false);
				tag = new Tag("", "");
				tagcnv = new TagCnv("", "", "");
				tagres = new TagRes("");
				tagsrc = new TagSrc("", "");
			};
		};

	};

};

