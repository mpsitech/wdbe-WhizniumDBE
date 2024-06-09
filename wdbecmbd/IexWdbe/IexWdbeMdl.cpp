/**
	* \file IexWdbeMdl.cpp
	* data blocks and readers/writers for import/export complex IexWdbeMdl (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "IexWdbeMdl.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeMdl::VecVIme
 ******************************************************************************/

uint IexWdbeMdl::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiammodulepar") return IMEIAMMODULEPAR;
	if (s == "imeiamperipheralpar") return IMEIAMPERIPHERALPAR;
	if (s == "imeimcontroller") return IMEIMCONTROLLER;
	if (s == "imeimgeneric") return IMEIMGENERIC;
	if (s == "imeimimbuf") return IMEIMIMBUF;
	if (s == "imeimmodule") return IMEIMMODULE;
	if (s == "imeimperipheral") return IMEIMPERIPHERAL;
	if (s == "imeimunit") return IMEIMUNIT;
	if (s == "imeirmmodulemmodule") return IMEIRMMODULEMMODULE;
	if (s == "imeirmmodulemperipheral") return IMEIRMMODULEMPERIPHERAL;

	return(0);
};

string IexWdbeMdl::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMMODULEPAR) return("ImeIAMModulePar");
	if (ix == IMEIAMPERIPHERALPAR) return("ImeIAMPeripheralPar");
	if (ix == IMEIMCONTROLLER) return("ImeIMController");
	if (ix == IMEIMGENERIC) return("ImeIMGeneric");
	if (ix == IMEIMIMBUF) return("ImeIMImbuf");
	if (ix == IMEIMMODULE) return("ImeIMModule");
	if (ix == IMEIMPERIPHERAL) return("ImeIMPeripheral");
	if (ix == IMEIMUNIT) return("ImeIMUnit");
	if (ix == IMEIRMMODULEMMODULE) return("ImeIRMModuleMModule");
	if (ix == IMEIRMMODULEMPERIPHERAL) return("ImeIRMModuleMPeripheral");

	return("");
};

/******************************************************************************
 class IexWdbeMdl::ImeitemIAMModulePar
 ******************************************************************************/

IexWdbeMdl::ImeitemIAMModulePar::ImeitemIAMModulePar(
			const string& x1SrefKKey
			, const string& Val
		) : WdbeAMModulePar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWdbeMdl::ImeitemIAMModulePar::ImeitemIAMModulePar(
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

void IexWdbeMdl::ImeitemIAMModulePar::readTxt(
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

void IexWdbeMdl::ImeitemIAMModulePar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMModulePar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMModulePar::VecWIel::VAL;
	};
};

void IexWdbeMdl::ImeitemIAMModulePar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWdbeMdl::ImeitemIAMModulePar::writeXML(
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
 class IexWdbeMdl::ImeIAMModulePar::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIAMModulePar::VecWIel::getIx(
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

void IexWdbeMdl::ImeIAMModulePar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIAMModulePar::VecWIel::getSrefs(
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
 class IexWdbeMdl::ImeIAMModulePar
 ******************************************************************************/

IexWdbeMdl::ImeIAMModulePar::ImeIAMModulePar() {
};

IexWdbeMdl::ImeIAMModulePar::~ImeIAMModulePar() {
	clear();
};

void IexWdbeMdl::ImeIAMModulePar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIAMModulePar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIAMModulePar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeMdl::ImeitemIAMModulePar();
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

void IexWdbeMdl::ImeIAMModulePar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIAMModulePar* ii = NULL;

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

			ii = new IexWdbeMdl::ImeitemIAMModulePar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIAMModulePar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMModulePar." << StrMod::replaceChar(ImeIAMModulePar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMModulePar.end" << endl;
	};
};

void IexWdbeMdl::ImeIAMModulePar::writeXML(
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
 class IexWdbeMdl::ImeitemIMController
 ******************************************************************************/

IexWdbeMdl::ImeitemIMController::ImeitemIMController(
		) : WdbeMController() {
	lineno = 0;
	ixWIelValid = 0;

};

IexWdbeMdl::ImeitemIMController::ImeitemIMController(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMController()
		{
	WdbeMController* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcontroller->loadRecByRef(ref, &rec)) {
		refWdbeMModule = rec->refWdbeMModule;
		Fullsref = rec->Fullsref;

		delete rec;
	};
};

void IexWdbeMdl::ImeitemIMController::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

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

void IexWdbeMdl::ImeitemIMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
	};
};

