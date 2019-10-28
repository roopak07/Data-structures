#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void new();
void delet();
void begining();
void after();
void display();
int length();
struct node
{
	int data;
	struct node *link;
};
struct node *root = NULL;
void main()
{
 int ch;
 while(1)
 {
	 printf(" \n ******Select one from below ******* \n");
	 printf("1.new node \n");
	 printf("2.delet a node \n");
	 printf("3.Add a node at the begining \n");
	 printf("4.Add a node after particular node \n");
	 printf("5.display \n");
	 printf("6.length of the node\n");
	 printf("7.Exit \n");
	 printf("Enter your choise: \n");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		case 1: new();
				break;
		case 2: delet();
				break;
		case 3: begining();
				break;
		case 4: after();
				break;
		case 5: display();
				break;
		case 6: length();
				break;
		case 7: exit(0);
				break;
		default:  printf("Enter a valid option");
	 }
 }
 getch();
}
// new node
void new()
{
	struct node *temp;
	struct node *pos;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("new node location : %u \n",temp);
	if(root == NULL)
	{
		root = temp;
		pos = root;
	}
	else
	{
		pos = root;
		while(pos-> link != NULL)
		{
			pos = pos->link;
		}
		pos->link = temp;
		printf("link position:%u \n",pos->link);
		
	}
	printf("enter a value: \n");
	scanf("%d",&temp->data);
	temp->link = NULL;
	printf("%u --->>> %d | %u \n",pos,temp->data,temp->link);
	
}
// delet a node
void delet()
{
	int npos,epos;
	struct node *ppos = root;
	npos=length();
	printf("Entered postion to delet: \n");
	scanf("%d",&epos);
	if(epos>npos)
		printf("Entered node postion does not exist's \n");
	else if(epos == 1)
	{
		root=ppos->link;
		ppos -> link = NULL;
		free(ppos);
		printf("delet node 1 sucesfull \n");
	}
	else
	{
		struct node *dpos;
		int count = 1;
		while(count < epos-1)
		{
			ppos=ppos->link;
			count++;
		}
		dpos=ppos->link;
		ppos->link=dpos->link;
		dpos->link=NULL;
		free(dpos);	
		printf("delet sucesfull \n");
	}	
}
// add at the begining
void begining()
{
 struct node *temp;
 temp=(struct node*)malloc(sizeof(struct node));
 printf("Enter data : \n");
 scanf("%d",&temp->data);
 temp->link = root;
 root=temp; 
}
// add after
void after()
{
	int epos,npos; // epos = entered postion, npos = node position or length 
	npos = length();
	printf("Entered postion to add: \n");
	scanf("%d",&epos);
	if(epos == npos+1)
		new();
	else if(epos>npos)
		printf("Entered node postion does not exist's \n");
	else if(epos == 1)
		begining();
	else
	{
		struct node *temp,*ppos=root; // ppos = present position node
		temp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter data : \n");
		scanf("%d",&temp->data);
		int count = 1;
		while(count < epos-1 )
		{
			ppos = ppos-> link;
			count++;
		}
		temp->link=ppos->link;
		ppos->link= temp;
	}
}
// display
void display()
{
	struct node *pos = root;
	printf("root: %d -->",root);
	while(pos!= NULL)
	{
		printf("%d | %u -->",pos->data,pos->link);
		pos=pos->link;
	}
	printf("\n \n");
}
// length 
int length()
{
	struct node *pos=root;
	int count = 0;
	while(pos != NULL)
	{
		count++;
		pos = pos -> link;
	}
	printf("length of the node:%d \n",count);
	return count;
}
