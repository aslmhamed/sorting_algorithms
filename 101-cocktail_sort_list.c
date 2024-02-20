#include "sort.h"

/**
 * swap - swap the nodes
 *
 * @curr: points to the current node.
 * @old_curr: points to the old node.
 * @list: the double linked list.
 *
 * Return: void
 *
*/

void swap(listint_t *curr, listint_t *old_curr, listint_t **list)
{
	listint_t *tail = curr->next;
	listint_t *head = old_curr->prev;

	if (tail != NULL)
	{
		tail->prev = old_curr;
	}
	if (head != NULL)
	{
		head->next = curr;
	}
	curr->prev = head;
	old_curr->next = tail;
	curr->next = old_curr;
	old_curr->prev = curr;
	if (*list == old_curr)
	{
		*list = curr;
	}
	print_list(*list);
}


/**
 * cocktail_sort_list - cocktail_sort_list
 *
 * @list: doubly linked list
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL, *last = NULL;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	do {
		while (check->next)
		{
			if (check->n > check->next->n)
			{
				swap(check->next, check, list);
			}
			else
			{
				check = check->next;
			}
		}
		last = check;
		while (check->prev != first)
		{
			if (check->n < check->prev->n)
			{
				swap(check, check->prev, list);
			}
			else
			{
				check = check->prev;
			}
		}

		first = check;
	} while (first != last);
}

