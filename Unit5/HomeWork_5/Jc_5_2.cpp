#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 20
#define M 5
#define N 5
#define DataType int
typedef struct {
  int i, j;    //非零元素的行列号
  DataType v;  //非零元素的值
} triple;
typedef struct {
  triple data[MaxSize];  //非零元素的三元组表
  int m, n, t;           //行 列 非零元素个数
} tripletable;           //三元组表
//稀疏矩阵向三元组转换
tripletable ConVert(int A[M][N]) {
  int i, j, total = 0;
  tripletable B;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      if (A[i][j] != 0) {
        B.data[total].i = i;
        B.data[total].j = j;
        B.data[total].v = A[i][j];
        total++;
      }
    }
  }
  B.m = M;
  B.n = N;
  B.t = total;
  return B;
}

int main(int argc, char** argv) {
  int A[5][5] = {{0, 2, 0, 0, 0},
                 {0, 6, 0, 0, 0},
                 {0, 0, 1, 2, 0},
                 {0, 6, 0, 0, 5},
                 {0, 0, 0, 0, 1}
  };
  tripletable B;
  B = ConVert(A);
  system("pause");
  return 0;
}
