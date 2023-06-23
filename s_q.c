#include "monty.h"

/**
* stack - Sets the format of the data to a stack (LIFO)
* @head: Head of the list
* @line: Number of the line
* Return: Void - Nothing
**/
void stack(stack_t **head, unsigned int line)
{
(void)head;
(void)line;
stack_mode = 1;
}

/**
* queue - Sets the format of the data to a queue (FIFO)
* @head: Head of the list
* @line: Number of the line
* Return: Void - Nothing
**/
void queue(stack_t **head, unsigned int line)
{
(void)head;
(void)line;
stack_mode = 0;
}