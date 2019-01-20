/*
** main.c:
**
** The test program for the homework.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.14
** 
*/


#include <stdio.h>


#include "hw4_lib.h"
#include "hw4_io.h"



/*
** Testing derivative calculations..
**
*/
int derivatives(double f(double a), double x, double eps, double * d1, double * d2);
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2);
double integral(double f(double x), double xs, double xe, double delta);
double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta);
/* These are my test functions > */
/* Test function for integral */
void test_integral()
{
	double f(double x){return x*x;}
	double res;
	res=integral(f,1,2, 0.0001);
	printf("%lf", res);
}
/*Test function for integral2 */
void test_integral2()
{
	double f(double x, double y){return (x*x)*y;}
	double res;
	res=integral2(f,1,2,1,2,0.001);
	printf("%lf", res);
}
/* Test function for compare derivatives */
void test_compare_derivatives() {
	double f(double x) { return x*x; }
	double d1(double x) { return 2.0*x; }
	double d2(double x) { return 2.0; }
	double e1, e2;
	int res = compare_derivatives(f, d1, d2, 1.0, 0.0001, &e1, &e2);
	printf("e1= %.15f  e2= %.15f\n",e1,e2);
}

/*
** main function for testing the functions...
**
*/
int main(void) {
	double a0,a1,a2,a3,a4;
	//test_integral2();
	//test_integral();
	/* Test for read& write polynomial parts */
	//read_polynomial3(&a0,&a1,&a2,&a3);
	//read_polynomial4(&a0,&a1,&a2,&a3,&a4);
	//test_compare_derivatives();
	return (0);
} /* end main */
