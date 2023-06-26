#include "sort.h"

/**
 * swap - swaps two values in an array
 * @val_1: first value
 * @val_2: second value
 */
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
  * bubble_sort - A function for bubble sorting.
  * @array: The array to sort.
  * @size: THe length of the aaray.
  */
void bubble_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int swapped = 1;
    for (size_t i = 0; i < size - 1 && swapped; i++) {
        swapped = 0;
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                swapped = 1;
				print_array(array, size);
			}
		}
	}
}

