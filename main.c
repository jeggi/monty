#include "monty.h"
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	char *contents;
	FILE *file;
	size_t size1 = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		contents = NULL;
		read_line = getline(&contents, &size1, file);
		bus.content = contents;
		count++;
		if (read_line > 0)
		{
			executes(contents, &stack, count, file);
		}
		free(contents);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
