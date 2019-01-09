#include "header.h"
/*
**sources 
**https://www.geeksforgeeks.org/doubly-linked-list/
**https://www.youtube.com/watch?v=VOQNf1VxU3Q
*/

/*
**Initial and create node element of doubly circular linked list
**by mallocing space for it, and setting its char content to data
**as well as next and previous to null.
*/
struct s_node *createNode(char data)
{
	struct s_node *list;

	list = (struct s_node *)malloc(sizeof(struct s_node));
	list->c = data;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void insert(struct s_node **head, char c)
{
    //if the head is empty, which is due to main setting it as NULL
	if (*head == NULL)
	{
		*head = createNode(c);
		(*head)->next = (*head);
		(*head)->prev = (*head);
		return;
	}
	struct s_node *node = createNode(c);
	node->next = *head;
	node->prev = (*head)->prev;
	(*head)->prev->next = node;
	(*head)->prev = node;
}

char *precious(int *text, int size)
{
	char *str = malloc(size + 1);
	struct s_node *list = NULL;
	if (size < 0)
		return (NULL);
	for (int i = 0; CS[i] != '\0'; i++)
		insert(&list, CS[i]);
	for (int j = 0; j < size; j++)
	{
		if (text[j] >= 0)
			while (text[j]--)
				list = list->next;
		else
			while (text[j]++)
				list = list->prev;
		str[j] = list->c;
	}
	return (str);
}
