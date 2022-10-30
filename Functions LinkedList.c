#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *link;
};
void merge(struct Node **q,struct Node **p)
{
	struct Node *temp;
	temp=*q;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=*p;
	
}
void count(struct Node *q)
{
	int i=0;
	while(q!=NULL)
	{
		i++;
		q=q->link;
	}
	printf("Number of Nodes = %i",i);
	printf("\n");
}
void display(struct Node *q)
{
	while(q!=NULL)
	{
		printf("%i\t",q->data);
		q=q->link;
	}
	printf("\n");
}
void addAtSpecific(struct Node **q,int d,int pos)
{
	struct Node *r,*temp;
	int i;
	r=(struct Node*)malloc(sizeof(struct Node));
	r->data=d;
	r->link=NULL;
	temp=*q;
	for(i=1;i<pos;i++)
	{
		temp=temp->link;
	}
	r->link=temp->link;
	temp->link=r;
}
void circular(struct Node **q)
{
	struct Node *temp;
	temp=*q;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=*q;
}
void circulardisplay(struct Node *q)
{
	struct Node *temp;
	temp=q;
	while(temp->link!=q)
	{
		printf("%i\t",temp->data);
		temp=temp->link;
	}
	printf("%i\t",temp->data);
	temp=temp->link;
	printf("%i\t",temp->data);
}
void addAtBeg(struct Node **q,int d)
{
	struct Node *r,*temp;
	r=(struct Node*)malloc(sizeof(struct Node));
	r->data=d;
	r->link=*q;
	*q=r;
}
void delAtStart(struct Node **q)
{
	struct Node *temp;
	temp=*q;
	*q=temp->link;
	free(temp);
}
void delAtLast(struct Node **q)
{
	struct Node *temp,*prev;
	temp=*q;
	while(temp->link!=NULL)
	{
		prev=temp;
		temp=temp->link;
	}
	prev->link=NULL;
	free(temp);
}
void delAtSpecific(struct Node **q,int pos)
{
	struct Node *temp,*prev;
	temp=*q;
	while(pos!=1)
	{
		prev=temp;
		temp=temp->link;
		pos--;
	}
	prev->link=temp->link;
	free(temp);
}
void reverse(struct Node **q)
{
	struct Node *prev=NULL,*next=NULL,*head;
	head=*q;
	while(head!=NULL)
	{
		next=head->link;
		head->link=prev;
		prev=head; 
		head=next;
	}
	head=prev;
	*q=head;
}
void append(struct Node **q,int d)
{
	struct Node *r,*temp;
	r=(struct Node*)malloc(sizeof(struct Node));
	r->data=d;
	r->link=NULL;
	if(*q==NULL)
	{
		*q=r;
		temp=r;
	}
	else 
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;	
		}	
		temp->link=r;
	}
}
void sortasc(struct Node **q)
{
	struct Node *i,*j,*start;
	i=*q;
	j=*q;
	start=*q;
	int temp;
	for(i=start;i->link!=NULL;i=i->link)
	{
		for(j=i->link;j!=NULL;j=j->link)
		{
			if(i->data>j->data)
			{
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
	q=start;
}
void sortdes(struct Node **q)
{
	struct Node *i,*j,*start;
	i=*q;
	j=*q;
	start=*q;
	int temp;
	for(i=start;i->link!=NULL;i=i->link)
	{
		for(j=i->link;j!=NULL;j=j->link)
		{
			if(i->data<j->data)
			{
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
	q=start;
}
int LinearSearch(struct Node **q,int key)
{
	struct Node *temp;
	temp=*q;
	while(temp->link!=NULL)
	{
		if(key==temp->data)
		{
			return 1;
		}
		temp=temp->link;
	}
	return -1;
}
void main()
{
	struct Node *p=NULL,*t=NULL;
	append(&p,10);
	append(&p,20);
	append(&p,30);
	append(&p,40);
	append(&t,45);
	append(&t,32);
	append(&t,76);
	append(&t,54);
	append(&t,43);
	count(p);
	display(p);
	addAtBeg(&p,50);
	display(p);
	addAtSpecific(&p,70,3);
	display(p);
	delAtStart(&p);
	display(p);
	delAtLast(&p);
	display(p);
	delAtSpecific(&p,2);
	display(p);
	reverse(&p);
	display(p);
	sortasc(&p);
	display(p);
	sortdes(&p);
	display(p);
	merge(&p,&t);
	display(p); 
	int key=LinearSearch(&p,76);
	if(key==-1)
	{
		printf("Value Not Found");
	}
	if(key==1)
	{
		printf("Value Found\n");
	}
	circular(&p);
	circulardisplay(p);
}
