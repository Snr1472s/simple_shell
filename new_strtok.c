#include "shell.h"

/**
 * check_match - checks if a character matches any in a string
 * @c: character to check
<<<<<<< HEAD
 * @str: str parameter
 * Return: 1 if match, 0 if not
 */

unsigned int check_match(char c, const char *str)
{
        unsigned int i;

        for (i = 0; str[i] != '\0'; i++)
        {
                if (c == str[i])
                        return (1);
        }
        return (0);
=======
 * @str: string to check
 * Return: 1 if match, 0 if not
 */
unsigned int check_match(char c, const char *str)
{
	unsigned int w;

	for (w = 0; str[w] != '\0'; w++)
	{
		if (c == str[w])
			return (1);
	}
	return (0);
>>>>>>> 192b35dc788554b387db4bbc58ef3c27a3726055
}


/**
 * new_strtok - custom strtok
 * @str: str parameter
 * @delim: delimiter to tokensize against
 * Return: pointer to the next token or NULL
 */

char *new_strtok(char *str, const char *delim)
{
	static char *token_start;
	static char *next_token;
	unsigned int s;

	if (str != NULL)
		next_token = str;
	token_start = next_token;
	if (token_start == NULL)
		return (NULL);
	for (s = 0; next_token[s] != '\0'; s++)
	{
		if (check_match(next_token[s], delim) == 0)
			break;
	}
	if (next_token[s] == '\0' || next_token[s] == '#')
	{
		next_token = NULL;
		return (NULL);
	}
	token_start = next_token + s;
	next_token = token_start;
	for (s = 0; next_token[s] != '\0'; s++)
	{
		if (check_match(next_token[s], delim) == 1)
			break;
	}
	if (next_token[s] == '\0')
		next_token = NULL;
	else
	{
		next_token[s] = '\0';
		next_token = next_token + s + 1;
		if (*next_token == '\0')
			next_token = NULL;
	}
	return (token_start);
}
