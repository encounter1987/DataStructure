#include "List.h"

static Node* newNode(int x)
{
	Node* tmp =  (Node*)malloc(sizeof(Node));
	tmp-> data = x;
	tmp-> next = NULL;

	return tmp;
}

void Insert(Node** head, int x)
{
	if( *head == NULL)
	{
		*head = newNode(x);

		return;
	}

	Node* tmp = *head;
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = newNode(x);
}


void Delete(Node* head, int key)
{
	Node* prev;
	while(head != NULL && head->data != key)
	{
		prev = head;
		head = head->next;
	}

	if(head == NULL)
	{
		printf("WARNING: The Key to be deleted does't exist in this list\n");

		return;
	}

	prev->next = head->next;
	delete head;
}

void Delete(Node* head, Node* node)
{
	Node* prev;
	while(head != NULL && head != node)
	{
		prev = head;
		head = head->next;
	}

	if(head == NULL)
	{
		printf("WARNING: The node to be deleted does't exist in this list\n");

		return;
	}

	prev->next = head->next;
	delete head;
}

void Reverse(Node** head)
{
	Node *first = *head, *second = (*head)->next, *third;
	third = second->next;
	second->next = first;
	first->next = NULL;

	while(third)
	{
		first = second;
		second = third;
		third = second->next;
		second->next = first;
	}

	*head = second;
}

void Print(Node* head)
{
	while(head)
	{
		printf("[%d]->", head->data);
		head = head->next;
	}
	printf("(NULL)\n");
}
