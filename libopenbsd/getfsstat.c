#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <sys/statfs.h>
#include <sys/types.h>
#include <mntent.h>

typedef struct { int32_t val[2]; } obsd_fsid_t;

#define MFSNAMELEN   16 /* length of fs type name, including nul */ 
#define MNAMELEN     90	/* length of buffer for returned name */ 

/* per-filesystem mount options */
union mount_info {
	struct ufs_args ufs_args;
	struct mfs_args mfs_args;
	struct nfs_args nfs_args;
	struct iso_args iso_args;
	struct msdosfs_args msdosfs_args;
	struct ntfs_args ntfs_args;
	struct tmpfs_args tmpfs_args;
	char __align[160];      /* 64-bit alignment and room to grow */
};


struct obsd_statfs {
	u_int32_t       f_flags;        /* copy of mount flags */ 
	u_int32_t       f_bsize;        /* file system block size */ 
	u_int32_t       f_iosize;       /* optimal transfer block size */ 

	/* unit is f_bsize */
	u_int64_t       f_blocks;       /* total data blocks in file system */ 
	u_int64_t       f_bfree;        /* free blocks in fs */ 
	int64_t         f_bavail;       /* free blocks avail to non-superuser */ 

	u_int64_t       f_files;        /* total file nodes in file system */ 
	u_int64_t       f_ffree;        /* free file nodes in fs */ 
	int64_t         f_favail;       /* free file nodes avail to non-root */ 

	u_int64_t       f_syncwrites;   /* count of sync writes since mount */ 
	u_int64_t       f_syncreads;    /* count of sync reads since mount */ 
	u_int64_t       f_asyncwrites;  /* count of async writes since mount */ 
	u_int64_t       f_asyncreads;   /* count of async reads since mount */ 

	obsd_fsid_t          f_fsid;         /* file system id */ 
	u_int32_t       f_namemax;      /* maximum filename length */ 
	uid_t           f_owner;        /* user that mounted the file system */ 
	u_int64_t       f_ctime;        /* last mount [-u] time */ 

	char f_fstypename[MFSNAMELEN];  /* fs type name */ 
	char f_mntonname[MNAMELEN];     /* directory on which mounted */ 
	char f_mntfromname[MNAMELEN];   /* mounted file system */ 
	char f_mntfromspec[MNAMELEN];   /* special for mount request */ 
	union mount_info mount_info;    /* per-filesystem mount options */ 
};

static char linebuf[256];

static int
nummounts(FILE *f)
{
	int rv;

	rv = 0;

	for (;;) {
		fgets(linebuf, sizeof linebuf, f);
		if (ferror(f)) {
			rv = -1;
			break;
		}
		if (!strchr(linebuf, '\n')) {
			errno = ERANGE;
			rv = -1;
			break;
		}
		if (feof(f))
			break;
		rv++;
	}

	return rv;
}

int
statfs(const char *path, struct statfs *buf)
{
	static struct ln_statfs fs;
}

int
getfsstat(struct statfs *buf, size_t bufsize, int flags)
{
	static struct mntent mnt;
	FILE *f;
	int i;

	if (!(f = fopen("/etc/mtab", "r")))
		return -1;

	if(!buf) {
		i = nummounts(f);
		fclose(f);
		return i;
	}

	for (i = 0; i < bufsize; i++) {
		getmntent_r(f, &mnt, linebuf, sizeof linebuf);
	}

	fclose(f);
	return i;
}

int
main()
{
	printf("num %d error %s\n", getfsstat(0, 0, 0), strerror(errno));
}
