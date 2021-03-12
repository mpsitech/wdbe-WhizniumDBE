/**
	* \file DbsWdbe_vecs.cpp
	* C++ wrapper for database DbsWdbe (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class DbsWdbe::VecVCard
 ******************************************************************************/

uint DbsWdbe::VecVCard::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "crdwdbeusg") return CRDWDBEUSG;
	if (s == "crdwdbeusr") return CRDWDBEUSR;
	if (s == "crdwdbeprs") return CRDWDBEPRS;
	if (s == "crdwdbefil") return CRDWDBEFIL;
	if (s == "crdwdbenav") return CRDWDBENAV;
	if (s == "crdwdbemch") return CRDWDBEMCH;
	if (s == "crdwdbelib") return CRDWDBELIB;
	if (s == "crdwdbefam") return CRDWDBEFAM;
	if (s == "crdwdbesil") return CRDWDBESIL;
	if (s == "crdwdbemtp") return CRDWDBEMTP;
	if (s == "crdwdbeprj") return CRDWDBEPRJ;
	if (s == "crdwdbever") return CRDWDBEVER;
	if (s == "crdwdbesys") return CRDWDBESYS;
	if (s == "crdwdbetrg") return CRDWDBETRG;
	if (s == "crdwdbeunt") return CRDWDBEUNT;
	if (s == "crdwdberls") return CRDWDBERLS;
	if (s == "crdwdbecpr") return CRDWDBECPR;
	if (s == "crdwdbecvr") return CRDWDBECVR;
	if (s == "crdwdbemod") return CRDWDBEMOD;
	if (s == "crdwdbevec") return CRDWDBEVEC;
	if (s == "crdwdbevit") return CRDWDBEVIT;
	if (s == "crdwdbecmd") return CRDWDBECMD;
	if (s == "crdwdbeerr") return CRDWDBEERR;
	if (s == "crdwdbepph") return CRDWDBEPPH;
	if (s == "crdwdbebnk") return CRDWDBEBNK;
	if (s == "crdwdbepin") return CRDWDBEPIN;
	if (s == "crdwdbegen") return CRDWDBEGEN;
	if (s == "crdwdbeprt") return CRDWDBEPRT;
	if (s == "crdwdbesig") return CRDWDBESIG;
	if (s == "crdwdbeprc") return CRDWDBEPRC;
	if (s == "crdwdbefst") return CRDWDBEFST;
	if (s == "crdwdbevar") return CRDWDBEVAR;
	if (s == "crdwdbeutl") return CRDWDBEUTL;

	return(0);
};

string DbsWdbe::VecVCard::getSref(
			const uint ix
		) {
	if (ix == CRDWDBEUSG) return("CrdWdbeUsg");
	if (ix == CRDWDBEUSR) return("CrdWdbeUsr");
	if (ix == CRDWDBEPRS) return("CrdWdbePrs");
	if (ix == CRDWDBEFIL) return("CrdWdbeFil");
	if (ix == CRDWDBENAV) return("CrdWdbeNav");
	if (ix == CRDWDBEMCH) return("CrdWdbeMch");
	if (ix == CRDWDBELIB) return("CrdWdbeLib");
	if (ix == CRDWDBEFAM) return("CrdWdbeFam");
	if (ix == CRDWDBESIL) return("CrdWdbeSil");
	if (ix == CRDWDBEMTP) return("CrdWdbeMtp");
	if (ix == CRDWDBEPRJ) return("CrdWdbePrj");
	if (ix == CRDWDBEVER) return("CrdWdbeVer");
	if (ix == CRDWDBESYS) return("CrdWdbeSys");
	if (ix == CRDWDBETRG) return("CrdWdbeTrg");
	if (ix == CRDWDBEUNT) return("CrdWdbeUnt");
	if (ix == CRDWDBERLS) return("CrdWdbeRls");
	if (ix == CRDWDBECPR) return("CrdWdbeCpr");
	if (ix == CRDWDBECVR) return("CrdWdbeCvr");
	if (ix == CRDWDBEMOD) return("CrdWdbeMod");
	if (ix == CRDWDBEVEC) return("CrdWdbeVec");
	if (ix == CRDWDBEVIT) return("CrdWdbeVit");
	if (ix == CRDWDBECMD) return("CrdWdbeCmd");
	if (ix == CRDWDBEERR) return("CrdWdbeErr");
	if (ix == CRDWDBEPPH) return("CrdWdbePph");
	if (ix == CRDWDBEBNK) return("CrdWdbeBnk");
	if (ix == CRDWDBEPIN) return("CrdWdbePin");
	if (ix == CRDWDBEGEN) return("CrdWdbeGen");
	if (ix == CRDWDBEPRT) return("CrdWdbePrt");
	if (ix == CRDWDBESIG) return("CrdWdbeSig");
	if (ix == CRDWDBEPRC) return("CrdWdbePrc");
	if (ix == CRDWDBEFST) return("CrdWdbeFst");
	if (ix == CRDWDBEVAR) return("CrdWdbeVar");
	if (ix == CRDWDBEUTL) return("CrdWdbeUtl");

	return("");
};

string DbsWdbe::VecVCard::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == CRDWDBEUSG) return("user groups");
		if (ix == CRDWDBEUSR) return("users");
		if (ix == CRDWDBEPRS) return("persons");
		if (ix == CRDWDBEFIL) return("files");
		if (ix == CRDWDBEMCH) return("machines");
		if (ix == CRDWDBELIB) return("libraries");
		if (ix == CRDWDBEFAM) return("product families");
		if (ix == CRDWDBESIL) return("silicon devices");
		if (ix == CRDWDBEMTP) return("module templates");
		if (ix == CRDWDBEPRJ) return("projects");
		if (ix == CRDWDBEVER) return("versions");
		if (ix == CRDWDBESYS) return("systems");
		if (ix == CRDWDBETRG) return("targets");
		if (ix == CRDWDBEUNT) return("units");
		if (ix == CRDWDBERLS) return("releases");
		if (ix == CRDWDBECPR) return("core projects");
		if (ix == CRDWDBECVR) return("core versions");
		if (ix == CRDWDBEMOD) return("modules");
		if (ix == CRDWDBEVEC) return("vectors");
		if (ix == CRDWDBEVIT) return("vector items");
		if (ix == CRDWDBECMD) return("commands");
		if (ix == CRDWDBEERR) return("errors");
		if (ix == CRDWDBEPPH) return("peripherals");
		if (ix == CRDWDBEBNK) return("I/O banks");
		if (ix == CRDWDBEPIN) return("pins");
		if (ix == CRDWDBEGEN) return("generics");
		if (ix == CRDWDBEPRT) return("ports");
		if (ix == CRDWDBESIG) return("signals");
		if (ix == CRDWDBEPRC) return("processes");
		if (ix == CRDWDBEFST) return("FSM states");
		if (ix == CRDWDBEVAR) return("variables");
		if (ix == CRDWDBEUTL) return("utilities");
		return(getSref(ix));
	};

	return("");
};

void DbsWdbe::VecVCard::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 33; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DbsWdbe::VecVControl
 ******************************************************************************/

