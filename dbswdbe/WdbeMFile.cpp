/**
	* \file WdbeMFile.cpp
	* database access for table TblWdbeMFile (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WdbeMFile.h"

#include "WdbeMFile_vecs.cpp"

using namespace std;
using namespace Sbecore;

/******************************************************************************
 class WdbeMFile
 ******************************************************************************/

WdbeMFile::WdbeMFile(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refWdbeCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const usmallint Size
			, const string Comment
		) :
			ref(ref)
			, grp(grp)
			, own(own)
			, refWdbeCFile(refWdbeCFile)
			, refIxVTbl(refIxVTbl)
			, refUref(refUref)
			, osrefKContent(osrefKContent)
			, Archived(Archived)
			, Filename(Filename)
			, Archivename(Archivename)
			, srefKMimetype(srefKMimetype)
			, Size(Size)
			, Comment(Comment)
		{
};

bool WdbeMFile::operator==(
			const WdbeMFile& comp
		) {
	return false;
};

bool WdbeMFile::operator!=(
			const WdbeMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListWdbeMFile
 ******************************************************************************/

ListWdbeMFile::ListWdbeMFile() {
};

ListWdbeMFile::ListWdbeMFile(
			const ListWdbeMFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WdbeMFile(*(src.nodes[i]));
};

ListWdbeMFile::~ListWdbeMFile() {
	clear();
};

void ListWdbeMFile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListWdbeMFile::size() const {
	return(nodes.size());
};

void ListWdbeMFile::append(
			WdbeMFile* rec
		) {
	nodes.push_back(rec);
};

WdbeMFile* ListWdbeMFile::operator[](
			const uint ix
		) {
	WdbeMFile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListWdbeMFile& ListWdbeMFile::operator=(
			const ListWdbeMFile& src
		) {
	WdbeMFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i = 0; i < src.size(); i++) {
			rec = new WdbeMFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListWdbeMFile::operator==(
			const ListWdbeMFile& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i = 0; i < size(); i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListWdbeMFile::operator!=(
			const ListWdbeMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblWdbeMFile
 ******************************************************************************/

TblWdbeMFile::TblWdbeMFile() {
};

TblWdbeMFile::~TblWdbeMFile() {
};

bool TblWdbeMFile::loadRecBySQL(
			const string& sqlstr
			, WdbeMFile** rec
		) {
	return false;
};

ubigint TblWdbeMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFile& rst
		) {
	return 0;
};

ubigint TblWdbeMFile::insertRec(
			WdbeMFile* rec
		) {
	return 0;
};

ubigint TblWdbeMFile::insertNewRec(
			WdbeMFile** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWdbeCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const usmallint Size
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMFile* _rec = NULL;

	_rec = new WdbeMFile(0, grp, own, refWdbeCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblWdbeMFile::appendNewRecToRst(
			ListWdbeMFile& rst
			, WdbeMFile** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refWdbeCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const usmallint Size
			, const string Comment
		) {
	ubigint retval = 0;
	WdbeMFile* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refWdbeCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblWdbeMFile::insertRst(
			ListWdbeMFile& rst
			, bool transact
		) {
};

void TblWdbeMFile::updateRec(
			WdbeMFile* rec
		) {
};

void TblWdbeMFile::updateRst(
			ListWdbeMFile& rst
			, bool transact
		) {
};

void TblWdbeMFile::removeRecByRef(
			ubigint ref
		) {
};

bool TblWdbeMFile::loadRecByRef(
			ubigint ref
			, WdbeMFile** rec
		) {
	return false;
};

bool TblWdbeMFile::loadFnmByRef(
			ubigint ref
			, string& Filename
		) {
	return false;
};

ubigint TblWdbeMFile::loadRefsByClu(
			ubigint refWdbeCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMFile::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblWdbeMFile::loadRstByClu(
			ubigint refWdbeCFile
			, const bool append
			, ListWdbeMFile& rst
		) {
	return 0;
};

ubigint TblWdbeMFile::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMFile& rst
		) {
	return 0;
};

ubigint TblWdbeMFile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListWdbeMFile& rst
		) {
	ubigint numload = 0;
	WdbeMFile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i = 0; i < refs.size(); i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
/******************************************************************************
 class MyTblWdbeMFile
 ******************************************************************************/

MyTblWdbeMFile::MyTblWdbeMFile() :
			TblWdbeMFile()
			, MyTable()
		{
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblWdbeMFile::~MyTblWdbeMFile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblWdbeMFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblWdbeMFile (grp, own, refWdbeCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblWdbeMFile SET grp = ?, own = ?, refWdbeCFile = ?, refIxVTbl = ?, refUref = ?, osrefKContent = ?, Archived = ?, Filename = ?, Archivename = ?, srefKMimetype = ?, Size = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblWdbeMFile WHERE ref = ?", false);
};

bool MyTblWdbeMFile::loadRecBySQL(
			const string& sqlstr
			, WdbeMFile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;
	WdbeMFile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMFile::loadRecBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMFile::loadRecBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		unsigned long* dblengths = mysql_fetch_lengths(dbresult);

		_rec = new WdbeMFile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refWdbeCFile = atoll((char*) dbrow[3]); else _rec->refWdbeCFile = 0;
		if (dbrow[4]) _rec->refIxVTbl = atol((char*) dbrow[4]); else _rec->refIxVTbl = 0;
		if (dbrow[5]) _rec->refUref = atoll((char*) dbrow[5]); else _rec->refUref = 0;
		if (dbrow[6]) _rec->osrefKContent.assign(dbrow[6], dblengths[6]); else _rec->osrefKContent = "";
		if (dbrow[7]) _rec->Archived = atol((char*) dbrow[7]); else _rec->Archived = 0;
		if (dbrow[8]) _rec->Filename.assign(dbrow[8], dblengths[8]); else _rec->Filename = "";
		if (dbrow[9]) _rec->Archivename.assign(dbrow[9], dblengths[9]); else _rec->Archivename = "";
		if (dbrow[10]) _rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else _rec->srefKMimetype = "";
		if (dbrow[11]) _rec->Size = atoi((char*) dbrow[11]); else _rec->Size = 0;
		if (dbrow[12]) _rec->Comment.assign(dbrow[12], dblengths[12]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblWdbeMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;
	WdbeMFile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) {
		string dbms = "MyTblWdbeMFile::loadRstBySQL() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	dbresult = mysql_store_result(dbs);
	if (!dbresult) {
		string dbms = "MyTblWdbeMFile::loadRstBySQL() / store result / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			unsigned long* dblengths = mysql_fetch_lengths(dbresult);

			rec = new WdbeMFile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refWdbeCFile = atoll((char*) dbrow[3]); else rec->refWdbeCFile = 0;
			if (dbrow[4]) rec->refIxVTbl = atol((char*) dbrow[4]); else rec->refIxVTbl = 0;
			if (dbrow[5]) rec->refUref = atoll((char*) dbrow[5]); else rec->refUref = 0;
			if (dbrow[6]) rec->osrefKContent.assign(dbrow[6], dblengths[6]); else rec->osrefKContent = "";
			if (dbrow[7]) rec->Archived = atol((char*) dbrow[7]); else rec->Archived = 0;
			if (dbrow[8]) rec->Filename.assign(dbrow[8], dblengths[8]); else rec->Filename = "";
			if (dbrow[9]) rec->Archivename.assign(dbrow[9], dblengths[9]); else rec->Archivename = "";
			if (dbrow[10]) rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else rec->srefKMimetype = "";
			if (dbrow[11]) rec->Size = atoi((char*) dbrow[11]); else rec->Size = 0;
			if (dbrow[12]) rec->Comment.assign(dbrow[12], dblengths[12]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

ubigint MyTblWdbeMFile::insertRec(
			WdbeMFile* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->osrefKContent.length();
	l[7] = rec->Filename.length();
	l[8] = rec->Archivename.length();
	l[9] = rec->srefKMimetype.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeCFile,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Archived,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Archivename.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUsmallint(&rec->Size,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) {
		string dbms = "MyTblWdbeMFile::insertRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtInsertRec)) {
		string dbms = "MyTblWdbeMFile::insertRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
	
	return rec->ref;
};

void MyTblWdbeMFile::insertRst(
			ListWdbeMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblWdbeMFile::updateRec(
			WdbeMFile* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->osrefKContent.length();
	l[7] = rec->Filename.length();
	l[8] = rec->Archivename.length();
	l[9] = rec->srefKMimetype.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refWdbeCFile,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Archived,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Archivename.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUsmallint(&rec->Size,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11])),
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) {
		string dbms = "MyTblWdbeMFile::updateRec() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtUpdateRec)) {
		string dbms = "MyTblWdbeMFile::updateRec() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

void MyTblWdbeMFile::updateRst(
			ListWdbeMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void MyTblWdbeMFile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) {
		string dbms = "MyTblWdbeMFile::removeRecByRef() / bind / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
	if (mysql_stmt_execute(stmtRemoveRecByRef)) {
		string dbms = "MyTblWdbeMFile::removeRecByRef() / " + string(mysql_error(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};
};

bool MyTblWdbeMFile::loadRecByRef(
			ubigint ref
			, WdbeMFile** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	return loadRecBySQL("SELECT * FROM TblWdbeMFile WHERE ref = " + to_string(ref), rec);
};

bool MyTblWdbeMFile::loadFnmByRef(
			ubigint ref
			, string& Filename
		) {
	return loadStringBySQL("SELECT Filename FROM TblWdbeMFile WHERE ref = " + to_string(ref) + "", Filename);
};

ubigint MyTblWdbeMFile::loadRefsByClu(
			ubigint refWdbeCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMFile WHERE refWdbeCFile = " + to_string(refWdbeCFile) + "", append, refs);
};

ubigint MyTblWdbeMFile::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblWdbeMFile WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + "", append, refs);
};

ubigint MyTblWdbeMFile::loadRstByClu(
			ubigint refWdbeCFile
			, const bool append
			, ListWdbeMFile& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, refWdbeCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblWdbeMFile WHERE refWdbeCFile = " + to_string(refWdbeCFile) + "", append, rst);
};

ubigint MyTblWdbeMFile::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMFile& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, refWdbeCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblWdbeMFile WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " ORDER BY Filename ASC", append, rst);
};

#endif

#if defined(SBECORE_PG)
/******************************************************************************
 class PgTblWdbeMFile
 ******************************************************************************/

PgTblWdbeMFile::PgTblWdbeMFile() :
			TblWdbeMFile()
			, PgTable()
		{
};

PgTblWdbeMFile::~PgTblWdbeMFile() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblWdbeMFile::initStatements() {
	createStatement("TblWdbeMFile_insertRec", "INSERT INTO TblWdbeMFile (grp, own, refWdbeCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12);
	createStatement("TblWdbeMFile_updateRec", "UPDATE TblWdbeMFile SET grp = $1, own = $2, refWdbeCFile = $3, refIxVTbl = $4, refUref = $5, osrefKContent = $6, Archived = $7, Filename = $8, Archivename = $9, srefKMimetype = $10, Size = $11, Comment = $12 WHERE ref = $13", 13);
	createStatement("TblWdbeMFile_removeRecByRef", "DELETE FROM TblWdbeMFile WHERE ref = $1", 1);

	createStatement("TblWdbeMFile_loadRecByRef", "SELECT ref, grp, own, refWdbeCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblWdbeMFile WHERE ref = $1", 1);
	createStatement("TblWdbeMFile_loadFnmByRef", "SELECT Filename FROM TblWdbeMFile WHERE ref = $1", 1);
	createStatement("TblWdbeMFile_loadRefsByClu", "SELECT ref FROM TblWdbeMFile WHERE refWdbeCFile = $1", 1);
	createStatement("TblWdbeMFile_loadRefsByRetReu", "SELECT ref FROM TblWdbeMFile WHERE refIxVTbl = $1 AND refUref = $2", 2);
	createStatement("TblWdbeMFile_loadRstByClu", "SELECT ref, grp, own, refWdbeCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblWdbeMFile WHERE refWdbeCFile = $1", 1);
	createStatement("TblWdbeMFile_loadRstByRetReu", "SELECT ref, grp, own, refWdbeCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblWdbeMFile WHERE refIxVTbl = $1 AND refUref = $2 ORDER BY Filename ASC", 2);
};

bool PgTblWdbeMFile::loadRec(
			PGresult* res
			, WdbeMFile** rec
		) {
	char* ptr;

	WdbeMFile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new WdbeMFile();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwdbecfile"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "archived"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "archivename"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refWdbeCFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->osrefKContent.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Archived = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Filename.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Archivename.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefKMimetype.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Size = atoi(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblWdbeMFile::loadRst(
			PGresult* res
			, const bool append
			, ListWdbeMFile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	WdbeMFile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refwdbecfile"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "archived"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "archivename"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new WdbeMFile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refWdbeCFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->osrefKContent.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Archived = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Filename.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Archivename.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefKMimetype.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Size = atoi(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblWdbeMFile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, WdbeMFile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFile::loadRecByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMFile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListWdbeMFile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFile::loadRstByStmt(" + srefStmt + ") / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	return loadRst(res, append, rst);
};

bool PgTblWdbeMFile::loadRecBySQL(
			const string& sqlstr
			, WdbeMFile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFile::loadRecBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRec(res, rec);
};

ubigint PgTblWdbeMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListWdbeMFile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFile::loadRstBySQL() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_QUERY, {{"dbms",dbms}, {"sql",sqlstr}});
	};

	return loadRst(res, append, rst);
};

ubigint PgTblWdbeMFile::insertRec(
			WdbeMFile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeCFile = htonl64(rec->refWdbeCFile);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _Archived = htonl(rec->Archived);
	usmallint _Size = htons(rec->Size);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeCFile,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		(char*) &_Archived,
		rec->Filename.c_str(),
		rec->Archivename.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		0,
		0,
		sizeof(usmallint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblWdbeMFile_insertRec", 12, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) {
		string dbms = "PgTblWdbeMFile::insertRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);

	PQclear(res);
	
	return rec->ref;
};

void PgTblWdbeMFile::insertRst(
			ListWdbeMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) insertRec(rst.nodes[i]);
};

void PgTblWdbeMFile::updateRec(
			WdbeMFile* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refWdbeCFile = htonl64(rec->refWdbeCFile);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _Archived = htonl(rec->Archived);
	usmallint _Size = htons(rec->Size);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refWdbeCFile,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		(char*) &_Archived,
		rec->Filename.c_str(),
		rec->Archivename.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		0,
		0,
		sizeof(usmallint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblWdbeMFile_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMFile::updateRec() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

void PgTblWdbeMFile::updateRst(
			ListWdbeMFile& rst
			, bool transact
		) {
	if (transact) begin();
	for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i = 0; i < rst.nodes.size(); i++) updateRec(rst.nodes[i]);
};

void PgTblWdbeMFile::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblWdbeMFile_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		string dbms = "PgTblWdbeMFile::removeRecByRef() / " + string(PQerrorMessage(dbs));
		throw SbeException(SbeException::DBS_STMTEXEC, {{"dbms",dbms}});
	};

	PQclear(res);
};

bool PgTblWdbeMFile::loadRecByRef(
			ubigint ref
			, WdbeMFile** rec
		) {
	if (ref == 0) {
		*rec = NULL;
		return false;
	};

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblWdbeMFile_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblWdbeMFile::loadFnmByRef(
			ubigint ref
			, string& Filename
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblWdbeMFile_loadFnmByRef", 1, vals, l, f, Filename);
};

ubigint PgTblWdbeMFile::loadRefsByClu(
			ubigint refWdbeCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refWdbeCFile = htonl64(refWdbeCFile);

	const char* vals[] = {
		(char*) &_refWdbeCFile
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblWdbeMFile_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblWdbeMFile::loadRefsByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, vector<ubigint>& refs
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRefsByStmt("TblWdbeMFile_loadRefsByRetReu", 2, vals, l, f, append, refs);
};

ubigint PgTblWdbeMFile::loadRstByClu(
			ubigint refWdbeCFile
			, const bool append
			, ListWdbeMFile& rst
		) {
	ubigint _refWdbeCFile = htonl64(refWdbeCFile);

	const char* vals[] = {
		(char*) &_refWdbeCFile
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblWdbeMFile_loadRstByClu", 1, vals, l, f, append, rst);
};

ubigint PgTblWdbeMFile::loadRstByRetReu(
			uint refIxVTbl
			, ubigint refUref
			, const bool append
			, ListWdbeMFile& rst
		) {
	uint _refIxVTbl = htonl(refIxVTbl);
	ubigint _refUref = htonl64(refUref);

	const char* vals[] = {
		(char*) &_refIxVTbl,
		(char*) &_refUref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblWdbeMFile_loadRstByRetReu", 2, vals, l, f, append, rst);
};

#endif
