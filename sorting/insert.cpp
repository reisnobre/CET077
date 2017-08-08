#include <iostream>
using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int *arr, int n);

int main(int argc, char const *argv[]) {
  int i;
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);
  insertionSort(arr, n);
  for (i = 0; i < n - 1; i ++) std::cout << arr[i] << '\n';
  return 0;
}

void insertionSort(int *arr, int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
	  key = arr[i];
	  j = i-1;

  	/* Move elements of arr[0..i-1], that are
  		greater than key, to one position ahead
  		of their current position */
  	while (j >= 0 && arr[j] > key) {
  		arr[j+1] = arr[j];
  		j = j-1;
  	}
  	arr[j+1] = key;
  }
}
