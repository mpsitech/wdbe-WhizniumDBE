/**
	* \file IexWdbeFin.cpp
	* data blocks and readers/writers for import/export complex IexWdbeFin (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "IexWdbeFin.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeFin::VecVIme
 ******************************************************************************/

uint IexWdbeFin::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamfsmstatestep") return IMEIAMFSMSTATESTEP;
	if (s == "imeiampinpar") return IMEIAMPINPAR;
	if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	if (s == "imeicfsmstate") return IMEICFSMSTATE;
	if (s == "imeicgeneric") return IMEICGENERIC;
	if (s == "imeicpin") return IMEICPIN;
	if (s == "imeicport") return IMEICPORT;
	if (s == "imeicsignal1") return IMEICSIGNAL1;
	if (s == "imeicsignal2") return IMEICSIGNAL2;
	if (s == "imeicvariable1") return IMEICVARIABLE1;
	if (s == "imeicvariable2") return IMEICVARIABLE2;
	if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;
	if (s == "imeijmpinsref") return IMEIJMPINSREF;
	if (s == "imeimbank") return IMEIMBANK;
	if (s == "imeimcdc") return IMEIMCDC;
	if (s == "imeimcommand") return IMEIMCOMMAND;
	if (s == "imeimcontroller") return IMEIMCONTROLLER;
	if (s == "imeimerror") return IMEIMERROR;
	if (s == "imeimfsm") return IMEIMFSM;
	if (s == "imeimfsmstate") return IMEIMFSMSTATE;
	if (s == "imeimgeneric") return IMEIMGENERIC;
	if (s == "imeiminterrupt1") return IMEIMINTERRUPT1;
	if (s == "imeimmodule") return IMEIMMODULE;
	if (s == "imeimpin") return IMEIMPIN;
	if (s == "imeimport") return IMEIMPORT;
	if (s == "imeimprocess") return IMEIMPROCESS;
	if (s == "imeimsensitivity1") return IMEIMSENSITIVITY1;
	if (s == "imeimsensitivity2") return IMEIMSENSITIVITY2;
	if (s == "imeimsignal1") return IMEIMSIGNAL1;
	if (s == "imeimsignal2") return IMEIMSIGNAL2;
	if (s == "imeimunit") return IMEIMUNIT;
	if (s == "imeimvariable1") return IMEIMVARIABLE1;
	if (s == "imeimvariable2") return IMEIMVARIABLE2;
	if (s == "imeirmcdcmsignal") return IMEIRMCDCMSIGNAL;
	if (s == "imeirmcommandmcontroller") return IMEIRMCOMMANDMCONTROLLER;

	return(0);
};

string IexWdbeFin::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMFSMSTATESTEP) return("ImeIAMFsmstateStep");
	if (ix == IMEIAMPINPAR) return("ImeIAMPinPar");
	if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	if (ix == IMEICFSMSTATE) return("ImeICFsmstate");
	if (ix == IMEICGENERIC) return("ImeICGeneric");
	if (ix == IMEICPIN) return("ImeICPin");
	if (ix == IMEICPORT) return("ImeICPort");
	if (ix == IMEICSIGNAL1) return("ImeICSignal1");
	if (ix == IMEICSIGNAL2) return("ImeICSignal2");
	if (ix == IMEICVARIABLE1) return("ImeICVariable1");
	if (ix == IMEICVARIABLE2) return("ImeICVariable2");
	if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");
	if (ix == IMEIJMPINSREF) return("ImeIJMPinSref");
	if (ix == IMEIMBANK) return("ImeIMBank");
	if (ix == IMEIMCDC) return("ImeIMCdc");
	if (ix == IMEIMCOMMAND) return("ImeIMCommand");
	if (ix == IMEIMCONTROLLER) return("ImeIMController");
	if (ix == IMEIMERROR) return("ImeIMError");
	if (ix == IMEIMFSM) return("ImeIMFsm");
	if (ix == IMEIMFSMSTATE) return("ImeIMFsmstate");
	if (ix == IMEIMGENERIC) return("ImeIMGeneric");
	if (ix == IMEIMINTERRUPT1) return("ImeIMInterrupt1");
	if (ix == IMEIMMODULE) return("ImeIMModule");
	if (ix == IMEIMPIN) return("ImeIMPin");
	if (ix == IMEIMPORT) return("ImeIMPort");
	if (ix == IMEIMPROCESS) return("ImeIMProcess");
	if (ix == IMEIMSENSITIVITY1) return("ImeIMSensitivity1");
	if (ix == IMEIMSENSITIVITY2) return("ImeIMSensitivity2");
	if (ix == IMEIMSIGNAL1) return("ImeIMSignal1");
	if (ix == IMEIMSIGNAL2) return("ImeIMSignal2");
	if (ix == IMEIMUNIT) return("ImeIMUnit");
	if (ix == IMEIMVARIABLE1) return("ImeIMVariable1");
	if (ix == IMEIMVARIABLE2) return("ImeIMVariable2");
	if (ix == IMEIRMCDCMSIGNAL) return("ImeIRMCdcMSignal");
	if (ix == IMEIRMCOMMANDMCONTROLLER) return("ImeIRMCommandMController");

	return("");
};

/******************************************************************************
 class IexWdbeFin::ImeitemICSignal1
 ******************************************************************************/

IexWdbeFin::ImeitemICSignal1::ImeitemICSignal1(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeFin::ImeitemICSignal1::ImeitemICSignal1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICSignal1()
		{
};

void IexWdbeFin::ImeitemICSignal1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICSignal1::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICSignal1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemICSignal1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICSignal1::VecWIel::IREF;
	};
};

void IexWdbeFin::ImeitemICSignal1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWdbeFin::ImeitemICSignal1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICSignal1","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeICSignal1::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeICSignal1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeFin::ImeICSignal1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeICSignal1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeICSignal1
 ******************************************************************************/

IexWdbeFin::ImeICSignal1::ImeICSignal1() {
};

IexWdbeFin::ImeICSignal1::~ImeICSignal1() {
	clear();
};

void IexWdbeFin::ImeICSignal1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeICSignal1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemICSignal1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeFin::ImeitemICSignal1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSignal1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICSignal1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICSIGNAL1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSignal1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSignal1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeICSignal1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemICSignal1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICSignal1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICSignal1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICSignal1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemICSignal1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeICSignal1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICSignal1." << StrMod::replaceChar(ImeICSignal1::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICSignal1.end" << endl;
	};
};

void IexWdbeFin::ImeICSignal1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICSignal1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemICPin
 ******************************************************************************/

IexWdbeFin::ImeitemICPin::ImeitemICPin(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeFin::ImeitemICPin::ImeitemICPin(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICPin()
		{
};

void IexWdbeFin::ImeitemICPin::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICPin::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICPin"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemICPin::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICPin::VecWIel::IREF;
	};
};

void IexWdbeFin::ImeitemICPin::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeFin::ImeitemICPin::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICPin","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeICPin::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeICPin::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeFin::ImeICPin::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeICPin::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeICPin
 ******************************************************************************/

IexWdbeFin::ImeICPin::ImeICPin() {
};

IexWdbeFin::ImeICPin::~ImeICPin() {
	clear();
};

void IexWdbeFin::ImeICPin::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeICPin::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemICPin* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemICPin();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICPin"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICPin"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICPIN) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICPin"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICPin"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeICPin::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemICPin* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICPin");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICPin", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICPin";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemICPin();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeICPin::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICPin." << StrMod::replaceChar(ImeICPin::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICPin.end" << endl;
	};
};

void IexWdbeFin::ImeICPin::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICPin");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIAMPinPar
 ******************************************************************************/

IexWdbeFin::ImeitemIAMPinPar::ImeitemIAMPinPar(
			const string& x1SrefKKey
			, const string& Val
		) : WdbeAMPinPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWdbeFin::ImeitemIAMPinPar::ImeitemIAMPinPar(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMPinPar()
		{
	WdbeAMPinPar* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeampinpar->loadRecByRef(ref, &rec)) {
		refWdbeMPin = rec->refWdbeMPin;
		x1SrefKKey = rec->x1SrefKKey;
		Val = rec->Val;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIAMPinPar::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {x1SrefKKey = txtrd.fields[0]; ixWIelValid += ImeIAMPinPar::VecWIel::X1SREFKKEY;};
	if (txtrd.fields.size() > 1) {Val = txtrd.fields[1]; ixWIelValid += ImeIAMPinPar::VecWIel::VAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMPinPar"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIAMPinPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMPinPar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMPinPar::VecWIel::VAL;
	};
};

void IexWdbeFin::ImeitemIAMPinPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWdbeFin::ImeitemIAMPinPar::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","key","val"};
	else tags = {"ImeitemIAMPinPar","x1SrefKKey","Val"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], x1SrefKKey);
		writeString(wr, tags[2], Val);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIAMPinPar::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIAMPinPar::VecWIel::getIx(
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

void IexWdbeFin::ImeIAMPinPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIAMPinPar::VecWIel::getSrefs(
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
 class IexWdbeFin::ImeIAMPinPar
 ******************************************************************************/

IexWdbeFin::ImeIAMPinPar::ImeIAMPinPar() {
};

IexWdbeFin::ImeIAMPinPar::~ImeIAMPinPar() {
	clear();
};

void IexWdbeFin::ImeIAMPinPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIAMPinPar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIAMPinPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIAMPinPar();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMPinPar"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMPinPar"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMPINPAR) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMPinPar"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMPinPar"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIAMPinPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIAMPinPar* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMPinPar");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMPinPar", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMPinPar";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIAMPinPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIAMPinPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMPinPar." << StrMod::replaceChar(ImeIAMPinPar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMPinPar.end" << endl;
	};
};

void IexWdbeFin::ImeIAMPinPar::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMPinPar");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIJMPinSref
 ******************************************************************************/

IexWdbeFin::ImeitemIJMPinSref::ImeitemIJMPinSref(
			const string& srefX1RefWdbeMPeripheral
			, const string& sref
		) : WdbeJMPinSref() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWdbeMPeripheral = srefX1RefWdbeMPeripheral;
	this->sref = sref;
};

IexWdbeFin::ImeitemIJMPinSref::ImeitemIJMPinSref(
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

void IexWdbeFin::ImeitemIJMPinSref::readTxt(
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

void IexWdbeFin::ImeitemIJMPinSref::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWdbeMPeripheral", "", srefX1RefWdbeMPeripheral)) ixWIelValid += ImeIJMPinSref::VecWIel::SREFX1REFWDBEMPERIPHERAL;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIJMPinSref::VecWIel::SREF;
	};
};

void IexWdbeFin::ImeitemIJMPinSref::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWdbeMPeripheral << "\t" << sref << endl;
};

void IexWdbeFin::ImeitemIJMPinSref::writeXML(
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
 class IexWdbeFin::ImeIJMPinSref::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIJMPinSref::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefx1refwdbemperipheral") ix |= SREFX1REFWDBEMPERIPHERAL;
		else if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWdbeFin::ImeIJMPinSref::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIJMPinSref::VecWIel::getSrefs(
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
 class IexWdbeFin::ImeIJMPinSref
 ******************************************************************************/

IexWdbeFin::ImeIJMPinSref::ImeIJMPinSref() {
};

IexWdbeFin::ImeIJMPinSref::~ImeIJMPinSref() {
	clear();
};

void IexWdbeFin::ImeIJMPinSref::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIJMPinSref::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIJMPinSref* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIJMPinSref();
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

void IexWdbeFin::ImeIJMPinSref::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIJMPinSref* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIJMPinSref();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIJMPinSref::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPinSref." << StrMod::replaceChar(ImeIJMPinSref::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMPinSref.end" << endl;
	};
};

void IexWdbeFin::ImeIJMPinSref::writeXML(
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
 class IexWdbeFin::ImeitemIMPin
 ******************************************************************************/

IexWdbeFin::ImeitemIMPin::ImeitemIMPin(
			const uint ixWdbeVIop
			, const ubigint irefRefWdbeCPin
			, const string& sref
			, const string& Location
		) : WdbeMPin() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWdbeVIop = ixWdbeVIop;
	this->irefRefWdbeCPin = irefRefWdbeCPin;
	this->sref = sref;
	this->Location = Location;
};

IexWdbeFin::ImeitemIMPin::ImeitemIMPin(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVIop
			, const ubigint ref
		) :
			ImeitemIMPin(ixWdbeVIop)
		{
	WdbeMPin* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbempin->loadRecByRef(ref, &rec)) {
		refWdbeCPin = rec->refWdbeCPin;
		refWdbeMBank = rec->refWdbeMBank;
		refJSref = rec->refJSref;
		sref = rec->sref;
		Location = rec->Location;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMPin::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWdbeVIop = txtrd.fields[0]; ixWIelValid += ImeIMPin::VecWIel::SREFIXWDBEVIOP;};
	if (txtrd.fields.size() > 1) {irefRefWdbeCPin = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMPin::VecWIel::IREFREFWDBECPIN;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMPin::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {Location = txtrd.fields[3]; ixWIelValid += ImeIMPin::VecWIel::LOCATION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIAMPINPAR)) {
					imeiampinpar.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJMPINSREF)) {
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

void IexWdbeFin::ImeitemIMPin::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVIop", "iop", srefIxWdbeVIop)) ixWIelValid += ImeIMPin::VecWIel::SREFIXWDBEVIOP;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCPin", "clu", irefRefWdbeCPin)) ixWIelValid += ImeIMPin::VecWIel::IREFREFWDBECPIN;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPin::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Location", "loc", Location)) ixWIelValid += ImeIMPin::VecWIel::LOCATION;
		imeiampinpar.readXML(docctx, basexpath);
		imeijmpinsref.readXML(docctx, basexpath);
	};
};

void IexWdbeFin::ImeitemIMPin::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << irefRefWdbeCPin << "\t" << sref << "\t" << Location << endl;
	imeiampinpar.writeTxt(outfile);
	imeijmpinsref.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIMPin::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","clu","srf","loc"};
	else tags = {"ImeitemIMPin","srefIxWdbeVIop","irefRefWdbeCPin","sref","Location"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVIop::getSref(ixWdbeVIop));
		writeUbigint(wr, tags[2], irefRefWdbeCPin);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], Location);
		imeiampinpar.writeXML(wr, shorttags);
		imeijmpinsref.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMPin::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMPin::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwdbeviop") ix |= SREFIXWDBEVIOP;
		else if (ss[i] == "irefrefwdbecpin") ix |= IREFREFWDBECPIN;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "location") ix |= LOCATION;
	};

	return(ix);
};

void IexWdbeFin::ImeIMPin::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LOCATION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMPin::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWDBEVIOP) ss.push_back("srefIxWdbeVIop");
	if (ix & IREFREFWDBECPIN) ss.push_back("irefRefWdbeCPin");
	if (ix & SREF) ss.push_back("sref");
	if (ix & LOCATION) ss.push_back("Location");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMPin
 ******************************************************************************/

IexWdbeFin::ImeIMPin::ImeIMPin() {
};

IexWdbeFin::ImeIMPin::~ImeIMPin() {
	clear();
};

void IexWdbeFin::ImeIMPin::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMPin::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMPin* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemIMPin();
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

void IexWdbeFin::ImeIMPin::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMPin* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIMPin();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMPin::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPin." << StrMod::replaceChar(ImeIMPin::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPin.end" << endl;
	};
};

void IexWdbeFin::ImeIMPin::writeXML(
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
 class IexWdbeFin::ImeitemIMBank
 ******************************************************************************/

IexWdbeFin::ImeitemIMBank::ImeitemIMBank(
			const uint ixWdbeVIop
			, const string& sref
			, const string& srefKVoltstd
		) : WdbeMBank() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWdbeVIop = ixWdbeVIop;
	this->sref = sref;
	this->srefKVoltstd = srefKVoltstd;
};

