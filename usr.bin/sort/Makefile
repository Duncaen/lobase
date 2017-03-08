# $OpenBSD: Makefile,v 1.6 2015/03/17 17:45:13 millert Exp $

.TOPDIR?=../..

PROG=	sort

SRCS=	bwstring.c coll.c file.c mem.c radixsort.c sort.c vsort.c
CPPFLAGS+=-D_GNU_SOURCE

include ${.TOPDIR}/mk/bsd.prog.mk
