#include "monty.h"
/**
  *f_rota- This rotates the stack to the bottom
  *@head: This is the stack head
  *@count: This is line_number
  *Return: no return
 */
void f_rota(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
