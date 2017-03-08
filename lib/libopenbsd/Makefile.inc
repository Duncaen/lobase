#	$OpenBSD: Makefile.inc,v 1.29 2016/05/07 19:05:21 guenther Exp $
#
# This file contains make rules used to build libc
#

ifndef LIBCSRCDIR
all:
	@echo "need to define LIBCSRCDIR" >&2; exit 1
endif

CFLAGS+=-I${LIBCSRCDIR}/include -I${LIBCSRCDIR}/hidden -D__LIBC__ \
	-Werror-implicit-function-declaration -include namespace.h

#.if ${COMPILER_VERSION:L} != "gcc3"
CFLAGS+=-Werror=deprecated-declarations
#.endif

# Include link-time warnings about unsafe API uses (ie. strcpy)
CFLAGS+=-DAPIWARN

include ${LIBCSRCDIR}/gen/Makefile.inc
include ${LIBCSRCDIR}/crypt/Makefile.inc
include ${LIBCSRCDIR}/hash/Makefile.inc
include ${LIBCSRCDIR}/net/Makefile.inc

include ${LIBCSRCDIR}/regex/Makefile.inc
include ${LIBCSRCDIR}/stdio/Makefile.inc
include ${LIBCSRCDIR}/stdlib/Makefile.inc
include ${LIBCSRCDIR}/string/Makefile.inc
include ${LIBCSRCDIR}/sys/Makefile.inc

${OBJS} ${GOBJS} ${POBJS} ${SOBJS} ${DOBJS}: ${LIBCSRCDIR}/include/namespace.h
