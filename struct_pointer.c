#include<stdio.h>
#include<conio.h>

struct node
{
	char name[50];
	int marks;
	float percentage;
};
void main()
{
	struct node student1;
	struct node *ptr;
	ptr=&student1;
	printf("enter name of the student:\n");
	scanf("%s",ptr->name);
	printf("enter marks of the student:\n");
	scanf("%d",&ptr->marks);
	//scanf("%d \n",&student1.marks);
	printf("enter percentage of the student:\n");
	scanf("%f",&ptr->percentage);
	//scanf("%f \n",&student1.percentage);
	printf("student details are:\n");
	printf("name=%s\n marks=%d\n percentage=%f \n",ptr->name,ptr->marks,ptr->percentage);
	getch();
}



