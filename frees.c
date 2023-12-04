#include "shell.h"

/**
 * free_args - Frees an array of strings.
 * @tokenized: The array of strings to be freed.
 */
void free_args(char **tokenized)
{
	int i = 0;

	if (tokenized != NULL)
	{
		while (tokenized[i])
		{
			free(tokenized[i]);
			i++;
		}
		free(tokenized[i]);
		free(tokenized);
	}
	tokenized = NULL;
}

/**
 * free_list - Frees a linked list.
 * @head: A pointer to the head of the list.
 */
void free_list(list_t *head)
{
	list_t *node, *ptr;

	node = head;
	while (node)
	{
		ptr = node->next;
		free(node->str);
		free(node);
		node = ptr;
	}
	head = NULL;
}

/**
 * sh_free - Inputed in main function.
 * @info: argument passed in.
 * @x: sec argument passed in.
 */
void sh_free(hsh *info, int x)
{

	if (info->args != NULL)
	{
		if (!x)
		{
			if (info->env != NULL)
			{
				free_args(info->env);
			}
			
			free_args(info->args);
		}
	}


	if (x)
	{
	
		free_list(info->environ);
		info->envir = NULL;
	}

}


