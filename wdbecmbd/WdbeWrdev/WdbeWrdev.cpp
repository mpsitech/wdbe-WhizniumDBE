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

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeWrdev
 ******************************************************************************/

// IP cust --- IBEGIN
void WdbeWrdev::writeVecH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMVector* vec
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, WdbeMCommand* cmd
			, const bool subclass
			, const unsigned int subil
		) {
	ListWdbeMVectoritem vits;
	string supsref, subsref;
	bool lin, tix, ns;
	bool notit, cmt, appfed, filfed;
	string ixtype, ixvar, icsvar;
	string clsnstype;

	WdbeMVectoritem* vit = NULL;

	string indent, pre;

	analyzeVec(dbswdbe, vec, unt, ctr, cmd, subclass, vits, supsref, subsref, lin, tix, ns, notit, cmt, appfed, filfed, ixtype, ixvar, icsvar, clsnstype);

	if (subclass) for (unsigned int i = 0; i < subil; i++) indent += "\t";

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

		outfile << pre << "constexpr " << ixtype <<  " " << getVitConst(vit->sref, tix) << " = ";
		if (tix) outfile << "0x" << Wdbe::binToHex(vit->vecNum) << ";" << endl;
		else outfile << vit->vecNum << ";" << endl;
	};
	outfile << endl;

	// getIx/getTix
	if (lin) outfile << pre << ixtype << " get" << StrMod::cap(ixvar) << "(const std::string& sref);" << endl;
	else {
		outfile << pre << ixtype << " get" << StrMod::cap(ixvar) << "(const std::string& srefs);" << endl;
		outfile << pre << "void get" << StrMod::cap(icsvar) << "(const " << ixtype << " " << ixvar << ", std::set<" << ixtype << ">& " << icsvar << ");" << endl;
	};

	// getSref
	if (lin) outfile << pre << "std::string getSref(const " << ixtype << " " << ixvar << ");" << endl;
	else outfile << pre << "std::string getSrefs(const " << ixtype << " " << ixvar << ");" << endl;

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
		if (appfed) outfile << pre << "void appendToFeed(const " << ixtype << " " << ixvar << ", Sbecore::Feed& feed);" << endl;

		// fillFeed
		if (filfed) outfile << pre << "void fillFeed(Sbecore::Feed& feed);" << endl;
	};

	if (subclass) outfile << indent;
	outfile << "};" << endl;

	outfile << endl;
};

