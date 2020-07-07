#ifndef __NET_INIT_H__
#define __NET_INIT_H__

#include <sys/lv2errno.h>

#define LIBNET_MEMORY_SIZE			0x20000 // 128KB

void* __netMemory;
#define LIBNET_INITIALZED	(__netMemory)

#ifdef __cplusplus
extern "C" {
#endif

s32 netErrno(int ret);

#ifdef __cplusplus
	}
#endif

#endif