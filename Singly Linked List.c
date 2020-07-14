#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE *head = NULL;


void displayList();
NODE* createNode(int val);
void addFirst(int val);
void addLast(int val);
void insert(int pos,int val);
int delFirst();
void del(int pos);
void delAll();



int main()
{
	int choice,value,pos;
	while(1)
	{
		printf("Enter Choice\n");
		printf("1.Display\n");
		printf("2.Add First\n");
		printf("3.Add Last\n");
		printf("4.Insert at pos\n");
		printf("5.Delete First\n");
		printf("6.Delete at Pos\n");
		printf("7.Delete All\n");
		printf("8.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				displayList();
				break;
			case 2:
				printf("Enter Value: ");
				scanf("%d",&value);
				addFirst(value);
				break;
			case 3:
				printf("Enter Value: ");
				scanf("%d",&value);
				addLast(value);
				break;
			case 4:
				printf("Enter Value: ");
				scanf("%d",&value);
				printf("Enter Position: ");
				scanf("%d",&pos);
				insert(pos,value);
				break;
			case 5:
				delFirst();
				break;
			case 6:
				printf("Enter Position: ");
				scanf("%d",&pos);
				del(pos);
				break;
			case 7:
				delAll();
				break;
			case 8:
				exit(1);
		}
	}
	return 0;
}



void displayList()
{
	NODE *trav;
	printf("List : ");
	trav=head;


	while(trav != NULL)
	{
		printf("%d->",trav->info);
		trav=trav->next;
	}
	printf("\n");
}

NODE* createNode(int val)
{
	NODE *newnode;
	newnode = (NODE *)malloc(sizeof(NODE));
	newnode->info = val;
	newnode->next = NULL;
	return newnode;
}

void addFirst(int val)
{
	NODE *newnode;
	newnode=createNode(val);
	if(head==NULL)
		head = newnode;
	else
	{
		newnode->next=head;
		head = newnode;
	}
}

void addLast(int val)
{
	NODE *newnode,*trav;
	newnode = createNode(val);
	if(head==NULL)
		head=newnode;
	else
	{
		trav=head;
		while(trav->next != NULL)
			trav = trav->next;
		trav->next = newnode;
	}
}

void insert(int pos,int val)
{
	NODE *trav,*newnode;
	int i;
	if(head == NULL || pos<=1)
		addFirst(val);
	else
	{
		trav = head;
		for(i=1;i<pos-1;i++)
		{
			trav = trav->next;
			if(trav == NULL)
			{
				printf("Invalid Position\n");
				return;
			}
		}
		newnode = createNode(val);
		newnode->next = trav->next;
		trav->next = newnode;
	}
}


int delFirst()
{
	NODE *temp;
	int val=0;
	if(head == NULL)
	{
		printf("List Empty\n");
		return 0;
	}
	val = head->info;
	temp = head;
	head = head->next;
	free(temp);
	return val;
}



void del(int pos)
{
	int i;
	NODE *trav,*temp;
	if(head == NULL || pos<=1)
		delFirst();
	else
	{
		trav = head;
		for(i=1;i<pos-1;i++)
		{
			if(trav==NULL)
			{
				printf("Invalid Position\n");
				return;
			}
			trav = trav->next;
		}
		temp = trav->next;
		trav->next = temp->next;
		free(temp);
	}
}

void delAll()
{
	NODE *temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

