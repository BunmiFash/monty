#include "monty.h"

/**
 * open_file - open file.
 * @file_name: file
 * Returns: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		error(2, file_name);
	read_file(fd);
	fclose(fd);
}


/**
 * read_file - read the file
 * @fd: pointer o dec
 * Returns: void.
 */

void read_file(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parse_line(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * parse_line - tokenize line
 * @buffer: line read
 * @line_number: line number.
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: 0 if the opcode is stack else 1 if it isqueue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		error(4);
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_func(opcode, value, line_number, format);
	return (format);
}

/**
 * find_func - finds func for opcode
 * @opcode: opcode.
 * @value: argument of opcode.
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number.
 * if 1 nodes will be entered as a queue.
 * Returns: a void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_begin},
		{"pall", print},
		{"pint",  printTopOfStack},
		{"pop", popTop},
		{"swap", swapNodes},
		{"add", addNodes},
		{"nop", nop},
		{"swap", swapNodes},
		{"add", addNodes},
		{"sub", subNodes},
		{"div", divNodes},
		{"mul", mulNodes},
		{"mod", modNodes},
		{"pchar", print_char},
		{"pstr", print_string},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, ln, opcode);
}


/**
 * call_fun - call function
 * @func: Pointer to func
 * @op: string rep opcode
 * @val: the string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				error(5, ln);
		}
		node = newNode(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_end(&node, ln);
	}
	else
	{
		func(&top, ln);
	}
}
