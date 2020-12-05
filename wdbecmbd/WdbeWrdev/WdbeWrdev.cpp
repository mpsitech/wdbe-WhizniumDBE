/**
	* \file WdbeWrdev.cpp
	* Wdbe operation pack global code (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeWrdev.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbeWrdev
 ******************************************************************************/

// IP cust --- IBEGIN
void WdbeWrdev::writeVecH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMVector* vec
			, WdbeMSystem* sys
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, const bool subclass
			, const unsigned int subil
		) {
	ListWdbeMVectoritem vits;
	string supsref, subsref;
	bool tix, ns;
	bool notit, cmt, appfed, filfed;
	string ixtype, ixvar;
	string clsnstype;

	WdbeMVectoritem* vit = NULL;

	string indent, pre;

	analyzeVec(dbswdbe, vec, sys, unt, ctr, subclass, vits, supsref, subsref, tix, ns, notit, cmt, appfed, filfed, ixtype, ixvar, clsnstype);
	ixtype = "Sbecore::" + ixtype;

	if (subclass) for (unsigned int i = 0; i < subil;i++) indent += "\t";

	pre = indent + "\t";
	if (!ns) pre += "static ";

	outfile << indent << "/**" << endl;
	if (subclass) outfile << indent << "\t* " << subsref << " (full: " << vec->sref << ")" << endl;
	else outfile << "\t* " << vec->sref << endl;
	outfile << indent << "\t*/" << endl;

	if (subclass) {
		outfile << indent << clsnstype << " " << subsref << " {" << endl;
		if (!ns) {
			outfile << endl;
			outfile << indent << "public:" << endl;
		};

	} else {
		outfile << clsnstype << " " << vec->sref << " {" << endl;
	};

	for (unsigned int i = 0; i < vits.nodes.size(); i++) {
		vit = vits.nodes[i];

		outfile << pre << "const " << ixtype <<  " " << getVitConst(vit, tix) << " = ";
		if (tix) outfile << "0x" << Wdbe::binToHex(vit->vecNum) << ";" << endl;
		else outfile << vit->vecNum << ";" << endl;
	};
	outfile << endl;

	// getIx/getTix
	outfile << pre << ixtype << " get" << StrMod::cap(ixvar) << "(const std::string& sref);" << endl;

	// getSref
	outfile << pre << "std::string getSref(const " << ixtype << " " << ixvar << ");" << endl;

	if (!notit || cmt) {
		outfile << endl;

		// getTitle
		if (!notit) outfile << pre << "std::string getTitle(const " << ixtype << " " << ixvar << ");" << endl;

		// getComment
		if (cmt) outfile << pre << "std::string getComment(const " << ixtype << " " << ixvar << ");" << endl;
	};

	if (appfed || filfed) {
		outfile << endl;

		// appendToFeed
		if (appfed) outfile << pre << "void appendToFeed(const " << ixtype << " " << ixvar << ", Sbecore::Xmlio::Feed& feed);" << endl;

		// fillFeed
		if (filfed) outfile << pre << "void fillFeed(Sbecore::Xmlio::Feed& feed);" << endl;
	};

	if (subclass) outfile << indent;
	outfile << "};" << endl;

	outfile << endl;
};

