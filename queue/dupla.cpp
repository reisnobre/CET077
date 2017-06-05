#include <iostream>
#include <cstdlib>
#include <assert.h>
#define SIZE 1000
using namespace std;

// Eduardo Reis Nobre, Gabriel Tranquilli Ueslei Sales

typedef int obj_t;
typedef struct queue_st {
  int head, tail;
  bool empty, full;
  obj_t itens[SIZE];
} queue;

bool enqueue(queue *q, obj_t obj);
int dequeue(queue *q);
bool isEmpty(queue q);
void status(queue q);
int peek(queue *q);

int main(int argc, char const *argv[]) {
  int N, i = 0, value;
  char ctrl;
  queue q1;
  queue q2;
  queue q3;
  q1.head = q1.tail = 1;
  q1.full = false;
  q1.empty = true;

  q2.head = q2.tail = 1;
  q2.full = false;
  q2.empty = true;

  q3.head = q3.tail = 1;
  q3.full = false;
  q3.empty = true;

  std::cin >> N;
  while (N != 0) {
    for (i = 0; i < N ; i++) {
      std::cin >> ctrl;
      if (ctrl == 'E') {
        std::cin >> value;
        if (value < 5000) {
          enqueue(&q1 , value);
        } else {
          enqueue(&q2 , value);
        }
      } else {
        if (!isEmpty(q1)) {
          dequeue(&q1);
        } else {
          dequeue(&q2);
        }
      }
    }
    while (!isEmpty(q1)) {
      std::cout << dequeue(&q1) << ' ';
    }
    std::cout << '\n';
    while (!isEmpty(q2)) {
      std::cout << dequeue(&q2);
    }
    std::cout << '\n';
    std::cin >> N;
  }
  return 0;
}

bool enqueue(queue *q, obj_t obj) {
  if (!q->full) {
    q->itens[q->tail++-1] = obj;
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
  i = q.head - 1;
  if (!isEmpty(q)) {
    do {
      std::cout << q.itens[i] << ' ';
      i++;
      if (i == SIZE) i = 0;
    } while(i != q.tail - 1);
  } else {
    std::cout << "*";
  }
  std::cout << '\n';
}
