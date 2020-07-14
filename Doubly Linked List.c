#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *prev;
	struct node *next;
}NODE;

NODE *head=NULL;


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
		printf("\nEnter Choice\n");
		printf("1.Display List\n");
		printf("2.Add First\n");
		printf("3.Add Last\n");
		printf("4.Insert at Position\n");
		printf("5.Delete First\n");
		printf("6.Delete at Position\n");
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
	printf("FWD : ");
	if(head == NULL)
		return ;
	trav = head;	



	while(trav != NULL)
	{
		printf("%d->",trav->info);
		trav = trav->next;
	}
	printf("\nREV : ");
	trav = head;
	while(trav->next != NULL)
		trav=trav->next;
	while(trav != NULL)
	{
		printf("%d->",trav->info);
		trav = trav->prev;
	}
	printf("\n");
}

NODE* createNode(int val)
{
	NODE *newnode;
	newnode = (NODE *)malloc(sizeof(NODE));
	newnode->info = val;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void addFirst(int val)
{
	NODE *newnode;
	newnode = createNode(val);
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}
}
	

void addLast(int val)
{
	NODE *newnode,*trav;
	newnode = createNode(val);
	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		trav = head;
		while(trav->next != NULL)
		{
			trav=trav->next;
		}
		trav->next = newnode;
		newnode->prev = trav;
	}
}


void insert(int pos,int val)
{
	NODE *newnode,*trav,*travnext;
	int i;
	newnode = createNode(val);
	if(head == NULL || pos<=1)
	{
		head = newnode;
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			trav=trav->next;
			if(trav == NULL)
			{
				printf("Invalid Position\n");
				return;
			}
			
		}
		travnext = trav->next;
		newnode->prev = trav;
		newnode->next = travnext;
		trav->next = newnode;
		if(travnext != NULL)
			travnext->prev=newnode;
	}
}

int delFirst()
{
	NODE *temp;
	int val = 0;
	if(head == NULL)
	{
		printf("List is Empty\n");
		return 0;
	}
	val=head->info;
	temp = head;
	head = head->next;
	if(head != NULL)
		head->prev = NULL;
	free(temp);
	return val;
}


void del(int pos)
{
	NODE *trav;
	int i;
	if(head == NULL || pos<=1)
	{
		delFirst();
	}
	else
	{
		trav=head;
		for(i=1;i<pos;i++)
		{
			if(trav==NULL)
			{
				printf("Invalid Position\n");
				return ;
			}
			trav = trav->next;
		}
			trav->prev->next = trav->next;
			if(trav->next != NULL)
				trav->next->prev = trav->prev;
			free(trav);
	}
}

void delAll()
{
	NODE *temp;
	while(head!=NULL)
	{
		temp = head;
		head=head->next;
		free(temp);
	}
}

