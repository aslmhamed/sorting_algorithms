#include "sort.h"

/**
 * swap - swaps two int values
 *
 * @array: array of integers to sort
 * @size: size of the array
 * @a: first address
 * @b: second address
 *
 * Return: void
 *
*/

void swap(int *array, int *a, int *b, size_t size)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}

}


/**
 * lomuto - partitioning the array
 *
 * @array: array of Integers to sort
 * @size: size of the array
 * @low: lowst index of the sort range
 * @high: highest index of the sort range
 *
 * Return: size_t
*/

size_t lomuto(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, piv = array[high];

	for (i = j = low; j < high; j++)
	{
		if (array[j] < piv)
		{
			swap(array, size, &array[j], &array[i++]);
		}
	}
	swap(array, size, &array[i], &array[high]);

	return (i);
}

/**
 * q_sort - quicksort using lomuto paritioning scheme
 *
 * @array: array of integers to sort
 * @size: size of the array
 * @low: lowest index of the sort range
 * @high: highest index of the sort range
 *
 * Return: void
*/

void q_sort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t p = lomuto(array, size, low, high);

		q_sort(array, size, low, p - 1);
		q_sort(array, size, p + 1, high);
	}

}

/**
 * quick_sort - function that sorts an array of integers
 *in ascending order using the Quick sort algorithm
 *
 * @array: array of integers to sort
 * @size: size of the array
 *
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}
	q_sort(array, size, 0, size - 1);
}


