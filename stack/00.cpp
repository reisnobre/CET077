#include <iostream>
#include <cstdlib>
#include <assert.h>
#define SIZE 1000
using namespace std;
typedef int obj_t;
typedef struct stack_st {
  int head;
  obj_t itens[SIZE];
} stack;

bool stackUp(stack *p, obj_t obj);
bool isEmpty(stack p);
int unStack(stack *p);
void stats(stack p);

int main(int argc, char const *argv[]) {
  stack p;
  p.head = 0;
  obj_t o;
  stackUp(&p, 5);
  stats(p);
  stackUp(&p, 3);
  stats(p);
  stackUp(&p, 2);
  stats(p);
  unStack(&p);
  stats(p);
  unStack(&p);
  stats(p);
  stackUp(&p, 8);
  while (!isEmpty(p)) unStack(&p);
  return 0;
}

bool stackUp(stack *p, obj_t obj) {
  if (p->head < SIZE) {
    p->itens[p->head++] = obj;
    return true;
  }
  return false;
}
obj_t unStack(stack *p) {
  assert(p->head > 0);
  return p->itens[--p->head];
}
bool isEmpty(stack p) {
  return (p.head ? false : true);
}

void stats(stack p) {
  int i = 0;
  for(i ; i < p.head ; i++) std::cout << p.itens[i] << '\n';
  std::cout << '\n';
  return;
}