uint DbsWdbe::VecVControl::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "pnlwdbeusglist.tcogrp") return PNLWDBEUSGLIST_TCOGRP;
	if (s == "pnlwdbeusglist.tcoown") return PNLWDBEUSGLIST_TCOOWN;
	if (s == "pnlwdbeusglist.tcosrf") return PNLWDBEUSGLIST_TCOSRF;
	if (s == "pnlwdbeusgaaccess.tcofeg") return PNLWDBEUSGAACCESS_TCOFEG;
	if (s == "pnlwdbeusgaaccess.tcofea") return PNLWDBEUSGAACCESS_TCOFEA;
	if (s == "pnlwdbeusgaaccess.tcoacc") return PNLWDBEUSGAACCESS_TCOACC;
	if (s == "pnlwdbeusgmnuser.tcomref") return PNLWDBEUSGMNUSER_TCOMREF;
	if (s == "pnlwdbeusgmnuser.tcoulv") return PNLWDBEUSGMNUSER_TCOULV;
	if (s == "pnlwdbeusrlist.tcogrp") return PNLWDBEUSRLIST_TCOGRP;
	if (s == "pnlwdbeusrlist.tcoown") return PNLWDBEUSRLIST_TCOOWN;
	if (s == "pnlwdbeusrlist.tcoprs") return PNLWDBEUSRLIST_TCOPRS;
	if (s == "pnlwdbeusrlist.tcosrf") return PNLWDBEUSRLIST_TCOSRF;
	if (s == "pnlwdbeusrlist.tcousg") return PNLWDBEUSRLIST_TCOUSG;
	if (s == "pnlwdbeusrlist.tcoste") return PNLWDBEUSRLIST_TCOSTE;
	if (s == "pnlwdbeusrlist.tcolcl") return PNLWDBEUSRLIST_TCOLCL;
	if (s == "pnlwdbeusrlist.tcoulv") return PNLWDBEUSRLIST_TCOULV;
	if (s == "pnlwdbeusraaccess.tcofeg") return PNLWDBEUSRAACCESS_TCOFEG;
	if (s == "pnlwdbeusraaccess.tcofea") return PNLWDBEUSRAACCESS_TCOFEA;
	if (s == "pnlwdbeusraaccess.tcoacc") return PNLWDBEUSRAACCESS_TCOACC;
	if (s == "pnlwdbeusr1nsession.tcoref") return PNLWDBEUSR1NSESSION_TCOREF;
	if (s == "pnlwdbeusrmnusergroup.tcomref") return PNLWDBEUSRMNUSERGROUP_TCOMREF;
	if (s == "pnlwdbeusrmnusergroup.tcoulv") return PNLWDBEUSRMNUSERGROUP_TCOULV;
	if (s == "pnlwdbeprslist.tcogrp") return PNLWDBEPRSLIST_TCOGRP;
	if (s == "pnlwdbeprslist.tcoown") return PNLWDBEPRSLIST_TCOOWN;
	if (s == "pnlwdbeprslist.tcotit") return PNLWDBEPRSLIST_TCOTIT;
	if (s == "pnlwdbeprslist.tcofnm") return PNLWDBEPRSLIST_TCOFNM;
	if (s == "pnlwdbeprslist.tcolnm") return PNLWDBEPRSLIST_TCOLNM;
	if (s == "pnlwdbeprslist.tcosex") return PNLWDBEPRSLIST_TCOSEX;
	if (s == "pnlwdbeprslist.tcotel") return PNLWDBEPRSLIST_TCOTEL;
	if (s == "pnlwdbeprslist.tcoeml") return PNLWDBEPRSLIST_TCOEML;
	if (s == "pnlwdbeprsadetail.tcotyp") return PNLWDBEPRSADETAIL_TCOTYP;
	if (s == "pnlwdbeprsadetail.tcoval") return PNLWDBEPRSADETAIL_TCOVAL;
	if (s == "pnlwdbeprsmnproject.tcomref") return PNLWDBEPRSMNPROJECT_TCOMREF;
	if (s == "pnlwdbeprsmnproject.tcosta") return PNLWDBEPRSMNPROJECT_TCOSTA;
	if (s == "pnlwdbeprsmnproject.tcosto") return PNLWDBEPRSMNPROJECT_TCOSTO;
	if (s == "pnlwdbeprsmnproject.tcofct") return PNLWDBEPRSMNPROJECT_TCOFCT;
	if (s == "pnlwdbeprsmncoreproject.tcomref") return PNLWDBEPRSMNCOREPROJECT_TCOMREF;
	if (s == "pnlwdbeprsmncoreproject.tcosta") return PNLWDBEPRSMNCOREPROJECT_TCOSTA;
	if (s == "pnlwdbeprsmncoreproject.tcosto") return PNLWDBEPRSMNCOREPROJECT_TCOSTO;
	if (s == "pnlwdbeprsmncoreproject.tcofct") return PNLWDBEPRSMNCOREPROJECT_TCOFCT;
	if (s == "pnlwdbefillist.tcogrp") return PNLWDBEFILLIST_TCOGRP;
	if (s == "pnlwdbefillist.tcoown") return PNLWDBEFILLIST_TCOOWN;
	if (s == "pnlwdbefillist.tcofnm") return PNLWDBEFILLIST_TCOFNM;
	if (s == "pnlwdbefillist.tcoret") return PNLWDBEFILLIST_TCORET;
	if (s == "pnlwdbefillist.tcoreu") return PNLWDBEFILLIST_TCOREU;
	if (s == "pnlwdbefillist.tcocnt") return PNLWDBEFILLIST_TCOCNT;
	if (s == "pnlwdbefillist.tcomim") return PNLWDBEFILLIST_TCOMIM;
	if (s == "pnlwdbefillist.tcosiz") return PNLWDBEFILLIST_TCOSIZ;
	if (s == "pnlwdbemchlist.tcosrf") return PNLWDBEMCHLIST_TCOSRF;
	if (s == "pnlwdbemchlist.tcosup") return PNLWDBEMCHLIST_TCOSUP;
	if (s == "pnlwdbemchamakefile.tcotag") return PNLWDBEMCHAMAKEFILE_TCOTAG;
	if (s == "pnlwdbemchamakefile.tcoval") return PNLWDBEMCHAMAKEFILE_TCOVAL;
	if (s == "pnlwdbemchapar.tcokey") return PNLWDBEMCHAPAR_TCOKEY;
	if (s == "pnlwdbemchapar.tcoval") return PNLWDBEMCHAPAR_TCOVAL;
	if (s == "pnlwdbemch1nrelease.tcoref") return PNLWDBEMCH1NRELEASE_TCOREF;
	if (s == "pnlwdbemchsup1nmachine.tcoref") return PNLWDBEMCHSUP1NMACHINE_TCOREF;
	if (s == "pnlwdbeliblist.tcosrf") return PNLWDBELIBLIST_TCOSRF;
	if (s == "pnlwdbeliblist.tcotit") return PNLWDBELIBLIST_TCOTIT;
	if (s == "pnlwdbeliblist.tcover") return PNLWDBELIBLIST_TCOVER;
	if (s == "pnlwdbelibamakefile.tcomch") return PNLWDBELIBAMAKEFILE_TCOMCH;
	if (s == "pnlwdbelibamakefile.tcotag") return PNLWDBELIBAMAKEFILE_TCOTAG;
	if (s == "pnlwdbelibamakefile.tcoval") return PNLWDBELIBAMAKEFILE_TCOVAL;
	if (s == "pnlwdbelibmnversion.tcomref") return PNLWDBELIBMNVERSION_TCOMREF;
	if (s == "pnlwdbefamlist.tcovnd") return PNLWDBEFAMLIST_TCOVND;
	if (s == "pnlwdbefamlist.tcotit") return PNLWDBEFAMLIST_TCOTIT;
	if (s == "pnlwdbefam1nunit.tcoref") return PNLWDBEFAM1NUNIT_TCOREF;
	if (s == "pnlwdbesillist.tcosrf") return PNLWDBESILLIST_TCOSRF;
	if (s == "pnlwdbesillist.tcotit") return PNLWDBESILLIST_TCOTIT;
	if (s == "pnlwdbesillist.tcofsr") return PNLWDBESILLIST_TCOFSR;
	if (s == "pnlwdbesillist.tcotyp") return PNLWDBESILLIST_TCOTYP;
	if (s == "pnlwdbesillist.tcoret") return PNLWDBESILLIST_TCORET;
	if (s == "pnlwdbesillist.tcoreu") return PNLWDBESILLIST_TCOREU;
	if (s == "pnlwdbesillist.tcosys") return PNLWDBESILLIST_TCOSYS;
	if (s == "pnlwdbesillist.tcomdl") return PNLWDBESILLIST_TCOMDL;
	if (s == "pnlwdbesillist.tcopkg") return PNLWDBESILLIST_TCOPKG;
	if (s == "pnlwdbesillist.tcoesy") return PNLWDBESILLIST_TCOESY;
	if (s == "pnlwdbesillist.tcotch") return PNLWDBESILLIST_TCOTCH;
	if (s == "pnlwdbesil1nperipheral.tcoref") return PNLWDBESIL1NPERIPHERAL_TCOREF;
	if (s == "pnlwdbesilsil1nunit.tcoref") return PNLWDBESILSIL1NUNIT_TCOREF;
	if (s == "pnlwdbesil1nbank.tcoref") return PNLWDBESIL1NBANK_TCOREF;
	if (s == "pnlwdbesilfwd1ncontroller.tcoref") return PNLWDBESILFWD1NCONTROLLER_TCOREF;
	if (s == "pnlwdbesil1ntarget.tcoref") return PNLWDBESIL1NTARGET_TCOREF;
	if (s == "pnlwdbesilref1ncommand.tcoref") return PNLWDBESILREF1NCOMMAND_TCOREF;
	if (s == "pnlwdbesilref1nerror.tcoref") return PNLWDBESILREF1NERROR_TCOREF;
	if (s == "pnlwdbesilhk1nvector.tcoref") return PNLWDBESILHK1NVECTOR_TCOREF;
	if (s == "pnlwdbesilhk1nmodule.tcoref") return PNLWDBESILHK1NMODULE_TCOREF;
	if (s == "pnlwdbemtplist.tcosrf") return PNLWDBEMTPLIST_TCOSRF;
	if (s == "pnlwdbemtplist.tcotyp") return PNLWDBEMTPLIST_TCOTYP;
	if (s == "pnlwdbemtplist.tcosrr") return PNLWDBEMTPLIST_TCOSRR;
	if (s == "pnlwdbemtpkparkey.tcofix") return PNLWDBEMTPKPARKEY_TCOFIX;
	if (s == "pnlwdbemtpkparkey.tcosrf") return PNLWDBEMTPKPARKEY_TCOSRF;
	if (s == "pnlwdbemtpkparkey.tcoavl") return PNLWDBEMTPKPARKEY_TCOAVL;
	if (s == "pnlwdbemtpkparkey.tcoimp") return PNLWDBEMTPKPARKEY_TCOIMP;
	if (s == "pnlwdbemtpkparkey.tcotit") return PNLWDBEMTPKPARKEY_TCOTIT;
	if (s == "pnlwdbemtpkparkey.tcocmt") return PNLWDBEMTPKPARKEY_TCOCMT;
	if (s == "pnlwdbemtpkhdltype.tcofix") return PNLWDBEMTPKHDLTYPE_TCOFIX;
	if (s == "pnlwdbemtpkhdltype.tcosrf") return PNLWDBEMTPKHDLTYPE_TCOSRF;
	if (s == "pnlwdbemtpkhdltype.tcoavl") return PNLWDBEMTPKHDLTYPE_TCOAVL;
	if (s == "pnlwdbemtpkhdltype.tcoimp") return PNLWDBEMTPKHDLTYPE_TCOIMP;
	if (s == "pnlwdbemtpkhdltype.tcotit") return PNLWDBEMTPKHDLTYPE_TCOTIT;
	if (s == "pnlwdbemtpkhdltype.tcocmt") return PNLWDBEMTPKHDLTYPE_TCOCMT;
	if (s == "pnlwdbemtpapar.tcokey") return PNLWDBEMTPAPAR_TCOKEY;
	if (s == "pnlwdbemtpapar.tcoval") return PNLWDBEMTPAPAR_TCOVAL;
	if (s == "pnlwdbemtpmdl1nport.tcoref") return PNLWDBEMTPMDL1NPORT_TCOREF;
	if (s == "pnlwdbemtptpl1nmodule.tcoref") return PNLWDBEMTPTPL1NMODULE_TCOREF;
	if (s == "pnlwdbemtpmdl1ngeneric.tcoref") return PNLWDBEMTPMDL1NGENERIC_TCOREF;
	if (s == "pnlwdbemtpsup1nmodule.tcoref") return PNLWDBEMTPSUP1NMODULE_TCOREF;
	if (s == "pnlwdbemtpref1nfile.tcoref") return PNLWDBEMTPREF1NFILE_TCOREF;
	if (s == "pnlwdbemtpmge1nsignal.tcoref") return PNLWDBEMTPMGE1NSIGNAL_TCOREF;
	if (s == "pnlwdbeprjlist.tcogrp") return PNLWDBEPRJLIST_TCOGRP;
	if (s == "pnlwdbeprjlist.tcoown") return PNLWDBEPRJLIST_TCOOWN;
	if (s == "pnlwdbeprjlist.tcosho") return PNLWDBEPRJLIST_TCOSHO;
	if (s == "pnlwdbeprjlist.tcotit") return PNLWDBEPRJLIST_TCOTIT;
	if (s == "pnlwdbeprjlist.tcover") return PNLWDBEPRJLIST_TCOVER;
	if (s == "pnlwdbeprjlist.tcoesy") return PNLWDBEPRJLIST_TCOESY;
	if (s == "pnlwdbeprjlist.tcogrl") return PNLWDBEPRJLIST_TCOGRL;
	if (s == "pnlwdbeprjprj1nversion.tcoref") return PNLWDBEPRJPRJ1NVERSION_TCOREF;
	if (s == "pnlwdbeprjmnperson.tcomref") return PNLWDBEPRJMNPERSON_TCOMREF;
	if (s == "pnlwdbeprjmnperson.tcosta") return PNLWDBEPRJMNPERSON_TCOSTA;
	if (s == "pnlwdbeprjmnperson.tcosto") return PNLWDBEPRJMNPERSON_TCOSTO;
	if (s == "pnlwdbeprjmnperson.tcofct") return PNLWDBEPRJMNPERSON_TCOFCT;
	if (s == "pnlwdbeverlist.tcogrp") return PNLWDBEVERLIST_TCOGRP;
	if (s == "pnlwdbeverlist.tcoown") return PNLWDBEVERLIST_TCOOWN;
	if (s == "pnlwdbeverlist.tcoprj") return PNLWDBEVERLIST_TCOPRJ;
	if (s == "pnlwdbeverlist.tcomaj") return PNLWDBEVERLIST_TCOMAJ;
	if (s == "pnlwdbeverlist.tcomin") return PNLWDBEVERLIST_TCOMIN;
	if (s == "pnlwdbeverlist.tcosub") return PNLWDBEVERLIST_TCOSUB;
	if (s == "pnlwdbeverlist.tcobvr") return PNLWDBEVERLIST_TCOBVR;
	if (s == "pnlwdbeverlist.tcoste") return PNLWDBEVERLIST_TCOSTE;
	if (s == "pnlwdbeverbvr1nversion.tcoref") return PNLWDBEVERBVR1NVERSION_TCOREF;
	if (s == "pnlwdbever1nsystem.tcoref") return PNLWDBEVER1NSYSTEM_TCOREF;
	if (s == "pnlwdbever1nrelease.tcoref") return PNLWDBEVER1NRELEASE_TCOREF;
	if (s == "pnlwdbever1nunit.tcoref") return PNLWDBEVER1NUNIT_TCOREF;
	if (s == "pnlwdbeverref1nfile.tcoref") return PNLWDBEVERREF1NFILE_TCOREF;
	if (s == "pnlwdbevermnlibrary.tcomref") return PNLWDBEVERMNLIBRARY_TCOMREF;
	if (s == "pnlwdbesyslist.tcosrf") return PNLWDBESYSLIST_TCOSRF;
	if (s == "pnlwdbesyslist.tcover") return PNLWDBESYSLIST_TCOVER;
	if (s == "pnlwdbesyslist.tcount") return PNLWDBESYSLIST_TCOUNT;
	if (s == "pnlwdbesyssys1ntarget.tcoref") return PNLWDBESYSSYS1NTARGET_TCOREF;
	if (s == "pnlwdbesyshk1nvector.tcoref") return PNLWDBESYSHK1NVECTOR_TCOREF;
	if (s == "pnlwdbetrglist.tcosrf") return PNLWDBETRGLIST_TCOSRF;
	if (s == "pnlwdbetrglist.tcosys") return PNLWDBETRGLIST_TCOSYS;
	if (s == "pnlwdbetrglist.tcount") return PNLWDBETRGLIST_TCOUNT;
	if (s == "pnlwdbeuntlist.tcosrf") return PNLWDBEUNTLIST_TCOSRF;
	if (s == "pnlwdbeuntlist.tcotit") return PNLWDBEUNTLIST_TCOTIT;
	if (s == "pnlwdbeuntlist.tcofsr") return PNLWDBEUNTLIST_TCOFSR;
	if (s == "pnlwdbeuntlist.tcotyp") return PNLWDBEUNTLIST_TCOTYP;
	if (s == "pnlwdbeuntlist.tcoret") return PNLWDBEUNTLIST_TCORET;
	if (s == "pnlwdbeuntlist.tcoreu") return PNLWDBEUNTLIST_TCOREU;
	if (s == "pnlwdbeuntlist.tcosys") return PNLWDBEUNTLIST_TCOSYS;
	if (s == "pnlwdbeuntlist.tcomdl") return PNLWDBEUNTLIST_TCOMDL;
	if (s == "pnlwdbeuntlist.tcopkg") return PNLWDBEUNTLIST_TCOPKG;
	if (s == "pnlwdbeuntlist.tcoesy") return PNLWDBEUNTLIST_TCOESY;
	if (s == "pnlwdbeuntlist.tcotch") return PNLWDBEUNTLIST_TCOTCH;
	if (s == "pnlwdbeunt1nperipheral.tcoref") return PNLWDBEUNT1NPERIPHERAL_TCOREF;
	if (s == "pnlwdbeuntsil1nunit.tcoref") return PNLWDBEUNTSIL1NUNIT_TCOREF;
	if (s == "pnlwdbeunt1nbank.tcoref") return PNLWDBEUNT1NBANK_TCOREF;
	if (s == "pnlwdbeuntfwd1ncontroller.tcoref") return PNLWDBEUNTFWD1NCONTROLLER_TCOREF;
	if (s == "pnlwdbeunt1ntarget.tcoref") return PNLWDBEUNT1NTARGET_TCOREF;
	if (s == "pnlwdbeuntref1ncommand.tcoref") return PNLWDBEUNTREF1NCOMMAND_TCOREF;
	if (s == "pnlwdbeuntref1nerror.tcoref") return PNLWDBEUNTREF1NERROR_TCOREF;
	if (s == "pnlwdbeunthk1nvector.tcoref") return PNLWDBEUNTHK1NVECTOR_TCOREF;
	if (s == "pnlwdbeunthk1nmodule.tcoref") return PNLWDBEUNTHK1NMODULE_TCOREF;
	if (s == "pnlwdberlslist.tcosrf") return PNLWDBERLSLIST_TCOSRF;
	if (s == "pnlwdberlslist.tcotyp") return PNLWDBERLSLIST_TCOTYP;
	if (s == "pnlwdberlslist.tcover") return PNLWDBERLSLIST_TCOVER;
	if (s == "pnlwdberlslist.tcomch") return PNLWDBERLSLIST_TCOMCH;
	if (s == "pnlwdbecprlist.tcogrp") return PNLWDBECPRLIST_TCOGRP;
	if (s == "pnlwdbecprlist.tcoown") return PNLWDBECPRLIST_TCOOWN;
	if (s == "pnlwdbecprlist.tcosrf") return PNLWDBECPRLIST_TCOSRF;
	if (s == "pnlwdbecprlist.tcotit") return PNLWDBECPRLIST_TCOTIT;
	if (s == "pnlwdbecprlist.tcotyp") return PNLWDBECPRLIST_TCOTYP;
	if (s == "pnlwdbecprlist.tcocvr") return PNLWDBECPRLIST_TCOCVR;
	if (s == "pnlwdbecprlist.tcogrl") return PNLWDBECPRLIST_TCOGRL;
	if (s == "pnlwdbecpr1ncoreversion.tcoref") return PNLWDBECPR1NCOREVERSION_TCOREF;
	if (s == "pnlwdbecprmnperson.tcomref") return PNLWDBECPRMNPERSON_TCOMREF;
	if (s == "pnlwdbecprmnperson.tcosta") return PNLWDBECPRMNPERSON_TCOSTA;
	if (s == "pnlwdbecprmnperson.tcosto") return PNLWDBECPRMNPERSON_TCOSTO;
	if (s == "pnlwdbecprmnperson.tcofct") return PNLWDBECPRMNPERSON_TCOFCT;
	if (s == "pnlwdbecvrlist.tcogrp") return PNLWDBECVRLIST_TCOGRP;
	if (s == "pnlwdbecvrlist.tcoown") return PNLWDBECVRLIST_TCOOWN;
	if (s == "pnlwdbecvrlist.tcocpr") return PNLWDBECVRLIST_TCOCPR;
	if (s == "pnlwdbecvrlist.tcomaj") return PNLWDBECVRLIST_TCOMAJ;
	if (s == "pnlwdbecvrlist.tcomin") return PNLWDBECVRLIST_TCOMIN;
	if (s == "pnlwdbecvrlist.tcosub") return PNLWDBECVRLIST_TCOSUB;
	if (s == "pnlwdbecvrlist.tcobcv") return PNLWDBECVRLIST_TCOBCV;
	if (s == "pnlwdbecvrlist.tcoste") return PNLWDBECVRLIST_TCOSTE;
	if (s == "pnlwdbecvraplh.tcosrf") return PNLWDBECVRAPLH_TCOSRF;
	if (s == "pnlwdbecvraplh.tcocmt") return PNLWDBECVRAPLH_TCOCMT;
	if (s == "pnlwdbecvraip.tcosrf") return PNLWDBECVRAIP_TCOSRF;
	if (s == "pnlwdbecvraip.tcotty") return PNLWDBECVRAIP_TCOTTY;
	if (s == "pnlwdbecvraip.tcocmt") return PNLWDBECVRAIP_TCOCMT;
	if (s == "pnlwdbecvrbcv1ncoreversion.tcoref") return PNLWDBECVRBCV1NCOREVERSION_TCOREF;
	if (s == "pnlwdbecvrhk1nmodule.tcoref") return PNLWDBECVRHK1NMODULE_TCOREF;
	if (s == "pnlwdbemodlist.tcosrf") return PNLWDBEMODLIST_TCOSRF;
	if (s == "pnlwdbemodlist.tcotyp") return PNLWDBEMODLIST_TCOTYP;
	if (s == "pnlwdbemodlist.tcohkt") return PNLWDBEMODLIST_TCOHKT;
	if (s == "pnlwdbemodlist.tcohku") return PNLWDBEMODLIST_TCOHKU;
	if (s == "pnlwdbemodlist.tcosup") return PNLWDBEMODLIST_TCOSUP;
	if (s == "pnlwdbemodlist.tcotpl") return PNLWDBEMODLIST_TCOTPL;
	if (s == "pnlwdbemodkhdltype.tcofix") return PNLWDBEMODKHDLTYPE_TCOFIX;
	if (s == "pnlwdbemodkhdltype.tcosrf") return PNLWDBEMODKHDLTYPE_TCOSRF;
	if (s == "pnlwdbemodkhdltype.tcoavl") return PNLWDBEMODKHDLTYPE_TCOAVL;
	if (s == "pnlwdbemodkhdltype.tcoimp") return PNLWDBEMODKHDLTYPE_TCOIMP;
	if (s == "pnlwdbemodkhdltype.tcotit") return PNLWDBEMODKHDLTYPE_TCOTIT;
	if (s == "pnlwdbemodkhdltype.tcocmt") return PNLWDBEMODKHDLTYPE_TCOCMT;
	if (s == "pnlwdbemodapar.tcokey") return PNLWDBEMODAPAR_TCOKEY;
	if (s == "pnlwdbemodapar.tcoval") return PNLWDBEMODAPAR_TCOVAL;
	if (s == "pnlwdbemod1nperipheral.tcoref") return PNLWDBEMOD1NPERIPHERAL_TCOREF;
	if (s == "pnlwdbemodmdl1nsignal.tcoref") return PNLWDBEMODMDL1NSIGNAL_TCOREF;
	if (s == "pnlwdbemod1nprocess.tcoref") return PNLWDBEMOD1NPROCESS_TCOREF;
	if (s == "pnlwdbemodmdl1nport.tcoref") return PNLWDBEMODMDL1NPORT_TCOREF;
	if (s == "pnlwdbemodcor1nimbuf.tcoref") return PNLWDBEMODCOR1NIMBUF_TCOREF;
	if (s == "pnlwdbemodmdl1ngeneric.tcoref") return PNLWDBEMODMDL1NGENERIC_TCOREF;
	if (s == "pnlwdbemodsup1nmodule.tcoref") return PNLWDBEMODSUP1NMODULE_TCOREF;
	if (s == "pnlwdbemodmge1nsignal.tcoref") return PNLWDBEMODMGE1NSIGNAL_TCOREF;
	if (s == "pnlwdbemodctrref1ncommand.tcoref") return PNLWDBEMODCTRREF1NCOMMAND_TCOREF;
	if (s == "pnlwdbemodctrref1nerror.tcoref") return PNLWDBEMODCTRREF1NERROR_TCOREF;
	if (s == "pnlwdbemodctrhk1nvector.tcoref") return PNLWDBEMODCTRHK1NVECTOR_TCOREF;
	if (s == "pnlwdbemodctrmncommand.tcomref") return PNLWDBEMODCTRMNCOMMAND_TCOMREF;
	if (s == "pnlwdbemodctrmncommand.tcoivr") return PNLWDBEMODCTRMNCOMMAND_TCOIVR;
	if (s == "pnlwdbemodctrmncommand.tcorvr") return PNLWDBEMODCTRMNCOMMAND_TCORVR;
	if (s == "pnlwdbeveclist.tcosrf") return PNLWDBEVECLIST_TCOSRF;
	if (s == "pnlwdbeveclist.tcotyp") return PNLWDBEVECLIST_TCOTYP;
	if (s == "pnlwdbeveclist.tcohkt") return PNLWDBEVECLIST_TCOHKT;
	if (s == "pnlwdbeveclist.tcohku") return PNLWDBEVECLIST_TCOHKU;
	if (s == "pnlwdbevecvec1nvectoritem.tcoref") return PNLWDBEVECVEC1NVECTORITEM_TCOREF;
	if (s == "pnlwdbevitlist.tcosrf") return PNLWDBEVITLIST_TCOSRF;
	if (s == "pnlwdbevitlist.tcotit") return PNLWDBEVITLIST_TCOTIT;
	if (s == "pnlwdbevitlist.tcovec") return PNLWDBEVITLIST_TCOVEC;
	if (s == "pnlwdbecmdlist.tcosrf") return PNLWDBECMDLIST_TCOSRF;
	if (s == "pnlwdbecmdlist.tcofsr") return PNLWDBECMDLIST_TCOFSR;
	if (s == "pnlwdbecmdlist.tcoret") return PNLWDBECMDLIST_TCORET;
	if (s == "pnlwdbecmdlist.tcoreu") return PNLWDBECMDLIST_TCOREU;
	if (s == "pnlwdbecmdlist.tcorty") return PNLWDBECMDLIST_TCORTY;
	if (s == "pnlwdbecmdaretpar.tcosrf") return PNLWDBECMDARETPAR_TCOSRF;
	if (s == "pnlwdbecmdaretpar.tcopty") return PNLWDBECMDARETPAR_TCOPTY;
	if (s == "pnlwdbecmdaretpar.tcovec") return PNLWDBECMDARETPAR_TCOVEC;
	if (s == "pnlwdbecmdaretpar.tcolen") return PNLWDBECMDARETPAR_TCOLEN;
	if (s == "pnlwdbecmdaretpar.tcocmt") return PNLWDBECMDARETPAR_TCOCMT;
	if (s == "pnlwdbecmdainvpar.tcosrf") return PNLWDBECMDAINVPAR_TCOSRF;
	if (s == "pnlwdbecmdainvpar.tcopty") return PNLWDBECMDAINVPAR_TCOPTY;
	if (s == "pnlwdbecmdainvpar.tcovec") return PNLWDBECMDAINVPAR_TCOVEC;
	if (s == "pnlwdbecmdainvpar.tcolen") return PNLWDBECMDAINVPAR_TCOLEN;
	if (s == "pnlwdbecmdainvpar.tcodfv") return PNLWDBECMDAINVPAR_TCODFV;
	if (s == "pnlwdbecmdainvpar.tcovit") return PNLWDBECMDAINVPAR_TCOVIT;
	if (s == "pnlwdbecmdainvpar.tcocmt") return PNLWDBECMDAINVPAR_TCOCMT;
	if (s == "pnlwdbecmdmncontroller.tcomref") return PNLWDBECMDMNCONTROLLER_TCOMREF;
	if (s == "pnlwdbecmdmncontroller.tcoivr") return PNLWDBECMDMNCONTROLLER_TCOIVR;
	if (s == "pnlwdbecmdmncontroller.tcorvr") return PNLWDBECMDMNCONTROLLER_TCORVR;
	if (s == "pnlwdbeerrlist.tcosrf") return PNLWDBEERRLIST_TCOSRF;
	if (s == "pnlwdbeerrlist.tcofsr") return PNLWDBEERRLIST_TCOFSR;
	if (s == "pnlwdbeerrlist.tcoret") return PNLWDBEERRLIST_TCORET;
	if (s == "pnlwdbeerrlist.tcoreu") return PNLWDBEERRLIST_TCOREU;
	if (s == "pnlwdbeerrapar.tcosrf") return PNLWDBEERRAPAR_TCOSRF;
	if (s == "pnlwdbeerrapar.tcopty") return PNLWDBEERRAPAR_TCOPTY;
	if (s == "pnlwdbeerrapar.tcovec") return PNLWDBEERRAPAR_TCOVEC;
	if (s == "pnlwdbeerrapar.tcolen") return PNLWDBEERRAPAR_TCOLEN;
	if (s == "pnlwdbeerrapar.tcocmt") return PNLWDBEERRAPAR_TCOCMT;
	if (s == "pnlwdbepphlist.tcosrf") return PNLWDBEPPHLIST_TCOSRF;
	if (s == "pnlwdbepphlist.tcount") return PNLWDBEPPHLIST_TCOUNT;
	if (s == "pnlwdbepphlist.tcomdl") return PNLWDBEPPHLIST_TCOMDL;
	if (s == "pnlwdbepphapar.tcokey") return PNLWDBEPPHAPAR_TCOKEY;
	if (s == "pnlwdbepphapar.tcoval") return PNLWDBEPPHAPAR_TCOVAL;
	if (s == "pnlwdbebnklist.tcosrf") return PNLWDBEBNKLIST_TCOSRF;
	if (s == "pnlwdbebnklist.tcount") return PNLWDBEBNKLIST_TCOUNT;
	if (s == "pnlwdbebnklist.tcovst") return PNLWDBEBNKLIST_TCOVST;
	if (s == "pnlwdbebnk1npin.tcoref") return PNLWDBEBNK1NPIN_TCOREF;
	if (s == "pnlwdbepinlist.tcosrf") return PNLWDBEPINLIST_TCOSRF;
	if (s == "pnlwdbepinlist.tcobnk") return PNLWDBEPINLIST_TCOBNK;
	if (s == "pnlwdbepinlist.tcoloc") return PNLWDBEPINLIST_TCOLOC;
	if (s == "pnlwdbepinapar.tcokey") return PNLWDBEPINAPAR_TCOKEY;
	if (s == "pnlwdbepinapar.tcoval") return PNLWDBEPINAPAR_TCOVAL;
	if (s == "pnlwdbegenlist.tcosrf") return PNLWDBEGENLIST_TCOSRF;
	if (s == "pnlwdbegenlist.tcomdl") return PNLWDBEGENLIST_TCOMDL;
	if (s == "pnlwdbegenlist.tcohty") return PNLWDBEGENLIST_TCOHTY;
	if (s == "pnlwdbegenlist.tcowid") return PNLWDBEGENLIST_TCOWID;
	if (s == "pnlwdbegenlist.tcommx") return PNLWDBEGENLIST_TCOMMX;
	if (s == "pnlwdbeprtlist.tcosrf") return PNLWDBEPRTLIST_TCOSRF;
	if (s == "pnlwdbeprtlist.tcomdl") return PNLWDBEPRTLIST_TCOMDL;
	if (s == "pnlwdbeprtlist.tcomdc") return PNLWDBEPRTLIST_TCOMDC;
	if (s == "pnlwdbeprtlist.tcodir") return PNLWDBEPRTLIST_TCODIR;
	if (s == "pnlwdbeprtlist.tcohty") return PNLWDBEPRTLIST_TCOHTY;
	if (s == "pnlwdbeprtlist.tcowid") return PNLWDBEPRTLIST_TCOWID;
	if (s == "pnlwdbeprtlist.tcommx") return PNLWDBEPRTLIST_TCOMMX;
	if (s == "pnlwdbesiglist.tcosrf") return PNLWDBESIGLIST_TCOSRF;
	if (s == "pnlwdbesiglist.tcotyp") return PNLWDBESIGLIST_TCOTYP;
	if (s == "pnlwdbesiglist.tcomdl") return PNLWDBESIGLIST_TCOMDL;
	if (s == "pnlwdbesiglist.tcomgt") return PNLWDBESIGLIST_TCOMGT;
	if (s == "pnlwdbesiglist.tcomgu") return PNLWDBESIGLIST_TCOMGU;
	if (s == "pnlwdbesiglist.tcovec") return PNLWDBESIGLIST_TCOVEC;
	if (s == "pnlwdbesiglist.tcocon") return PNLWDBESIGLIST_TCOCON;
	if (s == "pnlwdbesiglist.tcohty") return PNLWDBESIGLIST_TCOHTY;
	if (s == "pnlwdbesiglist.tcowid") return PNLWDBESIGLIST_TCOWID;
	if (s == "pnlwdbesiglist.tcommx") return PNLWDBESIGLIST_TCOMMX;
	if (s == "pnlwdbeprclist.tcosrf") return PNLWDBEPRCLIST_TCOSRF;
	if (s == "pnlwdbeprclist.tcomdl") return PNLWDBEPRCLIST_TCOMDL;
	if (s == "pnlwdbeprclist.tcofal") return PNLWDBEPRCLIST_TCOFAL;
	if (s == "pnlwdbeprckhdltype.tcofix") return PNLWDBEPRCKHDLTYPE_TCOFIX;
	if (s == "pnlwdbeprckhdltype.tcosrf") return PNLWDBEPRCKHDLTYPE_TCOSRF;
	if (s == "pnlwdbeprckhdltype.tcoavl") return PNLWDBEPRCKHDLTYPE_TCOAVL;
	if (s == "pnlwdbeprckhdltype.tcoimp") return PNLWDBEPRCKHDLTYPE_TCOIMP;
	if (s == "pnlwdbeprckhdltype.tcotit") return PNLWDBEPRCKHDLTYPE_TCOTIT;
	if (s == "pnlwdbeprckhdltype.tcocmt") return PNLWDBEPRCKHDLTYPE_TCOCMT;
	if (s == "pnlwdbeprcprc1nvariable.tcoref") return PNLWDBEPRCPRC1NVARIABLE_TCOREF;
	if (s == "pnlwdbeprcmge1nsignal.tcoref") return PNLWDBEPRCMGE1NSIGNAL_TCOREF;
	if (s == "pnlwdbeprcfsmfsm1nfsmstate.tcoref") return PNLWDBEPRCFSMFSM1NFSMSTATE_TCOREF;
	if (s == "pnlwdbefstlist.tcosrf") return PNLWDBEFSTLIST_TCOSRF;
	if (s == "pnlwdbefstlist.tcofsm") return PNLWDBEFSTLIST_TCOFSM;
	if (s == "pnlwdbefstastep.tcofnx") return PNLWDBEFSTASTEP_TCOFNX;
	if (s == "pnlwdbefstastep.tcocn1") return PNLWDBEFSTASTEP_TCOCN1;
	if (s == "pnlwdbefstastep.tcoip1") return PNLWDBEFSTASTEP_TCOIP1;
	if (s == "pnlwdbefstastep.tcocn2") return PNLWDBEFSTASTEP_TCOCN2;
	if (s == "pnlwdbefstastep.tcoip2") return PNLWDBEFSTASTEP_TCOIP2;
	if (s == "pnlwdbefstastep.tcocn3") return PNLWDBEFSTASTEP_TCOCN3;
	if (s == "pnlwdbefstastep.tcoip3") return PNLWDBEFSTASTEP_TCOIP3;
	if (s == "pnlwdbefstastep.tcocn4") return PNLWDBEFSTASTEP_TCOCN4;
	if (s == "pnlwdbefstastep.tcoip4") return PNLWDBEFSTASTEP_TCOIP4;
	if (s == "pnlwdbevarlist.tcosrf") return PNLWDBEVARLIST_TCOSRF;
	if (s == "pnlwdbevarlist.tcoprc") return PNLWDBEVARLIST_TCOPRC;
	if (s == "pnlwdbevarlist.tcocon") return PNLWDBEVARLIST_TCOCON;
	if (s == "pnlwdbevarlist.tcofal") return PNLWDBEVARLIST_TCOFAL;
	if (s == "pnlwdbevarlist.tcohty") return PNLWDBEVARLIST_TCOHTY;
	if (s == "pnlwdbevarlist.tcowid") return PNLWDBEVARLIST_TCOWID;
	if (s == "pnlwdbevarlist.tcommx") return PNLWDBEVARLIST_TCOMMX;

	return(0);
};

