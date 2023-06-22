#include "monty.h"

/**
* find_func - Searches for the appropriate function.
* @token: Pointer to the instruction token.
* @stack: Pointer to the top of the stack.
* @line_number: Line number of the instruction.
* Return: 0 on success, or an error code if the instruction is not found.
*/
int find_func(char *token, stack_t **stack, unsigned int line_number)
{
instruction_t op_built[] = {
{ "push", push },
{ "pall", pall },
{ "pop", pop },
{ "add", add },
{ "nop", nop },
{ "sub", sub },
{ "pall", pall },
{ "pint", pint },
{ "swap", swap },
{ "mul", mul },
{ "div", _div },
{ "pchar", pchar },
{ "mod", mod },
{ "\n", nop },
{ " ", nop },
{ "\t", nop },
{ "pstr", pstr },
{ "rotl", rotrl },
{ "rotr", rotr },
{ NULL, NULL }
};
int i, found = 0;
char *instruction = NULL;
if (stack == NULL || token == NULL)
return (0);
instruction = token;
for (i = 0; op_built[i].opcode != NULL; i++)
{
if (strcmp(instruction, op_built[i].opcode) == 0)
{
found = (1);
op_built[i].f(stack, line_number);
break;
}
}
if (found == 0)
stderr_unknown(token, line_number);
return (0);
}

