#	$OpenBSD: Makefile,v 1.16 2017/07/10 21:30:37 espie Exp $

.TOPDIR?=../..

PROG=	awk
SRCS=	ytab.c lex.c b.c main.c parse.c proctab.c tran.c lib.c run.c
LDADD=	-lm
DPADD=	${LIBM}
CLEANFILES+=proctab.c maketab ytab.c ytab.h
CFLAGS+=-I. -I${.CURDIR} -DHAS_ISBLANK -DNDEBUG
HOSTCFLAGS+=-I. -I${.CURDIR} -DHAS_ISBLANK -DNDEBUG

# XXX: replace with make depends
lex.o b.o main.o tran.o run.o parse.o lib.o : ytab.h

# XXX: add BUILDFIRST to mk/prog.bsd.mk
BUILDFIRST = ytab.h

ytab.c: awkgram.y
	@echo ${YACC} -d awkgram.y
	@${YACC} -d ${.CURDIR}/awkgram.y
	@mv y.tab.c ytab.c

ytab.h: ytab.c
	@mv y.tab.h ytab.h

proctab.c: maketab
	./maketab >proctab.c

maketab: ytab.h maketab.c
	@echo ${HOSTCC} maketab.c -o $(@F)
	@${HOSTCC} ${HOSTCFLAGS} ${.CURDIR}/maketab.c -o $@

include ${.TOPDIR}/mk/bsd.prog.mk
