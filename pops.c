#include "monty.h"
/**
 * f_pops - This prints the top
 * @head: This is the stack head
 * @count: This is line_number
 * Return: no return
*/
void f_pops(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
