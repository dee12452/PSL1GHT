#include "init.h"
#include <net/net.h>
#include <poll.h>

int poll(struct pollfd fds[],nfds_t nfds,int timeout)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }
    return netErrno(netPoll(fds, nfds, timeout));
}