/**
	* \file IexWdbeDdd.cpp
	* data blocks and readers/writers for import/export complex IexWdbeDdd (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWdbeDdd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeDdd::VecVIme
 ******************************************************************************/

uint IexWdbeDdd::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamcommandinvpar1") return IMEIAMCOMMANDINVPAR1;
	if (s == "imeiamcommandinvpar2") return IMEIAMCOMMANDINVPAR2;
	if (s == "imeiamcommandretpar1") return IMEIAMCOMMANDRETPAR1;
	if (s == "imeiamcommandretpar2") return IMEIAMCOMMANDRETPAR2;
	if (s == "imeiamerrorpar1") return IMEIAMERRORPAR1;
	if (s == "imeiamerrorpar2") return IMEIAMERRORPAR2;
	if (s == "imeiamfsmstatestep") return IMEIAMFSMSTATESTEP;
	if (s == "imeiampinpar") return IMEIAMPINPAR;
	if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	if (s == "imeicfsmstate") return IMEICFSMSTATE;
	if (s == "imeicgeneric") return IMEICGENERIC;
	if (s == "imeicpin") return IMEICPIN;
	if (s == "imeicport") return IMEICPORT;
	if (s == "imeicsignal") return IMEICSIGNAL;
	if (s == "imeicvariable") return IMEICVARIABLE;
	if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;
	if (s == "imeijmpinsref") return IMEIJMPINSREF;
	if (s == "imeimbank") return IMEIMBANK;
	if (s == "imeimcommand1") return IMEIMCOMMAND1;
	if (s == "imeimcommand2") return IMEIMCOMMAND2;
	if (s == "imeimcontroller") return IMEIMCONTROLLER;
	if (s == "imeimerror1") return IMEIMERROR1;
	if (s == "imeimerror2") return IMEIMERROR2;
	if (s == "imeimfsm") return IMEIMFSM;
	if (s == "imeimfsmstate") return IMEIMFSMSTATE;
	if (s == "imeimgeneric") return IMEIMGENERIC;
	if (s == "imeimimbuf") return IMEIMIMBUF;
	if (s == "imeimmodule") return IMEIMMODULE;
	if (s == "imeimpin") return IMEIMPIN;
	if (s == "imeimport") return IMEIMPORT;
	if (s == "imeimprocess") return IMEIMPROCESS;
	if (s == "imeimsignal") return IMEIMSIGNAL;
	if (s == "imeimunit") return IMEIMUNIT;
	if (s == "imeimvariable") return IMEIMVARIABLE;
	if (s == "imeimvector1") return IMEIMVECTOR1;
	if (s == "imeimvector2") return IMEIMVECTOR2;
	if (s == "imeimvectoritem1") return IMEIMVECTORITEM1;
	if (s == "imeimvectoritem2") return IMEIMVECTORITEM2;
	if (s == "imeirmcommandmcontroller") return IMEIRMCOMMANDMCONTROLLER;

	return(0);
};

string IexWdbeDdd::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMCOMMANDINVPAR1) return("ImeIAMCommandInvpar1");
	if (ix == IMEIAMCOMMANDINVPAR2) return("ImeIAMCommandInvpar2");
	if (ix == IMEIAMCOMMANDRETPAR1) return("ImeIAMCommandRetpar1");
	if (ix == IMEIAMCOMMANDRETPAR2) return("ImeIAMCommandRetpar2");
	if (ix == IMEIAMERRORPAR1) return("ImeIAMErrorPar1");
	if (ix == IMEIAMERRORPAR2) return("ImeIAMErrorPar2");
	if (ix == IMEIAMFSMSTATESTEP) return("ImeIAMFsmstateStep");
	if (ix == IMEIAMPINPAR) return("ImeIAMPinPar");
	if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	if (ix == IMEICFSMSTATE) return("ImeICFsmstate");
	if (ix == IMEICGENERIC) return("ImeICGeneric");
	if (ix == IMEICPIN) return("ImeICPin");
	if (ix == IMEICPORT) return("ImeICPort");
	if (ix == IMEICSIGNAL) return("ImeICSignal");
	if (ix == IMEICVARIABLE) return("ImeICVariable");
	if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");
	if (ix == IMEIJMPINSREF) return("ImeIJMPinSref");
	if (ix == IMEIMBANK) return("ImeIMBank");
	if (ix == IMEIMCOMMAND1) return("ImeIMCommand1");
	if (ix == IMEIMCOMMAND2) return("ImeIMCommand2");
	if (ix == IMEIMCONTROLLER) return("ImeIMController");
	if (ix == IMEIMERROR1) return("ImeIMError1");
	if (ix == IMEIMERROR2) return("ImeIMError2");
	if (ix == IMEIMFSM) return("ImeIMFsm");
	if (ix == IMEIMFSMSTATE) return("ImeIMFsmstate");
	if (ix == IMEIMGENERIC) return("ImeIMGeneric");
	if (ix == IMEIMIMBUF) return("ImeIMImbuf");
	if (ix == IMEIMMODULE) return("ImeIMModule");
	if (ix == IMEIMPIN) return("ImeIMPin");
	if (ix == IMEIMPORT) return("ImeIMPort");
	if (ix == IMEIMPROCESS) return("ImeIMProcess");
	if (ix == IMEIMSIGNAL) return("ImeIMSignal");
	if (ix == IMEIMUNIT) return("ImeIMUnit");
	if (ix == IMEIMVARIABLE) return("ImeIMVariable");
	if (ix == IMEIMVECTOR1) return("ImeIMVector1");
	if (ix == IMEIMVECTOR2) return("ImeIMVector2");
	if (ix == IMEIMVECTORITEM1) return("ImeIMVectoritem1");
	if (ix == IMEIMVECTORITEM2) return("ImeIMVectoritem2");
	if (ix == IMEIRMCOMMANDMCONTROLLER) return("ImeIRMCommandMController");

	return("");
};

/******************************************************************************
 class IexWdbeDdd::ImeitemICPin
 ******************************************************************************/

IexWdbeDdd::ImeitemICPin::ImeitemICPin(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDdd::ImeitemICPin::ImeitemICPin(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICPin()
		{
};

void IexWdbeDdd::ImeitemICPin::readTxt(
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

void IexWdbeDdd::ImeitemICPin::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICPin::VecWIel::IREF;
	};
};

void IexWdbeDdd::ImeitemICPin::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeDdd::ImeitemICPin::writeXML(
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
 class IexWdbeDdd::ImeICPin::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeICPin::VecWIel::getIx(
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

void IexWdbeDdd::ImeICPin::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeICPin::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeICPin
 ******************************************************************************/

IexWdbeDdd::ImeICPin::ImeICPin() {
};

IexWdbeDdd::ImeICPin::~ImeICPin() {
	clear();
};

void IexWdbeDdd::ImeICPin::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeICPin::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemICPin* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemICPin();
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

void IexWdbeDdd::ImeICPin::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemICPin* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemICPin();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeICPin::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICPin." << StrMod::replaceChar(ImeICPin::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICPin.end" << endl;
	};
};

void IexWdbeDdd::ImeICPin::writeXML(
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
 class IexWdbeDdd::ImeitemIAMPinPar
 ******************************************************************************/

IexWdbeDdd::ImeitemIAMPinPar::ImeitemIAMPinPar(
			const string& x1SrefKKey
			, const string& Val
		) : WdbeAMPinPar() {
	lineno = 0;
	ixWIelValid = 0;

	this->x1SrefKKey = x1SrefKKey;
	this->Val = Val;
};

IexWdbeDdd::ImeitemIAMPinPar::ImeitemIAMPinPar(
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

void IexWdbeDdd::ImeitemIAMPinPar::readTxt(
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

void IexWdbeDdd::ImeitemIAMPinPar::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "x1SrefKKey", "key", x1SrefKKey)) ixWIelValid += ImeIAMPinPar::VecWIel::X1SREFKKEY;
		if (extractStringUclc(docctx, basexpath, "Val", "val", Val)) ixWIelValid += ImeIAMPinPar::VecWIel::VAL;
	};
};

void IexWdbeDdd::ImeitemIAMPinPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << x1SrefKKey << "\t" << Val << endl;
};

void IexWdbeDdd::ImeitemIAMPinPar::writeXML(
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
 class IexWdbeDdd::ImeIAMPinPar::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIAMPinPar::VecWIel::getIx(
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

void IexWdbeDdd::ImeIAMPinPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*VAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIAMPinPar::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIAMPinPar
 ******************************************************************************/

IexWdbeDdd::ImeIAMPinPar::ImeIAMPinPar() {
};

IexWdbeDdd::ImeIAMPinPar::~ImeIAMPinPar() {
	clear();
};

void IexWdbeDdd::ImeIAMPinPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIAMPinPar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIAMPinPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemIAMPinPar();
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

void IexWdbeDdd::ImeIAMPinPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIAMPinPar* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIAMPinPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIAMPinPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMPinPar." << StrMod::replaceChar(ImeIAMPinPar::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMPinPar.end" << endl;
	};
};

void IexWdbeDdd::ImeIAMPinPar::writeXML(
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
 class IexWdbeDdd::ImeitemIJMPinSref
 ******************************************************************************/

IexWdbeDdd::ImeitemIJMPinSref::ImeitemIJMPinSref(
			const string& srefX1RefWdbeMPeripheral
			, const string& sref
		) : WdbeJMPinSref() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefX1RefWdbeMPeripheral = srefX1RefWdbeMPeripheral;
	this->sref = sref;
};

IexWdbeDdd::ImeitemIJMPinSref::ImeitemIJMPinSref(
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

void IexWdbeDdd::ImeitemIJMPinSref::readTxt(
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

void IexWdbeDdd::ImeitemIJMPinSref::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefX1RefWdbeMPeripheral", "", srefX1RefWdbeMPeripheral)) ixWIelValid += ImeIJMPinSref::VecWIel::SREFX1REFWDBEMPERIPHERAL;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIJMPinSref::VecWIel::SREF;
	};
};

void IexWdbeDdd::ImeitemIJMPinSref::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefX1RefWdbeMPeripheral << "\t" << sref << endl;
};

void IexWdbeDdd::ImeitemIJMPinSref::writeXML(
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
 class IexWdbeDdd::ImeIJMPinSref::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIJMPinSref::VecWIel::getIx(
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

void IexWdbeDdd::ImeIJMPinSref::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIJMPinSref::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIJMPinSref
 ******************************************************************************/

IexWdbeDdd::ImeIJMPinSref::ImeIJMPinSref() {
};

IexWdbeDdd::ImeIJMPinSref::~ImeIJMPinSref() {
	clear();
};

void IexWdbeDdd::ImeIJMPinSref::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIJMPinSref::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIJMPinSref* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemIJMPinSref();
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

void IexWdbeDdd::ImeIJMPinSref::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIJMPinSref* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIJMPinSref();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIJMPinSref::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJMPinSref." << StrMod::replaceChar(ImeIJMPinSref::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJMPinSref.end" << endl;
	};
};

