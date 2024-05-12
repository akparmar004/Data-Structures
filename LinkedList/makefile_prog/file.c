#include"header.h"
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
