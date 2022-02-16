#include "sort.h"

/**
 * counting_sort - sorts array using counting sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, j = 0, k = 0;
	size_t i = 0;
	int *output;

	count = NULL; output = NULL;
	if (!array || !*array || size < 2)
		return;
	k = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count = malloc(((k + 1) * 4));
	if (!count)
		return;
	for (j = 0; j < k; j++)
		count[j] = 0;
	/*counting numbers and adding 1 to their valueposition/ setting count*/
	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	/*add summed positions to get actual position value*/
	for (j = 1; j <= k; j++)
		count[j] += count[j - 1];
	print_array(count, (k + 1));

	output = malloc(sizeof(int) * (size));
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
	free(count), free(output);
}
