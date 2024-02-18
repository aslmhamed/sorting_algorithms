#include "sort.h"

/**
 * swap - function to swap two nodes in a
 *doubly linked list
 *
 * @temp: address of the first node
 * @h: addresss of the second node
 *
 * Return: void
*/

void swap(listint_t *temp, listint_t *h)
{
	if (temp->prev)
	{
		temp->prev->next = h;
	}
	if (h->next)
	{
		h->next->prev = temp;
	}
	temp->next = h->next;
	h->prev = temp->prev;
	temp->prev = h;
	h->next = temp;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *in ascending order using the Insertion sort algorithm
 *
 * @list: address of pointer to head node
 *
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	a = (*list)->next;

	while (a)
	{
		b = a;
		a = a->next;
		while (b && b->prev)
		{
			if (b->prev->n > b->n)
			{
				swap(b->prev, b);
				if (!b->prev)
				{
					*list = b;
				}
				print_list((const listint_t *)*list);
			}
			else
			{
				b = b->prev;
			}
		}

	}

}
