/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018
**
** Revision: 2018.03.27.08.19
** 
*/
#include "hw4_lib.h"
/* This function calculates integral with Riemann method */
double integral(double f(double), double xs, double xe, double delta)
{
	double integral=0,n,temp;
	int i;
	double test_xs=xs, test_xe=xe;
	if(xs>xe)
	{
		temp=xs;
		xs=xe;
		xe=temp;
	}
	n=(xe-xs)/delta;
	for(i=0; i<n; i++)
	{
			integral+=f(xs+(i*delta))*delta;
	}
	if(test_xs>test_xe)
	{
		integral*=-1;
	}
	return integral;
}
/* This function calculates double integral with Riemann method */
double integral2(double f(double x, double y), double xs, double xe, double ys, double ye, double delta)
{
	double integral2=0,n,n2,temp;
	double test_xs=xs, test_xe=xe, test_ys=ys, test_ye=ye;
	int i,j;
	if(xs>xe)
	{
		temp=xs;
		xs=xe;
		xe=temp;
	}
	if(ys>ye)
	{
		temp=ys;
		ys=ye;
		ye=temp;
	}
	n=(xe-xs)/delta;
	n2=(ye-ys)/delta;
	for (i=0; i<n; i++)
	{
		for(j=0; j<n2; j++)
		{
			integral2+=f(xs+(i*delta),ys+(j*delta))*(delta*delta);
		}
	}
	return integral2;
}
/* This function calculates derivative, function will return -1 if there is a problem ,1 otherwise. */
int derivatives(double f(double a), double x, double eps, double * d1, double * d2)
{
	
	int status;
	if(eps==0)
	{
		status=-1;
	}
	else
	{
		status=1;
		*d1=(f(x+eps)-f(x-eps))/(2*eps);
		*d2=(f(x+eps)-2*(f(x))+f(x-eps))/(eps*eps);
	}
	return status;
	
}
/* This function tests the error in numeric calculation of derivatives vs. actual derivatives*/
int compare_derivatives(double f(double a), double d1(double b), double d2(double b), double x, double eps, double * e1, double *e2)
{
		double my_d1,my_d2;
	    derivatives(f,x,eps,&my_d1,&my_d2);
		*e1=my_d1-d1(x);
		if(*e1<0)
			*e1*=-1;
		*e2=my_d2-d2(x);
		if (*e2<0)
			*e2*=-1;
		return 0;		
}

int find_roots(double f(double x), double * x1, double * x2, double * x3, double * x4)
{
	
	return 0;
}

