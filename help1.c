#include "monty.h"

/**
* int_to_str - Convert an integer to a string
* @num: Number to convert
*
* Return: Pointer to the converted string, or NULL if fails to allocate memory
*/
char *int_to_str(int num)
{
long num_v = 0;
unsigned int tmp;
int len = 0;
char *ret;

tmp = absolute_value(num);
len = len_buff_uint(tmp, 10);

if (num < 0 || num_v < 0)
len++;

ret = malloc((len + 1) * sizeof(char));
if (!ret)
return (NULL);

full_buff(tmp, 10, ret, len);
if (num < 0 || num_v < 0)
ret[0] = '-';

return (ret);
}

/**
* absolute_value - Calculate the absolute value of an integer
* @i: Integer to get the absolute value of
*
* Return: Unsigned integer representing the absolute value of i
*/
unsigned int absolute_value(int i)
{
if (i < 0)
return (-(unsigned int)i);
return ((unsigned int)i);
}

/**
* len_buff_uint - Calculate the length of a buffer for an unsigned integer
* @num: Number to calculate the length for
* @base: Base of the number representation used by the buffer
*
* Return: Length of the buffer
*/
int len_buff_uint(unsigned int num, unsigned int base)
{
int len = 1;

while (num > base - 1)
{
len++;
num /= base;
}
return (len);
}

/**
* _isdigit - Check if a string consists only of digits
*
* Return: 1 if the string consists only of digits, 0 otherwise
*/
int _isdigit(void)
{
int i = 0;

if (globalvar.token2[0] == '-' || globalvar.token2[0] == '+')
i++;

while (globalvar.token2[i])
{
if (!isdigit(globalvar.token2[i]))
return (0);
i++;
}

return (1);
}

/**
* array_len - Calculate the length of an array of tokens
*
* Return: Length of the token array
*/
unsigned int array_len(void)
{
unsigned int token_len = 0;

while (globalvar.token2[token_len])
token_len++;

return (token_len);
}