void IexWdbeDdd::ImeIJMPinSref::writeXML(
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
 class IexWdbeDdd::ImeitemIMPin
 ******************************************************************************/

IexWdbeDdd::ImeitemIMPin::ImeitemIMPin(
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

IexWdbeDdd::ImeitemIMPin::ImeitemIMPin(
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

void IexWdbeDdd::ImeitemIMPin::readTxt(
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

void IexWdbeDdd::ImeitemIMPin::readXML(
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

void IexWdbeDdd::ImeitemIMPin::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << irefRefWdbeCPin << "\t" << sref << "\t" << Location << endl;
	imeiampinpar.writeTxt(outfile);
	imeijmpinsref.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMPin::writeXML(
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
 class IexWdbeDdd::ImeIMPin::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMPin::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwdbeviop") ix |= SREFIXWDBEVIOP;
		else if (ss[i] == "irefrefwdbecpin") ix |= IREFREFWDBECPIN;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "location") ix |= LOCATION;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMPin::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*LOCATION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMPin::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMPin
 ******************************************************************************/

IexWdbeDdd::ImeIMPin::ImeIMPin() {
};

IexWdbeDdd::ImeIMPin::~ImeIMPin() {
	clear();
};

void IexWdbeDdd::ImeIMPin::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMPin::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMPin* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIMPin();
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

void IexWdbeDdd::ImeIMPin::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMPin* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMPin();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMPin::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPin." << StrMod::replaceChar(ImeIMPin::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPin.end" << endl;
	};
};

void IexWdbeDdd::ImeIMPin::writeXML(
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
 class IexWdbeDdd::ImeitemIMBank
 ******************************************************************************/

IexWdbeDdd::ImeitemIMBank::ImeitemIMBank(
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

IexWdbeDdd::ImeitemIMBank::ImeitemIMBank(
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

void IexWdbeDdd::ImeitemIMBank::readTxt(
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

void IexWdbeDdd::ImeitemIMBank::readXML(
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

void IexWdbeDdd::ImeitemIMBank::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << sref << "\t" << srefKVoltstd << endl;
	imeicpin.writeTxt(outfile);
	imeimpin.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMBank::writeXML(
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
 class IexWdbeDdd::ImeIMBank::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMBank::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwdbeviop") ix |= SREFIXWDBEVIOP;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefkvoltstd") ix |= SREFKVOLTSTD;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMBank::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFKVOLTSTD); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMBank::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMBank
 ******************************************************************************/

IexWdbeDdd::ImeIMBank::ImeIMBank() {
};

IexWdbeDdd::ImeIMBank::~ImeIMBank() {
	clear();
};

void IexWdbeDdd::ImeIMBank::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMBank::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMBank* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDdd::ImeitemIMBank();
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

void IexWdbeDdd::ImeIMBank::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMBank* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMBank();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMBank::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMBank." << StrMod::replaceChar(ImeIMBank::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMBank.end" << endl;
	};
};

void IexWdbeDdd::ImeIMBank::writeXML(
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
 class IexWdbeDdd::ImeitemIAMCommandInvpar1
 ******************************************************************************/

IexWdbeDdd::ImeitemIAMCommandInvpar1::ImeitemIAMCommandInvpar1(
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

IexWdbeDdd::ImeitemIAMCommandInvpar1::ImeitemIAMCommandInvpar1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMCommandInvpar1()
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

void IexWdbeDdd::ImeitemIAMCommandInvpar1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMCommandInvpar1::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWdbeVPartype = txtrd.fields[1]; ixWIelValid += ImeIAMCommandInvpar1::VecWIel::SREFIXWDBEVPARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWdbeMVector = txtrd.fields[2]; ixWIelValid += ImeIAMCommandInvpar1::VecWIel::SREFREFWDBEMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMCommandInvpar1::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Defval = txtrd.fields[4]; ixWIelValid += ImeIAMCommandInvpar1::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 5) {srefRefWdbeMVectoritem = txtrd.fields[5]; ixWIelValid += ImeIAMCommandInvpar1::VecWIel::SREFREFWDBEMVECTORITEM;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIAMCommandInvpar1::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandInvpar1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIAMCommandInvpar1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMCommandInvpar1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype)) ixWIelValid += ImeIAMCommandInvpar1::VecWIel::SREFIXWDBEVPARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVector", "vec", srefRefWdbeMVector)) ixWIelValid += ImeIAMCommandInvpar1::VecWIel::SREFREFWDBEMVECTOR;
		if (extractUtinyintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMCommandInvpar1::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMCommandInvpar1::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVectoritem", "vit", srefRefWdbeMVectoritem)) ixWIelValid += ImeIAMCommandInvpar1::VecWIel::SREFREFWDBEMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMCommandInvpar1::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIAMCommandInvpar1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Defval << "\t" << srefRefWdbeMVectoritem << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIAMCommandInvpar1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","pty","vec","len","dfv","vit","cmt"};
	else tags = {"ImeitemIAMCommandInvpar1","sref","srefIxWdbeVPartype","srefRefWdbeMVector","Length","Defval","srefRefWdbeMVectoritem","Comment"};

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
 class IexWdbeDdd::ImeIAMCommandInvpar1::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIAMCommandInvpar1::VecWIel::getIx(
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

void IexWdbeDdd::ImeIAMCommandInvpar1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIAMCommandInvpar1::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIAMCommandInvpar1
 ******************************************************************************/

IexWdbeDdd::ImeIAMCommandInvpar1::ImeIAMCommandInvpar1() {
};

IexWdbeDdd::ImeIAMCommandInvpar1::~ImeIAMCommandInvpar1() {
	clear();
};

void IexWdbeDdd::ImeIAMCommandInvpar1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIAMCommandInvpar1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIAMCommandInvpar1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIAMCommandInvpar1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandInvpar1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandInvpar1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDINVPAR1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandInvpar1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandInvpar1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIAMCommandInvpar1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIAMCommandInvpar1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCommandInvpar1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCommandInvpar1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCommandInvpar1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIAMCommandInvpar1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIAMCommandInvpar1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMCommandInvpar1." << StrMod::replaceChar(ImeIAMCommandInvpar1::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMCommandInvpar1.end" << endl;
	};
};

void IexWdbeDdd::ImeIAMCommandInvpar1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCommandInvpar1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIAMCommandRetpar1
 ******************************************************************************/

IexWdbeDdd::ImeitemIAMCommandRetpar1::ImeitemIAMCommandRetpar1(
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

IexWdbeDdd::ImeitemIAMCommandRetpar1::ImeitemIAMCommandRetpar1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMCommandRetpar1()
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

void IexWdbeDdd::ImeitemIAMCommandRetpar1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMCommandRetpar1::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWdbeVPartype = txtrd.fields[1]; ixWIelValid += ImeIAMCommandRetpar1::VecWIel::SREFIXWDBEVPARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWdbeMVector = txtrd.fields[2]; ixWIelValid += ImeIAMCommandRetpar1::VecWIel::SREFREFWDBEMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMCommandRetpar1::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMCommandRetpar1::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandRetpar1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIAMCommandRetpar1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMCommandRetpar1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype)) ixWIelValid += ImeIAMCommandRetpar1::VecWIel::SREFIXWDBEVPARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVector", "vec", srefRefWdbeMVector)) ixWIelValid += ImeIAMCommandRetpar1::VecWIel::SREFREFWDBEMVECTOR;
		if (extractUtinyintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMCommandRetpar1::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMCommandRetpar1::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIAMCommandRetpar1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIAMCommandRetpar1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","pty","vec","len","cmt"};
	else tags = {"ImeitemIAMCommandRetpar1","sref","srefIxWdbeVPartype","srefRefWdbeMVector","Length","Comment"};

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
 class IexWdbeDdd::ImeIAMCommandRetpar1::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIAMCommandRetpar1::VecWIel::getIx(
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

void IexWdbeDdd::ImeIAMCommandRetpar1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIAMCommandRetpar1::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIAMCommandRetpar1
 ******************************************************************************/

IexWdbeDdd::ImeIAMCommandRetpar1::ImeIAMCommandRetpar1() {
};

IexWdbeDdd::ImeIAMCommandRetpar1::~ImeIAMCommandRetpar1() {
	clear();
};

void IexWdbeDdd::ImeIAMCommandRetpar1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIAMCommandRetpar1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIAMCommandRetpar1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIAMCommandRetpar1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandRetpar1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandRetpar1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDRETPAR1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandRetpar1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandRetpar1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIAMCommandRetpar1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIAMCommandRetpar1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCommandRetpar1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCommandRetpar1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCommandRetpar1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIAMCommandRetpar1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIAMCommandRetpar1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMCommandRetpar1." << StrMod::replaceChar(ImeIAMCommandRetpar1::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMCommandRetpar1.end" << endl;
	};
};

void IexWdbeDdd::ImeIAMCommandRetpar1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCommandRetpar1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMCommand1
 ******************************************************************************/

IexWdbeDdd::ImeitemIMCommand1::ImeitemIMCommand1(
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

IexWdbeDdd::ImeitemIMCommand1::ImeitemIMCommand1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMCommand1()
		{
	WdbeMCommand* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcommand->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		sref = rec->sref;
		Fullsref = rec->Fullsref;
		ixVRettype = rec->ixVRettype;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDdd::ImeitemIMCommand1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {refNum = atol(txtrd.fields[0].c_str()); ixWIelValid += ImeIMCommand1::VecWIel::REFNUM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMCommand1::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxVRettype = txtrd.fields[2]; ixWIelValid += ImeIMCommand1::VecWIel::SREFIXVRETTYPE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMCommand1::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDINVPAR1)) {
					imeiamcommandinvpar1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDRETPAR1)) {
					imeiamcommandretpar1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCommand1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMCommand1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUintUclc(docctx, basexpath, "refNum", "ren", refNum)) ixWIelValid += ImeIMCommand1::VecWIel::REFNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCommand1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVRettype", "rty", srefIxVRettype)) ixWIelValid += ImeIMCommand1::VecWIel::SREFIXVRETTYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMCommand1::VecWIel::COMMENT;
		imeiamcommandinvpar1.readXML(docctx, basexpath);
		imeiamcommandretpar1.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMCommand1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << refNum << "\t" << sref << "\t" << VecWdbeVMCommandRettype::getSref(ixVRettype) << "\t" << Comment << endl;
	imeiamcommandinvpar1.writeTxt(outfile);
	imeiamcommandretpar1.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMCommand1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ren","srf","rty","cmt"};
	else tags = {"ImeitemIMCommand1","refNum","sref","srefIxVRettype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], refNum);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWdbeVMCommandRettype::getSref(ixVRettype));
		writeString(wr, tags[4], Comment);
		imeiamcommandinvpar1.writeXML(wr, shorttags);
		imeiamcommandretpar1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMCommand1::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMCommand1::VecWIel::getIx(
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

void IexWdbeDdd::ImeIMCommand1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMCommand1::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMCommand1
 ******************************************************************************/

IexWdbeDdd::ImeIMCommand1::ImeIMCommand1() {
};

IexWdbeDdd::ImeIMCommand1::~ImeIMCommand1() {
	clear();
};

void IexWdbeDdd::ImeIMCommand1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMCommand1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMCommand1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDdd::ImeitemIMCommand1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCommand1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCommand1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCOMMAND1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCommand1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCommand1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMCommand1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMCommand1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCommand1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCommand1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCommand1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMCommand1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMCommand1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMCommand1." << StrMod::replaceChar(ImeIMCommand1::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMCommand1.end" << endl;
	};
};

void IexWdbeDdd::ImeIMCommand1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCommand1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIAMErrorPar1
 ******************************************************************************/

IexWdbeDdd::ImeitemIAMErrorPar1::ImeitemIAMErrorPar1(
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

IexWdbeDdd::ImeitemIAMErrorPar1::ImeitemIAMErrorPar1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMErrorPar1()
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

void IexWdbeDdd::ImeitemIAMErrorPar1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMErrorPar1::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWdbeVPartype = txtrd.fields[1]; ixWIelValid += ImeIAMErrorPar1::VecWIel::SREFIXWDBEVPARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWdbeMVector = txtrd.fields[2]; ixWIelValid += ImeIAMErrorPar1::VecWIel::SREFREFWDBEMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMErrorPar1::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMErrorPar1::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMErrorPar1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIAMErrorPar1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMErrorPar1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype)) ixWIelValid += ImeIAMErrorPar1::VecWIel::SREFIXWDBEVPARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVector", "vec", srefRefWdbeMVector)) ixWIelValid += ImeIAMErrorPar1::VecWIel::SREFREFWDBEMVECTOR;
		if (extractUtinyintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMErrorPar1::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMErrorPar1::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIAMErrorPar1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIAMErrorPar1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","pty","vec","len","cmt"};
	else tags = {"ImeitemIAMErrorPar1","sref","srefIxWdbeVPartype","srefRefWdbeMVector","Length","Comment"};

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
 class IexWdbeDdd::ImeIAMErrorPar1::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIAMErrorPar1::VecWIel::getIx(
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

void IexWdbeDdd::ImeIAMErrorPar1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIAMErrorPar1::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIAMErrorPar1
 ******************************************************************************/

IexWdbeDdd::ImeIAMErrorPar1::ImeIAMErrorPar1() {
};

IexWdbeDdd::ImeIAMErrorPar1::~ImeIAMErrorPar1() {
	clear();
};

void IexWdbeDdd::ImeIAMErrorPar1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIAMErrorPar1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIAMErrorPar1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIAMErrorPar1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMErrorPar1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMErrorPar1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMERRORPAR1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMErrorPar1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMErrorPar1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIAMErrorPar1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIAMErrorPar1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMErrorPar1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMErrorPar1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMErrorPar1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIAMErrorPar1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIAMErrorPar1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMErrorPar1." << StrMod::replaceChar(ImeIAMErrorPar1::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMErrorPar1.end" << endl;
	};
};

void IexWdbeDdd::ImeIAMErrorPar1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMErrorPar1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMError1
 ******************************************************************************/

IexWdbeDdd::ImeitemIMError1::ImeitemIMError1(
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

IexWdbeDdd::ImeitemIMError1::ImeitemIMError1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMError1()
		{
	WdbeMError* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemerror->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		sref = rec->sref;
		Fullsref = rec->Fullsref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDdd::ImeitemIMError1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {refNum = atol(txtrd.fields[0].c_str()); ixWIelValid += ImeIMError1::VecWIel::REFNUM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMError1::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMError1::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAMERRORPAR1)) {
					imeiamerrorpar1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMError1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMError1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUintUclc(docctx, basexpath, "refNum", "ren", refNum)) ixWIelValid += ImeIMError1::VecWIel::REFNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMError1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMError1::VecWIel::COMMENT;
		imeiamerrorpar1.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMError1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << refNum << "\t" << sref << "\t" << Comment << endl;
	imeiamerrorpar1.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMError1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ren","srf","cmt"};
	else tags = {"ImeitemIMError1","refNum","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], refNum);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Comment);
		imeiamerrorpar1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMError1::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMError1::VecWIel::getIx(
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

void IexWdbeDdd::ImeIMError1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMError1::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMError1
 ******************************************************************************/

IexWdbeDdd::ImeIMError1::ImeIMError1() {
};

IexWdbeDdd::ImeIMError1::~ImeIMError1() {
	clear();
};

void IexWdbeDdd::ImeIMError1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMError1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMError1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDdd::ImeitemIMError1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMError1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMERROR1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMError1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMError1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMError1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMError1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMError1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMError1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMError1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMError1." << StrMod::replaceChar(ImeIMError1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMError1.end" << endl;
	};
};

void IexWdbeDdd::ImeIMError1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMError1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemICGeneric
 ******************************************************************************/

IexWdbeDdd::ImeitemICGeneric::ImeitemICGeneric(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDdd::ImeitemICGeneric::ImeitemICGeneric(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICGeneric()
		{
};

void IexWdbeDdd::ImeitemICGeneric::readTxt(
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

void IexWdbeDdd::ImeitemICGeneric::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICGeneric::VecWIel::IREF;
	};
};

void IexWdbeDdd::ImeitemICGeneric::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeDdd::ImeitemICGeneric::writeXML(
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
 class IexWdbeDdd::ImeICGeneric::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeICGeneric::VecWIel::getIx(
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

void IexWdbeDdd::ImeICGeneric::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeICGeneric::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeICGeneric
 ******************************************************************************/

IexWdbeDdd::ImeICGeneric::ImeICGeneric() {
};

IexWdbeDdd::ImeICGeneric::~ImeICGeneric() {
	clear();
};

void IexWdbeDdd::ImeICGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeICGeneric::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemICGeneric* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemICGeneric();
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

void IexWdbeDdd::ImeICGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemICGeneric* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemICGeneric();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeICGeneric::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICGeneric." << StrMod::replaceChar(ImeICGeneric::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICGeneric.end" << endl;
	};
};

void IexWdbeDdd::ImeICGeneric::writeXML(
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
 class IexWdbeDdd::ImeitemICPort
 ******************************************************************************/

IexWdbeDdd::ImeitemICPort::ImeitemICPort(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDdd::ImeitemICPort::ImeitemICPort(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICPort()
		{
};

void IexWdbeDdd::ImeitemICPort::readTxt(
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

void IexWdbeDdd::ImeitemICPort::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICPort::VecWIel::IREF;
	};
};

void IexWdbeDdd::ImeitemICPort::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeDdd::ImeitemICPort::writeXML(
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
 class IexWdbeDdd::ImeICPort::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeICPort::VecWIel::getIx(
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

void IexWdbeDdd::ImeICPort::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeICPort::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeICPort
 ******************************************************************************/

IexWdbeDdd::ImeICPort::ImeICPort() {
};

IexWdbeDdd::ImeICPort::~ImeICPort() {
	clear();
};

void IexWdbeDdd::ImeICPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeICPort::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemICPort* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemICPort();
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

void IexWdbeDdd::ImeICPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemICPort* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemICPort();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeICPort::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICPort." << StrMod::replaceChar(ImeICPort::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICPort.end" << endl;
	};
};

void IexWdbeDdd::ImeICPort::writeXML(
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
 class IexWdbeDdd::ImeitemICSignal
 ******************************************************************************/

IexWdbeDdd::ImeitemICSignal::ImeitemICSignal(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDdd::ImeitemICSignal::ImeitemICSignal(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICSignal()
		{
};

void IexWdbeDdd::ImeitemICSignal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICSignal::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICSignal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemICSignal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICSignal::VecWIel::IREF;
	};
};

void IexWdbeDdd::ImeitemICSignal::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeDdd::ImeitemICSignal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICSignal","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeICSignal::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeICSignal::VecWIel::getIx(
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

void IexWdbeDdd::ImeICSignal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeICSignal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeICSignal
 ******************************************************************************/

IexWdbeDdd::ImeICSignal::ImeICSignal() {
};

IexWdbeDdd::ImeICSignal::~ImeICSignal() {
	clear();
};

void IexWdbeDdd::ImeICSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeICSignal::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemICSignal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemICSignal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSignal"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICSignal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICSIGNAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSignal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSignal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeICSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemICSignal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICSignal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICSignal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICSignal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemICSignal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeICSignal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICSignal." << StrMod::replaceChar(ImeICSignal::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICSignal.end" << endl;
	};
};

void IexWdbeDdd::ImeICSignal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICSignal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIAMCommandInvpar2
 ******************************************************************************/

IexWdbeDdd::ImeitemIAMCommandInvpar2::ImeitemIAMCommandInvpar2(
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

IexWdbeDdd::ImeitemIAMCommandInvpar2::ImeitemIAMCommandInvpar2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMCommandInvpar2()
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

void IexWdbeDdd::ImeitemIAMCommandInvpar2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMCommandInvpar2::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWdbeVPartype = txtrd.fields[1]; ixWIelValid += ImeIAMCommandInvpar2::VecWIel::SREFIXWDBEVPARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWdbeMVector = txtrd.fields[2]; ixWIelValid += ImeIAMCommandInvpar2::VecWIel::SREFREFWDBEMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMCommandInvpar2::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Defval = txtrd.fields[4]; ixWIelValid += ImeIAMCommandInvpar2::VecWIel::DEFVAL;};
	if (txtrd.fields.size() > 5) {srefRefWdbeMVectoritem = txtrd.fields[5]; ixWIelValid += ImeIAMCommandInvpar2::VecWIel::SREFREFWDBEMVECTORITEM;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIAMCommandInvpar2::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandInvpar2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIAMCommandInvpar2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMCommandInvpar2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype)) ixWIelValid += ImeIAMCommandInvpar2::VecWIel::SREFIXWDBEVPARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVector", "vec", srefRefWdbeMVector)) ixWIelValid += ImeIAMCommandInvpar2::VecWIel::SREFREFWDBEMVECTOR;
		if (extractUtinyintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMCommandInvpar2::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Defval", "dfv", Defval)) ixWIelValid += ImeIAMCommandInvpar2::VecWIel::DEFVAL;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVectoritem", "vit", srefRefWdbeMVectoritem)) ixWIelValid += ImeIAMCommandInvpar2::VecWIel::SREFREFWDBEMVECTORITEM;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMCommandInvpar2::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIAMCommandInvpar2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Defval << "\t" << srefRefWdbeMVectoritem << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIAMCommandInvpar2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","pty","vec","len","dfv","vit","cmt"};
	else tags = {"ImeitemIAMCommandInvpar2","sref","srefIxWdbeVPartype","srefRefWdbeMVector","Length","Defval","srefRefWdbeMVectoritem","Comment"};

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
 class IexWdbeDdd::ImeIAMCommandInvpar2::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIAMCommandInvpar2::VecWIel::getIx(
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

void IexWdbeDdd::ImeIAMCommandInvpar2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIAMCommandInvpar2::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIAMCommandInvpar2
 ******************************************************************************/

IexWdbeDdd::ImeIAMCommandInvpar2::ImeIAMCommandInvpar2() {
};

IexWdbeDdd::ImeIAMCommandInvpar2::~ImeIAMCommandInvpar2() {
	clear();
};

void IexWdbeDdd::ImeIAMCommandInvpar2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIAMCommandInvpar2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIAMCommandInvpar2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeDdd::ImeitemIAMCommandInvpar2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandInvpar2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandInvpar2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDINVPAR2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandInvpar2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandInvpar2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIAMCommandInvpar2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIAMCommandInvpar2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCommandInvpar2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCommandInvpar2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCommandInvpar2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIAMCommandInvpar2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIAMCommandInvpar2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIAMCommandInvpar2." << StrMod::replaceChar(ImeIAMCommandInvpar2::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIAMCommandInvpar2.end" << endl;
	};
};

void IexWdbeDdd::ImeIAMCommandInvpar2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCommandInvpar2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIAMCommandRetpar2
 ******************************************************************************/

IexWdbeDdd::ImeitemIAMCommandRetpar2::ImeitemIAMCommandRetpar2(
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

IexWdbeDdd::ImeitemIAMCommandRetpar2::ImeitemIAMCommandRetpar2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMCommandRetpar2()
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

void IexWdbeDdd::ImeitemIAMCommandRetpar2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMCommandRetpar2::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWdbeVPartype = txtrd.fields[1]; ixWIelValid += ImeIAMCommandRetpar2::VecWIel::SREFIXWDBEVPARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWdbeMVector = txtrd.fields[2]; ixWIelValid += ImeIAMCommandRetpar2::VecWIel::SREFREFWDBEMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMCommandRetpar2::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMCommandRetpar2::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandRetpar2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIAMCommandRetpar2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMCommandRetpar2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype)) ixWIelValid += ImeIAMCommandRetpar2::VecWIel::SREFIXWDBEVPARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVector", "vec", srefRefWdbeMVector)) ixWIelValid += ImeIAMCommandRetpar2::VecWIel::SREFREFWDBEMVECTOR;
		if (extractUtinyintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMCommandRetpar2::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMCommandRetpar2::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIAMCommandRetpar2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIAMCommandRetpar2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","pty","vec","len","cmt"};
	else tags = {"ImeitemIAMCommandRetpar2","sref","srefIxWdbeVPartype","srefRefWdbeMVector","Length","Comment"};

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
 class IexWdbeDdd::ImeIAMCommandRetpar2::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIAMCommandRetpar2::VecWIel::getIx(
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

void IexWdbeDdd::ImeIAMCommandRetpar2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIAMCommandRetpar2::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIAMCommandRetpar2
 ******************************************************************************/

IexWdbeDdd::ImeIAMCommandRetpar2::ImeIAMCommandRetpar2() {
};

IexWdbeDdd::ImeIAMCommandRetpar2::~ImeIAMCommandRetpar2() {
	clear();
};

void IexWdbeDdd::ImeIAMCommandRetpar2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIAMCommandRetpar2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIAMCommandRetpar2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeDdd::ImeitemIAMCommandRetpar2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandRetpar2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCommandRetpar2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDRETPAR2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandRetpar2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCommandRetpar2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIAMCommandRetpar2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIAMCommandRetpar2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCommandRetpar2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCommandRetpar2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCommandRetpar2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIAMCommandRetpar2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIAMCommandRetpar2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIAMCommandRetpar2." << StrMod::replaceChar(ImeIAMCommandRetpar2::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIAMCommandRetpar2.end" << endl;
	};
};

void IexWdbeDdd::ImeIAMCommandRetpar2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCommandRetpar2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMCommand2
 ******************************************************************************/

IexWdbeDdd::ImeitemIMCommand2::ImeitemIMCommand2(
			const uint refNum
			, const string& sref
			, const uint ixVRettype
			, const string& srefIvrRefWdbeMSignal
			, const string& srefRvrRefWdbeMSignal
			, const string& srefRerRefWdbeMSignal
			, const string& Comment
		) : WdbeMCommand() {
	lineno = 0;
	ixWIelValid = 0;

	this->refNum = refNum;
	this->sref = sref;
	this->ixVRettype = ixVRettype;
	this->srefIvrRefWdbeMSignal = srefIvrRefWdbeMSignal;
	this->srefRvrRefWdbeMSignal = srefRvrRefWdbeMSignal;
	this->srefRerRefWdbeMSignal = srefRerRefWdbeMSignal;
	this->Comment = Comment;
};

IexWdbeDdd::ImeitemIMCommand2::ImeitemIMCommand2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMCommand2()
		{
	WdbeMCommand* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemcommand->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		sref = rec->sref;
		Fullsref = rec->Fullsref;
		ixVRettype = rec->ixVRettype;
		ivrRefWdbeMSignal = rec->ivrRefWdbeMSignal;
		rvrRefWdbeMSignal = rec->rvrRefWdbeMSignal;
		rerRefWdbeMSignal = rec->rerRefWdbeMSignal;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDdd::ImeitemIMCommand2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {refNum = atol(txtrd.fields[0].c_str()); ixWIelValid += ImeIMCommand2::VecWIel::REFNUM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMCommand2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxVRettype = txtrd.fields[2]; ixWIelValid += ImeIMCommand2::VecWIel::SREFIXVRETTYPE;};
	if (txtrd.fields.size() > 3) {srefIvrRefWdbeMSignal = txtrd.fields[3]; ixWIelValid += ImeIMCommand2::VecWIel::SREFIVRREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 4) {srefRvrRefWdbeMSignal = txtrd.fields[4]; ixWIelValid += ImeIMCommand2::VecWIel::SREFRVRREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 5) {srefRerRefWdbeMSignal = txtrd.fields[5]; ixWIelValid += ImeIMCommand2::VecWIel::SREFRERREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMCommand2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDINVPAR2)) {
					imeiamcommandinvpar2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIAMCOMMANDRETPAR2)) {
					imeiamcommandretpar2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCommand2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMCommand2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUintUclc(docctx, basexpath, "refNum", "ren", refNum)) ixWIelValid += ImeIMCommand2::VecWIel::REFNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCommand2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVRettype", "rty", srefIxVRettype)) ixWIelValid += ImeIMCommand2::VecWIel::SREFIXVRETTYPE;
		if (extractStringUclc(docctx, basexpath, "srefIvrRefWdbeMSignal", "ivr", srefIvrRefWdbeMSignal)) ixWIelValid += ImeIMCommand2::VecWIel::SREFIVRREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefRvrRefWdbeMSignal", "rvr", srefRvrRefWdbeMSignal)) ixWIelValid += ImeIMCommand2::VecWIel::SREFRVRREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefRerRefWdbeMSignal", "rer", srefRerRefWdbeMSignal)) ixWIelValid += ImeIMCommand2::VecWIel::SREFRERREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMCommand2::VecWIel::COMMENT;
		imeiamcommandinvpar2.readXML(docctx, basexpath);
		imeiamcommandretpar2.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMCommand2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << refNum << "\t" << sref << "\t" << VecWdbeVMCommandRettype::getSref(ixVRettype) << "\t" << srefIvrRefWdbeMSignal << "\t" << srefRvrRefWdbeMSignal << "\t" << srefRerRefWdbeMSignal << "\t" << Comment << endl;
	imeiamcommandinvpar2.writeTxt(outfile);
	imeiamcommandretpar2.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMCommand2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ren","srf","rty","ivr","rvr","rer","cmt"};
	else tags = {"ImeitemIMCommand2","refNum","sref","srefIxVRettype","srefIvrRefWdbeMSignal","srefRvrRefWdbeMSignal","srefRerRefWdbeMSignal","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], refNum);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWdbeVMCommandRettype::getSref(ixVRettype));
		writeString(wr, tags[4], srefIvrRefWdbeMSignal);
		writeString(wr, tags[5], srefRvrRefWdbeMSignal);
		writeString(wr, tags[6], srefRerRefWdbeMSignal);
		writeString(wr, tags[7], Comment);
		imeiamcommandinvpar2.writeXML(wr, shorttags);
		imeiamcommandretpar2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMCommand2::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMCommand2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "refnum") ix |= REFNUM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvrettype") ix |= SREFIXVRETTYPE;
		else if (ss[i] == "srefivrrefwdbemsignal") ix |= SREFIVRREFWDBEMSIGNAL;
		else if (ss[i] == "srefrvrrefwdbemsignal") ix |= SREFRVRREFWDBEMSIGNAL;
		else if (ss[i] == "srefrerrefwdbemsignal") ix |= SREFRERREFWDBEMSIGNAL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMCommand2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMCommand2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & REFNUM) ss.push_back("refNum");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVRETTYPE) ss.push_back("srefIxVRettype");
	if (ix & SREFIVRREFWDBEMSIGNAL) ss.push_back("srefIvrRefWdbeMSignal");
	if (ix & SREFRVRREFWDBEMSIGNAL) ss.push_back("srefRvrRefWdbeMSignal");
	if (ix & SREFRERREFWDBEMSIGNAL) ss.push_back("srefRerRefWdbeMSignal");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMCommand2
 ******************************************************************************/

