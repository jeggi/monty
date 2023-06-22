#include "monty.h"
/**
 * f_divi - This divides the top two elements of the stack.
 * @head: This is the stack head
 * @counter: This is line_number
 * Return: no return
*/
void f_divi(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
