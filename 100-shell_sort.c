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
	size_t i, j, gap;
	int temp;

        if (array == NULL || size < 2)
                return;

	/*Genrate the Knuth sequence*/
	for(gap = 1; gap < size; gap = gap 3 + 1)
		;
        /*iterating the array and progressively reducing the gap*/
	for (gap = gap / 3; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			/*comparing elements far apart based on the gap between them*/
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
