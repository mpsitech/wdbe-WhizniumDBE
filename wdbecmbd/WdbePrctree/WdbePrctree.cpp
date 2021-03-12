/**
	* \file WdbePrctree.cpp
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

#include "WdbePrctree.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbePrctree
 ******************************************************************************/

// IP cust --- IBEGIN
/******************************************************************************
 namespace WdbePrctree::Ipformat
 ******************************************************************************/

unsigned int WdbePrctree::Ipformat::get(
			const string& path
			, bool& ip
		) {
	unsigned int ipfmt = CSS + 1;

	string filename;
	size_t ptr1;

	string ext;

	ifstream infi;

	size_t ptr2;

	char* buf = NULL;
	string s;

	// chop off path
	ptr1 = path.rfind('/');
	if (ptr1 == string::npos) filename = path;
	else filename = path.substr(ptr1+1);

	// see if path ends with .ip
	ip = false;
	if (filename.length() > 3) {
		if (filename.substr(filename.length() - 3) == ".ip") {
			filename = filename.substr(0, filename.length()-3);
			ip = true;
		};
	};

	// extract extension
	ptr1 = filename.rfind('.');
	if (ptr1 != string::npos) ext = filename.substr(ptr1+1);

	if (ext.length() > 0) {
		// known extensions
		if (ext == "xml") ipfmt = XML;
		else if (ext == "html") ipfmt = XML;
		else if (ext == "h") ipfmt = GNR;
		else if (ext == "c") ipfmt = GNR;
		else if (ext == "cpp") ipfmt = GNR;
		else if (ext == "java") ipfmt = GNR;
		else if (ext == "js") ipfmt = GNR;
		else if (ext == "sql") ipfmt = SQL;
		else if (ext == "vhd") ipfmt = SQL;
		else if (ext == "sh") ipfmt = MSH;
		else if (ext == "ucf") ipfmt = MSH;
		else if (ext == "css") ipfmt = CSS;

	} else if (filename.find("Makefile") == 0) {
		// Makefile's have no extension
		ipfmt = MSH;
	};

	if (ipfmt > CSS) {
		// judge based on the first IP found
		buf = new char[1048576];
		infi.open(path.c_str(), ios::in);

		while (infi.good() && (!infi.eof())) {
			// read single line
			s = StrMod::readLine(infi, buf, 1048576);

			// look for IP tag
			ptr1 = s.rfind(" IP ");
			if (ptr1 != string::npos) {
				ptr2 = s.find(" --- ", ptr1);
				if (ptr2 == string::npos) ptr2 = s.find(" - ", ptr1);

				if (ptr2 != string::npos) {
					if (ptr1 >= 4) {
						if (s.substr(ptr1 - 4, 4) == "<!--") {
							ipfmt = XML;
							break;
						};
					};
					if (ptr1 >= 2) {
						if (s.substr(ptr1 - 2, 2) == "//") {
							ipfmt = GNR;
							break;
						} else if (s.substr(ptr1 - 2, 2) == "--") {
							ipfmt = SQL;
							break;
						} else if (s.substr(ptr1 - 2, 2) == "/*") {
							ipfmt = CSS;
							break;
						};
					};
					if (ptr1 >= 1) {
						if (s.substr(ptr1 - 1, 1) == "#") {
							ipfmt = MSH;
							break;
						};
					};
				};
			};
		};

		infi.close();
		delete[] buf;
	};

	if (ipfmt > CSS) ipfmt = GNR;

	return ipfmt;
};

void WdbePrctree::Ipformat::getPrefixInfixPostfix(
			const unsigned int fmt
			, string& prefix
			, string& infix
			, string& postfix
		) {
	// general/text/C++/C/JavaScript pattern is '// IP <tag> --- <TYPE>' (appended tabs are allowed)
	// XML/HTML IP pattern is '<!-- IP <tag> - <TYPE> -->'
	// SQL pattern is '-- IP <tag> --- <TYPE>'
	// Makefile/shell script pattern is '# IP <tag> --- <TYPE>'
	// CSS pattern is '/* IP <tag> --- <TYPE> */'

	prefix = "";
	infix = "";
	postfix = "";

	if (fmt == GNR) {
		prefix = "// IP ";
		infix = " --- ";
	} else if (fmt == XML) {
		prefix = "<!-- IP ";
		infix = " - ";
		postfix = " -->";
	} else if (fmt == SQL) {
		prefix = "-- IP ";
		infix = " --- ";
	} else if (fmt == MSH) {
		prefix = "# IP ";
		infix = " --- ";
	} else if (fmt == CSS) {
		prefix = "/* IP ";
		infix = " --- ";
		postfix = " */";
	};
};

/******************************************************************************
 namespace WdbePrctree::Iptype
 ******************************************************************************/

