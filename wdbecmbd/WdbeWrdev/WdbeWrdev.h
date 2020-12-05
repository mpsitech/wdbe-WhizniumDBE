/**
	* \file WdbeWrdev.h
	* Wdbe operation pack global code (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRDEV_H
#define WDBEWRDEV_H

#include "WdbeWrdev_blks.h"

// IP include.cust --- INSERT

namespace WdbeWrdev {

	// IP cust --- IBEGIN
	void writeVecH(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMVector* vec, WdbeMSystem* sys, WdbeMUnit* unt, WdbeMController* ctr, const bool subclass, const unsigned int subil = 1);
	void writeVecCpp(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMVector* vec, WdbeMSystem* sys, WdbeMUnit* unt, WdbeMController* ctr, const bool subclass);

	void analyzeVec(DbsWdbe* dbswdbe, WdbeMVector* vec, WdbeMSystem* sys, WdbeMUnit* unt, WdbeMController* ctr, const bool subclass, ListWdbeMVectoritem& vits, std::string& supsref, std::string& subsref, bool& tix, bool& ns, bool& notit, bool& cmt, bool& appfed, bool& filfed, std::string& ixtype, std::string& ixvar, std::string& clsnstype);
	void getVecSupsubsref(WdbeMVector* vec, WdbeMSystem* sys, WdbeMUnit* unt, WdbeMController* ctr, std::string& supsref, std::string& subsref);
	std::string getVitConst(WdbeMVectoritem* vit, const bool tix);

	void writeSpeccmdH(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMCommand* cmd, ListWdbeAMCommandRetpar& rpas, const std::string& supsref, const std::string& subsref);

	void writeSpeccmdCpp(DbsWdbe* dbswdbe, std::fstream& outfile, const Sbecore::utinyint tixCtr, WdbeMCommand* cmd, ListWdbeAMCommandRetpar& rpas, const std::string& supsref, const std::string& subsref);
	void writeSpeccmdCpp_getrpa(std::fstream& outfile, WdbeAMCommandRetpar* rpa);

	void writeCmdH(DbsWdbe* dbswdbe, std::fstream& outfile, const bool Easy, WdbeMCommand* cmd, ListWdbeAMCommandInvpar& ipas, ListWdbeAMCommandRetpar& rpas, const std::string& supsref, const std::string& subsref);

	void writeCmdCpp(DbsWdbe* dbswdbe, std::fstream& outfile, const bool Easy, const Sbecore::utinyint tixCtr, const std::string& srefCtr, const bool hasvecerr, WdbeMCommand* cmd, ListWdbeAMCommandInvpar& ipas, ListWdbeAMCommandRetpar& rpas, const std::string& supsref, const std::string& subsref);
	void writeCmdCpp_setipa(std::fstream& outfile, WdbeAMCommandInvpar* ipa);
	void writeCmdCpp_getrpa(std::fstream& outfile, WdbeAMCommandRetpar* rpa);

	void writeErrH(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMError* err);

	void writeErrCpp(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMError* err, ListWdbeAMErrorPar& epas, const std::string& supsref, const std::string& subsref);

	void wrAddpar(DbsWdbe* dbswdbe, std::fstream& outfile, const std::string& sref, const Sbecore::uint ixWdbeVPartype, const Sbecore::ubigint refWdbeMVector, const Sbecore::utinyint Length, const bool errNotCmd, const bool retNotInv);
	void wrIparpa(std::fstream& outfile, const std::string& sref, const Sbecore::uint ixWdbeVPartype, const bool first, const bool newline, const bool refNotConst, const bool ns, const bool init, const bool len);
	// IP cust --- IEND
};

#endif