void IexWdbeMdl::ImeitemIMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << "^" << endl;
};

void IexWdbeMdl::ImeitemIMController::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii"};
	else tags = {"ImeitemIMController"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeMdl::ImeIMController::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIMController::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
	};

	return(ix);
};

void IexWdbeMdl::ImeIMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; false;) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIMController::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeMdl::ImeIMController
 ******************************************************************************/

IexWdbeMdl::ImeIMController::ImeIMController() {
};

IexWdbeMdl::ImeIMController::~ImeIMController() {
	clear();
};

void IexWdbeMdl::ImeIMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeMdl::ImeitemIMController();
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

void IexWdbeMdl::ImeIMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIMController* ii = NULL;

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

			ii = new IexWdbeMdl::ImeitemIMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMController." << StrMod::replaceChar(ImeIMController::VecWIel::getSrefs(0), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMController.end" << endl;
	};
};

void IexWdbeMdl::ImeIMController::writeXML(
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
 class IexWdbeMdl::ImeitemIMGeneric
 ******************************************************************************/

IexWdbeMdl::ImeitemIMGeneric::ImeitemIMGeneric(
			const string& sref
			, const string& Defval
		) : WdbeMGeneric() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Defval = Defval;
};

IexWdbeMdl::ImeitemIMGeneric::ImeitemIMGeneric(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMGeneric()
		{
	WdbeMGeneric* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemgeneric->loadRecByRef(ref, &rec)) {
		sref = rec->sref;
		Defval = rec->Defval;

		delete rec;
	};
};

void IexWdbeMdl::ImeitemIMGeneric::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMGeneric::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Defval = txtrd.fields[1]; ixWIelValid += ImeIMGeneric::VecWIel::DEFVAL;};

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

void IexWdbeMdl::ImeitemIMGeneric::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMGeneric::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIMGeneric::VecWIel::DEFVAL;
	};
};

void IexWdbeMdl::ImeitemIMGeneric::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Defval << endl;
};

void IexWdbeMdl::ImeitemIMGeneric::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","dfv"};
	else tags = {"ImeitemIMGeneric","sref","Defval"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Defval);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeMdl::ImeIMGeneric::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIMGeneric::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "defval") ix |= DEFVAL;
	};

	return(ix);
};

void IexWdbeMdl::ImeIMGeneric::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*DEFVAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIMGeneric::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & DEFVAL) ss.push_back("Defval");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeMdl::ImeIMGeneric
 ******************************************************************************/

IexWdbeMdl::ImeIMGeneric::ImeIMGeneric() {
};

IexWdbeMdl::ImeIMGeneric::~ImeIMGeneric() {
	clear();
};

void IexWdbeMdl::ImeIMGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIMGeneric::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIMGeneric* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeMdl::ImeitemIMGeneric();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeMdl::ImeIMGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIMGeneric* ii = NULL;

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

			ii = new IexWdbeMdl::ImeitemIMGeneric();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIMGeneric::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMGeneric." << StrMod::replaceChar(ImeIMGeneric::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMGeneric.end" << endl;
	};
};

void IexWdbeMdl::ImeIMGeneric::writeXML(
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
 class IexWdbeMdl::ImeitemIMImbuf
 ******************************************************************************/

IexWdbeMdl::ImeitemIMImbuf::ImeitemIMImbuf(
			const uint ixVRotype
			, const usmallint Width
			, const string& Minmax
			, const utinyint Prio
		) : WdbeMImbuf() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVRotype = ixVRotype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Prio = Prio;
};

IexWdbeMdl::ImeitemIMImbuf::ImeitemIMImbuf(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMImbuf()
		{
	WdbeMImbuf* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemimbuf->loadRecByRef(ref, &rec)) {
		ixVRotype = rec->ixVRotype;
		refWdbeMModule = rec->refWdbeMModule;
		Fullsref = rec->Fullsref;
		Width = rec->Width;
		Minmax = rec->Minmax;
		Prio = rec->Prio;

		delete rec;
	};
};