IexWdbeDdd::ImeIMCommand2::ImeIMCommand2() {
};

IexWdbeDdd::ImeIMCommand2::~ImeIMCommand2() {
	clear();
};

void IexWdbeDdd::ImeIMCommand2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMCommand2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMCommand2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemIMCommand2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCommand2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMCommand2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMCOMMAND2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCommand2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMCommand2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMCommand2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMCommand2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMCommand2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMCommand2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMCommand2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMCommand2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMCommand2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMCommand2." << StrMod::replaceChar(ImeIMCommand2::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMCommand2.end" << endl;
	};
};

void IexWdbeDdd::ImeIMCommand2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMCommand2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIAMErrorPar2
 ******************************************************************************/

IexWdbeDdd::ImeitemIAMErrorPar2::ImeitemIAMErrorPar2(
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

IexWdbeDdd::ImeitemIAMErrorPar2::ImeitemIAMErrorPar2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMErrorPar2()
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

void IexWdbeDdd::ImeitemIAMErrorPar2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMErrorPar2::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxWdbeVPartype = txtrd.fields[1]; ixWIelValid += ImeIAMErrorPar2::VecWIel::SREFIXWDBEVPARTYPE;};
	if (txtrd.fields.size() > 2) {srefRefWdbeMVector = txtrd.fields[2]; ixWIelValid += ImeIAMErrorPar2::VecWIel::SREFREFWDBEMVECTOR;};
	if (txtrd.fields.size() > 3) {Length = atoi(txtrd.fields[3].c_str()); ixWIelValid += ImeIAMErrorPar2::VecWIel::LENGTH;};
	if (txtrd.fields.size() > 4) {Comment = txtrd.fields[4]; ixWIelValid += ImeIAMErrorPar2::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMErrorPar2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIAMErrorPar2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMErrorPar2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVPartype", "pty", srefIxWdbeVPartype)) ixWIelValid += ImeIAMErrorPar2::VecWIel::SREFIXWDBEVPARTYPE;
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMVector", "vec", srefRefWdbeMVector)) ixWIelValid += ImeIAMErrorPar2::VecWIel::SREFREFWDBEMVECTOR;
		if (extractUtinyintUclc(docctx, basexpath, "Length", "len", Length)) ixWIelValid += ImeIAMErrorPar2::VecWIel::LENGTH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMErrorPar2::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIAMErrorPar2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIAMErrorPar2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","pty","vec","len","cmt"};
	else tags = {"ImeitemIAMErrorPar2","sref","srefIxWdbeVPartype","srefRefWdbeMVector","Length","Comment"};

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
 class IexWdbeDdd::ImeIAMErrorPar2::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIAMErrorPar2::VecWIel::getIx(
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

void IexWdbeDdd::ImeIAMErrorPar2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIAMErrorPar2::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIAMErrorPar2
 ******************************************************************************/

IexWdbeDdd::ImeIAMErrorPar2::ImeIAMErrorPar2() {
};

IexWdbeDdd::ImeIAMErrorPar2::~ImeIAMErrorPar2() {
	clear();
};

void IexWdbeDdd::ImeIAMErrorPar2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIAMErrorPar2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIAMErrorPar2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeDdd::ImeitemIAMErrorPar2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMErrorPar2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMErrorPar2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMERRORPAR2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMErrorPar2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMErrorPar2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIAMErrorPar2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIAMErrorPar2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMErrorPar2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMErrorPar2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMErrorPar2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIAMErrorPar2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIAMErrorPar2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIAMErrorPar2." << StrMod::replaceChar(ImeIAMErrorPar2::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIAMErrorPar2.end" << endl;
	};
};

