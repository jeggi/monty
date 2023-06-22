#include "monty.h"
/**
 * f_palls - This prints the stack
 * @head: This is the stack head
 * @count: no used
 * Return: no return
*/
void f_palls(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