string DbsWdbe::VecVControl::getSref(
			const uint ix
		) {
	if (ix == PNLWDBEUSGLIST_TCOGRP) return("PnlWdbeUsgList.TcoGrp");
	if (ix == PNLWDBEUSGLIST_TCOOWN) return("PnlWdbeUsgList.TcoOwn");
	if (ix == PNLWDBEUSGLIST_TCOSRF) return("PnlWdbeUsgList.TcoSrf");
	if (ix == PNLWDBEUSGAACCESS_TCOFEG) return("PnlWdbeUsgAAccess.TcoFeg");
	if (ix == PNLWDBEUSGAACCESS_TCOFEA) return("PnlWdbeUsgAAccess.TcoFea");
	if (ix == PNLWDBEUSGAACCESS_TCOACC) return("PnlWdbeUsgAAccess.TcoAcc");
	if (ix == PNLWDBEUSGMNUSER_TCOMREF) return("PnlWdbeUsgMNUser.TcoMref");
	if (ix == PNLWDBEUSGMNUSER_TCOULV) return("PnlWdbeUsgMNUser.TcoUlv");
	if (ix == PNLWDBEUSRLIST_TCOGRP) return("PnlWdbeUsrList.TcoGrp");
	if (ix == PNLWDBEUSRLIST_TCOOWN) return("PnlWdbeUsrList.TcoOwn");
	if (ix == PNLWDBEUSRLIST_TCOPRS) return("PnlWdbeUsrList.TcoPrs");
	if (ix == PNLWDBEUSRLIST_TCOSRF) return("PnlWdbeUsrList.TcoSrf");
	if (ix == PNLWDBEUSRLIST_TCOUSG) return("PnlWdbeUsrList.TcoUsg");
	if (ix == PNLWDBEUSRLIST_TCOSTE) return("PnlWdbeUsrList.TcoSte");
	if (ix == PNLWDBEUSRLIST_TCOLCL) return("PnlWdbeUsrList.TcoLcl");
	if (ix == PNLWDBEUSRLIST_TCOULV) return("PnlWdbeUsrList.TcoUlv");
	if (ix == PNLWDBEUSRAACCESS_TCOFEG) return("PnlWdbeUsrAAccess.TcoFeg");
	if (ix == PNLWDBEUSRAACCESS_TCOFEA) return("PnlWdbeUsrAAccess.TcoFea");
	if (ix == PNLWDBEUSRAACCESS_TCOACC) return("PnlWdbeUsrAAccess.TcoAcc");
	if (ix == PNLWDBEUSR1NSESSION_TCOREF) return("PnlWdbeUsr1NSession.TcoRef");
	if (ix == PNLWDBEUSRMNUSERGROUP_TCOMREF) return("PnlWdbeUsrMNUsergroup.TcoMref");
	if (ix == PNLWDBEUSRMNUSERGROUP_TCOULV) return("PnlWdbeUsrMNUsergroup.TcoUlv");
	if (ix == PNLWDBEPRSLIST_TCOGRP) return("PnlWdbePrsList.TcoGrp");
	if (ix == PNLWDBEPRSLIST_TCOOWN) return("PnlWdbePrsList.TcoOwn");
	if (ix == PNLWDBEPRSLIST_TCOTIT) return("PnlWdbePrsList.TcoTit");
	if (ix == PNLWDBEPRSLIST_TCOFNM) return("PnlWdbePrsList.TcoFnm");
	if (ix == PNLWDBEPRSLIST_TCOLNM) return("PnlWdbePrsList.TcoLnm");
	if (ix == PNLWDBEPRSLIST_TCOSEX) return("PnlWdbePrsList.TcoSex");
	if (ix == PNLWDBEPRSLIST_TCOTEL) return("PnlWdbePrsList.TcoTel");
	if (ix == PNLWDBEPRSLIST_TCOEML) return("PnlWdbePrsList.TcoEml");
	if (ix == PNLWDBEPRSADETAIL_TCOTYP) return("PnlWdbePrsADetail.TcoTyp");
	if (ix == PNLWDBEPRSADETAIL_TCOVAL) return("PnlWdbePrsADetail.TcoVal");
	if (ix == PNLWDBEPRSMNPROJECT_TCOMREF) return("PnlWdbePrsMNProject.TcoMref");
	if (ix == PNLWDBEPRSMNPROJECT_TCOSTA) return("PnlWdbePrsMNProject.TcoSta");
	if (ix == PNLWDBEPRSMNPROJECT_TCOSTO) return("PnlWdbePrsMNProject.TcoSto");
	if (ix == PNLWDBEPRSMNPROJECT_TCOFCT) return("PnlWdbePrsMNProject.TcoFct");
	if (ix == PNLWDBEPRSMNCOREPROJECT_TCOMREF) return("PnlWdbePrsMNCoreproject.TcoMref");
	if (ix == PNLWDBEPRSMNCOREPROJECT_TCOSTA) return("PnlWdbePrsMNCoreproject.TcoSta");
	if (ix == PNLWDBEPRSMNCOREPROJECT_TCOSTO) return("PnlWdbePrsMNCoreproject.TcoSto");
	if (ix == PNLWDBEPRSMNCOREPROJECT_TCOFCT) return("PnlWdbePrsMNCoreproject.TcoFct");
	if (ix == PNLWDBEFILLIST_TCOGRP) return("PnlWdbeFilList.TcoGrp");
	if (ix == PNLWDBEFILLIST_TCOOWN) return("PnlWdbeFilList.TcoOwn");
	if (ix == PNLWDBEFILLIST_TCOFNM) return("PnlWdbeFilList.TcoFnm");
	if (ix == PNLWDBEFILLIST_TCORET) return("PnlWdbeFilList.TcoRet");
	if (ix == PNLWDBEFILLIST_TCOREU) return("PnlWdbeFilList.TcoReu");
	if (ix == PNLWDBEFILLIST_TCOCNT) return("PnlWdbeFilList.TcoCnt");
	if (ix == PNLWDBEFILLIST_TCOMIM) return("PnlWdbeFilList.TcoMim");
	if (ix == PNLWDBEFILLIST_TCOSIZ) return("PnlWdbeFilList.TcoSiz");
	if (ix == PNLWDBEMCHLIST_TCOSRF) return("PnlWdbeMchList.TcoSrf");
	if (ix == PNLWDBEMCHLIST_TCOSUP) return("PnlWdbeMchList.TcoSup");
	if (ix == PNLWDBEMCHAMAKEFILE_TCOTAG) return("PnlWdbeMchAMakefile.TcoTag");
	if (ix == PNLWDBEMCHAMAKEFILE_TCOVAL) return("PnlWdbeMchAMakefile.TcoVal");
	if (ix == PNLWDBEMCHAPAR_TCOKEY) return("PnlWdbeMchAPar.TcoKey");
	if (ix == PNLWDBEMCHAPAR_TCOVAL) return("PnlWdbeMchAPar.TcoVal");
	if (ix == PNLWDBEMCH1NRELEASE_TCOREF) return("PnlWdbeMch1NRelease.TcoRef");
	if (ix == PNLWDBEMCHSUP1NMACHINE_TCOREF) return("PnlWdbeMchSup1NMachine.TcoRef");
	if (ix == PNLWDBELIBLIST_TCOSRF) return("PnlWdbeLibList.TcoSrf");
	if (ix == PNLWDBELIBLIST_TCOTIT) return("PnlWdbeLibList.TcoTit");
	if (ix == PNLWDBELIBLIST_TCOVER) return("PnlWdbeLibList.TcoVer");
	if (ix == PNLWDBELIBAMAKEFILE_TCOMCH) return("PnlWdbeLibAMakefile.TcoMch");
	if (ix == PNLWDBELIBAMAKEFILE_TCOTAG) return("PnlWdbeLibAMakefile.TcoTag");
	if (ix == PNLWDBELIBAMAKEFILE_TCOVAL) return("PnlWdbeLibAMakefile.TcoVal");
	if (ix == PNLWDBELIBMNVERSION_TCOMREF) return("PnlWdbeLibMNVersion.TcoMref");
	if (ix == PNLWDBEFAMLIST_TCOVND) return("PnlWdbeFamList.TcoVnd");
	if (ix == PNLWDBEFAMLIST_TCOTIT) return("PnlWdbeFamList.TcoTit");
	if (ix == PNLWDBEFAM1NUNIT_TCOREF) return("PnlWdbeFam1NUnit.TcoRef");
	if (ix == PNLWDBESILLIST_TCOSRF) return("PnlWdbeSilList.TcoSrf");
	if (ix == PNLWDBESILLIST_TCOTIT) return("PnlWdbeSilList.TcoTit");
	if (ix == PNLWDBESILLIST_TCOFSR) return("PnlWdbeSilList.TcoFsr");
	if (ix == PNLWDBESILLIST_TCOTYP) return("PnlWdbeSilList.TcoTyp");
	if (ix == PNLWDBESILLIST_TCORET) return("PnlWdbeSilList.TcoRet");
	if (ix == PNLWDBESILLIST_TCOREU) return("PnlWdbeSilList.TcoReu");
	if (ix == PNLWDBESILLIST_TCOSYS) return("PnlWdbeSilList.TcoSys");
	if (ix == PNLWDBESILLIST_TCOMDL) return("PnlWdbeSilList.TcoMdl");
	if (ix == PNLWDBESILLIST_TCOPKG) return("PnlWdbeSilList.TcoPkg");
	if (ix == PNLWDBESILLIST_TCOESY) return("PnlWdbeSilList.TcoEsy");
	if (ix == PNLWDBESILLIST_TCOTCH) return("PnlWdbeSilList.TcoTch");
	if (ix == PNLWDBESIL1NPERIPHERAL_TCOREF) return("PnlWdbeSil1NPeripheral.TcoRef");
	if (ix == PNLWDBESILSIL1NUNIT_TCOREF) return("PnlWdbeSilSil1NUnit.TcoRef");
	if (ix == PNLWDBESIL1NBANK_TCOREF) return("PnlWdbeSil1NBank.TcoRef");
	if (ix == PNLWDBESILFWD1NCONTROLLER_TCOREF) return("PnlWdbeSilFwd1NController.TcoRef");
	if (ix == PNLWDBESIL1NTARGET_TCOREF) return("PnlWdbeSil1NTarget.TcoRef");
	if (ix == PNLWDBESILREF1NCOMMAND_TCOREF) return("PnlWdbeSilRef1NCommand.TcoRef");
	if (ix == PNLWDBESILREF1NERROR_TCOREF) return("PnlWdbeSilRef1NError.TcoRef");
	if (ix == PNLWDBESILHK1NVECTOR_TCOREF) return("PnlWdbeSilHk1NVector.TcoRef");
	if (ix == PNLWDBESILHK1NMODULE_TCOREF) return("PnlWdbeSilHk1NModule.TcoRef");
	if (ix == PNLWDBEMTPLIST_TCOSRF) return("PnlWdbeMtpList.TcoSrf");
	if (ix == PNLWDBEMTPLIST_TCOTYP) return("PnlWdbeMtpList.TcoTyp");
	if (ix == PNLWDBEMTPLIST_TCOSRR) return("PnlWdbeMtpList.TcoSrr");
	if (ix == PNLWDBEMTPKPARKEY_TCOFIX) return("PnlWdbeMtpKParKey.TcoFix");
	if (ix == PNLWDBEMTPKPARKEY_TCOSRF) return("PnlWdbeMtpKParKey.TcoSrf");
	if (ix == PNLWDBEMTPKPARKEY_TCOAVL) return("PnlWdbeMtpKParKey.TcoAvl");
	if (ix == PNLWDBEMTPKPARKEY_TCOIMP) return("PnlWdbeMtpKParKey.TcoImp");
	if (ix == PNLWDBEMTPKPARKEY_TCOTIT) return("PnlWdbeMtpKParKey.TcoTit");
	if (ix == PNLWDBEMTPKPARKEY_TCOCMT) return("PnlWdbeMtpKParKey.TcoCmt");
	if (ix == PNLWDBEMTPKHDLTYPE_TCOFIX) return("PnlWdbeMtpKHdltype.TcoFix");
	if (ix == PNLWDBEMTPKHDLTYPE_TCOSRF) return("PnlWdbeMtpKHdltype.TcoSrf");
	if (ix == PNLWDBEMTPKHDLTYPE_TCOAVL) return("PnlWdbeMtpKHdltype.TcoAvl");
	if (ix == PNLWDBEMTPKHDLTYPE_TCOIMP) return("PnlWdbeMtpKHdltype.TcoImp");
	if (ix == PNLWDBEMTPKHDLTYPE_TCOTIT) return("PnlWdbeMtpKHdltype.TcoTit");
	if (ix == PNLWDBEMTPKHDLTYPE_TCOCMT) return("PnlWdbeMtpKHdltype.TcoCmt");
	if (ix == PNLWDBEMTPAPAR_TCOKEY) return("PnlWdbeMtpAPar.TcoKey");
	if (ix == PNLWDBEMTPAPAR_TCOVAL) return("PnlWdbeMtpAPar.TcoVal");
	if (ix == PNLWDBEMTPMDL1NPORT_TCOREF) return("PnlWdbeMtpMdl1NPort.TcoRef");
	if (ix == PNLWDBEMTPTPL1NMODULE_TCOREF) return("PnlWdbeMtpTpl1NModule.TcoRef");
	if (ix == PNLWDBEMTPMDL1NGENERIC_TCOREF) return("PnlWdbeMtpMdl1NGeneric.TcoRef");
	if (ix == PNLWDBEMTPSUP1NMODULE_TCOREF) return("PnlWdbeMtpSup1NModule.TcoRef");
	if (ix == PNLWDBEMTPREF1NFILE_TCOREF) return("PnlWdbeMtpRef1NFile.TcoRef");
	if (ix == PNLWDBEMTPMGE1NSIGNAL_TCOREF) return("PnlWdbeMtpMge1NSignal.TcoRef");
	if (ix == PNLWDBEPRJLIST_TCOGRP) return("PnlWdbePrjList.TcoGrp");
	if (ix == PNLWDBEPRJLIST_TCOOWN) return("PnlWdbePrjList.TcoOwn");
	if (ix == PNLWDBEPRJLIST_TCOSHO) return("PnlWdbePrjList.TcoSho");
	if (ix == PNLWDBEPRJLIST_TCOTIT) return("PnlWdbePrjList.TcoTit");
	if (ix == PNLWDBEPRJLIST_TCOVER) return("PnlWdbePrjList.TcoVer");
	if (ix == PNLWDBEPRJLIST_TCOESY) return("PnlWdbePrjList.TcoEsy");
	if (ix == PNLWDBEPRJLIST_TCOGRL) return("PnlWdbePrjList.TcoGrl");
	if (ix == PNLWDBEPRJPRJ1NVERSION_TCOREF) return("PnlWdbePrjPrj1NVersion.TcoRef");
	if (ix == PNLWDBEPRJMNPERSON_TCOMREF) return("PnlWdbePrjMNPerson.TcoMref");
	if (ix == PNLWDBEPRJMNPERSON_TCOSTA) return("PnlWdbePrjMNPerson.TcoSta");
	if (ix == PNLWDBEPRJMNPERSON_TCOSTO) return("PnlWdbePrjMNPerson.TcoSto");
	if (ix == PNLWDBEPRJMNPERSON_TCOFCT) return("PnlWdbePrjMNPerson.TcoFct");
	if (ix == PNLWDBEVERLIST_TCOGRP) return("PnlWdbeVerList.TcoGrp");
	if (ix == PNLWDBEVERLIST_TCOOWN) return("PnlWdbeVerList.TcoOwn");
	if (ix == PNLWDBEVERLIST_TCOPRJ) return("PnlWdbeVerList.TcoPrj");
	if (ix == PNLWDBEVERLIST_TCOMAJ) return("PnlWdbeVerList.TcoMaj");
	if (ix == PNLWDBEVERLIST_TCOMIN) return("PnlWdbeVerList.TcoMin");
	if (ix == PNLWDBEVERLIST_TCOSUB) return("PnlWdbeVerList.TcoSub");
	if (ix == PNLWDBEVERLIST_TCOBVR) return("PnlWdbeVerList.TcoBvr");
	if (ix == PNLWDBEVERLIST_TCOSTE) return("PnlWdbeVerList.TcoSte");
	if (ix == PNLWDBEVERBVR1NVERSION_TCOREF) return("PnlWdbeVerBvr1NVersion.TcoRef");
	if (ix == PNLWDBEVER1NSYSTEM_TCOREF) return("PnlWdbeVer1NSystem.TcoRef");
	if (ix == PNLWDBEVER1NRELEASE_TCOREF) return("PnlWdbeVer1NRelease.TcoRef");
	if (ix == PNLWDBEVER1NUNIT_TCOREF) return("PnlWdbeVer1NUnit.TcoRef");
	if (ix == PNLWDBEVERREF1NFILE_TCOREF) return("PnlWdbeVerRef1NFile.TcoRef");
	if (ix == PNLWDBEVERMNLIBRARY_TCOMREF) return("PnlWdbeVerMNLibrary.TcoMref");
	if (ix == PNLWDBESYSLIST_TCOSRF) return("PnlWdbeSysList.TcoSrf");
	if (ix == PNLWDBESYSLIST_TCOVER) return("PnlWdbeSysList.TcoVer");
	if (ix == PNLWDBESYSLIST_TCOUNT) return("PnlWdbeSysList.TcoUnt");
	if (ix == PNLWDBESYSSYS1NTARGET_TCOREF) return("PnlWdbeSysSys1NTarget.TcoRef");
	if (ix == PNLWDBESYSHK1NVECTOR_TCOREF) return("PnlWdbeSysHk1NVector.TcoRef");
	if (ix == PNLWDBETRGLIST_TCOSRF) return("PnlWdbeTrgList.TcoSrf");
	if (ix == PNLWDBETRGLIST_TCOSYS) return("PnlWdbeTrgList.TcoSys");
	if (ix == PNLWDBETRGLIST_TCOUNT) return("PnlWdbeTrgList.TcoUnt");
	if (ix == PNLWDBEUNTLIST_TCOSRF) return("PnlWdbeUntList.TcoSrf");
	if (ix == PNLWDBEUNTLIST_TCOTIT) return("PnlWdbeUntList.TcoTit");
	if (ix == PNLWDBEUNTLIST_TCOFSR) return("PnlWdbeUntList.TcoFsr");
	if (ix == PNLWDBEUNTLIST_TCOTYP) return("PnlWdbeUntList.TcoTyp");
	if (ix == PNLWDBEUNTLIST_TCORET) return("PnlWdbeUntList.TcoRet");
	if (ix == PNLWDBEUNTLIST_TCOREU) return("PnlWdbeUntList.TcoReu");
	if (ix == PNLWDBEUNTLIST_TCOSYS) return("PnlWdbeUntList.TcoSys");
	if (ix == PNLWDBEUNTLIST_TCOMDL) return("PnlWdbeUntList.TcoMdl");
	if (ix == PNLWDBEUNTLIST_TCOPKG) return("PnlWdbeUntList.TcoPkg");
	if (ix == PNLWDBEUNTLIST_TCOESY) return("PnlWdbeUntList.TcoEsy");
	if (ix == PNLWDBEUNTLIST_TCOTCH) return("PnlWdbeUntList.TcoTch");
	if (ix == PNLWDBEUNT1NPERIPHERAL_TCOREF) return("PnlWdbeUnt1NPeripheral.TcoRef");
	if (ix == PNLWDBEUNTSIL1NUNIT_TCOREF) return("PnlWdbeUntSil1NUnit.TcoRef");
	if (ix == PNLWDBEUNT1NBANK_TCOREF) return("PnlWdbeUnt1NBank.TcoRef");
	if (ix == PNLWDBEUNTFWD1NCONTROLLER_TCOREF) return("PnlWdbeUntFwd1NController.TcoRef");
	if (ix == PNLWDBEUNT1NTARGET_TCOREF) return("PnlWdbeUnt1NTarget.TcoRef");
	if (ix == PNLWDBEUNTREF1NCOMMAND_TCOREF) return("PnlWdbeUntRef1NCommand.TcoRef");
	if (ix == PNLWDBEUNTREF1NERROR_TCOREF) return("PnlWdbeUntRef1NError.TcoRef");
	if (ix == PNLWDBEUNTHK1NVECTOR_TCOREF) return("PnlWdbeUntHk1NVector.TcoRef");
	if (ix == PNLWDBEUNTHK1NMODULE_TCOREF) return("PnlWdbeUntHk1NModule.TcoRef");
	if (ix == PNLWDBERLSLIST_TCOSRF) return("PnlWdbeRlsList.TcoSrf");
	if (ix == PNLWDBERLSLIST_TCOTYP) return("PnlWdbeRlsList.TcoTyp");
	if (ix == PNLWDBERLSLIST_TCOVER) return("PnlWdbeRlsList.TcoVer");
	if (ix == PNLWDBERLSLIST_TCOMCH) return("PnlWdbeRlsList.TcoMch");
	if (ix == PNLWDBECPRLIST_TCOGRP) return("PnlWdbeCprList.TcoGrp");
	if (ix == PNLWDBECPRLIST_TCOOWN) return("PnlWdbeCprList.TcoOwn");
	if (ix == PNLWDBECPRLIST_TCOSRF) return("PnlWdbeCprList.TcoSrf");
	if (ix == PNLWDBECPRLIST_TCOTIT) return("PnlWdbeCprList.TcoTit");
	if (ix == PNLWDBECPRLIST_TCOTYP) return("PnlWdbeCprList.TcoTyp");
	if (ix == PNLWDBECPRLIST_TCOCVR) return("PnlWdbeCprList.TcoCvr");
	if (ix == PNLWDBECPRLIST_TCOGRL) return("PnlWdbeCprList.TcoGrl");
	if (ix == PNLWDBECPR1NCOREVERSION_TCOREF) return("PnlWdbeCpr1NCoreversion.TcoRef");
	if (ix == PNLWDBECPRMNPERSON_TCOMREF) return("PnlWdbeCprMNPerson.TcoMref");
	if (ix == PNLWDBECPRMNPERSON_TCOSTA) return("PnlWdbeCprMNPerson.TcoSta");
	if (ix == PNLWDBECPRMNPERSON_TCOSTO) return("PnlWdbeCprMNPerson.TcoSto");
	if (ix == PNLWDBECPRMNPERSON_TCOFCT) return("PnlWdbeCprMNPerson.TcoFct");
	if (ix == PNLWDBECVRLIST_TCOGRP) return("PnlWdbeCvrList.TcoGrp");
	if (ix == PNLWDBECVRLIST_TCOOWN) return("PnlWdbeCvrList.TcoOwn");
	if (ix == PNLWDBECVRLIST_TCOCPR) return("PnlWdbeCvrList.TcoCpr");
	if (ix == PNLWDBECVRLIST_TCOMAJ) return("PnlWdbeCvrList.TcoMaj");
	if (ix == PNLWDBECVRLIST_TCOMIN) return("PnlWdbeCvrList.TcoMin");
	if (ix == PNLWDBECVRLIST_TCOSUB) return("PnlWdbeCvrList.TcoSub");
	if (ix == PNLWDBECVRLIST_TCOBCV) return("PnlWdbeCvrList.TcoBcv");
	if (ix == PNLWDBECVRLIST_TCOSTE) return("PnlWdbeCvrList.TcoSte");
	if (ix == PNLWDBECVRAPLH_TCOSRF) return("PnlWdbeCvrAPlh.TcoSrf");
	if (ix == PNLWDBECVRAPLH_TCOCMT) return("PnlWdbeCvrAPlh.TcoCmt");
	if (ix == PNLWDBECVRAIP_TCOSRF) return("PnlWdbeCvrAIp.TcoSrf");
	if (ix == PNLWDBECVRAIP_TCOTTY) return("PnlWdbeCvrAIp.TcoTty");
	if (ix == PNLWDBECVRAIP_TCOCMT) return("PnlWdbeCvrAIp.TcoCmt");
	if (ix == PNLWDBECVRBCV1NCOREVERSION_TCOREF) return("PnlWdbeCvrBcv1NCoreversion.TcoRef");
	if (ix == PNLWDBECVRHK1NMODULE_TCOREF) return("PnlWdbeCvrHk1NModule.TcoRef");
	if (ix == PNLWDBEMODLIST_TCOSRF) return("PnlWdbeModList.TcoSrf");
	if (ix == PNLWDBEMODLIST_TCOTYP) return("PnlWdbeModList.TcoTyp");
	if (ix == PNLWDBEMODLIST_TCOHKT) return("PnlWdbeModList.TcoHkt");
	if (ix == PNLWDBEMODLIST_TCOHKU) return("PnlWdbeModList.TcoHku");
	if (ix == PNLWDBEMODLIST_TCOSUP) return("PnlWdbeModList.TcoSup");
	if (ix == PNLWDBEMODLIST_TCOTPL) return("PnlWdbeModList.TcoTpl");
	if (ix == PNLWDBEMODKHDLTYPE_TCOFIX) return("PnlWdbeModKHdltype.TcoFix");
	if (ix == PNLWDBEMODKHDLTYPE_TCOSRF) return("PnlWdbeModKHdltype.TcoSrf");
	if (ix == PNLWDBEMODKHDLTYPE_TCOAVL) return("PnlWdbeModKHdltype.TcoAvl");
	if (ix == PNLWDBEMODKHDLTYPE_TCOIMP) return("PnlWdbeModKHdltype.TcoImp");
	if (ix == PNLWDBEMODKHDLTYPE_TCOTIT) return("PnlWdbeModKHdltype.TcoTit");
	if (ix == PNLWDBEMODKHDLTYPE_TCOCMT) return("PnlWdbeModKHdltype.TcoCmt");
	if (ix == PNLWDBEMODAPAR_TCOKEY) return("PnlWdbeModAPar.TcoKey");
	if (ix == PNLWDBEMODAPAR_TCOVAL) return("PnlWdbeModAPar.TcoVal");
	if (ix == PNLWDBEMOD1NPERIPHERAL_TCOREF) return("PnlWdbeMod1NPeripheral.TcoRef");
	if (ix == PNLWDBEMODMDL1NSIGNAL_TCOREF) return("PnlWdbeModMdl1NSignal.TcoRef");
	if (ix == PNLWDBEMOD1NPROCESS_TCOREF) return("PnlWdbeMod1NProcess.TcoRef");
	if (ix == PNLWDBEMODMDL1NPORT_TCOREF) return("PnlWdbeModMdl1NPort.TcoRef");
	if (ix == PNLWDBEMODCOR1NIMBUF_TCOREF) return("PnlWdbeModCor1NImbuf.TcoRef");
	if (ix == PNLWDBEMODMDL1NGENERIC_TCOREF) return("PnlWdbeModMdl1NGeneric.TcoRef");
	if (ix == PNLWDBEMODSUP1NMODULE_TCOREF) return("PnlWdbeModSup1NModule.TcoRef");
	if (ix == PNLWDBEMODMGE1NSIGNAL_TCOREF) return("PnlWdbeModMge1NSignal.TcoRef");
	if (ix == PNLWDBEMODCTRREF1NCOMMAND_TCOREF) return("PnlWdbeModCtrRef1NCommand.TcoRef");
	if (ix == PNLWDBEMODCTRREF1NERROR_TCOREF) return("PnlWdbeModCtrRef1NError.TcoRef");
	if (ix == PNLWDBEMODCTRHK1NVECTOR_TCOREF) return("PnlWdbeModCtrHk1NVector.TcoRef");
	if (ix == PNLWDBEMODCTRMNCOMMAND_TCOMREF) return("PnlWdbeModCtrMNCommand.TcoMref");
	if (ix == PNLWDBEMODCTRMNCOMMAND_TCOIVR) return("PnlWdbeModCtrMNCommand.TcoIvr");
	if (ix == PNLWDBEMODCTRMNCOMMAND_TCORVR) return("PnlWdbeModCtrMNCommand.TcoRvr");
	if (ix == PNLWDBEVECLIST_TCOSRF) return("PnlWdbeVecList.TcoSrf");
	if (ix == PNLWDBEVECLIST_TCOTYP) return("PnlWdbeVecList.TcoTyp");
	if (ix == PNLWDBEVECLIST_TCOHKT) return("PnlWdbeVecList.TcoHkt");
	if (ix == PNLWDBEVECLIST_TCOHKU) return("PnlWdbeVecList.TcoHku");
	if (ix == PNLWDBEVECVEC1NVECTORITEM_TCOREF) return("PnlWdbeVecVec1NVectoritem.TcoRef");
	if (ix == PNLWDBEVITLIST_TCOSRF) return("PnlWdbeVitList.TcoSrf");
	if (ix == PNLWDBEVITLIST_TCOTIT) return("PnlWdbeVitList.TcoTit");
	if (ix == PNLWDBEVITLIST_TCOVEC) return("PnlWdbeVitList.TcoVec");
	if (ix == PNLWDBECMDLIST_TCOSRF) return("PnlWdbeCmdList.TcoSrf");
	if (ix == PNLWDBECMDLIST_TCOFSR) return("PnlWdbeCmdList.TcoFsr");
	if (ix == PNLWDBECMDLIST_TCORET) return("PnlWdbeCmdList.TcoRet");
	if (ix == PNLWDBECMDLIST_TCOREU) return("PnlWdbeCmdList.TcoReu");
	if (ix == PNLWDBECMDLIST_TCORTY) return("PnlWdbeCmdList.TcoRty");
	if (ix == PNLWDBECMDARETPAR_TCOSRF) return("PnlWdbeCmdARetpar.TcoSrf");
	if (ix == PNLWDBECMDARETPAR_TCOPTY) return("PnlWdbeCmdARetpar.TcoPty");
	if (ix == PNLWDBECMDARETPAR_TCOVEC) return("PnlWdbeCmdARetpar.TcoVec");
	if (ix == PNLWDBECMDARETPAR_TCOLEN) return("PnlWdbeCmdARetpar.TcoLen");
	if (ix == PNLWDBECMDARETPAR_TCOCMT) return("PnlWdbeCmdARetpar.TcoCmt");
	if (ix == PNLWDBECMDAINVPAR_TCOSRF) return("PnlWdbeCmdAInvpar.TcoSrf");
	if (ix == PNLWDBECMDAINVPAR_TCOPTY) return("PnlWdbeCmdAInvpar.TcoPty");
	if (ix == PNLWDBECMDAINVPAR_TCOVEC) return("PnlWdbeCmdAInvpar.TcoVec");
	if (ix == PNLWDBECMDAINVPAR_TCOLEN) return("PnlWdbeCmdAInvpar.TcoLen");
	if (ix == PNLWDBECMDAINVPAR_TCODFV) return("PnlWdbeCmdAInvpar.TcoDfv");
	if (ix == PNLWDBECMDAINVPAR_TCOVIT) return("PnlWdbeCmdAInvpar.TcoVit");
	if (ix == PNLWDBECMDAINVPAR_TCOCMT) return("PnlWdbeCmdAInvpar.TcoCmt");
	if (ix == PNLWDBECMDMNCONTROLLER_TCOMREF) return("PnlWdbeCmdMNController.TcoMref");
	if (ix == PNLWDBECMDMNCONTROLLER_TCOIVR) return("PnlWdbeCmdMNController.TcoIvr");
	if (ix == PNLWDBECMDMNCONTROLLER_TCORVR) return("PnlWdbeCmdMNController.TcoRvr");
	if (ix == PNLWDBEERRLIST_TCOSRF) return("PnlWdbeErrList.TcoSrf");
	if (ix == PNLWDBEERRLIST_TCOFSR) return("PnlWdbeErrList.TcoFsr");
	if (ix == PNLWDBEERRLIST_TCORET) return("PnlWdbeErrList.TcoRet");
	if (ix == PNLWDBEERRLIST_TCOREU) return("PnlWdbeErrList.TcoReu");
	if (ix == PNLWDBEERRAPAR_TCOSRF) return("PnlWdbeErrAPar.TcoSrf");
	if (ix == PNLWDBEERRAPAR_TCOPTY) return("PnlWdbeErrAPar.TcoPty");
	if (ix == PNLWDBEERRAPAR_TCOVEC) return("PnlWdbeErrAPar.TcoVec");
	if (ix == PNLWDBEERRAPAR_TCOLEN) return("PnlWdbeErrAPar.TcoLen");
	if (ix == PNLWDBEERRAPAR_TCOCMT) return("PnlWdbeErrAPar.TcoCmt");
	if (ix == PNLWDBEPPHLIST_TCOSRF) return("PnlWdbePphList.TcoSrf");
	if (ix == PNLWDBEPPHLIST_TCOUNT) return("PnlWdbePphList.TcoUnt");
	if (ix == PNLWDBEPPHLIST_TCOMDL) return("PnlWdbePphList.TcoMdl");
	if (ix == PNLWDBEPPHAPAR_TCOKEY) return("PnlWdbePphAPar.TcoKey");
	if (ix == PNLWDBEPPHAPAR_TCOVAL) return("PnlWdbePphAPar.TcoVal");
	if (ix == PNLWDBEBNKLIST_TCOSRF) return("PnlWdbeBnkList.TcoSrf");
	if (ix == PNLWDBEBNKLIST_TCOUNT) return("PnlWdbeBnkList.TcoUnt");
	if (ix == PNLWDBEBNKLIST_TCOVST) return("PnlWdbeBnkList.TcoVst");
	if (ix == PNLWDBEBNK1NPIN_TCOREF) return("PnlWdbeBnk1NPin.TcoRef");
	if (ix == PNLWDBEPINLIST_TCOSRF) return("PnlWdbePinList.TcoSrf");
	if (ix == PNLWDBEPINLIST_TCOBNK) return("PnlWdbePinList.TcoBnk");
	if (ix == PNLWDBEPINLIST_TCOLOC) return("PnlWdbePinList.TcoLoc");
	if (ix == PNLWDBEPINAPAR_TCOKEY) return("PnlWdbePinAPar.TcoKey");
	if (ix == PNLWDBEPINAPAR_TCOVAL) return("PnlWdbePinAPar.TcoVal");
	if (ix == PNLWDBEGENLIST_TCOSRF) return("PnlWdbeGenList.TcoSrf");
	if (ix == PNLWDBEGENLIST_TCOMDL) return("PnlWdbeGenList.TcoMdl");
	if (ix == PNLWDBEGENLIST_TCOHTY) return("PnlWdbeGenList.TcoHty");
	if (ix == PNLWDBEGENLIST_TCOWID) return("PnlWdbeGenList.TcoWid");
	if (ix == PNLWDBEGENLIST_TCOMMX) return("PnlWdbeGenList.TcoMmx");
	if (ix == PNLWDBEPRTLIST_TCOSRF) return("PnlWdbePrtList.TcoSrf");
	if (ix == PNLWDBEPRTLIST_TCOMDL) return("PnlWdbePrtList.TcoMdl");
	if (ix == PNLWDBEPRTLIST_TCOMDC) return("PnlWdbePrtList.TcoMdc");
	if (ix == PNLWDBEPRTLIST_TCODIR) return("PnlWdbePrtList.TcoDir");
	if (ix == PNLWDBEPRTLIST_TCOHTY) return("PnlWdbePrtList.TcoHty");
	if (ix == PNLWDBEPRTLIST_TCOWID) return("PnlWdbePrtList.TcoWid");
	if (ix == PNLWDBEPRTLIST_TCOMMX) return("PnlWdbePrtList.TcoMmx");
	if (ix == PNLWDBESIGLIST_TCOSRF) return("PnlWdbeSigList.TcoSrf");
	if (ix == PNLWDBESIGLIST_TCOTYP) return("PnlWdbeSigList.TcoTyp");
	if (ix == PNLWDBESIGLIST_TCOMDL) return("PnlWdbeSigList.TcoMdl");
	if (ix == PNLWDBESIGLIST_TCOMGT) return("PnlWdbeSigList.TcoMgt");
	if (ix == PNLWDBESIGLIST_TCOMGU) return("PnlWdbeSigList.TcoMgu");
	if (ix == PNLWDBESIGLIST_TCOVEC) return("PnlWdbeSigList.TcoVec");
	if (ix == PNLWDBESIGLIST_TCOCON) return("PnlWdbeSigList.TcoCon");
	if (ix == PNLWDBESIGLIST_TCOHTY) return("PnlWdbeSigList.TcoHty");
	if (ix == PNLWDBESIGLIST_TCOWID) return("PnlWdbeSigList.TcoWid");
	if (ix == PNLWDBESIGLIST_TCOMMX) return("PnlWdbeSigList.TcoMmx");
	if (ix == PNLWDBEPRCLIST_TCOSRF) return("PnlWdbePrcList.TcoSrf");
	if (ix == PNLWDBEPRCLIST_TCOMDL) return("PnlWdbePrcList.TcoMdl");
	if (ix == PNLWDBEPRCLIST_TCOFAL) return("PnlWdbePrcList.TcoFal");
	if (ix == PNLWDBEPRCKHDLTYPE_TCOFIX) return("PnlWdbePrcKHdltype.TcoFix");
	if (ix == PNLWDBEPRCKHDLTYPE_TCOSRF) return("PnlWdbePrcKHdltype.TcoSrf");
	if (ix == PNLWDBEPRCKHDLTYPE_TCOAVL) return("PnlWdbePrcKHdltype.TcoAvl");
	if (ix == PNLWDBEPRCKHDLTYPE_TCOIMP) return("PnlWdbePrcKHdltype.TcoImp");
	if (ix == PNLWDBEPRCKHDLTYPE_TCOTIT) return("PnlWdbePrcKHdltype.TcoTit");
	if (ix == PNLWDBEPRCKHDLTYPE_TCOCMT) return("PnlWdbePrcKHdltype.TcoCmt");
	if (ix == PNLWDBEPRCPRC1NVARIABLE_TCOREF) return("PnlWdbePrcPrc1NVariable.TcoRef");
	if (ix == PNLWDBEPRCMGE1NSIGNAL_TCOREF) return("PnlWdbePrcMge1NSignal.TcoRef");
	if (ix == PNLWDBEPRCFSMFSM1NFSMSTATE_TCOREF) return("PnlWdbePrcFsmFsm1NFsmstate.TcoRef");
	if (ix == PNLWDBEFSTLIST_TCOSRF) return("PnlWdbeFstList.TcoSrf");
	if (ix == PNLWDBEFSTLIST_TCOFSM) return("PnlWdbeFstList.TcoFsm");
	if (ix == PNLWDBEFSTASTEP_TCOFNX) return("PnlWdbeFstAStep.TcoFnx");
	if (ix == PNLWDBEFSTASTEP_TCOCN1) return("PnlWdbeFstAStep.TcoCn1");
	if (ix == PNLWDBEFSTASTEP_TCOIP1) return("PnlWdbeFstAStep.TcoIp1");
	if (ix == PNLWDBEFSTASTEP_TCOCN2) return("PnlWdbeFstAStep.TcoCn2");
	if (ix == PNLWDBEFSTASTEP_TCOIP2) return("PnlWdbeFstAStep.TcoIp2");
	if (ix == PNLWDBEFSTASTEP_TCOCN3) return("PnlWdbeFstAStep.TcoCn3");
	if (ix == PNLWDBEFSTASTEP_TCOIP3) return("PnlWdbeFstAStep.TcoIp3");
	if (ix == PNLWDBEFSTASTEP_TCOCN4) return("PnlWdbeFstAStep.TcoCn4");
	if (ix == PNLWDBEFSTASTEP_TCOIP4) return("PnlWdbeFstAStep.TcoIp4");
	if (ix == PNLWDBEVARLIST_TCOSRF) return("PnlWdbeVarList.TcoSrf");
	if (ix == PNLWDBEVARLIST_TCOPRC) return("PnlWdbeVarList.TcoPrc");
	if (ix == PNLWDBEVARLIST_TCOCON) return("PnlWdbeVarList.TcoCon");
	if (ix == PNLWDBEVARLIST_TCOFAL) return("PnlWdbeVarList.TcoFal");
	if (ix == PNLWDBEVARLIST_TCOHTY) return("PnlWdbeVarList.TcoHty");
	if (ix == PNLWDBEVARLIST_TCOWID) return("PnlWdbeVarList.TcoWid");
	if (ix == PNLWDBEVARLIST_TCOMMX) return("PnlWdbeVarList.TcoMmx");

	return("");
};

