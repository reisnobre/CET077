#include <iostream>
using namespace std;

/* function to sort arr using shellSort */
int shellSort(int *arr, int n);


int main(int argc, char const *argv[]) {
  int i;
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr)/sizeof(arr[0]);
  shellSort(arr, n);
  for (i = 0; i < n - 1; i ++) std::cout << arr[i] << '\n';
  return 0;
}

int shellSort(int *arr, int n) {
  int gap;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i += 1) {
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
	return 0;
}
