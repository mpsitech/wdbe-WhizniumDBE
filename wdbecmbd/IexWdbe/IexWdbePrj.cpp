/**
	* \file IexWdbePrj.cpp
	* data blocks and readers/writers for import/export complex IexWdbePrj (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#include "IexWdbePrj.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbePrj::VecVIme
 ******************************************************************************/

uint IexWdbePrj::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeijmversionstate") return IMEIJMVERSIONSTATE;
	if (s == "imeimproject") return IMEIMPROJECT;
	if (s == "imeimrelease") return IMEIMRELEASE;
	if (s == "imeimversion") return IMEIMVERSION;
	if (s == "imeirmlibrarymversion") return IMEIRMLIBRARYMVERSION;
	if (s == "imeirmpersonmproject") return IMEIRMPERSONMPROJECT;

	return(0);
};

string IexWdbePrj::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIJMVERSIONSTATE) return("ImeIJMVersionState");
	if (ix == IMEIMPROJECT) return("ImeIMProject");
	if (ix == IMEIMRELEASE) return("ImeIMRelease");
	if (ix == IMEIMVERSION) return("ImeIMVersion");
	if (ix == IMEIRMLIBRARYMVERSION) return("ImeIRMLibraryMVersion");
	if (ix == IMEIRMPERSONMPROJECT) return("ImeIRMPersonMProject");

	return("");
};

/******************************************************************************
 class IexWdbePrj::ImeitemIJMVersionState
 ******************************************************************************/

IexWdbePrj::ImeitemIJMVersionState::ImeitemIJMVersionState(
			const uint ixVState
		) : WdbeJMVersionState() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVState = ixVState;
};

IexWdbePrj::ImeitemIJMVersionState::ImeitemIJMVersionState(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIJMVersionState()
		{
	WdbeJMVersionState* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbejmversionstate->loadRecByRef(ref, &rec)) {
		refWdbeMVersion = rec->refWdbeMVersion;
		x1Start = rec->x1Start;
		ixVState = rec->ixVState;

		delete rec;
	};
};

void IexWdbePrj::ImeitemIJMVersionState::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVState = txtrd.fields[0]; ixWIelValid += ImeIJMVersionState::VecWIel::SREFIXVSTATE;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbePrj::ImeitemIJMVersionState::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIJMVersionState::VecWIel::SREFIXVSTATE;
	};
};

void IexWdbePrj::ImeitemIJMVersionState::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMVersionState::getSref(ixVState) << endl;
};

void IexWdbePrj::ImeitemIJMVersionState::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ste"};
	else tags = {"ImeitemIJMVersionState","srefIxVState"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMVersionState::getSref(ixVState));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbePrj::ImeIJMVersionState::VecWIel
 ******************************************************************************/

uint IexWdbePrj::ImeIJMVersionState::VecWIel::getIx(
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

void IexWdbePrj::ImeIJMVersionState::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVSTATE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbePrj::ImeIJMVersionState::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbePrj::ImeIJMVersionState
 ******************************************************************************/

IexWdbePrj::ImeIJMVersionState::ImeIJMVersionState() {
};

IexWdbePrj::ImeIJMVersionState::~ImeIJMVersionState() {
	clear();
};

void IexWdbePrj::ImeIJMVersionState::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbePrj::ImeIJMVersionState::readTxt(
			Txtrd& txtrd
		) {
	IexWdbePrj::ImeitemIJMVersionState* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbePrj::ImeitemIJMVersionState();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJMVERSIONSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJMVersionState"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbePrj::ImeIJMVersionState::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbePrj::ImeitemIJMVersionState* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJMVersionState");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJMVersionState", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJMVersionState";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbePrj::ImeitemIJMVersionState();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbePrj::ImeIJMVersionState::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJMVersionState." << StrMod::replaceChar(ImeIJMVersionState::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJMVersionState.end" << endl;
	};
};

void IexWdbePrj::ImeIJMVersionState::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJMVersionState");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbePrj::ImeitemIMRelease
 ******************************************************************************/

IexWdbePrj::ImeitemIMRelease::ImeitemIMRelease(
			const uint ixVBasetype
			, const string& srefRefWdbeMMachine
			, const string& sref
			, const string& srefsKOption
			, const string& Comment
		) : WdbeMRelease() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->srefRefWdbeMMachine = srefRefWdbeMMachine;
	this->sref = sref;
	this->srefsKOption = srefsKOption;
	this->Comment = Comment;
};

