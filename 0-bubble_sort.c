#include "sort.h"
/**
 * bubble_sort - sort array of ints using bubble sort algorithm
 * @array: pointer to array
 * @size: size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int counter = 0, comparer = 0, swaper, swaper2;

	if (size < 2)
		return;

	for (counter = 0; counter < size; counter++)
	{
		for (comparer = 0; comparer < (size - 1); comparer++)
		{
			if (array[comparer] > array[comparer + 1])
			{
				swaper = array[comparer];
				swaper2 = array[comparer + 1];
				array[comparer] = swaper2;
				array[comparer + 1] = swaper;
				print_array(array, size);
			}
		}

	}
}
