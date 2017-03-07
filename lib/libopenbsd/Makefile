LIB=openbsd
CPPFLAGS += -I. -Ihidden -include openbsd.h -I.. -include config.h

GEN_SRCS = hash/md5hl.c hash/rmd160hl.c hash/sha1hl.c hash/sha224hl.c \
					 hash/sha256hl.c hash/sha384hl.c hash/sha512hl.c

CLEANFILES+=$(GEN_SRCS)

SRCS = base64.c closefrom.c \
	heapsort.c merge.c pledge-noop.c progname.c \
	qsort.c radixsort.c random.c readpassphrase.c \
	setproctitle.c strtoimax.c strtonum.c strtoumax.c \
	vis.c unvis.c pwcache.c pw_dup.c getbsize.c \
	strmode.c logwtmp.c crypt/arc4random.c crypt/arc4random_uniform.c \
	crypt/chacha.c crypt/blowfish.c hash/md5.c hash/rmd160.c hash/sha1.c \
	hash/sha2.c $(GEN_SRCS)

SRCS += gen/errc.c gen/fts.c gen/warnc.c gen/verrc.c gen/vwarnc.c gen/setmode.c\
SRCS += stdio/fgetwln.c

include config.mk

ifneq ($(HAVE_EXPLICIT_BZERO),1)
	SRCS += string/explicit_bzero.c
endif

ifneq ($(HAVE_REALLOCARRAY),1)
	SRCS += stdlib/reallocarray.c
endif

ifneq ($(HAVE_STRLCPY),1)
	SRCS += string/strlcpy.c
endif

ifneq ($(HAVE_STRLCAT),1)
	SRCS += string/strlcat.c
endif

ifneq ($(HAVE_ISSETUGID),1)
	SRCS += issetugid.c
endif

ifneq ($(HAVE_FGETLN),1)
	SRCS += stdio/fgetln.c
endif

ifneq ($(HAVE_GETENTROPY),1)
	SRCS += getentropy_linux.c
getentropy_linux.o : CPPFLAGS += -D_GNU_SOURCE
endif

ifneq ($(HAVE_GETDTABLECOUNT),1)
	SRCS += sys/getdtablecount.c
endif

$(GEN_SRCS) : % : hash/helper.c

hash/sha1hl.c:
	sed -e 's/hashinc/sha1.h/g;s/HASH/SHA1/g' hash/helper.c > $@

hash/sha%hl.c:
	sed -e 's/hashinc/sha2.h/g;s/HASH_CTX/SHA2_CTX/g' \
	    -e 's/HASH/SHA$*/g' hash/helper.c > $@

hash/md5hl.c:
	sed -e "s/hashinc/md5.h/g;s/HASH/MD5/g" hash/helper.c > $@

hash/rmd160hl.c:
	sed -e "s/hashinc/rmd160.h/g;s/HASH/RMD160/g" hash/helper.c > $@


include bsd.lib.mk