IexWdbePrj::ImeitemIMRelease::ImeitemIMRelease(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMRelease()
		{
	WdbeMRelease* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemrelease->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWdbeMVersion = rec->refWdbeMVersion;
		refWdbeMMachine = rec->refWdbeMMachine;
		sref = rec->sref;
		srefsKOption = rec->srefsKOption;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbePrj::ImeitemIMRelease::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMRelease::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefRefWdbeMMachine = txtrd.fields[1]; ixWIelValid += ImeIMRelease::VecWIel::SREFREFWDBEMMACHINE;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMRelease::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {srefsKOption = txtrd.fields[3]; ixWIelValid += ImeIMRelease::VecWIel::SREFSKOPTION;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMRelease::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRelease"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbePrj::ImeitemIMRelease::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMRelease::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMMachine", "mch", srefRefWdbeMMachine)) ixWIelValid += ImeIMRelease::VecWIel::SREFREFWDBEMMACHINE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMRelease::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMRelease::VecWIel::SREFSKOPTION;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMRelease::VecWIel::COMMENT;
	};
};

void IexWdbePrj::ImeitemIMRelease::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMReleaseBasetype::getSref(ixVBasetype) << "\t" << srefRefWdbeMMachine << "\t" << sref << "\t" << srefsKOption << "\t" << Comment << endl;
};

void IexWdbePrj::ImeitemIMRelease::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","mch","srf","opt","cmt"};
	else tags = {"ImeitemIMRelease","srefIxVBasetype","srefRefWdbeMMachine","sref","srefsKOption","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMReleaseBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], srefRefWdbeMMachine);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], srefsKOption);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbePrj::ImeIMRelease::VecWIel
 ******************************************************************************/

uint IexWdbePrj::ImeIMRelease::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefrefwdbemmachine") ix |= SREFREFWDBEMMACHINE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbePrj::ImeIMRelease::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbePrj::ImeIMRelease::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFREFWDBEMMACHINE) ss.push_back("srefRefWdbeMMachine");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbePrj::ImeIMRelease
 ******************************************************************************/

IexWdbePrj::ImeIMRelease::ImeIMRelease() {
};

IexWdbePrj::ImeIMRelease::~ImeIMRelease() {
	clear();
};

void IexWdbePrj::ImeIMRelease::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbePrj::ImeIMRelease::readTxt(
			Txtrd& txtrd
		) {
	IexWdbePrj::ImeitemIMRelease* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbePrj::ImeitemIMRelease();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRelease"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMRelease"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMRELEASE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRelease"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMRelease"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbePrj::ImeIMRelease::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbePrj::ImeitemIMRelease* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMRelease");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMRelease", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMRelease";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbePrj::ImeitemIMRelease();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbePrj::ImeIMRelease::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMRelease." << StrMod::replaceChar(ImeIMRelease::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMRelease.end" << endl;
	};
};

void IexWdbePrj::ImeIMRelease::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMRelease");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbePrj::ImeitemIRMLibraryMVersion
 ******************************************************************************/

IexWdbePrj::ImeitemIRMLibraryMVersion::ImeitemIRMLibraryMVersion(
			const string& srefRefWdbeMLibrary
		) : WdbeRMLibraryMVersion() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWdbeMLibrary = srefRefWdbeMLibrary;
};

IexWdbePrj::ImeitemIRMLibraryMVersion::ImeitemIRMLibraryMVersion(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIRMLibraryMVersion()
		{
	WdbeRMLibraryMVersion* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbermlibrarymversion->loadRecByRef(ref, &rec)) {
		refWdbeMLibrary = rec->refWdbeMLibrary;
		refWdbeMVersion = rec->refWdbeMVersion;

		delete rec;
	};
};

void IexWdbePrj::ImeitemIRMLibraryMVersion::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWdbeMLibrary = txtrd.fields[0]; ixWIelValid += ImeIRMLibraryMVersion::VecWIel::SREFREFWDBEMLIBRARY;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMLibraryMVersion"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbePrj::ImeitemIRMLibraryMVersion::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMLibrary", "lib", srefRefWdbeMLibrary)) ixWIelValid += ImeIRMLibraryMVersion::VecWIel::SREFREFWDBEMLIBRARY;
	};
};