/******************************************************************************
 class DbsWdbe::VecVFeatgroup
 ******************************************************************************/

uint DbsWdbe::VecVFeatgroup::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vecwdbevcard") return VECWDBEVCARD;

	return(0);
};

string DbsWdbe::VecVFeatgroup::getSref(
			const uint ix
		) {
	if (ix == VECWDBEVCARD) return("VecWdbeVCard");

	return("");
};

string DbsWdbe::VecVFeatgroup::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VECWDBEVCARD) return("card");
		return(getSref(ix));
	};

	return("");
};

void DbsWdbe::VecVFeatgroup::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DbsWdbe::VecVKeylist
 ******************************************************************************/

uint DbsWdbe::VecVKeylist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "klstwdbekamlibrarymakefiletag") return KLSTWDBEKAMLIBRARYMAKEFILETAG;
	if (s == "klstwdbekammachinemakefiletag") return KLSTWDBEKAMMACHINEMAKEFILETAG;
	if (s == "klstwdbekammachineparkey") return KLSTWDBEKAMMACHINEPARKEY;
	if (s == "klstwdbekammoduleparkey") return KLSTWDBEKAMMODULEPARKEY;
	if (s == "klstwdbekamperipheralparkey") return KLSTWDBEKAMPERIPHERALPARKEY;
	if (s == "klstwdbekampersondetailtype") return KLSTWDBEKAMPERSONDETAILTYPE;
	if (s == "klstwdbekampinparkey") return KLSTWDBEKAMPINPARKEY;
	if (s == "klstwdbekhdltype") return KLSTWDBEKHDLTYPE;
	if (s == "klstwdbekmbankvoltstd") return KLSTWDBEKMBANKVOLTSTD;
	if (s == "klstwdbekmfamilyvendor") return KLSTWDBEKMFAMILYVENDOR;
	if (s == "klstwdbekmfilecontent") return KLSTWDBEKMFILECONTENT;
	if (s == "klstwdbekmfilemimetype") return KLSTWDBEKMFILEMIMETYPE;
	if (s == "klstwdbekmreleaseoption") return KLSTWDBEKMRELEASEOPTION;
	if (s == "klstwdbekmunitpackage") return KLSTWDBEKMUNITPACKAGE;
	if (s == "klstwdbekmunittoolch") return KLSTWDBEKMUNITTOOLCH;
	if (s == "klstwdbekmvectoroption") return KLSTWDBEKMVECTOROPTION;
	if (s == "klstwdbekrmcoreprojectmpersonfunction") return KLSTWDBEKRMCOREPROJECTMPERSONFUNCTION;
	if (s == "klstwdbekrmpersonmprojectfunction") return KLSTWDBEKRMPERSONMPROJECTFUNCTION;
	if (s == "klstkwdbemtpmodbscbucustop") return KLSTKWDBEMTPMODBSCBUCUSTOP;
	if (s == "klstkwdbemtpmodbsctdcustop") return KLSTKWDBEMTPMODBSCTDCUSTOP;
	if (s == "klstkwdbemtpmoddetcustop") return KLSTKWDBEMTPMODDETCUSTOP;
	if (s == "klstkwdbemtpplhfpgacustop") return KLSTKWDBEMTPPLHFPGACUSTOP;
	if (s == "klstkwdbemtpplhmcucustop") return KLSTKWDBEMTPPLHMCUCUSTOP;
	if (s == "klstkwdbemtpwrfpgacustop") return KLSTKWDBEMTPWRFPGACUSTOP;
	if (s == "klstkwdbemtpwrmcucustop") return KLSTKWDBEMTPWRMCUCUSTOP;

	return(0);
};

