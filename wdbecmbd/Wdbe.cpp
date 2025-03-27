/**
	* \file Wdbe.cpp
	* Wdbe global functionality (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
  */
// IP header --- ABOVE

#include "Wdbe.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace Acv
 ******************************************************************************/

ubigint Acv::addfile(
			DbsWdbe* dbswdbe
			, const string& acvpath
			, const string& path
			, const ubigint grp
			, const ubigint own
			, const uint refIxVTbl
			, const ubigint refUref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) {
	ubigint retval = 0;

	WdbeMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in byte
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size;

	dbswdbe->tblwdbemfile->insertNewRec(&fil, grp, own, 0, refIxVTbl, refUref, osrefKContent, Archived, Filename, "", srefKMimetype, Size, Comment);
	
	// adjust archive name in record
	str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
	if (Filename.rfind('.') != string::npos) str << Filename.substr(Filename.rfind('.'));

	fil->Archivename = str.str();
	dbswdbe->tblwdbemfile->updateRec(fil);

	// create folder if required
	str.str(""); str << acvpath << "/";
	str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

	// copy file
	s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

	res = system(s.c_str());
	if (res != 0) cout << "Acv::addfile() error copying file (" << res << ")" << endl;

	retval = fil->ref;
	delete fil;

	return retval;
};

void Acv::alterfile(
			DbsWdbe* dbswdbe
			, const string& acvpath
			, const string& path
			, const ubigint ref
		) {
	WdbeMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	// load record
	dbswdbe->tblwdbemfile->loadRecByRef(ref, &fil);

	if (fil) {
		// update record
		fil->Archived = Archived;

		str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
		if (fil->Filename.rfind('.') != string::npos) str << fil->Filename.substr(fil->Filename.rfind('.'));
		fil->Archivename = str.str();

		fil->Size = Size;

		dbswdbe->tblwdbemfile->updateRec(fil);

		// create folder if required
		str.str(""); str << acvpath << "/";
		str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

		// copy file
		s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

		res = system(s.c_str());
		if (res != 0) cout << "Acv::alterfile() error copying file (" << res << ")" << endl;

		delete fil;
	};
};

string Acv::getfile(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMFile
		) {
	WdbeMFile* fil = NULL;

	ostringstream str;

	dbswdbe->tblwdbemfile->loadRecByRef(refWdbeMFile, &fil);

	if (fil) {
		str.fill('0');
		str.width(5);
		str << right << ((fil->ref-(fil->ref%1000)) / 1000);
		
		str.width(0);
		str << "/" << fil->Archivename;

		delete fil;
	};

	return(str.str());
};

/******************************************************************************
 namespace Lop
 ******************************************************************************/

void Lop::apply(
			const uint ixWdbeVLop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	if (ixWdbeVLop == VecWdbeVLop::INS) insert(refsList, refsPool, ref);
	else if (ixWdbeVLop == VecWdbeVLop::RMV) remove(refsList, refsPool, ref);
};

void Lop::insert(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i = 0; i < refsPool.size(); i++) {
		if (refsPool[i] == ref) {
			refsList[i] = ref;
			refsPool[i] = 0;
			break;
		};
	};
};

void Lop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref) {
			refsPool[i] = ref;
			refsList[i] = 0;
			break;
		};
	};
};

/******************************************************************************
 namespace Oolop
 ******************************************************************************/

void Oolop::apply(
			const uint ixWdbeVOolop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	if (ixWdbeVOolop == VecWdbeVOolop::INB) insertBefore(refsList, refsPool, ref1, ref2);
	else if (ixWdbeVOolop == VecWdbeVOolop::INA) insertAfter(refsList, refsPool, ref1, ref2);
	else if (ixWdbeVOolop == VecWdbeVOolop::RMV) remove(refsList, refsPool, ref1);
	else if (ixWdbeVOolop == VecWdbeVOolop::TOB) toBefore(refsList, ref1, ref2);
	else if (ixWdbeVOolop == VecWdbeVOolop::TOA) toAfter(refsList, ref1, ref2);
	else if (ixWdbeVOolop == VecWdbeVOolop::SWP) swap(refsList, ref1, ref2);
};

