#include <stdio.h>
#include <stdlib.h>

struct dlist {
	int data;
	struct dlist * rlist, * llist;
};

typedef struct dlist node;
node *ptr, *root, *cur, *last;

void creation() {
	int a,ch;
	root=NULL;
	ptr=root;
	printf("\n Enter data for node (-999 to stop)");
	scanf("%d", &a);
	while(a!=-999) {
		cur=(node *)malloc(sizeof(node));
		cur->data=a;
		cur->rlist=NULL;
		cur->llist=NULL;
		if(root==NULL)
			root=cur;
		else
			ptr->rlink=cur;
		ptr=cur;
		printf("\n Enter data for node(-999 to stop)");
		scanf("%d", &a);
	}
}

void insertion() {
	int ele;
	char ch;
	ptr=root;
	cur=(node *)malloc(sizeof(node));
	printf("\n Enter the data for node");
	scanf("%d", &ele);
	cur->data=ele;
	cur->rlink=NULL;
	cur->llink=NULL;
	fflush(stdin);
	printf("\n Do you want to insert first [y/n]");
	scanf("%c",&ch);
	if(ch=='y' || ch=='Y') {
		ptr->llink=cur;
		cur->rlink=ptr;
		root=cur;
	} else {
		printf("\n After which element do you want to insert");
		scanf("%d",&ele);
		while(ptr!=NULL) {
			if(ptr->data==ele) {
				cur->rlink=ptr->rlink;
				cur->llink=ptr;
				ptr->rlink->llink=cur;
				ptr->rlink=cur;
				break;
			} else {
				ptr=ptr->rlink;
			}
		}
}


void deletion() {
	int ele;
	char ch;
	ptr=root;
	fflush(stdin);
	prinf("\n do you want to delete first element [Y/N]");
	scanf("%c",&ch);
	if(ch=='Y' || ch=='N') {
		ptr->rlink->llink=ptr->llink;
		root=ptr->rlink;
	} else {
		printf("\n which element do you want to delete");
		scanf("%d",&ele);
		while(ptr!=NULL) {
			if(ptr->data==ele) {
				ptr->rlink->llink=ptr->llink;
				ptr->llink->rlink=ptr->rlink;
				break; 
			} else {
				ptr=ptr->rlink;
			}
	}
}


void display() {
ptr=root;
//last=NULL;
printf("\n the double linked list is: \n");
prinf("root->");
while(ptr!=NULL)
{
prinf("%d->",ptr->data);
if(ptr->rlink==NULL);
last=ptr;
ptr=ptr->rlink;
}
prinf("NULL");
}
void main()
{
int ch
clrscr();
creation();
printf("\n 1. insertion");
printf("\n 2. deletion");
printf("\n 3. display \n");
printf("\n 4. exit \n");
do
{
printf("\n Enter your option");
scanf("%d",&ch);
switch(ch)
{
case 1:
insertion();
break;
case 2:
deletion();
break;
case 3:
display();
break;
case 4:
exit(0);
} {
while(ch<=4);
getch();
}
