#ifndef QTHREAD_DEBUG_H
#define QTHREAD_DEBUG_H

#ifdef QTHREAD_DEBUG
# define DEBUG_ONLY(x) x

/* System headers */
# include <limits.h>      // for INT_MAX, per C89
# include <sys/syscall.h> // for syscall()
# include <unistd.h>      // for SYS_write
# include <stdarg.h>      // for va_start and friends

/* Internal headers */
# include <qt_locks.h>
# include <qthread_asserts.h>

enum qthread_debug_levels {
    NO_DEBUG_OUTPUT = 0,
    DEBUG_CALLS     = 1,
    DEBUG_FUNCTIONS = 3,
    DEBUG_BEHAVIOR  = 7,
    DEBUG_DETAILS   = 15,
    ALWAYS_OUTPUT   = INT_MAX,
};
extern enum qthread_debug_levels debuglevel;

# ifdef QTHREAD_DEBUG_AFFINITY
#  define AFFINITY_CALLS     DEBUG_CALLS
#  define AFFINITY_FUNCTIONS DEBUG_FUNCTIONS
#  define AFFINITY_BEHAVIOR  DEBUG_BEHAVIOR
#  define AFFINITY_DETAILS   DEBUG_DETAILS
# else
#  define AFFINITY_BEHAVIOR  NO_DEBUG_OUTPUT
#  define AFFINITY_CALLS     NO_DEBUG_OUTPUT
#  define AFFINITY_FUNCTIONS NO_DEBUG_OUTPUT
#  define AFFINITY_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_THREADQUEUES
#  define THREADQUEUE_BEHAVIOR  DEBUG_BEHAVIOR
#  define THREADQUEUE_CALLS     DEBUG_CALLS
#  define THREADQUEUE_FUNCTIONS DEBUG_FUNCTIONS
#  define THREADQUEUE_DETAILS   DEBUG_DETAILS
# else
#  define THREADQUEUE_BEHAVIOR  NO_DEBUG_OUTPUT
#  define THREADQUEUE_CALLS     NO_DEBUG_OUTPUT
#  define THREADQUEUE_FUNCTIONS NO_DEBUG_OUTPUT
#  define THREADQUEUE_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_CORE
#  define CORE_BEHAVIOR  DEBUG_BEHAVIOR
#  define CORE_CALLS     DEBUG_CALLS
#  define CORE_FUNCTIONS DEBUG_FUNCTIONS
#  define CORE_DETAILS   DEBUG_DETAILS
# else
#  define CORE_BEHAVIOR  NO_DEBUG_OUTPUT
#  define CORE_CALLS     NO_DEBUG_OUTPUT
#  define CORE_FUNCTIONS NO_DEBUG_OUTPUT
#  define CORE_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_THREADS
#  define THREAD_BEHAVIOR  DEBUG_BEHAVIOR
#  define THREAD_CALLS     DEBUG_CALLS
#  define THREAD_FUNCTIONS DEBUG_FUNCTIONS
#  define THREAD_DETAILS   DEBUG_DETAILS
# else
#  define THREAD_BEHAVIOR  NO_DEBUG_OUTPUT
#  define THREAD_CALLS     NO_DEBUG_OUTPUT
#  define THREAD_FUNCTIONS NO_DEBUG_OUTPUT
#  define THREAD_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_SYSCALLS
#  define SYSCDEBUG_BEHAVIOR  DEBUG_BEHAVIOR
#  define SYSCDEBUG_CALLS     DEBUG_CALLS
#  define SYSCDEBUG_FUNCTIONS DEBUG_FUNCTIONS
#  define SYSCDEBUG_DETAILS   DEBUG_DETAILS
# else
#  define SYSCDEBUG_BEHAVIOR  NO_DEBUG_OUTPUT
#  define SYSCDEBUG_CALLS     NO_DEBUG_OUTPUT
#  define SYSCDEBUG_FUNCTIONS NO_DEBUG_OUTPUT
#  define SYSCDEBUG_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_LOCKS
#  define LOCK_BEHAVIOR  DEBUG_BEHAVIOR
#  define LOCK_CALLS     DEBUG_CALLS
#  define LOCK_FUNCTIONS DEBUG_FUNCTIONS
#  define LOCK_DETAILS   DEBUG_DETAILS
# else
#  define LOCK_BEHAVIOR  NO_DEBUG_OUTPUT
#  define LOCK_CALLS     NO_DEBUG_OUTPUT
#  define LOCK_FUNCTIONS NO_DEBUG_OUTPUT
#  define LOCK_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_FEBS
#  define FEB_BEHAVIOR  DEBUG_BEHAVIOR
#  define FEB_CALLS     DEBUG_CALLS
#  define FEB_FUNCTIONS DEBUG_FUNCTIONS
#  define FEB_DETAILS   DEBUG_DETAILS
# else
#  define FEB_BEHAVIOR  NO_DEBUG_OUTPUT
#  define FEB_CALLS     NO_DEBUG_OUTPUT
#  define FEB_FUNCTIONS NO_DEBUG_OUTPUT
#  define FEB_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_SYNCVARS
#  define SYNCVAR_BEHAVIOR  DEBUG_BEHAVIOR
#  define SYNCVAR_CALLS     DEBUG_CALLS
#  define SYNCVAR_FUNCTIONS DEBUG_FUNCTIONS
#  define SYNCVAR_DETAILS   DEBUG_DETAILS
# else
#  define SYNCVAR_BEHAVIOR  NO_DEBUG_OUTPUT
#  define SYNCVAR_CALLS     NO_DEBUG_OUTPUT
#  define SYNCVAR_FUNCTIONS NO_DEBUG_OUTPUT
#  define SYNCVAR_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_LOOPS
#  define LOOP_BEHAVIOR  DEBUG_BEHAVIOR
#  define LOOP_CALLS     DEBUG_CALLS
#  define LOOP_FUNCTIONS DEBUG_FUNCTIONS
#  define LOOP_DETAILS   DEBUG_DETAILS
# else
#  define LOOP_BEHAVIOR  NO_DEBUG_OUTPUT
#  define LOOP_CALLS     NO_DEBUG_OUTPUT
#  define LOOP_FUNCTIONS NO_DEBUG_OUTPUT
#  define LOOP_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_IO
#  define IO_BEHAVIOR  DEBUG_BEHAVIOR
#  define IO_CALLS     DEBUG_CALLS
#  define IO_FUNCTIONS DEBUG_FUNCTIONS
#  define IO_DETAILS   DEBUG_DETAILS
# else
#  define IO_BEHAVIOR  NO_DEBUG_OUTPUT
#  define IO_CALLS     NO_DEBUG_OUTPUT
#  define IO_FUNCTIONS NO_DEBUG_OUTPUT
#  define IO_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_BARRIER
#  define BARRIER_BEHAVIOR  DEBUG_BEHAVIOR
#  define BARRIER_CALLS     DEBUG_CALLS
#  define BARRIER_FUNCTIONS DEBUG_FUNCTIONS
#  define BARRIER_DETAILS   DEBUG_DETAILS
# else
#  define BARRIER_BEHAVIOR  NO_DEBUG_OUTPUT
#  define BARRIER_CALLS     NO_DEBUG_OUTPUT
#  define BARRIER_FUNCTIONS NO_DEBUG_OUTPUT
#  define BARRIER_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_QARRAY
#  define QARRAY_BEHAVIOR  DEBUG_BEHAVIOR
#  define QARRAY_CALLS     DEBUG_CALLS
#  define QARRAY_FUNCTIONS DEBUG_FUNCTIONS
#  define QARRAY_DETAILS   DEBUG_DETAILS
# else
#  define QARRAY_BEHAVIOR  NO_DEBUG_OUTPUT
#  define QARRAY_CALLS     NO_DEBUG_OUTPUT
#  define QARRAY_FUNCTIONS NO_DEBUG_OUTPUT
#  define QARRAY_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_RCRTOOL
#  define RCRTOOL_BEHAVIOR  DEBUG_BEHAVIOR
#  define RCRTOOL_CALLS     DEBUG_CALLS
#  define RCRTOOL_FUNCTIONS DEBUG_FUNCTIONS
#  define RCRTOOL_DETAILS   DEBUG_DETAILS
# else
#  define RCRTOOL_BEHAVIOR  NO_DEBUG_OUTPUT
#  define RCRTOOL_CALLS     NO_DEBUG_OUTPUT
#  define RCRTOOL_FUNCTIONS NO_DEBUG_OUTPUT
#  define RCRTOOL_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_SHEPHERD
#  define SHEPHERD_BEHAVIOR  DEBUG_BEHAVIOR
#  define SHEPHERD_CALLS     DEBUG_CALLS
#  define SHEPHERD_FUNCTIONS DEBUG_FUNCTIONS
#  define SHEPHERD_DETAILS   DEBUG_DETAILS
# else
#  define SHEPHERD_BEHAVIOR  NO_DEBUG_OUTPUT
#  define SHEPHERD_CALLS     NO_DEBUG_OUTPUT
#  define SHEPHERD_FUNCTIONS NO_DEBUG_OUTPUT
#  define SHEPHERD_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_FUTURELIB
#  define FUTURELIB_BEHAVIOR  DEBUG_BEHAVIOR
#  define FUTURELIB_CALLS     DEBUG_CALLS
#  define FUTURELIB_FUNCTIONS DEBUG_FUNCTIONS
#  define FUTURELIB_DETAILS   DEBUG_DETAILS
# else
#  define FUTURELIB_BEHAVIOR  NO_DEBUG_OUTPUT
#  define FUTURELIB_CALLS     NO_DEBUG_OUTPUT
#  define FUTURELIB_FUNCTIONS NO_DEBUG_OUTPUT
#  define FUTURELIB_DETAILS   NO_DEBUG_OUTPUT
# endif
# ifdef QTHREAD_DEBUG_XOMP
#  define XOMP_BEHAVIOR  DEBUG_BEHAVIOR
#  define XOMP_CALLS     DEBUG_CALLS
#  define XOMP_FUNCTIONS DEBUG_FUNCTIONS
#  define XOMP_DETAILS   DEBUG_DETAILS
# else
#  define XOMP_BEHAVIOR  NO_DEBUG_OUTPUT
#  define XOMP_CALLS     NO_DEBUG_OUTPUT
#  define XOMP_FUNCTIONS NO_DEBUG_OUTPUT
#  define XOMP_DETAILS   NO_DEBUG_OUTPUT
# endif

