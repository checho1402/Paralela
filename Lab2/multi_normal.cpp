#include <iostream>
#define MAX 9
#define MIN 3
int C[MAX][MAX];
using namespace std;

void rellenar(int A[][MAX], int contador) {
  for (int(*p)[MAX] = A; p < A + MAX; p++) {
    for (int *q = *p; q < *(p + 1); q++) {
      *q = contador;
      contador++;
    }
  }
}
void print(int A[][MAX]) {
  for (int(*p)[MAX] = A; p < A + MAX; p++) {
    for (int *q = *p; q < *(p + 1); q++) {
      cout << *q << "\t";
    }
    cout << endl;
  }
}
void inicial() {
  for (int(*p)[MAX] = C; p < C + MAX; p++) {
    for (int *q = *p; q < *(p + 1); q++) {
      *q = 0;
    }
  }
}
void multiplicacion(int A[][MAX], int B[][MAX]) {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      for (int k = 0; k < MAX; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  print(C);
}


int main() {
  int A[MAX][MAX];
  rellenar(A, 1);
  int B[MAX][MAX];
  rellenar(B, 1);
  inicial();
  multiplicacion(A, B);

}
