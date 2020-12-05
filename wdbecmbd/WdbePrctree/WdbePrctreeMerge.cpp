/**
	* \file WdbePrctreeMerge.cpp
	* Wdbe operation processor - merge extract file tree into template file tree (implementation)
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

#include "WdbePrctreeMerge.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePrctree;

/******************************************************************************
 namespace WdbePrctreeMerge
 ******************************************************************************/

DpchRetWdbePrctreeMerge* WdbePrctreeMerge::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePrctreeMerge* dpchinv
		) {
	string extfile = dpchinv->extfile;
	string extfolder = dpchinv->extfolder;
	string tplfile = dpchinv->tplfile;
	string tplfolder = dpchinv->tplfolder;
	bool notrace = dpchinv->notrace;
	bool skipmultvoid = dpchinv->skipmultvoid;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	fstream logfi;

	string s;

	logfile = Tmp::newfile(xchg->tmppath, "txt");

	s = xchg->tmppath + "/" + logfile;
	logfi.open(s.c_str(), ios::out);

	if ((extfile.length() > 0) && (tplfile.length() > 0)) {
		// single file (merge extfile -> tplfile)
		if (!scanFile(xchg->tmppath, tplfile, extfile, notrace, skipmultvoid, logfi)) ixOpVOpres = VecOpVOpres::FAILURE;

	} else if ((extfolder.length() > 0) && (tplfolder.length() > 0)) {
		// directory tree (merge extfolder -> tplfolder)
		if (!scanFolder(xchg->tmppath, tplfolder, "", extfolder, notrace, skipmultvoid, logfi)) ixOpVOpres = VecOpVOpres::FAILURE;
		invscanFolder(xchg->tmppath, tplfolder, extfolder, ""); // handle files with KEEP IP only present in extfolder, and KEEP folders in extfolder
	};

	logfi.close();
	// IP run --- IEND

	return(new DpchRetWdbePrctreeMerge("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- IBEGIN
bool WdbePrctreeMerge::scanFolder(
			const string& tmppath
			, const string& tplroot
			, const string& tplsub
			, const string& extfolder // no change in recursion
			, const bool notrace
			, const bool skipmultvoid
			, fstream& logfi
		) {
	bool success = true;

	DIR* dir = NULL;

	dirent* diritem = NULL;

	vector<string> folders;
	vector<string> files;

	string s;

	s = tmppath + "/" + tplroot + tplsub;
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
					files.push_back(diritem->d_name);
				};
			};

			diritem = readdir(dir);
		};
		closedir(dir);
	};

	// traverse directory II (scan sub-folders and files)
	for (unsigned int i = 0; i < files.size(); i++) {
		// file: scan
		s = extfolder + tplsub + "/" + files[i] + ".ip";
		if (!scanFile(tmppath, tplroot + tplsub + "/" + files[i], s, notrace, skipmultvoid, logfi)) success = false;
	};

	for (unsigned int i = 0; i < folders.size(); i++) {
		// sub-folder: scan recursively
		if (!scanFolder(tmppath, tplroot, tplsub + "/" + folders[i], extfolder, notrace, skipmultvoid, logfi)) success = false;
	};

	return success;
};

