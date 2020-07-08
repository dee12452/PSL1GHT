#include "init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <socket.h>
#include <net/net.h>
#include <sys/lv2errno.h>

int accept(int socket, struct sockaddr* address, socklen_t* address_len)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }

	s32 ret = 0;
	socklen_t len = address_len ? *address_len : 0;
	socklen_t *lenp = (address && address_len) ? &len : NULL;

    ret = netAccept(socket, address, lenp);

    if(ret<0)
        return netErrno(ret);

    if(lenp)
        *address_len = len;

    return (ret);
}

int bind(int socket, const struct sockaddr* address, socklen_t address_len)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }
    return netErrno(netBind(socket,address,address_len));
}

int connect(int socket, const struct sockaddr* address, socklen_t address_len)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }
	return netErrno(netConnect(socket,address,address_len));
}

int getpeername(int socket, struct sockaddr* address, socklen_t* address_len)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }

	s32 ret = 0;
	socklen_t len = address_len ? *address_len : 0;
	socklen_t *lenp = (address && address_len) ? &len : NULL;

    ret = netGetPeerName(socket,address,lenp);
    
    if(ret<0)
        return netErrno(ret);

    if(lenp)
        *address_len = len;

    return ret;
}

int getsockname(int socket, struct sockaddr* address, socklen_t* address_len)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }

	s32 ret = 0;
	socklen_t len = address_len ? *address_len : 0;
	socklen_t *lenp = (address && address_len) ? &len : NULL;

    ret = netGetSockName(socket,address,lenp);
    
    if(ret<0)
        return netErrno(ret);

    if(lenp)
        *address_len = len;

    return ret;
}

int getsockopt(int socket, int level, int option_name, void* option_value,socklen_t* option_len)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }
	return netErrno(netGetSockOpt(socket,level,option_name,option_value,option_len));
}

int listen(int socket, int backlog)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }
	return netErrno(netListen(socket,backlog));
}

ssize_t recv(int socket, void* buffer, size_t length, int flags)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return (ssize_t) -1;
    }
    return (ssize_t) netErrno(netRecv(socket, buffer, length, flags));
}

ssize_t recvfrom(int socket, void* buffer, size_t length, int flags,struct sockaddr* from, socklen_t* fromlen)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return (ssize_t) -1;
    }

	s32 ret = 0;
	socklen_t len_;
	socklen_t *lenp = (from && fromlen) ? &len_ : NULL;

    ret = netRecvFrom(socket,buffer,length,flags,from,lenp);

    if(ret<0)
        return netErrno(ret);

    if(lenp)
        *fromlen = len_;

    return (ssize_t) ret;
}

ssize_t recvmsg(int socket, struct msghdr* message, int flags)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return (ssize_t) -1;
    }
    return (ssize_t) netErrno(netRecvMsg(socket, message, flags));
}

ssize_t send(int socket, const void* message, size_t length, int flags)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return (ssize_t) -1;
    }
    return (ssize_t) netErrno(netSend(socket, message, length, flags));
}

ssize_t sendto(int socket, const void* message, size_t length, int flags,const struct sockaddr* dest_addr, socklen_t dest_len)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return (ssize_t) -1;
    }
    return (ssize_t) netErrno(netSendTo(socket, message, length, flags, dest_addr, dest_len));
}

ssize_t sendmsg(int socket, const struct msghdr* message, int flags)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return (ssize_t) -1;
    }
    return (ssize_t) netErrno(netSendMsg(socket, message, flags));
}

int setsockopt(int socket, int level, int option_name, const void* option_value,socklen_t option_len)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }
    return netErrno(netSetSockOpt(socket, level, option_name, option_value, option_len));
}

int shutdown(int socket, int how)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }
	return netErrno(netShutdown(socket,how));
}

int socket(int domain, int type, int protocol)
{
    if(!LIBNET_INITIALZED)
    {
        errno = ENOSYS;
        return -1;
    }

	switch (domain)
	{
	case PF_INET:
		return netErrno(netSocket(domain, type, protocol));
	/* TODO: Implement IPV6 support */
	case PF_INET6:
		errno = EAFNOSUPPORT;
		return -1;
	default:
		errno = EAFNOSUPPORT;
		return -1;
	}
}


int socketpair(int domain, int type, int protocol, int socket_vector[2])
{
    errno = EOPNOTSUPP;
    return -1;
}