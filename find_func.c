#include "monty.h"

/**
* find_func - Find and execute the appropriate command based on input
* @token: Line arguments string
* @line: Line number
* @head: Pointer to the top of the stack
*/
void find_func(stack_t **head, char *token, unsigned int line)
{
instruction_t instructions[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
{NULL, NULL}
};

unsigned long i = 0;

char *cmd = strtok(token, " \t");

if (cmd == NULL || cmd[0] == '#')
return;

cmd = remove_space(cmd);

while (i < (sizeof(instructions) / sizeof(instructions[0])))
{
if (strcmp(instructions[i].opcode, cmd) == 0)
{
instructions[i].f(head, line);
return;
}
i++;
}

if (cmd[0] != '#')
err_unk(line, cmd);
}
