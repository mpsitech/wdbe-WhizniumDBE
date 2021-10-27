/**
	* \file IexWdbeDal.cpp
	* data blocks and readers/writers for import/export complex IexWdbeDal (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "IexWdbeDal.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeDal::VecVIme
 ******************************************************************************/

uint IexWdbeDal::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeicsegment") return IMEICSEGMENT;
	if (s == "imeimmodule") return IMEIMMODULE;
	if (s == "imeimpipeline") return IMEIMPIPELINE;
	if (s == "imeimsegment") return IMEIMSEGMENT;
	if (s == "imeimunit") return IMEIMUNIT;

	return(0);
};

string IexWdbeDal::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEICSEGMENT) return("ImeICSegment");
	if (ix == IMEIMMODULE) return("ImeIMModule");
	if (ix == IMEIMPIPELINE) return("ImeIMPipeline");
	if (ix == IMEIMSEGMENT) return("ImeIMSegment");
	if (ix == IMEIMUNIT) return("ImeIMUnit");

	return("");
};

/******************************************************************************
 class IexWdbeDal::ImeitemICSegment
 ******************************************************************************/

IexWdbeDal::ImeitemICSegment::ImeitemICSegment(
			const ubigint iref
		) {
	lineno = 0;
	ixWIelValid = 0;

	this->iref = iref;
};

IexWdbeDal::ImeitemICSegment::ImeitemICSegment(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemICSegment()
		{
};

void IexWdbeDal::ImeitemICSegment::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {iref = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeICSegment::VecWIel::IREF;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICSegment"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDal::ImeitemICSegment::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "iref", "irf", iref)) ixWIelValid += ImeICSegment::VecWIel::IREF;
	};
};

void IexWdbeDal::ImeitemICSegment::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << iref << endl;
};

void IexWdbeDal::ImeitemICSegment::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","irf"};
	else tags = {"ImeitemICSegment","iref"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], iref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDal::ImeICSegment::VecWIel
 ******************************************************************************/

uint IexWdbeDal::ImeICSegment::VecWIel::getIx(
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

void IexWdbeDal::ImeICSegment::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*IREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDal::ImeICSegment::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREF) ss.push_back("iref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDal::ImeICSegment
 ******************************************************************************/

IexWdbeDal::ImeICSegment::ImeICSegment() {
};

IexWdbeDal::ImeICSegment::~ImeICSegment() {
	clear();
};

void IexWdbeDal::ImeICSegment::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDal::ImeICSegment::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDal::ImeitemICSegment* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDal::ImeitemICSegment();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSegment"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeICSegment"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEICSEGMENT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSegment"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeICSegment"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDal::ImeICSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDal::ImeitemICSegment* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeICSegment");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemICSegment", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemICSegment";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDal::ImeitemICSegment();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDal::ImeICSegment::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeICSegment." << StrMod::replaceChar(ImeICSegment::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeICSegment.end" << endl;
	};
};

void IexWdbeDal::ImeICSegment::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeICSegment");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDal::ImeitemIMSegment
 ******************************************************************************/

IexWdbeDal::ImeitemIMSegment::ImeitemIMSegment(
			const ubigint irefRefWdbeCSegment
			, const string& hsrefSupRefWdbeMSegment
			, const string& sref
			, const string& Infmt
			, const string& Outfmt
			, const usmallint Latency
			, const string& Comment
		) : WdbeMSegment() {
	lineno = 0;
	ixWIelValid = 0;

	this->irefRefWdbeCSegment = irefRefWdbeCSegment;
	this->hsrefSupRefWdbeMSegment = hsrefSupRefWdbeMSegment;
	this->sref = sref;
	this->Infmt = Infmt;
	this->Outfmt = Outfmt;
	this->Latency = Latency;
	this->Comment = Comment;
};

