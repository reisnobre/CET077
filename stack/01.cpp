#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>
#define SIZE 1000
using namespace std;

typedef char obj_t;
typedef struct stack_st {
  int head;
  obj_t itens[SIZE];
} stack;

bool stackUp(stack *p, obj_t obj);
bool isEmpty(stack p);
bool isOperator(char o);
bool isOrganizer(char o);
int powerLevel(char a);
char soulMate(char a);
obj_t unStack(stack *p);
void stats(stack p);

int main(int argc, char const *argv[]) {
  stack p;
  p.head = 0;
  obj_t o;
  string expr, posfix;
  expr = "4+5*6*7^(8+9)";
  int i = 0, a, b, c;
  char simb, temp;
  bool valid = true;
  // getline(cin, expr);
  while (expr[i] != '\0') {
    simb = expr[i];
    if (simb >= '0' && simb <= '9') {
      posfix.append(sizeof(char), simb);
    }
    if (simb == '(' || simb == '[' || simb == '{') {
      stackUp(&p, simb);
    }
    if (simb == ')' || simb == ']' || simb == '}') {
      // stats(p);
      while (p.itens[p.head - 1] != soulMate(simb)) {
        if (isEmpty(p)) break;
        temp = unStack(&p);
        posfix.append(sizeof(char), temp);
      }
    }
    if (isOperator(simb)) {
      if (isEmpty(p)) {
        stackUp(&p, simb);
      } else if (powerLevel(simb) > powerLevel(p.itens[p.head - 1]) || isOrganizer(p.itens[p.head - 1]) ) {
        stackUp(&p, simb);
      } else {
        while (powerLevel(simb) <= powerLevel(p.itens[p.head - 1])) {
          if (isEmpty(p)) break;
          posfix.append(sizeof(char), unStack(&p));
        }
        stackUp(&p, simb);
      }
    }
    i++;
  }
  while (!isEmpty(p)) {
    posfix.append(sizeof(char), unStack(&p));
  }
  std::cout << posfix << '\n';
  return 0;
}
char soulMate(char a) {
  switch (a) {
    case ')': {
      return '(';
      break;
    }
    case ']': {
      return '[';
      break;
    }
    case '}': {
      return '{';
      break;
    }
    default: {
      return '0';
      break;
    }
  }
}
int powerLevel(char a) {
  switch (a) {
    case '^': {
      return 3;
      break;
    }
    case '/': {
      return 2;
      break;
    }
    case '*': {
      return 2;
      break;
    }
    default: {
      return 1;
      break;
    }
  }
}
bool isOperator(char o) {
  if (o == '+' || o == '-' || o == '/' || o =='*' || o == '^') return true;
  return false;
}
bool isOrganizer(char o) {
  if (o == '(' || o == '[' || o == '{') return true;
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
