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

void main()
{
	int ch,l=0;
	while(1)
	{
		printf("Select one from the list\n");
		printf("1.Append\n");
		printf("2.begining\n");
		printf("3.length\n");
		printf("4.display\n");
		printf("5.Exit\n");
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
			case 5 :exit(0);
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
		printf("initial p=%u\n",p);
		while(p->link!=NULL)
		{
			p=p->link;
			printf("p=%u\n",p);
		}
		p->link=temp;
		printf("after p=%u\n",p);
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
			printf("%d | %u -->",temp->data,temp->link);
			temp=temp->link;
		}
	}
	printf("\n");
}
