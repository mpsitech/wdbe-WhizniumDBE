/**
	* \file IexWdbeIni.cpp
	* data blocks and readers/writers for import/export complex IexWdbeIni (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "IexWdbeIni.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeIni::VecVIme
 ******************************************************************************/

uint IexWdbeIni::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamcommandinvpar") return IMEIAMCOMMANDINVPAR;
	if (s == "imeiamcommandretpar") return IMEIAMCOMMANDRETPAR;
	if (s == "imeiamerrorpar") return IMEIAMERRORPAR;
	if (s == "imeiamlibrarymakefile") return IMEIAMLIBRARYMAKEFILE;
	if (s == "imeiammachinemakefile") return IMEIAMMACHINEMAKEFILE;
	if (s == "imeiammachinepar") return IMEIAMMACHINEPAR;
	if (s == "imeiammodulepar") return IMEIAMMODULEPAR;
	if (s == "imeiamuseraccess") return IMEIAMUSERACCESS;
	if (s == "imeiamusergroupaccess") return IMEIAMUSERGROUPACCESS;
	if (s == "imeiavcontrolpar") return IMEIAVCONTROLPAR;
	if (s == "imeiavkeylistkey1") return IMEIAVKEYLISTKEY1;
	if (s == "imeiavkeylistkey2") return IMEIAVKEYLISTKEY2;
	if (s == "imeiavkeylistkey3") return IMEIAVKEYLISTKEY3;
	if (s == "imeiavvaluelistval") return IMEIAVVALUELISTVAL;
	if (s == "imeicgeneric") return IMEICGENERIC;
	if (s == "imeicport") return IMEICPORT;
	if (s == "imeijavkeylistkey1") return IMEIJAVKEYLISTKEY1;
	if (s == "imeijavkeylistkey2") return IMEIJAVKEYLISTKEY2;
	if (s == "imeijavkeylistkey3") return IMEIJAVKEYLISTKEY3;
	if (s == "imeijmcoreversionstate") return IMEIJMCOREVERSIONSTATE;
	if (s == "imeijmpersonlastname") return IMEIJMPERSONLASTNAME;
	if (s == "imeijmpinsref") return IMEIJMPINSREF;
	if (s == "imeijmuserstate") return IMEIJMUSERSTATE;
	if (s == "imeimbank") return IMEIMBANK;
	if (s == "imeimcommand") return IMEIMCOMMAND;
	if (s == "imeimcontroller") return IMEIMCONTROLLER;
	if (s == "imeimcoreproject") return IMEIMCOREPROJECT;
	if (s == "imeimcoreversion") return IMEIMCOREVERSION;
	if (s == "imeimerror") return IMEIMERROR;
	if (s == "imeimfamily") return IMEIMFAMILY;
	if (s == "imeimfile1") return IMEIMFILE1;
	if (s == "imeimfile2") return IMEIMFILE2;
	if (s == "imeimgeneric") return IMEIMGENERIC;
	if (s == "imeimlibrary") return IMEIMLIBRARY;
	if (s == "imeimmachine") return IMEIMMACHINE;
	if (s == "imeimmodule") return IMEIMMODULE;
	if (s == "imeimperipheral") return IMEIMPERIPHERAL;
	if (s == "imeimperson") return IMEIMPERSON;
	if (s == "imeimpin") return IMEIMPIN;
	if (s == "imeimport") return IMEIMPORT;
	if (s == "imeimunit") return IMEIMUNIT;
	if (s == "imeimuser") return IMEIMUSER;
	if (s == "imeimusergroup") return IMEIMUSERGROUP;
	if (s == "imeimvector") return IMEIMVECTOR;
	if (s == "imeimvectoritem") return IMEIMVECTORITEM;
	if (s == "imeirmcoreprojectmperson") return IMEIRMCOREPROJECTMPERSON;

	return(0);
};

string IexWdbeIni::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMCOMMANDINVPAR) return("ImeIAMCommandInvpar");
	if (ix == IMEIAMCOMMANDRETPAR) return("ImeIAMCommandRetpar");
	if (ix == IMEIAMERRORPAR) return("ImeIAMErrorPar");
	if (ix == IMEIAMLIBRARYMAKEFILE) return("ImeIAMLibraryMakefile");
	if (ix == IMEIAMMACHINEMAKEFILE) return("ImeIAMMachineMakefile");
	if (ix == IMEIAMMACHINEPAR) return("ImeIAMMachinePar");
	if (ix == IMEIAMMODULEPAR) return("ImeIAMModulePar");
	if (ix == IMEIAMUSERACCESS) return("ImeIAMUserAccess");
	if (ix == IMEIAMUSERGROUPACCESS) return("ImeIAMUsergroupAccess");
	if (ix == IMEIAVCONTROLPAR) return("ImeIAVControlPar");
	if (ix == IMEIAVKEYLISTKEY1) return("ImeIAVKeylistKey1");
	if (ix == IMEIAVKEYLISTKEY2) return("ImeIAVKeylistKey2");
	if (ix == IMEIAVKEYLISTKEY3) return("ImeIAVKeylistKey3");
	if (ix == IMEIAVVALUELISTVAL) return("ImeIAVValuelistVal");
	if (ix == IMEICGENERIC) return("ImeICGeneric");
	if (ix == IMEICPORT) return("ImeICPort");
	if (ix == IMEIJAVKEYLISTKEY1) return("ImeIJAVKeylistKey1");
	if (ix == IMEIJAVKEYLISTKEY2) return("ImeIJAVKeylistKey2");
	if (ix == IMEIJAVKEYLISTKEY3) return("ImeIJAVKeylistKey3");
	if (ix == IMEIJMCOREVERSIONSTATE) return("ImeIJMCoreversionState");
	if (ix == IMEIJMPERSONLASTNAME) return("ImeIJMPersonLastname");
	if (ix == IMEIJMPINSREF) return("ImeIJMPinSref");
	if (ix == IMEIJMUSERSTATE) return("ImeIJMUserState");
	if (ix == IMEIMBANK) return("ImeIMBank");
	if (ix == IMEIMCOMMAND) return("ImeIMCommand");
	if (ix == IMEIMCONTROLLER) return("ImeIMController");
	if (ix == IMEIMCOREPROJECT) return("ImeIMCoreproject");
	if (ix == IMEIMCOREVERSION) return("ImeIMCoreversion");
	if (ix == IMEIMERROR) return("ImeIMError");
	if (ix == IMEIMFAMILY) return("ImeIMFamily");
	if (ix == IMEIMFILE1) return("ImeIMFile1");
	if (ix == IMEIMFILE2) return("ImeIMFile2");
	if (ix == IMEIMGENERIC) return("ImeIMGeneric");
	if (ix == IMEIMLIBRARY) return("ImeIMLibrary");
	if (ix == IMEIMMACHINE) return("ImeIMMachine");
	if (ix == IMEIMMODULE) return("ImeIMModule");
	if (ix == IMEIMPERIPHERAL) return("ImeIMPeripheral");
	if (ix == IMEIMPERSON) return("ImeIMPerson");
	if (ix == IMEIMPIN) return("ImeIMPin");
	if (ix == IMEIMPORT) return("ImeIMPort");
	if (ix == IMEIMUNIT) return("ImeIMUnit");
	if (ix == IMEIMUSER) return("ImeIMUser");
	if (ix == IMEIMUSERGROUP) return("ImeIMUsergroup");
	if (ix == IMEIMVECTOR) return("ImeIMVector");
	if (ix == IMEIMVECTORITEM) return("ImeIMVectoritem");
	if (ix == IMEIRMCOREPROJECTMPERSON) return("ImeIRMCoreprojectMPerson");

	return("");
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAVControlPar
 ******************************************************************************/

IexWdbeIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			const uint ixWdbeVControl
			, const string& Par
			, const string& Val
		) : WdbeAVControlPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWdbeVControl = ixWdbeVControl;
	this->Par = Par;
	this->Val = Val;
};

IexWdbeIni::ImeitemIAVControlPar::ImeitemIAVControlPar(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAVControlPar()
		{
	WdbeAVControlPar* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeavcontrolpar->loadRecByRef(ref, &rec)) {
		ixWdbeVControl = rec->ixWdbeVControl;
		Par = rec->Par;
		Val = rec->Val;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWdbeVControl = txtrd.fields[0]; ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXWDBEVCONTROL;};
	if (txtrd.fields.size() > 1) {Par = txtrd.fields[1]; ixWIelValid += ImeIAVControlPar::VecWIel::PAR;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVControlPar::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAVControlPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVControl", "ctl", srefIxWdbeVControl)) ixWIelValid += ImeIAVControlPar::VecWIel::SREFIXWDBEVCONTROL;
		if (extractStringUclc(docctx, basexpath, "Par", "par", Par)) ixWIelValid += ImeIAVControlPar::VecWIel::PAR;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVControlPar::VecWIel::VAL;
	};
};

void IexWdbeIni::ImeitemIAVControlPar::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVControl::getSref(ixWdbeVControl) << "\t" << Par << "\t" << Val << endl;
};

void IexWdbeIni::ImeitemIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ctl","par","val"};
	else tags = {"ImeitemIAVControlPar","srefIxWdbeVControl","Par","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVControl::getSref(ixWdbeVControl));
		writeString(wr, tags[2], Par);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVControlPar::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAVControlPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwdbevcontrol") ix |= SREFIXWDBEVCONTROL;
		else if (ss[i] == "par") ix |= PAR;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWdbeIni::ImeIAVControlPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAVControlPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWDBEVCONTROL) ss.push_back("srefIxWdbeVControl");
	if (ix & PAR) ss.push_back("Par");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVControlPar
 ******************************************************************************/

IexWdbeIni::ImeIAVControlPar::ImeIAVControlPar() {
};

IexWdbeIni::ImeIAVControlPar::~ImeIAVControlPar() {
	clear();
};

void IexWdbeIni::ImeIAVControlPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAVControlPar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAVControlPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIAVControlPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVControlPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAVControlPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAVControlPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVControlPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVControlPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVControlPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAVControlPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAVControlPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVControlPar." << StrMod::replaceChar(ImeIAVControlPar::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVControlPar.end" << endl;
	};
};

void IexWdbeIni::ImeIAVControlPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVControlPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIJAVKeylistKey1
 ******************************************************************************/

IexWdbeIni::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
			const uint x1IxWdbeVLocale
			, const string& Title
			, const string& Comment
		) : WdbeJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWdbeVLocale = x1IxWdbeVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIJAVKeylistKey1::ImeitemIJAVKeylistKey1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey1()
		{
	WdbeJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbejavkeylistkey->loadRecByRef(ref, &rec)) {
		refWdbeAVKeylistKey = rec->refWdbeAVKeylistKey;
		x1IxWdbeVLocale = rec->x1IxWdbeVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIJAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWdbeVLocale = txtrd.fields[0]; ixWIelValid += ImeIJAVKeylistKey1::VecWIel::SREFX1IXWDBEVLOCALE;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIJAVKeylistKey1::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIJAVKeylistKey1::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIJAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWdbeVLocale", "lcl", srefX1IxWdbeVLocale)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::SREFX1IXWDBEVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey1::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVLocale::getSref(x1IxWdbeVLocale) << "\t" << Title << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIJAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lcl","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey1","srefX1IxWdbeVLocale","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVLocale::getSref(x1IxWdbeVLocale));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIJAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIJAVKeylistKey1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwdbevlocale") ix |= SREFX1IXWDBEVLOCALE;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIJAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIJAVKeylistKey1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWDBEVLOCALE) ss.push_back("srefX1IxWdbeVLocale");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIJAVKeylistKey1
 ******************************************************************************/

IexWdbeIni::ImeIJAVKeylistKey1::ImeIJAVKeylistKey1() {
};

IexWdbeIni::ImeIJAVKeylistKey1::~ImeIJAVKeylistKey1() {
	clear();
};

void IexWdbeIni::ImeIJAVKeylistKey1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIJAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIJAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIJAVKeylistKey1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIJAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIJAVKeylistKey1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIJAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIJAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIJAVKeylistKey1." << StrMod::replaceChar(ImeIJAVKeylistKey1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIJAVKeylistKey1.end" << endl;
	};
};

void IexWdbeIni::ImeIJAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAVKeylistKey1
 ******************************************************************************/

IexWdbeIni::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
			const uint klsIxWdbeVKeylist
			, const string& sref
			, const string& Avail
			, const string& Implied
			, const string& Title
			, const string& Comment
		) : WdbeAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxWdbeVKeylist = klsIxWdbeVKeylist;
	this->sref = sref;
	this->Avail = Avail;
	this->Implied = Implied;
	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIAVKeylistKey1::ImeitemIAVKeylistKey1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey1()
		{
	WdbeAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxWdbeVKeylist = rec->klsIxWdbeVKeylist;
		klsNum = rec->klsNum;
		x1IxWdbeVMaintable = rec->x1IxWdbeVMaintable;
		Fixed = rec->Fixed;
		sref = rec->sref;
		Avail = rec->Avail;
		Implied = rec->Implied;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefKlsIxWdbeVKeylist = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREFKLSIXWDBEVKEYLIST;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Avail = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::AVAIL;};
	if (txtrd.fields.size() > 3) {Implied = txtrd.fields[3]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::IMPLIED;};
	if (txtrd.fields.size() > 4) {Title = txtrd.fields[4]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::TITLE;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIAVKeylistKey1::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY1)) {
					imeijavkeylistkey1.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxWdbeVKeylist", "kls", srefKlsIxWdbeVKeylist)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREFKLSIXWDBEVKEYLIST;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Avail", "avl", Avail)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::AVAIL;
		if (extractStringUclc(docctx, basexpath, "Implied", "imp", Implied)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::IMPLIED;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAVKeylistKey1::VecWIel::COMMENT;
		imeijavkeylistkey1.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVKeylist::getSref(klsIxWdbeVKeylist) << "\t" << sref << "\t" << Avail << "\t" << Implied << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey1.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","avl","imp","tit","cmt"};
	else tags = {"ImeitemIAVKeylistKey1","srefKlsIxWdbeVKeylist","sref","Avail","Implied","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVKeylist::getSref(klsIxWdbeVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Avail);
		writeString(wr, tags[4], Implied);
		writeString(wr, tags[5], Title);
		writeString(wr, tags[6], Comment);
		imeijavkeylistkey1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVKeylistKey1::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAVKeylistKey1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefklsixwdbevkeylist") ix |= SREFKLSIXWDBEVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "avail") ix |= AVAIL;
		else if (ss[i] == "implied") ix |= IMPLIED;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIAVKeylistKey1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAVKeylistKey1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXWDBEVKEYLIST) ss.push_back("srefKlsIxWdbeVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & AVAIL) ss.push_back("Avail");
	if (ix & IMPLIED) ss.push_back("Implied");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVKeylistKey1
 ******************************************************************************/

IexWdbeIni::ImeIAVKeylistKey1::ImeIAVKeylistKey1() {
};

IexWdbeIni::ImeIAVKeylistKey1::~ImeIAVKeylistKey1() {
	clear();
};

void IexWdbeIni::ImeIAVKeylistKey1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAVKeylistKey1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAVKeylistKey1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIAVKeylistKey1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAVKeylistKey1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAVKeylistKey1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAVKeylistKey1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAVKeylistKey1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVKeylistKey1." << StrMod::replaceChar(ImeIAVKeylistKey1::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVKeylistKey1.end" << endl;
	};
};

void IexWdbeIni::ImeIAVKeylistKey1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAVValuelistVal
 ******************************************************************************/

IexWdbeIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			const uint vlsIxWdbeVValuelist
			, const uint x1IxWdbeVLocale
			, const string& Val
		) : WdbeAVValuelistVal() {
	lineno = 0;
	ixWIelValid = 0;

	this->vlsIxWdbeVValuelist = vlsIxWdbeVValuelist;
	this->x1IxWdbeVLocale = x1IxWdbeVLocale;
	this->Val = Val;
};

IexWdbeIni::ImeitemIAVValuelistVal::ImeitemIAVValuelistVal(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAVValuelistVal()
		{
	WdbeAVValuelistVal* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeavvaluelistval->loadRecByRef(ref, &rec)) {
		vlsIxWdbeVValuelist = rec->vlsIxWdbeVValuelist;
		vlsNum = rec->vlsNum;
		x1IxWdbeVLocale = rec->x1IxWdbeVLocale;
		Val = rec->Val;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefVlsIxWdbeVValuelist = txtrd.fields[0]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXWDBEVVALUELIST;};
	if (txtrd.fields.size() > 1) {srefX1IxWdbeVLocale = txtrd.fields[1]; ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXWDBEVLOCALE;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefVlsIxWdbeVValuelist", "vls", srefVlsIxWdbeVValuelist)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFVLSIXWDBEVVALUELIST;
		if (extractStringUclc(docctx, basexpath, "srefX1IxWdbeVLocale", "lcl", srefX1IxWdbeVLocale)) ixWIelValid += ImeIAVValuelistVal::VecWIel::SREFX1IXWDBEVLOCALE;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAVValuelistVal::VecWIel::VAL;
	};
};

void IexWdbeIni::ImeitemIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVValuelist::getSref(vlsIxWdbeVValuelist) << "\t" << VecWdbeVLocale::getSref(x1IxWdbeVLocale) << "\t" << Val << endl;
};

