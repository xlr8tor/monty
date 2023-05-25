#include "monty.h"
/**
 * free_list - free doubly linked list
 * @head: start of list
 */
void free_list(stack_t **head)
{
	stack_t *ptr, *temp;

	if (head == NULL)
	{
		free(head);
		return;
	}
	free(global_variables.argv);
	ptr = *head;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
}