void WdbeWrdev::writeVecCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMVector* vec
			, WdbeMSystem* sys
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, const bool subclass
		) {
	ListWdbeMVectoritem vits;
	string supsref, subsref;
	bool tix, ns;
	bool notit, cmt, appfed, filfed;
	string ixtype, ixvar;
	string clsnstype;

	WdbeMVectoritem* vit = NULL;

	unsigned int cnt;

	analyzeVec(dbswdbe, vec, sys, unt, ctr, subclass, vits, supsref, subsref, tix, ns, notit, cmt, appfed, filfed, ixtype, ixvar, clsnstype);

	outfile << "/******************************************************************************" << endl;
	outfile << " " << clsnstype << " ";
	if (subclass) outfile << supsref << "::" << subsref << endl;
	else outfile << vec->sref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	// getIx/getTix
	outfile << ixtype << " ";
	if (subclass) outfile << supsref << "::" << subsref;
	else outfile << vec->sref;
	outfile << "::get" << StrMod::cap(ixvar) << "(" << endl;
	outfile << "\t\t\tconst string& sref" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\tstring s = StrMod::lc(sref);" << endl;
	outfile << endl;

	for (unsigned int i = 0; i < vits.nodes.size(); i++) {
		vit = vits.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "else ";
		outfile << "if (s == \"" << StrMod::lc(vit->sref) << "\") return " << getVitConst(vit, tix) << ";" << endl;
	};
	outfile << endl;

	outfile << "\treturn(0);" << endl;
	outfile << "};" << endl;
	outfile << endl;

	// getSref
	outfile << "string ";
	if (subclass) outfile << supsref << "::" << subsref;
	else outfile << vec->sref;
	outfile << "::getSref(" << endl;
	outfile << "\t\t\tconst " << ixtype << " " << ixvar << endl;
	outfile << "\t\t) {" << endl;

	for (unsigned int i = 0; i < vits.nodes.size(); i++) {
		vit = vits.nodes[i];

		outfile << "\t";
		if (i != 0) outfile << "else ";
		outfile << "if (" << ixvar << " == " << getVitConst(vit, tix) << ") return(\"" << vit->sref << "\");" << endl;
	};
	outfile << endl;

	outfile << "\treturn(\"\");" << endl;
	outfile << "};" << endl;
	outfile << endl;

	if (!notit) {
		// getTitle
		outfile << "string ";
		if (subclass) outfile << supsref << "::" << subsref;
		else outfile << vec->sref;
		outfile << "::getTitle(" << endl;
		outfile << "\t\t\tconst " << ixtype << " " << ixvar << endl;
		outfile << "\t\t) {" << endl;

		cnt = 0;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			if (vit->Title.length() != 0) {
				outfile << "\t";
				if (cnt > 0) outfile << "else ";
				outfile << "if (" << ixvar << " == " << getVitConst(vit, tix) << ") return(\"" << StrMod::esc(vit->Title) << "\");" << endl;

				cnt++;
			};
		};

		if (cnt == 0) outfile << "\treturn(getSref(" << ixvar << "));" << endl;
		else if (vits.nodes.size() != cnt) outfile << "\telse return(getSref(" << ixvar << "));" << endl;

		outfile << endl;
		outfile << "\treturn(\"\");" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (cmt) {
		// getComment
		outfile << "string ";
		if (subclass) outfile << supsref << "::" << subsref;
		else outfile << vec->sref;
		outfile << "::getComment(" << endl;
		outfile << "\t\t\tconst " << ixtype << " " << ixvar << endl;
		outfile << "\t\t) {" << endl;

		cnt = 0;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			if (vit->Comment.length() != 0) {
				outfile << "\t";
				if (cnt > 0) outfile << "else ";
				outfile << "if (" << ixvar << " == " << getVitConst(vit, tix) << ") return(\"" << StrMod::esc(vit->Comment) << "\");" << endl;

				cnt++;
			};
		};

		outfile << endl;
		outfile << "\treturn(\"\");" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (appfed) {
		// appendToFeed
		outfile << "void ";
		if (subclass) outfile << supsref << "::" << subsref;
		else outfile << vec->sref;
		outfile << "::appendToFeed(" << endl;
		outfile << "\t\t\tconst " << ixtype << " " << ixvar << endl;
		outfile << "\t\t\t, Feed& feed" << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tfeed.appendIxSrefTitles(ix, getSref(" << ixvar << ")";
		if (!notit) outfile << ", getTitle(" << ixvar << ")";
		else outfile << ", getSref(" << ixvar << ")";
		outfile << ");" << endl;

		outfile << "};" << endl;
		outfile << endl;
	};

	// fillFeed
	if (filfed) {
		outfile << "void ";
		if (subclass) outfile << supsref << "::" << subsref;
		else outfile << vec->sref;
		outfile << "::fillFeed(" << endl;
		outfile << "\t\t\tFeed& feed" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\tfeed.clear();" << endl;

		if (vits.nodes.size() > 0) {
			outfile << endl;

			outfile << "\tstd::set<" << ixtype << "> items = {";
			for (unsigned int i = 0; i < vits.nodes.size(); i++) {
				vit = vits.nodes[i];

				if (i != 0) outfile << ",";
				outfile << getVitConst(vit, tix);
			};
			outfile << "};" << endl;
			outfile << endl;

			outfile << "\tfor (auto it = items.begin(); it != items.end(); it++) ";

			outfile << "feed.appendIxSrefTitles(*it";
			outfile << ", getSref(*it)";
			if (!notit) outfile << ", getTitle(*it)";
			else outfile << ", getSref(*it)";
			outfile << ");" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;
	};
};

void WdbeWrdev::analyzeVec(
			DbsWdbe* dbswdbe
			, WdbeMVector* vec
			, WdbeMSystem* sys
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, const bool subclass
			, ListWdbeMVectoritem& vits
			, string& supsref
			, string& subsref
			, bool& tix
			, bool& ns
			, bool& notit
			, bool& cmt
			, bool& appfed
			, bool& filfed
			, string& ixtype
			, string& ixvar
			, string& clsnstype
		) {
	dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

	if (subclass) getVecSupsubsref(vec, sys, unt, ctr, supsref, subsref);

	tix = ((vec->ixVBasetype == VecWdbeVMVectorBasetype::TIXLIN) || (vec->ixVBasetype == VecWdbeVMVectorBasetype::TIXOR));
	ns = !subclass;

	notit = StrMod::srefInSrefs(vec->srefsKOption, "notit");
	cmt = StrMod::srefInSrefs(vec->srefsKOption, "cmt");
	appfed = StrMod::srefInSrefs(vec->srefsKOption, "appfed");
	filfed = StrMod::srefInSrefs(vec->srefsKOption, "filfed");

	if (tix) {
		ixtype = "utinyint";
		ixvar = "tix";
	} else {
		ixtype = "uint";
		ixvar = "ix";
	};

	if (ns) clsnstype = "namespace";
	else clsnstype = "class";
};

void WdbeWrdev::getVecSupsubsref(
			WdbeMVector* vec
			, WdbeMSystem* sys
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, string& supsref
			, string& subsref
		) {
	string s;
	size_t ptr;

	supsref = "";
	subsref = vec->sref;

	if (ctr) {
		// ex. VecVIdhwIcm2RoicBias -> CtrIdhwIcm2Roic::VecVBias
		supsref = ctr->Fullsref;

		ptr = subsref.find(supsref.substr(3));
		if (ptr != string::npos) subsref = subsref.substr(0, ptr) + subsref.substr(ptr + supsref.length()-3);

	} else if (unt) {
		// ex. VecWIdhwIcm2Buffer -> UntIdhwIcm2::VecWBuffer
		// however, generally subclass not used

	} else if (sys) {
		// ex. VecVSysIdhwBasys2fwdTarget -> SysIdhwBasys2fwd::VecVTarget
		supsref = sys->sref;

		ptr = subsref.find(supsref);
		if (ptr != string::npos) subsref = subsref.substr(0, ptr) + subsref.substr(ptr + supsref.length());

	};
};

string WdbeWrdev::getVitConst(
			WdbeMVectoritem* vit
			, const bool tix
		) {
	if (tix) return StrMod::uc(StrMod::uscToCap(StrMod::dotToUsc(vit->sref)));
	else return StrMod::uc(StrMod::dotToUsc(vit->sref));
};

void WdbeWrdev::writeSpeccmdH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMCommand* cmd
			, ListWdbeAMCommandRetpar& rpas
			, const string& supsref
			, const string& subsref
		) {
	WdbeAMCommandRetpar* rpa = NULL;

	outfile << "\t/**" << endl;
	outfile << "\t\t* " << subsref << " (full: " << cmd->Fullsref << ")" << endl;
	outfile << "\t\t*/" << endl;
	outfile << "\tclass " << subsref << " : public Dbecore::Cmd {" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	outfile << "\t\t" << subsref << "();" << endl;
	outfile << endl;
	
	outfile << "\tpublic:" << endl;
	outfile << "\t\tvoid (*returnSpeccallback)(Dbecore::Cmd* cmd, void* arg";
	for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
		rpa = rpas.nodes[i];
		wrIparpa(outfile, rpa->sref, rpa->ixWdbeVPartype, false, false, true, true, false, false);
	};
	outfile << ");" << endl;
	outfile << "\t\tvoid* argReturnSpeccallback;" << endl;
	outfile << endl;

	outfile << "\tpublic:" << endl;
	outfile << "\t\tvoid setReturnSpeccallback(void (*_returnSpeccallback)(Dbecore::Cmd* cmd, void* arg";
	for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
		rpa = rpas.nodes[i];
		wrIparpa(outfile, rpa->sref, rpa->ixWdbeVPartype, false, false, true, true, false, false);
	};
	outfile << "), void* _argReturnSpeccallback);" << endl;
	outfile << "\t\tvoid returnToCallback();" << endl;
	outfile << "\t};" << endl;
	outfile << endl;
};

