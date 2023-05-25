#include "main.h"
/**
 * main - Entry point into the program
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: either 0 or 1
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	init_buffer(argv[1]);
	fclose(global_variables.file);

	return (EXIT_SUCCESS);
}
