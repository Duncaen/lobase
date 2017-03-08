#	$OpenBSD: Makefile.inc,v 1.27 2016/03/30 06:38:41 jmc Exp $

VPATH+=	${LIBCSRCDIR}/arch/${MACHINE_CPU}/crypt ${LIBCSRCDIR}/crypt

SRCS+=	arc4random.c arc4random_uniform.c bcrypt.c blowfish.c

MAN+=	blowfish.3 arc4random.3