void WdbeWrdev::writeSpeccmdCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const utinyint tixCtr
			, WdbeMCommand* cmd
			, ListWdbeAMCommandRetpar& rpas
			, const string& supsref
			, const string& subsref
		) {
	WdbeAMCommandRetpar* rpa = NULL;

	outfile << "/******************************************************************************" << endl;
	outfile << " class " << supsref << "::" << subsref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	outfile << supsref << "::" << subsref << "::" << subsref << "() :" << endl;
	outfile << "\t\t\tCmd(";
	if (cmd->refIxVTbl == VecWdbeVMCommandRefTbl::CTR) outfile << "0x" << Wdbe::binToHex(tixCtr) << ", VecVCommand";
	else outfile << "VecV" << supsref.substr(3) << "Command";
	outfile << "::" << StrMod::uc(cmd->sref) << ", Cmd::VecVRettype::" << StrMod::uc(VecWdbeVMCommandRettype::getSref(cmd->ixVRettype)) << ")" << endl;
	outfile << "\t\t{" << endl;
	outfile << "\treturnSpeccallback = NULL;" << endl;
	outfile << "\targReturnSpeccallback = NULL;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	outfile << "void " << supsref << "::" << subsref << "::setReturnSpeccallback(" << endl;

	outfile << "\t\t\tvoid (*_returnSpeccallback)(Cmd* cmd, void* arg";
	for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
		rpa = rpas.nodes[i];
		wrIparpa(outfile, rpa->sref, rpa->ixWdbeVPartype, false, false, true, false, false, false);
	};
	outfile << ")" << endl;
	outfile << "\t\t\t, void* _argReturnSpeccallback" << endl;
	outfile << "\t\t) {" << endl;
	outfile << "\treturnSpeccallback = _returnSpeccallback;" << endl;
	outfile << "\targReturnSpeccallback = _argReturnSpeccallback;" << endl;
	outfile << "};" << endl;
	outfile << endl;

	outfile << "void " << supsref << "::" << subsref << "::returnToCallback() {" << endl;
	outfile << "\tif (returnCallback) returnCallback(this, argReturnCallback);" << endl;
	outfile << "\tif (returnSpeccallback) returnSpeccallback(this, argReturnSpeccallback";
	for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
		rpa = rpas.nodes[i];
		writeSpeccmdCpp_getrpa(outfile, rpa);
	};
	outfile << ");" << endl;
	outfile << "};" << endl;
	outfile << endl;
};