void IexWdbeIni::ImeitemIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","vls","lcl","val"};
	else tags = {"ImeitemIAVValuelistVal","srefVlsIxWdbeVValuelist","srefX1IxWdbeVLocale","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVValuelist::getSref(vlsIxWdbeVValuelist));
		writeString(wr, tags[2], VecWdbeVLocale::getSref(x1IxWdbeVLocale));
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVValuelistVal::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAVValuelistVal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefvlsixwdbevvaluelist") ix |= SREFVLSIXWDBEVVALUELIST;
		else if (ss[i] == "srefx1ixwdbevlocale") ix |= SREFX1IXWDBEVLOCALE;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWdbeIni::ImeIAVValuelistVal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAVValuelistVal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFVLSIXWDBEVVALUELIST) ss.push_back("srefVlsIxWdbeVValuelist");
	if (ix & SREFX1IXWDBEVLOCALE) ss.push_back("srefX1IxWdbeVLocale");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVValuelistVal
 ******************************************************************************/

IexWdbeIni::ImeIAVValuelistVal::ImeIAVValuelistVal() {
};

IexWdbeIni::ImeIAVValuelistVal::~ImeIAVValuelistVal() {
	clear();
};

void IexWdbeIni::ImeIAVValuelistVal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAVValuelistVal::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAVValuelistVal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIAVValuelistVal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVValuelistVal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAVValuelistVal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAVValuelistVal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVValuelistVal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVValuelistVal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVValuelistVal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAVValuelistVal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAVValuelistVal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAVValuelistVal." << StrMod::replaceChar(ImeIAVValuelistVal::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAVValuelistVal.end" << endl;
	};
};

void IexWdbeIni::ImeIAVValuelistVal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVValuelistVal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIJMCoreversionState
 ******************************************************************************/

IexWdbeIni::ImeitemIJMCoreversionState::ImeitemIJMCoreversionState(
			const uint ixVState
		) : WdbeJMCoreversionState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexWdbeIni::ImeitemIJMCoreversionState::ImeitemIJMCoreversionState(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIJMCoreversionState()
		{
	WdbeJMCoreversionState* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbejmcoreversionstate->loadRecByRef(ref, &rec)) {
		refWdbeMCoreversion = rec->refWdbeMCoreversion;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIJMCoreversionState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVState = txtrd.fields[0]; ixWIelValid += ImeIJMCoreversionState::VecWIel::SREFIXVSTATE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMCoreversionState"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIJMCoreversionState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIJMCoreversionState::VecWIel::SREFIXVSTATE;
	};
};

void IexWdbeIni::ImeitemIJMCoreversionState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMCoreversionState::getSref(ixVState) << endl;
};

void IexWdbeIni::ImeitemIJMCoreversionState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMCoreversionState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMCoreversionState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIJMCoreversionState::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIJMCoreversionState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexWdbeIni::ImeIJMCoreversionState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVSTATE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIJMCoreversionState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIJMCoreversionState
 ******************************************************************************/

IexWdbeIni::ImeIJMCoreversionState::ImeIJMCoreversionState() {
};

IexWdbeIni::ImeIJMCoreversionState::~ImeIJMCoreversionState() {
	clear();
};

void IexWdbeIni::ImeIJMCoreversionState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIJMCoreversionState::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIJMCoreversionState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIJMCoreversionState();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMCoreversionState"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMCoreversionState"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMCOREVERSIONSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMCoreversionState"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMCoreversionState"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIJMCoreversionState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIJMCoreversionState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMCoreversionState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMCoreversionState", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMCoreversionState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIJMCoreversionState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIJMCoreversionState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMCoreversionState." << StrMod::replaceChar(ImeIJMCoreversionState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMCoreversionState.end" << endl;
	};
};

void IexWdbeIni::ImeIJMCoreversionState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMCoreversionState");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMCoreversion
 ******************************************************************************/

IexWdbeIni::ImeitemIMCoreversion::ImeitemIMCoreversion(
			const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const uint ixVState
			, const uint ixWSpectype
		) : WdbeMCoreversion() {
	lineno = 0;
	ixWIelValid = 0;

	this->Major = Major;
	this->Minor = Minor;
	this->Sub = Sub;
	this->ixVState = ixVState;
	this->ixWSpectype = ixWSpectype;
};

IexWdbeIni::ImeitemIMCoreversion::ImeitemIMCoreversion(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMCoreversion()
		{
	WdbeMCoreversion* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcoreversion->loadRecByRef(ref, &rec)) {
		refWdbeMCoreproject = rec->refWdbeMCoreproject;
		Major = rec->Major;
		Minor = rec->Minor;
		Sub = rec->Sub;
		refJState = rec->refJState;
		ixVState = rec->ixVState;
		ixWSpectype = rec->ixWSpectype;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMCoreversion::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Major = atoi(txtrd.fields[0].c_str()); ixWIelValid += ImeIMCoreversion::VecWIel::MAJOR;};
	if (txtrd.fields.size() > 1) {Minor = atoi(txtrd.fields[1].c_str()); ixWIelValid += ImeIMCoreversion::VecWIel::MINOR;};
	if (txtrd.fields.size() > 2) {Sub = atoi(txtrd.fields[2].c_str()); ixWIelValid += ImeIMCoreversion::VecWIel::SUB;};
	if (txtrd.fields.size() > 3) {srefIxVState = txtrd.fields[3]; ixWIelValid += ImeIMCoreversion::VecWIel::SREFIXVSTATE;};
	if (txtrd.fields.size() > 4) {srefsIxWSpectype = txtrd.fields[4]; ixWIelValid += ImeIMCoreversion::VecWIel::SREFSIXWSPECTYPE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMCOREVERSIONSTATE)) {
					imeijmcoreversionstate.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCoreversion"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMCoreversion::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUsmallintUclc(docctx, basexpath, "Major", "maj", Major)) ixWIelValid += ImeIMCoreversion::VecWIel::MAJOR;
		if (extractUsmallintUclc(docctx, basexpath, "Minor", "min", Minor)) ixWIelValid += ImeIMCoreversion::VecWIel::MINOR;
		if (extractUsmallintUclc(docctx, basexpath, "Sub", "sub", Sub)) ixWIelValid += ImeIMCoreversion::VecWIel::SUB;
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIMCoreversion::VecWIel::SREFIXVSTATE;
		if (extractStringUclc(docctx, basexpath, "srefsIxWSpectype", "sty", srefsIxWSpectype)) ixWIelValid += ImeIMCoreversion::VecWIel::SREFSIXWSPECTYPE;
		imeijmcoreversionstate.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMCoreversion::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Major << "\t" << Minor << "\t" << Sub << "\t" << VecWdbeVMCoreversionState::getSref(ixVState) << "\t" << VecWdbeWMCoreversionSpectype::getSrefs(ixWSpectype) << endl;
	imeijmcoreversionstate.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMCoreversion::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","maj","min","sub","ste","sty"};
	else tags = {"ImeitemIMCoreversion","Major","Minor","Sub","srefIxVState","srefsIxWSpectype"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUsmallint(wr, tags[1], Major);
		writeUsmallint(wr, tags[2], Minor);
		writeUsmallint(wr, tags[3], Sub);
		writeString(wr, tags[4], VecWdbeVMCoreversionState::getSref(ixVState));
		writeString(wr, tags[5], VecWdbeWMCoreversionSpectype::getSrefs(ixWSpectype));
		imeijmcoreversionstate.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMCoreversion::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMCoreversion::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "major") ix |= MAJOR;
		else if (ss[i] == "minor") ix |= MINOR;
		else if (ss[i] == "sub") ix |= SUB;
		else if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
		else if (ss[i] == "srefsixwspectype") ix |= SREFSIXWSPECTYPE;
	};

	return(ix);
};

void IexWdbeIni::ImeIMCoreversion::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXWSPECTYPE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMCoreversion::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & MAJOR) ss.push_back("Major");
	if (ix & MINOR) ss.push_back("Minor");
	if (ix & SUB) ss.push_back("Sub");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");
	if (ix & SREFSIXWSPECTYPE) ss.push_back("srefsIxWSpectype");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMCoreversion
 ******************************************************************************/

IexWdbeIni::ImeIMCoreversion::ImeIMCoreversion() {
};

IexWdbeIni::ImeIMCoreversion::~ImeIMCoreversion() {
	clear();
};

void IexWdbeIni::ImeIMCoreversion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMCoreversion::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMCoreversion* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIMCoreversion();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCoreversion"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCoreversion"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCOREVERSION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCoreversion"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCoreversion"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMCoreversion::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMCoreversion* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCoreversion");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCoreversion", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCoreversion";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMCoreversion();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMCoreversion::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMCoreversion." << StrMod::replaceChar(ImeIMCoreversion::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMCoreversion.end" << endl;
	};
};

void IexWdbeIni::ImeIMCoreversion::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCoreversion");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIRMCoreprojectMPerson
 ******************************************************************************/

IexWdbeIni::ImeitemIRMCoreprojectMPerson::ImeitemIRMCoreprojectMPerson(
			const string& hintRefWdbeMPerson
			, const string& srefKFunction
		) : WdbeRMCoreprojectMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefWdbeMPerson = hintRefWdbeMPerson;
	this->srefKFunction = srefKFunction;
};

IexWdbeIni::ImeitemIRMCoreprojectMPerson::ImeitemIRMCoreprojectMPerson(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIRMCoreprojectMPerson()
		{
	WdbeRMCoreprojectMPerson* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbermcoreprojectmperson->loadRecByRef(ref, &rec)) {
		refWdbeMCoreproject = rec->refWdbeMCoreproject;
		refWdbeMPerson = rec->refWdbeMPerson;
		srefKFunction = rec->srefKFunction;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIRMCoreprojectMPerson::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hintRefWdbeMPerson = txtrd.fields[0]; ixWIelValid += ImeIRMCoreprojectMPerson::VecWIel::HINTREFWDBEMPERSON;};
	if (txtrd.fields.size() > 1) {srefKFunction = txtrd.fields[1]; ixWIelValid += ImeIRMCoreprojectMPerson::VecWIel::SREFKFUNCTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCoreprojectMPerson"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIRMCoreprojectMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hintRefWdbeMPerson", "prs", hintRefWdbeMPerson)) ixWIelValid += ImeIRMCoreprojectMPerson::VecWIel::HINTREFWDBEMPERSON;
		if (extractStringUclc(docctx, basexpath, "srefKFunction", "fct", srefKFunction)) ixWIelValid += ImeIRMCoreprojectMPerson::VecWIel::SREFKFUNCTION;
	};
};

void IexWdbeIni::ImeitemIRMCoreprojectMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hintRefWdbeMPerson << "\t" << srefKFunction << endl;
};

void IexWdbeIni::ImeitemIRMCoreprojectMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","prs","fct"};
	else tags = {"ImeitemIRMCoreprojectMPerson","hintRefWdbeMPerson","srefKFunction"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefWdbeMPerson);
		writeString(wr, tags[2], srefKFunction);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIRMCoreprojectMPerson::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIRMCoreprojectMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hintrefwdbemperson") ix |= HINTREFWDBEMPERSON;
		else if (ss[i] == "srefkfunction") ix |= SREFKFUNCTION;
	};

	return(ix);
};

void IexWdbeIni::ImeIRMCoreprojectMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFKFUNCTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIRMCoreprojectMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HINTREFWDBEMPERSON) ss.push_back("hintRefWdbeMPerson");
	if (ix & SREFKFUNCTION) ss.push_back("srefKFunction");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIRMCoreprojectMPerson
 ******************************************************************************/

IexWdbeIni::ImeIRMCoreprojectMPerson::ImeIRMCoreprojectMPerson() {
};

IexWdbeIni::ImeIRMCoreprojectMPerson::~ImeIRMCoreprojectMPerson() {
	clear();
};

void IexWdbeIni::ImeIRMCoreprojectMPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIRMCoreprojectMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIRMCoreprojectMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIRMCoreprojectMPerson();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCoreprojectMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCoreprojectMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMCOREPROJECTMPERSON) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCoreprojectMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCoreprojectMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIRMCoreprojectMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIRMCoreprojectMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMCoreprojectMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMCoreprojectMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMCoreprojectMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIRMCoreprojectMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIRMCoreprojectMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMCoreprojectMPerson." << StrMod::replaceChar(ImeIRMCoreprojectMPerson::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMCoreprojectMPerson.end" << endl;
	};
};

void IexWdbeIni::ImeIRMCoreprojectMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMCoreprojectMPerson");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMCoreproject
 ******************************************************************************/

IexWdbeIni::ImeitemIMCoreproject::ImeitemIMCoreproject(
			const uint ixVBasetype
			, const string& sref
			, const string& Title
			, const string& Giturl
			, const string& Comment
		) : WdbeMCoreproject() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->Title = Title;
	this->Giturl = Giturl;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMCoreproject::ImeitemIMCoreproject(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMCoreproject()
		{
	WdbeMCoreproject* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcoreproject->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWdbeMCoreversion = rec->refWdbeMCoreversion;
		sref = rec->sref;
		Title = rec->Title;
		Giturl = rec->Giturl;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMCoreproject::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMCoreproject::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMCoreproject::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMCoreproject::VecWIel::TITLE;};
	if (txtrd.fields.size() > 3) {Giturl = txtrd.fields[3]; ixWIelValid += ImeIMCoreproject::VecWIel::GITURL;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMCoreproject::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMCOREVERSION)) {
					imeimcoreversion.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMCOREPROJECTMPERSON)) {
					imeirmcoreprojectmperson.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCoreproject"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMCoreproject::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMCoreproject::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCoreproject::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMCoreproject::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Giturl", "grl", Giturl)) ixWIelValid += ImeIMCoreproject::VecWIel::GITURL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMCoreproject::VecWIel::COMMENT;
		imeimcoreversion.readXML(docctx, basexpath);
		imeirmcoreprojectmperson.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMCoreproject::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVMCoreprojectBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << Title << "\t" << Giturl << "\t" << Comment << endl;
	imeimcoreversion.writeTxt(outfile);
	imeirmcoreprojectmperson.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMCoreproject::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","tit","grl","cmt"};
	else tags = {"ImeitemIMCoreproject","srefIxVBasetype","sref","Title","Giturl","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMCoreprojectBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], Giturl);
		writeString(wr, tags[5], Comment);
		imeimcoreversion.writeXML(wr, shorttags);
		imeirmcoreprojectmperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMCoreproject::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMCoreproject::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "giturl") ix |= GITURL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMCoreproject::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMCoreproject::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & GITURL) ss.push_back("Giturl");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMCoreproject
 ******************************************************************************/

IexWdbeIni::ImeIMCoreproject::ImeIMCoreproject() {
};

IexWdbeIni::ImeIMCoreproject::~ImeIMCoreproject() {
	clear();
};

void IexWdbeIni::ImeIMCoreproject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMCoreproject::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMCoreproject* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIMCoreproject();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCoreproject"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCOREPROJECT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCoreproject"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCoreproject"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMCoreproject::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMCoreproject* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCoreproject");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCoreproject", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCoreproject";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMCoreproject();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMCoreproject::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMCoreproject." << StrMod::replaceChar(ImeIMCoreproject::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMCoreproject.end" << endl;
	};
};

void IexWdbeIni::ImeIMCoreproject::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCoreproject");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMFamily
 ******************************************************************************/

