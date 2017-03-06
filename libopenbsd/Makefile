include config.mk

CFLAGS += -Wno-attributes -Wno-implicit-int
CPPFLAGS += -I. -Ihidden -include openbsd.h -I.. -include config.h

LIB=libopenbsd.a

SRCS = base64.c closefrom.c errc.c warnc.c execvpe.c explicit_bzero.c fts.c \
	fgetwln.c heapsort.c merge.c pledge-noop.c progname.c \
	qsort.c radixsort.c random.c readpassphrase.c reallocarray.c setmode.c \
	setproctitle.c strlcat.c strlcpy.c strtoimax.c strtonum.c strtoumax.c verrc.c\
	vwarnc.c vis.c unvis.c pwcache.c pw_dup.c getbsize.c \
	strmode.c logwtmp.c crypt/arc4random.c crypt/arc4random_uniform.c \
	crypt/chacha.c crypt/blowfish.c hash/md5.c hash/rmd160.c hash/sha1.c \
	hash/sha2.c

GEN_SRC = hash/md5hl.c hash/rmd160hl.c hash/sha1hl.c hash/sha224hl.c \
	hash/sha256hl.c hash/sha384hl.c hash/sha512hl.c

OBJS = $(SRCS:.c=.o) $(GEN_SRC:.c=.o)

ifndef HAVE_STRLCPY
	SRCS += strlcpy.c
endif

ifndef HAVE_STRLCAT
	SRCS += strlcat.c
endif

ifndef HAVE_ISSETUGID
	SRCS += issetugid.c
endif

ifndef HAVE_FGETLN
	SRCS += fgetln.c
endif

ifndef HAVE_GETENTROPY
	SRCS += getentropy_linux.c
endif

# getentropy_linux.c 

all: $(LIB)

clean:
	rm -f $(GEN_SRC) $(OBJS)

install:

.PHONY: all clean install


$(LIB) : $(OBJS)

getentropy_linux.o : CPPFLAGS += -D_GNU_SOURCE


%.a:
	ar rc $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@


$(GEN_SRC) : % : hash/helper.c
$(GEN_SRC:.c=.o) : %.o :

hash/md5hl.c:
	sed -e 's/hashinc/md5.h/g' -e 's/HASH/MD5/g' hash/helper.c > $@

hash/rmd160hl.c:
	sed -e 's/hashinc/rmd160.h/g' -e 's/HASH/RMD160/g' hash/helper.c > $@

hash/sha1hl.c:
	sed -e 's/hashinc/sha1.h/g' -e 's/HASH/SHA1/g' hash/helper.c > $@

hash/sha224hl.c hash/sha256hl.c hash/sha384hl.c hash/sha512hl.c:
	stem=$@; stem=$${stem#*/sha}; stem=$${stem%hl.c}; \
	sed -e 's/hashinc/sha2.h/g' \
	    -e "s/HASH/SHA$$stem/g" \
	    -e 's/SHA[0-9][0-9][0-9]_CTX/SHA2_CTX/g' \
	    hash/helper.c > $@
