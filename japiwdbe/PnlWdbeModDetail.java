/**
  * \file PnlWdbeModDetail.java
  * Java API code for job PnlWdbeModDetail
  * \author Alexander Wirthmueller
  * \date created: 11 Jul 2020
  * \date modified: 11 Jul 2020
  */

package apiwdbe;

import java.util.*;
import org.w3c.dom.*;
import sbecore.*;

public class PnlWdbeModDetail {
	/**
		* VecVDo (full: VecVWdbeModDetailDo)
		*/
	public static class VecVDo {

		public static final int BUTSAVECLICK = 1;
		public static final int BUTHKUVIEWCLICK = 2;
		public static final int BUTSUPVIEWCLICK = 3;
		public static final int BUTTPLVIEWCLICK = 4;
		public static final int BUTIMBNEWCLICK = 5;
		public static final int BUTIMBDELETECLICK = 6;
		public static final int BUTIMBCORVIEWCLICK = 7;
		public static final int BUTCTRNEWCLICK = 8;
		public static final int BUTCTRDELETECLICK = 9;
		public static final int BUTCTRFWDVIEWCLICK = 10;
		public static final int BUTCTRCLRVIEWCLICK = 11;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("buthkuviewclick")) return BUTHKUVIEWCLICK;
			if (s.equals("butsupviewclick")) return BUTSUPVIEWCLICK;
			if (s.equals("buttplviewclick")) return BUTTPLVIEWCLICK;
			if (s.equals("butimbnewclick")) return BUTIMBNEWCLICK;
			if (s.equals("butimbdeleteclick")) return BUTIMBDELETECLICK;
			if (s.equals("butimbcorviewclick")) return BUTIMBCORVIEWCLICK;
			if (s.equals("butctrnewclick")) return BUTCTRNEWCLICK;
			if (s.equals("butctrdeleteclick")) return BUTCTRDELETECLICK;
			if (s.equals("butctrfwdviewclick")) return BUTCTRFWDVIEWCLICK;
			if (s.equals("butctrclrviewclick")) return BUTCTRCLRVIEWCLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
			if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
			if (ix == BUTTPLVIEWCLICK) return("ButTplViewClick");
			if (ix == BUTIMBNEWCLICK) return("ButImbNewClick");
			if (ix == BUTIMBDELETECLICK) return("ButImbDeleteClick");
			if (ix == BUTIMBCORVIEWCLICK) return("ButImbCorViewClick");
			if (ix == BUTCTRNEWCLICK) return("ButCtrNewClick");
			if (ix == BUTCTRDELETECLICK) return("ButCtrDeleteClick");
			if (ix == BUTCTRFWDVIEWCLICK) return("ButCtrFwdViewClick");
			if (ix == BUTCTRCLRVIEWCLICK) return("ButCtrClrViewClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeModDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPTYP = 1;
		public static final int NUMFPUPHKT = 2;
		public static final int TXFSRR = 3;
		public static final int TXFCMT = 4;
		public static final int NUMFPUPIMBDIR = 5;
		public static final int TXFIMBPRI = 6;
		public static final int TXFCTRFSR = 7;

		public ContIac(
					int numFPupTyp
					, int numFPupHkt
					, String TxfSrr
					, String TxfCmt
					, int numFPupImbDir
					, String TxfImbPri
					, String TxfCtrFsr
				) {
			this.numFPupTyp = numFPupTyp;
			this.numFPupHkt = numFPupHkt;
			this.TxfSrr = TxfSrr;
			this.TxfCmt = TxfCmt;
			this.numFPupImbDir = numFPupImbDir;
			this.TxfImbPri = TxfImbPri;
			this.TxfCtrFsr = TxfCtrFsr;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, NUMFPUPIMBDIR, TXFIMBPRI, TXFCTRFSR));
		};

		public int numFPupTyp;
		public int numFPupHkt;
		public String TxfSrr;
		public String TxfCmt;
		public int numFPupImbDir;
		public String TxfImbPri;
		public String TxfCtrFsr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeModDetail");

			String itemtag = "ContitemIacWdbeModDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFPupHkt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupHkt", mask, NUMFPUPHKT);
				TxfSrr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSrr", mask, TXFSRR);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);
				numFPupImbDir = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupImbDir", mask, NUMFPUPIMBDIR);
				TxfImbPri = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfImbPri", mask, TXFIMBPRI);
				TxfCtrFsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCtrFsr", mask, TXFCTRFSR);

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
			if (difftag.isEmpty()) difftag = "ContIacWdbeModDetail";

			String itemtag;

			if (shorttags) itemtag = "Ci";
			else itemtag = "ContitemIacWdbeModDetail";

			Element el = doc.createElement(difftag);

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupHkt", numFPupHkt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSrr", TxfSrr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupImbDir", numFPupImbDir);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfImbPri", TxfImbPri);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCtrFsr", TxfCtrFsr);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFPupHkt == comp.numFPupHkt) items.add(NUMFPUPHKT);
			if (TxfSrr.equals(comp.TxfSrr)) items.add(TXFSRR);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);
			if (numFPupImbDir == comp.numFPupImbDir) items.add(NUMFPUPIMBDIR);
			if (TxfImbPri.equals(comp.TxfImbPri)) items.add(TXFIMBPRI);
			if (TxfCtrFsr.equals(comp.TxfCtrFsr)) items.add(TXFCTRFSR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, NUMFPUPIMBDIR, TXFIMBPRI, TXFCTRFSR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * ContInf (full: ContInfWdbeModDetail)
	  */
	public class ContInf extends Block {

		public static final int TXTSRF = 1;
		public static final int TXTHKU = 2;
		public static final int TXTSUP = 3;
		public static final int TXTTPL = 4;
		public static final int TXTIMBSRF = 5;
		public static final int TXTIMBCOR = 6;
		public static final int TXTCTRFWD = 7;
		public static final int TXTCTRCLR = 8;

		public ContInf(
					String TxtSrf
					, String TxtHku
					, String TxtSup
					, String TxtTpl
					, String TxtImbSrf
					, String TxtImbCor
					, String TxtCtrFwd
					, String TxtCtrClr
				) {
			this.TxtSrf = TxtSrf;
			this.TxtHku = TxtHku;
			this.TxtSup = TxtSup;
			this.TxtTpl = TxtTpl;
			this.TxtImbSrf = TxtImbSrf;
			this.TxtImbCor = TxtImbCor;
			this.TxtCtrFwd = TxtCtrFwd;
			this.TxtCtrClr = TxtCtrClr;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTIMBSRF, TXTIMBCOR, TXTCTRFWD, TXTCTRCLR));
		};

		public String TxtSrf;
		public String TxtHku;
		public String TxtSup;
		public String TxtTpl;
		public String TxtImbSrf;
		public String TxtImbCor;
		public String TxtCtrFwd;
		public String TxtCtrClr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContInfWdbeModDetail");

			String itemtag = "ContitemInfWdbeModDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				TxtSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSrf", mask, TXTSRF);
				TxtHku = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtHku", mask, TXTHKU);
				TxtSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtSup", mask, TXTSUP);
				TxtTpl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtTpl", mask, TXTTPL);
				TxtImbSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtImbSrf", mask, TXTIMBSRF);
				TxtImbCor = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtImbCor", mask, TXTIMBCOR);
				TxtCtrFwd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCtrFwd", mask, TXTCTRFWD);
				TxtCtrClr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxtCtrClr", mask, TXTCTRCLR);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					ContInf comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (TxtSrf.equals(comp.TxtSrf)) items.add(TXTSRF);
			if (TxtHku.equals(comp.TxtHku)) items.add(TXTHKU);
			if (TxtSup.equals(comp.TxtSup)) items.add(TXTSUP);
			if (TxtTpl.equals(comp.TxtTpl)) items.add(TXTTPL);
			if (TxtImbSrf.equals(comp.TxtImbSrf)) items.add(TXTIMBSRF);
			if (TxtImbCor.equals(comp.TxtImbCor)) items.add(TXTIMBCOR);
			if (TxtCtrFwd.equals(comp.TxtCtrFwd)) items.add(TXTCTRFWD);
			if (TxtCtrClr.equals(comp.TxtCtrClr)) items.add(TXTCTRCLR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTIMBSRF, TXTIMBCOR, TXTCTRFWD, TXTCTRCLR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeModDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;

		public StatApp(
					int ixWdbeVExpstate
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE));
		};

		public int ixWdbeVExpstate;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {
			String srefIxWdbeVExpstate;

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatAppWdbeModDetail");

			String itemtag = "StatitemAppWdbeModDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				srefIxWdbeVExpstate = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Si", "sref", "srefIxWdbeVExpstate", mask, IXWDBEVEXPSTATE);
				ixWdbeVExpstate = VecWdbeVExpstate.getIx(srefIxWdbeVExpstate);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatShr (full: StatShrWdbeModDetail)
	  */
	public class StatShr extends Block {

		public static final int BUTSAVEAVAIL = 1;
		public static final int BUTSAVEACTIVE = 2;
		public static final int TXTSRFACTIVE = 3;
		public static final int PUPTYPACTIVE = 4;
		public static final int TXTHKUACTIVE = 5;
		public static final int BUTHKUVIEWAVAIL = 6;
		public static final int BUTHKUVIEWACTIVE = 7;
		public static final int TXTSUPACTIVE = 8;
		public static final int BUTSUPVIEWAVAIL = 9;
		public static final int BUTSUPVIEWACTIVE = 10;
		public static final int TXTTPLACTIVE = 11;
		public static final int BUTTPLVIEWAVAIL = 12;
		public static final int BUTTPLVIEWACTIVE = 13;
		public static final int TXFSRRACTIVE = 14;
		public static final int TXFCMTACTIVE = 15;
		public static final int SEPIMBAVAIL = 16;
		public static final int HDGIMBAVAIL = 17;
		public static final int BUTIMBNEWAVAIL = 18;
		public static final int BUTIMBDELETEAVAIL = 19;
		public static final int TXTIMBSRFAVAIL = 20;
		public static final int TXTIMBSRFACTIVE = 21;
		public static final int TXTIMBCORAVAIL = 22;
		public static final int TXTIMBCORACTIVE = 23;
		public static final int BUTIMBCORVIEWAVAIL = 24;
		public static final int BUTIMBCORVIEWACTIVE = 25;
		public static final int PUPIMBDIRAVAIL = 26;
		public static final int PUPIMBDIRACTIVE = 27;
		public static final int TXFIMBPRIAVAIL = 28;
		public static final int TXFIMBPRIACTIVE = 29;
		public static final int SEPCTRAVAIL = 30;
		public static final int HDGCTRAVAIL = 31;
		public static final int BUTCTRNEWAVAIL = 32;
		public static final int BUTCTRDELETEAVAIL = 33;
		public static final int TXFCTRFSRAVAIL = 34;
		public static final int TXFCTRFSRACTIVE = 35;
		public static final int TXTCTRFWDAVAIL = 36;
		public static final int TXTCTRFWDACTIVE = 37;
		public static final int BUTCTRFWDVIEWAVAIL = 38;
		public static final int BUTCTRFWDVIEWACTIVE = 39;
		public static final int TXTCTRCLRAVAIL = 40;
		public static final int TXTCTRCLRACTIVE = 41;
		public static final int BUTCTRCLRVIEWAVAIL = 42;
		public static final int BUTCTRCLRVIEWACTIVE = 43;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupTypActive
					, boolean TxtHkuActive
					, boolean ButHkuViewAvail
					, boolean ButHkuViewActive
					, boolean TxtSupActive
					, boolean ButSupViewAvail
					, boolean ButSupViewActive
					, boolean TxtTplActive
					, boolean ButTplViewAvail
					, boolean ButTplViewActive
					, boolean TxfSrrActive
					, boolean TxfCmtActive
					, boolean SepImbAvail
					, boolean HdgImbAvail
					, boolean ButImbNewAvail
					, boolean ButImbDeleteAvail
					, boolean TxtImbSrfAvail
					, boolean TxtImbSrfActive
					, boolean TxtImbCorAvail
					, boolean TxtImbCorActive
					, boolean ButImbCorViewAvail
					, boolean ButImbCorViewActive
					, boolean PupImbDirAvail
					, boolean PupImbDirActive
					, boolean TxfImbPriAvail
					, boolean TxfImbPriActive
					, boolean SepCtrAvail
					, boolean HdgCtrAvail
					, boolean ButCtrNewAvail
					, boolean ButCtrDeleteAvail
					, boolean TxfCtrFsrAvail
					, boolean TxfCtrFsrActive
					, boolean TxtCtrFwdAvail
					, boolean TxtCtrFwdActive
					, boolean ButCtrFwdViewAvail
					, boolean ButCtrFwdViewActive
					, boolean TxtCtrClrAvail
					, boolean TxtCtrClrActive
					, boolean ButCtrClrViewAvail
					, boolean ButCtrClrViewActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupTypActive = PupTypActive;
			this.TxtHkuActive = TxtHkuActive;
			this.ButHkuViewAvail = ButHkuViewAvail;
			this.ButHkuViewActive = ButHkuViewActive;
			this.TxtSupActive = TxtSupActive;
			this.ButSupViewAvail = ButSupViewAvail;
			this.ButSupViewActive = ButSupViewActive;
			this.TxtTplActive = TxtTplActive;
			this.ButTplViewAvail = ButTplViewAvail;
			this.ButTplViewActive = ButTplViewActive;
			this.TxfSrrActive = TxfSrrActive;
			this.TxfCmtActive = TxfCmtActive;
			this.SepImbAvail = SepImbAvail;
			this.HdgImbAvail = HdgImbAvail;
			this.ButImbNewAvail = ButImbNewAvail;
			this.ButImbDeleteAvail = ButImbDeleteAvail;
			this.TxtImbSrfAvail = TxtImbSrfAvail;
			this.TxtImbSrfActive = TxtImbSrfActive;
			this.TxtImbCorAvail = TxtImbCorAvail;
			this.TxtImbCorActive = TxtImbCorActive;
			this.ButImbCorViewAvail = ButImbCorViewAvail;
			this.ButImbCorViewActive = ButImbCorViewActive;
			this.PupImbDirAvail = PupImbDirAvail;
			this.PupImbDirActive = PupImbDirActive;
			this.TxfImbPriAvail = TxfImbPriAvail;
			this.TxfImbPriActive = TxfImbPriActive;
			this.SepCtrAvail = SepCtrAvail;
			this.HdgCtrAvail = HdgCtrAvail;
			this.ButCtrNewAvail = ButCtrNewAvail;
			this.ButCtrDeleteAvail = ButCtrDeleteAvail;
			this.TxfCtrFsrAvail = TxfCtrFsrAvail;
			this.TxfCtrFsrActive = TxfCtrFsrActive;
			this.TxtCtrFwdAvail = TxtCtrFwdAvail;
			this.TxtCtrFwdActive = TxtCtrFwdActive;
			this.ButCtrFwdViewAvail = ButCtrFwdViewAvail;
			this.ButCtrFwdViewActive = ButCtrFwdViewActive;
			this.TxtCtrClrAvail = TxtCtrClrAvail;
			this.TxtCtrClrActive = TxtCtrClrActive;
			this.ButCtrClrViewAvail = ButCtrClrViewAvail;
			this.ButCtrClrViewActive = ButCtrClrViewActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXTIMBSRFAVAIL, TXTIMBSRFACTIVE, TXTIMBCORAVAIL, TXTIMBCORACTIVE, BUTIMBCORVIEWAVAIL, BUTIMBCORVIEWACTIVE, PUPIMBDIRAVAIL, PUPIMBDIRACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRFWDAVAIL, TXTCTRFWDACTIVE, BUTCTRFWDVIEWAVAIL, BUTCTRFWDVIEWACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupTypActive;
		public boolean TxtHkuActive;
		public boolean ButHkuViewAvail;
		public boolean ButHkuViewActive;
		public boolean TxtSupActive;
		public boolean ButSupViewAvail;
		public boolean ButSupViewActive;
		public boolean TxtTplActive;
		public boolean ButTplViewAvail;
		public boolean ButTplViewActive;
		public boolean TxfSrrActive;
		public boolean TxfCmtActive;
		public boolean SepImbAvail;
		public boolean HdgImbAvail;
		public boolean ButImbNewAvail;
		public boolean ButImbDeleteAvail;
		public boolean TxtImbSrfAvail;
		public boolean TxtImbSrfActive;
		public boolean TxtImbCorAvail;
		public boolean TxtImbCorActive;
		public boolean ButImbCorViewAvail;
		public boolean ButImbCorViewActive;
		public boolean PupImbDirAvail;
		public boolean PupImbDirActive;
		public boolean TxfImbPriAvail;
		public boolean TxfImbPriActive;
		public boolean SepCtrAvail;
		public boolean HdgCtrAvail;
		public boolean ButCtrNewAvail;
		public boolean ButCtrDeleteAvail;
		public boolean TxfCtrFsrAvail;
		public boolean TxfCtrFsrActive;
		public boolean TxtCtrFwdAvail;
		public boolean TxtCtrFwdActive;
		public boolean ButCtrFwdViewAvail;
		public boolean ButCtrFwdViewActive;
		public boolean TxtCtrClrAvail;
		public boolean TxtCtrClrActive;
		public boolean ButCtrClrViewAvail;
		public boolean ButCtrClrViewActive;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "StatShrWdbeModDetail");

			String itemtag = "StatitemShrWdbeModDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				ButSaveAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveAvail", mask, BUTSAVEAVAIL);
				ButSaveActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSaveActive", mask, BUTSAVEACTIVE);
				TxtSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSrfActive", mask, TXTSRFACTIVE);
				PupTypActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupTypActive", mask, PUPTYPACTIVE);
				TxtHkuActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtHkuActive", mask, TXTHKUACTIVE);
				ButHkuViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHkuViewAvail", mask, BUTHKUVIEWAVAIL);
				ButHkuViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButHkuViewActive", mask, BUTHKUVIEWACTIVE);
				TxtSupActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtSupActive", mask, TXTSUPACTIVE);
				ButSupViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewAvail", mask, BUTSUPVIEWAVAIL);
				ButSupViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButSupViewActive", mask, BUTSUPVIEWACTIVE);
				TxtTplActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtTplActive", mask, TXTTPLACTIVE);
				ButTplViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTplViewAvail", mask, BUTTPLVIEWAVAIL);
				ButTplViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButTplViewActive", mask, BUTTPLVIEWACTIVE);
				TxfSrrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfSrrActive", mask, TXFSRRACTIVE);
				TxfCmtActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCmtActive", mask, TXFCMTACTIVE);
				SepImbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SepImbAvail", mask, SEPIMBAVAIL);
				HdgImbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "HdgImbAvail", mask, HDGIMBAVAIL);
				ButImbNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImbNewAvail", mask, BUTIMBNEWAVAIL);
				ButImbDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImbDeleteAvail", mask, BUTIMBDELETEAVAIL);
				TxtImbSrfAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtImbSrfAvail", mask, TXTIMBSRFAVAIL);
				TxtImbSrfActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtImbSrfActive", mask, TXTIMBSRFACTIVE);
				TxtImbCorAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtImbCorAvail", mask, TXTIMBCORAVAIL);
				TxtImbCorActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtImbCorActive", mask, TXTIMBCORACTIVE);
				ButImbCorViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImbCorViewAvail", mask, BUTIMBCORVIEWAVAIL);
				ButImbCorViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImbCorViewActive", mask, BUTIMBCORVIEWACTIVE);
				PupImbDirAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupImbDirAvail", mask, PUPIMBDIRAVAIL);
				PupImbDirActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupImbDirActive", mask, PUPIMBDIRACTIVE);
				TxfImbPriAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbPriAvail", mask, TXFIMBPRIAVAIL);
				TxfImbPriActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbPriActive", mask, TXFIMBPRIACTIVE);
				SepCtrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SepCtrAvail", mask, SEPCTRAVAIL);
				HdgCtrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "HdgCtrAvail", mask, HDGCTRAVAIL);
				ButCtrNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrNewAvail", mask, BUTCTRNEWAVAIL);
				ButCtrDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrDeleteAvail", mask, BUTCTRDELETEAVAIL);
				TxfCtrFsrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCtrFsrAvail", mask, TXFCTRFSRAVAIL);
				TxfCtrFsrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCtrFsrActive", mask, TXFCTRFSRACTIVE);
				TxtCtrFwdAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCtrFwdAvail", mask, TXTCTRFWDAVAIL);
				TxtCtrFwdActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCtrFwdActive", mask, TXTCTRFWDACTIVE);
				ButCtrFwdViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrFwdViewAvail", mask, BUTCTRFWDVIEWAVAIL);
				ButCtrFwdViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrFwdViewActive", mask, BUTCTRFWDVIEWACTIVE);
				TxtCtrClrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCtrClrAvail", mask, TXTCTRCLRAVAIL);
				TxtCtrClrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCtrClrActive", mask, TXTCTRCLRACTIVE);
				ButCtrClrViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrClrViewAvail", mask, BUTCTRCLRVIEWAVAIL);
				ButCtrClrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrClrViewActive", mask, BUTCTRCLRVIEWACTIVE);

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
			if (PupTypActive == comp.PupTypActive) items.add(PUPTYPACTIVE);
			if (TxtHkuActive == comp.TxtHkuActive) items.add(TXTHKUACTIVE);
			if (ButHkuViewAvail == comp.ButHkuViewAvail) items.add(BUTHKUVIEWAVAIL);
			if (ButHkuViewActive == comp.ButHkuViewActive) items.add(BUTHKUVIEWACTIVE);
			if (TxtSupActive == comp.TxtSupActive) items.add(TXTSUPACTIVE);
			if (ButSupViewAvail == comp.ButSupViewAvail) items.add(BUTSUPVIEWAVAIL);
			if (ButSupViewActive == comp.ButSupViewActive) items.add(BUTSUPVIEWACTIVE);
			if (TxtTplActive == comp.TxtTplActive) items.add(TXTTPLACTIVE);
			if (ButTplViewAvail == comp.ButTplViewAvail) items.add(BUTTPLVIEWAVAIL);
			if (ButTplViewActive == comp.ButTplViewActive) items.add(BUTTPLVIEWACTIVE);
			if (TxfSrrActive == comp.TxfSrrActive) items.add(TXFSRRACTIVE);
			if (TxfCmtActive == comp.TxfCmtActive) items.add(TXFCMTACTIVE);
			if (SepImbAvail == comp.SepImbAvail) items.add(SEPIMBAVAIL);
			if (HdgImbAvail == comp.HdgImbAvail) items.add(HDGIMBAVAIL);
			if (ButImbNewAvail == comp.ButImbNewAvail) items.add(BUTIMBNEWAVAIL);
			if (ButImbDeleteAvail == comp.ButImbDeleteAvail) items.add(BUTIMBDELETEAVAIL);
			if (TxtImbSrfAvail == comp.TxtImbSrfAvail) items.add(TXTIMBSRFAVAIL);
			if (TxtImbSrfActive == comp.TxtImbSrfActive) items.add(TXTIMBSRFACTIVE);
			if (TxtImbCorAvail == comp.TxtImbCorAvail) items.add(TXTIMBCORAVAIL);
			if (TxtImbCorActive == comp.TxtImbCorActive) items.add(TXTIMBCORACTIVE);
			if (ButImbCorViewAvail == comp.ButImbCorViewAvail) items.add(BUTIMBCORVIEWAVAIL);
			if (ButImbCorViewActive == comp.ButImbCorViewActive) items.add(BUTIMBCORVIEWACTIVE);
			if (PupImbDirAvail == comp.PupImbDirAvail) items.add(PUPIMBDIRAVAIL);
			if (PupImbDirActive == comp.PupImbDirActive) items.add(PUPIMBDIRACTIVE);
			if (TxfImbPriAvail == comp.TxfImbPriAvail) items.add(TXFIMBPRIAVAIL);
			if (TxfImbPriActive == comp.TxfImbPriActive) items.add(TXFIMBPRIACTIVE);
			if (SepCtrAvail == comp.SepCtrAvail) items.add(SEPCTRAVAIL);
			if (HdgCtrAvail == comp.HdgCtrAvail) items.add(HDGCTRAVAIL);
			if (ButCtrNewAvail == comp.ButCtrNewAvail) items.add(BUTCTRNEWAVAIL);
			if (ButCtrDeleteAvail == comp.ButCtrDeleteAvail) items.add(BUTCTRDELETEAVAIL);
			if (TxfCtrFsrAvail == comp.TxfCtrFsrAvail) items.add(TXFCTRFSRAVAIL);
			if (TxfCtrFsrActive == comp.TxfCtrFsrActive) items.add(TXFCTRFSRACTIVE);
			if (TxtCtrFwdAvail == comp.TxtCtrFwdAvail) items.add(TXTCTRFWDAVAIL);
			if (TxtCtrFwdActive == comp.TxtCtrFwdActive) items.add(TXTCTRFWDACTIVE);
			if (ButCtrFwdViewAvail == comp.ButCtrFwdViewAvail) items.add(BUTCTRFWDVIEWAVAIL);
			if (ButCtrFwdViewActive == comp.ButCtrFwdViewActive) items.add(BUTCTRFWDVIEWACTIVE);
			if (TxtCtrClrAvail == comp.TxtCtrClrAvail) items.add(TXTCTRCLRAVAIL);
			if (TxtCtrClrActive == comp.TxtCtrClrActive) items.add(TXTCTRCLRACTIVE);
			if (ButCtrClrViewAvail == comp.ButCtrClrViewAvail) items.add(BUTCTRCLRVIEWAVAIL);
			if (ButCtrClrViewActive == comp.ButCtrClrViewActive) items.add(BUTCTRCLRVIEWACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXTIMBSRFAVAIL, TXTIMBSRFACTIVE, TXTIMBCORAVAIL, TXTIMBCORACTIVE, BUTIMBCORVIEWAVAIL, BUTIMBCORVIEWACTIVE, PUPIMBDIRAVAIL, PUPIMBDIRACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRFWDAVAIL, TXTCTRFWDACTIVE, BUTCTRFWDVIEWAVAIL, BUTCTRFWDVIEWACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * Tag (full: TagWdbeModDetail)
	  */
	public class Tag extends Block {

		public static final int CPT = 1;
		public static final int CPTSRF = 2;
		public static final int CPTTYP = 3;
		public static final int CPTHKU = 4;
		public static final int CPTSUP = 5;
		public static final int CPTTPL = 6;
		public static final int CPTSRR = 7;
		public static final int CPTCMT = 8;
		public static final int HDGIMB = 9;
		public static final int CPTIMBSRF = 10;
		public static final int CPTIMBCOR = 11;
		public static final int CPTIMBDIR = 12;
		public static final int CPTIMBPRI = 13;
		public static final int HDGCTR = 14;
		public static final int CPTCTRFSR = 15;
		public static final int CPTCTRFWD = 16;
		public static final int CPTCTRCLR = 17;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptTyp
					, String CptHku
					, String CptSup
					, String CptTpl
					, String CptSrr
					, String CptCmt
					, String HdgImb
					, String CptImbSrf
					, String CptImbCor
					, String CptImbDir
					, String CptImbPri
					, String HdgCtr
					, String CptCtrFsr
					, String CptCtrFwd
					, String CptCtrClr
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptTyp = CptTyp;
			this.CptHku = CptHku;
			this.CptSup = CptSup;
			this.CptTpl = CptTpl;
			this.CptSrr = CptSrr;
			this.CptCmt = CptCmt;
			this.HdgImb = HdgImb;
			this.CptImbSrf = CptImbSrf;
			this.CptImbCor = CptImbCor;
			this.CptImbDir = CptImbDir;
			this.CptImbPri = CptImbPri;
			this.HdgCtr = HdgCtr;
			this.CptCtrFsr = CptCtrFsr;
			this.CptCtrFwd = CptCtrFwd;
			this.CptCtrClr = CptCtrClr;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTHKU, CPTSUP, CPTTPL, CPTSRR, CPTCMT, HDGIMB, CPTIMBSRF, CPTIMBCOR, CPTIMBDIR, CPTIMBPRI, HDGCTR, CPTCTRFSR, CPTCTRFWD, CPTCTRCLR));
		};

		public String Cpt;
		public String CptSrf;
		public String CptTyp;
		public String CptHku;
		public String CptSup;
		public String CptTpl;
		public String CptSrr;
		public String CptCmt;
		public String HdgImb;
		public String CptImbSrf;
		public String CptImbCor;
		public String CptImbDir;
		public String CptImbPri;
		public String HdgCtr;
		public String CptCtrFsr;
		public String CptCtrFwd;
		public String CptCtrClr;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "TagWdbeModDetail");

			String itemtag = "TagitemWdbeModDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				Cpt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "Cpt", mask, CPT);
				CptSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrf", mask, CPTSRF);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptHku = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHku", mask, CPTHKU);
				CptSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSup", mask, CPTSUP);
				CptTpl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTpl", mask, CPTTPL);
				CptSrr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrr", mask, CPTSRR);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);
				HdgImb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgImb", mask, HDGIMB);
				CptImbSrf = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImbSrf", mask, CPTIMBSRF);
				CptImbCor = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImbCor", mask, CPTIMBCOR);
				CptImbDir = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImbDir", mask, CPTIMBDIR);
				CptImbPri = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImbPri", mask, CPTIMBPRI);
				HdgCtr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgCtr", mask, HDGCTR);
				CptCtrFsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCtrFsr", mask, CPTCTRFSR);
				CptCtrFwd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCtrFwd", mask, CPTCTRFWD);
				CptCtrClr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCtrClr", mask, CPTCTRCLR);

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
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptHku.equals(comp.CptHku)) items.add(CPTHKU);
			if (CptSup.equals(comp.CptSup)) items.add(CPTSUP);
			if (CptTpl.equals(comp.CptTpl)) items.add(CPTTPL);
			if (CptSrr.equals(comp.CptSrr)) items.add(CPTSRR);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);
			if (HdgImb.equals(comp.HdgImb)) items.add(HDGIMB);
			if (CptImbSrf.equals(comp.CptImbSrf)) items.add(CPTIMBSRF);
			if (CptImbCor.equals(comp.CptImbCor)) items.add(CPTIMBCOR);
			if (CptImbDir.equals(comp.CptImbDir)) items.add(CPTIMBDIR);
			if (CptImbPri.equals(comp.CptImbPri)) items.add(CPTIMBPRI);
			if (HdgCtr.equals(comp.HdgCtr)) items.add(HDGCTR);
			if (CptCtrFsr.equals(comp.CptCtrFsr)) items.add(CPTCTRFSR);
			if (CptCtrFwd.equals(comp.CptCtrFwd)) items.add(CPTCTRFWD);
			if (CptCtrClr.equals(comp.CptCtrClr)) items.add(CPTCTRCLR);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTTYP, CPTHKU, CPTSUP, CPTTPL, CPTSRR, CPTCMT, HDGIMB, CPTIMBSRF, CPTIMBCOR, CPTIMBDIR, CPTIMBPRI, HDGCTR, CPTCTRFSR, CPTCTRFWD, CPTCTRCLR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
		* DpchAppData (full: DpchAppWdbeModDetailData)
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
			super(VecWdbeVDpch.DPCHAPPWDBEMODDETAILDATA, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeModDetailData");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(CONTIAC)) contiac.writeXML(doc, el, "", true);
		};

	};

	/**
		* DpchAppDo (full: DpchAppWdbeModDetailDo)
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
			super(VecWdbeVDpch.DPCHAPPWDBEMODDETAILDO, scrJref);

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
			Element el = doc.createElement("DpchAppWdbeModDetailDo");

			if (sup == null) doc.appendChild(el);
			else sup.appendChild(el);

			el.setAttribute("xmlns", "http://www.mpsitech.com");

			if (has(SCRJREF)) Xmlio.writeString(doc, el, "scrJref", scrJref);
			if (has(IXVDO)) Xmlio.writeString(doc, el, "srefIxVDo", VecVDo.getSref(ixVDo));
		};

	};

	/**
		* DpchEngData (full: DpchEngWdbeModDetailData)
		*/
	public class DpchEngData extends DpchEngWdbe {

		public static final int SCRJREF = 1;
		public static final int CONTIAC = 2;
		public static final int CONTINF = 3;
		public static final int FEEDFPUPHKT = 4;
		public static final int FEEDFPUPIMBDIR = 5;
		public static final int FEEDFPUPTYP = 6;
		public static final int STATAPP = 7;
		public static final int STATSHR = 8;
		public static final int TAG = 9;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEMODDETAILDATA);

			contiac = new ContIac(0, 0, "", "", 0, "", "");
			continf = new ContInf("", "", "", "", "", "", "", "");
			feedFPupHkt = new Feed("FeedFPupHkt");
			feedFPupImbDir = new Feed("FeedFPupImbDir");
			feedFPupTyp = new Feed("FeedFPupTyp");
			statapp = new StatApp(0);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupHkt;
		public Feed feedFPupImbDir;
		public Feed feedFPupTyp;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPHKT)) ss.add("feedFPupHkt");
			if (has(FEEDFPUPIMBDIR)) ss.add("feedFPupImbDir");
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

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "DpchEngWdbeModDetailData");

			if (Xmlio.checkXPath(doc, basexpath)) {
				scrJref = Xmlio.extractStringUclc(doc, basexpath, "scrJref", "", mask, SCRJREF);
				if (contiac.readXML(doc, basexpath, true)) add(CONTIAC);
				if (continf.readXML(doc, basexpath, true)) add(CONTINF);
				if (feedFPupHkt.readXML(doc, basexpath, true)) add(FEEDFPUPHKT);
				if (feedFPupImbDir.readXML(doc, basexpath, true)) add(FEEDFPUPIMBDIR);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, 0, "", "", 0, "", "");
				continf = new ContInf("", "", "", "", "", "", "", "");
				feedFPupHkt = new Feed("FeedFPupHkt");
				feedFPupImbDir = new Feed("FeedFPupImbDir");
				feedFPupTyp = new Feed("FeedFPupTyp");
				statapp = new StatApp(0);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};

