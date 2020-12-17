/**
	* \file IexWdbeBdd.cpp
	* data blocks and readers/writers for import/export complex IexWdbeBdd (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWdbeBdd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeBdd::VecVIme
 ******************************************************************************/

uint IexWdbeBdd::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiammodulepar") return IMEIAMMODULEPAR;
	if (s == "imeiamperipheralpar") return IMEIAMPERIPHERALPAR;
	if (s == "imeimcontroller") return IMEIMCONTROLLER;
	if (s == "imeimimbuf") return IMEIMIMBUF;
	if (s == "imeimmodule") return IMEIMMODULE;
	if (s == "imeimperipheral") return IMEIMPERIPHERAL;
	if (s == "imeimsystem") return IMEIMSYSTEM;
	if (s == "imeimtarget") return IMEIMTARGET;
	if (s == "imeimunit") return IMEIMUNIT;

	return(0);
};

string IexWdbeBdd::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMMODULEPAR) return("ImeIAMModulePar");
	if (ix == IMEIAMPERIPHERALPAR) return("ImeIAMPeripheralPar");
	if (ix == IMEIMCONTROLLER) return("ImeIMController");
	if (ix == IMEIMIMBUF) return("ImeIMImbuf");
	if (ix == IMEIMMODULE) return("ImeIMModule");
	if (ix == IMEIMPERIPHERAL) return("ImeIMPeripheral");
	if (ix == IMEIMSYSTEM) return("ImeIMSystem");
	if (ix == IMEIMTARGET) return("ImeIMTarget");
	if (ix == IMEIMUNIT) return("ImeIMUnit");

	return("");
};

/******************************************************************************
 class IexWdbeBdd::ImeitemIMTarget
 ******************************************************************************/

IexWdbeBdd::ImeitemIMTarget::ImeitemIMTarget(
			const string& srefRefWdbeMUnit
			, const string& sref
			, const string& rteSrefsWdbeMModule
			, const string& Comment
		) : WdbeMTarget() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWdbeMUnit = srefRefWdbeMUnit;
	this->sref = sref;
	this->rteSrefsWdbeMModule = rteSrefsWdbeMModule;
	this->Comment = Comment;
};

IexWdbeBdd::ImeitemIMTarget::ImeitemIMTarget(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMTarget()
		{
	WdbeMTarget* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemtarget->loadRecByRef(ref, &rec)) {
		sysRefWdbeMSystem = rec->sysRefWdbeMSystem;
		sysNum = rec->sysNum;
		refWdbeMUnit = rec->refWdbeMUnit;
		sref = rec->sref;
		rteSrefsWdbeMModule = rec->rteSrefsWdbeMModule;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeBdd::ImeitemIMTarget::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWdbeMUnit = txtrd.fields[0]; ixWIelValid += ImeIMTarget::VecWIel::SREFREFWDBEMUNIT;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMTarget::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {rteSrefsWdbeMModule = txtrd.fields[2]; ixWIelValid += ImeIMTarget::VecWIel::RTESREFSWDBEMMODULE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMTarget::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTarget"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeBdd::ImeitemIMTarget::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMUnit", "unt", srefRefWdbeMUnit)) ixWIelValid += ImeIMTarget::VecWIel::SREFREFWDBEMUNIT;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMTarget::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "rteSrefsWdbeMModule", "rte", rteSrefsWdbeMModule)) ixWIelValid += ImeIMTarget::VecWIel::RTESREFSWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMTarget::VecWIel::COMMENT;
	};
};

void IexWdbeBdd::ImeitemIMTarget::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << srefRefWdbeMUnit << "\t" << sref << "\t" << rteSrefsWdbeMModule << "\t" << Comment << endl;
};

