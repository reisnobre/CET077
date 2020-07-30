#include<iostream>
using namespace std;

// Eduardo Reis Nobre && Ueslei Sales

int getMax(int *arr, int n);
void countSort(int *arr, int n, int exp);
void radixsort(int *arr, int n, int m);
void print(int arr[], int n);

int main(int argc, char const *argv[]) {
  int N, i, num, sizeB;
  while (std::cin >> sizeB) {
		std::cin >> N;
    int arr[N];
    for (i = 0; i < N; i++) {
      std::cin >> num;
      arr[i] = num;
    }
		// print(arr, N);
    radixsort(arr, N, sizeB);
    std::cout << '\n';
  }
  return 0;
}

void radixsort(int *arr, int n, int m) {
  unsigned int b = 1;
  int i, j, skip, passes = 0;
  int out[n];
  for (i = 0; i < m; i++) { // fazendo m passadas de bit
    for (j = 0; j < n; j++) { // percorrendo o vetor
      if ((arr[j] & b) == 0) { // se a combinação dos bits do numero e a mascara atual for igual a zero
        out[passes++] = arr[j]; // colocar no começo do vetor
      }
    }
    for (j = 0; j < n; j++) { // percorrendo o vetor novamente pegando os outros casos
      if ((arr[j] & b) != 0) { // se a combinação dos bits do numero e a mascara atual for diferente de zero
        out[passes++] = arr[j]; // nas ultimas posições
      }
    }
    for (j = 0; j < n; j++) arr[j] = out[j]; // copiando o vetor
    passes = 0;
    b = b << 1;
    for (int i = 0; i < n; i++) std::cout << out[i] << ' ';
    std::cout << '\n';
  }

	// for (int exp = 1; m/exp > 0; exp *= 10) {
	// 	countSort(arr, n, exp);
	// 	for (int i = 0; i < n; i++) std::cout << arr[i] << ' ';
	// }
}