void Oolop::insertBefore(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool = refsPool.begin(); itPool != refsPool.end(); itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.insert(refsList.begin(), ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
					if (*itList == ref2) {
						refsList.insert(itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::insertAfter(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool = refsPool.begin(); itPool != refsPool.end(); itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.push_back(ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
					if (*itList == ref2) {
						refsList.insert(++itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
		if (*itList == ref) {
			refsList.erase(itList);
			refsPool.push_back(ref);
		};
	};
};

void Oolop::toBefore(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******2*****1****
	// *******12*********
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref2) {
			for (unsigned int j = i + 1; j < refsList.size(); j++) {
				if (refsList[j] == ref1) {
					for (unsigned int k = i + 1; k < j; k++) refsList[k+1] = refsList[k];
					refsList[i] = ref1;
					refsList[i+1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::toAfter(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******1*****2****
	// ************21****
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref1) {
			for (unsigned int j = i + 1; j < refsList.size(); j++) {
				if (refsList[j] == ref2) {
					for (unsigned int k = i + 1; k < j; k++) refsList[k-1] = refsList[k];
					refsList[j] = ref1;
					refsList[j-1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::swap(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
		if (*itList == ref1) {
			for (auto itList2 = refsList.begin(); itList2 != refsList.end(); itList2++) {
				if (*itList2 == ref2) {
					*itList = ref2;
					*itList2 = ref1;
					break;
				};
			};
			break;
		};
	};
};

/******************************************************************************
 namespace Tmp
 ******************************************************************************/

string Tmp::newfile(
			const string& tmppath
			, const string& ext
		) {
	string filename;
	fstream tmpfile;

	unsigned int pathlen = tmppath.length() + 1;

	FILE* file;

	bool valid = false;

	while (!valid) {
		filename = tmppath + "/" + random();
		if (ext.length() > 0) filename += "." + ext;

		file = fopen(filename.c_str(), "w+x");

		if (file) {
			fclose(file);
			valid = true;
		} else if (errno != EEXIST) break;
	};

	return(filename.substr(pathlen));
};

string Tmp::newfolder(
			const string& tmppath
		) {
	string foldername;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		foldername = tmppath + "/" + random();

		// mkdir() fails if folder exists
#ifdef _WIN32
		valid = (mkdir(foldername.c_str()) == 0);
#else
		valid = (mkdir(foldername.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0);
#endif

		if (!valid) if (errno != EEXIST) break;
	};

	return(foldername.substr(pathlen));
};

string Tmp::random() {
	string retval;

	int digit;

	// random seed is done in engine initialization

	// fetch digits and make sure their ASCII code is in the range 0..9/a..z
	for (unsigned int i = 0; i < 8; i++) {
		digit = rand() % 36 + 48;
		if (digit > 57) digit += (97-48-10);

		retval = retval + ((char) digit);
	};

	return retval;
};

// IP cust --- INSERT

/******************************************************************************
 namespace Wdbe
 ******************************************************************************/

// IP gbl --- IBEGIN
ubigint Wdbe::getRefMtp(
			DbsWdbe* dbswdbe
			, const string& sref
		) {
	ubigint retval = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE ((hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::VOID) + ") AND (supRefWdbeMModule = 0) AND (tplRefWdbeMModule = 0)) AND sref = '" + sref + "'", retval);

	return retval;
};

void Wdbe::getSrefsMtpCustops(
			DbsWdbe* dbswdbe
			, map<ubigint,string>& srefsMtpCustops
			, const uint ixWdbeVKeylist
		) {
	ListWdbeMModule mtps;
	WdbeMModule* mtp = NULL;

	Feed feed;

	string Opksref;

	srefsMtpCustops.clear();

	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE ((hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::VOID) + ") AND (supRefWdbeMModule = 0) AND (tplRefWdbeMModule = 0))", false, mtps);

	dbswdbe->fillFeedFromKlst(ixWdbeVKeylist, 1, feed);

	// keylist sref ex. KlstKWdbeMtpModbscbuCustop
	// keylist key ex.       WdbeMtpModbscbuAxihostif_v1_0

	Opksref = VecWdbeVKeylist::getSref(ixWdbeVKeylist);
	Opksref = Opksref.substr(4+1);
	if (Opksref.length() > 6) Opksref = Opksref.substr(0, Opksref.length()-6);

	for (unsigned int i = 0; i < mtps.nodes.size(); i++) {
		mtp = mtps.nodes[i];
		if (feed.getNumBySref(Opksref + StrMod::cap(mtp->sref)) != 0) srefsMtpCustops[mtp->ref] = Opksref + StrMod::cap(mtp->sref);
	};

//	cout << "for keylist " << VecWdbeVKeylist::getSref(ixWdbeVKeylist) << ", found these custom operations:" << endl;
//	for (auto it = srefsMtpCustops.begin(); it != srefsMtpCustops.end(); it++) cout << it->first << ": " << it->second << endl;
};

bool Wdbe::getMpa(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& x1SrefKKey
			, string& Val
		) {
	return(dbswdbe->loadStringBySQL("SELECT Val FROM TblWdbeAMModulePar WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND x1SrefKKey = '" + x1SrefKKey + "'", Val));
};

string Wdbe::getPrjshort(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMVersion
		) {
	string Prjshort;

	dbswdbe->loadStringBySQL("SELECT TblWdbeMProject.Short FROM TblWdbeMProject, TblWdbeMVersion WHERE TblWdbeMProject.ref = TblWdbeMVersion.prjRefWdbeMProject AND TblWdbeMVersion.ref = "
				+ to_string(refWdbeMVersion), Prjshort);

	return(StrMod::cap(Prjshort));
};

void Wdbe::updateVerste(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMVersion
			, const uint ixVState
		) {
	vector<ubigint> refs;
	ubigint ref;

	WdbeJMVersionState* verJste = NULL;

	time_t rawtime;
	time(&rawtime);

	bool skip = false;

	if (dbswdbe->tblwdbejmversionstate->loadRecBySQL("SELECT * FROM TblWdbeJMVersionState WHERE refWdbeMVersion = " + to_string(refWdbeMVersion) + " AND x1Start <= " + to_string(rawtime) + " ORDER BY x1Start DESC LIMIT 0,1", &verJste)) {
		if (verJste->ixVState == ixVState) skip = true;
	};

	if (!skip) {
		if (ixVState == VecWdbeVMVersionState::READY) {
			// make sure other versions with the same number in state build-ready become abandonned
			dbswdbe->loadRefsBySQL("SELECT ver2.ref FROM TblWdbeMVersion AS ver1, TblWdbeMVersion AS ver2 WHERE ver1.ref = " + to_string(refWdbeMVersion)
						+ " AND ver1.ref <> ver2.ref AND ver2.prjRefWdbeMProject = ver1.prjRefWdbeMProject AND ver2.Major = ver1.Major"
						+ " AND ver2.Minor = ver1.Minor AND ver2.Sub = ver1.Sub AND ver2.ixVState = " + to_string(VecWdbeVMVersionState::READY), false, refs);
			for (unsigned int i = 0; i < refs.size(); i++) updateVerste(dbswdbe, refs[i], VecWdbeVMVersionState::ABANDON);
		};

		// commence new state
		ref = dbswdbe->tblwdbejmversionstate->insertNewRec(NULL, refWdbeMVersion, rawtime, ixVState);
		dbswdbe->executeQuery("UPDATE TblWdbeMVersion SET refJState = " + to_string(ref) + ", ixVState = " + to_string(ixVState) + " WHERE ref = " + to_string(refWdbeMVersion));
	};
};

bool Wdbe::getLibmkf(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMLibrary
			, const ubigint x1RefWdbeMMachine
			, vector<ubigint>& hrefsMch
			, const string& x2SrefKTag
			, string& Val
		) {
	Val = "";

	if (dbswdbe->tblwdbeamlibrarymakefile->loadValByLibMchTag(refWdbeMLibrary, x1RefWdbeMMachine, x2SrefKTag, Val)) return true;
	for (unsigned int i = 0; i < hrefsMch.size(); i++) if (dbswdbe->tblwdbeamlibrarymakefile->loadValByLibMchTag(refWdbeMLibrary, hrefsMch[i], x2SrefKTag, Val)) return true;

	return false;
};

bool Wdbe::getMchmkf(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMMachine
			, vector<ubigint>& hrefsMch
			, const string& x1SrefKTag
			, string& Val
		) {
	Val = "";

	if (dbswdbe->tblwdbeammachinemakefile->loadValByMchTag(refWdbeMMachine, x1SrefKTag, Val)) return true;
	for (unsigned int i = 0; i < hrefsMch.size(); i++) if (dbswdbe->tblwdbeammachinemakefile->loadValByMchTag(hrefsMch[i], x1SrefKTag, Val)) return true;

	return false;
};

bool Wdbe::getMchpar(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMMachine
			, vector<ubigint>& hrefsMch
			, const string& x1SrefKKey
			, string& Val
		) {
	Val = "";

	if (dbswdbe->tblwdbeammachinepar->loadValByMchKey(refWdbeMMachine, x1SrefKKey, Val)) return true;
	for (unsigned int i = 0; i < hrefsMch.size(); i++) if (dbswdbe->tblwdbeammachinepar->loadValByMchKey(hrefsMch[i], x1SrefKKey, Val)) return true;

	return false;
};

void Wdbe::addLibBySref(
			DbsWdbe* dbswdbe
			, const string& srefLib
			, const ubigint refMch
			, vector<ubigint>& hrefsMch
			, set<string>& incpaths
		) {
	ubigint refLib;

	if (dbswdbe->tblwdbemlibrary->loadRefBySrf(srefLib, refLib)) addLibByRef(dbswdbe, refLib, refMch, hrefsMch, incpaths);
};

void Wdbe::addLibByRef(
			DbsWdbe* dbswdbe
			, const ubigint refLib
			, const ubigint refMch
			, vector<ubigint>& hrefsMch
			, set<string>& incpaths
		) {
	set<string> cppflags;
	set<string> linkflags;
	set<string> libpaths;
	vector<string> libss;

	addLibByRef(dbswdbe, refLib, refMch, hrefsMch, cppflags, linkflags, incpaths, libpaths, libss, 0, true);
};

void Wdbe::addLibBySref(
			DbsWdbe* dbswdbe
			, const string& srefLib
			, const ubigint refMch
			, vector<ubigint>& hrefsMch
			, std::set<std::string>& cppflags
			, std::set<std::string>& linkflags
			, std::set<std::string>& incpaths
			, std::set<std::string>& libpaths
			, std::vector<std::string>& libss
			, unsigned int ix0
			, const bool inconly
		) {
	ubigint refLib;

	if (dbswdbe->tblwdbemlibrary->loadRefBySrf(srefLib, refLib)) addLibByRef(dbswdbe, refLib, refMch, hrefsMch, cppflags, linkflags, incpaths, libpaths, libss, ix0, inconly);
};

void Wdbe::addLibByRef(
			DbsWdbe* dbswdbe
			, const ubigint refLib
			, const ubigint refMch
			, vector<ubigint>& hrefsMch
			, std::set<std::string>& cppflags
			, std::set<std::string>& linkflags
			, std::set<std::string>& incpaths
			, std::set<std::string>& libpaths
			, std::vector<std::string>& libss
			, unsigned int ix0
			, const bool inconly
		) {
	WdbeMLibrary* lib = NULL;

	vector<string> ss;
	string s;

	if (dbswdbe->tblwdbemlibrary->loadRecByRef(refLib, &lib)) {
		if (getLibmkf(dbswdbe, refLib, refMch, hrefsMch, "incpath", s)) {
			StrMod::stringToVector(s, ss, ' ');
			for (unsigned int i = 0; i < ss.size(); i++) incpaths.insert(ss[i]);
		};

		if (!inconly) {
			if (getLibmkf(dbswdbe, refLib, refMch, hrefsMch, "cppflags", s)) {
				StrMod::stringToVector(s, ss, ' ');
				for (unsigned int i = 0; i < ss.size(); i++) cppflags.insert(ss[i]);
			};

			if (getLibmkf(dbswdbe, refLib, refMch, hrefsMch, "linkflags", s)) {
				StrMod::stringToVector(s, ss, ' ');
				for (unsigned int i = 0; i < ss.size(); i++) linkflags.insert(ss[i]);
			};


			if (getLibmkf(dbswdbe, refLib, refMch, hrefsMch, "libpath", s)) {
				StrMod::stringToVector(s, ss, ' ');
				for (unsigned int i = 0; i < ss.size(); i++) libpaths.insert(ss[i]);
			};

			if (getLibmkf(dbswdbe, refLib, refMch, hrefsMch, "libs", s)) {
				StrMod::stringToVector(s, ss, ' ');

				if (libss.size() < (ix0 + ss.size())) libss.resize(ix0 + ss.size());

				for (unsigned int i = 0; i < ss.size(); i++) {
					if (libss[ix0+i] == "") libss[ix0+i] = ss[i];
					else libss[ix0+i] += " " + ss[i];
				};

				ix0 += ss.size();
			};
		};

		StrMod::srefsToVector(lib->depSrefsWdbeMLibrary, ss);
		for (unsigned int i = 0; i < ss.size();i++) addLibBySref(dbswdbe, ss[i], refMch, hrefsMch, cppflags, linkflags, incpaths, libpaths, libss, ix0, inconly);

		delete lib;
	};
};

void Wdbe::trimLibss(
			vector<string>& libss
		) {
	set<string> unqlibs;

	vector<string> ss;
	set<string> unqss;

	string s;

	for (unsigned int i = libss.size(); i > 0; i--) {
		unqss.clear();

		StrMod::stringToVector(libss[i - 1], ss, ' ');
		for (unsigned int j = 0; j < ss.size(); j++) {
			if (unqlibs.find(ss[j]) == unqlibs.end()) {
				unqlibs.insert(ss[j]);
				unqss.insert(ss[j]);
			};
		};

		s = "";
		for (auto it = unqss.begin(); it != unqss.end(); it++) {
			if (it != unqss.begin()) s += " ";
			s += *it;
		};

		libss[i-1] = s;
	};
};

string Wdbe::pathToPathstr(
			const string& path
			, const bool libNotInc
			, const string& inclibeq
		) {
	string pathstr;

	vector<string> ss;

	StrMod::stringToVector(path, ss, ' ');

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (i != 0) pathstr += " ";

		if (libNotInc) pathstr += "-L" + inclibeq + ss[i];
		else pathstr += "-I" + inclibeq + ss[i];
	};

	return pathstr;
};

string Wdbe::libsToLibstr(
			const string& libs
			, const bool statNotDyn
		) {
	string libstr;

	vector<string> ss;

	StrMod::stringToVector(libs, ss, ' ');

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (i != 0) libstr += " ";
		
		if (statNotDyn) libstr += "-l:" + ss[i] + ".a";
		else libstr += "-l" + ss[i].substr(3);
	};

	return libstr;
};

void Wdbe::analyzeUnt(
			DbsWdbe* dbswdbe
			, WdbeMUnit* unt
			, string& srefroot
			, ListWdbeMVector& vecs
			, ListWdbeMController& ctrs
			, ListWdbeMImbuf& imbs
			, ListWdbeMCommand& cmds
			, ListWdbeMError& errs
			, ubigint& refHostif
			, uint& ixImbCmdinv
			, uint& ixImbCmdret
			, bool& hasvecbuf
			, bool& hasvecctr
			, bool& hasveccmd
			, bool& hasvecerr
			, bool& hasspeccmd
		) {
	ubigint ref;

	WdbeMVector* vec = NULL;

	WdbeMImbuf* imb = NULL;

	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	ListWdbeAMCommandRetpar rpas;

	string supsref, subsref;

	refHostif = 0;

	ixImbCmdinv = 0; ixImbCmdinv--;
	ixImbCmdret = 0; ixImbCmdret--;

	hasvecbuf = false;
	hasvecctr = false;
	hasveccmd = false;
	hasspeccmd = false;

	srefroot = unt->Fullsref.substr(3);

	dbswdbe->tblwdbemvector->loadRstByHktHku(VecWdbeVMVectorHkTbl::UNT, unt->ref, false, vecs);
	dbswdbe->tblwdbemvector->loadRstBySQL("SELECT TblWdbeMVector.* FROM TblWdbeMModule, TblWdbeMProcess, TblWdbeMVector WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = " + to_string(unt->ref)
				+ " AND TblWdbeMProcess.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMVector.hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::FSM) + " AND TblWdbeMVector.hkUref = TblWdbeMProcess.refWdbeMFsm ORDER BY TblWdbeMVector.sref ASC", true, vecs);

	dbswdbe->tblwdbemcontroller->loadRstBySQL("SELECT TblWdbeMController.* FROM TblWdbeMModule, TblWdbeMController WHERE TblWdbeMModule.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND TblWdbeMModule.hkUref = "
				+ to_string(unt->ref) + " AND TblWdbeMController.refWdbeMModule = TblWdbeMModule.ref ORDER BY TblWdbeMController.Fullsref ASC", false, ctrs);

	if (!dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF), refHostif))
				dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(unt->ref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::EHOSTIF), refHostif);

	if (refHostif != 0) {
		dbswdbe->tblwdbemimbuf->loadRstBySQL("SELECT TblWdbeMImbuf.* FROM TblWdbeMImbuf, TblWdbeMModule, TblWdbeRMModuleMModule WHERE TblWdbeMImbuf.refWdbeMModule = TblWdbeMModule.ref AND TblWdbeMModule.ref = TblWdbeRMModuleMModule.ctdRefWdbeMModule AND TblWdbeRMModuleMModule.corRefWdbeMModule = "
					+ to_string(refHostif) + " ORDER BY TblWdbeMImbuf.Prio ASC, TblWdbeMModule.sref ASC", false, imbs);

		for (unsigned int i = 0; i < imbs.nodes.size(); i++) {
			imb = imbs.nodes[i];

			if ((ixImbCmdinv+1) == 0) if (dbswdbe->loadRefBySQL("SELECT mdl1.ref FROM TblWdbeMModule AS mdl1, TblWdbeMModule AS mdl2 WHERE mdl2.supRefWdbeMModule = mdl1.ref AND mdl2.ref = "
						+ to_string(imb->refWdbeMModule) + " AND mdl1.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDINV), ref)) ixImbCmdinv = i;
			if ((ixImbCmdret+1) == 0) if (dbswdbe->loadRefBySQL("SELECT mdl1.ref FROM TblWdbeMModule AS mdl1, TblWdbeMModule AS mdl2 WHERE mdl2.supRefWdbeMModule = mdl1.ref AND mdl2.ref = "
						+ to_string(imb->refWdbeMModule) + " AND mdl1.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDRET), ref)) ixImbCmdret = i;

			if (((ixImbCmdinv + 1) != 0) && ((ixImbCmdret + 1) != 0)) break;
		};
	};

	dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::UNT, unt->ref, false, cmds);

	dbswdbe->tblwdbemerror->loadRstByRetReu(VecWdbeVMErrorRefTbl::UNT, unt->ref, false, errs);

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];

		if (vec->sref == ("VecV" + srefroot + "Buffer")) hasvecbuf = true;
		else if (vec->sref == ("VecV" + srefroot + "Controller")) hasvecctr = true;
		else if (vec->sref == ("VecV" + srefroot + "Command")) hasveccmd = true;
		else if (vec->sref == ("VecV" + srefroot + "Error")) hasvecerr = true;

		if (hasvecbuf && hasvecctr && hasveccmd && hasvecerr) break;
	};

	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		analyzeCmd(dbswdbe, cmd, unt, NULL, ipas, rpas, supsref, subsref);

		if (rpas.nodes.size() > 0) {
			hasspeccmd = true;
			break;
		};
	};
};

string Wdbe::getUntVendor(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMUnit
		) {
	string srefWdbeKVendor;

	dbswdbe->loadStringBySQL("SELECT TblWdbeMFamily.srefWdbeKVendor FROM TblWdbeMFamily, TblWdbeMUnit AS unt1, TblWdbeMUnit AS unt2 WHERE TblWdbeMFamily.ref = unt2.refUref AND unt2.ref = unt1.silRefWdbeMUnit AND unt1.ref = "
				+ to_string(refWdbeMUnit), srefWdbeKVendor);

	return srefWdbeKVendor;
};

string Wdbe::getMdlVendor(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
		) {
	string srefWdbeKVendor;

	dbswdbe->loadStringBySQL("SELECT TblWdbeMFamily.srefWdbeKVendor FROM TblWdbeMFamily, TblWdbeMUnit AS unt1, TblWdbeMUnit AS unt2, TblWdbeMModule WHERE TblWdbeMModule.ref = " + to_string(refWdbeMModule)
				+ " AND TblWdbeMFamily.ref = unt2.refUref AND unt2.ref = unt1.silRefWdbeMUnit AND unt1.ref = TblWdbeMModule.hkUref", srefWdbeKVendor);

	return srefWdbeKVendor;
};

void Wdbe::getPairsCmdbus(
			DbsWdbe* dbswdbe
			, ListWdbeMModule& mdls
			, set<pair<string,string> >& pairsCmdbus
		) {
	WdbeMModule* mdl = NULL;
	WdbeMModule* mdl2 = NULL;

	WdbeMController* ctr = NULL;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeRMCommandMController crcs;
	WdbeRMCommandMController* crc = NULL;

	string cmdinvsref, cmdretsref;

	bool found;

	pairsCmdbus.clear();

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDINV) cmdinvsref = mdl->sref;
		else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDRET) cmdretsref = mdl->sref;

		if ((cmdinvsref != "") && (cmdretsref != "")) break;
	};

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::DBGCTR)) {
			if (dbswdbe->tblwdbemcontroller->loadRecByRef(mdl->refWdbeMController, &ctr)) {
				// analyze controller commands
				dbswdbe->tblwdbemcommand->loadRstBySQL("SELECT * FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(ctr->ref) + " ORDER BY refNum ASC", false, cmds);

				if (cmds.nodes.size() > 0) pairsCmdbus.insert(pair<string,string>(cmdinvsref, mdl->sref));
				for (unsigned int j = 0; j < cmds.nodes.size(); j++) {
					cmd = cmds.nodes[j];
					if (cmd->ixVRettype != VecWdbeVMCommandRettype::VOID) pairsCmdbus.insert(pair<string,string>(mdl->sref, cmdretsref));
				};

				// analyze invoked commands
				dbswdbe->tblwdbermcommandmcontroller->loadRstByCtr(mdl->refWdbeMController, false, crcs);
				for (unsigned int j = 0; j < crcs.nodes.size(); j++) {
					crc = crcs.nodes[j];

					if (dbswdbe->tblwdbemcommand->loadRecByRef(crc->refWdbeMCommand, &cmd)) {
						found = false;
						for (unsigned int k = 0; k < mdls.nodes.size(); k++) {
							mdl2 = mdls.nodes[k];

							if (mdl2->refWdbeMController == cmd->refUref) {
								found = true;
								break;
							};
						};

						if (found) {
							pairsCmdbus.insert(pair<string,string>(mdl->sref, mdl2->sref));
							if (cmd->ixVRettype != VecWdbeVMCommandRettype::VOID) pairsCmdbus.insert(pair<string,string>(mdl2->sref, mdl->sref));
						};

						delete cmd;
					};
				};

				delete ctr;
			};
		};
	};
};

bool Wdbe::getImbsrefs(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, string& sref
			, string& srefrootMgmt
			, string& srefrootCor
		) {
	// ex. evtbufLogToHostif (mgmt log, snk hostif) => mgmtToNotFrom = false, srefrootMgmt = "EvtbufToHostif", srefrootCor = "EvtbufFromLog"
	// ex. bufHostifToFoo (mgmt foo, src hostif) => mgmtToNotFrom = true, srefrootMgmt = "BufFromHostif", srefrootCor = "BufToFoo"

	bool mgmtToNotFrom;

	ListWdbeRMModuleMModule mdlRmdls;
	WdbeRMModuleMModule* mdlRmdl = NULL;

	string srefBuf, srefMgmt, srefFrom, srefTo;

	dbswdbe->tblwdbemmodule->loadSrfByRef(refWdbeMModule, srefBuf);

	dbswdbe->tblwdbermmodulemmodule->loadRstByCtd(refWdbeMModule, false, mdlRmdls);
	for (unsigned int i = 0; i < mdlRmdls.nodes.size(); i++) {
		mdlRmdl = mdlRmdls.nodes[i];

		if (mdlRmdl->srefKFunction == "mgmt") dbswdbe->tblwdbemmodule->loadSrfByRef(mdlRmdl->corRefWdbeMModule, srefMgmt);
		else if (mdlRmdl->srefKFunction == "snk") dbswdbe->tblwdbemmodule->loadSrfByRef(mdlRmdl->corRefWdbeMModule, srefTo);
		else if (mdlRmdl->srefKFunction == "src") dbswdbe->tblwdbemmodule->loadSrfByRef(mdlRmdl->corRefWdbeMModule, srefFrom);
	};

	// FPGA case
	if (srefMgmt == "") dbswdbe->loadStringBySQL("SELECT mdl1.sref FROM TblWdbeMModule AS mdl1, TblWdbeMModule AS mdl2 WHERE mdl1.ref = mdl2.supRefWdbeMModule AND mdl2.ref = "
				+ to_string(refWdbeMModule), srefMgmt);

	if (srefTo == "") srefTo = srefMgmt;
	else if (srefFrom == "") srefFrom = srefMgmt;

	srefMgmt = StrMod::cap(srefMgmt);
	srefFrom = StrMod::cap(srefFrom);
	srefTo = StrMod::cap(srefTo);

	mgmtToNotFrom = (srefMgmt == srefTo);
	
	sref = srefBuf + srefFrom + "To" + srefTo;

	if (!mgmtToNotFrom) {
		srefrootMgmt = StrMod::cap(srefBuf) + "To" + srefTo;
		srefrootCor = StrMod::cap(srefBuf) + "From" + srefFrom;
	} else {
		srefrootMgmt =  StrMod::cap(srefBuf) + "From" + srefFrom;
		srefrootCor =  StrMod::cap(srefBuf) + "To" + srefTo;
	};

	return mgmtToNotFrom;
};

void Wdbe::analyzeCmd(
			DbsWdbe* dbswdbe
			, WdbeMCommand* cmd
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, ListWdbeAMCommandInvpar& ipas
			, ListWdbeAMCommandRetpar& rpas
			, string& supsref
			, string& subsref
		) {
	dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);
	dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

	getCmdSupsubsref(cmd, unt, ctr, supsref, subsref);
};

void Wdbe::getCmdSupsubsref(
			WdbeMCommand* cmd
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, string& supsref
			, string& subsref
		) {
	string s;
	size_t ptr;

	supsref = "";
	subsref = cmd->Fullsref;

	if (ctr) {
		// ex. CmdIdhwIcm2AcqGetFrame -> CtrIdhwIcm2Acq::CmdGetFrame
		supsref = ctr->Fullsref;

		ptr = subsref.find(supsref.substr(3));
		if (ptr != string::npos) subsref = subsref.substr(0, ptr) + subsref.substr(ptr + supsref.length()-3);

	} else if (unt) {
		// ex. CmdIdhwAxs2GetCp -> UntIdhwAxs2::CmdGetCp
		supsref = unt->Fullsref;

		ptr = subsref.find(supsref.substr(3));
		if (ptr != string::npos) subsref = subsref.substr(0, ptr) + subsref.substr(ptr + supsref.length()-3);
	};
};

void Wdbe::analyzeErr(
			DbsWdbe* dbswdbe
			, WdbeMError* err
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, ListWdbeAMErrorPar& epas
			, string& supsref
			, string& subsref
		) {
	dbswdbe->tblwdbeamerrorpar->loadRstByErr(err->ref, false, epas);

	getErrSupsubsref(err, unt, ctr, supsref, subsref);
};

void Wdbe::getErrSupsubsref(
			WdbeMError* err
			, WdbeMUnit* unt
			, WdbeMController* ctr
			, string& supsref
			, string& subsref
		) {
	string s;
	size_t ptr;

	supsref = "";
	subsref = err->Fullsref;

	if (ctr) {
		// ex. ErrIdhwBss3PmmuInvalid -> CtrIdhwBss3Pmmu::ErrInvalid
		supsref = ctr->Fullsref;

		ptr = subsref.find(supsref.substr(3));
		if (ptr != string::npos) subsref = subsref.substr(0, ptr) + subsref.substr(ptr + supsref.length()-3);

	} else if (unt) {
		// ex. ErrIdhwAxs2Stuck -> UntIdhwAxs2::ErrStuck
		supsref = unt->Fullsref;

		ptr = subsref.find(supsref.substr(3));
		if (ptr != string::npos) subsref = subsref.substr(0, ptr) + subsref.substr(ptr + supsref.length()-3);
	};
};

unsigned int Wdbe::getLenInv(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMCommand
		) {
	unsigned int len = 0;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(refWdbeMCommand, false, ipas);

	for (unsigned int i = 0; i < ipas.nodes.size(); i++) {
		ipa = ipas.nodes[i];
		len += getParlen(ipa->ixWdbeVPartype, ipa->Length);
	};

	return len;
};

unsigned int Wdbe::getLenRet(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMCommand
		) {
	unsigned int len = 0;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(refWdbeMCommand, false, rpas);

	for (unsigned int i = 0; i < rpas.nodes.size(); i++) {
		rpa = rpas.nodes[i];
		len += getParlen(rpa->ixWdbeVPartype, rpa->Length);
	};

	return len;
};

unsigned int Wdbe::getLenErr(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMError
		) {
	unsigned int len = 0;

	ListWdbeAMErrorPar epas;
	WdbeAMErrorPar* epa = NULL;

	dbswdbe->tblwdbeamerrorpar->loadRstByErr(refWdbeMError, false, epas);

	for (unsigned int i = 0; i < epas.nodes.size(); i++) {
		epa = epas.nodes[i];
		len += getParlen(epa->ixWdbeVPartype, epa->Length);
	};

	return len;
};

string Wdbe::getCompsref(
			DbsWdbe* dbswdbe
			, WdbeMModule* mdl
		) {
	string compsref = mdl->sref;

	WdbeMModule* mtp = NULL;

	ListWdbeAMModulePar mpas;
	WdbeAMModulePar* mpa = NULL;

	string s;

	if (mdl->tplRefWdbeMModule != 0) if (dbswdbe->tblwdbemmodule->loadRecByRef(mdl->tplRefWdbeMModule, &mtp)) {
		dbswdbe->tblwdbeammodulepar->loadRstByMdl(mdl->ref, false, mpas);

		if (mpas.nodes.size() == 0) {
			// implies no mtp->Srefrule and no customization
			compsref = mtp->sref;

		} else {
			if (mtp->Srefrule != "") {
				compsref = mtp->Srefrule;

				for (unsigned int i = 0; i < mpas.nodes.size(); i++) {
					mpa = mpas.nodes[i];
					compsref = StrMod::replacePlh(compsref, mpa->x1SrefKKey, StrMod::dotToUsc(mpa->Val));
				};

				if (compsref.find("&untsref;") != string::npos) {
					dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMUnit WHERE ref = " + to_string(mdl->hkUref), s);
					compsref = StrMod::replacePlh(compsref, "untsref", s);
				};

			} else {
				// internal customization without sref change
				if ((mtp->ixVBasetype == VecWdbeVMModuleBasetype::MNFCORE) || (mtp->ixVBasetype == VecWdbeVMModuleBasetype::MNFPRIM)) compsref = mtp->sref;
				//else compsref = mdl->sref;
			};

		 };

		delete mtp;
	};

	return compsref;
};

void Wdbe::setMpa(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& x1SrefKKey
			, const string& Val
		) {
	uint mdlNum;

	WdbeAMModulePar* mpa = NULL;

	if (dbswdbe->tblwdbeammodulepar->loadRecBySQL("SELECT * FROM TblWdbeAMModulePar WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND x1SrefKKey = '" + x1SrefKKey + "'", &mpa)) {
		mpa->Val = Val;
		dbswdbe->tblwdbeammodulepar->updateRec(mpa);

		delete mpa;

	} else {
		mdlNum = 1;
		if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeAMModulePar WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY mdlNum DESC LIMIT 1", mdlNum)) mdlNum++;

		dbswdbe->tblwdbeammodulepar->insertNewRec(NULL, refWdbeMModule, mdlNum, x1SrefKKey, Val);
	};
};

bool Wdbe::getGenDfv(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& sref
			, string& Defval
		) {
	return(dbswdbe->loadStringBySQL("SELECT Defval FROM TblWdbeMGeneric WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = '" + sref + "'", Defval));
};

void Wdbe::setGenDfv(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& sref
			, const string& Defval
		) {
	
	dbswdbe->executeQuery("UPDATE TblWdbeMGeneric SET Defval = '" + Defval + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = '" + sref + "'");
};

void Wdbe::setGenSrc(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& sref
			, const string& srcSrefWdbeMGeneric
		) {
	dbswdbe->executeQuery("UPDATE TblWdbeMGeneric SET srcSrefWdbeMGeneric = '" + srcSrefWdbeMGeneric + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = '" + sref + "'");
};

void Wdbe::setPrtWdt(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& sref
			, const usmallint Width
		) {
	dbswdbe->executeQuery("UPDATE TblWdbeMPort SET Width = " + to_string((int) Width) + " WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = '" + sref + "'");
};

void Wdbe::setPrtDfv(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& sref
			, const string& Defval
		) {
	dbswdbe->executeQuery("UPDATE TblWdbeMPort SET Defval = '" + Defval + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = '" + sref + "'");
};

void Wdbe::setPrtCpi(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& sref
			, const string& cpiSrefWdbeMPin
		) {
	dbswdbe->executeQuery("UPDATE TblWdbeMPort SET cpiSrefWdbeMPin = '" + cpiSrefWdbeMPin + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = '" + sref + "'");
};

void Wdbe::setPrtCpr(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& sref
			, const string& cprSrefWdbeMPort
		) {
	dbswdbe->executeQuery("UPDATE TblWdbeMPort SET cprSrefWdbeMPort = '" + cprSrefWdbeMPort + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = '" + sref + "'");
};

void Wdbe::setPrtCsi(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
			, const string& sref
			, const string& csiSrefWdbeMSignal
		) {
	dbswdbe->executeQuery("UPDATE TblWdbeMPort SET csiSrefWdbeMSignal = '" + csiSrefWdbeMSignal + "' WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " AND sref = '" + sref + "'");
};

unsigned int Wdbe::getParlen(
			const uint ixWdbeVPartype
			, const utinyint Length
		) {
	switch (ixWdbeVPartype) {
		case VecWdbeVPartype::TIX:
		case VecWdbeVPartype::_BOOL:
		case VecWdbeVPartype::INT8:
		case VecWdbeVPartype::UINT8:
			return(1);
		case VecWdbeVPartype::INT16:
		case VecWdbeVPartype::UINT16:
			return(2);
		case VecWdbeVPartype::INT32:
		case VecWdbeVPartype::UINT32:
			return(4);
		case VecWdbeVPartype::BLOB:
			return(Length);
		case VecWdbeVPartype::VBLOB:
			return(Length+1);
	};

	return 0;
};

unsigned int Wdbe::getMinmaxMax(
			const string& Minmax
		) {
	// ex. 12..1234 -> 1234
	size_t ptr;

	ptr = Minmax.find("..");

	if (ptr == string::npos) return(atoi(Minmax.c_str()));
	else return(atoi(Minmax.substr(ptr + 2).c_str()));
};

void Wdbe::getRange(
			const string& s
			, string& sref
			, bool& hasrng
			, utinyint& from
			, utinyint& to
			, string& ix
		) {
	string rng;

	size_t ptr, ptr2;

	utinyint imd;

	hasrng = false;
	from = 0;
	to = 0;
	ix = "";

	ptr = s.find('[');

	if (ptr == string::npos) {
		sref = s;

	} else {
		sref = s.substr(0, ptr);
		hasrng = true;

		ptr2 = s.find(']', ptr);
		if (ptr != string::npos) {
			if (ptr2 > (ptr+1)) {
				rng = s.substr(ptr+1, ptr2-ptr-1);

				ptr = rng.find("..");
				if (ptr == string::npos) {
					if ((rng[0] >= '0') && (rng[0] <= '9')) {
						from = atoi(rng.c_str());
						to = from;
					} else {
						ix = rng;
					};
				} else {
					from = atoi(rng.substr(0, ptr).c_str());
					to = atoi(rng.substr(ptr+2).c_str());
				};
			};
		};
	};

	if (from > to) {
		imd = from;
		from = to;
		to = imd;
	};
};

void Wdbe::levelUntmdls(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMUnit
			, ListWdbeMModule& mdls
			, vector<unsigned int>& lvlsMdls
		) {
	// lowest level (0): top, highest level: bottom
	// generally, follow hierarchy defined by supRefWdbeMModule
	// exception 1: cmdinv needs to be above ctr
	// exception 2: dbg, dbgctr, edbgctr need to be above all but top
	// exception 3: an imbuf's corresponding module needs to be above the imbuf's host module
	//   covered by this: hostif needs to be above cmdinv/cmdret (once WdbeModbscCmdinvtd/WdbeModbscCmdrettd have added buf)

	// ex. of levels for icm2
	// icm2: 0
	// icm2-hostif: 1
	// icm2-cmdbus: 1
	// icm2-cmdinv: 2
	// icm2-cmdinv-buf: 3 (cor. module: icm2-hostif)
	// icm2-cmdret: 2
	// icm2-cmdret-buf: 3 (cor. module: icm2-hostif)
	// icm2-acq: 3
	// icm2-acq-buf: 4
	// icm2-wavegen: 3
	// icm2-wavegen-buf: 4

	// ex. of levels for dcx3 (imb lwiracqToPmmu doesn't touch hostif)
	// dcx3: 0
	// dcx3-hostif: 1
	// dcx3-cmdbus: 1
	// dcx3-cmdinv: 2
	// dcx3-cmdinv-buf: 3 (cor. module: dcx3-hostif)
	// dcx3-cmdret: 2
	// dcx3-cmdret-buf: 3 (cor. module: dcx3-hostif)
	// dcx3-lwiracq: 4
	// dcx3-lwiracq-buf: 5 (cor. module: dcx3-pmmu)
	// dcx3-pmmu: 3
	// dcx3-pmmu-buf: 4 (cor. module: dcx3-hostif)

	ubigint ref;

	WdbeMModule* mdl = NULL;

	map<ubigint,unsigned int> icsMdls;
	unsigned int ixMdlsCmdinv; // index of (single) cmdinv module
	set<unsigned int> icsMdlsDbg; // indices of dbg, dbgctr and edbgctr modules
	map<ubigint,unsigned int> icsMdlsCor; // index of corresponding module for each imbuf module

	unsigned int lvl;

	bool changed;

	dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " ORDER BY hkNum ASC", false, mdls);
	for (unsigned int i = 0; i < mdls.nodes.size(); i++) icsMdls[mdls.nodes[i]->ref] = i;

	ixMdlsCmdinv = mdls.nodes.size();

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CMDINV) {
			ixMdlsCmdinv = i;

		} else if ((mdl->ixVBasetype == VecWdbeVMModuleBasetype::DBG) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::DBGCTR) || (mdl->ixVBasetype == VecWdbeVMModuleBasetype::EDBGCTR)) {
			icsMdlsDbg.insert(i);

		} else if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::IMBUF) {
			if (dbswdbe->loadRefBySQL("SELECT corRefWdbeMModule FROM TblWdbeRMModuleMModule WHERE ctdRefWdbeMModule = " + to_string(mdl->refWdbeMImbuf) + " AND (srefKFunction = 'src' OR srefKFunction = 'snk')", ref)) {
				auto it = icsMdls.find(ref);
				if (it != icsMdls.end()) icsMdlsCor[mdl->ref] = it->second;
			};
		};
	};

	// - establish levels starting from all-zero
	lvlsMdls.clear();
	lvlsMdls.resize(mdls.nodes.size(), 0);

	changed = true;
	while (changed) {
		changed = false;

		for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
			mdl = mdls.nodes[i];

			auto it = icsMdls.find(mdl->supRefWdbeMModule);

			if (it != icsMdls.end()) {
				// require level of super module to be inferior
				lvl = lvlsMdls[it->second];

				if (lvlsMdls[i] <= lvl) {
					lvlsMdls[i] = lvl+1;
					changed = true;
				};
			};

			if (ixMdlsCmdinv != mdls.nodes.size()) {
				if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::CTR) {
					// require level of cmdinv to be inferior
					lvl = lvlsMdls[ixMdlsCmdinv];

					if (lvlsMdls[i] <= lvl) {
						lvlsMdls[i] = lvl+1;
						changed = true;
					};
				};
			};

			if ((mdl->ixVBasetype != VecWdbeVMModuleBasetype::TOP) && (mdl->ixVBasetype != VecWdbeVMModuleBasetype::DBG) && (mdl->ixVBasetype != VecWdbeVMModuleBasetype::DBGCTR) && (mdl->ixVBasetype != VecWdbeVMModuleBasetype::EDBGCTR)) {
				// require level of any debug module to be inferior
				for (auto it = icsMdlsDbg.begin(); it != icsMdlsDbg.end(); it++) {
					lvl = lvlsMdls[*it];

					if (lvlsMdls[i] <= lvl) {
						lvlsMdls[i] = lvl+1;
						changed = true;
					};
				};
			};

			if (mdl->ixVBasetype == VecWdbeVMModuleBasetype::IMBUF) {
				auto it = icsMdlsCor.find(mdl->ref);

				if (it != icsMdlsCor.end()) {
					auto it2 = icsMdls.find(mdl->supRefWdbeMModule);
					
					if (it2 != icsMdls.end()) {
						// require level of corresponding module to be inferior to that of the imb's super module
						lvl = lvlsMdls[it->second];

						if (lvlsMdls[it2->second] <= lvl) {
							lvlsMdls[it2->second] = lvl+1;
							changed = true;
						};
					};
				};
			};
		};
	};
};

void Wdbe::sortMdls(
			ListWdbeMModule& mdls
			, vector<unsigned int>& lvlsMdls
			, bool buNotTd
		) {
	WdbeMModule* mdl = NULL;

	unsigned int lvl;

	unsigned int ixpvt;

	for (unsigned int i = 0; i < lvlsMdls.size();i++) {
		ixpvt = i;

		for (unsigned int j=(i+1);j<lvlsMdls.size();j++) {
			if (!buNotTd && (lvlsMdls[j] < lvlsMdls[ixpvt])) ixpvt = j;
			else if (buNotTd && (lvlsMdls[j] > lvlsMdls[ixpvt])) ixpvt = j;
		};

		if (ixpvt != i) {
			mdl = mdls.nodes[i];
			mdls.nodes[i] = mdls.nodes[ixpvt];
			mdls.nodes[ixpvt] = mdl;

			lvl = lvlsMdls[i];
			lvlsMdls[i] = lvlsMdls[ixpvt];
			lvlsMdls[ixpvt] = lvl;
		};
	};
};

void Wdbe::levelMdls(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMVersion
			, ListWdbeMModule& mdls
			, vector<unsigned int>& lvlsMdls
			, bool buNotTd
		) {
	ListWdbeMUnit unts;
	WdbeMUnit* unt = NULL;
	vector<unsigned int> lvlsUnts;

	ListWdbeMModule untmdls;
	vector<unsigned int> lvlsUntmdls;

	dbswdbe->tblwdbemunit->loadRstBySQL("SELECT * FROM TblWdbeMUnit WHERE refIxVTbl = " + to_string(VecWdbeVMUnitRefTbl::VER) + " AND refUref = " + to_string(refWdbeMVersion), false, unts);

	mdls.clear();
	lvlsMdls.clear();

	for (unsigned int i = 0; i < unts.nodes.size(); i++) {
		unt = unts.nodes[i];

		levelUntmdls(dbswdbe, unt->ref, untmdls, lvlsUntmdls);

		for (unsigned int j = 0; j < untmdls.nodes.size(); j++) {
			mdls.nodes.push_back(untmdls.nodes[j]);
			lvlsMdls.push_back(lvlsUntmdls[j]);
		};

		untmdls.nodes.resize(0);
	};

	sortMdls(mdls, lvlsMdls, buNotTd);
};

void Wdbe::showLvlsMdls(
			DbsWdbe* dbswdbe
			, ListWdbeMModule& mdls
			, vector<unsigned int>& lvlsMdls
		) {
	WdbeMModule* mdl = NULL;

	for (unsigned int i = 0; i < mdls.nodes.size(); i++) {
		mdl = mdls.nodes[i];

		cout << lvlsMdls[i] << ":";
		if (mdl->hkIxVTbl == VecWdbeVMModuleHkTbl::UNT) cout << " " << StubWdbe::getStubUntSref(dbswdbe, mdl->hkUref);
		cout << " " << StubWdbe::getStubMdlHsref(dbswdbe, mdl->ref) << endl;
	};
};

uint Wdbe::getNextPrtMdlNum(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMModule
		) {
	uint mdlNum = 1;

	if (dbswdbe->loadUintBySQL("SELECT mdlNum FROM TblWdbeMPort WHERE mdlRefWdbeMModule = " + to_string(refWdbeMModule) + " ORDER BY mdlNum DESC LIMIT 1", mdlNum)) mdlNum++;

	return mdlNum;
};

uint Wdbe::getNextSigRefNum(
			DbsWdbe* dbswdbe
			, const uint refIxVTbl
			, const ubigint refUref
		) {
	uint refNum = 1;

	if (dbswdbe->loadUintBySQL("SELECT refNum FROM TblWdbeMSignal WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY refNum DESC LIMIT 1", refNum)) refNum++;

	return refNum;
};

uint Wdbe::getNextVarRefNum(
			DbsWdbe* dbswdbe
			, const uint refIxVTbl
			, const ubigint refUref
		) {
	uint refNum = 1;

	if (dbswdbe->loadUintBySQL("SELECT refNum FROM TblWdbeMVariable WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY refNum DESC LIMIT 1", refNum)) refNum++;

	return refNum;
};

void Wdbe::setFsmDbgtaptype(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMFsm
		) {
	WdbeMFsm* fsm = NULL;

	ListWdbeMFsmstate fsts;
	WdbeMFsmstate* fst = NULL;

	uint cntNoclust = 0;
	set<ubigint> refsClusts;
	uint cnt;

	if (dbswdbe->tblwdbemfsm->loadRecByRef(refWdbeMFsm, &fsm)) {
		fsm->ixVDbgtaptype = VecWdbeVMFsmDbgtaptype::CLUST;

		dbswdbe->tblwdbemfsmstate->loadRstByFsm(refWdbeMFsm, false, fsts);

		for (unsigned int i = 0; i < fsts.nodes.size(); i++) {
			fst = fsts.nodes[i];

			if (fst->refWdbeCFsmstate == 0) cntNoclust++;
			else refsClusts.insert(fst->refWdbeCFsmstate);
		};

		if ((cntNoclust + refsClusts.size()) > 15) fsm->ixVDbgtaptype = VecWdbeVMFsmDbgtaptype::LIN;
		else {
			for (auto it = refsClusts.begin(); it != refsClusts.end(); it++) {
				cnt = 0;

				for (unsigned int i = 0; i < fsts.nodes.size(); i++) {
					fst = fsts.nodes[i];

					if (fst->refWdbeCFsmstate == *it) {
						cnt++;

						if (cnt > 9) {
							fsm->ixVDbgtaptype = VecWdbeVMFsmDbgtaptype::LIN;
							break;
						};
					};
				};

				if (fsm->ixVDbgtaptype == VecWdbeVMFsmDbgtaptype::LIN) break;
			};
		};

		dbswdbe->tblwdbemfsm->updateRec(fsm);

		delete fsm;
	};
};

ubigint Wdbe::getHostifRef(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMUnit
		) {
	ubigint ref = 0;

	dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit)
				+ " AND (ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF) + " OR ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::EHOSTIF) + ")", ref);

	return ref;
};

