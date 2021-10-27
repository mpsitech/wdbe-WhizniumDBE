# file Makefile
# make file for Wdbe combined daemon, release wdbecmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Oct 2021
# IP header --- ABOVE

include Makefile.inc

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread -DWDBECMBD

LINK = g++
LINKFLAGS =

INCPATH = -I$(BUILDROOT)/dbswdbe -I$(BUILDROOT)/wdbecmbd/VecWdbe -I$(BUILDROOT)/wdbecmbd/IexWdbe -I$(BUILDROOT)/wdbecmbd
INCPATH += -I$(BUILDROOT)/wdbecmbd/CrdWdbeUsg -I$(BUILDROOT)/wdbecmbd/CrdWdbeUsr -I$(BUILDROOT)/wdbecmbd/CrdWdbePrs -I$(BUILDROOT)/wdbecmbd/CrdWdbeFil -I$(BUILDROOT)/wdbecmbd/CrdWdbeNav -I$(BUILDROOT)/wdbecmbd/CrdWdbeMch -I$(BUILDROOT)/wdbecmbd/CrdWdbeLib -I$(BUILDROOT)/wdbecmbd/CrdWdbeFam -I$(BUILDROOT)/wdbecmbd/CrdWdbeSil -I$(BUILDROOT)/wdbecmbd/CrdWdbeMtp -I$(BUILDROOT)/wdbecmbd/CrdWdbePrj -I$(BUILDROOT)/wdbecmbd/CrdWdbeVer -I$(BUILDROOT)/wdbecmbd/CrdWdbeSys -I$(BUILDROOT)/wdbecmbd/CrdWdbeTrg -I$(BUILDROOT)/wdbecmbd/CrdWdbeUnt -I$(BUILDROOT)/wdbecmbd/CrdWdbeRls -I$(BUILDROOT)/wdbecmbd/CrdWdbeCpr -I$(BUILDROOT)/wdbecmbd/CrdWdbeCvr -I$(BUILDROOT)/wdbecmbd/CrdWdbePph -I$(BUILDROOT)/wdbecmbd/CrdWdbeMod -I$(BUILDROOT)/wdbecmbd/CrdWdbeVec -I$(BUILDROOT)/wdbecmbd/CrdWdbeVit -I$(BUILDROOT)/wdbecmbd/CrdWdbeCmd -I$(BUILDROOT)/wdbecmbd/CrdWdbeErr -I$(BUILDROOT)/wdbecmbd/CrdWdbePpl -I$(BUILDROOT)/wdbecmbd/CrdWdbeSeg -I$(BUILDROOT)/wdbecmbd/CrdWdbeBnk -I$(BUILDROOT)/wdbecmbd/CrdWdbePin -I$(BUILDROOT)/wdbecmbd/CrdWdbeInt -I$(BUILDROOT)/wdbecmbd/CrdWdbeSns -I$(BUILDROOT)/wdbecmbd/CrdWdbeVar -I$(BUILDROOT)/wdbecmbd/CrdWdbeGen -I$(BUILDROOT)/wdbecmbd/CrdWdbePrt -I$(BUILDROOT)/wdbecmbd/CrdWdbeSig -I$(BUILDROOT)/wdbecmbd/CrdWdbePrc -I$(BUILDROOT)/wdbecmbd/CrdWdbeFst -I$(BUILDROOT)/wdbecmbd/CrdWdbeUtl
INCPATH += -I$(BUILDROOT)/wdbecmbd/WdbeCplmst -I$(BUILDROOT)/wdbecmbd/WdbeGen -I$(BUILDROOT)/wdbecmbd/WdbeGenfst -I$(BUILDROOT)/wdbecmbd/WdbeMtpPlhfpga -I$(BUILDROOT)/wdbecmbd/WdbeMtpPlhmcu -I$(BUILDROOT)/wdbecmbd/WdbeMtpCplmstbu -I$(BUILDROOT)/wdbecmbd/WdbeMtpCplmsttd -I$(BUILDROOT)/wdbecmbd/WdbeMtpGenfst -I$(BUILDROOT)/wdbecmbd/WdbeMtpWrfpga -I$(BUILDROOT)/wdbecmbd/WdbeMtpWrmcu -I$(BUILDROOT)/wdbecmbd/WdbePlhfpga -I$(BUILDROOT)/wdbecmbd/WdbePlhmcu -I$(BUILDROOT)/wdbecmbd/WdbePrcfile -I$(BUILDROOT)/wdbecmbd/WdbePrctree -I$(BUILDROOT)/wdbecmbd/WdbeWrdev -I$(BUILDROOT)/wdbecmbd/WdbeWrfpga -I$(BUILDROOT)/wdbecmbd/WdbeWrmcu
INCPATH += -I${WHIZSDKROOT}/build -I${WHIZSDKROOT}/build/apiwzlm -I/usr/include -I/usr/include/jsoncpp -I/usr/include/libxml2 -I/usr/include/mariadb

PCHS = Wdbecmbd.h.gch

OBJS = Wdbe.o WdbecmbdAppsrv.o WdbecmbdJobprc.o WdbecmbdOpprc.o Wdbecmbd.o
OBJS += RootWdbe.o SessWdbe.o JobWdbeLicense.o
OBJS += Wdbecmbd_exe.o

LIBPATH = -L$(LIBROOT)
LIBPATH += -L$(LIBROOT)/wdbecmbd
LIBPATH += -L${WHIZSDKROOT}/lib -L/usr/lib/x86_64-linux-gnu
LIBPATH += -L/lib/x86_64-linux-gnu

LIBS = -lcrdwdbeusg -lcrdwdbeusr -lcrdwdbeprs -lcrdwdbefil -lcrdwdbenav -lcrdwdbemch -lcrdwdbelib -lcrdwdbefam -lcrdwdbesil -lcrdwdbemtp -lcrdwdbeprj -lcrdwdbever -lcrdwdbesys -lcrdwdbetrg -lcrdwdbeunt -lcrdwdberls -lcrdwdbecpr -lcrdwdbecvr -lcrdwdbepph -lcrdwdbemod -lcrdwdbevec -lcrdwdbevit -lcrdwdbecmd -lcrdwdbeerr -lcrdwdbeppl -lcrdwdbeseg -lcrdwdbebnk -lcrdwdbepin -lcrdwdbeint -lcrdwdbesns -lcrdwdbevar -lcrdwdbegen -lcrdwdbeprt -lcrdwdbesig -lcrdwdbeprc -lcrdwdbefst -lcrdwdbeutl
LIBS += -lwdbecplmst -lwdbegen -lwdbegenfst -lwdbemtpplhfpga -lwdbemtpplhmcu -lwdbemtpcplmstbu -lwdbemtpcplmsttd -lwdbemtpgenfst -lwdbemtpwrfpga -lwdbemtpwrmcu -lwdbeplhfpga -lwdbeplhmcu -lwdbeprcfile -lwdbeprctree -lwdbewrdev -lwdbewrfpga -lwdbewrmcu
LIBS += -liexwdbe -lvecwdbe -ldbswdbe
LIBS += -lapiwzlm -lcurl -lgit2 -lmicrohttpd -lsbecore_dbsmon -lsbecore_mon
LIBS += -ldbswzem
LIBS += -lsbecore_lite -lsbecore_mar
LIBS += -lmariadbclient -lsbecore_plus -lsqlite3 -lssl
LIBS += -lcrypto -lsbecore
LIBS += -ljsoncpp -lxml2
LIBS += -lpthread

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
