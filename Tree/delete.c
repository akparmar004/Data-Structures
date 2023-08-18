#include "header.h"

bst* delete(bst* ptr,int d)
{
	bst* temp = NULL;
	
	if(ptr == NULL)
	{
		printf("%d is not found..\n",d);
	}
	else if(d < ptr -> data)
	{
		ptr -> left = delete(ptr -> left,d);
	}
	else if(d > ptr -> data)
	{
		ptr -> right = delete(ptr -> right,d);
	}
	else
	{
		if(ptr -> left && ptr -> right)
		{
			temp = minValue(ptr -> right);
			ptr -> data = temp -> data;
			ptr -> right =delete(ptr -> right,temp -> data);
		}
		else
		{
			temp = ptr;
			if(ptr -> left == NULL)
			{
				ptr = ptr -> right;
			}
			else
			{
				ptr = ptr -> left;
			}
			free(temp);
			temp = NULL;
		}
	}
	return ptr;
}