string DbsWdbe::VecVKeylist::getSref(
			const uint ix
		) {
	if (ix == KLSTWDBEKAMLIBRARYMAKEFILETAG) return("KlstWdbeKAMLibraryMakefileTag");
	if (ix == KLSTWDBEKAMMACHINEMAKEFILETAG) return("KlstWdbeKAMMachineMakefileTag");
	if (ix == KLSTWDBEKAMMACHINEPARKEY) return("KlstWdbeKAMMachineParKey");
	if (ix == KLSTWDBEKAMMODULEPARKEY) return("KlstWdbeKAMModuleParKey");
	if (ix == KLSTWDBEKAMPERIPHERALPARKEY) return("KlstWdbeKAMPeripheralParKey");
	if (ix == KLSTWDBEKAMPERSONDETAILTYPE) return("KlstWdbeKAMPersonDetailType");
	if (ix == KLSTWDBEKAMPINPARKEY) return("KlstWdbeKAMPinParKey");
	if (ix == KLSTWDBEKHDLTYPE) return("KlstWdbeKHdltype");
	if (ix == KLSTWDBEKMBANKVOLTSTD) return("KlstWdbeKMBankVoltstd");
	if (ix == KLSTWDBEKMFAMILYVENDOR) return("KlstWdbeKMFamilyVendor");
	if (ix == KLSTWDBEKMFILECONTENT) return("KlstWdbeKMFileContent");
	if (ix == KLSTWDBEKMFILEMIMETYPE) return("KlstWdbeKMFileMimetype");
	if (ix == KLSTWDBEKMRELEASEOPTION) return("KlstWdbeKMReleaseOption");
	if (ix == KLSTWDBEKMUNITPACKAGE) return("KlstWdbeKMUnitPackage");
	if (ix == KLSTWDBEKMUNITTOOLCH) return("KlstWdbeKMUnitToolch");
	if (ix == KLSTWDBEKMVECTOROPTION) return("KlstWdbeKMVectorOption");
	if (ix == KLSTWDBEKRMCOREPROJECTMPERSONFUNCTION) return("KlstWdbeKRMCoreprojectMPersonFunction");
	if (ix == KLSTWDBEKRMPERSONMPROJECTFUNCTION) return("KlstWdbeKRMPersonMProjectFunction");
	if (ix == KLSTKWDBEMTPMODBSCBUCUSTOP) return("KlstKWdbeMtpModbscbuCustop");
	if (ix == KLSTKWDBEMTPMODBSCTDCUSTOP) return("KlstKWdbeMtpModbsctdCustop");
	if (ix == KLSTKWDBEMTPMODDETCUSTOP) return("KlstKWdbeMtpModdetCustop");
	if (ix == KLSTKWDBEMTPPLHFPGACUSTOP) return("KlstKWdbeMtpPlhfpgaCustop");
	if (ix == KLSTKWDBEMTPPLHMCUCUSTOP) return("KlstKWdbeMtpPlhmcuCustop");
	if (ix == KLSTKWDBEMTPWRFPGACUSTOP) return("KlstKWdbeMtpWrfpgaCustop");
	if (ix == KLSTKWDBEMTPWRMCUCUSTOP) return("KlstKWdbeMtpWrmcuCustop");

	return("");
};

string DbsWdbe::VecVKeylist::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == KLSTWDBEKAMLIBRARYMAKEFILETAG) return("tag");
		if (ix == KLSTWDBEKAMMACHINEMAKEFILETAG) return("tag");
		if (ix == KLSTWDBEKAMMACHINEPARKEY) return("key");
		if (ix == KLSTWDBEKAMMODULEPARKEY) return("key");
		if (ix == KLSTWDBEKAMPERIPHERALPARKEY) return("key");
		if (ix == KLSTWDBEKAMPERSONDETAILTYPE) return("type");
		if (ix == KLSTWDBEKAMPINPARKEY) return("key");
		if (ix == KLSTWDBEKHDLTYPE) return("HDL data type");
		if (ix == KLSTWDBEKMBANKVOLTSTD) return("voltage standard");
		if (ix == KLSTWDBEKMFAMILYVENDOR) return("vendor");
		if (ix == KLSTWDBEKMFILECONTENT) return("content");
		if (ix == KLSTWDBEKMFILEMIMETYPE) return("MIME type");
		if (ix == KLSTWDBEKMRELEASEOPTION) return("options");
		if (ix == KLSTWDBEKMUNITPACKAGE) return("package");
		if (ix == KLSTWDBEKMUNITTOOLCH) return("tool chain");
		if (ix == KLSTWDBEKMVECTOROPTION) return("options");
		if (ix == KLSTWDBEKRMCOREPROJECTMPERSONFUNCTION) return("function");
		if (ix == KLSTWDBEKRMPERSONMPROJECTFUNCTION) return("function");
		if (ix == KLSTKWDBEMTPMODBSCBUCUSTOP) return("WdbeMtpModbscbu custom operations");
		if (ix == KLSTKWDBEMTPMODBSCTDCUSTOP) return("WdbeMtpModbsctd custom operations");
		if (ix == KLSTKWDBEMTPMODDETCUSTOP) return("WdbeMtpModdet custom operations");
		if (ix == KLSTKWDBEMTPPLHFPGACUSTOP) return("WdbeMtpPlhfpga custom operations");
		if (ix == KLSTKWDBEMTPPLHMCUCUSTOP) return("WdbeMtpPlhmcu custom operations");
		if (ix == KLSTKWDBEMTPWRFPGACUSTOP) return("WdbeMtpWrfpga custom operations");
		if (ix == KLSTKWDBEMTPWRMCUCUSTOP) return("WdbeMtpWrmcu custom operations");
		return(getSref(ix));
	};

	return("");
};

/******************************************************************************
 class DbsWdbe::VecVLat
 ******************************************************************************/

uint DbsWdbe::VecVLat::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "dlo") return DLO;
	if (s == "ini") return INI;

	return(0);
};

