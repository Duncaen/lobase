#	$OpenBSD: Makefile.inc,v 1.59 2016/03/30 06:38:41 jmc Exp $

# net sources
VPATH+=	${LIBCSRCDIR}/net

CPPCFLAGS+=-DRESOLVSORT

SRCS+=	base64.c
