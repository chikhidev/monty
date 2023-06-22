#include "monty.h"

/**
* node_stack_create - create a node stack.
* @stack: A pointer to top and bottom stack.
* Return: EXIT SUCCESS
*/
int node_stack_create(stack_t **stack)
{
stack_t *p;

p = malloc(sizeof(stack_t));
if (p == NULL)
stderr_malloc();
p->n = STACK;
p->prev = NULL;
p->next = NULL;

*stack = p;

return (EXIT_SUCCESS);
}
/**
* node_stack_free - takes a stack and frees it.
* @stack: stack.
*/
void node_stack_free(stack_t **stack)
{
stack_t *temp_node = *stack;

while (*stack)
{
temp_node = (*stack)->next;
free(*stack);
*stack = temp_node;
}
}
/**
* opcode_process -processes if STACK or QUEUE.
* @stack: A pointer to top and bottom stack.
* Return: The value of Stack or Queue
*/
int opcode_process(stack_t *stack)
{
int ret_val = 2;

if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (ret_val);
}

