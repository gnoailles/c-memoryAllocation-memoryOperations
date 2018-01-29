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
		t_block* ptr = NULL;
		for(ptr = (t_block*)HEAD; ptr->next != NULL; ptr = ptr->next);
		ptr->next = block;
		block->prev = ptr;
		block->next = NULL;
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
	return (t_block*)(sbrk(sizeof(t_block) + size));
}

void* malloc_custom(size_t size)
{
	if(size <= 0)
		return NULL;

	size = (ALIGNED_SIZE(size));
	t_block *block = find_block(size);
	if (block == NULL)
	{
		block = extend_heap(size);
		if (block == (t_block *) -1) return NULL;
		block->size = size;
		initialize_block(block);
	}

	return block + 1;
}

t_block* find_block(size_t size)
{
	if (HEAD != NULL)
	{
		for(t_block* ptr = (t_block*)HEAD; ptr != NULL; ptr = ptr->next)
		{
			if(ptr->size >= size && ptr->free == true)
			{
				split_block(ptr, size);
				return ptr;
			}
		}
	}
	return NULL;
}

void split_block(t_block *b, size_t size)
{
	if (b != NULL && b->size > size + sizeof(t_block))
	{
		t_block* block = b + sizeof(t_block) + size;

		block->size = b->size - size - sizeof(t_block);
		b->size = size;

		if(b->next)
			b->next->prev = block;

		block->next = b->next;
		b->next = block;
		block->prev = b;
		block->free = true;
	}
}

void try_to_fusion()
{
	if (HEAD != NULL)
	{
		for(t_block* ptr = (t_block*)HEAD; ptr != NULL; ptr = ptr->next)
		{
			if(ptr->prev != NULL && ptr->free == true && ptr->prev->free == true)
			{
				ptr->prev->size += sizeof(t_block) + ptr->size;
				if(ptr->next != NULL)
					ptr->next->prev = ptr->prev;

				ptr->prev->next = ptr->next;
			}
		}
	}
}
