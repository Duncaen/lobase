SUBDIRS = cat chmod cp date dd df domainname echo ed expr hostname kill ln ls \
					md5 mkdir mv pax pwd rm rmdir sleep stty sync test

BROKEN = df

all:

include ../mk/subdirs.mk

$(BROKEN):
	@echo "skipping $@"
	@true