void IexWdbePrj::ImeitemIRMLibraryMVersion::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefRefWdbeMLibrary << endl;
};

void IexWdbePrj::ImeitemIRMLibraryMVersion::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lib"};
	else tags = {"ImeitemIRMLibraryMVersion","srefRefWdbeMLibrary"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWdbeMLibrary);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbePrj::ImeIRMLibraryMVersion::VecWIel
 ******************************************************************************/

uint IexWdbePrj::ImeIRMLibraryMVersion::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwdbemlibrary") ix |= SREFREFWDBEMLIBRARY;
	};

	return(ix);
};

void IexWdbePrj::ImeIRMLibraryMVersion::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWDBEMLIBRARY); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbePrj::ImeIRMLibraryMVersion::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWDBEMLIBRARY) ss.push_back("srefRefWdbeMLibrary");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbePrj::ImeIRMLibraryMVersion
 ******************************************************************************/

IexWdbePrj::ImeIRMLibraryMVersion::ImeIRMLibraryMVersion() {
};

IexWdbePrj::ImeIRMLibraryMVersion::~ImeIRMLibraryMVersion() {
	clear();
};

void IexWdbePrj::ImeIRMLibraryMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbePrj::ImeIRMLibraryMVersion::readTxt(
			Txtrd& txtrd
		) {
	IexWdbePrj::ImeitemIRMLibraryMVersion* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbePrj::ImeitemIRMLibraryMVersion();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMLibraryMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMLibraryMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMLIBRARYMVERSION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMLibraryMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMLibraryMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbePrj::ImeIRMLibraryMVersion::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbePrj::ImeitemIRMLibraryMVersion* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMLibraryMVersion");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMLibraryMVersion", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMLibraryMVersion";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbePrj::ImeitemIRMLibraryMVersion();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbePrj::ImeIRMLibraryMVersion::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMLibraryMVersion." << StrMod::replaceChar(ImeIRMLibraryMVersion::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIRMLibraryMVersion.end" << endl;
	};
};

void IexWdbePrj::ImeIRMLibraryMVersion::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMLibraryMVersion");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbePrj::ImeitemIMVersion
 ******************************************************************************/

IexWdbePrj::ImeitemIMVersion::ImeitemIMVersion(
			const usmallint Major
			, const usmallint Minor
			, const usmallint Sub
			, const uint ixVState
			, const string& About
			, const string& Comment
		) : WdbeMVersion() {
	lineno = 0;
	ixWIelValid = 0;

	this->Major = Major;
	this->Minor = Minor;
	this->Sub = Sub;
	this->ixVState = ixVState;
	this->About = About;
	this->Comment = Comment;
};

IexWdbePrj::ImeitemIMVersion::ImeitemIMVersion(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVersion()
		{
	WdbeMVersion* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemversion->loadRecByRef(ref, &rec)) {
		grp = rec->grp;
		own = rec->own;
		refWdbeMProject = rec->refWdbeMProject;
		Major = rec->Major;
		Minor = rec->Minor;
		Sub = rec->Sub;
		refJState = rec->refJState;
		ixVState = rec->ixVState;
		About = rec->About;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbePrj::ImeitemIMVersion::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Major = atoi(txtrd.fields[0].c_str()); ixWIelValid += ImeIMVersion::VecWIel::MAJOR;};
	if (txtrd.fields.size() > 1) {Minor = atoi(txtrd.fields[1].c_str()); ixWIelValid += ImeIMVersion::VecWIel::MINOR;};
	if (txtrd.fields.size() > 2) {Sub = atoi(txtrd.fields[2].c_str()); ixWIelValid += ImeIMVersion::VecWIel::SUB;};
	if (txtrd.fields.size() > 3) {srefIxVState = txtrd.fields[3]; ixWIelValid += ImeIMVersion::VecWIel::SREFIXVSTATE;};
	if (txtrd.fields.size() > 4) {About = txtrd.fields[4]; ixWIelValid += ImeIMVersion::VecWIel::ABOUT;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIMVersion::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJMVERSIONSTATE)) {
					imeijmversionstate.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMRELEASE)) {
					imeimrelease.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMLIBRARYMVERSION)) {
					imeirmlibrarymversion.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVersion"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbePrj::ImeitemIMVersion::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUsmallintUclc(docctx, basexpath, "Major", "maj", Major)) ixWIelValid += ImeIMVersion::VecWIel::MAJOR;
		if (extractUsmallintUclc(docctx, basexpath, "Minor", "min", Minor)) ixWIelValid += ImeIMVersion::VecWIel::MINOR;
		if (extractUsmallintUclc(docctx, basexpath, "Sub", "sub", Sub)) ixWIelValid += ImeIMVersion::VecWIel::SUB;
		if (extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState)) ixWIelValid += ImeIMVersion::VecWIel::SREFIXVSTATE;
		if (extractStringUclc(docctx, basexpath, "About", "abt", About)) ixWIelValid += ImeIMVersion::VecWIel::ABOUT;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVersion::VecWIel::COMMENT;
		imeijmversionstate.readXML(docctx, basexpath);
		imeimrelease.readXML(docctx, basexpath);
		imeirmlibrarymversion.readXML(docctx, basexpath);
	};
};

