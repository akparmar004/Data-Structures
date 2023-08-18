#include"header.h"
void main()
{
	cdll *headptr=0;
	int op,c;
	while(1)
	{
		printf("enter option\n");
		printf("1)add end 2)add begin 4)print data 5)delete node 6)count 0)exit\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:add_end(&headptr); break;
			case 2:add_begin(&headptr); break;
			case 4:print_data(headptr); break;
			case 5:delete_node(&headptr); break;
			case 6:printf("%d",count_nodes(headptr)); break;
			case 0:exit(0);
			default:printf("wrong option\n");
		}
	}	
}
int count_nodes(cdll *ptr)
{
	int c=0;
	if(ptr==0)
	{
		printf("no record available\n");
		return 0;
	}
	cdll *cur=ptr;
	do
	{
		c++;
		cur=cur->next;
		
	}while(cur != ptr);
	return c;
}
void add_end(cdll **ptr)
{
	cdll *new;
	new=malloc(sizeof(cdll));
	printf("enter rollno,name and marks : ");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	
	if(*ptr==0)
	{
		new->prev=new;
		new->next=new;
		*ptr=new;
	}
	else
	{
		new->next=*ptr;
		new->prev=(*ptr)->prev;
		(*ptr)->prev->next=new;
		(*ptr)->prev=new;
	}
}

void print_data(cdll *ptr)
{
	if(ptr==0)
	{
		printf("no record available\n");
		return;
	}
	cdll *cur=ptr;
	do
	{
		printf("%d %s %f\n",cur->rollno,cur->name,cur->marks);
		cur=cur->next;
		
	}while(cur != ptr);
	printf("*************** reverse ***************\n");
	
	cur=ptr->prev;
	do
	{
		printf("%d %s %f\n",cur->rollno,cur->name,cur->marks);
		cur=cur->prev;
		
	}while(cur != ptr -> prev);
	
}

void add_begin(cdll **ptr)
{
	cdll *new;
	new=malloc(sizeof(cdll));
	printf("enter rollno,name and marks : ");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	
	if(*ptr==0)
	{
		new->prev=new;
		new->next=new;
	}
	else
	{
		new->next=*ptr;
		new->prev=(*ptr)->prev;
		(*ptr)->prev->next=new;
		(*ptr)->prev=new;
	}
	*ptr=new;
}

void delete_node(cdll **ptr)
{
	if(*ptr==0)
	{
		printf("no record available\n");
		return;
	}

	cdll *del=*ptr;	
	int num,c,i;
	c=count_nodes(*ptr);
	
	printf("enter number : ");
	scanf("%d",&num);
	
	if(num > 0 && num <= c)
	{
		for(i=1;i<=c;i++)
		{
			if(num == i)
			{
				if(del == *ptr)
				{
					(*ptr)=del->next;	
				}
				del->prev->next=del->next;
				del->next->prev=del->prev;
				free(del);
				return;
			}
			del=del->next;
		}
	}
	else
	{
		printf("node number out of range..\n");
	}	
}
