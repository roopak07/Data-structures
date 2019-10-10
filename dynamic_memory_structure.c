#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};
struct node *root = NULL;
void main()
{
 struct node *temp;
 temp = (struct node*)malloc(sizeof(struct node));
 printf("temp : %u \n",temp);
 if(root == NULL)
 {
  root = temp;
 }
  printf("Enter elemnt: ");
  scanf("%d",&temp->data);
  temp->link = NULL;
 printf("root :%u ,data : %d , link :%u ",root,temp->data, temp->link);
 getch();
}