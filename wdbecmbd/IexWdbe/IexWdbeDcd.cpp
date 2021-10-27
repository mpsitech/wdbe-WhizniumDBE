/**
	* \file IexWdbeDcd.cpp
	* data blocks and readers/writers for import/export complex IexWdbeDcd (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 Nov 2020
	*/
// IP header --- ABOVE

#include "IexWdbeDcd.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeDcd::VecVIme
 ******************************************************************************/

uint IexWdbeDcd::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamcommandinvpar") return IMEIAMCOMMANDINVPAR;
	if (s == "imeiamcommandretpar") return IMEIAMCOMMANDRETPAR;
	if (s == "imeiamcoreversionip") return IMEIAMCOREVERSIONIP;
	if (s == "imeiamcoreversionplh") return IMEIAMCOREVERSIONPLH;
	if (s == "imeiamerrorpar") return IMEIAMERRORPAR;
	if (s == "imeiamfsmstatestep") return IMEIAMFSMSTATESTEP;
	if (s == "imeiavkeylistkey") return IMEIAVKEYLISTKEY;
	if (s == "imeicfsmstate") return IMEICFSMSTATE;
	if (s == "imeicgeneric") return IMEICGENERIC;
	if (s == "imeicport") return IMEICPORT;
	if (s == "imeicsignal") return IMEICSIGNAL;
	if (s == "imeicvariable") return IMEICVARIABLE;
	if (s == "imeijavkeylistkey") return IMEIJAVKEYLISTKEY;
	if (s == "imeimcommand") return IMEIMCOMMAND;
	if (s == "imeimcontroller") return IMEIMCONTROLLER;
	if (s == "imeimerror") return IMEIMERROR;
	if (s == "imeimfsm") return IMEIMFSM;
	if (s == "imeimfsmstate") return IMEIMFSMSTATE;
	if (s == "imeimgeneric") return IMEIMGENERIC;
	if (s == "imeimmodule") return IMEIMMODULE;
	if (s == "imeimport") return IMEIMPORT;
	if (s == "imeimprocess") return IMEIMPROCESS;
	if (s == "imeimsignal") return IMEIMSIGNAL;
	if (s == "imeimvariable") return IMEIMVARIABLE;
	if (s == "imeimvector") return IMEIMVECTOR;

	return(0);
};

string IexWdbeDcd::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMCOMMANDINVPAR) return("ImeIAMCommandInvpar");
	if (ix == IMEIAMCOMMANDRETPAR) return("ImeIAMCommandRetpar");
	if (ix == IMEIAMCOREVERSIONIP) return("ImeIAMCoreversionIp");
	if (ix == IMEIAMCOREVERSIONPLH) return("ImeIAMCoreversionPlh");
	if (ix == IMEIAMERRORPAR) return("ImeIAMErrorPar");
	if (ix == IMEIAMFSMSTATESTEP) return("ImeIAMFsmstateStep");
	if (ix == IMEIAVKEYLISTKEY) return("ImeIAVKeylistKey");
	if (ix == IMEICFSMSTATE) return("ImeICFsmstate");
	if (ix == IMEICGENERIC) return("ImeICGeneric");
	if (ix == IMEICPORT) return("ImeICPort");
	if (ix == IMEICSIGNAL) return("ImeICSignal");
	if (ix == IMEICVARIABLE) return("ImeICVariable");
	if (ix == IMEIJAVKEYLISTKEY) return("ImeIJAVKeylistKey");
	if (ix == IMEIMCOMMAND) return("ImeIMCommand");
	if (ix == IMEIMCONTROLLER) return("ImeIMController");
	if (ix == IMEIMERROR) return("ImeIMError");
	if (ix == IMEIMFSM) return("ImeIMFsm");
	if (ix == IMEIMFSMSTATE) return("ImeIMFsmstate");
	if (ix == IMEIMGENERIC) return("ImeIMGeneric");
	if (ix == IMEIMMODULE) return("ImeIMModule");
	if (ix == IMEIMPORT) return("ImeIMPort");
	if (ix == IMEIMPROCESS) return("ImeIMProcess");
	if (ix == IMEIMSIGNAL) return("ImeIMSignal");
	if (ix == IMEIMVARIABLE) return("ImeIMVariable");
	if (ix == IMEIMVECTOR) return("ImeIMVector");

	return("");
};

/******************************************************************************
 class IexWdbeDcd::ImeitemIAMCoreversionIp
 ******************************************************************************/

IexWdbeDcd::ImeitemIAMCoreversionIp::ImeitemIAMCoreversionIp(
			const string& sref
			, const uint ixVTagtype
			, const string& Comment
		) : WdbeAMCoreversionIp() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->ixVTagtype = ixVTagtype;
	this->Comment = Comment;
};

IexWdbeDcd::ImeitemIAMCoreversionIp::ImeitemIAMCoreversionIp(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMCoreversionIp()
		{
	WdbeAMCoreversionIp* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamcoreversionip->loadRecByRef(ref, &rec)) {
		cvrRefWdbeMCoreversion = rec->cvrRefWdbeMCoreversion;
		cvrNum = rec->cvrNum;
		sref = rec->sref;
		ixVTagtype = rec->ixVTagtype;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDcd::ImeitemIAMCoreversionIp::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMCoreversionIp::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {srefIxVTagtype = txtrd.fields[1]; ixWIelValid += ImeIAMCoreversionIp::VecWIel::SREFIXVTAGTYPE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIAMCoreversionIp::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCoreversionIp"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDcd::ImeitemIAMCoreversionIp::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMCoreversionIp::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVTagtype", "tty", srefIxVTagtype)) ixWIelValid += ImeIAMCoreversionIp::VecWIel::SREFIXVTAGTYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMCoreversionIp::VecWIel::COMMENT;
	};
};

void IexWdbeDcd::ImeitemIAMCoreversionIp::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << VecWdbeVAMCoreversionIpTagtype::getSref(ixVTagtype) << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIAMCoreversionIp::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","tty","cmt"};
	else tags = {"ImeitemIAMCoreversionIp","sref","srefIxVTagtype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], VecWdbeVAMCoreversionIpTagtype::getSref(ixVTagtype));
		writeString(wr, tags[3], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDcd::ImeIAMCoreversionIp::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIAMCoreversionIp::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvtagtype") ix |= SREFIXVTAGTYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDcd::ImeIAMCoreversionIp::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIAMCoreversionIp::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & SREFIXVTAGTYPE) ss.push_back("srefIxVTagtype");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDcd::ImeIAMCoreversionIp
 ******************************************************************************/

IexWdbeDcd::ImeIAMCoreversionIp::ImeIAMCoreversionIp() {
};

IexWdbeDcd::ImeIAMCoreversionIp::~ImeIAMCoreversionIp() {
	clear();
};

void IexWdbeDcd::ImeIAMCoreversionIp::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIAMCoreversionIp::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIAMCoreversionIp* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeDcd::ImeitemIAMCoreversionIp();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCoreversionIp"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCOREVERSIONIP) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCoreversionIp"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCoreversionIp"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDcd::ImeIAMCoreversionIp::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIAMCoreversionIp* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCoreversionIp");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCoreversionIp", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCoreversionIp";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDcd::ImeitemIAMCoreversionIp();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIAMCoreversionIp::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAMCoreversionIp." << StrMod::replaceChar(ImeIAMCoreversionIp::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAMCoreversionIp.end" << endl;
	};
};

void IexWdbeDcd::ImeIAMCoreversionIp::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCoreversionIp");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDcd::ImeitemIAMCoreversionPlh
 ******************************************************************************/

