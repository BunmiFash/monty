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
