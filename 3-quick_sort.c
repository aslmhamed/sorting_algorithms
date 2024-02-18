#include "sort.h"

/**
 * swap - swaps two integer values
 *
 * @array: array of ints to sort
 * @size: size of the array
 * @a: address for the first value
 * @b:address for the second value
 *
 * Return: void
*/

void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != b)
	{
		/*doing arithmetic based operation */
		*a = *a + b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - partitions the array
 *
 * @array: array of ints to sort
 * @size: size of the array
 * @low: the lowest index of the sort range
 * @high: the highest index of the sort range
 *
 * Return: size_t
*/

size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int x, y, pivot = array[high];

	for (x = y = low; y < high; y++)
	{
		if (array[y] < pivot)
		{
			swap(array, size, &array[y], &array[x++]);
		}
	}
	swap(array, size, &array[x], &array[high]);

	return (x);
}

/**
 * quicksort - quicksorts via lomuto paritioning scheme
 *
 * @array: array of ints to sort
 * @size: the size of the array
 * @low: the lowest index of the sort range
 * @high: the highest index of the sort range
 *
 * Return: void
*/

void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t p = lomuto_partition(array, size, low, high);

		quicksort(array, size, low, p - 1);
		quicksort(array, size, p + 1, high);
	}
}

/**
 * quick_sort -  function that sorts an array of integers in
 *ascending order using the Quick sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}
	quicksort(array, size, 0, size - 1);
}
