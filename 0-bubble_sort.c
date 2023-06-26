#include "sort.h"


/**
 * bubble_sort - a function that sorts an array of integers in
 *     ascending order using the Bubble sort algorithm.
 * @array: given intiger array to sort
 * @size: the size of the array
 *
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
unsigned long int h, i;
int flag = 0;
int val;


h = 0;
while (h < size)
{

i = 0;
while (i < size - 1)
{
/* if the 'current value' > 'next value'; switch values */
/* print the updated list and raise a flag */
if (array[i] > array[i + 1])
{
val = array[i];
array[i] = array[i + 1];
array[i + 1] = val;
print_array(array, size);
flag = 1;
}
++i;
}

/* if no flags raised (list is sorted); return */
if (flag == 0)
break;

h++;
}

}