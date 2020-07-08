#include "init.h"
#include <net/net.h>
#include <arpa/inet.h>
#include <sys/lv2errno.h>

const char * inet_ntop(int af, const void* src, char* dst, socklen_t size)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return (char *) NULL;
    }
    
    switch(af)
    {
        case AF_INET:
            return netInetNtop(af, src, dst, size);
        case AF_INET6:
            /* TODO: Implement support for IPV6 */
            errno = EAFNOSUPPORT;
            return (char *) NULL;
        default:
            errno = EAFNOSUPPORT;
            return (char *) NULL;
    }
}