#include"header.h"
void main()
{
	csll *headptr=0;
	int op,c;
	while(1)
	{
		printf("enter option\n");
		printf("1)add_end 2)add_begin 3)add mid 4)print 5)count nodes 6)save file 7)read_file 8)delete node 9)search data 10)delete all 11)rev links 0)exit\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:add_end(&headptr); break;
			case 2:add_begin(&headptr); break;
			case 3:add_mid(&headptr); break;
			case 4:print(headptr); break;
			case 5:c=count_nodes(headptr); printf("total node : %d\n",c); break;
			case 6:save_file(headptr); break;
			case 7:read_file(&headptr); break;
			case 8:delete_node(&headptr); break;
			case 9:search_data(headptr); break;
			case 10:delete_all(&headptr); break;
			case 11:reverse_links(&headptr); break;
			case 0:exit(0);
			default:printf("wrong option\n");
		}
	}	
}

void reverse_links(csll **ptr)
{
    csll *prev, *cur, *last;

    if (*ptr == 0)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }
    
    last = *ptr;
    prev  = *ptr;
    cur   = (*ptr)->next;
    *ptr = (*ptr)->next;

    while (*ptr != last)
    {
        *ptr = (*ptr)->next;
        cur->next = prev;

        prev = cur;
        cur  = *ptr;
    }

    cur->next = prev;
    *ptr = prev;     
}

void add_mid(csll **ptr)
{
	csll *new,*last;
	new = malloc(sizeof(csll));
	printf("enter rollno, name and marks : ");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	if(*ptr == 0)
	{
		new->next=new;
		*ptr=new;
	}
	else if(new->rollno < (*ptr)->rollno)
	{
		new->next=(*ptr);
		last = new;
		do
		{
			last = last -> next;
		}while(last->next != (*ptr));
		last->next=new;
		*ptr=new;
	}
	else
	{
		last=*ptr;
		while(last->next->rollno < new->rollno  && last->next != *ptr)
		{
			last=last->next;	
		}
		new->next=last->next;
		last->next=new;
	}
}

void add_end(csll **ptr)
{
	csll *new,*last;
	new = malloc(sizeof(csll));
	printf("enter rollno,name and marks..\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	
	if(*ptr==0)
	{
		new->next=new;
		*ptr=new;
	}
	else
	{
		last=*ptr;
		while(last->next != *ptr)
		{
			last=last->next;
		}
		
		new->next=*ptr;
		last->next=new;
	}
}
void add_begin(csll **ptr)
{
	csll *new,*last;
	new = malloc(sizeof(csll));
	printf("enter rollno,name and marks..\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	
	if(*ptr==0)
	{
		new->next=new;
		*ptr=new;
	}
	else
	{
		new->next=*ptr;
	}
	
	last=*ptr;
	while(last->next!=*ptr)
	last=last->next;
	last->next=new;
	*ptr=new;
		
}

void print(csll *ptr)
{
	csll *first=ptr;
	if(ptr==0)
	{
		printf("no records available..\n");
		return;
	}
	while(1)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
		if(ptr==first)
			break;	
	}
}
 
void save_file(csll *ptr)
{
	csll *first=ptr;
	FILE *fp;
	fp=fopen("data","w");
	if(ptr==0)
	{
		printf("no records available..\n");
	}
	do
	{
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}while(ptr!=first);
	fclose(fp);
}

int count_nodes(csll *ptr)
{
	csll *first=ptr;
	int c=0;
	if(ptr==0)
	{
		printf("no records available..\n");
		return 0;
	}
	do
	{
		c++;
		ptr=ptr->next;
	}while(ptr!=first);
	return c;
}

void delete_node(csll **ptr)
{
	int num;
	csll *del=*ptr,*last,*prev;
	printf("enter rollno to delete : ");
	scanf("%d",&num);
	
	if(*ptr==0)
	{
		printf("no records available to delete..\n");
		return;
	}
	
	do
	{
		if(del->rollno==num)//it will check rollno is present in record or not
		{
			if(del==*ptr)//if present, is it first node?
			{
				last=*ptr;
				while(last->next!=*ptr)
					last=last->next;
					
					last->next=del->next;				
					*ptr=del->next;	
							
			}
			else
			{
				prev->next=del->next;
			}
			free(del);
			return;	
		}
		prev=del;
		del=del->next;
	}while(del != *ptr);
	
	printf("rollno not found in data..\n");
	
}

void search_data(csll *ptr)
{
	int op;
	csll *cur=ptr;
	int flag=0;
	if(ptr==0)
	{
		printf("no record found\n");
		return;
	}
	printf("1)rollno 2)name 3)marks : ");
	scanf("%d",&op);
	
	switch(op)
	{		
		case 1:int rollno;

			printf("enter rollno : ");
			scanf("%d",&rollno);
			
			do
			{
				if(cur->rollno==rollno)
				{
					flag=1;
					printf("%d %s %f\n",cur->rollno,cur->name,cur->marks);
				}
				cur=cur->next;
			}while(cur != ptr);
			
			if(flag==0)
			{
				printf("name not found in record\n");
			}
		break;
		case 2:char name[20];
			
			printf("enter name : ");
			scanf("%s",name);
			
			do
			{
				if(strcmp(cur->name,name) == 0)
				{
					flag=1;
					printf("%d %s %f\n",cur->rollno,cur->name,cur->marks);
				}
				cur=cur->next;
			}while(cur != ptr);
			
			if(flag==0)
			{
				printf("name not found in record\n");
			}
		break;
			
		case 3:float marks;
			
			printf("enter marks : ");
			scanf("%f",&marks);
		
			do
			{
				if(cur->marks==marks)
				{
					flag=1;
					printf("%d %s %f\n",cur->rollno,cur->name,cur->marks);
				}
				cur=cur->next;
			}while(cur != ptr);
			
			if(flag==0)
			{
				printf("name not found in record\n");
			}	
		break;	
		default:printf("invalid option\n");
	}
}

void read_file(csll **ptr)
{
	
	csll *new,*temp;
	int flag=1;
	FILE *fp;
	fp=fopen("data","r");
	
	while(1)
	{	
		new = malloc(sizeof(csll));
		if(fscanf(fp,"%d %s %f",&new->rollno,new->name,&new->marks) == -1)
		{
			break;
		}
		if(flag==1)
		{
			*ptr=new;
			temp=*ptr;
			new->next=temp;
			flag=0;
			continue;
		}
		new->next = *ptr;
		temp->next=new;
		temp=temp->next;
	}
	fclose(fp);
}

void delete_all(csll **ptr)
{
	csll *del=*ptr;
	if(del==0)
	{
		printf("no record available\n");
		return;
	}
	
	int c = count_nodes(*ptr),i;
	for(i=0;i<c;i++)
	{
		*ptr=(*ptr)->next;
		free(del);
		del=*ptr;
	}
	*ptr=0;
}
