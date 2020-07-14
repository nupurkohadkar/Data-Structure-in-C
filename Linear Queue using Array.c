#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int info[SIZE];
int rear;
int front;

void init();
void push(int data);
void pop();

int main()
{
	int choice,value;
	init();
	while(1)
	{
		printf("\nEnter Choice\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter value to push: ");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
				value = info[front+1];
				pop();
				printf("Value Popped: %d",value);
				break;


			case 3:
				exit(1);
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
	front = -1;
	rear = -1;
	for(i=0;i<SIZE;i++)
		info[i] = -1;
}

void push(int data)
{
	if(rear == SIZE-1)
	{
		printf("Queue is Full\n");
	}
	else
	{
		rear = rear +1;
		info[rear] = data;
	}
}

void pop()
{
	if(rear == front)
	{
		printf("Queue is Empty\n");
	}


	else
	{
		front = front + 1;
		info[front] = -1;
	}
}
