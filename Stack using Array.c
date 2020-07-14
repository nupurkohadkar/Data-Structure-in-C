#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int top;
int info[SIZE];

void push(int data);
void init();
void pop();

int main()
{
	int choice,value;
	init();
	while(1)
	{
		printf("Enter Choice\n");
		printf("1. Push\n");
		printf("2. Pull\n");
		printf("3. exit\n");

		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter Value: ");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
				value = info[top];
				pop();
				printf("Value poped : %d\n",value);
				break;
		
			case 3:
				exit(1);
				break;
			default:
				printf("Invalid Choice\n");
				break;
	         }
	}
	return 0;
}

void init()
{
	int i;
	top = -1;
	for(i=0;i<SIZE;i++)
	{
		info[i]=-1;
	}
}

void push(int data)
{
	if(top == SIZE-1)
	{
		printf("Stack is Full\n");
	}
	else
	{
		top = top +1;
		info[top] = data;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		info[top] = -1;
		top = top-1;
	}
}