void IexWdbeMdl::ImeitemIMImbuf::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVRotype = txtrd.fields[0]; ixWIelValid += ImeIMImbuf::VecWIel::SREFIXVROTYPE;};
	if (txtrd.fields.size() > 1) {Width = atoi(txtrd.fields[1].c_str()); ixWIelValid += ImeIMImbuf::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 2) {Minmax = txtrd.fields[2]; ixWIelValid += ImeIMImbuf::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 3) {Prio = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIMImbuf::VecWIel::PRIO;};

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

void IexWdbeMdl::ImeitemIMImbuf::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVRotype", "rty", srefIxVRotype)) ixWIelValid += ImeIMImbuf::VecWIel::SREFIXVROTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMImbuf::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMImbuf::VecWIel::MINMAX;
		if (extractUtinyintUclc(docctx, basexpath, "Prio", "pri", Prio)) ixWIelValid += ImeIMImbuf::VecWIel::PRIO;
	};
};

void IexWdbeMdl::ImeitemIMImbuf::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMImbufRotype::getSref(ixVRotype) << "\t" << Width << "\t" << Minmax << "\t" << Prio << endl;
};

void IexWdbeMdl::ImeitemIMImbuf::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","rty","wid","mmx","pri"};
	else tags = {"ImeitemIMImbuf","srefIxVRotype","Width","Minmax","Prio"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMImbufRotype::getSref(ixVRotype));
		writeUsmallint(wr, tags[2], Width);
		writeString(wr, tags[3], Minmax);
		writeUtinyint(wr, tags[4], Prio);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeMdl::ImeIMImbuf::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIMImbuf::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvrotype") ix |= SREFIXVROTYPE;
		else if (ss[i] == "width") ix |= WIDTH;
		else if (ss[i] == "minmax") ix |= MINMAX;
		else if (ss[i] == "prio") ix |= PRIO;
	};

	return(ix);
};

void IexWdbeMdl::ImeIMImbuf::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*PRIO); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIMImbuf::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVROTYPE) ss.push_back("srefIxVRotype");
	if (ix & WIDTH) ss.push_back("Width");
	if (ix & MINMAX) ss.push_back("Minmax");
	if (ix & PRIO) ss.push_back("Prio");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeMdl::ImeIMImbuf
 ******************************************************************************/

IexWdbeMdl::ImeIMImbuf::ImeIMImbuf() {
};

IexWdbeMdl::ImeIMImbuf::~ImeIMImbuf() {
	clear();
};

void IexWdbeMdl::ImeIMImbuf::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIMImbuf::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIMImbuf* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeMdl::ImeitemIMImbuf();
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

void IexWdbeMdl::ImeIMImbuf::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIMImbuf* ii = NULL;

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

			ii = new IexWdbeMdl::ImeitemIMImbuf();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIMImbuf::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMImbuf." << StrMod::replaceChar(ImeIMImbuf::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMImbuf.end" << endl;
	};
};

void IexWdbeMdl::ImeIMImbuf::writeXML(
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
 class IexWdbeMdl::ImeitemIRMModuleMModule
 ******************************************************************************/

IexWdbeMdl::ImeitemIRMModuleMModule::ImeitemIRMModuleMModule(
			const string& hsrefCorRefWdbeMModule
			, const string& srefKFunction
		) : WdbeRMModuleMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefCorRefWdbeMModule = hsrefCorRefWdbeMModule;
	this->srefKFunction = srefKFunction;
};

IexWdbeMdl::ImeitemIRMModuleMModule::ImeitemIRMModuleMModule(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIRMModuleMModule()
		{
	WdbeRMModuleMModule* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbermmodulemmodule->loadRecByRef(ref, &rec)) {
		ctdRefWdbeMModule = rec->ctdRefWdbeMModule;
		corRefWdbeMModule = rec->corRefWdbeMModule;
		srefKFunction = rec->srefKFunction;

		delete rec;
	};
};

