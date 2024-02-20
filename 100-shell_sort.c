#include "sort.h"

/**
 * max_gap - get the largest knuth sequence gap for the size
 *
 * @size: the size of the array
 *
 * Return: the size gap.
 *
*/

size_t max_gap(size_t size)
{
	size_t n;

	n = 1;
	while (n < size)
	{
		n = n * 3 + 1;
	}
	return ((n - 1) / 3);
}

/**
 * shell_sort - function that sorts an array of integers in ascending
 *order using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void
*/

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || !size)
	{
		return;
	}
	for (gap = max_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[i - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
