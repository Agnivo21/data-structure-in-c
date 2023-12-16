/*7)WAP to create a Double Linked List and perform the following operations:
(Options: 1: create a list containing 08 values/nodes, 2: display the list,
3: add/insert a node at the beginning, 4: add/insert a node at the end, 5:
add/insert node at a particular position/location, 6: delete a node from the
beginning, 7: delete a node from the end, 8: delete a node from a particular
position/location, 9: reverse the list, 10: exit). You can take user input
based on the given choices.*/


#include<stdio.h> 
#include<stdlib.h>

struct DLLNODE{ 
int data; 
struct DLLNODE *next; 
struct DLLNODE *prev; 
} *head=NULL;

void display()
{
	struct DLLNODE *temp=head;
	if(temp==NULL)
	{
		printf("EMPTY LINKED LIST");
		return;
	}
	while(temp->next!=NULL)
	{
		printf("%d ",temp->data);
        temp=temp->next;  
	}
	printf("%d ",temp->data);
}

void insertAtbegin(int key)
{
	struct DLLNODE *current=head;
	struct DLLNODE *newnode=(struct DLLNODE*)malloc(sizeof(struct DLLNODE));
	newnode->data=key;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(current==NULL)
		head=newnode;
	else
	{
      head->prev=newnode;
      newnode->next=head;
      head=newnode;
	}
}

void insertAtend(int key)
{
	struct DLLNODE *current=head;
	struct DLLNODE *newnode=(struct DLLNODE*)malloc(sizeof(struct DLLNODE));
	newnode->data=key;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(current==NULL)
	{
		head=newnode;
		return;
	}
	while(current->next != NULL)
		current=current->next;
		current->next=newnode;
		newnode->prev=current;
}

void insertAtpos(int key,int pos)
{
	struct DLLNODE *newnode=(struct DLLNODE*)malloc(sizeof(struct DLLNODE));
	newnode->prev=NULL;
	newnode->next=NULL;
	newnode->data=key;

	if(pos==1)
	{
		newnode->next=head;
		newnode->prev=NULL;
		head->prev=newnode;
		head=newnode;
		return;
	}
	struct DLLNODE *temp=head;
	int currpos=1;
	while(currpos<pos-1 && temp->next!=NULL)
	{
      temp=temp->next;
      currpos++;
	}
	if(currpos<pos-1)
	{
		printf("Desired position  does not exits\n");
		return;
	}
	newnode->next=temp->next;
	newnode->prev=temp;
	if(temp->next)
		temp->next->prev=newnode;
	temp->next=newnode;
}


void deleteAtbeg()
{
	struct DLLNODE *temp=head;
	if(head==NULL)
	{
		printf("LIST EMPTY\n");
		return;
	}
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
}

void deleteAtend()
{
   struct DLLNODE *curr=head,*temp;

   if(head==NULL)
   {
    printf("LIST EMPTY\n");
    return;
   }
  while(curr->next !=NULL)
  	curr=curr->next;

  temp=curr->prev;
  temp->next=NULL;
  free(curr);
}

void deleteAtpos(int pos)
{
	struct DLLNODE *temp2,*temp=head;
	if(head==NULL)
	{
		printf("LIST IS EMPTY\n");
		return;
	}
	if(pos==1)
	{
		head=head->next;

	}
     
     int k=1;
	while(k<pos && temp->next !=NULL)
	{
		temp=temp->next;
		k++;
	}
	if(k<pos-1)
	{
		printf("DESIRED POSITION DOESNOT EXISTS");
		return;
	}
	temp2=temp->prev;
	temp2->next=temp->next;
	if(temp->next)
		temp->next->prev=temp2;
	free(temp);
}



void main()
{
	insertAtbegin(10);
	insertAtbegin(20);
	insertAtbegin(30);
	insertAtbegin(40);
	insertAtbegin(50);
	//ll is created
	printf("\nThe linked list is \n");
	display();
	printf("\ninsert at begin\n");
	insertAtbegin(05);
	display();
	printf("\ninsert at end\n");
	display();
	insertAtend(60);
	printf("\ninsert at pos\n");
	insertAtpos(25,3);
	display();
	printf("\ndelete at begin\n");
	deleteAtbeg();
	display();
	printf("\ndelete at end\n");
	deleteAtend();
	display();
	printf("\ndelete at pos\n");
	deleteAtpos(3);
	display();

}