IexWdbeFin::ImeitemIMBank::ImeitemIMBank(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVIop
			, const ubigint ref
		) :
			ImeitemIMBank(ixWdbeVIop)
		{
	WdbeMBank* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbembank->loadRecByRef(ref, &rec)) {
		refWdbeMUnit = rec->refWdbeMUnit;
		sref = rec->sref;
		srefKVoltstd = rec->srefKVoltstd;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMBank::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWdbeVIop = txtrd.fields[0]; ixWIelValid += ImeIMBank::VecWIel::SREFIXWDBEVIOP;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMBank::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefKVoltstd = txtrd.fields[2]; ixWIelValid += ImeIMBank::VecWIel::SREFKVOLTSTD;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICPIN)) {
					imeicpin.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPIN)) {
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

void IexWdbeFin::ImeitemIMBank::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVIop", "iop", srefIxWdbeVIop)) ixWIelValid += ImeIMBank::VecWIel::SREFIXWDBEVIOP;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMBank::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefKVoltstd", "vst", srefKVoltstd)) ixWIelValid += ImeIMBank::VecWIel::SREFKVOLTSTD;
		imeicpin.readXML(docctx, basexpath);
		imeimpin.readXML(docctx, basexpath);
	};
};

void IexWdbeFin::ImeitemIMBank::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << sref << "\t" << srefKVoltstd << endl;
	imeicpin.writeTxt(outfile);
	imeimpin.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIMBank::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","srf","vst"};
	else tags = {"ImeitemIMBank","srefIxWdbeVIop","sref","srefKVoltstd"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVIop::getSref(ixWdbeVIop));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefKVoltstd);
		imeicpin.writeXML(wr, shorttags);
		imeimpin.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMBank::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMBank::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwdbeviop") ix |= SREFIXWDBEVIOP;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefkvoltstd") ix |= SREFKVOLTSTD;
	};

	return(ix);
};

void IexWdbeFin::ImeIMBank::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFKVOLTSTD); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMBank::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWDBEVIOP) ss.push_back("srefIxWdbeVIop");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFKVOLTSTD) ss.push_back("srefKVoltstd");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMBank
 ******************************************************************************/

IexWdbeFin::ImeIMBank::ImeIMBank() {
};

IexWdbeFin::ImeIMBank::~ImeIMBank() {
	clear();
};

void IexWdbeFin::ImeIMBank::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMBank::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMBank* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeFin::ImeitemIMBank();
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

void IexWdbeFin::ImeIMBank::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMBank* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIMBank();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMBank::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMBank." << StrMod::replaceChar(ImeIMBank::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMBank.end" << endl;
	};
};

void IexWdbeFin::ImeIMBank::writeXML(
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
 class IexWdbeFin::ImeitemIMInterrupt1
 ******************************************************************************/

IexWdbeFin::ImeitemIMInterrupt1::ImeitemIMInterrupt1(
			const string& sref
			, const string& Comment
		) : WdbeMInterrupt() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIMInterrupt1::ImeitemIMInterrupt1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMInterrupt1()
		{
	WdbeMInterrupt* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeminterrupt->loadRecByRef(ref, &rec)) {
		refWdbeMUnit = rec->refWdbeMUnit;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMInterrupt1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMInterrupt1::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIMInterrupt1::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMInterrupt1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMInterrupt1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMInterrupt1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMInterrupt1::VecWIel::COMMENT;
	};
};

void IexWdbeFin::ImeitemIMInterrupt1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << Comment << endl;
};

void IexWdbeFin::ImeitemIMInterrupt1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIMInterrupt1","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMInterrupt1::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMInterrupt1::VecWIel::getIx(
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

void IexWdbeFin::ImeIMInterrupt1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMInterrupt1::VecWIel::getSrefs(
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
 class IexWdbeFin::ImeIMInterrupt1
 ******************************************************************************/

IexWdbeFin::ImeIMInterrupt1::ImeIMInterrupt1() {
};

IexWdbeFin::ImeIMInterrupt1::~ImeIMInterrupt1() {
	clear();
};

void IexWdbeFin::ImeIMInterrupt1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMInterrupt1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMInterrupt1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeFin::ImeitemIMInterrupt1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMInterrupt1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMInterrupt1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMINTERRUPT1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMInterrupt1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMInterrupt1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMInterrupt1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMInterrupt1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMInterrupt1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMInterrupt1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMInterrupt1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMInterrupt1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMInterrupt1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMInterrupt1." << StrMod::replaceChar(ImeIMInterrupt1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMInterrupt1.end" << endl;
	};
};

void IexWdbeFin::ImeIMInterrupt1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMInterrupt1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemICGeneric
 ******************************************************************************/

IexWdbeFin::ImeitemICGeneric::ImeitemICGeneric(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeFin::ImeitemICGeneric::ImeitemICGeneric(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICGeneric()
		{
};

void IexWdbeFin::ImeitemICGeneric::readTxt(
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

void IexWdbeFin::ImeitemICGeneric::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICGeneric::VecWIel::IREF;
	};
};

void IexWdbeFin::ImeitemICGeneric::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeFin::ImeitemICGeneric::writeXML(
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
 class IexWdbeFin::ImeICGeneric::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeICGeneric::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeFin::ImeICGeneric::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeICGeneric::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeICGeneric
 ******************************************************************************/

IexWdbeFin::ImeICGeneric::ImeICGeneric() {
};

IexWdbeFin::ImeICGeneric::~ImeICGeneric() {
	clear();
};

void IexWdbeFin::ImeICGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeICGeneric::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemICGeneric* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemICGeneric();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeFin::ImeICGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemICGeneric* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemICGeneric();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeICGeneric::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICGeneric." << StrMod::replaceChar(ImeICGeneric::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICGeneric.end" << endl;
	};
};

void IexWdbeFin::ImeICGeneric::writeXML(
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
 class IexWdbeFin::ImeitemICPort
 ******************************************************************************/

IexWdbeFin::ImeitemICPort::ImeitemICPort(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeFin::ImeitemICPort::ImeitemICPort(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICPort()
		{
};

void IexWdbeFin::ImeitemICPort::readTxt(
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

void IexWdbeFin::ImeitemICPort::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICPort::VecWIel::IREF;
	};
};

void IexWdbeFin::ImeitemICPort::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeFin::ImeitemICPort::writeXML(
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
 class IexWdbeFin::ImeICPort::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeICPort::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeFin::ImeICPort::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeICPort::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeICPort
 ******************************************************************************/

IexWdbeFin::ImeICPort::ImeICPort() {
};

IexWdbeFin::ImeICPort::~ImeICPort() {
	clear();
};

void IexWdbeFin::ImeICPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeICPort::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemICPort* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemICPort();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeFin::ImeICPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemICPort* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemICPort();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeICPort::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICPort." << StrMod::replaceChar(ImeICPort::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICPort.end" << endl;
	};
};

void IexWdbeFin::ImeICPort::writeXML(
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
 class IexWdbeFin::ImeitemICSignal2
 ******************************************************************************/

IexWdbeFin::ImeitemICSignal2::ImeitemICSignal2(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeFin::ImeitemICSignal2::ImeitemICSignal2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICSignal2()
		{
};

void IexWdbeFin::ImeitemICSignal2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICSignal2::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICSignal2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemICSignal2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICSignal2::VecWIel::IREF;
	};
};

void IexWdbeFin::ImeitemICSignal2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeFin::ImeitemICSignal2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICSignal2","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeICSignal2::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeICSignal2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeFin::ImeICSignal2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeICSignal2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeICSignal2
 ******************************************************************************/

IexWdbeFin::ImeICSignal2::ImeICSignal2() {
};

IexWdbeFin::ImeICSignal2::~ImeICSignal2() {
	clear();
};

void IexWdbeFin::ImeICSignal2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeICSignal2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemICSignal2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemICSignal2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSignal2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICSignal2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICSIGNAL2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSignal2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSignal2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeICSignal2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemICSignal2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICSignal2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICSignal2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICSignal2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemICSignal2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeICSignal2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICSignal2." << StrMod::replaceChar(ImeICSignal2::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICSignal2.end" << endl;
	};
};

void IexWdbeFin::ImeICSignal2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICSignal2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemICVariable1
 ******************************************************************************/

IexWdbeFin::ImeitemICVariable1::ImeitemICVariable1(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeFin::ImeitemICVariable1::ImeitemICVariable1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICVariable1()
		{
};

void IexWdbeFin::ImeitemICVariable1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICVariable1::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICVariable1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemICVariable1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICVariable1::VecWIel::IREF;
	};
};

void IexWdbeFin::ImeitemICVariable1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeFin::ImeitemICVariable1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICVariable1","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeICVariable1::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeICVariable1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeFin::ImeICVariable1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeICVariable1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeICVariable1
 ******************************************************************************/

IexWdbeFin::ImeICVariable1::ImeICVariable1() {
};

IexWdbeFin::ImeICVariable1::~ImeICVariable1() {
	clear();
};

void IexWdbeFin::ImeICVariable1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeICVariable1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemICVariable1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemICVariable1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICVariable1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICVariable1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICVARIABLE1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICVariable1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICVariable1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeICVariable1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemICVariable1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICVariable1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICVariable1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICVariable1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemICVariable1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeICVariable1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICVariable1." << StrMod::replaceChar(ImeICVariable1::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICVariable1.end" << endl;
	};
};

void IexWdbeFin::ImeICVariable1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICVariable1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIRMCdcMSignal
 ******************************************************************************/

IexWdbeFin::ImeitemIRMCdcMSignal::ImeitemIRMCdcMSignal(
			const string& srefRefWdbeMSignal
			, const uint ixVDir
		) : WdbeRMCdcMSignal() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWdbeMSignal = srefRefWdbeMSignal;
	this->ixVDir = ixVDir;
};

IexWdbeFin::ImeitemIRMCdcMSignal::ImeitemIRMCdcMSignal(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIRMCdcMSignal()
		{
	WdbeRMCdcMSignal* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbermcdcmsignal->loadRecByRef(ref, &rec)) {
		refWdbeMCdc = rec->refWdbeMCdc;
		refWdbeMSignal = rec->refWdbeMSignal;
		ixVDir = rec->ixVDir;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIRMCdcMSignal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWdbeMSignal = txtrd.fields[0]; ixWIelValid += ImeIRMCdcMSignal::VecWIel::SREFREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 1) {srefIxVDir = txtrd.fields[1]; ixWIelValid += ImeIRMCdcMSignal::VecWIel::SREFIXVDIR;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCdcMSignal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIRMCdcMSignal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMSignal", "sig", srefRefWdbeMSignal)) ixWIelValid += ImeIRMCdcMSignal::VecWIel::SREFREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir)) ixWIelValid += ImeIRMCdcMSignal::VecWIel::SREFIXVDIR;
	};
};

void IexWdbeFin::ImeitemIRMCdcMSignal::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefRefWdbeMSignal << "\t" << VecWdbeVRMCdcMSignalDir::getSref(ixVDir) << endl;
};

void IexWdbeFin::ImeitemIRMCdcMSignal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sig","dir"};
	else tags = {"ImeitemIRMCdcMSignal","srefRefWdbeMSignal","srefIxVDir"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWdbeMSignal);
		writeString(wr, tags[2], VecWdbeVRMCdcMSignalDir::getSref(ixVDir));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIRMCdcMSignal::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIRMCdcMSignal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwdbemsignal") ix |= SREFREFWDBEMSIGNAL;
		else if (ss[i] == "srefixvdir") ix |= SREFIXVDIR;
	};

	return(ix);
};

void IexWdbeFin::ImeIRMCdcMSignal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVDIR); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIRMCdcMSignal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWDBEMSIGNAL) ss.push_back("srefRefWdbeMSignal");
	if (ix & SREFIXVDIR) ss.push_back("srefIxVDir");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIRMCdcMSignal
 ******************************************************************************/

IexWdbeFin::ImeIRMCdcMSignal::ImeIRMCdcMSignal() {
};

IexWdbeFin::ImeIRMCdcMSignal::~ImeIRMCdcMSignal() {
	clear();
};

void IexWdbeFin::ImeIRMCdcMSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIRMCdcMSignal::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIRMCdcMSignal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIRMCdcMSignal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCdcMSignal"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCdcMSignal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMCDCMSIGNAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCdcMSignal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCdcMSignal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIRMCdcMSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIRMCdcMSignal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMCdcMSignal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMCdcMSignal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMCdcMSignal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIRMCdcMSignal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIRMCdcMSignal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIRMCdcMSignal." << StrMod::replaceChar(ImeIRMCdcMSignal::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIRMCdcMSignal.end" << endl;
	};
};

void IexWdbeFin::ImeIRMCdcMSignal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMCdcMSignal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMCdc
 ******************************************************************************/

IexWdbeFin::ImeitemIMCdc::ImeitemIMCdc(
			const string& fckSrefWdbeMSignal
			, const string& farSrefWdbeMSignal
			, const string& sckSrefWdbeMSignal
			, const string& sarSrefWdbeMSignal
			, const double Ratio
		) : WdbeMCdc() {
	lineno = 0;
	ixWIelValid = 0;

	this->fckSrefWdbeMSignal = fckSrefWdbeMSignal;
	this->farSrefWdbeMSignal = farSrefWdbeMSignal;
	this->sckSrefWdbeMSignal = sckSrefWdbeMSignal;
	this->sarSrefWdbeMSignal = sarSrefWdbeMSignal;
	this->Ratio = Ratio;
};

IexWdbeFin::ImeitemIMCdc::ImeitemIMCdc(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMCdc()
		{
	WdbeMCdc* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcdc->loadRecByRef(ref, &rec)) {
		refWdbeMModule = rec->refWdbeMModule;
		fckSrefWdbeMSignal = rec->fckSrefWdbeMSignal;
		farSrefWdbeMSignal = rec->farSrefWdbeMSignal;
		sckSrefWdbeMSignal = rec->sckSrefWdbeMSignal;
		sarSrefWdbeMSignal = rec->sarSrefWdbeMSignal;
		Ratio = rec->Ratio;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMCdc::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {fckSrefWdbeMSignal = txtrd.fields[0]; ixWIelValid += ImeIMCdc::VecWIel::FCKSREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 1) {farSrefWdbeMSignal = txtrd.fields[1]; ixWIelValid += ImeIMCdc::VecWIel::FARSREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 2) {sckSrefWdbeMSignal = txtrd.fields[2]; ixWIelValid += ImeIMCdc::VecWIel::SCKSREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 3) {sarSrefWdbeMSignal = txtrd.fields[3]; ixWIelValid += ImeIMCdc::VecWIel::SARSREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 4) {Ratio = atof(txtrd.fields[4].c_str()); ixWIelValid += ImeIMCdc::VecWIel::RATIO;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIRMCDCMSIGNAL)) {
					imeirmcdcmsignal.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCdc"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMCdc::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "fckSrefWdbeMSignal", "fck", fckSrefWdbeMSignal)) ixWIelValid += ImeIMCdc::VecWIel::FCKSREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "farSrefWdbeMSignal", "far", farSrefWdbeMSignal)) ixWIelValid += ImeIMCdc::VecWIel::FARSREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "sckSrefWdbeMSignal", "sck", sckSrefWdbeMSignal)) ixWIelValid += ImeIMCdc::VecWIel::SCKSREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "sarSrefWdbeMSignal", "sar", sarSrefWdbeMSignal)) ixWIelValid += ImeIMCdc::VecWIel::SARSREFWDBEMSIGNAL;
		if (extractDoubleUclc(docctx, basexpath, "Ratio", "rat", Ratio)) ixWIelValid += ImeIMCdc::VecWIel::RATIO;
		imeirmcdcmsignal.readXML(docctx, basexpath);
	};
};

