# file Makefile
# make file for Wdbe combined daemon, release wdbecmbd_ungenio
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWDBECMBD

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbswdbe -I$(SRCROOT)/wdbecmbd/VecWdbe -I$(SRCROOT)/wdbecmbd/IexWdbe -I$(SRCROOT)/wdbecmbd
INCPATH += -I$(SRCROOT)/wdbecmbd/CrdWdbeUsg -I$(SRCROOT)/wdbecmbd/CrdWdbeUsr -I$(SRCROOT)/wdbecmbd/CrdWdbePrs -I$(SRCROOT)/wdbecmbd/CrdWdbeFil -I$(SRCROOT)/wdbecmbd/CrdWdbeNav -I$(SRCROOT)/wdbecmbd/CrdWdbeMch -I$(SRCROOT)/wdbecmbd/CrdWdbeLib -I$(SRCROOT)/wdbecmbd/CrdWdbeFam -I$(SRCROOT)/wdbecmbd/CrdWdbeSil -I$(SRCROOT)/wdbecmbd/CrdWdbeMtp -I$(SRCROOT)/wdbecmbd/CrdWdbePrj -I$(SRCROOT)/wdbecmbd/CrdWdbeVer -I$(SRCROOT)/wdbecmbd/CrdWdbeSys -I$(SRCROOT)/wdbecmbd/CrdWdbeTrg -I$(SRCROOT)/wdbecmbd/CrdWdbeUnt -I$(SRCROOT)/wdbecmbd/CrdWdbeRls -I$(SRCROOT)/wdbecmbd/CrdWdbeCpr -I$(SRCROOT)/wdbecmbd/CrdWdbeCvr -I$(SRCROOT)/wdbecmbd/CrdWdbeMod -I$(SRCROOT)/wdbecmbd/CrdWdbeVec -I$(SRCROOT)/wdbecmbd/CrdWdbeVit -I$(SRCROOT)/wdbecmbd/CrdWdbeCmd -I$(SRCROOT)/wdbecmbd/CrdWdbeErr -I$(SRCROOT)/wdbecmbd/CrdWdbePph -I$(SRCROOT)/wdbecmbd/CrdWdbeBnk -I$(SRCROOT)/wdbecmbd/CrdWdbePin -I$(SRCROOT)/wdbecmbd/CrdWdbeGen -I$(SRCROOT)/wdbecmbd/CrdWdbePrt -I$(SRCROOT)/wdbecmbd/CrdWdbeSig -I$(SRCROOT)/wdbecmbd/CrdWdbePrc -I$(SRCROOT)/wdbecmbd/CrdWdbeFst -I$(SRCROOT)/wdbecmbd/CrdWdbeVar -I$(SRCROOT)/wdbecmbd/CrdWdbeUtl
INCPATH += -I$(SRCROOT)/wdbecmbd/WdbeWrmcu -I$(SRCROOT)/wdbecmbd/WdbeWrfpga -I$(SRCROOT)/wdbecmbd/WdbeWrdev -I$(SRCROOT)/wdbecmbd/WdbePrctree -I$(SRCROOT)/wdbecmbd/WdbePrcfile -I$(SRCROOT)/wdbecmbd/WdbePlhmcu -I$(SRCROOT)/wdbecmbd/WdbePlhfpga -I$(SRCROOT)/wdbecmbd/WdbeMtpWrmcu -I$(SRCROOT)/wdbecmbd/WdbeMtpWrfpga -I$(SRCROOT)/wdbecmbd/WdbeMtpModdet -I$(SRCROOT)/wdbecmbd/WdbeMtpModbsctd -I$(SRCROOT)/wdbecmbd/WdbeMtpModbscbu -I$(SRCROOT)/wdbecmbd/WdbeMtpPlhmcu -I$(SRCROOT)/wdbecmbd/WdbeMtpPlhfpga -I$(SRCROOT)/wdbecmbd/WdbeModdet -I$(SRCROOT)/wdbecmbd/WdbeModbsc
INCPATH += -I/Library/PostgreSQL/9.6/include -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include

PCHS = Wdbecmbd.h.gch

OBJS = Wdbe.o WdbecmbdAppsrv.o WdbecmbdJobprc.o WdbecmbdOpprc.o Wdbecmbd.o
OBJS += RootWdbe.o SessWdbe.o JobWdbeLicense.o
OBJS += Wdbecmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbecmbd
LIBPATH += -L/Library/PostgreSQL/9.6/lib -L/usr/local/lib -L/usr/local/mysql/lib
LIBPATH += 

LIBS = -lcrdwdbeusg -lcrdwdbeusr -lcrdwdbeprs -lcrdwdbefil -lcrdwdbenav -lcrdwdbemch -lcrdwdbelib -lcrdwdbefam -lcrdwdbesil -lcrdwdbemtp -lcrdwdbeprj -lcrdwdbever -lcrdwdbesys -lcrdwdbetrg -lcrdwdbeunt -lcrdwdberls -lcrdwdbecpr -lcrdwdbecvr -lcrdwdbemod -lcrdwdbevec -lcrdwdbevit -lcrdwdbecmd -lcrdwdbeerr -lcrdwdbepph -lcrdwdbebnk -lcrdwdbepin -lcrdwdbegen -lcrdwdbeprt -lcrdwdbesig -lcrdwdbeprc -lcrdwdbefst -lcrdwdbevar -lcrdwdbeutl
LIBS += -lwdbewrmcu -lwdbewrfpga -lwdbewrdev -lwdbeprctree -lwdbeprcfile -lwdbeplhmcu -lwdbeplhfpga -lwdbemtpwrmcu -lwdbemtpwrfpga -lwdbemtpmoddet -lwdbemtpmodbsctd -lwdbemtpmodbscbu -lwdbemtpplhmcu -lwdbemtpplhfpga -lwdbemoddet -lwdbemodbsc
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lapiwzlm -lcurl -lgit2 -ljsoncpp -lmicrohttpd -lsbecore_dbsmon -lsbecore_mon -lsbecore_my -lsbecore_pg
LIBS += -ldbswzem -lmysqlclient -lpq -lsbecore_plus -lssl
LIBS += -lcrypto -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += 

EXE = Wdbecmbd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJS)
	$(LINK) $(LINKFLAGS) $(OBJS) $(LIBPATH) $(LIBS) -o $(EXE)
	rm -f *.o

pch:	$(PCHS)

install:
	mv $(EXE) $(BINROOT)/wdbecmbd/

clean:
	rm -f *.gch
	rm -f *.o

