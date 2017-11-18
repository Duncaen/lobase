#	$OpenBSD: Makefile.inc,v 1.29 2016/03/30 06:38:41 jmc Exp $

# compat sources
VPATH+=	${LIBCSRCDIR}/compat

SRCS+=	fgetwln.c

include ${.TOPDIR}/config.mk

ifneq ($(HAVE_FGETLN),1)
SRCS+=	fgetln.c
endif

ifneq ($(HAVE_FREEZERO),1)
SRCS+=	freezero.c
endif

ifneq ($(HAVE_GETDTABLECOUNT),1)
SRCS+=	getdtablecount.c
endif

ifneq ($(HAVE_GETFSSTAT),1)
SRCS+=	getfsstat.c statfs.c
endif
