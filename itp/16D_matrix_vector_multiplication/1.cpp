#include <cstdio>
#define MAX_N 100
#define MAX_M 100

int main() {
  int A[MAX_N][MAX_M], b[MAX_M], product[MAX_M];
  int n_size, m_size;

  scanf("%d %d%*c", &n_size, &m_size);

  for(int i = 0; i < n_size; i++) {
    for(int j = 0; j < m_size; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  for(int i = 0; i < m_size; i++) {
    scanf("%d%*c",&b[i]);
  }

  for(int i = 0; i < n_size; i++) {
    int product_elem = 0;

    for(int j = 0; j < m_size; j++) {
      product_elem += A[i][j] * b[j];
    }

    // 変数に入れずにそのまま出力しても良い。
    product[i] = product_elem;
  }

  for(int i = 0; i < n_size; i++) {
    printf("%d\n", product[i]);
  }
}
