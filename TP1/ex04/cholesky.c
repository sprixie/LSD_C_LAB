#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10

float cholesky(float C[N][N], float A[N][N],int n)
{	
	for(int j = 0; j < n; j++){
		for(int i = j; i < n; i++){
			if(i == j)
      {
				float sum1 = 0;
				for(int k = 0; k < j; k++){
					sum1 += C[i][k]*C[i][k];
			  }
				C[i][j] = sqrt(A[i][j]-sum1);
			}
			else
      {
				float sum2 = 0;
				for(int k=0; k < j; k++){
					sum2 += C[i][k]*C[j][k];
				}
				C[i][j]=(A[i][j]-sum2)/C[j][j];
			}
		}
	}
	return C[N][N];
}

int main()
{
  int n;
	float A[N][N], B[N], Y[N], X[N], C[N][N];
	printf("enter the dimension of the matrix ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n ; j++){
			printf("A[%d][%d]= ", i, j);
			scanf("%f", &A[i][j]);
			}

	for(int i=0; i < n; i++){
		printf("B[%d]=", i);
		scanf("%f", &B[i]);
		}


	//Here we are implementing the C matrix
	for(int i = 0; i < n; i++)
  {
		for(int j = 0; j < n; j++){
			C[i][j]=0;
		}
	}
	
	
	
	//Le3ts find the resulting cholesky matrix
	C[N][N]=cholesky(C, A, n);
  
	//printing  C
	printf("Here is the C matrix \n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
    {
		printf("C[%d][%d] = %f\t",i, j, C[i][j]);
		}
		printf("\n");
	}
	
	//solving C(Transpose)*Y=B
	Y[0] = B[0] / C[0][0];
	for(int i = 1; i < n; i++){
		float sum1=0;
		for(int j=0; j <= i-1; j++){
			sum1 += C[i][j] * Y[j];
		}
		Y[i]=(B[i]-sum1)/C[i][i];
	}
	//printing Y
	for(int i = 0; i < n ; i++)
  {
		printf("Y[%d]=%f\t",i, Y[i]);
	}
	
	//solving c*x=y
	X[n-1] = Y[n-1]/C[n-1][n-1];

	for(int i = n-2; i >= 0; i--){
		float sum2=0;
		for(int j = i+1; j < n; j++){
			sum2 += C[j][i] * X[j];
	  }
		X[i] = (Y[i]-sum2)/C[i][i];
	}
  
	//printing X
	printf("\n the final solution is :\n");
	for(int i=0; i < n; i++)
		printf("X[%d]=%f\t",i, X[i]);
  return (0);
}

