cat <<!
lobase
======

lobase is a port of the OpenBSD userland to Linux.

Installation
------------

	$ autoreconf -fi
	$ ./configure
	$ make
	# make install

Dependencies
------------

- autoconf
- make (GNU Make)
- cc (gcc, clang)
- yacc (byacc, bison)
- lex (flex)

- libedit (bc)
- libevent (cu)
- libressl
  - libcrypto (bc,dc)
- ncurses (bc,ul)
- zlib (grep)

Debian:

	# apt-get install libedit-dev libevent-dev libssl-dev libz-dev

Void Linux:

	# xbps-install libedit-devel libevent-devel libressl-devel zlib-dev

Not included
------------

Some projects already have portable versions and are not included in lobase.

- acme-client	https://github.com/kristapsdz/acme-client-portable
- cwm		https://github.com/chneukirchen/cwm
- file		https://github.com/brynet/file
- libressl	https://www.libressl.org/
  - nc
- mandoc	http://mandoc.bsd.lv/
  - man
  - apropos
- sndio		http://www.sndio.org/
  - aucat
  - aucatctl
- smtpd		https://www.opensmtpd.org/
- ssh		https://www.openssh.com/

Broken
------

- cu		should be simple to fix
- ftp


TODO
----

- mk/bsd.prog.mk
  - add DPADD support

- mk/bsd.lib.mk
  - install headers
  - build shared libraries?

- usr.bin/tail
  - import, rewrite -F or add a shim for kqueue?

- libtool?

lib
---

liboutil	Parts of OpenBSDs libutil
libopenbsd	Parts of OpenBSDs libc
!

mklist() {
	(
	cd $1
	for f in */; do
		printf '%s' "${f%*/}"
		[ -f "$f/PORT_NOTES" ] && cat "$f/PORT_NOTES"|sed 's/^/	/' || printf '\n'
	done
	) | expand -t 16
}

cat <<!

bin
---

!

mklist bin

cat <<!

sbin
----
!

mklist sbin

cat <<!

usr.bin
-------

!

mklist usr.bin

cat <<!

usr.sbin
--------

!

mklist usr.sbin