void IexWdbeFin::ImeitemIMCdc::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << fckSrefWdbeMSignal << "\t" << farSrefWdbeMSignal << "\t" << sckSrefWdbeMSignal << "\t" << sarSrefWdbeMSignal << "\t" << Ratio << endl;
	imeirmcdcmsignal.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIMCdc::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","fck","far","sck","sar","rat"};
	else tags = {"ImeitemIMCdc","fckSrefWdbeMSignal","farSrefWdbeMSignal","sckSrefWdbeMSignal","sarSrefWdbeMSignal","Ratio"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], fckSrefWdbeMSignal);
		writeString(wr, tags[2], farSrefWdbeMSignal);
		writeString(wr, tags[3], sckSrefWdbeMSignal);
		writeString(wr, tags[4], sarSrefWdbeMSignal);
		writeDouble(wr, tags[5], Ratio);
		imeirmcdcmsignal.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMCdc::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMCdc::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "fcksrefwdbemsignal") ix |= FCKSREFWDBEMSIGNAL;
		else if (ss[i] == "farsrefwdbemsignal") ix |= FARSREFWDBEMSIGNAL;
		else if (ss[i] == "scksrefwdbemsignal") ix |= SCKSREFWDBEMSIGNAL;
		else if (ss[i] == "sarsrefwdbemsignal") ix |= SARSREFWDBEMSIGNAL;
		else if (ss[i] == "ratio") ix |= RATIO;
	};

	return(ix);
};

void IexWdbeFin::ImeIMCdc::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*RATIO); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMCdc::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & FCKSREFWDBEMSIGNAL) ss.push_back("fckSrefWdbeMSignal");
	if (ix & FARSREFWDBEMSIGNAL) ss.push_back("farSrefWdbeMSignal");
	if (ix & SCKSREFWDBEMSIGNAL) ss.push_back("sckSrefWdbeMSignal");
	if (ix & SARSREFWDBEMSIGNAL) ss.push_back("sarSrefWdbeMSignal");
	if (ix & RATIO) ss.push_back("Ratio");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMCdc
 ******************************************************************************/

IexWdbeFin::ImeIMCdc::ImeIMCdc() {
};

IexWdbeFin::ImeIMCdc::~ImeIMCdc() {
	clear();
};

void IexWdbeFin::ImeIMCdc::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMCdc::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMCdc* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemIMCdc();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCdc"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCdc"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCDC) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCdc"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCdc"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMCdc::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMCdc* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCdc");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCdc", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCdc";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMCdc();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMCdc::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMCdc." << StrMod::replaceChar(ImeIMCdc::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMCdc.end" << endl;
	};
};

void IexWdbeFin::ImeIMCdc::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCdc");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMCommand
 ******************************************************************************/

IexWdbeFin::ImeitemIMCommand::ImeitemIMCommand(
			const string& sref
			, const string& srefIvrRefWdbeMSignal
			, const string& srefRvrRefWdbeMSignal
			, const string& srefRerRefWdbeMSignal
		) : WdbeMCommand() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->srefIvrRefWdbeMSignal = srefIvrRefWdbeMSignal;
	this->srefRvrRefWdbeMSignal = srefRvrRefWdbeMSignal;
	this->srefRerRefWdbeMSignal = srefRerRefWdbeMSignal;
};

IexWdbeFin::ImeitemIMCommand::ImeitemIMCommand(
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
		sref = rec->sref;
		ivrRefWdbeMSignal = rec->ivrRefWdbeMSignal;
		rvrRefWdbeMSignal = rec->rvrRefWdbeMSignal;
		rerRefWdbeMSignal = rec->rerRefWdbeMSignal;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMCommand::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMCommand::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIvrRefWdbeMSignal = txtrd.fields[1]; ixWIelValid += ImeIMCommand::VecWIel::SREFIVRREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 2) {srefRvrRefWdbeMSignal = txtrd.fields[2]; ixWIelValid += ImeIMCommand::VecWIel::SREFRVRREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 3) {srefRerRefWdbeMSignal = txtrd.fields[3]; ixWIelValid += ImeIMCommand::VecWIel::SREFRERREFWDBEMSIGNAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCommand"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMCommand::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCommand::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIvrRefWdbeMSignal", "ivr", srefIvrRefWdbeMSignal)) ixWIelValid += ImeIMCommand::VecWIel::SREFIVRREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefRvrRefWdbeMSignal", "rvr", srefRvrRefWdbeMSignal)) ixWIelValid += ImeIMCommand::VecWIel::SREFRVRREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefRerRefWdbeMSignal", "rer", srefRerRefWdbeMSignal)) ixWIelValid += ImeIMCommand::VecWIel::SREFRERREFWDBEMSIGNAL;
	};
};

void IexWdbeFin::ImeitemIMCommand::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << srefIvrRefWdbeMSignal << "\t" << srefRvrRefWdbeMSignal << "\t" << srefRerRefWdbeMSignal << endl;
};

void IexWdbeFin::ImeitemIMCommand::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","ivr","rvr","rer"};
	else tags = {"ImeitemIMCommand","sref","srefIvrRefWdbeMSignal","srefRvrRefWdbeMSignal","srefRerRefWdbeMSignal"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], srefIvrRefWdbeMSignal);
		writeString(wr, tags[3], srefRvrRefWdbeMSignal);
		writeString(wr, tags[4], srefRerRefWdbeMSignal);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMCommand::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMCommand::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefivrrefwdbemsignal") ix |= SREFIVRREFWDBEMSIGNAL;
		else if (ss[i] == "srefrvrrefwdbemsignal") ix |= SREFRVRREFWDBEMSIGNAL;
		else if (ss[i] == "srefrerrefwdbemsignal") ix |= SREFRERREFWDBEMSIGNAL;
	};

	return(ix);
};

void IexWdbeFin::ImeIMCommand::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFRERREFWDBEMSIGNAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMCommand::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIVRREFWDBEMSIGNAL) ss.push_back("srefIvrRefWdbeMSignal");
	if (ix & SREFRVRREFWDBEMSIGNAL) ss.push_back("srefRvrRefWdbeMSignal");
	if (ix & SREFRERREFWDBEMSIGNAL) ss.push_back("srefRerRefWdbeMSignal");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMCommand
 ******************************************************************************/

IexWdbeFin::ImeIMCommand::ImeIMCommand() {
};

IexWdbeFin::ImeIMCommand::~ImeIMCommand() {
	clear();
};

void IexWdbeFin::ImeIMCommand::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMCommand::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMCommand* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIMCommand();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
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

void IexWdbeFin::ImeIMCommand::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMCommand* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIMCommand();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMCommand::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMCommand." << StrMod::replaceChar(ImeIMCommand::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMCommand.end" << endl;
	};
};

void IexWdbeFin::ImeIMCommand::writeXML(
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
 class IexWdbeFin::ImeitemIMError
 ******************************************************************************/

IexWdbeFin::ImeitemIMError::ImeitemIMError(
			const string& sref
			, const string& srefTraRefWdbeMSignal
		) : WdbeMError() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->srefTraRefWdbeMSignal = srefTraRefWdbeMSignal;
};

IexWdbeFin::ImeitemIMError::ImeitemIMError(
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
		sref = rec->sref;
		traRefWdbeMSignal = rec->traRefWdbeMSignal;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMError::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMError::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefTraRefWdbeMSignal = txtrd.fields[1]; ixWIelValid += ImeIMError::VecWIel::SREFTRAREFWDBEMSIGNAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMError"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMError::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMError::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefTraRefWdbeMSignal", "tra", srefTraRefWdbeMSignal)) ixWIelValid += ImeIMError::VecWIel::SREFTRAREFWDBEMSIGNAL;
	};
};

void IexWdbeFin::ImeitemIMError::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << srefTraRefWdbeMSignal << endl;
};

void IexWdbeFin::ImeitemIMError::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tra"};
	else tags = {"ImeitemIMError","sref","srefTraRefWdbeMSignal"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], srefTraRefWdbeMSignal);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMError::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMError::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "sreftrarefwdbemsignal") ix |= SREFTRAREFWDBEMSIGNAL;
	};

	return(ix);
};

void IexWdbeFin::ImeIMError::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFTRAREFWDBEMSIGNAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMError::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFTRAREFWDBEMSIGNAL) ss.push_back("srefTraRefWdbeMSignal");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMError
 ******************************************************************************/

IexWdbeFin::ImeIMError::ImeIMError() {
};

IexWdbeFin::ImeIMError::~ImeIMError() {
	clear();
};

void IexWdbeFin::ImeIMError::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMError::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMError* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIMError();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
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

void IexWdbeFin::ImeIMError::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMError* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIMError();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMError::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMError." << StrMod::replaceChar(ImeIMError::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMError.end" << endl;
	};
};

void IexWdbeFin::ImeIMError::writeXML(
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
 class IexWdbeFin::ImeitemIRMCommandMController
 ******************************************************************************/

IexWdbeFin::ImeitemIRMCommandMController::ImeitemIRMCommandMController(
			const string& srefRefWdbeMCommand
			, const string& srefIvrRefWdbeMSignal
			, const string& srefRvrRefWdbeMSignal
		) : WdbeRMCommandMController() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWdbeMCommand = srefRefWdbeMCommand;
	this->srefIvrRefWdbeMSignal = srefIvrRefWdbeMSignal;
	this->srefRvrRefWdbeMSignal = srefRvrRefWdbeMSignal;
};

IexWdbeFin::ImeitemIRMCommandMController::ImeitemIRMCommandMController(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIRMCommandMController()
		{
	WdbeRMCommandMController* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbermcommandmcontroller->loadRecByRef(ref, &rec)) {
		refWdbeMCommand = rec->refWdbeMCommand;
		refWdbeMController = rec->refWdbeMController;
		ivrRefWdbeMSignal = rec->ivrRefWdbeMSignal;
		rvrRefWdbeMSignal = rec->rvrRefWdbeMSignal;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIRMCommandMController::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWdbeMCommand = txtrd.fields[0]; ixWIelValid += ImeIRMCommandMController::VecWIel::SREFREFWDBEMCOMMAND;};
	if (txtrd.fields.size() > 1) {srefIvrRefWdbeMSignal = txtrd.fields[1]; ixWIelValid += ImeIRMCommandMController::VecWIel::SREFIVRREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 2) {srefRvrRefWdbeMSignal = txtrd.fields[2]; ixWIelValid += ImeIRMCommandMController::VecWIel::SREFRVRREFWDBEMSIGNAL;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCommandMController"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIRMCommandMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMCommand", "cmd", srefRefWdbeMCommand)) ixWIelValid += ImeIRMCommandMController::VecWIel::SREFREFWDBEMCOMMAND;
		if (extractStringUclc(docctx, basexpath, "srefIvrRefWdbeMSignal", "ivr", srefIvrRefWdbeMSignal)) ixWIelValid += ImeIRMCommandMController::VecWIel::SREFIVRREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefRvrRefWdbeMSignal", "rvr", srefRvrRefWdbeMSignal)) ixWIelValid += ImeIRMCommandMController::VecWIel::SREFRVRREFWDBEMSIGNAL;
	};
};

void IexWdbeFin::ImeitemIRMCommandMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefRefWdbeMCommand << "\t" << srefIvrRefWdbeMSignal << "\t" << srefRvrRefWdbeMSignal << endl;
};

void IexWdbeFin::ImeitemIRMCommandMController::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cmd","ivr","rvr"};
	else tags = {"ImeitemIRMCommandMController","srefRefWdbeMCommand","srefIvrRefWdbeMSignal","srefRvrRefWdbeMSignal"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWdbeMCommand);
		writeString(wr, tags[2], srefIvrRefWdbeMSignal);
		writeString(wr, tags[3], srefRvrRefWdbeMSignal);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIRMCommandMController::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIRMCommandMController::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwdbemcommand") ix |= SREFREFWDBEMCOMMAND;
		else if (ss[i] == "srefivrrefwdbemsignal") ix |= SREFIVRREFWDBEMSIGNAL;
		else if (ss[i] == "srefrvrrefwdbemsignal") ix |= SREFRVRREFWDBEMSIGNAL;
	};

	return(ix);
};

void IexWdbeFin::ImeIRMCommandMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFRVRREFWDBEMSIGNAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIRMCommandMController::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWDBEMCOMMAND) ss.push_back("srefRefWdbeMCommand");
	if (ix & SREFIVRREFWDBEMSIGNAL) ss.push_back("srefIvrRefWdbeMSignal");
	if (ix & SREFRVRREFWDBEMSIGNAL) ss.push_back("srefRvrRefWdbeMSignal");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIRMCommandMController
 ******************************************************************************/

IexWdbeFin::ImeIRMCommandMController::ImeIRMCommandMController() {
};

IexWdbeFin::ImeIRMCommandMController::~ImeIRMCommandMController() {
	clear();
};

void IexWdbeFin::ImeIRMCommandMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIRMCommandMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIRMCommandMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIRMCommandMController();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCommandMController"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIRMCommandMController"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIRMCOMMANDMCONTROLLER) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCommandMController"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIRMCommandMController"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIRMCommandMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIRMCommandMController* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIRMCommandMController");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIRMCommandMController", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIRMCommandMController";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIRMCommandMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIRMCommandMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIRMCommandMController." << StrMod::replaceChar(ImeIRMCommandMController::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIRMCommandMController.end" << endl;
	};
};

void IexWdbeFin::ImeIRMCommandMController::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIRMCommandMController");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMController
 ******************************************************************************/

IexWdbeFin::ImeitemIMController::ImeitemIMController(
			const uint ixWdbeVIop
			, const string& srefClrRefWdbeMSignal
		) : WdbeMController() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWdbeVIop = ixWdbeVIop;
	this->srefClrRefWdbeMSignal = srefClrRefWdbeMSignal;
};

IexWdbeFin::ImeitemIMController::ImeitemIMController(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVIop
			, const ubigint ref
		) :
			ImeitemIMController(ixWdbeVIop)
		{
	WdbeMController* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcontroller->loadRecByRef(ref, &rec)) {
		refWdbeMModule = rec->refWdbeMModule;
		clrRefWdbeMSignal = rec->clrRefWdbeMSignal;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMController::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWdbeVIop = txtrd.fields[0]; ixWIelValid += ImeIMController::VecWIel::SREFIXWDBEVIOP;};
	if (txtrd.fields.size() > 1) {srefClrRefWdbeMSignal = txtrd.fields[1]; ixWIelValid += ImeIMController::VecWIel::SREFCLRREFWDBEMSIGNAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMCOMMAND)) {
					imeimcommand.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMERROR)) {
					imeimerror.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIRMCOMMANDMCONTROLLER)) {
					imeirmcommandmcontroller.readTxt(txtrd);
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

void IexWdbeFin::ImeitemIMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVIop", "iop", srefIxWdbeVIop)) ixWIelValid += ImeIMController::VecWIel::SREFIXWDBEVIOP;
		if (extractStringUclc(docctx, basexpath, "srefClrRefWdbeMSignal", "clr", srefClrRefWdbeMSignal)) ixWIelValid += ImeIMController::VecWIel::SREFCLRREFWDBEMSIGNAL;
		imeimcommand.readXML(docctx, basexpath);
		imeimerror.readXML(docctx, basexpath);
		imeirmcommandmcontroller.readXML(docctx, basexpath);
	};
};

void IexWdbeFin::ImeitemIMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << srefClrRefWdbeMSignal << endl;
	imeimcommand.writeTxt(outfile);
	imeimerror.writeTxt(outfile);
	imeirmcommandmcontroller.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIMController::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","clr"};
	else tags = {"ImeitemIMController","srefIxWdbeVIop","srefClrRefWdbeMSignal"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVIop::getSref(ixWdbeVIop));
		writeString(wr, tags[2], srefClrRefWdbeMSignal);
		imeimcommand.writeXML(wr, shorttags);
		imeimerror.writeXML(wr, shorttags);
		imeirmcommandmcontroller.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMController::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMController::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwdbeviop") ix |= SREFIXWDBEVIOP;
		else if (ss[i] == "srefclrrefwdbemsignal") ix |= SREFCLRREFWDBEMSIGNAL;
	};

	return(ix);
};

