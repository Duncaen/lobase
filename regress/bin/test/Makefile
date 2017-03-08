# $OpenBSD: Makefile,v 1.2 2012/08/21 15:30:48 matthew Exp $

REGRESS_TARGETS=	run_test

run_test:
	$(SHELL) $(.CURDIR)/TEST.sh >/dev/null

include ${.TOPDIR}/mk/bsd.regress.mk
