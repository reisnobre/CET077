#include <iostream>
#include <cstdlib>
#include <assert.h>
#define SIZE 1000
using namespace std;

typedef int obj_t;

typedef struct element_st {
  obj_t value;
  int priority;
  struct element_st *next;
} element;

typedef struct queue_st {
  bool empty, full;
  element *itens;
} queue;

bool enqueue(queue *q, obj_t obj, int priority);
int dequeue(queue *q);
bool isEmpty(queue q);
void status(queue q);

int main(int argc, char const *argv[]) {
  queue q;
  q.full = false;
  q.empty = true;
  q->itens->next = 0;
  // element *p;
  // q.itens = (element *)malloc(sizeof(element));
  // p = q.itens;

  return 0;

}

bool enqueue(queue *q, obj_t obj, int priority) {

}

int dequeue(queue *q) {

}
bool isEmpty(queue q) {
  return q.empty;
}

void status(queue q) {

}
