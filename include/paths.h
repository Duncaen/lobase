/*	$OpenBSD: paths.h,v 1.25 2014/03/13 15:24:41 tedu Exp $	*/
/*	$NetBSD: paths.h,v 1.7 1994/10/26 00:56:12 cgd Exp $	*/

/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)paths.h	8.1 (Berkeley) 6/2/93
 */

#ifndef _COMPAT_PATHS_H_
#define	_COMPAT_PATHS_H_

#include_next <paths.h>

/* Default search path. */
#ifndef _PATH_DEFPATH
# define	_PATH_DEFPATH	"/usr/bin:/bin:/usr/sbin:/sbin:/usr/X11R6/bin:/usr/local/bin"
#endif

/* All standard utilities path. */
#ifndef _PATH_STDPATH
# define	_PATH_STDPATH	"/usr/bin:/bin:/usr/sbin:/sbin:/usr/X11R6/bin:/usr/local/bin"
#endif

#ifndef _PATH_BSHELL
# define	_PATH_BSHELL	"/bin/sh"
#endif
#ifndef _PATH_CONSOLE
# define	_PATH_CONSOLE	"/dev/console"
#endif
#ifndef _PATH_CSHELL
# define	_PATH_CSHELL	"/bin/csh"
#endif
#ifndef _PATH_DEFTAPE
# define	_PATH_DEFTAPE	"/dev/rst0"
#endif
#ifndef _PATH_DEVDB
# define	_PATH_DEVDB	"/var/run/dev.db"
#endif
#ifndef _PATH_DEVNULL
# define	_PATH_DEVNULL	"/dev/null"
#endif
#ifndef _PATH_FSIRAND
# define	_PATH_FSIRAND	"/sbin/fsirand"
#endif
#ifndef _PATH_KLOG
# define _PATH_KLOG      "/dev/klog"
#endif
#ifndef _PATH_KMEM
# define	_PATH_KMEM	"/dev/kmem"
#endif
#ifndef _PATH_KSHELL
# define	_PATH_KSHELL	"/bin/ksh"
#endif
#ifndef _PATH_KSYMS
# define	_PATH_KSYMS	"/dev/ksyms"
#endif
#ifndef _PATH_KVMDB
# define	_PATH_KVMDB	"/var/db/kvm_bsd.db"
#endif
#ifndef _PATH_LOCALE
# define	_PATH_LOCALE	"/usr/share/locale"
#endif
#ifndef _PATH_LOGCONF
# define _PATH_LOGCONF   "/etc/syslog.conf"
#endif
#ifndef _PATH_LOGPID
# define _PATH_LOGPID    "/var/run/syslog.pid"
#endif
#ifndef _PATH_MAILDIR
# define	_PATH_MAILDIR	"/var/mail"
#endif
#ifndef _PATH_MAN
# define	_PATH_MAN	"/usr/share/man"
#endif
#ifndef _PATH_MEM
# define	_PATH_MEM	"/dev/mem"
#endif
#ifndef _PATH_NOLOGIN
# define	_PATH_NOLOGIN	"/etc/nologin"
#endif
#ifndef _PATH_RSH
# define	_PATH_RSH	"/usr/bin/ssh"
#endif
#ifndef _PATH_SENDMAIL
# define	_PATH_SENDMAIL	"/usr/sbin/sendmail"
#endif
#ifndef _PATH_SHELLS
# define	_PATH_SHELLS	"/etc/shells"
#endif
#ifndef _PATH_TTY
# define	_PATH_TTY	"/dev/tty"
#endif
#ifndef _PATH_UNIX
# define	_PATH_UNIX	"/bsd"
#endif
#ifndef _PATH_VI
# define	_PATH_VI	"/usr/bin/vi"
#endif


/* Provide trailing slash, since mostly used for building pathnames. */
#ifndef _PATH_BOOTDIR
# define _PATH_BOOTDIR	"/usr/mdec/"
#endif
#ifndef _PATH_DEV
# define	_PATH_DEV	"/dev/"
#endif
#ifndef _PATH_DEVFD
# define	_PATH_DEVFD	"/dev/fd/"
#endif
#ifndef _PATH_TMP
# define	_PATH_TMP	"/tmp/"
#endif
#ifndef _PATH_UUCPLOCK
# define	_PATH_UUCPLOCK	"/var/spool/lock/"
#endif
#ifndef _PATH_VARDB
# define	_PATH_VARDB	"/var/db/"
#endif
#ifndef _PATH_VAREMPTY
# define	_PATH_VAREMPTY	"/var/empty/"
#endif
#ifndef _PATH_VARRUN
# define	_PATH_VARRUN	"/var/run/"
#endif
#ifndef _PATH_VARTMP
# define	_PATH_VARTMP	"/var/tmp/"
#endif

#endif /* !_PATHS_H_ */