void IexWdbeDdd::ImeIAMErrorPar2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMErrorPar2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMError2
 ******************************************************************************/

IexWdbeDdd::ImeitemIMError2::ImeitemIMError2(
			const uint refNum
			, const string& sref
			, const string& srefTraRefWdbeMSignal
			, const string& Comment
		) : WdbeMError() {
	lineno = 0;
	ixWIelValid = 0;

	this->refNum = refNum;
	this->sref = sref;
	this->srefTraRefWdbeMSignal = srefTraRefWdbeMSignal;
	this->Comment = Comment;
};

IexWdbeDdd::ImeitemIMError2::ImeitemIMError2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMError2()
		{
	WdbeMError* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemerror->loadRecByRef(ref, &rec)) {
		refIxVTbl = rec->refIxVTbl;
		refUref = rec->refUref;
		refNum = rec->refNum;
		sref = rec->sref;
		Fullsref = rec->Fullsref;
		traRefWdbeMSignal = rec->traRefWdbeMSignal;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDdd::ImeitemIMError2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {refNum = atol(txtrd.fields[0].c_str()); ixWIelValid += ImeIMError2::VecWIel::REFNUM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMError2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefTraRefWdbeMSignal = txtrd.fields[2]; ixWIelValid += ImeIMError2::VecWIel::SREFTRAREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMError2::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIAMERRORPAR2)) {
					imeiamerrorpar2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMError2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMError2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUintUclc(docctx, basexpath, "refNum", "ren", refNum)) ixWIelValid += ImeIMError2::VecWIel::REFNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMError2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefTraRefWdbeMSignal", "tra", srefTraRefWdbeMSignal)) ixWIelValid += ImeIMError2::VecWIel::SREFTRAREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMError2::VecWIel::COMMENT;
		imeiamerrorpar2.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMError2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << refNum << "\t" << sref << "\t" << srefTraRefWdbeMSignal << "\t" << Comment << endl;
	imeiamerrorpar2.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMError2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ren","srf","tra","cmt"};
	else tags = {"ImeitemIMError2","refNum","sref","srefTraRefWdbeMSignal","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], refNum);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefTraRefWdbeMSignal);
		writeString(wr, tags[4], Comment);
		imeiamerrorpar2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMError2::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMError2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "refnum") ix |= REFNUM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "sreftrarefwdbemsignal") ix |= SREFTRAREFWDBEMSIGNAL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMError2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMError2::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & REFNUM) ss.push_back("refNum");
	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFTRAREFWDBEMSIGNAL) ss.push_back("srefTraRefWdbeMSignal");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMError2
 ******************************************************************************/

IexWdbeDdd::ImeIMError2::ImeIMError2() {
};

IexWdbeDdd::ImeIMError2::~ImeIMError2() {
	clear();
};

void IexWdbeDdd::ImeIMError2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMError2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMError2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemIMError2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMError2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMERROR2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMError2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMError2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMError2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMError2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMError2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMError2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMError2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMError2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMError2." << StrMod::replaceChar(ImeIMError2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMError2.end" << endl;
	};
};

void IexWdbeDdd::ImeIMError2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMError2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMVectoritem2
 ******************************************************************************/

IexWdbeDdd::ImeitemIMVectoritem2::ImeitemIMVectoritem2(
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

IexWdbeDdd::ImeitemIMVectoritem2::ImeitemIMVectoritem2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVectoritem2()
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

void IexWdbeDdd::ImeitemIMVectoritem2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMVectoritem2::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMVectoritem2::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMVectoritem2::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMVectoritem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVectoritem2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMVectoritem2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVectoritem2::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIMVectoritem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIMVectoritem2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","cmt"};
	else tags = {"ImeitemIMVectoritem2","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMVectoritem2::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMVectoritem2::VecWIel::getIx(
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

void IexWdbeDdd::ImeIMVectoritem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMVectoritem2::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMVectoritem2
 ******************************************************************************/

IexWdbeDdd::ImeIMVectoritem2::ImeIMVectoritem2() {
};

IexWdbeDdd::ImeIMVectoritem2::~ImeIMVectoritem2() {
	clear();
};

void IexWdbeDdd::ImeIMVectoritem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMVectoritem2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMVectoritem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeDdd::ImeitemIMVectoritem2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMVectoritem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMVectoritem2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVectoritem2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVectoritem2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVectoritem2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMVectoritem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMVectoritem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIMVectoritem2." << StrMod::replaceChar(ImeIMVectoritem2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIMVectoritem2.end" << endl;
	};
};