void WdbeWrdev::writeSpeccmdCpp_getrpa(
			fstream& outfile
			, WdbeAMCommandRetpar* rpa
		) {
	outfile << ", parsRet[\"" << rpa->sref << "\"].get";
	if (rpa->ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << "Bool";
	else {
		// TIX, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BLOB, VBLOB
		outfile << StrMod::cap(VecWdbeVPartype::getSref(rpa->ixWdbeVPartype));
	};
	outfile << "()";

	if ((rpa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) {
		outfile << ", parsRet[\"" << rpa->sref << "\"].getLen()";
	};
};

void WdbeWrdev::writeCmdH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const bool Easy
			, WdbeMCommand* cmd
			, ListWdbeAMCommandInvpar& ipas
			, ListWdbeAMCommandRetpar& rpas
			, const string& supsref
			, const string& subsref
		) {
	WdbeAMCommandInvpar* ipa = NULL;
	WdbeAMCommandRetpar* rpa = NULL;

	if (Easy) {
		outfile << "\tstatic Dbecore::Cmd* getNewCmd" << StrMod::cap(cmd->sref) << "();" << endl;

		outfile << "\tvoid " << cmd->sref << "(";
		for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
			ipa = ipas.nodes[i];
			wrIparpa(outfile, ipa->sref, ipa->ixWdbeVPartype, (i == 0), false, false, true, false, false);
		};
		for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
			rpa = rpas.nodes[i];
			wrIparpa(outfile, rpa->sref, rpa->ixWdbeVPartype, ((ipas.nodes.size() == 0) && (i == 0)), false, true, true, false, false);
		};
		outfile << ");" << endl;

	} else {
		outfile << "\tstatic ";
		if (rpas.nodes.size() > 0) outfile << subsref;
		else outfile << "Dbecore::Cmd";
		outfile << "* getNewCmd" << StrMod::cap(cmd->sref) << "(";
		for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
			ipa = ipas.nodes[i];
			wrIparpa(outfile, ipa->sref, ipa->ixWdbeVPartype, (i==0), false, false, true, false, false);
		};
		outfile << ");" << endl;

		if ((cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) || (cmd->ixVRettype == VecWdbeVMCommandRettype::STATSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG)) {
			outfile << "\tvoid " << cmd->sref << "(";
			for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
				ipa = ipas.nodes[i];
				wrIparpa(outfile, ipa->sref, ipa->ixWdbeVPartype, (i == 0), false, false, true, false, false);
			};
			for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
				rpa = rpas.nodes[i];
				wrIparpa(outfile, rpa->sref, rpa->ixWdbeVPartype, ((ipas.nodes.size() == 0) && (i == 0)), false, true, true, false, false);
			};
			if ((ipas.nodes.size() > 0) || (rpas.nodes.size() > 0)) outfile << ", ";
			outfile << "const unsigned int to = 0";
			outfile << ");" << endl;
		};
	};

	outfile << endl;
};

