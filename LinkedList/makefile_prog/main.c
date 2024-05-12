#include "header.h"
void main()
{
	int op,c;
	sll *headptr=0;
	while(1)
	{
		printf("Enter choice : \n");
		printf("1)add begin 2)add end 3)add middle 4)print data 5)save file 6)delete all nodes 7)delete node 8)count nodes 9)reverse print 10)rev print recursion 11)read file 12)sort data 13)rev links 0)exit\n");
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
			case 0:exit(0);
			default:printf("Wrong option\n");
		}
	}
}
