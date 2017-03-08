#include <sys/vfs.h>
#include_next <sys/mount.h>

#ifndef _COMPAT_SYS_MOUNT_H_
#define _COMPAT_SYS_MOUNT_H_

#include <stdlib.h>

#define	MNT_NOWAIT	0x01
#define	MNT_WAIT	0x02
#define	MNT_LOCAL	0x10
#define	MFSNAMELEN	128
#define	MNAMELEN	128

union mount_info {

};

struct openbsd_statfs {
	struct statfs buf;
	dev_t st_dev;
	char f_fstypename[MFSNAMELEN];  /* fs type name */
	char f_mntonname[MNAMELEN];     /* directory on which mounted */
	char f_mntfromname[MNAMELEN];   /* mounted file system */
	char f_mntfromspec[MNAMELEN];   /* special for mount request */
	union mount_info mount_info;    /* per-filesystem mount options */
};

#ifdef	__NEED_OPENBSD_statfs
#define	statfs		openbsd_statfs

#define	f_blocks	buf.f_blocks
#define	f_bsize		buf.f_bsize
#define	f_bfree		buf.f_bfree
#define	f_bavail	buf.f_bavail

#define	f_files		buf.f_files
#define	f_ffree		buf.f_ffree
#define	f_flags		buf.f_flags
#endif	/* !__NEED_OPENBSD_statfs */

int getmntinfo(struct openbsd_statfs **, int);
int getfsstat(struct openbsd_statfs *, size_t, int);
int openbsd_statfs(const char *, struct openbsd_statfs *);

#endif /* _COMPAT_SYS_MOUNT_H_ */
