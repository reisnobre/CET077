#include <iostream>
#include <cstdlib>
#include <assert.h>
#define SIZE 1000
using namespace std;

typedef int obj_t;

typedef struct element_st {
  obj_t value;
  element_st *next;
} element;

typedef struct queue_st {
  int head, tail, priority;
  bool empty, full;
  element item;
} queue;

bool enqueue(queue *q, obj_t obj, int priority);
int dequeue(queue *q);
bool isEmpty(queue q);
void status(queue q);

int main(int argc, char const *argv[]) {
  queue q;
  q.head = q.tail = 1;
  q.full = false;
  q.empty = true;

  return 0;
}

bool enqueue(queue *q, obj_t obj, int priority) {
  int i = 0, k = q->tail;
  if (!q->full) {
    if (q->empty) {
      q->itens[q->tail++-1] = obj;
    } else {
      for(i ; i < k ; i++) {
        if (priority > q->itens[i].priority) {
          std::cout << "stakin" << '\n';
          q->itens[q->tail++ - 1] = q->itens[q->tail - 1];
          q->itens[q->tail - 1] = obj;
          break;
        } else {
          q->itens[q->tail++-1] = obj;
          break;
        }
      }
    }
    if (q->tail > SIZE) q->tail = 1;
    if (q->head == q->tail) q->full = true;
    q->empty = false;
    return true;
  }
  return false;
}

int dequeue(queue *q) {
  obj_t o;
  assert(!q->empty);
  o = q->itens[q->head++ - 1];
  if (q->head > SIZE) q->head = 1;
  if (q->head == q->tail) q->empty = true;
  q->full = false;
  return o;
}
bool isEmpty(queue q) {
  return q.empty;
}

void status(queue q) {
  int i = 0;
  std::cout << q.head << ": ";
  i = q.head - 1;
  if (!isEmpty(q)) {
    do {
      std::cout << q.itens[i] << ' ';
      i++;
      if (i == SIZE) i = 0;
    } while(i != q.tail - 1);
  }
  std::cout << " :" << q.tail << '\n';
}
