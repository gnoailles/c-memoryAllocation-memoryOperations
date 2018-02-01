//
// Created by Guillaume Noailles on 31/01/18.
//
#ifndef MALLOC_FREE_MEMORY_CUSTOM_H
#define MALLOC_FREE_MEMORY_CUSTOM_H

#include <stddef.h>

#if defined(__x86_64__)
	#define MEMSET(dest, c, size) (((size) >= 64)? memset_word64((dest),(c),(size)) : memset_char((dest),(c),(size)))

	#define MEMCPY(dest, src, size) (((size) >= 64)? memcpy_word64((dest),(src),(size)) : memcpy_char((dest),(src),(size)))

	#define MEMMOVE(dest, src, size) (((size) >= 64)? memmove_word64((dest),(src),(size)) : memmove_char((dest),(src),(size)))

#endif
#if defined(__i386__)
	#define MEMSET(dest, c, size) (((size) >= 32)? memset_word32((dest),(c),(size)) : memset_char((dest),(c),(size)))

	#define MEMCPY(dest, src, size) (((size) >= 32)? memcpy_word32((dest),(src),(size)) : memcpy_char((dest),(src),(size)))

	#define MEMMOVE(dest, src, size) (((size) >= 64)? memmove_word32((dest),(src),(size)) : memmove_char((dest),(src),(size)))
#endif


void* memset_char(void* dest, int c, size_t n );
void* memset_word32(void* dest, int c, size_t n );
void* memset_word64(void* dest, int c, size_t n );

void* memcpy_char(void *dest, void *src, size_t n);
void* memcpy_word32(void *dest, void *src, size_t n);
void* memcpy_word64(void *dest, void *src, size_t n);

void* memmove_char(void *dest, void *src, size_t n);
void* memmove_word32(void *dest, void *src, size_t n);
void* memmove_word64(void *dest, void *src, size_t n);

#endif //MALLOC_FREE_MEMORY_CUSTOM_H
