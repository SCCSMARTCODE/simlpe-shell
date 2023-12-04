#include "shell.h"

/**
 * add_node_begin - Add a new node to the beginning of a linked list.
 * @head: A pointer to the head pointer of the list.
 * @str: The string to be stored in the new node.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */
list_t *add_node_begin(list_t **head, const char *str)
{
	list_t *ptr = malloc(sizeof(list_t));

	if (ptr == NULL)
	{
		return (NULL);
	}
	ptr->str = my_strdup(str);
	ptr->next = *head;
	*head = ptr;

	return (ptr);
}

/**
 * add_node_end - Add a new node to the end of a linked list.
 * @head: A pointer to the head pointer of the list.
 * @str: The string to be stored in the new node.
 *
 * Return: A pointer to the head of the list, or NULL on failure.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *ptr = *head;
	list_t *temp = malloc(sizeof(list_t));

	if (temp == NULL)
	{
		return (NULL);
	}

	temp->str = my_strdup(str);
	temp->next = NULL;
	if (ptr == NULL)
	{
		*head = temp;
	}
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	return (*head);
}

