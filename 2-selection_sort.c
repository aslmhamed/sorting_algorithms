#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 *in ascending order using the Selection sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
*/

void selection_sort(int *array, size_t size)
{
	size_t x, y, z;
	int temp;

	if (!array || !size)
	{
		return;
	}
	for (x = 0; x < size - 1; x++)
	{
		for (y = size - 1, z = x + 1; y > x; y--)
		{
			if (array[y] < array[z])
			{
				z = y;
			}
		}
		if (array[x] > array[z])
		{
			temp = array[x];
			array[x] = array[z];
			array[z] = temp;
			print_array(array, size);
		}
	}
}
