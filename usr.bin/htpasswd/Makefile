#	$OpenBSD: Makefile,v 1.4 2017/07/09 21:23:19 espie Exp $

.TOPDIR?=../..

PROG=		htpasswd

CFLAGS+=	-W -Wall
CFLAGS+=	-Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations
CFLAGS+=	-Wshadow -Wpointer-arith -Wcast-qual -Wsign-compare

include ${.TOPDIR}/mk/bsd.prog.mk
