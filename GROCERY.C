#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0
void traverse();
struct node
{
	char data[50];
	int quantity;
	int price;
	struct node *next;
};

struct node *first = NULL;


/*
This method will create singly linkedlist.
@param:  takes no parameters
@returns: nothing
*/
void createMart()
{
	char ch;
       //	char ch[50];
	struct node *pnode;
	do
	{
		pnode=(struct node*)malloc(sizeof(struct node));
		if(pnode==NULL )
		{
			printf("\nMemory overflow cannot create node");
			exit(1);
		}
		else
		{
			printf("\nEnter the item to be added to mart : ");
			scanf("%s",&pnode->data);
			printf("\nEnter quantity : ");
			scanf("%d",&pnode->quantity);
			printf("\nEnter price per kg : ");
			scanf("%d",&pnode->price);
			pnode->next=first;
			first=pnode;

			printf("\nDo you want to add more items?(y|n):");
			scanf("%s",&ch);
		}
	}
	while(ch=='Y'||ch=='y');
}
/*
This method will delete the specified item in the list
@param:  takes no parameters
@returns: nothing
*/
void deleteNode()
{
	char x[50];
	int check;
	struct node *pnode,*current,*follow;
	printf("\nEnter the data value of the which has to be deleted ");
	scanf("%s",&x);
       puts(x);
	current=first;
	follow=NULL;
	while( strcmp(current->data,x)!=0 && current != NULL)
	{
	       //	printf("inside while");
		follow = current;
		current= current->next;
	}
	if(current==NULL)           {
		//printf("current is null");
		printf("Specified node not found");
	}
	else
	{
		if(current==first)
			first=first->next;
		else
			follow->next=current->next;
		printf("%s has been removed from the mart",current->data);
		free(current);
	}
	printf("\n---------------items  left --------------");
	traverse();
}
/*
This method will search the specified item in the list
@param:  takes no parameters
@returns: nothing
*/
void search()
{
	int check;
	char x[50];
	struct node *pnode,*current,*follow;
	printf("\n enter the item to be searched to check weather it is present in mart:");
	scanf("%s",&x);
	current=first;
	if(first ==NULL)
		printf("\n Grocery is empty");
	else{
		while(strcmp(current->data,x)!=0 && current != NULL)
			current = current->next;
		if(current==NULL)
			printf("\nSpecified item not present in the mart\n\n");
		else
			printf("\nSpecified item present\n\n");
	}
}
/*
This method is used to traverse i.e retrive the nodes in the ll.
@param:  takes no parameters
@returns: nothing
*/
void traverse()
{
	struct node *current;
	current=first;
	if(first==NULL)
		printf("\nlist is empty");
	else
	{
		printf("\nItems\t\tQuantity\t\tPrice/kg\t\ttotalprice");
		printf("\n--------\t---------\t------------\t----------");

		while(current!= NULL)
		{

			printf("\n%s\t\t\t%d\t\t%d\t\t\t%d",current->data,current->quantity,current->price,current->quantity*current->price);
		       //	printf("quantity = %d\t",current->quantity);
			current=current->next;
		}
	}
}
/*
This method destorys the entire list
@param:  takes no parameters
@returns: nothing
*/
void destroyList()
{
	struct node *current;
	while(first!= NULL )
	{
		current=first;

		first=first->next;
		free(current);
	}
}
/*
This method inserts new nodes into already created linkedlist.
@param:  takes no parameters
@returns: nothing
*/
void insertEle()
{
	struct node *pnode, *current,*follow;
	pnode=(struct node *)malloc (sizeof(struct node));
	if(pnode==NULL)
	{
		printf("\nmemory overflow cannpt create node");
		exit(1);
	}
	else
	{
		printf("\nEnter the item to be added to mart ");
		scanf("%s",&pnode->data);
		printf("\nEnter quantity of the item just added");
		scanf("%d",&pnode->quantity);
		printf("\nEnter price for the grocery item ");
		scanf("%d",&pnode->price);
		pnode->next=NULL;
		if(first==NULL)
			first=pnode;
		else
		{
			follow = NULL;
			current = first;
			while(current != NULL)
			{
				follow = current;
				current = current->next;
			}
			follow->next=pnode;
		       traverse();
		}
	}
}
/*
This method sorts the linkedlist asendingly based on the Price
@param:  takes no parameters
@returns: nothing
*/
void sortPrice()
{
	int temp;
	struct node *current ,*follow;
	current = first;
	follow = first;
	if(first==NULL)
		printf("\nList is empty");
	else
	{
		while(follow -> next != NULL)
		{
			current = first;
			while(current->next!=NULL)
				{
				 if(current->price > current->next->price)
				 {
					temp = current->price;
					current->price=current->next->price;
					current->next->price=temp;
				 }
				 current=current->next;
			}
			follow = follow->next;
		}
	}
	traverse();
}
/*
This method sorts the linkedlist asendingly based on the quantity
@param:  takes no parameters
@returns: nothing
*/
void sortQuantity()
{
	int temp;
	struct node *current ,*follow;
	current = first;
	follow = first;
	if(first==NULL)
		printf("\nList is empty");
	else
	{
		while(follow -> next != NULL)
		{
			current = first;
			while(current->next!=NULL)
				{
				 if(current->quantity > current->next->quantity)
				 {
					temp = current->quantity;
					current->quantity=current->next->quantity;
					current->next->quantity=temp;
				 }
				 current=current->next;
			}
			follow = follow->next;
		}
	}
	traverse();
}
/*
This method updates the nodes in the linked list based on user input weather
to update price or quantity of the entered item
@param:   old        : value that is to be replace
	      new_val    : value that will replace old
	      update_bit : char accepted to update price or quantity
@returns: nothing
*/

