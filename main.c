#include "monty.h"
/**
* main - Entry point of the program
* @ac: Number of command-line arguments
* @av: Array of command-line arguments
*
* Return: 0 on success
*/

int main(int ac, char *av[])
{
FILE *file;
char *line = NULL, *line_args;
size_t line_size;
int line_counter = 0;
stack_t *head = NULL;

if (ac != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(av[1], "r");

if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", av[1]);
exit(EXIT_FAILURE);
}

while (_getline(&line, &line_size, file) != -1)
{
line_args = strtok(line, "\n");
line_counter++;

if (line_args)
find_func(line_args, line_counter, &head);
}

if (line)
free(line);
fclose(file);
exit(EXIT_SUCCESS);

return (0);
}
