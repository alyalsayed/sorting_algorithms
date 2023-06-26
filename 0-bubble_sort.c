#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, t;
	int holder;

	if (array == NULL || size < 2)
		return;

	for (t = size; t > 0; t--)
	{
		for (n = 0; n < size - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				holder = array[n];
				array[n] = array[n + 1];
				array[n + 1] = holder;
				print_array(array, size);
			}
		}
	}
}