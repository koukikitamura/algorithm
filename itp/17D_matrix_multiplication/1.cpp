#include <cstdio>
#define MATRIX_SIZE_MAX 100
using Matrix = int[MATRIX_SIZE_MAX][MATRIX_SIZE_MAX];

long long  product_elem(Matrix A, Matrix B, int m, int i, int j) {
  long long sum = 0;

  for(int k = 0; k < m; k++) {
    sum += A[i][k] * B[k][j];
  }

  return sum;
}


int main() {
  int n, m, l;
  Matrix A, B;

  scanf("%d %d %d%*c", &n, &m, &l);


  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < l; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < l; j++) {
      long long elem = product_elem(A, B, m, i, j);

      printf("%lld", elem);

      if(j != l - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
}
