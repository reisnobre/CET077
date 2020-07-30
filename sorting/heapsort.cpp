#include <iostream>
using namespace std;

// Driver program
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void buildMaxHeap(int *arr, int n);
void swap(int *a, int *b);

int main(int argc, char const *argv[]) {
  int N, i, num;
  while (std::cin >> N) {
    int arr[N];
    for (i = 0; i < N; i++) {
      std::cin >> num;
      arr[i] = num;
    }
    heapSort(arr, N);
    std::cout << '\n';
  }
  return 0;
}

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) {
	int largest = i;
  int l = (2 * i);  // left = 2*i + 1
  int r = (2 * i) + 1;  // right = 2*i + 2

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest]) largest = l;
  if (r < n && arr[r] > arr[largest]) largest = r;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void buildMaxHeap(int *arr, int n) {
  int i;
  for (i = (n/2); i != 1; i--) {
    heapify(arr, n, i);
  }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
	// Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
  for (int i = n-1; i >= 0; i--) {
    // Move current root to end
    std::cout << arr[0] << ' ' << arr[i];
    swap(arr[0], arr[i]);
    heapify(arr, i - 1, 1);
  }
}