void IexWdbeBdd::ImeitemIMTarget::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","unt","srf","rte","cmt"};
	else tags = {"ImeitemIMTarget","srefRefWdbeMUnit","sref","rteSrefsWdbeMModule","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWdbeMUnit);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], rteSrefsWdbeMModule);
		writeString(wr, tags[4], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMTarget::VecWIel
 ******************************************************************************/

uint IexWdbeBdd::ImeIMTarget::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwdbemunit") ix |= SREFREFWDBEMUNIT;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "rtesrefswdbemmodule") ix |= RTESREFSWDBEMMODULE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeBdd::ImeIMTarget::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBdd::ImeIMTarget::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWDBEMUNIT) ss.push_back("srefRefWdbeMUnit");
	if (ix & SREF) ss.push_back("sref");
	if (ix & RTESREFSWDBEMMODULE) ss.push_back("rteSrefsWdbeMModule");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMTarget
 ******************************************************************************/

IexWdbeBdd::ImeIMTarget::ImeIMTarget() {
};

IexWdbeBdd::ImeIMTarget::~ImeIMTarget() {
	clear();
};

void IexWdbeBdd::ImeIMTarget::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBdd::ImeIMTarget::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBdd::ImeitemIMTarget* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeBdd::ImeitemIMTarget();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTarget"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMTarget"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMTARGET) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTarget"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMTarget"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeBdd::ImeIMTarget::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBdd::ImeitemIMTarget* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMTarget");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMTarget", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMTarget";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeBdd::ImeitemIMTarget();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBdd::ImeIMTarget::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMTarget." << StrMod::replaceChar(ImeIMTarget::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMTarget.end" << endl;
	};
};

void IexWdbeBdd::ImeIMTarget::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMTarget");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeBdd::ImeitemIMSystem
 ******************************************************************************/

IexWdbeBdd::ImeitemIMSystem::ImeitemIMSystem(
			const string& srefRefWdbeMUnit
			, const string& sref
			, const string& Comment
		) : WdbeMSystem() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWdbeMUnit = srefRefWdbeMUnit;
	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeBdd::ImeitemIMSystem::ImeitemIMSystem(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMSystem()
		{
	WdbeMSystem* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemsystem->loadRecByRef(ref, &rec)) {
		refWdbeMVersion = rec->refWdbeMVersion;
		refWdbeMUnit = rec->refWdbeMUnit;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeBdd::ImeitemIMSystem::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWdbeMUnit = txtrd.fields[0]; ixWIelValid += ImeIMSystem::VecWIel::SREFREFWDBEMUNIT;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMSystem::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMSystem::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMTARGET)) {
					imeimtarget.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSystem"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeBdd::ImeitemIMSystem::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMUnit", "unt", srefRefWdbeMUnit)) ixWIelValid += ImeIMSystem::VecWIel::SREFREFWDBEMUNIT;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMSystem::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMSystem::VecWIel::COMMENT;
		imeimtarget.readXML(docctx, basexpath);
	};
};

void IexWdbeBdd::ImeitemIMSystem::writeTxt(
			fstream& outfile
		) {
	outfile << srefRefWdbeMUnit << "\t" << sref << "\t" << Comment << endl;
	imeimtarget.writeTxt(outfile);
};

void IexWdbeBdd::ImeitemIMSystem::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","unt","srf","cmt"};
	else tags = {"ImeitemIMSystem","srefRefWdbeMUnit","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWdbeMUnit);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Comment);
		imeimtarget.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMSystem::VecWIel
 ******************************************************************************/

uint IexWdbeBdd::ImeIMSystem::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwdbemunit") ix |= SREFREFWDBEMUNIT;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeBdd::ImeIMSystem::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBdd::ImeIMSystem::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWDBEMUNIT) ss.push_back("srefRefWdbeMUnit");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMSystem
 ******************************************************************************/

IexWdbeBdd::ImeIMSystem::ImeIMSystem() {
};

IexWdbeBdd::ImeIMSystem::~ImeIMSystem() {
	clear();
};

void IexWdbeBdd::ImeIMSystem::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBdd::ImeIMSystem::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBdd::ImeitemIMSystem* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeBdd::ImeitemIMSystem();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSystem"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSYSTEM) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSystem"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSystem"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeBdd::ImeIMSystem::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBdd::ImeitemIMSystem* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSystem");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSystem", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSystem";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeBdd::ImeitemIMSystem();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBdd::ImeIMSystem::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMSystem." << StrMod::replaceChar(ImeIMSystem::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMSystem.end" << endl;
	};
};

void IexWdbeBdd::ImeIMSystem::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSystem");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeBdd::ImeitemIAMModulePar
 ******************************************************************************/

