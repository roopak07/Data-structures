#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *root=NULL; // gloabl variable 'root'
int len();
void begining(void);
void append(void);
void display(void);
void delet(void);
void addafter(void);

void main()
{
	int ch,l=0;
	while(1)
	{
		printf("_____Select one from the list_____\n");
		printf("1.Append\n");
		printf("2.begining\n");
		printf("3.length\n");
		printf("4.display\n");
		printf("5.delet\n");
		printf("6.addafter\n");
		printf("7.Exit\n");
		printf("Enter your choise:");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1 : append();
				break;
			case 2 :begining();
				break;
			case 3 :l=len();
				printf("lenght of the linked list:%d\n",l);
				break;
			case 4 :display();
				break;
			case 5 : delet();
				break;
			case 6 : addafter();
				break;
			case 7 :exit(0);
			default:printf("invalid operation \n");
		}
	}
	  getch();
}

void append()
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("root location:%u\n",root);
	printf("new node location is:%u\n",temp);
	printf("enter data:");
	scanf("%d",&temp->data);
	printf("\n");
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
			printf("p:%u\n",p);
		}
		p->link=temp;
	}
}

void begining()
{
	struct node *temp; // local variable temp
	temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
	scanf("%d",&temp->data);
	printf("\n");
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
	printf("root address:%d\n",root);
	temp=root;
	if(temp==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		printf("linked list data:\n");
		while(temp!=NULL)
		{
			printf("%d|%u --> ",temp->data,temp->link);
			temp=temp->link;
		}
	}
	printf("\n");
}

void delet()
{
	struct node *temp;
	int loc;
	printf("Enter location to delet:");
	scanf("%d",&loc);
	printf("\n");
	if(loc > len())
	{
		printf("Invalid location \n");
	}
	else if(loc == 1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		struct node *p=root,*q;
		for(int i=1;i<loc-1;i++)
		{
			p=p->link;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}

void addafter()
{
	struct node *temp,*p=root;
	int loc;
	printf("Enter location to insert:");
	scanf("%d",&loc);
	if(loc>len())
	{
		printf("Invalid location \n");
	}
	else
	{
		for(int i=1;i<loc-1;i++)
		{
			p=p->link;
		}
		temp=(struct node*)malloc(sizeof(struct node));
		printf("new node created at :%u\n",temp);
		printf("enter data:");
		scanf("%d",&temp->data);
		temp->link=NULL;
		temp->link=p->link;
		p->link=temp;
	}
}