void IexWdbeDdd::ImeIMVectoritem2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVectoritem2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMVector2
 ******************************************************************************/

IexWdbeDdd::ImeitemIMVector2::ImeitemIMVector2(
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

IexWdbeDdd::ImeitemIMVector2::ImeitemIMVector2(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVector2()
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

void IexWdbeDdd::ImeitemIMVector2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMVector2::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVector2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefsKOption = txtrd.fields[2]; ixWIelValid += ImeIMVector2::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM2)) {
					imeimvectoritem2.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector2"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMVector2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector2::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector2::VecWIel::SREFSKOPTION;
		imeimvectoritem2.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMVector2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWdbeVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << srefsKOption << endl;
	imeimvectoritem2.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMVector2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","opt"};
	else tags = {"ImeitemIMVector2","srefIxVBasetype","sref","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMVectorBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefsKOption);
		imeimvectoritem2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMVector2::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMVector2::VecWIel::getIx(
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

void IexWdbeDdd::ImeIMVector2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMVector2::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMVector2
 ******************************************************************************/

IexWdbeDdd::ImeIMVector2::ImeIMVector2() {
};

IexWdbeDdd::ImeIMVector2::~ImeIMVector2() {
	clear();
};

void IexWdbeDdd::ImeIMVector2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMVector2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMVector2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemIMVector2();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTOR2) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector2"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMVector2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMVector2* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVector2");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVector2", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVector2";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMVector2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMVector2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMVector2." << StrMod::replaceChar(ImeIMVector2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMVector2.end" << endl;
	};
};

void IexWdbeDdd::ImeIMVector2::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVector2");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIRMCommandMController
 ******************************************************************************/

IexWdbeDdd::ImeitemIRMCommandMController::ImeitemIRMCommandMController(
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

IexWdbeDdd::ImeitemIRMCommandMController::ImeitemIRMCommandMController(
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

void IexWdbeDdd::ImeitemIRMCommandMController::readTxt(
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

void IexWdbeDdd::ImeitemIRMCommandMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMCommand", "cmd", srefRefWdbeMCommand)) ixWIelValid += ImeIRMCommandMController::VecWIel::SREFREFWDBEMCOMMAND;
		if (extractStringUclc(docctx, basexpath, "srefIvrRefWdbeMSignal", "ivr", srefIvrRefWdbeMSignal)) ixWIelValid += ImeIRMCommandMController::VecWIel::SREFIVRREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefRvrRefWdbeMSignal", "rvr", srefRvrRefWdbeMSignal)) ixWIelValid += ImeIRMCommandMController::VecWIel::SREFRVRREFWDBEMSIGNAL;
	};
};

void IexWdbeDdd::ImeitemIRMCommandMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefRefWdbeMCommand << "\t" << srefIvrRefWdbeMSignal << "\t" << srefRvrRefWdbeMSignal << endl;
};

void IexWdbeDdd::ImeitemIRMCommandMController::writeXML(
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
 class IexWdbeDdd::ImeIRMCommandMController::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIRMCommandMController::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwdbemcommand") ix |= SREFREFWDBEMCOMMAND;
		else if (ss[i] == "srefivrrefwdbemsignal") ix |= SREFIVRREFWDBEMSIGNAL;
		else if (ss[i] == "srefrvrrefwdbemsignal") ix |= SREFRVRREFWDBEMSIGNAL;
	};

	return(ix);
};

void IexWdbeDdd::ImeIRMCommandMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFRVRREFWDBEMSIGNAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIRMCommandMController::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIRMCommandMController
 ******************************************************************************/

IexWdbeDdd::ImeIRMCommandMController::ImeIRMCommandMController() {
};

IexWdbeDdd::ImeIRMCommandMController::~ImeIRMCommandMController() {
	clear();
};

void IexWdbeDdd::ImeIRMCommandMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIRMCommandMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIRMCommandMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemIRMCommandMController();
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

void IexWdbeDdd::ImeIRMCommandMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIRMCommandMController* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIRMCommandMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIRMCommandMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIRMCommandMController." << StrMod::replaceChar(ImeIRMCommandMController::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIRMCommandMController.end" << endl;
	};
};

void IexWdbeDdd::ImeIRMCommandMController::writeXML(
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
 class IexWdbeDdd::ImeitemIMController
 ******************************************************************************/

IexWdbeDdd::ImeitemIMController::ImeitemIMController(
			const uint ixWdbeVIop
			, const string& srefClrRefWdbeMSignal
		) : WdbeMController() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWdbeVIop = ixWdbeVIop;
	this->srefClrRefWdbeMSignal = srefClrRefWdbeMSignal;
};

IexWdbeDdd::ImeitemIMController::ImeitemIMController(
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

void IexWdbeDdd::ImeitemIMController::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWdbeVIop = txtrd.fields[0]; ixWIelValid += ImeIMController::VecWIel::SREFIXWDBEVIOP;};
	if (txtrd.fields.size() > 1) {srefClrRefWdbeMSignal = txtrd.fields[1]; ixWIelValid += ImeIMController::VecWIel::SREFCLRREFWDBEMSIGNAL;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMCOMMAND2)) {
					imeimcommand2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMERROR2)) {
					imeimerror2.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMVECTOR2)) {
					imeimvector2.readTxt(txtrd);
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

void IexWdbeDdd::ImeitemIMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVIop", "iop", srefIxWdbeVIop)) ixWIelValid += ImeIMController::VecWIel::SREFIXWDBEVIOP;
		if (extractStringUclc(docctx, basexpath, "srefClrRefWdbeMSignal", "clr", srefClrRefWdbeMSignal)) ixWIelValid += ImeIMController::VecWIel::SREFCLRREFWDBEMSIGNAL;
		imeimcommand2.readXML(docctx, basexpath);
		imeimerror2.readXML(docctx, basexpath);
		imeimvector2.readXML(docctx, basexpath);
		imeirmcommandmcontroller.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << srefClrRefWdbeMSignal << endl;
	imeimcommand2.writeTxt(outfile);
	imeimerror2.writeTxt(outfile);
	imeimvector2.writeTxt(outfile);
	imeirmcommandmcontroller.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMController::writeXML(
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
		imeimcommand2.writeXML(wr, shorttags);
		imeimerror2.writeXML(wr, shorttags);
		imeimvector2.writeXML(wr, shorttags);
		imeirmcommandmcontroller.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMController::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMController::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixwdbeviop") ix |= SREFIXWDBEVIOP;
		else if (ss[i] == "srefclrrefwdbemsignal") ix |= SREFCLRREFWDBEMSIGNAL;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFCLRREFWDBEMSIGNAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMController::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMController
 ******************************************************************************/

IexWdbeDdd::ImeIMController::ImeIMController() {
};

IexWdbeDdd::ImeIMController::~ImeIMController() {
	clear();
};

void IexWdbeDdd::ImeIMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIMController();
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

void IexWdbeDdd::ImeIMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMController* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMController." << StrMod::replaceChar(ImeIMController::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMController.end" << endl;
	};
};

void IexWdbeDdd::ImeIMController::writeXML(
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
 class IexWdbeDdd::ImeitemIMGeneric
 ******************************************************************************/

IexWdbeDdd::ImeitemIMGeneric::ImeitemIMGeneric(
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

IexWdbeDdd::ImeitemIMGeneric::ImeitemIMGeneric(
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

void IexWdbeDdd::ImeitemIMGeneric::readTxt(
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

void IexWdbeDdd::ImeitemIMGeneric::readXML(
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

void IexWdbeDdd::ImeitemIMGeneric::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << irefRefWdbeCGeneric << "\t" << sref << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Defval << "\t" << srcSrefWdbeMGeneric << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIMGeneric::writeXML(
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
 class IexWdbeDdd::ImeIMGeneric::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMGeneric::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

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

void IexWdbeDdd::ImeIMGeneric::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMGeneric::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMGeneric
 ******************************************************************************/

IexWdbeDdd::ImeIMGeneric::ImeIMGeneric() {
};

IexWdbeDdd::ImeIMGeneric::~ImeIMGeneric() {
	clear();
};

void IexWdbeDdd::ImeIMGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMGeneric::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMGeneric* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIMGeneric();
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

void IexWdbeDdd::ImeIMGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMGeneric* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMGeneric();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMGeneric::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMGeneric." << StrMod::replaceChar(ImeIMGeneric::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMGeneric.end" << endl;
	};
};

void IexWdbeDdd::ImeIMGeneric::writeXML(
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
 class IexWdbeDdd::ImeitemIMImbuf
 ******************************************************************************/

IexWdbeDdd::ImeitemIMImbuf::ImeitemIMImbuf(
			const utinyint Prio
		) : WdbeMImbuf() {
	lineno = 0;
	ixWIelValid = 0;

	this->Prio = Prio;
};

IexWdbeDdd::ImeitemIMImbuf::ImeitemIMImbuf(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMImbuf()
		{
	WdbeMImbuf* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemimbuf->loadRecByRef(ref, &rec)) {
		refWdbeMModule = rec->refWdbeMModule;
		Prio = rec->Prio;

		delete rec;
	};
};

void IexWdbeDdd::ImeitemIMImbuf::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {Prio = atoi(txtrd.fields[0].c_str()); ixWIelValid += ImeIMImbuf::VecWIel::PRIO;};

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

void IexWdbeDdd::ImeitemIMImbuf::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUtinyintUclc(docctx, basexpath, "Prio", "pri", Prio)) ixWIelValid += ImeIMImbuf::VecWIel::PRIO;
	};
};

void IexWdbeDdd::ImeitemIMImbuf::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << Prio << endl;
};

void IexWdbeDdd::ImeitemIMImbuf::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","pri"};
	else tags = {"ImeitemIMImbuf","Prio"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUtinyint(wr, tags[1], Prio);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMImbuf::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMImbuf::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "prio") ix |= PRIO;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMImbuf::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*PRIO); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMImbuf::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & PRIO) ss.push_back("Prio");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMImbuf
 ******************************************************************************/

IexWdbeDdd::ImeIMImbuf::ImeIMImbuf() {
};

IexWdbeDdd::ImeIMImbuf::~ImeIMImbuf() {
	clear();
};

void IexWdbeDdd::ImeIMImbuf::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMImbuf::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMImbuf* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIMImbuf();
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

void IexWdbeDdd::ImeIMImbuf::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMImbuf* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMImbuf();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMImbuf::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMImbuf." << StrMod::replaceChar(ImeIMImbuf::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMImbuf.end" << endl;
	};
};