IexWdbeIni::ImeitemIMFamily::ImeitemIMFamily(
			const ubigint iref
			, const string& srefKVendor
			, const string& Title
			, const string& Comment
		) : WdbeMFamily() {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
	this->srefKVendor = srefKVendor;
	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMFamily::ImeitemIMFamily(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMFamily()
		{
	WdbeMFamily* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemfamily->loadRecByRef(ref, &rec)) {
		srefKVendor = rec->srefKVendor;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMFamily::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMFamily::VecWIel::IREF;};
	if (txtrd.fields.size() > 1) {srefKVendor = txtrd.fields[1]; ixWIelValid += ImeIMFamily::VecWIel::SREFKVENDOR;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIMFamily::VecWIel::TITLE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMFamily::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFamily"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMFamily::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeIMFamily::VecWIel::IREF;
		if (extractStringUclc(docctx, basexpath, "srefKVendor", "cnd", srefKVendor)) ixWIelValid += ImeIMFamily::VecWIel::SREFKVENDOR;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMFamily::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFamily::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIMFamily::writeTxt(
			fstream& outfile
		) {
	outfile << iref << "\t" << srefKVendor << "\t" << Title << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIMFamily::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf","cnd","tit","cmt"};
	else tags = {"ImeitemIMFamily","iref","srefKVendor","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
		writeString(wr, tags[2], srefKVendor);
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMFamily::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMFamily::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
		else if (ss[i] == "srefkvendor") ix |= SREFKVENDOR;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMFamily::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMFamily::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");
	if (ix & SREFKVENDOR) ss.push_back("srefKVendor");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMFamily
 ******************************************************************************/

IexWdbeIni::ImeIMFamily::ImeIMFamily() {
};

IexWdbeIni::ImeIMFamily::~ImeIMFamily() {
	clear();
};

void IexWdbeIni::ImeIMFamily::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMFamily::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMFamily* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIMFamily();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFamily"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFAMILY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFamily"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFamily"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMFamily::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMFamily* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFamily");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFamily", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFamily";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMFamily();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMFamily::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFamily." << StrMod::replaceChar(ImeIMFamily::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMFamily.end" << endl;
	};
};

void IexWdbeIni::ImeIMFamily::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFamily");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMFile1
 ******************************************************************************/

IexWdbeIni::ImeitemIMFile1::ImeitemIMFile1(
			const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : WdbeMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMFile1::ImeitemIMFile1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMFile1()
		{
	WdbeMFile* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMFile1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {osrefKContent = txtrd.fields[0]; ixWIelValid += ImeIMFile1::VecWIel::OSREFKCONTENT;};
	if (txtrd.fields.size() > 1) {Filename = txtrd.fields[1]; ixWIelValid += ImeIMFile1::VecWIel::FILENAME;};
	if (txtrd.fields.size() > 2) {srefKMimetype = txtrd.fields[2]; ixWIelValid += ImeIMFile1::VecWIel::SREFKMIMETYPE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMFile1::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMFile1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile1::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile1::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile1::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile1::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIMFile1::writeTxt(
			fstream& outfile
		) {
	outfile << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIMFile1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile1","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], osrefKContent);
		writeString(wr, tags[2], Filename);
		writeString(wr, tags[3], srefKMimetype);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMFile1::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMFile1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "osrefkcontent") ix |= OSREFKCONTENT;
		else if (ss[i] == "filename") ix |= FILENAME;
		else if (ss[i] == "srefkmimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMFile1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMFile1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMFile1
 ******************************************************************************/

IexWdbeIni::ImeIMFile1::ImeIMFile1() {
};

IexWdbeIni::ImeIMFile1::~ImeIMFile1() {
	clear();
};

void IexWdbeIni::ImeIMFile1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMFile1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMFile1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIMFile1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFILE1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMFile1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMFile1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMFile1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMFile1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMFile1." << StrMod::replaceChar(ImeIMFile1::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMFile1.end" << endl;
	};
};

void IexWdbeIni::ImeIMFile1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAMLibraryMakefile
 ******************************************************************************/

IexWdbeIni::ImeitemIAMLibraryMakefile::ImeitemIAMLibraryMakefile(
			const string& srefX1RefWdbeMMachine
			, const string& x2SrefKTag
			, const string& Val
		) : WdbeAMLibraryMakefile() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWdbeMMachine = srefX1RefWdbeMMachine;
	this->x2SrefKTag = x2SrefKTag;
	this->Val = Val;
};

IexWdbeIni::ImeitemIAMLibraryMakefile::ImeitemIAMLibraryMakefile(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMLibraryMakefile()
		{
	WdbeAMLibraryMakefile* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamlibrarymakefile->loadRecByRef(ref, &rec)) {
		refWdbeMLibrary = rec->refWdbeMLibrary;
		x1RefWdbeMMachine = rec->x1RefWdbeMMachine;
		x2SrefKTag = rec->x2SrefKTag;
		Val = rec->Val;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAMLibraryMakefile::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWdbeMMachine = txtrd.fields[0]; ixWIelValid += ImeIAMLibraryMakefile::VecWIel::SREFX1REFWDBEMMACHINE;};
	if (txtrd.fields.size() > 1) {x2SrefKTag = txtrd.fields[1]; ixWIelValid += ImeIAMLibraryMakefile::VecWIel::X2SREFKTAG;};
	if (txtrd.fields.size() > 2) {Val = txtrd.fields[2]; ixWIelValid += ImeIAMLibraryMakefile::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAMLibraryMakefile::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWdbeMMachine", "mch", srefX1RefWdbeMMachine)) ixWIelValid += ImeIAMLibraryMakefile::VecWIel::SREFX1REFWDBEMMACHINE;
		if (extractStringUclc(docctx, basexpath, "x2SrefKTag", "tag", x2SrefKTag)) ixWIelValid += ImeIAMLibraryMakefile::VecWIel::X2SREFKTAG;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMLibraryMakefile::VecWIel::VAL;
	};
};

void IexWdbeIni::ImeitemIAMLibraryMakefile::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefX1RefWdbeMMachine << "\t" << x2SrefKTag << "\t" << Val << endl;
};

void IexWdbeIni::ImeitemIAMLibraryMakefile::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mch","tag","val"};
	else tags = {"ImeitemIAMLibraryMakefile","srefX1RefWdbeMMachine","x2SrefKTag","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWdbeMMachine);
		writeString(wr, tags[2], x2SrefKTag);
		writeString(wr, tags[3], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMLibraryMakefile::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAMLibraryMakefile::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwdbemmachine") ix |= SREFX1REFWDBEMMACHINE;
		else if (ss[i] == "x2srefktag") ix |= X2SREFKTAG;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWdbeIni::ImeIAMLibraryMakefile::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAMLibraryMakefile::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWDBEMMACHINE) ss.push_back("srefX1RefWdbeMMachine");
	if (ix & X2SREFKTAG) ss.push_back("x2SrefKTag");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMLibraryMakefile
 ******************************************************************************/

IexWdbeIni::ImeIAMLibraryMakefile::ImeIAMLibraryMakefile() {
};

IexWdbeIni::ImeIAMLibraryMakefile::~ImeIAMLibraryMakefile() {
	clear();
};

void IexWdbeIni::ImeIAMLibraryMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAMLibraryMakefile::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAMLibraryMakefile* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIAMLibraryMakefile();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMLIBRARYMAKEFILE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMLibraryMakefile"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAMLibraryMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAMLibraryMakefile* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMLibraryMakefile");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMLibraryMakefile", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMLibraryMakefile";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAMLibraryMakefile();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAMLibraryMakefile::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMLibraryMakefile." << StrMod::replaceChar(ImeIAMLibraryMakefile::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMLibraryMakefile.end" << endl;
	};
};

void IexWdbeIni::ImeIAMLibraryMakefile::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMLibraryMakefile");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMLibrary
 ******************************************************************************/

IexWdbeIni::ImeitemIMLibrary::ImeitemIMLibrary(
			const string& sref
			, const string& Title
			, const string& Version
			, const string& depSrefsWdbeMLibrary
			, const string& Comment
		) : WdbeMLibrary() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
	this->Version = Version;
	this->depSrefsWdbeMLibrary = depSrefsWdbeMLibrary;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMLibrary::ImeitemIMLibrary(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMLibrary()
		{
	WdbeMLibrary* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemlibrary->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Title = rec->Title;
		Version = rec->Version;
		depSrefsWdbeMLibrary = rec->depSrefsWdbeMLibrary;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMLibrary::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMLibrary::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMLibrary::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Version = txtrd.fields[2]; ixWIelValid += ImeIMLibrary::VecWIel::VERSION;};
	if (txtrd.fields.size() > 3) {depSrefsWdbeMLibrary = txtrd.fields[3]; ixWIelValid += ImeIMLibrary::VecWIel::DEPSREFSWDBEMLIBRARY;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMLibrary::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMLIBRARYMAKEFILE)) {
					imeiamlibrarymakefile.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLibrary"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMLibrary::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMLibrary::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMLibrary::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Version", "ver", Version)) ixWIelValid += ImeIMLibrary::VecWIel::VERSION;
		if (extractStringUclc(docctx, basexpath, "depSrefsWdbeMLibrary", "dep", depSrefsWdbeMLibrary)) ixWIelValid += ImeIMLibrary::VecWIel::DEPSREFSWDBEMLIBRARY;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMLibrary::VecWIel::COMMENT;
		imeiamlibrarymakefile.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMLibrary::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Title << "\t" << Version << "\t" << depSrefsWdbeMLibrary << "\t" << Comment << endl;
	imeiamlibrarymakefile.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMLibrary::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","ver","dep","cmt"};
	else tags = {"ImeitemIMLibrary","sref","Title","Version","depSrefsWdbeMLibrary","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Version);
		writeString(wr, tags[4], depSrefsWdbeMLibrary);
		writeString(wr, tags[5], Comment);
		imeiamlibrarymakefile.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMLibrary::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMLibrary::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "version") ix |= VERSION;
		else if (ss[i] == "depsrefswdbemlibrary") ix |= DEPSREFSWDBEMLIBRARY;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMLibrary::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMLibrary::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & VERSION) ss.push_back("Version");
	if (ix & DEPSREFSWDBEMLIBRARY) ss.push_back("depSrefsWdbeMLibrary");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMLibrary
 ******************************************************************************/

IexWdbeIni::ImeIMLibrary::ImeIMLibrary() {
};

IexWdbeIni::ImeIMLibrary::~ImeIMLibrary() {
	clear();
};

void IexWdbeIni::ImeIMLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMLibrary::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMLibrary* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIMLibrary();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMLIBRARY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMLibrary::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMLibrary* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMLibrary");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMLibrary", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMLibrary";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMLibrary();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMLibrary::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMLibrary." << StrMod::replaceChar(ImeIMLibrary::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMLibrary.end" << endl;
	};
};

void IexWdbeIni::ImeIMLibrary::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMLibrary");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAMMachineMakefile
 ******************************************************************************/

IexWdbeIni::ImeitemIAMMachineMakefile::ImeitemIAMMachineMakefile(
			const string& x1SrefKTag
			, const string& Val
		) : WdbeAMMachineMakefile() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKTag = x1SrefKTag;
	this->Val = Val;
};

IexWdbeIni::ImeitemIAMMachineMakefile::ImeitemIAMMachineMakefile(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMMachineMakefile()
		{
	WdbeAMMachineMakefile* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeammachinemakefile->loadRecByRef(ref, &rec)) {
		refWdbeMMachine = rec->refWdbeMMachine;
		x1SrefKTag = rec->x1SrefKTag;
		Val = rec->Val;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAMMachineMakefile::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKTag = txtrd.fields[0]; ixWIelValid += ImeIAMMachineMakefile::VecWIel::X1SREFKTAG;};
	if (txtrd.fields.size() > 1) {Val = txtrd.fields[1]; ixWIelValid += ImeIAMMachineMakefile::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAMMachineMakefile::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKTag", "tag", x1SrefKTag)) ixWIelValid += ImeIAMMachineMakefile::VecWIel::X1SREFKTAG;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMMachineMakefile::VecWIel::VAL;
	};
};

void IexWdbeIni::ImeitemIAMMachineMakefile::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKTag << "\t" << Val << endl;
};

void IexWdbeIni::ImeitemIAMMachineMakefile::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tag","val"};
	else tags = {"ImeitemIAMMachineMakefile","x1SrefKTag","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKTag);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMMachineMakefile::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAMMachineMakefile::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefktag") ix |= X1SREFKTAG;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWdbeIni::ImeIAMMachineMakefile::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAMMachineMakefile::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKTAG) ss.push_back("x1SrefKTag");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMMachineMakefile
 ******************************************************************************/

IexWdbeIni::ImeIAMMachineMakefile::ImeIAMMachineMakefile() {
};

IexWdbeIni::ImeIAMMachineMakefile::~ImeIAMMachineMakefile() {
	clear();
};

void IexWdbeIni::ImeIAMMachineMakefile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAMMachineMakefile::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAMMachineMakefile* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIAMMachineMakefile();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMMACHINEMAKEFILE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachineMakefile"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAMMachineMakefile::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAMMachineMakefile* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMMachineMakefile");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMMachineMakefile", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMMachineMakefile";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAMMachineMakefile();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAMMachineMakefile::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMMachineMakefile." << StrMod::replaceChar(ImeIAMMachineMakefile::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMMachineMakefile.end" << endl;
	};
};

void IexWdbeIni::ImeIAMMachineMakefile::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMMachineMakefile");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAMMachinePar
 ******************************************************************************/

IexWdbeIni::ImeitemIAMMachinePar::ImeitemIAMMachinePar(
			const string& x1SrefKKey
			, const string& Val
		) : WdbeAMMachinePar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWdbeIni::ImeitemIAMMachinePar::ImeitemIAMMachinePar(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMMachinePar()
		{
	WdbeAMMachinePar* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeammachinepar->loadRecByRef(ref, &rec)) {
		refWdbeMMachine = rec->refWdbeMMachine;
		x1SrefKKey = rec->x1SrefKKey;
		Val = rec->Val;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAMMachinePar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKKey = txtrd.fields[0]; ixWIelValid += ImeIAMMachinePar::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 1) {Val = txtrd.fields[1]; ixWIelValid += ImeIAMMachinePar::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAMMachinePar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMMachinePar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMMachinePar::VecWIel::VAL;
	};
};

void IexWdbeIni::ImeitemIAMMachinePar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWdbeIni::ImeitemIAMMachinePar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","val"};
	else tags = {"ImeitemIAMMachinePar","x1SrefKKey","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMMachinePar::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAMMachinePar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWdbeIni::ImeIAMMachinePar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAMMachinePar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKKEY) ss.push_back("x1SrefKKey");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMMachinePar
 ******************************************************************************/

IexWdbeIni::ImeIAMMachinePar::ImeIAMMachinePar() {
};

IexWdbeIni::ImeIAMMachinePar::~ImeIAMMachinePar() {
	clear();
};

void IexWdbeIni::ImeIAMMachinePar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAMMachinePar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAMMachinePar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIAMMachinePar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMMACHINEPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMMachinePar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAMMachinePar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAMMachinePar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMMachinePar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMMachinePar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMMachinePar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAMMachinePar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAMMachinePar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMMachinePar." << StrMod::replaceChar(ImeIAMMachinePar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMMachinePar.end" << endl;
	};
};

void IexWdbeIni::ImeIAMMachinePar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMMachinePar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMMachine
 ******************************************************************************/

IexWdbeIni::ImeitemIMMachine::ImeitemIMMachine(
			const string& srefKPlatform
			, const string& sref
			, const string& srefCchRefWdbeMMachine
			, const string& Comment
		) : WdbeMMachine() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefKPlatform = srefKPlatform;
	this->sref = sref;
	this->srefCchRefWdbeMMachine = srefCchRefWdbeMMachine;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMMachine::ImeitemIMMachine(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMMachine()
		{
	WdbeMMachine* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemmachine->loadRecByRef(ref, &rec)) {
		srefKPlatform = rec->srefKPlatform;
		sref = rec->sref;
		cchRefWdbeMMachine = rec->cchRefWdbeMMachine;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMMachine::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefKPlatform = txtrd.fields[0]; ixWIelValid += ImeIMMachine::VecWIel::SREFKPLATFORM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMMachine::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefCchRefWdbeMMachine = txtrd.fields[2]; ixWIelValid += ImeIMMachine::VecWIel::SREFCCHREFWDBEMMACHINE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMMachine::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMMACHINEMAKEFILE)) {
					imeiammachinemakefile.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMMACHINEPAR)) {
					imeiammachinepar.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMMachine"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMMachine::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefKPlatform", "pla", srefKPlatform)) ixWIelValid += ImeIMMachine::VecWIel::SREFKPLATFORM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMMachine::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefCchRefWdbeMMachine", "cch", srefCchRefWdbeMMachine)) ixWIelValid += ImeIMMachine::VecWIel::SREFCCHREFWDBEMMACHINE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMMachine::VecWIel::COMMENT;
		imeiammachinemakefile.readXML(docctx, basexpath);
		imeiammachinepar.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMMachine::writeTxt(
			fstream& outfile
		) {
	outfile << srefKPlatform << "\t" << sref << "\t" << srefCchRefWdbeMMachine << "\t" << Comment << endl;
	imeiammachinemakefile.writeTxt(outfile);
	imeiammachinepar.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMMachine::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","pla","srf","cch","cmt"};
	else tags = {"ImeitemIMMachine","srefKPlatform","sref","srefCchRefWdbeMMachine","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefKPlatform);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefCchRefWdbeMMachine);
		writeString(wr, tags[4], Comment);
		imeiammachinemakefile.writeXML(wr, shorttags);
		imeiammachinepar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMMachine::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMMachine::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefkplatform") ix |= SREFKPLATFORM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefcchrefwdbemmachine") ix |= SREFCCHREFWDBEMMACHINE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMMachine::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMMachine::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKPLATFORM) ss.push_back("srefKPlatform");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFCCHREFWDBEMMACHINE) ss.push_back("srefCchRefWdbeMMachine");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMMachine
 ******************************************************************************/

IexWdbeIni::ImeIMMachine::ImeIMMachine() {
};

IexWdbeIni::ImeIMMachine::~ImeIMMachine() {
	clear();
};

void IexWdbeIni::ImeIMMachine::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMMachine::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMMachine* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIMMachine();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMMachine"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMMACHINE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMMachine"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMMachine"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMMachine::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMMachine* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMMachine");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMMachine", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMMachine";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMMachine();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMMachine::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMMachine." << StrMod::replaceChar(ImeIMMachine::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMMachine.end" << endl;
	};
};

void IexWdbeIni::ImeIMMachine::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMMachine");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAMModulePar
 ******************************************************************************/

IexWdbeIni::ImeitemIAMModulePar::ImeitemIAMModulePar(
			const string& x1SrefKKey
			, const string& Val
		) : WdbeAMModulePar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWdbeIni::ImeitemIAMModulePar::ImeitemIAMModulePar(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMModulePar()
		{
	WdbeAMModulePar* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeammodulepar->loadRecByRef(ref, &rec)) {
		mdlRefWdbeMModule = rec->mdlRefWdbeMModule;
		mdlNum = rec->mdlNum;
		x1SrefKKey = rec->x1SrefKKey;
		Val = rec->Val;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAMModulePar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKKey = txtrd.fields[0]; ixWIelValid += ImeIAMModulePar::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 1) {Val = txtrd.fields[1]; ixWIelValid += ImeIAMModulePar::VecWIel::VAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMModulePar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAMModulePar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMModulePar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMModulePar::VecWIel::VAL;
	};
};

void IexWdbeIni::ImeitemIAMModulePar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWdbeIni::ImeitemIAMModulePar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","val"};
	else tags = {"ImeitemIAMModulePar","x1SrefKKey","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMModulePar::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAMModulePar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWdbeIni::ImeIAMModulePar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAMModulePar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & X1SREFKKEY) ss.push_back("x1SrefKKey");
	if (ix & VAL) ss.push_back("Val");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMModulePar
 ******************************************************************************/

IexWdbeIni::ImeIAMModulePar::ImeIAMModulePar() {
};

IexWdbeIni::ImeIAMModulePar::~ImeIAMModulePar() {
	clear();
};

void IexWdbeIni::ImeIAMModulePar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAMModulePar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAMModulePar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIAMModulePar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMModulePar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMModulePar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMMODULEPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMModulePar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMModulePar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAMModulePar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAMModulePar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMModulePar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMModulePar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMModulePar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAMModulePar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAMModulePar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMModulePar." << StrMod::replaceChar(ImeIAMModulePar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMModulePar.end" << endl;
	};
};

