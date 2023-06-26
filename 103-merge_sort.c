#include "sort.h"
/**
 * merge_SubArray - merges the sub-arrays
 * @high: highest index
 * @low: lowest index
 * @mid: middle index
 * @sub_array: sub-array to be sorted
 * @sorted_buf: a buffer to store the sorted elements
 * Return: Nothing
 */
void merge_SubArray(int *sub_array, int high, int mid,
		int low, int *sorted_buf)
{
	int i = low, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + low, mid - low);

	printf("[right]: ");
	print_array(sub_array + mid, high - mid);
	while (i < mid && j < high)
	{
		if (sub_array[i] < sub_array[j])
		{
			sorted_buf[k] = sub_array[i];
			i++;
		}
		else
		{
			sorted_buf[k] = sub_array[j];
			j++;
		}
		k++;
	}
	while (j < high)
	{
		sorted_buf[k] = sub_array[j];
		j++;
		k++;
	}
	while (i < mid)
	{
		sorted_buf[k] = sub_array[i];
		i++;
		k++;
	}
	for (i = low, k = 0; i < high; k++, i++)
		sub_array[i] = sorted_buf[k];

	printf("[Done]: ");
	print_array(sub_array + low, high - low);
}

/**
 * TopDown_MergeSort - divided the array into halves repeatedly
 * till it contains a single value
 * @array: array to sorted
 * @sorted_buf: a buffer to store the sorted array
 * @high: the highest index
 * @low: the lowest index
 *
 * Return: Nothing
 */
void TopDown_MergeSort(int *array, int high, int low, int *sorted_buf)
{
	int mid;

	if (high - low > 1)
	{
		mid = (high + low) / 2;
		TopDown_MergeSort(array, mid, low, sorted_buf);
		TopDown_MergeSort(array, high, mid, sorted_buf);
		merge_SubArray(array, high, mid, low, sorted_buf);
	}
}

/**
 * merge_sort - nction that sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *sorted_buf;

	if (array == NULL || size < 2)
		return;
	sorted_buf = malloc(sizeof(int) * size);
	if (sorted_buf == NULL)
		return;

	TopDown_MergeSort(array, size, 0, sorted_buf);
	free(sorted_buf);
}