IexWdbeDal::ImeitemIMSegment::ImeitemIMSegment(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMSegment()
		{
	WdbeMSegment* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbemsegment->loadRecByRef(ref, &rec)) {
		refWdbeCSegment = rec->refWdbeCSegment;
		pplRefWdbeMPipeline = rec->pplRefWdbeMPipeline;
		pplNum = rec->pplNum;
		supRefWdbeMSegment = rec->supRefWdbeMSegment;
		sref = rec->sref;
		Infmt = rec->Infmt;
		Outfmt = rec->Outfmt;
		Latency = rec->Latency;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDal::ImeitemIMSegment::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {irefRefWdbeCSegment = atoll(txtrd.fields[0].c_str()); ixWIelValid += ImeIMSegment::VecWIel::IREFREFWDBECSEGMENT;};
	if (txtrd.fields.size() > 1) {hsrefSupRefWdbeMSegment = txtrd.fields[1]; ixWIelValid += ImeIMSegment::VecWIel::HSREFSUPREFWDBEMSEGMENT;};
	if (txtrd.fields.size() > 2) {sref = txtrd.fields[2]; ixWIelValid += ImeIMSegment::VecWIel::SREF;};
	if (txtrd.fields.size() > 3) {Infmt = txtrd.fields[3]; ixWIelValid += ImeIMSegment::VecWIel::INFMT;};
	if (txtrd.fields.size() > 4) {Outfmt = txtrd.fields[4]; ixWIelValid += ImeIMSegment::VecWIel::OUTFMT;};
	if (txtrd.fields.size() > 5) {Latency = atoi(txtrd.fields[5].c_str()); ixWIelValid += ImeIMSegment::VecWIel::LATENCY;};
	if (txtrd.fields.size() > 6) {Comment = txtrd.fields[6]; ixWIelValid += ImeIMSegment::VecWIel::COMMENT;};

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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSegment"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDal::ImeitemIMSegment::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUbigintUclc(docctx, basexpath, "irefRefWdbeCSegment", "clu", irefRefWdbeCSegment)) ixWIelValid += ImeIMSegment::VecWIel::IREFREFWDBECSEGMENT;
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefWdbeMSegment", "sup", hsrefSupRefWdbeMSegment)) ixWIelValid += ImeIMSegment::VecWIel::HSREFSUPREFWDBEMSEGMENT;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMSegment::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Infmt", "ifm", Infmt)) ixWIelValid += ImeIMSegment::VecWIel::INFMT;
		if (extractStringUclc(docctx, basexpath, "Outfmt", "ofm", Outfmt)) ixWIelValid += ImeIMSegment::VecWIel::OUTFMT;
		if (extractUsmallintUclc(docctx, basexpath, "Latency", "lcy", Latency)) ixWIelValid += ImeIMSegment::VecWIel::LATENCY;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMSegment::VecWIel::COMMENT;
	};
};

void IexWdbeDal::ImeitemIMSegment::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << irefRefWdbeCSegment << "\t" << hsrefSupRefWdbeMSegment << "\t" << sref << "\t" << Infmt << "\t" << Outfmt << "\t" << Latency << "\t" << Comment << endl;
};

void IexWdbeDal::ImeitemIMSegment::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","clu","sup","srf","ifm","ofm","lcy","cmt"};
	else tags = {"ImeitemIMSegment","irefRefWdbeCSegment","hsrefSupRefWdbeMSegment","sref","Infmt","Outfmt","Latency","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUbigint(wr, tags[1], irefRefWdbeCSegment);
		writeString(wr, tags[2], hsrefSupRefWdbeMSegment);
		writeString(wr, tags[3], sref);
		writeString(wr, tags[4], Infmt);
		writeString(wr, tags[5], Outfmt);
		writeUsmallint(wr, tags[6], Latency);
		writeString(wr, tags[7], Comment);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDal::ImeIMSegment::VecWIel
 ******************************************************************************/

uint IexWdbeDal::ImeIMSegment::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "irefrefwdbecsegment") ix |= IREFREFWDBECSEGMENT;
		else if (ss[i] == "hsrefsuprefwdbemsegment") ix |= HSREFSUPREFWDBEMSEGMENT;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "infmt") ix |= INFMT;
		else if (ss[i] == "outfmt") ix |= OUTFMT;
		else if (ss[i] == "latency") ix |= LATENCY;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDal::ImeIMSegment::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDal::ImeIMSegment::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & IREFREFWDBECSEGMENT) ss.push_back("irefRefWdbeCSegment");
	if (ix & HSREFSUPREFWDBEMSEGMENT) ss.push_back("hsrefSupRefWdbeMSegment");
	if (ix & SREF) ss.push_back("sref");
	if (ix & INFMT) ss.push_back("Infmt");
	if (ix & OUTFMT) ss.push_back("Outfmt");
	if (ix & LATENCY) ss.push_back("Latency");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDal::ImeIMSegment
 ******************************************************************************/

IexWdbeDal::ImeIMSegment::ImeIMSegment() {
};

IexWdbeDal::ImeIMSegment::~ImeIMSegment() {
	clear();
};

