#include "sort.h"
/**
 * shell_sort - sort array using shell sort with knuth sequence
 * @array: pointer to array
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int n = 1;
	int i, tmp, j;

	/*setting gap*/
	while (n < (int)size / 3)
		n = n * 3 + 1;
	while (n > 0)
	{
		for (i = n; i < (int)size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= n && array[j - n] > tmp)
			{
				array[j] = array[j - n];
				j -= n;
			}
			if (j != i)
				array[j] = tmp;
			print_array(array, size);

		}
		n = (n - 1) / 3;
	}

}
