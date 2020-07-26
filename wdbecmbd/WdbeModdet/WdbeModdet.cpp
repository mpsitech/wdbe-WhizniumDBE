/**
	* \file WdbeModdet.cpp
	* Wdbe operation pack global code (implementation)
	* \author Alexander Wirthmueller
	* \date created: 11 Jul 2020
	* \date modified: 11 Jul 2020
	*/

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeModdet.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WdbeModdet
 ******************************************************************************/

// IP cust --- IBEGIN
void WdbeModdet::addCtrVits(
			DbsWdbe* dbswdbe
			, WdbeMController* ctr
			, ListWdbeMCommand& cmds
			, uint& mdlNum
			, const string& Prjshort
			, const string& Untsref
		) {
	vector<ubigint> refs;

	ubigint refC;

	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	ListWdbeMVector vecs;
	WdbeMVector* vec = NULL;

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	string s;

	size_t ptr;

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMVector WHERE hkIxVTbl = " + to_string(VecWdbeVMVectorHkTbl::CTR) + " AND hkUref = " + to_string(ctr->ref) + " ORDER BY sref ASC", false, refs);

	for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
		cmd = cmds.nodes[i];

		dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);
		dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

		for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
			ipa = ipas.nodes[j];
			if (ipa->refWdbeMVector != 0) refs.push_back(ipa->refWdbeMVector);
		};

		for (unsigned int j = 0; j < rpas.nodes.size(); j++) {
			rpa = rpas.nodes[j];
			if (rpa->refWdbeMVector != 0) refs.push_back(rpa->refWdbeMVector);
		};
	};

	// eliminate duplicates
	for (unsigned int i = 0; i < refs.size(); i++) {
		if (refs[i] == 0) {
			refs.resize(i);
			break;
		} else {
			for (unsigned int j = i + 1; j < refs.size();) {
				if (refs[j] == 0) {
					break;
				} else if (refs[j] == refs[i]) {
					for (unsigned int k = j; (k+1) < refs.size(); k++) {
						refs[k] = refs[k+1];
						if (refs[k] == 0) break;
					};
					refs[refs.size()-1] = 0;
				} else {
					j++;
				};
			};
		};
	};

	dbswdbe->tblwdbemvector->loadRstByRefs(refs, false, vecs);

	for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
		vec = vecs.nodes[i];
		
		s = vec->sref.substr(3);

		if (vec->hkIxVTbl == VecWdbeVMVectorHkTbl::CTR) {
			if (vec->hkUref == ctr->ref) {
				// ex. VecVIdhwIcm2TempFanmode.on -> VFanmode / tixVFanmodeOn
				ptr = vec->sref.find(ctr->Fullsref.substr(3));
				if (ptr != string::npos) s = vec->sref.substr(3, 1) + vec->sref.substr(ptr + ctr->Fullsref.length()-3);

			} else {
				// ex. VecVIdhwIcm2RoicBias.decr32 -> VIcm2RoicBias / tixVIcm2RoicBiasDecr32
				ptr = vec->sref.find(Untsref);
				if (ptr != string::npos) s = vec->sref.substr(3, 1) + vec->sref.substr(ptr);
			};

		} else if (vec->hkIxVTbl == VecWdbeVMVectorHkTbl::UNT) {
			// ex. VecVIdhwIcm2State.nc -> VIcm2State / tixVIcm2StateNc
			// same for vectors of other units
			ptr = vec->sref.find(Prjshort);
			s = vec->sref.substr(3, 1) + vec->sref.substr(ptr + Prjshort.length());
		};

		if (s != "VCommand") {
			refC = dbswdbe->tblwdbecsignal->getNewRef();

			dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

			for (unsigned int j = 0; j < vits.nodes.size(); j++) {
				vit = vits.nodes[j];
				dbswdbe->tblwdbemsignal->insertNewRec(NULL, VecWdbeVMSignalBasetype::OTH, refC, ctr->refWdbeMModule, mdlNum++, VecWdbeVMSignalMgeTbl::VOID, 0, vec->ref, "tix" + s + StrMod::cap(vit->sref), true, "slvdn", 8, "", "", "", Wdbe::binToHex(vit->vecNum), false, 0, "");
			};
		};
	};
};

