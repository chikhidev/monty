#include "monty.h"

/**
* err_unk - unk cmd err
* @line: line count
* @cmd: cmdi
* Return: void
*/
void err_unk(int line, char *cmd)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd);
exit(EXIT_FAILURE);
}