void WdbeWrdev::writeVecCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, WdbeMVector* vec
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, WdbeMCommand* cmd
			, const bool subclass
		) {
	ListWdbeMVectoritem vits;
	string supsref, subsref;
	bool lin, tix, ns;
	bool notit, cmt, appfed, filfed;
	string ixtype, ixvar, icsvar;
	string clsnstype;

	WdbeMVectoritem* vit = NULL;

	analyzeVec(dbswdbe, vec, unt, ctr, cmd, subclass, vits, supsref, subsref, lin, tix, ns, notit, cmt, appfed, filfed, ixtype, ixvar, icsvar, clsnstype);

	outfile << "/******************************************************************************" << endl;
	outfile << " " << clsnstype << " ";
	if (subclass) outfile << supsref << "::" << subsref << endl;
	else outfile << vec->sref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	if (lin) {
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
			outfile << "\tif (s == \"" << StrMod::lc(vit->sref) << "\") return " << getVitConst(vit->sref, tix) << ";" << endl;
		};
		outfile << endl;

		if (tix) outfile << "\treturn(0xFF);" << endl;
		else outfile << "\treturn(0);" << endl;
		outfile << "};" << endl;
		outfile << endl;

	} else {
		// getIx/getTix
		outfile << ixtype << " ";
		if (subclass) outfile << supsref << "::" << subsref;
		else outfile << vec->sref;
		outfile << "::get" << StrMod::cap(ixvar) << "(" << endl;
		outfile << "\t\t\tconst string& srefs" << endl;
		outfile << "\t\t) {" << endl;
		outfile << "\t" << ixtype << " " << ixvar << " = 0;" << endl;
		outfile << endl;

		outfile << "\tvector<string> ss;" << endl;
		outfile << "\tStrMod::srefsToVector(StrMod::lc(srefs), ss);" << endl;
		outfile << endl;

		outfile << "\tfor (unsigned int i = 0; i < ss.size(); i++) {" << endl;
		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\t\t";
			if (i != 0) outfile << "else ";
			outfile << "if (ss[i] == \"" << StrMod::lc(vit->sref) << "\") " << ixvar << " |= " << getVitConst(vit->sref, tix) << ";" << endl;
		};
		outfile << "\t};" << endl;
		outfile << endl;

		outfile << "\treturn(" << ixvar << ");" << endl;
		outfile << "};" << endl;
		outfile << endl;

		// getIcs/getTics
		if (subclass) outfile << "void " << supsref << "::" << subsref;
		else outfile << "void " << vec->sref;
		outfile << "::get" << StrMod::cap(icsvar) << "(" << endl;
		outfile << "\t\t\tconst " << ixtype << " " << ixvar << endl;
		outfile << "\t\t\t, set<" << ixtype << ">& " << icsvar << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\t" << icsvar << ".clear();" << endl;
		if (vits.nodes.size() == 0) {
			outfile << "\tfor (" << ixtype << " i = 1; false;) if (" << ixvar << " & i) " << icsvar << ".insert(i);" << endl;
		} else {
			outfile << "\tfor (" << ixtype << " i = 1; i < (2*" << getVitConst(vits.nodes[vits.nodes.size()-1]->sref, tix) << "); i *= 2) if (" << ixvar << " & i) " << icsvar << ".insert(i);" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;
	};

	if (lin) {
		// getSref
		outfile << "string ";
		if (subclass) outfile << supsref << "::" << subsref;
		else outfile << vec->sref;
		outfile << "::getSref(" << endl;
		outfile << "\t\t\tconst " << ixtype << " " << ixvar << endl;
		outfile << "\t\t) {" << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			outfile << "\tif (" << ixvar << " == " << getVitConst(vit->sref, tix) << ") return(\"" << vit->sref << "\");" << endl;
		};
		outfile << endl;

		outfile << "\treturn(\"\");" << endl;
		outfile << "};" << endl;
		outfile << endl;

	} else {
		// getSrefs
		outfile << "string ";
		if (subclass) outfile << supsref << "::" << subsref;
		else outfile << vec->sref;
		outfile << "::getSrefs(" << endl;
		outfile << "\t\t\tconst " << ixtype << " " << ixvar << endl;
		outfile << "\t\t) {" << endl;

		outfile << "\tvector<string> ss;" << endl;
		outfile << "\tstring srefs;" << endl;
		outfile << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];

			outfile << "\tif (" << ixvar << " & " << getVitConst(vit->sref, tix) << ") ss.push_back(\"" << vit->sref << "\");" << endl;
		};
		outfile << endl;

		outfile << "\tStrMod::vectorToString(ss, srefs);" << endl;
		outfile << endl;

		outfile << "\treturn(srefs);" << endl;
		outfile << "};" << endl;
		outfile << endl;
	};

	if (!notit) {
		// getTitle
		outfile << "string ";
		if (subclass) outfile << supsref << "::" << subsref;
		else outfile << vec->sref;
		outfile << "::getTitle(" << endl;
		outfile << "\t\t\tconst " << ixtype << " " << ixvar << endl;
		outfile << "\t\t) {" << endl;

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			if (vit->Title != "") outfile << "\tif (" << ixvar << " == " << getVitConst(vit->sref, tix) << ") return(\"" << StrMod::esc(vit->Title) << "\");" << endl;
		};

		outfile << endl;
		outfile << "\treturn(get";
		if (lin) outfile << "Sref";
		else outfile << "Srefs";
		outfile << "(" << ixvar << "));" << endl;
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

		for (unsigned int i = 0; i < vits.nodes.size(); i++) {
			vit = vits.nodes[i];
			if (vit->Comment != "") outfile << "\tif (" << ixvar << " == " << getVitConst(vit->sref, tix) << ") return(\"" << StrMod::esc(vit->Comment) << "\");" << endl;
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

		outfile << "\tfeed.appendIxSrefTitles(ix, getSref";
		if (!lin) outfile << "s";
		outfile << "(" << ixvar << ")";
		if (!notit) outfile << ", getTitle(" << ixvar << ")";
		else {
			outfile << ", getSref";
			if (!lin) outfile << "s";
			outfile << "(" << ixvar << ")";
		};
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
				outfile << getVitConst(vit->sref, tix);
			};
			outfile << "};" << endl;
			outfile << endl;

			outfile << "\tfor (auto it = items.begin(); it != items.end(); it++) ";

			outfile << "feed.appendIxSrefTitles(*it";
			outfile << ", getSref";
			if (!lin) outfile << "s";
			outfile << "(*it)";
			if (!notit) outfile << ", getTitle(*it)";
			else {
				outfile << ", getSref";
				if (!lin) outfile << "s";
				outfile << "(*it)";
			};
			outfile << ");" << endl;
		};
		outfile << "};" << endl;
		outfile << endl;
	};
};

