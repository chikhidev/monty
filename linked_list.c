#include "monty.h"

/**
* create_node_start - Create a new node and add it to the top of the stack.
* @stack: A pointer to the top of the stack.
* @n: The value to be stored in the new node.
* Return: The newly created node.
*/
stack_t *create_node_start(stack_t **stack, int n)
{
stack_t *new_node;

if (stack == NULL)
return NULL;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
stderr_malloc();
return NULL;
}

new_node->n = n;
new_node->next = *stack;
new_node->prev = NULL;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
return new_node;
}

/**
* create_node_end - Create a new node and add it to the end of the stack.
* @stack: A pointer to the top of the stack.
* @n: The value to be stored in the new node.
* Return: The newly created node.
*/
stack_t *create_node_end(stack_t **stack, int n)
{
stack_t *new_node;
stack_t *temp;

if (stack == NULL)
return NULL;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
stderr_malloc();
return NULL;
}

temp = *stack;
while (temp != NULL && temp->next != NULL)
temp = temp->next;

if (temp != NULL)
temp->next = new_node;

new_node->n = n;
new_node->prev = temp;
new_node->next = NULL;

return new_node;
}

/**
* add_dnodeint - Add a new node at the beginning of a doubly linked list.
* @head: A pointer to the head of the doubly linked list.
* @n: The integer value to be stored in the new node.
* Return: The pointer to the new node.
*/
stack_t *add_dnodeint(stack_t **head, int n)
{
stack_t *new_node;

if (head == NULL)
return NULL;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
return NULL;

new_node->n = n;
new_node->prev = NULL;
new_node->next = *head;

if (*head != NULL)
(*head)->prev = new_node;

*head = new_node;
return new_node;
}

