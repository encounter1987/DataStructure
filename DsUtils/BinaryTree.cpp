#include "BinaryTree.h"

#include<iostream>
#include<stdio.h>
#include<string>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <limits.h>
#include <vector>

#define ABS(n)       (n) < (0) ? (-(n)):(n)
#define MIN(a, b)    (a) < (b)? (a):(b)
#define MAX(a, b)    (a) > (b)? (a):(b)
#define FOR(i, a, b) for( int i = (a); i <=(b); ++i)

#define KEY_SIZE      4
#define FLOOR_HEIGHT  16
#define LEFT_ARM      printf("/")
#define RIGHT_ARM     printf("\\")
#define NEW_LINE      printf("\n")
#define SPACE         printf(" ")
#define N_SPACE(n)    FOR(i,0,n) printf(" ")

#define TEXT          "    "
#define ROOT_POS      70

using namespace std;


inline static int stringToInt(const char* ch)
{
	int val = 0;

	for( int i = 0; ch[i] != '\0'; ++i)
	{
		if(ch[i] == '-') continue;
		val = val*10 + ch[i] - '0';
	}
	if(ch[0] == '-') val = -val;

	return val;
}

static Node* newNode(int val)
{
	Node* _new = new Node();
	_new->data = val;
	_new->left = NULL;
	_new->right = NULL;

	return _new;
}


void deSerialize(Node *&root)
{
	char ch[32];

	if( 1 != scanf("%s", ch) || ch[0] == ')')
	{
		return;
	}

	root = newNode(stringToInt(ch));
	deSerialize(root->left);
	deSerialize(root->right);
}

void Inorder(Node* root)
{
	if(root == NULL)
		return;

	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
}

void Preorder(Node* root)
{
	if(root == NULL)
		return;

	printf("%d ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(Node* root)
{
	if(root == NULL)
		return;

	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->data);
}



int GetHeight(Node* root)
{
    if( root == NULL)
        return 0;

    return (MAX(GetHeight(root->left), GetHeight(root->right)))+1;
}

static void drawTreeLinks(const vector<Node*>& treeData, int levelStart, int width, int& floorHeight, int& leftSpace)
{
	int betSpace = 0;
	FOR(i,1,floorHeight-1)
	{
		N_SPACE(leftSpace+1);

		FOR(k,levelStart,levelStart+width-1)
		{
			treeData[2*k+1] != NULL? LEFT_ARM : SPACE;
			N_SPACE(betSpace-1);
			treeData[2*k+2] != NULL? RIGHT_ARM : SPACE;

			if(k < levelStart+width-1)
			{
				N_SPACE(4*floorHeight-KEY_SIZE-betSpace+1);
			}
		}
		NEW_LINE;
		leftSpace--;
		betSpace += 2;
	}
	floorHeight /= 2;
}

static void PrintNode(const Node* node)
{
	if(node == NULL)
		cout << TEXT;
	else
	{
		int count = 0;
		if(node->data < 0) count ++;

		int n = ABS(node->data);
		while(n)
	   	{ 
			n /= 10; count++; 
		} 
		count = KEY_SIZE - count;

		while(count--) cout <<".";
		cout << node->data;
	}
}

static void drawTree(const vector< Node* >& treeData, int maxHeight)
{
    int levelCount = 1;
    int width = 1;

    int levelStart = 0;
	int leftSpace = ROOT_POS;
	int floorHeight = FLOOR_HEIGHT;

    FOR(h,1,maxHeight)
    {
		N_SPACE(leftSpace);
        FOR(k,levelStart, levelStart+width-1)
        {
			PrintNode(treeData[k]);
			if(k < levelStart+width-1)
			{
				N_SPACE(4*floorHeight-KEY_SIZE-1);
			}
        }
		NEW_LINE;
	
		if(h < maxHeight)
			drawTreeLinks(treeData, levelStart, width, floorHeight, leftSpace);

		levelStart = levelStart + width;
		leftSpace --;
		width <<= 1;
    }    
}

void drawBinaryTree(Node* root)
{
	if(root == NULL)
		return;

    int maxLevel = GetHeight(root);
    int maxSize  = (1 << maxLevel)-1;
    vector< Node* > treeData(maxSize);

    FOR(i,0,treeData.size()-1)
    {
        treeData[i] = NULL;
    }

    treeData[0] = root;
    
    FOR(pos, 0, (maxSize-2)/2)
    {
        if(treeData[pos] != NULL)
        {
            treeData[2*pos+1] = treeData[pos]->left;
            treeData[2*pos+2] = treeData[pos]->right;
        }
    }

    drawTree(treeData, maxLevel);

    cout << endl;
}


