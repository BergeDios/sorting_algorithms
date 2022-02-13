#include "sort.h"
/**
 * selection_sort - sort array with selection algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int pos = 0, pos2, pos_swap = 0;
	int min, swap2;

	for (pos = 0; pos < (size - 1); pos++)
	{
		min = array[pos];
		pos2 = pos;
		while (pos2 < size)
		{
			if (array[pos2] < min)
			{
				min = array[pos2];
				pos_swap = pos2;
			}
			pos2++;
		}
		swap2 = array[pos];
		if (pos_swap == 0)
			continue;
		array[pos] = min;
		array[pos_swap] = swap2;
		print_array(array, size);
		pos_swap = 0;
	}
}
