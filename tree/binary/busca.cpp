#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <string>

// Eduardo José dos Reis Nobre && Gabriel Tranquilli

using namespace std;

typedef int obj_t;

typedef struct tree_st {
  obj_t info;
  struct tree_st *leftChild, *rightChild;
  struct tree_st *father;
} tree;

void init(tree *a, obj_t info);
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
void bstInsert(tree *a, tree *c);

void seekAndRemove(tree *a, obj_t value);

bool removeByValue(tree *a, obj_t value);
bool isEmpty(tree *a);
void destroy(tree *a);

int factor(tree *a);
bool isBalanced(tree *a);
bool removeNode(tree *a);
void balance(tree *a);

void rightRotation(tree *a);
void leftRotation(tree *a);

void leftRightRotation(tree *a);
void rightLeftRotation(tree *a);

void preOrder(tree *a);
void posOrder(tree *a);
void order(tree *a);

int main(int argc, char const *argv[]) {
  tree *root, *aux;
  int N;
  char ctrl;
  obj_t value;
  root = aux = NULL;
  string str;

  std::cin >> N;
  while (N != 0) {
    for (int i = 0; i < N; i++) {
      std::cin >> ctrl;
      std::cin >> value;
      cin.ignore();
      if (ctrl == 'I') {
        if (root == NULL) {
          root = (tree *) malloc(sizeof(tree));
          init(root, value);
          preOrder(root);
          std::cout << '\n';
        } else {
          aux = (tree *)malloc(sizeof(tree));
          init(aux, value);
          bstInsert(root, aux);
          preOrder(root);
          std::cout << '\n';
        }
      } else {
        removeByValue(root, value);
        preOrder(root);
        std::cout << '\n';
      }
    }
    destroy(root);
    root = NULL;
    std::cin >> N;
    std::cout << '\n';
  }
  return 0;
}
//  Funcs
void init(tree *a, obj_t info) {
  a->info = info;
  a->father = NULL;
  a->leftChild = NULL;
  a->rightChild = NULL;
}

void bstInsert(tree *a, tree *c) {
  bool bal;
  if (info(c) < info(a)) {
    if(leftChild(a) == NULL) {
      insertLeftChild(a, c);
    } else {
      bstInsert(leftChild(a), c);
    }
  } else {
    if(rightChild(a) == NULL) {
      insertRightChild(a, c);
    } else {
      bstInsert(rightChild(a), c);
    }
  }
}

void destroy(tree *a) {
  if (a == NULL) return;
  destroy(leftChild(a));
  a->leftChild = NULL;
  destroy(rightChild(a));
  a->rightChild = NULL;
  free(a);
}

bool isEmpty(tree *a) {
  if (a == NULL) return true;
  return false;
}

bool removeByValue(tree *a, obj_t value) {
  tree *lc, *rc, *p;
  if (!isEmpty(a)) {
    if(value == info(a)) {
      std::cout << "found " << value << '\n';
      lc = leftChild(a);
      rc = rightChild(a);
      p = a;
      if (isEmpty(lc) && isEmpty(rc)) {
        a = NULL;
      } else {
        if (isEmpty(lc)) {
          a = rc;
        }
        if (isEmpty(rc)) {
          a = lc;
        }
      }
      if (!isEmpty(lc) && !isEmpty(rc)) {
        while (!isEmpty(rightChild(lc))) lc = rightChild(lc);
        a->info = info(lc);
        p = lc;
        lc = leftChild(lc);
      }
      // free(p);
      p = NULL;
      return true;
    } else {
      value > info(a) ? removeByValue(rightChild(a), value) : removeByValue(leftChild(a), value);
    }
  }
  return false;
}

obj_t info(tree *a) {
  if (!isEmpty(a)) {
    return a->info;
  }
  return false;
}

int height(tree *a) {
  int leftHeight, rightHeight;
  if (a == NULL) {
    return 0;
  } else {
    leftHeight = height(leftChild(a)) + 1;
    rightHeight = height(rightChild(a)) + 1;
    if (leftHeight > rightHeight) {
      return leftHeight;
    } else {
      return rightHeight;
    }
  }
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

void preOrder(tree *a) {
  if (!isEmpty(a)) {
    std::cout << info(a) << ' ';
    preOrder(leftChild(a));
    preOrder(rightChild(a));
  }
}

void posOrder(tree *a){
  if (!isEmpty(a)) {
    posOrder(leftChild(a));
    posOrder(rightChild(a));
    std::cout << info(a) << '\n';
  }
}

void order(tree *a){
  if (!isEmpty(a)) {
    order(leftChild(a));
    std::cout << info(a) << '\n';
    order(rightChild(a));
  }
}
