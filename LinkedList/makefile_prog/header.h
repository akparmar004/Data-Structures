#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student 
{
	int rollno;
	char name[20];
	float marks;
	struct student *next;
} sll;


void add_begin(sll **);
void add_end(sll **);
void print_data(sll*);
void save_file(sll*);
void delete_all(sll**);
void delete_node(sll**);
void add_mid(sll**);
int count_nodes(sll*);
void rev_print(sll*);
void rev_print_rec(sll*);
void read_file(sll**);
void sort(sll*);
void rev_links(sll**);
void rev_data(sll*);
