# file Makefile
# make file for Wdbe daemon, release wdbed_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 16 Dec 2020
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWDBED

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswdbe -I$(BUILDROOT)/wdbed/VecWdbe -I$(BUILDROOT)/wdbed/IexWdbe -I$(BUILDROOT)/wdbed
INCPATH += -I$(BUILDROOT)/wdbed/CrdWdbeUsg -I$(BUILDROOT)/wdbed/CrdWdbeUsr -I$(BUILDROOT)/wdbed/CrdWdbePrs -I$(BUILDROOT)/wdbed/CrdWdbeFil -I$(BUILDROOT)/wdbed/CrdWdbeNav -I$(BUILDROOT)/wdbed/CrdWdbeMch -I$(BUILDROOT)/wdbed/CrdWdbeLib -I$(BUILDROOT)/wdbed/CrdWdbeFam -I$(BUILDROOT)/wdbed/CrdWdbeSil -I$(BUILDROOT)/wdbed/CrdWdbeMtp -I$(BUILDROOT)/wdbed/CrdWdbePrj -I$(BUILDROOT)/wdbed/CrdWdbeVer -I$(BUILDROOT)/wdbed/CrdWdbeSys -I$(BUILDROOT)/wdbed/CrdWdbeTrg -I$(BUILDROOT)/wdbed/CrdWdbeUnt -I$(BUILDROOT)/wdbed/CrdWdbeRls -I$(BUILDROOT)/wdbed/CrdWdbeCpr -I$(BUILDROOT)/wdbed/CrdWdbeCvr -I$(BUILDROOT)/wdbed/CrdWdbeMod -I$(BUILDROOT)/wdbed/CrdWdbeVec -I$(BUILDROOT)/wdbed/CrdWdbeVit -I$(BUILDROOT)/wdbed/CrdWdbeCmd -I$(BUILDROOT)/wdbed/CrdWdbeErr -I$(BUILDROOT)/wdbed/CrdWdbePph -I$(BUILDROOT)/wdbed/CrdWdbeBnk -I$(BUILDROOT)/wdbed/CrdWdbePin -I$(BUILDROOT)/wdbed/CrdWdbeGen -I$(BUILDROOT)/wdbed/CrdWdbePrt -I$(BUILDROOT)/wdbed/CrdWdbeSig -I$(BUILDROOT)/wdbed/CrdWdbePrc -I$(BUILDROOT)/wdbed/CrdWdbeFst -I$(BUILDROOT)/wdbed/CrdWdbeVar -I$(BUILDROOT)/wdbed/CrdWdbeUtl
INCPATH += -I${WHIZSDKROOT}/build -I${WHIZSDKROOT}/build/apiwzlm -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include -I/usr/local/opt/sqlite/include

PCHS = Wdbed.h.gch

OBJS = Wdbe.o WdbedAppsrv.o WdbedJobprc.o WdbedOpprc.o WdbedOpengcli.o WdbedOpengsrv.o Wdbed.o
OBJS += RootWdbe.o SessWdbe.o JobWdbeLicense.o
OBJS += WdbeWrmcu_blks.o SqkWdbeWrmcu.o WdbeWrfpga_blks.o SqkWdbeWrfpga.o WdbeWrdev_blks.o SqkWdbeWrdev.o WdbePlhmcu_blks.o SqkWdbePlhmcu.o WdbePrcfile_blks.o SqkWdbePrcfile.o WdbePrctree_blks.o SqkWdbePrctree.o WdbeMtpWrfpga_blks.o SqkWdbeMtpWrfpga.o WdbeMtpWrmcu_blks.o SqkWdbeMtpWrmcu.o WdbePlhfpga_blks.o SqkWdbePlhfpga.o WdbeMtpModdet_blks.o SqkWdbeMtpModdet.o WdbeMtpModbsctd_blks.o SqkWdbeMtpModbsctd.o WdbeMtpModbscbu_blks.o SqkWdbeMtpModbscbu.o WdbeMtpPlhmcu_blks.o SqkWdbeMtpPlhmcu.o WdbeMtpPlhfpga_blks.o SqkWdbeMtpPlhfpga.o WdbeModdet_blks.o SqkWdbeModdet.o WdbeModbsc_blks.o SqkWdbeModbsc.o
OBJS += Wdbed_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbed
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/local/lib -L/usr/local/mysql/lib -L/usr/local/opt/sqlite/lib

LIBS = -lcrdwdbeusg -lcrdwdbeusr -lcrdwdbeprs -lcrdwdbefil -lcrdwdbenav -lcrdwdbemch -lcrdwdbelib -lcrdwdbefam -lcrdwdbesil -lcrdwdbemtp -lcrdwdbeprj -lcrdwdbever -lcrdwdbesys -lcrdwdbetrg -lcrdwdbeunt -lcrdwdberls -lcrdwdbecpr -lcrdwdbecvr -lcrdwdbemod -lcrdwdbevec -lcrdwdbevit -lcrdwdbecmd -lcrdwdbeerr -lcrdwdbepph -lcrdwdbebnk -lcrdwdbepin -lcrdwdbegen -lcrdwdbeprt -lcrdwdbesig -lcrdwdbeprc -lcrdwdbefst -lcrdwdbevar -lcrdwdbeutl
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lapiwzlm -lcurl -lgit2 -ljsoncpp -lmicrohttpd -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem
LIBS += -lsbecore_lite -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus -lsqlite3 -lssl
LIBS += -lcrypto -lsbecore
LIBS += -lxml2

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