void IexWdbeMdl::ImeitemIRMModuleMModule::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefCorRefWdbeMModule = txtrd.fields[0]; ixWIelValid += ImeIRMModuleMModule::VecWIel::HSREFCORREFWDBEMMODULE;};
	if (txtrd.fields.size() > 1) {srefKFunction = txtrd.fields[1]; ixWIelValid += ImeIRMModuleMModule::VecWIel::SREFKFUNCTION;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMModuleMModule"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeMdl::ImeitemIRMModuleMModule::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefCorRefWdbeMModule", "cor", hsrefCorRefWdbeMModule)) ixWIelValid += ImeIRMModuleMModule::VecWIel::HSREFCORREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "srefKFunction", "fct", srefKFunction)) ixWIelValid += ImeIRMModuleMModule::VecWIel::SREFKFUNCTION;
	};
};

void IexWdbeMdl::ImeitemIRMModuleMModule::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << hsrefCorRefWdbeMModule << "\t" << srefKFunction << endl;
};

void IexWdbeMdl::ImeitemIRMModuleMModule::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cor","fct"};
	else tags = {"ImeitemIRMModuleMModule","hsrefCorRefWdbeMModule","srefKFunction"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefCorRefWdbeMModule);
		writeString(wr, tags[2], srefKFunction);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeMdl::ImeIRMModuleMModule::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIRMModuleMModule::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefcorrefwdbemmodule") ix |= HSREFCORREFWDBEMMODULE;
		else if (ss[i] == "srefkfunction") ix |= SREFKFUNCTION;
	};

	return(ix);
};

void IexWdbeMdl::ImeIRMModuleMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFKFUNCTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIRMModuleMModule::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFCORREFWDBEMMODULE) ss.push_back("hsrefCorRefWdbeMModule");
	if (ix & SREFKFUNCTION) ss.push_back("srefKFunction");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeMdl::ImeIRMModuleMModule
 ******************************************************************************/

IexWdbeMdl::ImeIRMModuleMModule::ImeIRMModuleMModule() {
};

IexWdbeMdl::ImeIRMModuleMModule::~ImeIRMModuleMModule() {
	clear();
};

void IexWdbeMdl::ImeIRMModuleMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIRMModuleMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIRMModuleMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeMdl::ImeitemIRMModuleMModule();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMModuleMModule"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMModuleMModule"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMMODULEMMODULE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMModuleMModule"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMModuleMModule"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeMdl::ImeIRMModuleMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIRMModuleMModule* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMModuleMModule");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMModuleMModule", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMModuleMModule";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeMdl::ImeitemIRMModuleMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIRMModuleMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMModuleMModule." << StrMod::replaceChar(ImeIRMModuleMModule::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIRMModuleMModule.end" << endl;
	};
};

void IexWdbeMdl::ImeIRMModuleMModule::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMModuleMModule");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeMdl::ImeitemIRMModuleMPeripheral
 ******************************************************************************/

IexWdbeMdl::ImeitemIRMModuleMPeripheral::ImeitemIRMModuleMPeripheral(
			const string& srefRefWdbeMPeripheral
		) : WdbeRMModuleMPeripheral() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWdbeMPeripheral = srefRefWdbeMPeripheral;
};

IexWdbeMdl::ImeitemIRMModuleMPeripheral::ImeitemIRMModuleMPeripheral(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIRMModuleMPeripheral()
		{
	WdbeRMModuleMPeripheral* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbermmodulemperipheral->loadRecByRef(ref, &rec)) {
		refWdbeMModule = rec->refWdbeMModule;
		refWdbeMPeripheral = rec->refWdbeMPeripheral;

		delete rec;
	};
};

void IexWdbeMdl::ImeitemIRMModuleMPeripheral::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWdbeMPeripheral = txtrd.fields[0]; ixWIelValid += ImeIRMModuleMPeripheral::VecWIel::SREFREFWDBEMPERIPHERAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMModuleMPeripheral"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeMdl::ImeitemIRMModuleMPeripheral::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMPeripheral", "pph", srefRefWdbeMPeripheral)) ixWIelValid += ImeIRMModuleMPeripheral::VecWIel::SREFREFWDBEMPERIPHERAL;
	};
};