void WdbePrctreeMerge::invscanFolder(
			const string& tmppath
			, const string& tplfolder // no change in recursion
			, const string& extroot
			, const string& extsub
		) {
	DIR* dir = NULL;

	dirent* diritem = NULL;

	vector<string> folders;
	vector<string> files;

	fstream logfi; // used as dummy
	vector<Ip*> ips;
	unsigned int fmt;

	bool keep = false;

	string s;

	s = tmppath + "/" + extroot + extsub;
	dir = opendir(s.c_str());

	if (dir) {
		// traverse directory I (survey)
		diritem = readdir(dir);
		while (diritem) {
			if (diritem->d_type == DT_DIR) {
				// sub-folders: avoid '.' and '..'
				if ((strcmp(diritem->d_name, ".") != 0) && (strcmp(diritem->d_name, "..") != 0)) folders.push_back(diritem->d_name);

			} else if (diritem->d_type == DT_REG) {
				if (strcmp(diritem->d_name, "IP folder --- KEEP") == 0) keep = true;
				files.push_back(diritem->d_name);
			};

			diritem = readdir(dir);
		};
		closedir(dir);
	};

	if (keep) {
		// generate directory in tplfolder if needed
		s = tmppath + "/" + tplfolder + extsub;

		if (access(s.c_str(), R_OK | W_OK) == -1) {
#ifdef _WIN32
			mkdir(s.c_str());
#else
			mkdir(s.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif
		};

		Wdbe::run("cp -rp " + tmppath + "/" + extroot + extsub + "/* " + tmppath + "/" + tplfolder + extsub + "/");

	} else {
		// traverse directory II (scan sub-folders and files)
		for (unsigned int i = 0; i < files.size(); i++) {
			// file: check for complement in tplfolder and check for KEEP directive
			s = tmppath + "/" + tplfolder + extsub + "/" + files[i];

			// chop off .ip extension
			if (s.rfind(".ip") == (s.length()-3)) s = s.substr(0, s.length()-3);

			if (access(s.c_str(), R_OK) == -1) {
				// corresponding tplfile does not exist
				parseFile(tmppath + "/" + extroot + extsub + "/" + files[i], logfi, false, ips, fmt);

				keep = false;

				for (unsigned int j = 0; j < ips.size(); j++)
					if (ips[j]->type == Iptype::KEEP) {
						keep = true;
						break;
					};

				if (keep) Wdbe::run("cp -p " + tmppath + "/" + extroot + extsub + "/" + files[i] + " " + s);

				for (unsigned int j = 0; j < ips.size(); j++) delete ips[j];
				ips.resize(0);
			};
		};

		for (unsigned int i = 0; i < folders.size(); i++) {
			// sub-folder: scan recursively
			invscanFolder(tmppath, tplfolder, extroot, extsub + "/" + folders[i]);
		};
	};
};

bool WdbePrctreeMerge::scanFile(
			const string& tmppath
			, const string& tplfile
			, const string& extfile
			, const bool notrace
			, const bool skipmultvoid
			, fstream& logfi
		) {
	bool success = true;

	vector<Ip*> ips;

	vector<Ip*> extips;
	bool hasExtipAbove;
	bool hasExtipKeep;
	map<string,unsigned int> icsExtipsAffirm;
	map<string,unsigned int> icsExtipsRemove;
	map<string,unsigned int> icsExtipsIline;
	map<string,unsigned int> icsExtipsIbegin;
	map<string,unsigned int> icsExtipsRline;
	map<string,unsigned int> icsExtipsRbegin;

	unsigned int fmt;

	string tmpfile;
	fstream tmpfi;

	mode_t mode;

	bool hasextfi;

	string s;

	// check if extfile exists
	s = tmppath + "/" + extfile;
	hasextfi = (access(s.c_str(), R_OK) != -1);

	if (hasextfi) {
		// parse extfile
		logfi << "processing extract file '" << extfile << "'" << endl;
		success = parseFile(tmppath + "/" + extfile, logfi, true, extips, fmt);

		if (success) {
			// read extfile content
			readFileContent(tmppath + "/" + extfile, extips, hasExtipAbove, hasExtipKeep, icsExtipsAffirm, icsExtipsRemove, icsExtipsIline, icsExtipsIbegin, icsExtipsRline, icsExtipsRbegin);

			if (hasExtipKeep) {
				// copy file without looking at tplfile
				Wdbe::run("cp -p " + tmppath + "/" + extfile + " " + tmppath + "/" + tplfile);

			} else {
				// parse tplfile
				logfi << "processing template file '" << tplfile << "'" << endl;
				success = parseFile(tmppath + "/" + tplfile, logfi, true, ips, fmt);

				if (success) {
					// determine tplfile permissions
					s = tmppath + "/" + tplfile;
					if (access(s.c_str(), X_OK) == 0) mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH; // 644
					else mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 755

					// create temporary file
					tmpfile = Tmp::newfile(tmppath, "");

					// open temporary file
					s = tmppath + "/" + tmpfile;
					tmpfi.open(s.c_str(), ios::out | ios::trunc);

					// copy from tplfile to tmpfi while replacing parts from extfile
					writeTmpfile(tmppath, tmpfi, tplfile, extfile, ips, extips, hasExtipAbove, icsExtipsAffirm, icsExtipsRemove, icsExtipsIline, icsExtipsIbegin, icsExtipsRline, icsExtipsRbegin, notrace, skipmultvoid);

					// close temporary file and adapt permissions
					tmpfi.close();
					chmod(s.c_str(), mode);

					// overwrite template file
					Wdbe::run("mv " + tmppath + "/" + tmpfile + " " + tmppath + "/" + tplfile);
				};
			};
		};

	} else {
		// leave tplfile untouched
	};

	// clean up
	for (unsigned int i = 0; i < ips.size(); i++) delete ips[i];
	for (unsigned int i = 0; i < extips.size(); i++) delete extips[i];

	return success;
};

void WdbePrctreeMerge::writeTmpfile(
			const string& tmppath
			, fstream& tmpfi
			, const string& tplfile
			, const string& extfile
			, const vector<Ip*>& ips
			, const vector<Ip*>& extips
			, const bool hasExtipAbove
			, map<string,unsigned int>& icsExtipsAffirm
			, map<string,unsigned int>& icsExtipsRemove
			, map<string,unsigned int>& icsExtipsIline
			, map<string,unsigned int>& icsExtipsIbegin
			, map<string,unsigned int>& icsExtipsRline
			, map<string,unsigned int>& icsExtipsRbegin
			, const bool notrace
			, const bool skipmultvoid
		) {
	ifstream tplfi;

	bool hasextfi;
	ifstream extfi;

	char* buf = new char[1048576];
	string s;

	unsigned int lineno = 0;
	unsigned int nextiplineno = 0;
	unsigned int skiptolineno = 0;

	unsigned int ipsix = 0;

	Ip* extip = NULL;

	map<string,unsigned int>::iterator it;

	bool lastvoid = false;

	// open template file
	s = tmppath + "/" + tplfile;
	tplfi.open(s.c_str(), ios::in);

	// open extracts file if exists
	s = tmppath + "/" + extfile;
	hasextfi = (access(s.c_str(), R_OK) != -1);
	if (hasextfi) extfi.open(s.c_str(), ios::in);

	// initialize next insertion point line number to first entry in ips
	if (ips.size() > 0) {
		nextiplineno = ips[0]->lineno;

		// special case of ABOVE ip
		if (hasExtipAbove && (ips[0]->type == Iptype::ABOVE)) skiptolineno = ips[0]->lineno - 1;

	} else {
		// big number
		nextiplineno--;
	};

	while (tplfi.good() && (!tplfi.eof())) {
		// read single line
		s = StrMod::readLine(tplfi, buf, 1048576);

		lineno++;

		if (lineno == skiptolineno) {
			// make sure next line is analyzed / copied
			skiptolineno = 0;

		} else if (lineno > skiptolineno) {
			// analyze / copy line

			if (lineno == nextiplineno) {
				// arrived at next insertion point
				if (ips[ipsix]->type == Iptype::ABOVE) {
					if (hasExtipAbove) {
						// ABOVE: copy entire content from extfile
						extip = extips[0];
	
						for (unsigned int j = 0; j < extip->content.size(); j++) writeTmpfile_line(tmpfi, extip->content[j], lastvoid, skipmultvoid);

					} else {
						// copy line from tplfile to leave a trace
						writeTmpfile_line(tmpfi, s, lastvoid, skipmultvoid);
					};

				} else if (ips[ipsix]->type == Iptype::INSERT) {
					if ((it = icsExtipsRemove.find(ips[ipsix]->tag)) != icsExtipsRemove.end()) {
						// REMOVE: copy line from extfile to leave a trace
						extip = extips[it->second];

						if (!notrace) writeTmpfile_line(tmpfi, extip->content[0], lastvoid, skipmultvoid);

					} else if ((it = icsExtipsIline.find(ips[ipsix]->tag)) != icsExtipsIline.end()) {
						// ILINE: copy line from extfile, optionally skipping IP part
						extip = extips[it->second];

						if (notrace) writeTmpfile_line(tmpfi, extip->content[0].substr(0, extip->ptr0-extip->il), lastvoid, skipmultvoid);
						else writeTmpfile_line(tmpfi, extip->content[0], lastvoid, skipmultvoid);

					} else if ((it = icsExtipsIbegin.find(ips[ipsix]->tag)) != icsExtipsIbegin.end()) {
						// IBEGIN/IEND: copy entire content from extfile
						extip = extips[it->second];

						if (notrace) {
							for (unsigned int j = 1; j < (extip->content.size() - 1); j++) writeTmpfile_line(tmpfi, extip->content[j], lastvoid, skipmultvoid);
						} else {
							for (unsigned int j = 0; j < extip->content.size(); j++) writeTmpfile_line(tmpfi, extip->content[j], lastvoid, skipmultvoid);
						};

					} else {
						// copy line from tplfile to leave a trace
						writeTmpfile_line(tmpfi, s, lastvoid, skipmultvoid);
					};

				} else if ((ips[ipsix]->type == Iptype::LINE) || (ips[ipsix]->type == Iptype::BEGIN)) {
					extip = NULL;

					if ((it = icsExtipsAffirm.find(ips[ipsix]->tag)) != icsExtipsAffirm.end()) {
						// AFFIRM
						if (ips[ipsix]->type == Iptype::LINE) {
							// copy line from tplfile skipping IP part
							writeTmpfile_line(tmpfi, s.substr(0, ips[ipsix]->ptr0-ips[ipsix]->il), lastvoid, skipmultvoid);

						} else {
							// don't write BEGIN line
						};

					} else if ((it = icsExtipsRemove.find(ips[ipsix]->tag)) != icsExtipsRemove.end()) {
						// REMOVE: copy line from extfile to leave a trace
						extip = extips[it->second];

						if (!notrace) writeTmpfile_line(tmpfi, extip->content[0], lastvoid, skipmultvoid);

					} else if ((it = icsExtipsRline.find(ips[ipsix]->tag)) != icsExtipsRline.end()) {
						// RLINE: copy line from extfile, optionally skipping IP part
						extip = extips[it->second];

						if (notrace) writeTmpfile_line(tmpfi, extip->content[0].substr(0, extip->ptr0-extip->il), lastvoid, skipmultvoid);
						else writeTmpfile_line(tmpfi, extip->content[0], lastvoid, skipmultvoid);

					} else if ((it = icsExtipsRbegin.find(ips[ipsix]->tag)) != icsExtipsRbegin.end()) {
						// RBEGIN/REND: copy entire content from extfile
						extip = extips[it->second];

						if (notrace) for (unsigned int j = 1; j < (extip->content.size() - 1); j++) writeTmpfile_line(tmpfi, extip->content[j], lastvoid, skipmultvoid);
						else for (unsigned int j = 0; j < extip->content.size(); j++) writeTmpfile_line(tmpfi, extip->content[j], lastvoid, skipmultvoid);

					} else {
						// copy line from tplfile to leave a trace
						writeTmpfile_line(tmpfi, s, lastvoid, skipmultvoid);
					};
					
					if ((ips[ipsix]->type == Iptype::BEGIN) && extip) {
						// REMOVE or RLINE or RBEGIN/REND

						// skip content in tplfile up to END
						skiptolineno = ips[ipsix]->par->lineno;

						// skip insertion points up to END, will be adjusted to the next one after further down the code
						for (unsigned int j = ipsix; j < ips.size(); j++) {
							if (ips[ipsix]->par == ips[j]) {
								ipsix = j;
								break;
							};
						};
					};

				} else if (ips[ipsix]->type == Iptype::END) {
					// see if AFFIRM counterpart exists in extips
					if ((it = icsExtipsAffirm.find(ips[ipsix]->tag)) != icsExtipsAffirm.end()) {
						// don't write END line

					} else {
						// copy line from tplfile to leave a trace
						writeTmpfile_line(tmpfi, s, lastvoid, skipmultvoid);
					};

				} else {
					// copy line from tplfile to leave a trace
					writeTmpfile_line(tmpfi, s, lastvoid, skipmultvoid);
				};

				// find line number of next insertion point
				ipsix++;
				if (ipsix < ips.size()) nextiplineno = ips[ipsix]->lineno;
				// else: no more insertion points, so what is to come is a simple copy operation

			} else {
				// copy line from tplfile
				writeTmpfile_line(tmpfi, s, lastvoid, skipmultvoid);
			};

		} else {
			// skip line
		};
	};

	tplfi.close();
	if (hasextfi) extfi.close();

	delete[] buf;
};

void WdbePrctreeMerge::writeTmpfile_line(
			fstream& tmpfi
			, const string& line
			, bool& lastvoid
			, const bool skipmultvoid
		) {
	if (line.length() > 0) tmpfi << line << endl;
	else if (!lastvoid || !skipmultvoid) tmpfi << endl;

	lastvoid = (line.length() == 0);
};
// IP cust --- IEND



