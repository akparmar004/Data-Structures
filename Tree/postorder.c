//postorder means ==  left - right - root...

#include "header.h"

void postorder(bst *ptr)
{
	if(ptr)
	{
		postorder(ptr -> left);
		postorder(ptr -> right);
		printf("%d ",ptr -> data);
	}
}
