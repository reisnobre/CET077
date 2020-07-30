#include <iostream>
#include <cstdlib>
#include <assert.h>

// Ueslei Sales, Gabriel Tranquili, Eduardo Reis Nobre

typedef struct arvore_st {
  char info;
  struct arvore_st *filhos[N];
  struct arvore_st *pai;
} arvore;

int counterb = -1;

void preordem(arvore *a) {
  if(a != NULL) {
    counterb++;
    std::cout << a->info;
    preordem(a->filhos[counterb]);
  }
  return;
}

int counter = -1;
void posordem(arvore *a) {
  if(a != NULL) {
    counter++;
    posordem(a->filhos[counterb]);
    std::cout << a->info;
  }
  return;
}
