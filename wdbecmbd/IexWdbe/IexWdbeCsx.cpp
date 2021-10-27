/**
	* \file IexWdbeCsx.cpp
	* data blocks and readers/writers for import/export complex IexWdbeCsx (implementation)
	* \copyright (C) 2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
	*/
// IP header --- ABOVE

#include "IexWdbeCsx.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class IexWdbeCsx::VecVIme
 ******************************************************************************/

uint IexWdbeCsx::VecVIme::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "imeiamcommandinvpar1") return IMEIAMCOMMANDINVPAR1;
	if (s == "imeiamcommandinvpar2") return IMEIAMCOMMANDINVPAR2;
	if (s == "imeiamcommandretpar1") return IMEIAMCOMMANDRETPAR1;
	if (s == "imeiamcommandretpar2") return IMEIAMCOMMANDRETPAR2;
	if (s == "imeiamerrorpar1") return IMEIAMERRORPAR1;
	if (s == "imeiamerrorpar2") return IMEIAMERRORPAR2;
	if (s == "imeimcommand1") return IMEIMCOMMAND1;
	if (s == "imeimcommand2") return IMEIMCOMMAND2;
	if (s == "imeimcontroller") return IMEIMCONTROLLER;
	if (s == "imeimerror1") return IMEIMERROR1;
	if (s == "imeimerror2") return IMEIMERROR2;
	if (s == "imeimmodule") return IMEIMMODULE;
	if (s == "imeimunit") return IMEIMUNIT;
	if (s == "imeimvector1") return IMEIMVECTOR1;
	if (s == "imeimvector2") return IMEIMVECTOR2;
	if (s == "imeimvectoritem1") return IMEIMVECTORITEM1;
	if (s == "imeimvectoritem2") return IMEIMVECTORITEM2;
	if (s == "imeirmcommandmcontroller") return IMEIRMCOMMANDMCONTROLLER;

	return(0);
};

string IexWdbeCsx::VecVIme::getSref(
			const uint ix
		) {
	if (ix == IMEIAMCOMMANDINVPAR1) return("ImeIAMCommandInvpar1");
	if (ix == IMEIAMCOMMANDINVPAR2) return("ImeIAMCommandInvpar2");
	if (ix == IMEIAMCOMMANDRETPAR1) return("ImeIAMCommandRetpar1");
	if (ix == IMEIAMCOMMANDRETPAR2) return("ImeIAMCommandRetpar2");
	if (ix == IMEIAMERRORPAR1) return("ImeIAMErrorPar1");
	if (ix == IMEIAMERRORPAR2) return("ImeIAMErrorPar2");
	if (ix == IMEIMCOMMAND1) return("ImeIMCommand1");
	if (ix == IMEIMCOMMAND2) return("ImeIMCommand2");
	if (ix == IMEIMCONTROLLER) return("ImeIMController");
	if (ix == IMEIMERROR1) return("ImeIMError1");
	if (ix == IMEIMERROR2) return("ImeIMError2");
	if (ix == IMEIMMODULE) return("ImeIMModule");
	if (ix == IMEIMUNIT) return("ImeIMUnit");
	if (ix == IMEIMVECTOR1) return("ImeIMVector1");
	if (ix == IMEIMVECTOR2) return("ImeIMVector2");
	if (ix == IMEIMVECTORITEM1) return("ImeIMVectoritem1");
	if (ix == IMEIMVECTORITEM2) return("ImeIMVectoritem2");
	if (ix == IMEIRMCOMMANDMCONTROLLER) return("ImeIRMCommandMController");

	return("");
};

/******************************************************************************
 class IexWdbeCsx::ImeitemIAMCommandInvpar1
 ******************************************************************************/

