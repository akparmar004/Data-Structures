#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student 
{
	int rollno;
	char name[20];
	float marks;
	struct student *next;
} csll;

void add_end(csll **);
void add_begin(csll **);
void add_mid(csll**);
void print(csll*);
int count_nodes(csll*);
void save_file(csll*);
void delete_node(csll**);
void search_data(csll*);
void read_file(csll**);
void delete_all(csll**);
void reverse_links(csll**);
