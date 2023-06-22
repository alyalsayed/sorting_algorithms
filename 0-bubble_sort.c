#include "sort.h"
/**
 * swap_array: a function that swaps two values in an array
 * @val1: first value
 * @val2: second value
 */
void swap_array(int *val1, int *val2)
{
	int *temp;

	temp = val1;
	val1 = val2;
	val2 = temp;
}

/**
 * bubble_sort - function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t swapped, temp, i, j;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
