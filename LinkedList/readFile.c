#include"header.h"
void main()
{
	int op,c;
	sll *headptr=0;
	while(1)
	{
		printf("Enter choice : \n");
		printf("1)add begin 2)add end 3)add middle 4)print data 5)save file 6)delete all nodes 7)delete node 8)count nodes 9)reverse print 10)rev print recursion 11)read file 12)sort data 13)rev links 14)rev data 0)exit\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:add_begin(&headptr);
			break;
			case 2:add_end(&headptr);
			break;
			case 3:add_mid(&headptr);
			break;
			case 4:print_data(headptr);
			break;
			case 5:save_file(headptr);
			break;
			case 6:delete_all(&headptr);
			break;
			case 7:delete_node(&headptr);
			break;
			case 8:c=count_nodes(headptr);
			       printf("Total node : %d\n",c);
			break;
			case 9:rev_print(headptr);
			break;
			case 10:rev_print_rec(headptr);
			break;
			case 11:read_file(&headptr);
			break;
			case 12:sort(headptr);
			break;
			case 13:rev_links(&headptr);	
			break;
			case 14:rev_data(headptr);
			break;
			case 0:exit(0);
			default:printf("Wrong option\n");
		}
	}
}

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

void rev_data(sll *ptr)
{
	int c = count_nodes(ptr),i,j;
	sll* last,*p,temp;
	p=ptr;
	for(i=0;i<c/2;i++)
	{
		last=ptr;
		for(j=0;j<c-1-i;j++)
		{
			last=last->next;
		}
				temp.rollno=p->rollno;
				p->rollno=last->rollno;
				last->rollno=temp.rollno;
				
 				strcpy(temp.name,p->name);
				strcpy(p->name,last->name);
				strcpy(last->name,temp.name);
				
				temp.marks=p->marks;
				p->marks=last->marks;
				last->marks=temp.marks;
				
				p=p->next;
	}
}

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


void read_file(sll **ptr)
{
	
	sll *new;
	FILE *fp;
	fp=fopen("student-data.txt","r");
	
	while(1)
	{	
		new = malloc(sizeof(sll));
		if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks) == -1)
		{
			break;
		}
		
		new->next=*ptr;
		*ptr=new;
	}
	fclose(fp);
	
	
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

void save_file(sll* ptr)
{
	if(ptr==0)
	{
		printf("No records available\n");
		return;
	}
	FILE *fp;
	fp=fopen("student-data.txt","w");
	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	fclose(fp);
	
}


void delete_all(sll **ptr)
{
	if(*ptr==0)
	{
		printf("No records available to delete");
		return;
	}
	sll *del;
	while(*ptr)
	{
		del=*ptr;
		*ptr=(*ptr)->next;
		free(del);
		del=0;
	}
}

void delete_node(sll **ptr)
{
	sll *p,*q;
	p=q=*ptr;
	int op;	
	
	if(*ptr==0)
	{
		printf("no nodes are available to delete\n");
		return;
	}
	
	printf("Enter information related to student : \n");
	printf("1)rollno 2)name 3)marks : \n");
	scanf("%d",&op);
	
	switch(op)
	{
		case 1: int num;
			printf("Enter roll no : ");
			scanf("%d",&num);
	
			while(p)
			{
				if(p->rollno==num)
				{
					if(p==*ptr)
					*ptr=p->next;
					else
					q->next=p->next;
					free(p);
					p=0;
					return;	
				}
			q=p;
			p=p->next;
			}
			if(p==0)
			printf("rollno not found in records..\n");
		break;
		case 2: char name[10];
			printf("Enter name : ");
			scanf("%s",name);
			
			while(p)
			{
				if(strcmp(p->name,name)==0)
				{
					if(p==*ptr)
					*ptr=p->next;
					else
					q->next=p->next;
					
					free(p);
					p=0;
					return;	
				}
			q=p;
			p=p->next;
			}
			if(p==0)
			printf("name not found in records..\n");
		break;
		
		case 3:float marks;
			printf("Enter marks : ");
			scanf("%f",&marks);
			
			while(p)
			{
				if(p->marks==marks)
				{
					if(p==*ptr)
					*ptr=p->next;
					else
					q->next=p->next;
					free(p);
					p=0;
					return;	
				}
			q=p;
			p=p->next;
			}
			if(p==0)
			printf("marks not found in records..\n");
			break;
		default : printf("invalid option");
			  return;
			
	}
}
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