IexWdbeBdd::ImeitemIAMModulePar::ImeitemIAMModulePar(
			const string& x1SrefKKey
			, const string& Val
		) : WdbeAMModulePar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWdbeBdd::ImeitemIAMModulePar::ImeitemIAMModulePar(
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

void IexWdbeBdd::ImeitemIAMModulePar::readTxt(
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

void IexWdbeBdd::ImeitemIAMModulePar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMModulePar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMModulePar::VecWIel::VAL;
	};
};

void IexWdbeBdd::ImeitemIAMModulePar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWdbeBdd::ImeitemIAMModulePar::writeXML(
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
 class IexWdbeBdd::ImeIAMModulePar::VecWIel
 ******************************************************************************/

uint IexWdbeBdd::ImeIAMModulePar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWdbeBdd::ImeIAMModulePar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBdd::ImeIAMModulePar::VecWIel::getSrefs(
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
 class IexWdbeBdd::ImeIAMModulePar
 ******************************************************************************/

IexWdbeBdd::ImeIAMModulePar::ImeIAMModulePar() {
};

IexWdbeBdd::ImeIAMModulePar::~ImeIAMModulePar() {
	clear();
};

void IexWdbeBdd::ImeIAMModulePar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBdd::ImeIAMModulePar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBdd::ImeitemIAMModulePar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeBdd::ImeitemIAMModulePar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeBdd::ImeIAMModulePar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBdd::ImeitemIAMModulePar* ii = NULL;

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

			ii = new IexWdbeBdd::ImeitemIAMModulePar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBdd::ImeIAMModulePar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMModulePar." << StrMod::replaceChar(ImeIAMModulePar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMModulePar.end" << endl;
	};
};

void IexWdbeBdd::ImeIAMModulePar::writeXML(
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
 class IexWdbeBdd::ImeitemIMController
 ******************************************************************************/

IexWdbeBdd::ImeitemIMController::ImeitemIMController(
			const string& srefFwdRefWdbeMUnit
		) : WdbeMController() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefFwdRefWdbeMUnit = srefFwdRefWdbeMUnit;
};

IexWdbeBdd::ImeitemIMController::ImeitemIMController(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMController()
		{
	WdbeMController* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcontroller->loadRecByRef(ref, &rec)) {
		refWdbeMModule = rec->refWdbeMModule;
		fwdRefWdbeMUnit = rec->fwdRefWdbeMUnit;
		Fullsref = rec->Fullsref;

		delete rec;
	};
};

void IexWdbeBdd::ImeitemIMController::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefFwdRefWdbeMUnit = txtrd.fields[0]; ixWIelValid += ImeIMController::VecWIel::SREFFWDREFWDBEMUNIT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMController"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeBdd::ImeitemIMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefFwdRefWdbeMUnit", "fwd", srefFwdRefWdbeMUnit)) ixWIelValid += ImeIMController::VecWIel::SREFFWDREFWDBEMUNIT;
	};
};

void IexWdbeBdd::ImeitemIMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefFwdRefWdbeMUnit << endl;
};

void IexWdbeBdd::ImeitemIMController::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","fwd"};
	else tags = {"ImeitemIMController","srefFwdRefWdbeMUnit"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefFwdRefWdbeMUnit);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMController::VecWIel
 ******************************************************************************/

uint IexWdbeBdd::ImeIMController::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sreffwdrefwdbemunit") ix |= SREFFWDREFWDBEMUNIT;
	};

	return(ix);
};

void IexWdbeBdd::ImeIMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFFWDREFWDBEMUNIT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBdd::ImeIMController::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFFWDREFWDBEMUNIT) ss.push_back("srefFwdRefWdbeMUnit");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMController
 ******************************************************************************/

IexWdbeBdd::ImeIMController::ImeIMController() {
};

IexWdbeBdd::ImeIMController::~ImeIMController() {
	clear();
};

void IexWdbeBdd::ImeIMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBdd::ImeIMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBdd::ImeitemIMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeBdd::ImeitemIMController();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeBdd::ImeIMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBdd::ImeitemIMController* ii = NULL;

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

			ii = new IexWdbeBdd::ImeitemIMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBdd::ImeIMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMController." << StrMod::replaceChar(ImeIMController::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMController.end" << endl;
	};
};

