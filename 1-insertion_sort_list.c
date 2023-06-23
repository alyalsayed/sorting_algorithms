#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: double pointer to the head of the list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *prev1, *next2;

    if (node1 == node2)
        return;

    prev1 = node1->prev;
    next2 = node2->next;

    if (prev1)
        prev1->next = node2;
    if (next2)
        next2->prev = node1;

    node1->next = next2;
    node1->prev = node2;
    node2->next = node1;
    node2->prev = prev1;

    if (!prev1)
        *list = node2;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;
    while (current)
    {
        insert = current;
        while (insert && insert->prev && insert->n < insert->prev->n)
        {
            swap_nodes(list, insert->prev, insert);
            print_list(*list);
        }
        current = current->next;
    }
}