void IexWdbePrj::ImeitemIMVersion::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << Major << "\t" << Minor << "\t" << Sub << "\t" << VecWdbeVMVersionState::getSref(ixVState) << "\t" << About << "\t" << Comment << endl;
	imeijmversionstate.writeTxt(outfile);
	imeimrelease.writeTxt(outfile);
	imeirmlibrarymversion.writeTxt(outfile);
};

void IexWdbePrj::ImeitemIMVersion::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","maj","min","sub","ste","abt","cmt"};
	else tags = {"ImeitemIMVersion","Major","Minor","Sub","srefIxVState","About","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUsmallint(wr, tags[1], Major);
		writeUsmallint(wr, tags[2], Minor);
		writeUsmallint(wr, tags[3], Sub);
		writeString(wr, tags[4], VecWdbeVMVersionState::getSref(ixVState));
		writeString(wr, tags[5], About);
		writeString(wr, tags[6], Comment);
		imeijmversionstate.writeXML(wr, shorttags);
		imeimrelease.writeXML(wr, shorttags);
		imeirmlibrarymversion.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbePrj::ImeIMVersion::VecWIel
 ******************************************************************************/

uint IexWdbePrj::ImeIMVersion::VecWIel::getIx(
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
		else if (ss[i] == "about") ix |= ABOUT;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbePrj::ImeIMVersion::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbePrj::ImeIMVersion::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & MAJOR) ss.push_back("Major");
	if (ix & MINOR) ss.push_back("Minor");
	if (ix & SUB) ss.push_back("Sub");
	if (ix & SREFIXVSTATE) ss.push_back("srefIxVState");
	if (ix & ABOUT) ss.push_back("About");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbePrj::ImeIMVersion
 ******************************************************************************/

IexWdbePrj::ImeIMVersion::ImeIMVersion() {
};

IexWdbePrj::ImeIMVersion::~ImeIMVersion() {
	clear();
};

void IexWdbePrj::ImeIMVersion::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbePrj::ImeIMVersion::readTxt(
			Txtrd& txtrd
		) {
	IexWdbePrj::ImeitemIMVersion* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbePrj::ImeitemIMVersion();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVersion"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVERSION) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVersion"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbePrj::ImeIMVersion::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbePrj::ImeitemIMVersion* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVersion");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVersion", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVersion";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbePrj::ImeitemIMVersion();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbePrj::ImeIMVersion::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMVersion." << StrMod::replaceChar(ImeIMVersion::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMVersion.end" << endl;
	};
};

void IexWdbePrj::ImeIMVersion::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVersion");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbePrj::ImeitemIRMPersonMProject
 ******************************************************************************/

IexWdbePrj::ImeitemIRMPersonMProject::ImeitemIRMPersonMProject(
			const string& hintRefWdbeMPerson
			, const string& srefKFunction
		) : WdbeRMPersonMProject() {
	lineno = 0;
	ixWIelValid = 0;

	this->hintRefWdbeMPerson = hintRefWdbeMPerson;
	this->srefKFunction = srefKFunction;
};

IexWdbePrj::ImeitemIRMPersonMProject::ImeitemIRMPersonMProject(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIRMPersonMProject()
		{
	WdbeRMPersonMProject* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbermpersonmproject->loadRecByRef(ref, &rec)) {
		refWdbeMPerson = rec->refWdbeMPerson;
		refWdbeMProject = rec->refWdbeMProject;
		srefKFunction = rec->srefKFunction;

		delete rec;
	};
};

void IexWdbePrj::ImeitemIRMPersonMProject::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hintRefWdbeMPerson = txtrd.fields[0]; ixWIelValid += ImeIRMPersonMProject::VecWIel::HINTREFWDBEMPERSON;};
	if (txtrd.fields.size() > 1) {srefKFunction = txtrd.fields[1]; ixWIelValid += ImeIRMPersonMProject::VecWIel::SREFKFUNCTION;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbePrj::ImeitemIRMPersonMProject::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hintRefWdbeMPerson", "prs", hintRefWdbeMPerson)) ixWIelValid += ImeIRMPersonMProject::VecWIel::HINTREFWDBEMPERSON;
		if (extractStringUclc(docctx, basexpath, "srefKFunction", "fct", srefKFunction)) ixWIelValid += ImeIRMPersonMProject::VecWIel::SREFKFUNCTION;
	};
};

