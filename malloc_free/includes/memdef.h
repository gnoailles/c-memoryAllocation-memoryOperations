//
// Created by Guillaume Noailles on 31/01/18.
//
#ifndef MALLOC_FREE_MEMDEF_H
#define MALLOC_FREE_MEMDEF_H

#if defined(__x86_64__)
	#define BLOCK_ALIGN 8
	#define ALIGN_MASK 0b0111
	#define ALIGNED_SIZE(size) (((((size) - 1) >> 3) << 3) + BLOCK_ALIGN)
#endif
#if defined(__i386__)
	#define BLOCK_ALIGN 4
	#define ALIGN_MASK 0b0011
	#define ALIGNED_SIZE(size) (((((size) - 1) >> 2) << 2) + BLOCK_ALIGN)
#endif

#endif //MALLOC_FREE_MEMDEF_H