string DbsWdbe::VecVLat::getSref(
			const uint ix
		) {
	if (ix == DLO) return("dlo");
	if (ix == INI) return("ini");

	return("");
};

/******************************************************************************
 class DbsWdbe::VecVLocale
 ******************************************************************************/

uint DbsWdbe::VecVLocale::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "enus") return ENUS;

	return(0);
};

string DbsWdbe::VecVLocale::getSref(
			const uint ix
		) {
	if (ix == ENUS) return("enus");

	return("");
};

string DbsWdbe::VecVLocale::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == ENUS) return("English (United States)");
		return(getSref(ix));
	};

	return("");
};

void DbsWdbe::VecVLocale::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DbsWdbe::VecVLop
 ******************************************************************************/

uint DbsWdbe::VecVLop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ins") return INS;
	if (s == "rmv") return RMV;

	return(0);
};

string DbsWdbe::VecVLop::getSref(
			const uint ix
		) {
	if (ix == INS) return("ins");
	if (ix == RMV) return("rmv");

	return("");
};

/******************************************************************************
 class DbsWdbe::VecVMaintable
 ******************************************************************************/

uint DbsWdbe::VecVMaintable::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "tblwdbembank") return TBLWDBEMBANK;
	if (s == "tblwdbemcommand") return TBLWDBEMCOMMAND;
	if (s == "tblwdbemcontroller") return TBLWDBEMCONTROLLER;
	if (s == "tblwdbemcoreproject") return TBLWDBEMCOREPROJECT;
	if (s == "tblwdbemcoreversion") return TBLWDBEMCOREVERSION;
	if (s == "tblwdbemerror") return TBLWDBEMERROR;
	if (s == "tblwdbemfamily") return TBLWDBEMFAMILY;
	if (s == "tblwdbemfile") return TBLWDBEMFILE;
	if (s == "tblwdbemfsm") return TBLWDBEMFSM;
	if (s == "tblwdbemfsmstate") return TBLWDBEMFSMSTATE;
	if (s == "tblwdbemgeneric") return TBLWDBEMGENERIC;
	if (s == "tblwdbemimbuf") return TBLWDBEMIMBUF;
	if (s == "tblwdbemlibrary") return TBLWDBEMLIBRARY;
	if (s == "tblwdbemmachine") return TBLWDBEMMACHINE;
	if (s == "tblwdbemmodule") return TBLWDBEMMODULE;
	if (s == "tblwdbemperipheral") return TBLWDBEMPERIPHERAL;
	if (s == "tblwdbemperson") return TBLWDBEMPERSON;
	if (s == "tblwdbempin") return TBLWDBEMPIN;
	if (s == "tblwdbemport") return TBLWDBEMPORT;
	if (s == "tblwdbemprocess") return TBLWDBEMPROCESS;
	if (s == "tblwdbemproject") return TBLWDBEMPROJECT;
	if (s == "tblwdbemrelease") return TBLWDBEMRELEASE;
	if (s == "tblwdbemsession") return TBLWDBEMSESSION;
	if (s == "tblwdbemsignal") return TBLWDBEMSIGNAL;
	if (s == "tblwdbemsystem") return TBLWDBEMSYSTEM;
	if (s == "tblwdbemtarget") return TBLWDBEMTARGET;
	if (s == "tblwdbemunit") return TBLWDBEMUNIT;
	if (s == "tblwdbemuser") return TBLWDBEMUSER;
	if (s == "tblwdbemusergroup") return TBLWDBEMUSERGROUP;
	if (s == "tblwdbemvariable") return TBLWDBEMVARIABLE;
	if (s == "tblwdbemvector") return TBLWDBEMVECTOR;
	if (s == "tblwdbemvectoritem") return TBLWDBEMVECTORITEM;
	if (s == "tblwdbemversion") return TBLWDBEMVERSION;

	return(0);
};

string DbsWdbe::VecVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == TBLWDBEMBANK) return("TblWdbeMBank");
	if (ix == TBLWDBEMCOMMAND) return("TblWdbeMCommand");
	if (ix == TBLWDBEMCONTROLLER) return("TblWdbeMController");
	if (ix == TBLWDBEMCOREPROJECT) return("TblWdbeMCoreproject");
	if (ix == TBLWDBEMCOREVERSION) return("TblWdbeMCoreversion");
	if (ix == TBLWDBEMERROR) return("TblWdbeMError");
	if (ix == TBLWDBEMFAMILY) return("TblWdbeMFamily");
	if (ix == TBLWDBEMFILE) return("TblWdbeMFile");
	if (ix == TBLWDBEMFSM) return("TblWdbeMFsm");
	if (ix == TBLWDBEMFSMSTATE) return("TblWdbeMFsmstate");
	if (ix == TBLWDBEMGENERIC) return("TblWdbeMGeneric");
	if (ix == TBLWDBEMIMBUF) return("TblWdbeMImbuf");
	if (ix == TBLWDBEMLIBRARY) return("TblWdbeMLibrary");
	if (ix == TBLWDBEMMACHINE) return("TblWdbeMMachine");
	if (ix == TBLWDBEMMODULE) return("TblWdbeMModule");
	if (ix == TBLWDBEMPERIPHERAL) return("TblWdbeMPeripheral");
	if (ix == TBLWDBEMPERSON) return("TblWdbeMPerson");
	if (ix == TBLWDBEMPIN) return("TblWdbeMPin");
	if (ix == TBLWDBEMPORT) return("TblWdbeMPort");
	if (ix == TBLWDBEMPROCESS) return("TblWdbeMProcess");
	if (ix == TBLWDBEMPROJECT) return("TblWdbeMProject");
	if (ix == TBLWDBEMRELEASE) return("TblWdbeMRelease");
	if (ix == TBLWDBEMSESSION) return("TblWdbeMSession");
	if (ix == TBLWDBEMSIGNAL) return("TblWdbeMSignal");
	if (ix == TBLWDBEMSYSTEM) return("TblWdbeMSystem");
	if (ix == TBLWDBEMTARGET) return("TblWdbeMTarget");
	if (ix == TBLWDBEMUNIT) return("TblWdbeMUnit");
	if (ix == TBLWDBEMUSER) return("TblWdbeMUser");
	if (ix == TBLWDBEMUSERGROUP) return("TblWdbeMUsergroup");
	if (ix == TBLWDBEMVARIABLE) return("TblWdbeMVariable");
	if (ix == TBLWDBEMVECTOR) return("TblWdbeMVector");
	if (ix == TBLWDBEMVECTORITEM) return("TblWdbeMVectoritem");
	if (ix == TBLWDBEMVERSION) return("TblWdbeMVersion");

	return("");
};

string DbsWdbe::VecVMaintable::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == TBLWDBEMBANK) return("I/O bank");
		if (ix == TBLWDBEMCOMMAND) return("command");
		if (ix == TBLWDBEMCONTROLLER) return("controller");
		if (ix == TBLWDBEMCOREPROJECT) return("core project");
		if (ix == TBLWDBEMCOREVERSION) return("core version");
		if (ix == TBLWDBEMERROR) return("error");
		if (ix == TBLWDBEMFAMILY) return("product family");
		if (ix == TBLWDBEMFILE) return("file");
		if (ix == TBLWDBEMFSM) return("finite state machine");
		if (ix == TBLWDBEMFSMSTATE) return("FSM state");
		if (ix == TBLWDBEMGENERIC) return("generic");
		if (ix == TBLWDBEMIMBUF) return("inter-module buffer");
		if (ix == TBLWDBEMLIBRARY) return("library");
		if (ix == TBLWDBEMMACHINE) return("machine");
		if (ix == TBLWDBEMMODULE) return("module");
		if (ix == TBLWDBEMPERIPHERAL) return("peripheral");
		if (ix == TBLWDBEMPERSON) return("person");
		if (ix == TBLWDBEMPIN) return("pin");
		if (ix == TBLWDBEMPORT) return("port");
		if (ix == TBLWDBEMPROCESS) return("process");
		if (ix == TBLWDBEMPROJECT) return("project");
		if (ix == TBLWDBEMRELEASE) return("release");
		if (ix == TBLWDBEMSESSION) return("session");
		if (ix == TBLWDBEMSIGNAL) return("signal");
		if (ix == TBLWDBEMSYSTEM) return("system");
		if (ix == TBLWDBEMTARGET) return("target");
		if (ix == TBLWDBEMUNIT) return("unit");
		if (ix == TBLWDBEMUSER) return("user");
		if (ix == TBLWDBEMUSERGROUP) return("user group");
		if (ix == TBLWDBEMVARIABLE) return("variable");
		if (ix == TBLWDBEMVECTOR) return("vector");
		if (ix == TBLWDBEMVECTORITEM) return("vector item");
		if (ix == TBLWDBEMVERSION) return("version");
		return(getSref(ix));
	};

	return("");
};

void DbsWdbe::VecVMaintable::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 34; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DbsWdbe::VecVOolop
 ******************************************************************************/

uint DbsWdbe::VecVOolop::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ina") return INA;
	if (s == "inb") return INB;
	if (s == "rmv") return RMV;
	if (s == "swp") return SWP;
	if (s == "toa") return TOA;
	if (s == "tob") return TOB;

	return(0);
};

string DbsWdbe::VecVOolop::getSref(
			const uint ix
		) {
	if (ix == INA) return("ina");
	if (ix == INB) return("inb");
	if (ix == RMV) return("rmv");
	if (ix == SWP) return("swp");
	if (ix == TOA) return("toa");
	if (ix == TOB) return("tob");

	return("");
};

/******************************************************************************
 class DbsWdbe::VecVPartype
 ******************************************************************************/

uint DbsWdbe::VecVPartype::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "tix") return TIX;
	if (s == "_bool") return _BOOL;
	if (s == "tinyint") return TINYINT;
	if (s == "utinyint") return UTINYINT;
	if (s == "smallint") return SMALLINT;
	if (s == "usmallint") return USMALLINT;
	if (s == "int") return INT;
	if (s == "uint") return UINT;
	if (s == "blob") return BLOB;
	if (s == "vblob") return VBLOB;

	return(0);
};

string DbsWdbe::VecVPartype::getSref(
			const uint ix
		) {
	if (ix == TIX) return("tix");
	if (ix == _BOOL) return("_bool");
	if (ix == TINYINT) return("tinyint");
	if (ix == UTINYINT) return("utinyint");
	if (ix == SMALLINT) return("smallint");
	if (ix == USMALLINT) return("usmallint");
	if (ix == INT) return("int");
	if (ix == UINT) return("uint");
	if (ix == BLOB) return("blob");
	if (ix == VBLOB) return("vblob");

	return("");
};

string DbsWdbe::VecVPartype::getTitle(
			const uint ix
		) {
	if (ix == TIX) return("vector item index");
	if (ix == _BOOL) return("boolean");
	if (ix == TINYINT) return("integer / byte (8bit)");
	if (ix == UTINYINT) return("unsigned integer / byte (8bit)");
	if (ix == SMALLINT) return("integer (16bit)");
	if (ix == USMALLINT) return("unsigned integer (16bit)");
	if (ix == INT) return("integer (32bit)");
	if (ix == UINT) return("unsigned integer (32bit)");
	if (ix == BLOB) return("fixed length binary large object");
	if (ix == VBLOB) return("variable length bin. large. obj.");
	return(getSref(ix));

	return("");
};

void DbsWdbe::VecVPartype::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 10; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i));
};

/******************************************************************************
 class DbsWdbe::VecVPreset
 ******************************************************************************/

