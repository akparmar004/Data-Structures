#include "header.h"
bst* search(bst* ptr, int d)
{
	if(ptr == NULL)
	{
		return NULL;
	}
	else if(d < ptr -> data)
	{
		return search(ptr -> left,d);
	}	
	else if(d > ptr -> data)
	{
		return search(ptr -> right,d);
	}
	return ptr;
}