extern QTHREAD_FASTLOCK_TYPE output_lock;

# ifdef QTHREAD_RCRTOOL
#  ifdef HAVE_GNU_VAMACROS
#   define qthread_debug(level, format, args ...) qthread_debug_(level, debuglevel, "QDEBUG: ", "%s(%u): " format, __FUNCTION__, __LINE__, ## args)
#   define rcrtool_debug(level, format, args ...) qthread_debug_(level, rcrtoollevel, "RCRDEBUG: ", "%s(%u): " format, __FUNCTION__, __LINE__, ## args)
static QINLINE void qthread_debug_(int         level,
                                   int         debuglevel,
                                   const char *msgPrefix,
                                   const char *format,
                                   ...)
#  elif defined(HAVE_C99_VAMACROS)
#   define qthread_debug(level, format, ...) qthread_debug_(level, debuglevel, "QDEBUG: ", "%s(%u): " format, __FUNCTION__, __LINE__, __VA_ARGS__)
#   define rcrtool_debug(level, format, ...) qthread_debug_(level, rcrtoollevel, "RCRDEBUG: ", "%s(%u): " format, __FUNCTION__, __LINE__, __VA_ARGS__)
static QINLINE void qthread_debug_(int         level,
                                   int         debuglevel,
                                   const char *msgPrefix,
                                   const char *format,
                                   ...)
