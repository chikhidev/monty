#include "monty.h"

/**
* pall - Print all elements in the stack
* @head: Pointer to the top of the stack
* @line: line cou
*/
void pall(stack_t **head,  unsigned int line)
{
stack_t *curr = *head;

(void) line;
if (*head == NULL)
return;

while (curr != NULL)
{
printf("%d\n", curr->n);
curr = curr->next;
}
}


/**
* push - Push a value onto the stack
* @head: Double pointer to the top of the stack
* @line: line cou
*/
void push(stack_t **head, unsigned int line)
{
stack_t *new_node = NULL;
int cont = 0;
char *verify = strtok(NULL, "\n\t ");

if (!verify)
{
fprintf(stderr, "L%u: usage: push integer\n", line);
exit(EXIT_FAILURE);
}

while (verify[cont] != '\0')
{
if (!isdigit(verify[cont]) && verify[cont] != '-')
{
fprintf(stderr, "L%u: usage: push integer\n", line);
exit(EXIT_FAILURE);
}
cont++;
}
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
err_malloc();

new_node->n = atoi(verify);
new_node->prev = NULL;

if (*head)
{
new_node->next = (*head);
(*head)->prev = new_node;
(*head) = new_node;
}
else
{
(*head) = new_node;
new_node->next = NULL;
}
}


/**
* pop - Pop the top element from the stack
* @head: Double pointer to the top of the stack
* @line: line counter
*/
void pop(stack_t **head, unsigned int line)
{
stack_t *next;
if (*head != NULL)
{
next = (*head)->next;
(*head)->next = NULL;
*head = next;
if (next != NULL)
{
next->prev = NULL;
}
}
else
err_pop(line);
}

/**
* pint - Print the value at the top of the stack
* @head: Double pointer to the top of the stack
* @line: line number
*/
void pint(stack_t **head, unsigned int line)
{
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}

