.TOPDIR?=../..
.CURDIR?=.

LIB=openbsd

SRCS+=	closefrom.c \
	heapsort.c merge.c pledge-noop.c progname.c \
	qsort.c radixsort.c random.c readpassphrase.c \
	setproctitle.c strtoimax.c strtonum.c strtoumax.c \
	pwcache.c pw_dup.c \
	strmode.c


LIBCSRCDIR=${.CURDIR}
include ${LIBCSRCDIR}/Makefile.inc

include ${.TOPDIR}/config.mk

ifneq ($(HAVE_ISSETUGID),1)
SRCS+=	issetugid.c
endif

ifneq ($(HAVE_GETENTROPY),1)
# XXX: fix fstatfs
SRCS+=	getentropy_linux.c
endif

include ${.TOPDIR}/mk/bsd.lib.mk