string Wdbe::getHostifSref(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMUnit
		) {
	string s;

	dbswdbe->loadStringBySQL("SELECT sref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit)
				+ " AND (ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF) + " OR ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::EHOSTIF) + ")", s);

	return s;
};

unsigned int Wdbe::getHostifWidth(
			DbsWdbe* dbswdbe
			, const ubigint refWdbeMUnit
		) {
	unsigned int w = 8;

	ubigint ref;

	string s;

	if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = "
				+ to_string(refWdbeMUnit) + " AND (ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::HOSTIF) + " OR ixVBasetype = "
				+ to_string(VecWdbeVMModuleBasetype::EHOSTIF) + ")", ref)) {

		if (Wdbe::getMpa(dbswdbe, ref, "wD", s)) w = atoi(s.c_str());
	};

	return w;
};

void Wdbe::getHostifSizeInvretbuf(
			DbsWdbe* dbswdbe
			, const Sbecore::ubigint refWdbeMUnit
			, unsigned int& sizeInvbuf
			, unsigned int& sizeRetbuf
		) {
	vector<ubigint> refs, refs2;

	unsigned int len;

	sizeInvbuf = 2; // min. 2 (CRC only)
	sizeRetbuf = 2; // min. 2 (CRC only)

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::UNT) + " AND refUref = " + to_string(refWdbeMUnit), false, refs2);

	dbswdbe->loadRefsBySQL("SELECT refWdbeMController FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT) + " AND hkUref = " + to_string(refWdbeMUnit) + " AND (ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::ECTR) + " OR ixVBasetype = "
				+ to_string(VecWdbeVMModuleBasetype::EDBGCTR) + ")", false, refs);
	for (unsigned int i = 0; i < refs.size(); i++) dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(VecWdbeVMCommandRefTbl::CTR) + " AND refUref = " + to_string(refs[i]), true, refs2);

	for (unsigned int j = 0; j < refs2.size();j++) {
		len = Wdbe::getLenInv(dbswdbe, refs2[j]) + 2;
		if (len > sizeInvbuf) sizeInvbuf = len;

		len = Wdbe::getLenRet(dbswdbe, refs2[j]) + 2;
		if (len > sizeRetbuf) sizeRetbuf = len;
	};
};

