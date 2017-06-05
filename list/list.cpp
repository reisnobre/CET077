#include <iostream>
#include <cstdlib>

using namespace std;

typedef int obj_t;

typedef struct number_st {
  obj_t num;
  struct number_st *after, *before;
} number;

void addItem (number **list, obj_t x);
void insertSort (number **list, obj_t x);

int main(int argc, char const *argv[]) {
  number *list, *p;
  p = list = 0;
  insertSort(&p, 10);
  insertSort(&p, 1);
  insertSort(&p, 4);
  insertSort(&p, -4);
  while (p != 0) {
    std::cout << p->num << '\n';
    p = p->after;
  }
  return 0;
}

void insertSort (number **p, obj_t x) {
  if ((*p) == 0) { // lista vazia
    (*p) = (number *) malloc(sizeof(number));
    (*p)->before = (*p)->after = 0;
    (*p)->num = x;
  } else { // lista contem itens
    number *node = (number *) malloc(sizeof(number));
    node->num = x;
    if ((*p)->num >= x) { // insere depois
      while (((*p)->num >= x) && (*p)->after != 0) {
        (*p) = (*p)->after;
      }
      if ((*p)->after == 0 && (*p)->num >= x) { // estou na ultima posição possível
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
  // traz p sempre pro começo da lista
  while ((*p)->before != 0) {
    (*p) = (*p)->before;
  }
}

void addItem (number **p, obj_t x) {
  if ((*p) == 0) { // lista vazia
    (*p) = (number *) malloc(sizeof(number));
    (*p)->before = (*p)->after = 0;
    (*p)->num = x;
  } else { // lista contem itens
    number *node = (number *) malloc(sizeof(number));
    node->after = 0;
    node->before = (*p);
    node->num = x;
    (*p)->after = node;
    (*p) = node;

    // traz p sempre pro começo da lista
  }
  while ((*p)->before != 0) {
    (*p) = (*p)->before;
  }
}
