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

	while (first <= last)
	{
		while (array[first] < pivot)
			first++;
		while (array[last] > pivot)
			last--;

		if (first <= last)
		{
			if (first != last)
			{
				swap = array[first];
				array[first] = array[last];
				array[last] = swap;
				print_array(array, size);
			}
			first++;
			last--;
		}
	}
	return (last);

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
			quick_sorter(array, first, pivot_index, size);
		if (pivot_index < last)
			quick_sorter(array, pivot_index + 1, last, size);
	}
}


/**
 * quick_sort_hoare - sort array using quick sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array && size > 1)
		quick_sorter(array, 0, size - 1, size);
}
