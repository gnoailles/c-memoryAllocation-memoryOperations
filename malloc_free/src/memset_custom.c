//
// Created by Guillaume Noailles on 31/01/18.
//
#include <memset_custom.h>
#include <stdint.h>
#include <assert.h>
#include <memdef.h>

void *memset_char(void* dest, int ch, size_t count)
{
	unsigned char* p = (unsigned char*)dest;

	while(count--)
	{
		*(p++) =  (unsigned char) (ch & 0xff);
	}

	return dest;
}

void* memset_word32(void* dest, int ch, size_t count)
{
	uint32_t* p = (uint32_t*) dest;

	uint32_t x = (uint32_t) (ch & 0xff);
	x |= x << 8;
	x |= x << 16;

	assert(!(count & ALIGN_MASK));

	count >>= 2;

	while(count--)
		*(p++) = x;

	return dest;
}
void *memset_word64(void* dest, int ch, size_t count)
{
	uint64_t* p = (uint64_t*) dest;

	uint64_t x = (uint64_t) (ch & 0xff);
	x |= x << 8;
	x |= x << 16;
	x |= x << 32;

	assert(!(count & ALIGN_MASK));

	count >>= 3;

	while(--count)
		*(p++) = x;

	return dest;
}