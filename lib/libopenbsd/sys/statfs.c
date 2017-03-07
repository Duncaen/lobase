#include <sys/mount.h>

/* sys/mount defines statfs as openbsd_statfs, here i need the original one */
#undef statfs

int openbsd_statfs(const char *path, struct openbsd_statfs *buf)
{
	if (statfs(path, &buf->buf) == -1)
		return -1;

	return 0;
}
