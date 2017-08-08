#include <iostream>
using namespace std;

// Driver program
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int main(int argc, char const *argv[]) {
  int i;
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);
  heapSort(arr, n);
  for (i = 0; i < n - 1; i ++) std::cout << arr[i] << '\n';
  return 0;
}


void heapify(int arr[], int n, int i) {
	int largest = i;
  int l = (2 * i) + 1;  // left = 2*i + 1
  int r = (2 * i) + 2;  // right = 2*i + 2

  // If left child is larger than root
  if (l < n && arr[l] > arr[largest]) largest = l;
  if (r < n && arr[r] > arr[largest]) largest = r;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
	// Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
  for (int i = n-1; i >= 0; i--) {
    // Move current root to end
    swap(arr[0], arr[i]);
    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}
