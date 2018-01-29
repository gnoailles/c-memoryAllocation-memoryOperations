//
// Created by Guillaume Noailles on 29/01/18.
//
#include <malloc_custom.h>
#include "free_custom.h"

void free_custom(void *ptr)
{
	if(ptr)
	{
		t_block* block = (ptr - sizeof(t_block));
		block->free = true;

		try_to_fusion();
	}
}
