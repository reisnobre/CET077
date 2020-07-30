#include <iostream>
#include <cstdlib>
#include <assert.h>
#define SIZE 1000
using namespace std;
typedef int obj_t;

// Eduardo Reis Nobre, Gabriel Tranquilli Ueslei Sales

typedef struct number_st {
  obj_t num;
  struct number_st *after, *before;
} number;

typedef struct queue_st {
  int head, tail;
  bool empty, full;
  number *itens;
} queue;

bool enqueue(queue *q, obj_t obj);

void insertSort (number **p, queue *q, obj_t x);

void dequeue(number **p, queue *q);
bool isEmpty(queue q);
void status(number *p, queue q);
int peek(queue *q);

int main(int argc, char const *argv[]) {
  int N, i = 0;
  obj_t value;
  char ctrl;

  std::cin >> N;
  while (N != 0) {
    number * p;
    queue q;
    p = q.itens = NULL;
    q.head = q.tail = 1;
    q.full = false;
    q.empty = true;

    for (i = 0; i < N ; i++) {
      std::cin >> ctrl;
      if (ctrl == 'E') {
        std::cin >> value;
        insertSort(&p, &q, value);
        status(p, q);
      } else {
        dequeue(&p, &q);
        status(p, q);
      }
    }
    std::cout << '\n';
    std::cin >> N;
  }
  return 0;
}

void insertSort (number **p, queue *q, obj_t x) {
  if ((*p) == 0) { // lista vazia
    (*p) = (number *) malloc(sizeof(number));
    (*p)->before = (*p)->after = 0;
    (*p)->num = x;
    q->empty = false;
  } else { // lista contem itens
    number *node = (number *) malloc(sizeof(number));
    node->num = x;
    q->tail++;
    if ((*p)->num <= x) { // insere depois
      while (((*p)->num <= x) && (*p)->after != 0) {
        (*p) = (*p)->after;
      }
      if ((*p)->after == 0 && (*p)->num <= x) { // estou na ultima posição possível
        node->before = (*p);
        node->after = (*p)->after;
        (*p)->after = node;
      } else { // inserindo no meio
        node->after = (*p);
        node->before = (*p)->before;
        (*p)->before->after = node;
        (*p)->before = node;
      }
    } else { // insere antes
      node->after = (*p);
      node->before = 0;
      (*p)->before = node;
      (*p) = node;
    }
  }
  q->empty = false;
  // traz p sempre pro começo da lista
  while ((*p)->before != 0) {
    (*p) = (*p)->before;
  }
}

void dequeue(number **p, queue *q) {
  assert(!q->empty);
  q->full = false;
  if ((*p)->after !=0) { // tenho +  de 1 item
    (*p)->after->before = 0;
    (*p)->after = 0;
  } else { // apenas um item
    (*p) = 0;
  }
}
bool isEmpty(queue q) {
  return q.empty;
}

void status(number *p, queue q) {
  number *t;
  t = p;
  while (t != 0) {
    std::cout << t->num << " ";
    t = t->after;
  }
  if (p == 0) {
    std::cout << "*";
  }
  std::cout << '\n';
}
