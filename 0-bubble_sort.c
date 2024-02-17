#include "sort.h"

/**
 * bubble_sort - function that sorts and array using
 * bubble sort algorithm
 *
 * @array: array of intgers
 * @size: size of the array
 *
*/

void bubble_sort(int *array, size_t size)
{
	int swap;
	size_t i, j;

	if (!array || !size)
	{
		return;
	}

	i = 0;
	while (i < size)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
		i++;
	}
}
