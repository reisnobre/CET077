/*
 * C Program to Implement various Queue Functions using Dynamic Memory Allocation
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node_st {
    int data;
    struct node_st *next;
} node;

// function protypes
void insert();
void delete();
void queue_size();
void check();
void first_element();

void main () {
  int value;
  node *front, *rear;
}

void insert () {
  node *temp;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter value to be inserted \n");
  scanf("%d", &temp->data);
  temp->link = NULL;
  if (rear  ==  NULL) {
    front = rear = temp;
  } else {
    rear->link = temp;
    rear = temp;
  }
}

// delete elements from queue
void delete()
{
    struct node *temp;

    temp = front;
    if (front == NULL)
    {
        printf("queue is empty \n");
        front = rear = NULL;
    }
    else
    {
        printf("deleted element is %d\n", front->data);
        front = front->link;
        free(temp);
    }
}

// check if queue is empty or not
void check()
{
    if (front == NULL)
        printf("\nQueue is empty\n");
    else
        printf("*************** Elements are present in the queue **************\n");
}

// returns first element of queue
void first_element()
{
    if (front == NULL)
    {
        printf("**************** The queue is empty ****************\n");
    }
    else
        printf("**************** The front element is %d ***********\n", front->data);
}

// returns number of entries and displays the elements in queue
void queue_size()
{
    struct node *temp;

    temp = front;
    int cnt = 0;
    if (front  ==  NULL)
    {
        printf(" queue empty \n");
    }
    while (temp)
    {
        printf("%d  ", temp->data);
        temp = temp->link;
        cnt++;
    }
    printf("********* size of queue is %d ******** \n", cnt);
}
