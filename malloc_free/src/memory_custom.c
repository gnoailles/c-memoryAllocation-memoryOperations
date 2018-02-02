//
// Created by Guillaume Noailles on 31/01/18.
//
#include <memory_custom.h>
#include <stdint.h>
#include <assert.h>
#include <memdef.h>



void* memset_custom(void *dest, int c, size_t n)
{
	if (n == 0)
		return dest;

	assert(!((unsigned long)dest & WORD_MASK));

	unsigned long* ld = (unsigned long*)dest;

	unsigned long x = (unsigned long) (c & 0xFF);
	x |= x << 8;
	x |= x << 16;
	if(WORD_SIZE == 8) x |= x << 32;

	for(;n >= WORD_SIZE * 4; n -= WORD_SIZE * 4)
	{
		*(ld++) = x;
		*(ld++) = x;
		*(ld++) = x;
		*(ld++) = x;
	}

	for(; n >= WORD_SIZE; n -= WORD_SIZE)
	{
		*(ld++) = x;
	}

	unsigned char* cd = (unsigned char*) ld;

	while(n--)
	{
		*(cd++) = (unsigned char)(x & 0xFF);
	}
	return dest;
}



void* memcpy_custom(void *dest, void *src, size_t n)
{
	if (n == 0 || dest == src)
		return dest;

	assert(!((unsigned long)dest & WORD_MASK) && !((long)src & WORD_MASK));

	unsigned long* ld = (unsigned long*)dest;
	unsigned long* ls = (unsigned long*)src;

	for(; n >= WORD_SIZE * 4; n -= WORD_SIZE * 4)
	{
		*(ld++) = *(ls++);
		*(ld++) = *(ls++);
		*(ld++) = *(ls++);
		*(ld++) = *(ls++);
	}

	for(; n >= WORD_SIZE; n -= WORD_SIZE)
	{
		*(ld++) = *(ls++);
	}

	unsigned char* cd = (unsigned char*) ld;
	unsigned char* cs = (unsigned char*) ls;

	while(n--)
	{
		*(cd++) = (unsigned char)(*(cs++) & 0xFF);
	}
	return dest;
}



void *memmove_custom(void *dest, void *src, size_t n)
{
	if (n == 0 || dest == src)
		return dest;

	assert(!((unsigned long)dest & WORD_MASK) && !((unsigned long)src & WORD_MASK));

	unsigned long* ld = (unsigned long*)dest;
	unsigned long* ls = (unsigned long*)src;

	if (ls < ld)
	{
		ld += n / (WORD_SIZE);
		ls += n / (WORD_SIZE);

		for (; n >= WORD_SIZE * 4; n-= WORD_SIZE * 4)
		{
			*(ld--) = *(ls--);
			*(ld--) = *(ls--);
			*(ld--) = *(ls--);
			*(ld--) = *(ls--);
		}
		for (; n >= WORD_SIZE; n-= WORD_SIZE)
		{
			*(ld--) = *(ls--);
		}

		unsigned char* cd = (unsigned char*) ld;
		unsigned char* cs = (unsigned char*) ls;

		while(n--)
		{
			*(cd--) = *(cs--);
		}
	}
	else
	{
		for(; n >= WORD_SIZE * 4; n -= WORD_SIZE * 4)
		{

		}

		for(; n >= WORD_SIZE; n -= WORD_SIZE)
		{
			*(ld++) = *(ls++);
		}

		unsigned char* cd = (unsigned char*) ld;
		unsigned char* cs = (unsigned char*) ls;

		while(n--)
		{
			*(cd++) = (unsigned char)(*(cs++) & 0xFF);
		}
	}

	return dest;
}