#include "monty.h"
/**
 * f_pushs - This add node to the stack
 * @head: This is the stack head
 * @count: line_number
 * Return: no return
*/
void f_pushs(stack_t **head, unsigned int count)
{
	int n, s = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			s++;
		for (; bus.arg[s] != '\0'; s++)
		{
			if (bus.arg[s] > 57 || bus.arg[s] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnodes(head, n);
	else
		addq(head, n);
}
