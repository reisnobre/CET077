#include <iostream>
#include <cstdlib>
#include <assert.h>

#define M 4
using namespace std;

typedef int obj_t;

typedef struct mTree_st {
  bool isLeaf;
  int nKeys;
  obj_t info[M - 1];
  struct mTree_st *children[M];
} mTree;

mTree *mtCreate(void);
void mtInsert(mTree *m, obj_t val);

int height(tree *a);

int main(int argc, char const *argv[]) {
  mTree *m;
  m = mtCreate();
  int N, P;
  std::cin >> N >> P;

  return 0;
}

mTree *mtCreate(void) {
  mTree *m;
  m = (mTree *)malloc(sizeof(mTree));
  assert(m);

  m->isLeaf = true;
  m->nKeys = 0;
  for (int i = 0; i < (M - 1); i++) m->info[i] = -1;
  return m;
}

void mtInsert(mTree *m, obj_t val) {
  if (m->nKeys == 0) {
    m->info[m->nKeys++] = val;
  } else {
    int i = 0;
    for (i ; m->info[i] && val > m->info[i]; i++);
    if (i == 0) { // Menor valor do vetor
      m->isLeaf = false;
      if (m->children[0]) { // já possui filho, fazer recursivo
        mtInsert(m->children[0], val);
      } else { // não possui filho
        m->children[0] = mtCreate();
        mtInsert(m->children[0], val);
      }
    } else { // inserindo diretamente em um vetor
      if (m->nKeys < M) { // checando se o numero de chaves é menor que M, ainda existe espaço
        m->info[i] = val;
        m->nKeys++;
      } else { // vetor está cheio, inserir no ultimo filho
        int i = 0;
        for (i ; m->children[i]; i++);
        mtInsert(m->children[i], val);
      }
    }
  }
}

int height(mTree *m) {
  int retHeight = -1, i = 0, j = 0;
  while (m->children[i] != 0) {
    retHeight = height(m->children[i]) + 1;
  }
  return retHeight;
}
