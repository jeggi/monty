#include "monty.h"
/**
 * f_swaps - This adds the top two elements of the stack.
 * @head: This is the stack head
 * @count: This is line_number
 * Return: no return
*/
void f_swaps(stack_t **head, unsigned int count)
{
	stack_t *h;
	int lenght = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		lenght++;
	}
	if (lenght < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
