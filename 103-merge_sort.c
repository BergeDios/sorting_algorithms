#include "sort.h"
#include "stdio.h"

/**
 * TDmerge - recursive to sort arrays?
 * @array: pointer to array
 * @min: min pos of array
 * @max: max of array
 * Return: void
 */
void merger(int *array, int min, int max)
{
	int tmp [1024];
	int mid = 0, posi = min, posm = 0, posk = 0;

	mid = (min + max) / 2;
	posm = mid;
	printf("merg min=%d, mid=%d, max=%d\n", array[min], array[mid], array[max]);
	while (posi <= mid && posm <= max)
	{
		if (array[posi] <= array[posm])
		{
			tmp[posk] = array[posi];
			posk++, posi++;
			
		}
		else
		{
			tmp[posk] = array[posm];
			posk++, posm++;
		}
	}
	while (posi <= mid)
	{
		tmp[posk] = array[posi];
		posk++, posi++;
	}
	while (posm <= max)
	{
		tmp[posk] = array[posm];
		posk++, posm++;
	}
	for (posi = min; posi <= max; posi++)
		array[posi] = tmp[posi - min];
}
/**
 * TDmerge - recursive merge part
 * @array: pointer to array
 * @min: start
 * @max: end
 * Return: void
 */
void TDmerge(int *array, int min, int max)
{
	int mid = 0;
	
	/*if ((max - min) < 2)
	{
		printf("\033[0;31mno recursion por min = max\n\033[0;37m");
		return;
	}*/

	if ((max - min) > 2)
	{
		mid = (min + max) / 2;
		printf("entering recursion, min = %d, max = %d, mid = %d\n",  array[min], array[max], array[mid]);
		if (1)
		{
			printf("entered recursion por la izquerda\n");
			TDmerge(array, min, mid);
		}
		if (1)
		{
			printf("entered recursion por la derecha\n");
			TDmerge(array, mid, max);

		}
		merger(array, min, max);
		return;
	}
	else
	{
		printf("no recursion needed\n");
		return;
	}
	
}
/**
 * merge_sort - sorts array using merge sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	if (!array || !*array || size < 2)
		return;
	TDmerge(array, 0, (size - 1));
}
