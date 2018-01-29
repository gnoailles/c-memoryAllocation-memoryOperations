#include <stdio.h>
#include <malloc_custom.h>
#include <free_custom.h>

int main()
{
	int* t = malloc_custom(sizeof(int)*4);
	*t = 5;

	float* f = malloc_custom(sizeof(float));
	*f = 3.2f;

	char* c = malloc_custom(sizeof(char));
	*c = 'w';

	char* c2 = malloc_custom(sizeof(char));
	*c2 = 'z';

	free_custom(t);
	free_custom(f);

	char* c3 = malloc_custom(sizeof(char));
	*c3 = 'o';

	return 0;

}