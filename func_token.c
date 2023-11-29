#include "main.h"

/**
 * tokenizer - split tha args
 * @buffer: the main buffer to split
 * @del: the delimeter to split with
 * Return: a pointer to splited buffer or NULL
 */

char **tokenizer(char *buffer, char *del)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	token = strtok(buffer, del);
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
