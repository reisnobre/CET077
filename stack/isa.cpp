#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <cstring>
// Eduardo Reis Nobre e Gabriel Tranquilli
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
  int N, i = 0, value, a, b;
  string ctrl;
  stack p;
  p.head = 0;
  obj_t o;
  std::cin >> N;
  while (N != 0) {
    for (i = 0; i < N ; i++) {
      getline(cin, ctrl);
      if (ctrl == "BIPUSH") {
        std::cin >> value;
        i--;
        std::cout << "/* staking */" << value << '\n';
        stackUp(&p, value);
      } else if (ctrl == "IADD") {
        a = unStack(&p);
        b = unStack(&p);
        stackUp(&p, a + b);
      } else if (ctrl == "ISUB") {
        a = unStack(&p);
        b = unStack(&p);
        stackUp(&p, a - b);
      } else if (ctrl == "IMUL") {
        a = unStack(&p);
        b = unStack(&p);
        stackUp(&p, a * b);
      }
    }
    std::cin >> N;
  }
  std::cout << p.itens[p.head - 1] << '\n';
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
