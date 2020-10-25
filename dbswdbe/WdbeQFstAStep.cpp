/**
	* \file WdbeQFstAStep.cpp
	* Dbs and XML wrapper for table TblWdbeQFstAStep (implementation)
	* \author Alexander Wirthmueller
	* \date created: 23 Aug 2020
	* \date modified: 23 Aug 2020
	*/

#include "WdbeQFstAStep.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WdbeQFstAStep
 ******************************************************************************/

WdbeQFstAStep::WdbeQFstAStep(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint fstNum
			, const ubigint fnxRefWdbeMFsmstate
			, const string stubFnxRefWdbeMFsmstate
			, const string Cond1
			, const string Ip1
			, const string Cond2
			, const string Ip2
			, const string Cond3
			, const string Ip3
			, const string Cond4
			, const string Ip4
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->fstNum = fstNum;
	this->fnxRefWdbeMFsmstate = fnxRefWdbeMFsmstate;
	this->stubFnxRefWdbeMFsmstate = stubFnxRefWdbeMFsmstate;
	this->Cond1 = Cond1;
	this->Ip1 = Ip1;
	this->Cond2 = Cond2;
	this->Ip2 = Ip2;
	this->Cond3 = Cond3;
	this->Ip3 = Ip3;
	this->Cond4 = Cond4;
	this->Ip4 = Ip4;
};

