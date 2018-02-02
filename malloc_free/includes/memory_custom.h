//
// Created by Guillaume Noailles on 31/01/18.
//
#ifndef MALLOC_FREE_MEMORY_CUSTOM_H
#define MALLOC_FREE_MEMORY_CUSTOM_H

#include <zconf.h>

#define WORD_SIZE (sizeof(unsigned long))
#define WORD_MASK (WORD_SIZE -1)


void* memset_custom(void* dest, int c, size_t n );

void* memcpy_custom(void *dest, void *src, size_t n);

void* memmove_custom(void *dest, void *src, size_t n);

#endif //MALLOC_FREE_MEMORY_CUSTOM_H
