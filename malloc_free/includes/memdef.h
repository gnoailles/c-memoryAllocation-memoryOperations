//
// Created by Guillaume Noailles on 31/01/18.
//
#ifndef MALLOC_FREE_MEMDEF_H
#define MALLOC_FREE_MEMDEF_H

#if defined(__x86_64__)
	#define BLOCK_ALIGN 8
	#define ALIGN_MASK 0b0111
#endif
#if defined(__i386__)
	#define BLOCK_ALIGN 4
	#define ALIGN_MASK 0b0011
#endif

#endif //MALLOC_FREE_MEMDEF_H
