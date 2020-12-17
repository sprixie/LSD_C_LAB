#include <stdio.h>
#include <stdlib.h>
#define N 10


float *descente(float A[N][N], float B[N], int n)
{
  float   *X;
  float s;
  X = malloc(sizeof(float) * n);
  X[0] = B[0]/A[0][0];
  for (i = 1;i < n; i++)
  {
    s = 0;
    for (j=0;j<i;j++)
      s += A[i][j] * X[j];
    X[i] = (B[i] - s)/A[i][i];
  }
  return (X);
}


int main()
{
  float   A[N][N], B[N];
  float   *X;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  X = descente(A, B, n);
  
  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", X[i], ",]"[i == n - 1]);
}
