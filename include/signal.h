#ifndef _COMPAT_SIGNAL_H_
#define _COMPAT_SIGNAL_H_

#define SIGINFO SIGUSR1

static const char *sys_signame[] = {
	"0",
	"HUP","INT","QUIT","ILL","TRAP","ABRT","BUS","FPE",
	"KILL","USR1","SEGV","USR2","PIPE","ALRM","TERM","STKFLT",
	"CHLD","CONT","STOP","TSTP","TTIN","TTOU","URG","XCPU",
	"XFSZ","VTALRM","PROF","WINCH","POLL","PWR","SYS","32",
	"33","34","35","36","37","38","39","40",
	"41","42","43","44","45","46","47","48",
	"49","50","51","52","53","54","55","56",
	"57","58","59","60","61","62","63","64"
};
#endif /* _COMPAT_SIGNAL_H_ */

#include_next <signal.h>
