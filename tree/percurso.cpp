#include <iostream>
#include <cstdlib>
#include <assert.h>
#define N 5
using namespace std;
typedef char obj_t;

typedef struct arvore_st {
  char info;
  struct arvore_st *filhos[N];
  struct arvore_st *pai;
} arvore;

int insert(arvore *a, arvore *c, int i);
obj_t info(arvore *a);
arvore * child(arvore *a, int i);
void iniciar(arvore *a, obj_t info);
void preordem(arvore *a);
void posordem(arvore *a);

int main(int argc, char const *argv[]) {

  arvore * d, * c, * f;
  d = (arvore *) malloc(sizeof(arvore));
  c = (arvore *) malloc(sizeof(arvore));
  f = (arvore *) malloc(sizeof(arvore));
  iniciar(d, 'd');
  iniciar(c, 'c');
  iniciar(f, 'f');
  insert(d,c,0);
  insert(c,f,1);
  preordem(d);
  std::cout << '\n';
  // posordem(d);
  // std::cout << '\n';
  return 0;
}

arvore * child(arvore *a, int i) {
  arvore * f = NULL;
  if(a != NULL)
    f = a->filhos[i];
  return f;
}

void preordem(arvore *a) {
  int i;
  for (i = 0; i < N ; i++) {
    if(a->filhos[i] != NULL) {
      std::cout << a->filhos[i]->info;
      preordem(a->filhos[i]);
    }
  }
  return;
}
// void posordem(arvore *a) {
//   if(a != NULL) {
//     posordem(child(a, counter));
//     std::cout << info(a);
//   }
//   return;
// }

int insert(arvore *a, arvore *c, int i) {
  assert(i < N);
  assert(c != NULL);
  assert(a != NULL);
  c->pai = a;
  a->filhos[i] = c;
}

obj_t info(arvore *a) {
  if (a != NULL) {
    return a->info;
  }
  return false;
}

void iniciar(arvore *a, obj_t info) {
  int i;
  a->info = info;
  a->pai = NULL;
  for(i = 0; i < N ; i++) a->filhos[i] = NULL;
}

void removeFilho(arvore *a, int i) {
  int k;
  arvore *f = NULL;

  if(a!=NULL) {
    f = a->filhos[i];
    a->filhos[i] = NULL;
    if(f != NULL) {
      for(k = 0; k < N; k++) removeFilho(f,k);
    }
    free(f);
  }
  return;
}
