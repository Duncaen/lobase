#include_next <signal.h>

#ifndef _COMPAT_SIGNAL_H_
#define _COMPAT_SIGNAL_H_

#define SIGINFO SIGUSR1

#ifndef _NSIG
# ifdef NSIG
#  define _NSIG NSIG
# else
#  define _NSIG 128
# endif
#endif

#if !HAVE_DECL_SYS_SIGLIST
extern const char *const sys_siglist[_NSIG];
#endif /* !HAVE_DECL_SYS_SIGLIST */

#if !HAVE_DECL_SYS_SIGNAME
extern const char *const sys_signame[_NSIG];
#endif /* !HAVE_DECL_SYS_SIGNAME */

#endif /* _COMPAT_SIGNAL_H_ */
