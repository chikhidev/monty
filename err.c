#include "monty.h"

/**
* err_push - Handles error for incorrect usage of the push instruction
* @line: Line number where the error occurred
*
* Description: Prints an error message indicating the correct usage of the
* push instruction, along with the line number where the error occurred, and
* exits the program with a failure status.
*/

void err_push(int line)
{
fprintf(stderr, "L%d: usage: push integer\n", line);
exit(EXIT_FAILURE);
}

/**
* err_malloc - Handles error for a failed memory allocation
*
* Description: Prints an error message indicating that a memory allocation
* failed, and exits the program with a failure status.
*/

void err_malloc(void)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

/**
* err_usage - Handles error for incorrect usage of the program
*
* Description: Prints an error message indicating the correct usage of the
* program, and exits the program with a failure status.
*/

void err_usage(void)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

/**
* err_file - Handles error for inability to open a file
* @arg: Name of the file that couldn't be opened
*
* Description: Prints an error message indicating that the specified file
* couldn't be opened, along with the file name, and exits the program with
* a failure status.
*/

void err_file(char *arg)
{
fprintf(stderr, "Error: Can't open file %s\n", arg);
exit(EXIT_FAILURE);
}

/**
* err_pop - Handles error for attempting to pop an empty stack
* @line: Line number where the error occurred
*
* Description: Prints an error message indicating that the stack is empty
* and cannot be popped, along with the line number where the error occurred,
* and exits the program with a failure status.
*/

void err_pop(int line)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line);
exit(EXIT_FAILURE);
}