void IexWdbePrj::ImeitemIRMPersonMProject::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hintRefWdbeMPerson << "\t" << srefKFunction << endl;
};

void IexWdbePrj::ImeitemIRMPersonMProject::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","prs","fct"};
	else tags = {"ImeitemIRMPersonMProject","hintRefWdbeMPerson","srefKFunction"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hintRefWdbeMPerson);
		writeString(wr, tags[2], srefKFunction);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbePrj::ImeIRMPersonMProject::VecWIel
 ******************************************************************************/

uint IexWdbePrj::ImeIRMPersonMProject::VecWIel::getIx(
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

void IexWdbePrj::ImeIRMPersonMProject::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFKFUNCTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbePrj::ImeIRMPersonMProject::VecWIel::getSrefs(
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
 class IexWdbePrj::ImeIRMPersonMProject
 ******************************************************************************/

IexWdbePrj::ImeIRMPersonMProject::ImeIRMPersonMProject() {
};

IexWdbePrj::ImeIRMPersonMProject::~ImeIRMPersonMProject() {
	clear();
};

void IexWdbePrj::ImeIRMPersonMProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbePrj::ImeIRMPersonMProject::readTxt(
			Txtrd& txtrd
		) {
	IexWdbePrj::ImeitemIRMPersonMProject* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbePrj::ImeitemIRMPersonMProject();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMPERSONMPROJECT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMPersonMProject"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbePrj::ImeIRMPersonMProject::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbePrj::ImeitemIRMPersonMProject* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMPersonMProject");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMPersonMProject", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMPersonMProject";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbePrj::ImeitemIRMPersonMProject();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbePrj::ImeIRMPersonMProject::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMPersonMProject." << StrMod::replaceChar(ImeIRMPersonMProject::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMPersonMProject.end" << endl;
	};
};

void IexWdbePrj::ImeIRMPersonMProject::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMPersonMProject");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbePrj::ImeitemIMProject
 ******************************************************************************/

IexWdbePrj::ImeitemIMProject::ImeitemIMProject(
			const string& Short
			, const string& Title
			, const bool Easy
			, const string& Giturl
			, const string& Comment
		) : WdbeMProject() {
	lineno = 0;
	ixWIelValid = 0;

	this->Short = Short;
	this->Title = Title;
	this->Easy = Easy;
	this->Giturl = Giturl;
	this->Comment = Comment;
};

IexWdbePrj::ImeitemIMProject::ImeitemIMProject(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMProject()
		{
	WdbeMProject* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemproject->loadRecByRef(ref, &rec)) {
		grp = rec->grp;
		own = rec->own;
		refWdbeMVersion = rec->refWdbeMVersion;
		Short = rec->Short;
		Title = rec->Title;
		Easy = rec->Easy;
		Giturl = rec->Giturl;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbePrj::ImeitemIMProject::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Short = txtrd.fields[0]; ixWIelValid += ImeIMProject::VecWIel::SHORT;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMProject::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Easy = (txtrd.fields[2] == "true"); ixWIelValid += ImeIMProject::VecWIel::EASY;};
	if (txtrd.fields.size() > 3) {Giturl = txtrd.fields[3]; ixWIelValid += ImeIMProject::VecWIel::GITURL;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMProject::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMVERSION)) {
					imeimversion.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMPERSONMPROJECT)) {
					imeirmpersonmproject.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMProject"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbePrj::ImeitemIMProject::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Short", "sho", Short)) ixWIelValid += ImeIMProject::VecWIel::SHORT;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMProject::VecWIel::TITLE;
		if (extractBoolUclc(docctx, basexpath, "Easy", "esy", Easy)) ixWIelValid += ImeIMProject::VecWIel::EASY;
		if (extractStringUclc(docctx, basexpath, "Giturl", "grl", Giturl)) ixWIelValid += ImeIMProject::VecWIel::GITURL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMProject::VecWIel::COMMENT;
		imeimversion.readXML(docctx, basexpath);
		imeirmpersonmproject.readXML(docctx, basexpath);
	};
};

