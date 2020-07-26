/**
	* \file WdbePrctreeExtract.cpp
	* Wdbe operation processor - extract from file tree into extract file tree (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbePrctreeExtract.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePrctree;

/******************************************************************************
 namespace WdbePrctreeExtract
 ******************************************************************************/

DpchRetWdbePrctreeExtract* WdbePrctreeExtract::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePrctreeExtract* dpchinv
		) {
	string infile = dpchinv->infile;
	string infolder = dpchinv->infolder;
	string extfile = dpchinv->extfile;
	string extfolder = dpchinv->extfolder;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	fstream logfi;

	string s;

	logfile = Tmp::newfile(xchg->tmppath, "txt");

	s = xchg->tmppath + "/" + logfile;
	logfi.open(s.c_str(), ios::out);

	if ((infile.length() > 0) && (extfile.length() > 0)) {
		// single file
		if (!scanFile(xchg->tmppath, infile, extfile, logfi)) ixOpVOpres = VecOpVOpres::FAILURE;

	} else if ((infolder.length() > 0) && (extfolder.length() > 0)) {
		// directory tree
		if (!scanFolder(xchg->tmppath, infolder, extfolder, logfi)) ixOpVOpres = VecOpVOpres::FAILURE;
	};

	logfi.close();
	// IP run --- IEND

	return(new DpchRetWdbePrctreeExtract("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- IBEGIN
bool WdbePrctreeExtract::scanFolder(
			const string& tmppath
			, const string& infolder
			, const string& extfolder // no change in recursion
			, fstream& logfi
		) {
	bool success = true;

	DIR* dir = NULL;

	dirent* diritem = NULL;

	vector<string> folders;
	vector<string> files;

	bool keep = false;

	string s;

	s = tmppath + "/" + infolder;
	dir = opendir(s.c_str());

	if (dir) {
		// traverse directory I (survey)
		diritem = readdir(dir);
		while (diritem) {
			// avoid hidden items starting with '.' e.g. ".", "..", ".git" folders and ".DS_Store" files
			if (strncmp(diritem->d_name, ".", 1) != 0) {
				if (diritem->d_type == DT_DIR) {
					folders.push_back(diritem->d_name);

				} else if (diritem->d_type == DT_REG) {
					if (strcmp(diritem->d_name, "IP folder --- KEEP") == 0) keep = true;
					files.push_back(diritem->d_name);
				};
			};

			diritem = readdir(dir);
		};
		closedir(dir);
	};

	if ((folders.size() > 0) || (files.size() > 0)) {
		// generate corresponding directory in extfolder
		s = tmppath + "/" + extfolder;
		if (infolder.find('/') != string::npos) s = s + infolder.substr(infolder.find('/'));

		if (access(s.c_str(), R_OK | W_OK) == -1) {
#ifdef _WIN32
			mkdir(s.c_str());
#else
			mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif
		};

		if (keep) {
			Wdbe::run("cp -rp " + tmppath + "/" + infolder + "/* " + s + "/");

		} else {
			// traverse directory II (scan sub-folders and files)
			for (unsigned int i = 0; i < files.size(); i++) {
				// file: scan
				s = extfolder;
				if (infolder.find('/') != string::npos) s = s + infolder.substr(infolder.find('/'));
				s = s + "/" + files[i] + ".ip";

				if (!scanFile(tmppath, infolder + "/" + files[i], s, logfi)) success = false;
			};

			for (unsigned int i = 0; i < folders.size(); i++) {
				// sub-folder: scan recursively
				if (!scanFolder(tmppath, infolder + "/" + folders[i], extfolder, logfi)) success = false;
			};
		};
	};

	return success;
};

bool WdbePrctreeExtract::scanFile(
			const string& tmppath
			, const string& infile
			, const string& extfile
			, fstream& logfi
		) {
	bool success;

	vector<Ip*> ips;
	map<string,unsigned int> icsIpsAffirm;
	map<string,unsigned int> icsIpsRemove;
	map<string,unsigned int> icsIpsIline;
	map<string,unsigned int> icsIpsIbegin;
	map<string,unsigned int> icsIpsRline;
	map<string,unsigned int> icsIpsRbegin;

	unsigned int fmt;

	bool keep = false;

	// parse infile
	logfi << "processing file '" << infile << "'" << endl;
	success = parseFile(tmppath + "/" + infile, logfi, true, ips, fmt);

	if (success) {
		// check if file is to be kept w/o modification
		if (ips.size() > 0) if (ips[0]->type == Iptype::KEEP) keep = true;

		if (keep) {
			// copy entire file
			Wdbe::run("cp -p " + tmppath + "/" + infile + " " + tmppath + "/" + extfile);

		} else {
			// copy IP's only
			readFileContent(tmppath + "/" + infile, ips, icsIpsAffirm, icsIpsRemove, icsIpsIline, icsIpsIbegin, icsIpsRline, icsIpsRbegin);

			// omit files with no relevant content
			if (!(icsIpsAffirm.empty() && icsIpsRemove.empty() && icsIpsIline.empty() && icsIpsIbegin.empty() && icsIpsRline.empty() && icsIpsRbegin.empty())) writeExtfile(tmppath, extfile, ips);
		};
	};

	for (unsigned int i = 0; i < ips.size(); i++) delete ips[i];

	return success;
};

void WdbePrctreeExtract::writeExtfile(
			const string& tmppath
			, const string& extfile
			, const vector<Ip*>& ips
		) {
	fstream extfi;

	unsigned int skiptolineno = 0;

	Ip* ip = NULL;

	string s;

	// open extfile
	s = tmppath + "/" + extfile;
	extfi.open(s.c_str(), ios::out);
	if (extfi.fail()) return;

	// large number (don't skip)
	skiptolineno--;

	for (unsigned int i = 0; i < ips.size();i++) {
		ip = ips[i];
		if ((ip->type == Iptype::AFFIRM) || (ip->type == Iptype::REMOVE) || (ip->type == Iptype::ILINE) || (ip->type == Iptype::IBEGIN) || (ip->type == Iptype::RLINE) || (ip->type == Iptype::RBEGIN)) {
			for (unsigned int j = 0; j < ip->content.size();j++) extfi << ip->content[j] << endl;
		};

		if ((ip->type == Iptype::IBEGIN) || (ip->type == Iptype::RBEGIN)) {
			// skip content in infile up to END
			skiptolineno = ip->par->lineno;

			// skip insertion points up to END, will be adjusted to the next one after further down the code
			for (unsigned int j=i;j<ips.size();j++) {
				if (ip->par == ips[j]) {
					i = j;
					break;
				};
			};
		};
	};

	extfi.close();
};
// IP cust --- IEND