#  else // ifdef HAVE_GNU_VAMACROS
#   define qthread_debug(level, format, ...) qthread_debug_(level, debuglevel, "QDEBUG: ", format, __FUNCTION__, __LINE__, __VA_ARGS__)
#   define rcrtool_debug(level, format, ...) qthread_debug_(level, rcrtoollevel, "RCRDEBUG: ", format, __FUNCTION__, __LINE__, __VA_ARGS__)
static QINLINE void qthread_debug_(int         level,
                                   int         debuglevel,
                                   const char *msgPrefix,
                                   const char *format,
                                   ...)
#  endif // ifdef HAVE_GNU_VAMACROS
# else // ifdef QTHREAD_RCRTOOL
#  ifdef HAVE_GNU_VAMACROS
#   define qthread_debug(level, format, args ...) qthread_debug_(level, "%s(%u): " format, __FUNCTION__, __LINE__, ## args)
static QINLINE void qthread_debug_(int         level,
                                   const char *format,
                                   ...)
#  elif defined(HAVE_C99_VAMACROS)
#   define qthread_debug(level, format, ...) qthread_debug_(level, "%s(%u): " format, __FUNCTION__, __LINE__, __VA_ARGS__)
static QINLINE void qthread_debug_(int         level,
                                   const char *format,
                                   ...)
