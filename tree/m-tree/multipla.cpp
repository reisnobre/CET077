#include <iostream>
#include <cstdlib>
#include <assert.h>

#define M 6
using namespace std;

// Eduardo Reis Nobre && Ueslei Sales

typedef int obj_t;

typedef struct mTree_st {
  bool isLeaf;
  int nKeys;
  int max;
  obj_t info[M - 1];
  struct mTree_st *children[M];
} mTree;

mTree *mtCreate(int limit);

void mtInsert(mTree *m, obj_t val);

int height(mTree *m);

int main(int argc, char const *argv[]) {
  mTree *m;
  int N, P, val;
  while (std::cin >> N) {
    m = mtCreate(N);
    std::cin >> P;
    for (int i = 0; i < P; i++) {
      std::cin >> val;
      mtInsert(m, val);
      // std::cout << height(m) << '\n';
    }
  }
  return 0;
}

mTree *mtCreate(int limit) {
  mTree *m;
  m = (mTree *)malloc(sizeof(mTree));
  assert(m);

  m->isLeaf = true;
  m->nKeys = 0;
  m->max = limit;
  for (int i = 0; i < (limit - 1); i++) m->info[i] = -1;
  return m;
}

void mtInsert(mTree *m, obj_t val) {
  if (m->nKeys == 0) {
    m->info[m->nKeys++] = val;
    std::cout << "inserindo " << val << '\n';
  } else {
    int i = 0, k = 0;
    for (k ; k < m->max - 1; k++) {
      if (val > m->info[i]) i++;
    }
    std::cout << i << '\n';
    if (i == 0) { // Menor valor do vetor
      m->isLeaf = false;
      if (m->children[i]) { // já possui filho, fazer recursivo
        mtInsert(m->children[i], val);
        std::cout << "inserindo no filho existente de " << val << " como filho de " << m->info[i] << '\n';
      } else { // não possui filho
        std::cout << "inserindo criando filho e inserindo " << val << " como filho de " << m->info[i] << '\n';
        m->children[i] = mtCreate(m->max);
        mtInsert(m->children[i], val);
      }
    } else { // inserindo diretamente em um vetor
      if (m->nKeys < m->max) { // checando se o numero de chaves é menor que M, ainda existe espaço
        std::cout << "inserindo no vetor " << val << " ao lado de " << m->info[i - 2] << '\n';
        m->info[i - 1] = val;
        m->nKeys++;
      } else { // vetor está cheio, inserir no ultimo filho
        std::cout << "vetor cheio, inserindo " << val << " como filho de " << m->info[i - 1] << '\n';
        mtInsert(m->children[i - 1], val);
      }
    }
  }
}

int height(mTree *m) {
  int max = -1, i = 0, j = 0;
  while (m->children[i] != 0) {
    max = height(m->children[i]) > max ? height(m->children[i]) : max;
    i++;
  }
  return max + 1;
}