void IexWdbeDal::ImeIMSegment::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDal::ImeIMSegment::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDal::ImeitemIMSegment* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeDal::ImeitemIMSegment();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 3) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSegment"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMSegment"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMSEGMENT) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSegment"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMSegment"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDal::ImeIMSegment::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDal::ImeitemIMSegment* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMSegment");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMSegment", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMSegment";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDal::ImeitemIMSegment();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDal::ImeIMSegment::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMSegment." << StrMod::replaceChar(ImeIMSegment::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMSegment.end" << endl;
	};
};

void IexWdbeDal::ImeIMSegment::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMSegment");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDal::ImeitemIMPipeline
 ******************************************************************************/

IexWdbeDal::ImeitemIMPipeline::ImeitemIMPipeline(
			const string& sref
			, const string& clkSrefWdbeMSignal
			, const string& clgSrefWdbeMSignal
			, const string& asrSrefWdbeMSignal
			, const usmallint Depth
			, const string& Comment
		) : WdbeMPipeline() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
	this->clkSrefWdbeMSignal = clkSrefWdbeMSignal;
	this->clgSrefWdbeMSignal = clgSrefWdbeMSignal;
	this->asrSrefWdbeMSignal = asrSrefWdbeMSignal;
	this->Depth = Depth;
	this->Comment = Comment;
};

IexWdbeDal::ImeitemIMPipeline::ImeitemIMPipeline(
			DbsWdbe* dbswdbe
			, const ubigint ref
		) :
			ImeitemIMPipeline()
		{
	WdbeMPipeline* rec = NULL;

	this->ref = ref;

	if (dbswdbe->tblwdbempipeline->loadRecByRef(ref, &rec)) {
		hsmRefWdbeMModule = rec->hsmRefWdbeMModule;
		sref = rec->sref;
		clkSrefWdbeMSignal = rec->clkSrefWdbeMSignal;
		clgSrefWdbeMSignal = rec->clgSrefWdbeMSignal;
		asrSrefWdbeMSignal = rec->asrSrefWdbeMSignal;
		Depth = rec->Depth;
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeDal::ImeitemIMPipeline::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMPipeline::VecWIel::SREF;};
	if (txtrd.fields.size() > 1) {clkSrefWdbeMSignal = txtrd.fields[1]; ixWIelValid += ImeIMPipeline::VecWIel::CLKSREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 2) {clgSrefWdbeMSignal = txtrd.fields[2]; ixWIelValid += ImeIMPipeline::VecWIel::CLGSREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 3) {asrSrefWdbeMSignal = txtrd.fields[3]; ixWIelValid += ImeIMPipeline::VecWIel::ASRSREFWDBEMSIGNAL;};
	if (txtrd.fields.size() > 4) {Depth = atoi(txtrd.fields[4].c_str()); ixWIelValid += ImeIMPipeline::VecWIel::DEPTH;};
	if (txtrd.fields.size() > 5) {Comment = txtrd.fields[5]; ixWIelValid += ImeIMPipeline::VecWIel::COMMENT;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEICSEGMENT)) {
					imeicsegment.readTxt(txtrd);
					continue;

				} else if ((txtrd.il == 3) && (txtrd.ixVToken == VecVIme::IMEIMSEGMENT)) {
					imeimsegment.readTxt(txtrd);
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
				throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPipeline"}, {"lineno",to_string(lineno)}});
		};
	};
};

void IexWdbeDal::ImeitemIMPipeline::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMPipeline::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "clkSrefWdbeMSignal", "clk", clkSrefWdbeMSignal)) ixWIelValid += ImeIMPipeline::VecWIel::CLKSREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "clgSrefWdbeMSignal", "clg", clgSrefWdbeMSignal)) ixWIelValid += ImeIMPipeline::VecWIel::CLGSREFWDBEMSIGNAL;
		if (extractStringUclc(docctx, basexpath, "asrSrefWdbeMSignal", "asr", asrSrefWdbeMSignal)) ixWIelValid += ImeIMPipeline::VecWIel::ASRSREFWDBEMSIGNAL;
		if (extractUsmallintUclc(docctx, basexpath, "Depth", "dth", Depth)) ixWIelValid += ImeIMPipeline::VecWIel::DEPTH;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMPipeline::VecWIel::COMMENT;
		imeicsegment.readXML(docctx, basexpath);
		imeimsegment.readXML(docctx, basexpath);
	};
};

void IexWdbeDal::ImeitemIMPipeline::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << clkSrefWdbeMSignal << "\t" << clgSrefWdbeMSignal << "\t" << asrSrefWdbeMSignal << "\t" << Depth << "\t" << Comment << endl;
	imeicsegment.writeTxt(outfile);
	imeimsegment.writeTxt(outfile);
};

