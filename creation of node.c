#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void main()
{
	struct node *root,*temp,*p;
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
