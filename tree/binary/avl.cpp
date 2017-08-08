#include <iostream>
#include <cstdlib>
#include <assert.h>

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

bool removeByValue(tree *a, obj_t value);
bool isEmpty(tree *a);
void destroy(tree *a);

int factor(tree *a);
bool isBalanced(tree *a);
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
  obj_t element;
  root = aux = NULL;

  std::cin >> N;
  while (N != 0) {
    for (int i = 0; i < N; i++) {
      std::cin >> element;
      if (root == NULL) {
        root = (tree *) malloc(sizeof(tree));
        init(root, element);
      } else {
        aux = (tree *)malloc(sizeof(tree));
        init(aux, element);
        bstInsert(root, aux);
      }
    }
    if (isBalanced(root)) std::cout << "balanced" << '\n';
    else std::cout << "not balanced" << '\n';
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
  if (!isBalanced(a)) balance(a);
}

void balance(tree *a) {
  int f;
  if (!isEmpty(a)) {
    while (!isBalanced(a)) {
      balance(leftChild(a));
      balance(rightChild(a));
      f = factor(a);
      if (f > 1) {
        if (factor(leftChild(a)) < 0) {
          leftRightRotation(a);
        } else {
          rightRotation(a);
        }
      } else if (f < -1) {
        if (factor(rightChild(a)) > 0) {
          rightLeftRotation(a);
        } else {
          leftRotation(a);
        }
      }
    }
  }
}

void leftRightRotation(tree *a) {
  leftRotation(leftChild(a));
  rightRotation(a);
}
void rightLeftRotation(tree *a) {
  rightRotation(rightChild(a));
  rightRotation(a);
}

int factor(tree *a) {
  int lh = height(leftChild(a));
  int rh = height(rightChild(a));
  return lh - rh;
}

bool isBalanced(tree *a) {
  if (a == NULL) return true;
  if ((abs(factor(a)) <= 1) && isBalanced(leftChild(a)) && isBalanced(rightChild(a))) return true;
  return false;
}

void destroy(tree *a) {
  if (a == NULL) return;
  destroy(leftChild(a));
  a->leftChild = NULL;
  destroy(rightChild(a));
  a->rightChild = NULL;
  free(a);
}

void rightRotation(tree *a) {
  tree *p;
  p = (tree *) malloc(sizeof(tree));
  p = leftChild(a);
  leftChild(p);
  insertLeftChild(a, leftChild(p));
  insertRightChild(p, a);
  a = p;
}
void leftRotation(tree *a) {
  tree *p;
  p = (tree *) malloc(sizeof(tree));
  p = rightChild(a);
  leftChild(p);
  insertRightChild(a, leftChild(p));
  insertLeftChild(p, a);
  a = p;
}

bool isEmpty(tree *a) {
  if (a == NULL) return true;
  return false;
}

bool removeByValue(tree *a, obj_t value) {
  tree *lc, *rc, *p;
  if (!isEmpty(a)) {
    if(value == info(a)) {
      lc = leftChild(a);
      rc = rightChild(a);
      p = a;
      if (isEmpty(lc) && isEmpty(rc)) {
        a = NULL;
      }
      else {
        if (isEmpty(lc)) {
          a = lc;
        }
        if (isEmpty(rc)) {
          a = rc;
        }
      }
      if (!isEmpty(lc) && !isEmpty(rc)) {
        while (!isEmpty(leftChild(lc))) lc = leftChild(lc);
        a->info = info(lc);
        p = lc;
        lc = leftChild(lc);
      }
      free(p);
      return true;
    } else {

    }
  }
}

obj_t info(tree *a) {
  if (a != NULL) {
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
  std::cout << a << " pai  filho " << c << '\n';
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
