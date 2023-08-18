#include<stdio.h>
#include<stdlib.h>

typedef struct student 
{
	int rollno;
	char name[20];
	float marks;
	struct student *next;
} sll;
void add_begin(sll **);
void print_data(sll*);
	 
void main()
{
	sll *headptr=0;
	add_begin(&headptr);
	add_begin(&headptr);
	add_begin(&headptr);
	print_data(headptr);
}

void add_begin(sll **ptr)
{
	sll *new;
	new = malloc(sizeof(sll));
	printf("Enter rollno,name,marks : ");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	new->next = *ptr;
	*ptr=new;
	
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
