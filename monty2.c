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
 * @stack: Pointer
 * @line_number: line
 */
void popTop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL)
		more_error(7, line_number);

	ptr = *stack;
	*stack = ptr->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(ptr);
}
