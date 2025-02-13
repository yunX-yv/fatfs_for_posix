/*
 * limits.h
 *
 *  Created on: 2025年1月21日
 *      Author: xiaodq
 */
#ifndef LIMITS_H
#define LIMITS_H

#include_next <limits.h>

#ifndef OPEN_MAX
#  ifdef _POSIX_OPEN_MAX
#    define OPEN_MAX _POSIX_OPEN_MAX
#  else
#    define OPEN_MAX 20
#  endif
#endif

#ifndef NAME_MAX
#  ifdef _POSIX_NAME_MAX
#    define NAME_MAX _POSIX_NAME_MAX
#  else
#    define NAME_MAX 12 /* 8+1+3 like FILENAME.EXT */
#  endif
#endif

#ifndef TIMER_MAX
#  ifdef _POSIX_TIMER_MAX
#    define TIMER_MAX _POSIX_TIMER_MAX
#  else
#    define TIMER_MAX 32
#  endif
#endif

#ifndef SIGQUEUE_MAX
#  ifdef _POSIX_SIGQUEUE_MAX
#    define SIGQUEUE_MAX _POSIX_SIGQUEUE_MAX
#  else
#    define SIGQUEUE_MAX 32
#  endif
#endif

#endif

