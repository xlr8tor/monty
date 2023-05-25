#include "monty.h"
/**
 * init_buffer - init buffer
 * @file_name: file name
 */
void init_buffer(char *file_name)
{
	FILE *file;
	char *line = NULL, *op = NULL;
	size_t linecap = 0;
	unsigned int line_number = 1;
	stack_t *data_struct = NULL;

	file = fopen(file_name, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	global_variables.file = file;

	while (getline(&line, &linecap, file) != -1)
	{
		global_variables.line = line;
		if (*line == '\n')
		{
			++line_number;
			continue;
		}
		op = strtok(line, " \t\n");
		if (!op)
		{
			++line_number;
			continue;
		}
		global_variables.argv = strtok(NULL, " \t\n");
		get_opcode(&data_struct, line_number, op);
		++line_number;
	}

	free_list(&data_struct);
}
