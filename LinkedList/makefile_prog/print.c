#include"header.h"
void rev_links(sll **ptr)
{
	sll *p,*q,*r;
	p=*ptr;
	q=0;
	while(p)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	*ptr=q;

}

void rev_print_rec(sll *ptr)
{
	if(ptr==0)
	{
		return;
	}
	else
	{
		rev_print_rec(ptr->next);
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
	}
}

void rev_print(sll *ptr)
{
	int c,i,j;
	sll *temp;
	c=count_nodes(ptr);
	for(i=0;i<c;i++)
	{
		temp=ptr;
		for(j=0;j<c-1-i;j++)
		{
			temp=temp->next;
		}
		printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
	}
}
void print_data(sll* ptr)
{
	if(ptr == 0)
	{
		printf("no records available");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr = ptr -> next;
	}
}


