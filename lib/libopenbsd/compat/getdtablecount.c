#include <sys/types.h>
#include <dirent.h>

#ifdef __linux__
int
getdtablecount(void)
{
	struct dirent *dp;
	DIR *dir;
	int n;

	/* XXX: return something different? */
	if (!(dir = opendir("/proc/self/fd")))
		return 0;

	n = 0;
	while ((dp = readdir(dir)))
		n++;

	closedir(dir);
	return n;
}
#else
#error getdtablecount(2) not supported
#endif
