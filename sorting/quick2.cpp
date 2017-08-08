#include <iostream>
#include <cstdlib>
using namespace std;

typedef int obj_t;

// Eduardo Reis Nobre && Ueslei Sales && Gabriel Traquilli

void swap(obj_t *a, obj_t *b);
int partition(obj_t arr[], int low, int high);
void quickSort(obj_t arr[], int low, int high);

int main(int argc, char const *argv[]) {
  int N, i, num;
  while (std::cin >> N) {
    int arr[N];
    for (i = 0; i < N; i++) {
      std::cin >> num;
      arr[i] = num;
    }
    quickSort(arr, 0, N - 1);
    std::cout << '\n';
  }
  return 0;
}

void swap(obj_t *a, obj_t *b) {
  obj_t temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

// int partition (obj_t arr[], int p, int r) {
//   int x = arr[r];
//   std::cout << x << ' ';
//   int i = (p - 1);
//
//   for (int j = p ; j <= (r - 1); j++) {
//     if (arr[j] <= x) {
//       i++;
//       swap(&arr[i], &arr[j]);
//     }
//   }
//   swap(&arr[i + 1], &arr[r]);
//   return (i + 1);
// }

void quickSort(obj_t arr[], int p, int r) {
  if (p < r) {
    int i = p;
    int j = r;
    int pivo = arr[(p + r) / 2];
    std::cout << pivo << ' ';
    while(i <= j) {
      while (arr[i] < pivo) i++;
      while (arr[j] > pivo) j--;
      if (i <= j) {
        swap(&arr[i], &arr[j]);
        i++;
        j--;
      }
    }
    quickSort(arr, p, j);
    quickSort(arr, i, r);
  }
}
