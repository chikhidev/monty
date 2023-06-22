#include "monty.h"
/**
 * remove_space - Remove space and tab characters from a string
 * @str: The input string to remove spaces and tabs from
 *
 * Return: A new dynamically allocated string with spaces and tabs removed
 */
char *remove_space(char *str)
{
char *holder = (char *)malloc(strlen(str) + 1);
int i = 0, j = 0;

if (holder == NULL)
return (str);

while (str[i] != '\0')
{
if (str[i] != ' ' && str[i] != '\t')
{
holder[j] = str[i];
j++;
}
i++;
}
holder[j] = '\0';

return (holder);
}