IexWdbeCsx::ImeitemIAMCommandInvpar1::ImeitemIAMCommandInvpar1(
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

IexWdbeCsx::ImeitemIAMCommandInvpar1::ImeitemIAMCommandInvpar1(
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

void IexWdbeCsx::ImeitemIAMCommandInvpar1::readTxt(
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

void IexWdbeCsx::ImeitemIAMCommandInvpar1::readXML(
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

void IexWdbeCsx::ImeitemIAMCommandInvpar1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Defval << "\t" << srefRefWdbeMVectoritem << "\t" << Comment << endl;
};

void IexWdbeCsx::ImeitemIAMCommandInvpar1::writeXML(
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
 class IexWdbeCsx::ImeIAMCommandInvpar1::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIAMCommandInvpar1::VecWIel::getIx(
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

void IexWdbeCsx::ImeIAMCommandInvpar1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIAMCommandInvpar1::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIAMCommandInvpar1
 ******************************************************************************/

IexWdbeCsx::ImeIAMCommandInvpar1::ImeIAMCommandInvpar1() {
};

IexWdbeCsx::ImeIAMCommandInvpar1::~ImeIAMCommandInvpar1() {
	clear();
};

void IexWdbeCsx::ImeIAMCommandInvpar1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIAMCommandInvpar1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIAMCommandInvpar1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeCsx::ImeitemIAMCommandInvpar1();
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

void IexWdbeCsx::ImeIAMCommandInvpar1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIAMCommandInvpar1* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIAMCommandInvpar1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIAMCommandInvpar1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMCommandInvpar1." << StrMod::replaceChar(ImeIAMCommandInvpar1::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMCommandInvpar1.end" << endl;
	};
};

void IexWdbeCsx::ImeIAMCommandInvpar1::writeXML(
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
 class IexWdbeCsx::ImeitemIAMCommandRetpar1
 ******************************************************************************/

IexWdbeCsx::ImeitemIAMCommandRetpar1::ImeitemIAMCommandRetpar1(
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

IexWdbeCsx::ImeitemIAMCommandRetpar1::ImeitemIAMCommandRetpar1(
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

void IexWdbeCsx::ImeitemIAMCommandRetpar1::readTxt(
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

void IexWdbeCsx::ImeitemIAMCommandRetpar1::readXML(
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

void IexWdbeCsx::ImeitemIAMCommandRetpar1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeCsx::ImeitemIAMCommandRetpar1::writeXML(
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
 class IexWdbeCsx::ImeIAMCommandRetpar1::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIAMCommandRetpar1::VecWIel::getIx(
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

void IexWdbeCsx::ImeIAMCommandRetpar1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIAMCommandRetpar1::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIAMCommandRetpar1
 ******************************************************************************/

IexWdbeCsx::ImeIAMCommandRetpar1::ImeIAMCommandRetpar1() {
};

IexWdbeCsx::ImeIAMCommandRetpar1::~ImeIAMCommandRetpar1() {
	clear();
};

void IexWdbeCsx::ImeIAMCommandRetpar1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIAMCommandRetpar1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIAMCommandRetpar1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeCsx::ImeitemIAMCommandRetpar1();
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

void IexWdbeCsx::ImeIAMCommandRetpar1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIAMCommandRetpar1* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIAMCommandRetpar1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIAMCommandRetpar1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMCommandRetpar1." << StrMod::replaceChar(ImeIAMCommandRetpar1::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMCommandRetpar1.end" << endl;
	};
};

void IexWdbeCsx::ImeIAMCommandRetpar1::writeXML(
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
 class IexWdbeCsx::ImeitemIMCommand1
 ******************************************************************************/

IexWdbeCsx::ImeitemIMCommand1::ImeitemIMCommand1(
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

IexWdbeCsx::ImeitemIMCommand1::ImeitemIMCommand1(
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

void IexWdbeCsx::ImeitemIMCommand1::readTxt(
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

void IexWdbeCsx::ImeitemIMCommand1::readXML(
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

void IexWdbeCsx::ImeitemIMCommand1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << refNum << "\t" << sref << "\t" << VecWdbeVMCommandRettype::getSref(ixVRettype) << "\t" << Comment << endl;
	imeiamcommandinvpar1.writeTxt(outfile);
	imeiamcommandretpar1.writeTxt(outfile);
};

void IexWdbeCsx::ImeitemIMCommand1::writeXML(
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
 class IexWdbeCsx::ImeIMCommand1::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMCommand1::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "refnum") ix |= REFNUM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvrettype") ix |= SREFIXVRETTYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeCsx::ImeIMCommand1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMCommand1::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIMCommand1
 ******************************************************************************/

IexWdbeCsx::ImeIMCommand1::ImeIMCommand1() {
};

IexWdbeCsx::ImeIMCommand1::~ImeIMCommand1() {
	clear();
};

void IexWdbeCsx::ImeIMCommand1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMCommand1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMCommand1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeCsx::ImeitemIMCommand1();
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

void IexWdbeCsx::ImeIMCommand1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMCommand1* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMCommand1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMCommand1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMCommand1." << StrMod::replaceChar(ImeIMCommand1::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMCommand1.end" << endl;
	};
};

void IexWdbeCsx::ImeIMCommand1::writeXML(
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
 class IexWdbeCsx::ImeitemIAMErrorPar1
 ******************************************************************************/

IexWdbeCsx::ImeitemIAMErrorPar1::ImeitemIAMErrorPar1(
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

IexWdbeCsx::ImeitemIAMErrorPar1::ImeitemIAMErrorPar1(
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

void IexWdbeCsx::ImeitemIAMErrorPar1::readTxt(
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

void IexWdbeCsx::ImeitemIAMErrorPar1::readXML(
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

void IexWdbeCsx::ImeitemIAMErrorPar1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeCsx::ImeitemIAMErrorPar1::writeXML(
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
 class IexWdbeCsx::ImeIAMErrorPar1::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIAMErrorPar1::VecWIel::getIx(
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

void IexWdbeCsx::ImeIAMErrorPar1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIAMErrorPar1::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIAMErrorPar1
 ******************************************************************************/

IexWdbeCsx::ImeIAMErrorPar1::ImeIAMErrorPar1() {
};

IexWdbeCsx::ImeIAMErrorPar1::~ImeIAMErrorPar1() {
	clear();
};

void IexWdbeCsx::ImeIAMErrorPar1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIAMErrorPar1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIAMErrorPar1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeCsx::ImeitemIAMErrorPar1();
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

void IexWdbeCsx::ImeIAMErrorPar1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIAMErrorPar1* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIAMErrorPar1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIAMErrorPar1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIAMErrorPar1." << StrMod::replaceChar(ImeIAMErrorPar1::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIAMErrorPar1.end" << endl;
	};
};

void IexWdbeCsx::ImeIAMErrorPar1::writeXML(
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
 class IexWdbeCsx::ImeitemIMError1
 ******************************************************************************/

IexWdbeCsx::ImeitemIMError1::ImeitemIMError1(
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

IexWdbeCsx::ImeitemIMError1::ImeitemIMError1(
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

void IexWdbeCsx::ImeitemIMError1::readTxt(
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

void IexWdbeCsx::ImeitemIMError1::readXML(
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

void IexWdbeCsx::ImeitemIMError1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << refNum << "\t" << sref << "\t" << Comment << endl;
	imeiamerrorpar1.writeTxt(outfile);
};

void IexWdbeCsx::ImeitemIMError1::writeXML(
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
 class IexWdbeCsx::ImeIMError1::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMError1::VecWIel::getIx(
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

void IexWdbeCsx::ImeIMError1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMError1::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIMError1
 ******************************************************************************/

IexWdbeCsx::ImeIMError1::ImeIMError1() {
};

IexWdbeCsx::ImeIMError1::~ImeIMError1() {
	clear();
};

void IexWdbeCsx::ImeIMError1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMError1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMError1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeCsx::ImeitemIMError1();
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

void IexWdbeCsx::ImeIMError1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMError1* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMError1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMError1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMError1." << StrMod::replaceChar(ImeIMError1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMError1.end" << endl;
	};
};

void IexWdbeCsx::ImeIMError1::writeXML(
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
 class IexWdbeCsx::ImeitemIAMCommandInvpar2
 ******************************************************************************/

IexWdbeCsx::ImeitemIAMCommandInvpar2::ImeitemIAMCommandInvpar2(
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

IexWdbeCsx::ImeitemIAMCommandInvpar2::ImeitemIAMCommandInvpar2(
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

void IexWdbeCsx::ImeitemIAMCommandInvpar2::readTxt(
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

void IexWdbeCsx::ImeitemIAMCommandInvpar2::readXML(
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

void IexWdbeCsx::ImeitemIAMCommandInvpar2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Defval << "\t" << srefRefWdbeMVectoritem << "\t" << Comment << endl;
};

void IexWdbeCsx::ImeitemIAMCommandInvpar2::writeXML(
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
 class IexWdbeCsx::ImeIAMCommandInvpar2::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIAMCommandInvpar2::VecWIel::getIx(
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

void IexWdbeCsx::ImeIAMCommandInvpar2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIAMCommandInvpar2::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIAMCommandInvpar2
 ******************************************************************************/

IexWdbeCsx::ImeIAMCommandInvpar2::ImeIAMCommandInvpar2() {
};

IexWdbeCsx::ImeIAMCommandInvpar2::~ImeIAMCommandInvpar2() {
	clear();
};

void IexWdbeCsx::ImeIAMCommandInvpar2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIAMCommandInvpar2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIAMCommandInvpar2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeCsx::ImeitemIAMCommandInvpar2();
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

void IexWdbeCsx::ImeIAMCommandInvpar2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIAMCommandInvpar2* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIAMCommandInvpar2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIAMCommandInvpar2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIAMCommandInvpar2." << StrMod::replaceChar(ImeIAMCommandInvpar2::VecWIel::getSrefs(127), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIAMCommandInvpar2.end" << endl;
	};
};

void IexWdbeCsx::ImeIAMCommandInvpar2::writeXML(
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
 class IexWdbeCsx::ImeitemIAMCommandRetpar2
 ******************************************************************************/

IexWdbeCsx::ImeitemIAMCommandRetpar2::ImeitemIAMCommandRetpar2(
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

IexWdbeCsx::ImeitemIAMCommandRetpar2::ImeitemIAMCommandRetpar2(
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

void IexWdbeCsx::ImeitemIAMCommandRetpar2::readTxt(
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

void IexWdbeCsx::ImeitemIAMCommandRetpar2::readXML(
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

void IexWdbeCsx::ImeitemIAMCommandRetpar2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeCsx::ImeitemIAMCommandRetpar2::writeXML(
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
 class IexWdbeCsx::ImeIAMCommandRetpar2::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIAMCommandRetpar2::VecWIel::getIx(
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

void IexWdbeCsx::ImeIAMCommandRetpar2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIAMCommandRetpar2::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIAMCommandRetpar2
 ******************************************************************************/

IexWdbeCsx::ImeIAMCommandRetpar2::ImeIAMCommandRetpar2() {
};

IexWdbeCsx::ImeIAMCommandRetpar2::~ImeIAMCommandRetpar2() {
	clear();
};

void IexWdbeCsx::ImeIAMCommandRetpar2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIAMCommandRetpar2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIAMCommandRetpar2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeCsx::ImeitemIAMCommandRetpar2();
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

void IexWdbeCsx::ImeIAMCommandRetpar2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIAMCommandRetpar2* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIAMCommandRetpar2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIAMCommandRetpar2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIAMCommandRetpar2." << StrMod::replaceChar(ImeIAMCommandRetpar2::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIAMCommandRetpar2.end" << endl;
	};
};

void IexWdbeCsx::ImeIAMCommandRetpar2::writeXML(
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
 class IexWdbeCsx::ImeitemIMCommand2
 ******************************************************************************/

IexWdbeCsx::ImeitemIMCommand2::ImeitemIMCommand2(
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

IexWdbeCsx::ImeitemIMCommand2::ImeitemIMCommand2(
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
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeCsx::ImeitemIMCommand2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {refNum = atol(txtrd.fields[0].c_str()); ixWIelValid += ImeIMCommand2::VecWIel::REFNUM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMCommand2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {srefIxVRettype = txtrd.fields[2]; ixWIelValid += ImeIMCommand2::VecWIel::SREFIXVRETTYPE;};
	if (txtrd.fields.size() > 3) {Comment = txtrd.fields[3]; ixWIelValid += ImeIMCommand2::VecWIel::COMMENT;};

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

void IexWdbeCsx::ImeitemIMCommand2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUintUclc(docctx, basexpath, "refNum", "ren", refNum)) ixWIelValid += ImeIMCommand2::VecWIel::REFNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMCommand2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "srefIxVRettype", "rty", srefIxVRettype)) ixWIelValid += ImeIMCommand2::VecWIel::SREFIXVRETTYPE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMCommand2::VecWIel::COMMENT;
		imeiamcommandinvpar2.readXML(docctx, basexpath);
		imeiamcommandretpar2.readXML(docctx, basexpath);
	};
};

void IexWdbeCsx::ImeitemIMCommand2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << refNum << "\t" << sref << "\t" << VecWdbeVMCommandRettype::getSref(ixVRettype) << "\t" << Comment << endl;
	imeiamcommandinvpar2.writeTxt(outfile);
	imeiamcommandretpar2.writeTxt(outfile);
};

void IexWdbeCsx::ImeitemIMCommand2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ren","srf","rty","cmt"};
	else tags = {"ImeitemIMCommand2","refNum","sref","srefIxVRettype","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], refNum);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], VecWdbeVMCommandRettype::getSref(ixVRettype));
		writeString(wr, tags[4], Comment);
		imeiamcommandinvpar2.writeXML(wr, shorttags);
		imeiamcommandretpar2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeCsx::ImeIMCommand2::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMCommand2::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "refnum") ix |= REFNUM;
		else if (ss[i] == "sref") ix |= SREF;
		else if (ss[i] == "srefixvrettype") ix |= SREFIXVRETTYPE;
		else if (ss[i] == "comment") ix |= COMMENT;
	};

	return(ix);
};

void IexWdbeCsx::ImeIMCommand2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMCommand2::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIMCommand2
 ******************************************************************************/

IexWdbeCsx::ImeIMCommand2::ImeIMCommand2() {
};

IexWdbeCsx::ImeIMCommand2::~ImeIMCommand2() {
	clear();
};

void IexWdbeCsx::ImeIMCommand2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMCommand2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMCommand2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeCsx::ImeitemIMCommand2();
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

void IexWdbeCsx::ImeIMCommand2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMCommand2* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMCommand2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMCommand2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMCommand2." << StrMod::replaceChar(ImeIMCommand2::VecWIel::getSrefs(15), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMCommand2.end" << endl;
	};
};

void IexWdbeCsx::ImeIMCommand2::writeXML(
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
 class IexWdbeCsx::ImeitemIAMErrorPar2
 ******************************************************************************/

IexWdbeCsx::ImeitemIAMErrorPar2::ImeitemIAMErrorPar2(
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

IexWdbeCsx::ImeitemIAMErrorPar2::ImeitemIAMErrorPar2(
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

void IexWdbeCsx::ImeitemIAMErrorPar2::readTxt(
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

void IexWdbeCsx::ImeitemIAMErrorPar2::readXML(
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

void IexWdbeCsx::ImeitemIAMErrorPar2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << sref << "\t" << VecWdbeVPartype::getSref(ixWdbeVPartype) << "\t" << srefRefWdbeMVector << "\t" << Length << "\t" << Comment << endl;
};

void IexWdbeCsx::ImeitemIAMErrorPar2::writeXML(
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
 class IexWdbeCsx::ImeIAMErrorPar2::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIAMErrorPar2::VecWIel::getIx(
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

void IexWdbeCsx::ImeIAMErrorPar2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIAMErrorPar2::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIAMErrorPar2
 ******************************************************************************/

IexWdbeCsx::ImeIAMErrorPar2::ImeIAMErrorPar2() {
};

IexWdbeCsx::ImeIAMErrorPar2::~ImeIAMErrorPar2() {
	clear();
};

void IexWdbeCsx::ImeIAMErrorPar2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIAMErrorPar2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIAMErrorPar2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeCsx::ImeitemIAMErrorPar2();
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

void IexWdbeCsx::ImeIAMErrorPar2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIAMErrorPar2* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIAMErrorPar2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIAMErrorPar2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIAMErrorPar2." << StrMod::replaceChar(ImeIAMErrorPar2::VecWIel::getSrefs(31), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIAMErrorPar2.end" << endl;
	};
};

void IexWdbeCsx::ImeIAMErrorPar2::writeXML(
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
 class IexWdbeCsx::ImeitemIMError2
 ******************************************************************************/

IexWdbeCsx::ImeitemIMError2::ImeitemIMError2(
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

IexWdbeCsx::ImeitemIMError2::ImeitemIMError2(
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
		Comment = rec->Comment;

		delete rec;
	};
};

void IexWdbeCsx::ImeitemIMError2::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {refNum = atol(txtrd.fields[0].c_str()); ixWIelValid += ImeIMError2::VecWIel::REFNUM;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMError2::VecWIel::SREF;};
	if (txtrd.fields.size() > 2) {Comment = txtrd.fields[2]; ixWIelValid += ImeIMError2::VecWIel::COMMENT;};

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

void IexWdbeCsx::ImeitemIMError2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractUintUclc(docctx, basexpath, "refNum", "ren", refNum)) ixWIelValid += ImeIMError2::VecWIel::REFNUM;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMError2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMError2::VecWIel::COMMENT;
		imeiamerrorpar2.readXML(docctx, basexpath);
	};
};

void IexWdbeCsx::ImeitemIMError2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << refNum << "\t" << sref << "\t" << Comment << endl;
	imeiamerrorpar2.writeTxt(outfile);
};

void IexWdbeCsx::ImeitemIMError2::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","ren","srf","cmt"};
	else tags = {"ImeitemIMError2","refNum","sref","Comment"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeUint(wr, tags[1], refNum);
		writeString(wr, tags[2], sref);
		writeString(wr, tags[3], Comment);
		imeiamerrorpar2.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeCsx::ImeIMError2::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMError2::VecWIel::getIx(
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

void IexWdbeCsx::ImeIMError2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMError2::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIMError2
 ******************************************************************************/

IexWdbeCsx::ImeIMError2::ImeIMError2() {
};

IexWdbeCsx::ImeIMError2::~ImeIMError2() {
	clear();
};

void IexWdbeCsx::ImeIMError2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMError2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMError2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeCsx::ImeitemIMError2();
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

void IexWdbeCsx::ImeIMError2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMError2* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMError2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMError2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMError2." << StrMod::replaceChar(ImeIMError2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMError2.end" << endl;
	};
};

void IexWdbeCsx::ImeIMError2::writeXML(
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
 class IexWdbeCsx::ImeitemIMVectoritem2
 ******************************************************************************/

IexWdbeCsx::ImeitemIMVectoritem2::ImeitemIMVectoritem2(
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

IexWdbeCsx::ImeitemIMVectoritem2::ImeitemIMVectoritem2(
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

void IexWdbeCsx::ImeitemIMVectoritem2::readTxt(
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

void IexWdbeCsx::ImeitemIMVectoritem2::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVectoritem2::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMVectoritem2::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVectoritem2::VecWIel::COMMENT;
	};
};

void IexWdbeCsx::ImeitemIMVectoritem2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
};

void IexWdbeCsx::ImeitemIMVectoritem2::writeXML(
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
 class IexWdbeCsx::ImeIMVectoritem2::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMVectoritem2::VecWIel::getIx(
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

void IexWdbeCsx::ImeIMVectoritem2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMVectoritem2::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIMVectoritem2
 ******************************************************************************/

IexWdbeCsx::ImeIMVectoritem2::ImeIMVectoritem2() {
};

IexWdbeCsx::ImeIMVectoritem2::~ImeIMVectoritem2() {
	clear();
};

void IexWdbeCsx::ImeIMVectoritem2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMVectoritem2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMVectoritem2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 4) {
					ii = new IexWdbeCsx::ImeitemIMVectoritem2();
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

void IexWdbeCsx::ImeIMVectoritem2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMVectoritem2* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMVectoritem2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMVectoritem2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\t\tImeIMVectoritem2." << StrMod::replaceChar(ImeIMVectoritem2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\t\tImeIMVectoritem2.end" << endl;
	};
};

void IexWdbeCsx::ImeIMVectoritem2::writeXML(
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
 class IexWdbeCsx::ImeitemIMVector2
 ******************************************************************************/

IexWdbeCsx::ImeitemIMVector2::ImeitemIMVector2(
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

IexWdbeCsx::ImeitemIMVector2::ImeitemIMVector2(
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

void IexWdbeCsx::ImeitemIMVector2::readTxt(
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

void IexWdbeCsx::ImeitemIMVector2::readXML(
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

void IexWdbeCsx::ImeitemIMVector2::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << VecWdbeVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << srefsKOption << endl;
	imeimvectoritem2.writeTxt(outfile);
};

void IexWdbeCsx::ImeitemIMVector2::writeXML(
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
 class IexWdbeCsx::ImeIMVector2::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMVector2::VecWIel::getIx(
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

void IexWdbeCsx::ImeIMVector2::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMVector2::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIMVector2
 ******************************************************************************/

IexWdbeCsx::ImeIMVector2::ImeIMVector2() {
};

IexWdbeCsx::ImeIMVector2::~ImeIMVector2() {
	clear();
};

void IexWdbeCsx::ImeIMVector2::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMVector2::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMVector2* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeCsx::ImeitemIMVector2();
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

void IexWdbeCsx::ImeIMVector2::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMVector2* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMVector2();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMVector2::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIMVector2." << StrMod::replaceChar(ImeIMVector2::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIMVector2.end" << endl;
	};
};

void IexWdbeCsx::ImeIMVector2::writeXML(
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
 class IexWdbeCsx::ImeitemIRMCommandMController
 ******************************************************************************/

IexWdbeCsx::ImeitemIRMCommandMController::ImeitemIRMCommandMController(
			const string& srefRefWdbeMCommand
		) : WdbeRMCommandMController() {
	lineno = 0;
	ixWIelValid = 0;

	this->srefRefWdbeMCommand = srefRefWdbeMCommand;
};

IexWdbeCsx::ImeitemIRMCommandMController::ImeitemIRMCommandMController(
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

		delete rec;
	};
};

void IexWdbeCsx::ImeitemIRMCommandMController::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {srefRefWdbeMCommand = txtrd.fields[0]; ixWIelValid += ImeIRMCommandMController::VecWIel::SREFREFWDBEMCOMMAND;};

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

void IexWdbeCsx::ImeitemIRMCommandMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "srefRefWdbeMCommand", "cmd", srefRefWdbeMCommand)) ixWIelValid += ImeIRMCommandMController::VecWIel::SREFREFWDBEMCOMMAND;
	};
};

void IexWdbeCsx::ImeitemIRMCommandMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t\t" << srefRefWdbeMCommand << endl;
};

void IexWdbeCsx::ImeitemIRMCommandMController::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii","cmd"};
	else tags = {"ImeitemIRMCommandMController","srefRefWdbeMCommand"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		writeString(wr, tags[1], srefRefWdbeMCommand);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeCsx::ImeIRMCommandMController::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIRMCommandMController::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "srefrefwdbemcommand") ix |= SREFREFWDBEMCOMMAND;
	};

	return(ix);
};

void IexWdbeCsx::ImeIRMCommandMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFREFWDBEMCOMMAND); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIRMCommandMController::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREFREFWDBEMCOMMAND) ss.push_back("srefRefWdbeMCommand");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeCsx::ImeIRMCommandMController
 ******************************************************************************/

IexWdbeCsx::ImeIRMCommandMController::ImeIRMCommandMController() {
};

IexWdbeCsx::ImeIRMCommandMController::~ImeIRMCommandMController() {
	clear();
};

void IexWdbeCsx::ImeIRMCommandMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIRMCommandMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIRMCommandMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 3) {
					ii = new IexWdbeCsx::ImeitemIRMCommandMController();
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

void IexWdbeCsx::ImeIRMCommandMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIRMCommandMController* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIRMCommandMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIRMCommandMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\t\tImeIRMCommandMController." << StrMod::replaceChar(ImeIRMCommandMController::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\t\tImeIRMCommandMController.end" << endl;
	};
};

void IexWdbeCsx::ImeIRMCommandMController::writeXML(
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
 class IexWdbeCsx::ImeitemIMController
 ******************************************************************************/

IexWdbeCsx::ImeitemIMController::ImeitemIMController(
		) : WdbeMController() {
	lineno = 0;
	ixWIelValid = 0;

};

IexWdbeCsx::ImeitemIMController::ImeitemIMController(
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

void IexWdbeCsx::ImeitemIMController::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

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

void IexWdbeCsx::ImeitemIMController::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		imeimcommand2.readXML(docctx, basexpath);
		imeimerror2.readXML(docctx, basexpath);
		imeimvector2.readXML(docctx, basexpath);
		imeirmcommandmcontroller.readXML(docctx, basexpath);
	};
};

void IexWdbeCsx::ImeitemIMController::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << "^" << endl;
	imeimcommand2.writeTxt(outfile);
	imeimerror2.writeTxt(outfile);
	imeimvector2.writeTxt(outfile);
	imeirmcommandmcontroller.writeTxt(outfile);
};

void IexWdbeCsx::ImeitemIMController::writeXML(
			xmlTextWriter* wr
			, const uint num
			, const bool shorttags
		) {
	vector<string> tags;
	if (shorttags) tags = {"Ii"};
	else tags = {"ImeitemIMController"};

	xmlTextWriterStartElement(wr, BAD_CAST tags[0].c_str());
		xmlTextWriterWriteAttribute(wr, BAD_CAST "num", BAD_CAST to_string(num).c_str());
		imeimcommand2.writeXML(wr, shorttags);
		imeimerror2.writeXML(wr, shorttags);
		imeimvector2.writeXML(wr, shorttags);
		imeirmcommandmcontroller.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeCsx::ImeIMController::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMController::VecWIel::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
	};

	return(ix);
};

void IexWdbeCsx::ImeIMController::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; false;) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMController::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeCsx::ImeIMController
 ******************************************************************************/

IexWdbeCsx::ImeIMController::ImeIMController() {
};

IexWdbeCsx::ImeIMController::~ImeIMController() {
	clear();
};

void IexWdbeCsx::ImeIMController::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMController::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMController* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeCsx::ImeitemIMController();
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

void IexWdbeCsx::ImeIMController::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMController* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMController();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMController::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMController." << StrMod::replaceChar(ImeIMController::VecWIel::getSrefs(0), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMController.end" << endl;
	};
};

void IexWdbeCsx::ImeIMController::writeXML(
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
 class IexWdbeCsx::ImeitemIMModule
 ******************************************************************************/

IexWdbeCsx::ImeitemIMModule::ImeitemIMModule(
			const string& hsrefSupRefWdbeMModule
			, const string& sref
		) : WdbeMModule() {
	lineno = 0;
	ixWIelValid = 0;

	this->hsrefSupRefWdbeMModule = hsrefSupRefWdbeMModule;
	this->sref = sref;
};

IexWdbeCsx::ImeitemIMModule::ImeitemIMModule(
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

void IexWdbeCsx::ImeitemIMModule::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {hsrefSupRefWdbeMModule = txtrd.fields[0]; ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;};
	if (txtrd.fields.size() > 1) {sref = txtrd.fields[1]; ixWIelValid += ImeIMModule::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 2) && (txtrd.ixVToken == VecVIme::IMEIMCONTROLLER)) {
					imeimcontroller.readTxt(txtrd);
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

void IexWdbeCsx::ImeitemIMModule::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "hsrefSupRefWdbeMModule", "sup", hsrefSupRefWdbeMModule)) ixWIelValid += ImeIMModule::VecWIel::HSREFSUPREFWDBEMMODULE;
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMModule::VecWIel::SREF;
		imeimcontroller.readXML(docctx, basexpath);
	};
};

void IexWdbeCsx::ImeitemIMModule::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << hsrefSupRefWdbeMModule << "\t" << sref << endl;
	imeimcontroller.writeTxt(outfile);
};

void IexWdbeCsx::ImeitemIMModule::writeXML(
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
		imeimcontroller.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeCsx::ImeIMModule::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMModule::VecWIel::getIx(
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

void IexWdbeCsx::ImeIMModule::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMModule::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIMModule
 ******************************************************************************/

IexWdbeCsx::ImeIMModule::ImeIMModule() {
};

IexWdbeCsx::ImeIMModule::~ImeIMModule() {
	clear();
};

void IexWdbeCsx::ImeIMModule::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMModule::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMModule* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeCsx::ImeitemIMModule();
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

void IexWdbeCsx::ImeIMModule::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMModule* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMModule();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMModule::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMModule." << StrMod::replaceChar(ImeIMModule::VecWIel::getSrefs(3), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMModule.end" << endl;
	};
};

void IexWdbeCsx::ImeIMModule::writeXML(
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
 class IexWdbeCsx::ImeitemIMVectoritem1
 ******************************************************************************/

IexWdbeCsx::ImeitemIMVectoritem1::ImeitemIMVectoritem1(
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

IexWdbeCsx::ImeitemIMVectoritem1::ImeitemIMVectoritem1(
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

void IexWdbeCsx::ImeitemIMVectoritem1::readTxt(
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

void IexWdbeCsx::ImeitemIMVectoritem1::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMVectoritem1::VecWIel::SREF;
		if (extractStringUclc(docctx, basexpath, "Title", "tit", Title)) ixWIelValid += ImeIMVectoritem1::VecWIel::TITLE;
		if (extractStringUclc(docctx, basexpath, "Comment", "cmt", Comment)) ixWIelValid += ImeIMVectoritem1::VecWIel::COMMENT;
	};
};

void IexWdbeCsx::ImeitemIMVectoritem1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t\t" << sref << "\t" << Title << "\t" << Comment << endl;
};

void IexWdbeCsx::ImeitemIMVectoritem1::writeXML(
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
 class IexWdbeCsx::ImeIMVectoritem1::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMVectoritem1::VecWIel::getIx(
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

void IexWdbeCsx::ImeIMVectoritem1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*COMMENT); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMVectoritem1::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIMVectoritem1
 ******************************************************************************/

IexWdbeCsx::ImeIMVectoritem1::ImeIMVectoritem1() {
};

IexWdbeCsx::ImeIMVectoritem1::~ImeIMVectoritem1() {
	clear();
};

void IexWdbeCsx::ImeIMVectoritem1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMVectoritem1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMVectoritem1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 2) {
					ii = new IexWdbeCsx::ImeitemIMVectoritem1();
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

void IexWdbeCsx::ImeIMVectoritem1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMVectoritem1* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMVectoritem1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMVectoritem1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\t\tImeIMVectoritem1." << StrMod::replaceChar(ImeIMVectoritem1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\t\tImeIMVectoritem1.end" << endl;
	};
};

void IexWdbeCsx::ImeIMVectoritem1::writeXML(
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
 class IexWdbeCsx::ImeitemIMVector1
 ******************************************************************************/

IexWdbeCsx::ImeitemIMVector1::ImeitemIMVector1(
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

IexWdbeCsx::ImeitemIMVector1::ImeitemIMVector1(
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

void IexWdbeCsx::ImeitemIMVector1::readTxt(
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

void IexWdbeCsx::ImeitemIMVector1::readXML(
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

void IexWdbeCsx::ImeitemIMVector1::writeTxt(
			fstream& outfile
		) {
	outfile << "\t" << VecWdbeVMVectorBasetype::getSref(ixVBasetype) << "\t" << sref << "\t" << srefsKOption << endl;
	imeimvectoritem1.writeTxt(outfile);
};

void IexWdbeCsx::ImeitemIMVector1::writeXML(
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
 class IexWdbeCsx::ImeIMVector1::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMVector1::VecWIel::getIx(
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

void IexWdbeCsx::ImeIMVector1::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREFSKOPTION); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMVector1::VecWIel::getSrefs(
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
 class IexWdbeCsx::ImeIMVector1
 ******************************************************************************/

IexWdbeCsx::ImeIMVector1::ImeIMVector1() {
};

IexWdbeCsx::ImeIMVector1::~ImeIMVector1() {
	clear();
};

void IexWdbeCsx::ImeIMVector1::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMVector1::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMVector1* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 1) {
					ii = new IexWdbeCsx::ImeitemIMVector1();
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

void IexWdbeCsx::ImeIMVector1::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMVector1* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMVector1();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMVector1::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "\tImeIMVector1." << StrMod::replaceChar(ImeIMVector1::VecWIel::getSrefs(7), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "\tImeIMVector1.end" << endl;
	};
};

void IexWdbeCsx::ImeIMVector1::writeXML(
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
 class IexWdbeCsx::ImeitemIMUnit
 ******************************************************************************/

IexWdbeCsx::ImeitemIMUnit::ImeitemIMUnit(
			const string& sref
		) : WdbeMUnit() {
	lineno = 0;
	ixWIelValid = 0;

	this->sref = sref;
};

IexWdbeCsx::ImeitemIMUnit::ImeitemIMUnit(
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

void IexWdbeCsx::ImeitemIMUnit::readTxt(
			Txtrd& txtrd
		) {
	lineno = txtrd.linecnt;

	if (txtrd.fields.size() > 0) {sref = txtrd.fields[0]; ixWIelValid += ImeIMUnit::VecWIel::SREF;};

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::HEADER:
				if ((txtrd.il == 1) && (txtrd.ixVToken == VecVIme::IMEIMCOMMAND1)) {
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

void IexWdbeCsx::ImeitemIMUnit::readXML(
			xmlXPathContext* docctx
			, const string& basexpath
		) {
	if (checkXPath(docctx, basexpath, lineno)) {
		if (extractStringUclc(docctx, basexpath, "sref", "srf", sref)) ixWIelValid += ImeIMUnit::VecWIel::SREF;
		imeimcommand1.readXML(docctx, basexpath);
		imeimerror1.readXML(docctx, basexpath);
		imeimmodule.readXML(docctx, basexpath);
		imeimvector1.readXML(docctx, basexpath);
	};
};

void IexWdbeCsx::ImeitemIMUnit::writeTxt(
			fstream& outfile
		) {
	outfile << sref << endl;
	imeimcommand1.writeTxt(outfile);
	imeimerror1.writeTxt(outfile);
	imeimmodule.writeTxt(outfile);
	imeimvector1.writeTxt(outfile);
};

void IexWdbeCsx::ImeitemIMUnit::writeXML(
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
		imeimcommand1.writeXML(wr, shorttags);
		imeimerror1.writeXML(wr, shorttags);
		imeimmodule.writeXML(wr, shorttags);
		imeimvector1.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class IexWdbeCsx::ImeIMUnit::VecWIel
 ******************************************************************************/

uint IexWdbeCsx::ImeIMUnit::VecWIel::getIx(
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

void IexWdbeCsx::ImeIMUnit::VecWIel::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*SREF); i *= 2) if (ix & i) ics.insert(i);
};

string IexWdbeCsx::ImeIMUnit::VecWIel::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & SREF) ss.push_back("sref");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

/******************************************************************************
 class IexWdbeCsx::ImeIMUnit
 ******************************************************************************/

IexWdbeCsx::ImeIMUnit::ImeIMUnit() {
};

IexWdbeCsx::ImeIMUnit::~ImeIMUnit() {
	clear();
};

void IexWdbeCsx::ImeIMUnit::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) delete nodes[i];
	nodes.resize(0);
};

void IexWdbeCsx::ImeIMUnit::readTxt(
			Txtrd& txtrd
		) {
	IexWdbeCsx::ImeitemIMUnit* ii = NULL;

	clear();

	while (txtrd.readLine()) {
		switch (txtrd.ixVLinetype) {
			case Txtrd::VecVLinetype::DATA:
				if (txtrd.il == 0) {
					ii = new IexWdbeCsx::ImeitemIMUnit();
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

void IexWdbeCsx::ImeIMUnit::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	vector<unsigned int> nums;
	vector<bool> _shorttags;

	IexWdbeCsx::ImeitemIMUnit* ii = NULL;

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

			ii = new IexWdbeCsx::ImeitemIMUnit();
			ii->readXML(docctx, s);
			nodes.push_back(ii);
		};
	};
};

void IexWdbeCsx::ImeIMUnit::writeTxt(
			fstream& outfile
		) {
	if (nodes.size() > 0) {
		outfile << "ImeIMUnit." << StrMod::replaceChar(ImeIMUnit::VecWIel::getSrefs(1), ';', '\t') << endl;
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeTxt(outfile);
		outfile << "ImeIMUnit.end" << endl;
	};
};

void IexWdbeCsx::ImeIMUnit::writeXML(
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
 namespace IexWdbeCsx
 ******************************************************************************/

void IexWdbeCsx::parseFromFile(
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
			Txtrd rd(fullpath, rectpath, "IexWdbeCsx", Version("1.1.9"), VecVIme::getIx);
			readTxt(rd, imeimunit);
	};
};

void IexWdbeCsx::exportToFile(
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

void IexWdbeCsx::readTxt(
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

void IexWdbeCsx::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, ImeIMUnit& imeimunit
		) {
	string goodxpath;
	string version;

	if (checkUclcXPaths(docctx, basexpath, basexpath, "IexWdbeCsx")) {
		// validate version
		if (checkUclcXPaths(docctx, goodxpath, basexpath, "@Version")) {
			extractString(docctx, goodxpath, version);
			if (Version(version) < Version("1.1.9")) throw SbeException(SbeException::IEX_VERSION, {{"version",version},{"minversion","1.1.9"}});
		};

		// look for XML sub-blocks
		imeimunit.readXML(docctx, basexpath);

	} else {
		imeimunit = ImeIMUnit();

		throw SbeException(SbeException::IEX_FILETYPE, {{"iexsref","IexWdbeCsx"}});
	};
};

void IexWdbeCsx::writeTxt(
			fstream& outfile
			, ImeIMUnit& imeimunit
		) {
	outfile << "IexWdbeCsx v" WDBE_VERSION << endl;

	imeimunit.writeTxt(outfile);
};

void IexWdbeCsx::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
			, ImeIMUnit& imeimunit
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexWdbeCsx");
		xmlTextWriterWriteAttribute(wr, BAD_CAST "version", BAD_CAST WDBE_VERSION);

		imeimunit.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

map<uint,uint> IexWdbeCsx::icsWdbeVIopInsAll() {
	return {{(uint)VecVIme::IMEIAMCOMMANDINVPAR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOMMANDINVPAR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOMMANDRETPAR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMCOMMANDRETPAR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMERRORPAR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIAMERRORPAR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCOMMAND1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMCOMMAND2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMERROR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMERROR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTOR1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTOR2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTORITEM1,VecWdbeVIop::INS},{(uint)VecVIme::IMEIMVECTORITEM2,VecWdbeVIop::INS},{(uint)VecVIme::IMEIRMCOMMANDMCONTROLLER,VecWdbeVIop::INS}};
};

uint IexWdbeCsx::getIxWdbeVIop(
			const map<uint,uint>& icsWdbeVIop
			, const uint ixVIme
			, uint& ixWdbeVIop
		) {
	ixWdbeVIop = 0;

	auto it = icsWdbeVIop.find(ixVIme);
	if (it != icsWdbeVIop.end()) ixWdbeVIop = it->second;

	return ixWdbeVIop;
};
