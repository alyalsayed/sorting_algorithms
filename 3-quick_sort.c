#include "sort.h"

/**
 * lomuto_partition - partitions an array using the Lomuto partition scheme
 * @array: array to partition
 * @low: lowest index of the partition
 * @high: highest index of the partition
 * @size: size of the array
 * Return: final position of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
            i++;
        }
    }
    if (i != high)
    {
        temp = array[i];
        array[i] = array[high];
        array[high] = temp;
        print_array(array, size);
    }
    return (i);
}

/**
 * quicksort - recursive function that sorts a partition of an array
 * @array: array to sort
 * @low: lowest index of the partition
 * @high: highest index of the partition
 * @size: size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    int pi;

    if (low < high)
    {
        pi = lomuto_partition(array, low, high, size);
        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}