void WdbeModdet::getMaxlenRecvSend(
			DbsWdbe* dbswdbe
			, const uint refIxVTbl
			, const ubigint refUref
			, unsigned int& maxlenRecv
			, unsigned int& maxlenSend
		) {
	vector<ubigint> refs;
	ubigint ref;

	WdbeMUnit* unt = NULL;

	string s;
	unsigned int len;

	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref), false, refs);

	for (unsigned int i = 0; i < refs.size(); i++) {
		len = 10 + Wdbe::getLenInv(dbswdbe, refs[i]);
		if (len > maxlenRecv) maxlenRecv = len;

		len = 9 + Wdbe::getLenRet(dbswdbe, refs[i]);
		if (len > maxlenSend) maxlenSend = len;
	};

	// creferr, length 13
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " AND ixVRettype = " + to_string(VecWdbeVMCommandRettype::DFRSNG), false, refs);
	dbswdbe->loadRefsBySQL("SELECT ref FROM TblWdbeMCommand WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " AND ixVRettype = " + to_string(VecWdbeVMCommandRettype::MULT), true, refs);
	if (refs.size() > 0) if (maxlenSend < 13) maxlenSend = 13;

	// fwderr, length 10
	if (refIxVTbl == VecWdbeVMCommandRefTbl::CTR)
				if (dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeMModule WHERE refWdbeMController = " + to_string(refUref) + " AND ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::FWDCTR), ref))
							if (maxlenSend < 9) maxlenSend = 9;

	if (refIxVTbl == VecWdbeVMCommandRefTbl::CTR) {
		// invoked commands
		// TBD: potential errors

		dbswdbe->loadRefsBySQL("SELECT refWdbeMCommand FROM TblWdbeRMCommandMController WHERE refWdbeMController = " + to_string(refUref), false, refs);

		for (unsigned int i = 0; i < refs.size(); i++) {
			len = 10 + Wdbe::getLenInv(dbswdbe, refs[i]);
			if (len > maxlenSend) maxlenSend = len;

			len = 9 + Wdbe::getLenRet(dbswdbe, refs[i]);
			if (len > maxlenRecv) maxlenRecv = len;
		};
	};

	// forwarding controller: analyze unit forwarded to
	if (refIxVTbl == VecWdbeVMCommandRefTbl::CTR) {
		if (dbswdbe->tblwdbemunit->loadRecBySQL("SELECT TblWdbeMUnit.* FROM TblWdbeMController, TblWdbeMUnit WHERE TblWdbeMController.ref = " + to_string(refUref) + " AND TblWdbeMUnit.ref = TblWdbeMController.fwdRefWdbeMUnit", &unt)) {
			if (unt->ixVBasetype == VecWdbeVMUnitBasetype::FPGA) {
				if (dbswdbe->loadRefBySQL("SELECT TblWdbeMModule2.ref FROM TblWdbeMModule AS TblWdbeMModule1, TblWdbeMModule AS TblWdbeMModule2 WHERE TblWdbeMModule1.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
							+ " AND TblWdbeMModule1.hkUref = " + to_string(unt->ref) + " AND TblWdbeMModule2.supRefWdbeMModule = TblWdbeMModule1.ref AND TblWdbeMModule1.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDINV)
							+ " AND TblWdbeMModule2.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::IMBUF), ref)) {
					if (Wdbe::getMpa(dbswdbe, ref, "maxlen", s)) {
						len = atoi(s.c_str());
						if (len > maxlenRecv) maxlenRecv = len;
					};
				};

				if (dbswdbe->loadRefBySQL("SELECT TblWdbeMModule2.ref FROM TblWdbeMModule AS TblWdbeMModule1, TblWdbeMModule AS TblWdbeMModule2 WHERE TblWdbeMModule1.hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::UNT)
							+ " AND TblWdbeMModule1.hkUref = " + to_string(unt->ref) + " AND TblWdbeMModule2.supRefWdbeMModule = TblWdbeMModule1.ref AND TblWdbeMModule1.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::CMDRET)
							+ " AND TblWdbeMModule2.ixVBasetype = " + to_string(VecWdbeVMModuleBasetype::IMBUF), ref)) {
					if (Wdbe::getMpa(dbswdbe, ref, "maxlen", s)) {
						len = atoi(s.c_str());
						if (len > maxlenSend) maxlenSend = len;
					};
				};

			} else {
				getMaxlenRecvSend(dbswdbe, VecWdbeVMCommandRefTbl::UNT, unt->ref, maxlenRecv, maxlenSend);
			};

			delete unt;
		};
	};
};
// IP cust --- IEND


