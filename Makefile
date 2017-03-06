export TOPDIR := $(shell pwd)

SUBDIR = libopenbsd lib bin sbin usr.bin usr.sbin

ifeq (clean,$(filter clean,$(MAKECMDGOALS)))
SUBDIR += regress
endif

all:
clean:
insteall:

regression-tests:
	@echo "Running regression tests..." \
	&& export PATH=$$PWD/dest/bin/:$$PATH \
	&& cd regress \
	&& $(MAKE) -I$(TOPDIR) -I$(TOPDIR)/mk depend \
	&& exec $(MAKE) -I$(TOPDIR) -I$(TOPDIR)/mk SHELL=/bin/oksh regress

.PHONY: all clean install regression-tests

include mk/bsd.subdir.mk
