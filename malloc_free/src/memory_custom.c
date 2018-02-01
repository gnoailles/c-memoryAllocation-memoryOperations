//
// Created by Guillaume Noailles on 31/01/18.
//
#include <memory_custom.h>
#include <stdint.h>
#include <assert.h>
#include <memdef.h>

void *memset_char(void* dest, int c, size_t n)
{
	unsigned char* p = (unsigned char*)dest;

	while(n--)
	{
		*(p++) =  (unsigned char) (c & 0xff);
	}

	return dest;
}

void* memset_word32(void* dest, int c, size_t n)
{
	uint32_t* p = (uint32_t*) dest;

	uint32_t x = (uint32_t) (c & 0xff);
	x |= x << 8;
	x |= x << 16;

	assert(!(n & ALIGN_MASK));

	n >>= 2;

	while(n--)
		*(p++) = x;

	return dest;
}
void* memset_word64(void* dest, int c, size_t n)
{
	uint64_t* p = (uint64_t*) dest;

	uint64_t x = (uint64_t) (c & 0xff);
	x |= x << 8;
	x |= x << 16;
	x |= x << 32;

	assert(!(n & ALIGN_MASK));

	n >>= 3;

	while(--n)
		*(p++) = x;

	return dest;
}

void* memcpy_char(void *dest, void *src, size_t n)
{
	unsigned char* d = (unsigned char*)dest;
	unsigned char* s = (unsigned char*)src;

	while(n--)
	{
		*(d++) =  (unsigned char) (*(s++) & 0xff);
	}

	return dest;
}


void* memcpy_word32(void *dest, void *src, size_t n)
{
	uint32_t* d = (uint32_t*) dest;
	uint32_t* s = (uint32_t*) src;

	assert(!(n & ALIGN_MASK));

	n >>= 2;

	while(n--)
		*(d++) = *(s++);

	return dest;
}

void* memcpy_word64(void *dest, void *src, size_t n)
{
	uint64_t* d = (uint64_t*) dest;
	uint64_t* s = (uint64_t*) src;

	assert(!(n & ALIGN_MASK));

	n >>= 3;

	while(--n)
		*(d++) = *(s++);

	return dest;
}

void *memmove_char(void *dest, void *src, size_t n)
{
	unsigned char* pd = (unsigned char*)dest;
	unsigned char* ps = (unsigned char*)src;
	if (ps < pd)
		for (pd += n, ps += n; n--;)
			*--pd = *--ps;
	else
		while(n--)
			*pd++ = *ps++;
	return dest;
}

void *memmove_word32(void *dest, void *src, size_t n)
{
	uint32_t* pd = (uint32_t*)dest;
	uint32_t* ps = (uint32_t*)src;

	assert(!(n & ALIGN_MASK));

	n >>= 2;

	if (ps < pd)
		for (pd += n, ps += n; n--;)
			*--pd = *--ps;
	else
		while(n--)
			*pd++ = *ps++;
	return dest;
}

void *memmove_word64(void *dest, void *src, size_t n)
{
	uint64_t* pd = (uint64_t*)dest;
	uint64_t* ps = (uint64_t*)src;

	assert(!(n & ALIGN_MASK));

	n >>= 3;

	if (ps < pd)
		for (pd += n, ps += n; n--;)
			*--pd = *--ps;
	else
		while(n--)
			*pd++ = *ps++;
	return dest;
}

