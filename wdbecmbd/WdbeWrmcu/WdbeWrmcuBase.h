/**
	* \file WdbeWrmcuBase.h
	* Wdbe operation processor - write C code basics (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#ifndef WDBEWRMCUBASE_H
#define WDBEWRMCUBASE_H

#include "WdbeWrmcu.h"

// IP include.cust --- INSERT

namespace WdbeWrmcuBase {

	DpchRetWdbe* run(XchgWdbe* xchg, DbsWdbe* dbswdbe, DpchInvWdbeWrmcuBase* dpchinv);
	// IP cust --- IBEGIN

	class Module;

	class Event {

	public:
		class VecVSection {

		public:
			static constexpr unsigned int ISR = 1;
			static constexpr unsigned int HSHK = 2;
			static constexpr unsigned int STRB = 3;
		};

	public:
		Event(const unsigned int ixVSection, const std::string& sref, const bool cluster, const unsigned int evtbyte, const unsigned char value);

	public:
		unsigned int ixVSection;

		std::string sref;
		bool cluster;

		unsigned int evtbyte;
		unsigned char value;

		Module* mdlSet;
		std::vector<Module*> mdlsGet;
	};

	class Module {

	public:
		Module(const std::string& sref, const unsigned int snsbyte, const unsigned char value);

	public:
		std::string sref;

		unsigned int snsbyte;
		unsigned char value;

		std::vector<Event*> evtsGet;
		std::vector<Event*> evtsSet;
	};

	void writeUntH(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMUnit* unt, const std::string& Untsref, ListWdbeMModule& mdls, unsigned int& snsbyte, unsigned int& evtbyte);
	void writeUntExeC(DbsWdbe* dbswdbe, std::fstream& outfile, WdbeMUnit* unt, ListWdbeMModule& mdls, const unsigned int snsbyte, const unsigned int evtbyte);
	// IP cust --- IEND
};

#endif
