#include <iostream>
#include <cstdlib>
#include <assert.h>
// Eduardo Reis Nobre e Gabriel Tranquill
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
  int N, i = 0, value;
  char ctrl;
  stack p;
  p.head = 0;
  obj_t o;
  std::cin >> N;
  while (N != 0) {
    for (i = 0; i < N ; i++) {
      std::cin >> ctrl;
      if (ctrl == 'E') {
        std::cin >> value;
        stackUp(&p, value);
        stats(p);
      } else {
        unStack(&p);
        stats(p);
      }
    }
    while (!isEmpty(p)) unStack(&p);
    std::cout << '\n';
    std::cin >> N;
  }
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
  int i = p.head;
  if (p.head < 1) {
    std::cout << "*";
  } else {
    std::cout << p.itens[i - 1];
    i--;
    for(i ; i > 0 ; i--) {
      std::cout << ' ' << p.itens[i - 1];
    }
  }
  std::cout << '\n';
  return;
}
