#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define E 2.71828182845904523536
double f(double x);

double rectangledroite(double (*f)(double),double a, double b, double n)
{
        float h = (b-a)/n;
        double s = 0;
        double x;
        for (int i = 0; i<n ; i++)
        {
                x = a+i*h;
                s += f(x);
        }
        return s*h;
}

double rectanglegauche(double (*f)(double), double a, double b, int n)
{
        float h = (b-a)/n;
        double s = 0;
        double x;
        for (int i = 1; i<n+1; i++)
        {
                x = a+i*h;
                s += f(x);
        }
        return s*h;
}

double trapeze(double (*f)(double), double a , double b, int n)
{
        float I = (0,5) * (f(a) + f(b));
        float h = (b-a)/n;
        double s = 0;
        double x;
        for (int i = 0; i<n-1; i++)
        {
                x = x+h;
                I += f(x);
        }
        return h*I;
}

double simpson(double (*f)(double), double a,double b, int n)
{
	float h = (b - a)/n;
	double x = a + h;
	double z = a + h / 2;
	double I1 = 0;
	double I2 = f(z);
	for(int i=0; i<n-1 ;i++)
	{
		z+=h;
		I1+=f(x);
		I2+=f(z);
		x+=h;
	}
	return (h/6)*(f(a)+f(b)+2*I1+4*I2);
}
unsigned nombre_necessaire(double(*f)(double),double a,double b,double Err,double (*methode)(double(*)(double),double,double,int),double I)
{
	int n=1;
	while((methode(exp,a,b,n)-I)>Err || (methode(exp,a,b,n)-I) < -Err )
	{
        	n+=1;
	}
    	return(n);
}
int main()
{
	double s;
	double a=0;
	double b=1;
	int n=100;
	s = simpson(f,a,b,n);
	printf("le resultat est : %f\n",s);
	printf("le nombre necessaire estt: %u\n",nombre_necessaire(exp,a,b,0.0000001,simpson,E-1));
	return 0;
}

double f(double x)
{
	return x;
}