void update_node(int old , int new_val, char update_bit){
	int pos;
	struct node *current;
	current = first;
	if(first == NULL)
		printf("nothing in the grocery list to be updated");
	else{
		if(update_bit == 'p'){
			  while(current!=NULL){
				if(current->price == old){
					printf("inside if %d",current->price);
					current->price = new_val;
					printf("\nTable updated");
				}
				current = current->next;
			}
		}
		else if(update_bit == 'q'){
			while(current!=NULL){
				if(current->quantity == old){
					current->quantity = new_val;
					printf("\nTable updated");
				}
				current = current->next;
			}
		}
		else
			printf("\nInvalid option");
		traverse();
	}

}
//*****Main Method**********//
void main()
{
	int ch,old,new_val;
	char update_bit,update_bit_sent;
	clrscr();
	printf("\n\t\t\t********************************");
	printf("\n\t\t\t*         GROCERY MART         *");
	printf("\n\t\t\t********************************");
	while(1)
	{
		printf("\n---Select action to be performed---");
		printf("\n1.Create item list");
		printf("\n2.Delete item \n3.Search a item");
		printf("\n4.check items in mart \n5.destroy complete mart ");
		printf("\n6.add more items");
		printf("\n7.Sort the list according to price \n8.Sort according to quantity\n9.update\n10.exit");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				createMart();
				break;
			case 2:
				deleteNode();
				break;
			case 3:
				search();
				break;
			case 4:
				traverse();
				break;
			case 5:
				destroyList();
				break;
			case 6:
				insertEle();
				break;

			case 7:
			       sortPrice();
				break;
			case 8:
				sortQuantity();
				break;
			case 9:
				printf("\nDo you want to update price or quanity(p|q)?");
				scanf(" %c",&update_bit);
				printf("enter the old value from the table to be updated");
				scanf("%d",&old);
				printf("enter new value to replace the old value ");
				scanf("%d",&new_val);
				update_node(old,new_val,update_bit);
				break;
			case 10:
				exit(0);

			default:
				printf("\nWrong choice!!!Try again");
		}
	}
}