void IexWdbeBdd::ImeIMController::writeXML(
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
 class IexWdbeBdd::ImeitemIMImbuf
 ******************************************************************************/

IexWdbeBdd::ImeitemIMImbuf::ImeitemIMImbuf(
			const string& hsrefCorRefWdbeMModule
			, const string& sref
			, const uint ixVDir
		) : WdbeMImbuf() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefCorRefWdbeMModule = hsrefCorRefWdbeMModule;
	this->sref = sref;
	this->ixVDir = ixVDir;
};

IexWdbeBdd::ImeitemIMImbuf::ImeitemIMImbuf(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMImbuf()
		{
	WdbeMImbuf* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemimbuf->loadRecByRef(ref, &rec)) {
		refWdbeMModule = rec->refWdbeMModule;
		corRefWdbeMModule = rec->corRefWdbeMModule;
		sref = rec->sref;
		ixVDir = rec->ixVDir;

		delete rec;
	};
};

void IexWdbeBdd::ImeitemIMImbuf::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefCorRefWdbeMModule = txtrd.fields[0]; ixWIelValid += ImeIMImbuf::VecWIel::HSREFCORREFWDBEMMODULE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMImbuf::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxVDir = txtrd.fields[2]; ixWIelValid += ImeIMImbuf::VecWIel::SREFIXVDIR;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMImbuf"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeBdd::ImeitemIMImbuf::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefCorRefWdbeMModule", "cor", hsrefCorRefWdbeMModule)) ixWIelValid += ImeIMImbuf::VecWIel::HSREFCORREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMImbuf::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir)) ixWIelValid += ImeIMImbuf::VecWIel::SREFIXVDIR;
	};
};

void IexWdbeBdd::ImeitemIMImbuf::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << hsrefCorRefWdbeMModule << "\t" << sref << "\t" << VecWdbeVMImbufDir::getSref(ixVDir) << endl;
};

void IexWdbeBdd::ImeitemIMImbuf::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cor","srf","dir"};
	else tags = {"ImeitemIMImbuf","hsrefCorRefWdbeMModule","sref","srefIxVDir"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefCorRefWdbeMModule);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWdbeVMImbufDir::getSref(ixVDir));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMImbuf::VecWIel
 ******************************************************************************/

uint IexWdbeBdd::ImeIMImbuf::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefcorrefwdbemmodule") ix |= HSREFCORREFWDBEMMODULE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvdir") ix |= SREFIXVDIR;
	};

	return(ix);
};

void IexWdbeBdd::ImeIMImbuf::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVDIR); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBdd::ImeIMImbuf::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFCORREFWDBEMMODULE) ss.push_back("hsrefCorRefWdbeMModule");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVDIR) ss.push_back("srefIxVDir");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMImbuf
 ******************************************************************************/

IexWdbeBdd::ImeIMImbuf::ImeIMImbuf() {
};

IexWdbeBdd::ImeIMImbuf::~ImeIMImbuf() {
	clear();
};

void IexWdbeBdd::ImeIMImbuf::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBdd::ImeIMImbuf::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBdd::ImeitemIMImbuf* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeBdd::ImeitemIMImbuf();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImbuf"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMImbuf"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMIMBUF) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImbuf"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMImbuf"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeBdd::ImeIMImbuf::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBdd::ImeitemIMImbuf* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMImbuf");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMImbuf", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMImbuf";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeBdd::ImeitemIMImbuf();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBdd::ImeIMImbuf::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMImbuf." << StrMod::replaceChar(ImeIMImbuf::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMImbuf.end" << endl;
	};
};

void IexWdbeBdd::ImeIMImbuf::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMImbuf");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeBdd::ImeitemIMModule
 ******************************************************************************/

