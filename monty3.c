#include "monty.h"

/**
 * mulNodes - Multiplies the top two nodes.
 * @top: Pointer
 * @line_number: Int
 */
void mulNodes(stack_t **top, unsigned int line_number)
{
	int mul;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		more_error(8, line_number, "mul");

	(*top) = (*top)->next;
	mul = (*top)->n * (*top)->prev->n;
	(*top)->n = mul;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * modNodes - Finds the mod of the top two nodes
 * @top: Pointer
 * @line_number: line
 */
void modNodes(stack_t **top, unsigned int line_number)
{
	int mod;

	if (top == NULL || *top == NULL || (*top)->next == NULL)

		more_error(8, line_number, "mod");


	if ((*top)->n == 0)
		more_error(9, line_number);
	(*top) = (*top)->next;
	mod = (*top)->n % (*top)->prev->n;
	(*top)->n = mod;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * print_char - print Ascii.
 * @top: Pointer
 * @line_number: ln
 */
void print_char(stack_t **top, unsigned int line_number)
{
	int ascii;

	if (top == NULL || *top == NULL)
		string_error(11, line_number);

	ascii = (*top)->n;
	if (ascii < 0 || ascii > 127)
		string_error(10, line_number);
	printf("%c\n", ascii);
}
/**
 * rotl - rotate stack
 * @top: Pointer
 * @ln: Int
 */
void rotl(stack_t **top, __attribute__((unused))unsigned int ln)
{
	stack_t *ptr;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		return;

	ptr = *top;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = *top;
	(*top)->prev = ptr;
	*top = (*top)->next;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
}
