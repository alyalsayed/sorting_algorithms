#include "sort.h"

/**
 * swap_ints - swaps two values in an array
 * @val_1: first value
 * @val_2: second value
 */
void swap_ints(int *val_1, int *val_2)
{
	int tmp;

	tmp = *val_1;
	*val_1 = *val_2;
	*val_2 = tmp;
}

/**
 * shell_sort - a function that sorts an array of integers
 * in ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 *
 * @array: the array to be sorted
 * @size: size of the array
*/
void shell_sort(int *array, size_t size)
{
	int i, j, gap = 1;

        if (array == NULL || size < 2)
                return;

	/* Genrate the Knuth sequence*/
	while (gap < (int)size / 3)
		gap *= 3 + 1;
        /*iterating the array and progressively reducing the gap*/
	for (; gap > 0; gap /= 3)
	{
		for (j = gap; j < (int)size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
                                /*comparing elements far apart based on the gap between them*/
				if (array[i] > array[i + gap])
				{
					swap_ints(&array[i], &array[i + gap]);
				}
				else
					break;
			}
		}
		print_array(array, size);
	}
}
