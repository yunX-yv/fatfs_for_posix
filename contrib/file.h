/*
 * fatfs.h
 *
 *  Created on: 2025年1月21日
 *      Author: xiaodq
 */
#ifndef SYSCALLS_H
#define SYSCALLS_H

#include <sys/types.h>
#include <sys/stat.h>

struct fd {
    int fd;
    struct stat stat;
    int isatty;
    int isopen;
    int (*write)(int, char*, int);
    int (*read)(int, char*, int);
    int (*close)(int);
    short (*poll)(int);
    int isallocated;
    int descriptor_flags;
    int status_flags;
    void *opaque;
};

extern
struct fd *file_struct_get(int fd);

extern
int file_alloc(void);

extern
void file_free(int fd);

#endif

