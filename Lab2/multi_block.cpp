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

void multiplyBlock(int A[][MAX], int B[][MAX], int rowA, int colA, int colB) {
  for (int i = 0; i < MIN; ++i) {
    for (int j = 0; j < MIN; ++j) {
      for (int k = 0; k < MIN; ++k) {
        C[rowA + i][colB + j] += A[rowA + i][colA + k] * B[colA + k][colB + j];
      }
    }
  }
}

void multiplyMatrix(int A[][MAX], int B[][MAX]) {
  for (int i = 0; i < MAX; i += MIN) {
    for (int j = 0; j < MAX; j += MIN) {
      for (int k = 0; k < MAX; k += MIN) {
        for (int x = 0; x < min(i + MIN, MAX); ++x) {
          for (int y = 0; y < min(j + MIN, MAX); ++y) {
            for (int z = 0; z < min(k + MIN, MAX); ++z) {
              C[x][y] += A[x][z] * B[z][y];
            }
          }
        }
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
  multiplyMatrix(A, B);
}