void WdbeWrdev::writeCmdCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const bool Easy
			, const utinyint tixCtr
			, const string& srefCtr
			, const bool hasvecerr
			, WdbeMCommand* cmd
			, ListWdbeAMCommandInvpar& ipas
			, ListWdbeAMCommandRetpar& rpas
			, const string& supsref
			, const string& subsref
		) {
	WdbeAMCommandInvpar* ipa = NULL;
	WdbeAMCommandRetpar* rpa = NULL;

	if (Easy) {
		outfile << "Cmd* " << supsref << "::getNewCmd" << StrMod::cap(cmd->sref) << "() {" << endl;

		outfile << "\tCmd* cmd = new Cmd(";
		if (cmd->refIxVTbl == VecWdbeVMCommandRefTbl::CTR) outfile << "0x" << Wdbe::binToHex(tixCtr) << ", VecVCommand";
		else outfile << "VecV" << supsref.substr(3) << "Command";
		outfile << "::" << StrMod::uc(cmd->sref) << ", Cmd::VecVRettype::" << StrMod::uc(VecWdbeVMCommandRettype::getSref(cmd->ixVRettype)) << ");" << endl;
		outfile << endl;

		if (ipas.nodes.size() > 0) {
			for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
				ipa = ipas.nodes[i];
				wrAddpar(dbswdbe, outfile, ipa->sref, ipa->ixWdbeVPartype, ipa->refWdbeMVector, ipa->Length, false, false);
			};
			outfile << endl;
		};

		if (rpas.nodes.size() > 0) {
			for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
				rpa = rpas.nodes[i];
				wrAddpar(dbswdbe, outfile, rpa->sref, rpa->ixWdbeVPartype, rpa->refWdbeMVector, rpa->Length, false, true);
			};
			outfile << endl;
		};

		outfile << "\treturn cmd;" << endl;
		outfile << "};" << endl;
		outfile << endl;

		outfile << "void " << supsref << "::" << cmd->sref << "(" << endl;
		for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
			ipa = ipas.nodes[i];
			wrIparpa(outfile, ipa->sref, ipa->ixWdbeVPartype, (i == 0), true, false, false, false, false);
		};
		for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
			rpa = rpas.nodes[i];
			wrIparpa(outfile, rpa->sref, rpa->ixWdbeVPartype, ((ipas.nodes.size() == 0) && (i == 0)), true, true, false, false, false);
		};
		outfile << "\t\t) {" << endl;
		outfile << "\tCmd* cmd = getNewCmd" << StrMod::cap(cmd->sref) << "();" << endl;
		outfile << endl;

		if (ipas.nodes.size() > 0) {
			for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
				ipa = ipas.nodes[i];
				writeCmdCpp_setipa(outfile, ipa);
			};
			outfile << endl;
		};

		if (cmd->refIxVTbl == VecWdbeVMCommandRefTbl::UNT) outfile << "\tif (unt->runCmd(cmd)) {" << endl;
		else outfile << "\tif (unt->runCmd(cmd)) {" << endl;
		for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
			rpa = rpas.nodes[i];
			writeCmdCpp_getrpa(outfile, rpa);
		};
		outfile << "\t} else {" << endl;
		outfile << "\t\tdelete cmd;" << endl;
		outfile << "\t\tthrow DbeException(\"error running " << cmd->sref << "\");" << endl;
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\tdelete cmd;" << endl;
		outfile << "};" << endl;
		outfile << endl;

	} else {
		if (rpas.nodes.size() > 0) outfile << supsref << "::" << subsref;
		else outfile << "Cmd";
		outfile << "* " << supsref << "::getNewCmd" << StrMod::cap(cmd->sref) << "(";
		if (ipas.nodes.size() > 0) {
			outfile << endl;
			for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
				ipa = ipas.nodes[i];
				wrIparpa(outfile, ipa->sref, ipa->ixWdbeVPartype, (i==0), true, false, false, false, false);
			};
			outfile << "\t\t";
		};
		outfile << ") {" << endl;

		outfile << "\t";
		if (rpas.nodes.size() > 0) outfile << subsref;
		else outfile << "Cmd";
		outfile << "* cmd = new ";
		if (rpas.nodes.size() > 0) outfile << subsref << "();" << endl;
		else {
			outfile << "Cmd(";
			if (cmd->refIxVTbl == VecWdbeVMCommandRefTbl::CTR) outfile << "0x" << Wdbe::binToHex(tixCtr) << ", VecVCommand";
			else outfile << "VecV" << supsref.substr(3) << "Command";
			outfile << "::" << StrMod::uc(cmd->sref) << ", Cmd::VecVRettype::" << StrMod::uc(VecWdbeVMCommandRettype::getSref(cmd->ixVRettype)) << ");" << endl;
		};
		outfile << endl;

		if (ipas.nodes.size() > 0) {
			for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
				ipa = ipas.nodes[i];
				wrAddpar(dbswdbe, outfile, ipa->sref, ipa->ixWdbeVPartype, ipa->refWdbeMVector, ipa->Length, false, false);
			};
			outfile << endl;

			for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
				ipa = ipas.nodes[i];
				writeCmdCpp_setipa(outfile, ipa);
			};
			outfile << endl;
		};

		if (rpas.nodes.size() > 0) {
			for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
				rpa = rpas.nodes[i];
				wrAddpar(dbswdbe, outfile, rpa->sref, rpa->ixWdbeVPartype, rpa->refWdbeMVector, rpa->Length, false, true);
			};
			outfile << endl;
		};

		outfile << "\treturn cmd;" << endl;
		outfile << "};" << endl;
		outfile << endl;

		if ((cmd->ixVRettype == VecWdbeVMCommandRettype::VOID) || (cmd->ixVRettype == VecWdbeVMCommandRettype::STATSNG) || (cmd->ixVRettype == VecWdbeVMCommandRettype::IMMSNG)) {
			outfile << "void " << supsref << "::" << cmd->sref << "(" << endl;
			for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
				ipa = ipas.nodes[i];
				wrIparpa(outfile, ipa->sref, ipa->ixWdbeVPartype, (i == 0), true, false, false, false, false);
			};
			for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
				rpa = rpas.nodes[i];
				wrIparpa(outfile, rpa->sref, rpa->ixWdbeVPartype, ((ipas.nodes.size() == 0) && (i == 0)), true, true, false, false, false);
			};
			outfile << "\t\t\t";
			if ((ipas.nodes.size() != 0) || (rpas.nodes.size() != 0)) outfile << ", ";
			outfile << "const unsigned int to" << endl;
			outfile << "\t\t) {" << endl;

			outfile << "\tstring msg;" << endl;
			outfile << endl;

			outfile << "\tCmd* cmd = getNewCmd" << StrMod::cap(cmd->sref) << "(";
			for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
				ipa = ipas.nodes[i];

				if (i != 0) outfile << ", ";
				outfile << ipa->sref;
				if ((ipa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) outfile << ", " << ipa->sref << "len";
			};
			outfile << ");" << endl;
			outfile << endl;

			outfile << "\tcmd->ixVTarget = ixVTarget;" << endl;
			outfile << "\tcmd->uref = uref;" << endl;
			outfile << endl;

			outfile << "\txchg->runCmd(cmd, to);" << endl;
			outfile << endl;

			outfile << "\tif (cmd->err.tixDbeVAction != 0x00) msg = cmd->err.getMessage(\"" << srefCtr << "\", \"" << cmd->sref << "\", cmd->cref";
			if (hasvecerr) outfile << ", VecVError::getSref(cmd->err.tixVError), VecVError::getTitle(cmd->err.tixVError)";
			else outfile << ", \"\", \"\"";
			outfile << ", true, true);" << endl;
			if (rpas.nodes.size() > 0) {
				outfile << "\telse {" << endl;
				for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
					rpa = rpas.nodes[i];
					writeCmdCpp_getrpa(outfile, rpa);
				};
				outfile << "\t};" << endl;
			};

			outfile << "\tdelete cmd;" << endl;
			outfile << endl;

			outfile << "\tif (msg != \"\") throw(DbeException(msg));" << endl;
			outfile << "};" << endl;
			outfile << endl;
		};
	};
};


