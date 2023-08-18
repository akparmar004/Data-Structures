#include"header.h"
void sort(sll *ptr)
{
	int i,j,c;
	c=count_nodes(ptr);
	sll* another,temp;
	
	for(i=0;i<c-1;i++)
	{	
		another = ptr->next;
		for(j=0;j<c-1-i;j++)
		{
			if(ptr->marks>another->marks)
			{
				temp.rollno=ptr->rollno;
				ptr->rollno=another->rollno;
				another->rollno=temp.rollno;
				
 				strcpy(temp.name,ptr->name);
				strcpy(ptr->name,another->name);
				strcpy(another->name,temp.name);
				
				temp.marks=ptr->marks;
				ptr->marks=another->marks;
				another->marks=temp.marks;
			}
			another=another->next;
		}
		ptr=ptr->next;
	}
}

