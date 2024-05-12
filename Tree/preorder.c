//preorder means ==  root - left - right...

#include "header.h"

void preorder(bst *ptr)
{
	if(ptr)
	{
		printf("%d ",ptr -> data);
		preorder(ptr -> left);
		preorder(ptr -> right);
	}
}
