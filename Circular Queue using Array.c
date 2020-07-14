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
	int choice, value;
	init();

	while(1)
	{
		printf("Enter Choice\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to push: ");
				scanf("%d",&value);
				push(value);
				break;
			case 2:
				pop();
				break;


			case 3:
				exit(1);
			default:
				printf("Invalid choice\n");
				break;
		}
	}
	return 0;
}




void init()
{
	int i;
	rear = -1;
	front = -1;
	for(i=0;i<SIZE;i++)
	{
		info[i] = -1;
	}
}

void push(int data)
{
	if(front == -1 && rear == -1)    //inserting first element
	{
		front = rear = 0;
		info[rear] = data;
	}
	else if(((rear + 1) % SIZE) == front)  // if queue is full
	{
		printf("Queue is full\n");
	}
	else
	{
		rear = (rear + 1) % SIZE;
		info[rear] = data;
	}
}


void pop()
{
	if(rear == -1 && front == -1)
	{
		printf("Queue is Empty\n");
	}
	else if(front == rear)
	{
		printf("Value poped is %d\n", info[front]);
		front = -1;
		rear = -1;
	}
	else
	{
		printf("Value poped is %d\n",info[front]);
		front = (front + 1)%SIZE;
	}
}

