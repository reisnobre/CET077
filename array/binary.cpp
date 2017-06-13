int binary(int arr[], int x);

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

int binary(int *arr, int x) {
  int pos = -1;
  int ini = 1;
  int fim = sizeof(arr) / sizeof(*arr);
  int meio;
  while (ini < fim && pos == -1) {
    meio = (ini + fim) / 2;
    if(arr[meio] == x) pos = meio;
    else if (arr[meio] > x) {
      fim = meio - 1;
    } else {
      ini = meio + 1;
    }
  }
  return pos;
}