IexWdbeDcd::ImeitemIAMCoreversionPlh::ImeitemIAMCoreversionPlh(
			const string& sref
			, const string& Comment
		) : WdbeAMCoreversionPlh() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->Comment = Comment;
};

IexWdbeDcd::ImeitemIAMCoreversionPlh::ImeitemIAMCoreversionPlh(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIAMCoreversionPlh()
		{
	WdbeAMCoreversionPlh* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbeamcoreversionplh->loadRecByRef(ref, &rec)) {
		cvrRefWdbeMCoreversion = rec->cvrRefWdbeMCoreversion;
		cvrNum = rec->cvrNum;
		sref = rec->sref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDcd::ImeitemIAMCoreversionPlh::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAMCoreversionPlh::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Comment = txtrd.fields[1]; ixWIelValid += ImeIAMCoreversionPlh::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCoreversionPlh"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDcd::ImeitemIAMCoreversionPlh::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIAMCoreversionPlh::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIAMCoreversionPlh::VecWIel::COMMENT;
	};
};

void IexWdbeDcd::ImeitemIAMCoreversionPlh::writeTxt(
			fstream& outfile
		) {
	outfile << sref << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIAMCoreversionPlh::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","cmt"};
	else tags = {"ImeitemIAMCoreversionPlh","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDcd::ImeIAMCoreversionPlh::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIAMCoreversionPlh::VecWIel::getIx(
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

void IexWdbeDcd::ImeIAMCoreversionPlh::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIAMCoreversionPlh::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIAMCoreversionPlh
 ******************************************************************************/

IexWdbeDcd::ImeIAMCoreversionPlh::ImeIAMCoreversionPlh() {
};

IexWdbeDcd::ImeIAMCoreversionPlh::~ImeIAMCoreversionPlh() {
	clear();
};

void IexWdbeDcd::ImeIAMCoreversionPlh::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIAMCoreversionPlh::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIAMCoreversionPlh* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeDcd::ImeitemIAMCoreversionPlh();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIAMCoreversionPlh"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIAMCOREVERSIONPLH) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCoreversionPlh"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIAMCoreversionPlh"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDcd::ImeIAMCoreversionPlh::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIAMCoreversionPlh* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIAMCoreversionPlh");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIAMCoreversionPlh", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIAMCoreversionPlh";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDcd::ImeitemIAMCoreversionPlh();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIAMCoreversionPlh::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIAMCoreversionPlh." << StrMod::replaceChar(ImeIAMCoreversionPlh::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIAMCoreversionPlh.end" << endl;
	};
};

void IexWdbeDcd::ImeIAMCoreversionPlh::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIAMCoreversionPlh");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDcd::ImeitemICGeneric
 ******************************************************************************/

