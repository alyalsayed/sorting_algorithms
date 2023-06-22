#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 *
 * @list: the unsorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			listint_t *next_node = current->next;
			listint_t *prev_node = current->prev;

			prev_node->next = next_node;

			if (next_node != NULL)
				next_node->prev = prev_node;
			current->prev = prev_node->prev;
			prev_node->prev = current;
			current->next = prev_node;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}
}
