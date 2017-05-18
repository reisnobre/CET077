#include <iostream>
#include <cstdlib>

using namespace std;
typedef struct number_st{
  int num;
  struct number_st *next;
} number;

void enqueueFront (number *tail, number *head,  int x);
int main(int argc, char const *argv[]) {
  int i, j, k, N, value;
  char ctrl;
  i = j = k = 0;
  number *head, *tail, *p, *temp;
  head = tail = p = 0;
  std::cin >> N;
  while (N != 0) {
    for (i = 0; i < N ; i++) {
      std::cin >> ctrl >> value;
      temp = (number *) malloc(sizeof(number));
      temp->next = 0;
      temp->num = value;
      if (head == 0 && tail == 0) {
        head = tail = temp;
      } else {
        if (ctrl == 'P') {
          temp->next = head;
          head = temp;
        } else {
          tail->next = temp;
          tail = temp;
        }
      }
    }
    std::cin >> N;
  }
  p = head;
  if (p) {
    std::cout << p->num;
    p = p->next;
  }
  while (p != 0) {
    std::cout << ' ' << p->num;
    p = p->next;
  }
  std::cout << '\n';
  return 0;
}

void enqueueFront (number *tail, number *head,  int x) {
  number *temp = (number *) malloc(sizeof(number));
  temp->num = x;
  temp->next = 0;
  if (head == 0 && tail == 0) {
    std::cout << "empty" << '\n';
    head = tail = temp;
    return;
  }
  tail->next = temp;
  tail = temp;
}
