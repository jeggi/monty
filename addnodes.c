#include "monty.h"
/**
 * addnodes - this add node to the head stack
 * @head: this is the head of the stack
 * @n: this is a new_value
 * Return: no return
*/
void addnodes(stack_t **head, int n)
{

	stack_t *new_nodes, *aux;

	aux = *head;
	new_nodes = malloc(sizeof(stack_t));
	if (new_nodes == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_nodes;
	new_nodes->n = n;
	new_nodes->next = *head;
	new_nodes->prev = NULL;
	*head = new_nodes;
}
