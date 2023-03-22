#include "monty.h"
/**
 * printTopOfStack - A function that prints the top of a stack
 * @top: Pointer to the top
 * @line_number: Line number
 */
void printTopOfStack(stack_t **top, unsigned int line_number)
{
	if (top == NULL || *top == NULL)
	{
		more_error(6, line_number);
	}
	printf("%d\n", (*top)->n);
}

/**
 * popTop - Deletes the first node
 * @top: Pointer
 * @line_number: line
 */
void popTop(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (top == NULL || *top == NULL)
		more_error(7, line_number);

	ptr = *top;
	*top = ptr->next;
	if (*top != NULL)
		(*top)->prev = NULL;
	free(ptr);
}

/**
 * swapNodes - swap top
 * @top: Pointer
 * @line_number: Int.
 */
void swapNodes(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		more_error(8, line_number, "swap");
	ptr = (*top)->next;
	(*top)->next = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = *top;
	ptr->next = *top;
	(*top)->prev = ptr;
	ptr->prev = NULL;
	*top = ptr;
}

/**
 * addNodes - Adds to node
 * @top: Pointer
 * @line_number: Int.
 */
void addNodes(stack_t **top, unsigned int line_number)
{
	int sum;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		more_error(8, line_number, "add");

	(*top) = (*top)->next;
	sum = (*top)->n + (*top)->prev->n;
	(*top)->n = sum;
	free((*top)->prev);
	(*top)->prev = NULL;
}


/**
 * nop - notching.
 * @top: add
 * @line_number: line
 */
void nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}
