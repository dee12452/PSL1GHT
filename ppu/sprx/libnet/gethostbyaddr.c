#include "init.h"
#include <net/net.h>
#include <netdb.h>
#include <sys/lv2errno.h>

struct hostent * gethostbyaddr(const char *addr, socklen_t len, int type)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return (struct hostent *) NULL;
    }
    return netGetHostByAddr(addr, len, type);
}