void IexWdbeFin::ImeIMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFCLRREFWDBEMSIGNAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMController::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWDBEVIOP) ss.push_back("srefIxWdbeVIop");
	if (ix & SREFCLRREFWDBEMSIGNAL) ss.push_back("srefClrRefWdbeMSignal");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMController
 ******************************************************************************/

IexWdbeFin::ImeIMController::ImeIMController() {
};

IexWdbeFin::ImeIMController::~ImeIMController() {
	clear();
};

void IexWdbeFin::ImeIMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemIMController();
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

void IexWdbeFin::ImeIMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMController* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMController." << StrMod::replaceChar(ImeIMController::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMController.end" << endl;
	};
};

void IexWdbeFin::ImeIMController::writeXML(
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
 class IexWdbeFin::ImeitemIMGeneric
 ******************************************************************************/

IexWdbeFin::ImeitemIMGeneric::ImeitemIMGeneric(
			const uint ixWdbeVIop
			, const ubigint irefRefWdbeCGeneric
			, const string& sref
			, const string& srefWdbeKHdltype
			, const usmallint Width
			, const string& Minmax
			, const string& Defval
			, const string& srcSrefWdbeMGeneric
			, const string& Comment
		) : WdbeMGeneric() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWdbeVIop = ixWdbeVIop;
	this->irefRefWdbeCGeneric = irefRefWdbeCGeneric;
	this->sref = sref;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Defval = Defval;
	this->srcSrefWdbeMGeneric = srcSrefWdbeMGeneric;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIMGeneric::ImeitemIMGeneric(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVIop
			, const ubigint ref
		) :
			ImeitemIMGeneric(ixWdbeVIop)
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
		srcSrefWdbeMGeneric = rec->srcSrefWdbeMGeneric;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMGeneric::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWdbeVIop = txtrd.fields[0]; ixWIelValid += ImeIMGeneric::VecWIel::SREFIXWDBEVIOP;};
	if (txtrd.fields.size() > 1) {irefRefWdbeCGeneric = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMGeneric::VecWIel::IREFREFWDBECGENERIC;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMGeneric::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {srefWdbeKHdltype = txtrd.fields[3]; ixWIelValid += ImeIMGeneric::VecWIel::SREFWDBEKHDLTYPE;};
	if (txtrd.fields.size() > 4) {Width = atoi(txtrd.fields[4].c_str()); ixWIelValid += ImeIMGeneric::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 5) {Minmax = txtrd.fields[5]; ixWIelValid += ImeIMGeneric::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 6) {Defval = txtrd.fields[6]; ixWIelValid += ImeIMGeneric::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 7) {srcSrefWdbeMGeneric = txtrd.fields[7]; ixWIelValid += ImeIMGeneric::VecWIel::SRCSREFWDBEMGENERIC;};
	if (txtrd.fields.size() > 8) {Comment = txtrd.fields[8]; ixWIelValid += ImeIMGeneric::VecWIel::COMMENT;};

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

void IexWdbeFin::ImeitemIMGeneric::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVIop", "iop", srefIxWdbeVIop)) ixWIelValid += ImeIMGeneric::VecWIel::SREFIXWDBEVIOP;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCGeneric", "clu", irefRefWdbeCGeneric)) ixWIelValid += ImeIMGeneric::VecWIel::IREFREFWDBECGENERIC;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMGeneric::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype)) ixWIelValid += ImeIMGeneric::VecWIel::SREFWDBEKHDLTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMGeneric::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMGeneric::VecWIel::MINMAX;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIMGeneric::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srcSrefWdbeMGeneric", "src", srcSrefWdbeMGeneric)) ixWIelValid += ImeIMGeneric::VecWIel::SRCSREFWDBEMGENERIC;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMGeneric::VecWIel::COMMENT;
	};
};

void IexWdbeFin::ImeitemIMGeneric::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << irefRefWdbeCGeneric << "\t" << sref << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Defval << "\t" << srcSrefWdbeMGeneric << "\t" << Comment << endl;
};

void IexWdbeFin::ImeitemIMGeneric::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","clu","srf","hty","wid","mmx","dfv","src","cmt"};
	else tags = {"ImeitemIMGeneric","srefIxWdbeVIop","irefRefWdbeCGeneric","sref","srefWdbeKHdltype","Width","Minmax","Defval","srcSrefWdbeMGeneric","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVIop::getSref(ixWdbeVIop));
		writeUbigint(wr, tags[2], irefRefWdbeCGeneric);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], srefWdbeKHdltype);
		writeUsmallint(wr, tags[5], Width);
		writeString(wr, tags[6], Minmax);
		writeString(wr, tags[7], Defval);
		writeString(wr, tags[8], srcSrefWdbeMGeneric);
		writeString(wr, tags[9], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMGeneric::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMGeneric::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwdbeviop") ix |= SREFIXWDBEVIOP;
		else if (ss[i] == "irefrefwdbecgeneric") ix |= IREFREFWDBECGENERIC;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefwdbekhdltype") ix |= SREFWDBEKHDLTYPE;
		else if (ss[i] == "width") ix |= WIDTH;
		else if (ss[i] == "minmax") ix |= MINMAX;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "srcsrefwdbemgeneric") ix |= SRCSREFWDBEMGENERIC;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIMGeneric::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMGeneric::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWDBEVIOP) ss.push_back("srefIxWdbeVIop");
	if (ix & IREFREFWDBECGENERIC) ss.push_back("irefRefWdbeCGeneric");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFWDBEKHDLTYPE) ss.push_back("srefWdbeKHdltype");
	if (ix & WIDTH) ss.push_back("Width");
	if (ix & MINMAX) ss.push_back("Minmax");
	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & SRCSREFWDBEMGENERIC) ss.push_back("srcSrefWdbeMGeneric");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMGeneric
 ******************************************************************************/

IexWdbeFin::ImeIMGeneric::ImeIMGeneric() {
};

IexWdbeFin::ImeIMGeneric::~ImeIMGeneric() {
	clear();
};

void IexWdbeFin::ImeIMGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMGeneric::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMGeneric* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemIMGeneric();
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

void IexWdbeFin::ImeIMGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMGeneric* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIMGeneric();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMGeneric::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMGeneric." << StrMod::replaceChar(ImeIMGeneric::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMGeneric.end" << endl;
	};
};

void IexWdbeFin::ImeIMGeneric::writeXML(
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
 class IexWdbeFin::ImeitemIMPort
 ******************************************************************************/

IexWdbeFin::ImeitemIMPort::ImeitemIMPort(
			const uint ixWdbeVIop
			, const ubigint irefRefWdbeCPort
			, const uint mdlIxVCat
			, const string& sref
			, const uint ixVDir
			, const string& srefWdbeKHdltype
			, const usmallint Width
			, const string& Minmax
			, const string& Defval
			, const string& cpiSrefWdbeMPin
			, const string& cprSrefWdbeMPort
			, const string& csiSrefWdbeMSignal
			, const string& Comment
		) : WdbeMPort() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWdbeVIop = ixWdbeVIop;
	this->irefRefWdbeCPort = irefRefWdbeCPort;
	this->mdlIxVCat = mdlIxVCat;
	this->sref = sref;
	this->ixVDir = ixVDir;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Defval = Defval;
	this->cpiSrefWdbeMPin = cpiSrefWdbeMPin;
	this->cprSrefWdbeMPort = cprSrefWdbeMPort;
	this->csiSrefWdbeMSignal = csiSrefWdbeMSignal;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIMPort::ImeitemIMPort(
			DbsWdbe* dbswdbe
			, const uint ixWdbeVIop
			, const ubigint ref
		) :
			ImeitemIMPort(ixWdbeVIop)
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
		cpiSrefWdbeMPin = rec->cpiSrefWdbeMPin;
		cprSrefWdbeMPort = rec->cprSrefWdbeMPort;
		csiSrefWdbeMSignal = rec->csiSrefWdbeMSignal;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMPort::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWdbeVIop = txtrd.fields[0]; ixWIelValid += ImeIMPort::VecWIel::SREFIXWDBEVIOP;};
	if (txtrd.fields.size() > 1) {irefRefWdbeCPort = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMPort::VecWIel::IREFREFWDBECPORT;};
	if (txtrd.fields.size() > 2) {srefMdlIxVCat = txtrd.fields[2]; ixWIelValid += ImeIMPort::VecWIel::SREFMDLIXVCAT;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMPort::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {srefIxVDir = txtrd.fields[4]; ixWIelValid += ImeIMPort::VecWIel::SREFIXVDIR;};
	if (txtrd.fields.size() > 5) {srefWdbeKHdltype = txtrd.fields[5]; ixWIelValid += ImeIMPort::VecWIel::SREFWDBEKHDLTYPE;};
	if (txtrd.fields.size() > 6) {Width = atoi(txtrd.fields[6].c_str()); ixWIelValid += ImeIMPort::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 7) {Minmax = txtrd.fields[7]; ixWIelValid += ImeIMPort::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 8) {Defval = txtrd.fields[8]; ixWIelValid += ImeIMPort::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 9) {cpiSrefWdbeMPin = txtrd.fields[9]; ixWIelValid += ImeIMPort::VecWIel::CPISREFWDBEMPIN;};
	if (txtrd.fields.size() > 10) {cprSrefWdbeMPort = txtrd.fields[10]; ixWIelValid += ImeIMPort::VecWIel::CPRSREFWDBEMPORT;};
	if (txtrd.fields.size() > 11) {csiSrefWdbeMSignal = txtrd.fields[11]; ixWIelValid += ImeIMPort::VecWIel::CSISREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 12) {Comment = txtrd.fields[12]; ixWIelValid += ImeIMPort::VecWIel::COMMENT;};

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

void IexWdbeFin::ImeitemIMPort::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVIop", "iop", srefIxWdbeVIop)) ixWIelValid += ImeIMPort::VecWIel::SREFIXWDBEVIOP;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCPort", "clu", irefRefWdbeCPort)) ixWIelValid += ImeIMPort::VecWIel::IREFREFWDBECPORT;
		if (extractStringUclc(docctx, basexpath, "srefMdlIxVCat", "mdc", srefMdlIxVCat)) ixWIelValid += ImeIMPort::VecWIel::SREFMDLIXVCAT;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPort::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVDir", "dir", srefIxVDir)) ixWIelValid += ImeIMPort::VecWIel::SREFIXVDIR;
		if (extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype)) ixWIelValid += ImeIMPort::VecWIel::SREFWDBEKHDLTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMPort::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMPort::VecWIel::MINMAX;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIMPort::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "cpiSrefWdbeMPin", "cpi", cpiSrefWdbeMPin)) ixWIelValid += ImeIMPort::VecWIel::CPISREFWDBEMPIN;
		if (extractStringUclc(docctx, basexpath, "cprSrefWdbeMPort", "cpr", cprSrefWdbeMPort)) ixWIelValid += ImeIMPort::VecWIel::CPRSREFWDBEMPORT;
		if (extractStringUclc(docctx, basexpath, "csiSrefWdbeMSignal", "csi", csiSrefWdbeMSignal)) ixWIelValid += ImeIMPort::VecWIel::CSISREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMPort::VecWIel::COMMENT;
	};
};

void IexWdbeFin::ImeitemIMPort::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << irefRefWdbeCPort << "\t" << VecWdbeVMPortMdlCat::getSref(mdlIxVCat) << "\t" << sref << "\t" << VecWdbeVMPortDir::getSref(ixVDir) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Defval << "\t" << cpiSrefWdbeMPin << "\t" << cprSrefWdbeMPort << "\t" << csiSrefWdbeMSignal << "\t" << Comment << endl;
};

void IexWdbeFin::ImeitemIMPort::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","clu","mdc","srf","dir","hty","wid","mmx","dfv","cpi","cpr","csi","cmt"};
	else tags = {"ImeitemIMPort","srefIxWdbeVIop","irefRefWdbeCPort","srefMdlIxVCat","sref","srefIxVDir","srefWdbeKHdltype","Width","Minmax","Defval","cpiSrefWdbeMPin","cprSrefWdbeMPort","csiSrefWdbeMSignal","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVIop::getSref(ixWdbeVIop));
		writeUbigint(wr, tags[2], irefRefWdbeCPort);
		writeString(wr, tags[3], VecWdbeVMPortMdlCat::getSref(mdlIxVCat));
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], VecWdbeVMPortDir::getSref(ixVDir));
		writeString(wr, tags[6], srefWdbeKHdltype);
		writeUsmallint(wr, tags[7], Width);
		writeString(wr, tags[8], Minmax);
		writeString(wr, tags[9], Defval);
		writeString(wr, tags[10], cpiSrefWdbeMPin);
		writeString(wr, tags[11], cprSrefWdbeMPort);
		writeString(wr, tags[12], csiSrefWdbeMSignal);
		writeString(wr, tags[13], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMPort::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMPort::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwdbeviop") ix |= SREFIXWDBEVIOP;
		else if (ss[i] == "irefrefwdbecport") ix |= IREFREFWDBECPORT;
		else if (ss[i] == "srefmdlixvcat") ix |= SREFMDLIXVCAT;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvdir") ix |= SREFIXVDIR;
		else if (ss[i] == "srefwdbekhdltype") ix |= SREFWDBEKHDLTYPE;
		else if (ss[i] == "width") ix |= WIDTH;
		else if (ss[i] == "minmax") ix |= MINMAX;
		else if (ss[i] == "defval") ix |= DEFVAL;
		else if (ss[i] == "cpisrefwdbempin") ix |= CPISREFWDBEMPIN;
		else if (ss[i] == "cprsrefwdbemport") ix |= CPRSREFWDBEMPORT;
		else if (ss[i] == "csisrefwdbemsignal") ix |= CSISREFWDBEMSIGNAL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIMPort::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMPort::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXWDBEVIOP) ss.push_back("srefIxWdbeVIop");
	if (ix & IREFREFWDBECPORT) ss.push_back("irefRefWdbeCPort");
	if (ix & SREFMDLIXVCAT) ss.push_back("srefMdlIxVCat");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVDIR) ss.push_back("srefIxVDir");
	if (ix & SREFWDBEKHDLTYPE) ss.push_back("srefWdbeKHdltype");
	if (ix & WIDTH) ss.push_back("Width");
	if (ix & MINMAX) ss.push_back("Minmax");
	if (ix & DEFVAL) ss.push_back("Defval");
	if (ix & CPISREFWDBEMPIN) ss.push_back("cpiSrefWdbeMPin");
	if (ix & CPRSREFWDBEMPORT) ss.push_back("cprSrefWdbeMPort");
	if (ix & CSISREFWDBEMSIGNAL) ss.push_back("csiSrefWdbeMSignal");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMPort
 ******************************************************************************/

IexWdbeFin::ImeIMPort::ImeIMPort() {
};

IexWdbeFin::ImeIMPort::~ImeIMPort() {
	clear();
};

void IexWdbeFin::ImeIMPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMPort::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMPort* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemIMPort();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeFin::ImeIMPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMPort* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIMPort();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMPort::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPort." << StrMod::replaceChar(ImeIMPort::VecWIel::getSrefs(8191), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPort.end" << endl;
	};
};

void IexWdbeFin::ImeIMPort::writeXML(
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
 class IexWdbeFin::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexWdbeFin::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			const string& Title
			, const string& Comment
		) : WdbeJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
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

void IexWdbeFin::ImeitemIJAVKeylistKey::readTxt(
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

void IexWdbeFin::ImeitemIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;
	};
};

void IexWdbeFin::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << Title << "\t" << Comment << endl;
};

void IexWdbeFin::ImeitemIJAVKeylistKey::writeXML(
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
 class IexWdbeFin::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIJAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIJAVKeylistKey::VecWIel::getSrefs(
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
 class IexWdbeFin::ImeIJAVKeylistKey
 ******************************************************************************/

IexWdbeFin::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexWdbeFin::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexWdbeFin::ImeIJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeFin::ImeitemIJAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
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

void IexWdbeFin::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIJAVKeylistKey* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIJAVKeylistKey.end" << endl;
	};
};

