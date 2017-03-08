#	$OpenBSD: Makefile.inc,v 1.29 2016/03/30 06:38:41 jmc Exp $

# stdio sources
VPATH+=	${LIBCSRCDIR}/stdio

SRCS+=	fgetwln.c

ifneq ($(HAVE_FGETLN),1)
SRCS+=	fgetln.c
endif

MAN+=	fgetwln.3