unsigned int Wdbe::valToWidth(
			unsigned long long val
		) {
	unsigned int w = 0;

	while (val != 0) {
		val >>= 1;
		w++;
	};

	return w;
};

string Wdbe::getVecSubsref(
			const string& Skipsref
			, const string& sref
		) {
	// ex. VecVSimdZudvkCoulcntCommand -> VCoulcntCommand
	// ex. VecVSimdArtyBuffer -> VArtyBuffer
	string s;

	size_t ptr;

	if (sref.length() > 4) {
		s = sref.substr(3);

		ptr = s.find(Skipsref);
		if (ptr != string::npos) s = s.substr(0, 1) + s.substr(ptr + Skipsref.length());
	};

	return s;
};

string Wdbe::binToHex(
			unsigned char bin
		) {
	string hex;

	unsigned char c;

	c = (bin >> 4) + 0x30;
	if (c > 0x39) c += 0x07;
	hex += (char) c;

	c = (bin & 0x0F) + 0x30;
	if (c > 0x39) c += 0x07;
	hex += (char) c;
	
	return hex;
};

unsigned char Wdbe::hexToBin(
			string hex
		) {
	if (hex.size() != 2) return 0;

	unsigned char c, bin;

	c = hex[0];
	if ((c >= '0') && (c <= '9')) c -= 0x30;
	else if ((c >= 'A') && (c <= 'F')) c = c - 0x41 + 0x0A;
	else if ((c >= 'a') && (c <= 'f')) c = c - 0x61 + 0x0A;
	else c = 0;
	bin = (c << 4);

	c = hex[1];
	if ((c >= '0') && (c <= '9')) c -= 0x30;
	else if ((c >= 'A') && (c <= 'F')) c = c - 0x41 + 0x0A;
	else if ((c >= 'a') && (c <= 'f')) c = c - 0x61 + 0x0A;
	else c = 0;
	bin += c;

	return bin;
};

