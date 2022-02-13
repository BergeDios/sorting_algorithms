#include "sort.h"
/**
 * div_and_conquer - takes pivot, finds places and divdes array
 * @array: array pointer
 * @first: first pos element of array
 * @last: last element of array
 * @size: size of array to print it
 * Return: position index of pivot
 */
size_t div_and_conquer(int *array, size_t first, size_t last, size_t size)
{
	int pivot = array[last], swap;
	size_t smaller_index = first - 1, pos = first;

	for (pos = first; pos <= last - 1; pos++)
	{
		if (array[pos] < pivot)
		{
			smaller_index++;
			if (smaller_index != pos)
			{
				swap = array[smaller_index];
				array[smaller_index] = array[pos];
				array[pos] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[last] < array[smaller_index + 1])
	{
		swap = array[smaller_index + 1];
		array[smaller_index + 1] = array[last];
		array[last] = swap;
		print_array(array, size);
	}
	return (smaller_index + 1);

}

/**
 * quick_sorter - sorts first array and then sub arrays
 * @array: pointer to array
 * @first: first pos of array
 * @last: last pos of array
 * @size: size for printing
 * Return: void
 */
void quick_sorter(int *array, size_t first, size_t last, size_t size)
{
	size_t pivot_index;

	if (first < last)
	{
		pivot_index = div_and_conquer(array, first, last, size);
		if (pivot_index > 0)
			quick_sorter(array, first, pivot_index - 1, size);
		if (pivot_index < last)
			quick_sorter(array, pivot_index + 1, last, size);
	}
}


/**
 * quick_sort - sort array using quick sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quick_sorter(array, 0, size - 1, size);
}
