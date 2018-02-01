#include <stdio.h>
#include <time.h>

#include <malloc_custom.h>
#include <free_custom.h>
#include <memory_custom.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
	clock_t start, end;
	double cpu_time_used;

	size_t testSize = ALIGNED_SIZE(40000);


	char* arr1 = NULL;
	char* arr2 = NULL;
	char* arr3 = NULL;
	char* arr4 = NULL;
	printf("\n=======Memory Performances=======\n");

	printf("Array testing type : char\n");
	printf("Array testing size : %zu\n", testSize);

	printf("\n-------C STD allocations-------\n");
	{
		start = clock();
		arr3 = (char*)malloc(testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("malloc\t\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		arr4 = (char*)calloc(testSize,1);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("calloc\t\t:  %lfs cpu_time.\n", cpu_time_used);
	}

	printf("\n-------custom allocations-------\n");
	{
		start = clock();
		arr1 = (char*)malloc_custom(testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("malloc\t\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		arr2 = (char*)calloc_custom(testSize,1);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("calloc\t\t:  %lfs cpu_time.\n", cpu_time_used);
	}


	printf("\n-------memset-------\n");
	{
		start = clock();
		memset(arr3, 0xFF, testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("STL memset\t:  %lfs cpu_time.\n", cpu_time_used);

		start = clock();
		memset_char(arr1, 0xFF, testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("memset_char\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		memset_word64(arr1, 0xFF, testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("memset_word64\t:  %lfs cpu_time.\n", cpu_time_used);
	}


	printf("\n-------memcpy-------\n");
	{
		start = clock();
		memcpy(arr4, arr3, testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("STL memcpy\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		memcpy_char(arr2, arr1, testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("memcpy_char\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		memcpy_word64(arr2, arr1, testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("memcpy_word64\t:  %lfs cpu_time.\n", cpu_time_used);
	}


	printf("\n-------memmove-------\n");
	{
		start = clock();
		memmove(arr4, arr3, testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("STL memmove\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		memmove_char(arr2, arr1, testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("memmove_char\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		memmove_word64(arr2, arr1, testSize);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("memmove_word64\t:  %lfs cpu_time.\n", cpu_time_used);
	}


	printf("\n-------C STD realloc-------\n");
	{
		start = clock();
		arr3 = (char*)realloc(arr3,5000);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("shrink to 5000\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		arr3 = (char*)realloc(arr3,10000);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("expand to 10000 \n(w/o new alloc)\t:  %lfs cpu_time.\n", cpu_time_used);

		start = clock();
		arr4 = (char*)realloc(arr4,80000);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("expand to 80000 \n(last in heap)\t:  %lfs cpu_time.\n", cpu_time_used);
		start = clock();
		arr3 = (char*)realloc(arr3,80000);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("expand to 80000 \n(copy needed)\t:  %lfs cpu_time.\n", cpu_time_used);
	}


	printf("\n-------realloc-------\n");
	{
		start = clock();
		arr1 = (char*)realloc_custom(arr1,5000);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("shrink to 5000\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		arr1 = (char*)realloc_custom(arr1,10000);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("expand to 10000 \n(w/o new alloc)\t:  %lfs cpu_time.\n", cpu_time_used);

		start = clock();
		arr2 = (char*)realloc_custom(arr2,80000);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("expand to 80000 \n(last in heap)\t:  %lfs cpu_time.\n", cpu_time_used);
		start = clock();
		arr1 = (char*)realloc_custom(arr1,80000);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("expand to 80000 \n(copy needed)\t:  %lfs cpu_time.\n", cpu_time_used);
	}


	printf("\n-------C STD free-------\n");
	{
		start = clock();
		free(arr4);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("free \t\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		free(arr3);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("free\t\t:  %lfs cpu_time.\n", cpu_time_used);
	}

	printf("\n-------custom free-------\n");
	{
		start = clock();
		free_custom(arr2);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("free \t\t:  %lfs cpu_time.\n", cpu_time_used);


		start = clock();
		free_custom(arr1);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("free\t\t:  %lfs cpu_time.\n", cpu_time_used);
	}




	return 0;

}