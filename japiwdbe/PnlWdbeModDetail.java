/**
  * \file PnlWdbeModDetail.java
  * Java API code for job PnlWdbeModDetail
	* \copyright (C) 2018-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

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
		public static final int BUTVNDEDITCLICK = 2;
		public static final int BUTHKUVIEWCLICK = 3;
		public static final int BUTSUPVIEWCLICK = 4;
		public static final int BUTTPLVIEWCLICK = 5;
		public static final int BUTCTRNEWCLICK = 6;
		public static final int BUTCTRDELETECLICK = 7;
		public static final int BUTCTRCLRVIEWCLICK = 8;
		public static final int BUTIMBNEWCLICK = 9;
		public static final int BUTIMBDELETECLICK = 10;

		public static int getIx(
					String sref
				) {
			String s = sref.toLowerCase();

			if (s.equals("butsaveclick")) return BUTSAVECLICK;
			if (s.equals("butvndeditclick")) return BUTVNDEDITCLICK;
			if (s.equals("buthkuviewclick")) return BUTHKUVIEWCLICK;
			if (s.equals("butsupviewclick")) return BUTSUPVIEWCLICK;
			if (s.equals("buttplviewclick")) return BUTTPLVIEWCLICK;
			if (s.equals("butctrnewclick")) return BUTCTRNEWCLICK;
			if (s.equals("butctrdeleteclick")) return BUTCTRDELETECLICK;
			if (s.equals("butctrclrviewclick")) return BUTCTRCLRVIEWCLICK;
			if (s.equals("butimbnewclick")) return BUTIMBNEWCLICK;
			if (s.equals("butimbdeleteclick")) return BUTIMBDELETECLICK;

			return 0;
		};

		public static String getSref(
					int ix
				) {
			if (ix == BUTSAVECLICK) return("ButSaveClick");
			if (ix == BUTVNDEDITCLICK) return("ButVndEditClick");
			if (ix == BUTHKUVIEWCLICK) return("ButHkuViewClick");
			if (ix == BUTSUPVIEWCLICK) return("ButSupViewClick");
			if (ix == BUTTPLVIEWCLICK) return("ButTplViewClick");
			if (ix == BUTCTRNEWCLICK) return("ButCtrNewClick");
			if (ix == BUTCTRDELETECLICK) return("ButCtrDeleteClick");
			if (ix == BUTCTRCLRVIEWCLICK) return("ButCtrClrViewClick");
			if (ix == BUTIMBNEWCLICK) return("ButImbNewClick");
			if (ix == BUTIMBDELETECLICK) return("ButImbDeleteClick");

			return "";
		};

	};

	/**
	  * ContIac (full: ContIacWdbeModDetail)
	  */
	public class ContIac extends Block {

		public static final int NUMFPUPVND = 1;
		public static final int TXFVND = 2;
		public static final int NUMFPUPTYP = 3;
		public static final int NUMFPUPHKT = 4;
		public static final int TXFSRR = 5;
		public static final int TXFCMT = 6;
		public static final int TXFCTRFSR = 7;
		public static final int TXFIMBFSR = 8;
		public static final int NUMFPUPIMBRTY = 9;
		public static final int TXFIMBWID = 10;
		public static final int TXFIMBMMX = 11;
		public static final int TXFIMBPRI = 12;

		public ContIac(
					int numFPupVnd
					, String TxfVnd
					, int numFPupTyp
					, int numFPupHkt
					, String TxfSrr
					, String TxfCmt
					, String TxfCtrFsr
					, String TxfImbFsr
					, int numFPupImbRty
					, String TxfImbWid
					, String TxfImbMmx
					, String TxfImbPri
				) {
			this.numFPupVnd = numFPupVnd;
			this.TxfVnd = TxfVnd;
			this.numFPupTyp = numFPupTyp;
			this.numFPupHkt = numFPupHkt;
			this.TxfSrr = TxfSrr;
			this.TxfCmt = TxfCmt;
			this.TxfCtrFsr = TxfCtrFsr;
			this.TxfImbFsr = TxfImbFsr;
			this.numFPupImbRty = numFPupImbRty;
			this.TxfImbWid = TxfImbWid;
			this.TxfImbMmx = TxfImbMmx;
			this.TxfImbPri = TxfImbPri;

			mask = new HashSet<Integer>(Arrays.asList(NUMFPUPVND, TXFVND, NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, TXFCTRFSR, TXFIMBFSR, NUMFPUPIMBRTY, TXFIMBWID, TXFIMBMMX, TXFIMBPRI));
		};

		public int numFPupVnd;
		public String TxfVnd;
		public int numFPupTyp;
		public int numFPupHkt;
		public String TxfSrr;
		public String TxfCmt;
		public String TxfCtrFsr;
		public String TxfImbFsr;
		public int numFPupImbRty;
		public String TxfImbWid;
		public String TxfImbMmx;
		public String TxfImbPri;

		public boolean readXML(
					Document doc
					, String basexpath
					, boolean addbasetag
				) {

			clear();

			if (addbasetag) basexpath = Xmlio.checkUclcXPaths(doc, basexpath, "ContIacWdbeModDetail");

			String itemtag = "ContitemIacWdbeModDetail";

			if (Xmlio.checkXPath(doc, basexpath)) {
				numFPupVnd = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupVnd", mask, NUMFPUPVND);
				TxfVnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfVnd", mask, TXFVND);
				numFPupTyp = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupTyp", mask, NUMFPUPTYP);
				numFPupHkt = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupHkt", mask, NUMFPUPHKT);
				TxfSrr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfSrr", mask, TXFSRR);
				TxfCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCmt", mask, TXFCMT);
				TxfCtrFsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfCtrFsr", mask, TXFCTRFSR);
				TxfImbFsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfImbFsr", mask, TXFIMBFSR);
				numFPupImbRty = Xmlio.extractIntegerAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "numFPupImbRty", mask, NUMFPUPIMBRTY);
				TxfImbWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfImbWid", mask, TXFIMBWID);
				TxfImbMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfImbMmx", mask, TXFIMBMMX);
				TxfImbPri = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ci", "sref", "TxfImbPri", mask, TXFIMBPRI);

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

			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupVnd", numFPupVnd);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfVnd", TxfVnd);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupTyp", numFPupTyp);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupHkt", numFPupHkt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfSrr", TxfSrr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCmt", TxfCmt);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfCtrFsr", TxfCtrFsr);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfImbFsr", TxfImbFsr);
			Xmlio.writeIntegerAttr(doc, el, itemtag, "sref", "numFPupImbRty", numFPupImbRty);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfImbWid", TxfImbWid);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfImbMmx", TxfImbMmx);
			Xmlio.writeStringAttr(doc, el, itemtag, "sref", "TxfImbPri", TxfImbPri);
		};

		public HashSet<Integer> comm(
					ContIac comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (numFPupVnd == comp.numFPupVnd) items.add(NUMFPUPVND);
			if (TxfVnd.equals(comp.TxfVnd)) items.add(TXFVND);
			if (numFPupTyp == comp.numFPupTyp) items.add(NUMFPUPTYP);
			if (numFPupHkt == comp.numFPupHkt) items.add(NUMFPUPHKT);
			if (TxfSrr.equals(comp.TxfSrr)) items.add(TXFSRR);
			if (TxfCmt.equals(comp.TxfCmt)) items.add(TXFCMT);
			if (TxfCtrFsr.equals(comp.TxfCtrFsr)) items.add(TXFCTRFSR);
			if (TxfImbFsr.equals(comp.TxfImbFsr)) items.add(TXFIMBFSR);
			if (numFPupImbRty == comp.numFPupImbRty) items.add(NUMFPUPIMBRTY);
			if (TxfImbWid.equals(comp.TxfImbWid)) items.add(TXFIMBWID);
			if (TxfImbMmx.equals(comp.TxfImbMmx)) items.add(TXFIMBMMX);
			if (TxfImbPri.equals(comp.TxfImbPri)) items.add(TXFIMBPRI);

			return(items);
		};

		public HashSet<Integer> diff(
					ContIac comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(NUMFPUPVND, TXFVND, NUMFPUPTYP, NUMFPUPHKT, TXFSRR, TXFCMT, TXFCTRFSR, TXFIMBFSR, NUMFPUPIMBRTY, TXFIMBWID, TXFIMBMMX, TXFIMBPRI));
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
		public static final int TXTCTRCLR = 5;

		public ContInf(
					String TxtSrf
					, String TxtHku
					, String TxtSup
					, String TxtTpl
					, String TxtCtrClr
				) {
			this.TxtSrf = TxtSrf;
			this.TxtHku = TxtHku;
			this.TxtSup = TxtSup;
			this.TxtTpl = TxtTpl;
			this.TxtCtrClr = TxtCtrClr;

			mask = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTCTRCLR));
		};

		public String TxtSrf;
		public String TxtHku;
		public String TxtSup;
		public String TxtTpl;
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
			if (TxtCtrClr.equals(comp.TxtCtrClr)) items.add(TXTCTRCLR);

			return(items);
		};

		public HashSet<Integer> diff(
					ContInf comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(TXTSRF, TXTHKU, TXTSUP, TXTTPL, TXTCTRCLR));
			for (Integer ci: commitems) diffitems.remove(ci);

			return(diffitems);
		};

	};

	/**
	  * StatApp (full: StatAppWdbeModDetail)
	  */
	public class StatApp extends Block {

		public static final int IXWDBEVEXPSTATE = 1;
		public static final int PUPVNDALT = 2;

		public StatApp(
					int ixWdbeVExpstate
					, boolean PupVndAlt
				) {
			this.ixWdbeVExpstate = ixWdbeVExpstate;
			this.PupVndAlt = PupVndAlt;

			mask = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPVNDALT));
		};

		public int ixWdbeVExpstate;
		public boolean PupVndAlt;

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
				PupVndAlt = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupVndAlt", mask, PUPVNDALT);

				return true;
			};

			return false;
		};

		public HashSet<Integer> comm(
					StatApp comp
				) {
			HashSet<Integer> items = new HashSet<Integer>();

			if (ixWdbeVExpstate == comp.ixWdbeVExpstate) items.add(IXWDBEVEXPSTATE);
			if (PupVndAlt == comp.PupVndAlt) items.add(PUPVNDALT);

			return(items);
		};

		public HashSet<Integer> diff(
					StatApp comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(IXWDBEVEXPSTATE, PUPVNDALT));
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
		public static final int PUPVNDACTIVE = 4;
		public static final int TXFVNDVALID = 5;
		public static final int BUTVNDEDITAVAIL = 6;
		public static final int PUPTYPACTIVE = 7;
		public static final int TXTHKUACTIVE = 8;
		public static final int BUTHKUVIEWAVAIL = 9;
		public static final int BUTHKUVIEWACTIVE = 10;
		public static final int TXTSUPACTIVE = 11;
		public static final int BUTSUPVIEWAVAIL = 12;
		public static final int BUTSUPVIEWACTIVE = 13;
		public static final int TXTTPLACTIVE = 14;
		public static final int BUTTPLVIEWAVAIL = 15;
		public static final int BUTTPLVIEWACTIVE = 16;
		public static final int TXFSRRACTIVE = 17;
		public static final int TXFCMTACTIVE = 18;
		public static final int SEPCTRAVAIL = 19;
		public static final int HDGCTRAVAIL = 20;
		public static final int BUTCTRNEWAVAIL = 21;
		public static final int BUTCTRDELETEAVAIL = 22;
		public static final int TXFCTRFSRAVAIL = 23;
		public static final int TXFCTRFSRACTIVE = 24;
		public static final int TXTCTRCLRAVAIL = 25;
		public static final int TXTCTRCLRACTIVE = 26;
		public static final int BUTCTRCLRVIEWAVAIL = 27;
		public static final int BUTCTRCLRVIEWACTIVE = 28;
		public static final int SEPIMBAVAIL = 29;
		public static final int HDGIMBAVAIL = 30;
		public static final int BUTIMBNEWAVAIL = 31;
		public static final int BUTIMBDELETEAVAIL = 32;
		public static final int TXFIMBFSRAVAIL = 33;
		public static final int TXFIMBFSRACTIVE = 34;
		public static final int PUPIMBRTYAVAIL = 35;
		public static final int PUPIMBRTYACTIVE = 36;
		public static final int TXFIMBWIDAVAIL = 37;
		public static final int TXFIMBWIDACTIVE = 38;
		public static final int TXFIMBMMXAVAIL = 39;
		public static final int TXFIMBMMXACTIVE = 40;
		public static final int TXFIMBPRIAVAIL = 41;
		public static final int TXFIMBPRIACTIVE = 42;

		public StatShr(
					boolean ButSaveAvail
					, boolean ButSaveActive
					, boolean TxtSrfActive
					, boolean PupVndActive
					, boolean TxfVndValid
					, boolean ButVndEditAvail
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
					, boolean SepCtrAvail
					, boolean HdgCtrAvail
					, boolean ButCtrNewAvail
					, boolean ButCtrDeleteAvail
					, boolean TxfCtrFsrAvail
					, boolean TxfCtrFsrActive
					, boolean TxtCtrClrAvail
					, boolean TxtCtrClrActive
					, boolean ButCtrClrViewAvail
					, boolean ButCtrClrViewActive
					, boolean SepImbAvail
					, boolean HdgImbAvail
					, boolean ButImbNewAvail
					, boolean ButImbDeleteAvail
					, boolean TxfImbFsrAvail
					, boolean TxfImbFsrActive
					, boolean PupImbRtyAvail
					, boolean PupImbRtyActive
					, boolean TxfImbWidAvail
					, boolean TxfImbWidActive
					, boolean TxfImbMmxAvail
					, boolean TxfImbMmxActive
					, boolean TxfImbPriAvail
					, boolean TxfImbPriActive
				) {
			this.ButSaveAvail = ButSaveAvail;
			this.ButSaveActive = ButSaveActive;
			this.TxtSrfActive = TxtSrfActive;
			this.PupVndActive = PupVndActive;
			this.TxfVndValid = TxfVndValid;
			this.ButVndEditAvail = ButVndEditAvail;
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
			this.SepCtrAvail = SepCtrAvail;
			this.HdgCtrAvail = HdgCtrAvail;
			this.ButCtrNewAvail = ButCtrNewAvail;
			this.ButCtrDeleteAvail = ButCtrDeleteAvail;
			this.TxfCtrFsrAvail = TxfCtrFsrAvail;
			this.TxfCtrFsrActive = TxfCtrFsrActive;
			this.TxtCtrClrAvail = TxtCtrClrAvail;
			this.TxtCtrClrActive = TxtCtrClrActive;
			this.ButCtrClrViewAvail = ButCtrClrViewAvail;
			this.ButCtrClrViewActive = ButCtrClrViewActive;
			this.SepImbAvail = SepImbAvail;
			this.HdgImbAvail = HdgImbAvail;
			this.ButImbNewAvail = ButImbNewAvail;
			this.ButImbDeleteAvail = ButImbDeleteAvail;
			this.TxfImbFsrAvail = TxfImbFsrAvail;
			this.TxfImbFsrActive = TxfImbFsrActive;
			this.PupImbRtyAvail = PupImbRtyAvail;
			this.PupImbRtyActive = PupImbRtyActive;
			this.TxfImbWidAvail = TxfImbWidAvail;
			this.TxfImbWidActive = TxfImbWidActive;
			this.TxfImbMmxAvail = TxfImbMmxAvail;
			this.TxfImbMmxActive = TxfImbMmxActive;
			this.TxfImbPriAvail = TxfImbPriAvail;
			this.TxfImbPriActive = TxfImbPriActive;

			mask = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPVNDACTIVE, TXFVNDVALID, BUTVNDEDITAVAIL, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXFIMBFSRAVAIL, TXFIMBFSRACTIVE, PUPIMBRTYAVAIL, PUPIMBRTYACTIVE, TXFIMBWIDAVAIL, TXFIMBWIDACTIVE, TXFIMBMMXAVAIL, TXFIMBMMXACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE));
		};

		public boolean ButSaveAvail;
		public boolean ButSaveActive;
		public boolean TxtSrfActive;
		public boolean PupVndActive;
		public boolean TxfVndValid;
		public boolean ButVndEditAvail;
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
		public boolean SepCtrAvail;
		public boolean HdgCtrAvail;
		public boolean ButCtrNewAvail;
		public boolean ButCtrDeleteAvail;
		public boolean TxfCtrFsrAvail;
		public boolean TxfCtrFsrActive;
		public boolean TxtCtrClrAvail;
		public boolean TxtCtrClrActive;
		public boolean ButCtrClrViewAvail;
		public boolean ButCtrClrViewActive;
		public boolean SepImbAvail;
		public boolean HdgImbAvail;
		public boolean ButImbNewAvail;
		public boolean ButImbDeleteAvail;
		public boolean TxfImbFsrAvail;
		public boolean TxfImbFsrActive;
		public boolean PupImbRtyAvail;
		public boolean PupImbRtyActive;
		public boolean TxfImbWidAvail;
		public boolean TxfImbWidActive;
		public boolean TxfImbMmxAvail;
		public boolean TxfImbMmxActive;
		public boolean TxfImbPriAvail;
		public boolean TxfImbPriActive;

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
				PupVndActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupVndActive", mask, PUPVNDACTIVE);
				TxfVndValid = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfVndValid", mask, TXFVNDVALID);
				ButVndEditAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButVndEditAvail", mask, BUTVNDEDITAVAIL);
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
				SepCtrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SepCtrAvail", mask, SEPCTRAVAIL);
				HdgCtrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "HdgCtrAvail", mask, HDGCTRAVAIL);
				ButCtrNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrNewAvail", mask, BUTCTRNEWAVAIL);
				ButCtrDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrDeleteAvail", mask, BUTCTRDELETEAVAIL);
				TxfCtrFsrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCtrFsrAvail", mask, TXFCTRFSRAVAIL);
				TxfCtrFsrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfCtrFsrActive", mask, TXFCTRFSRACTIVE);
				TxtCtrClrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCtrClrAvail", mask, TXTCTRCLRAVAIL);
				TxtCtrClrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxtCtrClrActive", mask, TXTCTRCLRACTIVE);
				ButCtrClrViewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrClrViewAvail", mask, BUTCTRCLRVIEWAVAIL);
				ButCtrClrViewActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButCtrClrViewActive", mask, BUTCTRCLRVIEWACTIVE);
				SepImbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "SepImbAvail", mask, SEPIMBAVAIL);
				HdgImbAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "HdgImbAvail", mask, HDGIMBAVAIL);
				ButImbNewAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImbNewAvail", mask, BUTIMBNEWAVAIL);
				ButImbDeleteAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "ButImbDeleteAvail", mask, BUTIMBDELETEAVAIL);
				TxfImbFsrAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbFsrAvail", mask, TXFIMBFSRAVAIL);
				TxfImbFsrActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbFsrActive", mask, TXFIMBFSRACTIVE);
				PupImbRtyAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupImbRtyAvail", mask, PUPIMBRTYAVAIL);
				PupImbRtyActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "PupImbRtyActive", mask, PUPIMBRTYACTIVE);
				TxfImbWidAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbWidAvail", mask, TXFIMBWIDAVAIL);
				TxfImbWidActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbWidActive", mask, TXFIMBWIDACTIVE);
				TxfImbMmxAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbMmxAvail", mask, TXFIMBMMXAVAIL);
				TxfImbMmxActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbMmxActive", mask, TXFIMBMMXACTIVE);
				TxfImbPriAvail = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbPriAvail", mask, TXFIMBPRIAVAIL);
				TxfImbPriActive = Xmlio.extractBooleanAttrUclc(doc, basexpath, itemtag, "Si", "sref", "TxfImbPriActive", mask, TXFIMBPRIACTIVE);

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
			if (PupVndActive == comp.PupVndActive) items.add(PUPVNDACTIVE);
			if (TxfVndValid == comp.TxfVndValid) items.add(TXFVNDVALID);
			if (ButVndEditAvail == comp.ButVndEditAvail) items.add(BUTVNDEDITAVAIL);
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
			if (SepCtrAvail == comp.SepCtrAvail) items.add(SEPCTRAVAIL);
			if (HdgCtrAvail == comp.HdgCtrAvail) items.add(HDGCTRAVAIL);
			if (ButCtrNewAvail == comp.ButCtrNewAvail) items.add(BUTCTRNEWAVAIL);
			if (ButCtrDeleteAvail == comp.ButCtrDeleteAvail) items.add(BUTCTRDELETEAVAIL);
			if (TxfCtrFsrAvail == comp.TxfCtrFsrAvail) items.add(TXFCTRFSRAVAIL);
			if (TxfCtrFsrActive == comp.TxfCtrFsrActive) items.add(TXFCTRFSRACTIVE);
			if (TxtCtrClrAvail == comp.TxtCtrClrAvail) items.add(TXTCTRCLRAVAIL);
			if (TxtCtrClrActive == comp.TxtCtrClrActive) items.add(TXTCTRCLRACTIVE);
			if (ButCtrClrViewAvail == comp.ButCtrClrViewAvail) items.add(BUTCTRCLRVIEWAVAIL);
			if (ButCtrClrViewActive == comp.ButCtrClrViewActive) items.add(BUTCTRCLRVIEWACTIVE);
			if (SepImbAvail == comp.SepImbAvail) items.add(SEPIMBAVAIL);
			if (HdgImbAvail == comp.HdgImbAvail) items.add(HDGIMBAVAIL);
			if (ButImbNewAvail == comp.ButImbNewAvail) items.add(BUTIMBNEWAVAIL);
			if (ButImbDeleteAvail == comp.ButImbDeleteAvail) items.add(BUTIMBDELETEAVAIL);
			if (TxfImbFsrAvail == comp.TxfImbFsrAvail) items.add(TXFIMBFSRAVAIL);
			if (TxfImbFsrActive == comp.TxfImbFsrActive) items.add(TXFIMBFSRACTIVE);
			if (PupImbRtyAvail == comp.PupImbRtyAvail) items.add(PUPIMBRTYAVAIL);
			if (PupImbRtyActive == comp.PupImbRtyActive) items.add(PUPIMBRTYACTIVE);
			if (TxfImbWidAvail == comp.TxfImbWidAvail) items.add(TXFIMBWIDAVAIL);
			if (TxfImbWidActive == comp.TxfImbWidActive) items.add(TXFIMBWIDACTIVE);
			if (TxfImbMmxAvail == comp.TxfImbMmxAvail) items.add(TXFIMBMMXAVAIL);
			if (TxfImbMmxActive == comp.TxfImbMmxActive) items.add(TXFIMBMMXACTIVE);
			if (TxfImbPriAvail == comp.TxfImbPriAvail) items.add(TXFIMBPRIAVAIL);
			if (TxfImbPriActive == comp.TxfImbPriActive) items.add(TXFIMBPRIACTIVE);

			return(items);
		};

		public HashSet<Integer> diff(
					StatShr comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(BUTSAVEAVAIL, BUTSAVEACTIVE, TXTSRFACTIVE, PUPVNDACTIVE, TXFVNDVALID, BUTVNDEDITAVAIL, PUPTYPACTIVE, TXTHKUACTIVE, BUTHKUVIEWAVAIL, BUTHKUVIEWACTIVE, TXTSUPACTIVE, BUTSUPVIEWAVAIL, BUTSUPVIEWACTIVE, TXTTPLACTIVE, BUTTPLVIEWAVAIL, BUTTPLVIEWACTIVE, TXFSRRACTIVE, TXFCMTACTIVE, SEPCTRAVAIL, HDGCTRAVAIL, BUTCTRNEWAVAIL, BUTCTRDELETEAVAIL, TXFCTRFSRAVAIL, TXFCTRFSRACTIVE, TXTCTRCLRAVAIL, TXTCTRCLRACTIVE, BUTCTRCLRVIEWAVAIL, BUTCTRCLRVIEWACTIVE, SEPIMBAVAIL, HDGIMBAVAIL, BUTIMBNEWAVAIL, BUTIMBDELETEAVAIL, TXFIMBFSRAVAIL, TXFIMBFSRACTIVE, PUPIMBRTYAVAIL, PUPIMBRTYACTIVE, TXFIMBWIDAVAIL, TXFIMBWIDACTIVE, TXFIMBMMXAVAIL, TXFIMBMMXACTIVE, TXFIMBPRIAVAIL, TXFIMBPRIACTIVE));
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
		public static final int CPTVND = 3;
		public static final int CPTTYP = 4;
		public static final int CPTHKU = 5;
		public static final int CPTSUP = 6;
		public static final int CPTTPL = 7;
		public static final int CPTSRR = 8;
		public static final int CPTCMT = 9;
		public static final int HDGCTR = 10;
		public static final int CPTCTRFSR = 11;
		public static final int CPTCTRCLR = 12;
		public static final int HDGIMB = 13;
		public static final int CPTIMBFSR = 14;
		public static final int CPTIMBRTY = 15;
		public static final int CPTIMBWID = 16;
		public static final int CPTIMBMMX = 17;
		public static final int CPTIMBPRI = 18;

		public Tag(
					String Cpt
					, String CptSrf
					, String CptVnd
					, String CptTyp
					, String CptHku
					, String CptSup
					, String CptTpl
					, String CptSrr
					, String CptCmt
					, String HdgCtr
					, String CptCtrFsr
					, String CptCtrClr
					, String HdgImb
					, String CptImbFsr
					, String CptImbRty
					, String CptImbWid
					, String CptImbMmx
					, String CptImbPri
				) {
			this.Cpt = Cpt;
			this.CptSrf = CptSrf;
			this.CptVnd = CptVnd;
			this.CptTyp = CptTyp;
			this.CptHku = CptHku;
			this.CptSup = CptSup;
			this.CptTpl = CptTpl;
			this.CptSrr = CptSrr;
			this.CptCmt = CptCmt;
			this.HdgCtr = HdgCtr;
			this.CptCtrFsr = CptCtrFsr;
			this.CptCtrClr = CptCtrClr;
			this.HdgImb = HdgImb;
			this.CptImbFsr = CptImbFsr;
			this.CptImbRty = CptImbRty;
			this.CptImbWid = CptImbWid;
			this.CptImbMmx = CptImbMmx;
			this.CptImbPri = CptImbPri;

			mask = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTVND, CPTTYP, CPTHKU, CPTSUP, CPTTPL, CPTSRR, CPTCMT, HDGCTR, CPTCTRFSR, CPTCTRCLR, HDGIMB, CPTIMBFSR, CPTIMBRTY, CPTIMBWID, CPTIMBMMX, CPTIMBPRI));
		};

		public String Cpt;
		public String CptSrf;
		public String CptVnd;
		public String CptTyp;
		public String CptHku;
		public String CptSup;
		public String CptTpl;
		public String CptSrr;
		public String CptCmt;
		public String HdgCtr;
		public String CptCtrFsr;
		public String CptCtrClr;
		public String HdgImb;
		public String CptImbFsr;
		public String CptImbRty;
		public String CptImbWid;
		public String CptImbMmx;
		public String CptImbPri;

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
				CptVnd = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptVnd", mask, CPTVND);
				CptTyp = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTyp", mask, CPTTYP);
				CptHku = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptHku", mask, CPTHKU);
				CptSup = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSup", mask, CPTSUP);
				CptTpl = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptTpl", mask, CPTTPL);
				CptSrr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptSrr", mask, CPTSRR);
				CptCmt = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCmt", mask, CPTCMT);
				HdgCtr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgCtr", mask, HDGCTR);
				CptCtrFsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCtrFsr", mask, CPTCTRFSR);
				CptCtrClr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptCtrClr", mask, CPTCTRCLR);
				HdgImb = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "HdgImb", mask, HDGIMB);
				CptImbFsr = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImbFsr", mask, CPTIMBFSR);
				CptImbRty = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImbRty", mask, CPTIMBRTY);
				CptImbWid = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImbWid", mask, CPTIMBWID);
				CptImbMmx = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImbMmx", mask, CPTIMBMMX);
				CptImbPri = Xmlio.extractStringAttrUclc(doc, basexpath, itemtag, "Ti", "sref", "CptImbPri", mask, CPTIMBPRI);

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
			if (CptVnd.equals(comp.CptVnd)) items.add(CPTVND);
			if (CptTyp.equals(comp.CptTyp)) items.add(CPTTYP);
			if (CptHku.equals(comp.CptHku)) items.add(CPTHKU);
			if (CptSup.equals(comp.CptSup)) items.add(CPTSUP);
			if (CptTpl.equals(comp.CptTpl)) items.add(CPTTPL);
			if (CptSrr.equals(comp.CptSrr)) items.add(CPTSRR);
			if (CptCmt.equals(comp.CptCmt)) items.add(CPTCMT);
			if (HdgCtr.equals(comp.HdgCtr)) items.add(HDGCTR);
			if (CptCtrFsr.equals(comp.CptCtrFsr)) items.add(CPTCTRFSR);
			if (CptCtrClr.equals(comp.CptCtrClr)) items.add(CPTCTRCLR);
			if (HdgImb.equals(comp.HdgImb)) items.add(HDGIMB);
			if (CptImbFsr.equals(comp.CptImbFsr)) items.add(CPTIMBFSR);
			if (CptImbRty.equals(comp.CptImbRty)) items.add(CPTIMBRTY);
			if (CptImbWid.equals(comp.CptImbWid)) items.add(CPTIMBWID);
			if (CptImbMmx.equals(comp.CptImbMmx)) items.add(CPTIMBMMX);
			if (CptImbPri.equals(comp.CptImbPri)) items.add(CPTIMBPRI);

			return(items);
		};

		public HashSet<Integer> diff(
					Tag comp
				) {
			HashSet<Integer> commitems;
			HashSet<Integer> diffitems;

			commitems = comm(comp);

			diffitems = new HashSet<Integer>(Arrays.asList(CPT, CPTSRF, CPTVND, CPTTYP, CPTHKU, CPTSUP, CPTTPL, CPTSRR, CPTCMT, HDGCTR, CPTCTRFSR, CPTCTRCLR, HDGIMB, CPTIMBFSR, CPTIMBRTY, CPTIMBWID, CPTIMBMMX, CPTIMBPRI));
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
		public static final int FEEDFPUPIMBRTY = 5;
		public static final int FEEDFPUPTYP = 6;
		public static final int FEEDFPUPVND = 7;
		public static final int STATAPP = 8;
		public static final int STATSHR = 9;
		public static final int TAG = 10;

		public DpchEngData() {
			super(VecWdbeVDpch.DPCHENGWDBEMODDETAILDATA);

			contiac = new ContIac(0, "", 0, 0, "", "", "", "", 0, "", "", "");
			continf = new ContInf("", "", "", "", "");
			feedFPupHkt = new Feed("FeedFPupHkt");
			feedFPupImbRty = new Feed("FeedFPupImbRty");
			feedFPupTyp = new Feed("FeedFPupTyp");
			feedFPupVnd = new Feed("FeedFPupVnd");
			statapp = new StatApp(0, false);
			statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
			tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
		};

		public ContIac contiac;
		public ContInf continf;
		public Feed feedFPupHkt;
		public Feed feedFPupImbRty;
		public Feed feedFPupTyp;
		public Feed feedFPupVnd;
		public StatApp statapp;
		public StatShr statshr;
		public Tag tag;

		public String getSrefsMask() {
			ArrayList<String> ss = new ArrayList<String>();

			if (has(SCRJREF)) ss.add("scrJref");
			if (has(CONTIAC)) ss.add("contiac");
			if (has(CONTINF)) ss.add("continf");
			if (has(FEEDFPUPHKT)) ss.add("feedFPupHkt");
			if (has(FEEDFPUPIMBRTY)) ss.add("feedFPupImbRty");
			if (has(FEEDFPUPTYP)) ss.add("feedFPupTyp");
			if (has(FEEDFPUPVND)) ss.add("feedFPupVnd");
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
				if (feedFPupImbRty.readXML(doc, basexpath, true)) add(FEEDFPUPIMBRTY);
				if (feedFPupTyp.readXML(doc, basexpath, true)) add(FEEDFPUPTYP);
				if (feedFPupVnd.readXML(doc, basexpath, true)) add(FEEDFPUPVND);
				if (statapp.readXML(doc, basexpath, true)) add(STATAPP);
				if (statshr.readXML(doc, basexpath, true)) add(STATSHR);
				if (tag.readXML(doc, basexpath, true)) add(TAG);
			} else {
				scrJref = "";
				contiac = new ContIac(0, "", 0, 0, "", "", "", "", 0, "", "", "");
				continf = new ContInf("", "", "", "", "");
				feedFPupHkt = new Feed("FeedFPupHkt");
				feedFPupImbRty = new Feed("FeedFPupImbRty");
				feedFPupTyp = new Feed("FeedFPupTyp");
				feedFPupVnd = new Feed("FeedFPupVnd");
				statapp = new StatApp(0, false);
				statshr = new StatShr(false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false);
				tag = new Tag("", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "");
			};
		};

	};

};