void Wdbe::appendToTmpfile(
			const string& tmppath
			, string& logfile
			, fstream& logfi
			, const string& err
		) {
	string s;

	if (!logfi.is_open()) {
		logfile = Tmp::newfile(tmppath, "txt");

		s = tmppath + "/" + logfile;
		logfi.open(s.c_str(), ios::out);
	};

	logfi << err << endl;
};

int Wdbe::run(
			const string& cmd
		) {
	int retval = 0;

	pid_t pid;
	int stat;

	//retval = system(cmd.c_str());

	pid = fork();

	if (pid == -1) {
		// no child process
		cout << "error" << endl;

	} else if (pid == 0) {
		// child process
		setsid();
		execl("/bin/bash", "bash", "-c", cmd.c_str(), (char*) NULL);
		_exit(0);

	} else {
		// parent process, wait for child process to terminate
		while (waitpid(pid, &stat, 0) == -1) if (errno != EINTR) break;
		if (WIFEXITED(stat)) retval = WEXITSTATUS(stat);
	};

	if (retval != 0) cout << "command '" << cmd << "' returned exit code " << retval << endl;

	return retval;
};

bool Wdbe::tgz(
			const string& infolder
			, const string& tgzfile
			, const bool verbose
		) {
	string cmd;

	cmd = "tar -pcz";
	if (verbose) cmd += "v";
	cmd += "f " + tgzfile + " -C " + infolder + " .";

	return(run(cmd) == 0);
};

