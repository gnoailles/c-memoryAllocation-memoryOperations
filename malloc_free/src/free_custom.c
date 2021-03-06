//
// Created by Guillaume Noailles on 29/01/18.
//
#include <malloc_custom.h>
#include <memory_custom.h>
#include <free_custom.h>
#include <zconf.h>

void free_custom(void *ptr)
{
	if(ptr != NULL)
	{
		t_block* block = (t_block*)ptr - 1;
		if (valid_block(block))
		{

			block->free = true;

			memset_custom(ptr, 0, block->size);

			fusion_all();
		}
	}
}
