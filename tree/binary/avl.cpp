#include <iostream>
#include <cstdlib>
#include <assert.h>

using namespace std;

typedef int obj_t;

typedef struct tree_st {
  obj_t val;
  int height;
  struct tree_st *leftChild, *rightChild;
  struct tree_st *father;
} tree;

// core
tree  *newTree (obj_t val);
tree *bstInsert(tree *t, obj_t val);
void insertRightChild(tree *f, tree *c);
void insertLeftChild(tree *f, tree *c);
void removeRightChild(tree *f);
void removeLeftChild(tree *f);
void destroy(tree *a);

// balancing
tree *rightRotation(tree *y);
tree *leftRotation(tree *x);
void leftRightRotation(tree *a);
void rightLeftRotation(tree *a);
// misc

int max(int a, int b);
int getFactor(tree *t);
void preOrder(tree *t);
int height(tree *t);

int main(int argc, char const *argv[]) {
  tree *root, *aux;
  int N;
  obj_t element;
  root = aux = NULL;
  /* Constructing tree given in the above figure */
  root = bstInsert(root, 15);
  root = bstInsert(root, 10);
  root = bstInsert(root, 7);
  root = bstInsert(root, 22);
  root = bstInsert(root, 13);
  root = bstInsert(root, 11);
  root = bstInsert(root, 12);
  root = bstInsert(root, 25);

  /* The constructed AVL Tree would be
  			30
  		/ \
  		20 40
  		/ \	 \
  	10 25 50
  */
  preOrder(root);
  std::cout << '\n';
  return 0;
}

tree  *newTree (obj_t val) {
  tree *t;
  t = (tree *) malloc(sizeof(tree));
  t->val = val;
  t->father = t->leftChild = t->rightChild = NULL;
  t->height = 1;
  return t;
}

void insertRightChild(tree *f, tree *c) {

}
void insertLeftChild(tree *f, tree *c) {

}
void removeRightChild(tree *f) {

}
void removeLeftChild(tree *f) {

}

tree *bstInsert(tree *t, obj_t val) {
  /* 1. Perform the normal BST insertion */
  if (t == NULL) return(newTree(val));
  if (val < t->val) t->leftChild = bstInsert(t->leftChild, val);
  else if (val > t->val) t->rightChild = bstInsert(t->rightChild, val);
  else return t; // Equal keys are not allowed in BST


  /* 2. Update height of this ancestor node */
  t->height = 1 + max(height(t->leftChild), height(t->rightChild));

  /* 3. Get the balance factor of this ancestor
    node to check whether this node became
    unbalanced */
  int factor = getFactor(t);
  // If this node becomes unbalanced, then
  // there are 4 cases


  // Pure rotations
  // Left Left Case
  if (factor > 1 && val < t->leftChild->val) {
    std::cout << "Rotação a direita" << val << '\n';
    return rightRotation(t);
  }

  // Right Right Case
  if (factor < -1 && val > t->rightChild->val) {
    std::cout << "Rotação a esquerda" << val << '\n';
    return leftRotation(t);
  }

  // Mixed rotations

  // Left Right Case
  if (factor > 1 && val > t->leftChild->val) {
    std::cout << "Rotação Esquerda Direta" << val << '\n';
    t->leftChild = leftRotation(t->leftChild);
    return rightRotation(t);
  }

  // Right Left Case
  if (factor < -1 && val < t->rightChild->val) {
    std::cout << "Rotação Direta Esquerda" << t->rightChild->val << '\n';
    t->rightChild = rightRotation(t->rightChild);
    return leftRotation(t);
  }

  /* return the (unchanged) node pointer */
  return t;
}
void destroy(tree *a) {

}

// balancing

tree *rightRotation(tree *y) {
	tree *x = y->leftChild;
	tree *T2 = x->rightChild;

	// Perform rotation
	x->rightChild = y;
	y->leftChild = T2;

	// Update heights
	y->height = max(height(y->leftChild), height(y->rightChild))+1;
	x->height = max(height(x->leftChild), height(x->rightChild))+1;

	// Return new root
	return x;
}

tree *leftRotation(tree *x) {
  tree *y = x->rightChild;
	tree *T2 = y->leftChild;

	// Perform rotation
	y->leftChild = x;
	x->rightChild = T2;

	// Update heights
	x->height = max(height(x->leftChild), height(x->rightChild))+1;
	y->height = max(height(y->leftChild), height(y->rightChild))+1;

	// Return new root
	return y;
}

// misc
int max(int a, int b) {
  return (a > b) ? a : b;
}

int getFactor(tree *t) {
  if (t == NULL)
		return 0;
	return height(t->leftChild) - height(t->rightChild);
}

void preOrder(tree *t) {
	if(t != NULL) {
    std::cout << t->val << ' ';
		preOrder(t->leftChild);
		preOrder(t->rightChild);
	}
}

int height(tree *t) {
	if (t == NULL)
		return 0;
	return t->height;
}
