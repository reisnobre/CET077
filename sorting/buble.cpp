#include <iostream>
#include <cstdlib>
using namespace std;

typedef int obj_t;

void bubleSort(obj_t *arr, int size);
void swap(obj_t *a, obj_t *b);

int main(int argc, char const *argv[]) {
  int i;
  int list_1[]={64, 34, 25, 12, 22, 11, 90};
  int size = sizeof(list_1)/sizeof(list_1[0]);
  bubleSort(list_1, size);
  for (i = 0; i < size - 1; i ++) std::cout << list_1[i] << '\n';
  return 0;
}

void swap(obj_t *a, obj_t *b) {
  (*a) ^= (*b);
  (*b) ^= (*a);
  (*a) ^= (*b);
}

void bubleSort(obj_t *arr, int size) {
  int i, j;
  int lenght;

  for(i = 0; i < size - 1; i++) {
    for (j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
    }
  }
}