bool Wdbe::untgz(
			const string& tgzfile
			, const string& outfolder
			, const bool verbose
		) {
	bool retval;

	string cmd;

	bool newdir = false;

	if (access(outfolder.c_str(), R_OK | W_OK) == -1) {
#ifdef _WIN32
		mkdir(outfolder.c_str());
#else
		mkdir(outfolder.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif
		newdir = true;
	};

	cmd = "tar -pxz";
	if (verbose) cmd += "v";
	cmd += "f " + tgzfile + " -C " + outfolder;

	retval = (run(cmd) == 0);

	if (!retval && newdir) rmdir(outfolder.c_str());

	return retval;
};
// IP gbl --- IEND

/******************************************************************************
 namespace OpengWdbe
 ******************************************************************************/

void OpengWdbe::getIcsWdbeVOppackByIxWdbeVOpengtype(
			const uint ixWdbeVOpengtype
			, vector<uint>& icsWdbeVOppack
		) {
	icsWdbeVOppack.clear();

	if (ixWdbeVOpengtype == VecWdbeVOpengtype::WDBEOPD1) {
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBECPLMST);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEGEN);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEGENFST);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEPLHFPGA);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEPLHMCU);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEPRCFILE);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEPRCTREE);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEWRDEV);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEWRFPGA);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEWRMCU);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEWRTERM);
	} else if (ixWdbeVOpengtype == VecWdbeVOpengtype::WDBEOPD2) {
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEMTPCPLMSTBU);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEMTPCPLMSTTD);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEMTPGENFST);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEMTPPLHFPGA);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEMTPPLHMCU);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEMTPWRFPGA);
		push_back(icsWdbeVOppack, VecWdbeVOppack::WDBEMTPWRMCU);
	};
};

void OpengWdbe::getIcsWdbeVDpchByIxWdbeVOppack(
			const uint ixWdbeVOppack
			, set<uint>& icsWdbeVDpch
		) {
	if (ixWdbeVOppack == VecWdbeVOppack::WDBECPLMST) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBECPLMSTCTRECTRHOSTIFEHOSTIF);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBECPLMSTIMBUF);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBECPLMSTTPLCPY);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBECPLMSTUNT);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEGEN) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENAUX);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENSTDVEC);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENWIRING);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEGENFST) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENFSTCMDBUS);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENFSTCTR);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENFSTECTR);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENFSTEHOSTIF);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENFSTHOSTIF);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENFSTIMBUF);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENFSTPPL);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEGENFSTTOP);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEMTPCPLMSTBU) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTBU);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEMTPCPLMSTTD) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEMTPCPLMSTTD);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEMTPGENFST) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEMTPGENFST);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEMTPPLHFPGA) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEMTPPLHFPGA);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEMTPPLHMCU) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEMTPPLHMCU);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEMTPWRFPGA) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEMTPWRFPGA);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEMTPWRMCU) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEMTPWRMCU);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEPLHFPGA) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPLHFPGACMDINV);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPLHFPGACMDRET);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPLHFPGACTR);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEPLHMCU) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPLHMCUECTR);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPLHMCUEHOSTIF);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEPRCFILE) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPRCFILECONCAT);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPRCFILEPLHRPL);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEPRCTREE) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPRCTREEEXTRACT);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPRCTREEMERGE);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEPRCTREEVALIDATE);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEWRDEV) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRDEVBASE);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRDEVCTR);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRDEVDEPLOY);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRDEVUNT);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEWRFPGA) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRFPGAAUX);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRFPGABASE);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRFPGACTR);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRFPGADEPLOY);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLFINE);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRFPGAMDLRAW);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRFPGATOP);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEWRMCU) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRMCUBASE);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRMCUCTR);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRMCUDEPLOY);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRMCUMDLFINE);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRMCUMDLRAW);
	} else if (ixWdbeVOppack == VecWdbeVOppack::WDBEWRTERM) {
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRTERMDEPLOY);
		insert(icsWdbeVDpch, VecWdbeVDpch::DPCHINVWDBEWRTERMMAIN);
	};
};

/******************************************************************************
 namespace StubWdbe
 ******************************************************************************/

string StubWdbe::getStub(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVStub
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEBNKSREF) return getStubBnkSref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEBNKSTD) return getStubBnkStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBECDCDSTD) return getStubCdcdStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBECMDSTD) return getStubCmdStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBECMPSTD) return getStubCmpStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBECPRSTD) return getStubCprStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBECTRLONG) return getStubCtrLong(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBECTRSREF) return getStubCtrSref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBECTRSTD) return getStubCtrStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBECVRNO) return getStubCvrNo(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBECVRSTD) return getStubCvrStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEERRSTD) return getStubErrStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEFAMSTD) return getStubFamStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEFILSTD) return getStubFilStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEFSMSTD) return getStubFsmStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEFSTSTD) return getStubFstStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEGENSTD) return getStubGenStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEGROUP) return getStubGroup(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEIMBSTD) return getStubImbStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEINTSTD) return getStubIntStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBELIBSREF) return getStubLibSref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBELIBSTD) return getStubLibStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEMCHSREF) return getStubMchSref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEMCHSTD) return getStubMchStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEMDLHSREF) return getStubMdlHsref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEMDLSREF) return getStubMdlSref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEMDLSTD) return getStubMdlStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEMODSTD) return getStubModStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEMTPSTD) return getStubMtpStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEOWNER) return getStubOwner(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEPINSTD) return getStubPinStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEPPHSTD) return getStubPphStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEPPLSTD) return getStubPplStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEPRCSTD) return getStubPrcStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEPRJSHORT) return getStubPrjShort(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEPRJSTD) return getStubPrjStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEPRSSTD) return getStubPrsStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEPRTSREF) return getStubPrtSref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEPRTSTD) return getStubPrtStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBERLSSTD) return getStubRlsStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBESEGHSREF) return getStubSegHsref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBESEGSREF) return getStubSegSref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBESEGSTD) return getStubSegStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBESESMENU) return getStubSesMenu(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBESESSTD) return getStubSesStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBESIGSREF) return getStubSigSref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBESIGSTD) return getStubSigStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBESILSTD) return getStubSilStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBESNSSTD) return getStubSnsStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEUNISTD) return getStubUniStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEUNTSREF) return getStubUntSref(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEUNTSTD) return getStubUntStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEUSGSTD) return getStubUsgStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEUSRPRS) return getStubUsrPrs(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEUSRSTD) return getStubUsrStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEVARSTD) return getStubVarStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEVECSTD) return getStubVecStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEVERNO) return getStubVerNo(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEVERSHORT) return getStubVerShort(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEVERSTD) return getStubVerStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWdbeVStub == VecWdbeVStub::STUBWDBEVITSTD) return getStubVitStd(dbswdbe, ref, ixWdbeVLocale, ixVNonetype, stcch, strefSub, refresh);

	return("");
};