uint DbsWdbe::VecVPreset::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	if (s == "prewdbeadmin") return PREWDBEADMIN;
	if (s == "prewdbebnklist.srf") return PREWDBEBNKLIST_SRF;
	if (s == "prewdbebnklist.unt") return PREWDBEBNKLIST_UNT;
	if (s == "prewdbecmdlist.ret") return PREWDBECMDLIST_RET;
	if (s == "prewdbecmdlist.reu") return PREWDBECMDLIST_REU;
	if (s == "prewdbecmdlist.srf") return PREWDBECMDLIST_SRF;
	if (s == "prewdbecprlist.cvr") return PREWDBECPRLIST_CVR;
	if (s == "prewdbecprlist.grp") return PREWDBECPRLIST_GRP;
	if (s == "prewdbecprlist.own") return PREWDBECPRLIST_OWN;
	if (s == "prewdbecprlist.srf") return PREWDBECPRLIST_SRF;
	if (s == "prewdbecprlist.tit") return PREWDBECPRLIST_TIT;
	if (s == "prewdbecprlist.typ") return PREWDBECPRLIST_TYP;
	if (s == "prewdbecprmnperson.x1") return PREWDBECPRMNPERSON_X1;
	if (s == "prewdbecvrlist.bcv") return PREWDBECVRLIST_BCV;
	if (s == "prewdbecvrlist.cpr") return PREWDBECVRLIST_CPR;
	if (s == "prewdbecvrlist.grp") return PREWDBECVRLIST_GRP;
	if (s == "prewdbecvrlist.own") return PREWDBECVRLIST_OWN;
	if (s == "prewdbecvrlist.ste") return PREWDBECVRLIST_STE;
	if (s == "prewdbeerrlist.ret") return PREWDBEERRLIST_RET;
	if (s == "prewdbeerrlist.reu") return PREWDBEERRLIST_REU;
	if (s == "prewdbeerrlist.srf") return PREWDBEERRLIST_SRF;
	if (s == "prewdbeextfolder") return PREWDBEEXTFOLDER;
	if (s == "prewdbefamlist.tit") return PREWDBEFAMLIST_TIT;
	if (s == "prewdbefamlist.vnd") return PREWDBEFAMLIST_VND;
	if (s == "prewdbefillist.fnm") return PREWDBEFILLIST_FNM;
	if (s == "prewdbefillist.grp") return PREWDBEFILLIST_GRP;
	if (s == "prewdbefillist.own") return PREWDBEFILLIST_OWN;
	if (s == "prewdbefillist.ret") return PREWDBEFILLIST_RET;
	if (s == "prewdbefillist.reu") return PREWDBEFILLIST_REU;
	if (s == "prewdbefstlist.fsm") return PREWDBEFSTLIST_FSM;
	if (s == "prewdbefstlist.srf") return PREWDBEFSTLIST_SRF;
	if (s == "prewdbegenlist.mdl") return PREWDBEGENLIST_MDL;
	if (s == "prewdbegenlist.srf") return PREWDBEGENLIST_SRF;
	if (s == "prewdbegiturl") return PREWDBEGITURL;
	if (s == "prewdbegroup") return PREWDBEGROUP;
	if (s == "prewdbeip") return PREWDBEIP;
	if (s == "prewdbeixbasereptype") return PREWDBEIXBASEREPTYPE;
	if (s == "prewdbeixcrdaccbnk") return PREWDBEIXCRDACCBNK;
	if (s == "prewdbeixcrdacccmd") return PREWDBEIXCRDACCCMD;
	if (s == "prewdbeixcrdacccpr") return PREWDBEIXCRDACCCPR;
	if (s == "prewdbeixcrdacccvr") return PREWDBEIXCRDACCCVR;
	if (s == "prewdbeixcrdaccerr") return PREWDBEIXCRDACCERR;
	if (s == "prewdbeixcrdaccfam") return PREWDBEIXCRDACCFAM;
	if (s == "prewdbeixcrdaccfil") return PREWDBEIXCRDACCFIL;
	if (s == "prewdbeixcrdaccfst") return PREWDBEIXCRDACCFST;
	if (s == "prewdbeixcrdaccgen") return PREWDBEIXCRDACCGEN;
	if (s == "prewdbeixcrdacclib") return PREWDBEIXCRDACCLIB;
	if (s == "prewdbeixcrdaccmch") return PREWDBEIXCRDACCMCH;
	if (s == "prewdbeixcrdaccmod") return PREWDBEIXCRDACCMOD;
	if (s == "prewdbeixcrdaccmtp") return PREWDBEIXCRDACCMTP;
	if (s == "prewdbeixcrdaccpin") return PREWDBEIXCRDACCPIN;
	if (s == "prewdbeixcrdaccpph") return PREWDBEIXCRDACCPPH;
	if (s == "prewdbeixcrdaccprc") return PREWDBEIXCRDACCPRC;
	if (s == "prewdbeixcrdaccprj") return PREWDBEIXCRDACCPRJ;
	if (s == "prewdbeixcrdaccprs") return PREWDBEIXCRDACCPRS;
	if (s == "prewdbeixcrdaccprt") return PREWDBEIXCRDACCPRT;
	if (s == "prewdbeixcrdaccrls") return PREWDBEIXCRDACCRLS;
	if (s == "prewdbeixcrdaccsig") return PREWDBEIXCRDACCSIG;
	if (s == "prewdbeixcrdaccsil") return PREWDBEIXCRDACCSIL;
	if (s == "prewdbeixcrdaccsys") return PREWDBEIXCRDACCSYS;
	if (s == "prewdbeixcrdacctrg") return PREWDBEIXCRDACCTRG;
	if (s == "prewdbeixcrdaccunt") return PREWDBEIXCRDACCUNT;
	if (s == "prewdbeixcrdaccusg") return PREWDBEIXCRDACCUSG;
	if (s == "prewdbeixcrdaccusr") return PREWDBEIXCRDACCUSR;
	if (s == "prewdbeixcrdaccutl") return PREWDBEIXCRDACCUTL;
	if (s == "prewdbeixcrdaccvar") return PREWDBEIXCRDACCVAR;
	if (s == "prewdbeixcrdaccvec") return PREWDBEIXCRDACCVEC;
	if (s == "prewdbeixcrdaccver") return PREWDBEIXCRDACCVER;
	if (s == "prewdbeixcrdaccvit") return PREWDBEIXCRDACCVIT;
	if (s == "prewdbeixlcl") return PREWDBEIXLCL;
	if (s == "prewdbeixord") return PREWDBEIXORD;
	if (s == "prewdbeixpre") return PREWDBEIXPRE;
	if (s == "prewdbeixrecacc") return PREWDBEIXRECACC;
	if (s == "prewdbejrefnotify") return PREWDBEJREFNOTIFY;
	if (s == "prewdbejrefsess") return PREWDBEJREFSESS;
	if (s == "prewdbelibamakefile.x1") return PREWDBELIBAMAKEFILE_X1;
	if (s == "prewdbelibamakefile.x2") return PREWDBELIBAMAKEFILE_X2;
	if (s == "prewdbeliblist.srf") return PREWDBELIBLIST_SRF;
	if (s == "prewdbemchamakefile.x1") return PREWDBEMCHAMAKEFILE_X1;
	if (s == "prewdbemchapar.x1") return PREWDBEMCHAPAR_X1;
	if (s == "prewdbemchlist.srf") return PREWDBEMCHLIST_SRF;
	if (s == "prewdbemchlist.sup") return PREWDBEMCHLIST_SUP;
	if (s == "prewdbemodapar.x1") return PREWDBEMODAPAR_X1;
	if (s == "prewdbemodlist.hkt") return PREWDBEMODLIST_HKT;
	if (s == "prewdbemodlist.hku") return PREWDBEMODLIST_HKU;
	if (s == "prewdbemodlist.srf") return PREWDBEMODLIST_SRF;
	if (s == "prewdbemodlist.sup") return PREWDBEMODLIST_SUP;
	if (s == "prewdbemodlist.tpl") return PREWDBEMODLIST_TPL;
	if (s == "prewdbemodlist.typ") return PREWDBEMODLIST_TYP;
	if (s == "prewdbemtpapar.x1") return PREWDBEMTPAPAR_X1;
	if (s == "prewdbemtplist.hkt") return PREWDBEMTPLIST_HKT;
	if (s == "prewdbemtplist.hku") return PREWDBEMTPLIST_HKU;
	if (s == "prewdbemtplist.srf") return PREWDBEMTPLIST_SRF;
	if (s == "prewdbemtplist.typ") return PREWDBEMTPLIST_TYP;
	if (s == "prewdbenoadm") return PREWDBENOADM;
	if (s == "prewdbeowner") return PREWDBEOWNER;
	if (s == "prewdbepinapar.x1") return PREWDBEPINAPAR_X1;
	if (s == "prewdbepinlist.bnk") return PREWDBEPINLIST_BNK;
	if (s == "prewdbepinlist.srf") return PREWDBEPINLIST_SRF;
	if (s == "prewdbepphapar.x1") return PREWDBEPPHAPAR_X1;
	if (s == "prewdbepphlist.mdl") return PREWDBEPPHLIST_MDL;
	if (s == "prewdbepphlist.srf") return PREWDBEPPHLIST_SRF;
	if (s == "prewdbepphlist.unt") return PREWDBEPPHLIST_UNT;
	if (s == "prewdbeprclist.mdl") return PREWDBEPRCLIST_MDL;
	if (s == "prewdbeprclist.srf") return PREWDBEPRCLIST_SRF;
	if (s == "prewdbeprjlist.grp") return PREWDBEPRJLIST_GRP;
	if (s == "prewdbeprjlist.own") return PREWDBEPRJLIST_OWN;
	if (s == "prewdbeprjlist.sho") return PREWDBEPRJLIST_SHO;
	if (s == "prewdbeprjlist.tit") return PREWDBEPRJLIST_TIT;
	if (s == "prewdbeprjlist.ver") return PREWDBEPRJLIST_VER;
	if (s == "prewdbeprjmnperson.x1") return PREWDBEPRJMNPERSON_X1;
	if (s == "prewdbeprsadetail.x1") return PREWDBEPRSADETAIL_X1;
	if (s == "prewdbeprslist.grp") return PREWDBEPRSLIST_GRP;
	if (s == "prewdbeprslist.lnm") return PREWDBEPRSLIST_LNM;
	if (s == "prewdbeprslist.own") return PREWDBEPRSLIST_OWN;
	if (s == "prewdbeprsmncoreproject.x1") return PREWDBEPRSMNCOREPROJECT_X1;
	if (s == "prewdbeprsmnproject.x1") return PREWDBEPRSMNPROJECT_X1;
	if (s == "prewdbeprtlist.mdl") return PREWDBEPRTLIST_MDL;
	if (s == "prewdbeprtlist.srf") return PREWDBEPRTLIST_SRF;
	if (s == "prewdberefbnk") return PREWDBEREFBNK;
	if (s == "prewdberefcmd") return PREWDBEREFCMD;
	if (s == "prewdberefcpr") return PREWDBEREFCPR;
	if (s == "prewdberefctr") return PREWDBEREFCTR;
	if (s == "prewdberefcvr") return PREWDBEREFCVR;
	if (s == "prewdbereferr") return PREWDBEREFERR;
	if (s == "prewdbereffam") return PREWDBEREFFAM;
	if (s == "prewdbereffil") return PREWDBEREFFIL;
	if (s == "prewdbereffsm") return PREWDBEREFFSM;
	if (s == "prewdbereffst") return PREWDBEREFFST;
	if (s == "prewdberefgen") return PREWDBEREFGEN;
	if (s == "prewdberefimb") return PREWDBEREFIMB;
	if (s == "prewdbereflib") return PREWDBEREFLIB;
	if (s == "prewdberefmch") return PREWDBEREFMCH;
	if (s == "prewdberefmct") return PREWDBEREFMCT;
	if (s == "prewdberefmdl") return PREWDBEREFMDL;
	if (s == "prewdberefmib") return PREWDBEREFMIB;
	if (s == "prewdberefmod") return PREWDBEREFMOD;
	if (s == "prewdberefmtp") return PREWDBEREFMTP;
	if (s == "prewdberefpin") return PREWDBEREFPIN;
	if (s == "prewdberefpph") return PREWDBEREFPPH;
	if (s == "prewdberefprc") return PREWDBEREFPRC;
	if (s == "prewdberefprj") return PREWDBEREFPRJ;
	if (s == "prewdberefprs") return PREWDBEREFPRS;
	if (s == "prewdberefprt") return PREWDBEREFPRT;
	if (s == "prewdberefrls") return PREWDBEREFRLS;
	if (s == "prewdberefsel") return PREWDBEREFSEL;
	if (s == "prewdberefses") return PREWDBEREFSES;
	if (s == "prewdberefsig") return PREWDBEREFSIG;
	if (s == "prewdberefsil") return PREWDBEREFSIL;
	if (s == "prewdberefsys") return PREWDBEREFSYS;
	if (s == "prewdbereftrg") return PREWDBEREFTRG;
	if (s == "prewdberefuni") return PREWDBEREFUNI;
	if (s == "prewdberefunt") return PREWDBEREFUNT;
	if (s == "prewdberefusg") return PREWDBEREFUSG;
	if (s == "prewdberefusr") return PREWDBEREFUSR;
	if (s == "prewdberefvar") return PREWDBEREFVAR;
	if (s == "prewdberefvec") return PREWDBEREFVEC;
	if (s == "prewdberefver") return PREWDBEREFVER;
	if (s == "prewdberefvit") return PREWDBEREFVIT;
	if (s == "prewdberepfolder") return PREWDBEREPFOLDER;
	if (s == "prewdberlslist.mch") return PREWDBERLSLIST_MCH;
	if (s == "prewdberlslist.srf") return PREWDBERLSLIST_SRF;
	if (s == "prewdberlslist.typ") return PREWDBERLSLIST_TYP;
	if (s == "prewdberlslist.ver") return PREWDBERLSLIST_VER;
	if (s == "prewdbesess") return PREWDBESESS;
	if (s == "prewdbesiglist.con") return PREWDBESIGLIST_CON;
	if (s == "prewdbesiglist.mdl") return PREWDBESIGLIST_MDL;
	if (s == "prewdbesiglist.mgt") return PREWDBESIGLIST_MGT;
	if (s == "prewdbesiglist.mgu") return PREWDBESIGLIST_MGU;
	if (s == "prewdbesiglist.srf") return PREWDBESIGLIST_SRF;
	if (s == "prewdbesiglist.typ") return PREWDBESIGLIST_TYP;
	if (s == "prewdbesiglist.vec") return PREWDBESIGLIST_VEC;
	if (s == "prewdbesillist.mdl") return PREWDBESILLIST_MDL;
	if (s == "prewdbesillist.ret") return PREWDBESILLIST_RET;
	if (s == "prewdbesillist.reu") return PREWDBESILLIST_REU;
	if (s == "prewdbesillist.srf") return PREWDBESILLIST_SRF;
	if (s == "prewdbesillist.sys") return PREWDBESILLIST_SYS;
	if (s == "prewdbesillist.tit") return PREWDBESILLIST_TIT;
	if (s == "prewdbesillist.typ") return PREWDBESILLIST_TYP;
	if (s == "prewdbesuspsess") return PREWDBESUSPSESS;
	if (s == "prewdbesysdate") return PREWDBESYSDATE;
	if (s == "prewdbesyslist.srf") return PREWDBESYSLIST_SRF;
	if (s == "prewdbesyslist.unt") return PREWDBESYSLIST_UNT;
	if (s == "prewdbesyslist.ver") return PREWDBESYSLIST_VER;
	if (s == "prewdbesysstamp") return PREWDBESYSSTAMP;
	if (s == "prewdbesystime") return PREWDBESYSTIME;
	if (s == "prewdbetlast") return PREWDBETLAST;
	if (s == "prewdbetrglist.srf") return PREWDBETRGLIST_SRF;
	if (s == "prewdbetrglist.sys") return PREWDBETRGLIST_SYS;
	if (s == "prewdbetrglist.unt") return PREWDBETRGLIST_UNT;
	if (s == "prewdbeuntlist.mdl") return PREWDBEUNTLIST_MDL;
	if (s == "prewdbeuntlist.ret") return PREWDBEUNTLIST_RET;
	if (s == "prewdbeuntlist.reu") return PREWDBEUNTLIST_REU;
	if (s == "prewdbeuntlist.srf") return PREWDBEUNTLIST_SRF;
	if (s == "prewdbeuntlist.sys") return PREWDBEUNTLIST_SYS;
	if (s == "prewdbeuntlist.tit") return PREWDBEUNTLIST_TIT;
	if (s == "prewdbeuntlist.typ") return PREWDBEUNTLIST_TYP;
	if (s == "prewdbeusgaaccess.x1") return PREWDBEUSGAACCESS_X1;
	if (s == "prewdbeusgaaccess.x2") return PREWDBEUSGAACCESS_X2;
	if (s == "prewdbeusglist.grp") return PREWDBEUSGLIST_GRP;
	if (s == "prewdbeusglist.own") return PREWDBEUSGLIST_OWN;
	if (s == "prewdbeusglist.srf") return PREWDBEUSGLIST_SRF;
	if (s == "prewdbeusraaccess.x1") return PREWDBEUSRAACCESS_X1;
	if (s == "prewdbeusraaccess.x2") return PREWDBEUSRAACCESS_X2;
	if (s == "prewdbeusrlist.grp") return PREWDBEUSRLIST_GRP;
	if (s == "prewdbeusrlist.own") return PREWDBEUSRLIST_OWN;
	if (s == "prewdbeusrlist.prs") return PREWDBEUSRLIST_PRS;
	if (s == "prewdbeusrlist.srf") return PREWDBEUSRLIST_SRF;
	if (s == "prewdbeusrlist.ste") return PREWDBEUSRLIST_STE;
	if (s == "prewdbeusrlist.usg") return PREWDBEUSRLIST_USG;
	if (s == "prewdbevarlist.prc") return PREWDBEVARLIST_PRC;
	if (s == "prewdbevarlist.srf") return PREWDBEVARLIST_SRF;
	if (s == "prewdbeveclist.hkt") return PREWDBEVECLIST_HKT;
	if (s == "prewdbeveclist.hku") return PREWDBEVECLIST_HKU;
	if (s == "prewdbeveclist.srf") return PREWDBEVECLIST_SRF;
	if (s == "prewdbeveclist.typ") return PREWDBEVECLIST_TYP;
	if (s == "prewdbeverlist.bvr") return PREWDBEVERLIST_BVR;
	if (s == "prewdbeverlist.grp") return PREWDBEVERLIST_GRP;
	if (s == "prewdbeverlist.own") return PREWDBEVERLIST_OWN;
	if (s == "prewdbeverlist.prj") return PREWDBEVERLIST_PRJ;
	if (s == "prewdbeverlist.ste") return PREWDBEVERLIST_STE;
	if (s == "prewdbevitlist.srf") return PREWDBEVITLIST_SRF;
	if (s == "prewdbevitlist.vec") return PREWDBEVITLIST_VEC;

	return(0);
};

