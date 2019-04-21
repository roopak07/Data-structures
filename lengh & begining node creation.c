#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *root; // gloabl variable 'root'
int len();
void begining();
void append();
void display();

void main()
{
	  append();
	  begining();
	  int l=len();
	  printf("lenght of the linked list:%d\n",l);
	  display();
	  getch();
}

void append()
{
	struct node *temp,*p;
	root=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("new node location is:%u\n",temp);
	printf("enter data:\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		p=root;
		while(p!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}

void begining()
{
	struct node *temp; // local variable temp
	temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data for the node:\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL) // check weather other nodes are present or not 
	{
		root=temp;
	}
	else
	{
	temp->link=root;
	root=temp;
	}
}

int len()
{
	int count=0;
	struct node *temp;
	temp=root;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	//printf("count:%d\n",count);
	return count;
}

void display()
{
	struct node *temp; // local variable temp
	int count=0;
	    printf("root:%d\n",root);
		printf("nodes data:\n");
		temp=root;
		while(temp!=NULL)
		{
			count++;
			printf("node %d data:%d link address:%u\n",count,temp->data,temp->link);
			temp=temp->link;
		}
}
