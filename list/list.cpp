#include <iostream>
#include <cstdlib>

using namespace std;

typedef int obj_t;

typedef struct number_st {
  obj_t num;
  struct number_st *next, *before;
} number;

void addItem (number **list, obj_t x);
void insertSort (number **list, obj_t x);
obj_t last (number p) {
  return p.num;
}
int main(int argc, char const *argv[]) {
  number *list, *p;
  list = (number *) malloc(sizeof(number));
  p = list;
  addItem(&p, 8);
  // addItem(&p, 7);
  insertSort(&p, 9);
  p = list;
  p = p->next;
  // while (p != 0) {
  //   std::cout << p->num << '\n';
  //   p = p->next;
  // }
  return 0;
}

void insertSort (number **list, obj_t x) {
  obj_t a = last(**list);
  std::cout << a << '\n';
}

void addItem (number **p, int x) {
  (*p)->next = (number *) malloc(sizeof(number));
  (*p) = (*p)->next;
  (*p)->num = x;
  (*p)->next = 0;
}