void IexWdbeFin::ImeIJAVKeylistKey::writeXML(
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
 class IexWdbeFin::ImeitemIAVKeylistKey
 ******************************************************************************/

IexWdbeFin::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

IexWdbeFin::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

void IexWdbeFin::ImeitemIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY)) {
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

void IexWdbeFin::ImeitemIAVKeylistKey::readXML(
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

void IexWdbeFin::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIAVKeylistKey::writeXML(
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
 class IexWdbeFin::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIAVKeylistKey::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "title") ix |= TITLE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIAVKeylistKey::VecWIel::getSrefs(
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
 class IexWdbeFin::ImeIAVKeylistKey
 ******************************************************************************/

IexWdbeFin::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexWdbeFin::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexWdbeFin::ImeIAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
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

void IexWdbeFin::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIAVKeylistKey* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAVKeylistKey.end" << endl;
	};
};

void IexWdbeFin::ImeIAVKeylistKey::writeXML(
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
 class IexWdbeFin::ImeitemICVariable2
 ******************************************************************************/

IexWdbeFin::ImeitemICVariable2::ImeitemICVariable2(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeFin::ImeitemICVariable2::ImeitemICVariable2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICVariable2()
		{
};

void IexWdbeFin::ImeitemICVariable2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICVariable2::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICVariable2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemICVariable2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICVariable2::VecWIel::IREF;
	};
};

void IexWdbeFin::ImeitemICVariable2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << iref << endl;
};

void IexWdbeFin::ImeitemICVariable2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICVariable2","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeICVariable2::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeICVariable2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeFin::ImeICVariable2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeICVariable2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeICVariable2
 ******************************************************************************/

IexWdbeFin::ImeICVariable2::ImeICVariable2() {
};

IexWdbeFin::ImeICVariable2::~ImeICVariable2() {
	clear();
};

void IexWdbeFin::ImeICVariable2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeICVariable2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemICVariable2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemICVariable2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICVariable2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICVariable2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICVARIABLE2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICVariable2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICVariable2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeICVariable2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemICVariable2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICVariable2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICVariable2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICVariable2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemICVariable2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeICVariable2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeICVariable2." << StrMod::replaceChar(ImeICVariable2::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeICVariable2.end" << endl;
	};
};

void IexWdbeFin::ImeICVariable2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICVariable2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemICFsmstate
 ******************************************************************************/

IexWdbeFin::ImeitemICFsmstate::ImeitemICFsmstate(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeFin::ImeitemICFsmstate::ImeitemICFsmstate(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICFsmstate()
		{
};

void IexWdbeFin::ImeitemICFsmstate::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICFsmstate::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICFsmstate"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemICFsmstate::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICFsmstate::VecWIel::IREF;
	};
};

void IexWdbeFin::ImeitemICFsmstate::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << iref << endl;
};

void IexWdbeFin::ImeitemICFsmstate::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICFsmstate","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeICFsmstate::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeICFsmstate::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "iref") ix |= IREF;
	};

	return(ix);
};

void IexWdbeFin::ImeICFsmstate::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeICFsmstate::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeICFsmstate
 ******************************************************************************/

IexWdbeFin::ImeICFsmstate::ImeICFsmstate() {
};

IexWdbeFin::ImeICFsmstate::~ImeICFsmstate() {
	clear();
};

void IexWdbeFin::ImeICFsmstate::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeICFsmstate::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemICFsmstate* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeFin::ImeitemICFsmstate();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICFsmstate"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICFsmstate"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICFSMSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICFsmstate"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICFsmstate"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeICFsmstate::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemICFsmstate* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICFsmstate");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICFsmstate", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICFsmstate";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemICFsmstate();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeICFsmstate::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeICFsmstate." << StrMod::replaceChar(ImeICFsmstate::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeICFsmstate.end" << endl;
	};
};

void IexWdbeFin::ImeICFsmstate::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICFsmstate");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIAMFsmstateStep
 ******************************************************************************/

IexWdbeFin::ImeitemIAMFsmstateStep::ImeitemIAMFsmstateStep(
			const string& srefFnxRefWdbeMFsmstate
			, const string& Cond1
			, const string& Ip1
			, const string& Cond2
			, const string& Ip2
			, const string& Cond3
			, const string& Ip3
			, const string& Cond4
			, const string& Ip4
			, const string& Cond5
			, const string& Ip5
			, const string& Cond6
			, const string& Ip6
		) : WdbeAMFsmstateStep() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefFnxRefWdbeMFsmstate = srefFnxRefWdbeMFsmstate;
	this->Cond1 = Cond1;
	this->Ip1 = Ip1;
	this->Cond2 = Cond2;
	this->Ip2 = Ip2;
	this->Cond3 = Cond3;
	this->Ip3 = Ip3;
	this->Cond4 = Cond4;
	this->Ip4 = Ip4;
	this->Cond5 = Cond5;
	this->Ip5 = Ip5;
	this->Cond6 = Cond6;
	this->Ip6 = Ip6;
};

IexWdbeFin::ImeitemIAMFsmstateStep::ImeitemIAMFsmstateStep(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMFsmstateStep()
		{
	WdbeAMFsmstateStep* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamfsmstatestep->loadRecByRef(ref, &rec)) {
		fstRefWdbeMFsmstate = rec->fstRefWdbeMFsmstate;
		fstNum = rec->fstNum;
		fnxRefWdbeMFsmstate = rec->fnxRefWdbeMFsmstate;
		Cond1 = rec->Cond1;
		Ip1 = rec->Ip1;
		Cond2 = rec->Cond2;
		Ip2 = rec->Ip2;
		Cond3 = rec->Cond3;
		Ip3 = rec->Ip3;
		Cond4 = rec->Cond4;
		Ip4 = rec->Ip4;
		Cond5 = rec->Cond5;
		Ip5 = rec->Ip5;
		Cond6 = rec->Cond6;
		Ip6 = rec->Ip6;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIAMFsmstateStep::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefFnxRefWdbeMFsmstate = txtrd.fields[0]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::SREFFNXREFWDBEMFSMSTATE;};
	if (txtrd.fields.size() > 1) {Cond1 = txtrd.fields[1]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND1;};
	if (txtrd.fields.size() > 2) {Ip1 = txtrd.fields[2]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP1;};
	if (txtrd.fields.size() > 3) {Cond2 = txtrd.fields[3]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND2;};
	if (txtrd.fields.size() > 4) {Ip2 = txtrd.fields[4]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP2;};
	if (txtrd.fields.size() > 5) {Cond3 = txtrd.fields[5]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND3;};
	if (txtrd.fields.size() > 6) {Ip3 = txtrd.fields[6]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP3;};
	if (txtrd.fields.size() > 7) {Cond4 = txtrd.fields[7]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND4;};
	if (txtrd.fields.size() > 8) {Ip4 = txtrd.fields[8]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP4;};
	if (txtrd.fields.size() > 9) {Cond5 = txtrd.fields[9]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND5;};
	if (txtrd.fields.size() > 10) {Ip5 = txtrd.fields[10]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP5;};
	if (txtrd.fields.size() > 11) {Cond6 = txtrd.fields[11]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND6;};
	if (txtrd.fields.size() > 12) {Ip6 = txtrd.fields[12]; ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP6;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMFsmstateStep"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIAMFsmstateStep::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefFnxRefWdbeMFsmstate", "fnx", srefFnxRefWdbeMFsmstate)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::SREFFNXREFWDBEMFSMSTATE;
		if (extractStringUclc(docctx, basexpath, "Cond1", "cn1", Cond1)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND1;
		if (extractStringUclc(docctx, basexpath, "Ip1", "ip1", Ip1)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP1;
		if (extractStringUclc(docctx, basexpath, "Cond2", "cn2", Cond2)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND2;
		if (extractStringUclc(docctx, basexpath, "Ip2", "ip2", Ip2)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP2;
		if (extractStringUclc(docctx, basexpath, "Cond3", "cn3", Cond3)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND3;
		if (extractStringUclc(docctx, basexpath, "Ip3", "ip3", Ip3)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP3;
		if (extractStringUclc(docctx, basexpath, "Cond4", "cn4", Cond4)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND4;
		if (extractStringUclc(docctx, basexpath, "Ip4", "ip4", Ip4)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP4;
		if (extractStringUclc(docctx, basexpath, "Cond5", "cn5", Cond5)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND5;
		if (extractStringUclc(docctx, basexpath, "Ip5", "ip5", Ip5)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP5;
		if (extractStringUclc(docctx, basexpath, "Cond6", "cn6", Cond6)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::COND6;
		if (extractStringUclc(docctx, basexpath, "Ip6", "ip6", Ip6)) ixWIelValid += ImeIAMFsmstateStep::VecWIel::IP6;
	};
};

void IexWdbeFin::ImeitemIAMFsmstateStep::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t\t" << srefFnxRefWdbeMFsmstate << "\t" << Cond1 << "\t" << Ip1 << "\t" << Cond2 << "\t" << Ip2 << "\t" << Cond3 << "\t" << Ip3 << "\t" << Cond4 << "\t" << Ip4 << "\t" << Cond5 << "\t" << Ip5 << "\t" << Cond6 << "\t" << Ip6 << endl;
};

void IexWdbeFin::ImeitemIAMFsmstateStep::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","fnx","cn1","ip1","cn2","ip2","cn3","ip3","cn4","ip4","cn5","ip5","cn6","ip6"};
	else tags = {"ImeitemIAMFsmstateStep","srefFnxRefWdbeMFsmstate","Cond1","Ip1","Cond2","Ip2","Cond3","Ip3","Cond4","Ip4","Cond5","Ip5","Cond6","Ip6"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefFnxRefWdbeMFsmstate);
		writeString(wr, tags[2], Cond1);
		writeString(wr, tags[3], Ip1);
		writeString(wr, tags[4], Cond2);
		writeString(wr, tags[5], Ip2);
		writeString(wr, tags[6], Cond3);
		writeString(wr, tags[7], Ip3);
		writeString(wr, tags[8], Cond4);
		writeString(wr, tags[9], Ip4);
		writeString(wr, tags[10], Cond5);
		writeString(wr, tags[11], Ip5);
		writeString(wr, tags[12], Cond6);
		writeString(wr, tags[13], Ip6);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIAMFsmstateStep::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIAMFsmstateStep::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sreffnxrefwdbemfsmstate") ix |= SREFFNXREFWDBEMFSMSTATE;
		else if (ss[i] == "cond1") ix |= COND1;
		else if (ss[i] == "ip1") ix |= IP1;
		else if (ss[i] == "cond2") ix |= COND2;
		else if (ss[i] == "ip2") ix |= IP2;
		else if (ss[i] == "cond3") ix |= COND3;
		else if (ss[i] == "ip3") ix |= IP3;
		else if (ss[i] == "cond4") ix |= COND4;
		else if (ss[i] == "ip4") ix |= IP4;
		else if (ss[i] == "cond5") ix |= COND5;
		else if (ss[i] == "ip5") ix |= IP5;
		else if (ss[i] == "cond6") ix |= COND6;
		else if (ss[i] == "ip6") ix |= IP6;
	};

	return(ix);
};

void IexWdbeFin::ImeIAMFsmstateStep::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IP6); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIAMFsmstateStep::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFFNXREFWDBEMFSMSTATE) ss.push_back("srefFnxRefWdbeMFsmstate");
	if (ix & COND1) ss.push_back("Cond1");
	if (ix & IP1) ss.push_back("Ip1");
	if (ix & COND2) ss.push_back("Cond2");
	if (ix & IP2) ss.push_back("Ip2");
	if (ix & COND3) ss.push_back("Cond3");
	if (ix & IP3) ss.push_back("Ip3");
	if (ix & COND4) ss.push_back("Cond4");
	if (ix & IP4) ss.push_back("Ip4");
	if (ix & COND5) ss.push_back("Cond5");
	if (ix & IP5) ss.push_back("Ip5");
	if (ix & COND6) ss.push_back("Cond6");
	if (ix & IP6) ss.push_back("Ip6");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIAMFsmstateStep
 ******************************************************************************/

IexWdbeFin::ImeIAMFsmstateStep::ImeIAMFsmstateStep() {
};

IexWdbeFin::ImeIAMFsmstateStep::~ImeIAMFsmstateStep() {
	clear();
};

void IexWdbeFin::ImeIAMFsmstateStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIAMFsmstateStep::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIAMFsmstateStep* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 5) {
					ii = new IexWdbeFin::ImeitemIAMFsmstateStep();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 5) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMFsmstateStep"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMFsmstateStep"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMFSMSTATESTEP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMFsmstateStep"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMFsmstateStep"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIAMFsmstateStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIAMFsmstateStep* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMFsmstateStep");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMFsmstateStep", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMFsmstateStep";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIAMFsmstateStep();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIAMFsmstateStep::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\t\tImeIAMFsmstateStep." << StrMod::replaceChar(ImeIAMFsmstateStep::VecWIel::getSrefs(8191), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\t\tImeIAMFsmstateStep.end" << endl;
	};
};

void IexWdbeFin::ImeIAMFsmstateStep::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMFsmstateStep");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMFsmstate
 ******************************************************************************/

IexWdbeFin::ImeitemIMFsmstate::ImeitemIMFsmstate(
			const ubigint irefRefWdbeCFsmstate
			, const string& sref
			, const bool Extip
			, const string& Comment
		) : WdbeMFsmstate() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWdbeCFsmstate = irefRefWdbeCFsmstate;
	this->sref = sref;
	this->Extip = Extip;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIMFsmstate::ImeitemIMFsmstate(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMFsmstate()
		{
	WdbeMFsmstate* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemfsmstate->loadRecByRef(ref, &rec)) {
		refWdbeCFsmstate = rec->refWdbeCFsmstate;
		fsmRefWdbeMFsm = rec->fsmRefWdbeMFsm;
		fsmNum = rec->fsmNum;
		sref = rec->sref;
		Extip = rec->Extip;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMFsmstate::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWdbeCFsmstate = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMFsmstate::VecWIel::IREFREFWDBECFSMSTATE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMFsmstate::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Extip = (txtrd.fields[2] == "true"); ixWIelValid += ImeIMFsmstate::VecWIel::EXTIP;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMFsmstate::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 5) && (txtrd.ixVToken == VecVIme::IMEIAMFSMSTATESTEP)) {
					imeiamfsmstatestep.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFsmstate"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMFsmstate::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCFsmstate", "clu", irefRefWdbeCFsmstate)) ixWIelValid += ImeIMFsmstate::VecWIel::IREFREFWDBECFSMSTATE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMFsmstate::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Extip", "eip", Extip)) ixWIelValid += ImeIMFsmstate::VecWIel::EXTIP;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMFsmstate::VecWIel::COMMENT;
		imeiamfsmstatestep.readXML(docctx, basexpath);
	};
};

void IexWdbeFin::ImeitemIMFsmstate::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << irefRefWdbeCFsmstate << "\t" << sref << "\t" << StrMod::boolToString(Extip) << "\t" << Comment << endl;
	imeiamfsmstatestep.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIMFsmstate::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","eip","cmt"};
	else tags = {"ImeitemIMFsmstate","irefRefWdbeCFsmstate","sref","Extip","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWdbeCFsmstate);
		writeString(wr, tags[2], sref);
		writeBool(wr, tags[3], Extip);
		writeString(wr, tags[4], Comment);
		imeiamfsmstatestep.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMFsmstate::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMFsmstate::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwdbecfsmstate") ix |= IREFREFWDBECFSMSTATE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "extip") ix |= EXTIP;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIMFsmstate::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMFsmstate::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWDBECFSMSTATE) ss.push_back("irefRefWdbeCFsmstate");
	if (ix & SREF) ss.push_back("sref");
	if (ix & EXTIP) ss.push_back("Extip");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMFsmstate
 ******************************************************************************/

IexWdbeFin::ImeIMFsmstate::ImeIMFsmstate() {
};

IexWdbeFin::ImeIMFsmstate::~ImeIMFsmstate() {
	clear();
};

void IexWdbeFin::ImeIMFsmstate::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMFsmstate::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMFsmstate* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeFin::ImeitemIMFsmstate();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFsmstate"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFsmstate"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFSMSTATE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFsmstate"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFsmstate"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMFsmstate::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMFsmstate* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFsmstate");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFsmstate", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFsmstate";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMFsmstate();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMFsmstate::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIMFsmstate." << StrMod::replaceChar(ImeIMFsmstate::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIMFsmstate.end" << endl;
	};
};