unsigned int WdbePrctree::Iptype::get(
			string s
		) {
	unsigned int retval = INVALID;

	size_t ptr = s.find('\t');
	if (ptr != string::npos) s = s.substr(0, ptr);

	if (s == "ABOVE") retval = ABOVE;
	else if (s == "KEEP") retval = KEEP;
	else if (s == "INSERT") retval = INSERT;
	else if (s == "AFFIRM") retval = AFFIRM;
	else if (s == "REMOVE") retval = REMOVE;
	else if (s == "LINE") retval = LINE;
	else if (s == "BEGIN") retval = BEGIN;
	else if (s == "END") retval = END;
	else if (s == "ILINE") retval = ILINE;
	else if (s == "IBEGIN") retval = IBEGIN;
	else if (s == "IEND") retval = IEND;
	else if (s == "RLINE") retval = RLINE;
	else if (s == "RBEGIN") retval = RBEGIN;
	else if (s == "REND") retval = REND;

	return retval;
};

/******************************************************************************
 namespace WdbePrctree::Ip
 ******************************************************************************/

WdbePrctree::Ip::Ip(
			const string& tag
			, const unsigned int type
			, const unsigned int lineno
			, const unsigned int il
			, const size_t ptr0
		) {
	this->tag = tag;
	this->type = type;
	this->lineno = lineno;
	this->il = il;
	this->ptr0 = ptr0;

	par = NULL;
};

/******************************************************************************
 namespace WdbePrctree
 ******************************************************************************/

bool WdbePrctree::parseFile(
			const string& path
			, fstream& logfile
			, const bool log
			, vector<Ip*>& ips
			, unsigned int& fmt
		) {
	bool retval = true;

	bool ipfile; // dummy

	string prefix, infix, postfix;

	ifstream infi;

	char* buf = new char[1048576];
	string s;

	bool valid;

	Ip* ip = NULL;
	Ip* ip2 = NULL;

	string tag;
	unsigned int type;
	unsigned int lineno = 0;
	unsigned int il;
	size_t ptr0;

	size_t ptr1, ptr2;

	bool hasIpAbove = false;
	bool hasIpKeep = false;

	// --- determine IP type to be expected according to file extension
	fmt = Ipformat::get(path, ipfile);
	Ipformat::getPrefixInfixPostfix(fmt, prefix, infix, postfix);

	infi.open(path.c_str(), ios::in);

	// --- collect IP tags (error on formatting mismatch)
	while (infi.good() && (!infi.eof())) {
		// read single line
		s = StrMod::readLine(infi, buf, 1048576);

		lineno++;

		valid = true;

		ptr0 = s.rfind(prefix);
		if (ptr0 != string::npos) {
			// found IP prefix ; see if line remainder corresponds to pattern
			ptr1 = ptr0 + prefix.length();

			if (s.find("\"", ptr1) != string::npos) continue;
			if (s.find("'", ptr1) != string::npos) continue;

			ptr2 = s.find(infix, ptr1);
			if (ptr2 != string::npos) {
				// found tag
				tag = s.substr(ptr1, ptr2-ptr1);

				ptr1 = ptr2 + infix.length();

				if (postfix == "") {
					ptr2 = s.length();

				} else {
					ptr2 = s.find(postfix, ptr1);
					
					if (ptr2 == string::npos) {
						if (log) logfile << "\tline " << lineno << ": malformed insertion point (wrong postfix)" << endl;
						valid = false;
					};
				};

				if (valid) {
					// found postfix if required by fmt
					type = Iptype::get(s.substr(ptr1, ptr2-ptr1));

					if (type != Iptype::INVALID) {
						// found valid type
						for (il = ptr0; il > 0; il--) if ((s[il-1] != ' ') && (s[il-1] != '\t')) break;
						il = ptr0 - il;

						if ((ptr0 == il) || (type == Iptype::LINE) || (type == Iptype::ILINE) || (type == Iptype::RLINE)) {
							if ((type == Iptype::ABOVE) && !(ips.size() == 0)) {
								if (log) logfile << "\tline " << lineno << ": only one IP of type ABOVE allowed before all other insertion points" << endl;
								valid = false;

							} else if ((type == Iptype::KEEP) && !(ips.size() == 0) && !(hasIpAbove && (ips.size() == 1))) {
								if (log) logfile << "\tline " << lineno << ": only one IP of type KEEP allowed before all other insertion points except ABOVE" << endl;
								valid = false;

							} else {
								ips.push_back(new Ip(tag, type, lineno, il, ptr0));

								if (type == Iptype::ABOVE) hasIpAbove = true;
								else if (type == Iptype::KEEP) hasIpKeep = true;
							};

						} else {
							if (log) logfile << "\tline " << lineno << ": malformed insertion point (invalid preceding content)" << endl;
							valid = false;
						};

					} else {
						if (log) logfile << "\tline " << lineno << ": invalid IP type '" << s.substr(ptr1, ptr2-ptr1) << "'" << endl;
						valid = false;
					};
				};

			} else {
				if (log) logfile << "\tline " << lineno << ": malformed insertion point (wrong infix)" << endl;
				valid = false;
			};
		};

		if (!valid) retval = false;

		if (hasIpKeep) break;
	};

	// --- match opening and closing IP tags
	for (unsigned int i = 0; i < ips.size();i++) {
		ip = ips[i];

		if ((ip->type == Iptype::BEGIN) || (ip->type == Iptype::IBEGIN) || (ip->type == Iptype::RBEGIN)) {
			valid = false;

			for (unsigned int j = (i+1); j < ips.size(); j++) {
				ip2 = ips[j];

				if (ip->tag == ip2->tag) {
					if ( ((ip->type == Iptype::BEGIN) && (ip2->type == Iptype::END)) || ((ip->type == Iptype::IBEGIN) && (ip2->type == Iptype::IEND))
								|| ((ip->type == Iptype::RBEGIN) && (ip2->type == Iptype::REND))) {
						ip->par = ip2;
						ip2->par = ip;
						valid = true;

						break;
					};
				};
			};

			if (!valid) {
				if (log) logfile << "\tline "  << ip->lineno << ": no closing counterpart for insertion point for tag '" << ip->tag << "'" << endl;
				retval = false;
			};
		};
	};

	for (unsigned int i = 0; i < ips.size();i++) {
		ip = ips[i];

		if (((ip->type == Iptype::END) || (ip->type == Iptype::IEND) || (ip->type == Iptype::REND)) && (ip->par == NULL)) {
			if (log) logfile << "\tline "  << ip->lineno << ": no opening counterpart for insertion point for tag '" << ip->tag << "'" << endl;
			retval = false;
		};
	};

	// clean up
	infi.close();

	delete[] buf;

	return retval;
};

