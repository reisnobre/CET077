#include <iostream>
#include <cstdlib>
using namespace std;

typedef int obj_t;

void swap(obj_t *a, obj_t *b);
int partition(obj_t arr[], int low, int high);
void quickSort(obj_t arr[], int low, int high);

int main(int argc, char const *argv[]) {
  int i;
  int arr[] = {10, 7, 8, 9, 1, 5};
  int size = sizeof(arr)/sizeof(arr[0]);
  quickSort(arr, 0, size - 1);
  for (i = 0; i < size - 1; i ++) std::cout << arr[i] << '\n';
  return 0;
}

void swap(obj_t *a, obj_t *b) {
  (*a) ^= (*b);
  (*b) ^= (*a);
  (*a) ^= (*b);
}

int partition (obj_t arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low ; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(obj_t arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
