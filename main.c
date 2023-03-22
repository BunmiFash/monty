#include "monty.h"
/**
 * main - Entry point.
 * @argc: Argument count
 * @argv: List of argument
 * Return: 0
 */

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();

	return (0);
}
