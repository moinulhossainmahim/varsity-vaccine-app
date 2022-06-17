#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node node;
node *start=NULL;

node * createNode() {
  node *newNode;
  newNode=(node *)malloc(sizeof(node));
  printf("Enter the data of new node: ");
  scanf("%d", &newNode->data);
  newNode->next=NULL;
  return newNode;
}

void createLinkedList(int n) {
  node *temp,*newNode;
  int i;
  for(i=0; i<n; i++) {
    newNode=createNode();
    if(start==NULL) {
      start=newNode;
    } else {
      temp=start;
      while(temp->next)
        temp=temp->next;
      temp->next=newNode;
    }
  }
}

void deleteFromEnd() {
  node *temp=start,*prev=NULL;
  if(temp==NULL)printf("There is no node exists\n");
  while(temp->next!=NULL) {
    prev=temp;
    temp=temp->next;
  }
  prev->next=NULL;
  free(temp);
  printf("Node has been deleted\n");
}

int nodeCounter() {
  node *temp=start;
  int length=0;
  while(temp) {
    length++;
    temp=temp->next;
  }
  return length;
}

void insetAtEven() {
  node *temp=start, *prev=NULL, *newNode;
  int i,pos;
  printf("Enter the position you want to insert new node: ");
  scanf("%d", &pos);
  if(pos<1 || pos>nodeCounter())
  {
    printf("Position is invalid\n");
  }
  else if(pos%2!=0)
  {
    printf("position must be even\n");
  }
  else
  {
    newNode=createNode();
    for(i=1; i<pos; i++) {
      prev=temp;
      temp=temp->next;
  }
  prev->next=newNode;
  newNode->next=temp;
  }
}

void traverse() {
  node *temp=start;
  while(temp) {
    printf("%d ", temp->data);
    temp=temp->next;
  }
  printf("\n");
}

int main() {
  createLinkedList(6);
  traverse();
  insetAtEven();
  return 0;
}
