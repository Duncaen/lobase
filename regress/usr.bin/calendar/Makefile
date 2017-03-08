#	$OpenBSD: Makefile,v 1.2 2016/09/14 16:11:54 tb Exp $

FILES = $(wildcard *.out)
REGRESS_TARGETS=$(FILES:%.out=%)
CALENDAR?=	calendar

$(REGRESS_TARGETS):
	@echo $@
	@${CALENDAR} -f ${.CURDIR}/in -t $@ | diff -u ${.CURDIR}/$@.out -

.PHONY:	${REGRESS_TARGETS}

include ${.TOPDIR}/mk/bsd.regress.mk
