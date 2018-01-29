//
// Created by Guillaume Noailles on 29/01/18.
//
#ifndef MALLOC_FREE_MALLOC_CUSTOM_H
#define MALLOC_FREE_MALLOC_CUSTOM_H

#include <stdbool.h>
#include <wchar.h>

#define ALIGNED_SIZE(size) (((size) % 4 == 0) ? (size) : ((size) + 4 - ((size) % 4)))

typedef struct s_block {
	size_t size;
	struct s_block* next;
	struct s_block* prev;
	bool free;
} t_block;


void initialize_block(t_block* block);

t_block* extend_heap(size_t size);

t_block* find_block(size_t size);
t_block* split_block (t_block* b, size_t size);

void* malloc_custom(size_t size);

#endif //MALLOC_FREE_MALLOC_CUSTOM_H
