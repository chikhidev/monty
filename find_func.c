#include "monty.h"

/**
* find_func - Find and execute the appropriate command based on input
* @line_args: Line arguments string
* @line: Line number
* @head: Pointer to the top of the stack
*/
void find_func(char *line_args, int line, stack_t **head)
{
char *cmd = strtok(line_args, " \t");
char *param;
int int_par;

if (cmd == NULL || cmd[0] == '#')
return;

if (strcmp(cmd, "push") == 0)
{
param = strtok(NULL, " \t");
param = remove_space(param);

if (param == NULL)
<<<<<<< HEAD
err_push(line);
=======
{
fprintf(stderr, "L%d: usage: push integer\n", line);
exit(EXIT_FAILURE);
}
>>>>>>> 563e8344644ab1b51cb7ae169bcbac2cf4ea2e5e

int_par = atoi(param);
if (int_par == 0 && strcmp(param, "0") != 0)
err_push(line);

push(head, int_par);
}
else if (strcmp(cmd, "pall") == 0)
{
pall(*head);
}
else
<<<<<<< HEAD
err_unk(line, remove_space(cmd));
=======
{
fprintf(stderr, "L%d: unknown instruction %s\n", line, remove_space(cmd));
exit(EXIT_FAILURE);
}
>>>>>>> 563e8344644ab1b51cb7ae169bcbac2cf4ea2e5e
}

