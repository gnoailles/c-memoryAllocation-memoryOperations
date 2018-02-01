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

			MEMSET(ptr, 0, block->size);

			try_to_fusion();
		}
	}
}
