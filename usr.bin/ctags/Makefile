#	$OpenBSD: Makefile,v 1.3 1997/09/21 11:48:50 deraadt Exp $

.TOPDIR?=../..

PROG=	ctags
CFLAGS+=-I${.CURDIR}
SRCS=	C.c ctags.c fortran.c lisp.c print.c tree.c yacc.c

include ${.TOPDIR}/mk/bsd.prog.mk