void WdbeWrdev::analyzeVec(
			DbsWdbe* dbswdbe
			, WdbeMVector* vec
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, WdbeMCommand* cmd
			, const bool subclass
			, ListWdbeMVectoritem& vits
			, string& supsref
			, string& subsref
			, bool& lin //
			, bool& tix
			, bool& ns
			, bool& notit
			, bool& cmt
			, bool& appfed
			, bool& filfed
			, string& ixtype
			, string& ixvar
			, string& icsvar //
			, string& clsnstype
		) {
	dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

	if (subclass) getVecSupsubsref(vec, unt, ctr, cmd, supsref, subsref);

	lin = ((vec->ixVBasetype == VecWdbeVMVectorBasetype::IXLIN) || (vec->ixVBasetype == VecWdbeVMVectorBasetype::TIXLIN));
	tix = ((vec->ixVBasetype == VecWdbeVMVectorBasetype::TIXLIN) || (vec->ixVBasetype == VecWdbeVMVectorBasetype::TIXOR));
	ns = !subclass;

	notit = StrMod::srefInSrefs(vec->srefsKOption, "notit");
	cmt = StrMod::srefInSrefs(vec->srefsKOption, "cmt");
	appfed = StrMod::srefInSrefs(vec->srefsKOption, "appfed");
	filfed = StrMod::srefInSrefs(vec->srefsKOption, "filfed");

	if (tix) {
		ixtype = "uint8_t";
		ixvar = "tix";
		icsvar = "tics";
	} else {
		ixtype = "uint32_t";
		ixvar = "ix";
		icsvar = "ics";
	};

	if (ns) clsnstype = "namespace";
	else clsnstype = "class";
};

void WdbeWrdev::getVecSupsubsref(
			WdbeMVector* vec
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, WdbeMCommand* cmd
			, string& supsref
			, string& subsref
		) {
	string s;
	size_t ptr;

	supsref = "";
	subsref = vec->sref;

	if (cmd) {
		// ex. VecVIdhwIcm2RoicBiasGetInvpar -> CmdIdhwIcm2RoicBias::VecVGetInvpar
		supsref = cmd->Fullsref;

		ptr = subsref.find(supsref.substr(3));
		if (ptr != string::npos) subsref = subsref.substr(0, ptr) + subsref.substr(ptr + supsref.length()-3);

	} else if (ctr) {
		// ex. VecVIdhwIcm2RoicBias -> CtrIdhwIcm2Roic::VecVBias
		supsref = ctr->Fullsref;

		ptr = subsref.find(supsref.substr(3));
		if (ptr != string::npos) subsref = subsref.substr(0, ptr) + subsref.substr(ptr + supsref.length()-3);

	} else if (unt) {
		// ex. VecWIdhwIcm2Buffer -> UntIdhwIcm2::VecWBuffer
		// however, generally subclass not used
	};
};

