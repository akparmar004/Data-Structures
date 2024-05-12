//inorder means == left - root - right...

#include "header.h"

void inorder(bst *ptr)
{
	if(ptr)
	{
		inorder(ptr -> left);
		printf("%d ",ptr -> data);
		inorder(ptr -> right);
	}
}
