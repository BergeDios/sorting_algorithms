#include "sort.h"

/**
 * counting_sort - sorts array using counting sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, j,  k = array[0];
	size_t i;
	char *output;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count = malloc(sizeof(int) * (k + 1));
	if (!count)
		return;
	for (j = 0; j < k; j++)
		count[j] = 0;
	/*counting numbers and adding 1 to their valueposition/ setting count*/
	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	/*add summed positions to get actual position value*/
	for (j = 0; j <= k; j++)
		count[j] += count[j - 1];
	print_array(count, (k + 1));

	output = malloc(sizeof(char) * (size));
	if (!output)
	{
		free(count);
		return;
	}
	/*building output array*/
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