string StubWdbe::getStubBnkSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "bank3"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEBNKSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no I/O bank)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbembank->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubBnkStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "bank3 3.3V"
	string stub;

	WdbeMBank* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEBNKSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no I/O bank)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbembank->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubBnkStd --- IBEGIN
			stub = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKMBANKVOLTSTD, rec->srefKVoltstd, ixWdbeVLocale);
			if (stub != "") stub = " " + stub;
			stub = rec->sref + stub;
			// IP getStubBnkStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubCdcdStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "mclk to mipiclk"
	string stub;

	WdbeMCdc* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBECDCDSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no clock domain crossing)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemcdc->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubCdcdStd --- IBEGIN
			stub = rec->fckSrefWdbeMSignal + " <-> " + rec->sckSrefWdbeMSignal;

			// IP getStubCdcdStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubCmdStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "sync.setTon"
	string stub;

	WdbeMCommand* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBECMDSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no command)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemcommand->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubCmdStd --- IBEGIN
			if (rec->refIxVTbl == VecWdbeVMCommandRefTbl::CTR) {
				stub = getStubCtrSref(dbswdbe, rec->refUref, ixWdbeVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			} else if (rec->refIxVTbl == VecWdbeVMCommandRefTbl::UNT) {
				stub = rec->sref;
			};
			// IP getStubCmdStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubCmpStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "ezdevwskd"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBECMPSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no component)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemcomponent->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubCprStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "UART host interface"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBECPRSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no core project)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemcoreproject->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubCtrLong(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "UntIdhwFIcm2 acq"
	string stub;

	WdbeMController* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBECTRLONG, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no controller)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemcontroller->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubCtrLong --- IBEGIN
			ubigint refUnt = 0;
			dbswdbe->loadRefBySQL("SELECT hkUref FROM TblWdbeMModule WHERE ref = " + to_string(rec->refWdbeMModule) + " AND hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT), refUnt);

			stub = getStubUntSref(dbswdbe, refUnt, ixWdbeVLocale, ixVNonetype, stcch, &stref) + " " + getStubMdlSref(dbswdbe, rec->refWdbeMModule, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			// IP getStubCtrLong --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubCtrSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "CtrIdhwCFIcm2Acq"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBECTRSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no controller)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemcontroller->loadFsrByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubCtrStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "acq"
	string stub;

	WdbeMController* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBECTRSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no controller)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemcontroller->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubCtrStd --- IBEGIN
			stub = getStubMdlSref(dbswdbe, rec->refWdbeMModule, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			// IP getStubCtrStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubCvrNo(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "0.1.0"
	string stub;

	WdbeMCoreversion* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBECVRNO, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no core version)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemcoreversion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubCvrNo --- IBEGIN
			stub = to_string((int) (rec->Major)) + "." + to_string((int) (rec->Minor)) + "." + to_string((int) (rec->Sub));
			// IP getStubCvrNo --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubCvrStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "UART host interface 0.1.0"
	string stub;

	WdbeMCoreversion* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBECVRSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no core version)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemcoreversion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubCvrStd --- IBEGIN
			stub = getStubCprStd(dbswdbe, rec->refWdbeMCoreproject, ixWdbeVLocale, ixVNonetype, stcch, &stref) + " " + to_string((int) (rec->Major)) + "." + to_string((int) (rec->Minor)) + "." + to_string((int) (rec->Sub));
			// IP getStubCvrStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubErrStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "bufxferr"
	string stub;

	WdbeMError* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEERRSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no error)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemerror->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubErrStd --- IBEGIN
			if (rec->refIxVTbl == VecWdbeVMErrorRefTbl::CTR) {
				stub = getStubCtrSref(dbswdbe, rec->refUref, ixWdbeVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			} else if (rec->refIxVTbl == VecWdbeVMErrorRefTbl::UNT) {
				stub = rec->sref;
			};
			// IP getStubErrStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubFamStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Microchip PIC12"
	string stub;

	WdbeMFamily* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEFAMSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no product family)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemfamily->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubFamStd --- IBEGIN
			stub = dbswdbe->getKlstTitleBySref(VecWdbeVKeylist::KLSTWDBEKVENDOR, rec->srefWdbeKVendor, ixWdbeVLocale);
			if (stub != "") stub += " ";
			stub += rec->Title;
			// IP getStubFamStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubFilStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "customers.xlsx"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEFILSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no file)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemfile->loadFnmByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubFsmStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "op (mclk)"
	string stub;

	WdbeMFsm* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEFSMSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no finite state machine)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemfsm->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubFsmStd --- IBEGIN
			stub = getStubPrcStd(dbswdbe, rec->refWdbeMProcess, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			// IP getStubFsmStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubFstStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "waitStrbA"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEFSTSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no FSM state)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemfsmstate->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubGenStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "fMclk"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEGENSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no generic)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemgeneric->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubGroup(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "agroup"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEGROUP, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubImbStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "pvwabufCamacqToHostif"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEIMBSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no inter-module buffer)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemimbuf->loadFsrByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubIntStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "isrUART0"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEINTSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no interrupt)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbeminterrupt->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubLibSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "netcdf"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBELIBSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no library)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemlibrary->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubLibStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "netcdf 4.2.1.1"
	string stub;

	WdbeMLibrary* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBELIBSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no library)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemlibrary->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubLibStd --- IBEGIN
			stub = rec->sref;
			if (rec->Version != "") stub += " " + rec->Version;
			// IP getStubLibStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubMchSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "jack"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEMCHSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no machine)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemmachine->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubMchStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "any;ubuntu;mpsitech;jack"
	string stub;

	WdbeMMachine* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEMCHSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no machine)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemmachine->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->supRefWdbeMMachine != 0) stub = getStubMchStd(dbswdbe, rec->supRefWdbeMMachine, ixWdbeVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubMdlHsref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "icm2;wavegen;buf"
	string stub;

	WdbeMModule* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEMDLHSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no module)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemmodule->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->supRefWdbeMModule != 0) stub = getStubMdlHsref(dbswdbe, rec->supRefWdbeMModule, ixWdbeVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubMdlSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "acq"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEMDLSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no module)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemmodule->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubMdlStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "icm2;acq;buf (dpbram_v1_0) - vs. - spifwd_v1_0 forwarding controller"
	string stub;

	WdbeMModule* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEMDLSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no module)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemmodule->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubMdlStd --- IBEGIN
			if ((rec->hkIxVTbl != VecWdbeVMModuleHkTbl::VOID) || (rec->supRefWdbeMModule != 0) || (rec->tplRefWdbeMModule != 0)) {
				stub = getStubModStd(dbswdbe, rec->ref, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			} else {
				stub = getStubMtpStd(dbswdbe, rec->ref, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			};
			// IP getStubMdlStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubModStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "icm2;acq;buf (dpbram_v1_0)"
	string stub;

	WdbeMModule* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEMODSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no module)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemmodule->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubModStd --- IBEGIN
			string s;
			size_t ptr;

			stub = getStubMdlHsref(dbswdbe, rec->ref, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			
			if (rec->tplRefWdbeMModule != 0) {
				s = getStubMtpStd(dbswdbe, rec->tplRefWdbeMModule, ixWdbeVLocale, ixVNonetype, stcch, &stref);
				ptr = s.find(' ');
				if (ptr != string::npos) s = s.substr(0, ptr);

				stub += " (" + s + ")";

			} else if (rec->ixVBasetype != VecWdbeVMModuleBasetype::OTH) {
				stub += " (" + VecWdbeVMModuleBasetype::getTitle(rec->ixVBasetype, ixWdbeVLocale) + ")";
			};
			// IP getStubModStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubMtpStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "spifwd_v1_0 forwarding controller"
	string stub;

	WdbeMModule* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEMTPSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no module template)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemmodule->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubMtpStd --- IBEGIN
			stub = getStubMdlHsref(dbswdbe, rec->ref, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			if (rec->ixVBasetype != VecWdbeVMModuleBasetype::OTH) stub += " " + VecWdbeVMModuleBasetype::getTitle(rec->ixVBasetype, ixWdbeVLocale);
			// IP getStubMtpStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubOwner(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "auser"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEOWNER, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemuser->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubPinStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "mclkn (bank3, P23)"
	string stub;

	WdbeMPin* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEPINSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no pin)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbempin->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubPinStd --- IBEGIN
			stub = rec->sref + " (" + getStubBnkSref(dbswdbe, rec->refWdbeMBank, ixWdbeVLocale, ixVNonetype, stcch, &stref) + ", " + rec->Location + ")";
			// IP getStubPinStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubPphStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "spi1"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEPPHSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no peripheral)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemperipheral->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubPplStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "corner"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEPPLSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no pipeline)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbempipeline->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubPrcStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "op (mclk)"
	string stub;

	WdbeMProcess* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEPRCSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no process)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemprocess->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubPrcStd --- IBEGIN
			stub = rec->sref + " (" + rec->clkSrefWdbeMSignal + ")";
			// IP getStubPrcStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubPrjShort(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "idhw"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEPRJSHORT, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no project)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemproject->loadShoByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubPrjStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "ICARUSDetectorHardwareControl"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEPRJSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no project)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemproject->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubPrsStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Franz Kuntz"
	string stub;

	WdbeMPerson* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEPRSSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no person)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemperson->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWdbePrsStd --- BEGIN
			stub = rec->Lastname;
			if (rec->Firstname.length() > 0) stub = rec->Firstname + " " + stub;
			// IP getStubWdbePrsStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubPrtSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "mclk"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEPRTSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no port)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemport->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubPrtStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "dcx3;thetaif: mclk (input/output)"
	string stub;

	WdbeMPort* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEPRTSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no port)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemport->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubPrtStd --- IBEGIN
			stub = getStubMdlHsref(dbswdbe, rec->mdlRefWdbeMModule, ixWdbeVLocale, ixVNonetype, stcch, &stref) + ": " + rec->sref + " (" + VecWdbeVMPortDir::getTitle(rec->ixVDir, ixWdbeVLocale) + ")";
			// IP getStubPrtStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubRlsStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "devidhw_genio"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBERLSSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no release)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemrelease->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubSegHsref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "I-II;diff"
	string stub;

	WdbeMSegment* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBESEGHSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no segment)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemsegment->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->supRefWdbeMSegment != 0) stub = getStubSegHsref(dbswdbe, rec->supRefWdbeMSegment, ixWdbeVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubSegSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "diff"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBESEGSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no segment)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemsegment->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubSegStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "corner #1: IIIk;factk"
	string stub;

	WdbeMSegment* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBESEGSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no segment)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemsegment->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubSegStd --- IBEGIN
			stub = getStubPplStd(dbswdbe, rec->pplRefWdbeMPipeline, ixWdbeVLocale, ixVNonetype, stcch, &stref) + "#" + to_string(rec->pplNum) + " " + getStubSegHsref(dbswdbe, rec->ref, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			// IP getStubSegStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubSesMenu(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "user fkuntz / Franz Kuntz;logged in from 127.0.0.1;since 01-01-2010 10:34"
	string stub;

	WdbeMSession* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBESESMENU, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWdbeSesMenu --- BEGIN
			if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "user " + getStubUsrStd(dbswdbe, rec->refWdbeMUser, ixWdbeVLocale, ixVNonetype, stcch, &stref) + ";logged in from " + rec->Ip + ";since " + Ftm::stamp(rec->start);
			// IP getStubWdbeSesMenu --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubSesStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "01-01-2010 10:34 from 127.0.0.1"
	string stub;

	WdbeMSession* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBESESSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWdbeSesStd --- BEGIN
			if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = Ftm::stamp(rec->start) + " from " + rec->Ip;
			// IP getStubWdbeSesStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubSigSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "dCmdbus"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBESIGSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no signal)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemsignal->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubSigStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "reqCmdToOpInv (handshake)"
	string stub;

	WdbeMSignal* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBESIGSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no signal)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemsignal->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubSigStd --- IBEGIN
			stub = rec->sref + " (" + VecWdbeVMSignalBasetype::getTitle(rec->ixVBasetype, ixWdbeVLocale) + ")";
			// IP getStubSigStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubSilStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "pic16f15356-X/ss"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBESILSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no silicon device)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemunit->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubSnsStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "isrUART0 - vs. - mclk - vs. - dCmdbus"
	string stub;

	WdbeMSensitivity* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBESNSSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no sensitivity)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemsensitivity->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubSnsStd --- IBEGIN
			if (rec->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::INT) stub = getStubIntStd(dbswdbe, rec->srcUref, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			else if (rec->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::PRT) stub = getStubPrtSref(dbswdbe, rec->srcUref, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			else if (rec->srcIxVTbl == VecWdbeVMSensitivitySrcTbl::SIG) stub = getStubSigSref(dbswdbe, rec->srcUref, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			// IP getStubSnsStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubUniStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "axis2"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEUNISTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no unit)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemunit->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubUntSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "UntIdhwMAxs2"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEUNTSREF, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no unit)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemunit->loadFsrByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubUntStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "axis2 - vs. - pic16f15356-X/ss"
	string stub;

	WdbeMUnit* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEUNTSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no unit)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemunit->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubUntStd --- IBEGIN
			if (rec->silRefWdbeMUnit != 0) {
				stub = rec->Title;
			} else {
				stub = rec->sref;
			};
			// IP getStubUntStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubUsgStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "super"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEUSGSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubUsrPrs(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Franz Kuntz"
	string stub;

	WdbeMUser* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEUSRPRS, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubUsrPrs --- IBEGIN
			stub = getStubPrsStd(dbswdbe, rec->refWdbeMPerson, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			// IP getStubUsrPrs --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubUsrStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "fkuntz / Franz Kuntz"
	string stub;

	WdbeMUser* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEUSRSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWdbeUsrStd --- BEGIN
			stub = rec->sref + " / " + getStubPrsStd(dbswdbe, rec->refWdbeMPerson, ixWdbeVLocale, ixVNonetype, stcch, &stref);
			// IP getStubWdbeUsrStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubVarStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "bytecnt"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEVARSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no variable)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemvariable->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubVecStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "VecIcm2VCmd"
	string stub;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEVECSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no vector)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemvector->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWdbe::getStubVerNo(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "0.1.0"
	string stub;

	WdbeMVersion* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEVERNO, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no version)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemversion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubVerNo --- IBEGIN
			stub = to_string((int) (rec->Major)) + "." + to_string((int) (rec->Minor)) + "." + to_string((int) (rec->Sub));
			// IP getStubVerNo --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubVerShort(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "idhw v0.1.0 (23)"
	string stub;

	WdbeMVersion* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEVERSHORT, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no version)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemversion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = getStubPrjShort(dbswdbe, rec->prjRefWdbeMProject, ixWdbeVLocale, ixVNonetype, stcch, &stref) + " v" + to_string((int) (rec->Major)) + "." + to_string((int) (rec->Minor)) + "." + to_string((int) (rec->Sub)) + " (" + to_string(rec->prjNum) + ")"; // IP getStubVerShort --- ILINE
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubVerStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "ICARUSDetectorHardwareControl v0.1.0 (s/n 23, abandonned)"
	string stub;

	WdbeMVersion* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEVERSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no version)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemversion->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubVerStd --- IBEGIN
			stub = getStubPrjStd(dbswdbe, rec->prjRefWdbeMProject, ixWdbeVLocale, ixVNonetype, stcch, &stref) + " v" + to_string((int) (rec->Major)) + "." + to_string((int) (rec->Minor)) + "." + to_string((int) (rec->Sub));

			if (rec->ixVState != VecWdbeVMVersionState::READY) {
				stub += " (s/n " + to_string(rec->prjNum);
				if ((rec->ixVState == VecWdbeVMVersionState::NEWCRE) || (rec->ixVState == VecWdbeVMVersionState::NEWIMP) || (rec->ixVState == VecWdbeVMVersionState::ABANDON)) stub += ", " + VecWdbeVMVersionState::getTitle(rec->ixVState, ixWdbeVLocale);
				stub += ")"; 
			};
			// IP getStubVerStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWdbe::getStubVitStd(
			DbsWdbe* dbswdbe
			, const ubigint ref
			, const uint ixWdbeVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "VecIcm2VCmd.syncSetTon"
	string stub;

	WdbeMVectoritem* rec = NULL;

	stcchitemref_t stref(VecWdbeVStub::STUBWDBEVITSTD, ref, ixWdbeVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWdbeVLocale == VecWdbeVLocale::ENUS) stub = "(no vector item)";
	};

	if (ref != 0) {
		if (dbswdbe->tblwdbemvectoritem->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubVitStd --- IBEGIN
			stub = getStubVecStd(dbswdbe, rec->vecRefWdbeMVector, ixWdbeVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			// IP getStubVitStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

/******************************************************************************
 class WdbeException
 ******************************************************************************/

WdbeException::WdbeException(
			const uint ix
			, const map<string,string>& vals
		) :
			SbeException(ix, vals)
		{
};

string WdbeException::getSref() {
	string sref = SbeException::getSref();
	if (sref != "") return sref;
	
	if (ix == LIC_AUTH) return("lic.auth");
	if (ix == LIC_CTWARN) return("lic.ctwarn");
	if (ix == LIC_CTLOST) return("lic.ctlost");
	
	return("");
};

/******************************************************************************
 class ContInfWdbeAlert
 ******************************************************************************/

ContInfWdbeAlert::ContInfWdbeAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
			, const string& TxtMsg11
			, const string& TxtMsg12
		) :
			Block()
			, TxtCpt(TxtCpt)
			, TxtMsg1(TxtMsg1)
			, TxtMsg2(TxtMsg2)
			, TxtMsg3(TxtMsg3)
			, TxtMsg4(TxtMsg4)
			, TxtMsg5(TxtMsg5)
			, TxtMsg6(TxtMsg6)
			, TxtMsg7(TxtMsg7)
			, TxtMsg8(TxtMsg8)
			, TxtMsg9(TxtMsg9)
			, TxtMsg10(TxtMsg10)
			, TxtMsg11(TxtMsg11)
			, TxtMsg12(TxtMsg12)
		{

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10, TXTMSG11, TXTMSG12};
};

bool ContInfWdbeAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;
	if (!find(items, TXTMSG11)) return false;
	if (!find(items, TXTMSG12)) return false;

	return true;
};