void IexWdbeDdd::ImeIMImbuf::writeXML(
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
 class IexWdbeDdd::ImeitemIMPort
 ******************************************************************************/

IexWdbeDdd::ImeitemIMPort::ImeitemIMPort(
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

IexWdbeDdd::ImeitemIMPort::ImeitemIMPort(
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

void IexWdbeDdd::ImeitemIMPort::readTxt(
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

void IexWdbeDdd::ImeitemIMPort::readXML(
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

void IexWdbeDdd::ImeitemIMPort::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << irefRefWdbeCPort << "\t" << VecWdbeVMPortMdlCat::getSref(mdlIxVCat) << "\t" << sref << "\t" << VecWdbeVMPortDir::getSref(ixVDir) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Defval << "\t" << cpiSrefWdbeMPin << "\t" << cprSrefWdbeMPort << "\t" << csiSrefWdbeMSignal << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIMPort::writeXML(
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
 class IexWdbeDdd::ImeIMPort::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMPort::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

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

void IexWdbeDdd::ImeIMPort::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMPort::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMPort
 ******************************************************************************/

IexWdbeDdd::ImeIMPort::ImeIMPort() {
};

IexWdbeDdd::ImeIMPort::~ImeIMPort() {
	clear();
};

void IexWdbeDdd::ImeIMPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMPort::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMPort* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIMPort();
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

void IexWdbeDdd::ImeIMPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMPort* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMPort();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMPort::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPort." << StrMod::replaceChar(ImeIMPort::VecWIel::getSrefs(8191), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPort.end" << endl;
	};
};

void IexWdbeDdd::ImeIMPort::writeXML(
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
 class IexWdbeDdd::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexWdbeDdd::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			const string& Title
			, const string& Comment
		) : WdbeJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeDdd::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
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

void IexWdbeDdd::ImeitemIJAVKeylistKey::readTxt(
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

void IexWdbeDdd::ImeitemIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << Title << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIJAVKeylistKey::writeXML(
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
 class IexWdbeDdd::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIJAVKeylistKey::VecWIel::getIx(
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

void IexWdbeDdd::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIJAVKeylistKey::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIJAVKeylistKey
 ******************************************************************************/

IexWdbeDdd::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexWdbeDdd::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexWdbeDdd::ImeIJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeDdd::ImeitemIJAVKeylistKey();
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

void IexWdbeDdd::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIJAVKeylistKey* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIJAVKeylistKey.end" << endl;
	};
};

void IexWdbeDdd::ImeIJAVKeylistKey::writeXML(
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
 class IexWdbeDdd::ImeitemIAVKeylistKey
 ******************************************************************************/

IexWdbeDdd::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

IexWdbeDdd::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

void IexWdbeDdd::ImeitemIAVKeylistKey::readTxt(
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

void IexWdbeDdd::ImeitemIAVKeylistKey::readXML(
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

void IexWdbeDdd::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIAVKeylistKey::writeXML(
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
 class IexWdbeDdd::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIAVKeylistKey::VecWIel::getIx(
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

void IexWdbeDdd::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIAVKeylistKey::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIAVKeylistKey
 ******************************************************************************/

IexWdbeDdd::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexWdbeDdd::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexWdbeDdd::ImeIAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemIAVKeylistKey();
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

void IexWdbeDdd::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIAVKeylistKey* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAVKeylistKey.end" << endl;
	};
};

void IexWdbeDdd::ImeIAVKeylistKey::writeXML(
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
 class IexWdbeDdd::ImeitemICVariable
 ******************************************************************************/

IexWdbeDdd::ImeitemICVariable::ImeitemICVariable(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDdd::ImeitemICVariable::ImeitemICVariable(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICVariable()
		{
};

void IexWdbeDdd::ImeitemICVariable::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICVariable::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICVariable"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemICVariable::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICVariable::VecWIel::IREF;
	};
};

void IexWdbeDdd::ImeitemICVariable::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << iref << endl;
};

void IexWdbeDdd::ImeitemICVariable::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICVariable","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeICVariable::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeICVariable::VecWIel::getIx(
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

void IexWdbeDdd::ImeICVariable::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeICVariable::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeICVariable
 ******************************************************************************/

IexWdbeDdd::ImeICVariable::ImeICVariable() {
};

IexWdbeDdd::ImeICVariable::~ImeICVariable() {
	clear();
};

void IexWdbeDdd::ImeICVariable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeICVariable::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemICVariable* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemICVariable();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICVariable"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICVariable"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICVARIABLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICVariable"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICVariable"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeICVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemICVariable* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICVariable");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICVariable", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICVariable";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemICVariable();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeICVariable::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeICVariable." << StrMod::replaceChar(ImeICVariable::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeICVariable.end" << endl;
	};
};

void IexWdbeDdd::ImeICVariable::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICVariable");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemICFsmstate
 ******************************************************************************/

IexWdbeDdd::ImeitemICFsmstate::ImeitemICFsmstate(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDdd::ImeitemICFsmstate::ImeitemICFsmstate(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICFsmstate()
		{
};

void IexWdbeDdd::ImeitemICFsmstate::readTxt(
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

void IexWdbeDdd::ImeitemICFsmstate::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICFsmstate::VecWIel::IREF;
	};
};

void IexWdbeDdd::ImeitemICFsmstate::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << iref << endl;
};

void IexWdbeDdd::ImeitemICFsmstate::writeXML(
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
 class IexWdbeDdd::ImeICFsmstate::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeICFsmstate::VecWIel::getIx(
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

void IexWdbeDdd::ImeICFsmstate::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeICFsmstate::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeICFsmstate
 ******************************************************************************/

IexWdbeDdd::ImeICFsmstate::ImeICFsmstate() {
};

IexWdbeDdd::ImeICFsmstate::~ImeICFsmstate() {
	clear();
};

void IexWdbeDdd::ImeICFsmstate::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeICFsmstate::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemICFsmstate* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeDdd::ImeitemICFsmstate();
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

void IexWdbeDdd::ImeICFsmstate::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemICFsmstate* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemICFsmstate();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeICFsmstate::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeICFsmstate." << StrMod::replaceChar(ImeICFsmstate::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeICFsmstate.end" << endl;
	};
};

void IexWdbeDdd::ImeICFsmstate::writeXML(
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
 class IexWdbeDdd::ImeitemIAMFsmstateStep
 ******************************************************************************/

IexWdbeDdd::ImeitemIAMFsmstateStep::ImeitemIAMFsmstateStep(
			const string& srefFnxRefWdbeMFsmstate
			, const string& Cond1
			, const string& Ip1
			, const string& Cond2
			, const string& Ip2
			, const string& Cond3
			, const string& Ip3
			, const string& Cond4
			, const string& Ip4
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
};

IexWdbeDdd::ImeitemIAMFsmstateStep::ImeitemIAMFsmstateStep(
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

		delete rec;
	};
};

void IexWdbeDdd::ImeitemIAMFsmstateStep::readTxt(
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

void IexWdbeDdd::ImeitemIAMFsmstateStep::readXML(
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
	};
};

void IexWdbeDdd::ImeitemIAMFsmstateStep::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t\t" << srefFnxRefWdbeMFsmstate << "\t" << Cond1 << "\t" << Ip1 << "\t" << Cond2 << "\t" << Ip2 << "\t" << Cond3 << "\t" << Ip3 << "\t" << Cond4 << "\t" << Ip4 << endl;
};

void IexWdbeDdd::ImeitemIAMFsmstateStep::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","fnx","cn1","ip1","cn2","ip2","cn3","ip3","cn4","ip4"};
	else tags = {"ImeitemIAMFsmstateStep","srefFnxRefWdbeMFsmstate","Cond1","Ip1","Cond2","Ip2","Cond3","Ip3","Cond4","Ip4"};

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
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIAMFsmstateStep::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIAMFsmstateStep::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

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
	};

	return(ix);
};

void IexWdbeDdd::ImeIAMFsmstateStep::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IP4); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIAMFsmstateStep::VecWIel::getSrefs(
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

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeIAMFsmstateStep
 ******************************************************************************/

IexWdbeDdd::ImeIAMFsmstateStep::ImeIAMFsmstateStep() {
};

IexWdbeDdd::ImeIAMFsmstateStep::~ImeIAMFsmstateStep() {
	clear();
};

void IexWdbeDdd::ImeIAMFsmstateStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIAMFsmstateStep::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIAMFsmstateStep* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 5) {
					ii = new IexWdbeDdd::ImeitemIAMFsmstateStep();
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

void IexWdbeDdd::ImeIAMFsmstateStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIAMFsmstateStep* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIAMFsmstateStep();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIAMFsmstateStep::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\t\tImeIAMFsmstateStep." << StrMod::replaceChar(ImeIAMFsmstateStep::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\t\tImeIAMFsmstateStep.end" << endl;
	};
};

void IexWdbeDdd::ImeIAMFsmstateStep::writeXML(
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
 class IexWdbeDdd::ImeitemIMFsmstate
 ******************************************************************************/

IexWdbeDdd::ImeitemIMFsmstate::ImeitemIMFsmstate(
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

IexWdbeDdd::ImeitemIMFsmstate::ImeitemIMFsmstate(
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

void IexWdbeDdd::ImeitemIMFsmstate::readTxt(
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

void IexWdbeDdd::ImeitemIMFsmstate::readXML(
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

void IexWdbeDdd::ImeitemIMFsmstate::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << irefRefWdbeCFsmstate << "\t" << sref << "\t" << StrMod::boolToString(Extip) << "\t" << Comment << endl;
	imeiamfsmstatestep.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMFsmstate::writeXML(
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
 class IexWdbeDdd::ImeIMFsmstate::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMFsmstate::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwdbecfsmstate") ix |= IREFREFWDBECFSMSTATE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "extip") ix |= EXTIP;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMFsmstate::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMFsmstate::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMFsmstate
 ******************************************************************************/

IexWdbeDdd::ImeIMFsmstate::ImeIMFsmstate() {
};

IexWdbeDdd::ImeIMFsmstate::~ImeIMFsmstate() {
	clear();
};

void IexWdbeDdd::ImeIMFsmstate::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMFsmstate::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMFsmstate* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeDdd::ImeitemIMFsmstate();
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

void IexWdbeDdd::ImeIMFsmstate::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMFsmstate* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMFsmstate();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMFsmstate::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIMFsmstate." << StrMod::replaceChar(ImeIMFsmstate::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIMFsmstate.end" << endl;
	};
};

void IexWdbeDdd::ImeIMFsmstate::writeXML(
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
 class IexWdbeDdd::ImeitemIMFsm
 ******************************************************************************/

IexWdbeDdd::ImeitemIMFsm::ImeitemIMFsm(
		) : WdbeMFsm() {
	lineno = 0;
	ixWIelValid = 0;

};

IexWdbeDdd::ImeitemIMFsm::ImeitemIMFsm(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMFsm()
		{
	WdbeMFsm* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemfsm->loadRecByRef(ref, &rec)) {
		refWdbeMProcess = rec->refWdbeMProcess;

		delete rec;
	};
};

void IexWdbeDdd::ImeitemIMFsm::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

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

void IexWdbeDdd::ImeitemIMFsm::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		imeicfsmstate.readXML(docctx, basexpath);
		imeimfsmstate.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMFsm::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << "^" << endl;
	imeicfsmstate.writeTxt(outfile);
	imeimfsmstate.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMFsm::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii"};
	else tags = {"ImeitemIMFsm"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		imeicfsmstate.writeXML(wr, shorttags);
		imeimfsmstate.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMFsm::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMFsm::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
	};

	return(ix);
};

void IexWdbeDdd::ImeIMFsm::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; false;) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMFsm::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMFsm
 ******************************************************************************/

IexWdbeDdd::ImeIMFsm::ImeIMFsm() {
};

IexWdbeDdd::ImeIMFsm::~ImeIMFsm() {
	clear();
};

void IexWdbeDdd::ImeIMFsm::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMFsm::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMFsm* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemIMFsm();
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

void IexWdbeDdd::ImeIMFsm::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMFsm* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMFsm();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMFsm::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMFsm." << StrMod::replaceChar(ImeIMFsm::VecWIel::getSrefs(0), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMFsm.end" << endl;
	};
};

void IexWdbeDdd::ImeIMFsm::writeXML(
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
 class IexWdbeDdd::ImeitemIMVariable
 ******************************************************************************/

IexWdbeDdd::ImeitemIMVariable::ImeitemIMVariable(
			const ubigint irefRefWdbeCVariable
			, const string& sref
			, const bool Const
			, const bool Falling
			, const string& srefWdbeKHdltype
			, const usmallint Width
			, const string& Minmax
			, const string& Onval
			, const string& Offval
			, const bool Defon
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
	this->Defon = Defon;
	this->Comment = Comment;
};

IexWdbeDdd::ImeitemIMVariable::ImeitemIMVariable(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVariable()
		{
	WdbeMVariable* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemvariable->loadRecByRef(ref, &rec)) {
		refWdbeCVariable = rec->refWdbeCVariable;
		prcRefWdbeMProcess = rec->prcRefWdbeMProcess;
		prcNum = rec->prcNum;
		sref = rec->sref;
		Const = rec->Const;
		Falling = rec->Falling;
		srefWdbeKHdltype = rec->srefWdbeKHdltype;
		Width = rec->Width;
		Minmax = rec->Minmax;
		Onval = rec->Onval;
		Offval = rec->Offval;
		Defon = rec->Defon;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDdd::ImeitemIMVariable::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWdbeCVariable = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMVariable::VecWIel::IREFREFWDBECVARIABLE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVariable::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Const = (txtrd.fields[2] == "true"); ixWIelValid += ImeIMVariable::VecWIel::CONST;};
	if (txtrd.fields.size() > 3) {Falling = (txtrd.fields[3] == "true"); ixWIelValid += ImeIMVariable::VecWIel::FALLING;};
	if (txtrd.fields.size() > 4) {srefWdbeKHdltype = txtrd.fields[4]; ixWIelValid += ImeIMVariable::VecWIel::SREFWDBEKHDLTYPE;};
	if (txtrd.fields.size() > 5) {Width = atoi(txtrd.fields[5].c_str()); ixWIelValid += ImeIMVariable::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 6) {Minmax = txtrd.fields[6]; ixWIelValid += ImeIMVariable::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 7) {Onval = txtrd.fields[7]; ixWIelValid += ImeIMVariable::VecWIel::ONVAL;};
	if (txtrd.fields.size() > 8) {Offval = txtrd.fields[8]; ixWIelValid += ImeIMVariable::VecWIel::OFFVAL;};
	if (txtrd.fields.size() > 9) {Defon = (txtrd.fields[9] == "true"); ixWIelValid += ImeIMVariable::VecWIel::DEFON;};
	if (txtrd.fields.size() > 10) {Comment = txtrd.fields[10]; ixWIelValid += ImeIMVariable::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVariable"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMVariable::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCVariable", "clu", irefRefWdbeCVariable)) ixWIelValid += ImeIMVariable::VecWIel::IREFREFWDBECVARIABLE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVariable::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Const", "con", Const)) ixWIelValid += ImeIMVariable::VecWIel::CONST;
		if (extractBoolUclc(docctx, basexpath, "Falling", "fal", Falling)) ixWIelValid += ImeIMVariable::VecWIel::FALLING;
		if (extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype)) ixWIelValid += ImeIMVariable::VecWIel::SREFWDBEKHDLTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMVariable::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMVariable::VecWIel::MINMAX;
		if (extractStringUclc(docctx, basexpath, "Onval", "onv", Onval)) ixWIelValid += ImeIMVariable::VecWIel::ONVAL;
		if (extractStringUclc(docctx, basexpath, "Offval", "ofv", Offval)) ixWIelValid += ImeIMVariable::VecWIel::OFFVAL;
		if (extractBoolUclc(docctx, basexpath, "Defon", "dfo", Defon)) ixWIelValid += ImeIMVariable::VecWIel::DEFON;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVariable::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIMVariable::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << irefRefWdbeCVariable << "\t" << sref << "\t" << StrMod::boolToString(Const) << "\t" << StrMod::boolToString(Falling) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Onval << "\t" << Offval << "\t" << StrMod::boolToString(Defon) << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIMVariable::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","srf","con","fal","hty","wid","mmx","onv","ofv","dfo","cmt"};
	else tags = {"ImeitemIMVariable","irefRefWdbeCVariable","sref","Const","Falling","srefWdbeKHdltype","Width","Minmax","Onval","Offval","Defon","Comment"};

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
		writeBool(wr, tags[10], Defon);
		writeString(wr, tags[11], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMVariable::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMVariable::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

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
		else if (ss[i] == "defon") ix |= DEFON;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMVariable::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMVariable::VecWIel::getSrefs(
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
	if (ix & DEFON) ss.push_back("Defon");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMVariable
 ******************************************************************************/

IexWdbeDdd::ImeIMVariable::ImeIMVariable() {
};

IexWdbeDdd::ImeIMVariable::~ImeIMVariable() {
	clear();
};

void IexWdbeDdd::ImeIMVariable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMVariable::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMVariable* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDdd::ImeitemIMVariable();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVariable"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVariable"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVARIABLE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVariable"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVariable"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMVariable* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVariable");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVariable", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVariable";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMVariable();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMVariable::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMVariable." << StrMod::replaceChar(ImeIMVariable::VecWIel::getSrefs(2047), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMVariable.end" << endl;
	};
};

void IexWdbeDdd::ImeIMVariable::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVariable");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMProcess
 ******************************************************************************/

IexWdbeDdd::ImeitemIMProcess::ImeitemIMProcess(
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

IexWdbeDdd::ImeitemIMProcess::ImeitemIMProcess(
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

void IexWdbeDdd::ImeitemIMProcess::readTxt(
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

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEICVARIABLE)) {
					imeicvariable.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMFSM)) {
					imeimfsm.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMVARIABLE)) {
					imeimvariable.readTxt(txtrd);
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

void IexWdbeDdd::ImeitemIMProcess::readXML(
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
		imeicvariable.readXML(docctx, basexpath);
		imeimfsm.readXML(docctx, basexpath);
		imeimvariable.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMProcess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << clkSrefWdbeMSignal << "\t" << asrSrefWdbeMSignal << "\t" << StrMod::boolToString(Falling) << "\t" << Syncrst << "\t" << StrMod::boolToString(Extip) << "\t" << Comment << endl;
	imeiavkeylistkey.writeTxt(outfile);
	imeicvariable.writeTxt(outfile);
	imeimfsm.writeTxt(outfile);
	imeimvariable.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMProcess::writeXML(
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
		imeicvariable.writeXML(wr, shorttags);
		imeimfsm.writeXML(wr, shorttags);
		imeimvariable.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMProcess::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMProcess::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

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

void IexWdbeDdd::ImeIMProcess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMProcess::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMProcess
 ******************************************************************************/

IexWdbeDdd::ImeIMProcess::ImeIMProcess() {
};

IexWdbeDdd::ImeIMProcess::~ImeIMProcess() {
	clear();
};

void IexWdbeDdd::ImeIMProcess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMProcess::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMProcess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIMProcess();
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

void IexWdbeDdd::ImeIMProcess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMProcess* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMProcess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMProcess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMProcess." << StrMod::replaceChar(ImeIMProcess::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMProcess.end" << endl;
	};
};

void IexWdbeDdd::ImeIMProcess::writeXML(
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
 class IexWdbeDdd::ImeitemIMSignal
 ******************************************************************************/

IexWdbeDdd::ImeitemIMSignal::ImeitemIMSignal(
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
			, const bool Defon
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
	this->Defon = Defon;
	this->srefDrvRefWdbeMPort = srefDrvRefWdbeMPort;
	this->Comment = Comment;
};

IexWdbeDdd::ImeitemIMSignal::ImeitemIMSignal(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMSignal()
		{
	WdbeMSignal* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemsignal->loadRecByRef(ref, &rec)) {
		ixVBasetype = rec->ixVBasetype;
		refWdbeCSignal = rec->refWdbeCSignal;
		mdlRefWdbeMModule = rec->mdlRefWdbeMModule;
		mdlNum = rec->mdlNum;
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
		Defon = rec->Defon;
		drvRefWdbeMPort = rec->drvRefWdbeMPort;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDdd::ImeitemIMSignal::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMSignal::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {irefRefWdbeCSignal = atoll(txtrd.fields[1].c_str()); ixWIelValid += ImeIMSignal::VecWIel::IREFREFWDBECSIGNAL;};
	if (txtrd.fields.size() > 2) {srefMgeIxVTbl = txtrd.fields[2]; ixWIelValid += ImeIMSignal::VecWIel::SREFMGEIXVTBL;};
	if (txtrd.fields.size() > 3) {srefMgeUref = txtrd.fields[3]; ixWIelValid += ImeIMSignal::VecWIel::SREFMGEUREF;};
	if (txtrd.fields.size() > 4) {sref = txtrd.fields[4]; ixWIelValid += ImeIMSignal::VecWIel::SREF;};
	if (txtrd.fields.size() > 5) {Const = (txtrd.fields[5] == "true"); ixWIelValid += ImeIMSignal::VecWIel::CONST;};
	if (txtrd.fields.size() > 6) {srefWdbeKHdltype = txtrd.fields[6]; ixWIelValid += ImeIMSignal::VecWIel::SREFWDBEKHDLTYPE;};
	if (txtrd.fields.size() > 7) {Width = atoi(txtrd.fields[7].c_str()); ixWIelValid += ImeIMSignal::VecWIel::WIDTH;};
	if (txtrd.fields.size() > 8) {Minmax = txtrd.fields[8]; ixWIelValid += ImeIMSignal::VecWIel::MINMAX;};
	if (txtrd.fields.size() > 9) {Comb = txtrd.fields[9]; ixWIelValid += ImeIMSignal::VecWIel::COMB;};
	if (txtrd.fields.size() > 10) {Onval = txtrd.fields[10]; ixWIelValid += ImeIMSignal::VecWIel::ONVAL;};
	if (txtrd.fields.size() > 11) {Offval = txtrd.fields[11]; ixWIelValid += ImeIMSignal::VecWIel::OFFVAL;};
	if (txtrd.fields.size() > 12) {Defon = (txtrd.fields[12] == "true"); ixWIelValid += ImeIMSignal::VecWIel::DEFON;};
	if (txtrd.fields.size() > 13) {srefDrvRefWdbeMPort = txtrd.fields[13]; ixWIelValid += ImeIMSignal::VecWIel::SREFDRVREFWDBEMPORT;};
	if (txtrd.fields.size() > 14) {Comment = txtrd.fields[14]; ixWIelValid += ImeIMSignal::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSignal"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMSignal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMSignal::VecWIel::SREFIXVBASETYPE;
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCSignal", "clu", irefRefWdbeCSignal)) ixWIelValid += ImeIMSignal::VecWIel::IREFREFWDBECSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefMgeIxVTbl", "mgt", srefMgeIxVTbl)) ixWIelValid += ImeIMSignal::VecWIel::SREFMGEIXVTBL;
		if (extractStringUclc(docctx, basexpath, "srefMgeUref", "mgu", srefMgeUref)) ixWIelValid += ImeIMSignal::VecWIel::SREFMGEUREF;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMSignal::VecWIel::SREF;
		if (extractBoolUclc(docctx, basexpath, "Const", "con", Const)) ixWIelValid += ImeIMSignal::VecWIel::CONST;
		if (extractStringUclc(docctx, basexpath, "srefWdbeKHdltype", "hty", srefWdbeKHdltype)) ixWIelValid += ImeIMSignal::VecWIel::SREFWDBEKHDLTYPE;
		if (extractUsmallintUclc(docctx, basexpath, "Width", "wid", Width)) ixWIelValid += ImeIMSignal::VecWIel::WIDTH;
		if (extractStringUclc(docctx, basexpath, "Minmax", "mmx", Minmax)) ixWIelValid += ImeIMSignal::VecWIel::MINMAX;
		if (extractStringUclc(docctx, basexpath, "Comb", "cmb", Comb)) ixWIelValid += ImeIMSignal::VecWIel::COMB;
		if (extractStringUclc(docctx, basexpath, "Onval", "onv", Onval)) ixWIelValid += ImeIMSignal::VecWIel::ONVAL;
		if (extractStringUclc(docctx, basexpath, "Offval", "ofv", Offval)) ixWIelValid += ImeIMSignal::VecWIel::OFFVAL;
		if (extractBoolUclc(docctx, basexpath, "Defon", "dfo", Defon)) ixWIelValid += ImeIMSignal::VecWIel::DEFON;
		if (extractStringUclc(docctx, basexpath, "srefDrvRefWdbeMPort", "drv", srefDrvRefWdbeMPort)) ixWIelValid += ImeIMSignal::VecWIel::SREFDRVREFWDBEMPORT;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMSignal::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIMSignal::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMSignalBasetype::getSref(ixVBasetype) << "\t" << irefRefWdbeCSignal << "\t" << VecWdbeVMSignalMgeTbl::getSref(mgeIxVTbl) << "\t" << srefMgeUref << "\t" << sref << "\t" << StrMod::boolToString(Const) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Comb << "\t" << Onval << "\t" << Offval << "\t" << StrMod::boolToString(Defon) << "\t" << srefDrvRefWdbeMPort << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIMSignal::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","clu","mgt","mgu","srf","con","hty","wid","mmx","cmb","onv","ofv","dfo","drv","cmt"};
	else tags = {"ImeitemIMSignal","srefIxVBasetype","irefRefWdbeCSignal","srefMgeIxVTbl","srefMgeUref","sref","Const","srefWdbeKHdltype","Width","Minmax","Comb","Onval","Offval","Defon","srefDrvRefWdbeMPort","Comment"};

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
		writeBool(wr, tags[13], Defon);
		writeString(wr, tags[14], srefDrvRefWdbeMPort);
		writeString(wr, tags[15], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMSignal::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMSignal::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

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
		else if (ss[i] == "defon") ix |= DEFON;
		else if (ss[i] == "srefdrvrefwdbemport") ix |= SREFDRVREFWDBEMPORT;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMSignal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMSignal::VecWIel::getSrefs(
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
	if (ix & DEFON) ss.push_back("Defon");
	if (ix & SREFDRVREFWDBEMPORT) ss.push_back("srefDrvRefWdbeMPort");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMSignal
 ******************************************************************************/

IexWdbeDdd::ImeIMSignal::ImeIMSignal() {
};

IexWdbeDdd::ImeIMSignal::~ImeIMSignal() {
	clear();
};

void IexWdbeDdd::ImeIMSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMSignal::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMSignal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIMSignal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSignal"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSignal"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSIGNAL) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSignal"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSignal"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMSignal* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSignal");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSignal", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSignal";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMSignal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMSignal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMSignal." << StrMod::replaceChar(ImeIMSignal::VecWIel::getSrefs(32767), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMSignal.end" << endl;
	};
};

void IexWdbeDdd::ImeIMSignal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSignal");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMModule
 ******************************************************************************/

IexWdbeDdd::ImeitemIMModule::ImeitemIMModule(
			const string& hsrefSupRefWdbeMModule
			, const string& sref
		) : WdbeMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefSupRefWdbeMModule = hsrefSupRefWdbeMModule;
	this->sref = sref;
};

IexWdbeDdd::ImeitemIMModule::ImeitemIMModule(
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

void IexWdbeDdd::ImeitemIMModule::readTxt(
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

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICSIGNAL)) {
					imeicsignal.readTxt(txtrd);
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

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPORT)) {
					imeimport.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPROCESS)) {
					imeimprocess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMSIGNAL)) {
					imeimsignal.readTxt(txtrd);
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

void IexWdbeDdd::ImeitemIMModule::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefWdbeMModule", "sup", hsrefSupRefWdbeMModule)) ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMModule::VecWIel::SREF;
		imeicgeneric.readXML(docctx, basexpath);
		imeicport.readXML(docctx, basexpath);
		imeicsignal.readXML(docctx, basexpath);
		imeimcontroller.readXML(docctx, basexpath);
		imeimgeneric.readXML(docctx, basexpath);
		imeimimbuf.readXML(docctx, basexpath);
		imeimport.readXML(docctx, basexpath);
		imeimprocess.readXML(docctx, basexpath);
		imeimsignal.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefSupRefWdbeMModule << "\t" << sref << endl;
	imeicgeneric.writeTxt(outfile);
	imeicport.writeTxt(outfile);
	imeicsignal.writeTxt(outfile);
	imeimcontroller.writeTxt(outfile);
	imeimgeneric.writeTxt(outfile);
	imeimimbuf.writeTxt(outfile);
	imeimport.writeTxt(outfile);
	imeimprocess.writeTxt(outfile);
	imeimsignal.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMModule::writeXML(
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
		imeicsignal.writeXML(wr, shorttags);
		imeimcontroller.writeXML(wr, shorttags);
		imeimgeneric.writeXML(wr, shorttags);
		imeimimbuf.writeXML(wr, shorttags);
		imeimport.writeXML(wr, shorttags);
		imeimprocess.writeXML(wr, shorttags);
		imeimsignal.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMModule::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::stringToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "hsrefsuprefwdbemmodule") ix |= HSREFSUPREFWDBEMMODULE;
		else if (ss[i] == "sref") ix |= SREF;
	};

	return(ix);
};

void IexWdbeDdd::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMModule::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMModule
 ******************************************************************************/

IexWdbeDdd::ImeIMModule::ImeIMModule() {
};

IexWdbeDdd::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWdbeDdd::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDdd::ImeitemIMModule();
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

void IexWdbeDdd::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMModule* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMModule.end" << endl;
	};
};

