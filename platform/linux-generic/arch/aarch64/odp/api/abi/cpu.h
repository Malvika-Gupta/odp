/* Copyright (c) 2016-2018, Linaro Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#ifndef ODP_API_ABI_CPU_H_
#define ODP_API_ABI_CPU_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <odp/autoheader_external.h>

#ifndef ODP_CACHE_LINE_SIZE
	#define ODP_CACHE_LINE_SIZE _ODP_CACHE_LINE_SIZE
#endif

static inline void odp_cpu_pause(void)
{
	/* YIELD hints the CPU to switch to another thread if possible
	 * and executes as a NOP otherwise.
	 * ISB flushes the pipeline, then restarts. This is guaranteed to
	 * stall the CPU a number of cycles.
	 */
	__asm volatile("isb" ::: "memory");
}

#ifdef __cplusplus
}
#endif

#endif
