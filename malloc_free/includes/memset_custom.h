//
// Created by Guillaume Noailles on 31/01/18.
//
#ifndef MALLOC_FREE_MEMSET_CUSTOM_H
#define MALLOC_FREE_MEMSET_CUSTOM_H

#include <stddef.h>

#if defined(__x86_64__)
	#define MEMSET(dest, ch, size) (((size) >= 64)? memset_word64((dest),(ch),(size)) : memset_char((dest),(ch),(size)))
#endif
#if defined(__i386__)
	#define MEMSET(dest, ch, size) (((size) >= 32)? memset_word32((dest),(ch),(size)) : memset_char((dest),(ch),(size)))
#endif


void* memset_char(void* dest, int ch, size_t count );
void* memset_word32(void* dest, int ch, size_t count );
void* memset_word64(void* dest, int ch, size_t count );

#endif //MALLOC_FREE_MEMSET_CUSTOM_H
