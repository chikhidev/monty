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
err_push(line);

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
err_unk(line, remove_space(cmd));
}