IexWdbeBdd::ImeitemIMModule::ImeitemIMModule(
			const uint ixVBasetype
			, const string& hsrefSupRefWdbeMModule
			, const string& srefTplRefWdbeMModule
			, const string& sref
			, const string& Comment
		) : WdbeMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->hsrefSupRefWdbeMModule = hsrefSupRefWdbeMModule;
	this->srefTplRefWdbeMModule = srefTplRefWdbeMModule;
	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeBdd::ImeitemIMModule::ImeitemIMModule(
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
		hkNum = rec->hkNum;
		supRefWdbeMModule = rec->supRefWdbeMModule;
		tplRefWdbeMModule = rec->tplRefWdbeMModule;
		refWdbeMController = rec->refWdbeMController;
		refWdbeMImbuf = rec->refWdbeMImbuf;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeBdd::ImeitemIMModule::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMModule::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {hsrefSupRefWdbeMModule = txtrd.fields[1]; ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;};
	if (txtrd.fields.size() > 2) {srefTplRefWdbeMModule = txtrd.fields[2]; ixWIelValid += ImeIMModule::VecWIel::SREFTPLREFWDBEMMODULE;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMModule::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMModule::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMMODULEPAR)) {
					imeiammodulepar.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMCONTROLLER)) {
					imeimcontroller.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMIMBUF)) {
					imeimimbuf.readTxt(txtrd);
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

void IexWdbeBdd::ImeitemIMModule::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMModule::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefWdbeMModule", "sup", hsrefSupRefWdbeMModule)) ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "srefTplRefWdbeMModule", "tpl", srefTplRefWdbeMModule)) ixWIelValid += ImeIMModule::VecWIel::SREFTPLREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMModule::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMModule::VecWIel::COMMENT;
		imeiammodulepar.readXML(docctx, basexpath);
		imeimcontroller.readXML(docctx, basexpath);
		imeimimbuf.readXML(docctx, basexpath);
	};
};

void IexWdbeBdd::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVMModuleBasetype::getSref(ixVBasetype) << "\t" << hsrefSupRefWdbeMModule << "\t" << srefTplRefWdbeMModule << "\t" << sref << "\t" << Comment << endl;
	imeiammodulepar.writeTxt(outfile);
	imeimcontroller.writeTxt(outfile);
	imeimimbuf.writeTxt(outfile);
};

void IexWdbeBdd::ImeitemIMModule::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","sup","tpl","srf","cmt"};
	else tags = {"ImeitemIMModule","srefIxVBasetype","hsrefSupRefWdbeMModule","srefTplRefWdbeMModule","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMModuleBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], hsrefSupRefWdbeMModule);
		writeString(wr, tags[3], srefTplRefWdbeMModule);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Comment);
		imeiammodulepar.writeXML(wr, shorttags);
		imeimcontroller.writeXML(wr, shorttags);
		imeimimbuf.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWdbeBdd::ImeIMModule::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "hsrefsuprefwdbemmodule") ix |= HSREFSUPREFWDBEMMODULE;
		else if (ss[i] == "sreftplrefwdbemmodule") ix |= SREFTPLREFWDBEMMODULE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeBdd::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBdd::ImeIMModule::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & HSREFSUPREFWDBEMMODULE) ss.push_back("hsrefSupRefWdbeMModule");
	if (ix & SREFTPLREFWDBEMMODULE) ss.push_back("srefTplRefWdbeMModule");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMModule
 ******************************************************************************/

IexWdbeBdd::ImeIMModule::ImeIMModule() {
};

IexWdbeBdd::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWdbeBdd::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBdd::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBdd::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeBdd::ImeitemIMModule();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMModule"}, {"lineno",to_string(txtrd.linecnt)}});

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

void IexWdbeBdd::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBdd::ImeitemIMModule* ii = NULL;

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

			ii = new IexWdbeBdd::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBdd::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMModule.end" << endl;
	};
};

void IexWdbeBdd::ImeIMModule::writeXML(
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
 class IexWdbeBdd::ImeitemIAMPeripheralPar
 ******************************************************************************/

IexWdbeBdd::ImeitemIAMPeripheralPar::ImeitemIAMPeripheralPar(
			const string& x1SrefKKey
			, const string& Val
		) : WdbeAMPeripheralPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWdbeBdd::ImeitemIAMPeripheralPar::ImeitemIAMPeripheralPar(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMPeripheralPar()
		{
	WdbeAMPeripheralPar* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamperipheralpar->loadRecByRef(ref, &rec)) {
		refWdbeMPeripheral = rec->refWdbeMPeripheral;
		x1SrefKKey = rec->x1SrefKKey;
		Val = rec->Val;

		delete rec;
	};
};

void IexWdbeBdd::ImeitemIAMPeripheralPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKKey = txtrd.fields[0]; ixWIelValid += ImeIAMPeripheralPar::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 1) {Val = txtrd.fields[1]; ixWIelValid += ImeIAMPeripheralPar::VecWIel::VAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMPeripheralPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeBdd::ImeitemIAMPeripheralPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMPeripheralPar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMPeripheralPar::VecWIel::VAL;
	};
};

