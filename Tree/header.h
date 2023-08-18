#include<stdio.h>
#include<stdlib.h>
typedef struct BSTNode
{
	struct BSTNode *left;
	int data;
	struct BSTNode *right;
	
} bst;

bst* insert(bst*,int);
bst* search(bst*,int);
void preorder(bst*);
void inorder(bst*);
void postorder(bst*);
bst* delete(bst*,int);
bst* minValue(bst*);
bst* maxValue(bst*);
int count(bst*);