void IexWdbeDal::ImeitemIMPipeline::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","srf","clk","clg","asr","dth","cmt"};
	else tags = {"ImeitemIMPipeline","sref","clkSrefWdbeMSignal","clgSrefWdbeMSignal","asrSrefWdbeMSignal","Depth","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], sref);
		writeString(wr, tags[2], clkSrefWdbeMSignal);
		writeString(wr, tags[3], clgSrefWdbeMSignal);
		writeString(wr, tags[4], asrSrefWdbeMSignal);
		writeUsmallint(wr, tags[5], Depth);
		writeString(wr, tags[6], Comment);
		imeicsegment.writeXML(wr, shorttags);
		imeimsegment.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDal::ImeIMPipeline::VecWIel
 ******************************************************************************/

uint IexWdbeDal::ImeIMPipeline::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "clksrefwdbemsignal") ix |= CLKSREFWDBEMSIGNAL;
		else if (ss[i] == "clgsrefwdbemsignal") ix |= CLGSREFWDBEMSIGNAL;
		else if (ss[i] == "asrsrefwdbemsignal") ix |= ASRSREFWDBEMSIGNAL;
		else if (ss[i] == "depth") ix |= DEPTH;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeDal::ImeIMPipeline::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDal::ImeIMPipeline::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");
	if (ix & CLKSREFWDBEMSIGNAL) ss.push_back("clkSrefWdbeMSignal");
	if (ix & CLGSREFWDBEMSIGNAL) ss.push_back("clgSrefWdbeMSignal");
	if (ix & ASRSREFWDBEMSIGNAL) ss.push_back("asrSrefWdbeMSignal");
	if (ix & DEPTH) ss.push_back("Depth");
	if (ix & COMMENT) ss.push_back("Comment");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDal::ImeIMPipeline
 ******************************************************************************/

IexWdbeDal::ImeIMPipeline::ImeIMPipeline() {
};

IexWdbeDal::ImeIMPipeline::~ImeIMPipeline() {
	clear();
};

void IexWdbeDal::ImeIMPipeline::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDal::ImeIMPipeline::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDal::ImeitemIMPipeline* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeDal::ImeitemIMPipeline();
					nodes.push_back(ii);

					ii->readTxt(txtrd);

					break;

				} else if (txtrd.il < 2) {
					throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPipeline"}, {"lineno",to_string(txtrd.linecnt)}});

				} else throw SbeException(SbeException::TXTRD_CONTENT, {{"ime","ImeIMPipeline"}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::FOOTER:
				if (txtrd.ixVToken == VecVIme::IMEIMPIPELINE) return;
				else throw SbeException(SbeException::TXTRD_TKNMISPL, {{"tkn",VecVIme::getSref(txtrd.ixVToken)}, {"lineno",to_string(txtrd.linecnt)}});

			case Txtrd::VecVLinetype::COMMENT:
				continue;

			default:
				throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPipeline"}, {"lineno",to_string(txtrd.linecnt)}});
		};
	};

	if (txtrd.eof()) throw SbeException(SbeException::TXTRD_ENDTKN, {{"ime","ImeIMPipeline"}, {"lineno",to_string(txtrd.linecnt)}});
};

void IexWdbeDal::ImeIMPipeline::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDal::ImeitemIMPipeline* ii = NULL;

	bool basefound;

	string s;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ImeIMPipeline");

	clear();

	if (basefound) {
		extractList(docctx, basexpath, "ImeitemIMPipeline", "Ii", "num", nums, _shorttags);

		for (unsigned int i = 0; i < nums.size(); i++) {
			s = basexpath + "/";
			if (_shorttags[i]) s += "Ii"; else s += "ImeitemIMPipeline";
			s += "[@num='" + to_string(nums[i]) + "']";

			ii = new IexWdbeDal::ImeitemIMPipeline();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDal::ImeIMPipeline::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMPipeline." << StrMod::replaceChar(ImeIMPipeline::VecWIel::getSrefs(63), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMPipeline.end" << endl;
	};
};

void IexWdbeDal::ImeIMPipeline::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	if (nodes.size() > 0) {
		xmlTextWriterStartElement(wr, BAD_CAST "ImeIMPipeline");
			for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, i+1, shorttags);
		xmlTextWriterEndElement(wr);
	};
};

/******************************************************************************
 class IexWdbeDal::ImeitemIMModule
 ******************************************************************************/

IexWdbeDal::ImeitemIMModule::ImeitemIMModule(
			const string& hsrefSupRefWdbeMModule
			, const string& sref
		) : WdbeMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefSupRefWdbeMModule = hsrefSupRefWdbeMModule;
	this->sref = sref;
};