void IexWdbeFin::ImeIMFsmstate::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFsmstate");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMFsm
 ******************************************************************************/

IexWdbeFin::ImeitemIMFsm::ImeitemIMFsm(
			const uint ixVDbgtaptype
		) : WdbeMFsm() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVDbgtaptype = ixVDbgtaptype;
};

IexWdbeFin::ImeitemIMFsm::ImeitemIMFsm(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMFsm()
		{
	WdbeMFsm* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemfsm->loadRecByRef(ref, &rec)) {
		refWdbeMProcess = rec->refWdbeMProcess;
		ixVDbgtaptype = rec->ixVDbgtaptype;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMFsm::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVDbgtaptype = txtrd.fields[0]; ixWIelValid += ImeIMFsm::VecWIel::SREFIXVDBGTAPTYPE;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEICFSMSTATE)) {
					imeicfsmstate.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIMFSMSTATE)) {
					imeimfsmstate.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFsm"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMFsm::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVDbgtaptype", "dtt", srefIxVDbgtaptype)) ixWIelValid += ImeIMFsm::VecWIel::SREFIXVDBGTAPTYPE;
		imeicfsmstate.readXML(docctx, basexpath);
		imeimfsmstate.readXML(docctx, basexpath);
	};
};

void IexWdbeFin::ImeitemIMFsm::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWdbeVMFsmDbgtaptype::getSref(ixVDbgtaptype) << endl;
	imeicfsmstate.writeTxt(outfile);
	imeimfsmstate.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIMFsm::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","dtt"};
	else tags = {"ImeitemIMFsm","srefIxVDbgtaptype"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMFsmDbgtaptype::getSref(ixVDbgtaptype));
		imeicfsmstate.writeXML(wr, shorttags);
		imeimfsmstate.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMFsm::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMFsm::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvdbgtaptype") ix |= SREFIXVDBGTAPTYPE;
	};

	return(ix);
};

void IexWdbeFin::ImeIMFsm::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFIXVDBGTAPTYPE); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMFsm::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVDBGTAPTYPE) ss.push_back("srefIxVDbgtaptype");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMFsm
 ******************************************************************************/

IexWdbeFin::ImeIMFsm::ImeIMFsm() {
};

IexWdbeFin::ImeIMFsm::~ImeIMFsm() {
	clear();
};

void IexWdbeFin::ImeIMFsm::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMFsm::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMFsm* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIMFsm();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFsm"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMFsm"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMFSM) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFsm"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMFsm"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMFsm::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMFsm* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMFsm");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMFsm", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMFsm";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMFsm();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMFsm::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMFsm." << StrMod::replaceChar(ImeIMFsm::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMFsm.end" << endl;
	};
};

void IexWdbeFin::ImeIMFsm::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMFsm");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMSensitivity2
 ******************************************************************************/

IexWdbeFin::ImeitemIMSensitivity2::ImeitemIMSensitivity2(
			const uint srcIxVTbl
			, const string& srefSrcUref
		) : WdbeMSensitivity() {
	lineno = 0;
	ixWIelValid = 0;

	this->srcIxVTbl = srcIxVTbl;
	this->srefSrcUref = srefSrcUref;
};

IexWdbeFin::ImeitemIMSensitivity2::ImeitemIMSensitivity2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMSensitivity2()
		{
	WdbeMSensitivity* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemsensitivity->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		srcIxVTbl = rec->srcIxVTbl;
		srcUref = rec->srcUref;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMSensitivity2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefSrcIxVTbl = txtrd.fields[0]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFSRCIXVTBL;};
	if (txtrd.fields.size() > 1) {srefSrcUref = txtrd.fields[1]; ixWIelValid += ImeIMSensitivity2::VecWIel::SREFSRCUREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMSensitivity2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefSrcIxVTbl", "srt", srefSrcIxVTbl)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFSRCIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefSrcUref", "sru", srefSrcUref)) ixWIelValid += ImeIMSensitivity2::VecWIel::SREFSRCUREF;
	};
};

void IexWdbeFin::ImeitemIMSensitivity2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWdbeVMSensitivitySrcTbl::getSref(srcIxVTbl) << "\t" << srefSrcUref << endl;
};

void IexWdbeFin::ImeitemIMSensitivity2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srt","sru"};
	else tags = {"ImeitemIMSensitivity2","srefSrcIxVTbl","srefSrcUref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMSensitivitySrcTbl::getSref(srcIxVTbl));
		writeString(wr, tags[2], srefSrcUref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMSensitivity2::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMSensitivity2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefsrcixvtbl") ix |= SREFSRCIXVTBL;
		else if (ss[i] == "srefsrcuref") ix |= SREFSRCUREF;
	};

	return(ix);
};

void IexWdbeFin::ImeIMSensitivity2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSRCUREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMSensitivity2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSRCIXVTBL) ss.push_back("srefSrcIxVTbl");
	if (ix & SREFSRCUREF) ss.push_back("srefSrcUref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMSensitivity2
 ******************************************************************************/

IexWdbeFin::ImeIMSensitivity2::ImeIMSensitivity2() {
};

IexWdbeFin::ImeIMSensitivity2::~ImeIMSensitivity2() {
	clear();
};

void IexWdbeFin::ImeIMSensitivity2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMSensitivity2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMSensitivity2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIMSensitivity2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSENSITIVITY2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMSensitivity2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMSensitivity2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSensitivity2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSensitivity2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSensitivity2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMSensitivity2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMSensitivity2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMSensitivity2." << StrMod::replaceChar(ImeIMSensitivity2::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMSensitivity2.end" << endl;
	};
};

void IexWdbeFin::ImeIMSensitivity2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSensitivity2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMVariable2
 ******************************************************************************/

IexWdbeFin::ImeitemIMVariable2::ImeitemIMVariable2(
			const ubigint irefRefWdbeCVariable
			, const string& sref
			, const bool Const
			, const bool Falling
			, const string& srefWdbeKHdltype
			, const usmallint Width
			, const string& Minmax
			, const string& Onval
			, const string& Offval
			, const string& Comment
		) : WdbeMVariable() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWdbeCVariable = irefRefWdbeCVariable;
	this->sref = sref;
	this->Const = Const;
	this->Falling = Falling;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Onval = Onval;
	this->Offval = Offval;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIMVariable2::ImeitemIMVariable2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVariable2()
		{
	WdbeMVariable* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemvariable->loadRecByRef(ref, &rec)) {
		refWdbeCVariable = rec->refWdbeCVariable;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		sref = rec->sref;
		Const = rec->Const;
		Falling = rec->Falling;
		srefWdbeKHdltype = rec->srefWdbeKHdltype;
		Width = rec->Width;
		Minmax = rec->Minmax;
		Onval = rec->Onval;
		Offval = rec->Offval;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMVariable2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWdbeCVariable = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMVariable2::VecWIel::IREFREFWDBECVARIABLE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVariable2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Const = (txtrd.fields[2] == "true"); ixWIelValid += ImeIMVariable2::VecWIel::CONST;};
	if (txtrd.fields.size() > 3) {Falling = (txtrd.fields[3] == "true"); ixWIelValid += ImeIMVariable2::VecWIel::FALLING;};
	if (txtrd.fields.size() > 4) {srefWdbeKHdltype = txtrd.fields[4]; ixWIelValid += ImeIMVariable2::VecWIel::SREFWDBEKHDLTYPE;};
	if (txtrd.fields.size() > 5) {Width = atoi(txtrd.fields[5].c_str()); ixWIelValid += ImeIMVariable2::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 6) {Minmax = txtrd.fields[6]; ixWIelValid += ImeIMVariable2::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 7) {Onval = txtrd.fields[7]; ixWIelValid += ImeIMVariable2::VecWIel::ONVAL;};
	if (txtrd.fields.size() > 8) {Offval = txtrd.fields[8]; ixWIelValid += ImeIMVariable2::VecWIel::OFFVAL;};
	if (txtrd.fields.size() > 9) {Comment = txtrd.fields[9]; ixWIelValid += ImeIMVariable2::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVariable2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMVariable2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCVariable", "clu", irefRefWdbeCVariable)) ixWIelValid += ImeIMVariable2::VecWIel::IREFREFWDBECVARIABLE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVariable2::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Const", "con", Const)) ixWIelValid += ImeIMVariable2::VecWIel::CONST;
		if (extractBoolUclc(docctx, basexpath, "Falling", "fal", Falling)) ixWIelValid += ImeIMVariable2::VecWIel::FALLING;
		if (extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype)) ixWIelValid += ImeIMVariable2::VecWIel::SREFWDBEKHDLTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMVariable2::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMVariable2::VecWIel::MINMAX;
		if (extractStringUclc(docctx, basexpath, "Onval", "onv", Onval)) ixWIelValid += ImeIMVariable2::VecWIel::ONVAL;
		if (extractStringUclc(docctx, basexpath, "Offval", "ofv", Offval)) ixWIelValid += ImeIMVariable2::VecWIel::OFFVAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVariable2::VecWIel::COMMENT;
	};
};

void IexWdbeFin::ImeitemIMVariable2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << irefRefWdbeCVariable << "\t" << sref << "\t" << StrMod::boolToString(Const) << "\t" << StrMod::boolToString(Falling) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Onval << "\t" << Offval << "\t" << Comment << endl;
};

void IexWdbeFin::ImeitemIMVariable2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","con","fal","hty","wid","mmx","onv","ofv","cmt"};
	else tags = {"ImeitemIMVariable2","irefRefWdbeCVariable","sref","Const","Falling","srefWdbeKHdltype","Width","Minmax","Onval","Offval","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWdbeCVariable);
		writeString(wr, tags[2], sref);
		writeBool(wr, tags[3], Const);
		writeBool(wr, tags[4], Falling);
		writeString(wr, tags[5], srefWdbeKHdltype);
		writeUsmallint(wr, tags[6], Width);
		writeString(wr, tags[7], Minmax);
		writeString(wr, tags[8], Onval);
		writeString(wr, tags[9], Offval);
		writeString(wr, tags[10], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMVariable2::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMVariable2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwdbecvariable") ix |= IREFREFWDBECVARIABLE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "const") ix |= CONST;
		else if (ss[i] == "falling") ix |= FALLING;
		else if (ss[i] == "srefwdbekhdltype") ix |= SREFWDBEKHDLTYPE;
		else if (ss[i] == "width") ix |= WIDTH;
		else if (ss[i] == "minmax") ix |= MINMAX;
		else if (ss[i] == "onval") ix |= ONVAL;
		else if (ss[i] == "offval") ix |= OFFVAL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIMVariable2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMVariable2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWDBECVARIABLE) ss.push_back("irefRefWdbeCVariable");
	if (ix & SREF) ss.push_back("sref");
	if (ix & CONST) ss.push_back("Const");
	if (ix & FALLING) ss.push_back("Falling");
	if (ix & SREFWDBEKHDLTYPE) ss.push_back("srefWdbeKHdltype");
	if (ix & WIDTH) ss.push_back("Width");
	if (ix & MINMAX) ss.push_back("Minmax");
	if (ix & ONVAL) ss.push_back("Onval");
	if (ix & OFFVAL) ss.push_back("Offval");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMVariable2
 ******************************************************************************/

IexWdbeFin::ImeIMVariable2::ImeIMVariable2() {
};

IexWdbeFin::ImeIMVariable2::~ImeIMVariable2() {
	clear();
};

void IexWdbeFin::ImeIMVariable2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMVariable2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMVariable2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeFin::ImeitemIMVariable2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVariable2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVariable2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVARIABLE2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVariable2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVariable2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMVariable2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMVariable2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVariable2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVariable2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVariable2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMVariable2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMVariable2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMVariable2." << StrMod::replaceChar(ImeIMVariable2::VecWIel::getSrefs(1023), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMVariable2.end" << endl;
	};
};

void IexWdbeFin::ImeIMVariable2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVariable2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMProcess
 ******************************************************************************/

IexWdbeFin::ImeitemIMProcess::ImeitemIMProcess(
			const string& sref
			, const string& clkSrefWdbeMSignal
			, const string& asrSrefWdbeMSignal
			, const bool Falling
			, const string& Syncrst
			, const bool Extip
			, const string& Comment
		) : WdbeMProcess() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->clkSrefWdbeMSignal = clkSrefWdbeMSignal;
	this->asrSrefWdbeMSignal = asrSrefWdbeMSignal;
	this->Falling = Falling;
	this->Syncrst = Syncrst;
	this->Extip = Extip;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIMProcess::ImeitemIMProcess(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMProcess()
		{
	WdbeMProcess* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemprocess->loadRecByRef(ref, &rec)) {
		refWdbeMModule = rec->refWdbeMModule;
		refWdbeMFsm = rec->refWdbeMFsm;
		sref = rec->sref;
		clkSrefWdbeMSignal = rec->clkSrefWdbeMSignal;
		asrSrefWdbeMSignal = rec->asrSrefWdbeMSignal;
		Falling = rec->Falling;
		Syncrst = rec->Syncrst;
		Extip = rec->Extip;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMProcess::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMProcess::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {clkSrefWdbeMSignal = txtrd.fields[1]; ixWIelValid += ImeIMProcess::VecWIel::CLKSREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 2) {asrSrefWdbeMSignal = txtrd.fields[2]; ixWIelValid += ImeIMProcess::VecWIel::ASRSREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 3) {Falling = (txtrd.fields[3] == "true"); ixWIelValid += ImeIMProcess::VecWIel::FALLING;};
	if (txtrd.fields.size() > 4) {Syncrst = txtrd.fields[4]; ixWIelValid += ImeIMProcess::VecWIel::SYNCRST;};
	if (txtrd.fields.size() > 5) {Extip = (txtrd.fields[5] == "true"); ixWIelValid += ImeIMProcess::VecWIel::EXTIP;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMProcess::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY)) {
					imeiavkeylistkey.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEICVARIABLE2)) {
					imeicvariable2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMFSM)) {
					imeimfsm.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMSENSITIVITY2)) {
					imeimsensitivity2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMVARIABLE2)) {
					imeimvariable2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMProcess"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMProcess::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMProcess::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "clkSrefWdbeMSignal", "clk", clkSrefWdbeMSignal)) ixWIelValid += ImeIMProcess::VecWIel::CLKSREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "asrSrefWdbeMSignal", "asr", asrSrefWdbeMSignal)) ixWIelValid += ImeIMProcess::VecWIel::ASRSREFWDBEMSIGNAL;
		if (extractBoolUclc(docctx, basexpath, "Falling", "fal", Falling)) ixWIelValid += ImeIMProcess::VecWIel::FALLING;
		if (extractStringUclc(docctx, basexpath, "Syncrst", "snr", Syncrst)) ixWIelValid += ImeIMProcess::VecWIel::SYNCRST;
		if (extractBoolUclc(docctx, basexpath, "Extip", "eip", Extip)) ixWIelValid += ImeIMProcess::VecWIel::EXTIP;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMProcess::VecWIel::COMMENT;
		imeiavkeylistkey.readXML(docctx, basexpath);
		imeicvariable2.readXML(docctx, basexpath);
		imeimfsm.readXML(docctx, basexpath);
		imeimsensitivity2.readXML(docctx, basexpath);
		imeimvariable2.readXML(docctx, basexpath);
	};
};

