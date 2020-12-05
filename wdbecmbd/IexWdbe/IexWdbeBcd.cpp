/**
	* \file IexWdbeBcd.cpp
	* data blocks and readers/writers for import/export complex IexWdbeBcd (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWdbeBcd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeBcd::VecVIme
 ******************************************************************************/

uint IexWdbeBcd::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiammodulepar") return IMEIAMMODULEPAR;
	if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;
	if (s == "imeimmodule") return IMEIMMODULE;

	return(0);
};

string IexWdbeBcd::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMMODULEPAR) return("ImeIAMModulePar");
	if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");
	if (ix == IMEIMMODULE) return("ImeIMModule");

	return("");
};

/******************************************************************************
 class IexWdbeBcd::ImeitemIAMModulePar
 ******************************************************************************/

IexWdbeBcd::ImeitemIAMModulePar::ImeitemIAMModulePar(
			const string& x1SrefKKey
			, const string& Val
		) : WdbeAMModulePar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWdbeBcd::ImeitemIAMModulePar::ImeitemIAMModulePar(
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

void IexWdbeBcd::ImeitemIAMModulePar::readTxt(
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

void IexWdbeBcd::ImeitemIAMModulePar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMModulePar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMModulePar::VecWIel::VAL;
	};
};

void IexWdbeBcd::ImeitemIAMModulePar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWdbeBcd::ImeitemIAMModulePar::writeXML(
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
 class IexWdbeBcd::ImeIAMModulePar::VecWIel
 ******************************************************************************/

uint IexWdbeBcd::ImeIAMModulePar::VecWIel::getIx(
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

void IexWdbeBcd::ImeIAMModulePar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBcd::ImeIAMModulePar::VecWIel::getSrefs(
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
 class IexWdbeBcd::ImeIAMModulePar
 ******************************************************************************/

IexWdbeBcd::ImeIAMModulePar::ImeIAMModulePar() {
};

IexWdbeBcd::ImeIAMModulePar::~ImeIAMModulePar() {
	clear();
};

void IexWdbeBcd::ImeIAMModulePar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBcd::ImeIAMModulePar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBcd::ImeitemIAMModulePar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeBcd::ImeitemIAMModulePar();
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

void IexWdbeBcd::ImeIAMModulePar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBcd::ImeitemIAMModulePar* ii = NULL;

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

			ii = new IexWdbeBcd::ImeitemIAMModulePar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBcd::ImeIAMModulePar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAMModulePar." << StrMod::replaceChar(ImeIAMModulePar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAMModulePar.end" << endl;
	};
};

void IexWdbeBcd::ImeIAMModulePar::writeXML(
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
 class IexWdbeBcd::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexWdbeBcd::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			const string& Title
			, const string& Comment
		) : WdbeJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeBcd::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIJAVKeylistKey()
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

void IexWdbeBcd::ImeitemIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Title = txtrd.fields[0]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeBcd::ImeitemIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;
	};
};

void IexWdbeBcd::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << Title << "\t" << Comment << endl;
};

void IexWdbeBcd::ImeitemIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","tit","cmt"};
	else tags = {"ImeitemIJAVKeylistKey","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], Title);
		writeString(wr, tags[2], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBcd::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWdbeBcd::ImeIJAVKeylistKey::VecWIel::getIx(
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

void IexWdbeBcd::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBcd::ImeIJAVKeylistKey::VecWIel::getSrefs(
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
 class IexWdbeBcd::ImeIJAVKeylistKey
 ******************************************************************************/

IexWdbeBcd::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexWdbeBcd::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexWdbeBcd::ImeIJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBcd::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBcd::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeBcd::ImeitemIJAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIJAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeBcd::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBcd::ImeitemIJAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIJAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIJAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIJAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeBcd::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBcd::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIJAVKeylistKey.end" << endl;
	};
};

void IexWdbeBcd::ImeIJAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIJAVKeylistKey");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeBcd::ImeitemIAVKeylistKey
 ******************************************************************************/

IexWdbeBcd::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

IexWdbeBcd::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAVKeylistKey()
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

void IexWdbeBcd::ImeitemIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY)) {
					imeijavkeylistkey.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeBcd::ImeitemIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;
		imeijavkeylistkey.readXML(docctx, basexpath);
	};
};

