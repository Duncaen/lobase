.TOPDIR?=../..
.CURDIR?=.

LIB=openbsd

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
