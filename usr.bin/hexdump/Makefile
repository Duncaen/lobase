#	$OpenBSD: Makefile,v 1.2 1996/06/26 05:34:16 deraadt Exp $

.TOPDIR?=../..

PROG=	hexdump
SRCS=	conv.c display.c hexdump.c hexsyntax.c odsyntax.c parse.c
MAN=	hexdump.1 od.1
LINKS=	${BINDIR}/hexdump ${BINDIR}/od

include ${.TOPDIR}/mk/bsd.prog.mk
