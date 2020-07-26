# file Makefile
# make file for Wdbe daemon, release wdbed_jack
# author Alexander Wirthmueller
# date created: 11 Jul 2020
# modified: 11 Jul 2020

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWDBED

LINK = g++
LINKFLAGS =

INCPATH = -I$(SRCROOT)/dbswdbe -I$(SRCROOT)/wdbed/VecWdbe -I$(SRCROOT)/wdbed/IexWdbe -I$(SRCROOT)/wdbed
INCPATH += -I$(SRCROOT)/wdbed/CrdWdbeUsg -I$(SRCROOT)/wdbed/CrdWdbeUsr -I$(SRCROOT)/wdbed/CrdWdbePrs -I$(SRCROOT)/wdbed/CrdWdbeFil -I$(SRCROOT)/wdbed/CrdWdbeNav -I$(SRCROOT)/wdbed/CrdWdbeMch -I$(SRCROOT)/wdbed/CrdWdbeLib -I$(SRCROOT)/wdbed/CrdWdbeFam -I$(SRCROOT)/wdbed/CrdWdbeSil -I$(SRCROOT)/wdbed/CrdWdbeMtp -I$(SRCROOT)/wdbed/CrdWdbePrj -I$(SRCROOT)/wdbed/CrdWdbeVer -I$(SRCROOT)/wdbed/CrdWdbeSys -I$(SRCROOT)/wdbed/CrdWdbeTrg -I$(SRCROOT)/wdbed/CrdWdbeUnt -I$(SRCROOT)/wdbed/CrdWdbeRls -I$(SRCROOT)/wdbed/CrdWdbeCpr -I$(SRCROOT)/wdbed/CrdWdbeCvr -I$(SRCROOT)/wdbed/CrdWdbeMod -I$(SRCROOT)/wdbed/CrdWdbeVec -I$(SRCROOT)/wdbed/CrdWdbeVit -I$(SRCROOT)/wdbed/CrdWdbeCmd -I$(SRCROOT)/wdbed/CrdWdbeErr -I$(SRCROOT)/wdbed/CrdWdbePph -I$(SRCROOT)/wdbed/CrdWdbeBnk -I$(SRCROOT)/wdbed/CrdWdbePin -I$(SRCROOT)/wdbed/CrdWdbeGen -I$(SRCROOT)/wdbed/CrdWdbePrt -I$(SRCROOT)/wdbed/CrdWdbeSig -I$(SRCROOT)/wdbed/CrdWdbePrc -I$(SRCROOT)/wdbed/CrdWdbeFst -I$(SRCROOT)/wdbed/CrdWdbeVar -I$(SRCROOT)/wdbed/CrdWdbeUtl
INCPATH += -I/home/mpsitech/src/apiwzlm -I/usr/include -I/usr/include/jsoncpp -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql -I/usr/local/include

PCHS = Wdbed.h.gch

OBJS = Wdbe.o WdbedAppsrv.o WdbedJobprc.o WdbedOpprc.o WdbedOpengcli.o WdbedOpengsrv.o Wdbed.o
OBJS += RootWdbe.o SessWdbe.o JobWdbeLicense.o
OBJS += WdbeWrmcu_blks.o SqkWdbeWrmcu.o WdbeWrfpga_blks.o SqkWdbeWrfpga.o WdbeWrdev_blks.o SqkWdbeWrdev.o WdbePrctree_blks.o SqkWdbePrctree.o WdbePrcfile_blks.o SqkWdbePrcfile.o WdbePlhmcu_blks.o SqkWdbePlhmcu.o WdbePlhfpga_blks.o SqkWdbePlhfpga.o WdbeMtpWrmcu_blks.o SqkWdbeMtpWrmcu.o WdbeMtpWrfpga_blks.o SqkWdbeMtpWrfpga.o WdbeMtpModdet_blks.o SqkWdbeMtpModdet.o WdbeMtpModbsctd_blks.o SqkWdbeMtpModbsctd.o WdbeMtpModbscbu_blks.o SqkWdbeMtpModbscbu.o WdbeMtpPlhmcu_blks.o SqkWdbeMtpPlhmcu.o WdbeMtpPlhfpga_blks.o SqkWdbeMtpPlhfpga.o WdbeModdet_blks.o SqkWdbeModdet.o WdbeModbsc_blks.o SqkWdbeModbsc.o
OBJS += Wdbed_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbed
LIBPATH += -L/home/mpsitech/lib -L/usr/lib/x86_64-linux-gnu -L/usr/local/lib
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdwdbeusg -lcrdwdbeusr -lcrdwdbeprs -lcrdwdbefil -lcrdwdbenav -lcrdwdbemch -lcrdwdbelib -lcrdwdbefam -lcrdwdbesil -lcrdwdbemtp -lcrdwdbeprj -lcrdwdbever -lcrdwdbesys -lcrdwdbetrg -lcrdwdbeunt -lcrdwdberls -lcrdwdbecpr -lcrdwdbecvr -lcrdwdbemod -lcrdwdbevec -lcrdwdbevit -lcrdwdbecmd -lcrdwdbeerr -lcrdwdbepph -lcrdwdbebnk -lcrdwdbepin -lcrdwdbegen -lcrdwdbeprt -lcrdwdbesig -lcrdwdbeprc -lcrdwdbefst -lcrdwdbevar -lcrdwdbeutl
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lapiwzlm -lcurl -lgit2 -ljsoncpp -lmicrohttpd -lsbecore_dbsmon -lsbecore_mon -lsbecore_my -lsbecore_pg
LIBS += -ldbswzem -lmysqlclient -lpq -lsbecore_plus -lssl
LIBS += -lcrypto -lsbecore
LIBS += -lxml2
LIBS += -lz
LIBS += -lpthread

EXE = Wdbed

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
	mv $(EXE) $(BINROOT)/wdbed/

clean:
	rm -f *.gch
	rm -f *.o

