#include "monty.h"

/**
 * rotr - this rotates stack
 * @top: Pointer
 * @ln: line
 */
void rotr(stack_t **top, __attribute__((unused))unsigned int ln)
{
	stack_t *ptr;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		return;

	ptr = *top;

	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = *top;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	(*top)->prev = ptr;
	(*top) = ptr;
}

/**
 * subNodes - Subtracts the top two nodes from each other
 * @top: Pointer to a pointer.
 * @line_number: Int.
 */
void subNodes(stack_t **top,  __attribute__((unused))unsigned int line_number)
{
	int sub;

	if (top == NULL || *top == NULL || (*top)->next == NULL)

		more_error(8, line_number, "sub");


	(*top) = (*top)->next;
	sub = (*top)->n - (*top)->prev->n;
	(*top)->n = sub;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * divNodes - Divides the top two nodes
 * @top: Pointer
 * @line_number: Int.
 */
void divNodes(stack_t **top, unsigned int line_number)
{
	int div;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		more_error(8, line_number, "div");

	if ((*top)->n == 0)
		more_error(9, line_number);
	(*top) = (*top)->next;
	div = (*top)->n / (*top)->prev->n;
	(*top)->n = div;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * print_string - print str
 * @top: Pointer
 * @ln: line
 */
void print_string(stack_t **top, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *ptr;

	if (top == NULL || *top == NULL)
	{
		printf("\n");
		return;
	}

	ptr = *top;
	while (ptr != NULL)
	{
		ascii = ptr->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		ptr = ptr->next;
	}
	printf("\n");
}
