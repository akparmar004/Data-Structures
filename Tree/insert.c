#include "header.h"

bst* insert(bst *ptr,int d)
{
	bst* new = NULL;
	if(ptr == NULL)
	{
		new = calloc(1, sizeof(bst));
		if(new == NULL)
		{
			printf("Node not created..\n");
			return ptr;
		}
		new -> data = d;
		ptr = new;
	}
	else if(d < ptr -> data)
	{
		ptr -> left = insert(ptr -> left,d);
	}
	else if(d > ptr -> data)
	{
		ptr -> right = insert(ptr -> right,d);
	}
	else
	{
		printf("%d already exists and duplicates are not allowed..\n",d);
	}
	return ptr;
}
