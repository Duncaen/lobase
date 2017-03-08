#	$OpenBSD: Makefile,v 1.11 2014/05/24 01:35:55 daniel Exp $

.TOPDIR?=../..

PROG=	ed
CFLAGS+=-DBACKWARDS
SRCS=	 buf.c glbl.c io.c main.c re.c sub.c undo.c

include ${.TOPDIR}/mk/bsd.prog.mk
