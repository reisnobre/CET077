#include <iostream>
#include <cstdlib>

using namespace std;
typedef struct number_st {
  int num;
  struct number_st *next;
} number;

typedef struct queue_st {
	head
} queue;

void enqueueFront (number **tail, number **head,  int x);
void enqueueBack (number **tail, number **head,  int x);
int main(int argc, char const *argv[]) {
  int i, j, k, N, value;
  char ctrl;
  i = j = k = 0;
  number *head, *tail, *p;
  head = tail = p = 0;
  std::cin >> N;
  while (N != 0) {
    for (i = 0; i < N ; i++) {
      std::cin >> ctrl >> value;
      if (ctrl == 'P') {
        enqueueFront(head, tail, value);
      } else {
        enqueueBack(head, tail, value);
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

void enqueueFront (number **tail, number **head,  int x) {
  number temp = (number *) malloc(sizeof(number));
  temp->next = 0;
  temp->num = value;
  if ((*head) == 0 && (*tail) == 0) {
    (*head) = (*tail) = temp;
  } else {
    temp->next = (*head);
    (*head) = temp;
  }
}
void enqueueBack (number **tail, number **head,  int x) {
  number temp = (number *) malloc(sizeof(number));
  temp->next = 0;
  temp->num = value;
  if ((*head) == 0 && (*tail) == 0) {
    (*head) = (*tail) = temp;
  } else {
    (*tail)->next = temp;
    (*tail) = temp;
  }
}