void WdbePrctree::readFileContent(
			const string& path
			, vector<Ip*>& ips
			, bool& hasIpAbove
			, bool& hasIpKeep
			, map<string,unsigned int>& icsIpsAffirm
			, map<string,unsigned int>& icsIpsRemove
			, map<string,unsigned int>& icsIpsIline
			, map<string,unsigned int>& icsIpsIbegin
			, map<string,unsigned int>& icsIpsRline
			, map<string,unsigned int>& icsIpsRbegin
		) {
	ifstream infi;

	char* buf = new char[1048576];
	string s;

	Ip* ip = NULL;

	hasIpAbove = false;
	hasIpKeep = false;
	icsIpsAffirm.clear();
	icsIpsRemove.clear();
	icsIpsIline.clear();
	icsIpsIbegin.clear();
	icsIpsRline.clear();
	icsIpsRbegin.clear();

	infi.open(path.c_str(), ios::in);

	for (unsigned int i = 0; i < ips.size();i++) {
		ip = ips[i];

		if (ip->type == Iptype::AFFIRM) icsIpsAffirm[ip->tag] = i;
		else if (ip->type == Iptype::REMOVE) icsIpsRemove[ip->tag] = i;
		else if (ip->type == Iptype::ILINE) icsIpsIline[ip->tag] = i;
		else if (ip->type == Iptype::IBEGIN) icsIpsIbegin[ip->tag] = i;
		else if (ip->type == Iptype::RLINE) icsIpsRline[ip->tag] = i;
		else if (ip->type == Iptype::RBEGIN) icsIpsRbegin[ip->tag] = i;

		if ((i == 0) && (ip->type == Iptype::ABOVE)) {
			// copy up to ABOVE
			for (unsigned int j = 1; j <= ip->lineno; j++) {
				s = StrMod::readLine(infi, buf, 1048576);
				ip->content.push_back(s);
			};

			hasIpAbove = true;

		} else if (((i == 0) && (ip->type == Iptype::KEEP)) || (hasIpAbove && (i == 1) && (ip->type == Iptype::KEEP))) {
			hasIpKeep = true;

		} else if ((ip->type == Iptype::AFFIRM) || (ip->type == Iptype::REMOVE) || (ip->type == Iptype::ILINE) || (ip->type == Iptype::IBEGIN) || (ip->type == Iptype::RLINE) || (ip->type == Iptype::RBEGIN)) {
			// skip leading lines
			infi.clear();
			infi.seekg(0);

			for (unsigned int j = 1; j < ip->lineno; j++) infi.getline(buf, 1048576, '\n');

			if ((ip->type == Iptype::AFFIRM) || (ip->type == Iptype::REMOVE) || (ip->type == Iptype::ILINE) || (ip->type == Iptype::RLINE)) {
				// copy single line
				s = StrMod::readLine(infi, buf, 1048576);
				ip->content.push_back(s);

			} else {
				// copy from *BEGIN to *END
				for (unsigned int j = ip->lineno; j <= ip->par->lineno; j++) {
					s = StrMod::readLine(infi, buf, 1048576);
					ip->content.push_back(s);
				};
			};
		};
	};

	delete[] buf;

	infi.close();
};
// IP cust --- IEND