void IexWdbeFin::ImeitemIMProcess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << clkSrefWdbeMSignal << "\t" << asrSrefWdbeMSignal << "\t" << StrMod::boolToString(Falling) << "\t" << Syncrst << "\t" << StrMod::boolToString(Extip) << "\t" << Comment << endl;
	imeiavkeylistkey.writeTxt(outfile);
	imeicvariable2.writeTxt(outfile);
	imeimfsm.writeTxt(outfile);
	imeimsensitivity2.writeTxt(outfile);
	imeimvariable2.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIMProcess::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","clk","asr","fal","snr","eip","cmt"};
	else tags = {"ImeitemIMProcess","sref","clkSrefWdbeMSignal","asrSrefWdbeMSignal","Falling","Syncrst","Extip","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], clkSrefWdbeMSignal);
		writeString(wr, tags[3], asrSrefWdbeMSignal);
		writeBool(wr, tags[4], Falling);
		writeString(wr, tags[5], Syncrst);
		writeBool(wr, tags[6], Extip);
		writeString(wr, tags[7], Comment);
		imeiavkeylistkey.writeXML(wr, shorttags);
		imeicvariable2.writeXML(wr, shorttags);
		imeimfsm.writeXML(wr, shorttags);
		imeimsensitivity2.writeXML(wr, shorttags);
		imeimvariable2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMProcess::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMProcess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "clksrefwdbemsignal") ix |= CLKSREFWDBEMSIGNAL;
		else if (ss[i] == "asrsrefwdbemsignal") ix |= ASRSREFWDBEMSIGNAL;
		else if (ss[i] == "falling") ix |= FALLING;
		else if (ss[i] == "syncrst") ix |= SYNCRST;
		else if (ss[i] == "extip") ix |= EXTIP;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIMProcess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMProcess::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & CLKSREFWDBEMSIGNAL) ss.push_back("clkSrefWdbeMSignal");
	if (ix & ASRSREFWDBEMSIGNAL) ss.push_back("asrSrefWdbeMSignal");
	if (ix & FALLING) ss.push_back("Falling");
	if (ix & SYNCRST) ss.push_back("Syncrst");
	if (ix & EXTIP) ss.push_back("Extip");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMProcess
 ******************************************************************************/

IexWdbeFin::ImeIMProcess::ImeIMProcess() {
};

IexWdbeFin::ImeIMProcess::~ImeIMProcess() {
	clear();
};

void IexWdbeFin::ImeIMProcess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMProcess::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMProcess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemIMProcess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMProcess"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMProcess"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPROCESS) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMProcess"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMProcess"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMProcess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMProcess* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMProcess");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMProcess", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMProcess";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMProcess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMProcess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMProcess." << StrMod::replaceChar(ImeIMProcess::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMProcess.end" << endl;
	};
};

void IexWdbeFin::ImeIMProcess::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMProcess");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMSensitivity1
 ******************************************************************************/

IexWdbeFin::ImeitemIMSensitivity1::ImeitemIMSensitivity1(
			const uint srcIxVTbl
			, const string& srefSrcUref
		) : WdbeMSensitivity() {
	lineno = 0;
	ixWIelValid = 0;

	this->srcIxVTbl = srcIxVTbl;
	this->srefSrcUref = srefSrcUref;
};

IexWdbeFin::ImeitemIMSensitivity1::ImeitemIMSensitivity1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMSensitivity1()
		{
	WdbeMSensitivity* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemsensitivity->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		srcIxVTbl = rec->srcIxVTbl;
		srcUref = rec->srcUref;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMSensitivity1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefSrcIxVTbl = txtrd.fields[0]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFSRCIXVTBL;};
	if (txtrd.fields.size() > 1) {srefSrcUref = txtrd.fields[1]; ixWIelValid += ImeIMSensitivity1::VecWIel::SREFSRCUREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMSensitivity1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefSrcIxVTbl", "srt", srefSrcIxVTbl)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFSRCIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefSrcUref", "sru", srefSrcUref)) ixWIelValid += ImeIMSensitivity1::VecWIel::SREFSRCUREF;
	};
};

void IexWdbeFin::ImeitemIMSensitivity1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMSensitivitySrcTbl::getSref(srcIxVTbl) << "\t" << srefSrcUref << endl;
};

void IexWdbeFin::ImeitemIMSensitivity1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srt","sru"};
	else tags = {"ImeitemIMSensitivity1","srefSrcIxVTbl","srefSrcUref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMSensitivitySrcTbl::getSref(srcIxVTbl));
		writeString(wr, tags[2], srefSrcUref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMSensitivity1::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMSensitivity1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefsrcixvtbl") ix |= SREFSRCIXVTBL;
		else if (ss[i] == "srefsrcuref") ix |= SREFSRCUREF;
	};

	return(ix);
};

void IexWdbeFin::ImeIMSensitivity1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSRCUREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMSensitivity1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFSRCIXVTBL) ss.push_back("srefSrcIxVTbl");
	if (ix & SREFSRCUREF) ss.push_back("srefSrcUref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMSensitivity1
 ******************************************************************************/

IexWdbeFin::ImeIMSensitivity1::ImeIMSensitivity1() {
};

IexWdbeFin::ImeIMSensitivity1::~ImeIMSensitivity1() {
	clear();
};

void IexWdbeFin::ImeIMSensitivity1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMSensitivity1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMSensitivity1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemIMSensitivity1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSENSITIVITY1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSensitivity1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMSensitivity1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMSensitivity1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSensitivity1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSensitivity1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSensitivity1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMSensitivity1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMSensitivity1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMSensitivity1." << StrMod::replaceChar(ImeIMSensitivity1::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMSensitivity1.end" << endl;
	};
};

void IexWdbeFin::ImeIMSensitivity1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSensitivity1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMSignal2
 ******************************************************************************/

IexWdbeFin::ImeitemIMSignal2::ImeitemIMSignal2(
			const uint ixVBasetype
			, const ubigint irefRefWdbeCSignal
			, const uint mgeIxVTbl
			, const string& srefMgeUref
			, const string& sref
			, const bool Const
			, const string& srefWdbeKHdltype
			, const usmallint Width
			, const string& Minmax
			, const string& Comb
			, const string& Onval
			, const string& Offval
			, const string& srefDrvRefWdbeMPort
			, const string& Comment
		) : WdbeMSignal() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->irefRefWdbeCSignal = irefRefWdbeCSignal;
	this->mgeIxVTbl = mgeIxVTbl;
	this->srefMgeUref = srefMgeUref;
	this->sref = sref;
	this->Const = Const;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Comb = Comb;
	this->Onval = Onval;
	this->Offval = Offval;
	this->srefDrvRefWdbeMPort = srefDrvRefWdbeMPort;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIMSignal2::ImeitemIMSignal2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMSignal2()
		{
	WdbeMSignal* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemsignal->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWdbeCSignal = rec->refWdbeCSignal;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		mgeIxVTbl = rec->mgeIxVTbl;
		mgeUref = rec->mgeUref;
		sref = rec->sref;
		Const = rec->Const;
		srefWdbeKHdltype = rec->srefWdbeKHdltype;
		Width = rec->Width;
		Minmax = rec->Minmax;
		Comb = rec->Comb;
		Onval = rec->Onval;
		Offval = rec->Offval;
		drvRefWdbeMPort = rec->drvRefWdbeMPort;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMSignal2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMSignal2::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {irefRefWdbeCSignal = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMSignal2::VecWIel::IREFREFWDBECSIGNAL;};
	if (txtrd.fields.size() > 2) {srefMgeIxVTbl = txtrd.fields[2]; ixWIelValid += ImeIMSignal2::VecWIel::SREFMGEIXVTBL;};
	if (txtrd.fields.size() > 3) {srefMgeUref = txtrd.fields[3]; ixWIelValid += ImeIMSignal2::VecWIel::SREFMGEUREF;};
	if (txtrd.fields.size() > 4) {sref = txtrd.fields[4]; ixWIelValid += ImeIMSignal2::VecWIel::SREF;};
	if (txtrd.fields.size() > 5) {Const = (txtrd.fields[5] == "true"); ixWIelValid += ImeIMSignal2::VecWIel::CONST;};
	if (txtrd.fields.size() > 6) {srefWdbeKHdltype = txtrd.fields[6]; ixWIelValid += ImeIMSignal2::VecWIel::SREFWDBEKHDLTYPE;};
	if (txtrd.fields.size() > 7) {Width = atoi(txtrd.fields[7].c_str()); ixWIelValid += ImeIMSignal2::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 8) {Minmax = txtrd.fields[8]; ixWIelValid += ImeIMSignal2::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 9) {Comb = txtrd.fields[9]; ixWIelValid += ImeIMSignal2::VecWIel::COMB;};
	if (txtrd.fields.size() > 10) {Onval = txtrd.fields[10]; ixWIelValid += ImeIMSignal2::VecWIel::ONVAL;};
	if (txtrd.fields.size() > 11) {Offval = txtrd.fields[11]; ixWIelValid += ImeIMSignal2::VecWIel::OFFVAL;};
	if (txtrd.fields.size() > 12) {srefDrvRefWdbeMPort = txtrd.fields[12]; ixWIelValid += ImeIMSignal2::VecWIel::SREFDRVREFWDBEMPORT;};
	if (txtrd.fields.size() > 13) {Comment = txtrd.fields[13]; ixWIelValid += ImeIMSignal2::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSignal2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMSignal2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMSignal2::VecWIel::SREFIXVBASETYPE;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCSignal", "clu", irefRefWdbeCSignal)) ixWIelValid += ImeIMSignal2::VecWIel::IREFREFWDBECSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefMgeIxVTbl", "mgt", srefMgeIxVTbl)) ixWIelValid += ImeIMSignal2::VecWIel::SREFMGEIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefMgeUref", "mgu", srefMgeUref)) ixWIelValid += ImeIMSignal2::VecWIel::SREFMGEUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMSignal2::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Const", "con", Const)) ixWIelValid += ImeIMSignal2::VecWIel::CONST;
		if (extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype)) ixWIelValid += ImeIMSignal2::VecWIel::SREFWDBEKHDLTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMSignal2::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMSignal2::VecWIel::MINMAX;
		if (extractStringUclc(docctx, basexpath, "Comb", "cmb", Comb)) ixWIelValid += ImeIMSignal2::VecWIel::COMB;
		if (extractStringUclc(docctx, basexpath, "Onval", "onv", Onval)) ixWIelValid += ImeIMSignal2::VecWIel::ONVAL;
		if (extractStringUclc(docctx, basexpath, "Offval", "ofv", Offval)) ixWIelValid += ImeIMSignal2::VecWIel::OFFVAL;
		if (extractStringUclc(docctx, basexpath, "srefDrvRefWdbeMPort", "drv", srefDrvRefWdbeMPort)) ixWIelValid += ImeIMSignal2::VecWIel::SREFDRVREFWDBEMPORT;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMSignal2::VecWIel::COMMENT;
	};
};

void IexWdbeFin::ImeitemIMSignal2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMSignalBasetype::getSref(ixVBasetype) << "\t" << irefRefWdbeCSignal << "\t" << VecWdbeVMSignalMgeTbl::getSref(mgeIxVTbl) << "\t" << srefMgeUref << "\t" << sref << "\t" << StrMod::boolToString(Const) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Comb << "\t" << Onval << "\t" << Offval << "\t" << srefDrvRefWdbeMPort << "\t" << Comment << endl;
};

void IexWdbeFin::ImeitemIMSignal2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","clu","mgt","mgu","srf","con","hty","wid","mmx","cmb","onv","ofv","drv","cmt"};
	else tags = {"ImeitemIMSignal2","srefIxVBasetype","irefRefWdbeCSignal","srefMgeIxVTbl","srefMgeUref","sref","Const","srefWdbeKHdltype","Width","Minmax","Comb","Onval","Offval","srefDrvRefWdbeMPort","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMSignalBasetype::getSref(ixVBasetype));
		writeUbigint(wr, tags[2], irefRefWdbeCSignal);
		writeString(wr, tags[3], VecWdbeVMSignalMgeTbl::getSref(mgeIxVTbl));
		writeString(wr, tags[4], srefMgeUref);
		writeString(wr, tags[5], sref);
		writeBool(wr, tags[6], Const);
		writeString(wr, tags[7], srefWdbeKHdltype);
		writeUsmallint(wr, tags[8], Width);
		writeString(wr, tags[9], Minmax);
		writeString(wr, tags[10], Comb);
		writeString(wr, tags[11], Onval);
		writeString(wr, tags[12], Offval);
		writeString(wr, tags[13], srefDrvRefWdbeMPort);
		writeString(wr, tags[14], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMSignal2::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMSignal2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "irefrefwdbecsignal") ix |= IREFREFWDBECSIGNAL;
		else if (ss[i] == "srefmgeixvtbl") ix |= SREFMGEIXVTBL;
		else if (ss[i] == "srefmgeuref") ix |= SREFMGEUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "const") ix |= CONST;
		else if (ss[i] == "srefwdbekhdltype") ix |= SREFWDBEKHDLTYPE;
		else if (ss[i] == "width") ix |= WIDTH;
		else if (ss[i] == "minmax") ix |= MINMAX;
		else if (ss[i] == "comb") ix |= COMB;
		else if (ss[i] == "onval") ix |= ONVAL;
		else if (ss[i] == "offval") ix |= OFFVAL;
		else if (ss[i] == "srefdrvrefwdbemport") ix |= SREFDRVREFWDBEMPORT;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIMSignal2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMSignal2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & IREFREFWDBECSIGNAL) ss.push_back("irefRefWdbeCSignal");
	if (ix & SREFMGEIXVTBL) ss.push_back("srefMgeIxVTbl");
	if (ix & SREFMGEUREF) ss.push_back("srefMgeUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & CONST) ss.push_back("Const");
	if (ix & SREFWDBEKHDLTYPE) ss.push_back("srefWdbeKHdltype");
	if (ix & WIDTH) ss.push_back("Width");
	if (ix & MINMAX) ss.push_back("Minmax");
	if (ix & COMB) ss.push_back("Comb");
	if (ix & ONVAL) ss.push_back("Onval");
	if (ix & OFFVAL) ss.push_back("Offval");
	if (ix & SREFDRVREFWDBEMPORT) ss.push_back("srefDrvRefWdbeMPort");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMSignal2
 ******************************************************************************/

IexWdbeFin::ImeIMSignal2::ImeIMSignal2() {
};

IexWdbeFin::ImeIMSignal2::~ImeIMSignal2() {
	clear();
};

void IexWdbeFin::ImeIMSignal2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMSignal2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMSignal2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemIMSignal2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSignal2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSignal2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSIGNAL2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSignal2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSignal2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMSignal2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMSignal2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSignal2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSignal2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSignal2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMSignal2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMSignal2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMSignal2." << StrMod::replaceChar(ImeIMSignal2::VecWIel::getSrefs(16383), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMSignal2.end" << endl;
	};
};

void IexWdbeFin::ImeIMSignal2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSignal2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMVariable1
 ******************************************************************************/

