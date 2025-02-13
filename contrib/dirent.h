/*
 * dirrent.h
 *
 *  Created on: 2025年1月21日
 *      Author: xiaodq
 */

#ifndef DIRENT_H
#define DIRENT_H

typedef struct dirstream FDIR;

struct dirent {
    ino_t  d_ino; /* File serial number. */
    char   d_name[]; /* Filename string of entry. */
};

int alphasort(
        const struct dirent **,
        const struct dirent **);

int closedir(FDIR *);

int dirfd(FDIR *);

FDIR *fdopendir(int);

FDIR *opendir(const char *);

struct dirent *readdir(FDIR *);

int  readdir_r(
		FDIR *__restrict,
        struct dirent *__restrict,
        struct dirent **__restrict);

void rewinddir(FDIR *);

int  scandir(
        const char *,
        struct dirent ***,
        int (*)(const struct dirent *),
        int (*)(const struct dirent **, const struct dirent **));

void seekdir(FDIR *, long);

long telldir(FDIR *);

#endif /* DIRENT_H */

