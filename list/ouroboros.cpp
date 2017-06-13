#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

typedef string obj_t;

typedef struct element_st {
  obj_t value;
  struct element_st *after, *before;
} element;

void addItem (element **p, element **list, obj_t x);
void insertSort (element **list, obj_t x);
void removeItem(element **p, element **list);

int main(int argc, char const *argv[]) {
  element *list, *p;
  p = list = NULL;
  string name;
  for (int i = 0 ; i < 5 ;  i++) {
    getline(cin, name);
    addItem(&p, &list, name);
  }

  do {
    std::cout << p->value << '\n';
    p = p->after;
  } while(p != list);

  return 0;
}

void insertSort (element **p, obj_t x) {
  if ((*p) == NULL) { // lista vazia
    (*p) = (element *) malloc(sizeof(element));
    (*p)->before = (*p)->after = NULL;
    (*p)->value = x;
  } else { // lista contem itens
    element *node = (element *) malloc(sizeof(element));
    node->value = x;
    if ((*p)->value >= x) { // insere depois
      while (((*p)->value >= x) && (*p)->after != NULL) {
        (*p) = (*p)->after;
      }
      if ((*p)->after == NULL && (*p)->value >= x) { // estou na ultima posição possível
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

void addItem (element **p, element **list, obj_t x) {
  if ((*p) == NULL) { // lista vazia
    (*p) = (element *) malloc(sizeof(element));
    (*p)->before = (*p)->after =  NULL;
    (*p)->value = x;
  } else if ((*p)->after == NULL) { // lista contem 1 item
    element *node = (element *) malloc(sizeof(element));
    node->value = x;

    node->after = node->before = (*p);
    (*p)->after = (*p)->before = node;
  } else {
    element *node = (element *) malloc(sizeof(element));
    node->value = x;

    node->before = (*p);
    node->after = (*p)->after;
    (*p)->after->before = node;
    (*p)->after = node;
  }
  (*list) = (*p);
}

void removeItem(element **p, element **list) {
  element *d;
  d = (*p)->after;
  if ((*p) != NULL) {
    if ((*p)->after == NULL) { // ultimo elemento
      free((*p));
      (*p) = (*list) = NULL;
    } else if ((*p)->after->after != NULL) { // ainda tem itens na lista 3 ou mais
      (*p)->after->after->before = (*p);
      (*p)->after = (*p)->after->after;
    } else { // apenas 2
      (*p)->before = (*p);
      (*p)->after = (*p);
    }
    free(d);
    (*list) = (*p);
  }
}