void IexWdbeBdd::ImeitemIAMPeripheralPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWdbeBdd::ImeitemIAMPeripheralPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","val"};
	else tags = {"ImeitemIAMPeripheralPar","x1SrefKKey","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBdd::ImeIAMPeripheralPar::VecWIel
 ******************************************************************************/

uint IexWdbeBdd::ImeIAMPeripheralPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "x1srefkkey") ix |= X1SREFKKEY;
		else if (ss[i] == "val") ix |= VAL;
	};

	return(ix);
};

void IexWdbeBdd::ImeIAMPeripheralPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBdd::ImeIAMPeripheralPar::VecWIel::getSrefs(
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
 class IexWdbeBdd::ImeIAMPeripheralPar
 ******************************************************************************/

IexWdbeBdd::ImeIAMPeripheralPar::ImeIAMPeripheralPar() {
};

IexWdbeBdd::ImeIAMPeripheralPar::~ImeIAMPeripheralPar() {
	clear();
};

void IexWdbeBdd::ImeIAMPeripheralPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBdd::ImeIAMPeripheralPar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBdd::ImeitemIAMPeripheralPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeBdd::ImeitemIAMPeripheralPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMPeripheralPar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMPeripheralPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMPERIPHERALPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMPeripheralPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMPeripheralPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeBdd::ImeIAMPeripheralPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBdd::ImeitemIAMPeripheralPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMPeripheralPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMPeripheralPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMPeripheralPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeBdd::ImeitemIAMPeripheralPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBdd::ImeIAMPeripheralPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMPeripheralPar." << StrMod::replaceChar(ImeIAMPeripheralPar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMPeripheralPar.end" << endl;
	};
};

void IexWdbeBdd::ImeIAMPeripheralPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMPeripheralPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeBdd::ImeitemIMPeripheral
 ******************************************************************************/

IexWdbeBdd::ImeitemIMPeripheral::ImeitemIMPeripheral(
			const string& hsrefRefWdbeMModule
			, const string& sref
			, const string& Comment
		) : WdbeMPeripheral() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefRefWdbeMModule = hsrefRefWdbeMModule;
	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeBdd::ImeitemIMPeripheral::ImeitemIMPeripheral(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMPeripheral()
		{
	WdbeMPeripheral* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemperipheral->loadRecByRef(ref, &rec)) {
		refWdbeMUnit = rec->refWdbeMUnit;
		refWdbeMModule = rec->refWdbeMModule;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeBdd::ImeitemIMPeripheral::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefRefWdbeMModule = txtrd.fields[0]; ixWIelValid += ImeIMPeripheral::VecWIel::HSREFREFWDBEMMODULE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMPeripheral::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMPeripheral::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMPERIPHERALPAR)) {
					imeiamperipheralpar.readTxt(txtrd);
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

void IexWdbeBdd::ImeitemIMPeripheral::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefRefWdbeMModule", "mdl", hsrefRefWdbeMModule)) ixWIelValid += ImeIMPeripheral::VecWIel::HSREFREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPeripheral::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMPeripheral::VecWIel::COMMENT;
		imeiamperipheralpar.readXML(docctx, basexpath);
	};
};

void IexWdbeBdd::ImeitemIMPeripheral::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefRefWdbeMModule << "\t" << sref << "\t" << Comment << endl;
	imeiamperipheralpar.writeTxt(outfile);
};