void IexWdbeIni::ImeIAMModulePar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMModulePar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIJAVKeylistKey3
 ******************************************************************************/

IexWdbeIni::ImeitemIJAVKeylistKey3::ImeitemIJAVKeylistKey3(
			const string& Title
			, const string& Comment
		) : WdbeJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIJAVKeylistKey3::ImeitemIJAVKeylistKey3(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey3()
		{
	WdbeJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbejavkeylistkey->loadRecByRef(ref, &rec)) {
		refWdbeAVKeylistKey = rec->refWdbeAVKeylistKey;
		x1IxWdbeVLocale = rec->x1IxWdbeVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIJAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Title = txtrd.fields[0]; ixWIelValid += ImeIJAVKeylistKey3::VecWIel::TITLE;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIJAVKeylistKey3::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey3"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIJAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey3::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey3::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIJAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << Title << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIJAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey3","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		writeString(wr, tags[2], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIJAVKeylistKey3::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIJAVKeylistKey3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIJAVKeylistKey3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIJAVKeylistKey3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIJAVKeylistKey3
 ******************************************************************************/

IexWdbeIni::ImeIJAVKeylistKey3::ImeIJAVKeylistKey3() {
};

IexWdbeIni::ImeIJAVKeylistKey3::~ImeIJAVKeylistKey3() {
	clear();
};

void IexWdbeIni::ImeIJAVKeylistKey3::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIJAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIJAVKeylistKey3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIJAVKeylistKey3();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey3"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey3"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY3) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey3"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey3"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIJAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIJAVKeylistKey3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey3", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIJAVKeylistKey3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIJAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAVKeylistKey3." << StrMod::replaceChar(ImeIJAVKeylistKey3::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJAVKeylistKey3.end" << endl;
	};
};

void IexWdbeIni::ImeIJAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey3");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAVKeylistKey3
 ******************************************************************************/

IexWdbeIni::ImeitemIAVKeylistKey3::ImeitemIAVKeylistKey3(
			const uint klsIxWdbeVKeylist
			, const string& sref
			, const string& Title
			, const string& Comment
		) : WdbeAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->klsIxWdbeVKeylist = klsIxWdbeVKeylist;
	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIAVKeylistKey3::ImeitemIAVKeylistKey3(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey3()
		{
	WdbeAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxWdbeVKeylist = rec->klsIxWdbeVKeylist;
		klsNum = rec->klsNum;
		x1IxWdbeVMaintable = rec->x1IxWdbeVMaintable;
		x1Uref = rec->x1Uref;
		Fixed = rec->Fixed;
		sref = rec->sref;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefKlsIxWdbeVKeylist = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey3::VecWIel::SREFKLSIXWDBEVKEYLIST;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey3::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Title = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey3::VecWIel::TITLE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIAVKeylistKey3::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY3)) {
					imeijavkeylistkey3.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey3"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefKlsIxWdbeVKeylist", "kls", srefKlsIxWdbeVKeylist)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::SREFKLSIXWDBEVKEYLIST;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAVKeylistKey3::VecWIel::COMMENT;
		imeijavkeylistkey3.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVKeylist::getSref(klsIxWdbeVKeylist) << "\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey3.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","kls","srf","tit","cmt"};
	else tags = {"ImeitemIAVKeylistKey3","srefKlsIxWdbeVKeylist","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVKeylist::getSref(klsIxWdbeVKeylist));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Title);
		writeString(wr, tags[4], Comment);
		imeijavkeylistkey3.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVKeylistKey3::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAVKeylistKey3::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefklsixwdbevkeylist") ix |= SREFKLSIXWDBEVKEYLIST;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIAVKeylistKey3::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAVKeylistKey3::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFKLSIXWDBEVKEYLIST) ss.push_back("srefKlsIxWdbeVKeylist");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVKeylistKey3
 ******************************************************************************/

IexWdbeIni::ImeIAVKeylistKey3::ImeIAVKeylistKey3() {
};

IexWdbeIni::ImeIAVKeylistKey3::~ImeIAVKeylistKey3() {
	clear();
};

void IexWdbeIni::ImeIAVKeylistKey3::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAVKeylistKey3::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAVKeylistKey3* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIAVKeylistKey3();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey3"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey3"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY3) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey3"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey3"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAVKeylistKey3::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAVKeylistKey3* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey3");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey3", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey3";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAVKeylistKey3();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAVKeylistKey3::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAVKeylistKey3." << StrMod::replaceChar(ImeIAVKeylistKey3::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAVKeylistKey3.end" << endl;
	};
};

void IexWdbeIni::ImeIAVKeylistKey3::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey3");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemICGeneric
 ******************************************************************************/

IexWdbeIni::ImeitemICGeneric::ImeitemICGeneric(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeIni::ImeitemICGeneric::ImeitemICGeneric(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICGeneric()
		{
};

void IexWdbeIni::ImeitemICGeneric::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICGeneric::VecWIel::IREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICGeneric"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemICGeneric::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICGeneric::VecWIel::IREF;
	};
};

void IexWdbeIni::ImeitemICGeneric::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWdbeIni::ImeitemICGeneric::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICGeneric","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeICGeneric::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeICGeneric::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeIni::ImeICGeneric::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeICGeneric::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeICGeneric
 ******************************************************************************/

IexWdbeIni::ImeICGeneric::ImeICGeneric() {
};

IexWdbeIni::ImeICGeneric::~ImeICGeneric() {
	clear();
};

void IexWdbeIni::ImeICGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeICGeneric::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemICGeneric* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemICGeneric();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICGeneric"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICGeneric"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICGENERIC) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICGeneric"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICGeneric"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeICGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemICGeneric* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICGeneric");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICGeneric", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICGeneric";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemICGeneric();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeICGeneric::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICGeneric." << StrMod::replaceChar(ImeICGeneric::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICGeneric.end" << endl;
	};
};

void IexWdbeIni::ImeICGeneric::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICGeneric");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemICPort
 ******************************************************************************/

IexWdbeIni::ImeitemICPort::ImeitemICPort(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeIni::ImeitemICPort::ImeitemICPort(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICPort()
		{
};

void IexWdbeIni::ImeitemICPort::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICPort::VecWIel::IREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICPort"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemICPort::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICPort::VecWIel::IREF;
	};
};

void IexWdbeIni::ImeitemICPort::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWdbeIni::ImeitemICPort::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICPort","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeICPort::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeICPort::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeIni::ImeICPort::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeICPort::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeICPort
 ******************************************************************************/

IexWdbeIni::ImeICPort::ImeICPort() {
};

IexWdbeIni::ImeICPort::~ImeICPort() {
	clear();
};

void IexWdbeIni::ImeICPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeICPort::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemICPort* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemICPort();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICPort"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICPort"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICPORT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICPort"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICPort"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeICPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemICPort* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICPort");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICPort", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICPort";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemICPort();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeICPort::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICPort." << StrMod::replaceChar(ImeICPort::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICPort.end" << endl;
	};
};

void IexWdbeIni::ImeICPort::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICPort");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAMCommandInvpar
 ******************************************************************************/

IexWdbeIni::ImeitemIAMCommandInvpar::ImeitemIAMCommandInvpar(
			const string& sref
			, const uint ixWdbeVPartype
			, const string& srefRefWdbeMVector
			, const utinyint Length
			, const string& Defval
			, const string& srefRefWdbeMVectoritem
			, const string& Comment
		) : WdbeAMCommandInvpar() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixWdbeVPartype = ixWdbeVPartype;
	this->srefRefWdbeMVector = srefRefWdbeMVector;
	this->Length = Length;
	this->Defval = Defval;
	this->srefRefWdbeMVectoritem = srefRefWdbeMVectoritem;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIAMCommandInvpar::ImeitemIAMCommandInvpar(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMCommandInvpar()
		{
	WdbeAMCommandInvpar* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamcommandinvpar->loadRecByRef(ref, &rec)) {
		cmdRefWdbeMCommand = rec->cmdRefWdbeMCommand;
		cmdNum = rec->cmdNum;
		sref = rec->sref;
		ixWdbeVPartype = rec->ixWdbeVPartype;
		refWdbeMVector = rec->refWdbeMVector;
		Length = rec->Length;
		Defval = rec->Defval;
		refWdbeMVectoritem = rec->refWdbeMVectoritem;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAMCommandInvpar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMCommandInvpar::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWdbeVPartype = txtrd.fields[1]; ixWIelValid += ImeIAMCommandInvpar::VecWIel::SREFIXWDBEVPARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWdbeMVector = txtrd.fields[2]; ixWIelValid += ImeIAMCommandInvpar::VecWIel::SREFREFWDBEMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMCommandInvpar::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Defval = txtrd.fields[4]; ixWIelValid += ImeIAMCommandInvpar::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 5) {srefRefWdbeMVectoritem = txtrd.fields[5]; ixWIelValid += ImeIAMCommandInvpar::VecWIel::SREFREFWDBEMVECTORITEM;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIAMCommandInvpar::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandInvpar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAMCommandInvpar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMCommandInvpar::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype)) ixWIelValid += ImeIAMCommandInvpar::VecWIel::SREFIXWDBEVPARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVector", "vec", srefRefWdbeMVector)) ixWIelValid += ImeIAMCommandInvpar::VecWIel::SREFREFWDBEMVECTOR;
		if (extractUtinyintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMCommandInvpar::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMCommandInvpar::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVectoritem", "vit", srefRefWdbeMVectoritem)) ixWIelValid += ImeIAMCommandInvpar::VecWIel::SREFREFWDBEMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMCommandInvpar::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIAMCommandInvpar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Defval << "\t" << srefRefWdbeMVectoritem << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIAMCommandInvpar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","pty","vec","len","dfv","vit","cmt"};
	else tags = {"ImeitemIAMCommandInvpar","sref","srefIxWdbeVPartype","srefRefWdbeMVector","Length","Defval","srefRefWdbeMVectoritem","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWdbeVPartype::getSref(ixWdbeVPartype));
		writeString(wr, tags[3], srefRefWdbeMVector);
		writeUtinyint(wr, tags[4], Length);
		writeString(wr, tags[5], Defval);
		writeString(wr, tags[6], srefRefWdbeMVectoritem);
		writeString(wr, tags[7], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMCommandInvpar::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAMCommandInvpar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwdbevpartype") ix |= SREFIXWDBEVPARTYPE;
		else if (ss[i] == "srefrefwdbemvector") ix |= SREFREFWDBEMVECTOR;
		else if (ss[i] == "length") ix |= LENGTH;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srefrefwdbemvectoritem") ix |= SREFREFWDBEMVECTORITEM;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIAMCommandInvpar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAMCommandInvpar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWDBEVPARTYPE) ss.push_back("srefIxWdbeVPartype");
	if (ix & SREFREFWDBEMVECTOR) ss.push_back("srefRefWdbeMVector");
	if (ix & LENGTH) ss.push_back("Length");
	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & SREFREFWDBEMVECTORITEM) ss.push_back("srefRefWdbeMVectoritem");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMCommandInvpar
 ******************************************************************************/

IexWdbeIni::ImeIAMCommandInvpar::ImeIAMCommandInvpar() {
};

IexWdbeIni::ImeIAMCommandInvpar::~ImeIAMCommandInvpar() {
	clear();
};

void IexWdbeIni::ImeIAMCommandInvpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAMCommandInvpar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAMCommandInvpar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeIni::ImeitemIAMCommandInvpar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandInvpar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandInvpar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDINVPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandInvpar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandInvpar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAMCommandInvpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAMCommandInvpar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCommandInvpar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCommandInvpar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCommandInvpar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAMCommandInvpar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAMCommandInvpar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMCommandInvpar." << StrMod::replaceChar(ImeIAMCommandInvpar::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMCommandInvpar.end" << endl;
	};
};

void IexWdbeIni::ImeIAMCommandInvpar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCommandInvpar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAMCommandRetpar
 ******************************************************************************/

IexWdbeIni::ImeitemIAMCommandRetpar::ImeitemIAMCommandRetpar(
			const string& sref
			, const uint ixWdbeVPartype
			, const string& srefRefWdbeMVector
			, const utinyint Length
			, const string& Comment
		) : WdbeAMCommandRetpar() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixWdbeVPartype = ixWdbeVPartype;
	this->srefRefWdbeMVector = srefRefWdbeMVector;
	this->Length = Length;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIAMCommandRetpar::ImeitemIAMCommandRetpar(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMCommandRetpar()
		{
	WdbeAMCommandRetpar* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamcommandretpar->loadRecByRef(ref, &rec)) {
		cmdRefWdbeMCommand = rec->cmdRefWdbeMCommand;
		cmdNum = rec->cmdNum;
		sref = rec->sref;
		ixWdbeVPartype = rec->ixWdbeVPartype;
		refWdbeMVector = rec->refWdbeMVector;
		Length = rec->Length;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAMCommandRetpar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMCommandRetpar::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWdbeVPartype = txtrd.fields[1]; ixWIelValid += ImeIAMCommandRetpar::VecWIel::SREFIXWDBEVPARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWdbeMVector = txtrd.fields[2]; ixWIelValid += ImeIAMCommandRetpar::VecWIel::SREFREFWDBEMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMCommandRetpar::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMCommandRetpar::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandRetpar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAMCommandRetpar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMCommandRetpar::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype)) ixWIelValid += ImeIAMCommandRetpar::VecWIel::SREFIXWDBEVPARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVector", "vec", srefRefWdbeMVector)) ixWIelValid += ImeIAMCommandRetpar::VecWIel::SREFREFWDBEMVECTOR;
		if (extractUtinyintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMCommandRetpar::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMCommandRetpar::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIAMCommandRetpar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIAMCommandRetpar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","pty","vec","len","cmt"};
	else tags = {"ImeitemIAMCommandRetpar","sref","srefIxWdbeVPartype","srefRefWdbeMVector","Length","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWdbeVPartype::getSref(ixWdbeVPartype));
		writeString(wr, tags[3], srefRefWdbeMVector);
		writeUtinyint(wr, tags[4], Length);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMCommandRetpar::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAMCommandRetpar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwdbevpartype") ix |= SREFIXWDBEVPARTYPE;
		else if (ss[i] == "srefrefwdbemvector") ix |= SREFREFWDBEMVECTOR;
		else if (ss[i] == "length") ix |= LENGTH;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIAMCommandRetpar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAMCommandRetpar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWDBEVPARTYPE) ss.push_back("srefIxWdbeVPartype");
	if (ix & SREFREFWDBEMVECTOR) ss.push_back("srefRefWdbeMVector");
	if (ix & LENGTH) ss.push_back("Length");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMCommandRetpar
 ******************************************************************************/

IexWdbeIni::ImeIAMCommandRetpar::ImeIAMCommandRetpar() {
};

IexWdbeIni::ImeIAMCommandRetpar::~ImeIAMCommandRetpar() {
	clear();
};

void IexWdbeIni::ImeIAMCommandRetpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAMCommandRetpar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAMCommandRetpar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeIni::ImeitemIAMCommandRetpar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandRetpar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandRetpar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDRETPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandRetpar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandRetpar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAMCommandRetpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAMCommandRetpar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCommandRetpar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCommandRetpar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCommandRetpar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAMCommandRetpar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAMCommandRetpar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMCommandRetpar." << StrMod::replaceChar(ImeIAMCommandRetpar::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMCommandRetpar.end" << endl;
	};
};

void IexWdbeIni::ImeIAMCommandRetpar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCommandRetpar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMCommand
 ******************************************************************************/

IexWdbeIni::ImeitemIMCommand::ImeitemIMCommand(
			const uint refNum
			, const string& sref
			, const uint ixVRettype
			, const string& Comment
		) : WdbeMCommand() {
	lineno = 0;
	ixWIelValid = 0;

	this->refNum = refNum;
	this->sref = sref;
	this->ixVRettype = ixVRettype;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMCommand::ImeitemIMCommand(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMCommand()
		{
	WdbeMCommand* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcommand->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		sref = rec->sref;
		ixVRettype = rec->ixVRettype;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMCommand::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {refNum = atol(txtrd.fields[0].c_str()); ixWIelValid += ImeIMCommand::VecWIel::REFNUM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMCommand::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxVRettype = txtrd.fields[2]; ixWIelValid += ImeIMCommand::VecWIel::SREFIXVRETTYPE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMCommand::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDINVPAR)) {
					imeiamcommandinvpar.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDRETPAR)) {
					imeiamcommandretpar.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCommand"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMCommand::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUintUclc(docctx, basexpath, "refNum", "ren", refNum)) ixWIelValid += ImeIMCommand::VecWIel::REFNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCommand::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVRettype", "rty", srefIxVRettype)) ixWIelValid += ImeIMCommand::VecWIel::SREFIXVRETTYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMCommand::VecWIel::COMMENT;
		imeiamcommandinvpar.readXML(docctx, basexpath);
		imeiamcommandretpar.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMCommand::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << refNum << "\t" << sref << "\t" << VecWdbeVMCommandRettype::getSref(ixVRettype) << "\t" << Comment << endl;
	imeiamcommandinvpar.writeTxt(outfile);
	imeiamcommandretpar.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMCommand::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ren","srf","rty","cmt"};
	else tags = {"ImeitemIMCommand","refNum","sref","srefIxVRettype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], refNum);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWdbeVMCommandRettype::getSref(ixVRettype));
		writeString(wr, tags[4], Comment);
		imeiamcommandinvpar.writeXML(wr, shorttags);
		imeiamcommandretpar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMCommand::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMCommand::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "refnum") ix |= REFNUM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvrettype") ix |= SREFIXVRETTYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMCommand::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMCommand::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & REFNUM) ss.push_back("refNum");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVRETTYPE) ss.push_back("srefIxVRettype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMCommand
 ******************************************************************************/

