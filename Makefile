SUBDIRS = libopenbsd bin sbin usr.bin usr.sbin

all:

clean:
	PATH=$$PWD/dest/bin/:$$PATH $(MAKE) -I$(SRCDIR) -C regress clean

check:
	PATH=$$PWD/dest/bin/:$$PATH $(MAKE) -I$(SRCDIR) -C regress SRCDIR=$(SRCDIR) SHELL=/bin/oksh

insteall:

include mk/subdirs.mk

.PHONY: all clean check install
