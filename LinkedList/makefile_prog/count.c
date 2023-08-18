#include"header.h"
int count_nodes(sll* ptr)
{
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
	
}
