#include "monty.h"
/**
 * f_add - this adds the top two elements of the stack.
 * @head: this is stack head
 * @count: this is line_number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int count)
{
	stack_t *s;
	int len = 0, aux;

	s = *head;
	while (s)
	{
		s = s->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	s = *head;
	aux = s->n + s->next->n;
	s->next->n = aux;
	*head = s->next;
	free(s);
}
