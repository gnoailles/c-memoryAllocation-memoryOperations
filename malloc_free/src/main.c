#include <stdio.h>
#include <malloc_custom.h>
#include <free_custom.h>
#include <memset_custom.h>

int main()
{
	char* t = (char*)calloc_custom(68,1);

	float* f = (float*)malloc_custom(sizeof(float));
	*f = 3.2f;

	char* c = (char*)malloc_custom(sizeof(char));
	*c = 'w';

	char* c2 = (char*)malloc_custom(sizeof(char));
	*c2 = 'z';

	free_custom(t);
	free_custom(f);

	char* c3 = (char*)malloc_custom(sizeof(char));
	*c3 = 'o';

	free_custom(c);
	free_custom(c2);
	free_custom(c3);

	return 0;

}