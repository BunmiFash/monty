#include "monty.h"
/**
 * newNode - A function that creates a new node
 * @n: Data contained in the new node
 * Return: The new node
 */

stack_t *newNode(int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		error(4);
	}

	newNode->prev = NULL;
	newNode->n = n;
	newNode->next = NULL;

	return (newNode);
}

/**
 * free_nodes - A function that frees nodes
 */
void free_nodes(void)
{
	stack_t *ptr;

	if (top == NULL)
	{
		return;
	}

	while (top != NULL)
	{
		ptr = top;
		top = top->next;
		free(ptr);
		ptr = NULL;
	}
}

/**
 * add_end - A function that adds a new node to a queue / end of a list.
 * @newNode: New Node to be added to the queue
 * @ln: Line Number
 */
void add_end(stack_t **newNode, __attribute__((unused))unsigned  int ln)
{
	stack_t *ptr;

	if (newNode == NULL || *newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	/* CHECK FOR EMPTY LIST*/
	if (top == NULL)
	{
		top = *newNode;
		return;
	}
	ptr = top;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = *newNode;
	(*newNode)->prev = ptr;
}
/**
 * add_begin - A function that adds a node to the beginning of a list/ stack
 * @newNode: New Node to be added
 * @ln: Line Number
 * Return: void
 */
void add_begin(stack_t **newNode, __attribute__((unused))unsigned int ln)
{
	stack_t *ptr;

	if (newNode == NULL || *newNode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	/* FOR EMPTY LIST*/
	if (top == NULL)
	{
		top = *newNode;
		return;
	}
	ptr = top;
	top = *newNode;
	top->next = ptr;
	ptr->prev = top;
}
/**
 * print - A function that prints the data of each node
 * @top: Pointer =to the first node
 * @line_number: Line number
 */
void print(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	(void) line_number;
	if (top == NULL)
	{
		exit(EXIT_FAILURE);
	}
	ptr = *top;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
