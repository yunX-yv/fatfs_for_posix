/*
 * fatfs.h
 *
 *  Created on: 2025年1月21日
 *      Author: xiaodq
 */
#ifndef FATFS_H
#define FATFS_H

#include "dirent.h"

extern
int fatfs_open(const char *pathname, int flags);

extern
int fatfs_close(int fd);

extern
off_t fatfs_lseek(int fd, off_t offset, int whence );

extern
int fatfs_unlink(const char *path);

extern
int fatfs_link(const char *path1, const char *path2);

extern
int fatfs_rename(const char *old, const char *new);

extern
int fatfs_fsync(int fd);

extern
int fatfs_stat(const char *path, struct stat *buf);

extern
int fatfs_mkdir(const char *path, mode_t mode);

extern
int fatfs_rmdir(const char *path);

extern
int fatfs_chdir(const char *path);

extern
char *fatfs_getcwd(char *buf, size_t size);

extern
FDIR *fatfs_opendir(const char *path);

extern
int fatfs_closedir(FDIR *dirp);

extern
struct dirent *fatfs_readdir(FDIR *);

extern
int  fatfs_readdir_r(
		FDIR *__restrict,
        struct dirent *__restrict,
        struct dirent **__restrict);

extern
void fatfs_rewinddir(FDIR *);

extern
long fatfs_telldir(FDIR *);

extern
int fatfs_dirfd(FDIR *);

extern
FDIR *fatfs_fdopendir(int fd);

extern
void fatfs_seekdir(FDIR *, long);

#endif /* FATFS_H */