void ContInfWdbeAlert::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag == "") difftag = "ContInfWdbeAlert";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtCpt"] = TxtCpt;
	me["TxtMsg1"] = TxtMsg1;
	me["TxtMsg2"] = TxtMsg2;
	me["TxtMsg3"] = TxtMsg3;
	me["TxtMsg4"] = TxtMsg4;
	me["TxtMsg5"] = TxtMsg5;
	me["TxtMsg6"] = TxtMsg6;
	me["TxtMsg7"] = TxtMsg7;
	me["TxtMsg8"] = TxtMsg8;
	me["TxtMsg9"] = TxtMsg9;
	me["TxtMsg10"] = TxtMsg10;
	me["TxtMsg11"] = TxtMsg11;
	me["TxtMsg12"] = TxtMsg12;
};

void ContInfWdbeAlert::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWdbeAlert";

	string itemtag;
	if (shorttags)
		itemtag = "Ci";
	else
		itemtag = "ContitemInfWdbeAlert";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCpt", TxtCpt);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg1", TxtMsg1);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg2", TxtMsg2);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg3", TxtMsg3);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg4", TxtMsg4);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg5", TxtMsg5);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg6", TxtMsg6);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg7", TxtMsg7);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg8", TxtMsg8);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg9", TxtMsg9);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg10", TxtMsg10);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg11", TxtMsg11);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg12", TxtMsg12);
	xmlTextWriterEndElement(wr);
};

set<uint> ContInfWdbeAlert::compare(
			const ContInfWdbeAlert* comp
		) {
	set<uint> items;

	if (TxtCpt == comp->TxtCpt) insert(items, TXTCPT);
	if (TxtMsg1 == comp->TxtMsg1) insert(items, TXTMSG1);
	if (TxtMsg2 == comp->TxtMsg2) insert(items, TXTMSG2);
	if (TxtMsg3 == comp->TxtMsg3) insert(items, TXTMSG3);
	if (TxtMsg4 == comp->TxtMsg4) insert(items, TXTMSG4);
	if (TxtMsg5 == comp->TxtMsg5) insert(items, TXTMSG5);
	if (TxtMsg6 == comp->TxtMsg6) insert(items, TXTMSG6);
	if (TxtMsg7 == comp->TxtMsg7) insert(items, TXTMSG7);
	if (TxtMsg8 == comp->TxtMsg8) insert(items, TXTMSG8);
	if (TxtMsg9 == comp->TxtMsg9) insert(items, TXTMSG9);
	if (TxtMsg10 == comp->TxtMsg10) insert(items, TXTMSG10);
	if (TxtMsg11 == comp->TxtMsg11) insert(items, TXTMSG11);
	if (TxtMsg12 == comp->TxtMsg12) insert(items, TXTMSG12);

	return(items);
};

/******************************************************************************
 class DpchWdbe
 ******************************************************************************/

DpchWdbe::DpchWdbe(
			const uint ixWdbeVDpch
		) :
			ixWdbeVDpch(ixWdbeVDpch)
		{
};

DpchWdbe::~DpchWdbe() {
};

/******************************************************************************
 class DpchInvWdbe
 ******************************************************************************/

DpchInvWdbe::DpchInvWdbe(
			const uint ixWdbeVDpch
			, const ubigint oref
			, const ubigint jref
		) :
			DpchWdbe(ixWdbeVDpch)
			, oref(oref)
			, jref(jref)
		{
};

DpchInvWdbe::~DpchInvWdbe() {
};

void DpchInvWdbe::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWdbe");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvWdbe::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbe");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWdbe
 ******************************************************************************/

DpchRetWdbe::DpchRetWdbe(
			const uint ixWdbeVDpch
			, const string& scrOref
			, const string& scrJref
			, const utinyint ixOpVOpres
			, const utinyint pdone
		) :
			DpchWdbe(ixWdbeVDpch)
			, scrOref(scrOref)
			, scrJref(scrJref)
			, ixOpVOpres(ixOpVOpres)
			, pdone(pdone)
		{
};

DpchRetWdbe::~DpchRetWdbe() {
};

void DpchRetWdbe::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWdbe");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxOpVOpres", "", srefIxOpVOpres)) {
			ixOpVOpres = VecOpVOpres::getIx(srefIxOpVOpres);
			add(IXOPVOPRES);
		};
		if (extractUtinyintUclc(docctx, basexpath, "pdone", "", pdone)) add(PDONE);
	};
};

void DpchRetWdbe::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWdbe");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wdbe");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
	xmlTextWriterEndElement(wr);
};
