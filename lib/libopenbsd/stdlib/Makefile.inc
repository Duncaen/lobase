#	$OpenBSD: Makefile.inc,v 1.61 2016/08/14 23:18:03 guenther Exp $

# stdlib sources
VPATH+=	${LIBCSRCDIR}/stdlib

SRCS+=	getopt_long.c
MAN+=	getopt.3 getopt_long.3

include ${.TOPDIR}/config.mk

ifneq ($(HAVE_FREEZERO),1)
SRCS+=	freezero.c
endif

ifneq ($(HAVE_REALLOCARRAY),1)
SRCS+=	reallocarray.c
MAN+=	malloc.3
endif

ifneq ($(HAVE_RECALLOCARRAY),1)
SRCS+=	recallocarray.c
MAN+=	malloc.3
endif
