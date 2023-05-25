#include "monty.h"
/**
* stacker - sets the format of the data to a stack (LIFO).
* @stack: ds
* @node: new node
*/
void stacker(stack_t **stack, stack_t *node)
{
	node->n = atoi(global_variables.argv);
	if (!*stack)
	{
		node->prev = NULL;
		node->next = NULL;
		*stack = node;
	}
	else
	{
		(*stack)->prev = node;
		node->next = *stack;
		node->prev = NULL;
		*stack = node;
	}
}

/**
* queuer - sets the format of the data to a queue (FIFO).
* @stack: ds
* @node: new node
*/
void queuer(stack_t **stack, stack_t *node)
{
	stack_t *ptr;

	node->next = NULL;
	node->n = atoi(global_variables.argv);

	if (!*stack)
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		ptr = *stack;
		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = node;
		node->prev = ptr;
	}
}
