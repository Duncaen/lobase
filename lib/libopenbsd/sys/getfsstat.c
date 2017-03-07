#include <sys/mount.h>

#include <stdio.h>
#include <paths.h>
#include <stdlib.h>
#include <mntent.h>
#include <string.h>

/* sys/mount.h defines statfs as openbsd_statfs, here i need the original one */
#undef statfs

int
getfsstat(struct openbsd_statfs *buf, size_t bufsize, int flags)
{
	struct openbsd_statfs *cur;
	struct mntent *m;
	FILE *fp;
	int n, max;

	if (!(fp = setmntent(_PATH_MOUNTED, "r")))
		return -1;

	n = 0;
	max = (bufsize / sizeof (struct openbsd_statfs));
	while ((m = getmntent(fp))) {
		if (!buf) {
			n++;
			continue;
		}
		if (n+1 >= max)
			break;
		cur = &buf[n++];
		statfs(m->mnt_dir, &cur->buf);
		strlcpy(cur->f_fstypename, m->mnt_type, sizeof (cur->f_fstypename));
		strlcpy(cur->f_mntfromname, m->mnt_fsname, sizeof (cur->f_mntfromname));
		strlcpy(cur->f_mntonname, m->mnt_dir, sizeof (cur->f_mntonname));
	}
	endmntent(fp);

	return n;
}