void IexWdbeBdd::ImeitemIMPeripheral::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","mdl","srf","cmt"};
	else tags = {"ImeitemIMPeripheral","hsrefRefWdbeMModule","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefRefWdbeMModule);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Comment);
		imeiamperipheralpar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMPeripheral::VecWIel
 ******************************************************************************/

uint IexWdbeBdd::ImeIMPeripheral::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefrefwdbemmodule") ix |= HSREFREFWDBEMMODULE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeBdd::ImeIMPeripheral::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBdd::ImeIMPeripheral::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFREFWDBEMMODULE) ss.push_back("hsrefRefWdbeMModule");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMPeripheral
 ******************************************************************************/

IexWdbeBdd::ImeIMPeripheral::ImeIMPeripheral() {
};

IexWdbeBdd::ImeIMPeripheral::~ImeIMPeripheral() {
	clear();
};

void IexWdbeBdd::ImeIMPeripheral::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBdd::ImeIMPeripheral::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBdd::ImeitemIMPeripheral* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeBdd::ImeitemIMPeripheral();
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

void IexWdbeBdd::ImeIMPeripheral::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBdd::ImeitemIMPeripheral* ii = NULL;

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

			ii = new IexWdbeBdd::ImeitemIMPeripheral();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBdd::ImeIMPeripheral::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMPeripheral." << StrMod::replaceChar(ImeIMPeripheral::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMPeripheral.end" << endl;
	};
};

void IexWdbeBdd::ImeIMPeripheral::writeXML(
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
 class IexWdbeBdd::ImeitemIMUnit
 ******************************************************************************/

IexWdbeBdd::ImeitemIMUnit::ImeitemIMUnit(
			const uint ixVBasetype
			, const string& srefSilRefWdbeMUnit
			, const string& sref
			, const string& Title
			, const bool Easy
			, const string& srefKToolch
			, const string& Comment
		) : WdbeMUnit() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->srefSilRefWdbeMUnit = srefSilRefWdbeMUnit;
	this->sref = sref;
	this->Title = Title;
	this->Easy = Easy;
	this->srefKToolch = srefKToolch;
	this->Comment = Comment;
};

IexWdbeBdd::ImeitemIMUnit::ImeitemIMUnit(
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
		silRefWdbeMUnit = rec->silRefWdbeMUnit;
		refWdbeMSystem = rec->refWdbeMSystem;
		refWdbeMModule = rec->refWdbeMModule;
		sref = rec->sref;
		Fullsref = rec->Fullsref;
		Title = rec->Title;
		Easy = rec->Easy;
		srefKToolch = rec->srefKToolch;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeBdd::ImeitemIMUnit::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMUnit::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {srefSilRefWdbeMUnit = txtrd.fields[1]; ixWIelValid += ImeIMUnit::VecWIel::SREFSILREFWDBEMUNIT;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMUnit::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {Title = txtrd.fields[3]; ixWIelValid += ImeIMUnit::VecWIel::TITLE;};
	if (txtrd.fields.size() > 4) {Easy = (txtrd.fields[4] == "true"); ixWIelValid += ImeIMUnit::VecWIel::EASY;};
	if (txtrd.fields.size() > 5) {srefKToolch = txtrd.fields[5]; ixWIelValid += ImeIMUnit::VecWIel::SREFKTOOLCH;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMUnit::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMMODULE)) {
					imeimmodule.readTxt(txtrd);
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

void IexWdbeBdd::ImeitemIMUnit::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMUnit::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "srefSilRefWdbeMUnit", "sil", srefSilRefWdbeMUnit)) ixWIelValid += ImeIMUnit::VecWIel::SREFSILREFWDBEMUNIT;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUnit::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMUnit::VecWIel::TITLE;
		if (extractBoolUclc(docctx, basexpath, "Easy", "esy", Easy)) ixWIelValid += ImeIMUnit::VecWIel::EASY;
		if (extractStringUclc(docctx, basexpath, "srefKToolch", "tch", srefKToolch)) ixWIelValid += ImeIMUnit::VecWIel::SREFKTOOLCH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMUnit::VecWIel::COMMENT;
		imeimmodule.readXML(docctx, basexpath);
		imeimperipheral.readXML(docctx, basexpath);
	};
};

void IexWdbeBdd::ImeitemIMUnit::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVMUnitBasetype::getSref(ixVBasetype) << "\t" << srefSilRefWdbeMUnit << "\t" << sref << "\t" << Title << "\t" << StrMod::boolToString(Easy) << "\t" << srefKToolch << "\t" << Comment << endl;
	imeimmodule.writeTxt(outfile);
	imeimperipheral.writeTxt(outfile);
};

