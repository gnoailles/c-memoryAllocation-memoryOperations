//
// Created by Guillaume Noailles on 29/01/18.
//
#include <malloc_custom.h>
#include <memset_custom.h>
#include <free_custom.h>

void free_custom(void *ptr)
{
	if(ptr)
	{
		t_block* block = (t_block*)ptr - 1;
		block->free = true;

		MEMSET(ptr, 0, block->size);

		try_to_fusion();
	}
}
