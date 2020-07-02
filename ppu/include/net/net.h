#ifndef __LV2_NET_H__
#define __LV2_NET_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <net_init.h>
#include <socket.h>
#include <poll.h>
#include <netdb.h>
#include <netinet/in.h>

#define	NET_EPERM			1
#define	NET_ENOENT			2
#define	NET_ESRCH			3
#define	NET_EINTR			4
#define	NET_EIO				5
#define	NET_ENXIO			6
#define	NET_E2BIG			7
#define	NET_ENOEXEC			8
#define	NET_EBADF			9
#define	NET_ECHILD			10
#define	NET_EDEADLK			11
#define	NET_ENOMEM			12
#define	NET_EACCES			13
#define	NET_EFAULT			14
#define	NET_ENOTBLK			15
#define	NET_EBUSY			16
#define	NET_EEXIST			17
#define	NET_EXDEV			18
#define	NET_ENODEV			19
#define	NET_ENOTDIR			20
#define	NET_EISDIR			21
#define	NET_EINVAL			22
#define	NET_ENFILE			23
#define	NET_EMFILE			24
#define	NET_ENOTTY			25
#define	NET_ETXTBSY			26
#define	NET_EFBIG			27
#define	NET_ENOSPC			28
#define	NET_ESPIPE			29
#define	NET_EROFS			30
#define	NET_EMLINK			31
#define	NET_EPIPE			32
#define	NET_EDOM			33
#define	NET_ERANGE			34
#define	NET_EAGAIN			35
#define	NET_EWOULDBLOCK		NET_EAGAIN
#define	NET_EINPROGRESS		36
#define	NET_EALREADY		37
#define	NET_ENOTSOCK		38
#define	NET_EDESTADDRREQ	39
#define	NET_EMSGSIZE		40
#define	NET_EPROTOTYPE		41
#define	NET_ENOPROTOOPT		42
#define	NET_EPROTONOSUPPORT	43
#define	NET_ESOCKTNOSUPPORT	44
#define	NET_EOPNOTSUPP		45
#define	NET_EPFNOSUPPORT	46
#define	NET_EAFNOSUPPORT	47
#define	NET_EADDRINUSE		48
#define	NET_EADDRNOTAVAIL	49
#define	NET_ENETDOWN		50
#define	NET_ENETUNREACH		51
#define	NET_ENETRESET		52
#define	NET_ECONNABORTED	53
#define	NET_ECONNRESET		54
#define	NET_ENOBUFS			55
#define	NET_EISCONN			56
#define	NET_ENOTCONN		57
#define	NET_ESHUTDOWN		58
#define	NET_ETOOMANYREFS	59
#define	NET_ETIMEDOUT		60
#define	NET_ECONNREFUSED	61
#define	NET_ELOOP			62
#define	NET_ENAMETOOLONG	63
#define	NET_EHOSTDOWN		64
#define	NET_EHOSTUNREACH	65
#define	NET_ENOTEMPTY		66
#define	NET_EPROCLIM		67
#define	NET_EUSERS			68
#define	NET_EDQUOT			69
#define	NET_ESTALE			70
#define	NET_EREMOTE			71
#define	NET_EBADRPC			72
#define	NET_ERPCMISMATCH	73
#define	NET_EPROGUNAVAIL	74
#define	NET_EPROGMISMATCH	75
#define	NET_EPROCUNAVAIL	76
#define	NET_ENOLCK			77
#define	NET_ENOSYS			78
#define	NET_EFTYPE			79
#define	NET_EAUTH			80
#define	NET_ENEEDAUTH		81
#define	NET_EIDRM			82
#define	NET_ENOMSG			83
#define	NET_EOVERFLOW		84
#define	NET_EILSEQ			85
#define	NET_ENOTSUP			86
#define	NET_ECANCELED		87
#define	NET_EBADMSG			88
#define	NET_ENODATA			89
#define	NET_ENOSR			90
#define	NET_ENOSTR			91
#define	NET_ETIME			92
#define	NET_ELAST			92

#define net_errno			(*netErrnoLoc())
#define net_h_errno			(*netHErrnoLoc())

struct netInitParam
{
	uint32_t memory;
	uint32_t memory_size;
	int32_t flags;
};

int32_t netInitialize();
int32_t netDeinitialize();

int32_t* netErrnoLoc();
int32_t* netHErrnoLoc();

int32_t netInitializeNetworkEx(struct netInitParam* param);
int32_t netFinalizeNetwork();
int32_t netShowIfConfig();
int32_t netShowNameServer();
int32_t netShowRoute();

int32_t netAccept(int32_t socket,const struct sockaddr* address,socklen_t* address_len);
int32_t netBind(int32_t socket,const struct sockaddr* address,socklen_t address_len);
int32_t netConnect(int32_t socket,const struct sockaddr* address,socklen_t address_len);
int32_t netListen(int32_t socket,int32_t backlog);
int32_t netSocket(int32_t domain,int32_t type,int32_t protocol);
int32_t netClose(int32_t socket);
int32_t netShutdown(int32_t socket,int32_t how);

ssize_t netRecv(int32_t socket,void *buffer,size_t len,int32_t flags);
ssize_t netRecvFrom(int32_t socket,void *buffer,size_t len,int32_t flags,struct sockaddr* from,socklen_t* fromlen);
ssize_t netRecvMsg(int32_t socket,struct msghdr *msg,int32_t flags);
ssize_t netSend(int32_t socket,const void *buffer,size_t len,int32_t flags);
ssize_t netSendTo(int32_t socket,const void *buffer,size_t len,int32_t flags,const struct sockaddr* dest_addr,socklen_t dest_len);
ssize_t netSendMsg(int32_t socket,const struct msghdr *msg,int32_t flags);

int32_t netPoll(struct pollfd *fds,nfds_t nfds,int32_t timeout);
int32_t netSelect(int32_t nfds,fd_set *readfds,fd_set *writefds,fd_set *errorfds,struct timeval *timeout);
int32_t netGetSockName(int32_t socket,struct sockaddr *address,socklen_t *address_len);
int32_t netGetPeerName(int32_t socket,struct sockaddr *address,socklen_t *address_len);

int32_t netGetSockOpt(int32_t socket,int32_t level,int32_t option_name,void *option_value,socklen_t *option_len);
int32_t netSetSockOpt(int32_t socket,int32_t level,int32_t option_name,const void *option_value,socklen_t option_len);

struct hostent * netGetHostByAddr(const char *addr,socklen_t len,int32_t type);
struct hostent * netGetHostByName(const char *name);

in_addr_t netInetAddr(const char* cp);
int netInetAton(const char* cp, struct in_addr* inp);
in_addr_t netInetLnaof(struct in_addr in);
struct in_addr netInetMakeaddr(in_addr_t net, in_addr_t lna);
in_addr_t netInetNetof(struct in_addr in);
in_addr_t netInetNetwork(const char* cp);
char * netInetNtoa(struct in_addr in);
const char * netInetNtop(int af, const void* src, char* dst, socklen_t size);
int netInetPton(int af, const char* src, void* dst);

#ifdef __cplusplus
	}
#endif

#endif