void IexWdbeMdl::ImeitemIRMModuleMPeripheral::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << srefRefWdbeMPeripheral << endl;
};

void IexWdbeMdl::ImeitemIRMModuleMPeripheral::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","pph"};
	else tags = {"ImeitemIRMModuleMPeripheral","srefRefWdbeMPeripheral"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWdbeMPeripheral);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeMdl::ImeIRMModuleMPeripheral::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIRMModuleMPeripheral::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwdbemperipheral") ix |= SREFREFWDBEMPERIPHERAL;
	};

	return(ix);
};

void IexWdbeMdl::ImeIRMModuleMPeripheral::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWDBEMPERIPHERAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIRMModuleMPeripheral::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWDBEMPERIPHERAL) ss.push_back("srefRefWdbeMPeripheral");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeMdl::ImeIRMModuleMPeripheral
 ******************************************************************************/

IexWdbeMdl::ImeIRMModuleMPeripheral::ImeIRMModuleMPeripheral() {
};

IexWdbeMdl::ImeIRMModuleMPeripheral::~ImeIRMModuleMPeripheral() {
	clear();
};

void IexWdbeMdl::ImeIRMModuleMPeripheral::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIRMModuleMPeripheral::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIRMModuleMPeripheral* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeMdl::ImeitemIRMModuleMPeripheral();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMModuleMPeripheral"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMModuleMPeripheral"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMMODULEMPERIPHERAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMModuleMPeripheral"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMModuleMPeripheral"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeMdl::ImeIRMModuleMPeripheral::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIRMModuleMPeripheral* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMModuleMPeripheral");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMModuleMPeripheral", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMModuleMPeripheral";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeMdl::ImeitemIRMModuleMPeripheral();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIRMModuleMPeripheral::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIRMModuleMPeripheral." << StrMod::replaceChar(ImeIRMModuleMPeripheral::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIRMModuleMPeripheral.end" << endl;
	};
};

void IexWdbeMdl::ImeIRMModuleMPeripheral::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMModuleMPeripheral");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeMdl::ImeitemIMModule
 ******************************************************************************/

IexWdbeMdl::ImeitemIMModule::ImeitemIMModule(
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

IexWdbeMdl::ImeitemIMModule::ImeitemIMModule(
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

void IexWdbeMdl::ImeitemIMModule::readTxt(
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

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMGENERIC)) {
					imeimgeneric.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMIMBUF)) {
					imeimimbuf.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMMODULEMMODULE)) {
					imeirmmodulemmodule.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIRMMODULEMPERIPHERAL)) {
					imeirmmodulemperipheral.readTxt(txtrd);
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

void IexWdbeMdl::ImeitemIMModule::readXML(
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
		imeimgeneric.readXML(docctx, basexpath);
		imeimimbuf.readXML(docctx, basexpath);
		imeirmmodulemmodule.readXML(docctx, basexpath);
		imeirmmodulemperipheral.readXML(docctx, basexpath);
	};
};

void IexWdbeMdl::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVMModuleBasetype::getSref(ixVBasetype) << "\t" << hsrefSupRefWdbeMModule << "\t" << srefTplRefWdbeMModule << "\t" << sref << "\t" << Comment << endl;
	imeiammodulepar.writeTxt(outfile);
	imeimcontroller.writeTxt(outfile);
	imeimgeneric.writeTxt(outfile);
	imeimimbuf.writeTxt(outfile);
	imeirmmodulemmodule.writeTxt(outfile);
	imeirmmodulemperipheral.writeTxt(outfile);
};

