#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	struct node *prev;
	int rollno;
	char name[20];
	float marks;
	struct node *next;
} dll;

void add_begin(dll**);
void add_end(dll**);
void add_mid(dll**);
void print_dll(dll*);
int count_nodes(dll*);
void save_file(dll*);
void delete_all(dll**);
void read_file(dll**);
void delete_node(dll**);
void reverse_links(dll**);
void rev_data(dll*);
void sort(dll*);
void rev_print(dll*);
void rev_rec_print(dll*);

