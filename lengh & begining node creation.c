#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int len();
void begining();
struct node
{
	int data;
	struct node *link;
};
struct node *root;
void main()
{
	struct node *temp,*p;
	int count=0;
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
	  begining();
	int l=len();
		printf("lenght of the linked list:%d\n",l);
		printf("root:%d\n",root);
		printf("nodes data:\n");
		p=root;
		while(p!=NULL)
		{
			count++;
			printf("node %d data:%d link address:%u\n",count,p->data,p->link);
			p=p->link;
		}
		
		getch();
}

void begining()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data for the node:\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	temp->link=root;
	root=temp;
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
