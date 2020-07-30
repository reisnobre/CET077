#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Ueslei Sales, Gabriel Tranquili, Eduardo Reis Nobre

typedef struct arvore_st {
  char info;
  struct arvore_st *filhos[N];
  struct arvore_st *pai;
} arvore;

void preordem(arvore *a) {
  int i;
  printf("%c", a->info);
  for (i = 0; i < N ; i++) {
    if(a->filhos[i] != NULL) {
      preordem(a->filhos[i]);
    }
  }
  return;
}

void posordem(arvore *a) {
  int i;
  for (i = 0; i < N ; i++) {
    if(a->filhos[i] != NULL) {
      posordem(a->filhos[i]);
    }
  }
  printf("%c", a->info);
  return;
}