void IexWdbePrj::ImeitemIMProject::writeTxt(
			fstream& outfile
		) {
	outfile << Short << "\t" << Title << "\t" << StrMod::boolToString(Easy) << "\t" << Giturl << "\t" << Comment << endl;
	imeimversion.writeTxt(outfile);
	imeirmpersonmproject.writeTxt(outfile);
};

void IexWdbePrj::ImeitemIMProject::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sho","tit","esy","grl","cmt"};
	else tags = {"ImeitemIMProject","Short","Title","Easy","Giturl","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Short);
		writeString(wr, tags[2], Title);
		writeBool(wr, tags[3], Easy);
		writeString(wr, tags[4], Giturl);
		writeString(wr, tags[5], Comment);
		imeimversion.writeXML(wr, shorttags);
		imeirmpersonmproject.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbePrj::ImeIMProject::VecWIel
 ******************************************************************************/

uint IexWdbePrj::ImeIMProject::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "short") ix |= SHORT;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "easy") ix |= EASY;
		else if (ss[i] == "giturl") ix |= GITURL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbePrj::ImeIMProject::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbePrj::ImeIMProject::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SHORT) ss.push_back("Short");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & EASY) ss.push_back("Easy");
	if (ix & GITURL) ss.push_back("Giturl");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbePrj::ImeIMProject
 ******************************************************************************/

IexWdbePrj::ImeIMProject::ImeIMProject() {
};

IexWdbePrj::ImeIMProject::~ImeIMProject() {
	clear();
};

void IexWdbePrj::ImeIMProject::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbePrj::ImeIMProject::readTxt(
			Txtrd& txtrd
		) {
	IexWdbePrj::ImeitemIMProject* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbePrj::ImeitemIMProject();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMProject"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPROJECT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMProject"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMProject"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbePrj::ImeIMProject::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbePrj::ImeitemIMProject* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMProject");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMProject", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMProject";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbePrj::ImeitemIMProject();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbePrj::ImeIMProject::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMProject." << StrMod::replaceChar(ImeIMProject::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMProject.end" << endl;
	};
};

void IexWdbePrj::ImeIMProject::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMProject");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWdbePrj
 ******************************************************************************/

void IexWdbePrj::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, ImeIMProject& imeimproject
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimproject);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, "IexWdbePrj", Version(""), VecVIme::getIx);
			readTxt(rd, imeimproject);
	};
};

void IexWdbePrj::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMProject& imeimproject
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimproject);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimproject);
		txtfile.close();
	};
};

void IexWdbePrj::readTxt(
			Txtrd& txtrd
			, ImeIMProject& imeimproject
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMPROJECT)) imeimproject.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWdbePrj::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMProject& imeimproject
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbePrj")) {

		// look for XML sub-blocks
		imeimproject.readXML(docctx, basexpath);

	} else {
		imeimproject = ImeIMProject();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbePrj"}});
	};
};

void IexWdbePrj::writeTxt(
			fstream& outfile
			, ImeIMProject& imeimproject
		) {
	outfile << "IexWdbePrj v" WDBE_VERSION << endl;

	imeimproject.writeTxt(outfile);
};

void IexWdbePrj::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMProject& imeimproject
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbePrj");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeimproject.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbePrj::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIJMVERSIONSTATE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPROJECT,VecWdbeVIop::RETRINS},{(uint)VecVIme::IMEIMRELEASE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVERSION,VecWdbeVIop::INS},{(uint)VecVIme::IMEIRMLIBRARYMVERSION,VecWdbeVIop::INS},{(uint)VecVIme::IMEIRMPERSONMPROJECT,VecWdbeVIop::INS}};
};

uint IexWdbePrj::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};

