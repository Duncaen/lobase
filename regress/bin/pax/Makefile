# $OpenBSD: Makefile,v 1.6 2006/07/21 22:59:05 ray Exp $

REGRESS_TARGETS=t1 t2 t3 t4 t5 t6
CLEANFILES=$(REGRESS_TARGETS:%=%.tar)

$(REGRESS_TARGETS):
	$(SHELL) ${.CURDIR}/$@.sh ${.CURDIR} ${.OBJDIR}

.PHONY: ${REGRESS_TARGETS}

include ${.TOPDIR}/mk/bsd.regress.mk
