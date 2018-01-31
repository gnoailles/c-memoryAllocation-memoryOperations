//
// Created by Guillaume Noailles on 29/01/18.
//
#ifndef MALLOC_FREE_MALLOC_CUSTOM_H
#define MALLOC_FREE_MALLOC_CUSTOM_H

#include <stdbool.h>
#include <wchar.h>
#include <memdef.h>

typedef struct s_block {
	size_t size;
	struct s_block* next;
	struct s_block* prev;
	bool free;
} t_block;


#define ALIGNED_SIZE(size) (((((size) - 1) >> ALIGN_MASK) << ALIGN_MASK) + BLOCK_ALIGN)


void* malloc_custom(size_t size);
void* calloc_custom(size_t nitems, size_t size);

void initialize_block(t_block* block);

t_block* extend_heap(size_t size);

t_block* find_block(size_t size);
void split_block (t_block* b, size_t size);

void try_to_fusion();

#endif //MALLOC_FREE_MALLOC_CUSTOM_H