#  else
static QINLINE void qthread_debug(int         level,
                                  const char *format,
                                  ...)
#  endif // ifdef HAVE_GNU_VAMACROS
# endif  // ifdef QTHREAD_RCRTOOL
{                                      /*{{{ */
    va_list args;

    if (level & debuglevel) {
        static char buf[1024];  /* protected by the output_lock */
        char       *head = buf;
        char        ch;

        QTHREAD_FASTLOCK_LOCK(&output_lock);

# ifdef QTHREAD_RCRTOOL
        while (syscall(SYS_write, 2, msgPrefix, 8) != 8) ;
# else
        while (syscall(SYS_write, 2, "QDEBUG: ", 8) != 8) ;
# endif

        va_start(args, format);
        /* avoiding the obvious method, to save on memory
         * vfprintf(stderr, format, args); */
        while ((ch = *format++)) {
            assert(head < (buf + 1024));
            if (ch == '%') {
                ch = *format++;
                switch (ch) {
                    case 's':
                    {
                        char *str = va_arg(args, char *);

                        qassert(syscall(SYS_write, 2, buf, head - buf), head - buf);
                        head = buf;
                        if (str == NULL) {
                            qassert(syscall(SYS_write, 2, "(null)", 6), 6);
                        } else {
                            qassert(syscall(SYS_write, 2, str, strlen(str)), strlen(str));
                        }
                        break;
                    }
                    case 'p':
                        *head++ = '0';
                        *head++ = 'x';
                        {
                            uintptr_t num;

                            num = va_arg(args, uintptr_t);
                            if (!num) {
                                *head++ = '0';
                            } else {
                                /* count places */
                                unsigned  places = 0;
                                uintptr_t tmpnum = num;

                                /* yes, this is dumb, but its guaranteed to take
                                 * less than 10 iterations on 32-bit numbers and
                                 * doesn't involve floating point */
                                while (tmpnum >= 16) {
                                    tmpnum /= 16;
                                    places++;
                                }
                                head  += places;
                                places = 0;
                                while (num >= 16) {
                                    uintptr_t tmp = num % 16;
                                    *(head - places) =
                                        (tmp <
                                         10) ? ('0' + tmp) : ('a' + tmp - 10);
                                    num /= 16;
                                    places++;
                                }
                                num             %= 16;
                                *(head - places) =
                                    (num < 10) ? ('0' + num) : ('a' + num - 10);
                                head++;
                            }
                        }
                        break;
                    case 'z':
                    {
                        size_t num = va_arg(args, size_t);
                        /* count places */
                        unsigned places = 0;
                        size_t   tmpnum = num;
                        /* yes, this is dumb, but its guaranteed to take
                         * less than 10 iterations on 32-bit numbers and
                         * doesn't involve floating point */
                        while (tmpnum >= 10) {
                            tmpnum /= 10;
                            places++;
                        }
                        head  += places;
                        places = 0;
                        while (num >= 10) {
                            uintptr_t tmp = num % 10;
                            *(head - places) = (tmp < 10) ? ('0' + tmp) : ('a' + tmp - 10);
                            num             /= 10;
                            places++;
                        }
                        num             %= 10;
                        *(head - places) = (num < 10) ? ('0' + num) : ('a' + num - 10);
                        head++;
                        break;
                    }
                    case 'x':
                        *head++ = '0';
                        *head++ = 'x';
                    case 'u':
                    case 'd':
                    case 'i':
                    {
                        unsigned int num;
                        unsigned     base;

                        num  = va_arg(args, unsigned int);
                        base = (ch == 'x') ? 16 : 10;
                        if (!num) {
                            *head++ = '0';
                        } else {
                            /* count places */
                            unsigned  places = 0;
                            uintptr_t tmpnum = num;

                            /* yes, this is dumb, but its guaranteed to take
                             * less than 10 iterations on 32-bit numbers and
                             * doesn't involve floating point */
                            while (tmpnum >= base) {
                                tmpnum /= base;
                                places++;
                            }
                            head  += places;
                            places = 0;
                            while (num >= base) {
                                uintptr_t tmp = num % base;
                                *(head - places) = (tmp < 10) ? ('0' + tmp) : ('a' + tmp - 10);
                                num             /= base;
                                places++;
                            }
                            num             %= base;
                            *(head - places) = (num < 10) ? ('0' + num) : ('a' + num - 10);
                            head++;
                        }
                        break;
                    }
                    case 'X':
                        *head++ = '0';
                        *head++ = 'x';
                    case 'U':
                    case 'D':
                    case 'I':
                    {
                        uint64_t num = va_arg(args, uint64_t);
                        unsigned base;

                        base = (ch == 'X') ? 16 : 10;
                        if (!num) {
                            *head++ = '0';
                        } else {
                            /* count places */
                            unsigned places = 0;
                            uint64_t tmpnum = num;

                            /* yes, this is dumb, but its guaranteed to take
                             * less than 10 iterations on 32-bit numbers and
                             * doesn't involve floating point */
                            while (tmpnum >= base) {
                                tmpnum /= base;
                                places++;
                            }
                            head  += places;
                            places = 0;
                            while (num >= base) {
                                uintptr_t tmp = num % base;
                                *(head - places) = (tmp < 10) ? ('0' + tmp) : ('a' + tmp - 10);
                                num             /= base;
                                places++;
                            }
                            num             %= base;
                            *(head - places) = (num < 10) ? ('0' + num) : ('a' + num - 10);
                            head++;
                        }
                        break;
                    }
                    default:
                        *head++ = '%';
                        *head++ = ch;
                }
            } else {
                *head++ = ch;
            }
        }
        /* XXX: not checking for extra long values of head */
        qassert(syscall(SYS_write, 2, buf, head - buf), head - buf);
        va_end(args);
        /*fflush(stderr); */

        QTHREAD_FASTLOCK_UNLOCK(&output_lock);
    }
}                                      /*}}} */

#else /* ifdef QTHREAD_DEBUG */
# define DEBUG_ONLY(x)
# define qthread_debug(...) do { } while(0)
#endif /* ifdef QTHREAD_DEBUG */

#endif /* QTHREAD_DEBUG_H */
/* vim:set expandtab: */