void WdbeQFstAStep::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "WdbeQFstAStep";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "fnx", stubFnxRefWdbeMFsmstate);
		writeString(wr, "cn1", Cond1);
		writeString(wr, "ip1", Ip1);
		writeString(wr, "cn2", Cond2);
		writeString(wr, "ip2", Ip2);
		writeString(wr, "cn3", Cond3);
		writeString(wr, "ip3", Ip3);
		writeString(wr, "cn4", Cond4);
		writeString(wr, "ip4", Ip4);
	} else {
		writeString(wr, "stubFnxRefWdbeMFsmstate", stubFnxRefWdbeMFsmstate);
		writeString(wr, "Cond1", Cond1);
		writeString(wr, "Ip1", Ip1);
		writeString(wr, "Cond2", Cond2);
		writeString(wr, "Ip2", Ip2);
		writeString(wr, "Cond3", Cond3);
		writeString(wr, "Ip3", Ip3);
		writeString(wr, "Cond4", Cond4);
		writeString(wr, "Ip4", Ip4);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListWdbeQFstAStep
 ******************************************************************************/

ListWdbeQFstAStep::ListWdbeQFstAStep() {
};

ListWdbeQFstAStep::ListWdbeQFstAStep(
			const ListWdbeQFstAStep& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeQFstAStep(*(src.nodes[i]));
};

ListWdbeQFstAStep::~ListWdbeQFstAStep() {
	clear();
};

void ListWdbeQFstAStep::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeQFstAStep::size() const {
	return(nodes.size());
};

void ListWdbeQFstAStep::append(
			WdbeQFstAStep* rec
		) {
	nodes.push_back(rec);
};

ListWdbeQFstAStep& ListWdbeQFstAStep::operator=(
			const ListWdbeQFstAStep& src
		) {
	WdbeQFstAStep* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeQFstAStep(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

void ListWdbeQFstAStep::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListWdbeQFstAStep";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i = 0; i < nodes.size(); i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class TblWdbeQFstAStep
 ******************************************************************************/

TblWdbeQFstAStep::TblWdbeQFstAStep() {
};

TblWdbeQFstAStep::~TblWdbeQFstAStep() {
};

bool TblWdbeQFstAStep::loadRecBySQL(
			const string& sqlstr
			, WdbeQFstAStep** rec
		) {
	return false;
};

ubigint TblWdbeQFstAStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQFstAStep& rst
		) {
	return 0;
};

ubigint TblWdbeQFstAStep::insertRec(
			WdbeQFstAStep* rec
		) {
	return 0;
};

ubigint TblWdbeQFstAStep::insertNewRec(
			WdbeQFstAStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint fstNum
			, const ubigint fnxRefWdbeMFsmstate
			, const string stubFnxRefWdbeMFsmstate
			, const string Cond1
			, const string Ip1
			, const string Cond2
			, const string Ip2
			, const string Cond3
			, const string Ip3
			, const string Cond4
			, const string Ip4
		) {
	ubigint retval = 0;
	WdbeQFstAStep* _rec = NULL;

	_rec = new WdbeQFstAStep(0, jref, jnum, ref, fstNum, fnxRefWdbeMFsmstate, stubFnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeQFstAStep::appendNewRecToRst(
			ListWdbeQFstAStep& rst
			, WdbeQFstAStep** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const uint fstNum
			, const ubigint fnxRefWdbeMFsmstate
			, const string stubFnxRefWdbeMFsmstate
			, const string Cond1
			, const string Ip1
			, const string Cond2
			, const string Ip2
			, const string Cond3
			, const string Ip3
			, const string Cond4
			, const string Ip4
		) {
	ubigint retval = 0;
	WdbeQFstAStep* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, fstNum, fnxRefWdbeMFsmstate, stubFnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeQFstAStep::insertRst(
			ListWdbeQFstAStep& rst
		) {
};

void TblWdbeQFstAStep::updateRec(
			WdbeQFstAStep* rec
		) {
};

void TblWdbeQFstAStep::updateRst(
			ListWdbeQFstAStep& rst
		) {
};

void TblWdbeQFstAStep::removeRecByQref(
			ubigint qref
		) {
};

void TblWdbeQFstAStep::removeRstByJref(
			ubigint jref
		) {
};

bool TblWdbeQFstAStep::loadRecByQref(
			ubigint qref
			, WdbeQFstAStep** rec
		) {
	return false;
};

ubigint TblWdbeQFstAStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQFstAStep& rst
		) {
	return 0;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeQFstAStep
 ******************************************************************************/

MyTblWdbeQFstAStep::MyTblWdbeQFstAStep() :
			TblWdbeQFstAStep()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblWdbeQFstAStep::~MyTblWdbeQFstAStep() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblWdbeQFstAStep::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeQFstAStep (jref, jnum, ref, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeQFstAStep SET jref = ?, jnum = ?, ref = ?, fstNum = ?, fnxRefWdbeMFsmstate = ?, Cond1 = ?, Ip1 = ?, Cond2 = ?, Ip2 = ?, Cond3 = ?, Ip3 = ?, Cond4 = ?, Ip4 = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblWdbeQFstAStep WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblWdbeQFstAStep WHERE jref = ?", false);
};

bool MyTblWdbeQFstAStep::loadRecBySQL(
			const string& sqlstr
			, WdbeQFstAStep** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeQFstAStep* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQFstAStep::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQFstAStep::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeQFstAStep();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->fstNum = atol((char*) dbrow[4]); else _rec->fstNum = 0;
		if (dbrow[5]) _rec->fnxRefWdbeMFsmstate = atoll((char*) dbrow[5]); else _rec->fnxRefWdbeMFsmstate = 0;
		if (dbrow[6]) _rec->Cond1.assign(dbrow[6], dblengths[6]); else _rec->Cond1 = "";
		if (dbrow[7]) _rec->Ip1.assign(dbrow[7], dblengths[7]); else _rec->Ip1 = "";
		if (dbrow[8]) _rec->Cond2.assign(dbrow[8], dblengths[8]); else _rec->Cond2 = "";
		if (dbrow[9]) _rec->Ip2.assign(dbrow[9], dblengths[9]); else _rec->Ip2 = "";
		if (dbrow[10]) _rec->Cond3.assign(dbrow[10], dblengths[10]); else _rec->Cond3 = "";
		if (dbrow[11]) _rec->Ip3.assign(dbrow[11], dblengths[11]); else _rec->Ip3 = "";
		if (dbrow[12]) _rec->Cond4.assign(dbrow[12], dblengths[12]); else _rec->Cond4 = "";
		if (dbrow[13]) _rec->Ip4.assign(dbrow[13], dblengths[13]); else _rec->Ip4 = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeQFstAStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQFstAStep& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeQFstAStep* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeQFstAStep::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeQFstAStep::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeQFstAStep();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->fstNum = atol((char*) dbrow[4]); else rec->fstNum = 0;
			if (dbrow[5]) rec->fnxRefWdbeMFsmstate = atoll((char*) dbrow[5]); else rec->fnxRefWdbeMFsmstate = 0;
			if (dbrow[6]) rec->Cond1.assign(dbrow[6], dblengths[6]); else rec->Cond1 = "";
			if (dbrow[7]) rec->Ip1.assign(dbrow[7], dblengths[7]); else rec->Ip1 = "";
			if (dbrow[8]) rec->Cond2.assign(dbrow[8], dblengths[8]); else rec->Cond2 = "";
			if (dbrow[9]) rec->Ip2.assign(dbrow[9], dblengths[9]); else rec->Ip2 = "";
			if (dbrow[10]) rec->Cond3.assign(dbrow[10], dblengths[10]); else rec->Cond3 = "";
			if (dbrow[11]) rec->Ip3.assign(dbrow[11], dblengths[11]); else rec->Ip3 = "";
			if (dbrow[12]) rec->Cond4.assign(dbrow[12], dblengths[12]); else rec->Cond4 = "";
			if (dbrow[13]) rec->Ip4.assign(dbrow[13], dblengths[13]); else rec->Ip4 = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeQFstAStep::insertRec(
			WdbeQFstAStep* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->Cond1.length();
	l[6] = rec->Ip1.length();
	l[7] = rec->Cond2.length();
	l[8] = rec->Ip2.length();
	l[9] = rec->Cond3.length();
	l[10] = rec->Ip3.length();
	l[11] = rec->Cond4.length();
	l[12] = rec->Ip4.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->fstNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->fnxRefWdbeMFsmstate,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Cond1.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Ip1.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Cond2.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Ip2.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Cond3.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Ip3.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Cond4.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Ip4.c_str()),&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeQFstAStep::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeQFstAStep::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->qref;
};

void MyTblWdbeQFstAStep::insertRst(
			ListWdbeQFstAStep& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeQFstAStep::updateRec(
			WdbeQFstAStep* rec
		) {
	unsigned long l[14]; my_bool n[14]; my_bool e[14];

	l[5] = rec->Cond1.length();
	l[6] = rec->Ip1.length();
	l[7] = rec->Cond2.length();
	l[8] = rec->Ip2.length();
	l[9] = rec->Cond3.length();
	l[10] = rec->Ip3.length();
	l[11] = rec->Cond4.length();
	l[12] = rec->Ip4.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->fstNum,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->fnxRefWdbeMFsmstate,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Cond1.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Ip1.c_str()),&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Cond2.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Ip2.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->Cond3.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindCstring((char*) (rec->Ip3.c_str()),&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Cond4.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindCstring((char*) (rec->Ip4.c_str()),&(l[12]),&(n[12]),&(e[12])),
		bindUbigint(&rec->qref,&(l[13]),&(n[13]),&(e[13]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeQFstAStep::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeQFstAStep::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQFstAStep::updateRst(
			ListWdbeQFstAStep& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeQFstAStep::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) {
		string dbms = "MyTblWdbeQFstAStep::removeRecByQref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByQref)) {
		string dbms = "MyTblWdbeQFstAStep::removeRecByQref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeQFstAStep::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) {
		string dbms = "MyTblWdbeQFstAStep::removeRstByJref() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRstByJref)) {
		string dbms = "MyTblWdbeQFstAStep::removeRstByJref() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeQFstAStep::loadRecByQref(
			ubigint qref
			, WdbeQFstAStep** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeQFstAStep WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblWdbeQFstAStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQFstAStep& rst
		) {
	return loadRstBySQL("SELECT * FROM TblWdbeQFstAStep WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeQFstAStep
 ******************************************************************************/

PgTblWdbeQFstAStep::PgTblWdbeQFstAStep() :
			TblWdbeQFstAStep()
			, PgTable()
		{
};

PgTblWdbeQFstAStep::~PgTblWdbeQFstAStep() {
};

void PgTblWdbeQFstAStep::initStatements() {
	createStatement("TblWdbeQFstAStep_insertRec", "INSERT INTO TblWdbeQFstAStep (jref, jnum, ref, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13) RETURNING qref", 13);
	createStatement("TblWdbeQFstAStep_updateRec", "UPDATE TblWdbeQFstAStep SET jref = $1, jnum = $2, ref = $3, fstNum = $4, fnxRefWdbeMFsmstate = $5, Cond1 = $6, Ip1 = $7, Cond2 = $8, Ip2 = $9, Cond3 = $10, Ip3 = $11, Cond4 = $12, Ip4 = $13 WHERE qref = $14", 14);
	createStatement("TblWdbeQFstAStep_removeRecByQref", "DELETE FROM TblWdbeQFstAStep WHERE qref = $1", 1);
	createStatement("TblWdbeQFstAStep_removeRstByJref", "DELETE FROM TblWdbeQFstAStep WHERE jref = $1", 1);

	createStatement("TblWdbeQFstAStep_loadRecByQref", "SELECT qref, jref, jnum, ref, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4 FROM TblWdbeQFstAStep WHERE qref = $1", 1);
	createStatement("TblWdbeQFstAStep_loadRstByJref", "SELECT qref, jref, jnum, ref, fstNum, fnxRefWdbeMFsmstate, Cond1, Ip1, Cond2, Ip2, Cond3, Ip3, Cond4, Ip4 FROM TblWdbeQFstAStep WHERE jref = $1 ORDER BY jnum ASC", 1);
};

bool PgTblWdbeQFstAStep::loadRec(
			PGresult* res
			, WdbeQFstAStep** rec
		) {
	char* ptr;

	WdbeQFstAStep* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeQFstAStep();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "fstnum"),
			PQfnumber(res, "fnxrefwdbemfsmstate"),
			PQfnumber(res, "cond1"),
			PQfnumber(res, "ip1"),
			PQfnumber(res, "cond2"),
			PQfnumber(res, "ip2"),
			PQfnumber(res, "cond3"),
			PQfnumber(res, "ip3"),
			PQfnumber(res, "cond4"),
			PQfnumber(res, "ip4")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->fstNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->fnxRefWdbeMFsmstate = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Cond1.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Ip1.assign(ptr, PQgetlength(res, 0, fnum[7]));
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Cond2.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Ip2.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->Cond3.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Ip3.assign(ptr, PQgetlength(res, 0, fnum[11]));
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Cond4.assign(ptr, PQgetlength(res, 0, fnum[12]));
		ptr = PQgetvalue(res, 0, fnum[13]); _rec->Ip4.assign(ptr, PQgetlength(res, 0, fnum[13]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeQFstAStep::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeQFstAStep& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeQFstAStep* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "fstnum"),
			PQfnumber(res, "fnxrefwdbemfsmstate"),
			PQfnumber(res, "cond1"),
			PQfnumber(res, "ip1"),
			PQfnumber(res, "cond2"),
			PQfnumber(res, "ip2"),
			PQfnumber(res, "cond3"),
			PQfnumber(res, "ip3"),
			PQfnumber(res, "cond4"),
			PQfnumber(res, "ip4")
		};

		while (numread < numrow) {
			rec = new WdbeQFstAStep();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->fstNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->fnxRefWdbeMFsmstate = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Cond1.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Ip1.assign(ptr, PQgetlength(res, numread, fnum[7]));
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Cond2.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Ip2.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->Cond3.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Ip3.assign(ptr, PQgetlength(res, numread, fnum[11]));
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Cond4.assign(ptr, PQgetlength(res, numread, fnum[12]));
			ptr = PQgetvalue(res, numread, fnum[13]); rec->Ip4.assign(ptr, PQgetlength(res, numread, fnum[13]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeQFstAStep::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeQFstAStep** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQFstAStep::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQFstAStep::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeQFstAStep& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQFstAStep::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeQFstAStep::loadRecBySQL(
			const string& sqlstr
			, WdbeQFstAStep** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQFstAStep::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeQFstAStep::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeQFstAStep& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeQFstAStep::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeQFstAStep::insertRec(
			WdbeQFstAStep* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _fstNum = htonl(rec->fstNum);
	ubigint _fnxRefWdbeMFsmstate = htonl64(rec->fnxRefWdbeMFsmstate);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_fstNum,
		(char*) &_fnxRefWdbeMFsmstate,
		rec->Cond1.c_str(),
		rec->Ip1.c_str(),
		rec->Cond2.c_str(),
		rec->Ip2.c_str(),
		rec->Cond3.c_str(),
		rec->Ip3.c_str(),
		rec->Cond4.c_str(),
		rec->Ip4.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblWdbeQFstAStep_insertRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK)	{
		string dbms = "PgTblWdbeQFstAStep::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
	
	return rec->qref;
};

void PgTblWdbeQFstAStep::insertRst(
			ListWdbeQFstAStep& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeQFstAStep::updateRec(
			WdbeQFstAStep* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _fstNum = htonl(rec->fstNum);
	ubigint _fnxRefWdbeMFsmstate = htonl64(rec->fnxRefWdbeMFsmstate);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_fstNum,
		(char*) &_fnxRefWdbeMFsmstate,
		rec->Cond1.c_str(),
		rec->Ip1.c_str(),
		rec->Cond2.c_str(),
		rec->Ip2.c_str(),
		rec->Cond3.c_str(),
		rec->Ip3.c_str(),
		rec->Cond4.c_str(),
		rec->Ip4.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeQFstAStep_updateRec", 14, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQFstAStep::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQFstAStep::updateRst(
			ListWdbeQFstAStep& rst
		) {
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeQFstAStep::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeQFstAStep_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQFstAStep::removeRecByQref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeQFstAStep::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeQFstAStep_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeQFstAStep::removeRstByJref() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeQFstAStep::loadRecByQref(
			ubigint qref
			, WdbeQFstAStep** rec
		) {
	if (qref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeQFstAStep_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblWdbeQFstAStep::loadRstByJref(
			ubigint jref
			, const bool append
			, ListWdbeQFstAStep& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeQFstAStep_loadRstByJref", 1, vals, l, f, append, rst);
};
#endif

