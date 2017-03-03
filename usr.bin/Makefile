# dc before bc because it depends on dc.o
SUBDIRS = apply awk basename dc bc biff cal calendar cmp colrm col column comm cut \
					dirname du diff3 diff env expand false fmt fold getopt grep head hexdump id \
					indent join jot lam lndir logger logname look mktemp nice nl nohup \
					paste patch printenv printf readlink renice rev rs sed shar sort \
					split stat tee time touch tr true tty uname unexpand uniq unvis \
					uudecode uuencode vis wc what which xinstall

BROKEN = sed

include ../mk/subdirs.mk

$(BROKEN):
	true
