/**
	* \file IexWdbeDpl.cpp
	* data blocks and readers/writers for import/export complex IexWdbeDpl (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Sep 2023
	*/
// IP header --- ABOVE

#include "IexWdbeDpl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeDpl::VecVIme
 ******************************************************************************/

uint IexWdbeDpl::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeimcomponent") return IMEIMCOMPONENT;
	if (s == "imeimrelease") return IMEIMRELEASE;
	if (s == "imeirmcomponentmlibrary") return IMEIRMCOMPONENTMLIBRARY;

	return(0);
};

string IexWdbeDpl::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIMCOMPONENT) return("ImeIMComponent");
	if (ix == IMEIMRELEASE) return("ImeIMRelease");
	if (ix == IMEIRMCOMPONENTMLIBRARY) return("ImeIRMComponentMLibrary");

	return("");
};

/******************************************************************************
 class IexWdbeDpl::ImeitemIMRelease
 ******************************************************************************/

IexWdbeDpl::ImeitemIMRelease::ImeitemIMRelease(
			const string& hsrefRefWdbeMMachine
			, const string& sref
			, const string& srefsKOption
			, const string& Comment
		) : WdbeMRelease() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefWdbeMMachine = hsrefRefWdbeMMachine;
	this->sref = sref;
	this->srefsKOption = srefsKOption;
	this->Comment = Comment;
};

IexWdbeDpl::ImeitemIMRelease::ImeitemIMRelease(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMRelease()
		{
	WdbeMRelease* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemrelease->loadRecByRef(ref, &rec)) {
		refWdbeMComponent = rec->refWdbeMComponent;
		refWdbeMMachine = rec->refWdbeMMachine;
		sref = rec->sref;
		srefsKOption = rec->srefsKOption;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDpl::ImeitemIMRelease::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefRefWdbeMMachine = txtrd.fields[0]; ixWIelValid += ImeIMRelease::VecWIel::HSREFREFWDBEMMACHINE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMRelease::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefsKOption = txtrd.fields[2]; ixWIelValid += ImeIMRelease::VecWIel::SREFSKOPTION;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMRelease::VecWIel::COMMENT;};

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

void IexWdbeDpl::ImeitemIMRelease::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefWdbeMMachine", "mch", hsrefRefWdbeMMachine)) ixWIelValid += ImeIMRelease::VecWIel::HSREFREFWDBEMMACHINE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMRelease::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMRelease::VecWIel::SREFSKOPTION;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMRelease::VecWIel::COMMENT;
	};
};

void IexWdbeDpl::ImeitemIMRelease::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefRefWdbeMMachine << "\t" << sref << "\t" << srefsKOption << "\t" << Comment << endl;
};

void IexWdbeDpl::ImeitemIMRelease::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mch","srf","opt","cmt"};
	else tags = {"ImeitemIMRelease","hsrefRefWdbeMMachine","sref","srefsKOption","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefWdbeMMachine);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefsKOption);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDpl::ImeIMRelease::VecWIel
 ******************************************************************************/

uint IexWdbeDpl::ImeIMRelease::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefrefwdbemmachine") ix |= HSREFREFWDBEMMACHINE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDpl::ImeIMRelease::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDpl::ImeIMRelease::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFWDBEMMACHINE) ss.push_back("hsrefRefWdbeMMachine");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFSKOPTION) ss.push_back("srefsKOption");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDpl::ImeIMRelease
 ******************************************************************************/

IexWdbeDpl::ImeIMRelease::ImeIMRelease() {
};

IexWdbeDpl::ImeIMRelease::~ImeIMRelease() {
	clear();
};

void IexWdbeDpl::ImeIMRelease::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDpl::ImeIMRelease::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDpl::ImeitemIMRelease* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDpl::ImeitemIMRelease();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
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

void IexWdbeDpl::ImeIMRelease::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDpl::ImeitemIMRelease* ii = NULL;

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

			ii = new IexWdbeDpl::ImeitemIMRelease();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDpl::ImeIMRelease::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMRelease." << StrMod::replaceChar(ImeIMRelease::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMRelease.end" << endl;
	};
};

void IexWdbeDpl::ImeIMRelease::writeXML(
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
 class IexWdbeDpl::ImeitemIRMComponentMLibrary
 ******************************************************************************/

IexWdbeDpl::ImeitemIRMComponentMLibrary::ImeitemIRMComponentMLibrary(
			const string& srefRefWdbeMLibrary
		) : WdbeRMComponentMLibrary() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWdbeMLibrary = srefRefWdbeMLibrary;
};

IexWdbeDpl::ImeitemIRMComponentMLibrary::ImeitemIRMComponentMLibrary(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIRMComponentMLibrary()
		{
	WdbeRMComponentMLibrary* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbermcomponentmlibrary->loadRecByRef(ref, &rec)) {
		refWdbeMComponent = rec->refWdbeMComponent;
		refWdbeMLibrary = rec->refWdbeMLibrary;

		delete rec;
	};
};

void IexWdbeDpl::ImeitemIRMComponentMLibrary::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWdbeMLibrary = txtrd.fields[0]; ixWIelValid += ImeIRMComponentMLibrary::VecWIel::SREFREFWDBEMLIBRARY;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDpl::ImeitemIRMComponentMLibrary::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMLibrary", "lib", srefRefWdbeMLibrary)) ixWIelValid += ImeIRMComponentMLibrary::VecWIel::SREFREFWDBEMLIBRARY;
	};
};

void IexWdbeDpl::ImeitemIRMComponentMLibrary::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWdbeMLibrary << endl;
};

