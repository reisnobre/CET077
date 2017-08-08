#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>

using namespace std;

typedef int obj_t;

typedef struct tree_st {
  obj_t info;
  struct tree_st *leftChild, *rightChild;
  struct tree_st *father;
} tree;

void init(tree *a, obj_t info);

void binarySeachTree(tree *a, tree *c);

obj_t info(tree *a);
int height(tree *a);
int depth(tree *a);
tree *father(tree *a);
tree *leftChild(tree *a);
tree *rightChild(tree *a);
void insertRightChild(tree *a, tree *c);
void insertLeftChild(tree *a, tree *c);
void removeRightChild(tree *a);
void removeLeftChild(tree *a);

void preOrder(tree *a);
void posOrder(tree *a);
void order(tree *a);

int main(int argc, char const *argv[]) {
  string str;
  int N;
  obj_t element;
  tree *father, *aux;

  father = aux = NULL;

  std::cin >> N;
  while(N > 0){
    for (int i = 0; i < N; i++) {
      std::cin >> element;
      if (father == NULL) {
        father = (tree *)malloc(sizeof(tree));
        init(father, element);
      } else {
        aux = (tree *)malloc(sizeof(tree));
        init(aux, element);
        if (leftChild(father) == NULL && rightChild(father) == NULL) {
          insertLeftChild(father, aux);
        }
        // leftChild(father) == NULL ? insertLeftChild(father, aux) : insertRightChild(father, aux);
      }
    }
    N--;
    // if (N == 0) // limpar o pai para começar uma nova arvore
    std::cin >> N;
  }
  preOrder(father);
  posOrder(father);
  return 0;
}
//  Funcs
void init(tree *a, obj_t info) {
  a->info = info;
  a->father = NULL;
  a->leftChild = NULL;
  a->rightChild = NULL;
}



obj_t info(tree *a) {
  if (a != NULL) {
    return a->info;
  }
  return false;
}

void binarySeachTree(tree *a, tree *c) {
}

int height(tree *a) {
  int retHeight = -1, leftHeight, rightHeight;
  if (a != NULL) {
    leftHeight = height(leftChild(a)) + 1;
    rightHeight = height(rightChild(a)) + 1;
    retHeight = (leftHeight < rightHeight) ? leftHeight : rightHeight;
  }
  return retHeight;
}

int depth(tree *a) {
  int d = 0;
  assert(a != NULL);
  if (a->father != NULL) d = depth(a->father) + 1;
  return d;
}

tree *father(tree *a) {
  return a->father;
}

tree *leftChild(tree *a){
  tree *child = NULL;
  if (a != NULL) {
    child = a->leftChild;
  }
  return child;
}

tree *rightChild(tree *a){
  tree *child = NULL;
  if (a != NULL) {
    child = a->rightChild;
  }
  return child;
}

void insertLeftChild(tree *a, tree *c){
  assert(a != NULL && c != NULL);
  c->father = a;
  a->leftChild = c;
}

void insertRightChild(tree *a, tree *c){
  assert(a != NULL && c != NULL);
  c->father = a;
  a->rightChild = c;
}

void removeLeftChild(tree *a){
  tree *child = NULL;
  if (a != NULL) {
    child = a->leftChild;
    a->leftChild = NULL;
    if (child != NULL){
      removeLeftChild(child);
      removeRightChild(child);
    }
    free(child);
  }
  return;
}

void removeRightChild(tree *a){
  tree *child = NULL;
  if (a != NULL) {
    child = a->rightChild;
    a->rightChild = NULL;
    if (child != NULL){
      removeLeftChild(child);
      removeRightChild(child);
    }
    free(child);
  }
  return;
}

void preOrder(tree *a){
  if (a != NULL) {
    std::cout << info(a) << '\n';
    preOrder(leftChild(a));
    preOrder(rightChild(a));
  }
}

void posOrder(tree *a){
  if (a != NULL) {
    posOrder(leftChild(a));
    posOrder(rightChild(a));
    std::cout << info(a) << '\n';
  }
}

void order(tree *a){
  if (a != NULL) {
    order(leftChild(a));
    std::cout << info(a) << '\n';
    order(rightChild(a));
  }
}
