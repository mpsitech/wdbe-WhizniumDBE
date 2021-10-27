/**
	* \file WdbeCplmstTplcpy.cpp
	* Wdbe operation processor - copy parameters, subs, generics and ports from template (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 26 Aug 2021
  */
// IP header --- ABOVE

#ifdef WDBECMBD
	#include <Wdbecmbd.h>
#else
	#include <Wdbeopd.h>
#endif

#include "WdbeCplmstTplcpy.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;
using namespace WdbeCplmst;

// IP ns.cust --- INSERT

/******************************************************************************
 namespace WdbeCplmstTplcpy
 ******************************************************************************/

DpchRetWdbeCplmstTplcpy* WdbeCplmstTplcpy::run(
			XchgWdbe* xchg
			, DbsWdbe* dbswdbe
			, DpchInvWdbeCplmstTplcpy* dpchinv
		) {
	ubigint refWdbeMModule = dpchinv->refWdbeMModule;

	utinyint ixOpVOpres = VecOpVOpres::SUCCESS;

	std::string logfile;

	// IP run --- IBEGIN
	fstream logfi;

	ubigint ref;

	WdbeMModule* mdl = NULL;
	WdbeMModule* mtp = NULL;

	ListWdbeRMModuleMModule mdlRmdls;
	WdbeRMModuleMModule* mdlRmdl = NULL;

	WdbeMUnit* unt = NULL;

	ListWdbeMVector vecs;
	WdbeMVector* vec = NULL;
	map<ubigint,ubigint> refsVecs; // mdl ref by mtp ref

	ListWdbeMVectoritem vits;
	WdbeMVectoritem* vit = NULL;

	ListWdbeMCommand cmds;
	WdbeMCommand* cmd = NULL;

	ListWdbeAMCommandInvpar ipas;
	WdbeAMCommandInvpar* ipa = NULL;

	ListWdbeAMCommandRetpar rpas;
	WdbeAMCommandRetpar* rpa = NULL;

	ListWdbeMError errs;
	WdbeMError* err = NULL;

	ListWdbeAMErrorPar epas;
	WdbeAMErrorPar* epa = NULL;

	ListWdbeAMModulePar mpas;
	WdbeAMModulePar* mpa = NULL;

	set<string> mpakeys;
	uint mdlNum;

	ListWdbeMModule submdls;
	map<string,WdbeMModule*> srefsSubmdls;
	WdbeMModule* submdl = NULL;

	ListWdbeMModule submtps;
	WdbeMModule* submtp = NULL;
	ubigint refSubmtp;

	ListWdbeMGeneric gens;
	WdbeMGeneric* gen = NULL;
	map<ubigint,ubigint> convGenCs;

	map<string,ubigint> refsMdlgens;
	map<string,string> DefvalsMdlgens;

	set<string> srefsGens;

	ListWdbeMPort prts;
	WdbeMPort* prt = NULL;
	map<ubigint,ubigint> convPrtCs;

	ListWdbeMVariable vars;
	WdbeMVariable* var = NULL;
	map<ubigint,ubigint> convVarCs;

	if (dbswdbe->tblwdbemmodule->loadRecByRef(refWdbeMModule, &mdl)) {
		if (dbswdbe->tblwdbemmodule->loadRecByRef(mdl->tplRefWdbeMModule, &mtp)) {
			// - validate all corresponding modules are specificed
			dbswdbe->tblwdbermmodulemmodule->loadRstByCtd(mtp->ref, false, mdlRmdls);
			for (unsigned int i = 0; i < mdlRmdls.nodes.size(); i++) {
				mdlRmdl = mdlRmdls.nodes[i];

				if (!dbswdbe->loadRefBySQL("SELECT ref FROM TblWdbeRMModuleMModule WHERE ctdRefWdbeMModule = " + to_string(mdl->ref) + " AND srefKFunction = '" + mdlRmdl->srefKFunction + "'", ref))
					Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "modular structure error: no corresponding module specified for function " + mdlRmdl->srefKFunction + "!");
			};

			if (mtp->refWdbeMController != 0) {
				if (dbswdbe->tblwdbemunit->loadRecByRef(mdl->hkUref, &unt)) {
					// - controller
					if (mdl->refWdbeMController == 0) {
						mdl->refWdbeMController = dbswdbe->tblwdbemcontroller->insertNewRec(NULL, mdl->ref, 0, "Ctr" + unt->Fullsref.substr(3) + StrMod::cap(mdl->sref), 0);
						dbswdbe->tblwdbemmodule->updateRec(mdl);
					};

					// - vectors: adapt sref
					dbswdbe->tblwdbemvector->loadRstByHktHku(VecWdbeVMVectorHkTbl::CTR, mtp->refWdbeMController, false, vecs);

					for (unsigned int i = 0; i < vecs.nodes.size(); i++) {
						vec = vecs.nodes[i];
						ref = vec->ref;

						dbswdbe->tblwdbemvectoritem->loadRstByVec(vec->ref, false, vits);

						vec->hkUref = mdl->refWdbeMController;
						vec->sref = vec->sref.substr(0, 4) + unt->Fullsref.substr(3) + StrMod::cap(mdl->sref) + vec->sref.substr(4);
						
						vec->ref = 0;
						dbswdbe->tblwdbemvector->insertRec(vec);
						refsVecs[ref] = vec->ref;

						// - vector items
						for (unsigned int j = 0; j < vits.nodes.size(); j++) {
							vit = vits.nodes[j];

							vit->vecRefWdbeMVector = vec->ref;
							
							vit->ref = 0;
							dbswdbe->tblwdbemvectoritem->insertRec(vit);
						};
					};

					// - commands: adapt Fullsref
					dbswdbe->tblwdbemcommand->loadRstByRetReu(VecWdbeVMCommandRefTbl::CTR, mtp->refWdbeMController, false, cmds);

					for (unsigned int i = 0; i < cmds.nodes.size(); i++) {
						cmd = cmds.nodes[i];

						dbswdbe->tblwdbeamcommandinvpar->loadRstByCmd(cmd->ref, false, ipas);
						dbswdbe->tblwdbeamcommandretpar->loadRstByCmd(cmd->ref, false, rpas);

						cmd->refUref = mdl->refWdbeMController;
						cmd->Fullsref = "Cmd" + unt->Fullsref.substr(3) + StrMod::cap(mdl->sref) + StrMod::cap(cmd->sref);
						
						cmd->ref = 0;
						dbswdbe->tblwdbemcommand->insertRec(cmd);

						// - invocation parameters: adapt refWdbeMVector
						for (unsigned int j = 0; j < ipas.nodes.size(); j++) {
							ipa = ipas.nodes[j];

							ipa->cmdRefWdbeMCommand = cmd->ref;
							auto it = refsVecs.find(ipa->refWdbeMVector);
							if (it != refsVecs.end()) ipa->refWdbeMVector = it->second;
							
							ipa->ref = 0;
							dbswdbe->tblwdbeamcommandinvpar->insertRec(ipa);
						};

						// - return parameters: adapt refWdbeMVector
						for (unsigned int j = 0; j < rpas.nodes.size(); j++) {
							rpa = rpas.nodes[j];

							rpa->cmdRefWdbeMCommand = cmd->ref;
							auto it = refsVecs.find(rpa->refWdbeMVector);
							if (it != refsVecs.end()) rpa->refWdbeMVector = it->second;

							rpa->ref = 0;
							dbswdbe->tblwdbeamcommandretpar->insertRec(rpa);
						};
					};

					// - errors: adapt Fullsref
					dbswdbe->tblwdbemerror->loadRstByRetReu(VecWdbeVMErrorRefTbl::CTR, mtp->refWdbeMController, false, errs);

					for (unsigned int i = 0; i < errs.nodes.size(); i++) {
						err = errs.nodes[i];

						dbswdbe->tblwdbeamerrorpar->loadRstByErr(err->ref, false, epas);

						err->refUref = mdl->refWdbeMController;
						err->Fullsref = "Err" + unt->Fullsref.substr(3) + StrMod::cap(mdl->sref) + StrMod::cap(err->sref);
						
						err->ref = 0;
						dbswdbe->tblwdbemerror->insertRec(err);

						// - error parameters: adapt refWdbeMVector
						for (unsigned int j = 0; j < epas.nodes.size(); j++) {
							epa = epas.nodes[j];

							epa->errRefWdbeMError = err->ref;
							auto it = refsVecs.find(epa->refWdbeMVector);
							if (it != refsVecs.end()) epa->refWdbeMVector = it->second;

							epa->ref = 0;
							dbswdbe->tblwdbeamerrorpar->insertRec(epa);
						};
					};

					delete unt;
				};
			};

			// - parameters unless they are present already
			mpakeys.clear();

			dbswdbe->tblwdbeammodulepar->loadRstByMdl(refWdbeMModule, false, mpas);
			for (unsigned int i = 0; i < mpas.nodes.size(); i++) mpakeys.insert(mpas.nodes[i]->x1SrefKKey);

			mdlNum = mpas.nodes.size() + 1;

			dbswdbe->tblwdbeammodulepar->loadRstByMdl(mtp->ref, false, mpas);

			for (unsigned int i = 0; i < mpas.nodes.size(); i++) {
				mpa = mpas.nodes[i];

				if (mpakeys.find(mpa->x1SrefKKey) == mpakeys.end()) {
					mpa->mdlRefWdbeMModule = refWdbeMModule;
					mpa->mdlNum = mdlNum++;
					
					mpa->ref = 0;
					dbswdbe->tblwdbeammodulepar->insertRec(mpa);
				};
			};

			// - generics: existing sref's have to match mtp; adapt refWdbeCGeneric
			dbswdbe->tblwdbemgeneric->loadRstByMdl(refWdbeMModule, false, gens);
			for (unsigned int i = 0; i < gens.nodes.size(); i++) {
				gen = gens.nodes[i];

				refsMdlgens[gen->sref] = gen->ref;
				DefvalsMdlgens[gen->sref] = gen->Defval;
			};

			dbswdbe->tblwdbemgeneric->loadRstByMdl(mtp->ref, false, gens);
			for (unsigned int i = 0; i < gens.nodes.size(); i++) srefsGens.insert(gens.nodes[i]->sref);

			for (auto it = refsMdlgens.begin(); it != refsMdlgens.end(); it++)
				if (srefsGens.find(it->first) == srefsGens.end())
					Wdbe::appendToTmpfile(xchg->tmppath, logfile, logfi, "modular structure error: template doesn't provide generic " + it->first + "!");

			for (unsigned int i = 0; i < gens.nodes.size(); i++) {
				gen = gens.nodes[i];

				gen->ref = 0;

				if (gen->refWdbeCGeneric != 0) {
					auto it = convGenCs.find(gen->refWdbeCGeneric);
					
					if (it != convGenCs.end()) {
						gen->refWdbeCGeneric = it->second;
					} else {
						convGenCs[gen->refWdbeCGeneric] = dbswdbe->tblwdbecgeneric->getNewRef();
						gen->refWdbeCGeneric = convGenCs[gen->refWdbeCGeneric];
					};
				};

				gen->mdlRefWdbeMModule = refWdbeMModule;

				auto it = DefvalsMdlgens.find(gen->sref);
				if (it != DefvalsMdlgens.end()) gen->Defval = it->second;

				dbswdbe->tblwdbemgeneric->insertRec(gen);
			};

			for (auto it = refsMdlgens.begin(); it != refsMdlgens.end(); it++) dbswdbe->tblwdbemgeneric->removeRecByRef(it->second);

			// - ports: adapt refWdbeCPort
			dbswdbe->tblwdbemport->loadRstByMdl(mtp->ref, false, prts);

			for (unsigned int i = 0; i < prts.nodes.size(); i++) {
				prt = prts.nodes[i];

				prt->ref = 0;

				if (prt->refWdbeCPort != 0) {
					auto it = convPrtCs.find(prt->refWdbeCPort);
					
					if (it != convPrtCs.end()) {
						prt->refWdbeCPort = it->second;
					} else {
						convPrtCs[prt->refWdbeCPort] = dbswdbe->tblwdbecport->getNewRef();
						prt->refWdbeCPort = convPrtCs[prt->refWdbeCPort];
					};
				};

				prt->mdlRefWdbeMModule = refWdbeMModule;

				dbswdbe->tblwdbemport->insertRec(prt);
			};

			// - variables: adapt refWdbeCVariable
			dbswdbe->tblwdbemvariable->loadRstByRetReu(VecWdbeVMVariableRefTbl::MDL, mtp->ref, false, vars);

			for (unsigned int i = 0; i < vars.nodes.size(); i++) {
				var = vars.nodes[i];

				var->ref = 0;

				if (var->refWdbeCVariable != 0) {
					auto it = convVarCs.find(var->refWdbeCVariable);
					
					if (it != convVarCs.end()) {
						var->refWdbeCVariable = it->second;
					} else {
						convVarCs[var->refWdbeCVariable] = dbswdbe->tblwdbecvariable->getNewRef();
						var->refWdbeCVariable = convVarCs[var->refWdbeCVariable];
					};
				};

				var->refUref = refWdbeMModule;

				dbswdbe->tblwdbemvariable->insertRec(var);
			};

			// - sub-modules unless they are present already: push back hkNum of subsequent modules, copy pars
			srefsSubmdls.clear();
			dbswdbe->tblwdbemmodule->loadRstBySup(mdl->ref, false, submdls);
			for (unsigned int i = 0; i < submdls.nodes.size(); i++) srefsSubmdls[submdls.nodes[i]->sref] = submdls.nodes[i];

			dbswdbe->tblwdbemmodule->loadRstBySQL("SELECT * FROM TblWdbeMModule WHERE hkIxVTbl = " + to_string(VecWdbeVMModuleHkTbl::VOID) + " AND supRefWdbeMModule = " + to_string(mtp->ref) + " ORDER BY hkNum ASC", false, submtps);

			if (submtps.nodes.size() > 0) {
				for (unsigned int i = 0; i < submtps.nodes.size(); i++) {
					submtp = submtps.nodes[i];

					refSubmtp = submtp->ref;

					mdlNum = 1;
					mpakeys.clear();

					auto it = srefsSubmdls.find(submtp->sref);
					if (it == srefsSubmdls.end()) {
						submdl = submtp;

						submdl->hkIxVTbl = mdl->hkIxVTbl;
						submdl->hkUref = mdl->hkUref;
						submdl->hkNum = mdl->hkNum + i + 1;
						submdl->supRefWdbeMModule = refWdbeMModule;
						submdl->Srefrule = "";

						submdl->ref = 0;
						dbswdbe->tblwdbemmodule->insertRec(submdl);

					} else {
						submdl = it->second;

						submdl->hkNum = mdl->hkNum + i + 1;
						submdl->tplRefWdbeMModule = submtp->tplRefWdbeMModule;
						
						dbswdbe->tblwdbemmodule->updateRec(submdl);

						dbswdbe->tblwdbeammodulepar->loadRstByMdl(submdl->ref, false, mpas);
						mdlNum = mpas.nodes.size() + 1;

						for (unsigned int j = 0; j < mpas.nodes.size(); j++) mpakeys.insert(mpas.nodes[j]->x1SrefKKey);
					};

					dbswdbe->tblwdbeammodulepar->loadRstByMdl(refSubmtp, false, mpas);

					for (unsigned int j = 0; j < mpas.nodes.size(); j++) {
						mpa = mpas.nodes[j];

						if (mpakeys.find(mpa->x1SrefKKey) == mpakeys.end()) {
							mpa->ref = 0;
							mpa->mdlRefWdbeMModule = submdl->ref;
							mpa->mdlNum = mdlNum++;
							
							dbswdbe->tblwdbeammodulepar->insertRec(mpa);
						};
					};
				};

				dbswdbe->executeQuery("UPDATE TblWdbeMModule SET hkNum = hkNum + " + to_string(submtps.nodes.size()-submdls.nodes.size()) + " WHERE hkIxVTbl = " + to_string(mdl->hkIxVTbl) + " AND hkUref = " + to_string(mdl->hkUref) + " AND hkNum > " + to_string(mdl->hkNum+submtps.nodes.size()));
			};

			delete mtp;
		};

		delete mdl;
	};

	if (logfi.is_open()) {
		logfi.close();

		ixOpVOpres = VecOpVOpres::FAILURE;
	};
	// IP run --- IEND

	return(new DpchRetWdbeCplmstTplcpy("", "", ixOpVOpres, 100, logfile));
};

// IP cust --- INSERT
