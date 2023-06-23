#include "sort.h"
/**
 * swap_ints - swaps two values in an array
 * @val_1: first value
 * @val_2: second value
 *
 * Return: Nothing
 */
void swap_ints(int *val_1, int *val_2)
{
	int tmp;

	tmp = *val_1;
	*val_1 = *val_2;
	*val_2 = tmp;
}

/**
 * selection_sort - A function that use selection sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * return: nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap_ints(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}