void IexWdbeMdl::ImeitemIMModule::writeXML(
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
		imeimgeneric.writeXML(wr, shorttags);
		imeimimbuf.writeXML(wr, shorttags);
		imeirmmodulemmodule.writeXML(wr, shorttags);
		imeirmmodulemperipheral.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeMdl::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIMModule::VecWIel::getIx(
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

void IexWdbeMdl::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIMModule::VecWIel::getSrefs(
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
 class IexWdbeMdl::ImeIMModule
 ******************************************************************************/

IexWdbeMdl::ImeIMModule::ImeIMModule() {
};

IexWdbeMdl::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWdbeMdl::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeMdl::ImeitemIMModule();
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

void IexWdbeMdl::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIMModule* ii = NULL;

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

			ii = new IexWdbeMdl::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMModule.end" << endl;
	};
};

void IexWdbeMdl::ImeIMModule::writeXML(
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
 class IexWdbeMdl::ImeitemIAMPeripheralPar
 ******************************************************************************/

IexWdbeMdl::ImeitemIAMPeripheralPar::ImeitemIAMPeripheralPar(
			const string& x1SrefKKey
			, const string& Val
		) : WdbeAMPeripheralPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWdbeMdl::ImeitemIAMPeripheralPar::ImeitemIAMPeripheralPar(
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

void IexWdbeMdl::ImeitemIAMPeripheralPar::readTxt(
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

void IexWdbeMdl::ImeitemIAMPeripheralPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMPeripheralPar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMPeripheralPar::VecWIel::VAL;
	};
};

void IexWdbeMdl::ImeitemIAMPeripheralPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWdbeMdl::ImeitemIAMPeripheralPar::writeXML(
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
 class IexWdbeMdl::ImeIAMPeripheralPar::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIAMPeripheralPar::VecWIel::getIx(
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

void IexWdbeMdl::ImeIAMPeripheralPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIAMPeripheralPar::VecWIel::getSrefs(
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
 class IexWdbeMdl::ImeIAMPeripheralPar
 ******************************************************************************/

IexWdbeMdl::ImeIAMPeripheralPar::ImeIAMPeripheralPar() {
};

IexWdbeMdl::ImeIAMPeripheralPar::~ImeIAMPeripheralPar() {
	clear();
};

void IexWdbeMdl::ImeIAMPeripheralPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIAMPeripheralPar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIAMPeripheralPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeMdl::ImeitemIAMPeripheralPar();
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

void IexWdbeMdl::ImeIAMPeripheralPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIAMPeripheralPar* ii = NULL;

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

			ii = new IexWdbeMdl::ImeitemIAMPeripheralPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIAMPeripheralPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMPeripheralPar." << StrMod::replaceChar(ImeIAMPeripheralPar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMPeripheralPar.end" << endl;
	};
};

void IexWdbeMdl::ImeIAMPeripheralPar::writeXML(
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
 class IexWdbeMdl::ImeitemIMPeripheral
 ******************************************************************************/

IexWdbeMdl::ImeitemIMPeripheral::ImeitemIMPeripheral(
			const string& sref
			, const string& Comment
		) : WdbeMPeripheral() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeMdl::ImeitemIMPeripheral::ImeitemIMPeripheral(
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

void IexWdbeMdl::ImeitemIMPeripheral::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMPeripheral::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMPeripheral::VecWIel::COMMENT;};

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

void IexWdbeMdl::ImeitemIMPeripheral::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPeripheral::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMPeripheral::VecWIel::COMMENT;
		imeiamperipheralpar.readXML(docctx, basexpath);
	};
};

void IexWdbeMdl::ImeitemIMPeripheral::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Comment << endl;
	imeiamperipheralpar.writeTxt(outfile);
};

void IexWdbeMdl::ImeitemIMPeripheral::writeXML(
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
		imeiamperipheralpar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeMdl::ImeIMPeripheral::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIMPeripheral::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeMdl::ImeIMPeripheral::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIMPeripheral::VecWIel::getSrefs(
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
 class IexWdbeMdl::ImeIMPeripheral
 ******************************************************************************/

IexWdbeMdl::ImeIMPeripheral::ImeIMPeripheral() {
};

IexWdbeMdl::ImeIMPeripheral::~ImeIMPeripheral() {
	clear();
};

void IexWdbeMdl::ImeIMPeripheral::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIMPeripheral::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIMPeripheral* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeMdl::ImeitemIMPeripheral();
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

void IexWdbeMdl::ImeIMPeripheral::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIMPeripheral* ii = NULL;

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

			ii = new IexWdbeMdl::ImeitemIMPeripheral();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIMPeripheral::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMPeripheral." << StrMod::replaceChar(ImeIMPeripheral::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMPeripheral.end" << endl;
	};
};

void IexWdbeMdl::ImeIMPeripheral::writeXML(
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
 class IexWdbeMdl::ImeitemIMUnit
 ******************************************************************************/

IexWdbeMdl::ImeitemIMUnit::ImeitemIMUnit(
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

IexWdbeMdl::ImeitemIMUnit::ImeitemIMUnit(
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
		refWdbeMModule = rec->refWdbeMModule;
		sref = rec->sref;
		Title = rec->Title;
		Fullsref = rec->Fullsref;
		Easy = rec->Easy;
		srefKToolch = rec->srefKToolch;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeMdl::ImeitemIMUnit::readTxt(
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

void IexWdbeMdl::ImeitemIMUnit::readXML(
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

void IexWdbeMdl::ImeitemIMUnit::writeTxt(
			fstream& outfile
		) {
	outfile << VecWdbeVMUnitBasetype::getSref(ixVBasetype) << "\t" << srefSilRefWdbeMUnit << "\t" << sref << "\t" << Title << "\t" << StrMod::boolToString(Easy) << "\t" << srefKToolch << "\t" << Comment << endl;
	imeimmodule.writeTxt(outfile);
	imeimperipheral.writeTxt(outfile);
};

void IexWdbeMdl::ImeitemIMUnit::writeXML(
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
 class IexWdbeMdl::ImeIMUnit::VecWIel
 ******************************************************************************/

uint IexWdbeMdl::ImeIMUnit::VecWIel::getIx(
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

void IexWdbeMdl::ImeIMUnit::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeMdl::ImeIMUnit::VecWIel::getSrefs(
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
 class IexWdbeMdl::ImeIMUnit
 ******************************************************************************/

IexWdbeMdl::ImeIMUnit::ImeIMUnit() {
};

IexWdbeMdl::ImeIMUnit::~ImeIMUnit() {
	clear();
};

void IexWdbeMdl::ImeIMUnit::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeMdl::ImeIMUnit::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeMdl::ImeitemIMUnit* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeMdl::ImeitemIMUnit();
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

void IexWdbeMdl::ImeIMUnit::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeMdl::ImeitemIMUnit* ii = NULL;

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

			ii = new IexWdbeMdl::ImeitemIMUnit();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeMdl::ImeIMUnit::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUnit." << StrMod::replaceChar(ImeIMUnit::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUnit.end" << endl;
	};
};

void IexWdbeMdl::ImeIMUnit::writeXML(
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
 namespace IexWdbeMdl
 ******************************************************************************/

void IexWdbeMdl::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIMUnit& imeimunit
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeimunit);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWdbeMdl", Version("1.1.28"), VecVIme::getIx);
			readTxt(rd, imeimunit);
	};
};

void IexWdbeMdl::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIMUnit& imeimunit
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeimunit);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeimunit);
		txtfile.close();
	};
};

void IexWdbeMdl::readTxt(
			Txtrd& txtrd
			, ImeIMUnit& imeimunit
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMUNIT)) imeimunit.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWdbeMdl::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMUnit& imeimunit
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeMdl")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.1.28")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.1.28"}});
		};

		// look for XML sub-blocks
		imeimunit.readXML(docctx, basexpath);

	} else {
		imeimunit = ImeIMUnit();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeMdl"}});
	};
};

void IexWdbeMdl::writeTxt(
			fstream& outfile
			, ImeIMUnit& imeimunit
		) {
	outfile << "IexWdbeMdl v" WDBE_VERSION << endl;

	imeimunit.writeTxt(outfile);
};

void IexWdbeMdl::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMUnit& imeimunit
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeMdl");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeimunit.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeMdl::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMMODULEPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMPERIPHERALPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCONTROLLER,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMGENERIC,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMIMBUF,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMMODULE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPERIPHERAL,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMUNIT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIRMMODULEMMODULE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIRMMODULEMPERIPHERAL,VecWdbeVIop::INS}};
};

uint IexWdbeMdl::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};