IexWdbeIni::ImeIMCommand::ImeIMCommand() {
};

IexWdbeIni::ImeIMCommand::~ImeIMCommand() {
	clear();
};

void IexWdbeIni::ImeIMCommand::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMCommand::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMCommand* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIMCommand();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCommand"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCommand"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCOMMAND) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCommand"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCommand"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMCommand::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMCommand* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCommand");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCommand", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCommand";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMCommand();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMCommand::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMCommand." << StrMod::replaceChar(ImeIMCommand::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMCommand.end" << endl;
	};
};

void IexWdbeIni::ImeIMCommand::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCommand");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAMErrorPar
 ******************************************************************************/

IexWdbeIni::ImeitemIAMErrorPar::ImeitemIAMErrorPar(
			const string& sref
			, const uint ixWdbeVPartype
			, const string& srefRefWdbeMVector
			, const utinyint Length
			, const string& Comment
		) : WdbeAMErrorPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixWdbeVPartype = ixWdbeVPartype;
	this->srefRefWdbeMVector = srefRefWdbeMVector;
	this->Length = Length;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIAMErrorPar::ImeitemIAMErrorPar(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMErrorPar()
		{
	WdbeAMErrorPar* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamerrorpar->loadRecByRef(ref, &rec)) {
		errRefWdbeMError = rec->errRefWdbeMError;
		errNum = rec->errNum;
		sref = rec->sref;
		ixWdbeVPartype = rec->ixWdbeVPartype;
		refWdbeMVector = rec->refWdbeMVector;
		Length = rec->Length;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAMErrorPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMErrorPar::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWdbeVPartype = txtrd.fields[1]; ixWIelValid += ImeIAMErrorPar::VecWIel::SREFIXWDBEVPARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWdbeMVector = txtrd.fields[2]; ixWIelValid += ImeIAMErrorPar::VecWIel::SREFREFWDBEMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMErrorPar::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMErrorPar::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMErrorPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAMErrorPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMErrorPar::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype)) ixWIelValid += ImeIAMErrorPar::VecWIel::SREFIXWDBEVPARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVector", "vec", srefRefWdbeMVector)) ixWIelValid += ImeIAMErrorPar::VecWIel::SREFREFWDBEMVECTOR;
		if (extractUtinyintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMErrorPar::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMErrorPar::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIAMErrorPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIAMErrorPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","pty","vec","len","cmt"};
	else tags = {"ImeitemIAMErrorPar","sref","srefIxWdbeVPartype","srefRefWdbeMVector","Length","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWdbeVPartype::getSref(ixWdbeVPartype));
		writeString(wr, tags[3], srefRefWdbeMVector);
		writeUtinyint(wr, tags[4], Length);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMErrorPar::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAMErrorPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwdbevpartype") ix |= SREFIXWDBEVPARTYPE;
		else if (ss[i] == "srefrefwdbemvector") ix |= SREFREFWDBEMVECTOR;
		else if (ss[i] == "length") ix |= LENGTH;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIAMErrorPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAMErrorPar::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXWDBEVPARTYPE) ss.push_back("srefIxWdbeVPartype");
	if (ix & SREFREFWDBEMVECTOR) ss.push_back("srefRefWdbeMVector");
	if (ix & LENGTH) ss.push_back("Length");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMErrorPar
 ******************************************************************************/

IexWdbeIni::ImeIAMErrorPar::ImeIAMErrorPar() {
};

IexWdbeIni::ImeIAMErrorPar::~ImeIAMErrorPar() {
	clear();
};

void IexWdbeIni::ImeIAMErrorPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAMErrorPar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAMErrorPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeIni::ImeitemIAMErrorPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMErrorPar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMErrorPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMERRORPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMErrorPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMErrorPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAMErrorPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAMErrorPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMErrorPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMErrorPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMErrorPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAMErrorPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAMErrorPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMErrorPar." << StrMod::replaceChar(ImeIAMErrorPar::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMErrorPar.end" << endl;
	};
};

void IexWdbeIni::ImeIAMErrorPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMErrorPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMError
 ******************************************************************************/

IexWdbeIni::ImeitemIMError::ImeitemIMError(
			const uint refNum
			, const string& sref
			, const string& Comment
		) : WdbeMError() {
	lineno = 0;
	ixWIelValid = 0;

	this->refNum = refNum;
	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMError::ImeitemIMError(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMError()
		{
	WdbeMError* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemerror->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMError::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {refNum = atol(txtrd.fields[0].c_str()); ixWIelValid += ImeIMError::VecWIel::REFNUM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMError::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMError::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIAMERRORPAR)) {
					imeiamerrorpar.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMError"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMError::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUintUclc(docctx, basexpath, "refNum", "ren", refNum)) ixWIelValid += ImeIMError::VecWIel::REFNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMError::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMError::VecWIel::COMMENT;
		imeiamerrorpar.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMError::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << refNum << "\t" << sref << "\t" << Comment << endl;
	imeiamerrorpar.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMError::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ren","srf","cmt"};
	else tags = {"ImeitemIMError","refNum","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], refNum);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Comment);
		imeiamerrorpar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMError::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMError::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "refnum") ix |= REFNUM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMError::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMError::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & REFNUM) ss.push_back("refNum");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMError
 ******************************************************************************/

IexWdbeIni::ImeIMError::ImeIMError() {
};

IexWdbeIni::ImeIMError::~ImeIMError() {
	clear();
};

void IexWdbeIni::ImeIMError::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMError::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMError* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIMError();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMError"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMERROR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMError::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMError* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMError");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMError", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMError";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMError();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMError::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMError." << StrMod::replaceChar(ImeIMError::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMError.end" << endl;
	};
};

void IexWdbeIni::ImeIMError::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMError");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMVectoritem
 ******************************************************************************/

IexWdbeIni::ImeitemIMVectoritem::ImeitemIMVectoritem(
			const string& sref
			, const string& Title
			, const string& Comment
		) : WdbeMVectoritem() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMVectoritem::ImeitemIMVectoritem(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVectoritem()
		{
	WdbeMVectoritem* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemvectoritem->loadRecByRef(ref, &rec)) {
		vecRefWdbeMVector = rec->vecRefWdbeMVector;
		vecNum = rec->vecNum;
		sref = rec->sref;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMVectoritem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMVectoritem::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMVectoritem::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMVectoritem::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMVectoritem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVectoritem::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMVectoritem::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVectoritem::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIMVectoritem::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIMVectoritem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","cmt"};
	else tags = {"ImeitemIMVectoritem","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMVectoritem::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMVectoritem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMVectoritem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMVectoritem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMVectoritem
 ******************************************************************************/

IexWdbeIni::ImeIMVectoritem::ImeIMVectoritem() {
};

IexWdbeIni::ImeIMVectoritem::~ImeIMVectoritem() {
	clear();
};

void IexWdbeIni::ImeIMVectoritem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMVectoritem::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMVectoritem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeIni::ImeitemIMVectoritem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMVectoritem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMVectoritem* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVectoritem");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVectoritem", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVectoritem";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMVectoritem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMVectoritem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMVectoritem." << StrMod::replaceChar(ImeIMVectoritem::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMVectoritem.end" << endl;
	};
};

void IexWdbeIni::ImeIMVectoritem::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVectoritem");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMVector
 ******************************************************************************/

IexWdbeIni::ImeitemIMVector::ImeitemIMVector(
			const uint ixVBasetype
			, const string& sref
			, const string& srefsKOption
		) : WdbeMVector() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->srefsKOption = srefsKOption;
};

IexWdbeIni::ImeitemIMVector::ImeitemIMVector(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVector()
		{
	WdbeMVector* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemvector->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		hkIxVTbl = rec->hkIxVTbl;
		hkUref = rec->hkUref;
		sref = rec->sref;
		srefsKOption = rec->srefsKOption;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMVector::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMVector::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVector::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefsKOption = txtrd.fields[2]; ixWIelValid += ImeIMVector::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM)) {
					imeimvectoritem.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMVector::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector::VecWIel::SREFSKOPTION;
		imeimvectoritem.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMVector::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << srefsKOption << endl;
	imeimvectoritem.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMVector::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","opt"};
	else tags = {"ImeitemIMVector","srefIxVBasetype","sref","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMVectorBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefsKOption);
		imeimvectoritem.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMVector::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMVector::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWdbeIni::ImeIMVector::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMVector::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMVector
 ******************************************************************************/

IexWdbeIni::ImeIMVector::ImeIMVector() {
};

IexWdbeIni::ImeIMVector::~ImeIMVector() {
	clear();
};

void IexWdbeIni::ImeIMVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMVector::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMVector* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIMVector();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTOR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMVector::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMVector* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVector");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVector", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVector";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMVector();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMVector::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMVector." << StrMod::replaceChar(ImeIMVector::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMVector.end" << endl;
	};
};

void IexWdbeIni::ImeIMVector::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVector");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMController
 ******************************************************************************/

IexWdbeIni::ImeitemIMController::ImeitemIMController(
		) : WdbeMController() {
	lineno = 0;
	ixWIelValid = 0;

};

IexWdbeIni::ImeitemIMController::ImeitemIMController(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMController()
		{
	WdbeMController* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcontroller->loadRecByRef(ref, &rec)) {
		refWdbeMModule = rec->refWdbeMModule;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMController::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMCOMMAND)) {
					imeimcommand.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMERROR)) {
					imeimerror.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMVECTOR)) {
					imeimvector.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMController"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		imeimcommand.readXML(docctx, basexpath);
		imeimerror.readXML(docctx, basexpath);
		imeimvector.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << "^" << endl;
	imeimcommand.writeTxt(outfile);
	imeimerror.writeTxt(outfile);
	imeimvector.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMController::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii"};
	else tags = {"ImeitemIMController"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		imeimcommand.writeXML(wr, shorttags);
		imeimerror.writeXML(wr, shorttags);
		imeimvector.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMController::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMController::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
	};

	return(ix);
};

void IexWdbeIni::ImeIMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; false;) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMController::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMController
 ******************************************************************************/

IexWdbeIni::ImeIMController::ImeIMController() {
};

IexWdbeIni::ImeIMController::~ImeIMController() {
	clear();
};

void IexWdbeIni::ImeIMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIMController();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMController"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMController"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCONTROLLER) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMController"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMController"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMController* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMController");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMController", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMController";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMController." << StrMod::replaceChar(ImeIMController::VecWIel::getSrefs(0), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMController.end" << endl;
	};
};

void IexWdbeIni::ImeIMController::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMController");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMFile2
 ******************************************************************************/

IexWdbeIni::ImeitemIMFile2::ImeitemIMFile2(
			const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) : WdbeMFile() {
	lineno = 0;
	ixWIelValid = 0;

	this->osrefKContent = osrefKContent;
	this->Filename = Filename;
	this->srefKMimetype = srefKMimetype;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMFile2::ImeitemIMFile2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMFile2()
		{
	WdbeMFile* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemfile->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		osrefKContent = rec->osrefKContent;
		Filename = rec->Filename;
		srefKMimetype = rec->srefKMimetype;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMFile2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {osrefKContent = txtrd.fields[0]; ixWIelValid += ImeIMFile2::VecWIel::OSREFKCONTENT;};
	if (txtrd.fields.size() > 1) {Filename = txtrd.fields[1]; ixWIelValid += ImeIMFile2::VecWIel::FILENAME;};
	if (txtrd.fields.size() > 2) {srefKMimetype = txtrd.fields[2]; ixWIelValid += ImeIMFile2::VecWIel::SREFKMIMETYPE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMFile2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMFile2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "osrefKContent", "cnt", osrefKContent)) ixWIelValid += ImeIMFile2::VecWIel::OSREFKCONTENT;
		if (extractStringUclc(docctx, basexpath, "Filename", "fnm", Filename)) ixWIelValid += ImeIMFile2::VecWIel::FILENAME;
		if (extractStringUclc(docctx, basexpath, "srefKMimetype", "mim", srefKMimetype)) ixWIelValid += ImeIMFile2::VecWIel::SREFKMIMETYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFile2::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIMFile2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << osrefKContent << "\t" << Filename << "\t" << srefKMimetype << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIMFile2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cnt","fnm","mim","cmt"};
	else tags = {"ImeitemIMFile2","osrefKContent","Filename","srefKMimetype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], osrefKContent);
		writeString(wr, tags[2], Filename);
		writeString(wr, tags[3], srefKMimetype);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMFile2::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMFile2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "osrefkcontent") ix |= OSREFKCONTENT;
		else if (ss[i] == "filename") ix |= FILENAME;
		else if (ss[i] == "srefkmimetype") ix |= SREFKMIMETYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMFile2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMFile2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & OSREFKCONTENT) ss.push_back("osrefKContent");
	if (ix & FILENAME) ss.push_back("Filename");
	if (ix & SREFKMIMETYPE) ss.push_back("srefKMimetype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMFile2
 ******************************************************************************/

IexWdbeIni::ImeIMFile2::ImeIMFile2() {
};

IexWdbeIni::ImeIMFile2::~ImeIMFile2() {
	clear();
};

void IexWdbeIni::ImeIMFile2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMFile2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMFile2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIMFile2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFile2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFILE2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFile2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMFile2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMFile2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFile2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFile2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFile2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMFile2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMFile2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMFile2." << StrMod::replaceChar(ImeIMFile2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMFile2.end" << endl;
	};
};

void IexWdbeIni::ImeIMFile2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFile2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMGeneric
 ******************************************************************************/

IexWdbeIni::ImeitemIMGeneric::ImeitemIMGeneric(
			const ubigint irefRefWdbeCGeneric
			, const string& sref
			, const string& srefWdbeKHdltype
			, const usmallint Width
			, const string& Minmax
			, const string& Defval
			, const string& Comment
		) : WdbeMGeneric() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWdbeCGeneric = irefRefWdbeCGeneric;
	this->sref = sref;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Defval = Defval;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMGeneric::ImeitemIMGeneric(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMGeneric()
		{
	WdbeMGeneric* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemgeneric->loadRecByRef(ref, &rec)) {
		refWdbeCGeneric = rec->refWdbeCGeneric;
		mdlRefWdbeMModule = rec->mdlRefWdbeMModule;
		mdlNum = rec->mdlNum;
		sref = rec->sref;
		srefWdbeKHdltype = rec->srefWdbeKHdltype;
		Width = rec->Width;
		Minmax = rec->Minmax;
		Defval = rec->Defval;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMGeneric::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWdbeCGeneric = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMGeneric::VecWIel::IREFREFWDBECGENERIC;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMGeneric::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefWdbeKHdltype = txtrd.fields[2]; ixWIelValid += ImeIMGeneric::VecWIel::SREFWDBEKHDLTYPE;};
	if (txtrd.fields.size() > 3) {Width = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIMGeneric::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 4) {Minmax = txtrd.fields[4]; ixWIelValid += ImeIMGeneric::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 5) {Defval = txtrd.fields[5]; ixWIelValid += ImeIMGeneric::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMGeneric::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMGeneric"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMGeneric::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCGeneric", "clu", irefRefWdbeCGeneric)) ixWIelValid += ImeIMGeneric::VecWIel::IREFREFWDBECGENERIC;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMGeneric::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype)) ixWIelValid += ImeIMGeneric::VecWIel::SREFWDBEKHDLTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMGeneric::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMGeneric::VecWIel::MINMAX;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIMGeneric::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMGeneric::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIMGeneric::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << irefRefWdbeCGeneric << "\t" << sref << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Defval << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIMGeneric::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","hty","wid","mmx","dfv","cmt"};
	else tags = {"ImeitemIMGeneric","irefRefWdbeCGeneric","sref","srefWdbeKHdltype","Width","Minmax","Defval","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWdbeCGeneric);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefWdbeKHdltype);
		writeUsmallint(wr, tags[4], Width);
		writeString(wr, tags[5], Minmax);
		writeString(wr, tags[6], Defval);
		writeString(wr, tags[7], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMGeneric::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMGeneric::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwdbecgeneric") ix |= IREFREFWDBECGENERIC;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefwdbekhdltype") ix |= SREFWDBEKHDLTYPE;
		else if (ss[i] == "width") ix |= WIDTH;
		else if (ss[i] == "minmax") ix |= MINMAX;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMGeneric::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMGeneric::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWDBECGENERIC) ss.push_back("irefRefWdbeCGeneric");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFWDBEKHDLTYPE) ss.push_back("srefWdbeKHdltype");
	if (ix & WIDTH) ss.push_back("Width");
	if (ix & MINMAX) ss.push_back("Minmax");
	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMGeneric
 ******************************************************************************/

IexWdbeIni::ImeIMGeneric::ImeIMGeneric() {
};

IexWdbeIni::ImeIMGeneric::~ImeIMGeneric() {
	clear();
};

void IexWdbeIni::ImeIMGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMGeneric::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMGeneric* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIMGeneric();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMGeneric"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMGeneric"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMGENERIC) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMGeneric"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMGeneric"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMGeneric* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMGeneric");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMGeneric", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMGeneric";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMGeneric();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMGeneric::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMGeneric." << StrMod::replaceChar(ImeIMGeneric::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMGeneric.end" << endl;
	};
};

void IexWdbeIni::ImeIMGeneric::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMGeneric");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMPort
 ******************************************************************************/

