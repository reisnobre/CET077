#include <iostream>
#include <cstdlib>

using namespace std;

typedef int obj_t;

typedef struct element_st {
  obj_t num;
  struct element_st *after, *before;
} element;

void addItem (element **list, obj_t x);
void insertSort (element **list, obj_t x);

int main(int argc, char const *argv[]) {
  element *list, *p;
  p = list = NULL;
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

void insertSort (element **p, obj_t x) {
  if ((*p) == NULL) { // lista vazia
    (*p) = (element *) malloc(sizeof(element));
    (*p)->before = (*p)->after = NULL;
    (*p)->num = x;
  } else { // lista contem itens
    element *node = (element *) malloc(sizeof(element));
    node->num = x;
    if ((*p)->num >= x) { // insere depois
      while (((*p)->num >= x) && (*p)->after != NULL) {
        (*p) = (*p)->after;
      }
      if ((*p)->after == NULL && (*p)->num >= x) { // estou na ultima posição possível
        node->before = (*p);
        node->after = (*p)->after;
        (*p)->after = node;
      } else { // inserindo no meio
        node->after = (*p);
        node->before = (*p)->before;
        (*p)->before->after = node;
        (*p)->before = node;
      }
    }
    else { // insere antes
      node->after = (*p);
      node->before = NULL;
      (*p)->before = node;
      (*p) = node;
    }
  }
  // traz p sempre pro começo da lista
  while ((*p)->before != 0) {
    (*p) = (*p)->before;
  }
}

void addItem (element **p, obj_t x) {
  if ((*p) == 0) { // lista vazia
    (*p) = (element *) malloc(sizeof(element));
    (*p)->before = (*p)->after = 0;
    (*p)->num = x;
  } else { // lista contem itens
    element *node = (element *) malloc(sizeof(element));
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
