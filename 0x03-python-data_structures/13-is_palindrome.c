#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list
 * @head: Pointer to the head of the listint_t list
 * @n: Integer to be added in the listint_t list
 *
 * Return: Address of the new element, or NULL if it fails
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * is_palindrome - Checks if a singly linked listint_t is a palindrome
 * @head: Pointer to the head of the listint_t list
 *
 * Return: 1 if the list is a palindrome, 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	listint_t *head2 = *head;
	listint_t *aux = NULL, *aux2 = NULL;

	if (*head == NULL || head2->next == NULL)
		return (1);
	while (head2 != NULL)
	{
		add_nodeint(&aux, head2->n);
		head2 = head2->next;
	}
	aux2 = aux;
	while (*head != NULL)
	{
		if ((*head)->n != aux2->n)
		{
			free_listint(aux);
			return (0);
		}
		*head = (*head)->next;
		aux2 = aux2->next;
	}
	free_listint(aux);
	return (1);
}