IexWdbeIni::ImeitemIMPort::ImeitemIMPort(
			const ubigint irefRefWdbeCPort
			, const uint mdlIxVCat
			, const string& sref
			, const uint ixVDir
			, const string& srefWdbeKHdltype
			, const usmallint Width
			, const string& Minmax
			, const string& Defval
			, const string& Comment
		) : WdbeMPort() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWdbeCPort = irefRefWdbeCPort;
	this->mdlIxVCat = mdlIxVCat;
	this->sref = sref;
	this->ixVDir = ixVDir;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Defval = Defval;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMPort::ImeitemIMPort(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMPort()
		{
	WdbeMPort* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemport->loadRecByRef(ref, &rec)) {
		refWdbeCPort = rec->refWdbeCPort;
		mdlRefWdbeMModule = rec->mdlRefWdbeMModule;
		mdlNum = rec->mdlNum;
		mdlIxVCat = rec->mdlIxVCat;
		sref = rec->sref;
		ixVDir = rec->ixVDir;
		srefWdbeKHdltype = rec->srefWdbeKHdltype;
		Width = rec->Width;
		Minmax = rec->Minmax;
		Defval = rec->Defval;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMPort::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWdbeCPort = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMPort::VecWIel::IREFREFWDBECPORT;};
	if (txtrd.fields.size() > 1) {srefMdlIxVCat = txtrd.fields[1]; ixWIelValid += ImeIMPort::VecWIel::SREFMDLIXVCAT;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMPort::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {srefIxVDir = txtrd.fields[3]; ixWIelValid += ImeIMPort::VecWIel::SREFIXVDIR;};
	if (txtrd.fields.size() > 4) {srefWdbeKHdltype = txtrd.fields[4]; ixWIelValid += ImeIMPort::VecWIel::SREFWDBEKHDLTYPE;};
	if (txtrd.fields.size() > 5) {Width = atoi(txtrd.fields[5].c_str()); ixWIelValid += ImeIMPort::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 6) {Minmax = txtrd.fields[6]; ixWIelValid += ImeIMPort::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 7) {Defval = txtrd.fields[7]; ixWIelValid += ImeIMPort::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 8) {Comment = txtrd.fields[8]; ixWIelValid += ImeIMPort::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPort"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMPort::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCPort", "clu", irefRefWdbeCPort)) ixWIelValid += ImeIMPort::VecWIel::IREFREFWDBECPORT;
		if (extractStringUclc(docctx, basexpath, "srefMdlIxVCat", "mdc", srefMdlIxVCat)) ixWIelValid += ImeIMPort::VecWIel::SREFMDLIXVCAT;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPort::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir)) ixWIelValid += ImeIMPort::VecWIel::SREFIXVDIR;
		if (extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype)) ixWIelValid += ImeIMPort::VecWIel::SREFWDBEKHDLTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMPort::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMPort::VecWIel::MINMAX;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIMPort::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMPort::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIMPort::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << irefRefWdbeCPort << "\t" << VecWdbeVMPortMdlCat::getSref(mdlIxVCat) << "\t" << sref << "\t" << VecWdbeVMPortDir::getSref(ixVDir) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Defval << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIMPort::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","mdc","srf","dir","hty","wid","mmx","dfv","cmt"};
	else tags = {"ImeitemIMPort","irefRefWdbeCPort","srefMdlIxVCat","sref","srefIxVDir","srefWdbeKHdltype","Width","Minmax","Defval","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWdbeCPort);
		writeString(wr, tags[2], VecWdbeVMPortMdlCat::getSref(mdlIxVCat));
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], VecWdbeVMPortDir::getSref(ixVDir));
		writeString(wr, tags[5], srefWdbeKHdltype);
		writeUsmallint(wr, tags[6], Width);
		writeString(wr, tags[7], Minmax);
		writeString(wr, tags[8], Defval);
		writeString(wr, tags[9], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMPort::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMPort::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwdbecport") ix |= IREFREFWDBECPORT;
		else if (ss[i] == "srefmdlixvcat") ix |= SREFMDLIXVCAT;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvdir") ix |= SREFIXVDIR;
		else if (ss[i] == "srefwdbekhdltype") ix |= SREFWDBEKHDLTYPE;
		else if (ss[i] == "width") ix |= WIDTH;
		else if (ss[i] == "minmax") ix |= MINMAX;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMPort::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMPort::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWDBECPORT) ss.push_back("irefRefWdbeCPort");
	if (ix & SREFMDLIXVCAT) ss.push_back("srefMdlIxVCat");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVDIR) ss.push_back("srefIxVDir");
	if (ix & SREFWDBEKHDLTYPE) ss.push_back("srefWdbeKHdltype");
	if (ix & WIDTH) ss.push_back("Width");
	if (ix & MINMAX) ss.push_back("Minmax");
	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMPort
 ******************************************************************************/

IexWdbeIni::ImeIMPort::ImeIMPort() {
};

IexWdbeIni::ImeIMPort::~ImeIMPort() {
	clear();
};

void IexWdbeIni::ImeIMPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMPort::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMPort* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIMPort();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPort"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPort"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPORT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPort"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPort"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMPort* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPort");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPort", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPort";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMPort();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMPort::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMPort." << StrMod::replaceChar(ImeIMPort::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMPort.end" << endl;
	};
};

void IexWdbeIni::ImeIMPort::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPort");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMModule
 ******************************************************************************/

IexWdbeIni::ImeitemIMModule::ImeitemIMModule(
			const uint ixVBasetype
			, const string& hsrefSupRefWdbeMModule
			, const string& srefTplRefWdbeMModule
			, const string& sref
			, const string& Srefrule
			, const string& Comment
		) : WdbeMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->hsrefSupRefWdbeMModule = hsrefSupRefWdbeMModule;
	this->srefTplRefWdbeMModule = srefTplRefWdbeMModule;
	this->sref = sref;
	this->Srefrule = Srefrule;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMModule::ImeitemIMModule(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMModule()
		{
	WdbeMModule* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		hkIxVTbl = rec->hkIxVTbl;
		supRefWdbeMModule = rec->supRefWdbeMModule;
		tplRefWdbeMModule = rec->tplRefWdbeMModule;
		refWdbeMController = rec->refWdbeMController;
		sref = rec->sref;
		Srefrule = rec->Srefrule;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMModule::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMModule::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {hsrefSupRefWdbeMModule = txtrd.fields[1]; ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;};
	if (txtrd.fields.size() > 2) {srefTplRefWdbeMModule = txtrd.fields[2]; ixWIelValid += ImeIMModule::VecWIel::SREFTPLREFWDBEMMODULE;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMModule::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Srefrule = txtrd.fields[4]; ixWIelValid += ImeIMModule::VecWIel::SREFRULE;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIMModule::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMMODULEPAR)) {
					imeiammodulepar.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY3)) {
					imeiavkeylistkey3.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICGENERIC)) {
					imeicgeneric.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICPORT)) {
					imeicport.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMCONTROLLER)) {
					imeimcontroller.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMFILE2)) {
					imeimfile2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMGENERIC)) {
					imeimgeneric.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMPORT)) {
					imeimport.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMModule"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMModule::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMModule::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefWdbeMModule", "sup", hsrefSupRefWdbeMModule)) ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "srefTplRefWdbeMModule", "tpl", srefTplRefWdbeMModule)) ixWIelValid += ImeIMModule::VecWIel::SREFTPLREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMModule::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Srefrule", "srr", Srefrule)) ixWIelValid += ImeIMModule::VecWIel::SREFRULE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMModule::VecWIel::COMMENT;
		imeiammodulepar.readXML(docctx, basexpath);
		imeiavkeylistkey3.readXML(docctx, basexpath);
		imeicgeneric.readXML(docctx, basexpath);
		imeicport.readXML(docctx, basexpath);
		imeimcontroller.readXML(docctx, basexpath);
		imeimfile2.readXML(docctx, basexpath);
		imeimgeneric.readXML(docctx, basexpath);
		imeimport.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVMModuleBasetype::getSref(ixVBasetype) << "\t" << hsrefSupRefWdbeMModule << "\t" << srefTplRefWdbeMModule << "\t" << sref << "\t" << Srefrule << "\t" << Comment << endl;
	imeiammodulepar.writeTxt(outfile);
	imeiavkeylistkey3.writeTxt(outfile);
	imeicgeneric.writeTxt(outfile);
	imeicport.writeTxt(outfile);
	imeimcontroller.writeTxt(outfile);
	imeimfile2.writeTxt(outfile);
	imeimgeneric.writeTxt(outfile);
	imeimport.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMModule::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","sup","tpl","srf","srr","cmt"};
	else tags = {"ImeitemIMModule","srefIxVBasetype","hsrefSupRefWdbeMModule","srefTplRefWdbeMModule","sref","Srefrule","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMModuleBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], hsrefSupRefWdbeMModule);
		writeString(wr, tags[3], srefTplRefWdbeMModule);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Srefrule);
		writeString(wr, tags[6], Comment);
		imeiammodulepar.writeXML(wr, shorttags);
		imeiavkeylistkey3.writeXML(wr, shorttags);
		imeicgeneric.writeXML(wr, shorttags);
		imeicport.writeXML(wr, shorttags);
		imeimcontroller.writeXML(wr, shorttags);
		imeimfile2.writeXML(wr, shorttags);
		imeimgeneric.writeXML(wr, shorttags);
		imeimport.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMModule::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "hsrefsuprefwdbemmodule") ix |= HSREFSUPREFWDBEMMODULE;
		else if (ss[i] == "sreftplrefwdbemmodule") ix |= SREFTPLREFWDBEMMODULE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefrule") ix |= SREFRULE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMModule::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & HSREFSUPREFWDBEMMODULE) ss.push_back("hsrefSupRefWdbeMModule");
	if (ix & SREFTPLREFWDBEMMODULE) ss.push_back("srefTplRefWdbeMModule");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFRULE) ss.push_back("Srefrule");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMModule
 ******************************************************************************/

IexWdbeIni::ImeIMModule::ImeIMModule() {
};

IexWdbeIni::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWdbeIni::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIMModule();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMModule"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMMODULE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMModule"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMModule"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMModule* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMModule");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMModule", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMModule";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMModule.end" << endl;
	};
};

void IexWdbeIni::ImeIMModule::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMModule");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIJMPinSref
 ******************************************************************************/

IexWdbeIni::ImeitemIJMPinSref::ImeitemIJMPinSref(
			const string& srefX1RefWdbeMPeripheral
			, const string& sref
		) : WdbeJMPinSref() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWdbeMPeripheral = srefX1RefWdbeMPeripheral;
	this->sref = sref;
};

IexWdbeIni::ImeitemIJMPinSref::ImeitemIJMPinSref(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIJMPinSref()
		{
	WdbeJMPinSref* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbejmpinsref->loadRecByRef(ref, &rec)) {
		refWdbeMPin = rec->refWdbeMPin;
		x1RefWdbeMPeripheral = rec->x1RefWdbeMPeripheral;
		sref = rec->sref;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIJMPinSref::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1RefWdbeMPeripheral = txtrd.fields[0]; ixWIelValid += ImeIJMPinSref::VecWIel::SREFX1REFWDBEMPERIPHERAL;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIJMPinSref::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPinSref"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIJMPinSref::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWdbeMPeripheral", "", srefX1RefWdbeMPeripheral)) ixWIelValid += ImeIJMPinSref::VecWIel::SREFX1REFWDBEMPERIPHERAL;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIJMPinSref::VecWIel::SREF;
	};
};

void IexWdbeIni::ImeitemIJMPinSref::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWdbeMPeripheral << "\t" << sref << endl;
};

void IexWdbeIni::ImeitemIJMPinSref::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","","srf"};
	else tags = {"ImeitemIJMPinSref","srefX1RefWdbeMPeripheral","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefX1RefWdbeMPeripheral);
		writeString(wr, tags[2], sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIJMPinSref::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIJMPinSref::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwdbemperipheral") ix |= SREFX1REFWDBEMPERIPHERAL;
		else if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWdbeIni::ImeIJMPinSref::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIJMPinSref::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1REFWDBEMPERIPHERAL) ss.push_back("srefX1RefWdbeMPeripheral");
	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIJMPinSref
 ******************************************************************************/

IexWdbeIni::ImeIJMPinSref::ImeIJMPinSref() {
};

IexWdbeIni::ImeIJMPinSref::~ImeIJMPinSref() {
	clear();
};

void IexWdbeIni::ImeIJMPinSref::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIJMPinSref::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIJMPinSref* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeIni::ImeitemIJMPinSref();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPinSref"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPinSref"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMPINSREF) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPinSref"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPinSref"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIJMPinSref::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIJMPinSref* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPinSref");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPinSref", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPinSref";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIJMPinSref();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIJMPinSref::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPinSref." << StrMod::replaceChar(ImeIJMPinSref::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMPinSref.end" << endl;
	};
};

void IexWdbeIni::ImeIJMPinSref::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPinSref");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMPin
 ******************************************************************************/

IexWdbeIni::ImeitemIMPin::ImeitemIMPin(
			const string& sref
			, const string& Location
		) : WdbeMPin() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Location = Location;
};

IexWdbeIni::ImeitemIMPin::ImeitemIMPin(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMPin()
		{
	WdbeMPin* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbempin->loadRecByRef(ref, &rec)) {
		refWdbeMBank = rec->refWdbeMBank;
		refJSref = rec->refJSref;
		sref = rec->sref;
		Location = rec->Location;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMPin::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMPin::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Location = txtrd.fields[1]; ixWIelValid += ImeIMPin::VecWIel::LOCATION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPINSREF)) {
					imeijmpinsref.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPin"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMPin::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPin::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Location", "loc", Location)) ixWIelValid += ImeIMPin::VecWIel::LOCATION;
		imeijmpinsref.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMPin::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Location << endl;
	imeijmpinsref.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMPin::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","loc"};
	else tags = {"ImeitemIMPin","sref","Location"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Location);
		imeijmpinsref.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMPin::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMPin::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "location") ix |= LOCATION;
	};

	return(ix);
};

void IexWdbeIni::ImeIMPin::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LOCATION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMPin::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & LOCATION) ss.push_back("Location");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMPin
 ******************************************************************************/

IexWdbeIni::ImeIMPin::ImeIMPin() {
};

IexWdbeIni::ImeIMPin::~ImeIMPin() {
	clear();
};

void IexWdbeIni::ImeIMPin::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMPin::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMPin* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIMPin();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPin"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPin"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPIN) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPin"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPin"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMPin::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMPin* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPin");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPin", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPin";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMPin();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMPin::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPin." << StrMod::replaceChar(ImeIMPin::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPin.end" << endl;
	};
};

void IexWdbeIni::ImeIMPin::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPin");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMBank
 ******************************************************************************/

IexWdbeIni::ImeitemIMBank::ImeitemIMBank(
			const string& sref
		) : WdbeMBank() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexWdbeIni::ImeitemIMBank::ImeitemIMBank(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMBank()
		{
	WdbeMBank* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbembank->loadRecByRef(ref, &rec)) {
		refWdbeMUnit = rec->refWdbeMUnit;
		sref = rec->sref;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMBank::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMBank::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPIN)) {
					imeimpin.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBank"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMBank::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMBank::VecWIel::SREF;
		imeimpin.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMBank::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << endl;
	imeimpin.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMBank::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf"};
	else tags = {"ImeitemIMBank","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		imeimpin.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMBank::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMBank::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWdbeIni::ImeIMBank::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMBank::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMBank
 ******************************************************************************/

IexWdbeIni::ImeIMBank::ImeIMBank() {
};

IexWdbeIni::ImeIMBank::~ImeIMBank() {
	clear();
};

void IexWdbeIni::ImeIMBank::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMBank::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMBank* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIMBank();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBank"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMBank"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMBANK) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBank"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMBank"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMBank::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMBank* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMBank");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMBank", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMBank";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMBank();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMBank::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMBank." << StrMod::replaceChar(ImeIMBank::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMBank.end" << endl;
	};
};

void IexWdbeIni::ImeIMBank::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMBank");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIJAVKeylistKey2
 ******************************************************************************/

IexWdbeIni::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
			const string& Title
			, const string& Comment
		) : WdbeJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIJAVKeylistKey2::ImeitemIJAVKeylistKey2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey2()
		{
	WdbeJAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbejavkeylistkey->loadRecByRef(ref, &rec)) {
		refWdbeAVKeylistKey = rec->refWdbeAVKeylistKey;
		x1IxWdbeVLocale = rec->x1IxWdbeVLocale;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIJAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Title = txtrd.fields[0]; ixWIelValid += ImeIJAVKeylistKey2::VecWIel::TITLE;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIJAVKeylistKey2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIJAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey2::VecWIel::COMMENT;
	};
};

void IexWdbeIni::ImeitemIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Title << "\t" << Comment << endl;
};

void IexWdbeIni::ImeitemIJAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey2","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		writeString(wr, tags[2], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIJAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIJAVKeylistKey2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIJAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIJAVKeylistKey2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIJAVKeylistKey2
 ******************************************************************************/

IexWdbeIni::ImeIJAVKeylistKey2::ImeIJAVKeylistKey2() {
};

IexWdbeIni::ImeIJAVKeylistKey2::~ImeIJAVKeylistKey2() {
	clear();
};

void IexWdbeIni::ImeIJAVKeylistKey2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIJAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIJAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeIni::ImeitemIJAVKeylistKey2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIJAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIJAVKeylistKey2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIJAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIJAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJAVKeylistKey2." << StrMod::replaceChar(ImeIJAVKeylistKey2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJAVKeylistKey2.end" << endl;
	};
};

void IexWdbeIni::ImeIJAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAVKeylistKey2
 ******************************************************************************/

