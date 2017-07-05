#include <iostream>
#include <cstdlib>
#include <assert.h>

using namespace std;

typedef int obj_t;

typedef struct element_st {
  struct tree_st * child;
  struct element_st * next;
} element;

typedef struct tree_st {
  obj_t info;
  struct element_st * offspring;
  struct tree_st * father;
} tree;

int children(tree *a);
int depth(tree *a);
int height(tree *a);
int insert(tree *a, tree *c);
obj_t info(tree *a);
tree * child(tree *a, int  i);
tree * father(tree *a);
void init(tree *a, obj_t info);
void remove(tree *a, int i);

int main(int argc, char const *argv[]) {

  tree * d, * c, * f;
  d = (tree *) malloc(sizeof(tree));
  c = (tree *) malloc(sizeof(tree));
  f = (tree *) malloc(sizeof(tree));
  init(d, 2);
  init(c, 3);
  init(f, 4);
  insert(d,c);
  insert(d, f);
  insert(d, f);
  std::cout << info(child(d, 2)) << '\n';

  return 0;
}
//  Funcs

int depth(tree *a) {
  int p = 0;
  std::cout << a->father << '\n';
  if (a->father != NULL) p = depth(a->father) + 1;
  return p;
}

int children(tree *a) {
  int k = 0;
  element * f = a->offspring; // f se torna os filhos de a
  while (f != NULL) {
    f = f->next;
    k++; // anda até o final da arvore contando os filhos
  }
  return k;
}

int height(tree *a) {
  int sizeOfChildren;
  int maxHeight = 0, h, i;

  sizeOfChildren = children(a);
  for (i = 1 ; i < sizeOfChildren ; i++) {
    h = height(child(a, i));
    if (maxHeight <= h) maxHeight = h + 1;
  }
  return maxHeight;
}

int insert(tree *a, tree *c) {
  int k = 1;
  element * fi = a->offspring; // ponteiro para os filhos da minha arvore pai

  if (fi == NULL) { // checa se minha arvore pai não tem filhos
    a->offspring = (element *) malloc(sizeof(element)); // cria como filho da minha arvore um filho vazio e então
    fi = a->offspring; // atualiza fi
  } else { // caso minha arvore tenha filhos
    while (fi->next != NULL) { // anda até o fim da arvore
      fi = fi->next;
    }
    fi->next = (element *) malloc(sizeof(element)); // cria como filho do ultimo filho da minha arvore um filho vazio e então
    fi = fi->next; // atualiza fi para esse filho
    k++;
  }
  c->father = a; // minha arvore a ser inserida vai ter como pai minha arvore pai
  fi->child = c; // o ultimo filho criado na @line 81 recebe o
  return k; // retorna o indice
}

obj_t info(tree *a) {
  if (a != NULL) {
    return a->info;
  }
  return false;
}

tree * child(tree *a, int  i) {
  int k = 1;
  element *f = a->offspring;
  while (k < i && f != NULL) {
    f = f->next;
    k++;
  }
  return f->child;
}

tree * father(tree *a) {
  return a->father;
}

void init(tree *a, obj_t info) {
  a->info = info;
  a->father = NULL;
  a->offspring = NULL;
}

void remove(tree *a, int i) {
  int k, sizeOfChildren;
  tree *f = NULL;
  element *fi, *before;

  fi = a->offspring;
  if (i == 1) {
    if (fi != NULL) {
      a->offspring = fi->next;
      f = fi->child;
      free(fi);
    }
  } else {
    k = 1;
    while(fi != NULL && k < (i - 1)) fi = fi->next;
    before = fi;
    fi = fi->next;
    if(fi != NULL) {
      before->next = fi->next;
      f = fi->child;
      free(fi);
    }
    else before->next = NULL;
  }
  if(f != NULL) {
    sizeOfChildren = children(f);
    if(sizeOfChildren > 0) {
      for(k = 1; k <= sizeOfChildren; k++)
	     remove(f, 1);
    }
    free(f);
  }
  return;
}
