#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define CAPACITY 5
int top = -1,stack[CAPACITY];

void push(void);
void pop(void);
void peek(void);
void Traverse(void);
int isfull(void);
int isempty(void);

void main(void)
{
    int ch;
    while(1)
    {
        printf("Select one from  the list below\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.Traverse\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3:peek();
                    break;
            case 4:Traverse();
                    break;
            case 5:exit(0);
            default:printf("Invalid input\n");
        }
    }
}

void push()
{
    int ele;
    if(isfull())
    {
        printf("stack overflow\n");
    }
    else
    {
        top++;
        printf("Enter element to insert:\n");
        scanf("%d",&ele);
        stack[top]=ele;
        printf("%d inserted sucessfully in %d index\n",ele,top);

    }
}

int isfull()
{
	printf("top=%d \t capacity=%d \n",top,CAPACITY-1);
    if(top == CAPACITY-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pop()
{
    if(isempty())
    {
        printf("stack underflow\n");
    }
    else
    {
     printf("removed %d from the %d index of stack\n",stack[top],top);
     top--;
    }
}

void peek()
{
    if(isempty())
    {
        printf("stack is empty\n");
    }
    else
    {
        printf(" present stack index:%d value at index:%d is:%d \n",top,top,stack[top]);
    }
}

void Traverse()
{
    if(isempty())
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("elements in stack are:\n");
        for(int i=0;i<=top;i++)
        {
            printf("index %d element=%d\n",i,stack[i]);
        }
    }
}

int isempty()
{
	printf("top=%d \t capacity=%d \n",top,CAPACITY-1);
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
