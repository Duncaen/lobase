#	$OpenBSD: Makefile.inc,v 1.29 2016/03/30 06:38:41 jmc Exp $

# stdio sources
VPATH+=	${LIBCSRCDIR}/gen

SRCS+=	basename.c devname.c dirname.c errc.c fts.c getmntinfo.c glob.c \
	setmode.c unvis.c verrc.c vis.c vwarnc.c warnc.c getbsize.c getcap.c

include ${.TOPDIR}/config.mk

ifneq ($(HAVE_SYS_SIGNAME),1)
SRCS+=	signame.c
endif

ifneq ($(HAVE_SYS_SIGLIST),1)
SRCS+=	siglist.c
endif

MAN+=	basename.3 devname.3 dirname.3 fts.3 getmntinfo.3 glob.3 setmode.3 \
	unvis.3 vis.3 getbsize.3 getcap.3