IexWdbeIni::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
			const string& sref
			, const string& Title
			, const string& Comment
		) : WdbeAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIAVKeylistKey2::ImeitemIAVKeylistKey2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey2()
		{
	WdbeAVKeylistKey* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeavkeylistkey->loadRecByRef(ref, &rec)) {
		klsIxWdbeVKeylist = rec->klsIxWdbeVKeylist;
		klsNum = rec->klsNum;
		x1IxWdbeVMaintable = rec->x1IxWdbeVMaintable;
		x1Uref = rec->x1Uref;
		Fixed = rec->Fixed;
		sref = rec->sref;
		refJ = rec->refJ;
		Title = rec->Title;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey2::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY2)) {
					imeijavkeylistkey2.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAVKeylistKey2::VecWIel::COMMENT;
		imeijavkeylistkey2.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey2.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","cmt"};
	else tags = {"ImeitemIAVKeylistKey2","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
		imeijavkeylistkey2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVKeylistKey2::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAVKeylistKey2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIAVKeylistKey2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAVKeylistKey2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAVKeylistKey2
 ******************************************************************************/

IexWdbeIni::ImeIAVKeylistKey2::ImeIAVKeylistKey2() {
};

IexWdbeIni::ImeIAVKeylistKey2::~ImeIAVKeylistKey2() {
	clear();
};

void IexWdbeIni::ImeIAVKeylistKey2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAVKeylistKey2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAVKeylistKey2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIAVKeylistKey2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAVKeylistKey2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAVKeylistKey2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAVKeylistKey2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAVKeylistKey2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAVKeylistKey2." << StrMod::replaceChar(ImeIAVKeylistKey2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAVKeylistKey2.end" << endl;
	};
};

void IexWdbeIni::ImeIAVKeylistKey2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMPeripheral
 ******************************************************************************/

IexWdbeIni::ImeitemIMPeripheral::ImeitemIMPeripheral(
			const string& sref
			, const string& Comment
		) : WdbeMPeripheral() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMPeripheral::ImeitemIMPeripheral(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMPeripheral()
		{
	WdbeMPeripheral* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemperipheral->loadRecByRef(ref, &rec)) {
		refWdbeMUnit = rec->refWdbeMUnit;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMPeripheral::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMPeripheral::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMPeripheral::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY2)) {
					imeiavkeylistkey2.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPeripheral"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMPeripheral::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPeripheral::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMPeripheral::VecWIel::COMMENT;
		imeiavkeylistkey2.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMPeripheral::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Comment << endl;
	imeiavkeylistkey2.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMPeripheral::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMPeripheral","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiavkeylistkey2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMPeripheral::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMPeripheral::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMPeripheral::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMPeripheral::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMPeripheral
 ******************************************************************************/

IexWdbeIni::ImeIMPeripheral::ImeIMPeripheral() {
};

IexWdbeIni::ImeIMPeripheral::~ImeIMPeripheral() {
	clear();
};

void IexWdbeIni::ImeIMPeripheral::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMPeripheral::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMPeripheral* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIMPeripheral();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPeripheral"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPeripheral"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPERIPHERAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPeripheral"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPeripheral"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMPeripheral::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMPeripheral* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPeripheral");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPeripheral", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPeripheral";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMPeripheral();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMPeripheral::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMPeripheral." << StrMod::replaceChar(ImeIMPeripheral::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMPeripheral.end" << endl;
	};
};

void IexWdbeIni::ImeIMPeripheral::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPeripheral");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMUnit
 ******************************************************************************/

IexWdbeIni::ImeitemIMUnit::ImeitemIMUnit(
			const uint ixVBasetype
			, const uint refIxVTbl
			, const ubigint irefRefUref
			, const string& sref
			, const string& Title
			, const string& srefKPackage
			, const string& Comment
		) : WdbeMUnit() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->refIxVTbl = refIxVTbl;
	this->irefRefUref = irefRefUref;
	this->sref = sref;
	this->Title = Title;
	this->srefKPackage = srefKPackage;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMUnit::ImeitemIMUnit(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMUnit()
		{
	WdbeMUnit* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemunit->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		sref = rec->sref;
		Title = rec->Title;
		srefKPackage = rec->srefKPackage;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMUnit::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMUnit::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefRefIxVTbl = txtrd.fields[1]; ixWIelValid += ImeIMUnit::VecWIel::SREFREFIXVTBL;};
	if (txtrd.fields.size() > 2) {irefRefUref = atoll(txtrd.fields[2].c_str()); ixWIelValid += ImeIMUnit::VecWIel::IREFREFUREF;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMUnit::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Title = txtrd.fields[4]; ixWIelValid += ImeIMUnit::VecWIel::TITLE;};
	if (txtrd.fields.size() > 5) {srefKPackage = txtrd.fields[5]; ixWIelValid += ImeIMUnit::VecWIel::SREFKPACKAGE;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMUnit::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMBANK)) {
					imeimbank.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMPERIPHERAL)) {
					imeimperipheral.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUnit"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMUnit::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMUnit::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefIxVTbl", "ret", srefRefIxVTbl)) ixWIelValid += ImeIMUnit::VecWIel::SREFREFIXVTBL;
		if (extractUbigintUclc(docctx, basexpath, "irefRefUref", "reu", irefRefUref)) ixWIelValid += ImeIMUnit::VecWIel::IREFREFUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUnit::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMUnit::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "srefKPackage", "pkg", srefKPackage)) ixWIelValid += ImeIMUnit::VecWIel::SREFKPACKAGE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUnit::VecWIel::COMMENT;
		imeimbank.readXML(docctx, basexpath);
		imeimperipheral.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMUnit::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVMUnitBasetype::getSref(ixVBasetype) << "\t" << VecWdbeVMUnitRefTbl::getSref(refIxVTbl) << "\t" << irefRefUref << "\t" << sref << "\t" << Title << "\t" << srefKPackage << "\t" << Comment << endl;
	imeimbank.writeTxt(outfile);
	imeimperipheral.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMUnit::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","ret","reu","srf","tit","pkg","cmt"};
	else tags = {"ImeitemIMUnit","srefIxVBasetype","srefRefIxVTbl","irefRefUref","sref","Title","srefKPackage","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMUnitBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], VecWdbeVMUnitRefTbl::getSref(refIxVTbl));
		writeUbigint(wr, tags[3], irefRefUref);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Title);
		writeString(wr, tags[6], srefKPackage);
		writeString(wr, tags[7], Comment);
		imeimbank.writeXML(wr, shorttags);
		imeimperipheral.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMUnit::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMUnit::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefixvtbl") ix |= SREFREFIXVTBL;
		else if (ss[i] == "irefrefuref") ix |= IREFREFUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "srefkpackage") ix |= SREFKPACKAGE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMUnit::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMUnit::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFIXVTBL) ss.push_back("srefRefIxVTbl");
	if (ix & IREFREFUREF) ss.push_back("irefRefUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & SREFKPACKAGE) ss.push_back("srefKPackage");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMUnit
 ******************************************************************************/

IexWdbeIni::ImeIMUnit::ImeIMUnit() {
};

IexWdbeIni::ImeIMUnit::~ImeIMUnit() {
	clear();
};

void IexWdbeIni::ImeIMUnit::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMUnit::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMUnit* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIMUnit();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUnit"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUNIT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUnit"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUnit"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMUnit::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMUnit* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUnit");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUnit", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUnit";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMUnit();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMUnit::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUnit." << StrMod::replaceChar(ImeIMUnit::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUnit.end" << endl;
	};
};

void IexWdbeIni::ImeIMUnit::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUnit");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAMUsergroupAccess
 ******************************************************************************/

IexWdbeIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			const uint x1IxWdbeVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixWdbeWAccess
		) : WdbeAMUsergroupAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWdbeVFeatgroup = x1IxWdbeVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWdbeWAccess = ixWdbeWAccess;
};

IexWdbeIni::ImeitemIAMUsergroupAccess::ImeitemIAMUsergroupAccess(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMUsergroupAccess()
		{
	WdbeAMUsergroupAccess* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamusergroupaccess->loadRecByRef(ref, &rec)) {
		refWdbeMUsergroup = rec->refWdbeMUsergroup;
		x1IxWdbeVFeatgroup = rec->x1IxWdbeVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixWdbeWAccess = rec->ixWdbeWAccess;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWdbeVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXWDBEVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxWdbeWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXWDBEWACCESS;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWdbeVFeatgroup", "feg", srefX1IxWdbeVFeatgroup)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFX1IXWDBEVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxWdbeWAccess", "acc", srefsIxWdbeWAccess)) ixWIelValid += ImeIAMUsergroupAccess::VecWIel::SREFSIXWDBEWACCESS;
	};
};

void IexWdbeIni::ImeitemIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVFeatgroup::getSref(x1IxWdbeVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecWdbeWAccess::getSrefs(ixWdbeWAccess) << endl;
};

void IexWdbeIni::ImeitemIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUsergroupAccess","srefX1IxWdbeVFeatgroup","x2FeaSrefUix","srefsIxWdbeWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVFeatgroup::getSref(x1IxWdbeVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecWdbeWAccess::getSrefs(ixWdbeWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMUsergroupAccess::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAMUsergroupAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwdbevfeatgroup") ix |= SREFX1IXWDBEVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixwdbewaccess") ix |= SREFSIXWDBEWACCESS;
	};

	return(ix);
};

void IexWdbeIni::ImeIAMUsergroupAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXWDBEWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAMUsergroupAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWDBEVFEATGROUP) ss.push_back("srefX1IxWdbeVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXWDBEWACCESS) ss.push_back("srefsIxWdbeWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMUsergroupAccess
 ******************************************************************************/

IexWdbeIni::ImeIAMUsergroupAccess::ImeIAMUsergroupAccess() {
};

IexWdbeIni::ImeIAMUsergroupAccess::~ImeIAMUsergroupAccess() {
	clear();
};

void IexWdbeIni::ImeIAMUsergroupAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAMUsergroupAccess::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAMUsergroupAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIAMUsergroupAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUsergroupAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAMUsergroupAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAMUsergroupAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUsergroupAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUsergroupAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUsergroupAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAMUsergroupAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAMUsergroupAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMUsergroupAccess." << StrMod::replaceChar(ImeIAMUsergroupAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMUsergroupAccess.end" << endl;
	};
};

void IexWdbeIni::ImeIAMUsergroupAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUsergroupAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIAMUserAccess
 ******************************************************************************/

IexWdbeIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			const uint x1IxWdbeVFeatgroup
			, const string& x2FeaSrefUix
			, const uint ixWdbeWAccess
		) : WdbeAMUserAccess() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1IxWdbeVFeatgroup = x1IxWdbeVFeatgroup;
	this->x2FeaSrefUix = x2FeaSrefUix;
	this->ixWdbeWAccess = ixWdbeWAccess;
};

IexWdbeIni::ImeitemIAMUserAccess::ImeitemIAMUserAccess(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMUserAccess()
		{
	WdbeAMUserAccess* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamuseraccess->loadRecByRef(ref, &rec)) {
		refWdbeMUser = rec->refWdbeMUser;
		x1IxWdbeVFeatgroup = rec->x1IxWdbeVFeatgroup;
		x2FeaSrefUix = rec->x2FeaSrefUix;
		ixWdbeWAccess = rec->ixWdbeWAccess;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefX1IxWdbeVFeatgroup = txtrd.fields[0]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXWDBEVFEATGROUP;};
	if (txtrd.fields.size() > 1) {x2FeaSrefUix = txtrd.fields[1]; ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;};
	if (txtrd.fields.size() > 2) {srefsIxWdbeWAccess = txtrd.fields[2]; ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXWDBEWACCESS;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1IxWdbeVFeatgroup", "feg", srefX1IxWdbeVFeatgroup)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFX1IXWDBEVFEATGROUP;
		if (extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix)) ixWIelValid += ImeIAMUserAccess::VecWIel::X2FEASREFUIX;
		if (extractStringUclc(docctx, basexpath, "srefsIxWdbeWAccess", "acc", srefsIxWdbeWAccess)) ixWIelValid += ImeIAMUserAccess::VecWIel::SREFSIXWDBEWACCESS;
	};
};

void IexWdbeIni::ImeitemIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVFeatgroup::getSref(x1IxWdbeVFeatgroup) << "\t" << x2FeaSrefUix << "\t" << VecWdbeWAccess::getSrefs(ixWdbeWAccess) << endl;
};

void IexWdbeIni::ImeitemIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","feg","fea","acc"};
	else tags = {"ImeitemIAMUserAccess","srefX1IxWdbeVFeatgroup","x2FeaSrefUix","srefsIxWdbeWAccess"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVFeatgroup::getSref(x1IxWdbeVFeatgroup));
		writeString(wr, tags[2], x2FeaSrefUix);
		writeString(wr, tags[3], VecWdbeWAccess::getSrefs(ixWdbeWAccess));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMUserAccess::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIAMUserAccess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1ixwdbevfeatgroup") ix |= SREFX1IXWDBEVFEATGROUP;
		else if (ss[i] == "x2feasrefuix") ix |= X2FEASREFUIX;
		else if (ss[i] == "srefsixwdbewaccess") ix |= SREFSIXWDBEWACCESS;
	};

	return(ix);
};

void IexWdbeIni::ImeIAMUserAccess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSIXWDBEWACCESS); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIAMUserAccess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFX1IXWDBEVFEATGROUP) ss.push_back("srefX1IxWdbeVFeatgroup");
	if (ix & X2FEASREFUIX) ss.push_back("x2FeaSrefUix");
	if (ix & SREFSIXWDBEWACCESS) ss.push_back("srefsIxWdbeWAccess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIAMUserAccess
 ******************************************************************************/

IexWdbeIni::ImeIAMUserAccess::ImeIAMUserAccess() {
};

IexWdbeIni::ImeIAMUserAccess::~ImeIAMUserAccess() {
	clear();
};

void IexWdbeIni::ImeIAMUserAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIAMUserAccess::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIAMUserAccess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIAMUserAccess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMUserAccess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIAMUserAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIAMUserAccess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMUserAccess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMUserAccess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMUserAccess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIAMUserAccess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIAMUserAccess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMUserAccess." << StrMod::replaceChar(ImeIAMUserAccess::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMUserAccess.end" << endl;
	};
};

void IexWdbeIni::ImeIAMUserAccess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMUserAccess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIJMUserState
 ******************************************************************************/

IexWdbeIni::ImeitemIJMUserState::ImeitemIJMUserState(
			const uint ixVState
		) : WdbeJMUserState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexWdbeIni::ImeitemIJMUserState::ImeitemIJMUserState(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIJMUserState()
		{
	WdbeJMUserState* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbejmuserstate->loadRecByRef(ref, &rec)) {
		refWdbeMUser = rec->refWdbeMUser;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVState = txtrd.fields[0]; ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIJMUserState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIJMUserState::VecWIel::SREFIXVSTATE;
	};
};

void IexWdbeIni::ImeitemIJMUserState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMUserState::getSref(ixVState) << endl;
};

void IexWdbeIni::ImeitemIJMUserState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMUserState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMUserState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIJMUserState::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIJMUserState::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
	};

	return(ix);
};

void IexWdbeIni::ImeIJMUserState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVSTATE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIJMUserState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIJMUserState
 ******************************************************************************/

IexWdbeIni::ImeIJMUserState::ImeIJMUserState() {
};

IexWdbeIni::ImeIJMUserState::~ImeIJMUserState() {
	clear();
};

void IexWdbeIni::ImeIJMUserState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIJMUserState::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIJMUserState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIJMUserState();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMUserState"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIJMUserState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIJMUserState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMUserState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMUserState", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMUserState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIJMUserState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIJMUserState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMUserState." << StrMod::replaceChar(ImeIJMUserState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMUserState.end" << endl;
	};
};

void IexWdbeIni::ImeIJMUserState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMUserState");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIJMPersonLastname
 ******************************************************************************/

IexWdbeIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			const string& Lastname
		) : WdbeJMPersonLastname() {
	lineno = 0;
	ixWIelValid = 0;

	this->Lastname = Lastname;
};

IexWdbeIni::ImeitemIJMPersonLastname::ImeitemIJMPersonLastname(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIJMPersonLastname()
		{
	WdbeJMPersonLastname* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbejmpersonlastname->loadRecByRef(ref, &rec)) {
		refWdbeMPerson = rec->refWdbeMPerson;
		x1Startd = rec->x1Startd;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Lastname = txtrd.fields[0]; ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIJMPersonLastname::VecWIel::LASTNAME;
	};
};

void IexWdbeIni::ImeitemIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Lastname << endl;
};

void IexWdbeIni::ImeitemIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lnm"};
	else tags = {"ImeitemIJMPersonLastname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Lastname);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIJMPersonLastname::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIJMPersonLastname::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexWdbeIni::ImeIJMPersonLastname::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIJMPersonLastname::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIJMPersonLastname
 ******************************************************************************/

IexWdbeIni::ImeIJMPersonLastname::ImeIJMPersonLastname() {
};

IexWdbeIni::ImeIJMPersonLastname::~ImeIJMPersonLastname() {
	clear();
};

void IexWdbeIni::ImeIJMPersonLastname::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIJMPersonLastname::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIJMPersonLastname* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeIni::ImeitemIJMPersonLastname();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMPersonLastname"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIJMPersonLastname::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIJMPersonLastname* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMPersonLastname");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMPersonLastname", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMPersonLastname";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIJMPersonLastname();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIJMPersonLastname::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPersonLastname." << StrMod::replaceChar(ImeIJMPersonLastname::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMPersonLastname.end" << endl;
	};
};

void IexWdbeIni::ImeIJMPersonLastname::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMPersonLastname");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMPerson
 ******************************************************************************/

IexWdbeIni::ImeitemIMPerson::ImeitemIMPerson(
			const uint ixVSex
			, const string& Title
			, const string& Firstname
			, const string& Lastname
		) : WdbeMPerson() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVSex = ixVSex;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
};