string WdbeWrdev::getVitConst(
			const string& vitsref
			, const bool tix
		) {
	if (tix) return StrMod::uc(StrMod::uscToCap(StrMod::dotToUsc(vitsref)));
	else return StrMod::uc(StrMod::dotToUsc(vitsref));
};

void WdbeWrdev::writeSpeccmdH(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const bool Easy
			, WdbeMCommand* cmd
			, ListWdbeAMCommandInvpar& ipas
			, ListWdbeAMCommandRetpar& rpas
			, const string& supsref
			, const string& subsref
		) {
	WdbeMVector* vec = NULL;
	WdbeAMCommandRetpar* rpa = NULL;

	outfile << "\t/**" << endl;
	outfile << "\t\t* " << subsref << " (full: " << cmd->Fullsref << ")" << endl;
	outfile << "\t\t*/" << endl;
	outfile << "\tclass " << subsref << " : public Dbecore::Cmd {" << endl;
	outfile << endl;

	if ((ipas.nodes.size() > 0) || (rpas.nodes.size() > 0)) {
		outfile << "\tpublic:" << endl;
		if (ipas.nodes.size() > 0) if (dbswdbe->tblwdbemvector->loadRecBySQL("SELECT * FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CMD) + " AND hkUref = " + to_string(cmd->ref) + " AND sref LIKE '%Invpar'", &vec)) {
			writeVecH(dbswdbe, outfile, vec, NULL, NULL, cmd, true, 2);
			delete vec;
		};
		if (rpas.nodes.size() > 0) if (dbswdbe->tblwdbemvector->loadRecBySQL("SELECT * FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CMD) + " AND hkUref = " + to_string(cmd->ref) + " AND sref LIKE '%Retpar'", &vec)) {
			writeVecH(dbswdbe, outfile, vec, NULL, NULL, cmd, true, 2);
			delete vec;
		};
	};

	outfile << "\tpublic:" << endl;
	outfile << "\t\t" << subsref << "();" << endl;

	if (Easy) {

	} else {
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
	};

	outfile << "\t};" << endl;
	outfile << endl;
};

void WdbeWrdev::writeSpeccmdCpp(
			DbsWdbe* dbswdbe
			, fstream& outfile
			, const bool Easy
			, const utinyint tixCtr
			, WdbeMCommand* cmd
			, ListWdbeAMCommandInvpar& ipas
			, ListWdbeAMCommandRetpar& rpas
			, const string& supsref
			, const string& subsref
		) {
	WdbeMVector* vec = NULL;

	WdbeAMCommandRetpar* rpa = NULL;
	WdbeAMCommandInvpar* ipa = NULL;

	if (ipas.nodes.size() > 0) if (dbswdbe->tblwdbemvector->loadRecBySQL("SELECT * FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CMD) + " AND hkUref = " + to_string(cmd->ref) + " AND sref LIKE '%Invpar'", &vec)) {
		writeVecCpp(dbswdbe, outfile, vec, NULL, NULL, cmd, true);
		delete vec;
	};
	if (rpas.nodes.size() > 0) if (dbswdbe->tblwdbemvector->loadRecBySQL("SELECT * FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CMD) + " AND hkUref = " + to_string(cmd->ref) + " AND sref LIKE '%Retpar'", &vec)) {
		writeVecCpp(dbswdbe, outfile, vec, NULL, NULL, cmd, true);
		delete vec;
	};

	outfile << "/******************************************************************************" << endl;
	outfile << " class " << supsref << "::" << subsref << endl;
	outfile << " ******************************************************************************/" << endl;
	outfile << endl;

	outfile << supsref << "::" << subsref << "::" << subsref << "() :" << endl;
	outfile << "\t\t\tCmd(" << endl;
	if (cmd->refIxVTbl == VecWdbeVMCommandRefTbl::CTR) {
		outfile << "\t\t\t\t" << supsref << "::tixVController" << endl;
		outfile << "\t\t\t\t, VecVCommand";
	} else outfile << "\t\t\t\tVecV" << supsref.substr(3) << "Command";
	outfile << "::" << getVitConst(cmd->sref, true) << endl;
	outfile << "\t\t\t\t, Cmd::VecVRettype::" << StrMod::uc(VecWdbeVMCommandRettype::getSref(cmd->ixVRettype)) << endl;
	outfile << "\t\t\t\t, " << ((ipas.nodes.size() > 0) ? "VecVInvpar::getIx" : "NULL") << endl;
	outfile << "\t\t\t\t, " << ((ipas.nodes.size() > 0) ? "VecVInvpar::getSref" : "NULL") << endl;
	outfile << "\t\t\t\t, " << ((rpas.nodes.size() > 0) ? "VecVRetpar::getIx" : "NULL") << endl;
	outfile << "\t\t\t\t, " << ((rpas.nodes.size() > 0) ? "VecVRetpar::getSref" : "NULL") << endl;
	outfile << "\t\t\t)" << endl;
	outfile << "\t\t{" << endl;

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

	outfile << "\tcomposeFixed();" << endl;

	if (!Easy) {
		outfile << endl;
		outfile << "\treturnSpeccallback = NULL;" << endl;
		outfile << "\targReturnSpeccallback = NULL;" << endl;
	};
	outfile << "};" << endl;
	outfile << endl;

	if (!Easy) {
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
};

void WdbeWrdev::writeSpeccmdCpp_getrpa(
			fstream& outfile
			, WdbeAMCommandRetpar* rpa
		) {
	outfile << ", parsRet[\"" << rpa->sref << "\"].get";
	if (rpa->ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << "Bool";
	else {
		// TIX, [U]INT{8/16/32}, [V]BLOB
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
		outfile << "\tstatic Cmd" << StrMod::cap(cmd->sref) << "* getNewCmd" << StrMod::cap(cmd->sref) << "(";
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

		outfile << "\tlockAccess(\"" << cmd->sref << "\");" << endl;
		outfile << endl;

		outfile << "\tCmd* cmd = cmd" << StrMod::cap(cmd->sref) << ";" << endl;
		outfile << endl;

		if (ipas.nodes.size() > 0) {
			for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
				ipa = ipas.nodes[i];
				writeCmdCpp_setipa(outfile, cmd, ipa);
			};
			outfile << endl;
		};

		if (cmd->refIxVTbl == VecWdbeVMCommandRefTbl::UNT) outfile << "\tif (runCmd(cmd)) {" << endl;
		else outfile << "\tif (unt->runCmd(cmd)) {" << endl;
		for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
			rpa = rpas.nodes[i];
			writeCmdCpp_getrpa(outfile, cmd, rpa);
		};
		outfile << "\t} else throw DbeException(\"error running " << cmd->sref << "\");" << endl;
		outfile << endl;

		outfile << "\tunlockAccess(\"" << cmd->sref << "\");" << endl;

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
			if (cmd->refIxVTbl == VecWdbeVMCommandRefTbl::CTR) outfile << "tixVController, VecVCommand";
			else outfile << "VecV" << supsref.substr(3) << "Command";
			outfile << "::" << getVitConst(cmd->sref, true) << ", Cmd::VecVRettype::" << StrMod::uc(VecWdbeVMCommandRettype::getSref(cmd->ixVRettype)) << ");" << endl;
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
				writeCmdCpp_setipa(outfile, cmd, ipa);
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
					writeCmdCpp_getrpa(outfile, cmd, rpa);
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
			, WdbeMCommand* cmd
			, WdbeAMCommandInvpar* ipa
		) {
	outfile << "\tPar::set";
	if (ipa->ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << "Bool";
	else outfile << StrMod::cap(VecWdbeVPartype::getSref(ipa->ixWdbeVPartype));
	outfile << "(cmd->parbufInv, Cmd" << StrMod::cap(cmd->sref) << "::VecVInvpar::" << StrMod::uc(ipa->sref);
	if ((ipa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) outfile << ", " << to_string(ipa->Length);
	outfile << ", " << ipa->sref;
	if ((ipa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ipa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) outfile << ", " << ipa->sref << "len";
	outfile << ");" << endl;
};

void WdbeWrdev::writeCmdCpp_getrpa(
			fstream& outfile
			, WdbeMCommand* cmd
			, WdbeAMCommandRetpar* rpa
		) {
	if (rpa->ixWdbeVPartype == VecWdbeVPartype::BLOB) {
		outfile << "\t\t" << rpa->sref << "len = " << to_string(rpa->Length) << ";" << endl;
	} else if (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB) {
		outfile << "\t\t" << rpa->sref << "len = Par::getVblobLen(cmd->parbufRet, Cmd" << StrMod::cap(cmd->sref) << "::VecVRetpar::" << StrMod::uc(rpa->sref) << ");" << endl;
	};

	outfile << "\t\t" << rpa->sref << " = Par::get";
	if (rpa->ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << "Bool";
	else {
		// TIX, [U]INT{8/16/32}, [V]BLOB
		outfile << StrMod::cap(VecWdbeVPartype::getSref(rpa->ixWdbeVPartype));
	};
	outfile << "(cmd->parbufRet, Cmd" << StrMod::cap(cmd->sref) << "::VecVRetpar::" << StrMod::uc(rpa->sref);
	if ((rpa->ixWdbeVPartype == VecWdbeVPartype::BLOB) || (rpa->ixWdbeVPartype == VecWdbeVPartype::VBLOB)) outfile << ", " << rpa->sref << "len";
	outfile << ");" << endl;
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

	if (errNotCmd) outfile << "\terr.addPar(\"" << sref << "\"";
	else if (retNotInv) outfile << "\taddRetpar(VecVRetpar::" << StrMod::uc(sref);
	else outfile << "\taddInvpar(VecVInvpar::" << StrMod::uc(sref);
	outfile << ", Par::VecVType::" << StrMod::uc(VecWdbeVPartype::getSref(ixWdbeVPartype));

	if (ixWdbeVPartype == VecWdbeVPartype::TIX) {
		if (dbswdbe->tblwdbemvector->loadRecByRef(refWdbeMVector, &vec)) {
			if (vec->hkIxVTbl == VecWdbeVMVectorHkTbl::CTR) dbswdbe->tblwdbemcontroller->loadRecByRef(vec->hkUref, &ctr);
			getVecSupsubsref(vec, NULL, ctr, NULL, supsref, subsref);
			if (ctr) delete ctr;

			if (supsref != "") {
				outfile << ", " << supsref << "::" << subsref << "::getTix";
				outfile << ", " << supsref << "::" << subsref << "::getSref";
				if (vec->ixVBasetype == VecWdbeVMVectorBasetype::TIXOR) outfile << "s";
				outfile << ", " << supsref << "::" << subsref << "::fillFeed";
			} else {
				outfile << ", " << subsref << "::getTix";
				outfile << ", " << subsref << "::getSref";
				if (vec->ixVBasetype == VecWdbeVMVectorBasetype::TIXOR) outfile << "s";
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

	if (ixWdbeVPartype == VecWdbeVPartype::TIX) outfile << "uint8_t";
	else if (ixWdbeVPartype == VecWdbeVPartype::_BOOL) outfile << "bool";
	else if ((ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ixWdbeVPartype == VecWdbeVPartype::VBLOB)) {
		if (len) outfile << "size_t";
		else outfile << "unsigned char*";
	} else {
		// [U]INT{8/16/32}
		outfile << VecWdbeVPartype::getSref(ixWdbeVPartype) << "_t";
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
			// [U]INT{8/16/32}
			outfile << " = 0";
		};
	};

	if (newline) outfile << endl;
	
	if (((ixWdbeVPartype == VecWdbeVPartype::BLOB) || (ixWdbeVPartype == VecWdbeVPartype::VBLOB)) && !len) wrIparpa(outfile, sref, ixWdbeVPartype, false, newline, refNotConst, ns, init, true);
};
// IP cust --- IEND
