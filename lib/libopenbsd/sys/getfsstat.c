#include <sys/mount.h>
#include <sys/stat.h>

#include <stdio.h>
#include <paths.h>
#include <stdlib.h>
#include <mntent.h>
#include <string.h>

int
getfsstat(struct openbsd_statfs *buf, size_t bufsize, int flags)
{
	struct openbsd_statfs *cur;
	struct stat sb;
	struct mntent *m;
	FILE *fp;
	int n, max;

	if (!(fp = setmntent(_PATH_MOUNTED, "r")))
		return -1;

	if (flags == 0)
		flags = MNT_WAIT;

	n = 0;
	max = (bufsize / sizeof (struct openbsd_statfs));
	while ((m = getmntent(fp))) {
		if (!buf || (flags & MNT_NOWAIT)) {
			n++;
			continue;
		}
		if (n+1 >= max)
			break;
		cur = &buf[n++];

		if (!cur->st_dev && stat(m->mnt_dir, &sb) == 0)
			cur->st_dev = sb.st_dev;

		statfs(m->mnt_dir, &cur->buf);
		strlcpy(cur->f_fstypename, m->mnt_type, sizeof (cur->f_fstypename));
		strlcpy(cur->f_mntfromname, m->mnt_fsname, sizeof (cur->f_mntfromname));
		strlcpy(cur->f_mntonname, m->mnt_dir, sizeof (cur->f_mntonname));
	}
	endmntent(fp);

	return n;
}
