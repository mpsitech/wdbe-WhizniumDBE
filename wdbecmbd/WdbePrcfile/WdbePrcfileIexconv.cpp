/**
	* \file WdbePrcfileIexconv.cpp
	* Wdbe operation processor - convert text import input file into output file (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbePrcfileIexconv.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbePrcfile;

/******************************************************************************
 namespace WdbePrcfileIexconv
 ******************************************************************************/

DpchRetWdbe* WdbePrcfileIexconv::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbePrcfileIexconv* dpchinv
		) {
	string infile = dpchinv->infile;
	string outfile = dpchinv->outfile;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	// IP run --- IBEGIN
	string txtfile;

	ifstream _txtfile;
	ofstream _iexfile;

	string s;

	txtfile = Tmp::newfile(xchg->tmppath, "txt");
	runIconv(xchg->tmppath + "/" + infile, xchg->tmppath + "/" + txtfile);

	s = xchg->tmppath + "/" + txtfile;
	_txtfile.open(s.c_str(), ifstream::in);
	s = xchg->tmppath + "/" + outfile;
	_iexfile.open(s.c_str(), ios::out);

	convert(_txtfile, _iexfile);

	_txtfile.close();
	_iexfile.close();
	// IP run --- IEND

	return(new DpchRetWdbe(VecWdbeVDpch::DPCHRETWDBE, "", "", ixOpVOpres, 100));
};

// IP cust --- IBEGIN
void WdbePrcfileIexconv::runIconv(
			const string& infile
			, const string& outfile
		) {
	Wdbe::run("iconv -f MACINTOSH -t ISO-8859-1 " +  infile + " > " + outfile);
};

void WdbePrcfileIexconv::convert(
			ifstream& txtfile
			, ofstream& iexfile
		) {
	char* buf = NULL;

	unsigned int hdril, il;

	string s;
	size_t ptr;

	buf = new char[65536];

	hdril = 0;
	il = 0;
	
	txtfile.clear();
	txtfile.seekg(0);

	while (txtfile.good() && (!txtfile.eof())) {
		s = StrMod::readLine(txtfile, buf, 65536);

		il = 0;
		for (unsigned int i = 0; i < s.length();i++) {
			if (s[i] == '\t') il++;
			else break;
		};

		s = s.substr(il);
		if (s.find("ImeI") == 0) hdril = il;

		if (il < hdril) hdril = il;

		ptr = s.find('\"');
		while (ptr != string::npos) {
			s = s.substr(0, ptr) + s.substr(ptr+1);
			ptr = s.find('\"');
		};

		if (s.length() == 1) {
			if (s[0] == '^') s = "";
		} else if (s.length() > 1) {
			if (s.find("^\t") == 0) s = s.substr(1);
		};

		strISO8859(s);
		strRequote(s);

		iexfile << string(hdril, '\t') << "- " << s << endl;
	};

	delete[] buf;
};

string WdbePrcfileIexconv::unicodeToHexcode(
			unsigned int unicode
		) {
	string hexcode;

	unsigned char c;

	if (unicode > 65535) unicode = 20;

	c = unicode / 4096;
	if (c < 10) hexcode = c+0x30; else hexcode = c-10+0x61;
	unicode -= c*4096;

	c = unicode / 256;
	if (c < 10) hexcode += c+0x30; else hexcode += c-10+0x61;
	unicode -= c*256;

	c = unicode / 16;
	if (c < 10) hexcode += c+0x30; else hexcode += c-10+0x61;
	unicode -= c*16;

	c = unicode;
	if (c < 10) hexcode += c+0x30; else hexcode += c-10+0x61;

	return hexcode;
};

void WdbePrcfileIexconv::strISO8859(
			string& s
		) {
	size_t ptr, ptr1, ptr2;

	int unicode;

	unsigned char ci;
	string hexcode;

	ptr1 = s.find("&#");
	while (ptr1 != string::npos) {
		// find closing semicolon
		ptr2 = s.find(";", ptr1+2);
		if (ptr2 == string::npos) break;

		// make sure closest brace is found
		ptr = s.find("&#", ptr1+2);
		if (ptr != string::npos) {
			if (ptr < ptr2) {
				ptr1 = ptr;
				continue;
			};
		};

		// insert \u.... (hex) instead of HTML expression
		unicode = atoi(s.substr(ptr1+2, ptr2-ptr1-2).c_str());

		s = s.substr(0, ptr1) + "\\u" + unicodeToHexcode(unicode) + s.substr(ptr2+1);
		ptr1 = s.find("&#", ptr1+2);

/*
		// insert ISO8859-1 conforming character instead of HTML expression
		unicode = atoi(s.substr(ptr1+2, ptr2-ptr1-2).c_str());

		if (((unicode >= 32) && (unicode <= 126)) || ((unicode >= 160) && (unicode <= 255))) {
			if ((unicode != 60) && (unicode != 62)) s = s.substr(0, ptr1) + ((char) unicode) + s.substr(ptr2+1);
		} else if (unicode == 338) {
			s = s.substr(0, ptr1) + "OE" + s.substr(ptr2+1);
		} else if (unicode == 339) {
			s = s.substr(0, ptr1) + "oe" + s.substr(ptr2+1);
		};

		// remaining: all greek characters - alpha, phi, theta

		ptr1 = s.find("&#", ptr1+1); // ptr1+1 as e.g. the expression &#228; is shortened to ä
*/
	};

	// replace characters using MSB by \u.... (hex)
	for (unsigned int i = 0; i < s.length();) {
		ci = ((unsigned char) s[i]);

		if (ci > 0x7f) {
			s = s.substr(0, i) + "\\u" + unicodeToHexcode(ci) + s.substr(i+1);
			i += 6;

		} else i++;
	};
};

void WdbePrcfileIexconv::strRequote(
			string& s
		) {
	size_t ptr;

	ptr = s.find("''");
	while (ptr != string::npos) {
		s = s.substr(0, ptr) + "\"" + s.substr(ptr+2);
		ptr = s.find("''", ptr+1);
	};
};
// IP cust --- IEND


