#include "monty.h"

/**
* push - Add node to the stack
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void push(stack_t **stack, unsigned int line_number)
{

int n = 0;

if (globalvar.token2 == NULL)
{
free_stack(*stack);
stderr_int(line_number);
}
if (!_isdigit() || stack == NULL)
{
free_stack(*stack);
stderr_int(line_number);
}
n = atoi(globalvar.token2);
if (*stack  == NULL)
{
create_node_start(stack, n);
}
else
{
create_node_end(stack, n);
}
}

/**
* pall - Print the stack
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void pall(stack_t **stack, unsigned int line_number)
{

stack_t *temp = NULL;


if (*stack == NULL)
{
return;
}
if (*stack == NULL && line_number != 1)
{
free_stack(*stack);
free_globalvars();
exit(EXIT_SUCCESS);
}
temp = *stack;
while (temp->next != NULL)
temp = temp->next;
while (temp->prev != NULL)
{
printf("%d", temp->n);
temp = temp->prev;
printf("\n");
}
printf("%d\n", temp->n);
}


/**
* pint - Print the top value of the stack
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void pint(stack_t **stack, unsigned int line_number)
{

stack_t *temp = NULL;

if (stack == NULL || *stack == NULL)
{
pint_e(line_number);
return;
}
temp = *stack;
while (temp->next != NULL)
temp = temp->next;

printf("%d", temp->n);
printf("\n");
}

/**
* swap - Swap the top two elements of the stack
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *temp;
int i, j;

if (*stack == NULL || stack == NULL)
op_e(line_number, "swap");

temp = (*stack)->next;
if ((*stack)->next == NULL)
op_e(line_number, "swap");
while (temp->next != NULL)
{
temp = temp->next;
}
i = temp->n;
j = temp->prev->n;
temp->n = j;
temp->prev->n = i;
}

/**
* nop - Do nothing
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

