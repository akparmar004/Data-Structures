#include "header.h"

void main()
{
	bst *root = NULL,*temp = NULL;
	int choice,val;
	
	while(1)
	{
		printf("\n Menu : \n 1)insert 2)search 3)preorder 4)inorder 5)postorder 6)delete 7)min value 8)max value 9)count 0) EXIT\n");
		printf("enter choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("enter the data to be inserted : ");
			       scanf("%d",&val);
			       root = insert(root,val);
			       break;
			       
			case 2:printf("enter the data to be searched : ");
			       scanf("%d",&val);
			       temp = search(root,val);
			       
			       if(temp == NULL)
			       		printf("node not found..\n");
			       else
			       		printf("%d is found..\n",temp -> data);
			       break;
			
			case 3:preorder(root);
			       printf("\n");
			       break;
			 
			case 4:inorder(root);
			       printf("\n");
			       break;
			       
			case 5:postorder(root);
			       printf("\n");
			       break;
			case 6:printf("enter the value to be deleted : ");
				scanf("%d",&val);
				root = delete(root,val);
				break;
				
			case 7:temp = minValue(root);
				if(temp != NULL)
				{
					printf("minimum value of bst is : %d\n",temp -> data);
				}
				break;
				
			case 8:temp = maxValue(root);
				if(temp != NULL)
				{
					printf("maximum value of bst is : %d\n",temp -> data);
				}
				break;
				
			case 9:val = count(root);
				printf("total nodes : %d\n",val);
				break;
				
			case 0:printf("exiting from the menu..\n");
			       exit(0);
			default: printf("wrong choice..\n");
		}
		
		
	}
}