void IexWdbeDpl::ImeitemIRMComponentMLibrary::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","lib"};
	else tags = {"ImeitemIRMComponentMLibrary","srefRefWdbeMLibrary"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWdbeMLibrary);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDpl::ImeIRMComponentMLibrary::VecWIel
 ******************************************************************************/

uint IexWdbeDpl::ImeIRMComponentMLibrary::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwdbemlibrary") ix |= SREFREFWDBEMLIBRARY;
	};

	return(ix);
};

void IexWdbeDpl::ImeIRMComponentMLibrary::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWDBEMLIBRARY); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDpl::ImeIRMComponentMLibrary::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWDBEMLIBRARY) ss.push_back("srefRefWdbeMLibrary");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDpl::ImeIRMComponentMLibrary
 ******************************************************************************/

IexWdbeDpl::ImeIRMComponentMLibrary::ImeIRMComponentMLibrary() {
};

IexWdbeDpl::ImeIRMComponentMLibrary::~ImeIRMComponentMLibrary() {
	clear();
};

void IexWdbeDpl::ImeIRMComponentMLibrary::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDpl::ImeIRMComponentMLibrary::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDpl::ImeitemIRMComponentMLibrary* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDpl::ImeitemIRMComponentMLibrary();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMCOMPONENTMLIBRARY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMComponentMLibrary"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDpl::ImeIRMComponentMLibrary::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDpl::ImeitemIRMComponentMLibrary* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMComponentMLibrary");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMComponentMLibrary", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMComponentMLibrary";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDpl::ImeitemIRMComponentMLibrary();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDpl::ImeIRMComponentMLibrary::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIRMComponentMLibrary." << StrMod::replaceChar(ImeIRMComponentMLibrary::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIRMComponentMLibrary.end" << endl;
	};
};

void IexWdbeDpl::ImeIRMComponentMLibrary::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMComponentMLibrary");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDpl::ImeitemIMComponent
 ******************************************************************************/

IexWdbeDpl::ImeitemIMComponent::ImeitemIMComponent(
			const uint ixVBasetype
			, const string& sref
			, const string& Comment
		) : WdbeMComponent() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeDpl::ImeitemIMComponent::ImeitemIMComponent(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMComponent()
		{
	WdbeMComponent* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcomponent->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWdbeMVersion = rec->refWdbeMVersion;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDpl::ImeitemIMComponent::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMComponent::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMComponent::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMComponent::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMRELEASE)) {
					imeimrelease.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIRMCOMPONENTMLIBRARY)) {
					imeirmcomponentmlibrary.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMComponent"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDpl::ImeitemIMComponent::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMComponent::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMComponent::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMComponent::VecWIel::COMMENT;
		imeimrelease.readXML(docctx, basexpath);
		imeirmcomponentmlibrary.readXML(docctx, basexpath);
	};
};

void IexWdbeDpl::ImeitemIMComponent::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVMComponentBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << Comment << endl;
	imeimrelease.writeTxt(outfile);
	imeirmcomponentmlibrary.writeTxt(outfile);
};

void IexWdbeDpl::ImeitemIMComponent::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","cmt"};
	else tags = {"ImeitemIMComponent","srefIxVBasetype","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMComponentBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Comment);
		imeimrelease.writeXML(wr, shorttags);
		imeirmcomponentmlibrary.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDpl::ImeIMComponent::VecWIel
 ******************************************************************************/

uint IexWdbeDpl::ImeIMComponent::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDpl::ImeIMComponent::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDpl::ImeIMComponent::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDpl::ImeIMComponent
 ******************************************************************************/

IexWdbeDpl::ImeIMComponent::ImeIMComponent() {
};

IexWdbeDpl::ImeIMComponent::~ImeIMComponent() {
	clear();
};

void IexWdbeDpl::ImeIMComponent::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDpl::ImeIMComponent::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDpl::ImeitemIMComponent* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeDpl::ImeitemIMComponent();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMComponent"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCOMPONENT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMComponent"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMComponent"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDpl::ImeIMComponent::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDpl::ImeitemIMComponent* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMComponent");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMComponent", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMComponent";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDpl::ImeitemIMComponent();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDpl::ImeIMComponent::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMComponent." << StrMod::replaceChar(ImeIMComponent::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMComponent.end" << endl;
	};
};

void IexWdbeDpl::ImeIMComponent::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMComponent");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 namespace IexWdbeDpl
 ******************************************************************************/

void IexWdbeDpl::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMComponent& imeimcomponent
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimcomponent);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWdbeDpl", Version("1.1.35"), VecVIme::getIx);
			readTxt(rd, imeimcomponent);
	};
};

void IexWdbeDpl::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMComponent& imeimcomponent
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimcomponent);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimcomponent);
		txtfile.close();
	};
};

void IexWdbeDpl::readTxt(
			Txtrd& txtrd
			, ImeIMComponent& imeimcomponent
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMCOMPONENT)) imeimcomponent.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWdbeDpl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMComponent& imeimcomponent
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeDpl")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.1.35")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.1.35"}});
		};

		// look for XML sub-blocks
		imeimcomponent.readXML(docctx, basexpath);

	} else {
		imeimcomponent = ImeIMComponent();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeDpl"}});
	};
};

void IexWdbeDpl::writeTxt(
			fstream& outfile
			, ImeIMComponent& imeimcomponent
		) {
	outfile << "IexWdbeDpl v" WDBE_VERSION << endl;

	imeimcomponent.writeTxt(outfile);
};

void IexWdbeDpl::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMComponent& imeimcomponent
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeDpl");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeimcomponent.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeDpl::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIMCOMPONENT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMRELEASE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIRMCOMPONENTMLIBRARY,VecWdbeVIop::INS}};
};

uint IexWdbeDpl::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};
