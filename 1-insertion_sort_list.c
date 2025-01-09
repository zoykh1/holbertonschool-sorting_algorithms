#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->n < current->prev->n)
		{
			temp = current->prev;
			current->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = current;
			temp->next = current->next;
			if (current->next)
				current->next->prev = temp;
			current->next = temp;
			temp->prev = current;

			if (!current->prev)
				*list = current;
			print_list(*list);
		}
		current = current->next;
	}
}
