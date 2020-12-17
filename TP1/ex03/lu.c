#include <stdlib.h>
#include <stdio.h>
#define N 10

float *lu(float A[N][N], float B[N], int n)
{

  float  *X , L[N][N] , Y[N] ;
  X = (float *)malloc(sizeof(float));
  /*Gauss elimination on A to get L and U*/
  for(int k = 0 ; k < n-1 ; k++)
  {
    for(int i = k+1 ; i < n ; i++) 
    {
      L[i][k] = A[i][k] / A[k][k];
      for(int j = k + 1; j < n; j++)
      {
        A[i][j] = A[i][j]- L[i][k] * A[k][j];
      }
    }
  }
  /*calculating Y with LY=B (forward substitution)*/
  Y[0] = B[0];
  for(int i = 1 ; i < n ; i++)
  {
    int s = 0;
    for(int j = 0 ; j < i ; j++)
    {
      s= s + L[i][j] * Y[j];
    }
    Y[i] = B[i] - s;
  }
  /*calculating X with UX=Y (back substitution)*/
  X[n-1] = Y[n-1] / A[n-1][n-1];
  for(int i = n-2 ; i >= 0 ; i--)
  {
    float s = 0;
    for(int j = i + 1 ; j <= n-1 ; j++)
      s += A[i][j] * X[j];
    X[i] = (Y[i] - s)/A[i][i];
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
  X = lu(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", X[i], ",]"[i == n - 1]);
}

