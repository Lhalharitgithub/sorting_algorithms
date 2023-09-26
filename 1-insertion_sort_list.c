#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Custom function that sorts double
 * linked list in ascending order.
 * @list: Argument of custom function containing double linked
 * list.
 * Return: The function returns nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *al_pointer;
	listint_t *al_var_t;

	if (!list)
		return;

	al_pointer = *list;

	while (al_pointer)
	{
		while (al_pointer->next && (al_pointer->n > al_pointer->next->n))
		{
			al_var_t = al_pointer->next;
			al_pointer->next = al_var_t->next;
			al_var_t->prev = al_pointer->prev;

			if (al_pointer->prev)
				al_pointer->prev->next = al_var_t;

			if (al_var_t->next)
				al_var_t->next->prev = al_pointer;

			al_pointer->prev = al_var_t;
			al_var_t->next = al_pointer;

			if (al_var_t->prev)
				al_pointer = al_var_t->prev;
			else
				*list = al_var_t;

			print_list(*list);
		}
		al_pointer = al_pointer->next;
	}
}
