#include_next <signal.h>

#ifndef _COMPAT_SIGNAL_H_
#define _COMPAT_SIGNAL_H_

#define SIGINFO SIGUSR1

extern const char *const sys_signame[_NSIG];
extern const char *const sys_siglist[_NSIG];

#endif /* _COMPAT_SIGNAL_H_ */
