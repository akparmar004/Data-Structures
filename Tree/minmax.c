#include "header.h"

bst* minValue(bst *ptr)
{
	if(ptr == NULL)
	{
		printf("tree is empty..\n");
		return NULL;
	}
	else if(ptr -> left == NULL)
	{
		return ptr;
	}
	else
	{
		return (minValue(ptr -> left));
	}
} 

bst* maxValue(bst *ptr)
{
	if(ptr != NULL)
	{
		if(ptr -> right == NULL)
		{	
			return ptr;
		}
		else
		{
			return (maxValue(ptr->right));
		}
	}
	else
	{
		printf("tree is empty..\n");
		return NULL;
	}
	
} 