void IexWdbeDdd::ImeIMModule::writeXML(
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
 class IexWdbeDdd::ImeitemIMVectoritem1
 ******************************************************************************/

IexWdbeDdd::ImeitemIMVectoritem1::ImeitemIMVectoritem1(
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

IexWdbeDdd::ImeitemIMVectoritem1::ImeitemIMVectoritem1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVectoritem1()
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

void IexWdbeDdd::ImeitemIMVectoritem1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMVectoritem1::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIMVectoritem1::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMVectoritem1::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMVectoritem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVectoritem1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMVectoritem1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVectoritem1::VecWIel::COMMENT;
	};
};

void IexWdbeDdd::ImeitemIMVectoritem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
};

void IexWdbeDdd::ImeitemIMVectoritem1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tit","cmt"};
	else tags = {"ImeitemIMVectoritem1","sref","Title","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Title);
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMVectoritem1::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMVectoritem1::VecWIel::getIx(
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

void IexWdbeDdd::ImeIMVectoritem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMVectoritem1::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMVectoritem1
 ******************************************************************************/

IexWdbeDdd::ImeIMVectoritem1::ImeIMVectoritem1() {
};

IexWdbeDdd::ImeIMVectoritem1::~ImeIMVectoritem1() {
	clear();
};

void IexWdbeDdd::ImeIMVectoritem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMVectoritem1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMVectoritem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDdd::ImeitemIMVectoritem1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVectoritem1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMVectoritem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMVectoritem1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVectoritem1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVectoritem1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVectoritem1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMVectoritem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMVectoritem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMVectoritem1." << StrMod::replaceChar(ImeIMVectoritem1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMVectoritem1.end" << endl;
	};
};