void WdbeWrdev::writeCmdCpp_setipa(
			fstream& outfile
			, WdbeAMCommandInvpar* ipa
		) {
	outfile << "\tcmd->parsInv[\"" << ipa->sref << "\"].set";
	if (ipa->ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << "Bool";
	else outfile << StrMod::cap(VecWdbeVPartype::getSref(ipa->ixWdbeVPartype));
	outfile << "(" << ipa->sref;
	if ((ipa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) outfile << ", " << ipa->sref << "len";
	outfile << ");" << endl;
};

void WdbeWrdev::writeCmdCpp_getrpa(
			fstream& outfile
			, WdbeAMCommandRetpar* rpa
		) {
	outfile << "\t\t" << rpa->sref << " = cmd->parsRet[\"" << rpa->sref << "\"].get";
	if (rpa->ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << "Bool";
	else {
		// TIX, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT, BLOB, VBLOB
		outfile << StrMod::cap(VecWdbeVPartype::getSref(rpa->ixWdbeVPartype));
	};
	outfile << "();" << endl;

	if ((rpa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) {
		outfile << "\t\t" << rpa->sref << "len = cmd->parsRet[\"" << rpa->sref << "\"].getLen();" << endl;
	};
};

void WdbeWrdev::writeErrH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMError* err
		) {
	outfile << "\tstatic Dbecore::Err getNewErr" << StrMod::cap(err->sref) << "();" << endl;
};

void WdbeWrdev::writeErrCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMError* err
			, ListWdbeAMErrorPar& epas
			, const string& supsref
			, const string& subsref
		) {
	WdbeAMErrorPar* epa = NULL;

	outfile << "Err " << supsref << "::getNewErr" << StrMod::cap(err->sref) << "() {" << endl;
	outfile << "\tErr err(VecDbeVAction::ERR, VecVError::" << StrMod::uc(err->sref) << ");" << endl;
	outfile << endl;

	if (epas.nodes.size() > 0) {
		for (unsigned int i = 0; i < epas.nodes.size(); i++) {
			epa = epas.nodes[i];
			wrAddpar(dbswdbe, outfile, epa->sref, epa->ixWdbeVPartype, epa->refWdbeMVector, epa->Length, true, false);
		};
		outfile << endl;
	};

	outfile << "\treturn err;" << endl;
	outfile << "};" << endl;
	outfile << endl;
};

void WdbeWrdev::wrAddpar(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const string& sref
			, const uint ixWdbeVPartype
			, const ubigint refWdbeMVector
			, const utinyint Length
			, const bool errNotCmd
			, const bool retNotInv
		) {
	WdbeMVector* vec = NULL;

	WdbeMController* ctr = NULL;
	string supsref, subsref;

	if (errNotCmd) outfile << "\terr.addPar";
	else if (retNotInv) outfile << "\tcmd->addParRet";
	else outfile << "\tcmd->addParInv";
	outfile << "(\"" << sref << "\", Par::VecVType::" << StrMod::uc(VecWdbeVPartype::getSref(ixWdbeVPartype));

	if (ixWdbeVPartype == VecWdbeVPartype::TIX) {
		if (dbswdbe->tblwdbemvector->loadRecByRef(refWdbeMVector, &vec)) {
			if (vec->hkIxVTbl == VecWdbeVMVectorHkTbl::CTR) dbswdbe->tblwdbemcontroller->loadRecByRef(vec->hkUref, &ctr);
			getVecSupsubsref(vec, NULL, NULL, ctr, supsref, subsref);
			if (ctr) delete ctr;

			if (supsref != "") {
				outfile << ", " << supsref << "::" << subsref << "::getTix";
				outfile << ", " << supsref << "::" << subsref << "::getSref";
				outfile << ", " << supsref << "::" << subsref << "::fillFeed";
			} else {
				outfile << ", " << subsref << "::getTix";
				outfile << ", " << subsref << "::getSref";
				outfile << ", " << subsref << "::fillFeed";
			};

			delete vec;
		};

	} else if ((ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ixWdbeVPartype == VecWdbeVPartype::VBLOB)) {
		outfile << ", NULL, NULL, NULL, " << to_string(Length);
	};

	outfile << ");" << endl;
};

void WdbeWrdev::wrIparpa(
			fstream& outfile
			, const string& sref
			, const uint ixWdbeVPartype
			, const bool first
			, const bool newline
			, const bool refNotConst
			, const bool ns
			, const bool init
			, const bool len
		) {
	if (newline) outfile << "\t\t\t";
	if (!first) outfile << ", ";
	if (!refNotConst) outfile << "const ";

	if (ns) if ( (ixWdbeVPartype == VecWdbeVPartype::TIX) || (ixWdbeVPartype == VecWdbeVPartype::TINYINT) || (ixWdbeVPartype == VecWdbeVPartype::UTINYINT)
				|| (ixWdbeVPartype == VecWdbeVPartype::SMALLINT) || (ixWdbeVPartype == VecWdbeVPartype::USMALLINT) || (ixWdbeVPartype == VecWdbeVPartype::UINT) ) outfile << "Sbecore::";

	if (ixWdbeVPartype == VecWdbeVPartype::TIX) outfile << "utinyint";
	else if (ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << "bool";
	else if ((ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ixWdbeVPartype == VecWdbeVPartype::VBLOB)) {
		if (len) outfile << "size_t";
		else outfile << "unsigned char*";
	} else {
		// TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT
		outfile << VecWdbeVPartype::getSref(ixWdbeVPartype);
	};

	if (refNotConst) outfile << "&";

	outfile << " " << sref;
	if (((ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ixWdbeVPartype == VecWdbeVPartype::VBLOB)) && len) outfile << "len";

	if (init) {
		if (ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << " = false";
		else if ((ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ixWdbeVPartype == VecWdbeVPartype::VBLOB)) {
			if (len) outfile << " = 0";
			else outfile << " = NULL";
		} else {
			// TIX, TINYINT, UTINYINT, SMALLINT, USMALLINT, INT, UINT
			outfile << " = 0";
		};
	};

	if (newline) outfile << endl;
	
	if (((ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ixWdbeVPartype == VecWdbeVPartype::VBLOB)) && !len) wrIparpa(outfile, sref, ixWdbeVPartype, false, newline, refNotConst, ns, init, true);
};
// IP cust --- IEND



