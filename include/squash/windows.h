/*
 * Copyright (c) 2016-2017 Minqi Pan and Shengyuan Liu
 *
 * This file is part of libsquash, distributed under the MIT License
 * For full terms see the included LICENSE file
 */

#ifndef WINDOWS_H_A80B5674
#define WINDOWS_H_A80B5674

#include <Windows.h>
#include <stdint.h>

typedef unsigned short sqfs_mode_t;
typedef uint32_t sqfs_id_t; /* Internal uids/gids are 32-bits */

typedef SSIZE_T ssize_t;
typedef DWORD64 sqfs_off_t;
typedef uint32_t uid_t;		/* [???] user IDs */

#define	S_IFIFO		0010000		/* [XSI] named pipe (fifo) */
#define	S_IFBLK		0060000		/* [XSI] block special */
#define	S_IFLNK		0120000		/* [XSI] symbolic link */
#define	S_IFSOCK	0140000		/* [XSI] socket */

#define	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)	/* block special */
#define	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)	/* char special */
#define	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)	/* directory */
#define	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)	/* fifo or socket */
#define	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)	/* regular file */
#define	S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)	/* symbolic link */
#define	S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)	/* socket */

#define	makedev(x,y)	((dev_t)(((x) << 24) | (y)))

struct _telldir;

/* structure describing an open directory. */
typedef struct {
	int	dd_fd;	/* file descriptor associated with directory */
	long	dd_loc;	/* offset in current buffer */
	long	dd_size;	/* amount of data returned */
	char	*dd_buf;	/* data buffer */
	int	dd_len;	/* size of data buffer */
	long	dd_seek;	/* magic cookie returned */
	long	dd_rewind;	/* magic cookie for rewinding */
	int	dd_flags;	/* flags for readdir */
	struct _telldir *dd_td; /* telldir position recording */
} DIR;

struct {
	uint64_t  d_ino;      /* file number of entry */ \
	uint64_t  d_seekoff;  /* seek offset (optional, used by servers) */ \
	uint16_t  d_reclen;   /* length of this record */ \
	uint16_t  d_namlen;   /* length of string in d_name */ \
	uint8_t   d_type;     /* file type, see below */ \
	char      d_name[1024]; /* entry name (up to MAXPATHLEN bytes) */ \
} dirent;

#endif /* end of include guard: WINDOWS_H_A80B5674 */