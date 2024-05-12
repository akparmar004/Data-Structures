#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student 
{
	struct student *prev;
	int rollno;
	char name[20];
	float marks;
	struct student *next;
} cdll;

void add_end(cdll **);
void add_begin(cdll **);
void print_data(cdll*);
int count_nodes(cdll*);
void save_file(cdll*);
void delete_node(cdll**);
void search_data(cdll*);
void read_file(cdll**);
void delete_all(cdll**);
