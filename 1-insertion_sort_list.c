#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: First node to swap
 * @b: Second node to swap
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;

	if (!b->prev)
		*list = b;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the Insertion sort algorithm
 * @list: Pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (current)
	{
		listint_t *temp = current;

		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
			temp = temp->prev;
		}
		current = current->next;
	}
}