void IexWdbeBdd::ImeitemIMUnit::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","sil","srf","tit","esy","tch","cmt"};
	else tags = {"ImeitemIMUnit","srefIxVBasetype","srefSilRefWdbeMUnit","sref","Title","Easy","srefKToolch","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMUnitBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], srefSilRefWdbeMUnit);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], Title);
		writeBool(wr, tags[5], Easy);
		writeString(wr, tags[6], srefKToolch);
		writeString(wr, tags[7], Comment);
		imeimmodule.writeXML(wr, shorttags);
		imeimperipheral.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMUnit::VecWIel
 ******************************************************************************/

uint IexWdbeBdd::ImeIMUnit::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "srefsilrefwdbemunit") ix |= SREFSILREFWDBEMUNIT;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "easy") ix |= EASY;
		else if (ss[i] == "srefktoolch") ix |= SREFKTOOLCH;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeBdd::ImeIMUnit::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeBdd::ImeIMUnit::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & SREFSILREFWDBEMUNIT) ss.push_back("srefSilRefWdbeMUnit");
	if (ix & SREF) ss.push_back("sref");
	if (ix & TITLE) ss.push_back("Title");
	if (ix & EASY) ss.push_back("Easy");
	if (ix & SREFKTOOLCH) ss.push_back("srefKToolch");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeBdd::ImeIMUnit
 ******************************************************************************/

IexWdbeBdd::ImeIMUnit::ImeIMUnit() {
};

IexWdbeBdd::ImeIMUnit::~ImeIMUnit() {
	clear();
};

void IexWdbeBdd::ImeIMUnit::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeBdd::ImeIMUnit::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeBdd::ImeitemIMUnit* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeBdd::ImeitemIMUnit();
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

void IexWdbeBdd::ImeIMUnit::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeBdd::ImeitemIMUnit* ii = NULL;

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

			ii = new IexWdbeBdd::ImeitemIMUnit();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeBdd::ImeIMUnit::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUnit." << StrMod::replaceChar(ImeIMUnit::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUnit.end" << endl;
	};
};

void IexWdbeBdd::ImeIMUnit::writeXML(
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
 namespace IexWdbeBdd
 ******************************************************************************/

void IexWdbeBdd::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMSystem& imeimsystem
			, ImeIMUnit& imeimunit
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimsystem, imeimunit);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWdbeBdd", Version("0.9.51"), VecVIme::getIx);
			readTxt(rd, imeimsystem, imeimunit);
	};
};

void IexWdbeBdd::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMSystem& imeimsystem
			, ImeIMUnit& imeimunit
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimsystem, imeimunit);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimsystem, imeimunit);
		txtfile.close();
	};
};

void IexWdbeBdd::readTxt(
			Txtrd& txtrd
			, ImeIMSystem& imeimsystem
			, ImeIMUnit& imeimunit
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMSYSTEM)) imeimsystem.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMUNIT)) imeimunit.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWdbeBdd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMSystem& imeimsystem
			, ImeIMUnit& imeimunit
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeBdd")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.51")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.51"}});
		};

		// look for XML sub-blocks
		imeimsystem.readXML(docctx, basexpath);
		imeimunit.readXML(docctx, basexpath);

	} else {
		imeimsystem = ImeIMSystem();
		imeimunit = ImeIMUnit();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeBdd"}});
	};
};

void IexWdbeBdd::writeTxt(
			fstream& outfile
			, ImeIMSystem& imeimsystem
			, ImeIMUnit& imeimunit
		) {
	outfile << "IexWdbeBdd v" WDBE_VERSION << endl;

	imeimsystem.writeTxt(outfile);
	imeimunit.writeTxt(outfile);
};

void IexWdbeBdd::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMSystem& imeimsystem
			, ImeIMUnit& imeimunit
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeBdd");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeimsystem.writeXML(wr, shorttags);
		imeimunit.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeBdd::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMMODULEPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMPERIPHERALPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCONTROLLER,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMIMBUF,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMMODULE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPERIPHERAL,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMSYSTEM,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMTARGET,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMUNIT,VecWdbeVIop::INS}};
};

uint IexWdbeBdd::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};