string DbsWdbe::VecVPreset::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	if (ix == PREWDBEADMIN) return("PreWdbeAdmin");
	if (ix == PREWDBEBNKLIST_SRF) return("PreWdbeBnkList.srf");
	if (ix == PREWDBEBNKLIST_UNT) return("PreWdbeBnkList.unt");
	if (ix == PREWDBECMDLIST_RET) return("PreWdbeCmdList.ret");
	if (ix == PREWDBECMDLIST_REU) return("PreWdbeCmdList.reu");
	if (ix == PREWDBECMDLIST_SRF) return("PreWdbeCmdList.srf");
	if (ix == PREWDBECPRLIST_CVR) return("PreWdbeCprList.cvr");
	if (ix == PREWDBECPRLIST_GRP) return("PreWdbeCprList.grp");
	if (ix == PREWDBECPRLIST_OWN) return("PreWdbeCprList.own");
	if (ix == PREWDBECPRLIST_SRF) return("PreWdbeCprList.srf");
	if (ix == PREWDBECPRLIST_TIT) return("PreWdbeCprList.tit");
	if (ix == PREWDBECPRLIST_TYP) return("PreWdbeCprList.typ");
	if (ix == PREWDBECPRMNPERSON_X1) return("PreWdbeCprMNPerson.x1");
	if (ix == PREWDBECVRLIST_BCV) return("PreWdbeCvrList.bcv");
	if (ix == PREWDBECVRLIST_CPR) return("PreWdbeCvrList.cpr");
	if (ix == PREWDBECVRLIST_GRP) return("PreWdbeCvrList.grp");
	if (ix == PREWDBECVRLIST_OWN) return("PreWdbeCvrList.own");
	if (ix == PREWDBECVRLIST_STE) return("PreWdbeCvrList.ste");
	if (ix == PREWDBEERRLIST_RET) return("PreWdbeErrList.ret");
	if (ix == PREWDBEERRLIST_REU) return("PreWdbeErrList.reu");
	if (ix == PREWDBEERRLIST_SRF) return("PreWdbeErrList.srf");
	if (ix == PREWDBEEXTFOLDER) return("PreWdbeExtfolder");
	if (ix == PREWDBEFAMLIST_TIT) return("PreWdbeFamList.tit");
	if (ix == PREWDBEFAMLIST_VND) return("PreWdbeFamList.vnd");
	if (ix == PREWDBEFILLIST_FNM) return("PreWdbeFilList.fnm");
	if (ix == PREWDBEFILLIST_GRP) return("PreWdbeFilList.grp");
	if (ix == PREWDBEFILLIST_OWN) return("PreWdbeFilList.own");
	if (ix == PREWDBEFILLIST_RET) return("PreWdbeFilList.ret");
	if (ix == PREWDBEFILLIST_REU) return("PreWdbeFilList.reu");
	if (ix == PREWDBEFSTLIST_FSM) return("PreWdbeFstList.fsm");
	if (ix == PREWDBEFSTLIST_SRF) return("PreWdbeFstList.srf");
	if (ix == PREWDBEGENLIST_MDL) return("PreWdbeGenList.mdl");
	if (ix == PREWDBEGENLIST_SRF) return("PreWdbeGenList.srf");
	if (ix == PREWDBEGITURL) return("PreWdbeGiturl");
	if (ix == PREWDBEGROUP) return("PreWdbeGroup");
	if (ix == PREWDBEIP) return("PreWdbeIp");
	if (ix == PREWDBEIXBASEREPTYPE) return("PreWdbeIxBasereptype");
	if (ix == PREWDBEIXCRDACCBNK) return("PreWdbeIxCrdaccBnk");
	if (ix == PREWDBEIXCRDACCCMD) return("PreWdbeIxCrdaccCmd");
	if (ix == PREWDBEIXCRDACCCPR) return("PreWdbeIxCrdaccCpr");
	if (ix == PREWDBEIXCRDACCCVR) return("PreWdbeIxCrdaccCvr");
	if (ix == PREWDBEIXCRDACCERR) return("PreWdbeIxCrdaccErr");
	if (ix == PREWDBEIXCRDACCFAM) return("PreWdbeIxCrdaccFam");
	if (ix == PREWDBEIXCRDACCFIL) return("PreWdbeIxCrdaccFil");
	if (ix == PREWDBEIXCRDACCFST) return("PreWdbeIxCrdaccFst");
	if (ix == PREWDBEIXCRDACCGEN) return("PreWdbeIxCrdaccGen");
	if (ix == PREWDBEIXCRDACCLIB) return("PreWdbeIxCrdaccLib");
	if (ix == PREWDBEIXCRDACCMCH) return("PreWdbeIxCrdaccMch");
	if (ix == PREWDBEIXCRDACCMOD) return("PreWdbeIxCrdaccMod");
	if (ix == PREWDBEIXCRDACCMTP) return("PreWdbeIxCrdaccMtp");
	if (ix == PREWDBEIXCRDACCPIN) return("PreWdbeIxCrdaccPin");
	if (ix == PREWDBEIXCRDACCPPH) return("PreWdbeIxCrdaccPph");
	if (ix == PREWDBEIXCRDACCPRC) return("PreWdbeIxCrdaccPrc");
	if (ix == PREWDBEIXCRDACCPRJ) return("PreWdbeIxCrdaccPrj");
	if (ix == PREWDBEIXCRDACCPRS) return("PreWdbeIxCrdaccPrs");
	if (ix == PREWDBEIXCRDACCPRT) return("PreWdbeIxCrdaccPrt");
	if (ix == PREWDBEIXCRDACCRLS) return("PreWdbeIxCrdaccRls");
	if (ix == PREWDBEIXCRDACCSIG) return("PreWdbeIxCrdaccSig");
	if (ix == PREWDBEIXCRDACCSIL) return("PreWdbeIxCrdaccSil");
	if (ix == PREWDBEIXCRDACCSYS) return("PreWdbeIxCrdaccSys");
	if (ix == PREWDBEIXCRDACCTRG) return("PreWdbeIxCrdaccTrg");
	if (ix == PREWDBEIXCRDACCUNT) return("PreWdbeIxCrdaccUnt");
	if (ix == PREWDBEIXCRDACCUSG) return("PreWdbeIxCrdaccUsg");
	if (ix == PREWDBEIXCRDACCUSR) return("PreWdbeIxCrdaccUsr");
	if (ix == PREWDBEIXCRDACCUTL) return("PreWdbeIxCrdaccUtl");
	if (ix == PREWDBEIXCRDACCVAR) return("PreWdbeIxCrdaccVar");
	if (ix == PREWDBEIXCRDACCVEC) return("PreWdbeIxCrdaccVec");
	if (ix == PREWDBEIXCRDACCVER) return("PreWdbeIxCrdaccVer");
	if (ix == PREWDBEIXCRDACCVIT) return("PreWdbeIxCrdaccVit");
	if (ix == PREWDBEIXLCL) return("PreWdbeIxLcl");
	if (ix == PREWDBEIXORD) return("PreWdbeIxOrd");
	if (ix == PREWDBEIXPRE) return("PreWdbeIxPre");
	if (ix == PREWDBEIXRECACC) return("PreWdbeIxRecacc");
	if (ix == PREWDBEJREFNOTIFY) return("PreWdbeJrefNotify");
	if (ix == PREWDBEJREFSESS) return("PreWdbeJrefSess");
	if (ix == PREWDBELIBAMAKEFILE_X1) return("PreWdbeLibAMakefile.x1");
	if (ix == PREWDBELIBAMAKEFILE_X2) return("PreWdbeLibAMakefile.x2");
	if (ix == PREWDBELIBLIST_SRF) return("PreWdbeLibList.srf");
	if (ix == PREWDBEMCHAMAKEFILE_X1) return("PreWdbeMchAMakefile.x1");
	if (ix == PREWDBEMCHAPAR_X1) return("PreWdbeMchAPar.x1");
	if (ix == PREWDBEMCHLIST_SRF) return("PreWdbeMchList.srf");
	if (ix == PREWDBEMCHLIST_SUP) return("PreWdbeMchList.sup");
	if (ix == PREWDBEMODAPAR_X1) return("PreWdbeModAPar.x1");
	if (ix == PREWDBEMODLIST_HKT) return("PreWdbeModList.hkt");
	if (ix == PREWDBEMODLIST_HKU) return("PreWdbeModList.hku");
	if (ix == PREWDBEMODLIST_SRF) return("PreWdbeModList.srf");
	if (ix == PREWDBEMODLIST_SUP) return("PreWdbeModList.sup");
	if (ix == PREWDBEMODLIST_TPL) return("PreWdbeModList.tpl");
	if (ix == PREWDBEMODLIST_TYP) return("PreWdbeModList.typ");
	if (ix == PREWDBEMTPAPAR_X1) return("PreWdbeMtpAPar.x1");
	if (ix == PREWDBEMTPLIST_HKT) return("PreWdbeMtpList.hkt");
	if (ix == PREWDBEMTPLIST_HKU) return("PreWdbeMtpList.hku");
	if (ix == PREWDBEMTPLIST_SRF) return("PreWdbeMtpList.srf");
	if (ix == PREWDBEMTPLIST_TYP) return("PreWdbeMtpList.typ");
	if (ix == PREWDBENOADM) return("PreWdbeNoadm");
	if (ix == PREWDBEOWNER) return("PreWdbeOwner");
	if (ix == PREWDBEPINAPAR_X1) return("PreWdbePinAPar.x1");
	if (ix == PREWDBEPINLIST_BNK) return("PreWdbePinList.bnk");
	if (ix == PREWDBEPINLIST_SRF) return("PreWdbePinList.srf");
	if (ix == PREWDBEPPHAPAR_X1) return("PreWdbePphAPar.x1");
	if (ix == PREWDBEPPHLIST_MDL) return("PreWdbePphList.mdl");
	if (ix == PREWDBEPPHLIST_SRF) return("PreWdbePphList.srf");
	if (ix == PREWDBEPPHLIST_UNT) return("PreWdbePphList.unt");
	if (ix == PREWDBEPRCLIST_MDL) return("PreWdbePrcList.mdl");
	if (ix == PREWDBEPRCLIST_SRF) return("PreWdbePrcList.srf");
	if (ix == PREWDBEPRJLIST_GRP) return("PreWdbePrjList.grp");
	if (ix == PREWDBEPRJLIST_OWN) return("PreWdbePrjList.own");
	if (ix == PREWDBEPRJLIST_SHO) return("PreWdbePrjList.sho");
	if (ix == PREWDBEPRJLIST_TIT) return("PreWdbePrjList.tit");
	if (ix == PREWDBEPRJLIST_VER) return("PreWdbePrjList.ver");
	if (ix == PREWDBEPRJMNPERSON_X1) return("PreWdbePrjMNPerson.x1");
	if (ix == PREWDBEPRSADETAIL_X1) return("PreWdbePrsADetail.x1");
	if (ix == PREWDBEPRSLIST_GRP) return("PreWdbePrsList.grp");
	if (ix == PREWDBEPRSLIST_LNM) return("PreWdbePrsList.lnm");
	if (ix == PREWDBEPRSLIST_OWN) return("PreWdbePrsList.own");
	if (ix == PREWDBEPRSMNCOREPROJECT_X1) return("PreWdbePrsMNCoreproject.x1");
	if (ix == PREWDBEPRSMNPROJECT_X1) return("PreWdbePrsMNProject.x1");
	if (ix == PREWDBEPRTLIST_MDL) return("PreWdbePrtList.mdl");
	if (ix == PREWDBEPRTLIST_SRF) return("PreWdbePrtList.srf");
	if (ix == PREWDBEREFBNK) return("PreWdbeRefBnk");
	if (ix == PREWDBEREFCMD) return("PreWdbeRefCmd");
	if (ix == PREWDBEREFCPR) return("PreWdbeRefCpr");
	if (ix == PREWDBEREFCTR) return("PreWdbeRefCtr");
	if (ix == PREWDBEREFCVR) return("PreWdbeRefCvr");
	if (ix == PREWDBEREFERR) return("PreWdbeRefErr");
	if (ix == PREWDBEREFFAM) return("PreWdbeRefFam");
	if (ix == PREWDBEREFFIL) return("PreWdbeRefFil");
	if (ix == PREWDBEREFFSM) return("PreWdbeRefFsm");
	if (ix == PREWDBEREFFST) return("PreWdbeRefFst");
	if (ix == PREWDBEREFGEN) return("PreWdbeRefGen");
	if (ix == PREWDBEREFIMB) return("PreWdbeRefImb");
	if (ix == PREWDBEREFLIB) return("PreWdbeRefLib");
	if (ix == PREWDBEREFMCH) return("PreWdbeRefMch");
	if (ix == PREWDBEREFMCT) return("PreWdbeRefMct");
	if (ix == PREWDBEREFMDL) return("PreWdbeRefMdl");
	if (ix == PREWDBEREFMIB) return("PreWdbeRefMib");
	if (ix == PREWDBEREFMOD) return("PreWdbeRefMod");
	if (ix == PREWDBEREFMTP) return("PreWdbeRefMtp");
	if (ix == PREWDBEREFPIN) return("PreWdbeRefPin");
	if (ix == PREWDBEREFPPH) return("PreWdbeRefPph");
	if (ix == PREWDBEREFPRC) return("PreWdbeRefPrc");
	if (ix == PREWDBEREFPRJ) return("PreWdbeRefPrj");
	if (ix == PREWDBEREFPRS) return("PreWdbeRefPrs");
	if (ix == PREWDBEREFPRT) return("PreWdbeRefPrt");
	if (ix == PREWDBEREFRLS) return("PreWdbeRefRls");
	if (ix == PREWDBEREFSEL) return("PreWdbeRefSel");
	if (ix == PREWDBEREFSES) return("PreWdbeRefSes");
	if (ix == PREWDBEREFSIG) return("PreWdbeRefSig");
	if (ix == PREWDBEREFSIL) return("PreWdbeRefSil");
	if (ix == PREWDBEREFSYS) return("PreWdbeRefSys");
	if (ix == PREWDBEREFTRG) return("PreWdbeRefTrg");
	if (ix == PREWDBEREFUNI) return("PreWdbeRefUni");
	if (ix == PREWDBEREFUNT) return("PreWdbeRefUnt");
	if (ix == PREWDBEREFUSG) return("PreWdbeRefUsg");
	if (ix == PREWDBEREFUSR) return("PreWdbeRefUsr");
	if (ix == PREWDBEREFVAR) return("PreWdbeRefVar");
	if (ix == PREWDBEREFVEC) return("PreWdbeRefVec");
	if (ix == PREWDBEREFVER) return("PreWdbeRefVer");
	if (ix == PREWDBEREFVIT) return("PreWdbeRefVit");
	if (ix == PREWDBEREPFOLDER) return("PreWdbeRepfolder");
	if (ix == PREWDBERLSLIST_MCH) return("PreWdbeRlsList.mch");
	if (ix == PREWDBERLSLIST_SRF) return("PreWdbeRlsList.srf");
	if (ix == PREWDBERLSLIST_TYP) return("PreWdbeRlsList.typ");
	if (ix == PREWDBERLSLIST_VER) return("PreWdbeRlsList.ver");
	if (ix == PREWDBESESS) return("PreWdbeSess");
	if (ix == PREWDBESIGLIST_CON) return("PreWdbeSigList.con");
	if (ix == PREWDBESIGLIST_MDL) return("PreWdbeSigList.mdl");
	if (ix == PREWDBESIGLIST_MGT) return("PreWdbeSigList.mgt");
	if (ix == PREWDBESIGLIST_MGU) return("PreWdbeSigList.mgu");
	if (ix == PREWDBESIGLIST_SRF) return("PreWdbeSigList.srf");
	if (ix == PREWDBESIGLIST_TYP) return("PreWdbeSigList.typ");
	if (ix == PREWDBESIGLIST_VEC) return("PreWdbeSigList.vec");
	if (ix == PREWDBESILLIST_MDL) return("PreWdbeSilList.mdl");
	if (ix == PREWDBESILLIST_RET) return("PreWdbeSilList.ret");
	if (ix == PREWDBESILLIST_REU) return("PreWdbeSilList.reu");
	if (ix == PREWDBESILLIST_SRF) return("PreWdbeSilList.srf");
	if (ix == PREWDBESILLIST_SYS) return("PreWdbeSilList.sys");
	if (ix == PREWDBESILLIST_TIT) return("PreWdbeSilList.tit");
	if (ix == PREWDBESILLIST_TYP) return("PreWdbeSilList.typ");
	if (ix == PREWDBESUSPSESS) return("PreWdbeSuspsess");
	if (ix == PREWDBESYSDATE) return("PreWdbeSysdate");
	if (ix == PREWDBESYSLIST_SRF) return("PreWdbeSysList.srf");
	if (ix == PREWDBESYSLIST_UNT) return("PreWdbeSysList.unt");
	if (ix == PREWDBESYSLIST_VER) return("PreWdbeSysList.ver");
	if (ix == PREWDBESYSSTAMP) return("PreWdbeSysstamp");
	if (ix == PREWDBESYSTIME) return("PreWdbeSystime");
	if (ix == PREWDBETLAST) return("PreWdbeTlast");
	if (ix == PREWDBETRGLIST_SRF) return("PreWdbeTrgList.srf");
	if (ix == PREWDBETRGLIST_SYS) return("PreWdbeTrgList.sys");
	if (ix == PREWDBETRGLIST_UNT) return("PreWdbeTrgList.unt");
	if (ix == PREWDBEUNTLIST_MDL) return("PreWdbeUntList.mdl");
	if (ix == PREWDBEUNTLIST_RET) return("PreWdbeUntList.ret");
	if (ix == PREWDBEUNTLIST_REU) return("PreWdbeUntList.reu");
	if (ix == PREWDBEUNTLIST_SRF) return("PreWdbeUntList.srf");
	if (ix == PREWDBEUNTLIST_SYS) return("PreWdbeUntList.sys");
	if (ix == PREWDBEUNTLIST_TIT) return("PreWdbeUntList.tit");
	if (ix == PREWDBEUNTLIST_TYP) return("PreWdbeUntList.typ");
	if (ix == PREWDBEUSGAACCESS_X1) return("PreWdbeUsgAAccess.x1");
	if (ix == PREWDBEUSGAACCESS_X2) return("PreWdbeUsgAAccess.x2");
	if (ix == PREWDBEUSGLIST_GRP) return("PreWdbeUsgList.grp");
	if (ix == PREWDBEUSGLIST_OWN) return("PreWdbeUsgList.own");
	if (ix == PREWDBEUSGLIST_SRF) return("PreWdbeUsgList.srf");
	if (ix == PREWDBEUSRAACCESS_X1) return("PreWdbeUsrAAccess.x1");
	if (ix == PREWDBEUSRAACCESS_X2) return("PreWdbeUsrAAccess.x2");
	if (ix == PREWDBEUSRLIST_GRP) return("PreWdbeUsrList.grp");
	if (ix == PREWDBEUSRLIST_OWN) return("PreWdbeUsrList.own");
	if (ix == PREWDBEUSRLIST_PRS) return("PreWdbeUsrList.prs");
	if (ix == PREWDBEUSRLIST_SRF) return("PreWdbeUsrList.srf");
	if (ix == PREWDBEUSRLIST_STE) return("PreWdbeUsrList.ste");
	if (ix == PREWDBEUSRLIST_USG) return("PreWdbeUsrList.usg");
	if (ix == PREWDBEVARLIST_PRC) return("PreWdbeVarList.prc");
	if (ix == PREWDBEVARLIST_SRF) return("PreWdbeVarList.srf");
	if (ix == PREWDBEVECLIST_HKT) return("PreWdbeVecList.hkt");
	if (ix == PREWDBEVECLIST_HKU) return("PreWdbeVecList.hku");
	if (ix == PREWDBEVECLIST_SRF) return("PreWdbeVecList.srf");
	if (ix == PREWDBEVECLIST_TYP) return("PreWdbeVecList.typ");
	if (ix == PREWDBEVERLIST_BVR) return("PreWdbeVerList.bvr");
	if (ix == PREWDBEVERLIST_GRP) return("PreWdbeVerList.grp");
	if (ix == PREWDBEVERLIST_OWN) return("PreWdbeVerList.own");
	if (ix == PREWDBEVERLIST_PRJ) return("PreWdbeVerList.prj");
	if (ix == PREWDBEVERLIST_STE) return("PreWdbeVerList.ste");
	if (ix == PREWDBEVITLIST_SRF) return("PreWdbeVitList.srf");
	if (ix == PREWDBEVITLIST_VEC) return("PreWdbeVitList.vec");

	return("");
};

string DbsWdbe::VecVPreset::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VOID) return("none");
		if (ix == PREWDBEEXTFOLDER) return("extract folder");
		if (ix == PREWDBEGITURL) return("Git URL");
		if (ix == PREWDBEIXBASEREPTYPE) return("base repository type");
		if (ix == PREWDBEREFBNK) return("I/O bank");
		if (ix == PREWDBEREFCMD) return("command");
		if (ix == PREWDBEREFCPR) return("core project");
		if (ix == PREWDBEREFCTR) return("controller");
		if (ix == PREWDBEREFCVR) return("core version");
		if (ix == PREWDBEREFERR) return("error");
		if (ix == PREWDBEREFFAM) return("product family");
		if (ix == PREWDBEREFFIL) return("file");
		if (ix == PREWDBEREFFSM) return("finite state machine");
		if (ix == PREWDBEREFFST) return("FSM state");
		if (ix == PREWDBEREFGEN) return("generic");
		if (ix == PREWDBEREFIMB) return("inter-module buffer");
		if (ix == PREWDBEREFLIB) return("library");
		if (ix == PREWDBEREFMCH) return("machine");
		if (ix == PREWDBEREFMCT) return("controller module");
		if (ix == PREWDBEREFMDL) return("module");
		if (ix == PREWDBEREFMIB) return("inter-module buffer module");
		if (ix == PREWDBEREFMOD) return("module");
		if (ix == PREWDBEREFMTP) return("module template");
		if (ix == PREWDBEREFPIN) return("pin");
		if (ix == PREWDBEREFPPH) return("peripheral");
		if (ix == PREWDBEREFPRC) return("process");
		if (ix == PREWDBEREFPRJ) return("project");
		if (ix == PREWDBEREFPRS) return("person");
		if (ix == PREWDBEREFPRT) return("port");
		if (ix == PREWDBEREFRLS) return("release");
		if (ix == PREWDBEREFSES) return("session");
		if (ix == PREWDBEREFSIG) return("signal");
		if (ix == PREWDBEREFSIL) return("silicon device");
		if (ix == PREWDBEREFSYS) return("system");
		if (ix == PREWDBEREFTRG) return("target");
		if (ix == PREWDBEREFUNI) return("unit");
		if (ix == PREWDBEREFUNT) return("unit");
		if (ix == PREWDBEREFUSG) return("user group");
		if (ix == PREWDBEREFUSR) return("user");
		if (ix == PREWDBEREFVAR) return("variable");
		if (ix == PREWDBEREFVEC) return("vector");
		if (ix == PREWDBEREFVER) return("version");
		if (ix == PREWDBEREFVIT) return("vector item");
		if (ix == PREWDBEREPFOLDER) return("repository folder");
		return(getSref(ix));
	};

	return("");
};

/******************************************************************************
 class DbsWdbe::VecVRecaccess
 ******************************************************************************/

uint DbsWdbe::VecVRecaccess::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "full") return FULL;
	if (s == "none") return NONE;
	if (s == "view") return VIEW;

	return(0);
};

string DbsWdbe::VecVRecaccess::getSref(
			const uint ix
		) {
	if (ix == FULL) return("full");
	if (ix == NONE) return("none");
	if (ix == VIEW) return("view");

	return("");
};

string DbsWdbe::VecVRecaccess::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == FULL) return("full");
		if (ix == NONE) return("none");
		if (ix == VIEW) return("view");
		return(getSref(ix));
	};

	return("");
};

void DbsWdbe::VecVRecaccess::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DbsWdbe::VecVUserlevel
 ******************************************************************************/

uint DbsWdbe::VecVUserlevel::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "adm") return ADM;
	if (s == "gadm") return GADM;
	if (s == "reg") return REG;
	if (s == "vtor") return VTOR;

	return(0);
};

string DbsWdbe::VecVUserlevel::getSref(
			const uint ix
		) {
	if (ix == ADM) return("adm");
	if (ix == GADM) return("gadm");
	if (ix == REG) return("reg");
	if (ix == VTOR) return("vtor");

	return("");
};

string DbsWdbe::VecVUserlevel::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == ADM) return("administrator");
		if (ix == GADM) return("user group administrator");
		if (ix == REG) return("regular user");
		if (ix == VTOR) return("visitor");
		return(getSref(ix));
	};

	return("");
};

void DbsWdbe::VecVUserlevel::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWdbeVLocale));
};

/******************************************************************************
 class DbsWdbe::VecVValuelist
 ******************************************************************************/

uint DbsWdbe::VecVValuelist::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "vlstwdbeumpersontitle") return VLSTWDBEUMPERSONTITLE;

	return(0);
};

string DbsWdbe::VecVValuelist::getSref(
			const uint ix
		) {
	if (ix == VLSTWDBEUMPERSONTITLE) return("VlstWdbeUMPersonTitle");

	return("");
};

string DbsWdbe::VecVValuelist::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == VLSTWDBEUMPERSONTITLE) return("title");
		return(getSref(ix));
	};

	return("");
};

/******************************************************************************
 class DbsWdbe::VecWAccess
 ******************************************************************************/

uint DbsWdbe::VecWAccess::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "edit") ix |= EDIT;
		else if (ss[i] == "exec") ix |= EXEC;
		else if (ss[i] == "view") ix |= VIEW;
	};

	return(ix);
};

void DbsWdbe::VecWAccess::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VIEW); i *= 2) if (ix & i) ics.insert(i);
};

string DbsWdbe::VecWAccess::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & EDIT) ss.push_back("edit");
	if (ix & EXEC) ss.push_back("exec");
	if (ix & VIEW) ss.push_back("view");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string DbsWdbe::VecWAccess::getTitle(
			const uint ix
			, const uint ixWdbeVLocale
		) {
	if (ixWdbeVLocale == 1) {
		if (ix == EDIT) return("edit");
		if (ix == EXEC) return("execute");
		if (ix == VIEW) return("view");
		return(getSrefs(ix));
	};

	return("");
};

void DbsWdbe::VecWAccess::fillFeed(
			const uint ixWdbeVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= VIEW; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWdbeVLocale));
};
