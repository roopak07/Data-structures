#include<stdio.h>
#include<stdlib.h>
void add();
void disp();
int length();
void addf();
void beg();
void delet();
void swap();
struct node
{
	int data;
	struct node *link;
};
struct node *root = NULL;

void main()
{
	int ch,l;
	while(1)
	{
		printf("1.Add a new node \n");
		printf("2.display \n");
		printf("3.length \n");
		printf("4.add after \n");
		printf("5.add at the begining \n");
		printf("6.delet \n");
		printf("7.Swapping \n");
		printf("8.exit \n");
		printf("Enter your choise: ");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1: add();
					break;
			case 2: disp();
					break;
			case 3: l=length();
					printf("length of the node: %d \n",l);
					break;
			case 4: addf();
					break;
			case 5: beg();
					break;
			case 6: delet();
					break;
			case 7: swap();
					break;
			case 8: exit(1);
					break;
			default: printf("Enter a valid choise \n");
			
		}
	}
}
/*add */
void add()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter data into the node: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root == NULL)
	{
		root = temp;
		printf("%d--> %d | %d \n",root,temp->data,temp->link);
	}
	else
	{
		struct node *pos;
		pos = root;
		while(pos->link!= NULL)
		{
			pos = pos->link;
		}
		pos->link=temp;
		printf("%d--> %d | %d \n",pos,temp->data,temp->link);
	}
}
/* display */
void disp()
{
	struct node *pos;
	pos=root;
	printf("%d",root);
	while(pos!=NULL)
	{
		printf(" --> %d | %d",pos->data,pos->link);
		pos= pos->link;
	}
	printf("\n");
}
/* length */
int length()
{
	int count=0;
	struct node *pos=root;
	while(pos!=NULL)
	{
		pos=pos->link;
		count++;
	}
	return count;
}
void addf()
{
	int p,len=length();
	printf("Enter position to add:");
	scanf("%d",&p);
	if(len<p)
	{
		printf("Enter postion is out of range");
	}
	else if(p==1)
	{
		beg();
	}
	else
	{
		struct node *pos=root,*temp;
		for(int i=1;i<p-1;i++)
		{
			pos=pos->link;
		}
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter data into the node:");
		scanf("%d",&temp->data);
		printf("\n");
		temp->link=pos->link;
		pos->link=temp;
		printf("%d --> %d | %d \n",pos->link,temp->data,temp->link);
	}	
}
void beg()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data into the node:");
	scanf("%d",&temp->data);
	printf("\n");
	temp->link=root;
	root=temp;
	printf("%d --> %d|%d \n",root,root->data,root->link);
}
void delet()
{
	int p,len=length();
	printf("Enter position to delet:");
	scanf("%d",&p);
	struct node *pos,*posn;
	if(len<p)
	{
		printf("Enter postion is out of range \n");
	}
	else if(p==1)
	{
		pos=root;
		root=root->link;
		pos->link = NULL;
		free(pos);
	}
	else
	{
		pos=root;
		for(int i=1;i<p-1;i++)
		{
			pos = pos->link;
		}
		posn = pos->link;
		pos->link=posn->link;
		posn->link = NULL;
		free(posn);
	}
	printf("Node deletion sucessfull \n");
}
void swap()
{
	int p,len=length();
	printf("Enter position to swap:");
	scanf("%d",&p);
	struct node *pos,*posp,*posn;
	if(len-1 < p)// since last node cant be exchanged
	{
		printf("Entered postion is out of range \n");
	}
	else if(p==1)
	{
		posp=root;
		posn=posp -> link;
		posp->link=posn->link;
		root=posn;
		posn->link=posp;
	}
	else
	{
		pos=root;
		for(int i=1;i<p-1;i++)
		{
			pos = pos->link;
		}
		posp = pos->link;
		posn = posp->link;
		posp->link=posn->link;
		posn->link=posp;
		pos->link=posn;
	}
}