IexWdbeFin::ImeitemIMVariable1::ImeitemIMVariable1(
			const ubigint irefRefWdbeCVariable
			, const string& sref
			, const string& srefWdbeKHdltype
			, const usmallint Width
			, const string& Minmax
			, const string& Comment
		) : WdbeMVariable() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWdbeCVariable = irefRefWdbeCVariable;
	this->sref = sref;
	this->srefWdbeKHdltype = srefWdbeKHdltype;
	this->Width = Width;
	this->Minmax = Minmax;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIMVariable1::ImeitemIMVariable1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVariable1()
		{
	WdbeMVariable* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemvariable->loadRecByRef(ref, &rec)) {
		refWdbeCVariable = rec->refWdbeCVariable;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		sref = rec->sref;
		srefWdbeKHdltype = rec->srefWdbeKHdltype;
		Width = rec->Width;
		Minmax = rec->Minmax;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMVariable1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWdbeCVariable = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMVariable1::VecWIel::IREFREFWDBECVARIABLE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVariable1::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefWdbeKHdltype = txtrd.fields[2]; ixWIelValid += ImeIMVariable1::VecWIel::SREFWDBEKHDLTYPE;};
	if (txtrd.fields.size() > 3) {Width = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIMVariable1::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 4) {Minmax = txtrd.fields[4]; ixWIelValid += ImeIMVariable1::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIMVariable1::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVariable1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMVariable1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCVariable", "clu", irefRefWdbeCVariable)) ixWIelValid += ImeIMVariable1::VecWIel::IREFREFWDBECVARIABLE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVariable1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype)) ixWIelValid += ImeIMVariable1::VecWIel::SREFWDBEKHDLTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMVariable1::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMVariable1::VecWIel::MINMAX;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVariable1::VecWIel::COMMENT;
	};
};

void IexWdbeFin::ImeitemIMVariable1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << irefRefWdbeCVariable << "\t" << sref << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Comment << endl;
};

void IexWdbeFin::ImeitemIMVariable1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","hty","wid","mmx","cmt"};
	else tags = {"ImeitemIMVariable1","irefRefWdbeCVariable","sref","srefWdbeKHdltype","Width","Minmax","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWdbeCVariable);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefWdbeKHdltype);
		writeUsmallint(wr, tags[4], Width);
		writeString(wr, tags[5], Minmax);
		writeString(wr, tags[6], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMVariable1::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMVariable1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwdbecvariable") ix |= IREFREFWDBECVARIABLE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefwdbekhdltype") ix |= SREFWDBEKHDLTYPE;
		else if (ss[i] == "width") ix |= WIDTH;
		else if (ss[i] == "minmax") ix |= MINMAX;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIMVariable1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMVariable1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWDBECVARIABLE) ss.push_back("irefRefWdbeCVariable");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFWDBEKHDLTYPE) ss.push_back("srefWdbeKHdltype");
	if (ix & WIDTH) ss.push_back("Width");
	if (ix & MINMAX) ss.push_back("Minmax");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMVariable1
 ******************************************************************************/

IexWdbeFin::ImeIMVariable1::ImeIMVariable1() {
};

IexWdbeFin::ImeIMVariable1::~ImeIMVariable1() {
	clear();
};

void IexWdbeFin::ImeIMVariable1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMVariable1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMVariable1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeFin::ImeitemIMVariable1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVariable1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVariable1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVARIABLE1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVariable1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVariable1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMVariable1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMVariable1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVariable1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVariable1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVariable1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMVariable1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMVariable1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMVariable1." << StrMod::replaceChar(ImeIMVariable1::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMVariable1.end" << endl;
	};
};

void IexWdbeFin::ImeIMVariable1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVariable1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMModule
 ******************************************************************************/

IexWdbeFin::ImeitemIMModule::ImeitemIMModule(
			const string& hsrefSupRefWdbeMModule
			, const string& sref
		) : WdbeMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefSupRefWdbeMModule = hsrefSupRefWdbeMModule;
	this->sref = sref;
};

IexWdbeFin::ImeitemIMModule::ImeitemIMModule(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMModule()
		{
	WdbeMModule* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(ref, &rec)) {
		hkIxVTbl = rec->hkIxVTbl;
		hkUref = rec->hkUref;
		supRefWdbeMModule = rec->supRefWdbeMModule;
		sref = rec->sref;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMModule::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefSupRefWdbeMModule = txtrd.fields[0]; ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMModule::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICGENERIC)) {
					imeicgeneric.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICPORT)) {
					imeicport.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICSIGNAL2)) {
					imeicsignal2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICVARIABLE1)) {
					imeicvariable1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMCDC)) {
					imeimcdc.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMCONTROLLER)) {
					imeimcontroller.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMGENERIC)) {
					imeimgeneric.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPORT)) {
					imeimport.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPROCESS)) {
					imeimprocess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMSENSITIVITY1)) {
					imeimsensitivity1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMSIGNAL2)) {
					imeimsignal2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMVARIABLE1)) {
					imeimvariable1.readTxt(txtrd);
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

void IexWdbeFin::ImeitemIMModule::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefWdbeMModule", "sup", hsrefSupRefWdbeMModule)) ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMModule::VecWIel::SREF;
		imeicgeneric.readXML(docctx, basexpath);
		imeicport.readXML(docctx, basexpath);
		imeicsignal2.readXML(docctx, basexpath);
		imeicvariable1.readXML(docctx, basexpath);
		imeimcdc.readXML(docctx, basexpath);
		imeimcontroller.readXML(docctx, basexpath);
		imeimgeneric.readXML(docctx, basexpath);
		imeimport.readXML(docctx, basexpath);
		imeimprocess.readXML(docctx, basexpath);
		imeimsensitivity1.readXML(docctx, basexpath);
		imeimsignal2.readXML(docctx, basexpath);
		imeimvariable1.readXML(docctx, basexpath);
	};
};

void IexWdbeFin::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefSupRefWdbeMModule << "\t" << sref << endl;
	imeicgeneric.writeTxt(outfile);
	imeicport.writeTxt(outfile);
	imeicsignal2.writeTxt(outfile);
	imeicvariable1.writeTxt(outfile);
	imeimcdc.writeTxt(outfile);
	imeimcontroller.writeTxt(outfile);
	imeimgeneric.writeTxt(outfile);
	imeimport.writeTxt(outfile);
	imeimprocess.writeTxt(outfile);
	imeimsensitivity1.writeTxt(outfile);
	imeimsignal2.writeTxt(outfile);
	imeimvariable1.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIMModule::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","sup","srf"};
	else tags = {"ImeitemIMModule","hsrefSupRefWdbeMModule","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], hsrefSupRefWdbeMModule);
		writeString(wr, tags[2], sref);
		imeicgeneric.writeXML(wr, shorttags);
		imeicport.writeXML(wr, shorttags);
		imeicsignal2.writeXML(wr, shorttags);
		imeicvariable1.writeXML(wr, shorttags);
		imeimcdc.writeXML(wr, shorttags);
		imeimcontroller.writeXML(wr, shorttags);
		imeimgeneric.writeXML(wr, shorttags);
		imeimport.writeXML(wr, shorttags);
		imeimprocess.writeXML(wr, shorttags);
		imeimsensitivity1.writeXML(wr, shorttags);
		imeimsignal2.writeXML(wr, shorttags);
		imeimvariable1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMModule::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefsuprefwdbemmodule") ix |= HSREFSUPREFWDBEMMODULE;
		else if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWdbeFin::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMModule::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & HSREFSUPREFWDBEMMODULE) ss.push_back("hsrefSupRefWdbeMModule");
	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMModule
 ******************************************************************************/

IexWdbeFin::ImeIMModule::ImeIMModule() {
};

IexWdbeFin::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWdbeFin::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeFin::ImeitemIMModule();
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

void IexWdbeFin::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMModule* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMModule.end" << endl;
	};
};

void IexWdbeFin::ImeIMModule::writeXML(
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
 class IexWdbeFin::ImeitemIMSignal1
 ******************************************************************************/

IexWdbeFin::ImeitemIMSignal1::ImeitemIMSignal1(
			const uint ixVBasetype
			, const ubigint irefRefWdbeCSignal
			, const string& srefMgeUref
			, const string& sref
			, const string& Comment
		) : WdbeMSignal() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixVBasetype = ixVBasetype;
	this->irefRefWdbeCSignal = irefRefWdbeCSignal;
	this->srefMgeUref = srefMgeUref;
	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeFin::ImeitemIMSignal1::ImeitemIMSignal1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMSignal1()
		{
	WdbeMSignal* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemsignal->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWdbeCSignal = rec->refWdbeCSignal;
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		mgeIxVTbl = rec->mgeIxVTbl;
		mgeUref = rec->mgeUref;
		sref = rec->sref;
		srefWdbeKHdltype = rec->srefWdbeKHdltype;
		Width = rec->Width;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMSignal1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMSignal1::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {irefRefWdbeCSignal = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMSignal1::VecWIel::IREFREFWDBECSIGNAL;};
	if (txtrd.fields.size() > 2) {srefMgeUref = txtrd.fields[2]; ixWIelValid += ImeIMSignal1::VecWIel::SREFMGEUREF;};
	if (txtrd.fields.size() > 3) {sref = txtrd.fields[3]; ixWIelValid += ImeIMSignal1::VecWIel::SREF;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIMSignal1::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSignal1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeFin::ImeitemIMSignal1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMSignal1::VecWIel::SREFIXVBASETYPE;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCSignal", "clu", irefRefWdbeCSignal)) ixWIelValid += ImeIMSignal1::VecWIel::IREFREFWDBECSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefMgeUref", "mgu", srefMgeUref)) ixWIelValid += ImeIMSignal1::VecWIel::SREFMGEUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMSignal1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMSignal1::VecWIel::COMMENT;
	};
};

void IexWdbeFin::ImeitemIMSignal1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVMSignalBasetype::getSref(ixVBasetype) << "\t" << irefRefWdbeCSignal << "\t" << srefMgeUref << "\t" << sref << "\t" << Comment << endl;
};

void IexWdbeFin::ImeitemIMSignal1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","clu","mgu","srf","cmt"};
	else tags = {"ImeitemIMSignal1","srefIxVBasetype","irefRefWdbeCSignal","srefMgeUref","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMSignalBasetype::getSref(ixVBasetype));
		writeUbigint(wr, tags[2], irefRefWdbeCSignal);
		writeString(wr, tags[3], srefMgeUref);
		writeString(wr, tags[4], sref);
		writeString(wr, tags[5], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMSignal1::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMSignal1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "irefrefwdbecsignal") ix |= IREFREFWDBECSIGNAL;
		else if (ss[i] == "srefmgeuref") ix |= SREFMGEUREF;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeFin::ImeIMSignal1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMSignal1::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFIXVBASETYPE) ss.push_back("srefIxVBasetype");
	if (ix & IREFREFWDBECSIGNAL) ss.push_back("irefRefWdbeCSignal");
	if (ix & SREFMGEUREF) ss.push_back("srefMgeUref");
	if (ix & SREF) ss.push_back("sref");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMSignal1
 ******************************************************************************/

IexWdbeFin::ImeIMSignal1::ImeIMSignal1() {
};

IexWdbeFin::ImeIMSignal1::~ImeIMSignal1() {
	clear();
};

void IexWdbeFin::ImeIMSignal1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMSignal1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMSignal1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeFin::ImeitemIMSignal1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSignal1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSignal1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSIGNAL1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSignal1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSignal1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeFin::ImeIMSignal1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMSignal1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSignal1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSignal1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSignal1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeFin::ImeitemIMSignal1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMSignal1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMSignal1." << StrMod::replaceChar(ImeIMSignal1::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMSignal1.end" << endl;
	};
};

void IexWdbeFin::ImeIMSignal1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSignal1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeFin::ImeitemIMUnit
 ******************************************************************************/

IexWdbeFin::ImeitemIMUnit::ImeitemIMUnit(
			const string& sref
		) : WdbeMUnit() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexWdbeFin::ImeitemIMUnit::ImeitemIMUnit(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMUnit()
		{
	WdbeMUnit* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemunit->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		sref = rec->sref;

		delete rec;
	};
};

void IexWdbeFin::ImeitemIMUnit::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUnit::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICSIGNAL1)) {
					imeicsignal1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMBANK)) {
					imeimbank.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMINTERRUPT1)) {
					imeiminterrupt1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMMODULE)) {
					imeimmodule.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSIGNAL1)) {
					imeimsignal1.readTxt(txtrd);
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

void IexWdbeFin::ImeitemIMUnit::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUnit::VecWIel::SREF;
		imeicsignal1.readXML(docctx, basexpath);
		imeimbank.readXML(docctx, basexpath);
		imeiminterrupt1.readXML(docctx, basexpath);
		imeimmodule.readXML(docctx, basexpath);
		imeimsignal1.readXML(docctx, basexpath);
	};
};

void IexWdbeFin::ImeitemIMUnit::writeTxt(
			fstream& outfile
		) {
	outfile << sref << endl;
	imeicsignal1.writeTxt(outfile);
	imeimbank.writeTxt(outfile);
	imeiminterrupt1.writeTxt(outfile);
	imeimmodule.writeTxt(outfile);
	imeimsignal1.writeTxt(outfile);
};

void IexWdbeFin::ImeitemIMUnit::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf"};
	else tags = {"ImeitemIMUnit","sref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		imeicsignal1.writeXML(wr, shorttags);
		imeimbank.writeXML(wr, shorttags);
		imeiminterrupt1.writeXML(wr, shorttags);
		imeimmodule.writeXML(wr, shorttags);
		imeimsignal1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeFin::ImeIMUnit::VecWIel
 ******************************************************************************/

uint IexWdbeFin::ImeIMUnit::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWdbeFin::ImeIMUnit::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeFin::ImeIMUnit::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeFin::ImeIMUnit
 ******************************************************************************/

IexWdbeFin::ImeIMUnit::ImeIMUnit() {
};

IexWdbeFin::ImeIMUnit::~ImeIMUnit() {
	clear();
};

void IexWdbeFin::ImeIMUnit::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeFin::ImeIMUnit::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeFin::ImeitemIMUnit* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeFin::ImeitemIMUnit();
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

void IexWdbeFin::ImeIMUnit::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeFin::ImeitemIMUnit* ii = NULL;

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

			ii = new IexWdbeFin::ImeitemIMUnit();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeFin::ImeIMUnit::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUnit." << StrMod::replaceChar(ImeIMUnit::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUnit.end" << endl;
	};
};

void IexWdbeFin::ImeIMUnit::writeXML(
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
 namespace IexWdbeFin
 ******************************************************************************/

void IexWdbeFin::parseFromFile(
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
			Txtrd rd(fullpath, rectpath, "IexWdbeFin", Version("1.1.49"), VecVIme::getIx);
			readTxt(rd, imeimunit);
	};
};

void IexWdbeFin::exportToFile(
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

void IexWdbeFin::readTxt(
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

void IexWdbeFin::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMUnit& imeimunit
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeFin")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.1.49")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.1.49"}});
		};

		// look for XML sub-blocks
		imeimunit.readXML(docctx, basexpath);

	} else {
		imeimunit = ImeIMUnit();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeFin"}});
	};
};

void IexWdbeFin::writeTxt(
			fstream& outfile
			, ImeIMUnit& imeimunit
		) {
	outfile << "IexWdbeFin v" WDBE_VERSION << endl;

	imeimunit.writeTxt(outfile);
};

void IexWdbeFin::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMUnit& imeimunit
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeFin");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeimunit.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeFin::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMFSMSTATESTEP,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMPINPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecWdbeVIop::INS},{(uint)VecVIme::IMEICFSMSTATE,VecWdbeVIop::INS},{(uint)VecVIme::IMEICGENERIC,VecWdbeVIop::INS},{(uint)VecVIme::IMEICPIN,VecWdbeVIop::INS},{(uint)VecVIme::IMEICPORT,VecWdbeVIop::INS},{(uint)VecVIme::IMEICSIGNAL1,VecWdbeVIop::INS},{(uint)VecVIme::IMEICSIGNAL2,VecWdbeVIop::INS},{(uint)VecVIme::IMEICVARIABLE1,VecWdbeVIop::INS},{(uint)VecVIme::IMEICVARIABLE2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJMPINSREF,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCDC,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMFSM,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMFSMSTATE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMGENERIC,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMINTERRUPT1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPORT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPROCESS,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMSENSITIVITY1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMSENSITIVITY2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMSIGNAL1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMSIGNAL2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVARIABLE1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVARIABLE2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIRMCDCMSIGNAL,VecWdbeVIop::INS}};
};

uint IexWdbeFin::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};
