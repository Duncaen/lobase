#	$OpenBSD: Makefile,v 1.4 2011/07/07 21:00:59 deraadt Exp $

.TOPDIR?=../..

PROG=	date
SRCS=	date.c
DPADD+=	${LIBUTIL}
LDADD+=	-loutil

include ${.TOPDIR}/mk/bsd.prog.mk
