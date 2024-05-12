#include<stdio.h>
#include<stdlib.h>


struct Group
{
	int data;
	struct Group * next;
};

void main()
{
	struct Group * head,* second,* third;
	
	head=(struct Group *)malloc(sizeof(struct Group));
	second=(struct Group *)malloc(sizeof(struct Group));
	third=(struct Group *)malloc(sizeof(struct Group));	
	
	head -> data = 10l;
	head -> next = second;
	
	second -> data = 20;
	second -> next = third;
	
	third -> data = 30;
	third -> next = NULL;	
}
