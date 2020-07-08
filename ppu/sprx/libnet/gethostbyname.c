#include "init.h"
#include <net/net.h>
#include <netdb.h>
#include <sys/lv2errno.h>

struct hostent * gethostbyname(const char *name)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return (struct hostent *) NULL;
    }
    return netGetHostByName(name);
}