IexWdbeIni::ImeitemIMPerson::ImeitemIMPerson(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMPerson()
		{
	WdbeMPerson* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemperson->loadRecByRef(ref, &rec)) {
		ixWDerivate = rec->ixWDerivate;
		ixVSex = rec->ixVSex;
		Title = rec->Title;
		Firstname = rec->Firstname;
		refJLastname = rec->refJLastname;
		Lastname = rec->Lastname;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMPerson::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVSex = txtrd.fields[0]; ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMPerson::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Firstname = txtrd.fields[2]; ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;};
	if (txtrd.fields.size() > 3) {Lastname = txtrd.fields[3]; ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPERSONLASTNAME)) {
					imeijmpersonlastname.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMPerson::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex)) ixWIelValid += ImeIMPerson::VecWIel::SREFIXVSEX;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMPerson::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname)) ixWIelValid += ImeIMPerson::VecWIel::FIRSTNAME;
		if (extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname)) ixWIelValid += ImeIMPerson::VecWIel::LASTNAME;
		imeijmpersonlastname.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMPerson::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMPersonSex::getSref(ixVSex) << "\t" << Title << "\t" << Firstname << "\t" << Lastname << endl;
	imeijmpersonlastname.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMPerson::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sex","tit","fnm","lnm"};
	else tags = {"ImeitemIMPerson","srefIxVSex","Title","Firstname","Lastname"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMPersonSex::getSref(ixVSex));
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Firstname);
		writeString(wr, tags[4], Lastname);
		imeijmpersonlastname.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMPerson::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMPerson::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvsex") ix |= SREFIXVSEX;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "firstname") ix |= FIRSTNAME;
		else if (ss[i] == "lastname") ix |= LASTNAME;
	};

	return(ix);
};

void IexWdbeIni::ImeIMPerson::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LASTNAME); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMPerson::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSEX) ss.push_back("srefIxVSex");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & FIRSTNAME) ss.push_back("Firstname");
	if (ix & LASTNAME) ss.push_back("Lastname");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMPerson
 ******************************************************************************/

IexWdbeIni::ImeIMPerson::ImeIMPerson() {
};

IexWdbeIni::ImeIMPerson::~ImeIMPerson() {
	clear();
};

void IexWdbeIni::ImeIMPerson::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMPerson::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMPerson* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeIni::ImeitemIMPerson();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPERSON) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPerson"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMPerson::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMPerson* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPerson");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPerson", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPerson";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMPerson();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMPerson::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPerson." << StrMod::replaceChar(ImeIMPerson::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPerson.end" << endl;
	};
};

void IexWdbeIni::ImeIMPerson::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPerson");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMUser
 ******************************************************************************/

IexWdbeIni::ImeitemIMUser::ImeitemIMUser(
			const string& sref
			, const uint ixVState
			, const uint ixWdbeVLocale
			, const uint ixWdbeVUserlevel
			, const string& Password
			, const string& Fullkey
			, const string& Comment
		) : WdbeMUser() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixVState = ixVState;
	this->ixWdbeVLocale = ixWdbeVLocale;
	this->ixWdbeVUserlevel = ixWdbeVUserlevel;
	this->Password = Password;
	this->Fullkey = Fullkey;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMUser::ImeitemIMUser(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMUser()
		{
	WdbeMUser* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemuser->loadRecByRef(ref, &rec)) {
		refRUsergroup = rec->refRUsergroup;
		refWdbeMUsergroup = rec->refWdbeMUsergroup;
		refWdbeMPerson = rec->refWdbeMPerson;
		sref = rec->sref;
		refJState = rec->refJState;
		ixVState = rec->ixVState;
		ixWdbeVLocale = rec->ixWdbeVLocale;
		ixWdbeVUserlevel = rec->ixWdbeVUserlevel;
		Password = rec->Password;
		Fullkey = rec->Fullkey;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMUser::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUser::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxVState = txtrd.fields[1]; ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;};
	if (txtrd.fields.size() > 2) {srefIxWdbeVLocale = txtrd.fields[2]; ixWIelValid += ImeIMUser::VecWIel::SREFIXWDBEVLOCALE;};
	if (txtrd.fields.size() > 3) {srefIxWdbeVUserlevel = txtrd.fields[3]; ixWIelValid += ImeIMUser::VecWIel::SREFIXWDBEVUSERLEVEL;};
	if (txtrd.fields.size() > 4) {Password = txtrd.fields[4]; ixWIelValid += ImeIMUser::VecWIel::PASSWORD;};
	if (txtrd.fields.size() > 5) {Fullkey = txtrd.fields[5]; ixWIelValid += ImeIMUser::VecWIel::FULLKEY;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMUser::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMUSERACCESS)) {
					imeiamuseraccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMUSERSTATE)) {
					imeijmuserstate.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPERSON)) {
					imeimperson.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMUser::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUser::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIMUser::VecWIel::SREFIXVSTATE;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVLocale", "lcl", srefIxWdbeVLocale)) ixWIelValid += ImeIMUser::VecWIel::SREFIXWDBEVLOCALE;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVUserlevel", "ulv", srefIxWdbeVUserlevel)) ixWIelValid += ImeIMUser::VecWIel::SREFIXWDBEVUSERLEVEL;
		if (extractStringUclc(docctx, basexpath, "Password", "pwd", Password)) ixWIelValid += ImeIMUser::VecWIel::PASSWORD;
		if (extractStringUclc(docctx, basexpath, "Fullkey", "fky", Fullkey)) ixWIelValid += ImeIMUser::VecWIel::FULLKEY;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUser::VecWIel::COMMENT;
		imeiamuseraccess.readXML(docctx, basexpath);
		imeijmuserstate.readXML(docctx, basexpath);
		imeimperson.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMUser::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << VecWdbeVMUserState::getSref(ixVState) << "\t" << VecWdbeVLocale::getSref(ixWdbeVLocale) << "\t" << VecWdbeVUserlevel::getSref(ixWdbeVUserlevel) << "\t" << Password << "\t" << Fullkey << "\t" << Comment << endl;
	imeiamuseraccess.writeTxt(outfile);
	imeijmuserstate.writeTxt(outfile);
	imeimperson.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMUser::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","ste","lcl","ulv","pwd","fky","cmt"};
	else tags = {"ImeitemIMUser","sref","srefIxVState","srefIxWdbeVLocale","srefIxWdbeVUserlevel","Password","Fullkey","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWdbeVMUserState::getSref(ixVState));
		writeString(wr, tags[3], VecWdbeVLocale::getSref(ixWdbeVLocale));
		writeString(wr, tags[4], VecWdbeVUserlevel::getSref(ixWdbeVUserlevel));
		writeString(wr, tags[5], Password);
		writeString(wr, tags[6], Fullkey);
		writeString(wr, tags[7], Comment);
		imeiamuseraccess.writeXML(wr, shorttags);
		imeijmuserstate.writeXML(wr, shorttags);
		imeimperson.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMUser::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMUser::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvstate") ix |= SREFIXVSTATE;
		else if (ss[i] == "srefixwdbevlocale") ix |= SREFIXWDBEVLOCALE;
		else if (ss[i] == "srefixwdbevuserlevel") ix |= SREFIXWDBEVUSERLEVEL;
		else if (ss[i] == "password") ix |= PASSWORD;
		else if (ss[i] == "fullkey") ix |= FULLKEY;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMUser::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMUser::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");
	if (ix & SREFIXWDBEVLOCALE) ss.push_back("srefIxWdbeVLocale");
	if (ix & SREFIXWDBEVUSERLEVEL) ss.push_back("srefIxWdbeVUserlevel");
	if (ix & PASSWORD) ss.push_back("Password");
	if (ix & FULLKEY) ss.push_back("Fullkey");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMUser
 ******************************************************************************/

IexWdbeIni::ImeIMUser::ImeIMUser() {
};

IexWdbeIni::ImeIMUser::~ImeIMUser() {
	clear();
};

void IexWdbeIni::ImeIMUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMUser::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMUser* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeIni::ImeitemIMUser();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSER) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUser"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMUser* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUser");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUser", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUser";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMUser();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMUser::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMUser." << StrMod::replaceChar(ImeIMUser::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMUser.end" << endl;
	};
};

void IexWdbeIni::ImeIMUser::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUser");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeIni::ImeitemIMUsergroup
 ******************************************************************************/

IexWdbeIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			const string& sref
			, const string& Comment
		) : WdbeMUsergroup() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeIni::ImeitemIMUsergroup::ImeitemIMUsergroup(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMUsergroup()
		{
	WdbeMUsergroup* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemusergroup->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeIni::ImeitemIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUsergroup::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAMUSERGROUPACCESS)) {
					imeiamusergroupaccess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMUSER)) {
					imeimuser.readTxt(txtrd);
					continue;

				} else {
					txtrd.skip = true;
					return;
				};

			case Txtrd::VecVLinetype::DATA:
			case Txtrd::VecVLinetype::FOOTER:
				txtrd.skip = true;
				return;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeIni::ImeitemIMUsergroup::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUsergroup::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUsergroup::VecWIel::COMMENT;
		imeiamusergroupaccess.readXML(docctx, basexpath);
		imeimuser.readXML(docctx, basexpath);
	};
};

void IexWdbeIni::ImeitemIMUsergroup::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
	imeiamusergroupaccess.writeTxt(outfile);
	imeimuser.writeTxt(outfile);
};

void IexWdbeIni::ImeitemIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMUsergroup","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
		imeiamusergroupaccess.writeXML(wr, shorttags);
		imeimuser.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeIni::ImeIMUsergroup::VecWIel
 ******************************************************************************/

uint IexWdbeIni::ImeIMUsergroup::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeIni::ImeIMUsergroup::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeIni::ImeIMUsergroup::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeIni::ImeIMUsergroup
 ******************************************************************************/

IexWdbeIni::ImeIMUsergroup::ImeIMUsergroup() {
};

IexWdbeIni::ImeIMUsergroup::~ImeIMUsergroup() {
	clear();
};

void IexWdbeIni::ImeIMUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeIni::ImeIMUsergroup::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeIni::ImeitemIMUsergroup* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeIni::ImeitemIMUsergroup();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMUsergroup"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeIni::ImeIMUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeIni::ImeitemIMUsergroup* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMUsergroup");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMUsergroup", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMUsergroup";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeIni::ImeitemIMUsergroup();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeIni::ImeIMUsergroup::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUsergroup." << StrMod::replaceChar(ImeIMUsergroup::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUsergroup.end" << endl;
	};
};

void IexWdbeIni::ImeIMUsergroup::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMUsergroup");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWdbeIni
 ******************************************************************************/

void IexWdbeIni::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCoreproject& imeimcoreproject
			, ImeIMFamily& imeimfamily
			, ImeIMFile1& imeimfile1
			, ImeIMLibrary& imeimlibrary
			, ImeIMMachine& imeimmachine
			, ImeIMModule& imeimmodule
			, ImeIMUnit& imeimunit
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcoreproject, imeimfamily, imeimfile1, imeimlibrary, imeimmachine, imeimmodule, imeimunit, imeimusergroup);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWdbeIni", Version("0.9.73"), VecVIme::getIx);
			readTxt(rd, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcoreproject, imeimfamily, imeimfile1, imeimlibrary, imeimmachine, imeimmodule, imeimunit, imeimusergroup);
	};
};

void IexWdbeIni::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCoreproject& imeimcoreproject
			, ImeIMFamily& imeimfamily
			, ImeIMFile1& imeimfile1
			, ImeIMLibrary& imeimlibrary
			, ImeIMMachine& imeimmachine
			, ImeIMModule& imeimmodule
			, ImeIMUnit& imeimunit
			, ImeIMUsergroup& imeimusergroup
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcoreproject, imeimfamily, imeimfile1, imeimlibrary, imeimmachine, imeimmodule, imeimunit, imeimusergroup);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeiavcontrolpar, imeiavkeylistkey1, imeiavvaluelistval, imeimcoreproject, imeimfamily, imeimfile1, imeimlibrary, imeimmachine, imeimmodule, imeimunit, imeimusergroup);
		txtfile.close();
	};
};

void IexWdbeIni::readTxt(
			Txtrd& txtrd
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCoreproject& imeimcoreproject
			, ImeIMFamily& imeimfamily
			, ImeIMFile1& imeimfile1
			, ImeIMLibrary& imeimlibrary
			, ImeIMMachine& imeimmachine
			, ImeIMModule& imeimmodule
			, ImeIMUnit& imeimunit
			, ImeIMUsergroup& imeimusergroup
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR)) imeiavcontrolpar.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY1)) imeiavkeylistkey1.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL)) imeiavvaluelistval.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMCOREPROJECT)) imeimcoreproject.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMFAMILY)) imeimfamily.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMFILE1)) imeimfile1.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMLIBRARY)) imeimlibrary.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMMACHINE)) imeimmachine.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMMODULE)) imeimmodule.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMUNIT)) imeimunit.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP)) imeimusergroup.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWdbeIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCoreproject& imeimcoreproject
			, ImeIMFamily& imeimfamily
			, ImeIMFile1& imeimfile1
			, ImeIMLibrary& imeimlibrary
			, ImeIMMachine& imeimmachine
			, ImeIMModule& imeimmodule
			, ImeIMUnit& imeimunit
			, ImeIMUsergroup& imeimusergroup
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeIni")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.73")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.73"}});
		};

		// look for XML sub-blocks
		imeiavcontrolpar.readXML(docctx, basexpath);
		imeiavkeylistkey1.readXML(docctx, basexpath);
		imeiavvaluelistval.readXML(docctx, basexpath);
		imeimcoreproject.readXML(docctx, basexpath);
		imeimfamily.readXML(docctx, basexpath);
		imeimfile1.readXML(docctx, basexpath);
		imeimlibrary.readXML(docctx, basexpath);
		imeimmachine.readXML(docctx, basexpath);
		imeimmodule.readXML(docctx, basexpath);
		imeimunit.readXML(docctx, basexpath);
		imeimusergroup.readXML(docctx, basexpath);

	} else {
		imeiavcontrolpar = ImeIAVControlPar();
		imeiavkeylistkey1 = ImeIAVKeylistKey1();
		imeiavvaluelistval = ImeIAVValuelistVal();
		imeimcoreproject = ImeIMCoreproject();
		imeimfamily = ImeIMFamily();
		imeimfile1 = ImeIMFile1();
		imeimlibrary = ImeIMLibrary();
		imeimmachine = ImeIMMachine();
		imeimmodule = ImeIMModule();
		imeimunit = ImeIMUnit();
		imeimusergroup = ImeIMUsergroup();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeIni"}});
	};
};

void IexWdbeIni::writeTxt(
			fstream& outfile
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCoreproject& imeimcoreproject
			, ImeIMFamily& imeimfamily
			, ImeIMFile1& imeimfile1
			, ImeIMLibrary& imeimlibrary
			, ImeIMMachine& imeimmachine
			, ImeIMModule& imeimmodule
			, ImeIMUnit& imeimunit
			, ImeIMUsergroup& imeimusergroup
		) {
	outfile << "IexWdbeIni v" WDBE_VERSION << endl;

	imeiavcontrolpar.writeTxt(outfile);
	imeiavkeylistkey1.writeTxt(outfile);
	imeiavvaluelistval.writeTxt(outfile);
	imeimcoreproject.writeTxt(outfile);
	imeimfamily.writeTxt(outfile);
	imeimfile1.writeTxt(outfile);
	imeimlibrary.writeTxt(outfile);
	imeimmachine.writeTxt(outfile);
	imeimmodule.writeTxt(outfile);
	imeimunit.writeTxt(outfile);
	imeimusergroup.writeTxt(outfile);
};

void IexWdbeIni::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIAVControlPar& imeiavcontrolpar
			, ImeIAVKeylistKey1& imeiavkeylistkey1
			, ImeIAVValuelistVal& imeiavvaluelistval
			, ImeIMCoreproject& imeimcoreproject
			, ImeIMFamily& imeimfamily
			, ImeIMFile1& imeimfile1
			, ImeIMLibrary& imeimlibrary
			, ImeIMMachine& imeimmachine
			, ImeIMModule& imeimmodule
			, ImeIMUnit& imeimunit
			, ImeIMUsergroup& imeimusergroup
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeIni");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeiavcontrolpar.writeXML(wr, shorttags);
		imeiavkeylistkey1.writeXML(wr, shorttags);
		imeiavvaluelistval.writeXML(wr, shorttags);
		imeimcoreproject.writeXML(wr, shorttags);
		imeimfamily.writeXML(wr, shorttags);
		imeimfile1.writeXML(wr, shorttags);
		imeimlibrary.writeXML(wr, shorttags);
		imeimmachine.writeXML(wr, shorttags);
		imeimmodule.writeXML(wr, shorttags);
		imeimunit.writeXML(wr, shorttags);
		imeimusergroup.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeIni::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMCOMMANDINVPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOMMANDRETPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMERRORPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMLIBRARYMAKEFILE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMMACHINEMAKEFILE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMMACHINEPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMMODULEPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMUSERACCESS,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMUSERGROUPACCESS,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAVCONTROLPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY3,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAVVALUELISTVAL,VecWdbeVIop::INS},{(uint)VecVIme::IMEICGENERIC,VecWdbeVIop::INS},{(uint)VecVIme::IMEICPORT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY3,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJMCOREVERSIONSTATE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJMPINSREF,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJMUSERSTATE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMBANK,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCOMMAND,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCONTROLLER,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCOREPROJECT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCOREVERSION,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMERROR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMFAMILY,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMFILE1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMFILE2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMGENERIC,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMLIBRARY,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMMACHINE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMMODULE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPERIPHERAL,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPIN,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPORT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMUNIT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMUSER,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMUSERGROUP,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTOR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTORITEM,VecWdbeVIop::INS},{(uint)VecVIme::IMEIRMCOREPROJECTMPERSON,VecWdbeVIop::INS}};
};

uint IexWdbeIni::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};

