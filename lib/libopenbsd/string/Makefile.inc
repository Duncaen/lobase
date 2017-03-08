#	$OpenBSD: Makefile.inc,v 1.38 2016/03/30 06:38:41 jmc Exp $

# string sources
VPATH+=	${LIBCSRCDIR}/string

SRCS+=	timingsafe_bcmp.c timingsafe_memcmp.c
MAN+=	timingsafe_bcmp.3

ifneq ($(HAVE_EXPLICIT_BZERO),1)
SRCS+=	explicit_bzero.c
endif

ifneq ($(HAVE_STRLCAT),1)
SRCS+=	strlcat.c
endif

ifneq ($(HAVE_STRLCPY),1)
SRCS+=	strlcpy.c
endif

MAN+=	strlcpy.3
