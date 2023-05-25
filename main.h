#ifndef MAIN_H
#define MAIN_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals_s - global variables
 * @file: a file handle
 */
typedef struct globals_s
{
	FILE *file;
	char *argv;
	char *line;
	int data_struct;
} globals_t;

extern globals_t global_variables;
globals_t global_variables;

void init_buffer(char *file_name);
void get_opcode(stack_t **ds, unsigned int line_number, char *op);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
int check_if_num(char *str);
void stacker(stack_t **stack, stack_t *node);
void queuer(stack_t **stack, stack_t *node);
void free_list(stack_t **head);
#endif /* MAIN_H */
