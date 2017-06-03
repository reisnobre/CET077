#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>
#include <cmath>
#define SIZE 1000
using namespace std;

// Eduardo Reis Nobre e Gabriel Tranquilli

typedef int obj_t;
typedef struct stack_st {
  int head;
  obj_t itens[SIZE];
} stack;

bool stackUp(stack *p, obj_t obj);
bool isEmpty(stack p);
bool isOperator(char o);
double operate(double x, char op, double y);
obj_t unStack(stack *p);
void stats(stack p);

int main(int argc, char const *argv[]) {
  stack p;
  p.head = 0;
  obj_t o;
  string expr, posfix;
  int N, i = 0, value, a, b;
  char simb, temp;
  std::cin >> N;
  while (N != 0) {
    i = N;
    while (i > 0) {
      std::cin >> simb;
      if (isEmpty(p)) {
        stackUp(&p, simb);
      } else if (isOperator(simb)) {
        a = unStack(&p);
        b = unStack(&p);
        stackUp(&p, operate(a, simb, b));
      } else {
        stackUp(&p, simb);
      }
      i--;
    }
    std::cout << unStack(&p) << '\n';
    std::cin >> N;
  }
  return 0;
}

double operate(double x, char op, double y) {
  switch (op) {
    case '+':{
      return x + y;
      break;
    }
    case '-':{
      return x - y;
      break;
    }
    case '*':{
      return x * y;
      break;
    }
    case '/':{
      return x / y;
      break;
    }
    case '^':{
      return pow(x,y);
      break;
    }

  }
}
bool isOperator(char o) {
  if (o == '+' || o == '-' || o == '/' || o =='*' || o == '^') return true;
  return false;
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
