#include "monty.h"
/**
* executes - This executes the opcode
* @stack: This is the head linked list - stack
* @count: This is line_counter
* @file: This is the pointer to monty file
* @content: line content
* Return: no return
*/
int executes(char *content, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
				{"pushs", f_pushs}, {"palls", f_palls}, {"pints", f_pints},
				{"pops", f_pops},
				{"swaps", f_swaps},
				{"add", f_add},
				{"nothing", f_nothing},
				{"subs", f_subs},
				{"divi", f_divi},
				{"mult", f_mult},
				{"mods", f_mods},
				{"pchars", f_pchars},
				{"pstrs", f_pstrs},
				{"rot", f_rot},
				{"rota", f_rota},
				{"q", f_q},
				{"stacks", f_stacks},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
