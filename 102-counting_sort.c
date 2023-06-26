#include "sort.h"
/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, size_t size)
{
	int i, max = array[0];

	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *count, *sorted;

	if (array == NULL || size < 2)
		return;
	/* getting the maximum value of the array*/
	max = get_max(array, size);

	sorted = malloc(sizeof(int) * size);
	if (sorted  == NULL)
		return;

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	/* intializing the array count with 0*/
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;

	/* counting the unique values of the array to be sorted */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	/* summing the counts consecutively */
	for (i = 1; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	/* sorting the array into a sorted array*/
	for (i = size - 1; i >= 0; --i)
		sorted[--count[array[i]]] = array[i];

	/* Reassignment of the array with the sorted array*/
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
