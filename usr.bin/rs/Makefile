#	$OpenBSD: Makefile,v 1.3 2015/12/03 12:23:15 schwarze Exp $

.TOPDIR?=../..

PROG=	rs
SRCS=	rs.c utf8.c
CPPFLAGS+=-D_GNU_SOURCE -D_XOPEN_SOURCE

include ${.TOPDIR}/mk/bsd.prog.mk