void IexWdbeBcd::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexWdbeBcd::ImeitemIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","cmt"};
	else tags = {"ImeitemIAVKeylistKey","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
		imeijavkeylistkey.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBcd::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWdbeBcd::ImeIAVKeylistKey::VecWIel::getIx(
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

void IexWdbeBcd::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBcd::ImeIAVKeylistKey::VecWIel::getSrefs(
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
 class IexWdbeBcd::ImeIAVKeylistKey
 ******************************************************************************/

IexWdbeBcd::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexWdbeBcd::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexWdbeBcd::ImeIAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBcd::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBcd::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeBcd::ImeitemIAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAVKeylistKey"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeBcd::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBcd::ImeitemIAVKeylistKey* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAVKeylistKey");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAVKeylistKey", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAVKeylistKey";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeBcd::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBcd::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIAVKeylistKey.end" << endl;
	};
};

void IexWdbeBcd::ImeIAVKeylistKey::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAVKeylistKey");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeBcd::ImeitemIMModule
 ******************************************************************************/

IexWdbeBcd::ImeitemIMModule::ImeitemIMModule(
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

IexWdbeBcd::ImeitemIMModule::ImeitemIMModule(
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
		hkUref = rec->hkUref;
		supRefWdbeMModule = rec->supRefWdbeMModule;
		tplRefWdbeMModule = rec->tplRefWdbeMModule;
		sref = rec->sref;
		Srefrule = rec->Srefrule;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeBcd::ImeitemIMModule::readTxt(
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

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY)) {
					imeiavkeylistkey.readTxt(txtrd);
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

void IexWdbeBcd::ImeitemIMModule::readXML(
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
		imeiavkeylistkey.readXML(docctx, basexpath);
	};
};

void IexWdbeBcd::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVMModuleBasetype::getSref(ixVBasetype) << "\t" << hsrefSupRefWdbeMModule << "\t" << srefTplRefWdbeMModule << "\t" << sref << "\t" << Srefrule << "\t" << Comment << endl;
	imeiammodulepar.writeTxt(outfile);
	imeiavkeylistkey.writeTxt(outfile);
};

void IexWdbeBcd::ImeitemIMModule::writeXML(
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
		imeiavkeylistkey.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBcd::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWdbeBcd::ImeIMModule::VecWIel::getIx(
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

void IexWdbeBcd::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBcd::ImeIMModule::VecWIel::getSrefs(
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
 class IexWdbeBcd::ImeIMModule
 ******************************************************************************/

IexWdbeBcd::ImeIMModule::ImeIMModule() {
};

IexWdbeBcd::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWdbeBcd::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBcd::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBcd::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeBcd::ImeitemIMModule();
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

void IexWdbeBcd::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBcd::ImeitemIMModule* ii = NULL;

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

			ii = new IexWdbeBcd::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBcd::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMModule.end" << endl;
	};
};

void IexWdbeBcd::ImeIMModule::writeXML(
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
 namespace IexWdbeBcd
 ******************************************************************************/

void IexWdbeBcd::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMModule& imeimmodule
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimmodule);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWdbeBcd", Version(""), VecVIme::getIx);
			readTxt(rd, imeimmodule);
	};
};

void IexWdbeBcd::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMModule& imeimmodule
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimmodule);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimmodule);
		txtfile.close();
	};
};

void IexWdbeBcd::readTxt(
			Txtrd& txtrd
			, ImeIMModule& imeimmodule
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMMODULE)) imeimmodule.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWdbeBcd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMModule& imeimmodule
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeBcd")) {

		// look for XML sub-blocks
		imeimmodule.readXML(docctx, basexpath);

	} else {
		imeimmodule = ImeIMModule();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeBcd"}});
	};
};

void IexWdbeBcd::writeTxt(
			fstream& outfile
			, ImeIMModule& imeimmodule
		) {
	outfile << "IexWdbeBcd v" WDBE_VERSION << endl;

	imeimmodule.writeTxt(outfile);
};

void IexWdbeBcd::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMModule& imeimmodule
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeBcd");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeimmodule.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeBcd::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMMODULEPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMMODULE,VecWdbeVIop::INS}};
};

uint IexWdbeBcd::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};



