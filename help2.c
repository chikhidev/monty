#include "monty.h"

/**
 * full_buff - Complete the buffer with numbers
 * @num: Number to convert to a string
 * @base: Base number
 * @buff: Buffer to be completed
 * @buff_size: Size of the buffer
 *
 * Return: void
 */
void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

/**
 * tokerr - Set the last element of the instructions array as an error code
 * @error_status: Error code to be set as a string
 */
void tokerr(int error_status)
{
	int token_len = 0, i = 0;
	char *exit_str = NULL;
	char *new_token = NULL;

	token_len = array_len();
	new_token = malloc(sizeof(char) * (token_len + 2));
	if (!new_token)
	{
		stderr_malloc();
		return;
	}

	while (i < token_len)
	{
		new_token[i] = globalvar.token2[i];
		i++;
	}

	exit_str = int_to_str(error_status);
	if (!exit_str)
	{
		free(new_token);
		stderr_malloc();
		return;
	}

	free(globalvar.token2);
	globalvar.token2 = new_token;
}

