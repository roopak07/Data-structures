#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void display();
void add();
void swap();
int length();
struct node
{
 int data;
 struct node *next;
};
struct node *root = NULL;

void main()
{
 int ch,len;
 while(1)
 {
  printf("************__List__*************\n");
  printf("1.Add\n");
  printf("2.display\n");
  printf("3.swap \n");
  printf("4.length \n");
  printf("9.exit\n");
  printf("Enter your choise:");
  scanf("%d",&ch);
  switch(ch)
  {
	case 1: add();
			break;
	case 2:	display();
			break;
	case 3:	swap();
			break;
	case 4:	len=length();
			printf("length of the node:%d \n",len);
			break;
	case 9:exit(0);
	default : printf("Enter a valid choise \n");
  }
 }
}

/***************** Add function*****************/
void add()
{
 struct node *temp;
 temp = (struct node*)malloc(sizeof(struct node));
 printf("Enter data : ");
 scanf("%d",&temp->data);
 temp->next = NULL;
 if(root == NULL)
 {
	 root = temp;
	 printf("%d --> %d | %d \n",root,temp->data,temp->next);
 }
 else
 {
	 struct node *pos;
	 pos = root;
	 while( pos->next != NULL)
	 {
		 pos = pos -> next;
	 }
	 pos->next = temp;
	 printf("%d --> %d | %d \n",pos -> next,temp->data,temp->next);
 }
}

/***************** display function*****************/
void display()
{
	struct node *pos;
	pos = root;
	printf("%d",root);
	while(pos!= NULL)
	{
		printf(" --> %d | %d",pos -> data,pos -> next);
		pos = pos ->next;
	}
	printf("\n");
}
/***************** display function*****************/
void swap()
{
	int n,len;
	len = length();
	printf("Enter a position of node to swap \n");
	scanf("%d",&n);
	printf("\n");
	if(len == 1)
		printf("Swap wont be possible due to single node \n");
	else if(n > len)
		printf("Swap wont be possible due to out of Range \n");
	else
	{
		struct node *pos,*prev,*pres,*nex;
		pos = root;
		for(int i =1;i<n-1; i++)
		{
			pos = pos -> next;
		}
		prev = pos;
		pres = prev -> next;
		nex = pres -> next;
		//Swapping
		pres->next = nex->next;
		nex->next=pres;
		prev->next=nex;
		printf(" Swapping sucess\n");
	}
}

int length()
{
	struct node *pos;
	pos = root;
	int count = 0;
	while(pos!= NULL)
	{
		count++;
		pos = pos->next;
	}
	return count;
}