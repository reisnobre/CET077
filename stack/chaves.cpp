#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>
#define SIZE 1000
using namespace std;


// Eduardo Reis Nobre e Gabriel Tranquili
typedef char obj_t;
typedef struct stack_st {
  int head;
  obj_t itens[SIZE];
} stack;

bool stackUp(stack *p, obj_t obj);
bool isEmpty(stack p);
bool isOrganizer(char o);
char soulMate(char a);
obj_t unStack(stack *p);
void stats(stack p);

int main(int argc, char const *argv[]) {
  obj_t o;
  string expr, posfix;
  int i = 0, a, b, c;
  char simb, temp;
  getline(cin, expr);
  while (expr[0] != '\0') {
    stack p;
    p.head = 0;
    bool valid = true;
    while (expr[i] != '\0') {
      simb = expr[i];
      if (isOrganizer(simb)) {
        if (expr[i - 1] != '\\') {
          stackUp(&p, simb);
        }
      } else if (soulMate(simb) != '0') {
        if (expr[i - 1] != '\\') {
          if (unStack(&p) != soulMate(simb)) {
            valid = false;
          }
        } else if (simb != '}') {
          if (unStack(&p) != soulMate(simb)) {
            valid = false;
          }
        }
      }
      i++;
    }
    if (p.head != 0) {
      valid = false;
    }
    if (valid)std::cout << "SIM" << '\n';
    else std::cout << "NAO" << '\n';
    getline(cin, expr);
  }
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
