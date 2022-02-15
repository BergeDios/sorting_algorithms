#include "sort.h"
/**
 * insertion_sort_list - sort dlinked with insertion algorithm
 * @list: pointer to head
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *tmp = NULL;

	if (!list || !*list || (*list)->next == NULL)
		return;
	while (current != NULL)
	{
		tmp = current->next;
		while (tmp != NULL && tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			if (tmp->prev != NULL)
				tmp->prev->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			if(tmp->next)
				tmp->prev = tmp->next->prev;
			if (tmp->prev != NULL)
			{
				tmp->prev->next = tmp;
			}
			if (tmp->prev == NULL)
			{
				*list = tmp;
			}
			if (tmp->next != NULL)
				tmp->next->prev = tmp;
			print_list(*list);
		}
		if (current->next == NULL)
			break;
		if (current->n < current->next->n)
			current = current->next;
	}
}
