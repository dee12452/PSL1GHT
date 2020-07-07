#include "init.h"
#include <net/net.h>
#include <select.h>

int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *errorfds, struct timeval *timeout)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }
    return netErrno(netSelect(nfds, readfds, writefds, errorfds, timeout));
}