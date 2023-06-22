#include "monty.h"
/**
  *f_subs- This is sustration
  *@head: This is the stack head
  *@count: This is line_number
  *Return: no return
 */
void f_subs(stack_t **head, unsigned int count)
{
	stack_t *aux;
	int subs, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	subs = aux->next->n - aux->n;
	aux->next->n = subs;
	*head = aux->next;
	free(aux);
}
