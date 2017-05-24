#	$OpenBSD: Makefile.inc,v 1.61 2016/08/14 23:18:03 guenther Exp $

# stdlib sources
VPATH+=	${LIBCSRCDIR}/stdlib

SRCS+=	getopt_long.c
MAN+=	getopt.3 getopt_long.3

ifneq ($(HAVE_REALLOCARRAY),1)
SRCS+=	reallocarray.c recallocarray.c
MAN+=	malloc.3
endif