IexWdbeDal::ImeitemIMModule::ImeitemIMModule(
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

void IexWdbeDal::ImeitemIMModule::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefSupRefWdbeMModule = txtrd.fields[0]; ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMModule::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMPIPELINE)) {
					imeimpipeline.readTxt(txtrd);
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

void IexWdbeDal::ImeitemIMModule::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefWdbeMModule", "sup", hsrefSupRefWdbeMModule)) ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMModule::VecWIel::SREF;
		imeimpipeline.readXML(docctx, basexpath);
	};
};

void IexWdbeDal::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefSupRefWdbeMModule << "\t" << sref << endl;
	imeimpipeline.writeTxt(outfile);
};

void IexWdbeDal::ImeitemIMModule::writeXML(
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
		imeimpipeline.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDal::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWdbeDal::ImeIMModule::VecWIel::getIx(
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

void IexWdbeDal::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDal::ImeIMModule::VecWIel::getSrefs(
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
 class IexWdbeDal::ImeIMModule
 ******************************************************************************/

IexWdbeDal::ImeIMModule::ImeIMModule() {
};

IexWdbeDal::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWdbeDal::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDal::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDal::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeDal::ImeitemIMModule();
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

void IexWdbeDal::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDal::ImeitemIMModule* ii = NULL;

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

			ii = new IexWdbeDal::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDal::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMModule.end" << endl;
	};
};

void IexWdbeDal::ImeIMModule::writeXML(
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
 class IexWdbeDal::ImeitemIMUnit
 ******************************************************************************/

IexWdbeDal::ImeitemIMUnit::ImeitemIMUnit(
			const string& sref
		) : WdbeMUnit() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexWdbeDal::ImeitemIMUnit::ImeitemIMUnit(
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

void IexWdbeDal::ImeitemIMUnit::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUnit::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMMODULE)) {
					imeimmodule.readTxt(txtrd);
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

void IexWdbeDal::ImeitemIMUnit::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUnit::VecWIel::SREF;
		imeimmodule.readXML(docctx, basexpath);
	};
};

void IexWdbeDal::ImeitemIMUnit::writeTxt(
			fstream& outfile
		) {
	outfile << sref << endl;
	imeimmodule.writeTxt(outfile);
};

void IexWdbeDal::ImeitemIMUnit::writeXML(
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
		imeimmodule.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeDal::ImeIMUnit::VecWIel
 ******************************************************************************/

uint IexWdbeDal::ImeIMUnit::VecWIel::getIx(
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

void IexWdbeDal::ImeIMUnit::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeDal::ImeIMUnit::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeDal::ImeIMUnit
 ******************************************************************************/

IexWdbeDal::ImeIMUnit::ImeIMUnit() {
};

IexWdbeDal::ImeIMUnit::~ImeIMUnit() {
	clear();
};

void IexWdbeDal::ImeIMUnit::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeDal::ImeIMUnit::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeDal::ImeitemIMUnit* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeDal::ImeitemIMUnit();
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

void IexWdbeDal::ImeIMUnit::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeDal::ImeitemIMUnit* ii = NULL;

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

			ii = new IexWdbeDal::ImeitemIMUnit();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeDal::ImeIMUnit::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUnit." << StrMod::replaceChar(ImeIMUnit::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUnit.end" << endl;
	};
};

void IexWdbeDal::ImeIMUnit::writeXML(
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
 namespace IexWdbeDal
 ******************************************************************************/

void IexWdbeDal::parseFromFile(
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
			Txtrd rd(fullpath, rectpath, "IexWdbeDal", Version("1.1.6"), VecVIme::getIx);
			readTxt(rd, imeimunit);
	};
};

void IexWdbeDal::exportToFile(
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

void IexWdbeDal::readTxt(
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

void IexWdbeDal::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMUnit& imeimunit
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeDal")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.1.6")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.1.6"}});
		};

		// look for XML sub-blocks
		imeimunit.readXML(docctx, basexpath);

	} else {
		imeimunit = ImeIMUnit();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeDal"}});
	};
};

void IexWdbeDal::writeTxt(
			fstream& outfile
			, ImeIMUnit& imeimunit
		) {
	outfile << "IexWdbeDal v" WDBE_VERSION << endl;

	imeimunit.writeTxt(outfile);
};

void IexWdbeDal::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMUnit& imeimunit
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeDal");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeimunit.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeDal::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEICSEGMENT,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMPIPELINE,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMSEGMENT,VecWdbeVIop::INS}};
};

uint IexWdbeDal::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};
