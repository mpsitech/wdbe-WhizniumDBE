# file Makefile
# make file for Wdbe combined daemon, release wdbecmbd_mac
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Mar 2021
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWDBECMBD

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswdbe -I$(BUILDROOT)/wdbecmbd/VecWdbe -I$(BUILDROOT)/wdbecmbd/IexWdbe -I$(BUILDROOT)/wdbecmbd
INCPATH += -I$(BUILDROOT)/wdbecmbd/CrdWdbeUsg -I$(BUILDROOT)/wdbecmbd/CrdWdbeUsr -I$(BUILDROOT)/wdbecmbd/CrdWdbePrs -I$(BUILDROOT)/wdbecmbd/CrdWdbeFil -I$(BUILDROOT)/wdbecmbd/CrdWdbeNav -I$(BUILDROOT)/wdbecmbd/CrdWdbeMch -I$(BUILDROOT)/wdbecmbd/CrdWdbeLib -I$(BUILDROOT)/wdbecmbd/CrdWdbeFam -I$(BUILDROOT)/wdbecmbd/CrdWdbeSil -I$(BUILDROOT)/wdbecmbd/CrdWdbeMtp -I$(BUILDROOT)/wdbecmbd/CrdWdbePrj -I$(BUILDROOT)/wdbecmbd/CrdWdbeVer -I$(BUILDROOT)/wdbecmbd/CrdWdbeSys -I$(BUILDROOT)/wdbecmbd/CrdWdbeTrg -I$(BUILDROOT)/wdbecmbd/CrdWdbeUnt -I$(BUILDROOT)/wdbecmbd/CrdWdbeRls -I$(BUILDROOT)/wdbecmbd/CrdWdbeCpr -I$(BUILDROOT)/wdbecmbd/CrdWdbeCvr -I$(BUILDROOT)/wdbecmbd/CrdWdbeMod -I$(BUILDROOT)/wdbecmbd/CrdWdbeVec -I$(BUILDROOT)/wdbecmbd/CrdWdbeVit -I$(BUILDROOT)/wdbecmbd/CrdWdbeCmd -I$(BUILDROOT)/wdbecmbd/CrdWdbeErr -I$(BUILDROOT)/wdbecmbd/CrdWdbePph -I$(BUILDROOT)/wdbecmbd/CrdWdbeBnk -I$(BUILDROOT)/wdbecmbd/CrdWdbePin -I$(BUILDROOT)/wdbecmbd/CrdWdbeGen -I$(BUILDROOT)/wdbecmbd/CrdWdbePrt -I$(BUILDROOT)/wdbecmbd/CrdWdbeSig -I$(BUILDROOT)/wdbecmbd/CrdWdbePrc -I$(BUILDROOT)/wdbecmbd/CrdWdbeFst -I$(BUILDROOT)/wdbecmbd/CrdWdbeVar -I$(BUILDROOT)/wdbecmbd/CrdWdbeUtl
INCPATH += -I$(BUILDROOT)/wdbecmbd/WdbeWrmcu -I$(BUILDROOT)/wdbecmbd/WdbePlhmcu -I$(BUILDROOT)/wdbecmbd/WdbeWrfpga -I$(BUILDROOT)/wdbecmbd/WdbeWrdev -I$(BUILDROOT)/wdbecmbd/WdbePrctree -I$(BUILDROOT)/wdbecmbd/WdbePrcfile -I$(BUILDROOT)/wdbecmbd/WdbePlhfpga -I$(BUILDROOT)/wdbecmbd/WdbeMtpWrmcu -I$(BUILDROOT)/wdbecmbd/WdbeMtpModdet -I$(BUILDROOT)/wdbecmbd/WdbeMtpWrfpga -I$(BUILDROOT)/wdbecmbd/WdbeMtpModbsctd -I$(BUILDROOT)/wdbecmbd/WdbeMtpModbscbu -I$(BUILDROOT)/wdbecmbd/WdbeMtpPlhfpga -I$(BUILDROOT)/wdbecmbd/WdbeMtpPlhmcu -I$(BUILDROOT)/wdbecmbd/WdbeModdet -I$(BUILDROOT)/wdbecmbd/WdbeModbsc
INCPATH += -I${WHIZSDKROOT}/build -I${WHIZSDKROOT}/build/apiwzlm -I/usr/local/include -I/usr/local/include/curl -I/usr/local/include/libxml2 -I/usr/local/mysql/include -I/usr/local/opt/sqlite/include

PCHS = Wdbecmbd.h.gch

OBJS = Wdbe.o WdbecmbdAppsrv.o WdbecmbdJobprc.o WdbecmbdOpprc.o Wdbecmbd.o
OBJS += RootWdbe.o SessWdbe.o JobWdbeLicense.o
OBJS += Wdbecmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbecmbd
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/local/lib -L/usr/local/mysql/lib -L/usr/local/opt/sqlite/lib

LIBS = -lcrdwdbeusg -lcrdwdbeusr -lcrdwdbeprs -lcrdwdbefil -lcrdwdbenav -lcrdwdbemch -lcrdwdbelib -lcrdwdbefam -lcrdwdbesil -lcrdwdbemtp -lcrdwdbeprj -lcrdwdbever -lcrdwdbesys -lcrdwdbetrg -lcrdwdbeunt -lcrdwdberls -lcrdwdbecpr -lcrdwdbecvr -lcrdwdbemod -lcrdwdbevec -lcrdwdbevit -lcrdwdbecmd -lcrdwdbeerr -lcrdwdbepph -lcrdwdbebnk -lcrdwdbepin -lcrdwdbegen -lcrdwdbeprt -lcrdwdbesig -lcrdwdbeprc -lcrdwdbefst -lcrdwdbevar -lcrdwdbeutl
LIBS += -lwdbewrmcu -lwdbeplhmcu -lwdbewrfpga -lwdbewrdev -lwdbeprctree -lwdbeprcfile -lwdbeplhfpga -lwdbemtpwrmcu -lwdbemtpmoddet -lwdbemtpwrfpga -lwdbemtpmodbsctd -lwdbemtpmodbscbu -lwdbemtpplhfpga -lwdbemtpplhmcu -lwdbemoddet -lwdbemodbsc
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lapiwzlm -lcurl -lgit2 -lmicrohttpd -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem
LIBS += -lsbecore_lite -lsbecore_my
LIBS += -lmysqlclient -lsbecore_plus -lsqlite3 -lssl
LIBS += -lcrypto -lsbecore
LIBS += -ljsoncpp -lxml2

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