IexWdbeDcd::ImeitemICGeneric::ImeitemICGeneric(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDcd::ImeitemICGeneric::ImeitemICGeneric(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICGeneric()
		{
};

void IexWdbeDcd::ImeitemICGeneric::readTxt(
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

void IexWdbeDcd::ImeitemICGeneric::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICGeneric::VecWIel::IREF;
	};
};

void IexWdbeDcd::ImeitemICGeneric::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWdbeDcd::ImeitemICGeneric::writeXML(
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
 class IexWdbeDcd::ImeICGeneric::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeICGeneric::VecWIel::getIx(
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

void IexWdbeDcd::ImeICGeneric::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeICGeneric::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDcd::ImeICGeneric
 ******************************************************************************/

IexWdbeDcd::ImeICGeneric::ImeICGeneric() {
};

IexWdbeDcd::ImeICGeneric::~ImeICGeneric() {
	clear();
};

void IexWdbeDcd::ImeICGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeICGeneric::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemICGeneric* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDcd::ImeitemICGeneric();
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

void IexWdbeDcd::ImeICGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemICGeneric* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemICGeneric();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeICGeneric::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICGeneric." << StrMod::replaceChar(ImeICGeneric::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICGeneric.end" << endl;
	};
};

void IexWdbeDcd::ImeICGeneric::writeXML(
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
 class IexWdbeDcd::ImeitemICPort
 ******************************************************************************/

IexWdbeDcd::ImeitemICPort::ImeitemICPort(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDcd::ImeitemICPort::ImeitemICPort(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICPort()
		{
};

void IexWdbeDcd::ImeitemICPort::readTxt(
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

void IexWdbeDcd::ImeitemICPort::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICPort::VecWIel::IREF;
	};
};

void IexWdbeDcd::ImeitemICPort::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWdbeDcd::ImeitemICPort::writeXML(
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
 class IexWdbeDcd::ImeICPort::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeICPort::VecWIel::getIx(
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

void IexWdbeDcd::ImeICPort::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeICPort::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDcd::ImeICPort
 ******************************************************************************/

IexWdbeDcd::ImeICPort::ImeICPort() {
};

IexWdbeDcd::ImeICPort::~ImeICPort() {
	clear();
};

void IexWdbeDcd::ImeICPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeICPort::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemICPort* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDcd::ImeitemICPort();
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

void IexWdbeDcd::ImeICPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemICPort* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemICPort();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeICPort::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICPort." << StrMod::replaceChar(ImeICPort::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICPort.end" << endl;
	};
};

void IexWdbeDcd::ImeICPort::writeXML(
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
 class IexWdbeDcd::ImeitemICSignal
 ******************************************************************************/

IexWdbeDcd::ImeitemICSignal::ImeitemICSignal(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDcd::ImeitemICSignal::ImeitemICSignal(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICSignal()
		{
};

void IexWdbeDcd::ImeitemICSignal::readTxt(
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

void IexWdbeDcd::ImeitemICSignal::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICSignal::VecWIel::IREF;
	};
};

void IexWdbeDcd::ImeitemICSignal::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << iref << endl;
};

void IexWdbeDcd::ImeitemICSignal::writeXML(
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
 class IexWdbeDcd::ImeICSignal::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeICSignal::VecWIel::getIx(
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

void IexWdbeDcd::ImeICSignal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeICSignal::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDcd::ImeICSignal
 ******************************************************************************/

IexWdbeDcd::ImeICSignal::ImeICSignal() {
};

IexWdbeDcd::ImeICSignal::~ImeICSignal() {
	clear();
};

void IexWdbeDcd::ImeICSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeICSignal::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemICSignal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDcd::ImeitemICSignal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
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

void IexWdbeDcd::ImeICSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemICSignal* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemICSignal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeICSignal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeICSignal." << StrMod::replaceChar(ImeICSignal::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeICSignal.end" << endl;
	};
};

void IexWdbeDcd::ImeICSignal::writeXML(
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
 class IexWdbeDcd::ImeitemIAMCommandInvpar
 ******************************************************************************/

IexWdbeDcd::ImeitemIAMCommandInvpar::ImeitemIAMCommandInvpar(
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

IexWdbeDcd::ImeitemIAMCommandInvpar::ImeitemIAMCommandInvpar(
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

void IexWdbeDcd::ImeitemIAMCommandInvpar::readTxt(
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

void IexWdbeDcd::ImeitemIAMCommandInvpar::readXML(
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

void IexWdbeDcd::ImeitemIAMCommandInvpar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Defval << "\t" << srefRefWdbeMVectoritem << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIAMCommandInvpar::writeXML(
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
 class IexWdbeDcd::ImeIAMCommandInvpar::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIAMCommandInvpar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

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

void IexWdbeDcd::ImeIAMCommandInvpar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIAMCommandInvpar::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIAMCommandInvpar
 ******************************************************************************/

IexWdbeDcd::ImeIAMCommandInvpar::ImeIAMCommandInvpar() {
};

IexWdbeDcd::ImeIAMCommandInvpar::~ImeIAMCommandInvpar() {
	clear();
};

void IexWdbeDcd::ImeIAMCommandInvpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIAMCommandInvpar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIAMCommandInvpar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDcd::ImeitemIAMCommandInvpar();
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

void IexWdbeDcd::ImeIAMCommandInvpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIAMCommandInvpar* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIAMCommandInvpar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIAMCommandInvpar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMCommandInvpar." << StrMod::replaceChar(ImeIAMCommandInvpar::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMCommandInvpar.end" << endl;
	};
};

void IexWdbeDcd::ImeIAMCommandInvpar::writeXML(
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
 class IexWdbeDcd::ImeitemIAMCommandRetpar
 ******************************************************************************/

IexWdbeDcd::ImeitemIAMCommandRetpar::ImeitemIAMCommandRetpar(
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

IexWdbeDcd::ImeitemIAMCommandRetpar::ImeitemIAMCommandRetpar(
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

void IexWdbeDcd::ImeitemIAMCommandRetpar::readTxt(
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

void IexWdbeDcd::ImeitemIAMCommandRetpar::readXML(
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

void IexWdbeDcd::ImeitemIAMCommandRetpar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIAMCommandRetpar::writeXML(
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
 class IexWdbeDcd::ImeIAMCommandRetpar::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIAMCommandRetpar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwdbevpartype") ix |= SREFIXWDBEVPARTYPE;
		else if (ss[i] == "srefrefwdbemvector") ix |= SREFREFWDBEMVECTOR;
		else if (ss[i] == "length") ix |= LENGTH;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDcd::ImeIAMCommandRetpar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIAMCommandRetpar::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIAMCommandRetpar
 ******************************************************************************/

IexWdbeDcd::ImeIAMCommandRetpar::ImeIAMCommandRetpar() {
};

IexWdbeDcd::ImeIAMCommandRetpar::~ImeIAMCommandRetpar() {
	clear();
};

void IexWdbeDcd::ImeIAMCommandRetpar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIAMCommandRetpar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIAMCommandRetpar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDcd::ImeitemIAMCommandRetpar();
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

void IexWdbeDcd::ImeIAMCommandRetpar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIAMCommandRetpar* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIAMCommandRetpar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIAMCommandRetpar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMCommandRetpar." << StrMod::replaceChar(ImeIAMCommandRetpar::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMCommandRetpar.end" << endl;
	};
};

void IexWdbeDcd::ImeIAMCommandRetpar::writeXML(
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
 class IexWdbeDcd::ImeitemIMCommand
 ******************************************************************************/

IexWdbeDcd::ImeitemIMCommand::ImeitemIMCommand(
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

IexWdbeDcd::ImeitemIMCommand::ImeitemIMCommand(
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
		Fullsref = rec->Fullsref;
		ixVRettype = rec->ixVRettype;
		ivrRefWdbeMSignal = rec->ivrRefWdbeMSignal;
		rvrRefWdbeMSignal = rec->rvrRefWdbeMSignal;
		rerRefWdbeMSignal = rec->rerRefWdbeMSignal;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDcd::ImeitemIMCommand::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {refNum = atol(txtrd.fields[0].c_str()); ixWIelValid += ImeIMCommand::VecWIel::REFNUM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMCommand::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxVRettype = txtrd.fields[2]; ixWIelValid += ImeIMCommand::VecWIel::SREFIXVRETTYPE;};
	if (txtrd.fields.size() > 3) {srefIvrRefWdbeMSignal = txtrd.fields[3]; ixWIelValid += ImeIMCommand::VecWIel::SREFIVRREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 4) {srefRvrRefWdbeMSignal = txtrd.fields[4]; ixWIelValid += ImeIMCommand::VecWIel::SREFRVRREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 5) {srefRerRefWdbeMSignal = txtrd.fields[5]; ixWIelValid += ImeIMCommand::VecWIel::SREFRERREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMCommand::VecWIel::COMMENT;};

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

void IexWdbeDcd::ImeitemIMCommand::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUintUclc(docctx, basexpath, "refNum", "ren", refNum)) ixWIelValid += ImeIMCommand::VecWIel::REFNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCommand::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVRettype", "rty", srefIxVRettype)) ixWIelValid += ImeIMCommand::VecWIel::SREFIXVRETTYPE;
		if (extractStringUclc(docctx, basexpath, "srefIvrRefWdbeMSignal", "ivr", srefIvrRefWdbeMSignal)) ixWIelValid += ImeIMCommand::VecWIel::SREFIVRREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefRvrRefWdbeMSignal", "rvr", srefRvrRefWdbeMSignal)) ixWIelValid += ImeIMCommand::VecWIel::SREFRVRREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "srefRerRefWdbeMSignal", "rer", srefRerRefWdbeMSignal)) ixWIelValid += ImeIMCommand::VecWIel::SREFRERREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMCommand::VecWIel::COMMENT;
		imeiamcommandinvpar.readXML(docctx, basexpath);
		imeiamcommandretpar.readXML(docctx, basexpath);
	};
};

void IexWdbeDcd::ImeitemIMCommand::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << refNum << "\t" << sref << "\t" << VecWdbeVMCommandRettype::getSref(ixVRettype) << "\t" << srefIvrRefWdbeMSignal << "\t" << srefRvrRefWdbeMSignal << "\t" << srefRerRefWdbeMSignal << "\t" << Comment << endl;
	imeiamcommandinvpar.writeTxt(outfile);
	imeiamcommandretpar.writeTxt(outfile);
};

void IexWdbeDcd::ImeitemIMCommand::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ren","srf","rty","ivr","rvr","rer","cmt"};
	else tags = {"ImeitemIMCommand","refNum","sref","srefIxVRettype","srefIvrRefWdbeMSignal","srefRvrRefWdbeMSignal","srefRerRefWdbeMSignal","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], refNum);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWdbeVMCommandRettype::getSref(ixVRettype));
		writeString(wr, tags[4], srefIvrRefWdbeMSignal);
		writeString(wr, tags[5], srefRvrRefWdbeMSignal);
		writeString(wr, tags[6], srefRerRefWdbeMSignal);
		writeString(wr, tags[7], Comment);
		imeiamcommandinvpar.writeXML(wr, shorttags);
		imeiamcommandretpar.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDcd::ImeIMCommand::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMCommand::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

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

void IexWdbeDcd::ImeIMCommand::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMCommand::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMCommand
 ******************************************************************************/

IexWdbeDcd::ImeIMCommand::ImeIMCommand() {
};

IexWdbeDcd::ImeIMCommand::~ImeIMCommand() {
	clear();
};

void IexWdbeDcd::ImeIMCommand::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMCommand::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMCommand* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDcd::ImeitemIMCommand();
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

void IexWdbeDcd::ImeIMCommand::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMCommand* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMCommand();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMCommand::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMCommand." << StrMod::replaceChar(ImeIMCommand::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMCommand.end" << endl;
	};
};

void IexWdbeDcd::ImeIMCommand::writeXML(
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
 class IexWdbeDcd::ImeitemIAMErrorPar
 ******************************************************************************/

IexWdbeDcd::ImeitemIAMErrorPar::ImeitemIAMErrorPar(
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

IexWdbeDcd::ImeitemIAMErrorPar::ImeitemIAMErrorPar(
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

void IexWdbeDcd::ImeitemIAMErrorPar::readTxt(
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

void IexWdbeDcd::ImeitemIAMErrorPar::readXML(
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

void IexWdbeDcd::ImeitemIAMErrorPar::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIAMErrorPar::writeXML(
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
 class IexWdbeDcd::ImeIAMErrorPar::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIAMErrorPar::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixwdbevpartype") ix |= SREFIXWDBEVPARTYPE;
		else if (ss[i] == "srefrefwdbemvector") ix |= SREFREFWDBEMVECTOR;
		else if (ss[i] == "length") ix |= LENGTH;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDcd::ImeIAMErrorPar::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIAMErrorPar::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIAMErrorPar
 ******************************************************************************/

IexWdbeDcd::ImeIAMErrorPar::ImeIAMErrorPar() {
};

IexWdbeDcd::ImeIAMErrorPar::~ImeIAMErrorPar() {
	clear();
};

void IexWdbeDcd::ImeIAMErrorPar::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIAMErrorPar::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIAMErrorPar* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDcd::ImeitemIAMErrorPar();
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

void IexWdbeDcd::ImeIAMErrorPar::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIAMErrorPar* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIAMErrorPar();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIAMErrorPar::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIAMErrorPar." << StrMod::replaceChar(ImeIAMErrorPar::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIAMErrorPar.end" << endl;
	};
};

void IexWdbeDcd::ImeIAMErrorPar::writeXML(
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
 class IexWdbeDcd::ImeitemIMError
 ******************************************************************************/

IexWdbeDcd::ImeitemIMError::ImeitemIMError(
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

IexWdbeDcd::ImeitemIMError::ImeitemIMError(
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
		Fullsref = rec->Fullsref;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDcd::ImeitemIMError::readTxt(
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

void IexWdbeDcd::ImeitemIMError::readXML(
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

void IexWdbeDcd::ImeitemIMError::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << refNum << "\t" << sref << "\t" << Comment << endl;
	imeiamerrorpar.writeTxt(outfile);
};

void IexWdbeDcd::ImeitemIMError::writeXML(
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
 class IexWdbeDcd::ImeIMError::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMError::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "refnum") ix |= REFNUM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDcd::ImeIMError::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMError::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMError
 ******************************************************************************/

IexWdbeDcd::ImeIMError::ImeIMError() {
};

IexWdbeDcd::ImeIMError::~ImeIMError() {
	clear();
};

void IexWdbeDcd::ImeIMError::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMError::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMError* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDcd::ImeitemIMError();
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

void IexWdbeDcd::ImeIMError::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMError* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMError();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMError::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMError." << StrMod::replaceChar(ImeIMError::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMError.end" << endl;
	};
};

void IexWdbeDcd::ImeIMError::writeXML(
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
 class IexWdbeDcd::ImeitemIMVector
 ******************************************************************************/

IexWdbeDcd::ImeitemIMVector::ImeitemIMVector(
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

IexWdbeDcd::ImeitemIMVector::ImeitemIMVector(
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

void IexWdbeDcd::ImeitemIMVector::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxVBasetype = txtrd.fields[0]; ixWIelValid += ImeIMVector::VecWIel::SREFIXVBASETYPE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMVector::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefsKOption = txtrd.fields[2]; ixWIelValid += ImeIMVector::VecWIel::SREFSKOPTION;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMVector"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDcd::ImeitemIMVector::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxVBasetype", "typ", srefIxVBasetype)) ixWIelValid += ImeIMVector::VecWIel::SREFIXVBASETYPE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVector::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefsKOption", "opt", srefsKOption)) ixWIelValid += ImeIMVector::VecWIel::SREFSKOPTION;
	};
};

void IexWdbeDcd::ImeitemIMVector::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << VecWdbeVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << srefsKOption << endl;
};

void IexWdbeDcd::ImeitemIMVector::writeXML(
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
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDcd::ImeIMVector::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMVector::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefixvbasetype") ix |= SREFIXVBASETYPE;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefskoption") ix |= SREFSKOPTION;
	};

	return(ix);
};

void IexWdbeDcd::ImeIMVector::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMVector::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMVector
 ******************************************************************************/

IexWdbeDcd::ImeIMVector::ImeIMVector() {
};

IexWdbeDcd::ImeIMVector::~ImeIMVector() {
	clear();
};

void IexWdbeDcd::ImeIMVector::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMVector::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMVector* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDcd::ImeitemIMVector();
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

void IexWdbeDcd::ImeIMVector::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMVector* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMVector();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMVector::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMVector." << StrMod::replaceChar(ImeIMVector::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMVector.end" << endl;
	};
};

void IexWdbeDcd::ImeIMVector::writeXML(
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
 class IexWdbeDcd::ImeitemIMController
 ******************************************************************************/

IexWdbeDcd::ImeitemIMController::ImeitemIMController(
			const uint ixWdbeVIop
			, const string& srefClrRefWdbeMSignal
		) : WdbeMController() {
	lineno = 0;
	ixWIelValid = 0;

	this->ixWdbeVIop = ixWdbeVIop;
	this->srefClrRefWdbeMSignal = srefClrRefWdbeMSignal;
};

IexWdbeDcd::ImeitemIMController::ImeitemIMController(
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

void IexWdbeDcd::ImeitemIMController::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefIxWdbeVIop = txtrd.fields[0]; ixWIelValid += ImeIMController::VecWIel::SREFIXWDBEVIOP;};
	if (txtrd.fields.size() > 1) {srefClrRefWdbeMSignal = txtrd.fields[1]; ixWIelValid += ImeIMController::VecWIel::SREFCLRREFWDBEMSIGNAL;};

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

void IexWdbeDcd::ImeitemIMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefIxWdbeVIop", "iop", srefIxWdbeVIop)) ixWIelValid += ImeIMController::VecWIel::SREFIXWDBEVIOP;
		if (extractStringUclc(docctx, basexpath, "srefClrRefWdbeMSignal", "clr", srefClrRefWdbeMSignal)) ixWIelValid += ImeIMController::VecWIel::SREFCLRREFWDBEMSIGNAL;
		imeimcommand.readXML(docctx, basexpath);
		imeimerror.readXML(docctx, basexpath);
		imeimvector.readXML(docctx, basexpath);
	};
};

void IexWdbeDcd::ImeitemIMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << srefClrRefWdbeMSignal << endl;
	imeimcommand.writeTxt(outfile);
	imeimerror.writeTxt(outfile);
	imeimvector.writeTxt(outfile);
};

void IexWdbeDcd::ImeitemIMController::writeXML(
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
		imeimvector.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDcd::ImeIMController::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMController::VecWIel::getIx(
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

void IexWdbeDcd::ImeIMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFCLRREFWDBEMSIGNAL); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMController::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMController
 ******************************************************************************/

IexWdbeDcd::ImeIMController::ImeIMController() {
};

IexWdbeDcd::ImeIMController::~ImeIMController() {
	clear();
};

void IexWdbeDcd::ImeIMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDcd::ImeitemIMController();
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

void IexWdbeDcd::ImeIMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMController* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMController." << StrMod::replaceChar(ImeIMController::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMController.end" << endl;
	};
};

void IexWdbeDcd::ImeIMController::writeXML(
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
 class IexWdbeDcd::ImeitemIMGeneric
 ******************************************************************************/

IexWdbeDcd::ImeitemIMGeneric::ImeitemIMGeneric(
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

IexWdbeDcd::ImeitemIMGeneric::ImeitemIMGeneric(
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

void IexWdbeDcd::ImeitemIMGeneric::readTxt(
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

void IexWdbeDcd::ImeitemIMGeneric::readXML(
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

void IexWdbeDcd::ImeitemIMGeneric::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << irefRefWdbeCGeneric << "\t" << sref << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Defval << "\t" << srcSrefWdbeMGeneric << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIMGeneric::writeXML(
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
 class IexWdbeDcd::ImeIMGeneric::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMGeneric::VecWIel::getIx(
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

void IexWdbeDcd::ImeIMGeneric::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMGeneric::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMGeneric
 ******************************************************************************/

IexWdbeDcd::ImeIMGeneric::ImeIMGeneric() {
};

IexWdbeDcd::ImeIMGeneric::~ImeIMGeneric() {
	clear();
};

void IexWdbeDcd::ImeIMGeneric::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMGeneric::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMGeneric* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDcd::ImeitemIMGeneric();
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

void IexWdbeDcd::ImeIMGeneric::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMGeneric* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMGeneric();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMGeneric::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMGeneric." << StrMod::replaceChar(ImeIMGeneric::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMGeneric.end" << endl;
	};
};

void IexWdbeDcd::ImeIMGeneric::writeXML(
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
 class IexWdbeDcd::ImeitemIMPort
 ******************************************************************************/

IexWdbeDcd::ImeitemIMPort::ImeitemIMPort(
			const uint ixWdbeVIop
			, const ubigint irefRefWdbeCPort
			, const uint mdlIxVCat
			, const string& sref
			, const uint ixVDir
			, const string& srefWdbeKHdltype
			, const usmallint Width
			, const string& Minmax
			, const string& Defval
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
	this->cprSrefWdbeMPort = cprSrefWdbeMPort;
	this->csiSrefWdbeMSignal = csiSrefWdbeMSignal;
	this->Comment = Comment;
};

IexWdbeDcd::ImeitemIMPort::ImeitemIMPort(
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
		cprSrefWdbeMPort = rec->cprSrefWdbeMPort;
		csiSrefWdbeMSignal = rec->csiSrefWdbeMSignal;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDcd::ImeitemIMPort::readTxt(
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
	if (txtrd.fields.size() > 9) {cprSrefWdbeMPort = txtrd.fields[9]; ixWIelValid += ImeIMPort::VecWIel::CPRSREFWDBEMPORT;};
	if (txtrd.fields.size() > 10) {csiSrefWdbeMSignal = txtrd.fields[10]; ixWIelValid += ImeIMPort::VecWIel::CSISREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 11) {Comment = txtrd.fields[11]; ixWIelValid += ImeIMPort::VecWIel::COMMENT;};

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

void IexWdbeDcd::ImeitemIMPort::readXML(
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
		if (extractStringUclc(docctx, basexpath, "cprSrefWdbeMPort", "cpr", cprSrefWdbeMPort)) ixWIelValid += ImeIMPort::VecWIel::CPRSREFWDBEMPORT;
		if (extractStringUclc(docctx, basexpath, "csiSrefWdbeMSignal", "csi", csiSrefWdbeMSignal)) ixWIelValid += ImeIMPort::VecWIel::CSISREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMPort::VecWIel::COMMENT;
	};
};

void IexWdbeDcd::ImeitemIMPort::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVIop::getSref(ixWdbeVIop) << "\t" << irefRefWdbeCPort << "\t" << VecWdbeVMPortMdlCat::getSref(mdlIxVCat) << "\t" << sref << "\t" << VecWdbeVMPortDir::getSref(ixVDir) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Defval << "\t" << cprSrefWdbeMPort << "\t" << csiSrefWdbeMSignal << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIMPort::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","iop","clu","mdc","srf","dir","hty","wid","mmx","dfv","cpr","csi","cmt"};
	else tags = {"ImeitemIMPort","srefIxWdbeVIop","irefRefWdbeCPort","srefMdlIxVCat","sref","srefIxVDir","srefWdbeKHdltype","Width","Minmax","Defval","cprSrefWdbeMPort","csiSrefWdbeMSignal","Comment"};

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
		writeString(wr, tags[10], cprSrefWdbeMPort);
		writeString(wr, tags[11], csiSrefWdbeMSignal);
		writeString(wr, tags[12], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDcd::ImeIMPort::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMPort::VecWIel::getIx(
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
		else if (ss[i] == "cprsrefwdbemport") ix |= CPRSREFWDBEMPORT;
		else if (ss[i] == "csisrefwdbemsignal") ix |= CSISREFWDBEMSIGNAL;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDcd::ImeIMPort::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMPort::VecWIel::getSrefs(
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
	if (ix & CPRSREFWDBEMPORT) ss.push_back("cprSrefWdbeMPort");
	if (ix & CSISREFWDBEMSIGNAL) ss.push_back("csiSrefWdbeMSignal");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDcd::ImeIMPort
 ******************************************************************************/

IexWdbeDcd::ImeIMPort::ImeIMPort() {
};

IexWdbeDcd::ImeIMPort::~ImeIMPort() {
	clear();
};

void IexWdbeDcd::ImeIMPort::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMPort::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMPort* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDcd::ImeitemIMPort();
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

void IexWdbeDcd::ImeIMPort::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMPort* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMPort();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMPort::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMPort." << StrMod::replaceChar(ImeIMPort::VecWIel::getSrefs(4095), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMPort.end" << endl;
	};
};

void IexWdbeDcd::ImeIMPort::writeXML(
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
 class IexWdbeDcd::ImeitemIJAVKeylistKey
 ******************************************************************************/

IexWdbeDcd::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
			const string& Title
			, const string& Comment
		) : WdbeJAVKeylistKey() {
	lineno = 0;
	ixWIelValid = 0;

	this->Title = Title;
	this->Comment = Comment;
};

IexWdbeDcd::ImeitemIJAVKeylistKey::ImeitemIJAVKeylistKey(
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

void IexWdbeDcd::ImeitemIJAVKeylistKey::readTxt(
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

void IexWdbeDcd::ImeitemIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIJAVKeylistKey::VecWIel::COMMENT;
	};
};

void IexWdbeDcd::ImeitemIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << Title << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIJAVKeylistKey::writeXML(
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
 class IexWdbeDcd::ImeIJAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIJAVKeylistKey::VecWIel::getIx(
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

void IexWdbeDcd::ImeIJAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIJAVKeylistKey::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIJAVKeylistKey
 ******************************************************************************/

IexWdbeDcd::ImeIJAVKeylistKey::ImeIJAVKeylistKey() {
};

IexWdbeDcd::ImeIJAVKeylistKey::~ImeIJAVKeylistKey() {
	clear();
};

void IexWdbeDcd::ImeIJAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIJAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIJAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDcd::ImeitemIJAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
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

void IexWdbeDcd::ImeIJAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIJAVKeylistKey* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIJAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIJAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIJAVKeylistKey." << StrMod::replaceChar(ImeIJAVKeylistKey::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIJAVKeylistKey.end" << endl;
	};
};

void IexWdbeDcd::ImeIJAVKeylistKey::writeXML(
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
 class IexWdbeDcd::ImeitemIAVKeylistKey
 ******************************************************************************/

IexWdbeDcd::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

IexWdbeDcd::ImeitemIAVKeylistKey::ImeitemIAVKeylistKey(
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

void IexWdbeDcd::ImeitemIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIAVKeylistKey::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {Title = txtrd.fields[1]; ixWIelValid += ImeIAVKeylistKey::VecWIel::TITLE;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIAVKeylistKey::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIJAVKEYLISTKEY)) {
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

void IexWdbeDcd::ImeitemIAVKeylistKey::readXML(
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

void IexWdbeDcd::ImeitemIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
	imeijavkeylistkey.writeTxt(outfile);
};

void IexWdbeDcd::ImeitemIAVKeylistKey::writeXML(
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
 class IexWdbeDcd::ImeIAVKeylistKey::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIAVKeylistKey::VecWIel::getIx(
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

void IexWdbeDcd::ImeIAVKeylistKey::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIAVKeylistKey::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIAVKeylistKey
 ******************************************************************************/

IexWdbeDcd::ImeIAVKeylistKey::ImeIAVKeylistKey() {
};

IexWdbeDcd::ImeIAVKeylistKey::~ImeIAVKeylistKey() {
	clear();
};

void IexWdbeDcd::ImeIAVKeylistKey::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIAVKeylistKey::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIAVKeylistKey* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDcd::ImeitemIAVKeylistKey();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeDcd::ImeIAVKeylistKey::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIAVKeylistKey* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIAVKeylistKey();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIAVKeylistKey::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAVKeylistKey." << StrMod::replaceChar(ImeIAVKeylistKey::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAVKeylistKey.end" << endl;
	};
};

void IexWdbeDcd::ImeIAVKeylistKey::writeXML(
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
 class IexWdbeDcd::ImeitemICVariable
 ******************************************************************************/

IexWdbeDcd::ImeitemICVariable::ImeitemICVariable(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDcd::ImeitemICVariable::ImeitemICVariable(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICVariable()
		{
};

void IexWdbeDcd::ImeitemICVariable::readTxt(
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

void IexWdbeDcd::ImeitemICVariable::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICVariable::VecWIel::IREF;
	};
};

void IexWdbeDcd::ImeitemICVariable::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << iref << endl;
};

void IexWdbeDcd::ImeitemICVariable::writeXML(
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
 class IexWdbeDcd::ImeICVariable::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeICVariable::VecWIel::getIx(
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

void IexWdbeDcd::ImeICVariable::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeICVariable::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDcd::ImeICVariable
 ******************************************************************************/

IexWdbeDcd::ImeICVariable::ImeICVariable() {
};

IexWdbeDcd::ImeICVariable::~ImeICVariable() {
	clear();
};

void IexWdbeDcd::ImeICVariable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeICVariable::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemICVariable* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDcd::ImeitemICVariable();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeDcd::ImeICVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemICVariable* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemICVariable();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeICVariable::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeICVariable." << StrMod::replaceChar(ImeICVariable::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeICVariable.end" << endl;
	};
};

void IexWdbeDcd::ImeICVariable::writeXML(
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
 class IexWdbeDcd::ImeitemICFsmstate
 ******************************************************************************/

IexWdbeDcd::ImeitemICFsmstate::ImeitemICFsmstate(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDcd::ImeitemICFsmstate::ImeitemICFsmstate(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICFsmstate()
		{
};

void IexWdbeDcd::ImeitemICFsmstate::readTxt(
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

void IexWdbeDcd::ImeitemICFsmstate::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICFsmstate::VecWIel::IREF;
	};
};

void IexWdbeDcd::ImeitemICFsmstate::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << iref << endl;
};

void IexWdbeDcd::ImeitemICFsmstate::writeXML(
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
 class IexWdbeDcd::ImeICFsmstate::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeICFsmstate::VecWIel::getIx(
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

void IexWdbeDcd::ImeICFsmstate::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeICFsmstate::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDcd::ImeICFsmstate
 ******************************************************************************/

IexWdbeDcd::ImeICFsmstate::ImeICFsmstate() {
};

IexWdbeDcd::ImeICFsmstate::~ImeICFsmstate() {
	clear();
};

void IexWdbeDcd::ImeICFsmstate::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeICFsmstate::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemICFsmstate* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDcd::ImeitemICFsmstate();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
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

void IexWdbeDcd::ImeICFsmstate::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemICFsmstate* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemICFsmstate();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeICFsmstate::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeICFsmstate." << StrMod::replaceChar(ImeICFsmstate::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeICFsmstate.end" << endl;
	};
};

void IexWdbeDcd::ImeICFsmstate::writeXML(
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
 class IexWdbeDcd::ImeitemIAMFsmstateStep
 ******************************************************************************/

IexWdbeDcd::ImeitemIAMFsmstateStep::ImeitemIAMFsmstateStep(
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

IexWdbeDcd::ImeitemIAMFsmstateStep::ImeitemIAMFsmstateStep(
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

void IexWdbeDcd::ImeitemIAMFsmstateStep::readTxt(
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

void IexWdbeDcd::ImeitemIAMFsmstateStep::readXML(
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

void IexWdbeDcd::ImeitemIAMFsmstateStep::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << srefFnxRefWdbeMFsmstate << "\t" << Cond1 << "\t" << Ip1 << "\t" << Cond2 << "\t" << Ip2 << "\t" << Cond3 << "\t" << Ip3 << "\t" << Cond4 << "\t" << Ip4 << endl;
};

void IexWdbeDcd::ImeitemIAMFsmstateStep::writeXML(
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
 class IexWdbeDcd::ImeIAMFsmstateStep::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIAMFsmstateStep::VecWIel::getIx(
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
	};

	return(ix);
};

void IexWdbeDcd::ImeIAMFsmstateStep::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IP4); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIAMFsmstateStep::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIAMFsmstateStep
 ******************************************************************************/

IexWdbeDcd::ImeIAMFsmstateStep::ImeIAMFsmstateStep() {
};

IexWdbeDcd::ImeIAMFsmstateStep::~ImeIAMFsmstateStep() {
	clear();
};

void IexWdbeDcd::ImeIAMFsmstateStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIAMFsmstateStep::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIAMFsmstateStep* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeDcd::ImeitemIAMFsmstateStep();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 4) {
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

void IexWdbeDcd::ImeIAMFsmstateStep::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIAMFsmstateStep* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIAMFsmstateStep();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIAMFsmstateStep::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIAMFsmstateStep." << StrMod::replaceChar(ImeIAMFsmstateStep::VecWIel::getSrefs(511), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIAMFsmstateStep.end" << endl;
	};
};

void IexWdbeDcd::ImeIAMFsmstateStep::writeXML(
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
 class IexWdbeDcd::ImeitemIMFsmstate
 ******************************************************************************/

IexWdbeDcd::ImeitemIMFsmstate::ImeitemIMFsmstate(
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

IexWdbeDcd::ImeitemIMFsmstate::ImeitemIMFsmstate(
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

void IexWdbeDcd::ImeitemIMFsmstate::readTxt(
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
				if ((txtrd.il == 4) && (txtrd.ixVToken == VecVIme::IMEIAMFSMSTATESTEP)) {
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

void IexWdbeDcd::ImeitemIMFsmstate::readXML(
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

void IexWdbeDcd::ImeitemIMFsmstate::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << irefRefWdbeCFsmstate << "\t" << sref << "\t" << StrMod::boolToString(Extip) << "\t" << Comment << endl;
	imeiamfsmstatestep.writeTxt(outfile);
};

void IexWdbeDcd::ImeitemIMFsmstate::writeXML(
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
 class IexWdbeDcd::ImeIMFsmstate::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMFsmstate::VecWIel::getIx(
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

void IexWdbeDcd::ImeIMFsmstate::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMFsmstate::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMFsmstate
 ******************************************************************************/

IexWdbeDcd::ImeIMFsmstate::ImeIMFsmstate() {
};

IexWdbeDcd::ImeIMFsmstate::~ImeIMFsmstate() {
	clear();
};

void IexWdbeDcd::ImeIMFsmstate::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMFsmstate::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMFsmstate* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDcd::ImeitemIMFsmstate();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
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

void IexWdbeDcd::ImeIMFsmstate::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMFsmstate* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMFsmstate();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMFsmstate::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMFsmstate." << StrMod::replaceChar(ImeIMFsmstate::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMFsmstate.end" << endl;
	};
};

void IexWdbeDcd::ImeIMFsmstate::writeXML(
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
 class IexWdbeDcd::ImeitemIMFsm
 ******************************************************************************/

IexWdbeDcd::ImeitemIMFsm::ImeitemIMFsm(
		) : WdbeMFsm() {
	lineno = 0;
	ixWIelValid = 0;

};

IexWdbeDcd::ImeitemIMFsm::ImeitemIMFsm(
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

void IexWdbeDcd::ImeitemIMFsm::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEICFSMSTATE)) {
					imeicfsmstate.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMFSMSTATE)) {
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

void IexWdbeDcd::ImeitemIMFsm::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		imeicfsmstate.readXML(docctx, basexpath);
		imeimfsmstate.readXML(docctx, basexpath);
	};
};

void IexWdbeDcd::ImeitemIMFsm::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << "^" << endl;
	imeicfsmstate.writeTxt(outfile);
	imeimfsmstate.writeTxt(outfile);
};

void IexWdbeDcd::ImeitemIMFsm::writeXML(
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
 class IexWdbeDcd::ImeIMFsm::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMFsm::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
	};

	return(ix);
};

void IexWdbeDcd::ImeIMFsm::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; false;) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMFsm::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDcd::ImeIMFsm
 ******************************************************************************/

IexWdbeDcd::ImeIMFsm::ImeIMFsm() {
};

IexWdbeDcd::ImeIMFsm::~ImeIMFsm() {
	clear();
};

void IexWdbeDcd::ImeIMFsm::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMFsm::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMFsm* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDcd::ImeitemIMFsm();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeDcd::ImeIMFsm::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMFsm* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMFsm();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMFsm::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMFsm." << StrMod::replaceChar(ImeIMFsm::VecWIel::getSrefs(0), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMFsm.end" << endl;
	};
};

void IexWdbeDcd::ImeIMFsm::writeXML(
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
 class IexWdbeDcd::ImeitemIMVariable
 ******************************************************************************/

IexWdbeDcd::ImeitemIMVariable::ImeitemIMVariable(
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

IexWdbeDcd::ImeitemIMVariable::ImeitemIMVariable(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMVariable()
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
		Defon = rec->Defon;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDcd::ImeitemIMVariable::readTxt(
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

void IexWdbeDcd::ImeitemIMVariable::readXML(
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

void IexWdbeDcd::ImeitemIMVariable::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << irefRefWdbeCVariable << "\t" << sref << "\t" << StrMod::boolToString(Const) << "\t" << StrMod::boolToString(Falling) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Onval << "\t" << Offval << "\t" << StrMod::boolToString(Defon) << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIMVariable::writeXML(
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
 class IexWdbeDcd::ImeIMVariable::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMVariable::VecWIel::getIx(
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
		else if (ss[i] == "defon") ix |= DEFON;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDcd::ImeIMVariable::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMVariable::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMVariable
 ******************************************************************************/

IexWdbeDcd::ImeIMVariable::ImeIMVariable() {
};

IexWdbeDcd::ImeIMVariable::~ImeIMVariable() {
	clear();
};

void IexWdbeDcd::ImeIMVariable::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMVariable::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMVariable* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDcd::ImeitemIMVariable();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
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

void IexWdbeDcd::ImeIMVariable::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMVariable* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMVariable();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMVariable::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMVariable." << StrMod::replaceChar(ImeIMVariable::VecWIel::getSrefs(2047), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMVariable.end" << endl;
	};
};

void IexWdbeDcd::ImeIMVariable::writeXML(
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
 class IexWdbeDcd::ImeitemIMProcess
 ******************************************************************************/

IexWdbeDcd::ImeitemIMProcess::ImeitemIMProcess(
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

IexWdbeDcd::ImeitemIMProcess::ImeitemIMProcess(
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

void IexWdbeDcd::ImeitemIMProcess::readTxt(
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
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY)) {
					imeiavkeylistkey.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEICVARIABLE)) {
					imeicvariable.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMFSM)) {
					imeimfsm.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMVARIABLE)) {
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

void IexWdbeDcd::ImeitemIMProcess::readXML(
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

void IexWdbeDcd::ImeitemIMProcess::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << sref << "\t" << clkSrefWdbeMSignal << "\t" << asrSrefWdbeMSignal << "\t" << StrMod::boolToString(Falling) << "\t" << Syncrst << "\t" << StrMod::boolToString(Extip) << "\t" << Comment << endl;
	imeiavkeylistkey.writeTxt(outfile);
	imeicvariable.writeTxt(outfile);
	imeimfsm.writeTxt(outfile);
	imeimvariable.writeTxt(outfile);
};

void IexWdbeDcd::ImeitemIMProcess::writeXML(
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
 class IexWdbeDcd::ImeIMProcess::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMProcess::VecWIel::getIx(
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

void IexWdbeDcd::ImeIMProcess::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMProcess::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMProcess
 ******************************************************************************/

IexWdbeDcd::ImeIMProcess::ImeIMProcess() {
};

IexWdbeDcd::ImeIMProcess::~ImeIMProcess() {
	clear();
};

void IexWdbeDcd::ImeIMProcess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMProcess::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMProcess* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDcd::ImeitemIMProcess();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
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

void IexWdbeDcd::ImeIMProcess::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMProcess* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMProcess();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMProcess::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMProcess." << StrMod::replaceChar(ImeIMProcess::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMProcess.end" << endl;
	};
};

void IexWdbeDcd::ImeIMProcess::writeXML(
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
 class IexWdbeDcd::ImeitemIMSignal
 ******************************************************************************/

IexWdbeDcd::ImeitemIMSignal::ImeitemIMSignal(
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

IexWdbeDcd::ImeitemIMSignal::ImeitemIMSignal(
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
		Defon = rec->Defon;
		drvRefWdbeMPort = rec->drvRefWdbeMPort;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDcd::ImeitemIMSignal::readTxt(
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

void IexWdbeDcd::ImeitemIMSignal::readXML(
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

void IexWdbeDcd::ImeitemIMSignal::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVMSignalBasetype::getSref(ixVBasetype) << "\t" << irefRefWdbeCSignal << "\t" << VecWdbeVMSignalMgeTbl::getSref(mgeIxVTbl) << "\t" << srefMgeUref << "\t" << sref << "\t" << StrMod::boolToString(Const) << "\t" << srefWdbeKHdltype << "\t" << Width << "\t" << Minmax << "\t" << Comb << "\t" << Onval << "\t" << Offval << "\t" << StrMod::boolToString(Defon) << "\t" << srefDrvRefWdbeMPort << "\t" << Comment << endl;
};

void IexWdbeDcd::ImeitemIMSignal::writeXML(
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
 class IexWdbeDcd::ImeIMSignal::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMSignal::VecWIel::getIx(
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
		else if (ss[i] == "defon") ix |= DEFON;
		else if (ss[i] == "srefdrvrefwdbemport") ix |= SREFDRVREFWDBEMPORT;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDcd::ImeIMSignal::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMSignal::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMSignal
 ******************************************************************************/

IexWdbeDcd::ImeIMSignal::ImeIMSignal() {
};

IexWdbeDcd::ImeIMSignal::~ImeIMSignal() {
	clear();
};

void IexWdbeDcd::ImeIMSignal::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMSignal::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMSignal* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDcd::ImeitemIMSignal();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 1) {
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

void IexWdbeDcd::ImeIMSignal::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMSignal* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMSignal();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMSignal::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMSignal." << StrMod::replaceChar(ImeIMSignal::VecWIel::getSrefs(32767), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMSignal.end" << endl;
	};
};

void IexWdbeDcd::ImeIMSignal::writeXML(
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
 class IexWdbeDcd::ImeitemIMModule
 ******************************************************************************/

IexWdbeDcd::ImeitemIMModule::ImeitemIMModule(
			const string& hsrefSupRefWdbeMModule
			, const string& sref
		) : WdbeMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefSupRefWdbeMModule = hsrefSupRefWdbeMModule;
	this->sref = sref;
};

IexWdbeDcd::ImeitemIMModule::ImeitemIMModule(
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

void IexWdbeDcd::ImeitemIMModule::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefSupRefWdbeMModule = txtrd.fields[0]; ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMModule::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICGENERIC)) {
					imeicgeneric.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICPORT)) {
					imeicport.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEICSIGNAL)) {
					imeicsignal.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMCONTROLLER)) {
					imeimcontroller.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMGENERIC)) {
					imeimgeneric.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMPORT)) {
					imeimport.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMPROCESS)) {
					imeimprocess.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMSIGNAL)) {
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

void IexWdbeDcd::ImeitemIMModule::readXML(
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
		imeimport.readXML(docctx, basexpath);
		imeimprocess.readXML(docctx, basexpath);
		imeimsignal.readXML(docctx, basexpath);
	};
};

void IexWdbeDcd::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << hsrefSupRefWdbeMModule << "\t" << sref << endl;
	imeicgeneric.writeTxt(outfile);
	imeicport.writeTxt(outfile);
	imeicsignal.writeTxt(outfile);
	imeimcontroller.writeTxt(outfile);
	imeimgeneric.writeTxt(outfile);
	imeimport.writeTxt(outfile);
	imeimprocess.writeTxt(outfile);
	imeimsignal.writeTxt(outfile);
};

void IexWdbeDcd::ImeitemIMModule::writeXML(
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
		imeimport.writeXML(wr, shorttags);
		imeimprocess.writeXML(wr, shorttags);
		imeimsignal.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDcd::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWdbeDcd::ImeIMModule::VecWIel::getIx(
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

void IexWdbeDcd::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDcd::ImeIMModule::VecWIel::getSrefs(
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
 class IexWdbeDcd::ImeIMModule
 ******************************************************************************/

IexWdbeDcd::ImeIMModule::ImeIMModule() {
};

IexWdbeDcd::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWdbeDcd::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDcd::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDcd::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeDcd::ImeitemIMModule();
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

void IexWdbeDcd::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDcd::ImeitemIMModule* ii = NULL;

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

			ii = new IexWdbeDcd::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDcd::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMModule.end" << endl;
	};
};

void IexWdbeDcd::ImeIMModule::writeXML(
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
 namespace IexWdbeDcd
 ******************************************************************************/

void IexWdbeDcd::parseFromFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const string& rectpath
			, ImeIAMCoreversionIp& imeiamcoreversionip
			, ImeIAMCoreversionPlh& imeiamcoreversionplh
			, ImeIMModule& imeimmodule
		) {
	if (xmlNotTxt) {
		xmlDoc* doc = NULL;
		xmlXPathContext* docctx = NULL;

		try {
			parseFile(fullpath, &doc, &docctx);
			readXML(docctx, "/", imeiamcoreversionip, imeiamcoreversionplh, imeimmodule);
			closeParsed(doc, docctx);
		
		} catch (SbeException& e) {
			if (doc) closeParsed(doc, docctx);
			throw;
		};

	} else {
			Txtrd rd(fullpath, rectpath, "IexWdbeDcd", Version("1.1.8"), VecVIme::getIx);
			readTxt(rd, imeiamcoreversionip, imeiamcoreversionplh, imeimmodule);
	};
};

void IexWdbeDcd::exportToFile(
			const string& fullpath
			, const bool xmlNotTxt
			, const bool shorttags
			, ImeIAMCoreversionIp& imeiamcoreversionip
			, ImeIAMCoreversionPlh& imeiamcoreversionplh
			, ImeIMModule& imeimmodule
		) {
	if (xmlNotTxt) {
		xmlTextWriter* wr = NULL;

		startwriteFile(fullpath, &wr);
			writeXML(wr, shorttags, imeiamcoreversionip, imeiamcoreversionplh, imeimmodule);
		closewriteFile(wr);

	} else {
		fstream txtfile;

		txtfile.open(fullpath.c_str(), ios::out);
		writeTxt(txtfile, imeiamcoreversionip, imeiamcoreversionplh, imeimmodule);
		txtfile.close();
	};
};

void IexWdbeDcd::readTxt(
			Txtrd& txtrd
			, ImeIAMCoreversionIp& imeiamcoreversionip
			, ImeIAMCoreversionPlh& imeiamcoreversionplh
			, ImeIMModule& imeimmodule
		) {
	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAMCOREVERSIONIP)) imeiamcoreversionip.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIAMCOREVERSIONPLH)) imeiamcoreversionplh.readTxt(txtrd);
				else if ((txtrd.il == 0) && (txtrd.ixVToken == VecVIme::IMEIMMODULE)) imeimmodule.readTxt(txtrd);
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

				break;

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_CONTENT, {{"lineno",to_string(txtrd.linecnt)}});
		};
	};
};

void IexWdbeDcd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIAMCoreversionIp& imeiamcoreversionip
			, ImeIAMCoreversionPlh& imeiamcoreversionplh
			, ImeIMModule& imeimmodule
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeDcd")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.1.8")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.1.8"}});
		};

		// look for XML sub-blocks
		imeiamcoreversionip.readXML(docctx, basexpath);
		imeiamcoreversionplh.readXML(docctx, basexpath);
		imeimmodule.readXML(docctx, basexpath);

	} else {
		imeiamcoreversionip = ImeIAMCoreversionIp();
		imeiamcoreversionplh = ImeIAMCoreversionPlh();
		imeimmodule = ImeIMModule();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeDcd"}});
	};
};

void IexWdbeDcd::writeTxt(
			fstream& outfile
			, ImeIAMCoreversionIp& imeiamcoreversionip
			, ImeIAMCoreversionPlh& imeiamcoreversionplh
			, ImeIMModule& imeimmodule
		) {
	outfile << "IexWdbeDcd v" WDBE_VERSION << endl;

	imeiamcoreversionip.writeTxt(outfile);
	imeiamcoreversionplh.writeTxt(outfile);
	imeimmodule.writeTxt(outfile);
};

void IexWdbeDcd::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIAMCoreversionIp& imeiamcoreversionip
			, ImeIAMCoreversionPlh& imeiamcoreversionplh
			, ImeIMModule& imeimmodule
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeDcd");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeiamcoreversionip.writeXML(wr, shorttags);
		imeiamcoreversionplh.writeXML(wr, shorttags);
		imeimmodule.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeDcd::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMCOMMANDINVPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOMMANDRETPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOREVERSIONIP,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOREVERSIONPLH,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMERRORPAR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMFSMSTATESTEP,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY,VecWdbeVIop::INS},{(uint)VecVIme::IMEICFSMSTATE,VecWdbeVIop::INS},{(uint)VecVIme::IMEICGENERIC,VecWdbeVIop::INS},{(uint)VecVIme::IMEICPORT,VecWdbeVIop::INS},{(uint)VecVIme::IMEICSIGNAL,VecWdbeVIop::INS},{(uint)VecVIme::IMEICVARIABLE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCOMMAND,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMERROR,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMFSM,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMFSMSTATE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMGENERIC,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPORT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPROCESS,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMSIGNAL,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVARIABLE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTOR,VecWdbeVIop::INS}};
};

uint IexWdbeDcd::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};
