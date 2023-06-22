#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
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

ssize_t _getline(char **line, size_t *line_size, FILE *stream);
void find_func(char *line_args, int line, stack_t **head);

char *remove_space(char *str);

/*errors*/
void err_push(int line);
void err_malloc();
void err_usage();
void err_file(char *arg);
void err_pop(int line);
void err_unk(int line, char *cmd);

void free_all(stack_t **head);
void pall(stack_t *head);
void push(stack_t **head, int val);
void pop(stack_t **head, int line);
void pint(stack_t **head, int line);

#endif
