#include "monty.h"

/**
* pall - Print all elements in the stack
* @head: Pointer to the top of the stack
*/
void pall(stack_t *head)
{
stack_t *curr = head;

if (head == NULL)
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
* @val: Value to be pushed
*/
void push(stack_t **head, int val)
{
stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = val;
new_node->prev = NULL;

if (*head != NULL)
{
new_node->next = (*head);
(*head)->prev = new_node;
}
else
new_node->next = NULL;

(*head) = new_node;

}


/**
* pop - Pop the top element from the stack
* @head: Double pointer to the top of the stack
*/
void pop(stack_t **head)
{
stack_t *next;
if (*head != NULL)
{
next = (*head)->next;
next->prev = NULL;

(*head)->next = NULL;
*head = next;
}
else
{
printf("L<line_number>: can't pop an empty stack");
exit(1);
}
}

/**
* pint - Print the value at the top of the stack
* @head: Double pointer to the top of the stack
* @line: line number
*/
void pint(stack_t **head, int line)
{
if (*head == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
