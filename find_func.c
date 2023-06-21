#include "monty.h"

/**
* find_func - Find and execute the appropriate command based on input
* @line_args: Line arguments string
* @line: Line number
* @head: Pointer to the top of the stack
*/
void find_func(char *line_args, int line, stack_t *head)
{
char *cmd = strtok(line_args, " ");
char *param;
int int_par;


if (strcmp(cmd, "push") == 0)
{
param = strtok(NULL, " ");

if (param == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line);
exit(EXIT_FAILURE);
}

int_par = atoi(param);
if (int_par == 0 && strcmp(param, "0") != 0)
{
fprintf(stderr, "L%d: usage: push integer\n", line);
exit(EXIT_FAILURE);
}

push(&head, int_par);
}
else if (strcmp(cmd, "pall") == 0)
{
pall(head);
}

else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd);
exit(EXIT_FAILURE);
}


}
