#include"header.h"
void add_begin(sll **ptr)
{
	sll *new;
	new = malloc(sizeof(sll));
	printf("Enter rollno,name,marks : ");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	new->next = *ptr;
	*ptr=new;
	
}

void add_end(sll **ptr)
{
	sll* new,*last;
	new = malloc(sizeof(sll));
	printf("Enter rollno,name,marks : ");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	new->next = 0;
	if(*ptr==0)
	{
		*ptr = new;
	}
	else
	{
		last=*ptr;
		while(last->next)
		{
			last=last->next;
		}
		last->next=new;
	}
	
}

void add_mid(sll** ptr)
{
	sll* new,*last;
	new=malloc(sizeof(sll));
	printf("Enter rollno, name and marks : \n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	
	if((*ptr==0) || (new->rollno < (*ptr)->rollno))
	{
		new->next = *ptr;
		*ptr=new;
	}
	else
	{
		last=*ptr;
		while((last->next != 0) && last->next->rollno < new->rollno)
		{
			last=last->next;
		}
		new->next = last->next;
		last->next = new;
	}
}
