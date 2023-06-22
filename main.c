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
unsigned int line_counter = 1;
stack_t *head = NULL;

if (ac != 2)
err_usage();

file = fopen(av[1], "r");

if (!file)
err_file(av[1]);

while (_getline(&line, &line_size, file) != -1)
{
line_args = strtok(line, "\n");

line_counter++;
if (line_args)
find_func(&head, line_args, line_counter);

else if (!line_args)
continue;



}

if (line)
free(line);

free_all(&head);
fclose(file);
exit(EXIT_SUCCESS);
}

