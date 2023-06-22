#include "monty.h"

/**
* _div - Divide the second top element of the stack by the top element
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void _div(stack_t **stack, unsigned int line_number)
{

stack_t *temp = NULL;
stack_t *temp2 = NULL;
int i = 0, j = 0, flag = 0;

if (*stack == NULL || stack == NULL)
{
op_e(line_number, "div");
}

temp = *stack;
while (temp->next != NULL)
{
temp = temp->next;
i++;
flag = 1;
}
temp2 = *stack;
while (j < (i - 1))
{
temp2 = temp2->next;
j++;
}
if (i == 0 && flag == 0)
free_stack(*stack), op_e(line_number, "div");
else
{
if (temp->n == 0)
div_e(line_number);
temp2->n = temp2->n / temp->n;
temp2->next = NULL;
free(temp);
temp = NULL;
return;
}



}

/**
* mod - Compute the modulo of the second top element by the top element
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void mod(stack_t **stack, unsigned int line_number)
{

stack_t *temp = NULL;
stack_t *temp2 = NULL;
int i = 0, j = 0, flag = 0;

if (*stack == NULL || stack == NULL)
{
op_e(line_number, "mod");
}

temp = *stack;
while (temp->next != NULL)
{
temp = temp->next;
i++;
flag = 1;
}
temp2 = *stack;
while (j < (i - 1))
{
temp2 = temp2->next;
j++;
}
if (i == 0 && flag == 0)
free_stack(*stack), op_e(line_number, "mod");
else
{
if (temp->n == 0)
div_e(line_number);
temp2->n = temp2->n % temp->n;
temp2->next = NULL;
free(temp);
temp = NULL;
return;
}
}

/**
* pstr - Print the string starting at the top of the stack
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *temp = NULL;
(void)line_number;

if (*stack == NULL || stack == NULL)
{
printf("\n");
free_globalvars();
exit(0);
}
temp = *stack;
if (temp->next == NULL && line_number == 2 && (temp->n < 0 || temp->n >= 127))
{
printf("\n");
free_stack(*stack);
free_globalvars();
exit(0);
}
while (temp->next != NULL)
temp = temp->next;
while (temp->prev != NULL)
{
if (temp->n > 0 && temp->n < 127)
{
printf("%c", temp->n);
temp = temp->prev;
}
else
temp = temp->prev;
if (temp->n <= 0 || temp->n >= 127)
{
printf("\n");
return;
}
}
printf("%c\n", temp->n);
}

/**
* rotrl - Rotate the stack to the left
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void rotrl(stack_t **stack, unsigned int line_number)
{

stack_t *temp2 = NULL;
stack_t *temp = NULL;
(void)line_number;

if (*stack == NULL || ((*stack)->next == NULL))
return;
temp = *stack;
while (temp->next != NULL)
temp = temp->next;
temp2 = temp->prev;
temp2->next = NULL;
temp->prev = NULL;
temp->next = *stack;
(*stack)->prev = temp;
*stack = temp;
}

/**
* rotr - Rotate the stack to the right
* @stack: Pointer to the head of the linked list
* @line_number: Line number of the instruction
*
* Return: No return value
*/
void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *temp2 = NULL;
(void)line_number;

if (*stack == NULL)
return;
temp2 = *stack;
while (temp2->next != NULL)
temp2 = temp2->next;
temp2->next = *stack;
(*stack)->prev = temp2;
temp2 = (*stack)->next;
(*stack)->next = NULL;
*stack = temp2;
(*stack)->prev = NULL;
}

