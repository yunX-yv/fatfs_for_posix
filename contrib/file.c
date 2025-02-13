/*
 * file.c
 *
 *  Created on: 2025年1月21日
 *      Author: xiaodq
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <file.h>
#include <limits.h>

static
struct fd files[OPEN_MAX];

struct fd *file_struct_get(int fd)
{
    struct fd *f;

    if (fd >= OPEN_MAX)
    {
        f = NULL;
    }
    else
    {
        f = &files[fd];
    }
    return f;
}

int file_alloc(void)
{
    int fd;
    int ret = -1;

    /* starting from 3 because of STDIN, STDOUT, STDERR */
    for (fd = 3; fd < OPEN_MAX; fd++)
    {
        if (!files[fd].isallocated)
        {
            memset(&files[fd], 0, sizeof(files[fd]));
            
            files[fd].isallocated = 1;
            files[fd].fd = fd;
            ret = fd;
            break;
        }
    }
    return ret;
}

void file_free(int fd)
{
    if ((fd < OPEN_MAX) && (fd >= 0) && (files[fd].isallocated))
    {
        files[fd].isallocated = 0;
    }
}

