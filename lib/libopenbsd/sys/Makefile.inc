#	$OpenBSD: Makefile.inc,v 1.146 2016/07/04 18:01:44 guenther Exp $
#	$NetBSD: Makefile.inc,v 1.35 1995/10/16 23:49:07 jtc Exp $
#	@(#)Makefile.inc	8.1 (Berkeley) 6/17/93

# sys sources
VPATH+=	${LIBCSRCDIR}/sys

include ${.TOPDIR}/config.mk

ifneq ($(HAVE_GETDTABLECOUNT),1)
MAN+=	getdtablecount.2
endif
