#include "header.h"

void main()
{
	int op,c;
	dll *headptr = 0;
	while(1)
	{
		printf("Enter choice : \n");
		printf("1)add begin 2)add end 3)add_mid 4)print data 5)count nodes 6)save file 7)delete all 8)read file 9)delete node 10)reverse links 11)reverse data 12)sort 13)reverse print 0)exit\n");
		scanf("%d",&op);
	
		switch(op)
		{
			case 1:add_begin(&headptr); break;
			case 2:add_end(&headptr); break;
			case 3:add_mid(&headptr); break;
			case 4:print_dll(headptr); break;
			case 5:c=count_nodes(headptr); printf("Total nodes : %d\n",c); break;
			case 6:save_file(headptr); break;
			case 7:delete_all(&headptr); break;
			case 8:read_file(&headptr); break;
			case 9:delete_node(&headptr); break;
			case 10:reverse_links(&headptr); break;
			case 11:rev_data(headptr); break;
			case 12:sort(headptr); break;
			case 13:rev_print(headptr); break;
			case 14:rev_rec_print(headptr); break;
			case 0:exit(0);
			default:printf("wrong option\n");
		}
	}
}

void rev_rec_print(dll *ptr)
{
	if(ptr==0)
	{
		return;
	}
	rev_rec_print(ptr->next);
	printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
}

void rev_print(dll *ptr)
{
	dll *last=ptr;
	while(last->next)
	{
		last=last->next;
	}
	while(last)
	{
		printf("%d %s %f\n",last->rollno,last->name,last->marks);
		last=last->prev;
	}
}

void sort(dll *ptr)
{
	int i,j,c;
	c=count_nodes(ptr);
	dll* another,temp;
	
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

void add_begin(dll **ptr)
{
	dll *new;
	new = malloc(sizeof(dll));
	
	printf("Enter rollno, name, marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	new->prev=0;
	new->next=*ptr;
	
	if(*ptr != 0)
	{
		(*ptr)->prev=new;
	}
	
	*ptr=new;
}

void add_end(dll **ptr)
{
	dll *new,*last;
	new=malloc(sizeof(dll));
	new->prev=0;
	new->next=0;
	printf("Enter rollno, name, marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
		
	if(*ptr==0)
	{
		*ptr=new;
	}
	else
	{
		last=*ptr;
		while(last->next)
		{
			last=last->next;
		}
		last->next=new;
		new->prev=last;
	}
}

void add_mid(dll **ptr)
{
	dll *new,*last;
	new=malloc(sizeof(dll));
	new->prev=0;
	printf("Enter rollno, name, marks\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	
	if(*ptr==0 )
	{
		new->next=*ptr;
		*ptr=new;
	}
	else if(new->rollno < (*ptr)->rollno)
	{
		(*ptr)->prev=new;
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		last = *ptr;
		while((last->next != 0) && last->next->rollno < new->rollno)
		{
			last=last->next;
		}
		new->next=last->next;
		new->prev=last;
		if(last->next!=0)
		{
			new->next->prev=new;
		}
		last->next=new;
		
	}
}

void print_dll(dll *ptr)
{	
	if(ptr==0)
	{
		printf("no records available");
		return;
	}
	
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	
}

int count_nodes(dll *ptr)
{
	dll *p=ptr;
	int c = 0;
	
	if(p==0)
	{
		printf("no record available...\n");
		return 0;
	}
	
	while(p)
	{
		c++;
		p=p->next;
	}
	
	return c;
}

void save_file(dll *ptr)
{
	FILE *fp;
	fp=fopen("data","w");
	if(ptr==0)
	{
		printf("no records available...\n");
		return;
	}
	while(ptr->next)
	{
		//fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	while(ptr)
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->prev;
	}
	fclose(fp);
}

void delete_all(dll **ptr)
{
	if(*ptr == 0)
	{
		printf("no records available to delete...");
		return;
	}
	
	dll *del=*ptr;
	
	while(del)
	{
		*ptr=(*ptr)->next;
		free(del);
		del=*ptr;
	}
}

void read_file(dll **ptr)
{
	
	dll *new;
	FILE *fp;
	fp=fopen("data","r");
	
	while(1)
	{	
		new = malloc(sizeof(dll));
		if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks) == -1)
		{
			break;
		}
		
		new->next=*ptr;
		new->prev=0;
		if(*ptr!=0)
			(*ptr)->prev=new;
		*ptr=new;
	}
	fclose(fp);
}

void delete_node(dll **ptr)
{
	int num,c,i;
	dll *del=*ptr;
	if(*ptr==0)
	{
		printf("no nodes available to delete..\n");
		return;
	}
	printf("enter node number to delete : ");
	scanf("%d",&num);
	c=count_nodes(*ptr);
	if(num>0 && num<=c)
	{
		for(i=1;i<=c;i++)
		{
			if(i==num)
			{
				if(del==*ptr)
				{
					*ptr=(*ptr)->next;
					(*ptr)->prev=0;
				}
				else
				{
					if(del->next!=0)
					{
						del->next->prev=del->prev;
					}
					del->prev->next=del->next;
				}
				free(del);
				return;
			}
			del=del->next;
		}	
	}
	else
	{
		printf("node out of range..\n");
	}
}

void reverse_links(dll **ptr)
{
	dll *temp=0,*present=*ptr;
		
	if(*ptr == 0)
	{
		printf("no records available..\n");
		return;
	}
	while(present)
	{
		temp=present->prev;
		present->prev=present->next;
		present->next=temp;
		
		present=present->prev;
	}
	if(temp != 0)
	(*ptr)=temp->prev;
}

void rev_data(dll *ptr)
{
	dll *last,temp;
	int i,c;
	c=count_nodes(ptr);
	
	last=ptr;
	
	while(last->next)
	{
		last=last->next;
	}
	for(i=0;i<c/2;i++)
	{
		temp.rollno=ptr->rollno;
		ptr->rollno=last->rollno;
		last->rollno=temp.rollno;
		
		strcpy(temp.name,ptr->name);
		strcpy(ptr->name,last->name);
		strcpy(last->name,temp.name);
		
		temp.marks=ptr->marks;
		ptr->marks=last->marks;
		last->marks=temp.marks;
		
		ptr=ptr->next;
		last=last->prev;
	}
}





