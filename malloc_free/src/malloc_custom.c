//
// Created by Guillaume Noailles on 29/01/18.
//
#include <malloc_custom.h>
#include <zconf.h>

void* HEAD = NULL;

void initialize_block(t_block *block)
{
	if (HEAD != NULL)
	{
		for(t_block* ptr = (t_block*)HEAD; ptr != NULL; ptr = ptr->next)
		{
			if(ptr->next == NULL)
			{
				ptr->next = block;
				block->prev = ptr;
				block->next = NULL;
				break;
			}
		}
	}
	else
	{
		HEAD = block;
		block->prev = NULL;
		block->next = NULL;
	}
	block->free = false;
}

t_block* extend_heap(size_t size)
{
	return sbrk(sizeof(t_block) + size);
}

void* malloc_custom(size_t size)
{
	size = (ALIGNED_SIZE(size));
	t_block* block = find_block(size);
	if(block == NULL)
	{
		block = extend_heap(size);
		block->size = size;
	}

	initialize_block(block);
	return block + 1;
}

t_block* find_block(size_t size)
{
	if (HEAD != NULL)
	{
		for(t_block* ptr = (t_block*)HEAD; ptr != NULL; ptr = ptr->next)
		{
			if(ptr->size >= size && ptr->free == true)
				return ptr;
		}
	}
	return NULL;
}

t_block* split_block(t_block *b, size_t size)
{
	size = ALIGNED_SIZE(size);
	if (b != NULL && b->size >= size + sizeof(t_block))
	{
		t_block* block = b + sizeof(t_block) + size;

		block->size = b->size - size - sizeof(t_block);
		b->size = size;

		if(b->next)
		{
			block->next = b->next;
			b->next->prev = block;
		}
		b->next = block;
		block->prev = b;
		return block;
	}
	return NULL;
}
