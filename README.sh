cat <<!
lobase
======

lobase is a port of the OpenBSD userland to Linux.

Caution
-------

There are subtle differences in GNU coreutils and the OpenBSD userland,
replacing coreutils on Linux system without caution will result in
issues with varying impact.

If you build your own linux system from the ground up and you know that
your scripts are all portable you can use lobase as main coreutils.

Otherwise I suggest to use a prefixed installation and adding lobase to
your users shell \`PATH\`.

Installation
------------

	$ autoreconf -fi
	$ ./configure
	$ make
	# make install

To speed up the compilation use multiple make jobs:

	$ MAKE_JOBS=\$(cat /proc/cpuinfo|grep processor|wc -l)
	$ make -j"\$MAKE_JOBS"
	# make -j"\$MAKE_JOBS" install


Prefix Installation
-------------------

You can install lobase into its own prefix and then use the \`PATH\`
environment variable to prefer lobases binaries over the default
coreutils for your users shell.

	$ ./configure --prefix=/usr/local/lobase

Build and install lobase and then add lobases bin and sbin directories
to your path.
To make this permanent, set \`PATH\` in your shell profile.

	$ PATH=/usr/local/lobase/bin:/usr/local/lobase/sbin:\$PATH

Simple test to verify that lobase is used:

	$ which which
	/usr/local/lobase/bin/which


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
