#include "main.h"
/**
 * get_opcode - gets the operator function
 * @data_struct: pointer to a queue or stack
 * @ln: line number
 * @op: operation to perform
 */
void get_opcode(stack_t **data_struct, unsigned int ln, char *op)
{
	int i;
	instruction_t op_codes[] = {
		{"push", push},
		{"pall", pall},
		{"\0", NULL}
	};
	if (op[0] == '#')
		return;
	if (strcmp(op, "queue") == 0)
	{
		global_variables.data_struct = 0;
		return;
	}
	if (strcmp(op, "stack") == 0)
	{
		global_variables.data_struct = 1;
		return;
	}

	for (i = 0; op_codes[i].opcode != NULL; i++)
	{
		if (strcmp(op_codes[i].opcode, op) == 0)
		{
			op_codes[i].f(data_struct, ln);
			return;
		}
	}
	printf("L%d: unknown instruction %s\n", ln, op);
	free_list(data_struct);
	exit(EXIT_FAILURE);
}
