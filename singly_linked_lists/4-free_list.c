#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the first node of the list
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *current, *next_node;

	current = head;

	while (current != NULL)
	{
		next_node = current->next;
		free(current->str);
		free(current);
		current = next_node;
	}
}
