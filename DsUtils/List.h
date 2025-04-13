/********************************************************************
 *          SINGLY LINKED LIST
 * This utility provides basic operartions on singly linked list:-
 * 1. Insert a node at nth position.
 * 2. Delete a node contains given key.
 * 3. Delete a given node.
 * 4. Reverse the list.
 * 5. Print the list items.
 *******************************************************************/

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	Node* next;
}Node;

void Insert(Node** head, int x);
void Insert(Node** head, Node**tail, int x);
void Delete(Node* head, int key);
void Delete(Node* head, Node* node);
void Reverse(Node** head);
void Print(Node* head);


#endif