void IexWdbeDdd::ImeIMVectoritem1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVectoritem1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMVector1
 ******************************************************************************/

IexWdbeDdd::ImeitemIMVector1::ImeitemIMVector1(
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

IexWdbeDdd::ImeitemIMVector1::ImeitemIMVector1(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVector1()
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

void IexWdbeDdd::ImeitemIMVector1::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMVector1::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVector1::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefsKOption = txtrd.fields[2]; ixWIelValid += ImeIMVector1::VecWIel::SREFSKOPTION;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMVECTORITEM1)) {
					imeimvectoritem1.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector1"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDdd::ImeitemIMVector1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector1::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector1::VecWIel::SREFSKOPTION;
		imeimvectoritem1.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMVector1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << srefsKOption << endl;
	imeimvectoritem1.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMVector1::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","typ","srf","opt"};
	else tags = {"ImeitemIMVector1","srefIxVBasetype","sref","srefsKOption"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], VecWdbeVMVectorBasetype::getSref(ixVBasetype));
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], srefsKOption);
		imeimvectoritem1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMVector1::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMVector1::VecWIel::getIx(
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

void IexWdbeDdd::ImeIMVector1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMVector1::VecWIel::getSrefs(
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
 class IexWdbeDdd::ImeIMVector1
 ******************************************************************************/

IexWdbeDdd::ImeIMVector1::ImeIMVector1() {
};

IexWdbeDdd::ImeIMVector1::~ImeIMVector1() {
	clear();
};

void IexWdbeDdd::ImeIMVector1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMVector1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMVector1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDdd::ImeitemIMVector1();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector1"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector1"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMVECTOR1) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector1"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMVector1"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDdd::ImeIMVector1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMVector1* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMVector1");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMVector1", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMVector1";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDdd::ImeitemIMVector1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMVector1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMVector1." << StrMod::replaceChar(ImeIMVector1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMVector1.end" << endl;
	};
};

void IexWdbeDdd::ImeIMVector1::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMVector1");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDdd::ImeitemIMUnit
 ******************************************************************************/

IexWdbeDdd::ImeitemIMUnit::ImeitemIMUnit(
			const string& sref
		) : WdbeMUnit() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexWdbeDdd::ImeitemIMUnit::ImeitemIMUnit(
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

void IexWdbeDdd::ImeitemIMUnit::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUnit::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMBANK)) {
					imeimbank.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMCOMMAND1)) {
					imeimcommand1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMERROR1)) {
					imeimerror1.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMMODULE)) {
					imeimmodule.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMVECTOR1)) {
					imeimvector1.readTxt(txtrd);
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

void IexWdbeDdd::ImeitemIMUnit::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUnit::VecWIel::SREF;
		imeimbank.readXML(docctx, basexpath);
		imeimcommand1.readXML(docctx, basexpath);
		imeimerror1.readXML(docctx, basexpath);
		imeimmodule.readXML(docctx, basexpath);
		imeimvector1.readXML(docctx, basexpath);
	};
};

void IexWdbeDdd::ImeitemIMUnit::writeTxt(
			fstream& outfile
		) {
	outfile << sref << endl;
	imeimbank.writeTxt(outfile);
	imeimcommand1.writeTxt(outfile);
	imeimerror1.writeTxt(outfile);
	imeimmodule.writeTxt(outfile);
	imeimvector1.writeTxt(outfile);
};

void IexWdbeDdd::ImeitemIMUnit::writeXML(
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
		imeimbank.writeXML(wr, shorttags);
		imeimcommand1.writeXML(wr, shorttags);
		imeimerror1.writeXML(wr, shorttags);
		imeimmodule.writeXML(wr, shorttags);
		imeimvector1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMUnit::VecWIel
 ******************************************************************************/

uint IexWdbeDdd::ImeIMUnit::VecWIel::getIx(
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

void IexWdbeDdd::ImeIMUnit::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDdd::ImeIMUnit::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDdd::ImeIMUnit
 ******************************************************************************/

IexWdbeDdd::ImeIMUnit::ImeIMUnit() {
};

IexWdbeDdd::ImeIMUnit::~ImeIMUnit() {
	clear();
};

void IexWdbeDdd::ImeIMUnit::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDdd::ImeIMUnit::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDdd::ImeitemIMUnit* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeDdd::ImeitemIMUnit();
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

void IexWdbeDdd::ImeIMUnit::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDdd::ImeitemIMUnit* ii = NULL;

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

			ii = new IexWdbeDdd::ImeitemIMUnit();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDdd::ImeIMUnit::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUnit." << StrMod::replaceChar(ImeIMUnit::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUnit.end" << endl;
	};
};

void IexWdbeDdd::ImeIMUnit::writeXML(
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
 namespace IexWdbeDdd
 ******************************************************************************/

void IexWdbeDdd::parseFromFile(
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
			Txtrd rd(fullpath, rectpath, "IexWdbeDdd", Version("0.9.51"), VecVIme::getIx);
			readTxt(rd, imeimunit);
	};
};

void IexWdbeDdd::exportToFile(
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

void IexWdbeDdd::readTxt(
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

void IexWdbeDdd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMUnit& imeimunit
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeDdd")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("0.9.51")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","0.9.51"}});
		};

		// look for XML sub-blocks
		imeimunit.readXML(docctx, basexpath);

	} else {
		imeimunit = ImeIMUnit();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeDdd"}});
	};
};

void IexWdbeDdd::writeTxt(
			fstream& outfile
			, ImeIMUnit& imeimunit
		) {
	outfile << "IexWdbeDdd v" WDBE_VERSION << endl;

	imeimunit.writeTxt(outfile);
};

void IexWdbeDdd::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMUnit& imeimunit
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeDdd");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeimunit.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeDdd::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMCOMMANDINVPAR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOMMANDINVPAR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOMMANDRETPAR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOMMANDRETPAR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMERRORPAR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMERRORPAR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMFSMSTATESTEP,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMPINPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecWdbeVIop::INS},{(uint)VecVIme::IMEICFSMSTATE,VecWdbeVIop::INS},{(uint)VecVIme::IMEICGENERIC,VecWdbeVIop::INS},{(uint)VecVIme::IMEICPIN,VecWdbeVIop::INS},{(uint)VecVIme::IMEICPORT,VecWdbeVIop::INS},{(uint)VecVIme::IMEICSIGNAL,VecWdbeVIop::INS},{(uint)VecVIme::IMEICVARIABLE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJMPINSREF,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCOMMAND1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCOMMAND2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMERROR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMERROR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMFSM,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMFSMSTATE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMGENERIC,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPORT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPROCESS,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMSIGNAL,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVARIABLE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTOR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTOR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTORITEM1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTORITEM2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIRMCOMMANDMCONTROLLER,VecWdbeVIop::INS}};
};

uint IexWdbeDdd::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};



