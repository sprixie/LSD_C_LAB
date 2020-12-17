#include <stdio.h>
#include <stdlib.h>
#define N 10

float *remontee(float A[N][N], float B[N], int n)
{
  float *X; 
  float s;
  X =(float*)malloc(n*sizeof(float));
  X[n - 1] = B[n - 1]/A[n - 1][n - 1];
  for(int i = n-2 ; i >= 0 ;i--)
  {
    s = 0;
    for(int j = i + 1; j <= n - 1 ; j++)
      s += A[i][j] * X[j];
    X[i] = (B[i] - s) / A[i][i];
  }                                                                                                                                                                                                             20   return X; 
  return X;
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
  printf("Filling the vector B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  X = remontee(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", X[i], ",]"[i == n - 1]);
}

