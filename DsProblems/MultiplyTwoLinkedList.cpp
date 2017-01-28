/*********************************************************************
 *
 * Multiply two big integer present in linked list and store the result
 * in new linked list.
 * Example:-
 * List1-> [2]->[7]->[4]->(NULL)
 * List2-> [9]->[2]->[9]->[3]->(NULL)
 * 
 * Result->[2]->[5]->[4]->[6]->[2]->[8]->[2]->(NULL)
 *
 *********************************************************************/

#include "List.h"
#include <iostream>
#include <stdio.h>


using namespace std;


#define FOR(i,a,b) for( int i = (a); i < (b); ++i)

typedef Node* p_Node;

void mulTwoNode(int m, int& carry, p_Node& H, p_Node& Gap, p_Node& Pos)
{
	if(Gap == NULL )
	{
		Insert(&H, (m + carry)%10);
		carry = (m + carry)/10;

		return;
	}

	m = Pos->data + m + carry;
	Pos->data = m%10;
	Pos = Pos->next;
	carry = m/10;    
}


void mulUtil(p_Node h1, p_Node h2, int& carry, p_Node& H, p_Node& Gap, p_Node& Pos)
{
	if(h2->next != NULL)
		mulUtil(h1, h2->next, carry, H, Gap, Pos);

	int m = h1->data * h2->data;
	mulTwoNode(m, carry, H, Gap, Pos);
}

void mul(p_Node h1, p_Node h2, int& carry, p_Node& H, p_Node& Gap, p_Node& Pos)
{
	if(h1->next != NULL)
		mul(h1->next, h2, carry, H, Gap, Pos);

	mulUtil(h1, h2, carry, H, Gap, Pos);

	if(carry)
	{
		Insert(&H, carry);
		carry = 0;
	}
	Pos = Gap = (Gap == NULL)? H->next : Gap->next;
}

void multiply(p_Node h1, p_Node h2)
{
	p_Node Res = NULL;
	p_Node Gap = NULL;
	p_Node Pos = NULL;
	int carry = 0;
	mul(h1, h2, carry, Res, Gap, Pos);

	Reverse(&Res);
	Print(Res);
}

int main()
{
	Node *h1 = NULL, *h2 = NULL;
	p_Node Res = NULL;

	Insert(&h1, 2);
	Insert(&h1, 7);
	Insert(&h1, 4);


	Insert(&h2, 9);
	Insert(&h2, 2);
	Insert(&h2, 9);
	Insert(&h2, 3);

	Print(h1);
	Print(h2);

	multiply(h1, h2);

	return 0;
}
