MAKEFLAGS += -I$(shell pwd)/mk

SUBDIR = libopenbsd bin sbin usr.bin usr.sbin

ifeq (clean,$(filter clean,$(MAKECMDGOALS)))
SUBDIR += regress
endif

all:
clean:
insteall:

regression-tests:
	@echo "Running regression tests..." \
	&& export PATH=$$PWD/dest/bin/:$$PATH SHELL=/bin/oksh \
	&& cd regress \
	&& $(MAKE) depend \
	&& exec $(MAKE) regress

.PHONY: all clean install regression-tests

include mk/bsd.subdir.mk
